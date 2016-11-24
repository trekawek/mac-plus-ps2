#include "PS2Keyboard.h"

#define PS2_DATA_PIN 2
#define PS2_CLOCK_PIN 3

#define MAC_DATA_PIN 5
#define MAC_CLOCK_PIN 6

#define NULL_TRANSITION 0x7b

PS2Keyboard keyboard;
byte scanCodesTable[256];
byte extScanCodesTable[256];

void setup() {
  initScancodes();

  keyboard.begin(PS2_DATA_PIN, PS2_CLOCK_PIN);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MAC_CLOCK_PIN, OUTPUT);
  pinMode(MAC_DATA_PIN, INPUT_PULLUP);

  waitForInitSignal();
  delayMicroseconds(180);
}

void waitForInitSignal() {
  unsigned long t = millis();
  boolean led = false;
  while (digitalRead(MAC_CLOCK_PIN) != LOW) {
    if (millis() - t > 100) {
      t = millis();
      led = !led;
      digitalWrite(LED_BUILTIN, led);
    }
  }
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  byte cmd = readByte();
  digitalWrite(LED_BUILTIN, HIGH);

  switch (cmd) {
    case 0x10:
      inquiry();
      break;

    case 0x14: // instant
      sendByte(getKeyTransition());
      break;

    case 0x16: // model number
      sendByte(B00000011);
      break;

    case 0x36: // test
      sendByte(0x7d);
      break;
  }
}

void inquiry() {
  unsigned long start = millis();
  while ((millis() - start) < 250) {
    byte key = getKeyTransition();
    if (key != NULL_TRANSITION) {
      sendByte(key);
      return;
    }
  }
  sendByte(NULL_TRANSITION);
}

byte readByte() {
  pinMode(MAC_DATA_PIN, INPUT_PULLUP);
  byte b = 0;
  for (byte i = 0; i < 8; i++) {
    digitalWrite(MAC_CLOCK_PIN, LOW);
    delayMicroseconds(180);
    digitalWrite(MAC_CLOCK_PIN, HIGH);
    delayMicroseconds(40);
    b = (b << 1) | digitalRead(MAC_DATA_PIN);
    delayMicroseconds(180);
  }

  return b;
}

void sendByte(byte b) {
  pinMode(MAC_DATA_PIN, OUTPUT);
  for (byte m = 128; m > 0; m >>= 1) {
    digitalWrite(MAC_DATA_PIN, b & m == 0 ? HIGH : LOW);
    delayMicroseconds(40);
    digitalWrite(MAC_CLOCK_PIN, LOW);
    delayMicroseconds(160);
    digitalWrite(MAC_CLOCK_PIN, HIGH);
    delayMicroseconds(130);
  }
}

byte getKeyTransition() {
  byte c = keyboard.getScanCode();
  if (c == 0) {
    return NULL_TRANSITION;
  } else if (c == 0xf0) {
    return translate(keyboard.getScanCode(), false, true);
  } else if (c == 0xe0) {
    return getExtendedTransition();
  } else {
    return translate(c, false, false);
  }
}

byte getExtendedTransition() {
  byte c = keyboard.getScanCode();
  if (c == 0xf0) {
    return translate(keyboard.getScanCode(), true, true);
  } else {
    return translate(c, true, false);
  }
}

byte translate(byte scanCode, boolean extended, boolean released) {
  byte translated = extended ? extScanCodesTable[scanCode] : scanCodesTable[scanCode];
  if (translated == NULL_TRANSITION) {
    return NULL_TRANSITION;
  } else if (released) {
    return translated & 0x80;
  } else {
    return translated;
  }
}

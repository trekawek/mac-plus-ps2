#include "PS2Keyboard.h"

//#define SERIAL_DEBUG

#define NUMPAD  0x0100
#define NUMPAD2 0x0200

#define PS2_DATA_PIN 3
#define PS2_CLOCK_PIN 2

#define MAC_DATA_PIN 5
#define MAC_CLOCK_PIN 6

#define NULL_TRANSITION 0x7b
#define CAPS_LOCK       0x73

PS2Keyboard keyboard;
unsigned int scanCodesTable[256];
unsigned int extScanCodesTable[256];

void setup() {
#ifdef SERIAL_DEBUG
  Serial.begin(9600);
#endif
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
  switch (readCmd()) {
    case 0x10:
      inquiry();
      break;

    case 0x14: // instant
      sendKey(getKeyTransition());
      break;

    case 0x16: // model number
      sendByte(0x0b);
      break;

    case 0x36: // test
      sendByte(0x7d);
      break;
  }
}

byte readCmd() {
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(MAC_DATA_PIN, INPUT_PULLUP);
  delayMicroseconds(20);
  
  while (digitalRead(MAC_DATA_PIN) != LOW);
  delayMicroseconds(400); // this is apparently required so we don't lose the first digit
  byte cmd = readByte();
  while (digitalRead(MAC_DATA_PIN) != HIGH);
  
  digitalWrite(LED_BUILTIN, HIGH);
  pinMode(MAC_DATA_PIN, OUTPUT);
  delayMicroseconds(20);
  return cmd;
}

void inquiry() {
  unsigned long start = millis();
  while ((millis() - start) < 250) {
    int key = getKeyTransition();
    if (key != NULL_TRANSITION) {
      sendKey(key);
      return;
    }
  }
  sendByte(NULL_TRANSITION);
}

void sendKey(unsigned int key) {
  if (key & NUMPAD) {
    sendByte(0x79); readCmd();
    sendByte(key);
  } else if (key & NUMPAD2) {
    sendByte(0x71); readCmd();
    sendByte(0x79); readCmd();
    sendByte(key);
  } else {
    sendByte(key);
  }
}

byte readByte() {
  byte b = 0;
  for (byte i = 0; i < 8; i++) {
    digitalWrite(MAC_CLOCK_PIN, LOW);
    delayMicroseconds(180);
    digitalWrite(MAC_CLOCK_PIN, HIGH);
    delayMicroseconds(80);
    b = (b << 1) | digitalRead(MAC_DATA_PIN);
    delayMicroseconds(140);
  }
#ifdef SERIAL_DEBUG
  Serial.print(b, HEX);
  Serial.print(" -> ");
#endif
  return b;
}

void sendByte(byte b) {
#ifdef SERIAL_DEBUG
  Serial.print(b, HEX);
  Serial.println();
#endif
  for (byte m = 128; m > 0; m >>= 1) {
    digitalWrite(MAC_DATA_PIN, !(b & m) ? LOW : HIGH);
    delayMicroseconds(40);
    digitalWrite(MAC_CLOCK_PIN, LOW);
    delayMicroseconds(120);
    digitalWrite(MAC_CLOCK_PIN, HIGH);
    delayMicroseconds(170);
  }
  digitalWrite(MAC_DATA_PIN, HIGH);
}

unsigned int getKeyTransition() {
  byte c = keyboard.getScanCode();
  if (c == 0) {
    return NULL_TRANSITION;
  } else if (c == 0xf0) {
    return translate(waitForScanCode(), false, true);
  } else if (c == 0xe0) {
    return getExtendedTransition();
  } else {
    return translate(c, false, false);
  }
}

unsigned int getExtendedTransition() {
  byte c = waitForScanCode();
  if (c == 0xf0) {
    return translate(waitForScanCode(), true, true);
  } else {
    return translate(c, true, false);
  }
}

boolean capsLockPressed = false;

unsigned int translate(byte scanCode, boolean extended, boolean released) {
  unsigned int translated = extended ? extScanCodesTable[scanCode] : scanCodesTable[scanCode];
  if (translated == NULL_TRANSITION) {
    return NULL_TRANSITION;
  } else if (released) {
    if (translated == CAPS_LOCK) {
      return handleCapsLockRelease();
    } else {
      return translated | 0x80;
    }
  } else {
    return translated;
  }
}

unsigned int handleCapsLockRelease() {
  if (capsLockPressed) {
    capsLockPressed = false;
    return CAPS_LOCK | 0x80;
  } else {
    capsLockPressed = true;
    return NULL_TRANSITION;
  }
}

byte waitForScanCode() {
  while (true) {
    byte s = keyboard.getScanCode();
    if (s) {
      return s;
    }
  }
}


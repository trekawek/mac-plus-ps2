# Arduino-based PS2 -> Macintosh Plus keyboard adapter

This sketch allows to use a PS/2 keyboard with the Macintosh Plus. Mapping between PS/2 keys and Mac keys is stored in the [keymap.ino](mac_plus_ps2/keymap.ino) file. Sketch uses a modified version of the [PS2Keyboard Library](http://www.pjrc.com/teensy/td_libs_PS2Keyboard.html) --- all the logic except `getScanCode()` method have been stripped.

## Connecting to Macintosh Plus

Get a phone cord with RJ10 plug and connect pin as follows:

1. Vcc -> +5V
2. +DATA -> pin 5,
3. +CLK -> pin 6,
4. GND -> GND.

The order of RJ10 pins is the same as in the computer connector:

<img src="https://github.com/trekawek/mac-plus-ps2/raw/master/doc/mac-plus-keyboard-pinout.png" width="50%">

## Connecting to PS/2 keyboard

For the Mini-DIN 6 plug, pins should be connected as follows:

1. +DATA -> pin 2,
2. -,
3. GND -> GND,
4. Vcc -> +5V,
5. +CLK -> pin 3,
6. -

Pinout for the female connector from front (copied from [Wikipedia](https://en.wikipedia.org/wiki/PS/2_port)):

<img src="https://github.com/trekawek/mac-plus-ps2/raw/master/doc/minidin6-pinout.png" width="25%">

## References
 
* [Similar project based on stm32f0discovery kit](http://www.synack.net/~bbraun/mackbd/index.html),
* [Mac Plus technical information](http://www.mac.linux-m68k.org/devel/plushw.php) - contains the description of the protocol,
* [Mac Plus scancodes](http://m0115.web.fc2.com/m0110a.jpg).

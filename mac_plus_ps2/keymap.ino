void initScancodes() {
  for (int i = 0; i < 256; i++) {
    scanCodesTable[i] = NULL_TRANSITION;
    extScanCodesTable[i] = NULL_TRANSITION;
  }
  
  scanCodesTable[0x0e] = 0x32; // ~`
  scanCodesTable[0x16] = 0x12; // 1!
  scanCodesTable[0x1e] = 0x13; // 2@
  scanCodesTable[0x26] = 0x14; // 3#
  scanCodesTable[0x25] = 0x15; // 4$
  scanCodesTable[0x2e] = 0x17; // 5%
  scanCodesTable[0x36] = 0x16; // 6^
  scanCodesTable[0x3d] = 0x1a; // 7&
  scanCodesTable[0x3e] = 0x1c; // 8*
  scanCodesTable[0x46] = 0x19; // 9(
  scanCodesTable[0x45] = 0x1d; // 0)
  scanCodesTable[0x4e] = 0x1b; // -_
  scanCodesTable[0x55] = 0x18; // +=
  scanCodesTable[0x5d] = 0x2a; // |\
  scanCodesTable[0x66] = 0x33; // backspace
  
  scanCodesTable[0x0d] = 0x30; // tab
  scanCodesTable[0x15] = 0x0c; // q
  scanCodesTable[0x1d] = 0x0d; // w
  scanCodesTable[0x24] = 0x0e; // e
  scanCodesTable[0x2d] = 0x0f; // r
  scanCodesTable[0x2c] = 0x10; // t
  scanCodesTable[0x35] = 0x11; // y
  scanCodesTable[0x3c] = 0x20; // u
  scanCodesTable[0x43] = 0x22; // i
  scanCodesTable[0x44] = 0x1f; // o
  scanCodesTable[0x4d] = 0x23; // p
  scanCodesTable[0x54] = 0x21; // [{
  scanCodesTable[0x5b] = 0x1e; // }]
  scanCodesTable[0x5a] = 0x24; // enter
  
  scanCodesTable[0x58] = 0x39; // caps lock
  scanCodesTable[0x1c] = 0x00; // a
  scanCodesTable[0x1b] = 0x01; // s
  scanCodesTable[0x23] = 0x02; // d
  scanCodesTable[0x2b] = 0x03; // f
  scanCodesTable[0x34] = 0x05; // g
  scanCodesTable[0x33] = 0x04; // h
  scanCodesTable[0x3b] = 0x26; // j
  scanCodesTable[0x42] = 0x28; // k
  scanCodesTable[0x4b] = 0x25; // l
  scanCodesTable[0x4c] = 0x29; // :;
  scanCodesTable[0x52] = 0x27; // "'
  
  scanCodesTable[0x12] = 0x38; // left shift
  scanCodesTable[0x1a] = 0x06; // z
  scanCodesTable[0x22] = 0x07; // x
  scanCodesTable[0x21] = 0x08; // c
  scanCodesTable[0x2a] = 0x09; // v
  scanCodesTable[0x32] = 0x0b; // b
  scanCodesTable[0x31] = 0x2d; // n
  scanCodesTable[0x3a] = 0x2e; // m
  scanCodesTable[0x41] = 0x2b; // <,
  scanCodesTable[0x49] = 0x2f; // >.
  scanCodesTable[0x4a] = 0x2c; // ?/
  scanCodesTable[0x59] = 0x38; // right shift
  
  scanCodesTable[0x14] = 0x3a; // left ctrl -> option
  scanCodesTable[0x11] = 0x3a; // left alt  -> option
  scanCodesTable[0x29] = 0x31; // space
  
  extScanCodesTable[0x11] = 0x3a; // right alt  -> option
  extScanCodesTable[0x14] = 0x3a; // right ctrl -> option
  
  extScanCodesTable[0x5b] = 0x37; // left windows -> cmd
  extScanCodesTable[0x1f] = 0x37; // left windows -> cmd
  extScanCodesTable[0x8b] = 0x37; // left windows -> cmd
  
  extScanCodesTable[0x5c] = 0x37; // right windows
  extScanCodesTable[0x27] = 0x37; // right windows
  extScanCodesTable[0x8c] = 0x37; // right windows
  
  extScanCodesTable[0x75] = 0x4d; // up arrow
  extScanCodesTable[0x6b] = 0x46; // left arrow
  extScanCodesTable[0x72] = 0x48; // down arrow
  extScanCodesTable[0x74] = 0x42; // right arrow
  
  extScanCodesTable[0x77] = 0x47; // numlock -> numpad clear
  extScanCodesTable[0x71] = 0x47; // delete -> numpad clear
  extScanCodesTable[0x4a] = 0x6d; // numpad /
  extScanCodesTable[0x5a] = 0x4c; // numpad enter
  
  scanCodesTable[0x7c] = 0x62; // numpad *
  scanCodesTable[0x7b] = 0x4e; // numpad -
  scanCodesTable[0x70] = 0x52; // numpad 0
  scanCodesTable[0x71] = 0x41; // numpad .
  scanCodesTable[0x69] = 0x53; // numpad 1
  scanCodesTable[0x72] = 0x54; // numpad 2
  scanCodesTable[0x7a] = 0x55; // numpad 3
  scanCodesTable[0x6b] = 0x56; // numpad 4
  scanCodesTable[0x73] = 0x57; // numpad 5
  scanCodesTable[0x74] = 0x58; // numpad 6
  scanCodesTable[0x79] = 0x66; // numpad +
  scanCodesTable[0x6c] = 0x59; // numpad 7
  scanCodesTable[0x75] = 0x5b; // numpad 8
  scanCodesTable[0x7d] = 0x5c; // numpad 9
}

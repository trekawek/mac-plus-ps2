
void initScancodes() {
  for (int i = 0; i < 256; i++) {
    scanCodesTable[i] = NULL_TRANSITION;
    extScanCodesTable[i] = NULL_TRANSITION;
  }
  
  scanCodesTable[0x66] = 0x67; // backspace
  scanCodesTable[0x0e] = 0x65; // ~`
  scanCodesTable[0x16] = 0x25; // 1!
  scanCodesTable[0x1e] = 0x27; // 2@
  scanCodesTable[0x26] = 0x29; // 3#
  scanCodesTable[0x25] = 0x2b; // 4$
  scanCodesTable[0x2e] = 0x2f; // 5%
  scanCodesTable[0x36] = 0x2d; // 6^
  scanCodesTable[0x3d] = 0x35; // 7&
  scanCodesTable[0x3e] = 0x39; // 8*
  scanCodesTable[0x46] = 0x33; // 9(
  scanCodesTable[0x45] = 0x3b; // 0)
  scanCodesTable[0x4e] = 0x37; // -_
  scanCodesTable[0x55] = 0x31; // +=
  scanCodesTable[0x5d] = 0x55; // |\
  
  scanCodesTable[0x0d] = 0x61; // tab
  scanCodesTable[0x15] = 0x19; // q
  scanCodesTable[0x1d] = 0x1b; // w
  scanCodesTable[0x24] = 0x1d; // e
  scanCodesTable[0x2d] = 0x1f; // r
  scanCodesTable[0x2c] = 0x23; // t
  scanCodesTable[0x35] = 0x21; // y
  scanCodesTable[0x3c] = 0x41; // u
  scanCodesTable[0x43] = 0x45; // i
  scanCodesTable[0x44] = 0x3f; // o
  scanCodesTable[0x4d] = 0x47; // p
  scanCodesTable[0x54] = 0x43; // [{
  scanCodesTable[0x5b] = 0x3d; // }]
  scanCodesTable[0x5a] = 0x49; // enter
  
  scanCodesTable[0x58] = 0x73; // caps lock
  scanCodesTable[0x1c] = 0x01; // a
  scanCodesTable[0x1b] = 0x03; // s
  scanCodesTable[0x23] = 0x05; // d
  scanCodesTable[0x2b] = 0x07; // f
  scanCodesTable[0x34] = 0x0b; // g
  scanCodesTable[0x33] = 0x09; // h
  scanCodesTable[0x3b] = 0x4d; // j
  scanCodesTable[0x42] = 0x51; // k
  scanCodesTable[0x4b] = 0x4b; // l
  scanCodesTable[0x4c] = 0x53; // :;
  scanCodesTable[0x52] = 0x4f; // "'
  
  scanCodesTable[0x12] = 0x71; // left shift
  scanCodesTable[0x1a] = 0x0d; // z
  scanCodesTable[0x22] = 0x0f; // x
  scanCodesTable[0x21] = 0x11; // c
  scanCodesTable[0x2a] = 0x13; // v
  scanCodesTable[0x32] = 0x17; // b
  scanCodesTable[0x31] = 0x5b; // n
  scanCodesTable[0x3a] = 0x5d; // m
  scanCodesTable[0x41] = 0x57; // <,
  scanCodesTable[0x49] = 0x5f; // >.
  scanCodesTable[0x4a] = 0x59; // ?/
  scanCodesTable[0x59] = 0x71; // right shift
  
  scanCodesTable[0x14] = 0x75; // left ctrl -> option
  scanCodesTable[0x11] = 0x75; // left alt  -> option
  scanCodesTable[0x29] = 0x63; // space
  
  extScanCodesTable[0x11] = 0x75; // right alt  -> option
  extScanCodesTable[0x14] = 0x75; // right ctrl -> option
  
  extScanCodesTable[0x5b] = 0x6f; // left windows -> cmd
  extScanCodesTable[0x1f] = 0x6f; // left windows -> cmd
  extScanCodesTable[0x8b] = 0x6f; // left windows -> cmd
  
  extScanCodesTable[0x5c] = 0x6f; // right windows
  extScanCodesTable[0x27] = 0x6f; // right windows
  extScanCodesTable[0x8c] = 0x6f; // right windows
  
  scanCodesTable[0x77] = 0x0f | NUMPAD;             // numlock -> numpad clear
  extScanCodesTable[0x71] = 0x0f | NUMPAD;          // delete -> numpad clear
  extScanCodesTable[0x75] = 0x1b | NUMPAD; // up arrow
  extScanCodesTable[0x6b] = 0x0d | NUMPAD; // left arrow
  extScanCodesTable[0x72] = 0x11 | NUMPAD; // down arrow
  extScanCodesTable[0x74] = 0x05 | NUMPAD; // right arrow

  extScanCodesTable[0x4a] = 0x1b | NUMPAD2; // numpad /
  extScanCodesTable[0x5a] = 0x19 | NUMPAD;  // numpad enter

  scanCodesTable[0x7c] = 0x05 | NUMPAD2;// numpad *
  scanCodesTable[0x7b] = 0x1d | NUMPAD; // numpad -
  scanCodesTable[0x70] = 0x25 | NUMPAD; // numpad 0
  scanCodesTable[0x71] = 0x03 | NUMPAD; // numpad .
  scanCodesTable[0x69] = 0x27 | NUMPAD; // numpad 1
  scanCodesTable[0x72] = 0x29 | NUMPAD; // numpad 2
  scanCodesTable[0x7a] = 0x2b | NUMPAD; // numpad 3
  scanCodesTable[0x6b] = 0x2d | NUMPAD; // numpad 4
  scanCodesTable[0x73] = 0x2f | NUMPAD; // numpad 5
  scanCodesTable[0x74] = 0x31 | NUMPAD; // numpad 6
  scanCodesTable[0x79] = 0x0d | NUMPAD2;// numpad +
  scanCodesTable[0x6c] = 0x33 | NUMPAD; // numpad 7
  scanCodesTable[0x75] = 0x37 | NUMPAD; // numpad 8
  scanCodesTable[0x7d] = 0x39 | NUMPAD; // numpad 9
}

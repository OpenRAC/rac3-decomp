/* functional: high. Clears the byte at +0xC of the object and returns 0. */
s32 func_L39_0067F980(u8 *self) {
    self[0xC] = 0;
    return 0;
}

/* functional: high. Hand-written retail asm (addi traps never fire here); same read of the word at +0x1C, same -1 for negative, same masked field. */
extern u8 D_L01_001EAA00[];
s32 func_L01_003FE908(void) {
    s32 v = *(s32 *)(D_L01_001EAA00 + 0x1C);
    if (v < 0) return -1;
    return (v & 0x60) >> 5;
}

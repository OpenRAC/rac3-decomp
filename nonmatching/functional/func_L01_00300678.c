/* functional: high. Not exact (18 diff: retail copies a0 to a1 up front and loads the state into a0; bytes only). Callee is PAL func_003C3A10 with last arg 8 (the NTSC-U draft used 10). */
extern s32 D_001A71A4[];
extern void func_003C3A10(void *, s32, s32, s32);
void func_L01_00300678(u8 *a0) {
    if (D_001A71A4[0] == 8) {
        if (a0[0x43] != 6) {
            func_003C3A10(a0, 6, 0, 8);
        }
    }
}

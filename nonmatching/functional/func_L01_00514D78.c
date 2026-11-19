/* functional: high. 4-instruction diff from retail only in register choice for the entry (retail copies it v1->a0 in the jal delay slot); behaviour identical. */
extern s32 func_003EDAF8(void *p, s32 mask);

s32 func_L01_00514D78(u8 **o, u32 i, u8 *out) {
    void *p;
    if (i < 0x23) {
        o = (u8 **)*o;
        i <<= 2;
        p = *(void **)(i + (u32)o + 0x50);
        if (p != 0) {
            *out = func_003EDAF8(p, 1);
            return 1;
        }
    }
    return 0;
}

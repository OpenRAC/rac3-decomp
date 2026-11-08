/* Ported from rac4-decomp's func_004369F0 (a twin of this function's code), names renamed from retail's
   relocations; 5 instruction(s) still differ under this file's flags. */
extern s32 D_3284A0[];

s32 func_L39_00554E18(s32 arg0, s32 arg1) {
    s32 *ptr;
    s32 i;
    ptr = &D_3284A0[arg1 * 4];
    i = 0;
    do {
        i++;
        if (*ptr != arg0) {
            ptr++;
        } else {
            *ptr = 0;
            return 1;
        }
    } while (i < 4);
    return 0;
}

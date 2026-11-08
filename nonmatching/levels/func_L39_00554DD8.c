/* Ported from rac4-decomp's func_004369B0 (a twin of this function's code), names renamed from retail's
   relocations; 5 instruction(s) still differ under this file's flags. */
extern int D_3284A0[];

int func_L39_00554DD8(int arg0) {
    int *ptr;
    int i;
    ptr = (int *)&D_3284A0 + arg0 * 4;
    for (i = 0; i < 4; i++) {
        if (*ptr == 0) {
            return 0;
        }
        ptr++;
    }
    return 1;
}

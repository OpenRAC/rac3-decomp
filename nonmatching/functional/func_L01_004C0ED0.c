/* functional: high. Rewritten from PAL asm; behaviour identical. */
/* localdecomp:start func_L01_004C0ED0 */
extern s32 D_001DAE00_sda[];
__asm__(".extern D_001DAE00_sda, 16");

s32 func_L01_004C0ED0(s32 a0) {
    s32 i;
    if (D_001DAE00_sda[0] < 0) return -1;
    i = 0;
    for (;;) {
        if (D_001DAE00_sda[i * 2] == a0) return D_001DAE00_sda[i * 2 + 1];
        i++;
        if (!(D_001DAE00_sda[i * 2] >= 0 && &D_001DAE00_sda[i * 2] < D_001DAE00_sda + 120)) break;
    }
    return -1;
}
/* localdecomp:end func_L01_004C0ED0 */

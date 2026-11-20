/* functional: high. Rewritten from PAL asm; behaviour identical. Walks the {key,value} pair table at gp-0x1AB0 (60 entries) until key matches or a negative key. */
/* localdecomp:start func_L01_004C0ED0 */
extern s32 D_001DAE00_sda;
__asm__(".extern D_001DAE00_sda, 4");
extern s32 D_L01_001DAE04[];
extern s32 D_L01_001DAFE0[];

s32 func_L01_004C0ED0(s32 a0) {
    s32 *p;
    s32 *v;
    if (D_001DAE00_sda < 0) return -1;
    p = &D_001DAE00_sda;
    v = D_L01_001DAE04;
    do {
        s32 k = *p;
        p += 2;
        if (a0 == k) return *v;
        v += 2;
    } while ((*p >= 0) & (p < D_L01_001DAFE0));
    return -1;
}
/* localdecomp:end func_L01_004C0ED0 */

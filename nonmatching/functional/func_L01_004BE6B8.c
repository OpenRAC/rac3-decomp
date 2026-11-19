/* functional: medium. Rewritten from PAL asm; logic matches blocks read; prototype of 00406210 is inferred. */
/* localdecomp:start func_L01_004BE6B8 */
extern S_00244740 D_L01_002446C0[];
extern u8 D_L01_002EF780[];
__asm__(".extern D_L01_002EF780, 16");
extern long func_00389598(s32);
extern void func_L01_00406210(f32, f32, f32, f32, s32, s32, s32, s32, u32 *, long);

void func_L01_004BE6B8(s32 color, u8 *str, s32 count, f32 x, f32 y, f32 scale) {
    u32 cols[8] __attribute__((aligned(16)));
    long tex;
    s32 i;
    s32 col;
    f32 step16;
    f32 yoff;
    f32 mid;
    s32 a, b;
    u8 *p;
    u8 *T;

    tex = func_00389598(2);
    step16 = scale * 16.0f;
    col = color & 0xFFFFFF;
    if (count == 0 || *str == 0) return;
    p = str;
    for (i = 0; ; ) {
        T = D_L01_002EF780 + *p * 4;
        if (((s8 *)T)[3] != 0) {
            yoff = (f32)((s8 *)T)[2] * scale;
            if (*(s32 *)((u8 *)D_L01_002446C0 + 0x50) == 2) {
                mid = 215.0f;
                {
                    double d = (double)(mid - x);
                    if (d < 0) d = -d;
                    a = 128 - (s32)d;
                    d = (double)(mid - (x + step16));
                    if (d < 0) d = -d;
                    b = 128 - (s32)d;
                }
            } else {
                mid = 256.0f;
                {
                    double d = (double)(mid - x);
                    if (d < 0) d = -d;
                    d = d * 0.75;
                    a = 128 - (s32)d;
                    d = (double)(mid - (x + step16));
                    if (d < 0) d = -d;
                    d = d * 0.75;
                    b = 128 - (s32)d;
                }
            }
            if (!(a > -1)) a = 0;
            if (!(b > -1)) b = 0;
            cols[0] = (a << 24) | col;
            cols[1] = (b << 24) | col;
            cols[2] = cols[0];
            cols[3] = cols[1];
            if (*p < 0x20) {
                u32 c = cols[0];
                s32 g = ((c & 0xFF) + ((c >> 8) & 0xFF) + ((c >> 16) & 0xFF)) / 3;
                u32 c2 = (c & 0xFF000000) + (g << 16) + (g << 8) + g;
                cols[4] = c2;
                cols[5] = c2;
                cols[6] = c2;
                cols[7] = c2;
                func_L01_00406210(x, y + yoff, scale * 24.0f, scale * 16.0f, D_L01_002EF780[*p * 4], D_L01_002EF780[*p * 4 + 1], 24, 16, &cols[4], tex);
            } else if (*p > 0x20) {
                func_L01_00406210(x, y + yoff, step16, step16, D_L01_002EF780[*p * 4], D_L01_002EF780[*p * 4 + 1], 16, 16, cols, tex);
            }
            x = x + (f32)((s8 *)(D_L01_002EF780 + *p * 4))[3] * scale;
        }
        i++;
        if (i == count) break;
        p++;
        if (*p == 0) break;
    }
}
/* localdecomp:end func_L01_004BE6B8 */

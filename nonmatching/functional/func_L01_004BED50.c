/* functional: medium. Rewritten from PAL asm; high instruction diff count is scheduling/constant style; callee prototypes inferred. The text-width call is the alias func_L01_004127C0_004BED50: in level 20 retail calls the other twin wrapper (0x431140, the catalogue's func_L01_00412810 place), not func_L01_004127C0's place 0x421A10, and the two call different routines there. Level $gp slots are D_L01_ names (they move per level). D_001E0FD0/D_001DC0E8/D_001DC104 are lui-addressed in retail (unsized arrays), the others $gp-relative. */
/* localdecomp:start func_L01_004BED50 */
extern S_00244740 D_L01_002446C0[];
extern f32 D_L01_001E0FD0[];
extern f32 D_L01_001DC0E8[];
extern f32 D_L01_001DC0EC;
extern f32 D_L01_001DC104[];
extern s32 D_L01_001DAD9C;
extern s32 D_L01_001DADA0;
extern s32 D_00143950[];
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
__asm__(".extern D_001D4BC0, 16");
__asm__(".extern D_001D4BC4, 16");
extern u8 D_001425C0[];
extern S_002C5640 D_L01_002C5600[];
extern void func_003A9500(s32, s32, s32, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_00415A58(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00396968(s32, s32);
extern void func_00396E50(s32, s32, s32, s32, s32, u32 *);
extern char *func_00381FF0(s32);
extern s32 func_L01_004127C0_004BED50(char *, f32, s32);
extern void func_0038E150(s32);
extern void func_0038E7E8(f32, f32, f32, f32, f32, f32, unsigned long, char *, s32, s32, s32, s32);

void func_L01_004BED50(void) {
    u8 *u = (u8 *)D_L01_002446C0;
    s32 i;
    s32 v;
    s32 h;
    s32 sc;
    s32 y21;
    s32 off = (D_00143950[0] != 0) ? 4 : 0;
    s32 a, b, idx, arg, yy, xx, col, cola, colb, mid, kind, tex, row;
    char *s;
    s32 w;
    f32 f = D_L01_001E0FD0[0];
    u32 cols[4] __attribute__((aligned(16)));
    f32 rx, ry, fy, sY;

    func_003A9500(0x3A, 0x1C8, (s32)(f * 299.0f + 0.5f), (s32)(f * 361.0f + 0.5f) + off);

    sc = *(s32 *)(u + 0x6C);
    if (sc < 0) *(s32 *)(u + 0x6C) = sc + 4;
    else if (sc > 0) *(s32 *)(u + 0x6C) = sc - 4;

    v = ((*(s32 *)(u + 4) << 2) & 0x3F) - 0x20;
    if (v <= 0) v = -v;
    v = v + 0x40;
    h = func_0038DBD8(0x331465B7, 0, 0.8f);
    f = D_L01_001E0FD0[0];
    col = (v * 0x10202) | 0x80000000;
    func_L01_00415A58(0xE5, (s32)(f * 304.0f + 0.5f) + off, 0x11D, (s32)(f * 360.0f + 0.5f) + off, D_001D4BC0, D_001D4BC4, col);
    f = D_L01_001E0FD0[0];
    func_L01_00415A58(0xE7, (s32)(f * 306.0f + 0.5f) + off, 0x11B, (s32)(f * 358.0f + 0.5f) + off, D_001D4BC0, D_001D4BC4, h);

    y21 = *(s32 *)(u + 0x6C) - 0x2C;
    for (i = -5; i < 7; i++, y21 += 0x38) {
        idx = *(s32 *)(u + 0x80) + i;
        if (idx < 0 || idx >= *(s32 *)(u + 0x740)) continue;
        row = idx * 0x14;
        if (u[row + 0x152] != 0) {
            arg = 0xED41;
        } else if (u[row + 0x153] != 0) {
            arg = 0x755D;
        } else {
            arg = *(u16 *)((u8 *)D_L01_002C5600 + D_001425C0[*(s32 *)(u + 0x140 + row)] * 0xF0 + 0x38);
        }
        tex = func_00396968(arg, 0);
        yy = y21 + 2;
        {
            double d = (double)(256.0f - (f32)yy);
            if (d < 0) d = -d;
            d = d * 0.75;
            a = 128 - (s32)d;
            d = (double)(256.0f - (f32)(y21 + 0x28));
            if (d < 0) d = -d;
            d = d * 0.75;
            b = 128 - (s32)d;
        }
        if (!(a > -1)) a = 0;
        if (!(b > -1)) b = 0;
        cola = a << 24;
        colb = b << 24;
        kind = (u[row + 0x144] != 0) ? 1 : 5;
        mid = ((cola + colb) >> 1) & 0xFF000000;
        cols[0] = cola | 0x66CCFF;
        cols[1] = colb | 0x66CCFF;
        cols[2] = cols[0];
        cols[3] = cols[1];
        func_00396E50(tex, yy, kind + off + (s32)(D_L01_001E0FD0[0] * 308.0f + 0.5f), 0x26, (s32)(D_L01_001E0FD0[0] * 38.0f + 0.5f), cols);
        if (u[row + 0x151] != 0) {
            s = func_00381FF0(0x583);
            w = func_L01_004127C0_004BED50(s, 0.75f, -1);
            func_0038E150(1);
            xx = y21 + D_L01_001DAD9C - (w >> 1);
            yy = (s32)((f32)(D_L01_001DADA0 + 0x134) * D_L01_001E0FD0[0] + 0.5f);
            if (D_00143950[0]) yy = yy + 4;
            fy = (f32)yy / D_L01_001DC0EC;
            sY = D_L01_001DC0EC;
            rx = (f32)xx / D_L01_001DC0E8[0];
            func_0038E7E8((f32)(s32)(rx * D_L01_001DC0E8[0]), (f32)(s32)((fy - D_L01_001DC104[0] * 0.75f) * sY), 0.75f, 0.8076923f, 0.0f, 0.0f, (u32)(mid | 0x66CCFF), s, -1, 1, 0, 0x80808080);
        } else if (u[row + 0x144] == 1) {
            s = func_00381FF0(0x178);
            func_L01_004127C0_004BED50(s, 0.75f, -1);
            func_0038E150(1);
            xx = y21 + D_L01_001DAD9C - 0xF;
            yy = (s32)((f32)(D_L01_001DADA0 + 0x134) * D_L01_001E0FD0[0] + 0.5f);
            yy = D_00143950[0] ? yy + 2 : yy - 2;
            sY = D_L01_001DC0EC;
            fy = (f32)yy / sY;
            rx = (f32)xx / D_L01_001DC0E8[0];
            func_0038E7E8((f32)(s32)(rx * D_L01_001DC0E8[0]), (f32)(s32)((fy - D_L01_001DC104[0] * 0.75f) * sY), 0.75f, 0.8076923f, 0.0f, 0.0f, (u32)(mid | 0x66CCFF), s, -1, 1, 0, 0x80808080);
        }
    }
}
/* localdecomp:end func_L01_004BED50 */

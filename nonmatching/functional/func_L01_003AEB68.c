/* functional: medium. compiles; layout of the quad descriptor (corners 0x00-0x3F, colours 0x40, uv 0x50, tex at 0x78, constants at 0x80/0x88) follows the sister function func_L01_0032CF90; func_0038DBD8 read as colour lerp by alpha; sets bit0 of D_L01_001DBCA0 (render flag); renderer packet builder - port may replace */
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern long func_00389598(s32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern u8 D_L01_001E29C0[];
extern u32 D_L01_001DBCA0;
extern f32 D_L01_001DE4F8[];
extern f32 D_L01_001DE4FC[];
extern s32 D_L01_001DE4DC;
__asm__(".extern D_L01_001DE4DC, 4");
extern s32 D_L01_001DE4D8;
__asm__(".extern D_L01_001DE4D8, 4");
extern s32 D_L01_001DE4E0;
__asm__(".extern D_L01_001DE4E0, 4");
extern u32 D_L01_001DE4E4;
__asm__(".extern D_L01_001DE4E4, 4");
extern u32 D_L01_001DE4E8;
__asm__(".extern D_L01_001DE4E8, 4");
extern u32 D_L01_001DE4EC;
__asm__(".extern D_L01_001DE4EC, 4");
extern f32 D_L01_001DE4F0;
__asm__(".extern D_L01_001DE4F0, 4");

void func_L01_003AEB68(u8 *obj) {
    u8 *pv = *(u8 **)(obj + 0x68);
    f32 pos[4] __attribute__((aligned(16)));
    f32 q[36] __attribute__((aligned(16)));    /* quad descriptor at +0x10 of retail frame: corners q[0..15], colours q[16..19], uv q[20..27], 0x70.. */
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 end[4] __attribute__((aligned(16)));
    f32 cam1[4] __attribute__((aligned(16)));
    f32 cam2[4] __attribute__((aligned(16)));
    f32 tmp[4] __attribute__((aligned(16)));
    f32 d;
    f32 r;
    f32 f22;
    f32 t;
    s32 i;
    s32 col;
    int k;

    d = func_0038CF00(obj + 0x10, D_L01_001E29C0);
    r = (f32)*(s16 *)(obj + 0x32);
    if (r < d) {
        f22 = 1.0f - (d - r) * 10.0f;
        if (f22 < 0.01f) {
            return;
        }
    } else {
        f22 = 1.0f;
    }
    t = *(f32 *)(pv + 0x1C) + 0.15f;
    D_L01_001DBCA0 |= 1;
    *(f32 *)(pv + 0x1C) = t;
    if (4.0f <= t) {
        *(f32 *)(pv + 0x1C) = t - 4.0f;
    }
    vec_copy(pos, obj + 0x10);
    func_0038CF68(end, pv, -4.0f);
    vec_add_ba(end, pos, end);
    vec_copy(cam1, D_L01_001E29C0);
    vec_copy(cam2, D_L01_001E29C0);
    vec_sub_ab(c, pos, end);
    vec_sub_ab(a, pos, cam1);
    vec_sub_ab(b, end, cam2);
    func_0038CE90(a, a, c);
    func_0038CF68(a, a, 0.4f);
    func_0038CE90(b, b, c);
    func_0038CF68(b, b, 0.4f);

    /* first beam quad */
    *(long *)(q + 28) = 0;
    *(long *)(q + 30) = func_00389598(D_L01_001DE4DC);
    *(long *)(q + 32) = 0x0000FF9000000260L;
    *(long *)(q + 34) = 0x0000008000000048L;
    col = func_0038DBD8(f22, 0, 0x806040);
    ((s32 *)q)[16] = col;
    ((s32 *)q)[17] = col;
    col = func_0038DBD8(f22, D_L01_001DE4EC & 0xFF000000, D_L01_001DE4EC);
    ((s32 *)q)[19] = col;
    ((s32 *)q)[18] = col;
    for (k = 0; k < 4; k++) {
        q[20 + k * 2] = D_L01_001DE4F8[k * 2] + *(f32 *)(pv + 0x1C);
        q[21 + k * 2] = D_L01_001DE4FC[k * 2];
    }
    vec_sub_ba(q + 0, end, a);
    vec_add_ba(q + 4, end, a);
    vec_sub_ab(q + 8, pos, b);
    vec_add_ab(q + 12, pos, b);
    func_003D2DA0(q, 0, 0);

    /* second beam quad */
    vec_sub_ab(c, pos, end);
    vec_copy(cam1, D_L01_001E29C0);
    vec_copy(cam2, D_L01_001E29C0);
    vec_sub_ab(a, pos, cam1);
    vec_sub_ab(b, end, cam2);
    func_0038CE90(a, a, c);
    func_0038CF68(a, a, 0.4f);
    func_0038CE90(b, b, c);
    func_0038CF68(b, b, 0.4f);
    *(long *)(q + 28) = 0;
    *(long *)(q + 30) = func_00389598(D_L01_001DE4D8);
    *(long *)(q + 32) = 0x0000FF9000000260L;
    *(long *)(q + 34) = 0x0000008000000048L;
    col = func_0038DBD8(f22, 0, 0x704020);
    ((s32 *)q)[16] = col;
    ((s32 *)q)[17] = col;
    col = func_0038DBD8(f22, D_L01_001DE4E8 & 0xFF000000, D_L01_001DE4E8);
    ((s32 *)q)[19] = col;
    ((s32 *)q)[18] = col;
    for (k = 0; k < 4; k++) {
        q[20 + k * 2] = D_L01_001DE4F8[k * 2] - *(f32 *)(pv + 0x1C);
        q[21 + k * 2] = D_L01_001DE4FC[k * 2];
    }
    vec_sub_ba(q + 0, end, a);
    vec_add_ba(q + 4, end, a);
    vec_sub_ab(q + 8, pos, b);
    vec_add_ab(q + 12, pos, b);
    func_003D2DA0(q, 0, 0);

    /* glow sprites at the start point */
    col = func_0038DBD8(f22, D_L01_001DE4E4 & 0xFF000000, D_L01_001DE4E4);
    func_003D9508(obj + 0x10, D_L01_001DE4E0, col, 1, D_L01_001DE4F0, 0.08f, func_00382538());
    col = func_0038DBD8(f22, 0x81000000, 0x80808080);
    func_003D9508(obj + 0x10, D_L01_001DE4E0, col, 1, D_L01_001DE4F0 * 0.5f, 0.08f, func_00382538());
}

/* functional: medium. VU0 vadd.xyz as scalar math; uses the file's func_003D3CB0 decl with casts. Not byte exact. */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern u8 D_L01_001EAA00[];
s32 func_L01_00458D50(u8 *self, u8 *out) {
    f32 p[4] __attribute__((aligned(16)));
    f32 dir[4] __attribute__((aligned(16)));
    f32 lo[4] __attribute__((aligned(16)));
    f32 hi[4] __attribute__((aligned(16)));
    f32 nrm[4] __attribute__((aligned(16)));
    f32 *sp = (f32 *)(self + 16);
    u8 *cfg;
    f32 g1, g2, limit, ang;

    cfg = *(u8 **)(*(u8 **)(self + 104) + 28);
    if (cfg == 0) {
        return 0;
    }
    if (*(f32 *)(cfg + 144) == 0.0f) {
        return 0;
    }
    p[0] = sp[0];
    p[1] = sp[1];
    p[2] = sp[2];
    p[3] = sp[3];
    dir[0] = func_0038D098(*(f32 *)(self + 248));
    dir[1] = func_0038D0B0(*(f32 *)(self + 248));
    dir[2] = 0.0f;
    p[0] = p[0] + dir[0];
    p[1] = p[1] + dir[1];
    p[2] = p[2] + dir[2];
    hi[0] = sp[0];
    hi[1] = sp[1];
    hi[2] = sp[2];
    hi[3] = sp[3];
    lo[0] = sp[0];
    lo[1] = sp[1];
    lo[2] = 0.01f;
    lo[3] = sp[3];
    hi[2] = hi[2] + 3.0f;
    if (func_003D3CB0((Vec4 *)hi, (Vec4 *)lo, 0, (void *)self, 0) != 0) {
        *(s32 *)(out + 92) = *(s32 *)(D_L01_001EAA00 + 24);
    }
    g1 = func_003C3D30(p, 34, 0, 0.5f);
    if (!(g1 < *(f32 *)(self + 24))) {
        return 0;
    }
    if (!(*(f32 *)(cfg + 12) < __builtin_fabsf(g1 - *(f32 *)(self + 24)))) {
        return 0;
    }
    dir[0] = func_0038D098(*(f32 *)(self + 248)) * 9.0f;
    dir[1] = func_0038D0B0(*(f32 *)(self + 248)) * 9.0f;
    dir[2] = 0.0f;
    p[0] = sp[0] + dir[0];
    p[1] = sp[1] + dir[1];
    p[2] = sp[2] + dir[2];
    p[3] = sp[3];
    ((f32 *)(out + 96))[0] = p[0];
    ((f32 *)(out + 96))[1] = p[1];
    ((f32 *)(out + 96))[2] = p[2];
    ((f32 *)(out + 96))[3] = p[3];
    g2 = func_003C3D30(p, 34, 0, 6.0f);
    limit = *(f32 *)(self + 24) - 2.0f;
    nrm[0] = ((f32 *)(D_L01_001EAA00 + 64))[0];
    nrm[1] = ((f32 *)(D_L01_001EAA00 + 64))[1];
    nrm[2] = ((f32 *)(D_L01_001EAA00 + 64))[2];
    nrm[3] = ((f32 *)(D_L01_001EAA00 + 64))[3];
    ang = func_0038D160(nrm[2], func_0038CED8(nrm));
    if (limit < g2 && ang < 0.17453292f) {
        *(f32 *)(out + 76) = g2;
        return 1;
    }
    return 2;
}

/* functional: high. VU0 vadd.xyz as scalar math; compiles under file flags, not byte exact. */
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L01_00451580(void *);
extern u8 D_L01_001EAA00[];
void func_L01_0045CDA0(u8 *self, u8 *b) {
    f32 dir[4] __attribute__((aligned(16)));
    f32 p1[4] __attribute__((aligned(16)));
    f32 p2[4] __attribute__((aligned(16)));
    f32 *sp = (f32 *)(self + 16);
    func_003C5180(self + 16, dir, 1);
    func_0038CF68(p1, dir, *(f32 *)(b + 8) + 0.1f);
    func_0038CF68(p2, dir, -*(f32 *)(b + 12) - 0.1f);
    p1[0] = p1[0] + sp[0];
    p1[1] = p1[1] + sp[1];
    p1[2] = p1[2] + sp[2];
    p2[0] = p2[0] + sp[0];
    p2[1] = p2[1] + sp[1];
    p2[2] = p2[2] + sp[2];
    if (func_003D3CB0(p1, p2, 0, self, 0) != 0) {
        *(f32 *)(b + 144) = func_L01_00451580(D_L01_001EAA00 + 32);
        *(s32 *)(b + 136) = *(s32 *)(D_L01_001EAA00 + 24);
        *(s32 *)(b + 140) = *(s32 *)(D_L01_001EAA00 + 28);
        *(s32 *)(b + 216) = -1;
        func_0038CF68(b + 80, D_L01_001EAA00 + 64, 1.0f);
    } else {
        *(f32 *)(b + 144) = 0.0f;
        *(s32 *)(b + 216) = -1;
        ((s32 *)(b + 80))[0] = 0;
        ((s32 *)(b + 80))[1] = 0;
        ((s32 *)(b + 80))[2] = 0;
        ((s32 *)(b + 80))[3] = 0;
        *(s32 *)(b + 136) = 0;
        *(s32 *)(b + 140) = 0;
    }
}

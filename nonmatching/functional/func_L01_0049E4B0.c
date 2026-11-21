/* functional: high. Same shape as 0049E408 with add instead of sub and c.lt operands swapped, checked against asm */
extern s32 D_001D94CC_sda;
__asm__(".extern D_001D94CC_sda, 4");
extern s32 D_001D94D0_sda;
__asm__(".extern D_001D94D0_sda, 4");
extern f32 D_001D94E4_sda;
__asm__(".extern D_001D94E4_sda, 4");
extern void func_L01_00516558(s32, f32 *, f32 *);
extern void func_L01_00516470(s32, f32, f32);

s32 func_L01_0049E4B0(void) {
    f32 v[4];
    s32 ok;

    v[3] = 0.0f;
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    ok = 1;
    func_L01_00516558(D_001D94CC_sda, &v[0], &v[1]);
    func_L01_00516558(D_001D94D0_sda, &v[2], &v[3]);
    v[2] = v[2] + D_001D94E4_sda;
    v[0] = v[0] + D_001D94E4_sda;
    if (0.5f < v[2]) {
        v[2] = 0.5f;
        ok = 0;
    }
    func_L01_00516470(D_001D94CC_sda, v[0], v[1]);
    func_L01_00516470(D_001D94D0_sda, v[2], v[3]);
    return ok;
}

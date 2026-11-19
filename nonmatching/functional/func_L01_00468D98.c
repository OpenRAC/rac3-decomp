/* functional: high. 18 diff at default flags (vec_add_ba instead of the draft's inline asm; func_0038CF68 arg order (0.25,dst,src)) */
/* localdecomp:start func_L01_00468D98 */
extern vu0_v4 D_L01_001E29C0;
void func_L01_00468D98(u8 *self) {
    extern f32 func_0038CEA8(f32 *);
    extern void func_0038CF68(f32, void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern s32 func_L01_00447470(s32, s32, f32);
    vu0_v4 delta;
    u8 *vars = self + 0x20;
    f32 facing;
    vec_sub_ab(&delta, &D_L01_001E29C0, self + 0x30);
    if (func_0038CEA8(&delta.x) > 1.0f) {
        func_0038CF68(0.25f, &delta.x, &delta.x);
    } else {
        func_0038CE20(&delta.x, &delta.x, 0.25f);
    }
    vec_add_ba(self + 0x10, vars + 0x10, &delta);
    *(f32 *)(vars + 4) = func_0038DAB8(*(f32 *)(vars + 4), *(f32 *)(vars + 0x1C));
    facing = func_0038D0B0(*(f32 *)(vars + 4));
    if (func_0038CB00(self + 0xA)) {
        if (facing < *(f32 *)(vars + 8) || facing < -0.9f) goto kill;
    }
    if (**(s32 **)vars == 0) {
kill:
        **(s32 **)vars = 0;
        func_003CD250(self);
        return;
    }
    if (*(f32 *)(vars + 8) < facing) {
        *(s32 *)(self + 4) = func_L01_00447470(0, *(s32 *)(vars + 0xC),
            (facing - *(f32 *)(vars + 8)) / (1.0f - *(f32 *)(vars + 8)));
    } else {
        *(s32 *)(self + 4) = 0;
    }
}
/* localdecomp:end func_L01_00468D98 */

/* functional: high. Compiles; ~25 diff insns (regalloc/branch layout) but same operations in the same order; block-checked by hand (all branches read). Arg order of func_L01_003FB640's third arg is D_001A71A0[0] left in $a2 by retail. */
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern s32 func_L01_003FB640(void *, s32, s32, f32);
extern u8 D_001EAA20[];
extern s32 D_001EAA18[];
extern s32 D_001A71A0[];

s32 func_L01_0032EE48(s128 *out, f32 *pos, u8 *obj, f32 scale) {
    f32 dir[4] __attribute__((aligned(16)));
    f32 dst[4] __attribute__((aligned(16)));
    s32 t;
    u8 *vars;
    s32 hit;

    func_L01_004C7D98(obj + 0x10, dir);
    func_0038CE20(dir, dir, -scale);
    vec_add_ab(dst, pos, dir);
    if (func_003D3CB0(pos, dst, 0x10, obj, 0) == 0) {
        return 0;
    }
    t = func_003D5630();
    if (t < 2 || t == 0xB || t == 7 || t == 0xD || t == 0xE) {
        return 0;
    }
    vars = *(u8 **)(obj + 0x68);
    *out = *(s128 *)D_001EAA20;
    if (D_001EAA18[0] == D_001A71A0[0]) {
        return 0;
    }
    if (func_L01_003FB640(pos, 2, D_001A71A0[0], 0.9f) != 0) {
        return 0;
    }
    hit = D_001EAA18[0];
    if (hit == 0 || vars == 0) {
        *(s32 *)(vars + 0x70) = 0;
    } else {
        *(s32 *)(vars + 0x70) = hit;
    }
    return 1;
}

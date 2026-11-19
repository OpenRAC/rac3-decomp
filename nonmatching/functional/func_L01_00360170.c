/* functional: high. VU0 adds written as plain float adds; the w lane of base/points copies offset.w as retail's vadd.xyz stores. */
extern f32 D_L01_001DD710;
extern u8 D_001A4C60[];
void func_L01_00360170(u8 *obj) {
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_003C4C18(void *, f32);
    extern void func_L01_00360398(void *, s32, s32, s32, f32, f32, f32);
    S_38C110v hero_pos;
    S_38C110v angles;
    S_38C110v forward;
    S_38C110v points[20];
    S_38C110v base;
    S_38C110v offset;
    S_38C110v transformed;
    S_38C110v dir;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 i;
    f32 t, scale, spread, angle_step;
    D_L01_001DD710 -= 0.0275f;
    t = D_L01_001DD710;
    if (t < 0.0f) t = 0.0f;
    *(s128 *)&hero_pos = *(s128 *)D_001A4C60;
    func_003C5180(&hero_pos, &angles, 1);
    angle_step = 0.31415927f;
    func_0038CF68(&forward, *(u8 **)(D_001A4C60 + 0x2540) + 0xc0, 1.0f);
    scale = (1.0f - t) * 10.0f + 0.05f;
    spread = (1.0f - t) * 0.5f;
    if (func_L01_004CB2D8()) func_L01_004CAB30(vars, vars);
    *(s128 *)&base = *(s128 *)vars;
    func_L01_004C7D98(obj + 0x10, &offset);
    func_0038CF68(&offset, &offset, 0.75f);
    base.x += offset.x; base.y += offset.y; base.z += offset.z;
    base.w = offset.w; /* vadd.xyz stores offset's w */
    for (i = 0; i < 20; i++) {
        func_003C4840(&dir, &angles, i * angle_step);
        func_0038D850(&transformed, &forward, &dir);
        func_0038CE20((s128 *)&transformed, (s128 *)&transformed, scale);
        func_003C4C18(&transformed, spread);
        points[i].x = base.x + transformed.x; points[i].y = base.y + transformed.y; points[i].z = base.z + transformed.z;
        points[i].w = base.w;
    }
    func_L01_00360398(points, *(s32 *)(vars + 0x1c) * 5, *(s32 *)(vars + 0x1c) * 5, 20, 0.4f, 0.9f, 0.2f);
}

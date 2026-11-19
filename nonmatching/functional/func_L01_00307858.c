/* functional: medium. Written from the disassembly; callee argument order, colours, scales and the three bolt/glow blocks read against it. func_L01_00308DE0, func_L01_00308848, func_L01_003083E8, func_L01_00308E88 are declared as the file's own later definitions give them; func_L01_00308508/003086D0 as their drafts do. */
extern f32 D_001DC60C_sda;
extern f32 D_001DC610_sda;
extern f32 D_001DC5F4_sda;
__asm__(".extern D_001DC60C_sda, 4");
__asm__(".extern D_001DC610_sda, 4");
__asm__(".extern D_001DC5F4_sda, 4");
extern f32 D_002A7EA0[];
extern f32 D_0026FB30[];
extern vu0_v4 D_001E1710;
extern void func_003A9440(s32, s32);
extern void func_003CA4A0(void *, s32, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2F58(u8 *, s32, void *);
extern void func_L01_00308DE0(u8 *obj, s32 idx, f32 *out, f32 *off);
extern void func_L01_00308848(s32 unused, s32 target, u32 color, s32 n, f32 scale);
extern void func_L01_00308E88(vu0_v4 *position, s32 count, f32 scale);
extern void func_L01_00308508(s32 owner, vu0_v4 *start, vu0_v4 *end, u8 *controls);
extern void func_L01_003086D0(u8 *object, vu0_v4 *origin, vu0_v4 *out, f32 radius);
extern void func_L01_00448340(void *, void *, s32 *, f32, f32, f32);
extern s32 func_13D3E0(void);

/* lava_gun_draw: the Lava Gun's draw callback (queued by func_L01_003071C8): wobbles the gun's
   5 light offsets, puts glows on the barrel joints, draws lightning bolts from the barrel and the
   three side coils to a smoothed focus point, and occasionally throws sparks. */
void func_L01_00307858(u8 *self)
{
    u8 *p = *(u8 **)(self + 0x68);
    vu0_v4 v[5];
    vu0_v4 pts[5];
    vu0_v4 m[4];
    vu0_v4 rows[4];
    s32 id;
    s32 junk;
    s32 i;
    s32 r;
    f32 g;

    func_003A9440(0x47, 0x53001);
    func_L01_003083E8((s32)self, D_0026FB30, 4);
    id = 0;
    func_003CA4A0(self, 1, &id, m);
    m[3].w = 1.0f;
    m[3].x = 0.0f;
    m[3].y = 0.0f;
    m[3].z = 0.0f;
    D_002A7EA0[4] = func_0038D0B0(D_001DC60C_sda) * 0.015f + 0.4f;
    D_002A7EA0[6] = func_0038D098(D_001DC60C_sda) * 0.0149f;
    D_002A7EA0[5] = -func_0038D098(D_001DC610_sda) * 0.0151f;
    D_001DC60C_sda = func_0038DAB8(D_001DC60C_sda, 0.50265485f);
    D_001DC610_sda = func_0038DAB8(D_001DC610_sda, 0.4956735f);
    for (i = 0; i < 5; i++) {
        func_0038D028(&pts[i], &D_002A7EA0[i * 4], &m[0]);
    }
    func_L01_00308DE0(self, 0, (f32 *)&v[0], (f32 *)&pts[0]);
    func_L01_00308848((s32)self, (s32)&v[0], 0x7F7F2020, 0x40, 0.11f);
    func_L01_00308848((s32)self, (s32)&v[0], 0x7FFF4040, 0x78, 0.05f);
    func_L01_00308DE0(self, 0, (f32 *)&v[1], (f32 *)&pts[1]);
    if (D_001E1710.w == -1.0f) {
        D_001E1710 = v[1];
        D_001E1710.w = 0.0f;
    } else {
        junk = 0;
        func_L01_00448340(&D_001E1710, &v[1], &junk, 0.3f, 0.24000001f, 0.6f);
    }
    func_L01_00308848((s32)self, (s32)&D_001E1710, 0x7F00397F, 0x40, *(f32 *)(p + 0xC) * 2.25f * 0.082499996f);
    func_L01_00308848((s32)self, (s32)&D_001E1710, 0x7F0072FF, 0x78, *(f32 *)(p + 0xC) * 2.25f * 0.0375f);
    for (i = 1; i <= 3; i++) {
        func_L01_00308DE0(self, i, (f32 *)&v[i + 1], (f32 *)&pts[i + 1]);
        func_L01_00308848((s32)self, (s32)&v[i + 1], 0x7F7F2020, 0x40, 0.055f);
        func_L01_00308848((s32)self, (s32)&v[i + 1], 0x7FFF4040, 0x78, 0.025f);
    }
    func_L01_00308508((s32)self, &v[0], &D_001E1710, (u8 *)D_0026FB30);
    func_L01_003086D0(self, &D_001E1710, &rows[0], *(f32 *)(p + 0xC) * 0.35f);
    for (i = 2; i <= 4; i++) {
        vec_sub_ba(&rows[1], &D_001E1710, &v[i]);
        func_0038CF68(&rows[1], &rows[1], 1.0f);
        func_0038CE90(&rows[1], &rows[1], &rows[0]);
        func_0038CF68(&rows[1], &rows[1], 1.0f);
        func_0038CE90(&rows[1], &rows[1], &rows[0]);
        func_0038CF68(&rows[1], &rows[1], *(f32 *)(p + 0xC) * 0.45f);
        vec_add_ab(&rows[2], &rows[1], &D_001E1710);
        func_L01_00308508((s32)self, &v[i], &rows[2], (u8 *)D_0026FB30 + (i - 1) * 0x80);
        func_L01_00308848((s32)self, (s32)&rows[2], 0x7F7F2020, 0x40, 0.055f);
        func_L01_00308848((s32)self, (s32)&rows[2], 0x7FFF4040, 0x78, 0.025f);
        if (func_13D3E0() % 11 == 0 && D_001DC5F4_sda < *(f32 *)(p + 0xC)) {
            func_L01_00308E88(&rows[2], 1, 0.0f);
        }
    }
    for (i = 1; i <= 3; i++) {
        func_003C2F58(self, i, &rows[3]);
        func_L01_00308508((s32)self, &rows[3], &v[i + 1], (u8 *)D_0026FB30 + (4 - i) * 0x80);
        func_L01_00308848((s32)self, (s32)&rows[3], 0x7F7F2020, 0x40, 0.055f);
        func_L01_00308848((s32)self, (s32)&rows[3], 0x7FFF4040, 0x78, 0.025f);
    }
    if (func_13D3E0() % 11 == 0) {
        r = func_13D3E0();
        func_L01_00308E88(&v[1 + r % 4], 1, 0.001f);
    }
    func_003A9440(0x47, 0x5360B);
}

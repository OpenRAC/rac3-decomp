/* functional: high. Ground probe after the surface test: sets ground height/normal fields (+0x88,+0x8C,+0x90,+0x50,+0xD8) from the cast; 27 diff at default flags from scheduling only. */
extern void func_0038CF68(f32, void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern f32 func_0038CE68(void *, void *);
extern u8 D_L01_001EAA00[];

void func_L01_0045D5C0(u8 *a, u8 *o) {
    f32 v0[4];
    f32 v1[4];
    f32 v2[4];
    f32 v3[4];
    f32 v4[4];

    func_L01_0045D4B8(a, (u8 *)v0, 1);
    func_0038CF68(*(f32 *)(o + 8) + 0.1f, v1, v0);
    func_0038CF68(-*(f32 *)(o + 0xC) - 0.1f, v2, v0);
    vec_add_ba(v1, v1, a + 0x10);
    vec_add_ba(v2, v2, a + 0x10);
    if (func_003D3CB0(v1, v2, 0, a, 0) != 0) {
        func_0038CF68(1.0f, v4, v0);
        vec_sub_ab(v3, D_L01_001EAA00 + 0x20, a + 0x10);
        *(f32 *)(o + 0x90) = func_0038CE68(v4, v3);
        *(s32 *)(o + 0x88) = *(s32 *)(D_L01_001EAA00 + 0x18);
        *(s32 *)(o + 0x8C) = *(s32 *)(D_L01_001EAA00 + 0x1C);
        *(s32 *)(o + 0xD8) = -1;
        func_0038CF68(1.0f, o + 0x50, D_L01_001EAA00 + 0x40);
    } else {
        *(s32 *)(o + 0xD8) = -1;
        qzero(o + 0x50);
        *(f32 *)(o + 0x90) = -1000.0f;
        *(s32 *)(o + 0x88) = 0;
        *(s32 *)(o + 0x8C) = 0;
    }
}

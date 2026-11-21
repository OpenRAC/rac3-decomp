/* functional: high. Register-allocation difference only; 3F666666=0.9 damping, D_L01_001DFB40 is the frame counter. */
/* localdecomp:start func_L01_00471D88 */
extern struct { f32 pos[4]; } D_L01_001E2880;
extern s32 D_L01_001DFB40;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);

void func_L01_00471D88(u8 *p) {
    u8 *s = p + 0x20;
    u8 *q = p + 0x10;
    vu0_v4 vec;
    s32 life;

    func_0038CE20(s, s, 0.9f);
    vec_add_ab(q, q, s);
    if (*(f32 *)(s + 0x10) + 0.25f < *(f32 *)(p + 0x18)) {
        *(f32 *)(s + 8) = *(f32 *)(s + 8) - *(f32 *)(s + 0xC);
        p[8] += s[0x16];
        if (D_L01_001DFB40 % 10 == 0) {
            *(f32 *)(s + 0x1C) = func_0038DAB8(*(f32 *)(s + 0x1C), 1.0f);
            func_0038CF68(&vec, &D_L01_001E2880, func_0038D0B0(*(f32 *)(s + 0x1C)) * 0.0075f);
            vec_add_ab(s, s, &vec);
        }
    } else {
        vec = *(vu0_v4 *)q;
        vec.z = vec.z - 0.35f;
        if (func_003D3CB0(q, &vec, 2, 0, 0) == 0) {
            *(f32 *)(s + 0x10) = func_003C3D30(q, 0, 0, 0.5f);
        }
    }
    life = *(s16 *)(p + 0xA);
    if (life < *(s16 *)(s + 0x14)) {
        *(s32 *)(p + 4) = ((s32)((f32)life / (f32)*(s16 *)(s + 0x14) * 128.0f) << 24) | 0x50505;
    } else {
        *(s32 *)(p + 4) = 0x9F050505;
    }
    if (func_0038CB00((s16 *)(p + 0xA))) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_00471D88 */

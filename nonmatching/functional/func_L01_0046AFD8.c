/* functional: high. Same effects as retail: vector adds done in plain floats; w of pos set to 0 as retail does via the zero stack quad; collision result and D_L01_001EAA20 reset kept. */
extern u8 D_L01_001EAA20[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
void func_L01_0046AFD8(f32 *p) {
    f32 vx = p[0x30 / 4], vy = p[0x34 / 4], vz = p[0x38 / 4];
    p[0x10 / 4] += vx;
    p[0x14 / 4] += vy;
    p[0x18 / 4] += vz;
    p[0x1C / 4] = 0.0f;
    p[0x20 / 4] += vx;
    p[0x24 / 4] += vy;
    p[0x28 / 4] += vz;
    if (func_0038CB00((s16 *)((u8 *)p + 0xA))) {
        func_003CD250((Obj *)p);
    } else if (func_003D3CB0(p + 0x20 / 4, p + 0x10 / 4, 0x10, ((void **)p)[0x3C / 4], 0)) {
        *(s16 *)((u8 *)p + 0xA) = 0;
        *(vu0_q *)(p + 0x10 / 4) = *(vu0_q *)D_L01_001EAA20;
    }
}

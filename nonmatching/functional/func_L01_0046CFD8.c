/* functional: medium. Written from PAL asm, float constants taken from the immediates; vadd.xyz done per component with w kept. */
extern u8 D_L01_001EAA20[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
void func_L01_0046CFD8(u8 *p) {
    f32 *vf;
    f32 *pf = (f32 *)p;
    vu0_v4 t;
    if (p == 0) {
        return;
    }
    vf = (f32 *)(p + 0x20);
    vf[7] = vf[7] + 0.0f;
    pf[3] = pf[3] + -120.000008f;
    t = *(vu0_v4 *)(p + 0x10);
    t.x = pf[4] + vf[0];
    t.y = pf[5] + vf[1];
    t.z = pf[6] + vf[2];
    if (vf[0] != 0.0f || vf[1] != 0.0f || vf[2] != 0.0f) {
        if (func_003D3CB0(p + 0x10, &t, 2, p, 0)) {
            *(vu0_q *)(p + 0x10) = *(vu0_q *)D_L01_001EAA20;
            vf[0] = 0.0f;
            vf[1] = 0.0f;
            vf[2] = 0.0f;
            vf[3] = 0.0f;
            pf[3] = pf[3] + pf[3];
        } else {
            *(vu0_v4 *)(p + 0x10) = t;
            if (vf[3] == 0.0f) {
                vf[2] = vf[2] + -0.00907200016f;
            } else {
                vf[2] = vf[2] + vf[3];
            }
        }
    }
    if (vf[7] <= 0.0f || func_0038CB00((s16 *)(p + 0xA)) || pf[3] < 0.0f || t.x < 0.00999999978f ||
        t.y < 0.00999999978f || t.z < 0.00999999978f) {
        func_003CD250((Obj *)p);
        return;
    }
    vf[4] = vf[4] + -0.0120000001f;
    if (vf[4] < 0.0f) {
        vf[4] = 0.0f;
    }
    vf[5] = vf[5] + -0.0360120013f;
    if (vf[5] < 0.0f) {
        vf[5] = 0.0f;
    }
    vf[6] = vf[6] + -0.0600000024f;
    if (vf[6] < 0.0f) {
        vf[6] = 0.0f;
    }
    vf[7] = vf[7] + 0.0f;
    if (vf[7] < 0.0f) {
        vf[7] = 0.0f;
    }
    *(s32 *)(p + 4) = func_L01_00448CC0(vf[4], vf[5], vf[6], vf[7]);
    p[8] = p[8] - 1;
}

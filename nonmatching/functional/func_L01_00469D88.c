/* functional: medium. Written from PAL asm; sibling of func_L01_004693D8 (same fade/phase tail) with the child spawner func_L01_00469C18, a random-chance gate func_00382468(3) before the collision sweep, and fixed size steps. w of the stack quads passed to the spawner comes from the position quad (retail passes uninitialised stack); dead scale of an uninitialised stack quad kept on a zeroed local. */
extern u8 *D_L01_002210C8[];
extern u8 *func_L01_00469C18(vu0_q *, vu0_q *, u8, s32);
extern s32 func_003D3CB0(void *, void *, s32, s32, void *);
extern s32 func_00382468(s32);
void func_L01_00469D88(u8 *p) {
    u8 *v = p + 0x20;
    f32 *pf = (f32 *)p;
    f32 *vf = (f32 *)v;
    f32 spread, g, size, a, b, sign;
    vu0_v4 sp0, sp10, scratch;
    f32 packet[12] __attribute__((aligned(16)));
    s32 hit = 0;
    s32 idx;
    if (*(s16 *)(p + 0xA) != 0 && func_0038CB00(p + 0xA)) {
        f32 r;
        u8 *child;
        v[0x18] = v[0x18] | 0x88;
        size = (f32)v[0x19] * 0.03125f;
        spread = pf[3] / (size * 900000.0f);
        pf[3] = pf[3] * 0.8f;
        r = func_003824E0(0.5f, 0.7f);
        func_0038CE20(&sp0, v, r);
        sp10 = *(vu0_v4 *)(p + 0x10);
        sp10.x = pf[4] + func_003824E0(-spread, spread);
        sp10.y = pf[5] + func_003824E0(-spread, spread);
        sp10.z = pf[6] + func_003824E0(-spread, spread);
        sp0.x = sp0.x + func_003824E0(-vf[0] * 0.2f, vf[0] * 0.2f);
        sp0.y = sp0.y + func_003824E0(-vf[1] * 0.2f, vf[1] * 0.2f);
        sp0.z = sp0.z + func_003824E0(-vf[2] * 0.2f, 0.0f);
        child = func_L01_00469C18((vu0_q *)&sp10, (vu0_q *)&sp0, (v[0x18] & 0x10) | 0x88, *(s32 *)(v + 0x1C));
        if (child != 0) {
            *(s16 *)(child + 0xA) = 2;
            *(f32 *)(child + 0xC) = pf[3];
        }
        r = func_003824E0(0.5f, 0.7f);
        func_0038CE20(v, v, r);
        vf[0] = vf[0] + func_003824E0(-vf[0] * 0.2f, vf[0] * 0.2f);
        vf[1] = vf[1] + func_003824E0(-vf[1] * 0.2f, vf[1] * 0.2f);
        vf[2] = vf[2] + func_003824E0(-vf[2] * 0.2f, 0.0f);
        pf[4] = pf[4] + func_003824E0(-spread, spread);
        pf[5] = pf[5] + func_003824E0(-spread, spread);
        pf[6] = pf[6] + func_003824E0(-spread, spread);
    }
    idx = (*(s16 *)(p + 0xA) + *(s16 *)(v + 0x16) + (p[2] - D_L01_002210C8[0][0])) & 7;
    p[2] = D_L01_002210C8[0][idx];
    sp0 = *(vu0_v4 *)(p + 0x10);
    sp0.x = pf[4] + vf[0];
    sp0.y = pf[5] + vf[1];
    sp0.z = pf[6] + vf[2];
    sp10 = *(vu0_v4 *)(p + 0x10);
    if (*(s16 *)(v + 0x14) >= 3) {
        sp10.x = pf[4] - vf[0];
        sp10.y = pf[5] - vf[1];
        sp10.z = pf[6] - vf[2];
    }
    scratch.x = scratch.y = scratch.z = scratch.w = 0.0f;
    func_0038CE20(&scratch, &scratch, 0.01f);
    if (v[0x18] & 8) {
        if ((*(u32 *)(p + 4) & 0xFF000000) == 0) {
            func_003CD250(p);
            return;
        }
        v[0x18] = v[0x18] | 8;
        if (func_00382468(3) == 0 && !(v[0x18] & 0x10)) {
            hit = func_003D3CB0(&sp10, &sp0, 0, *(s32 *)(v + 0x1C), 0) != 0;
        }
    } else {
        *(vu0_q *)&packet[0] = *(vu0_q *)v;
        *(s32 *)&packet[4] = *(s32 *)(v + 0x1C);
        *(s32 *)&packet[5] = 1;
        packet[7] = 1.0f;
        *(s32 *)&packet[8] = 1;
        if (func_00382468(3) == 0 && !(v[0x18] & 0x10)) {
            hit = func_003D3CB0(&sp10, &sp0, 0, *(s32 *)(v + 0x1C), packet) != 0;
        }
    }
    if (hit) {
        v[0x18] = v[0x18] | 8;
    } else {
        *(vu0_q *)(p + 0x10) = *(vu0_q *)&sp0;
    }
    if (v[0x18] & 8) {
        *(u16 *)(v + 0x16) = *(u16 *)(v + 0x16) + 1;
        pf[3] = pf[3] - 26000.002f;
        if (pf[3] <= 0.0f) {
            func_003CD250(p);
            return;
        }
    } else {
        pf[3] = pf[3] + 20800.002f;
    }
    g = (f32)*(s16 *)(v + 0x14) / 15.0f * 0.0064f + 0.08f;
    if (g < 0.0f) {
        g = 0.0f;
    }
    if (0.08f < g) {
        g = 0.08f;
    }
    if (v[0x18] & 8) {
        g = g / ((f32)*(s16 *)(v + 0x16) / 7.0f + 1.0f);
    }
    *(u32 *)(p + 4) = (*(u32 *)(p + 4) & 0xFFFFFF) | ((u32)(s32)(g * 256.0f) << 24);
    vf[2] = vf[2] + 0.01152f;
    if (*(s16 *)(v + 0x14) >= 0x16 || (v[0x18] & 8)) {
        vf[0] = vf[0] * 0.95f;
        vf[1] = vf[1] * 0.95f;
    }
    sign = -1.0f;
    if (v[0x18] & 1) {
        sign = 1.0f;
    }
    if (v[0x18] & 8) {
        vf[4] = vf[4] + sign * -0.012f / (f32)*(s16 *)(v + 0x16);
        vf[2] = vf[2] + 0.01152f;
    } else {
        vf[4] = vf[4] + sign * -0.012f;
    }
    if (vf[4] > 1.0f) {
        vf[4] = vf[4] - 1.0f;
    }
    if (vf[4] < 0.0f) {
        vf[4] = vf[4] + 1.0f;
    }
    p[8] = (s32)(vf[4] * 256.0f);
}

/* functional: medium. Written from PAL asm. Differences: w of the two stack quads passed to func_L01_00469210 is taken from the position quad (retail passes uninitialised stack); the dead scale of an uninitialised stack quad (func_0038CE20 on sp+0x20) is kept on a zeroed local. Prototypes of func_0038CB00/func_003CD250 follow this unit (u8 *). */
extern u8 *D_L01_002210C8[];
extern u8 D_001EAA20[];
extern u8 D_001EAA40[];
extern void func_L01_0040E790(void *, void *, void *);
extern u8 *func_L01_00469210(vu0_q *, vu0_q *, u8, s32, u8, s32);
extern s32 func_003D3CB0(void *, void *, s32, s32, void *);
void func_L01_004693D8(u8 *p) {
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
        child = func_L01_00469210((vu0_q *)&sp10, (vu0_q *)&sp0, (v[0x18] & 0x10) | 0x88, *(s32 *)(v + 0x1C), v[0x19], 0x80);
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
        if (!(v[0x18] & 0x10)) {
            hit = func_003D3CB0(&sp10, &sp0, 4, *(s32 *)(v + 0x1C), 0) != 0;
        }
    } else {
        *(vu0_q *)&packet[0] = *(vu0_q *)v;
        *(s32 *)&packet[4] = *(s32 *)(v + 0x1C);
        *(s32 *)&packet[5] = 0x10001;
        packet[7] = 1.0f;
        if (v[0x18] & 0x40) {
            packet[0] = packet[1] = packet[2] = packet[3] = 0.0f;
        }
        *(s32 *)&packet[8] = 1;
        if (!(v[0x18] & 0x10)) {
            hit = func_003D3CB0(&sp10, &sp0, 0, *(s32 *)(v + 0x1C), packet) != 0;
        }
    }
    if (hit) {
        vu0_v4 n;
        func_0038CF68(&n, D_001EAA40, 1.0f);
        func_L01_0040E790(v, v, D_001EAA40);
        func_0038CE20(v, v, 0.02f);
        func_0038CF68(&n, D_001EAA40, 0.055f);
        *(vu0_v4 *)(p + 0x10) = *(vu0_v4 *)D_001EAA20;
        pf[4] = ((f32 *)D_001EAA20)[0] + n.x;
        pf[5] = ((f32 *)D_001EAA20)[1] + n.y;
        pf[6] = ((f32 *)D_001EAA20)[2] + n.z;
        if (pf[3] < 200000.0f && !(v[0x18] & 8)) {
            pf[3] = pf[3] + pf[3];
        }
        v[0x18] = v[0x18] | 8;
    } else {
        *(vu0_q *)(p + 0x10) = *(vu0_q *)&sp0;
    }
    size = (f32)v[0x19] * 0.03125f;
    a = size * 30000.0f;
    b = size * 270000.0f;
    if (v[0x18] & 8) {
        *(u16 *)(v + 0x16) = *(u16 *)(v + 0x16) + 1;
        pf[3] = pf[3] - ((b - a) / 15.0f * 1.2f) * 1.25f;
        if (pf[3] <= 0.0f) {
            func_003CD250(p);
            return;
        }
    } else {
        pf[3] = pf[3] + (b - a) / 15.0f * 1.2f;
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

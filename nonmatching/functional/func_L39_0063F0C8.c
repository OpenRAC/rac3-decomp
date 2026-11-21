/* functional: medium. The obfuscated-state decode (index byte -> scrambled 8 bytes from D_L39_004997E0, as the matched neighbours inline it) is a helper here; the VU0 vector adds are plain C with retail's w lanes. Unknown names: the object at *(g+0x2524) (the hero's mover/camera target) and what the 0x12/0x31/0x8F/0x03/0x0E/0x7A/0x90/0x66/0x11/0x04 state values mean. */
extern u8 D_L39_004997E0[];
extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
extern f32 D_L39_00246130[];
extern f32 D_L39_00246138[];
extern f32 D_L39_00246060;
extern f32 D_L39_002935E0[];
extern u8 D_L39_0025F740[];
extern f32 D_L39_0025F760[];
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_0043BA48(s32, f32 *);
extern s32 func_L39_005BE900(void *, s32, f32);

/* reads the obfuscated 32-bit state whose index byte is *q (0 when unset) */
static u32 dec_state_0063F0C8(u8 *q) {
    u32 buf[2];
    u8 *b;
    s32 n, m, k, i;
    if (*q == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((u32)q - n) & 7;
    b = (u8 *)buf;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf[0] ^= (u32)q;
    buf[1] ^= buf[0];
    return buf[1];
}

void func_L39_0063F0C8(u8 *g) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    u8 *p;
    f32 f;
    f32 ang;
    f32 angle;
    f32 sy;
    f32 cy;
    f32 sa;
    f32 ca;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 f24;
    f32 d;
    s32 k;
    s32 gate;

    gate = 0;
    if (dec_state_0063F0C8(g + 0x19E6) == 0x12) gate = 1;
    else if (dec_state_0063F0C8(g + 0x19E4) == 0x31) gate = 1;
    else if (dec_state_0063F0C8(g + 0x19E4) == 0x8F) gate = 1;
    else if (dec_state_0063F0C8(g + 0x19E6) == 0x03) gate = 1;
    else if (dec_state_0063F0C8(g + 0x19E6) == 0x0E) gate = 1;
    else if (dec_state_0063F0C8(g + 0x19E4) == 0x7A) gate = 1;
    else if (dec_state_0063F0C8(g + 0x19E4) == 0x90 && dec_state_0063F0C8(g + 0x19E7) == 0x7A) gate = 1;
    else if (dec_state_0063F0C8(g + 0x19E4) == 0x66 && *(s32 *)(g + 0x13D4) != 0) gate = 1;

    if (gate) {
        if (dec_state_0063F0C8(g + 0x19E6) == 0x12) {
            *(f32 *)(g + 0xFA0) = 1.56f;
        }
        p = *(u8 **)(g + 0x2524);
        *(u16 *)(p + 0x34) &= 0xFBFF;
        return;
    }

    p = *(u8 **)(g + 0x2524);
    *(u16 *)(p + 0x34) |= 0x400;
    p = *(u8 **)(g + 0x2524);
    if (*(f32 *)(p + 0xE8) < 0.99f) {
        if (dec_state_0063F0C8(g + 0x19E6) != 0x11) {
            p = *(u8 **)(g + 0x2524);
            p[0xBD] = 0xFF;
            func_0038CE20(v0, *(u8 **)(g + 0x2524), 0.0009765625f);
            p = *(u8 **)(g + 0x2524);
            func_0038CE20(v10, p + 0xE0, -16.0f);
            v10[0] = v0[0] + v10[0];
            v10[1] = v0[1] + v10[1];
            v10[2] = v0[2] + v10[2];
            v10[3] = v0[3];
            if (func_003D3CB0(v0, v10, 0x22, 0, 0) != 0) {
                p = *(u8 **)(g + 0x2524);
                v20[0] = D_L39_0025F760[0] - ((f32 *)(p + 0x10))[0];
                v20[1] = D_L39_0025F760[1] - ((f32 *)(p + 0x10))[1];
                v20[2] = D_L39_0025F760[2] - ((f32 *)(p + 0x10))[2];
                v20[3] = D_L39_0025F760[3];
                d = func_0038CE68(v20, p + 0xE0);
                p = *(u8 **)(g + 0x2524);
                *(f32 *)(p + 0x70) = d;
                p = *(u8 **)(g + 0x2524);
                *(f32 *)(p + 0x74) = *(f32 *)(p + 0xC) * 0.000244140625f;
            } else {
                p = *(u8 **)(g + 0x2524);
                *(s32 *)(p + 0x70) = 0;
                p = *(u8 **)(g + 0x2524);
                *(s32 *)(p + 0x74) = 0;
            }
            *(f32 *)(g + 0xFA0) = 1.56f;
            return;
        }
    }

    p = *(u8 **)(g + 0x2524);
    p[0xBD] = g[0x2544] + 4;
    f = 1.16f;
    if (*(s16 *)(g + 0x2DE) != 0 || dec_state_0063F0C8(g + 0x19E6) == 0x04) {
        f = 1.56f;
    }
    d = func_0038DB00(f, *(f32 *)(g + 0xFA0));
    if (0.052f < d) {
        d = 0.052f;
    } else if (d < -0.052f) {
        d = -0.052f;
    }
    *(f32 *)(g + 0xFA0) = func_0038DAB8(*(f32 *)(g + 0xFA0), d);

    f23 = *(f32 *)(g + 0x2A8);
    if (f23 < 1.0f) {
        f23 = *(f32 *)(g + 0x2C0);
        if (!(1.0f <= f23)) {
            f23 = *(f32 *)(g + 0x2C4);
            if (!(1.0f < f23)) {
                p = *(u8 **)(g + 0x2524);
                *(s32 *)(p + 0x70) = 0;
                p = *(u8 **)(g + 0x2524);
                *(s32 *)(p + 0x74) = 0;
                return;
            }
        }
    }
    p = *(u8 **)(g + 0x2524);
    *(f32 *)(p + 0x70) = f23 - *(f32 *)(p + 0x18);
    p = *(u8 **)(g + 0x2524);
    *(f32 *)(p + 0x74) = 0.18f;
    f = *(f32 *)(g + 0xFA0) - 1.56f;
    if (f < 0.0f) f = -f;
    if (f < 0.1f) {
        return;
    }
    if (g[0x1A14] != 0 && *(s32 *)(g + 0x1310) == 2 && *D_00241120 == 1) {
        return;
    }

    p = *(u8 **)(g + 0x2524);
    v0[0] = ((f32 *)(p + 0x10))[0];
    v0[1] = ((f32 *)(p + 0x10))[1];
    v0[2] = *(f32 *)(g + 0x2A8);
    v0[3] = 1.5f;
    if (func_L39_005BE900(v0, 0, 28.0f) < 0) {
        return;
    }
    func_L01_0043BA48(*(s32 *)(g + 0x2524), v0);
    f22 = f23;
    f24 = f22;
    angle = func_0038D160(v0[0], v0[1]);
    sa = func_0038D098(angle);
    ca = func_0038D0B0(angle);
    sy = func_0038D098(*(f32 *)(g + 0xFA0));
    v0[1] = ca * sy;
    v0[0] = sa * sy;
    cy = func_0038D0B0(*(f32 *)(g + 0xFA0));
    v0[2] = -cy;
    ((f32 *)((u8 *)D_L39_002935E0 + *(s32 *)(g + 0x2544) * 16))[0] = v0[0];
    ((f32 *)((u8 *)D_L39_002935E0 + *(s32 *)(g + 0x2544) * 16))[1] = v0[1];
    ((f32 *)((u8 *)D_L39_002935E0 + *(s32 *)(g + 0x2544) * 16))[2] = v0[2];
    ((f32 *)((u8 *)D_L39_002935E0 + *(s32 *)(g + 0x2544) * 16))[3] = v0[3];
    for (k = 0; k < 2; k++) {
        p = *(u8 **)(g + 0x2524);
        f21 = *(f32 *)(p + 0xC) * 0.0009765625f;
        func_0038CE20(v10, p, 0.0009765625f);
        f20 = func_0038DAB8(angle, D_L39_00246138[k]);
        v10[0] = v10[0] + func_0038D098(f20) * 0.35f * f21;
        d = func_0038D0B0(f20) * 0.35f * f21;
        v10[2] = v10[2] + D_L39_00246130[k] * f21;
        v10[1] = v10[1] + d;
        func_0038CF68(v20, v0, ((v10[2] - f23) + 0.5f) * 2.0f / -v0[2]);
        v20[0] = v10[0] + v20[0];
        v20[1] = v10[1] + v20[1];
        v20[2] = v10[2] + v20[2];
        if (func_003D3CB0(v10, v20, 0x22, 0, 0) != 0) {
            f = *(f32 *)(D_L39_0025F740 + 0x28);
            if (f22 < f) f22 = f;
            if (f < f24) f24 = f;
        }
    }
    p = *(u8 **)(g + 0x2524);
    *(f32 *)(p + 0x70) = (f24 + f22) * 0.5f - *(f32 *)(p + 0x18) + D_L39_00246060;
    p = *(u8 **)(g + 0x2524);
    *(f32 *)(p + 0x74) = (f22 - f24) * 0.5f + 0.12f;
    p = *(u8 **)(g + 0x2524);
    f = *(f32 *)(p + 0x74);
    if (1.0f < f) {
        *(f32 *)(p + 0x74) = 1.0f;
        p = *(u8 **)(g + 0x2524);
        *(f32 *)(p + 0x70) = *(f32 *)(p + 0x70) + (f - 1.0f) * 0.5f;
    }
}

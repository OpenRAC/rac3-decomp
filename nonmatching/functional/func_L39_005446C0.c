/* functional: medium. Free-look camera update (the 0x2B0/0x2B4 springs, stick/button input); retail reads uninitialised stack (sp+0x40, sp+0x50) when o->3BC == 0, here those locals start at zero. Vector adds are plain xyz adds (retail's vadd.xyz keeps w). */
__asm__(".extern D_L39_00241164, 16");
extern u8 *D_L39_00241164;
__asm__(".extern D_L39_0024BB90, 4");
extern s32 D_L39_0024BB90;
extern u8 D_001A5810[];
extern s32 D_001A58D0[][8];
extern s32 D_001A5930[][8];
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L39_00543AA8(void *);
extern f32 func_L01_00448728(f32 *, f32 *, s32, f32, f32, f32, f32);

s32 func_L39_005446C0(u8 *a) {
    u8 *o = *(u8 **)(a + 0x68);
    u8 *pad = D_L39_00241164;
    u8 *g;
    u8 *pl;
    u8 *vec = o + 0x290;
    f32 m0[16];
    f32 lv40[4];
    f32 lv50[4];
    f32 lv60[4];
    f32 m70[16];
    f32 q80[4];
    s32 res;
    s32 idx;
    s32 b;
    s32 btn;
    f32 f20, f21, f22, f23, f5, f1, f0, t, d, len;

    lv40[0] = 0.0f; lv40[1] = 0.0f; lv40[2] = 0.0f; lv40[3] = 0.0f;
    lv50[0] = 0.0f; lv50[1] = 0.0f; lv50[2] = 0.0f; lv50[3] = 0.0f;

    g = *(u8 **)(o + 0x384);
    if (g != 0) {
        pl = *(u8 **)(g + 0x2D8);
        if (pl != 0) {
            if (*(u8 *)(pl + 0x1A14) != 0) {
                D_L39_0024BB90 = 2;
                *(s32 *)(g + 0x2F8) |= 0x800;
            }
            pad = *(u8 **)(*(u8 **)(*(u8 **)(o + 0x384) + 0x2D8) + 0x2534);
        }
    }

    if (*(s32 *)(o + 0x3BC) != 0) {
        func_0038D5B0(m0, a + 0xC0);
        func_0038D028(lv40, vec, m0);
    }

    f1 = *(f32 *)(o + 0x2A8) * 0.899999976f;
    f20 = *(f32 *)(o + 0x298) * 0.949999988f;
    *(f32 *)(o + 0x2A8) = f1;
    func_0038CE20(vec, vec, 0.980000019f);
    *(f32 *)(o + 0x298) = f20;

    g = *(u8 **)(o + 0x384);
    pl = *(u8 **)(g + 0x2D8);
    idx = *(s32 *)(pl + 0x2544);
    f0 = *(f32 *)(pl + 0x110);
    b = D_001A5810[0xA4 + idx];
    if (*(s32 *)(o + 0x3BC) != 0) {
        f0 = -f0;
    }
    f22 = f0;
    f23 = -1.0f;
    if (D_001A58D0[b][idx] != 0) {
        f23 = 1.0f;
    }
    f1 = 1.0f;
    if (D_001A5930[b][idx] != 0) {
        f1 = -1.0f;
    }
    *(s32 *)(pl + 0x2D0) = 0;
    if (b == 0) {
        f1 = 1.0f;
    }
    f0 = -*(f32 *)(pad + 0x100);
    btn = *(s32 *)(pad + 0x1A0);
    pl = *(u8 **)(*(u8 **)(o + 0x384) + 0x2D8);
    f5 = f0 * f1;
    f21 = *(f32 *)(pl + 0x114);
    f20 = 0.0f;
    if (btn & 4) {
        f20 = 1.0f;
    }
    if (btn & 1) {
        f20 -= 1.0f;
    }
    if (btn & 0x40) {
        f20 += 1.0f;
    }
    if (btn & 0x80) {
        f20 -= 1.0f;
    }
    if (1.0f < f20) {
        f20 = 1.0f;
    }
    if (f20 < -1.0f) {
        f20 = -1.0f;
    }
    if (*(u8 **)(o + 0x384) != 0 && pl != 0 && *(s16 *)(pl + 0x320) > 0) {
        f5 = 0.0f;
        f20 = 0.0f;
        f21 = 0.0f;
        f22 = 0.0f;
    }

    f1 = *(f32 *)(o + 0x390);
    f0 = (f20 + 1.0f) * 0.5f * 0.087266475f + 0.052359879f;
    d = f0 - f1;
    if (0.00349065871f < d) {
        d = 0.00349065871f;
    } else if (d < -0.00349065871f) {
        d = -0.00349065871f;
    }
    *(f32 *)(o + 0x390) = f1 + d;
    f5 *= 0.00293215318f;
    f22 *= 0.00800000038f;
    f21 *= 0.0140000004f;
    f20 *= 0.0140000004f;
    f0 = func_0038DAB8(*(f32 *)(o + 0x2A8), f5);
    *(f32 *)(o + 0x2A8) = f0;
    if (0.209439516f < f0) {
        *(f32 *)(o + 0x2A8) = 0.209439516f;
    } else if (f0 < -0.209439516f) {
        *(f32 *)(o + 0x2A8) = -0.209439516f;
    }
    if (*(s32 *)(o + 0x3BC) != 0) {
        *(f32 *)(a + 0xF8) = func_0038DAB8(*(f32 *)(a + 0xF8), *(f32 *)(o + 0x2A8));
    }
    f0 = *(f32 *)(a + 0xF8);
    q80[0] = 0.0f; q80[1] = 0.0f; q80[2] = f0; q80[3] = 0.0f;
    lv60[0] = f21;
    lv60[1] = f22;
    lv60[2] = f20;
    func_0038D328(m70, q80);
    func_0038D028(lv60, lv60, m70);
    *(f32 *)(o + 0x290) += lv60[0];
    *(f32 *)(o + 0x294) += lv60[1];
    *(f32 *)(o + 0x298) += lv60[2];
    len = func_0038CED8(vec);
    f21 = len;
    if (0.480000019f < len) {
        f20 = 0.480000019f / len;
        *(f32 *)(o + 0x290) *= f20;
        *(f32 *)(o + 0x294) *= f20;
        f21 = 0.480000019f;
    }
    *(f32 *)(*(u8 **)(o + 0x384) + 0x310) = f21;
    f0 = *(f32 *)(o + 0x298);
    if (0.280000031f < f0) {
        *(f32 *)(o + 0x298) = 0.280000031f;
    } else if (f0 < -0.280000031f) {
        *(f32 *)(o + 0x298) = -0.280000031f;
    }
    {
        u8 *g2 = *(u8 **)(o + 0x384);
        f32 *src = (f32 *)(o + 0x290);
        f32 *dst = (f32 *)(g2 + 0x270);
        dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];
    }
    res = func_L39_00543AA8(a);

    if (*(s32 *)(o + 0x3BC) != 0) {
        f0 = *(f32 *)(o + 0x394);
        f1 = *(f32 *)(o + 0x39C);
    } else {
        f0 = *(f32 *)(o + 0x39C);
        f1 = *(f32 *)(o + 0x394);
    }
    f5 = (f0 - f1) * -0.8f;
    func_L01_00448728((f32 *)(o + 0x2B0), (f32 *)(o + 0x2A0), 0, f5, 0.0100800004f, 0.288000017f, 0.0244346112f);
    f0 = *(f32 *)(o + 0x2B0);
    if (0.3f < f0) {
        *(f32 *)(o + 0x2B0) = 0.3f;
    }
    if (*(f32 *)(o + 0x2B0) < -0.3f) {
        *(f32 *)(o + 0x2B0) = -0.3f;
    }
    if (*(s32 *)(o + 0x3BC) != 0) {
        *(f32 *)(a + 0xF0) = *(f32 *)(o + 0x2B0);
    }

    f1 = *(f32 *)(pad + 0x104);
    g = *(u8 **)(o + 0x384);
    if (g != 0 && *(u8 **)(g + 0x2D8) != 0 && *(s16 *)(*(u8 **)(g + 0x2D8) + 0x320) > 0) {
        f1 = 0.0f;
    }
    f0 = f1 * -0.0120000001f * f23;
    f1 = 20.0f * 0.0174532924f;
    t = *(f32 *)(o + 0x350) + f0;
    *(f32 *)(o + 0x350) = t;
    if (f1 < t) {
        *(f32 *)(o + 0x350) = f1;
    }
    f0 = -15.0f * 0.0174532924f;
    if (*(f32 *)(o + 0x350) < f0) {
        *(f32 *)(o + 0x350) = f0;
    }
    if (*(s32 *)(o + 0x3BC) != 0) {
        *(f32 *)(a + 0xF4) = *(f32 *)(o + 0x350);
        if (*(s32 *)(o + 0x3BC) != 0) {
            func_0038D028(lv50, vec, m0);
        }
    }
    f5 = (lv50[0] - lv40[0]) * 45.0f;
    f21 = 0.00800000038f;
    if (fabs_asm(f5) <= 0.00100000005f) {
        f21 = 0.000800000038f;
    }
    func_L01_00448728((f32 *)(o + 0x2B4), (f32 *)(o + 0x2A4), 0, f5, f21 * 1.44000006f, 0.288000017f, 0.0349065885f);
    f0 = *(f32 *)(o + 0x2B4);
    if (0.55f < f0) {
        *(f32 *)(o + 0x2B4) = 0.55f;
    }
    if (*(f32 *)(o + 0x2B4) < -0.5f) {
        *(f32 *)(o + 0x2B4) = -0.5f;
    }
    if (*(s32 *)(o + 0x3BC) != 0) {
        *(f32 *)(a + 0xF4) = func_0038DAB8(*(f32 *)(a + 0xF4), *(f32 *)(o + 0x2B4));
    }
    return res;
}

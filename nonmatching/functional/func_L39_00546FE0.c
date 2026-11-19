/* functional: medium. Per-frame update of a multiplayer-menu player blip/spawn object (states 1-3, 6): reads the 0x1A40 event buffer, picks its colour and spawns the effect, then in state 2 runs 20 swept probes with func_L39_00547E10 and in state 3 launches the object. The tamper-checked value at g+0x19E4/0x19E6 is read through the same decode as retail. The scratch block at sp+0x70 is written but never passed to a callee in retail; kept as a local. */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L39_004997E0[];
extern u8 D_L39_0049C890[];
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
extern void *D_L39_002637C0[];
extern u8 D_L39_00470480[];
extern u8 D_L39_0024DE80[];
__asm__(".extern D_L39_0024AF90, 4");
extern u8 D_L39_0024AF90;
__asm__(".extern D_L39_0024AFA0, 4");
extern s32 D_L39_0024AFA0;
__asm__(".extern D_L39_0024AFA4, 4");
extern s32 D_L39_0024AFA4;
__asm__(".extern D_L39_0024AFA8, 4");
extern s32 D_L39_0024AFA8;
__asm__(".extern D_L39_0024AFAC, 4");
extern s32 D_L39_0024AFAC;
__asm__(".extern D_L39_0024AFB0, 4");
extern s32 D_L39_0024AFB0;
__asm__(".extern D_L39_0024AFD4, 4");
extern s32 D_L39_0024AFD4;

extern void func_L39_0061C4D0(u8 *, u8 **);
extern s32 func_0038CB00(void *);
extern void func_0038CAD0(void *);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern s32 func_L01_0040E050(void *);
extern s32 func_L39_00639D90(void *);
extern void func_L39_00546F30(s32, f32 *, f32 *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L39_005FFD20(void *, void *, s32, f32);
extern s32 func_L39_00620CF8(void *, s32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L39_00674320(void *);
extern s32 func_L39_006732D0(void *, s32, s32, void *);
extern s32 func_L39_00648AE0(void *, s32);
extern void func_L39_00621D60(void *, s32);
extern s32 func_L01_003F2058(void *, void *);
extern void func_L01_003F2278(s32, void *);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4410(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00457588(void *, void *, f32, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L39_00548130(void *, void *);
extern void func_L39_00548648(void *);
extern s32 func_L39_00547E10(u8 *, void *, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern void func_0038D328(void *, void *);
extern void func_0038D590(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D850(void *, void *, void *);
extern void func_003C4840(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_00446978(void *, void *);

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_00546FE0;

static __inline__ u32 decode_00546FE0(u8 *p) {
    Buf_00546FE0 buf;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

static __inline__ u8 *cfg_00546FE0(u8 *g) {
    if (func_L39_00648AE0(g, 2) != 0) {
        return D_L39_0049C890 + ((s8)D_L39_0049C890[0x121] << 7);
    }
    return D_L39_0049C890 + 0x100;
}

void func_L39_00546FE0(u8 *a) {
    u8 *ex = *(u8 **)(a + 0x68);
    u8 *g;
    u8 *cfg;
    u32 col;
    s32 r17;
    s32 v;
    s32 i;
    s32 n;
    s32 cnt;
    f32 f;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 sb[24] __attribute__((aligned(16)));
    f32 limit[4] __attribute__((aligned(16)));
    f32 v00[4] __attribute__((aligned(16)));
    f32 v60[4] __attribute__((aligned(16)));
    f32 v90[4] __attribute__((aligned(16)));
    f32 vA0[4] __attribute__((aligned(16)));
    f32 vB0[4] __attribute__((aligned(16)));
    f32 vC0[4] __attribute__((aligned(16)));
    f32 vD0[16] __attribute__((aligned(16)));
    f32 v100[16] __attribute__((aligned(16)));
    f32 m130[16] __attribute__((aligned(16)));
    f32 v170[4] __attribute__((aligned(16)));
    f32 v180[4] __attribute__((aligned(16)));
    s32 w190[20];
    s32 w1E0[20];
    f32 q230[4] __attribute__((aligned(16)));
    f32 v240[4] __attribute__((aligned(16)));
    f32 v250[4] __attribute__((aligned(16)));
    f32 v260[4] __attribute__((aligned(16)));
    u8 blk70[0x20];
    u8 *obj;
    u8 *ent;

    if (a[0x20] == 0) {
        a[0x20] = 1;
        *(s16 *)(ex + 8) = 0;
        *(s16 *)(ex + 0xA) = 0;
        *(s32 *)(ex + 0x4C) = -1;
        func_L39_0061C4D0(a, (u8 **)(ex + 0x50));
    }
    g = *(u8 **)(ex + 0x50);
    if (g == 0) {
        return;
    }
    if (a[0x20] == 6) {
        if (func_0038CB00(ex + 4) != 0) {
            func_L39_005F33E0(2, 0, a);
            a[0x20] = 1;
        }
    }
    if (a[0x42] == a[0x43] && (a[0x60] & 2) != 0) {
        func_L01_00444F38(a, 1, 0, 2, 0);
    }
    if (decode_00546FE0(g + 0x19E4) == 1) {
        (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(g + 0x14) + 0x34))(g, 0x1D, 0, 0, 1);
    }
    func_L01_0040E050(ex);

    if (g[0x1A14] != 0 && func_L39_00639D90(g) != 0) {
        if (0.800000012f <= *(f32 *)(g + 0x1250)) {
            *(s32 *)(g + 0x1078) = *(s32 *)(g + 0x122C);
            func_L39_00546F30(*(s32 *)(g + 0x122C), &limit[0], 0);
            f = func_0038CF00(g + 0xA0, *(u8 **)(g + 0x122C) + 0x10);
            if (f < limit[0]) {
                col = 0x700000FF;
            } else {
                col = 0x601080FF;
            }
        } else {
            col = func_L39_005FFD20(g + 0x1338, g + 0x133C, 0, 150.0f);
        }
    } else if (g[0x1A14] != 0 && decode_00546FE0(g + 0x19E4) == 0x1D) {
        col = 0x600FFF0F;
        if (0.0f < *(f32 *)ex) {
            if (func_L39_00620CF8(g, -1) != 0) {
                col = 0x600000FF;
            }
        }
    } else {
        if (g[0x1A14] == 0) {
            func_L39_00674320(g);
        }
        goto after_colour;
    }
    if (g[0x1A14] != 0) {
        func_L01_003F6F20(g[0x24C9], a, col, 0, 0x20, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
    }
after_colour:
    if (*(s32 *)(g + 0x3E0) != 0) {
        *(s32 *)(g + 0x1078) = *(s32 *)(g + 0x3E0);
    }
    if (a[0x20] == 1) {
        g[0x1A0D] = 0;
    } else {
        g[0x1A0D] = 1;
    }
    r17 = func_L39_006732D0(g + 0x1A40, 0, 1, sb);
    if (r17 == 8) {
        s32 want = (*(u8 **)(g + 0x2524))[0x43];
        cfg = cfg_00546FE0(g);
        if (want == *(s16 *)(cfg + 0xC)) {
            goto set_a;
        }
        v = decode_00546FE0(g + 0x19E6);
        if (v != 0) {
            goto set_a;
        }
        if (g[0x1A08] == 0) {
            *(s16 *)(ex + 6) = 2;
            *(s16 *)(ex + 8) = (D_L39_0024AFA4 * 5 + 2) / 6;
            *(s32 *)(ex + 0x48) = 0;
            *(s16 *)(ex + 0xA) = (D_L39_0024AFAC * 5 + 2) / 6;
            goto set_b;
        }
set_a:
        *(s32 *)(ex + 0x48) = 1;
        *(s16 *)(ex + 0xA) = (D_L39_0024AFB0 * 5 + 2) / 6;
        *(s16 *)(ex + 6) = (D_L39_0024AFA0 * 5 + 2) / 6;
        *(s16 *)(ex + 8) = (D_L39_0024AFA8 * 5 + 2) / 6;
set_b:
        if (g[0x1A14] == 0) {
            *(f32 *)(ex + 0x54) = sb[15];
            *(f32 *)(ex + 0x58) = sb[16];
            *(f32 *)(ex + 0x5C) = sb[17];
        }
        func_L39_00621D60(g, -1);
        *(s32 *)(ex + 0x4C) = func_L01_003F2058(D_L39_00470480, *(void **)(g + 0x2534));
        a[0x20] = 2;
        *(f32 *)(ex + 0xC) = func_L39_005B44C8();
        func_003C3A10(a, 2, 0, 0);
        *(f32 *)(ex + 0x20) = 1.0f / (f32)*(s16 *)(ex + 8);
        *(f32 *)(ex + 0x24) = 1.0f / (f32)*(s16 *)(ex + 0xA);
        *(f32 *)(ex + 0x28) = func_L39_005B44C8();
        *(f32 *)(ex + 0x2C) = func_L39_005B44C8();
        v = (D_L39_0024AFD4 * 5 + 2) / 6;
        *(s32 *)(ex + 0x40) = v;
        *(f32 *)(ex + 0x44) = 1.0f / (f32)v;
    } else if (r17 == 4) {
        func_L39_005F33E0(4, 0, a);
    }

    if (r17 != 8 || g[0x1A07] == 0) {
        if (*(s32 *)(ex + 0x4C) >= 0) {
            func_L01_003F2278(*(s32 *)(ex + 0x4C), *(void **)(g + 0x2534));
            *(s32 *)(ex + 0x4C) = -1;
        }
    }
    if (*(s16 *)(ex + 6) == 0) {
        func_0038CB00(ex + 0xA);
        func_0038CB00(ex + 8);
        func_0038CAD0(ex + 0x40);
        if (*(u32 *)(ex + 8) != 0) {
            func_L01_00404A10(func_L39_00548648, a);
        }
    }
    if ((u8)(a[0x20] - 2) >= 2) {
        return;
    }
    if (func_0038CB00(ex + 6) == 0) {
        return;
    }
    if (*(s32 *)(g + 0x1078) != 0) {
        func_L01_00457588(*(void **)(g + 0x1078), ex + 0x10, 1.0f, g + 0x3B0);
        *(u128_t *)(g + 0x380) = *(u128_t *)(g + 0x3B0);
    } else if (g[0x1A14] == 0) {
        *(f32 *)(g + 0x3B0) = *(f32 *)(ex + 0x54);
        *(f32 *)(g + 0x3B4) = *(f32 *)(ex + 0x58);
        *(f32 *)(g + 0x3B8) = *(f32 *)(ex + 0x5C);
        *(s32 *)(g + 0x3BC) = 0;
        *(u128_t *)(g + 0x380) = *(u128_t *)(g + 0x3B0);
    }

    if (a[0x20] == 2) {
        a[0x20] = 3;
        func_003C2F58(a, 0, ex + 0x10);
        func_L39_00548130(a, ex + 0x10);
        *(u128_t *)(ex + 0x30) = *(u128_t *)(g + 0x3B0);
        func_L01_00404A10(func_L39_00548648, a);
        func_L39_005F33E0(0, 0, a);
        if (*(s32 *)(ex + 0x48) != 0) {
            if (g[0x1A14] != 0) {
                ent = D_L39_0024DE80 + g[0x24C9] * 0x460;
                *(f32 *)(ent + 0x20) = 0.119999997f;
                *(s32 *)(ent + 0x28) = 0x19;
                *(s32 *)(ent + 0x2C) = 0;
            }
        } else {
            if (g[0x1A14] != 0) {
                ent = D_L39_0024DE80 + g[0x24C9] * 0x460;
                *(f32 *)(ent + 0x20) = 0.0599999987f;
                *(s32 *)(ent + 0x28) = 0x19;
                *(s32 *)(ent + 0x2C) = 0;
            }
        }
        return;
    }

    a[0x20] = 6;
    *(s16 *)(ex + 4) = 0x17;
    *(u8 **)(blk70 + 0x00) = a;
    *(s32 *)(blk70 + 0x04) = 0x10001;
    blk70[8] = 3;
    blk70[9] = 2;
    *(u16 *)(blk70 + 0xA) = *(u16 *)(a + 0xAA);
    *(s32 *)(blk70 + 0x10) = 1;
    cfg = cfg_00546FE0(g);
    *(f32 *)(blk70 + 0xC) = *(f32 *)(cfg + 0x30) + *(f32 *)(cfg + 0x30);
    *(s32 *)(blk70 + 0x18) = 0;
    func_0038CE20(v00, a + 0xD0, -1.35000002f);
    v00[0] += *(f32 *)(a + 0x10);
    v00[1] += *(f32 *)(a + 0x14);
    v00[2] += *(f32 *)(a + 0x18);
    func_0038CE20(v90, a + 0xC0, 0.275000006f);
    v00[0] += v90[0];
    v00[1] += v90[1];
    v00[2] += v90[2];
    ent = D_L39_0024CE20[*(s32 *)(g + 0x2544)];
    v = -1;
    if (ent != 0) {
        v = *(s32 *)(ent + 0x2548);
    }
    func_L39_005FFDF8(v);
    cnt = func_003D4D00(v00, 1, *(void **)(g + 0x2524), 0, 1.5f);
    func_L39_005FFE78();
    if (cnt > 0) {
        void **p = D_L39_002637C0;
        f20 = 5627.9248f;
        for (i = cnt; i > 0; i--, p++) {
            if ((u32)*p != *(u32 *)(g + 0x2524)) {
                func_0038CE20(v60, a + 0xD0, -1.5f);
                v60[3] = f20;
                func_L01_00446978(*p, v60);
            }
        }
    }
    func_0038D328(m130, &D_L39_0024AF90);
    func_0038D590(v100, m130);
    func_003C2F58(a, 0, v170);
    if (func_L39_00639D90(g) != 0 && g[0x1A08] == 0) {
        *(u128_t *)vA0 = *(u128_t *)(g + 0x380);
        *(u128_t *)vB0 = *(u128_t *)(g + 0x390);
        func_0038CF68(vC0, g + 0x3A0, -0.100000001f);
        func_0038D5F0(vD0, g + 0x380, v100);
    } else if (g[0x1A08] == 1) {
        func_0038CE20(vA0, a + 0xD0, -1.0f);
        func_0038CE20(vB0, a + 0xC0, -1.0f);
        func_0038CE20(vC0, a + 0xE0, 0.100000001f);
        func_0038D5F0(vD0, a + 0xC0, v100);
    } else {
        *(u128_t *)vA0 = *(u128_t *)(g + 0x380);
        *(u128_t *)vB0 = *(u128_t *)(g + 0x390);
        func_0038CE20(vC0, g + 0x3A0, -0.100000001f);
        func_0038D5F0(vD0, g + 0x380, v100);
    }
    *(u128_t *)(ex + 0x30) = *(u128_t *)vA0;
    f22 = 1.04719758f;
    f21 = 0.0f;
    for (i = 0; i < 20; i++) {
        w190[i] = 0;
        w1E0[i] = 0;
    }
    n = 0;
    for (i = 0; i < 20; i++) {
        f20 = ((f32)i * 0.327249229f) / 20.0f;
        func_003C4840(q230, vB0, f20);
        func_0038D850(v240, vA0, q230);
        func_0038D850(v180, vC0, q230);
        f21 = func_0038DAB8(func_L39_005B4410(f22 * 0.5f, f22 * 1.5f), f21);
        func_003C4840(q230, vA0, f21);
        func_0038D850(v240, v240, q230);
        func_0038D850(v180, v180, q230);
        func_0038CE20(v240, v240, 32.0f);
        v250[0] = v170[0] + v180[0];
        v250[1] = v170[1] + v180[1];
        v250[2] = v170[2] + v180[2];
        v260[0] = v250[0] + v240[0];
        v260[1] = v250[1] + v240[1];
        v260[2] = v250[2] + v240[2];
        obj = (u8 *)func_L39_00547E10(a, v250, v260, v60, f20);
        if (obj != 0) {
            w1E0[n] = *(s32 *)(obj + 0x98);
            w190[n] = (s32)obj;
            n++;
            *(s32 *)(obj + 0x98) = 0;
        }
    }
    for (i = 0; i < n; i++) {
        *(s32 *)(w190[i] + 0x98) = w1E0[i];
    }
    cfg = cfg_00546FE0(g);
    *(f32 *)ex = 1.0f / *(f32 *)(cfg + 0x28);
}

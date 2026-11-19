/* functional: medium. Per-frame update of a multiplayer-menu lock-on/targeting object: owner g = ex+0x40, a lock timer (ex+0x44) from the owner's aim value at g+0x1250, target acquisition (func_L39_006472D0 or the owner's lock at g+0x122C), target validity timers (ex+0x24/0x34 via func_0038CAD0), the lock-on marker effect (func_L01_003F6F20), the state-8 fire step (probe with func_003D4D00, calls func_L39_005490D0/0054A028) and the 12-frame flash effect at D_L39_002667C0[ex.h2C]. Written from the PAL assembly; the NTSC-U twin draft was only used as a map. */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L39_004997E0[];
extern u8 D_L39_0049C890[];
extern void *D_L39_002637C0[];
extern s32 D_L39_0025F740[];
extern u8 D_L39_00470500[];
extern u8 D_L39_002667C0[];

extern void func_L39_0061C4D0(u8 *, u8 **);
extern void func_L39_00548E60(u8 *);
extern s32 func_L01_0040E050(void *);
extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern void func_L39_00674320(void *);
extern s32 func_L39_005FFD20(void *, void *, s32, f32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L39_006472D0(void *, void *, void *, s32, f32, f32, f32, f32, f32);
extern f32 *func_00382348(void *);
extern s32 func_L39_00639D90(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF00(void *, void *);
extern u32 func_0038DBD8(u32, u32, f32);
extern s32 func_L39_006732D0(void *, s32, s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L39_005B8928(void *);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005490D0(u8 *);
extern void func_L39_0054A028(u8 *, void *);
extern void func_L39_00621D60(void *, s32);
extern s32 func_L01_003F2058(void *, void *);
extern void func_L01_003F2278(s32, void *);
extern s32 func_L39_00648AE0(void *, s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L39_0059EBC8(void *, f32, f32, f32, f32, f32);
extern void func_L01_00424D88(s32);

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_00549510;

static __inline__ u32 decode_00549510(u8 *p) {
    Buf_00549510 buf;
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

void func_L39_00549510(u8 *a) {
    u8 *ex = *(u8 **)(a + 0x68);
    u8 *g;
    u8 *target;
    u8 *cur;
    u8 *cfg;
    u8 *t;
    u8 *d4;
    f32 *hp;
    s32 sbuf[16];
    f32 vb[4] __attribute__((aligned(16)));
    f32 vc[4] __attribute__((aligned(16)));
    f32 v00[4] __attribute__((aligned(16)));
    f32 v80[4] __attribute__((aligned(16)));
    f32 v90[4] __attribute__((aligned(16)));
    f32 vA0[4] __attribute__((aligned(16)));
    f32 strength;
    f32 dist;
    f32 f20, f21, f22, q;
    u32 col;
    s32 r23;
    s32 n;
    s32 i;
    s32 h;
    s32 e;
    s32 reset;

    if (a[0x20] == 0) {
        func_L39_0061C4D0(a, (u8 **)(ex + 0x40));
        a[0x20] = 1;
        *(s16 *)(ex + 0x2C) = -1;
        *(s32 *)(ex + 0x34) = 4;
        *(s32 *)(ex + 0x3C) = -1;
        *(s16 *)(ex + 0x2E) = 0;
        *(s32 *)(ex + 0x20) = 0;
        *(s32 *)(ex + 0x30) = 0;
        *(s32 *)(ex + 0x38) = 0;
    }
    g = *(u8 **)(ex + 0x40);
    if (g == 0) {
        return;
    }
    func_L39_00548E60(a);
    func_L01_0040E050(ex + 0x10);
    if (decode_00549510(g + 0x19E4) == 1) {
        (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(g + 0x14) + 0x34))(g, 0x1D, 0, 0, 1);
    }
    if (a[0x42] == a[0x43]) {
        if ((a[0x60] & 2) != 0) {
            func_L01_00444F38(a, 1, 0, 2, 0);
        }
    }
    if (*(s32 *)(g + 0x3E0) != 0) {
        *(s32 *)(g + 0x1078) = *(s32 *)(g + 0x3E0);
    }
    if (g[0x1A14] == 0) {
        func_L39_00674320(g);
    }
    *(s32 *)(ex + 0x44) = 0;

    target = 0;
    if (*(s32 *)(g + 0x1310) != 0) {
        if (g[0x1A14] != 0) {
            if (*(s32 *)(ex + 0x38) == 0) {
                *(s32 *)(ex + 0x20) = 0;
                *(s32 *)(ex + 0x34) = 4;
            }
            *(s32 *)(ex + 0x38) = 1;
            strength = (*(f32 *)(g + 0x1250) - 0.850000024f) / 0.149999976f;
            if (1.0f < strength) {
                strength = 1.0f;
            } else if (strength < 0.0f) {
                strength = 0.0f;
            }
            *(f32 *)(ex + 0x44) = strength;
            if (strength != 0.0f) {
                col = func_L39_005FFD20(g + 0x1338, g + 0x133C, 1, 150.0f);
                if (g[0x1A14] != 0) {
                    func_L01_003F6F20(g[0x24C9], a, col, 0, 0x27, -1, 4, 0.699999988f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
                }
                target = (u8 *)*(s32 *)(g + 0x122C);
            } else {
                col = func_L39_005FFD20(g + 0x1338, g + 0x133C, 0, 150.0f);
                if (g[0x1A14] != 0) {
                    func_L01_003F6F20(g[0x24C9], a, col, 0, 0x27, -1, 4, 0.699999988f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
                }
                target = 0;
            }
        }
    } else if (g[0x1A14] != 0) {
        *(s32 *)(ex + 0x38) = 0;
        if (g[0x1A08] != 0) {
            func_0038CE20(vb, a + 0xD0, -1.0f);
        } else {
            *(u128_t *)vb = *(u128_t *)(g + 0x3B0);
        }
        func_0038CE20(vc, *(u8 **)(g + 0x2524) + 0xE0, 0.75f);
        vc[0] = *(f32 *)(g + 0xA0) + vc[0];
        vc[1] = *(f32 *)(g + 0xA4) + vc[1];
        vc[2] = *(f32 *)(g + 0xA8) + vc[2];
        vc[3] = *(f32 *)(g + 0xAC);
        target = func_L39_006472D0(g, vc, vb, 0, 0.314159274f, 0.296705961f, 75.0f, 0.314159274f, 0.314159274f);
        *(f32 *)(ex + 0x44) = 0.5f;
    }
    if (g[0x1A08] != 0) {
        func_0038CE20(vb, a + 0xD0, -1.0f);
        target = 0;
    }

    if (*(s32 *)(ex + 0x20) != 0) {
        hp = func_00382348((void *)*(s32 *)(ex + 0x20));
        cur = (u8 *)*(s32 *)(ex + 0x20);
        reset = 0;
        if (cur == 0 || cur[0x20] == 0xFE || cur[0x20] == 0xFD) {
            reset = 1;
        } else if (hp != 0 && hp[0] <= 0.0f) {
            reset = 1;
        } else if (cur[0x31] == 0) {
            reset = 1;
        } else if (g[0x1A08] != 0 && func_L39_00639D90(g) == 0) {
            reset = 1;
        }
        if (reset) {
            *(s32 *)(ex + 0x20) = 0;
            *(s32 *)(ex + 0x34) = 4;
        } else if (target != (u8 *)*(s32 *)(ex + 0x20)) {
            if (func_0038CAD0(ex + 0x24) != 0) {
                *(s32 *)(ex + 0x20) = 0;
                *(s32 *)(ex + 0x34) = 4;
            }
        } else {
            *(s32 *)(ex + 0x24) = 4;
            dist = func_0038CF00(*(void **)(g + 0x2530), target + 0x10) / 150.0f;
            hp = func_00382348(target);
            if (hp != 0) {
                *(f32 *)(ex + 0x28) = hp[4];
            } else {
                *(f32 *)(ex + 0x28) = 0.100000001f;
            }
            func_0038CE20(v00, target + 0xE0, *(f32 *)(ex + 0x28));
            v00[0] = *(f32 *)(target + 0x10) + v00[0];
            v00[1] = *(f32 *)(target + 0x14) + v00[1];
            v00[2] = *(f32 *)(target + 0x18) + v00[2];
            v00[3] = *(f32 *)(target + 0x1C);
            col = func_0038DBD8(0xFF0FFFFF, 0xFF0F0FFF, *(f32 *)(ex + 0x44));
            f20 = 0.899999976f - dist * 0.649999976f;
            f20 = fabs_asm(f20);
            if (g[0x1A14] != 0) {
                func_L01_003F6F20(g[0x24C9], a, col, v00, 0x26, -1, 4, f20, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            }
            *(s32 *)(g + 0x1078) = (s32)target;
        }
    } else if (g[0x1A14] != 0 && target == (u8 *)*(s32 *)(ex + 0x30)) {
        if (func_0038CAD0(ex + 0x34) != 0) {
            *(s32 *)(ex + 0x20) = (s32)target;
            *(s32 *)(ex + 0x24) = 4;
            hp = func_00382348(target);
            if (hp != 0) {
                *(f32 *)(ex + 0x28) = hp[4];
            } else {
                *(f32 *)(ex + 0x28) = 0.100000001f;
            }
        }
    } else {
        *(s32 *)(ex + 0x34) = 4;
    }

    *(s32 *)(ex + 0x30) = (s32)target;
    target = (u8 *)*(s32 *)(ex + 0x20);
    r23 = func_L39_006732D0(g + 0x1A40, 0, 1, sbuf);
    if (r23 == 8) {
        if (a[0x43] == 0) {
            func_003C3A10(a, 1, 0, 3);
        }
        *(s32 *)(ex + 0x48) = 1;
        if (target == 0) {
            func_0038CE20(v80, a + 0xD0, -1.0f);
            v80[0] += *(f32 *)(a + 0x10);
            v80[1] += *(f32 *)(a + 0x14);
            v80[2] += *(f32 *)(a + 0x18);
            func_0038CE20(v90, a + 0xC0, 0.275000006f);
            v80[0] += v90[0];
            v80[1] += v90[1];
            v80[2] += v90[2];
            n = func_003D4D00(v80, 1, *(void **)(g + 0x2524), 0, 1.0f);
            if (n != 0 && n > 0) {
                for (i = 0; i < n; i++) {
                    t = (u8 *)D_L39_002637C0[i];
                    hp = func_00382348(t);
                    if (t[0x31] == 0) {
                        continue;
                    }
                    if (*(s16 *)(t + 0x32) <= 0) {
                        continue;
                    }
                    if (t == 0 || t[0x20] == 0xFE || t[0x20] == 0xFD) {
                        continue;
                    }
                    if (*(s16 *)(t + 0xAA) == 0xC87 || *(s16 *)(t + 0xAA) == 0xECC) {
                        continue;
                    }
                    if (hp == 0) {
                        continue;
                    }
                    if (!(0.0f < hp[0])) {
                        if (func_L39_005B8928(t) == 0) {
                            continue;
                        }
                    }
                    d4 = *(u8 **)(t + 0x24);
                    if (d4 == 0 || d4[0x46] != 5) {
                        target = (u8 *)D_L39_0025F740[6];
                        *(s32 *)(ex + 0x20) = (s32)target;
                        break;
                    }
                }
            }
        }
        func_L39_005F33E0(0, 0, a);
        *(s16 *)(ex + 0x2E) = 12;
        func_L39_005490D0(a);
        func_L39_0054A028(a, sbuf);
        func_L39_00621D60(g, -1);
        func_003C3A10(a, 2, 0, 0);
        *(s32 *)(ex + 0x3C) = func_L01_003F2058(D_L39_00470500, *(void **)(g + 0x2534));
        if (func_L39_00648AE0(g, 4) != 0) {
            cfg = D_L39_0049C890 + ((s8)D_L39_0049C890[0x221] << 7);
        } else {
            cfg = D_L39_0049C890 + 0x200;
        }
        *(f32 *)(ex + 0x10) = 1.0f / *(f32 *)(cfg + 0x28);
    } else if (r23 == 4 && *(s32 *)(ex + 0x48) == 1) {
        func_L39_005F33E0(1, 0, a);
        *(s32 *)(ex + 0x48) = 0;
    }

    if (r23 != 8 || g[0x1A07] == 0) {
        if (*(s32 *)(ex + 0x3C) >= 0) {
            func_L01_003F2278(*(s32 *)(ex + 0x3C), *(void **)(g + 0x2534));
            *(s32 *)(ex + 0x3C) = -1;
        }
    }

    h = *(s16 *)(ex + 0x2E);
    if (a[0x42] != 2 && h > 0) {
        if (h >= 11) {
            q = (f32)(12 - h);
            f20 = q * 0.5f;
            f22 = (q * 0.800000012f) * 0.5f;
            f21 = f20 * 0.5f;
        } else {
            q = (f32)h;
            f20 = q * 0.100000001f;
            f21 = (q * 0.5f) * 0.100000001f;
            f22 = (q * 0.800000012f) * 0.100000001f;
        }
        if (g[0x1A08] != 0) {
            func_0038CE20(v90, a + 0xD0, -1.0f);
            func_003C2F58(a, 0, v80);
        } else {
            *(u128_t *)v90 = *(u128_t *)(g + 0x3B0);
            func_003C2F58(a, 0, v80);
        }
        v80[0] += v90[0];
        v80[1] += v90[1];
        v80[2] += v90[2];
        func_0038CE20(vA0, *(u8 **)(g + 0x2524) + 0xE0, 0.300000012f);
        v80[0] += vA0[0];
        v80[1] += vA0[1];
        v80[2] += vA0[2];
        e = *(s16 *)(ex + 0x2C);
        if (e == -1) {
            *(s16 *)(ex + 0x2C) = func_L39_0059EBC8(v80, 8.0f, 0.0f, f20, f22, f21);
        } else {
            u8 *ent = D_L39_002667C0 + (e << 5);
            *(u128_t *)(ent + 0x10) = *(u128_t *)v80;
            *(f32 *)(ent + 8) = f21;
            *(f32 *)(ent + 0x1C) = 8.0f;
            *(f32 *)(ent + 0) = f20;
            *(f32 *)(ent + 4) = f22;
        }
        func_0038CB00(ex + 0x2E);
    } else {
        e = *(s16 *)(ex + 0x2C);
        if (e != -1) {
            func_L01_00424D88(e);
            *(s16 *)(ex + 0x2C) = -1;
            *(s16 *)(ex + 0x2E) = 0;
        }
    }
    if (a[0x43] == 2) {
        e = *(s16 *)(ex + 0x2C);
        if (e != -1) {
            func_L01_00424D88(e);
        }
        *(s16 *)(ex + 0x2C) = -1;
        *(s16 *)(ex + 0x2E) = 0;
    }
}

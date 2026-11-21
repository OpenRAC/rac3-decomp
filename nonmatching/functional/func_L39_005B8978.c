/* functional: medium. Same calls, arguments and order as retail; locals (spark/colour tables, scratch vectors) are plain C arrays instead of ldl/ldr copies. Parameter names are guesses; the four stack ints and the seven floats are ordered as the caller passes them. */
typedef int u128_5B8978 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 f28;
    s32 f2C;
} Cam_005B8978;

extern f32 D_L39_0024BB48;
extern f32 D_L39_0024BB4C;
extern f32 D_L39_0024DE00[4];
extern s32 *D_L39_00241120;
extern s32 D_L39_00243278[6];
extern s32 D_L39_00243290[6];
extern Cam_005B8978 D_L39_0024DE80[];
extern u8 D_L39_004996F0[];
extern u8 D_L39_00499740[];
extern u8 D_001FE100[];

extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L01_00448D88(s32, s32);
extern void *func_L39_005C7B40(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L39_005C6E90(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_00464210(void *, void *, s32, s32, s32, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_0038CF68(void *, void *, f32);
extern s32 func_L01_0040E6B8(void *, void *, f32);
extern void func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_L01_002F9578(void *, void *, void *, s32, s32, s32, s32, s32, f32);
extern s32 func_0038DC20(void *, f32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L01_003006C0(void *, void *, s32, s32);

void func_L39_005B8978(u8 *obj, s32 a1, f32 *pos, s32 nSparks, s32 nSmoke, s32 nDebris, s32 idArg, s32 aC,
                       s32 nExtra, s32 mode, u8 col, s32 flags, f32 fDur, f32 fArg, f32 fRange, f32 fSize2,
                       f32 fFlashDist, f32 scale, f32 fShake) {
    u8 ev[0x50] __attribute__((aligned(16)));
    f32 zero[4];
    f32 v30[4];
    f32 v40[4];
    f32 d[4];
    s32 tabA[6];
    s32 tabB[6];
    f32 v80[4];
    f32 v90[4];
    f32 dist, f21, f20, f24, f25, nSmokeF, r;
    s32 n, i, k, c0, c1, life, nS, A, B, C, D, E, F, m10, m2, m3, m5;
    u8 *cam;

    zero[0] = 0.0f;
    zero[1] = 0.0f;
    zero[2] = 0.0f;
    zero[3] = 0.0f;
    zero[2] = scale * 0.16000001f; /* the quad is the velocity passed to the effects: (0, 0, scale*0.16) */

    if (mode == -1) {
        if (1.7f < D_L39_0024BB4C + D_L39_0024BB48) {
            mode = 1;
        }
    }
    if (!(*D_L39_00241120 < 3)) {
        mode = 1;
    }
    if (pos == 0) {
        if (obj == 0) {
            return;
        }
        pos = (f32 *)(obj + 0x10);
    }

    if (0.0f < fDur) {
        func_L01_00446748(ev, obj, flags, fArg);
        ev[0x48] = 2;
        ev[0x49] = 1;
        *(u16 *)(ev + 0x4A) = *(u16 *)(obj + 0xAA);
        func_003D4D00(pos, 0x10, obj, ev, fDur);
    }

    nSmokeF = (f32)nSmoke;
    m10 = mode * 10;
    n = nSparks;
    if (n > 0) {
        do {
            n--;
            f21 = func_L39_005B4410(0.2617994f, 1.3962634f);
            f20 = func_L39_005B44C8();
            f24 = func_L39_005B4410(7.0f, 10.5f) * 0.020000001f;
            func_00382760(v30, scale * f24, f20, f21);
            v30[2] += 0.060000002f;
            c0 = func_L01_00448D88(0x4F007FFF, col);
            c1 = func_L01_00448D88(0x1F00007F, col);
            life = func_L39_005B43C8(0x32, 0x64) - m10;
            func_L39_005C7B40(pos, v30, c0, c1, life, 1, -1, -1, 0, scale * 40000.0f);
        } while (n != 0);
    }

    d[0] = D_L39_0024DE00[0] - pos[0];
    d[1] = D_L39_0024DE00[1] - pos[1];
    d[2] = D_L39_0024DE00[2] - pos[2];
    d[3] = D_L39_0024DE00[3];
    dist = func_0038CEA8(d);

    if (nExtra != 0) {
        v40[0] = 0.0f;
        v40[1] = 0.0f;
        v40[2] = 0.0f;
        v40[3] = 0.0f;
        v40[0] = func_L39_005B4410(-1.0f, 1.0f);
        v40[1] = func_L39_005B4410(-1.0f, 1.0f);
        v40[2] = func_L39_005B4410(-1.0f, 1.0f);
        v30[0] = v40[0];
        v30[1] = v40[1];
        v30[2] = v40[2];
        v30[3] = v40[3];
        if (dist < 14.0f) {
            d[2] = d[2] + dist * 0.5f;
            func_0038CF68(v30, v30, (dist / 5.0f) * 0.020000001f);
            func_0038CF68(d, d, (dist + dist) * 0.020000001f);
            v30[0] += d[0];
            v30[1] += d[1];
            v30[2] += d[2];
            func_L01_0040E6B8(v30, v30, 0.20000002f);
            func_L01_002FB660(pos, v30, func_L39_005B43C8(0x32, 0x4B), 0, 0, 0);
        }
        nExtra--;
        if (nExtra > 0) {
            i = 0;
            do {
                f21 = func_L39_005B4410(0.2617994f, 1.3089969f);
                k = 1;
                f20 = func_L39_005B44C8();
                f24 = func_L39_005B4410(7.0f, 10.5f) * 0.020000001f;
                func_00382760(v40, scale * f24, f20, f21);
                v40[2] += 0.040000003f;
                if (i % 3 != 0) {
                    k = 0;
                }
                i++;
                func_L01_002FB660(pos, v40, func_L39_005B43C8(0x32, 0x4B), k, 0, 0);
            } while (i < nExtra);
        }
    }

    nS = nSmoke;
    if (dist < nSmokeF + nSmokeF) {
        nS = (s32)dist / 2;
    }
    f25 = 0.0f;
    if (dist < 7.0f) {
        f25 = 7.0f - dist;
    }
    if (nS > 0) {
        m2 = mode * 2;
        m3 = m2 + mode;
        m5 = mode * 5;
        do {
            nS--;
            f21 = func_L39_005B4410(8.0f, 10.0f) * 0.020000001f;
            for (k = 0; k < 6; k++) {
                tabA[k] = D_L39_00243278[k];
            }
            for (k = 0; k < 6; k++) {
                tabB[k] = D_L39_00243290[k];
            }
            r = f25 * 0.020000001f;
            f21 = f21 - r;
            c0 = func_L01_00448D88(tabA[func_L39_005B4398(6)], col);
            f21 = f21 * scale;
            c1 = func_L01_00448D88(tabB[func_L39_005B4398(6)], col);
            f20 = scale * 400000.0f;
            life = func_L39_005B43C8(0xC, 0x11) - m3;
            func_L39_005C6E90(pos, zero, c0, c1, life, func_L39_005B43C8(0x19, 0x25) - m5, 0, 0, f20, f21);
            life = func_L39_005B43C8(4, 8) - m2;
            func_L39_005C6E90(pos, zero, 0x7FFFFFFF, 0xFFFFFF, life, func_L39_005B43C8(0xC, 0x11) - m3, 0, 0, f20,
                              f21 * 0.5f);
        } while (nS != 0);
    }

    n = nDebris;
    if (n > 0) {
        m5 = mode * 5;
        do {
            for (k = 0; k < 6; k++) {
                tabA[k] = D_L39_00243278[k];
            }
            for (k = 0; k < 6; k++) {
                tabB[k] = D_L39_00243290[k];
            }
            v90[0] = 0.0f;
            v90[1] = 0.0f;
            v90[2] = 0.0f;
            v90[3] = 0.0f;
            v90[0] = func_L39_005B4410(-1.0f, 1.0f);
            n--;
            v90[1] = func_L39_005B4410(-1.0f, 1.0f);
            v90[2] = func_L39_005B4410(-1.0f, 1.0f);
            v80[0] = v90[0];
            v80[1] = v90[1];
            v80[2] = v90[2];
            v80[3] = v90[3];
            f24 = func_L39_005B4410(0.0f, 3.0f) * 0.020000001f;
            func_0038CF68(v80, v80, scale * f24);
            c0 = func_L01_00448D88(tabA[func_L39_005B4398(6)], col);
            c1 = func_L01_00448D88(tabB[func_L39_005B4398(6)], col);
            life = func_L39_005B43C8(0x19, 0x25) - m5;
            func_L01_00464210(pos, v80, c0, c1, life, 200000.0f);
        } while (n != 0);
    }

    if (obj != 0) {
        if (0.0f < fRange) {
            A = 0x96;
            B = 0x96;
            C = 0x96;
            D = 0x7F;
            E = 0x7F;
            F = 0;
            if (col != 0) {
                if ((col & 4) != 0) {
                    A = 0x23;
                    B = 0;
                    C = 0xFA;
                    D = 0x20;
                    E = 0;
                    F = 0x64;
                } else {
                    A = 0x46;
                    C = 0x46;
                    D = 0x3C;
                }
            }
            if (D_L39_0024BB48 < 0.95f) {
                if (fFlashDist < dist) {
                    func_L01_002F9578(obj, pos, zero, 0xD, A, B, C, 0x20, fRange);
                    func_L01_002F9578(obj, pos, zero, 0x12, D & 0xFF, E & 0xFF, F + 0x50, 0x20, fRange);
                }
            }
            func_L01_002F9578(obj, pos, zero, 0x19, D & 0xFF, E & 0xFF, F, 0x30, fRange);
        }
        if (0.0f < fSize2) {
            func_L01_002F9578(obj, pos, zero, 0x16, 0xFF, 0xFF, 0xFF, 0x20, fSize2);
        }
    }

    if (aC != 0) {
        v30[0] = pos[0];
        v30[1] = pos[1];
        v30[2] = pos[2];
        v30[3] = 2.0f;
        if (func_0038DC20(v30, 10.0f) != -1) {
            if (dist < 20.0f) {
                D_L39_0024DE80[0].f20 = 0.4f - dist * 0.0175f;
            } else {
                D_L39_0024DE80[0].f20 = 0.050000012f;
            }
            D_L39_0024DE80[0].f28 = 0x15;
            D_L39_0024DE80[0].f2C = 0;
        }
    }

    if (obj != 0) {
        if (idArg != -1) {
            k = func_L39_005F33E0(idArg, 0, obj);
            if (k != -1) {
                *(u128_5B8978 *)(D_001FE100 + k * 128) = *(u128_5B8978 *)pos;
                *(s32 *)(D_001FE100 + k * 128 - 4) = 0;
                *(s32 *)(D_001FE100 + k * 128 + 0x38) = 0;
            }
        }
    }

    if (fShake == 0.0f) {
        return;
    }
    if (mode != 0) {
        return;
    }
    v30[0] = pos[0];
    v30[1] = pos[1];
    v30[2] = pos[2];
    v30[3] = fShake;
    if (func_0038DC20(v30, 100.0f) == -1) {
        return;
    }
    if (0.0f < fShake) {
        *(f32 *)(D_L39_004996F0 + 0x20) = fShake;
        *(f32 *)(D_L39_004996F0 + 0x24) = fShake;
        *(f32 *)(D_L39_004996F0 + 0x28) = fShake;
    } else {
        *(f32 *)(D_L39_004996F0 + 0x20) = 15.0f;
        *(f32 *)(D_L39_004996F0 + 0x24) = 15.0f;
        *(f32 *)(D_L39_004996F0 + 0x28) = 15.0f;
    }
    if (col != 0) {
        func_L01_003006C0(D_L39_00499740, pos, 0, 0);
    } else {
        func_L01_003006C0(D_L39_004996F0, pos, 0, 0);
    }
}

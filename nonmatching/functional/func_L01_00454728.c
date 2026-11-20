/* functional: medium. Block-by-block translation of the 970-instruction assembly (M = moby, S = movement state; returns a bit set 1/2/3/4). Several likely-branch delay-slot loads and the shared exit paths were folded into plain if/else; every constant, offset and callee argument was read off the retail words. The spark effect loop adds the x-part cos*8 to both x and y exactly as retail does (kept, not fixed). The VU0 vadd/vsub.xyz are per-component adds keeping the first operand's w. Callee prototypes are inferred from the register setup. */
extern u8 D_L01_001EAA00[];
extern f32 func_0038CED8(void *);
extern void func_0038CFB8(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4138(void *, f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_003D5630(void);
extern void func_L01_0046A938(void *, s32, s32, f32, f32);
extern void func_L01_003016B0(void *, s32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00468A68(void *, void *, s32, s32);
extern f32 func_L01_004463D0(void *);
extern f32 func_L01_004395E0(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_004461B8(void *, void *, f32, f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(f32, void *, s32, void *);
extern void func_L01_00476F10(s32, void *, void *, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_0044C1B8(void *, void *);
extern s32 func_L01_0044E1B8(void *, f32);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00454728;

static void v3add_00454728(f32 *d, f32 *a, f32 *b) {
    f32 w = a[3];
    d[0] = a[0] + b[0];
    d[1] = a[1] + b[1];
    d[2] = a[2] + b[2];
    d[3] = w;
}

static void v3sub_00454728(f32 *d, f32 *a, f32 *b) {
    f32 w = a[3];
    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
    d[3] = w;
}

s32 func_L01_00454728(u8 *M, u8 *S) {
    V4_00454728 q0, q10, q20, q30, q40, q50, q60, q70;
    f32 spd, ground, a88, a8c, a90;
    f32 f0, f1, f2, f3, f12, f20, f21, f22, f23;
    s32 flags, gflag, hit, fp, i, k, n, r;
    f32 *Mp = (f32 *)(M + 0x10);
    f32 *V80 = (f32 *)(S + 0x80);
    u8 *t;

    flags = 0;
    if (S[0x1A] == 0) {
        f1 = *(f32 *)(S + 0x4C);
    } else {
        f1 = *(f32 *)(S + 0x50);
    }
    *(f32 *)(S + 0x88) = *(f32 *)(S + 0x88) - f1;
    spd = func_0038CED8(V80);
    f12 = (S[0x1A] < 2) ? 0.0200000014f : 0.0f;
    func_003C4138(&spd, f12, *(f32 *)(S + 0x2C));
    func_0038CFB8(V80, V80, spd);
    gflag = 0;
    q20.x = 0.0f;
    q20.y = 0.0f;
    q20.z = *(f32 *)(S + 0x34);
    q20.w = 0.0f;
    func_0038D000(&q20, &q20, M + 0xC0);
    v3add_00454728((f32 *)&q10, (f32 *)&q20, Mp);
    ground = func_003C3D30(&q10, 0, 0, 0.5f);
    if (func_003D5630() == 0) {
        gflag = 1;
        if (S[0x1B] == 0) {
            f1 = q10.z;
            f2 = ground;
            if (f2 <= f1) {
                f0 = f1 + *(f32 *)(S + 0x88);
                if (f0 < f2) {
                    S[0x1B] = 1;
                    if (*(s16 *)(M + 0xAA) == 0x16AD || *(s16 *)(M + 0xAA) == 0x160E) {
                        q30 = *(V4_00454728 *)Mp;
                        q30.z = f2;
                        func_L01_003016B0(&q30, 3, 3.25f, 1.02499998f);
                        for (i = 2; i >= 0; i--) {
                            q40.x = Mp[0] + func_003824E0(-0.300000012f, 0.300000012f);
                            q40.y = Mp[1] + func_003824E0(-0.300000012f, 0.300000012f);
                            q40.z = ground;
                            f12 = func_003824E0(0.5f, 0.75f);
                            func_L01_0046A938(&q40, (s32)&ground, -1, f12, 5250.0f);
                        }
                        i = 15;
                        do {
                            f21 = func_00382538();
                            i--;
                            f20 = func_003824E0(0.0f, 0.0600000024f);
                            q40.x = func_0038D098(f21) * f20;
                            q40.y = func_0038D0B0(f21) * f20;
                            q40.z = func_003824E0(0.0600000024f, 0.160000011f);
                            f2 = q40.x * 8.0f;
                            q50.x = Mp[0] + f2;
                            q50.y = Mp[1] + f2;
                            q50.z = ground - func_003824E0(0.0f, 0.200000003f);
                            k = func_00382468(2);
                            n = func_00382498(0x5A, 0x78);
                            func_L01_00468A68(&q50, &q40, k, n);
                        } while (i >= 0);
                    }
                }
            }
        }
        ground = func_L01_004463D0(Mp);
    }
    if (S[0x1B] != 0) {
        if (S[0x1B] < 4) {
            func_0038CE20(V80, V80, 0.899999976f);
        }
        if (S[0x1B] < 7) {
            S[0x1B] = S[0x1B] + 1;
            *(f32 *)(S + 0x50) = *(f32 *)(S + 0x50) * 0.949999988f;
        }
    }
    if (Mp[0] < 2.0f || Mp[0] > 1021.0f || Mp[1] < 2.0f || Mp[1] > 1021.0f || Mp[2] < 2.0f || Mp[2] > 1021.0f) {
        flags = 1;
    }
    f21 = 0.0f;
    if (S[0x1A] != 0 && Mp[2] < *(f32 *)(S + 0x40)) {
        flags |= 1;
    } else if (M[0x43] != S[0x15] && 0.0f < *(f32 *)(S + 0x60) && 0.0f < *(f32 *)(S + 0x54)) {
        if (S[0x1A] == 1) {
            f0 = func_L01_004395E0(M);
            if (*(f32 *)(S + 0x60) <= f0) {
                *(f32 *)(M + 0x48) = 0.0f;
            } else if (S[0x15] == 0xFF
                       || (ground != 0.0f && !(ground < *(f32 *)(S + 0x40)) && !(10.0f < Mp[2] - ground))) {
                f12 = *(f32 *)(S + 0x50) * -0.5f;
                f20 = 60.0f;
                r = func_L01_004461B8(&a88, &a8c, f12, *(f32 *)(S + 0x88) - f12, Mp[2] - ground);
                if (r > 0) {
                    if (0.0f < a88 && a88 < f20) {
                        f20 = a88;
                    }
                }
                if (f20 < 0.0001f) {
                    f20 = 0.0001f;
                }
                f0 = func_L01_004395E0(M);
                f1 = *(f32 *)(S + 0x60) - f0;
                f1 = f1 + f1;
                f12 = f1 / f20;
                if (2.0f < f12) {
                    f12 = 2.0f;
                } else if (f12 < 0.0f) {
                    f12 = 0.0f;
                }
                func_003C4138(M + 0x48, f12, 0.420000017f);
            } else {
                if (M[0x43] != S[0x15]) {
                    func_003C3A10(M, S[0x15], 0, 4);
                }
                if (0.00600000005f < *(f32 *)(S + 0x50)) {
                    *(f32 *)(S + 0x50) = 0.00600000005f;
                }
            }
        } else if (S[0x1A] == 0) {
            f20 = *(f32 *)(S + 0x88) / *(f32 *)(S + 0x4C);
            if (f20 < 0.0f) {
                f20 = -f20;
            }
            if (2.0f < f20) {
                f0 = func_L01_004395E0(M);
                f1 = *(f32 *)(S + 0x54) - f0;
                f1 = f1 + f1;
                f12 = f1 / f20;
                if (0.0f < f12) {
                    func_003C4138(M + 0x48, f12, 0.420000017f);
                }
            }
        } else if (S[0x1A] == 2) {
            q40 = *(V4_00454728 *)Mp;
            q30 = *(V4_00454728 *)Mp;
            q40.z = q40.z - 1.0f;
            *(f32 *)(M + 0x48) = 1.0f;
            q30.z = q30.z + 0.200000003f;
            if (func_003D3CB0(&q30, &q40, 2, M, 0) == 0) {
                S[0x1A] = 1;
            }
        }
    }
    hit = 0;
    func_L01_00448890(M + 0xF8, S + 0x68, 0, *(f32 *)(S + 0x64), 0.0201061945f, 0.00502654864f, 3.1400001f);
    v3add_00454728(Mp, Mp, V80);
    v3add_00454728((f32 *)&q0, (f32 *)&q10, V80);
    f21 = func_003C3D30(Mp, 0, 0, 0.5f);
    if ((*(u16 *)(S + 0x38) & 3) == 0) {
        f20 = 0.0f;
        if (f20 < f21 && (*(u16 *)(M + 0x34) & 0x20) != 0) {
            t = *(u8 **)(*(u8 **)(M + 0x68) + 0x1C);
            if (t != 0) {
                f0 = func_0038CED8(D_L01_001EAA00 + 0x40);
                f0 = func_0038D160(*(f32 *)(D_L01_001EAA00 + 0x48), f0);
                if (*(f32 *)(t + 0x10) < f0) {
                    f3 = ground;
                    Mp[0] = q10.x;
                    Mp[1] = q10.y;
                    if (Mp[2] < f3) {
                        Mp[2] = f3;
                    }
                    q0 = *(V4_00454728 *)Mp;
                    hit = 1;
                    *(f32 *)(S + 0x84) = f20;
                    *(f32 *)(S + 0x80) = f20;
                }
            }
        }
        f1 = *(f32 *)(S + 0xB0);
        if (0.0f < f1 && gflag == 0 && hit == 0) {
            f3 = ground;
            f0 = f3 - f21;
            if (f1 < f0) {
                Mp[0] = q10.x;
                Mp[1] = q10.y;
                if (Mp[2] < f3) {
                    Mp[2] = f3;
                }
                *(f32 *)(S + 0x84) = 0.0f;
                q0 = *(V4_00454728 *)Mp;
                *(f32 *)(S + 0x80) = 0.0f;
            }
        }
    }
    func_0038CE20(&q30, V80, 3.0f);
    v3add_00454728((f32 *)&q30, (f32 *)&q30, (f32 *)&q0);
    func_L01_00446780(M, &q30, 0x08000000, 0, 1, 0, *(f32 *)(S + 0x30), 1.0f, 1.0f);
    if (*(f32 *)(S + 0x30) < func_0038CEA8(V80)) {
        if (func_003D3CB0(&q10, &q0, 0x24, M, 0) != 0) {
            q0 = *(V4_00454728 *)(D_L01_001EAA00 + 0x20);
        }
    }
    fp = 0;
    r = func_L01_003FB640(*(f32 *)(S + 0x30), &q0, 0x24, M);
    if (r == 0) {
        fp = 1;
        r = func_003D3CB0(&q0, Mp, 0x24, M, 0);
        if (r == 0) {
            goto tail;
        }
    }
    flags |= 4;
    if (fp != 0) {
        *(V4_00454728 *)Mp = *(V4_00454728 *)(D_L01_001EAA00 + 0x20);
    } else {
        v3sub_00454728(Mp, (f32 *)(D_L01_001EAA00 + 0x30), (f32 *)&q20);
        Mp[3] = ((f32 *)(D_L01_001EAA00 + 0x30))[3];
    }
    f20 = 1.0f;
    func_0038CF68(&q40, D_L01_001EAA00 + 0x40, f20);
    if (0.707000017f <= q40.z) {
        f20 = func_0038CE68(V80, &q40);
        if (f20 < 0.0f) {
            if (*(s32 *)(D_L01_001EAA00 + 0x18) == 0 || *(s32 *)(D_L01_001EAA00 + 0x1C) > 0) {
                q60 = *(V4_00454728 *)Mp;
                q70 = *(V4_00454728 *)Mp;
                q60.z = q60.z + 0.200000003f;
                q70.z = q70.z - 2.0f;
                if (func_003D3CB0(&q60, &q70, 2, M, 0) != 0) {
                    S[0x1A] = 2;
                }
            }
            func_0038CF68(&q50, &q40, f20);
            v3sub_00454728(V80, V80, (f32 *)&q50);
            if (S[0x1A] == 2) {
                if (*(s32 *)(D_L01_001EAA00 + 0x18) != 0 && *(s32 *)(D_L01_001EAA00 + 0x1C) < 0) {
                    flags |= *(u16 *)(S + 0x38) & 1;
                }
                a90 = func_0038CEA8(V80);
                func_003C4138(&a90, 0.0f, *(f32 *)(S + 0x50));
                func_0038CF68(V80, V80, a90);
            }
        }
    } else {
        f0 = func_0038CE68(V80, &q40);
        if (f0 < 0.0f) {
            func_0038CF68(&q50, &q40, f0 * -(*(f32 *)(S + 0x3C) + f20));
            v3add_00454728(V80, V80, (f32 *)&q50);
        }
    }
tail:
    if (*(s32 *)(S + 0x7C) != -1) {
        func_L01_00476F10(*(s32 *)(S + 0x7C), Mp, Mp, *(f32 *)(S + 0x30));
    }
    if (S[0x1A] == 0 && *(f32 *)(S + 0x88) < 0.0f) {
        S[0x1A] = 1;
    } else {
        if ((*(u16 *)(S + 0x38) & 2) != 0) {
            if ((flags & 4) != 0) {
                if (*(f32 *)(S + 0x88) <= 0.0f) {
                    flags |= 1;
                }
            }
            if ((*(u16 *)(M + 0x34) & 0x100) != 0) {
                func_0038D308(&q40, S + 0x90);
                func_0038D5F0(M + 0xC0, M + 0xC0, &q40);
                f0 = *(f32 *)(S + 0x34);
            } else {
                func_L01_0044C1B8(M + 0xF0, S + 0x90);
                func_0038D308(M + 0xC0, M + 0xF0);
                f0 = *(f32 *)(S + 0x34);
            }
            q40.x = 0.0f;
            q40.y = 0.0f;
            q40.z = f0;
            q40.w = 0.0f;
            func_0038D000(&q40, &q40, M + 0xC0);
            v3sub_00454728((f32 *)&q50, (f32 *)&q20, (f32 *)&q40);
            v3add_00454728(Mp, Mp, (f32 *)&q50);
        } else {
            n = 0;
            if (gflag == 0 && S[0x7B] != 0xFF && M[0x43] == S[0x11]
                && func_L01_0044E1B8(M, (f32)S[0x7B]) != 0) {
                n = 1;
            } else if ((M[0x60] & 2) != 0 && M[0x43] != S[0x15]) {
                n = 1;
            } else if (S[0x1A] == 2 && M[0x43] == S[0x15]) {
                n = 1;
            }
            if (n != 0) {
                if ((*(u16 *)(S + 0x38) & 1) == 0) {
                    flags |= 2;
                } else {
                    flags |= 3;
                }
            }
        }
    }
    if (!(spd < 0.0220000017f)) {
        S[0x14] = 0;
    } else if (*(f32 *)(S + 0x54) == -1.0f) {
        S[0x14] = 0;
    } else {
        S[0x14] = S[0x14] + 1;
        if (S[0x14] >= 0x32) {
            S[0x14] = 0x32;
            if ((*(u16 *)(S + 0x38) & 1) != 0) {
                flags |= 3;
            } else {
                flags |= 2;
            }
        }
    }
    return flags;
}

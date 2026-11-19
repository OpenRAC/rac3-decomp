/* functional: medium. Block-by-block translation of the assembly (S = state block at a1, M = moby at a0; returns a bit set: 1 out of bounds / blocked, 2, 4 hit). The VU0 vadd/vsub.xyz are written as per-component float adds that keep the first operand's w, as the instructions do. Callee prototypes are inferred from the register setup. */
extern u8 D_L01_001EAA00[];
extern f32 func_L01_004513A8(void *, s32, s32);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, s32);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_00451388(void *, void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4138(void *, f32, f32);
extern f32 func_L01_00451580(void *);
extern f32 func_L01_004395E0(void *);
extern void func_L01_0044E130(void *, void *);
extern f32 func_L01_00451700(void *, void *, s32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(f32, void *, s32, void *);
extern s32 func_L01_004461B8(void *, void *, f32, f32, f32);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00455550;

static void v3add_00455550(f32 *d, f32 *a, f32 *b) {
    f32 w = a[3];
    d[0] = a[0] + b[0];
    d[1] = a[1] + b[1];
    d[2] = a[2] + b[2];
    d[3] = w;
}

static void v3sub_00455550(f32 *d, f32 *a, f32 *b) {
    f32 w = a[3];
    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
    d[3] = w;
}

s32 func_L01_00455550(u8 *M, u8 *S) {
    V4_00455550 q0, t10, V, q30, q40, q50, m60[4], q70, q80, q90, tC0, tD0;
    f32 a0, a4_, a8_, aAC, aB0;
    f32 f20, f21, f22, f23, f0, f1, f12;
    s32 flags, hit, st, r;
    f32 *Mp = (f32 *)(M + 0x10);
    f32 *S80 = (f32 *)(S + 0x80);

    flags = 0;
    func_003C5180(Mp, &V, 0);
    func_L01_004515D8(M + 0xC0, &V, 0);
    f23 = func_L01_004513A8(Mp, 0, 0);
    f22 = -func_0038CE68(S80, &V);
    if (S[0x1A] == 0) {
        func_L01_00451388(M, S80, S80, *(f32 *)(S + 0x4C));
        f0 = func_0038CEA8(&V);
        f1 = *(f32 *)(S + 0x4C);
    } else {
        func_L01_00451388(M, S80, S80, *(f32 *)(S + 0x50));
        f0 = func_0038CEA8(&V);
        f1 = *(f32 *)(S + 0x50);
    }
    f20 = f1 * f0;
    t10 = *(V4_00455550 *)Mp;
    func_L01_00451388(M, &t10, &t10, -*(f32 *)(S + 0x34));
    func_0038CF68(&q30, &V, -f22);
    v3sub_00455550(S80, S80, (f32 *)&q30);
    a0 = func_0038CEA8(S80);
    f12 = (S[0x1A] < 2) ? 0.0400000028f : 0.0f;
    func_003C4138(&a0, f12, *(f32 *)(S + 0x2C));
    func_0038CF68(S80, S80, a0);
    v3add_00455550(S80, S80, (f32 *)&q30);

    if (Mp[0] < 2.0f || Mp[0] > 1021.0f || Mp[1] < 2.0f || Mp[1] > 1021.0f || Mp[2] < 2.0f || Mp[2] > 1021.0f) {
        flags = 1;
    }
    if (S[0x1A] != 0) {
        if (func_L01_00451580(Mp) < *(f32 *)(S + 0x40)) {
            flags |= 1;
        }
    }
    f21 = 0.0f;
    if (f21 < *(f32 *)(S + 0x60) && f21 < *(f32 *)(S + 0x54)) {
        st = S[0x1A];
        if (st == 1) {
            f0 = func_L01_004395E0(M);
            if (*(f32 *)(S + 0x60) <= f0) {
                *(f32 *)(M + 0x48) = f21;
            } else {
                f12 = f20 * -0.5f;
                f20 = 60.0f;
                r = func_L01_004461B8(&a4_, &a8_, f12, f22 - f12, f23);
                if (r > 0) {
                    f0 = a4_;
                    if (f21 < f0 && f0 < f20) {
                        f20 = f0;
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
                func_003C4138(M + 0x48, f12, 0.120000005f);
            }
        } else if (st == 0) {
            f20 = f22 / f20;
            if (f20 < 0.0f) {
                f20 = -f20;
            }
            if (2.0f < f20) {
                f0 = func_L01_004395E0(M);
                f1 = *(f32 *)(S + 0x54) - f0;
                f1 = f1 + f1;
                f12 = f1 / f20;
                if (f21 < f12) {
                    func_003C4138(M + 0x48, f12, 0.120000005f);
                }
            }
        } else if (st == 2) {
            *(f32 *)(M + 0x48) = 1.0f;
            func_0038CF68(&q40, &V, -0.2f);
            v3add_00455550((f32 *)&q40, (f32 *)&q40, Mp);
            func_0038CF68(&q50, &V, 1.0f);
            v3add_00455550((f32 *)&q50, (f32 *)&q50, Mp);
            if (func_003D3CB0(&q40, &q50, 2, M, 0) == 0) {
                S[0x1A] = 1;
            }
        }
    }
    func_L01_0044E130(&q40, S + 0x64);
    f0 = func_L01_00451700(M, &q40, 0);
    aAC = 0.0f;
    func_L01_00448890(&aAC, S + 0x68, 0, f0, 0.0201061945f, 0.00502654864f, 3.1415927f);
    q50.x = 0.0f;
    q50.y = 0.0f;
    q50.z = *(f32 *)(S + 0x68);
    q50.w = 0.0f;
    func_0038D308(&m60[0], &q50);
    func_0038D5F0(M + 0xC0, M + 0xC0, &m60[0]);

    tD0 = *(V4_00455550 *)S80;
    tC0 = t10;
    v3add_00455550(Mp, Mp, (f32 *)&tD0);
    tD0 = *(V4_00455550 *)S80;
    v3add_00455550((f32 *)&q0, (f32 *)&tC0, S80);
    v3add_00455550((f32 *)&q40, (f32 *)&q0, (f32 *)&tD0);
    func_L01_00446780(M, &q40, 0x08000000, 0, 1, 0, *(f32 *)(S + 0x30), 1.0f, 1.0f);
    if (*(f32 *)(S + 0x30) < func_0038CEA8(S80)) {
        if (func_003D3CB0(&t10, &q0, 0x24, M, 0) != 0) {
            q0 = *(V4_00455550 *)(D_L01_001EAA00 + 0x20);
        }
    }
    hit = 0;
    if (func_L01_003FB640(*(f32 *)(S + 0x30), &q0, 0x24, M) == 0) {
        hit = 1;
        if (func_003D3CB0(&q0, Mp, 0x24, M, 0) == 0) {
            goto after;
        }
    }
    flags |= 4;
    if (hit == 0) {
        *(V4_00455550 *)Mp = *(V4_00455550 *)(D_L01_001EAA00 + 0x20);
    } else {
        *(V4_00455550 *)Mp = *(V4_00455550 *)(D_L01_001EAA00 + 0x30);
        func_0038CF68(&m60[0], &V, *(f32 *)(S + 0x34));
        v3add_00455550(Mp, Mp, (f32 *)&m60[0]);
    }
    f20 = 1.0f;
    func_0038CF68(&q50, D_L01_001EAA00 + 0x40, f20);
    f0 = func_0038CE68(&q50, &V);
    if (f0 <= -0.707000017f) {
        f20 = func_0038CE68(S80, &q50);
        if (f20 < 0.0f) {
            if (*(s32 *)(D_L01_001EAA00 + 0x18) == 0 || *(s32 *)(D_L01_001EAA00 + 0x1C) > 0) {
                func_0038CF68(&q80, M + 0xE0, 0.2f);
                func_0038CF68(&q90, M + 0xE0, -2.0f);
                v3add_00455550((f32 *)&q80, (f32 *)&q80, Mp);
                v3add_00455550((f32 *)&q90, (f32 *)&q90, Mp);
                if (func_003D3CB0(&q80, &q90, 2, M, 0) != 0) {
                    S[0x1A] = 2;
                }
            }
            func_0038CF68(&q70, &q50, f20);
            v3sub_00455550(S80, S80, (f32 *)&q70);
            if (S[0x1A] == 2) {
                aB0 = func_0038CEA8(S80);
                func_003C4138(&aB0, 0.0f, *(f32 *)(S + 0x50));
                func_0038CF68(S80, S80, aB0);
            }
        }
    } else {
        f0 = func_0038CE68(S80, &q50);
        if (f0 < 0.0f) {
            f12 = f0 * -(*(f32 *)(S + 0x3C) + f20);
            func_0038CF68(&q70, &q50, f12);
            v3add_00455550(S80, S80, (f32 *)&q70);
        }
    }
after:
    if (S[0x1A] == 0) {
        if (f22 < 0.0f) {
            S[0x1A] = 1;
            return flags;
        }
    }
    if ((*(u16 *)(S + 0x38) & 2) != 0) {
        if ((flags & 4) == 0) {
            return flags;
        }
        if (f22 <= 0.0f) {
            flags |= 1;
        }
        return flags;
    }
    if ((M[0x60] & 2) != 0) {
        if ((*(u16 *)(S + 0x38) & 1) != 0) {
            flags |= 1;
        } else {
            flags |= 2;
        }
    }
    return flags;
}

/* functional: medium. Hand-translated control flow of a 700-instruction camera/collision routine with plain-C vector helpers (VU0 xyz ops, w from dest); every branch, constant (bit patterns), offset and callee checked against the asm once; the retry loop and the float compare directions were verified by reading only (no byte match, 688 diff lines) so a slip in a rarely taken branch is possible. Locals: B0 saved list holds up to 16 pointers (retail has room for 12 before overlapping v90). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00543AA8;
extern s32 D_L39_002412DC;
extern u8 *D_L39_00241640;
extern u8 *D_L39_0024BF5C;
extern u8 *D_L39_0024BC4C;
extern u8 *D_L39_0024C000;
extern u8 *D_L39_0024AEC0 __attribute__((section(".sdata")));
extern u8 *D_L39_0024AEC4 __attribute__((section(".sdata")));
extern f32 D_L39_0024AEDC __attribute__((section(".sdata")));
typedef struct { u8 p0[0x18]; u8 *x18; u8 p1C[0x24]; V_00543AA8 x40; } G_00543AA8;
extern G_00543AA8 D_L39_0025F740;
extern V_00543AA8 D_L39_0025F770;
extern V_00543AA8 D_L39_0025F780;
extern u8 *D_L39_0025F758;
extern void *D_L39_002637C0[];
extern void func_L18_00353110(void *);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern u32 *func_L39_0061D7B0(void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_004464C8(void *, void *, void *, void *);
extern f32 func_L01_00446E38(void *, void *, s32, void *, f32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_L01_003FDCA0(void *, s32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);

static void vadd_00543AA8(V_00543AA8 *d, V_00543AA8 *a, V_00543AA8 *b) {
    f32 w = a->w;
    d->x = a->x + b->x; d->y = a->y + b->y; d->z = a->z + b->z; d->w = w;
}
static void vsub_00543AA8(V_00543AA8 *d, V_00543AA8 *a, V_00543AA8 *b) {
    f32 w = a->w;
    d->x = a->x - b->x; d->y = a->y - b->y; d->z = a->z - b->z; d->w = w;
}

s32 func_L39_00543AA8(u8 *o) {
    u8 *s;
    u8 *g;
    u8 *fp = 0;
    V_00543AA8 *pos = (V_00543AA8 *)(o + 0x10);
    V_00543AA8 v0, v10, v20, v30, v40, v50, v90;
    void *saved[16];
    s32 A0 = 0, A4 = 0, A8 = 0, AC = 1, B0 = 0;
    s32 *B4;
    s32 n, i, idx;
    f32 f21;
    u8 *p;

    func_L18_00353110(o);
    s = *(u8 **)(o + 0x68);
    A4 = 0;
    *(u32 *)&v20 = 0; *((u32 *)&v20 + 1) = 0; *((u32 *)&v20 + 2) = 0; *((u32 *)&v20 + 3) = 0;
    A8 = 0;
    if (D_L39_00241640 != 0) {
        AC = (*(s8 *)(D_L39_00241640 + 0x18F) != 0) ? 1 : 0;
    }
    g = *(u8 **)(s + 0x384);
    if (g != 0 && (p = *(u8 **)(g + 0x2D8)) != 0 && *(u8 *)(p + 0x1A14) != 0) {
        u8 *a = D_L39_0024AEC0;
        u8 *b = D_L39_0024AEC4;
        if (a == o && b != 0) {
            fp = b;
        } else if (b == o && a != 0) {
            fp = a;
        }
    }
    B0 = 0;
    n = func_003D4D00(pos, 0, o, 0, 4.5f);
    B4 = (s32 *)(s + 0x308);
    for (i = 0; i < n; i++) {
        u32 *r = func_L39_0061D7B0(D_L39_002637C0[i]);
        if (r != 0) {
            u32 v = (*r & 0x0F000000) >> 24;
            if (v == 0 || v == 2) {
                saved[B0] = D_L39_002637C0[i];
                B0 = B0 + 1;
                *(s32 *)((u8 *)D_L39_002637C0[i] + 0x98) = 0;
            }
        }
    }
    for (i = 0; i < 18; i++) {
        idx = B4[i];
        if (idx != -1) {
            u8 *o2 = D_L39_0024BF5C + (idx << 8);
            if (AC != 0 || *(s16 *)(o2 + 0xAA) != 0x10C6) {
                *(s32 *)(o2 + 0x98) = *(s32 *)(*(u8 **)(o2 + 0x24) + 0x10);
            }
        }
    }
    if (*(s32 *)(s + 0x3BC) != 0) {
        s32 a5 = *(s32 *)(s + 0x3EC);
        if (a5 != -1) {
            if (func_00382380(pos, a5, 0) == 0) {
                vsub_00543AA8(&v20, (V_00543AA8 *)(D_L39_0024C000 + (a5 << 7) + 0x30), pos);
                v20.z = 0.0f;
                goto L_E0C;
            }
        }
        a5 = *(s32 *)(s + 0x43C);
        if (a5 == -1 || func_L01_00456500(pos, a5) != 0) {
            goto L_E2C;
        }
        {
            u8 *ent = D_L39_0024BC4C + a5 * 0x30 + 0x20;
            s32 i1 = -1, i2 = -1;
            f32 best2 = 999999.0f, best1 = 999999.0f;
            s32 k;
            if (*(s16 *)(ent + 0x12) > 0) {
                k = 0;
                do {
                    f32 d = func_L01_0040E570(D_L39_0024C000 + (*(s32 *)(*(u8 **)(ent + 0x20) + k * 4) << 7) + 0x30, pos);
                    if (d < best1) {
                        i2 = i1;
                        best2 = best1;
                        best1 = d;
                        i1 = k;
                    } else if (d < best2) {
                        best2 = d;
                        i2 = k;
                    }
                    k++;
                } while (k < *(s16 *)(ent + 0x12));
            }
            func_L01_004464C8(&v90, D_L39_0024C000 + (i1 << 7) + 0x30, D_L39_0024C000 + (i2 << 7) + 0x30, pos);
            vsub_00543AA8(&v20, &v90, pos);
            v20.z = 0.0f;
        }
    L_E0C:
        func_0038CF68(&v20, &v20, 0.0003000000142492354f);
        vadd_00543AA8((V_00543AA8 *)(s + 0x3F0), (V_00543AA8 *)(s + 0x3F0), &v20);
        goto L_EAC;
    L_E2C:
        {
            f32 *q = (f32 *)(s + 0x3F0);
            for (i = 0; i < 3; i++) {
                f32 v = q[i];
                v = v - v * 0.09000000357627869f;
                q[i] = v;
                if (((v < 0.0f) ? -v : v) < 0.009999999776482582f) {
                    q[i] = 0.0f;
                }
            }
        }
    L_EAC:
        vadd_00543AA8((V_00543AA8 *)(s + 0x290), (V_00543AA8 *)(s + 0x290), (V_00543AA8 *)(s + 0x3F0));
        if (*(f32 *)(s + 0x300) < *(f32 *)(o + 0x18)) {
            *(f32 *)(o + 0x18) = *(f32 *)(s + 0x300);
            if (0.0f < *(f32 *)(s + 0x298)) {
                *(f32 *)(s + 0x298) = 0.0f;
            }
        } else if (*(f32 *)(o + 0x18) < *(f32 *)(s + 0x304)) {
            *(f32 *)(s + 0x298) = *(f32 *)(s + 0x298) + 0.014000000432133675f;
        }
        if (*(s32 *)(s + 0x3BC) != 0) {
            v20 = *(V_00543AA8 *)(s + 0x290);
            if (*(s32 *)(s + 0x3BC) != 0) {
                *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + 0.5f;
            }
        }
    }
    vadd_00543AA8(&v0, pos, &v20);
    if (fp != 0) {
        u32 t = *(u8 *)(fp + 0xBC);
        if (t != 7 && t != 9 && t != 0xA) {
            vsub_00543AA8(&v20, &v0, (V_00543AA8 *)(fp + 0x10));
            if (func_0038CEA8(&v20) < 5.0f) {
                func_0038CF68(&v20, &v20, 5.0f);
                vadd_00543AA8(&v0, &v20, (V_00543AA8 *)(fp + 0x10));
            }
        }
    }
    vsub_00543AA8(&v40, &v0, pos);
L_3FF0:
    f21 = func_L01_00446E38(pos, &v0, 0x84, o, 2.5f);
    if (!(0.0f <= f21 && f21 < 1.0f)) {
        goto L_4374;
    }
L_4040:
    func_0038CF68(&v30, &D_L39_0025F780, 1.0f);
    func_0038CE20(&v90, &v30, 0.00800000037997961f);
    vadd_00543AA8(pos, pos, &v90);
    if (f21 == 0.0f) {
        if (A8 == 0) {
            goto L_C8;
        }
        if (A8 < 3) {
            if (0.0f < func_0038CE68(&v50, &v30)) {
                goto L_C8;
            }
        }
    }
    goto L_E4;
L_C8:
    A8 = A8 + 1;
    A4 = 0;
    v50 = v30;
    goto L_3FF0;
L_E4:
    {
        f32 dot = func_0038CE68(&v40, &v30);
        A0 = 1;
        func_0038CE20(&v20, &v30, dot * -1.0099999904632568f);
    }
    vadd_00543AA8((V_00543AA8 *)(s + 0x290), (V_00543AA8 *)(s + 0x290), &v20);
    func_0038CE20(&v10, &v40, f21);
    vadd_00543AA8(pos, pos, &v10);
    if (D_L39_002412DC == 0x2B || D_L39_002412DC == 0x35) {
        u8 *h = D_L39_0025F740.x18;
        if (h != 0 && *(s16 *)(h + 0xAA) == 0x1B23) {
            *(f32 *)(s + 0x298) = *(f32 *)(s + 0x298) + D_L39_0024AEDC * 0.0004000000189989805f;
            h = D_L39_0025F740.x18;
            if (*(f32 *)(o + 0x18) < *(f32 *)(h + 0x18)) {
                *(f32 *)(o + 0x18) = *(f32 *)(h + 0x18) + 0.15000000596046448f;
            }
        }
    }
    g = *(u8 **)(s + 0x384);
    if (g != 0) {
        u8 *h = D_L39_0025F740.x18;
        if (h != 0 && *(s32 *)(g + 0x2D8) == 0 && *(s32 *)(g + 0x2DC) == 0 &&
            (*(s16 *)(h + 0xAA) == 0x10C6 || *(s16 *)(h + 0xAA) == 0x1A47)) {
            func_0038CE90(&v90, &D_L39_0025F740.x40, o + 0xC0);
            if (0.0f < v90.z) {
                func_0038CE20(&v90, &v90, -0.03920000046491623f);
            } else {
                func_0038CE20(&v90, &v90, 0.03920000046491623f);
            }
            vadd_00543AA8((V_00543AA8 *)(s + 0x290), (V_00543AA8 *)(s + 0x290), &v90);
            *(f32 *)(s + 0x298) = *(f32 *)(s + 0x298) - 0.011760001070797443f;
        }
    }
    if (*(f32 *)(s + 0x298) < 0.0f) {
        if (D_L39_0025F758 == 0) {
            *(s32 *)(s + 0x298) = 0;
        } else if (*(s16 *)(D_L39_0025F758 + 0xAA) == 0x10C6 || *(s16 *)(D_L39_0025F758 + 0xAA) == 0x1A47) {
            *(s32 *)(s + 0x298) = 0;
        }
    }
    if (A4 == 0) {
        f32 one = 1.0f;
        func_0038CE20(&v40, s + 0x290, one - f21);
        vadd_00543AA8(&v90, pos, &v40);
        f21 = func_L01_00446E38(pos, &v90, 0x84, o, 2.5f);
        if (f21 < one) {
            if (0.0f <= f21) {
                A4 = 1;
                goto L_4040;
            }
            goto L_4384;
        }
        goto L_4374;
    }
    goto L_4388;
L_4374:
    vadd_00543AA8(pos, pos, &v40);
L_4384:
L_4388:
    for (i = 0; i < 4; i++) {
        s32 found = 0;
        if (func_L01_003FB640(pos, 4, o, 2.5f) != 0) {
            *pos = D_L39_0025F770;
            found = 1;
        }
        if (func_L01_003FDCA0(pos, 0, 2.5f) != 0) {
            *pos = D_L39_0025F770;
            found = 1;
        }
        if (found == 0) {
            break;
        }
    }
    if (*(s32 *)(s + 0x3BC) != 0) {
        *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) - 0.5f;
    }
    if (pos->x < 10.0f) pos->x = 10.0f;
    if (1013.0f < pos->x) pos->x = 1013.0f;
    if (pos->y < 10.0f) pos->y = 10.0f;
    if (1013.0f < pos->y) pos->y = 1013.0f;
    if (pos->z < 10.0f) pos->z = 10.0f;
    if (1013.0f < pos->z) pos->z = 1013.0f;
    for (i = 0; i < 18; i++) {
        idx = B4[i];
        if (idx != -1) {
            u8 *o2 = D_L39_0024BF5C + (idx << 8);
            if (AC != 0 || *(s16 *)(o2 + 0xAA) != 0x10C6) {
                *(s32 *)(o2 + 0x98) = 0;
            }
        }
    }
    for (i = 0; i < B0; i++) {
        u8 *r = (u8 *)saved[i];
        *(s32 *)(r + 0x98) = *(s32 *)(*(u8 **)(r + 0x24) + 0x10);
    }
    *(f32 *)(s + 0x368) = *(f32 *)(o + 0x18);
    *(V_00543AA8 *)(s + 0x420) = *pos;
    return A0;
}

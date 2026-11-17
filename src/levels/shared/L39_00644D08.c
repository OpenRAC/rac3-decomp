#include "common.h"

/* localdecomp:start func_L39_00644D08 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00644D08;

typedef union Buf_00644D08 {
    u8 b[8];
    u32 w[2];
} Buf_00644D08;

typedef struct Glob_00644D08 {
    u8 pad0[0xA4];
    u8 bA4[4];
} Glob_00644D08;

extern Glob_00644D08 D_001A5810;
extern s32 D_L39_002410F8[] __attribute__((section(".sdata")));
extern u8 D_L39_004997E0[];

extern void func_0038CC88(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CED8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D2A0(void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_L01_004130C0(u8 *);
extern void func_L01_004130D0(u8 *);
extern void func_L39_00595C18(void *, void *, void *, void *, void *, s32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_L39_005C42E8(s32, s32);
extern s32 func_L39_00639D90(void *);
extern void func_L39_006461B0(u8 *);
extern void func_L39_00646B98(void *);
extern void func_L39_00647150(u8 *, s32);

static __inline__ u32 Dec_00644D08(u8 *q) {
    Buf_00644D08 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static __inline__ s32 DecEq_00644D08(u8 *q, s32 v) {
    return Dec_00644D08(q) == v;
}

static __inline__ s32 Busy_00644D08(u8 *a) {
    return DecEq_00644D08(a + 0x19E4, 1) || DecEq_00644D08(a + 0x19E4, 0x1D) ||
           a[0x24FE] != 0 || a[0x2500] != 0;
}

static __inline__ void Steer_00644D08(u8 *a, s32 v, f32 scale) {
    V4_00644D08 tmp;

    func_0038CE20(&tmp, a + 0x1120, 0.7f);
    vec_add_ab(&tmp, &tmp, a + 0xA0);
    func_L39_00595C18(a + 0x11A0, *(void **)(a + 0x2534), a + 0x1180, a + 0x1170, &tmp, v, scale);
}

void func_L39_00644D08(u8 *a) {
    s32 old;
    s32 c;
    s32 v;
    f32 scale;
    f32 ang;
    f32 t;
    u8 busy;

    if (DecEq_00644D08(a + 0x19E4, 0x31)) {
        return;
    }
    old = *(s32 *)(a + 0x1310);
    if (a[0x1A14] != 0) {
        if (DecEq_00644D08(a + 0x19E4, 0x76)) {
            if (D_001A5810.bA4[*(s32 *)(a + 0x2544)] != 0) {
                D_001A5810.bA4[*(s32 *)(a + 0x2544)] = 0;
                func_L39_00647150(a, 0);
                if (*(u8 **)(a + 0x2558) != 0) {
                    *(u16 *)(*(u8 **)(*(u8 **)(a + 0x2558) + 4) + 0x86) = 0;
                }
            }
        } else {
            if (D_L39_002410F8[*(s32 *)(a + 0x2544)] != D_001A5810.bA4[*(s32 *)(a + 0x2544)] &&
                !DecEq_00644D08(a + 0x19E6, 0x14) && !DecEq_00644D08(a + 0x19E4, 0x7A) &&
                !DecEq_00644D08(a + 0x19E4, 1) && !DecEq_00644D08(a + 0x19E4, 0x1D)) {
                D_001A5810.bA4[*(s32 *)(a + 0x2544)] = D_L39_002410F8[*(s32 *)(a + 0x2544)];
                func_L39_00647150(a, D_L39_002410F8[*(s32 *)(a + 0x2544)]);
                if (*(u8 **)(a + 0x2558) != 0) {
                    *(u16 *)(*(u8 **)(*(u8 **)(a + 0x2558) + 4) + 0x86) =
                        D_L39_002410F8[*(s32 *)(a + 0x2544)];
                }
            }
        }
    } else {
        if (D_001A5810.bA4[*(s32 *)(a + 0x2544)] != *(u16 *)(*(u8 **)(*(u8 **)(a + 0x2558) + 4) + 0x86)) {
            D_L39_002410F8[*(s32 *)(a + 0x2544)] = *(u16 *)(*(u8 **)(*(u8 **)(a + 0x2558) + 4) + 0x86);
            D_001A5810.bA4[*(s32 *)(a + 0x2544)] = D_L39_002410F8[*(s32 *)(a + 0x2544)];
            func_L39_00647150(a, D_L39_002410F8[*(s32 *)(a + 0x2544)]);
        }
    }
    *(u16 *)(a + 0x1280) &= 0xFFF7;
    if (*(s32 *)(a + 0x1310) != 0) {
        c = *(u32 *)(*(u8 **)(a + 0x2534) + 0x1A0) & func_L39_005C42E8(4, *(s32 *)(a + 0x2544));
        if (c != 0 && *(s32 *)(a + 0x1310) == 1 && (busy = Busy_00644D08(a)) != 0) {
            func_L39_00647150(a, 2);
            *(u16 *)(a + 0x1280) |= 8;
        } else if (c == 0 && *(s32 *)(a + 0x1310) == 2 &&
                   D_001A5810.bA4[*(s32 *)(a + 0x2544)] == 1) {
            func_L39_00647150(a, 1);
        }
    }
    if (a[0x1A14] != 0) {
        V4_00644D08 mtx[4];

        func_0038CC88(a + 0x1100, a + 0x20, 0x30);
        *(V4_00644D08 *)(a + 0x1120) = *(V4_00644D08 *)(*(u8 **)(a + 0x2530) + 0x80);
        func_0038CF68(a + 0x1120, a + 0x1120, 1.0f);
        func_0038CE90(a + 0x1110, a + 0x1100, a + 0x1120);
        func_0038CF68(a + 0x1110, a + 0x1110, 1.0f);
        func_0038CE90(a + 0x1100, a + 0x1120, a + 0x1110);
        func_0038CF68(a + 0x1100, a + 0x1100, 1.0f);
        func_0038D2A0(mtx);
        func_0038D5B0(mtx, a + 0x1100);
        func_0038CC88(a + 0x1130, mtx, 0x30);
    }
    if (*(s32 *)(a + 0x1310) != 0) {
        if (a[0x1A14] != 0) {
            scale = 1.0f;
            if (DecEq_00644D08(a + 0x19E6, 0x14)) {
                scale = 2.5f;
            }
            *(u16 *)(a + 0x1282) = *(u16 *)(a + 0x2548);
            if (*(f32 *)(a + 0x48) > 0.99999f || DecEq_00644D08(a + 0x19E4, 0x2B) ||
                DecEq_00644D08(a + 0x19E4, 0x2C)) {
                func_L01_004130D0(a + 0x11A0);
            } else {
                func_L01_004130C0(a + 0x11A0);
            }
            v = D_L39_002410F8[*(s32 *)(a + 0x2544)];
            if (v == 0) {
                busy = Busy_00644D08(a);
                if (busy) {
                    *(u16 *)(a + 0x1280) |= 8;
                }
            }
            if (DecEq_00644D08(a + 0x19E6, 3) || DecEq_00644D08(a + 0x19E6, 0x14) ||
                DecEq_00644D08(a + 0x19E4, 0x7A)) {
                ang = 45.0f;
                if (DecEq_00644D08(a + 0x19E6, 0x14) || DecEq_00644D08(a + 0x19E4, 0x7A)) {
                    ang = -10.0f;
                }
                t = -(ang * 0.017453292f);
                if (*(f32 *)(a + 0x1258) != t) {
                    func_003C4138((f32 *)(a + 0x1258), t, 0.041887905f);
                }
            } else {
                if (*(f32 *)(a + 0x1258) != -1.2217305f) {
                    func_003C4138((f32 *)(a + 0x1258), -1.2217305f, 0.041887905f);
                }
            }
            Steer_00644D08(a, v, scale);
            func_L39_00646B98(a);
        } else {
            func_L39_00646B98(a);
            func_0038CC88(a + 0x11A0, a + 0x23C0, 0x30);
            *(f32 *)(a + 0x1200) = *(f32 *)(a + 0x23B4);
            *(f32 *)(a + 0x11E0) = *(f32 *)(a + 0x23B8);
            func_00382760(a + 0x1290, 1.0f, *(f32 *)(a + 0x23B8), -*(f32 *)(a + 0x23B4));
            if (*(f32 *)(a + 0x48) > 0.99999f || DecEq_00644D08(a + 0x19E4, 0x2B) ||
                DecEq_00644D08(a + 0x19E4, 0x2C)) {
                *(u16 *)(a + 0x1280) |= 2;
            } else {
                *(u16 *)(a + 0x1280) &= 0xFFFD;
            }
            if (*(s32 *)(a + 0x1288) != 0 && !(*(u16 *)(a + 0x1280) & 2)) {
                V4_00644D08 tmp;

                func_0038D000(&tmp, a + 0x1290, *(void **)(a + 0x128C));
                *(f32 *)(a + 0x11E0) = func_0038D160(tmp.x, tmp.y);
                *(f32 *)(a + 0x1200) = -func_0038D160(func_0038CED8(&tmp), tmp.z);
            }
            func_0038CF68(a + 0x12B0, a + 0x11A0, *(f32 *)(a + 0x12C0));
            vec_add_ab(a + 0x12B0, a + 0x12B0, a + 0x1180);
        }
        if (D_001A5810.bA4[*(s32 *)(a + 0x2544)] == 0) {
            *(s16 *)(a + 0x3E4) = 0;
        } else if (*(s32 *)(a + 0x1310) == 2) {
            *(s16 *)(a + 0x3E4) = 2;
        } else if (*(s32 *)(a + 0x478) == 10) {
            *(s16 *)(a + 0x3E4) = 0;
        } else {
            *(s16 *)(a + 0x3E4) = 2;
        }
    } else {
        *(f32 *)(a + 0x1200) = *(f32 *)(a + 0x23B4);
        *(f32 *)(a + 0x11E0) = *(f32 *)(a + 0x23B8);
        func_0038D308(a + 0x11A0, a + 0x23B0);
        *(V4_00644D08 *)(a + 0x1290) = *(V4_00644D08 *)(a + 0x11A0);
        func_0038CF68(a + 0x11D0, a + 0x40, *(f32 *)(a + 0x132C));
        vec_add_ab(a + 0x11D0, a + 0x11D0, a + 0xA0);
        if (D_001A5810.bA4[*(s32 *)(a + 0x2544)] == 1) {
            V4_00644D08 tmp;

            func_0038CF68(&tmp, a + 0x1260, *(f32 *)(a + 0x12C4));
            func_0038D000(&tmp, &tmp, a + 0x11A0);
            vec_add_ab(a + 0x11D0, a + 0x11D0, &tmp);
        }
    }
    if (func_L39_00639D90(a) != 0 ||
        ((busy = Busy_00644D08(a)) != 0 &&
         ((a[0x1A0A] != 0 && a[0x1A14] != 0) || (a[0x1A14] == 0 && *(s32 *)(a + 0x2F0) >= 9)))) {
        if (*(s32 *)(a + 0x1310) == 0) {
            *(s32 *)(a + 0x1310) = D_001A5810.bA4[*(s32 *)(a + 0x2544)] != 0 ? D_001A5810.bA4[*(s32 *)(a + 0x2544)] : 2;
            *(s32 *)(a + 0x1308) = 0;
            *(s32 *)(a + 0x130C) = 0;
            *(s32 *)(a + 0x131C) = 0;
        }
    } else if ((busy = Busy_00644D08(a)) == 0 && *(s32 *)(a + 0x1310) != 0) {
        *(s32 *)(a + 0x1310) = D_001A5810.bA4[*(s32 *)(a + 0x2544)];
        if (!DecEq_00644D08(a + 0x19E4, 0x90)) {
            *(u16 *)(*(u8 **)(a + 0x424) + 0x34) &= 0xFFFE;
            a[0x1A0A] = 0;
        }
    }
    if (old == 2 && a[0x1A14] != 0) {
        func_L39_006461B0(a);
    }
}
/* localdecomp:end func_L39_00644D08 */

/* localdecomp:start func_L39_006461B0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_006461B0;

extern s32 D_001A5CDC __attribute__((section(".data")));
extern const f32 D_001DAA30_sda;
extern f32 D_L39_00246144;
extern s32 D_L39_0024112C;
extern u8 D_L39_0049C8D0[];
extern u8 D_L39_0025F760[];

extern void func_L39_006468F0(u8 *a, u8 *b);
extern s32 func_L39_00639D90(void *);
extern void func_003C7C38(void *);
extern void func_0038D570(void *, void *);
extern void func_0038D590(void *, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_003C3FC0(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_003C41A0(f32 *, f32 *, f32, f32, f32, f32);
extern void func_0038CE90(void *, void *, void *);

void func_L39_006461B0(u8 *a) {
    u8 *m = *(u8 **)(a + 0x450);
    s32 st;
    s32 skip;
    u8 *ent;
    f32 k;
    f32 t;
    V4_006461B0 mtx[4];
    V4_006461B0 rot[4];
    V4_006461B0 pos;
    V4_006461B0 v90;
    V4_006461B0 vA0;

    if (m == 0) {
        return;
    }
    if (*(s16 *)(m + 0xAA) == 0x18AB) {
        func_L39_006468F0(a, m);
        return;
    }
    st = -1;
    if (*(s32 *)(a + 0x474) == 2) {
        st = *(s32 *)(a + 0x478);
    }
    if (st == 6 || st == 12) {
        skip = 1;
    } else {
        skip = 0;
    }
    if (skip) {
        *(u16 *)(m + 0x34) |= 1;
        m[0x31] = 0;
        if (*(void (**)(void *))(m + 0x64)) {
            (*(void (**)(void *))(m + 0x64))(m);
        }
        func_003C7C38(m);
        return;
    }
    if (*(s32 *)(a + 0x1310) != 2) {
        if (*(void (**)(void *))(m + 0x64)) {
            (*(void (**)(void *))(m + 0x64))(m);
        }
        func_003C7C38(m);
        return;
    }
    ent = D_L39_0049C8D0 + *(s32 *)(a + 0x478) * 128;
    k = 0.15f;
    if (D_001A5CDC == 2) {
        k = 0.1f;
    }
    func_0038D570(mtx, a + 0x11A0);
    mtx[3] = *(V4_006461B0 *)(a + 0x11D0);
    mtx[3].w = 1.0f;
    pos = *(V4_006461B0 *)ent;
    pos.x += *(f32 *)(a + 0x1318);
    pos.z -= k;
    pos.y += 0.05f;
    t = (0.02f < *(f32 *)(a + 0x1A4) ? D_L39_00246144 : D_001DAA30_sda) * 0.017453292f * 0.020000001f;
    func_003C4138((f32 *)(a + 0x1324), t, 0.010053097f);
    *(f32 *)(a + 0x1320) = func_0038DAB8(*(f32 *)(a + 0x1320), *(f32 *)(a + 0x1324));
    pos.z += func_0038D0B0(*(f32 *)(a + 0x1320)) * 0.02f;
    func_0038D028(m + 0x10, &pos, mtx);
    if (func_L39_00639D90(a) == 0) {
        vec_add_ab(m + 0x10, m + 0x10, a + 0x180);
    }
    func_0038D328(rot, ent + 0x10);
    func_0038D5F0(m + 0xC0, mtx, rot);
    func_003C48A8(m + 0xC0, m + 0xF0);
    func_003C3FC0(a + 0x1160, m + 0xF0);
    *(f32 *)(m + 0xCC) = *(f32 *)(m + 0xDC) = *(f32 *)(m + 0xEC) = 0.0f;
    if (a[0x1A0B]) {
        m[0x31] = 0;
        *(u16 *)(m + 0x34) |= 1;
    } else {
        m[0x31] = 1;
        *(u16 *)(m + 0x34) &= 0xFFFE;
    }
    func_003C7C38(m);
    if (((u8)D_L39_0024112C ^ 1) & 1) {
        f32 s = 0.0009765625f;
        f32 h = *(f32 *)(m + 0xC) * s;

        func_0038CE20(&v90, m, s);
        func_0038CF68(&vA0, m + 0xD0, h * -1.2f);
        vec_add_ab(&vA0, &vA0, &v90);
        if (func_003D3CB0(*(void **)(a + 0x2530), &vA0, 0, *(void **)(a + 0x2524), 0)) {
            *(f32 *)(a + 0x131C) = *(f32 *)(a + 0x1318) - h + func_0038CF00(D_L39_0025F760, &v90);
            if (*(f32 *)(a + 0x131C) > 0.0f) {
                *(f32 *)(a + 0x131C) = 0.0f;
            } else if (*(f32 *)(a + 0x131C) < -1.5f) {
                *(f32 *)(a + 0x131C) = -1.5f;
            }
        } else {
            *(f32 *)(a + 0x131C) = 0.0f;
        }
    }
    func_003C41A0((f32 *)(a + 0x1318), (f32 *)(a + 0x1314), *(f32 *)(a + 0x131C), 0.006f, 0.006f, 0.10000001f);
    if (*(s32 *)(a + 0x1310) == 2) {
        func_0038D590(a + 0x380, mtx);
        *(V4_006461B0 *)(a + 0x3B0) = mtx[0];
        *(V4_006461B0 *)(a + 0x3C0) = *(V4_006461B0 *)(*(u8 **)(a + 0x2530) + 0x10);
    } else {
        vu0_q qu;

        vec_sub_ba(a + 0x380, a + 0x12B0, a + 0x1180);
        __asm__("vmr32.xyzw %0, $vf0" : "=j"(qu));
        __asm__("sqc2 %1, %0" : "=m"(v90) : "j"(qu));
        func_0038CF68(a + 0x380, a + 0x380, 1.0f);
        func_0038CE90(a + 0x390, a + 0x380, &v90);
        func_0038CF68(a + 0x390, a + 0x390, 1.0f);
        func_0038CE90(a + 0x3A0, a + 0x390, a + 0x380);
        func_003C48A8(a + 0x380, a + 0x3C0);
        *(V4_006461B0 *)(a + 0x3B0) = *(V4_006461B0 *)(a + 0x380);
    }
    if (*(void (**)(void *))(m + 0x64)) {
        (*(void (**)(void *))(m + 0x64))(m);
    }
    func_0038D570(a + 0x1340, m + 0xC0);
    *(V4_006461B0 *)(a + 0x1370) = *(V4_006461B0 *)(m + 0x10);
}
/* localdecomp:end func_L39_006461B0 */

/* localdecomp:start func_L39_00646660 */
#include "vu0.h"

extern s32 *D_001D5A10_sda;
extern void func_L39_006468F0(u8 *a, u8 *b);
extern void func_0038D590(void *, void *);
extern void func_0038D278(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_003C7DD8(void *);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00646660;

void func_L39_00646660(u8 *a, s32 alt) {
    u8 *m = *(u8 **)(a + 0x450);
    u8 *src;
    s32 st;
    s32 skip;

    if (m == 0) {
        return;
    }
    st = -1;
    if (*(s32 *)(a + 0x474) == 2) {
        st = *(s32 *)(a + 0x478);
    }
    if (st == 6 || st == 12) {
        skip = 1;
    } else {
        skip = 0;
    }
    if (skip) {
        return;
    }
    if (*(s16 *)(m + 0xAA) == 0x18AB) {
        if (alt) {
            func_L39_006468F0(a, m);
            if (m[0x42] == m[0x43] && m[0x42] == 6) {
                return;
            }
            if (*D_001D5A10_sda < 2) {
                *(f32 *)(m + 0x18) += 0.6f;
            } else {
                *(f32 *)(m + 0x18) += 0.2f;
            }
        } else {
            m[0x31] = 1;
            *(u16 *)(m + 0x34) &= 0xFFFE;
        }
        return;
    }
    src = alt ? a + 0x1340 : a + 0x1380;
    func_0038D590(m + 0xC0, src);
    *(V4_00646660 *)(m + 0x10) = *(V4_00646660 *)(src + 0x30);
    if (*(s16 *)(a + 0x2488) != 0 && alt == 0) {
        V4_00646660 rot[3];
        V4_00646660 scale;
        V4_00646660 mtx[3];
        V4_00646660 rel;

        func_0038D278(rot);
        scale = *(V4_00646660 *)(a + 0xF0);
        if (scale.x < 0.0f) {
            scale.x = 0.0f;
        }
        if (scale.y < 0.0f) {
            scale.y = 0.0f;
        }
        if (scale.z < 0.0f) {
            scale.z = 0.0f;
        }
        func_0038CF68(&rot[0], &rot[0], scale.x);
        func_0038CF68(&rot[1], &rot[1], scale.y);
        func_0038CF68(&rot[2], &rot[2], scale.z);
        func_0038D5F0(mtx, rot, a + 0x60);
        func_0038D5F0(mtx, a + 0x20, mtx);
        func_0038D5F0(m + 0xC0, mtx, m + 0xC0);
        vec_sub_ba(&rel, m + 0x10, a + 0xA0);
        func_0038D000(&rel, &rel, mtx);
        vec_add_ab(m + 0x10, &rel, a + 0xA0);
        if (*(f32 *)(a + 0xF0) < 0.1f) {
            *(u16 *)(m + 0x34) |= 0x41;
        }
    }
    func_003C7DD8(m);
    if ((u32)((*(u8 **)(a + 0x2524))[0x42] - 0x40) < 2) {
        *(f32 *)(m + 0xC) += 1800.0f;
    }
}
/* localdecomp:end func_L39_00646660 */

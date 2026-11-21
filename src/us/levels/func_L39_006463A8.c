#include "common.h"

/* NTSC-U counterpart of func_L39_00648C20 (src/levels/shared/L39_00648C20.c) */
/* localdecomp:start func_L39_006463A8 */
#include "vu0.h"

typedef struct VT_00648C20 {
    u8 pad0[0x30];
    void (*f30)(u8 *);
} VT_00648C20;

typedef union Buf_00648C20 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00648C20;

typedef struct Ent_00648C20 {
    u8 pad0[0x18];
    s32 i18;
    u8 pad1C[0x10];
} Ent_00648C20;

/* func_L39_00620BD8's result (L39_006233A8.c's Out_006233A8) */
typedef struct Out_00648C20 {
    vu0_v4 v0;
    vu0_v4 v10;
    u8 pad20[4];
    f32 f24;
    s32 f28;
    u8 pad2C[8];
    s32 f34;
    s32 f38;
} Out_00648C20;

typedef struct Tab_00648C20 {
    u8 pad[0xA4];
    u8 flags[0x100];
} Tab_00648C20;

extern u8 D_L39_004998A0[];
extern u8 D_L39_004998A1[];
extern u32 D_L39_0024BAC8;
extern Tab_00648C20 D_001A5990;
extern u8 *D_L39_002638C0[];
__asm__(".extern D_L39_00242AB0, 16");
extern vu0_v4 D_L39_00242AB0 __attribute__((section(".sdata")));
extern const f32 D_L39_0024617C[][4] __attribute__((section(".sdata")));
extern f32 D_L39_002462D0[] __attribute__((section(".sdata")));
extern Ent_00648C20 D_L39_0047A968[];

static inline u32 Dec_00648C20(u8 *q) {
    Buf_00648C20 buf;
    u8 *d;
    s32 n;
    s32 k;
    s32 m;
    s32 i;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

static inline s32 DecEq_00648C20(u8 *q, u32 v) {
    return Dec_00648C20(q) == v;
}

static inline s32 DecGt_00648C20(u8 *q, s32 v) {
    return (s32)Dec_00648C20(q) > v;
}

static inline void Prep_00648C20(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004998A0[0];
    } else {
        t = *q;
        *q = D_L39_004998A1[0];
        D_L39_004998A1[0] = t;
    }
}

static inline void Set16_00648C20(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00648C20 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00648C20(q);
    buf.h[2] = v;
    key = ((u32 *)D_L39_004998A0)[((u32)hk * D_L39_0024BAC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    buf.w[0] = (u32)q ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static inline void Set32_00648C20(u8 *q, u32 v) {
    u8 *hk = q;
    Buf_00648C20 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00648C20(q);
    key = ((u32 *)D_L39_004998A0)[((u32)hk * D_L39_0024BAC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = v;
    buf.w[1] ^= key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
    }
}

extern s32 func_L01_003EFFE0(s32, s32);
extern s32 func_003CF790(void *, s32, f32, void *, void *);
extern void func_003886E8(f32 *, f32 *, f32);
extern f32 func_00388730(void *, void *);
extern void func_00388758(void *, void *, void *);
extern f32 func_003887A0(f32 *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0040C1F8(void *, void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_L01_00443938(u8 *, u8 *, s32, void *, void *, f32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern f32 func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_L01_004454A8(s32, f32, f32);
extern void func_L01_00445558(void *, s32, f32, f32);
extern f32 func_L01_004455F0(f32 *, f32, f32 *, f32, f32, f32, s32);
extern s32 func_L39_005B6970(u8 *);
extern void func_003BF640(f32 *, f32);
extern void func_L39_005F0D88(s32, s32, s32, s32);
extern s32 func_L39_00620BD8(u8 *, vu0_v4 *, void *, Out_00648C20 *);
extern void func_L39_0062A8F0(u8 *, f32);
extern void func_L39_0062A9B8(u8 *, f32);
extern void func_L39_0062C710(u8 *);
extern void func_L39_0062D4A8(u8 *, f32, f32, f32);
extern void func_L39_0062EC98(u8 *, s32);
extern void func_L39_0062FA50(void *, void *, void *, f32);
extern void func_L39_0062FD10(void *, void *, void *, f32);
extern f32 func_L39_0062FD90(u8 *, void *);
extern f32 func_L39_0062FE30(u8 *, void *);
extern void func_L39_006301D8(u8 *, void *, void *, f32);
extern s32 func_L39_00630400(u8 *, f32);
extern void func_L39_00630438(u8 *, void *, void *, f32);
extern void func_L39_00630530(u8 *, s32, f32);
extern void func_L39_00630918(u8 *);
extern void func_L39_00630988(u8 *, f32, f32, f32);
extern void func_L39_00630AC0(u8 *, s32, f32, f32, f32);
extern void func_L39_00630DD8(u8 *, f32, f32);
extern void func_L39_00630E28(u8 *, f32);
extern void func_L39_00630F00(u8 *);
extern void func_L39_00631138(u8 *, f32, f32, f32);
extern f32 func_L39_00631430(u8 *, void *, s32);
extern void func_L39_006314B0(u8 *);
extern void func_L39_006325D0(u8 *, f32, f32);
extern void func_L39_006325F0(u8 *, f32, f32);
extern void func_L39_00632600(u8 *, f32, f32);
extern void func_L31_004F0040_006463A8(u8 *, f32, f32);
extern void func_L39_00635680(void *, void *, void *, s32, s32, s32, s32);
extern void func_L39_00635C78(u8 *, f32, f32, f32);
extern void func_L39_00637810(u8 *, s32, s32, s32);
extern void func_L39_006391F8(u8 *);
extern void func_L39_00644F00(void *, void *);
extern void func_L39_006481E0(u8 *);
extern void func_L39_00649380(u8 *);
extern void func_L39_00649F38(u8 *);
extern void func_L39_0064AC00(u8 *);
extern void func_L39_0064B448(u8 *);
extern void func_L39_0064BB08(u8 *);
extern void func_L39_0064C050(u8 *);

void func_L39_006463A8(void *arg) {
    u8 *o = arg;
    u8 *q;
    u32 a;
    u32 qb;
    u32 x;
    u8 ok;

    q = *(u8 **)(o + 0x2524);
    a = Dec_00648C20(o + 0x19E5);
    qb = q[0x43];
    switch (Dec_00648C20(o + 0x19E4)) {
    case 0x90: {
        x = Dec_00648C20(o + 0x19E7);
        if ((x ^ 0x7E) == 0) {
            func_L39_0064C050(o);
            break;
        }
        Set16_00648C20(o + 0x313, 2);
        x = Dec_00648C20(o + 0x19E7);
        if ((x ^ 0x76) == 0) {
            ((VT_00648C20 *)*(void **)(o + 0x14))->f30(o);
            break;
        }
        x = Dec_00648C20(o + 0x19E7);
        if ((x ^ 0x7A) == 0) {
            ((VT_00648C20 *)*(void **)(o + 0x14))->f30(o);
            break;
        }
    }
    case 0: case 1: case 3: case 4: case 0x1C: case 0x1D: case 0x1E: case 0x39:
    case 0x6F: case 0x71: case 0x7F:
        func_L39_006481E0(o);
        break;
    case 0x7E:
        func_L39_0064C050(o);
        break;
    case 2: case 0x72:
        func_L39_00649380(o);
        break;
    case 7: case 9: case 0xA: case 0xB: case 0xC: case 0xD: case 0xE: case 0xF:
    case 0x10: case 0x11: case 0x12: case 0x1B: case 0x38: case 0x68: case 0x70: case 0x83:
        func_L39_00649F38(o);
        break;
    case 0x13:
        func_L39_0064BB08(o);
        break;
    case 0x22:
        if (D_001A5990.flags[*(s32 *)(o + 0x2544)] != 0
            || ((ok = DecEq_00648C20(o + 0x19E4, 1) || DecEq_00648C20(o + 0x19E4, 0x1D) || o[0x24FE] != 0 || o[0x2500] != 0)
                && (o[0x1A0A] != 0 || o[0x1A14] == 0))) {
            *(vu0_v4 *)(o + 0xFC0) = *(vu0_v4 *)(o + 0x11A0);
            *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x11E0);
        } else if (*(s16 *)(o + 0x3E4) != 0) {
            *(vu0_v4 *)(o + 0xFC0) = *(vu0_v4 *)(o + 0x23C0);
            *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x23B8);
        }
        func_L39_00630AC0(o, 0, 0.037f, 0.13f, 0.20362175f);
        break;
    case 0x7D: {
        vu0_v4 vloc;
        vu0_v4 vloc2;
        f32 f21;
        f32 roll;
        s32 lim;
        s32 n;
        s32 i;
        {
            func_L39_00637810(o, 4, *(s32 *)(o + 0x2524), 0xD);
            func_L01_003EFFE0(0x16, *(s32 *)(o + 0x2534));
            func_L39_00630530(o, 0, 1.0f);
            *(f32 *)(o + 0xFB0) = 0.19166668f;
            func_L39_00630438(o, &vloc, o + 0x1580, 0.17f);
            f21 = *(f32 *)(o + 0x2468) * 0.020362176f * vloc.x;
            if (*(s32 *)(o + 0x2F0) < 0x3c) {
                *(f32 *)(o + 0xFB0) = 0.5f;
            }
            lim = 0x32;
            if (*(s32 *)(o + 0x2F0) < lim) {
                f21 = f21 * ((f32)*(s32 *)(o + 0x2F0) / (f32)lim);
            }
            if (0.2f < *(f32 *)(o + 0x2468)) {
                func_L39_00630988(o, 0.0f, 0.0f, f21);
            }
            func_L39_00630DD8(o, 0.027777778f, 0.004166667f);
            func_L39_00630E28(o, 99999.0f);
            func_L01_00445168((f32 *)(o + 0xA8), (f32 *)(o + 0x1590), *(f32 *)(o + 0x2A8) + 0.17f, 0.04f, 0.3f, 0.125f);
            func_003886E8((f32 *)&vloc2, (f32 *)(o + 0x140), 3.0f);
            vec_add_ab(&vloc2, &vloc2, o + 0xE0);
            n = func_003CF790(&vloc2, 0, 0.57f, *(void **)(o + 0x2524), 0);
            if (n != 0) {
                vu0_v4 vloc3;
                func_003886E8((f32 *)&vloc3, (f32 *)(o + 0x140), 7.0f);
                for (i = 0; i < n; i++) {
                    if (func_L39_005B6970(D_L39_002638C0[i]) != 0
                        || *(s16 *)(D_L39_002638C0[i] + 0xAA) == 0x1080
                        || *(s16 *)(D_L39_002638C0[i] + 0xAA) == 0x10AA
                        || *(s16 *)(D_L39_002638C0[i] + 0xAA) == 0x10AD
                        || *(s16 *)(D_L39_002638C0[i] + 0xAA) == 0x10AE) {
                        func_L01_00443938(D_L39_002638C0[i], *(u8 **)(o + 0x2524), 0x10000, o + 0xA0, &vloc3, 1.0f);
                    }
                }
            }
            if (*(s32 *)(o + 0x1310) == 1) {
                *(s32 *)(o + 0x35C) = 2;
            }
            func_L39_006325D0(o, 0.017f, 0.3f);
            func_L39_006325F0(o, 0.025f, 0.3f);
            func_L39_00632600(o, 0.03f, 0.27f);
            roll = f21 * 27.0f;
            if (1.7f < roll) {
                roll = 1.7f;
            } else if (roll < -1.7f) {
                roll = -1.7f;
            }
            *(f32 *)(o + 0x7C0) = -roll;
            *(f32 *)(o + 0x9D8) = roll * 0.5f;
            *(f32 *)(o + 0x928) = roll * 0.5f;
            break;
        }
    }
    case 0x78:
        *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x2BC);
        *(f32 *)(o + 0xFB0) = 0.09166667f;
        func_L39_0062A9B8(o, 0.0069444445f);
        func_L39_006301D8(o, o + 0x120, o + 0x160, 0.005f);
        break;
    case 6: case 0x2C: {
        f32 fa;
        x = Dec_00648C20(o + 0x19E4);
        if ((x ^ 0x2C) == 0) {
            vu0_v4 vloc;
            {
                fa = 0.0f;
                if (4.0f < *(f32 *)(o + 0x2AC)) {
                    fa = 0.43633232f;
                }
                vloc = *(vu0_v4 *)(o + 0xB0);
                func_L01_004455F0(&vloc.y, fa, (f32 *)(o + 0xC4), 0.02f, 0.3f, 0.043633234f, 0);
                func_L01_004455F0(&vloc.x, 0.0f, (f32 *)(o + 0xC0), 0.02f, 0.3f, 0.043633234f, 0);
                func_L39_00631138(o, *(f32 *)(o + 0xC0), *(f32 *)(o + 0xC4), 0.0f);
                if (1.0f < *(f32 *)(o + 0x2AC)) {
                    Set32_00648C20(o + 0x19E5, 1);
                }
            }
        }
        func_L39_00630918(o);
        if (*(s16 *)(o + 0x320) == 0) {
            func_L39_0062C710(o);
        }
        func_L39_006314B0(o);
        func_L31_004F0040_006463A8(o, 0.7f, 0.0f);
        func_L39_006301D8(o, o + 0x120, o + 0x120, *(f32 *)(o + 0x15C0));
        if (func_L39_0062FE30(o, o + 0x120) < -0.8333334f) {
            func_L39_0062FD10(o, o + 0x120, o + 0x120, -0.8333334f);
        }
        break;
    }
    case 0x76:
        x = Dec_00648C20(o + 0x19E5);
        if ((x ^ 8) != 0) {
            u8 *v;
            f32 fa;
            fa = 0.0024240685f;
            o[0x1A0C] = 1;
            func_003BEBF8((f32 *)(o + 0x15C8), *(f32 *)(o + 0x15D0), fa);
            v = o + 0x120;
            func_003BEBF8((f32 *)(o + 0x15CC), *(f32 *)(o + 0x15D4), fa);
            func_L39_00631138(o, *(f32 *)(o + 0x15C8), *(f32 *)(o + 0x15CC), 0.0f);
            func_L01_0040C1F8(v, v, func_003887A0((f32 *)v) * 0.9f);
            func_L39_006301D8(o, v, v, *(f32 *)(o + 0x15C0));
            if (func_L39_0062FE30(o, v) < -0.8333334f) {
                func_L39_0062FD10(o, v, v, -0.8333334f);
            }
        }
        break;
    case 0x16: {
        f32 f20;
        f32 d;
        f20 = func_L39_0062FD90(o, o + 0x120);
        d = 0.0011111111f;
        if (*(s16 *)(o + 0x2DE) == 0 && *(s32 *)(o + 0x2F0) >= 11) {
            d = 0.0027777778f;
        }
        f20 -= d;
        if (f20 < 0.0f) {
            f20 = 0.0f;
        }
        if (o[0x377] != 0) {
            func_L39_00635C78(o, 3.7f, 0.0f, 0.35f);
        }
        func_L39_0062FA50(o, o + 0x120, o + 0x120, f20);
        func_L39_006301D8(o, o + 0x120, o + 0x120, 0.004f);
        break;
    }
    case 0x8E:
        qzero(o + 0x120);
        break;
    case 0x64: {
        vu0_v4 vloc;
        vu0_v4 vloc2;
        f32 f20;
        s32 n;
        s32 i;
        {
            vec_sub_ab(&vloc, o + 0x13C0, o + 0xA0);
            *(f32 *)(o + 0xFD0) = func_00388A28(vloc.x, vloc.y);
            f20 = func_003887A0((f32 *)&vloc);
            if (0.2f < f20) {
                *(f32 *)(o + 0x2468) = 1.0f;
                *(f32 *)(o + 0xFD0) = func_00388A28(vloc.x, vloc.y);
                *(f32 *)(o + 0xFB0) = f20;
                *(f32 *)(o + 0xFB0) = (f20 < D_L39_0024617C[0][2] ? D_L39_0024617C[0][1] : D_L39_0024617C[1][1]) * 0.016666668f;
            } else {
                *(f32 *)(o + 0x2468) = 1.0f;
                *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x13CC);
                *(s32 *)(o + 0xFB0) = 0;
            }
            func_L39_00630AC0(o, 0, 0.03f, 0.3f, 0.1308997f);
            func_L39_006314B0(o);
            func_L39_00630DD8(o, 0.010277778f, 0.008333334f);
            func_L39_00630E28(o, 99999.0f);
            func_L39_0062EC98(o, 0);
            if (*(s16 *)(o + 0x2DE) != 0) {
                func_L39_006301D8(o, o + 0x120, o + 0x140, 0.0069444445f);
                func_L39_00630F00(o);
            } else {
                func_L39_006301D8(o, o + 0x120, o + 0x120, 0.015000001f);
            }
            vloc2 = *(vu0_v4 *)(o + 0xE0);
            n = func_003CF790(&vloc2, 0, *(f32 *)(o + 0x1F4) + 0.2f, *(void **)(o + 0x2524), 0);
            for (i = 0; i < n; i++) {
                u8 *p = D_L39_002638C0[i];
                if (p != 0 && *(s16 *)(p + 0xAA) == 0xCB) {
                    func_L01_00443938(p, *(u8 **)(o + 0x2524), 0x10000, o + 0xE0, &D_L39_00242AB0, 100.0f);
                }
            }
            break;
        }
    }
    case 0x65: {
        vu0_v4 vloc;
        u8 *v;
        {
            vec_sub_ab(&vloc, o + 0x13C0, o + 0xA0);
            if (func_00388730(&vloc, o + 0x190) < 0.0f) {
                qzero(o + 0x190);
            }
            v = o + 0x120;
            qzero(v);
            func_L39_0062A8F0(o, 0.0075000003f);
            func_L39_0062EC98(o, 0);
            if (*(s16 *)(o + 0x2DE) != 0) {
                func_L39_006301D8(o, v, o + 0x140, 0.0069444445f);
                func_L39_00630F00(o);
            } else {
                func_L39_006301D8(o, v, v, 0.015000001f);
            }
            break;
        }
    }
    case 0x66: {
        vu0_v4 vloc;
        vu0_v4 vloc2;
        s32 i;
        {
            qzero(o + 0x120);
            if (*(s32 *)(o + 0x13D4) == 0) {
                break;
            }
            if (*(s32 *)(o + 0x13D8) > 0) {
                if (*(s32 *)(o + 0x2F0) == 1) {
                    func_L39_00644F00(o, *(u8 **)(o + 0x2524) + 0x10);
                    func_L39_005F0D88(0, 0, *(s32 *)(o + 0x2524), 0x10C3);
                }
                func_003BEBF8((f32 *)(o + 0xF0), 0.0f, 0.13333334f);
                func_003BEBF8((f32 *)(o + 0xF4), 0.0f, 0.13333334f);
                func_003BEBF8((f32 *)(o + 0xF8), 2.0f, 0.13333334f);
                *(s16 *)(o + 0x2488) = 1;
                *(s32 *)(o + 0x13D8) = *(s32 *)(o + 0x13D8) - 1;
            }
            if (*(s32 *)(o + 0x13D4) == 0) {
                break;
            }
            if (*(s32 *)(o + 0x13D8) != 0) {
                break;
            }
            *(f32 *)(o + 0xF0) = -0.26666668f;
            *(f32 *)(o + 0xF4) = -0.26666668f;
            vec_sub_ba(&vloc, o + 0x13C0, *(u8 **)(o + 0x2524) + 0x10);
            vloc.z = 0.0f;
            func_00388830(&vloc2, &vloc, 0.3f);
            vec_add_ab(&vloc, &vloc, *(u8 **)(o + 0x13DC) + 0x10);
            vloc.z = vloc.z + 0.2f;
            if (func_003CF790(&vloc, 1, 0.5f, *(void **)(o + 0x13DC), 0) != 0) {
                for (i = 0; i < 8; i++) {
                    vec_add_ab(&vloc, &vloc, &vloc2);
                    if (func_003CF790(&vloc, 1, 0.5f, *(void **)(o + 0x13DC), 0) == 0) {
                        break;
                    }
                }
            }
            *(s32 *)(o + 0x13D4) = 0;
            func_L39_00635680(o, &vloc, *(u8 **)(o + 0x13DC) + 0xF0, 0, 1, 1, 0);
            func_L39_00644F00(o, &vloc);
            func_L39_005F0D88(1, 0, *(s32 *)(o + 0x2524), 0x10C3);
            Set16_00648C20(o + 0x311, 0x5A);
            break;
        }
    }
    case 0x2B:
        func_L39_0064AC00(o);
        break;
    case 0x14:
        func_L39_0064B448(o);
        break;
    case 0x15: case 0x85: {
        s32 hit;
        u32 z;
        s32 flag;
        f32 f20;
        f32 f1;
        *(s32 *)(o + 0xFB0) = 0;
        if (*(s32 *)(o + 0x61C) != 0
            || *(f32 *)(o + 0x628) < (f32)D_L39_0047A968[*(s16 *)(o + 0x107C)].i18) {
            o[0x469] = 2;
        }
        hit = 0;
        if ((DecEq_00648C20(o + 0x19E7, 1) && DecGt_00648C20(o + 0x19E9, 0x14)) || o[0x24FE] != 0) {
            hit = 1;
        }
        if (hit == 0) {
            if (*(s32 *)(o + 0x1068) != 0 || *(s32 *)(o + 0x1064) != 0) {
                flag = 0;
                if (o[0x1A06] != 0) {
                    f20 = func_L39_00631430(o, o + 0x1040, 0);
                    f1 = func_L39_00631430(o, o + 0x1040, 1);
                } else {
                    f20 = func_003893C8(*(f32 *)(o + 0x106C), *(f32 *)(o + 0xB8));
                    f1 = func_L01_004454A8(1, *(f32 *)(o + 0x106C), *(f32 *)(o + 0xB8));
                }
                if (f1 < 4.363323f) {
                    flag = 1;
                }
                if (0.0f < f20) {
                    *(f32 *)(o + 0x610) = 1.0f / (f1 + 1.0f);
                }
                *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x106C);
                *(vu0_v4 *)(o + 0xFC0) = *(vu0_v4 *)(o + 0x1040);
                if (flag != 0) {
                    func_L39_00630AC0(o, 1, 0.057f, 0.2f, 0.28216156f);
                } else {
                    func_L39_00630AC0(o, 0, 0.057f, 0.2f, 0.28216156f);
                }
            } else {
                s32 g = 1;
                z = Dec_00648C20(o + 0x19E4);
                if ((z ^ 0x85) == 0 && *(s32 *)(o + 0x2F0) >= 12) {
                    g = 0;
                } else if (*(s32 *)(o + 0x61C) == 0 && 6.0f < *(f32 *)(o + 0x628)) {
                    g = 0;
                }
                if (g != 0) {
                    z = Dec_00648C20(o + 0x19E4);
                    if ((z ^ 0x15) == 0) {
                        func_L39_0062D4A8(o, 14.0f, 0.5235988f, 0.7853982f);
                    }
                }
            }
        }
        if ((*(s32 *)(o + 0x61C) == 0 || o[0x24FE] != 0) && (*(u8 **)(o + 0x2524))[0x43] == 0x1A) {
            f32 fz = 33.0f;
            if (o[0x24FE] != 0) {
                fz = 32.0f;
            }
            if (func_L39_00630400(o, fz) != 0) {
                z = Dec_00648C20(o + 0x19E4);
                if ((z ^ 0x15) == 0) {
                    func_L39_006391F8(o);
                }
            }
        }
        func_L39_00630DD8(o, 0.010277778f, 0.007777778f);
        func_L39_00630E28(o, 99999.0f);
        if (*(s16 *)(o + 0x2DE) != 0) {
            func_L39_006301D8(o, o + 0x120, o + 0x160, 0.0069444445f);
        } else {
            func_L39_006301D8(o, o + 0x120, o + 0x120, 0.015000001f);
        }
        break;
    }
    case 0x17: case 0x18:
        vec_sub_ba(o + 0xFC0, o + 0x1550, o + 0x1540);
        *(f32 *)(o + 0xFD0) = func_00388A28(*(f32 *)(o + 0xFC0), *(f32 *)(o + 0xFC4));
        func_L39_00630AC0(o, 0, 0.04f, 0.2f, 0.104719765f);
        if (o[0x1A06] != 2) {
            func_L01_00445558(o + 0xB4, 0, 0.0f, 0.07853982f);
        }
        vec_sub_ab(o + 0x120, o + 0x1540, o + 0xA0);
        func_003BF640((f32 *)(o + 0x120), 0.06666667f);
        func_003BEBF8((f32 *)(o + 0x1570), *(f32 *)(o + 0xA8), 0.050000004f);
        break;
    case 0x19: case 0x1A: {
        vu0_v4 side;
        vu0_v4 pos;
        vu0_v4 dir;
        Out_00648C20 hit;
        {
            vec_sub_ba(o + 0xFC0, o + 0x1550, o + 0x1540);
            *(f32 *)(o + 0xFD0) = func_00388A28(*(f32 *)(o + 0xFC0), *(f32 *)(o + 0xFC4));
            func_L39_00630AC0(o, 0, 0.02f, 0.2f, 0.07853982f);
            vec_sub_ab(&dir, o + 0x1550, o + 0x1540);
            qzero(o + 0x120);
            x = Dec_00648C20(o + 0x19E4);
            if ((x ^ 0x19) == 0) {
                func_00388758(&side, o + 0x250, &dir);
            } else {
                func_00388758(&side, &dir, o + 0x250);
            }
            func_00388830(&side, &side, 0.2f);
            vec_add_ba(&pos, o + 0xA0, &side);
            if (func_L39_00620BD8(o, (vu0_v4 *)(o + 0xA0), o + 0xB0, 0) == 0) {
                break;
            }
            if (func_L39_00620BD8(o, &pos, o + 0xB0, &hit) == 0) {
                break;
            }
            vec_sub_ba(o + 0x120, &hit.v0, o + 0xA0);
            func_00388830(o + 0x120, o + 0x120, D_L39_002462D0[(s32)*(f32 *)(o + 0x628)] * 0.5f);
            break;
        }
    }
    case 0x79: {
        f32 f20 = 0.0f;
        func_003BEBF8((f32 *)(o + 0xFB4), f20, 0.006666667f);
        *(f32 *)(o + 0x120) = func_00388960(*(f32 *)(o + 0x1070)) * *(f32 *)(o + 0xFB4);
        *(f32 *)(o + 0x124) = func_00388978(*(f32 *)(o + 0x1070)) * *(f32 *)(o + 0xFB4);
        if (0.0f < *(f32 *)(o + 0x2AC)) {
            *(f32 *)(o + 0x128) = *(f32 *)(o + 0x158) - 0.0069444445f;
        } else {
            *(f32 *)(o + 0x128) = f20;
        }
        *(f32 *)(o + 0xFD0) = func_00389380(*(f32 *)(o + 0x1070), 3.1415927f);
        func_L39_00630AC0(o, 0, 0.05f, 0.2f, 0.28216156f);
        break;
    }
    case 0x7A:
        qzero(o + 0x120);
        *(f32 *)(o + 0x128) = -0.016666668f;
        break;
    case 0x37:
        if ((*(u8 **)(o + 0x2524))[0x43] == 0x33) {
            func_L39_00630AC0(o, 0, 0.137f, 0.25f, 0.20362175f);
        } else {
            func_L39_00630AC0(o, 0, 1.0f, 0.1f, 0.4072435f);
        }
        break;
    case 0x62: case 0x63:
        qzero(o + 0x120);
        break;
    }
    x = Dec_00648C20(o + 0x19E5);
    if (a != x) {
        *(s32 *)(o + 0x2F8) = 0;
    }
    if (qb != q[0x43]) {
        *(s32 *)(o + 0x2FC) = 0;
    }
}
/* localdecomp:end func_L39_006463A8 */

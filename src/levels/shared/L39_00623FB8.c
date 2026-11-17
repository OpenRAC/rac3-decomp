#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 b0;
    u8 b1;
    u8 b2;
} S_00627EF8;

/* declared by functions of L39_00622990.c, which this file was cut from */
extern u8 D_L39_004997E0[];
extern void func_L39_00623FB8(void *);
extern void func_L39_006244E0(u8 *);

/* localdecomp:start func_L39_00623FB8 */
extern u8 D_L39_004997E0[];
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_L01_004482A0_00623FB8(f32, f32, f32, f32, void *, void *);
extern f32 func_0038CF38(void *, void *);

typedef union Buf_00623FB8 {
    u8 b[8];
    u32 w[2];
} Buf_00623FB8;

void func_L39_00623FB8(void *arg0) {
    u8 *g = arg0;
    Buf_00623FB8 buf;
    f32 *p = *(f32 **)(g + 0x2520);

    *(f32 *)(g + 0x1E8) = p[5];
    *(f32 *)(g + 0x1EC) = p[6];
    *(f32 *)(g + 0x1F0) = p[4];
    if ((({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 4) == 0) {
        if (*(s16 *)(g + 0x14BC) < *(s32 *)(g + 0x2F0) && g[0x14AE] == 0) {
            *(f32 *)(g + 0x1EC) = *(f32 *)(g + 0x14C8);
        }
    } else if ((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 6) == 0) {
        *(f32 *)(g + 0x1EC) = (*(f32 **)(g + 0x2520))[7];
    } else if ((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 4) == 0 || g[0x24FD] != 0) {
        *(f32 *)(g + 0x1E8) = 0.8f - (*(f32 **)(g + 0x2520))[4];
    } else if ((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x7E) == 0) {
        *(f32 *)(g + 0x1F0) = 0.8f;
    }
    if (g[0x216] == 0 || (({
        u8 *q = g + 0x19E8;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x12) == 0 || (({
        u8 *q = g + 0x19EB;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x12) == 0 ||
        *(f32 *)(g + 0x1E4) < (*(f32 **)(g + 0x2520))[6] - 0.17f || (({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x11) == 0 ||
        g[0x374] != 0 || func_0038CF38(g + 0x1D0, g + 0xA0) > *(f32 *)(g + 0x1F4) * 0.5f) {
        func_003C4138((f32 *)(g + 0x1E0), *(f32 *)(g + 0x1E8), 0.024f);
        func_003C4138((f32 *)(g + 0x1E4), *(f32 *)(g + 0x1EC), 0.024f);
        func_L01_004482A0_00623FB8(*(f32 *)(g + 0x1F0), 0.028800001f, 0.43200004f, 0.080000006f, g + 0x1F4, g + 0x1F8);
    }
}
/* localdecomp:end func_L39_00623FB8 */

/* localdecomp:start func_L39_006244E0 */
/* decode step as Dec16_00629098 in this file (same loop and (b >> 16) / ... step), inlined by hand, returning byte 4 */
typedef union Buf_006244E0 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_006244E0;

typedef struct { u8 pad0[0x18]; void *f18; u8 pad1C[0x24]; u8 v40[8]; f32 f48; } S_006244E0;

extern u8 D_L39_004997E0[];
extern s32 D_L39_0024112C;
extern S_006244E0 D_L39_0025F740;
extern void func_L39_0062A4C0(u8 *);
extern s32 func_L39_00634E58(u8 *, void *, f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_L39_005B8928(void *);

void func_L39_006244E0(u8 *g) {
    u8 *q = g + 0x1A18;
    u8 r;

    if (*q == 0) {
        r = 0;
    } else {
        Buf_006244E0 buf;
        u32 a;
        u32 b;
        s32 n;
        s32 k;
        s32 m;
        s32 i;
        u8 *d;

        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 24; i += 3) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
        r = buf.b[4];
    }
    if (r == 0) {
        func_L39_0062A4C0(g);
        if ((D_L39_0024112C + g[0x24C9]) % 3 == 0) {
            g[0x214] = 0;
            g[0x215] = 0;
            *(f32 *)(g + 0x208) = 4.0f;
            if (func_L39_00634E58(g, g + 0x208, 0.7f, 4.0f) != 0) {
                *(f32 *)(g + 0x210) = func_0038D160(D_L39_0025F740.f48, func_0038CED8(D_L39_0025F740.v40));
                if (D_L39_0025F740.f18 != 0) {
                    g[0x215] = 1;
                    if (func_L39_005B8928(D_L39_0025F740.f18) != 0) {
                        g[0x214] = 1;
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006244E0 */

INCLUDE_ASM("asm/levels", func_L39_00624658);

/* localdecomp:start func_L39_00626910 */
extern void func_L39_006323B8(void *, void *, void *, f32);
extern void func_L39_00632328(void *, void *, void *, f32);
extern void func_L39_00632298(void *, void *, void *, f32);
extern void func_L39_00632558(void *, void *, void *, f32);

void func_L39_00626910(void *arg0, void *arg1, s32 arg2, f32 arg3, f32 arg4)
{
    if (arg2 != 0) {
        func_L39_006323B8(arg0, arg1, arg1, arg3);
        func_L39_00632328(arg0, arg1, arg1, arg4);
    } else {
        func_L39_00632298(arg0, arg1, arg1, arg3);
        func_L39_00632558(arg0, arg1, arg1, arg4);
    }
}
/* localdecomp:end func_L39_00626910 */

/* localdecomp:start func_L39_00626998 */
typedef struct Vt_00626998 {
    u8 pad0[0x1C];
    s32 (*f1C)(void *, s32);
} Vt_00626998;

typedef struct Ob_00626998 {
    s32 f0;
    u8 pad4[0x10];
    Vt_00626998 *f14;
    u8 pad18[0x18];
    struct Ob_00626998 *f30;
} Ob_00626998;

typedef struct Pn_00626998 {
    u8 pad0[0x68];
    Ob_00626998 *f68;
    u8 pad6C[0x3E];
    s16 hAA;
    u8 padAC[0xC];
    struct Pn_00626998 *fB8;
} Pn_00626998;

extern Ob_00626998 *func_L39_0061CF40(Pn_00626998 *);
extern Ob_00626998 *func_L39_0061D7B0(Pn_00626998 *);

s32 func_L39_00626998(u8 *g, Pn_00626998 *p, s32 flag) {
    s32 found;
    Ob_00626998 *obj;
    Ob_00626998 *a;
    Ob_00626998 *o2;

    found = 0;
    if (p != 0) {
        obj = func_L39_0061CF40(p);
    } else {
        obj = 0;
    }
    if (obj != 0) {
        if (obj->f14->f1C(obj, *(s32 *)(g + 0x2548)) != 0) {
            if (flag != 0) {
                *(s32 *)(g + 0x24CC) = obj->f0;
            }
            return 0;
        }
        switch (p->hAA) {
        case 0x1095:
            *(s32 *)(g + 0x24D0) = 1;
            break;
        case 0x1087:
            *(s32 *)(g + 0x24D0) = 2;
            break;
        case 0x1096:
        case 0x1097:
            *(s32 *)(g + 0x24D0) = 3;
            break;
        case 0x108C:
            *(s32 *)(g + 0x24D0) = 4;
            break;
        case 0x18AB:
            *(s32 *)(g + 0x24D0) = 10;
            break;
        case 0x1099:
            *(s32 *)(g + 0x24D0) = 6;
            break;
        case 0x10A4:
            *(s32 *)(g + 0x24D0) = 7;
            break;
        case 0x108F:
            *(s32 *)(g + 0x24D0) = 5;
            break;
        default:
            *(s32 *)(g + 0x24D0) = -1;
            break;
        }
        *(s32 *)(g + 0x24CC) = obj->f0;
    } else {
        while (p != 0 && p->fB8 != 0 && p->fB8 != p) {
            switch (p->hAA) {
            case 0x1094:
                *(s32 *)(g + 0x24D0) = 1;
                break;
            case 0x1087:
                *(s32 *)(g + 0x24D0) = 2;
                break;
            case 0x1096:
                *(s32 *)(g + 0x24D0) = 3;
                break;
            case 0x108A:
                *(s32 *)(g + 0x24D0) = 5;
                break;
            case 0x1089:
                *(s32 *)(g + 0x24D0) = 4;
                break;
            case 0x18AB:
                *(s32 *)(g + 0x24D0) = 10;
                break;
            case 0x1098:
                *(s32 *)(g + 0x24D0) = 6;
                break;
            case 0x10A4:
                *(s32 *)(g + 0x24D0) = 7;
                break;
            case 0x108F:
                *(s32 *)(g + 0x24D0) = 5;
                o2 = p->f68;
                if (o2 != 0) {
                    a = o2->f30;
                    if (a != 0) {
                        found = 1;
                        if (a->f14->f1C(a, *(s32 *)(g + 0x2548)) != 0) {
                            *(s32 *)(g + 0x24D0) = -1;
                            return 0;
                        }
                        *(s32 *)(g + 0x24CC) = o2->f30->f0;
                    }
                }
                break;
            case 0x16DB:
            case 0x1700:
            case 0x1900:
            case 0x1902:
            case 0x1904:
            case 0x1ADC:
            case 0x1B00:
            case 0x1CF0 ... 0x1CFE:
            case 0x1D00:
            case 0x1D02:
            case 0x1D04:
            case 0x1E59:
            case 0x1E5B:
            case 0x1E5D:
            case 0x1E5F:
            case 0x1E77:
            case 0x1E78:
            case 0x1E7A:
            case 0x1E7C:
                break;
            }
            if (found != 0) {
                return 1;
            }
            p = p->fB8;
        }
        if (found != 0) {
            return 1;
        }
        obj = func_L39_0061D7B0(p);
        if (obj != 0) {
            if (obj->f14->f1C(obj, *(s32 *)(g + 0x2548)) != 0) {
                if (flag != 0) {
                    *(s32 *)(g + 0x24CC) = obj->f0;
                }
                return 0;
            }
            *(s32 *)(g + 0x24CC) = obj->f0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00626998 */

/* localdecomp:start func_L39_00626D18 */
void func_L39_00626D18(u8 *p) {
    *(s32 *)(p + 9424) = -1;
    *(u32 *)(p + 9420) = 0xFFFFFFFFU;
    *(s32 *)(p + 9308) = 0;
}
/* localdecomp:end func_L39_00626D18 */

#include "common.h"

/* NTSC-U counterpart of func_L40_003EC320 (src/levels/shared/L40_003EBB98.c) */
/* localdecomp:start func_L40_003EBEC8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_L40_003EBEC8;

typedef struct {
    u8 pad[0x88];
    s32 arr[1];
} T_L40_003EBEC8;

typedef struct {
    u8 pad00[0x30];
    f32 f30;
    u8 pad34[0x114];
    s32 w148;
    u8 pad14C[0x14];
    u8 b160[0xC0];
    V4_L40_003EBEC8 v220;
    u8 *p230;
    s16 s234;
    u8 pad236[0x1A];
    s32 w250;
    u8 pad254[2];
    u8 b256[2];
    s32 w258;
    u8 pad25C[4];
    V4_L40_003EBEC8 v260;
    V4_L40_003EBEC8 v270;
    V4_L40_003EBEC8 v280;
    u8 pad290[0x14];
    s32 w2A4;
    u8 pad2A8[4];
    s32 w2AC;
    u8 pad2B0[8];
    s32 w2B8;
    f32 f2BC;
    V4_L40_003EBEC8 v2C0;
    f32 f2D0;
    f32 f2D4;
    f32 f2D8;
    s32 w2DC;
} Vars_L40_003EBEC8;

extern T_L40_003EBEC8 *D_L40_003575EC[];
extern u8 D_L40_00242AB0;
__asm__(".extern D_L40_00242AB0, 16");
extern f32 D_001DB620_sda;
__asm__(".extern D_001DB620_sda, 4");
extern s32 D_001DB624_sda;
__asm__(".extern D_001DB624_sda, 4");

extern s32 func_L40_003ECB00(s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_003883C8(void *);
extern s32 func_L39_005B24C8(s32, s32);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L40_0053C768(void *);
extern void func_L40_003ECDC8(void *);
extern u8 *func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L40_0053CE30(void *);
extern void func_L39_00669B68(s32);
extern void func_L39_00619AE0(void *);
extern void func_L39_005F08F8(void *, s32);
extern s32 func_L39_005F0D88(s32, s32, void *, s32);
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L40_003ECEC0(void *);
extern void func_L40_003ED380(void *);
extern f32 func_00388800(void *, void *);
extern s32 func_L01_00457440(void *, void *);
extern f32 func_L01_0040C040(void *, void *);
extern void func_L40_003ECE68(void *);

void func_L40_003EBEC8(u8 *obj) {
    Vars_L40_003EBEC8 *v;
    s32 *net;
    s32 uid;
    s32 hit;
    u8 *q;
    s32 st;
    s32 t;
    u8 *r;
    f32 f;
    V4_L40_003EBEC8 tmp;
    V4_L40_003EBEC8 tmp2;

    if (obj == 0) {
        return;
    }
    v = *(Vars_L40_003EBEC8 **)(obj + 0x68);
    net = *(s32 **)(obj + 0x90);
    uid = *net;
    if (v->w2B8 != -1) {
        v->w2AC = D_L40_003575EC[0]->arr[v->w2B8];
        net[6] = v->w2AC;
    }
    t = v->w2AC;
    if ((u32)t >= 2) {
        t = 0;
    }
    obj[0x7E] = ((obj[0x7E] | 0x80) & 0x8F) | (t << 4);
    if (func_L40_003ECB00(uid, obj) != 0) {
        goto range;
    }
    if ((u8)(obj[0x20] + 3) < 2) {
        goto range;
    }
    switch (obj[0x95]) {
    case 4:
        *(f32 *)(obj + 0x2C) = *(f32 *)(obj + 0x2C) + v->f2D4;
        if (v->f2D8 <= *(f32 *)(obj + 0x2C)) {
            func_L01_00441FB8(obj, 1, 0);
            *(V4_L40_003EBEC8 *)&v->v2C0 = *(V4_L40_003EBEC8 *)(obj + 0x10);
        }
        *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + 0.025000002f;
        break;
    case 0:
        if (v->s234 == 1) {
            if (obj[0x43] != 1) {
                func_003BE4F0(obj, 1, 0, 10);
            }
            func_L01_00441FB8(obj, 3, 2);
            goto sw2;
        }
        if (v->w258 != 0 && func_003883C8(v->b256) != 0) {
            func_L01_00441FB8(obj, 2, 1);
            v->w258 = 0;
            if (v->w250 < 0x12C) {
                v->w250 = func_L39_005B24C8(0x1E0, 0x258);
            }
        }
        break;
    case 1:
        if (v->s234 == 1) {
            func_L01_00441FB8(obj, 3, 2);
            goto sw2;
        }
        if (v->w250 == 0) {
            func_L01_00441FB8(obj, 1, 0);
        }
        goto sw2;
    case 2:
        break;
    case 3:
        hit = func_L01_00451078(obj, v->b160);
        if (v->f30 <= 0.0f && func_L40_0053C768(obj) != 0) {
            func_L40_003ECDC8(obj);
            if (func_L40_0053C768(obj) != 0) {
                r = func_L01_0032FE90(obj + 0x10, 0, 10, 4, 5, 5, 10, 0, 0.8f, 3.0f, 2.0f, 2.0f,
                                      0, 1, 0, 0, 1, 0, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            } else {
                r = func_L01_0032FE90(obj + 0x10, 0, 10, 4, 5, 5, 10, 0, 0.8f, 3.0f, 2.0f, 2.0f,
                                      0, 1, 0, 0, 1, 0, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
            if (r != 0) {
                *(s32 *)(r + 0xB8) = (s32)obj;
            }
            func_L40_0053CE30(obj);
            func_L01_00441FB8(obj, 0x25, -1);
            *(s32 *)(obj + 0x98) = 0;
            *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F08F8(obj, 1);
            return;
        }
        if ((hit & 2) != 0) {
            if (v->s234 == 1) {
                func_L01_00441FB8(obj, 3, 2);
                goto sw2;
            }
            func_L01_00441FB8(obj, 2, 1);
            v->w250 = func_L39_005B24C8(0x244, 0x258);
        }
        break;
    }
sw2:
    st = obj[0x20];
    switch (st) {
    case 1:
        if (func_L01_00452EC8(obj) != 0) {
            f = func_003BE7F0(obj + 0x10, 0, 0, 0.5f);
            v->f2D0 = *(f32 *)(obj + 0x18) - f - 0.5f;
        }
        v->f2BC = func_00389380(v->f2BC, 0.008726646f);
        *(f32 *)(obj + 0x18) = v->v2C0.z + v->f2D0 * func_00388978(v->f2BC);
        goto post;
    case 2:
        goto post;
    case 3:
        if (func_L01_00452EC8(obj) != 0) {
            func_L01_00458A70(obj, 0.0125f, 0.3166667f, 0.0069813174f, 0.20943953f);
            v->v270 = v->v220;
            v->v260 = v->v220;
            v->v280 = v->v220;
            func_L40_003ECEC0(obj);
        }
        func_L40_003ED380(obj);
        q = (u8 *)&v->v220;
        tmp = *(V4_L40_003EBEC8 *)q;
        if (func_00388800(&v->v280, &tmp) > 1.0f) {
            v->v260 = v->v220;
            v->v280 = v->v220;
            func_L40_003ECEC0(obj);
            v->w2A4 = 0;
        }
        v->v270 = v->v220;
        if (v->w2A4 >= 6) {
            v->v260 = v->v220;
            v->v280 = v->v220;
            func_L40_003ECEC0(obj);
            v->w2A4 = 0;
        }
        func_L01_00457440(obj, &v->v260);
        v->w2DC = v->w2DC + 1;
        if (func_L40_0053C768(obj) != 0) {
            f = func_00388800(obj + 0x10, q);
            if (f <= 1.4f || v->v2C0.z + 6.0f <= *(f32 *)(obj + 0x18) || v->w2DC > D_001DB624_sda || v->w148 == 0) {
                r = func_L01_0032FE90(obj + 0x10, 0, 10, 4, 5, 5, 10, 0, 0.8f, 3.0f, 2.0f, 2.0f,
                                      0, 1, 0, 0, 1, 0, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                if (r != 0) {
                    *(s32 *)(r + 0xB8) = (s32)obj;
                }
                func_L39_005F0D88(4, 0, obj, 0x109A);
                func_L01_0044ED60(obj, 0x3F, &D_L40_00242AB0, 3.0f, 7.0f, 4.0f, 7.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                func_L40_0053CE30(obj);
                func_L01_00441FB8(obj, 0x25, -1);
                *(s32 *)(obj + 0x98) = 0;
                *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
                func_L39_005F08F8(obj, 1);
                return;
            } else {
                tmp2 = *(V4_L40_003EBEC8 *)(obj + 0x10);
                tmp2.z = tmp2.z + 0.5f;
                if (v->p230 == 0) {
                    goto post;
                }
                if (*(s16 *)(v->p230 + 0xAA) != 0x107C && *(s16 *)(v->p230 + 0xAA) != 0x107E) {
                    goto post;
                }
                if (!(func_L01_0040C040(obj + 0x10, v->p230 + 0x10) < D_001DB620_sda)) {
                    goto post;
                }
                r = func_L01_0032FE90(obj + 0x10, 0, 10, 4, 5, 5, 10, 0, 0.8f, 3.0f, 2.0f, 2.0f,
                                      0, 1, 0, 0, 1, 0, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                if (r != 0) {
                    *(s32 *)(r + 0xB8) = (s32)obj;
                }
                func_L39_005F0D88(4, 0, obj, 0x109A);
                func_L01_0044ED60(obj, 0x3F, &D_L40_00242AB0, 3.0f, 7.0f, 4.0f, 7.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                func_L39_00619AE0(obj);
                func_L40_0053CE30(obj);
                func_L01_00441FB8(obj, 0x25, -1);
                *(s32 *)(obj + 0x98) = 0;
                *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
                func_L39_005F08F8(obj, 1);
                return;
            }
        } else {
            f = func_00388800(obj + 0x10, q);
            if (f <= 1.1f || v->v2C0.z + 6.0f <= *(f32 *)(obj + 0x18) || (f32)D_001DB624_sda * 1.5f < (f32)v->w2DC) {
                r = func_L01_0032FE90(obj + 0x10, 0, 10, 4, 5, 5, 10, 0, 0.8f, 3.0f, 2.0f, 2.0f,
                                      0, 1, 0, 0, 1, 0, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                if (r != 0) {
                    *(s32 *)(r + 0xB8) = (s32)obj;
                }
                func_L39_005F0D88(4, 0, obj, 0x109A);
                func_L01_0044ED60(obj, 0x3F, &D_L40_00242AB0, 3.0f, 7.0f, 4.0f, 7.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                func_L40_0053CE30(obj);
                func_L39_00669B68(uid);
                func_L01_00441FB8(obj, 0x25, -1);
                *(s32 *)(obj + 0x98) = 0;
                *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
                func_L39_005F08F8(obj, 1);
                return;
            }
        }
        goto post;
    }
post:
    func_L40_003ECE68(obj);
range:
    if (*(f32 *)(obj + 0x10) < 2.0f || 1021.0f < *(f32 *)(obj + 0x10) || *(f32 *)(obj + 0x14) < 2.0f || 1021.0f < *(f32 *)(obj + 0x14) ||
        *(f32 *)(obj + 0x18) < 2.0f || 1021.0f < *(f32 *)(obj + 0x18)) {
        func_L40_0053CE30(obj);
        func_L39_00669B68(uid);
        func_L01_00441FB8(obj, 0x25, -1);
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F08F8(obj, 1);
    }
    return;
}
/* localdecomp:end func_L40_003EBEC8 */

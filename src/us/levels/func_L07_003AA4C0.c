#include "common.h"

/* localdecomp:start func_L07_003AA4C0 */
typedef struct {
    u8 p0[0x20];
    u8 b20;
    u8 p21[0x22];
    u8 b43;
    u8 p44[0x1C];
    u8 b60;
    u8 p61[7];
    u8 *f68;
} O_AA4C0;
extern void func_L07_003AAA78(O_AA4C0 *);
extern void func_L07_003AACA8(O_AA4C0 *);
extern void func_L01_004576E8(O_AA4C0 *);
extern s32 func_003883C8(u8 *);
extern void func_L07_003AB238(O_AA4C0 *, s32);
extern void func_L01_00457440(O_AA4C0 *, u8 *);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L01_00451078(O_AA4C0 *, u8 *);
extern s32 func_L07_003308C8(u8 *, O_AA4C0 *);
extern void func_L07_003AB500(O_AA4C0 *, f32);
extern f32 func_00388800(void *, void *);
extern void func_L03_0032D348_003AA4C0(O_AA4C0 *);
extern s32 func_L07_00333CC8(O_AA4C0 *);
extern s32 func_L07_00333F98(O_AA4C0 *);
extern f32 func_L01_00436500(O_AA4C0 *);
extern void func_L07_003AB830(O_AA4C0 *);
extern void func_L07_003AB6E8(O_AA4C0 *);
extern void func_L07_003AB928(void);
extern void func_L01_00402498(void (*)(void), O_AA4C0 *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

static __inline__ s32 odd16_AA4C0(u16 x) {
    return x & 1;
}

void func_L07_003AA4C0(O_AA4C0 *o) {
    u8 *s;
    u16 *q;
    u8 *s2;
    u8 *s3;
    f32 f;

    if (o->b20 == 0) func_L07_003AAA78(o);
    func_L07_003AACA8(o);
    s = o->f68;
    switch (o->b20) {
    case 1:
        break;
    case 2:
        func_L01_004576E8(o);
        if (func_003883C8(s + 0x24E)) func_L07_003AB238(o, 3);
        break;
    case 3:
        func_L01_004576E8(o);
        func_L07_003AB238(o, 4);
        break;
    case 4:
        func_L01_00457440(o, *(u8 **)(s + 0x240) + 0x10);
        if (func_L01_0040C040(*(u8 **)(s + 0x240) + 0x10, (u8 *)o + 0x10) < 484.0f) {
            s[0x25E] = 1;
            func_L07_003AB238(o, 6);
        }
        break;
    case 5:
        func_L01_004576E8(o);
        if (func_L01_00451078(o, s + 0x70) & 2) {
            if (s[0x25E] != 0) {
                func_L07_003AB238(o, 6);
            } else {
                func_L07_003AB238(o, 4);
            }
        }
        break;
    case 6:
        func_L01_004576E8(o);
        if (func_L07_003308C8(*(u8 **)(s + 0x240), o) != 0) {
            if (func_L01_0040C040((u8 *)o + 0x10, s + 0x130) < 121.0f) {
                func_L07_003AB238(o, 8);
            } else {
                func_L07_003AB238(o, 7);
            }
        } else {
            func_L07_003AB238(o, 0xD);
        }
        break;
    case 7:
        func_L07_003AB500(o, 5.0f);
        if (func_L07_003308C8(*(u8 **)(s + 0x240), o) != 0) {
            if (func_L01_0040C040((u8 *)o + 0x10, s + 0x130) < 64.0f) {
                func_L07_003AB238(o, 8);
            }
        } else {
            func_L07_003AB238(o, 6);
        }
        break;
    case 8:
        func_L07_003AB500(o, 1.5f);
        if (func_L07_003308C8(*(u8 **)(s + 0x240), o) != 0) {
            s2 = (u8 *)o + 0x10;
            s3 = s + 0x130;
            if (121.0f < func_L01_0040C040(s2, s3)) {
                *(s32 *)(s + 0x188) &= ~0x10;
                func_L07_003AB238(o, 7);
            } else if (func_003883C8(s + 0x564)) {
                if (func_L01_0040C040(s2, s3) < 6.25f) {
                    *(s16 *)(s + 0x24C) = func_L07_00333CC8(o);
                    if (func_L07_00333F98(o)) func_L07_003AB238(o, 10);
                }
            }
        } else {
            *(s32 *)(s + 0x188) &= ~0x10;
            func_L03_0032D348_003AA4C0(o);
            func_L07_003AB238(o, 6);
        }
        break;
    case 9:
        func_L07_003AB500(o, 1.5f);
        if (func_L07_003308C8(*(u8 **)(s + 0x240), o) != 0) {
            f = func_00388800((u8 *)o + 0x10, s + 0x130);
            if (11.0f < f) {
                *(s32 *)(s + 0x188) &= ~0x10;
                func_L03_0032D348_003AA4C0(o);
                func_L07_003AB238(o, 7);
            } else if (f < 2.5f) {
                func_L07_003AB238(o, 10);
            }
        } else {
            *(s32 *)(s + 0x188) &= ~0x10;
            func_L03_0032D348_003AA4C0(o);
            func_L07_003AB238(o, 6);
        }
        break;
    case 10: {
        f32 d = func_L01_00436500(o);
        func_L01_004576E8(o);
        if (10.0f < d) {
            q = (u16 *)(s + 0x564);
            *q = *q + 1;
            if (!odd16_AA4C0(*q)) func_L07_003AB830(o);
            func_L01_00402498(func_L07_003AB928, o);
        }
        if (13.0f < d && d < 16.0f) func_L07_003AB6E8(o);
        if (o->b60 & 2) {
            func_L03_0032D348_003AA4C0(o);
            if (s[0x566] != 0) {
                func_L07_003AB238(o, 0xC);
            } else {
                *(s16 *)(s + 0x564) = 0x3C;
                func_L07_003AB238(o, 6);
            }
        }
        break;
    }
    case 11: {
        q = (u16 *)(s + 0x564);
        *q = *q + 1;
        if (!odd16_AA4C0(*q)) func_L07_003AB830(o);
        func_L01_00402498(func_L07_003AB928, o);
        func_L01_004576E8(o);
        func_L07_003AB6E8(o);
        if (o->b60 & 2) {
            func_L03_0032D348_003AA4C0(o);
            if (s[0x566] != 0) {
                if (o->b43 != 8) func_003BE4F0(o, 8, 0, 0xC);
                func_L07_003AB238(o, 0xC);
            } else {
                *(s16 *)(s + 0x564) = 0x3C;
                if (o->b43 != 3) func_003BE4F0(o, 3, 0, 0xC);
                func_L01_00441FB8(o, 6, -1);
            }
        }
        break;
    }
    case 12:
        func_L07_003AB500(o, 4.0f);
        if (o->b60 & 2) {
            *(s32 *)(s + 0x188) &= ~0x10;
            func_L07_003AB238(o, 6);
        }
        break;
    case 13:
        func_L07_003AB500(o, 8.0f);
        if (func_L07_003308C8(*(u8 **)(s + 0x240), o) != 0) func_L07_003AB238(o, 6);
        break;
    }
}
/* localdecomp:end func_L07_003AA4C0 */

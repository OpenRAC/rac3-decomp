#include "common.h"

/* localdecomp:start func_L39_00629DE0 */
/* from this file's func_L39_0055AD78 loop (L39_005598D8.c) */
typedef struct {
    u8 pad0[0xB8];
    f32 fB8;
    u8 padBC[0x3E4 - 0xBC];
    s16 h3E4;
    u8 pad3E6;
    u8 b3E7;
    u8 pad3E8[0x1310 - 0x3E8];
    s32 w1310;
    u8 pad1314[0x19E4 - 0x1314];
    u8 b19E4;
    u8 pad19E5[0x1A06 - 0x19E5];
    u8 b1A06;
} Obj_00629DE0;
extern u8 D_L39_004997E0[];
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(void *);
extern void func_L39_00632D78(void *, s32, f32);
extern f32 func_L39_00633C78(void *, void *, s32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);

s32 func_L39_00629DE0(Obj_00629DE0 *o) {
    s32 ret = 2;
    f32 ang;
    if (o->h3E4 != 0 || (o->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, *(s32 *)((u8 *)o + 0x2534)) != 0 && func_L39_006212E8(o) != 10)) {
        u8 *p = &o->b19E4;
        s32 x = 0;
        long t = *p;
        if (t != 0) {
            u32 buf[2];
            u8 *b;
            s32 i;
            s32 m;
            s32 k;
            s32 n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x = buf[1];
        }
        if ((x ^ 0x10) != 0) {
            u8 c = o->b3E7;
            if (c == 0) {
                ret = 0;
            } else if (c == 3) {
                ret = 3;
            } else {
                ret = (c == 2) ? 2 : 1;
            }
            return ret;
        }
    }
    func_L39_00632D78(o, 0, 1.0f);
    if (o->b1A06 != 0) {
        ang = func_L39_00633C78(o, (u8 *)o + 0xFC0, 0);
    } else {
        ang = func_0038DB00(*(f32 *)((u8 *)o + 0xFD0), o->fB8);
    }
    if (func_0038DBA0(ang, 3.1415927f) < 0.7853982f) {
        ret = 3;
    } else if (func_0038DBA0(ang, -1.5707964f) < 0.7853982f) {
        ret = 1;
    } else if (func_0038DBA0(ang, 1.5707964f) < 0.7853982f) {
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_00629DE0 */

INCLUDE_ASM("asm/levels", func_L39_00629FE0);

INCLUDE_ASM("asm/levels", func_L39_0062A4C0);

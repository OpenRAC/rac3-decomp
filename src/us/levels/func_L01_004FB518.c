#include "common.h"

typedef struct {
    u8 pad0[152];
    float f98;
    u8 pad1[400 - 156];
    u8 sub190[16];
    float f1A0;
    u8 pad2[5172 - 420];
    s16 h1434;
    u8 pad3;
    u8 b1437;
    u8 pad4[5808 - 5176];
    s32 mode;
    u8 pad5[9716 - 5812];
    u8 b25F4;
} Veldin1A4BE0;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec_4FB8C8;
typedef union {
    s128 q;
    Vec_4FB8C8 v;
} Q_4FB8C8;
typedef struct {
    u8 pad0[28];
    s32 x28;
    f32 f32;
} Pvar_4FB8C8;
typedef struct {
    u8 pad0[16];
    s128 pos;
    u8 pad32[17];
    u8 b49;
    u8 pad50[2];
    u16 h52;
    u8 pad54[50];
    Pvar_4FB8C8 *pv;
} Moby_4FB8C8;
typedef struct {
    u8 pad0[128];
    s128 v128;
    u8 pad144[8];
    f32 f152;
    u8 pad156[374];
    s16 h530;
    u8 pad532[2108];
    Moby_4FB8C8 *target;
    u8 pad2644[4];
    f32 f2648;
    u8 pad2652[2];
    s16 h2654;
    u8 pad2656[7012];
    s32 x9668;
} Player_4FB8C8;
typedef struct {
    u8 p0[16];
    s128 pos;
    u8 p20[17];
    u8 b49;
    u8 p50;
    u16 h52;
    u8 p54[116];
    s16 h170;
} M_4FBE48;
typedef struct {
    u8 p0[128];
    s128 v128;
    u8 p90[8];
    float f152;
    u8 p9C[1360];
    float f1516;
    u8 p5F0[1184];
    M_4FBE48 *f2704;
    s32 f2708;
    u8 pA98[6964];
    s32 f9676;
} G_4FBE48;
typedef struct {
    u8 p0[9540];
    s32 f9540;
} H_4FBE48;
typedef struct {
    u8 pad0[0x1B8];
    s32 x1B8;
    u8 pad1BC[0x23D4 - 0x1BC];
    s32 x23D4[16];
    s32 x2414[16];
    s32 x2454[16];
    s32 x2494;
    u8 pad2498[0x25C4 - 0x2498];
    s32 x25C4;
    s32 x25C8;
    s32 x25CC;
    s32 x25D0;
    s32 x25D4;
    s32 x25D8;
    s32 x25DC;
    s32 x25E0;
} G_4FC2D0;
typedef struct {
    u8 pad0[440];
    s32 start;
    u8 pad1[9172 - 444];
    s32 ids[32];
    s32 lens[16];
    s32 count;
} S_4FC388;
typedef struct {
    u8 p0[0x1A0];
    s32 w1A0;
} S_00502368;
typedef struct {
    u8 p0[0x1434];
    s16 h1434;
    u8 p1436[0x16B0 - 0x1436];
    s32 w16B0;
    u8 p16B4[0x2838 - 0x16B4];
    f32 f2838;
} G_00502368;

typedef struct {
    u8 pad0[0x284];
    f32 scale;
    u8 pad288[0x298 - 0x288];
    f32 height;
    u8 pad29C[4];
    f32 angle;
    u8 first_flag;
    u8 second_flag;
    u8 pad2A6[2];
    f32 distance;
    f32 clearance;
    s32 valid;
    u8 pad2B4[0x360 - 0x2B4];
    s32 enabled;
    u8 pad364[0x25C0 - 0x364];
    s32 object;
    u8 pad25C4[0x25EE - 0x25C4];
    u8 gate;
} Gate_004FE668;
typedef struct {
    u8 pad0[0x18];
    s32 object;
    u8 pad1C[4];
    f32 hit_position[4];
    u8 pad30[0x10];
    f32 direction[4];
} Dir_004FE668;

extern Gate_004FE668 D_1A4BE0;
extern f32 fe_func_0038CED8(f32 *);
extern f32 fe_func_0038D160(f32, f32);
extern f32 fe_func_0038CF00(void *, void *);
extern s32 fe_func_003C4B50(s32);
extern s32 fe_func_003D3CB0(void *, void *, s32, s32, s32);
/* localdecomp:start func_L01_004FB518 */
extern f32 func_00388770(void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);

/* Pushes the hero toward a target around a point: when slow and in one of a few states it arms a
 * counter, and while armed it eases a speed toward the target direction and writes it to the hero's
 * velocity. */
void func_L01_004FB518(void)
{
    u8 *p = (u8 *)&D_1A4BE0;
    f32 v;
    f32 dist, range, ang;

    if (*(u8 *)(p + 0x2A7) != 0) {
        if (0.0f < *(f32 *)(p + 0x33C)) {
            if (*(f32 *)(p + 0x170) < 0.0500000045f) {
                dist = func_00388770(p + 0xF0);
                if (dist < 0.0500000045f) {
                    if (*(f32 *)(p + 0x2838) < 0.2f) {
                        int state = *(int *)(p + 0x25CC);

                        if (state == 0 || state == 2 || state == 4 || state == 10
                            || state == 1) {
                            u8 *q = (u8 *)&D_1A4BE0;

                            *(short *)(q + 0x20A) = 5;
                        }
                    }
                }
            }
        }
    }
    p = (u8 *)&D_1A4BE0;
    if (*(short *)(p + 0x20A) != 0) {
        dist = func_00388800(p + 0x80, p + 0x260);
        range = *(f32 *)(p + 0x284) * 0.9f;
        if (dist < range) {
            f32 dx = *(f32 *)(p + 0x80) - *(f32 *)(p + 0x260);
            f32 dy = *(f32 *)(p + 0x84) - *(f32 *)(p + 0x264);

            ang = func_00388A28(dx, dy);
            if (dist < *(f32 *)(p + 0x284) * 0.05f)
                ang = *(f32 *)(p + 0x98);
            v = dist - range;
            func_L01_00445168(&v, (f32 *)(p + 0x294), 0.0f, 0.0299999993f, 0.300000012f, 0.0466666669f);
            *(f32 *)(p + 0x100) = func_00388960(ang) * *(f32 *)(p + 0x294);
            *(f32 *)(p + 0x104) = func_00388978(ang) * *(f32 *)(p + 0x294);
            *(f32 *)(p + 0x108) = 0.0f;
        }
    } else {
        *(int *)(p + 0x294) = 0;
    }
}
/* localdecomp:end func_L01_004FB518 */

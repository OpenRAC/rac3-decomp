#include "common.h"

typedef struct S_0069D260 {
    u8 pad0[0x2B0];
    u32 f2B0;
    u32 f2B4;
    u32 f2B8;
    u32 f2BC;
    u32 f2C0;
    u32 f2C4;
    u32 f2C8;
    u32 f2CC;
    u8 pad1[0x4];
    u32 f2D4;
    u32 f2D8;
    u8 f2DC;
} S_0069D260;

/* localdecomp:start func_L39_0069D1F8 */
typedef struct {
    u8 pad[0x2A8];
    s32 f2A8, f2AC, f2B0, f2B4, f2B8, f2BC, f2C0, f2C4, f2C8, f2CC, f2D0, f2D4, f2D8;
    u8 f2DC;
} S_0069D1F8;

void func_L39_0069D1F8(S_0069D1F8 *o, s32 a1, s32 a2, s32 a3, s32 a4, u8 a5, s32 a6, s32 a7,
                       s32 a8, s32 a9, s32 a10, s32 a11, s32 a12, s32 a13, s32 a14)
{
    o->f2A8 = a1;
    o->f2D0 = a2;
    o->f2AC = a3;
    o->f2B0 = a4;
    o->f2DC = a5;
    o->f2D8 = a6;
    o->f2BC = a9;
    o->f2D4 = a10;
    o->f2B4 = a7;
    o->f2B8 = a8;
    o->f2C0 = a11;
    o->f2C4 = a12;
    o->f2C8 = a13;
    o->f2CC = a14;
}
/* localdecomp:end func_L39_0069D1F8 */

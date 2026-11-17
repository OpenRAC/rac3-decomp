#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
extern u8 D_1A4C60[];

/* localdecomp:start func_L32_003A40B0 */
typedef struct { u8 pad[0x80]; f32 x; f32 y; f32 z; } H_003A40B0;
extern H_003A40B0 D_1A4BE0;
extern f32 D_L32_001DEA10;
extern f32 D_L32_001DEA14;
extern f32 D_L32_001DE8E4;
extern f32 D_L32_001DE8E8;
extern f32 D_L32_001DE934;
extern f32 func_0038DB00(f32, f32);
__asm__(".extern D_L32_001DEA10, 4");
__asm__(".extern D_L32_001DEA14, 4");
__asm__(".extern D_L32_001DE8E4, 4");
__asm__(".extern D_L32_001DE8E8, 4");
__asm__(".extern D_L32_001DE934, 4");

typedef struct {
    u8 pad0[0xA4];
    s32 fA4;
    u8 padA8[0x48];
    s32 fF0;
    u8 padF4[8];
    s32 fFC;
    s32 f100;
    u8 pad104[0x28];
    s32 f12C;
    u8 pad130[4];
    s32 f134;
    s32 f138;
} S_003A40B0;

void func_L32_003A40B0(void *arg0) {
    S_003A40B0 *p = *(S_003A40B0 **)((u8 *)arg0 + 0x68);

    p->fF0 = p->fA4 == 0;
    p->f134 = p->f100 != 0
        ? D_1A4BE0.x < *(f32 *)((u8 *)arg0 + 0x10) && *(f32 *)((u8 *)arg0 + 0x10) - D_L32_001DEA10 < D_1A4BE0.x
        : *(f32 *)((u8 *)arg0 + 0x10) < D_1A4BE0.x && D_1A4BE0.x < *(f32 *)((u8 *)arg0 + 0x10) + D_L32_001DEA10;
    p->f138 = *(f32 *)((u8 *)arg0 + 0x18) - 0.5f < D_1A4BE0.z && D_1A4BE0.z < *(f32 *)((u8 *)arg0 + 0x18) + D_L32_001DEA14;
    p->f100 = fabs_asm(func_0038DB00(*(f32 *)((u8 *)arg0 + 0xF8), D_L32_001DE8E4)) < 1.5707964f;
    p->fFC = p->f100 != 0 ? D_1A4BE0.x < *(f32 *)((u8 *)arg0 + 0x10) : *(f32 *)((u8 *)arg0 + 0x10) < D_1A4BE0.x;
    if (p->f100 != 0) {
        p->f12C = fabs_asm(func_0038DB00(*(f32 *)((u8 *)arg0 + 0xF8), D_L32_001DE8E4)) < D_L32_001DE934;
    } else {
        p->f12C = fabs_asm(func_0038DB00(*(f32 *)((u8 *)arg0 + 0xF8), D_L32_001DE8E8)) < D_L32_001DE934;
    }
}
/* localdecomp:end func_L32_003A40B0 */

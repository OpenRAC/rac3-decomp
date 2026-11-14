#include "common.h"

/* NTSC-U counterpart of func_L34_003508A8 (src/levels/34_vidcomic_3/L34_0034F718.c) */
/* localdecomp:start func_L34_0034FB88 */
extern void func_L01_00441FB8(void *, s32, s32);
typedef struct { u8 pad[0x84]; f32 f84; } G_0034FB88;
extern G_0034FB88 D_001A4BE0_0034FB88;
extern s32 *D_L34_0021D8C0[];

void func_L34_0034FB88(u8 *obj)
{
    u8 *p = *(u8 **)(obj + 0x68);
    s32 *tbl;
    s32 i;

    *(f32 *)(p + 0x60) = 0.75f;
    *(f32 *)(p + 0x50) = 3.0f;
    *(f32 *)(p + 0x90) = 0.5f;
    *(f32 *)(p + 0x94) = 0.5f;
    *(f32 *)(p + 0x98) = 0.5f;
    *(f32 *)(p + 0x9C) = 1.0f;
    *(f32 *)(p + 0xA0) = 0.785398185f;
    *(f32 *)(p + 0xC0) = 0.349065840f;
    *(f32 *)(p + 0xBC) = 0.0027222224f;
    *(u16 *)(obj + 0x34) |= 0x100;
    *(f32 *)(obj + 0x14) = D_001A4BE0_0034FB88.f84;
    if (*(s32 *)(p + 0x260) != -1) {
        tbl = D_L34_0021D8C0[*(s32 *)(p + 0x260)];
        for (i = 0; i < tbl[0]; i++) {
            *(f32 *)((u8 *)tbl + 0x14 + i * 16) = D_001A4BE0_0034FB88.f84;
        }
    }
    if (*(s32 *)(p + 0x26C) != 0) {
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) |= 0x41;
        func_L01_00441FB8(obj, 1, -1);
    } else {
        func_L01_00441FB8(obj, 2, -1);
    }
}
/* localdecomp:end func_L34_0034FB88 */

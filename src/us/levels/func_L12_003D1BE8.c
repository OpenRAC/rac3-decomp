#include "common.h"

/* NTSC-U counterpart of func_L12_003D37F0 (src/levels/shared/L12_003D2E60.c) */
/* localdecomp:start func_L12_003D1BE8 */
typedef struct {
    u8 pad0[0x19E0];
    u8 *f19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    s32 f25C0;
} G_003D1BE8;

typedef struct {
    u8 pad0[0x140];
    s32 f140;
    u8 pad144[0x160 - 0x144];
    u8 f160[0x1C8 - 0x160];
    f32 f1C8;
    u8 pad1CC[0x1E0 - 0x1CC];
    u8 f1E0[0x240 - 0x1E0];
    f32 f240;
    u8 pad244[0x274 - 0x244];
    f32 f274;
    f32 f278;
} P_003D1BE8;

extern G_003D1BE8 D_001A4BE0_003D1BE8;
extern f32 func_003893C8(f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern u8 D_L12_001E2800[];
extern f32 D_001DEF30_sda;
extern f32 D_001DEF34_sda;
extern f32 D_001DEF3C_sda;
extern f32 D_001DEF40_sda;
__asm__(".extern D_001DEF30_sda, 4");
__asm__(".extern D_001DEF34_sda, 4");
__asm__(".extern D_001DEF3C_sda, 4");
__asm__(".extern D_001DEF40_sda, 4");

void func_L12_003D1BE8(u8 *obj, P_003D1BE8 *p)
{
    if (p->f140 == D_001A4BE0_003D1BE8.f25C0 && D_001A4BE0_003D1BE8.f19E0 != 0 &&
        *(s16 *)(D_001A4BE0_003D1BE8.f19E0 + 0xAA) == 0x1A17) {
        p->f1C8 = func_003893C8(p->f274, *(f32 *)(obj + 0xF8));
        func_L01_0044B5C8(obj, p->f160, 0, D_001DEF30_sda * 2.0f, D_001DEF34_sda * 2.0f);
        p->f240 = p->f278;
        func_L01_0044B5C8(obj, p->f1E0, 2, D_001DEF3C_sda * 2.0f, D_001DEF40_sda * 2.0f);
    } else {
        p->f1C8 = func_003893C8(p->f274, *(f32 *)(obj + 0xF8));
        func_L01_0044B5C8(obj, p->f160, 0, D_001DEF30_sda, D_001DEF34_sda);
        p->f240 = p->f278;
        func_L01_0044B5C8(obj, p->f1E0, 2, D_001DEF3C_sda, D_001DEF40_sda);
    }
    if (obj[0x31] != 0 && func_L01_0040C018(D_L12_001E2800, obj + 0x10) < 576.0f) {
        func_L01_00444188(obj);
        obj[0x6F] = 0x16;
    }
}
/* localdecomp:end func_L12_003D1BE8 */

#include "common.h"

/* NTSC-U counterpart of func_L03_00399278 (src/levels/03_starship_phoenix/L03_00399278.c) */
/* localdecomp:start func_L03_00397BF8 */
extern f32 D_001DE390_sda_00397BF8; __asm__(".extern D_001DE390_sda_00397BF8, 4");
extern s32 func_L01_00452F60(void *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
void func_L03_00397BF8(u8 *self)
{
    s32 s = self[0x20];
    f32 *p = *(f32 **)(self + 0x68);
    f32 v;
    switch (s) {
    case 0:
        *(u16 *)(self + 0x34) |= 0x2000;
        *p = 1.0f;
        func_L01_00441FB8(self, 1, -1);
        break;
    case 1:
        if (func_L01_00452F60(self)) {
            func_L01_00441FB8(self, 2, -1);
        }
        break;
    case 2:
        self[0x23] = (s32)(*p * 128.0f);
        v = *p - D_001DE390_sda_00397BF8;
        *p = v;
        if (v <= 0.0f) {
            *p = 0.0f;
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(self, 1);
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    }
}
/* localdecomp:end func_L03_00397BF8 */

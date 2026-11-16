#include "common.h"

/* NTSC-U counterpart of func_L08_003C39B0 (src/levels/08_aquatos/L08_003C39B0.c) */
/* localdecomp:start func_L08_003C17D8 */
typedef struct {
    u8 pad0[0x35C];
    void *f35C;
    s32 f360;
} G_003C39B0;
extern G_003C39B0 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern s32 D_L08_001DEDC0_003C17D8;
extern u8 *D_L08_001DF300;
extern void func_003BE418(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_00388398(void *);
extern void func_L01_00452F40(void *, s32);
extern void func_L02_003C3A40(s32);
extern void func_L01_003EAB30(s32);
extern s32 func_L08_003CE910(s32);
extern s32 func_L01_00452EF0(void *);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern s32 func_L03_0043BF68(s32, s32, f32);

void func_L08_003C17D8(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);
    s32 a, b;
    u8 *p;
    f32 ang;

    switch (self[0x20]) {
    case 0:
        func_003BE418(self, 1, 4);
        *(s32 *)(self + 0x48) = 0;
        func_L01_00441FB8(self, 1, -1);
        break;
    case 1:
        break;
    case 2:
        if (func_L01_00452EC8(self)) {
            *(s32 *)(s + 0xC4) = (s32)((f32)*(s32 *)(s + 0xC0) * 60.0f);
        }
        if (func_00388398(s + 0xC4)) {
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(self)) {
            func_L01_00452F40(self, 1);
            if (*(s32 *)(s + 0xC8) != -1) {
                func_L02_003C3A40(*(s32 *)(s + 0xC8));
                func_L01_003EAB30(*(s32 *)(s + 0xC8));
            }
        } else if (*(s32 *)(s + 0xC8) != -1 && func_L08_003CE910(*(s32 *)(s + 0xC8)) && func_L01_00452EF0(self)) {
            p = D_L08_001DF300 + (*(s32 *)(s + 0xCC) << 7);
            func_L01_004F12C0(p + 0x30, p + 0x70, 0x74, 0);
        }
        break;
    }
    if (self[0x31]) {
        s32 n = 120;
        ang = (f32)(D_L08_001DEDC0_003C17D8 % n) * 6.2831855f / (f32)n - 3.1415927f;
        if (D_001A4BE0.f35C == self && D_001A4BE0.f360) {
            a = 0x40;
            b = 0x20;
        } else {
            a = 0x404040;
            b = 0x202020;
        }
        *(s32 *)(self + 0x78) = func_L03_0043BF68(a, b, ang);
    }
}
/* localdecomp:end func_L08_003C17D8 */

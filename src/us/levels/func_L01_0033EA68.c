#include "common.h"

/* NTSC-U counterpart of func_L01_0033F1F0 (src/levels/shared/L01_0033F1F0.c): 0.02 -> 0.0166667 */
#include "vu0.h"

/* localdecomp:start func_L01_0033EA68 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[2];
    u8 bA;
    u8 bB;
} __attribute__((aligned(16))) Inner_0033F1F0;

typedef struct {
    u8 pad0[0xA];
    s16 hA;
    u8 padC[0x14];
    Inner_0033F1F0 in;
} __attribute__((aligned(16))) Part_0033F1F0;

extern vu0_v4 D_L01_001E2A40_0033EA68[];
extern u8 *func_L01_004633E8(f32, f32, f32, f32, void *, s32, void *, u32, s32);
extern f32 D_L01_001DD0A8;
extern s32 D_L01_001DD0B8;
extern u16 D_L01_001DD0BC;
extern f32 D_L01_001DD0C0;
extern f32 D_L01_001DD0C4;
extern s32 D_L01_001DD0C8;
extern u8 D_L01_001DD0CC;
extern f32 D_L01_001DD0D0;
__asm__(".extern D_L01_001DD0A8, 4");
__asm__(".extern D_L01_001DD0B8, 4");
__asm__(".extern D_L01_001DD0BC, 2");
__asm__(".extern D_L01_001DD0C0, 4");
__asm__(".extern D_L01_001DD0C4, 4");
__asm__(".extern D_L01_001DD0C8, 4");
__asm__(".extern D_L01_001DD0CC, 1");
__asm__(".extern D_L01_001DD0D0, 4");
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);

void func_L01_0033EA68(u8 *self) {
    f32 axis[4] __attribute__((aligned(16)));
    f32 dir[4] __attribute__((aligned(16)));
    f32 rot[4] __attribute__((aligned(16)));
    f32 vel[4] __attribute__((aligned(16)));
    f32 step;
    s32 i;
    s32 r;
    s32 s;
    u32 fl;
    Part_0033F1F0 *p;
    Inner_0033F1F0 *in;

    *(s128 *)axis = 0;
    axis[2] = D_L01_001DD0A8;
    vec_sub_ab(dir, D_L01_001E2A40_0033EA68, self + 0x10);
    step = 6.2831855f / (f32)D_L01_001DD0B8;
    for (i = 0; i < D_L01_001DD0B8; i++) {
        func_00389158(rot, axis, dir, (f32)i * step);
        func_00388830(vel, rot, D_L01_001DD0C0 * 0.0166666675f);
        r = func_0037E1D8(0x10);
        s = func_0037E1D8(2);
        fl = D_L01_001DD0C8;
        p = (Part_0033F1F0 *)func_L01_004633E8(0.5f, 1.0f, D_L01_001DD0D0, D_L01_001DD0C4 * 210000.0f, self + 0x10, s == 0 ? r : -r, vel, fl, 0);
        if (p != 0) {
            in = &p->in;
            p->hA = D_L01_001DD0BC;
            in->w4 = 2;
            in->bA = D_L01_001DD0CC;
            in->bB = p->hA;
        }
    }
}
/* localdecomp:end func_L01_0033EA68 */

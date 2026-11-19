#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0033F1F0 */
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

extern vu0_v4 D_L01_001E29C0[];
extern u8 *func_L01_004669B0(f32, f32, f32, f32, void *, s32, void *, u32, s32);
extern f32 D_L01_001DD068;
extern s32 D_L01_001DD078;
extern u16 D_L01_001DD07C;
extern f32 D_L01_001DD080;
extern f32 D_L01_001DD084;
extern s32 D_L01_001DD088;
extern u8 D_L01_001DD08C;
extern f32 D_L01_001DD090;
__asm__(".extern D_L01_001DD068, 4");
__asm__(".extern D_L01_001DD078, 4");
__asm__(".extern D_L01_001DD07C, 2");
__asm__(".extern D_L01_001DD080, 4");
__asm__(".extern D_L01_001DD084, 4");
__asm__(".extern D_L01_001DD088, 4");
__asm__(".extern D_L01_001DD08C, 1");
__asm__(".extern D_L01_001DD090, 4");
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);

void func_L01_0033F1F0(u8 *self) {
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
    axis[2] = D_L01_001DD068;
    vec_sub_ab(dir, D_L01_001E29C0, self + 0x10);
    step = 6.2831855f / (f32)D_L01_001DD078;
    for (i = 0; i < D_L01_001DD078; i++) {
        func_0038D890(rot, axis, dir, (f32)i * step);
        func_0038CF68(vel, rot, D_L01_001DD080 * 0.020000001f);
        r = func_00382468(0x10);
        s = func_00382468(2);
        fl = D_L01_001DD088;
        p = (Part_0033F1F0 *)func_L01_004669B0(0.5f, 1.0f, D_L01_001DD090, D_L01_001DD084 * 210000.0f, self + 0x10, s == 0 ? r : -r, vel, fl, 0);
        if (p != 0) {
            in = &p->in;
            p->hA = D_L01_001DD07C;
            in->w4 = 2;
            in->bA = D_L01_001DD08C;
            in->bB = p->hA;
        }
    }
}
/* localdecomp:end func_L01_0033F1F0 */

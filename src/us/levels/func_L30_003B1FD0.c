#include "common.h"

/* localdecomp:start func_L30_003B1FD0 */
typedef struct {
    s16 h0;
    u8 pad02[2];
    f32 f4;
    f32 f8;
    u8 bC;
    u8 bD;
    u8 bE;
    u8 bF;
} Vars_003B1FD0;

typedef struct {
    u8 pad00[0x20];
    f32 f20;
    u8 pad24[4];
    s32 w28;
    s32 w2C;
} G_003B1FD0;

__asm__(".extern D_001DED2C_sda, 4");
__asm__(".extern D_001DED30_sda, 4");
__asm__(".extern D_001DED48_sda, 4");
__asm__(".extern D_001DED70_sda, 4");
__asm__(".extern D_001DED74_sda, 4");
__asm__(".extern D_001DED78_sda, 4");
__asm__(".extern D_001DED7C_sda, 4");
__asm__(".extern D_001DEC68_sda, 4");
extern f32 D_001DED2C_sda;
extern s32 D_001DED30_sda;
extern s32 D_001DED48_sda;
extern f32 D_001DED70_sda;
extern s32 D_001DED74_sda;
extern f32 D_001DED78_sda;
extern f32 D_001DED7C_sda;
extern u16 D_001DEC68_sda;
extern G_003B1FD0 D_L30_001E22C0_003B1FD0;
__asm__(".extern D_L30_001E22C0_003B1FD0, 16");
extern void func_L30_003B1680(void *);
extern void func_L30_003B1E58(void *, s32);
extern void func_L30_003B1CD0(void *, s32);
extern void func_L30_003B1AB0();
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004026A0(void *, void *);
extern s32 func_003883C8(void *);
extern void func_003BD360(void *);

void func_L30_003B1FD0(u8 *self) {
    Vars_003B1FD0 *v = *(Vars_003B1FD0 **)(self + 0x68);
    f32 t;
    f32 a;
    f32 b;

    switch (self[0x20]) {
    case 0:
        func_L30_003B1680(self + 0x10);
        func_L30_003B1E58(self, D_001DED48_sda);
        func_L30_003B1CD0(self, D_001DED30_sda);
        D_L30_001E22C0_003B1FD0.f20 = D_001DED70_sda;
        D_L30_001E22C0_003B1FD0.w28 = D_001DED74_sda;
        D_L30_001E22C0_003B1FD0.w2C = 0;
        func_L01_00441FB8(self, 1, -1);
        v->h0 = D_001DEC68_sda;
        break;
    case 1:
        t = (f32)v->h0;
        a = t / (t + 1.5f);
        b = t / (t + D_001DED2C_sda);
        v->f4 = v->f4 + D_001DED78_sda;
        v->f8 = v->f8 + D_001DED7C_sda;
        v->bC = (s32)((f32)v->bC * b);
        v->bD = (s32)((f32)v->bD * b);
        v->bE = (s32)((f32)v->bE * a);
        v->bF = (s32)((f32)v->bF * b);
        func_L01_004026A0(func_L30_003B1AB0, self);
        if (func_003883C8(v) != 0) {
            func_L01_00441FB8(self, 2, -1);
        }
        break;
    case 2:
        func_003BD360(self);
        break;
    }
}
/* localdecomp:end func_L30_003B1FD0 */

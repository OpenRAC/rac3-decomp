/* functional: high. State switch on obj->type (jump table read from the L36 copy of the function: states 0/4,1,2,3,5,6,7,0x42, everything else only runs the common tail); COP2 vadd.xyz written as scalar adds (w left as in retail, uninitialised stack word); scheduling differs. */
#include "vu0.h"
__asm__(".extern D_L30_001DE8FC, 4");
extern s32 D_L30_001DE8FC;
__asm__(".extern D_L30_001DE994, 4");
extern f32 D_L30_001DE994;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L30_003A1D08(void *);
extern void func_L30_003A14F8(void *);
extern void func_L30_003A1A68(void *);
extern void func_L30_003A22F0(void *);
extern void func_L30_003A2608(void *);
extern void func_L30_003A3070(void *);
extern void func_L30_003A2C68(void *, s32);
extern void func_L30_003A2FA8(void *);
extern void func_L30_003A2808(void *);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Q_3A1AF8;
typedef struct {
    Q_3A1AF8 x0;
    u8 p10[0x20 - 0x10]; Q_3A1AF8 x20; Q_3A1AF8 x30;
    u8 p40[0x54 - 0x40]; s32 x54;
    u8 p58[0x6C - 0x58]; f32 x6C;
} V_3A1AF8;
typedef struct {
    u8 p0[0x10]; Q_3A1AF8 x10; u8 x20; u8 p21[0x60 - 0x21]; u8 x60;
    u8 p61[0xAA - 0x61]; s16 xAA;
    u8 pAC[0xF4 - 0xAC]; f32 xF4;
} O_3A1AF8;

void func_L30_003A1AF8(O_3A1AF8 *self) {
    V_3A1AF8 *v = *(V_3A1AF8 **)((u8 *)self + 0x68);
    Q_3A1AF8 t;
    Q_3A1AF8 d;

    t.x = func_0038D098(func_0038DAB8(-self->xF4, -1.5707964f)) * v->x6C;
    t.y = 0.0f;
    t.z = func_0038D0B0(func_0038DAB8(-self->xF4, -1.5707964f)) * v->x6C;
    self->x10.x = t.x + v->x30.x;
    self->x10.y = t.y + v->x30.y;
    self->x10.z = t.z + v->x30.z;
    self->x10.w = t.w;
    switch (self->x20) {
    case 0:
    case 4:
        func_L30_003A3070(self);
        break;
    case 1:
        func_L30_003A1D08(self);
        break;
    case 2:
        func_L30_003A22F0(self);
        break;
    case 3:
        func_L30_003A2608(self);
        break;
    case 5:
        if (self->x60 & 2) {
            func_L30_003A2C68(self, 1);
        }
        break;
    case 6:
        func_L30_003A2FA8(self);
        break;
    case 7:
        if (func_L01_004561B8(self) != 0) {
            func_0038CF68(&d, &v->x20, -D_L30_001DE994);
            v->x0.x += d.x;
            v->x0.y += d.y;
            v->x0.z += d.z;
        }
        if (self->x60 & 2) {
            func_L30_003A2C68(self, 2);
        }
        break;
    case 0x42:
        if (func_L01_004561B8(self) != 0) {
            if (v->x54 & 1) {
                D_L30_001DE8FC--;
            }
            func_003A52A0(1, 0, self);
            func_003A52A0(3, 0, self);
        }
        if (self != 0) {
            if (self->xAA == 0x1946) {
                func_L30_003A14F8(self);
            }
            if (self->xAA == 0x1C1A) {
                func_L30_003A1A68(self);
            }
        }
        func_003C2880(self);
        return;
    }
    func_L30_003A2808(self);
}

#include "common.h"

/* NTSC-U counterpart of func_L02_00326430 (src/levels/shared/L02_00326430.c): 0.02 -> 0.0166667 */
typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x60 - 0x1C];
    f32 f60;
    f32 f64;
    f32 f68;
} State_416A50;
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} Class_416A50;
typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x20 - 0x1C];
    u8 b20;
    u8 pad2[0x24 - 0x21];
    Class_416A50 *cls;
    u8 pad3[0x2C - 0x28];
    f32 f2C;
    u8 pad4[0x68 - 0x30];
    State_416A50 *st;
    u8 pad5[0xF0 - 0x6C];
    f32 fF0;
    f32 fF4;
    f32 fF8;
    f32 fFC;
} Obj_416A50;

/* localdecomp:start func_L02_00325BB8 */
extern void func_L02_003261F0(Obj_416A50 *a0);
extern float D_L02_001DC930;
extern float D_L02_001DC934;
extern float D_L02_001DC938;
extern float D_L02_001DC948;
extern int D_L02_001DC95C;
__asm__(".extern D_L02_001DC930, 4");
__asm__(".extern D_L02_001DC934, 4");
__asm__(".extern D_L02_001DC938, 4");
__asm__(".extern D_L02_001DC948, 4");
__asm__(".extern D_L02_001DC95C, 4");
extern float func_0038D0B0(float);
extern float func_0038DAB8(float, float);
extern int func_00382468(int);
extern void func_L02_00325D78(Obj_416A50 *);

void func_L02_00325BB8(Obj_416A50 *a0)
{
    State_416A50 *s1 = a0->st;
    float f;
    a0->f2C = a0->cls->f24 * D_L02_001DC930;
    if (a0->b20 == 1) {
        f = func_0038D0B0(a0->fFC);
        a0->f18 = s1->f18 + D_L02_001DC934 + D_L02_001DC938 * f;
        a0->fF0 = func_0038DAB8(a0->fF0, s1->f68);
        a0->fF4 = func_0038DAB8(a0->fF4, s1->f64);
        a0->fF8 = func_0038DAB8(a0->fF8, s1->f60);
        a0->fFC = func_0038DAB8(a0->fFC, D_L02_001DC948 * 0.017453292f * 0.0166666675f);
    }
    func_L02_00325D78(a0);
    if (func_00382468(D_L02_001DC95C) == 0)
        func_L02_003261F0(a0);
}
/* localdecomp:end func_L02_00325BB8 */

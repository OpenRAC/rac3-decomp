#include "common.h"

/* NTSC-U counterpart of func_L02_00326A80 (src/levels/shared/L02_00326430.c) */
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
extern void func_L02_003261F0(Obj_416A50 *a0);
extern int func_0037E1D8(int);
#include "vu0.h"

/* localdecomp:start func_L02_003261F0 */
#include "vu0.h"
extern void func_003886E8(void *, void *, float);
extern void func_003BDA38(void *, int, void *);
extern void func_L01_00440A88(void *, float, float);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern float D_001A4CC8 __attribute__((section(".data")));
extern float D_L02_001DC964;
extern float D_L02_001DC968_003261F0;
extern float D_L02_001DC96C;
extern float D_L02_001DC970;
extern int D_L02_001DC974;
extern int D_L02_001DC978;
extern int D_L02_001DC97C;
extern float D_L02_001DC980;
extern float D_L02_001DC984;
__asm__(".extern D_L02_001DC964, 4");
__asm__(".extern D_L02_001DC968_003261F0, 4");
__asm__(".extern D_L02_001DC96C, 4");
__asm__(".extern D_L02_001DC970, 4");
__asm__(".extern D_L02_001DC974, 4");
__asm__(".extern D_L02_001DC978, 4");
__asm__(".extern D_L02_001DC97C, 4");
__asm__(".extern D_L02_001DC980, 4");
__asm__(".extern D_L02_001DC984, 4");

void func_L02_003261F0(Obj_416A50 *a0)
{
    vu0_v4 m, v1, v2;
    int i;

    if (a0->b20 == 1) {
        func_003886E8(&m, a0, 0.0009765625f);
    } else {
        func_003BDA38(a0, 0, &m);
        if (m.z < D_001A4CC8) return;
    }

    func_L01_00440A88(&v1, D_L02_001DC964 * 0.016666668f, D_L02_001DC968_003261F0 * 0.016666668f);
    i = 2;
    func_L01_00468DC0(&m, &v1, D_L02_001DC978, D_L02_001DC980, D_L02_001DC974, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
    do {
        i--;
        func_L01_00440A88(&v2, D_L02_001DC96C * 0.016666668f, D_L02_001DC970 * 0.016666668f);
        vec_add_ab(&v1, &v1, &v2);
        func_L01_00468DC0(&m, &v1, D_L02_001DC97C, D_L02_001DC984, D_L02_001DC974, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
    } while (i >= 0);
}
/* localdecomp:end func_L02_003261F0 */

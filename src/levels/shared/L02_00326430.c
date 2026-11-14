#include "common.h"

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

/* localdecomp:start func_L02_00326430 */
extern void func_L02_00326A80(Obj_416A50 *a0);
extern float D_L02_001DC8F0;
extern float D_L02_001DC8F4;
extern float D_L02_001DC8F8;
extern float D_L02_001DC908;
extern int D_L02_001DC91C;
__asm__(".extern D_L02_001DC8F0, 4");
__asm__(".extern D_L02_001DC8F4, 4");
__asm__(".extern D_L02_001DC8F8, 4");
__asm__(".extern D_L02_001DC908, 4");
__asm__(".extern D_L02_001DC91C, 4");
extern float func_0038D0B0(float);
extern float func_0038DAB8(float, float);
extern int func_00382468(int);
extern void func_L02_00326600(Obj_416A50 *);

void func_L02_00326430(Obj_416A50 *a0)
{
    State_416A50 *s1 = a0->st;
    float f;
    a0->f2C = a0->cls->f24 * D_L02_001DC8F0;
    if (a0->b20 == 1) {
        f = func_0038D0B0(a0->fFC);
        a0->f18 = s1->f18 + D_L02_001DC8F4 + D_L02_001DC8F8 * f;
        a0->fF0 = func_0038DAB8(a0->fF0, s1->f68);
        a0->fF4 = func_0038DAB8(a0->fF4, s1->f64);
        a0->fF8 = func_0038DAB8(a0->fF8, s1->f60);
        a0->fFC = func_0038DAB8(a0->fFC, D_L02_001DC908 * 0.017453292f * 0.020000001f);
    }
    func_L02_00326600(a0);
    if (func_00382468(D_L02_001DC91C) == 0)
        func_L02_00326A80(a0);
}
/* localdecomp:end func_L02_00326430 */

/* localdecomp:start func_L02_00326520 */
void func_L02_00326520(unsigned char *a0) {
    unsigned char *obj = *(unsigned char **)(a0 + 0x68);
    float *p;
    int *q;
    int v;
    int i;
    int d;

    i = 3;
    p = (float *)(obj + 0x20);
    do {
        for (; i >= 0; i--) {
            *p++ = (float)func_00382468(0xFF);
        }
    } while (0);
    *(float *)(obj + 0x30) = -1.0f;
    *(float *)(obj + 0x34) = -2.25f;
    *(float *)(obj + 0x38) = 1.25f;
    *(float *)(obj + 0x3C) = 2.5f;
    d = 6;
    q = (int *)(obj + 0x40);
    v = 0x13D;
    i = 3;
    for (; i >= 0; i--) {
        *q++ = v / d;
        v += 0x140;
    }
    *(float *)(obj + 0x50) = 2.5f;
    *(float *)(obj + 0x54) = 3.0f;
    *(float *)(obj + 0x58) = 3.0f;
    *(float *)(obj + 0x5C) = 2.5f;
}
/* localdecomp:end func_L02_00326520 */

INCLUDE_ASM("asm/levels", func_L02_00326600);

INCLUDE_ASM("asm/levels", func_L02_00326878);

INCLUDE_ASM("asm/levels", func_L02_00326A80);

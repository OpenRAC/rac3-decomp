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

typedef int Q_326878 __attribute__((mode(TI)));
typedef union { Q_326878 whole; float f[4]; } Vec_326878;
typedef struct { unsigned char prefix[0x80]; Vec_326878 position; unsigned char unused90[8]; float heading; } Hero_326878;

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

/* localdecomp:start func_L02_00326878 */
#include "vu0.h"

extern float func_L01_004395E0(void *);
extern float func_0038DB00(float, float);
extern float func_0038D098(float);
extern void func_0038CDF8(void *, void *, void *, float);
extern void func_L01_003EB350(int, void *), func_L01_003EB3C0(int, void *);

extern Hero_326878 D_001A4BE0;
extern char *D_L02_001DEA80 __attribute__((section(".sdata")));

void func_L02_00326878(Obj_416A50 *a0)
{
    char *object = (char *)a0;
    int *state = *(int **)(object + 0x68);
    Vec_326878 position, rotation, first, second;
    float weight, heading, value;
    if (*(unsigned char *)(object + 0x42) == 1)
        value = func_L01_004395E0(object);
    else
        value = 170.0f;
    weight = value / 170.0f;
    if (state[1] == -1 || state[2] == -1) {
        heading = func_0038DAB8(weight * 0.6981316804885864f - 0.3490658402442932f, D_001A4BE0.heading);
        position.f[0] = func_0038D098(heading) * 5.0f;
        position.f[1] = func_0038D0B0(heading) * 5.0f;
        position.f[2] = 0;
        vec_add_ab(&position, &position, &D_001A4BE0.position);
        position.f[2] += 1.0f;
        qzero(&rotation);
        rotation.f[2] = func_0038DAB8(heading, 3.141590118408203125f);
        rotation.f[1] = weight * -0.17000000178813934326f;
    } else {
        func_0038CDF8(&position, D_L02_001DEA80 + state[1] * 0x80 + 0x30, D_L02_001DEA80 + state[2] * 0x80 + 0x30, weight);
        first.whole = ((Vec_326878 *)(D_L02_001DEA80 + state[1] * 0x80 + 0x70))->whole;
        second.whole = ((Vec_326878 *)(D_L02_001DEA80 + state[2] * 0x80 + 0x70))->whole;
        rotation.f[2] = func_0038DAB8(func_0038DB00(second.f[2], first.f[2]) * weight, first.f[2]);
        rotation.f[1] = func_0038DAB8(func_0038DB00(second.f[1], first.f[1]) * weight, first.f[1]);
        rotation.f[0] = func_0038DAB8(func_0038DB00(second.f[0], first.f[0]) * weight, first.f[0]);
    }
    func_L01_003EB350(0, &position);
    func_L01_003EB3C0(0, &rotation);
}
/* localdecomp:end func_L02_00326878 */

/* localdecomp:start func_L02_00326A80 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, float);
extern void func_003C2F58(void *, int, void *);
extern void func_L01_00443B88(void *, float, float);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern float D_001A4CC8 __attribute__((section(".data")));
extern float D_L02_001DC924;
extern float D_L02_001DC928;
extern float D_L02_001DC92C;
extern float D_L02_001DC930;
extern int D_L02_001DC934;
extern int D_L02_001DC938;
extern int D_L02_001DC93C;
extern float D_L02_001DC940;
extern float D_L02_001DC944;
__asm__(".extern D_L02_001DC924, 4");
__asm__(".extern D_L02_001DC928, 4");
__asm__(".extern D_L02_001DC92C, 4");
__asm__(".extern D_L02_001DC930, 4");
__asm__(".extern D_L02_001DC934, 4");
__asm__(".extern D_L02_001DC938, 4");
__asm__(".extern D_L02_001DC93C, 4");
__asm__(".extern D_L02_001DC940, 4");
__asm__(".extern D_L02_001DC944, 4");

void func_L02_00326A80(Obj_416A50 *a0)
{
    vu0_v4 m, v1, v2;
    int i;

    if (a0->b20 == 1) {
        func_0038CE20(&m, a0, 0.0009765625f);
    } else {
        func_003C2F58(a0, 0, &m);
        if (m.z < D_001A4CC8) return;
    }

    func_L01_00443B88(&v1, D_L02_001DC924 * 0.020000001f, D_L02_001DC928 * 0.020000001f);
    i = 2;
    func_L01_0046C470(&m, &v1, D_L02_001DC938, D_L02_001DC940, D_L02_001DC934, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
    do {
        i--;
        func_L01_00443B88(&v2, D_L02_001DC92C * 0.020000001f, D_L02_001DC930 * 0.020000001f);
        vec_add_ab(&v1, &v1, &v2);
        func_L01_0046C470(&m, &v1, D_L02_001DC93C, D_L02_001DC944, D_L02_001DC934, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
    } while (i >= 0);
}
/* localdecomp:end func_L02_00326A80 */

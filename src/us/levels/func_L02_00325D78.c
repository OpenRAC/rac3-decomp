#include "common.h"

/* NTSC-U counterpart of func_L02_00326600 (src/levels/shared/L02_00326430.c) */
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
extern void func_L02_00325D78(Obj_416A50 *);

/* localdecomp:start func_L02_00325D78 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_326600;
typedef struct { u8 p0[0x20]; f32 f20[4]; f32 f30[4]; s32 f40[4]; f32 f50[4]; } S_326600;

extern V4_326600 D_L02_001E1300_00325D78;
extern s32 D_L02_001DC94C;
__asm__(".extern D_L02_001DC94C, 4");
extern s32 D_L02_001DC950;
__asm__(".extern D_L02_001DC950, 4");
extern s32 D_L02_001DC954;
__asm__(".extern D_L02_001DC954, 4");
extern s32 D_L02_001DC958_00325D78;
__asm__(".extern D_L02_001DC958_00325D78, 4");
extern void func_003886E8(void *, void *, float);
extern void func_003BDA38(void *, int, void *);
extern float func_L01_00436500(void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_00388398(void *);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00468C38(void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L02_00325D78(Obj_416A50 *a0) {
    V4_326600 d;
    V4_326600 v10;
    V4_326600 e;
    S_326600 *st;
    f32 mul;
    s32 i;

    mul = 1.0f;
    st = (S_326600 *)a0->st;
    if (a0->b20 == 1) {
        func_003886E8(&v10, a0, 0.0009765625f);
    } else {
        func_003BDA38(a0, 0, &v10);
        mul = (160.0f - func_L01_00436500(a0)) / 160.0f * 5.0f;
        if (1.0f < mul) {
            mul = 1.0f;
        }
    }
    vec_sub_ba(&d, &D_L02_001E1300_00325D78, &v10);
    func_00388830(&d, &d, -0.3f);
    func_00388830(&e, &d, 0.1f);
    vec_add_ab(&d, &d, &v10);
    for (i = 0; i < 4; i++) {
        st->f20[i] = st->f20[i] + st->f30[i];
        if (st->f20[i] >= 255.0f) {
            st->f20[i] = st->f20[i] - 255.0f;
        } else if (st->f20[i] <= 0.0f) {
            st->f20[i] = st->f20[i] + 255.0f;
        }
        if (func_00388398(&st->f40[i]) != 0) {
            st->f40[i] = 0xFF;
        }
        func_L01_00468C38(&d, func_003894A0(D_L02_001DC94C, D_L02_001DC950, fabs_asm(0.5f - (f32)(0xFF - st->f40[i]) / 255.0f)),
                          (s32)st->f20[i] & 0xFF, D_L02_001DC958_00325D78, D_L02_001DC954, 2, 0, 0, st->f50[i] * mul);
        vec_add_ab(&d, &d, &e);
    }
}
/* localdecomp:end func_L02_00325D78 */

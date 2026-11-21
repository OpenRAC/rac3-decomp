#include "common.h"

/* NTSC-U counterpart of func_L01_004723B0 (src/levels/shared/L01_00470A28.c) */
#include "vu0.h"
typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub;
typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub sub;
} Obj;
extern void func_003886E8(void *, void *, f32);
extern void func_L01_004C6EC8(void *, void *);
extern s32 func_003883C8(s16 *);
extern s32 func_003883C8(s16 *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_003883C8(s16 *);
#include "vu0.h"
extern s32 func_003883C8(s16 *);
extern s32 func_003883C8(s16 *);
extern int func_003883C8(short *);
extern s32 func_003883C8(s16 *);
extern void func_L01_004C6EC8(void *, void *);
extern s32 func_003883C8(s16 *);
extern void func_L01_004C6EC8(void *, void *);

/* localdecomp:start func_L01_0046EC60 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4723B0;
extern void func_L01_004C6EC8(void *, void *);
extern s32 func_003894A0(s32, s32, f32);
extern f32 func_L01_00442070(f32);
extern f32 func_L01_00442068(f32);

void func_L01_0046EC60(u8 *p)
{
    u8 *v = p + 0x20;
    V4_4723B0 a;
    V4_4723B0 b;
    f32 t;
    f32 k;

    b.w = 0.0f;
    b.x = *(f32 *)(p + 0x20);
    b.y = *(f32 *)(v + 4);
    b.z = *(f32 *)(v + 8);
    func_L01_004C6EC8(p + 0x10, p + 0x10);
    t = (f32)*(s16 *)(p + 0xA) / (f32)v[0x11];
    k = 1.0f - t;
    if (v[0x13] == 0) {
        *(u32 *)(p + 4) = func_003894A0(0x103080, *(s32 *)(v + 0xC), k) | (v[0x12] << 24);
        *(f32 *)(p + 0xC) = *(f32 *)(v + 0x14) + (*(f32 *)(v + 0x18) - *(f32 *)(v + 0x14)) * k;
        func_003886E8(&a, &b, *(f32 *)(v + 0x1C) * func_L01_00442070(k));
    } else {
        f32 x = func_L01_00442068(k);
        f32 al = (f32)v[0x12];
        *(u32 *)(p + 4) = *(s32 *)(v + 0xC) | ((s32)(al - al * x) << 24);
        func_003886E8(&a, &b, *(f32 *)(v + 0x1C));
    }
    vec_add_ba(p + 0x10, &a, p + 0x10);
    p[8] = p[8] + v[0x10];
    if (func_003883C8((s16 *)(p + 0xA)) != 0) {
        if (v[0x13] == 0) {
            v[0x13] = 1;
            v[0x11] = 0x14;
            *(s16 *)(p + 0xA) = 0x14;
        } else {
            func_003C7CE0((Obj *)p);
        }
    }
}
/* localdecomp:end func_L01_0046EC60 */

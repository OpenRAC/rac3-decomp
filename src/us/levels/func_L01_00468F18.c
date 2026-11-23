#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0046C5C8 (src/levels/shared/L01_0046A938.c): life limit 300 for PAL's 250 */
/* localdecomp:start func_L01_00468F18 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef int u128_t __attribute__((mode(TI)));
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
extern Vec4 D_001A4C60;
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_003883C8(s16 *);
extern void func_003C7CE0(Obj *);

void func_L01_00468F18(u8 *p)
{
    f32 v[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    u8 *q = p + 0x20;
    s32 life;

    v[3] = 0.0f;
    v[0] = *(f32 *)(p + 0x20);
    v[1] = *(f32 *)(q + 4);
    v[2] = *(f32 *)(q + 8);
    if (*(s32 *)(q + 0x1C) == 1) {
        *(u128_t *)g = *(u128_t *)&D_001A4C60;
        *(f32 *)(p + 0x10) = g[0] + *(f32 *)(q + 0x10);
        *(f32 *)(p + 0x14) = g[1] + *(f32 *)(q + 0x14);
        *(f32 *)(p + 0x18) = g[2] + *(f32 *)(q + 0x18);
        vec_add_ab(p + 0x10, p + 0x10, v);
        *(f32 *)(q + 0x10) = *(f32 *)(p + 0x10) - g[0];
        *(f32 *)(q + 0x14) = *(f32 *)(p + 0x14) - g[1];
        *(f32 *)(q + 0x18) = *(f32 *)(p + 0x18) - g[2];
    } else {
        vec_add_ab(p + 0x10, p + 0x10, v);
    }
    if (*(f32 *)(p + 0x10) < 2.0f || 1021.0f < *(f32 *)(p + 0x10) ||
        *(f32 *)(p + 0x14) < 2.0f || 1021.0f < *(f32 *)(p + 0x14) ||
        *(f32 *)(p + 0x18) < 2.0f || 1021.0f < *(f32 *)(p + 0x18) ||
        func_003883C8((s16 *)(p + 0xA)) != 0) {
        func_003C7CE0((Obj *)p);
        return;
    }
    life = *(s16 *)(p + 0xA);
    if (life < 300) {
        *(s32 *)(p + 4) = func_003894A0(*(s32 *)(p + 4) & 0xFFFFFF, *(s32 *)(p + 4), (f32)(life - 1) / (f32)life);
    }
}
/* localdecomp:end func_L01_00468F18 */

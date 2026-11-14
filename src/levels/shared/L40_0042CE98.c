#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_0042CE98);

/* localdecomp:start func_L40_0042D000 */
#include "vu0.h"

typedef int u128_0042D000 __attribute__((mode(TI)));
typedef struct {
    u128_0042D000 v0, v1, v2;
} Ray_0042D000;
typedef struct {
    u8 *ptr;
    s32 pad;
    s32 color[4];
} Col_0042D000;

extern vu0_v4 D_L40_00247930 __attribute__((section(".sdata")));
__asm__(".extern D_L40_00247930, 8");
extern f32 D_L40_00247924;
__asm__(".extern D_L40_00247924, 4");
extern s32 D_L40_00247920;
__asm__(".extern D_L40_00247920, 4");
extern Col_0042D000 D_L40_0025B998;
extern u8 D_L40_00242930[] __attribute__((section(".sdata")));
extern u8 *D_L40_0029AF58[];

extern void func_0038D000(void *, void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_00446780(void *, f32, void *, s32, f32, f32, s32, s32, s32);
extern void func_L40_0042D5D8(void *, s32, s32);
extern f32 func_0038CEA8(void *);
extern s32 func_L39_0059EBC8(void *, f32, f32, f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_00424D88(s32);
extern void func_003C2880(void *);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern void func_L01_00399E80(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L40_0042D4C8(void *);

void func_L40_0042D000(u8 *o)
{
    vu0_v4 delta;
    Ray_0042D000 ray;
    vu0_v4 dir;
    vu0_v4 v;
    u8 *d = *(u8 **)(o + 0x68);
    f32 angle;
    f32 size;
    u8 *p;
    s32 i;

    func_0038D000(&delta, &D_L40_00247930, *(u8 **)(o + 0xB8) + 0xC0);
    func_003C2F58(*(void **)(o + 0xB8), 3, o + 0x10);
    vec_add_ba(o + 0x10, o + 0x10, &delta);
    ray.v0 = *(u128_0042D000 *)(o + 0x10);
    func_L39_005BC330(o + 0x10, &ray.v1, 1);
    ray.v2 = *(u128_0042D000 *)(o + 0x10);
    vec_sub_ba(&dir, d + 0x30, o + 0x10);
    func_0038CF68(&dir, &dir, 1.0f);
    if (func_0038D160(*(f32 *)(d + 0x30) - *(f32 *)(o + 0x10),
                      *(f32 *)(d + 0x34) - *(f32 *)(o + 0x14)) < 1.5707964f) {
        angle = func_L39_005B4410(0.0f, -0.7853982f);
    } else {
        angle = func_L39_005B4410(0.0f, 0.7853982f);
    }
    *(u128_0042D000 *)(d + 0x40) = *(u128_0042D000 *)(o + 0x10);
    *(f32 *)(d + 0x48) -= D_L40_00247924;
    vec_sub_ba(d + 0x40, d + 0x40, o + 0x10);
    func_0038D890(d + 0x40, d + 0x40, &dir, angle);
    vec_add_ab(d + 0x40, o + 0x10, d + 0x40);

    switch (o[0x20]) {
    case 0:
        if (func_003D3CB0(o + 0x10, d + 0x30, 0, *(void **)(o + 0xB8), 0) != 0) {
            *(u128_0042D000 *)&v = *(u128_0042D000 *)D_L40_0025B998.color;
            func_L01_00446780(o, 1.5f, &v, 0x210001, *(f32 *)(d + 0xC), 1.0f, 1, 1, 0);
            if (D_L40_0025B998.ptr == 0) {
                func_L40_0042D5D8(&v, 0xF, 0);
            } else if (*(s32 *)(D_L40_0025B998.ptr + 0x98) != 0) {
                func_L40_0042D5D8(&v, 0xA, 0);
            }
            o[0x20] = 1;
            *(s32 *)(d + 0x10) = (D_L40_00247920 * 5 + 2) / 6;
        } else {
            o[0x20] = 1;
            *(s32 *)(d + 0x10) = (D_L40_00247920 * 5 + 2) / 6;
        }
        vec_sub_ba(&v, d + 0x30, o + 0x10);
        func_0038CF68(&v, &v, func_0038CEA8(&v) * 0.5f);
        vec_add_ba(&v, o + 0x10, &v);
        *(s32 *)(d + 0x18) = func_L39_0059EBC8(&v, 10.0f, 0.0f, 0.1f, 0.1f, 1.0f);
        break;
    case 1:
        if (func_0038CAD0(d + 0x10) != 0) {
            if (*(s32 *)(d + 0x18) != -1) {
                func_L01_00424D88(*(s32 *)(d + 0x18));
            }
            func_003C2880(o);
            return;
        }
        for (i = 9; i >= 0; i--) {
            size = func_L39_005B4410(0.25f, 0.4f) * 210000.0f;
            p = func_L01_0046FB40(o + 0x10, D_L40_00242930, 2, 0x804020, 2, 0x7F, 0x10, size, size, 0, 0.0f);
            if (p != 0) {
                p[2] = D_L40_0029AF58[25][0];
            }
            p = func_L01_0046FB40(o + 0x10, D_L40_00242930, 2, 0xFF8040, -1, 0x7F, 0x10, size, size, 0, 0.0f);
            if (p != 0) {
                p[2] = D_L40_0029AF58[25][0];
            }
        }
        func_L01_00399E80(o);
        func_L01_00404A10(func_L40_0042D4C8, o);
        break;
    }
    if (*(f32 *)(o + 0x10) < 2.0f || 1021.0f < *(f32 *)(o + 0x10) ||
        *(f32 *)(o + 0x14) < 2.0f || 1021.0f < *(f32 *)(o + 0x14) ||
        *(f32 *)(o + 0x18) < 2.0f || 1021.0f < *(f32 *)(o + 0x18)) {
        func_003C2880(o);
    }
}
/* localdecomp:end func_L40_0042D000 */

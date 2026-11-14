#include "common.h"

/* NTSC-U counterpart of func_L19_003CEEF8 (src/levels/19_thran_asteroid_belt/L19_003CDD90.c) */
#include "vu0.h"
extern void func_L19_003CCD90(u8 *);
extern void func_003BE418(void *, s32, s32);

/* localdecomp:start func_L19_003CCD90 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CEEF8;
extern V4_3CEEF8 D_L19_001E8E60_003CCD90;
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_00388730(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_00437350(void *, s32, void *);

void func_L19_003CCD90(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V4_3CEEF8 a;
    V4_3CEEF8 b;

    p[0x58] = 0xA;
    p[0x5A] = 2;
    *(f32 *)(p + 0x40) = 0.3f;
    p[0x3E] = 3;
    p[0x39] = 0;
    p[0x3F] = 0;
    p[0x64] = 0;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 1;
        *(f32 *)(p + 0x30) = 1.0f;
    }
    vec_add_ab(&a, obj + 0x10, obj + 0xE0);
    func_003886E8(&b, obj + 0xE0, -10.0f);
    vec_add_ab(&b, &b, obj + 0x10);
    if (func_003CE740(&a, &b, 0, obj, 0) != 0)
        *(V4_3CEEF8 *)(obj + 0x10) = D_L19_001E8E60_003CCD90;
    *(s32 *)(p + 0x118) = 0;
    func_003BE418(obj, 2, 0);
    func_003BDA38(obj, 1, p + 0x130);
    vec_sub_ba(p + 0x130, p + 0x130, obj + 0x10);
    func_003886E8(p + 0x130, obj + 0xE0, func_00388730(p + 0x130, obj + 0xE0));
    vec_add_ba(p + 0x130, p + 0x130, obj + 0x10);
    func_L01_00437350(obj, 2, p + 0x80);
    func_L01_00437350(obj, 0, p + 0xC0);
}
/* localdecomp:end func_L19_003CCD90 */

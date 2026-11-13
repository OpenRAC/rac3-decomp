#include "common.h"

/* NTSC-U counterpart of func_L23_003B7730 (src/levels/23_holostar_studios_clank/L23_003B7530.c) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    u8 pad0[0x30];
    u8 x30[0x3C];
    s32 x6C;
    f32 x70;
    s32 x74;
    s32 x78;
    u8 pad7C[4];
    V4 x80;
} Vars_3B7730;
#include "vu0.h"
extern s32 D_L23_001D6694_003B5D78;
extern s32 D_L23_001DECC0;
extern void func_L01_004A6DF8(void *, s32);
extern f32 func_00389410(f32);
extern f32 func_00388978(f32);
extern void func_003BF838(void *, void *, void *, void *);

/* localdecomp:start func_L23_003B5D78 */
#include "vu0.h"
extern s32 D_L23_001D6694_003B5D78;
__asm__(".extern D_L23_001D6694_003B5D78, 16");
extern s32 D_L23_001DECC0;
__asm__(".extern D_L23_001DECC0, 16");
extern void func_L01_004A6DF8(void *, s32);
extern f32 func_00389410(f32);
extern f32 func_00388978(f32);
extern void func_003BF838(void *, void *, void *, void *);

void func_L23_003B5D78(u8 *a0)
{
    Vars_3B7730 *v = *(Vars_3B7730 **)(a0 + 0x68);
    V4 a;
    V4 b;
    V4 d;

    if (D_L23_001D6694_003B5D78 == 2) {
        *(s32 *)(a0 + 152) = 0;
        *(u16 *)(a0 + 52) = (*(u16 *)(a0 + 52) | 0x41) & ~0x1000;
        func_L01_004A6DF8(a0, 1);
    } else {
        u8 *o = *(u8 **)(a0 + 36);
        *(u16 *)(a0 + 52) &= ~0x41;
        *(u16 *)(a0 + 52) |= *(u16 *)(o + 68) & 0x1000;
        *(s32 *)(a0 + 152) = *(s32 *)(o + 16);
    }
    if (a0[0x20] == 0) {
        if (v->x74 < 10)
            v->x74 = v->x74 * 60.0f;
        if (v->x78 < 10)
            v->x78 = v->x78 * 60.0f;
        v->x80 = *(V4 *)(a0 + 0x10);
        v->x6C |= 1;
        a0[0x20] = 1;
    }
    a = *(V4 *)(a0 + 0x10);
    b = v->x80;
    b.z += func_00388978(func_00389410((f32)((D_L23_001DECC0 + v->x78) % v->x74) / (f32)v->x74 * 6.2831855f)) * v->x70;
    *(V4 *)(a0 + 0x10) = b;
    vec_sub_ab(&d, &b, &a);
    func_003BF838(v->x30, &d, a0 + 0xF0, a0 + 0xF0);
}
/* localdecomp:end func_L23_003B5D78 */

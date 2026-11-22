#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct Moby Moby;
typedef struct {
    u8 pad0[0x29C];
    s32 field_29C;
    u8 pad2A0[0x5C];
    s32 count;
    s32 field_300;
    s32 field_304;
    u8 pad308[8];
    Moby *items[1];
} Vars;
typedef struct {
    u8 pad0[0x354];
    s32 field_354;
    u8 pad358[8];
    Vec4 pos;
} VarsB;
struct Moby {
    u8 pad0[0x10];
    Vec4 pos;
    u8 field_20;
    u8 pad21[0x47];
    void *pVar;
};
typedef int u128_3F1460 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec4_003F1538;

/* localdecomp:start func_L40_003F21B8 */
#include "vu0.h"
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
__asm__(".extern D_L40_0025B9A0, 16");
extern vu0_v4 D_L40_0025B9A0;

f32 func_L40_003F21B8(vu0_v4 *p0, vu0_v4 *p1, s32 a2, u8 *a3, f32 angle) {
    vu0_v4 d0, d1, e1, f1, e0, f0;
    f32 len;

    d0 = *(vu0_v4 *)(a3 + 0xD0);
    d1 = d0;
    len = func_0038CF00(p0, p1);
    if (func_003D3CB0(p0, p1, a2, a3, 0) == 0) {
        func_0038CF68(&d0, &d0, angle);
        vec_add_ba(&e0, &d0, p0);
        vec_add_ba(&e1, &d0, p1);
        if (func_003D3CB0(&e0, &e1, a2, a3, 0) == 0) {
            func_0038CF68(&d1, &d1, -angle);
            vec_add_ba(&f0, &d1, p0);
            vec_add_ba(&f1, &d1, p1);
            if (func_003D3CB0(&f0, &f1, a2, a3, 0) == 0) {
                return 1.0f;
            }
        }
    }
    do { do { return func_0038CF00(p0, &D_L40_0025B9A0) / len; } while (0); } while (0);
}
/* localdecomp:end func_L40_003F21B8 */

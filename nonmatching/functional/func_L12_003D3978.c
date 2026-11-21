/* functional: high. Hand-written from PAL assembly; needs -mvu0-use-vf0-vf2 for vec_sub_ba (file flags spill vf17), otherwise the only diff is nothing. The first store to +0x274 is retail's delay-slot store of the earlier result before the second func_0038DAB8 call. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L12_003D3978 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D3978;
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_L01_0040E570(void *, void *);
extern f32 D_001DEEE4_sda;
extern f32 D_001DEF0C_sda;
extern f32 D_001DEF10_sda;
__asm__(".extern D_001DEEE4_sda, 4");
__asm__(".extern D_001DEF0C_sda, 4");
__asm__(".extern D_001DEF10_sda, 4");

void func_L12_003D3978(u8 *obj, u8 *p) {
    V4_003D3978 t;
    V4_003D3978 q;
    V4_003D3978 d;
    f32 k;
    f32 r;
    f32 dist;

    if (*(s16 *)(p + 0x14C) != 0) {
        k = 0.017453292f;
        func_003C2F58(obj, 1, &t);
        q = *(V4_003D3978 *)(p + 0x130);
        vec_sub_ba(&d, &q, &t);
        r = func_0038D160(d.x, d.y);
        r = func_0038DAB8(r, D_001DEEE4_sda * k);
        *(f32 *)(p + 0x274) = r;
        *(f32 *)(p + 0x274) = func_0038DAB8(r, *(f32 *)(p + 0x27C));
        dist = func_L01_0040E570(obj + 0x10, &q);
        if (dist < D_001DEF10_sda * D_001DEF10_sda) {
            r = -func_0038D160(func_0038CED8(&d), d.z);
        } else {
            r = -func_0038D160(func_0038CED8(&d), d.z);
            r = func_0038DAB8(r, D_001DEF0C_sda * k);
        }
        *(f32 *)(p + 0x278) = r;
    }
}
/* localdecomp:end func_L12_003D3978 */

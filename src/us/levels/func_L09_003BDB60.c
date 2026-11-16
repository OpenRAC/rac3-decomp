#include "common.h"

/* NTSC-U counterpart of func_L09_003BF3E0 (src/levels/09_tyhrranosis/L09_003BF3E0.c) */
#include "vu0.h"
extern u8 *D_L09_001E011C;

/* localdecomp:start func_L09_003BDB60 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BF3E0;

typedef struct {
    u8 pad0[0x80];
    f32 x80;
    f32 x84;
} Hero_003BF3E0;
extern Hero_003BF3E0 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern u8 D_L09_001D66B0_003BDB60;
__asm__(".extern D_L09_001D66B0_003BDB60, 16");
extern f32 func_003893C8(f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern void func_003BEA80(void *, void *);

void func_L09_003BDB60(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    V4_003BF3E0 v;
    u8 *e;
    f32 a;

    e = D_L09_001E011C + (*(s32 *)(p + 0xCD0) << 8);
    v = *(V4_003BF3E0 *)&D_L09_001D66B0_003BDB60;
    v.y = -0.017453292f;
    v.x = *(f32 *)(p + 0xCDC);
    a = func_003893C8(*(f32 *)(a0 + 0xF8), 1.5707964f);
    if (*(s8 *)(p + 0xD2F) == -1) {
        a = func_003893C8(func_00389380(func_00388A28(D_001A4BE0.x80 - *(f32 *)(e + 0x10),
                                                      D_001A4BE0.x84 - *(f32 *)(e + 0x14)),
                                        3.1415927f),
                          a);
        func_L01_00445758(&v, a, p + 0xCD8, 0.0034906587097793818f, 0.0034906587097793818f, 0.024725498631596565f, *(s8 *)(p + 0xD2F));
        if (func_00389468(v.x, a) < 0.017453292f) {
            s8 old = *(s8 *)(p + 0xD2F);
            *(s8 *)(p + 0xD2F) = 1;
            if (old != 1) {
                p[0xD2E]++;
            }
        }
    } else {
        a = func_003893C8(func_00388A28(D_001A4BE0.x80 - *(f32 *)(e + 0x10),
                                        D_001A4BE0.x84 - *(f32 *)(e + 0x14)),
                          a);
        func_L01_00445758(&v, a, p + 0xCD8, 0.0034906587097793818f, 0.0034906587097793818f, 0.024725498631596565f, *(s8 *)(p + 0xD2F));
        if (func_00389468(v.x, a) < 0.017453292f) {
            s8 old = *(s8 *)(p + 0xD2F);
            *(s8 *)(p + 0xD2F) = -1;
            if (old != -1) {
                p[0xD2E]++;
            }
        }
    }
    *(f32 *)(p + 0xCDC) = v.x;
    func_003BEA80(p + 0xC50, &v);
}
/* localdecomp:end func_L09_003BDB60 */

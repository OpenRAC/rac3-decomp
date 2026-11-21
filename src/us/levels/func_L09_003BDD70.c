#include "common.h"

/* NTSC-U counterpart of func_L09_003BF5F0 (src/levels/09_tyhrranosis/L09_003BF3E0.c): 0.0432 -> 0.03; 0.432 -> 0.3; 0.0418879 -> 0.0349066 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L09_001E011C;
typedef struct {
    u8 pad0[0x80];
    f32 x80;
    f32 x84;
} Hero_003BF3E0;
extern Hero_003BF3E0 D_001A4BE0;
extern f32 func_00388A28(f32, f32);

/* localdecomp:start func_L09_003BDD70 */
extern u128_t D_L09_001DE770 __attribute__((section(".sdata")));
__asm__(".extern D_L09_001DE770, 4");
extern vu0_v4 D_L09_001D9BA0 __attribute__((section(".sdata")));
extern void func_L01_003E94A0(s32, void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_004455F0(void *, f32, void *, f32, f32, f32, s32);
extern void func_L01_003E9510(s32, void *);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_00389158(void *, void *, void *, f32);

void func_L09_003BDD70(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e = D_L09_001E011C + (*(s32 *)(p + 0xCD0) << 8);
    vu0_v4 t, a, b;
    u8 *h;
    f32 d, s, r, dist;

    *(u16 *)(e + 0x34) &= 0xFFF9;
    *(u128_t *)&t = *(u128_t *)(a0 + 0x10);
    func_L01_003E94A0(0, &t);
    *(f32 *)(p + 0xD60) = 0.0f;
    r = func_00388800(a0 + 0x10, (u8 *)&D_001A4BE0 + 0xD0);
    h = (u8 *)&D_001A4BE0;
    func_L01_004455F0(p + 0xD64, -func_00388A28(r, *(f32 *)(h + 0xD8) - *(f32 *)(a0 + 0x18)),
        p + 0xD74, 0.0299999993f, 0.300000012f, 0.0349065885f, 0);
    func_L01_004455F0(p + 0xD68,
        func_00388A28(*(f32 *)(h + 0xD0) - *(f32 *)(a0 + 0x10),
                      *(f32 *)(h + 0xD4) - *(f32 *)(a0 + 0x14)),
        p + 0xD78, 0.0299999993f, 0.300000012f, 0.0349065885f, 0);
    *(f32 *)(p + 0xD6C) = 0.0f;
    func_L01_003E9510(0, p + 0xD60);
    *(u128_t *)&a = *(u128_t *)(a0 + 0x10);
    *(u128_t *)&b = D_L09_001DE770;
    d = 0.0f;
    if (*(f32 *)(h + 0x88) < 332.0f)
        d = 332.0f - *(f32 *)(h + 0x88);
    s = 0.0f;
    dist = func_00388800(a0 + 0x10, h + 0x80) - d;
    if (dist <= -5.0f)
        s = -1.3f;
    else if (dist >= 15.0f)
        s = 1.3f;
    else
        s = func_003BE6A8(0.0f, 1.3f, (dist - -5.0f) / 20.0f) * 2.0f - 1.3f;
    b.x *= s;
    b.y *= s;
    func_00389158(&b, &b, &D_L09_001D9BA0, *(f32 *)(p + 0xD68));
    vec_add_ab(&a, &a, &b);
    *(u128_t *)(e + 0x10) = *(u128_t *)&a;
    *(f32 *)(e + 0xF8) = *(f32 *)(p + 0xD68);
}
/* localdecomp:end func_L09_003BDD70 */

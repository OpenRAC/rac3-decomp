#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L09_003BF2F8.c, which this file was cut from */
extern u8 *D_L09_001E009C;

/* localdecomp:start func_L09_003BF3E0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BF3E0;

typedef struct {
    u8 pad0[0x80];
    f32 x80;
    f32 x84;
} Hero_003BF3E0;
extern Hero_003BF3E0 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern u8 D_001D66B0;
__asm__(".extern D_001D66B0, 16");
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_003C3FC0(void *, void *);

void func_L09_003BF3E0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    V4_003BF3E0 v;
    u8 *e;
    f32 a;

    e = D_L09_001E009C + (*(s32 *)(p + 0xCD0) << 8);
    v = *(V4_003BF3E0 *)&D_001D66B0;
    v.y = -0.017453292f;
    v.x = *(f32 *)(p + 0xCDC);
    a = func_0038DB00(*(f32 *)(a0 + 0xF8), 1.5707964f);
    if (*(s8 *)(p + 0xD2F) == -1) {
        a = func_0038DB00(func_0038DAB8(func_0038D160(D_001A4BE0.x80 - *(f32 *)(e + 0x10),
                                                      D_001A4BE0.x84 - *(f32 *)(e + 0x14)),
                                        3.1415927f),
                          a);
        func_L01_00448890(&v, a, p + 0xCD8, 0.0050265486f, 0.0050265486f, 0.029670598f, *(s8 *)(p + 0xD2F));
        if (func_0038DBA0(v.x, a) < 0.017453292f) {
            s8 old = *(s8 *)(p + 0xD2F);
            *(s8 *)(p + 0xD2F) = 1;
            if (old != 1) {
                p[0xD2E]++;
            }
        }
    } else {
        a = func_0038DB00(func_0038D160(D_001A4BE0.x80 - *(f32 *)(e + 0x10),
                                        D_001A4BE0.x84 - *(f32 *)(e + 0x14)),
                          a);
        func_L01_00448890(&v, a, p + 0xCD8, 0.0050265486f, 0.0050265486f, 0.029670598f, *(s8 *)(p + 0xD2F));
        if (func_0038DBA0(v.x, a) < 0.017453292f) {
            s8 old = *(s8 *)(p + 0xD2F);
            *(s8 *)(p + 0xD2F) = -1;
            if (old != -1) {
                p[0xD2E]++;
            }
        }
    }
    *(f32 *)(p + 0xCDC) = v.x;
    func_003C3FC0(p + 0xC50, &v);
}
/* localdecomp:end func_L09_003BF3E0 */

/* localdecomp:start func_L09_003BF5F0 */
extern u128_t D_L09_001DE730 __attribute__((section(".sdata")));
__asm__(".extern D_L09_001DE730, 4");
extern vu0_v4 D_L09_001D9B60 __attribute__((section(".sdata")));
extern void func_L01_003EB350(s32, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
extern void func_L01_003EB3C0(s32, void *);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_0038D890(void *, void *, void *, f32);

void func_L09_003BF5F0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e = D_L09_001E009C + (*(s32 *)(p + 0xCD0) << 8);
    vu0_v4 t, a, b;
    u8 *h;
    f32 d, s, r, dist;

    *(u16 *)(e + 0x34) &= 0xFFF9;
    *(u128_t *)&t = *(u128_t *)(a0 + 0x10);
    func_L01_003EB350(0, &t);
    *(f32 *)(p + 0xD60) = 0.0f;
    r = func_0038CF38(a0 + 0x10, (u8 *)&D_001A4BE0 + 0xD0);
    h = (u8 *)&D_001A4BE0;
    func_L01_00448728(p + 0xD64, -func_0038D160(r, *(f32 *)(h + 0xD8) - *(f32 *)(a0 + 0x18)),
        p + 0xD74, 0.0432f, 0.43200004f, 0.041887905f, 0);
    func_L01_00448728(p + 0xD68,
        func_0038D160(*(f32 *)(h + 0xD0) - *(f32 *)(a0 + 0x10),
                      *(f32 *)(h + 0xD4) - *(f32 *)(a0 + 0x14)),
        p + 0xD78, 0.0432f, 0.43200004f, 0.041887905f, 0);
    *(f32 *)(p + 0xD6C) = 0.0f;
    func_L01_003EB3C0(0, p + 0xD60);
    *(u128_t *)&a = *(u128_t *)(a0 + 0x10);
    *(u128_t *)&b = D_L09_001DE730;
    d = 0.0f;
    if (*(f32 *)(h + 0x88) < 332.0f)
        d = 332.0f - *(f32 *)(h + 0x88);
    s = 0.0f;
    dist = func_0038CF38(a0 + 0x10, h + 0x80) - d;
    if (dist <= -5.0f)
        s = -1.3f;
    else if (dist >= 15.0f)
        s = 1.3f;
    else
        s = func_003C3BE8(0.0f, 1.3f, (dist - -5.0f) / 20.0f) * 2.0f - 1.3f;
    b.x *= s;
    b.y *= s;
    func_0038D890(&b, &b, &D_L09_001D9B60, *(f32 *)(p + 0xD68));
    vec_add_ab(&a, &a, &b);
    *(u128_t *)(e + 0x10) = *(u128_t *)&a;
    *(f32 *)(e + 0xF8) = *(f32 *)(p + 0xD68);
}
/* localdecomp:end func_L09_003BF5F0 */

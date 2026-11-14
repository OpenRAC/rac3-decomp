#include "common.h"

/* NTSC-U counterpart of func_L39_00532FE0 (src/levels/shared/L39_00532FE0.c): 0.94 -> 0.783333; 0.008 -> 0.00555556; 50 -> 60 */
/* localdecomp:start func_L39_00532968 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

__asm__(".extern D_L39_0024AE00, 4");
extern f32 D_L39_0024AE00;
__asm__(".extern D_L39_0024AE04, 4");
extern f32 D_L39_0024AE04;
__asm__(".extern D_L39_0024AE08, 4");
extern f32 D_L39_0024AE08;
__asm__(".extern D_L39_0024AE0C, 4");
extern f32 D_L39_0024AE0C;
__asm__(".extern D_L39_0024AE10, 4");
extern f32 D_L39_0024AE10;
extern f32 func_00389380(f32, f32);
extern void func_00389018(void *, s32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_00388398(void *);
extern void func_003BD9A0(void *, s32, void *);
extern s32 func_L39_005FC5C0(f32, void *, void *, void *, void *, void *, void *, s32, s32, s32, s32);
extern u8 *func_L39_0054CB98(s32, void *, void *, s32, s32, s32);
extern s32 func_L39_0066B708(void *, s32, void *, s32, void *);

void func_L39_00532968(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *g = *(u8 **)(*(u8 **)(p + 0x160) + 0x2D8);
    u128_t mtx[4];
    u128_t pos[1];
    u128_t dir;
    f32 v;
    f32 r;
    f32 k;
    u8 *q;

    v = *(f32 *)(*(u8 **)(g + 0x2534) + 0x100);
    v = v * fabs_asm(v);
    r = func_00389380(*(f32 *)(p + 0x150), v * D_L39_0024AE00);
    k = D_L39_0024AE04;
    *(f32 *)(p + 0x150) = r;
    if (r > k) {
        *(f32 *)(p + 0x150) = k;
    }
    if (*(f32 *)(p + 0x150) < -D_L39_0024AE04) {
        *(f32 *)(p + 0x150) = -D_L39_0024AE04;
    }
    func_00389018(p + 0x80, 2, *(f32 *)(p + 0x150));

    v = *(f32 *)(*(u8 **)(g + 0x2534) + 0x104);
    if (fabs_asm(v) < 0.07f) {
        v = 0.0f;
    } else {
        v = (v - 0.07f) / 0.93f;
    }
    v = v * fabs_asm(v);
    r = func_00389380(*(f32 *)(p + 0x154), v * D_L39_0024AE10);
    k = D_L39_0024AE08;
    *(f32 *)(p + 0x154) = r;
    if (r > k) {
        *(f32 *)(p + 0x154) = k;
    }
    if (*(f32 *)(p + 0x154) < D_L39_0024AE0C) {
        *(f32 *)(p + 0x154) = D_L39_0024AE0C;
    }
    q = p + 0x120;
    func_00389018(p + 0xC0, 1, *(f32 *)(p + 0x154));

    func_003BD9A0(a0, 2, mtx);
    pos[0] = mtx[3];
    func_003886E8(&dir, mtx, 0.783333361f);
    *(s32 *)(p + 0x164) = func_L39_005FC5C0(0.00555555569f, g, pos, &dir, q, p + 0x130, a0, 0, 0, 0, 0);
    func_00388398(p + 0x168);
    if (*(s32 *)(p + 0x168) <= 0) {
        if ((*(s32 *)(*(u8 **)(g + 0x2534) + 0x1A4) & 0x28) != 0) {
            func_L39_0066B708(g, 5, func_L39_0054CB98((s32)a0, pos, &dir, 0, (s32)a0, (s32)g), 0, q);
            *(s32 *)(p + 0x168) = 0x3C;
        }
    }
}
/* localdecomp:end func_L39_00532968 */

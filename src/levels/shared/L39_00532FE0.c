#include "common.h"

/* localdecomp:start func_L39_00532FE0 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

__asm__(".extern D_L39_0024ACF0, 4");
extern f32 D_L39_0024ACF0;
__asm__(".extern D_L39_0024ACF4, 4");
extern f32 D_L39_0024ACF4;
__asm__(".extern D_L39_0024ACF8, 4");
extern f32 D_L39_0024ACF8;
__asm__(".extern D_L39_0024ACFC, 4");
extern f32 D_L39_0024ACFC;
__asm__(".extern D_L39_0024AD00, 4");
extern f32 D_L39_0024AD00;
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D750(void *, s32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C2EC0(void *, s32, void *);
extern s32 func_L39_005FED60(f32, void *, void *, void *, void *, void *, void *, s32, s32, s32, s32);
extern u8 *func_L39_0054D4B0(s32, void *, void *, s32, s32, s32);
extern s32 func_L39_0066E010(void *, s32, void *, s32, void *);

void func_L39_00532FE0(u8 *a0) {
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
    r = func_0038DAB8(*(f32 *)(p + 0x150), v * D_L39_0024ACF0);
    k = D_L39_0024ACF4;
    *(f32 *)(p + 0x150) = r;
    if (r > k) {
        *(f32 *)(p + 0x150) = k;
    }
    if (*(f32 *)(p + 0x150) < -D_L39_0024ACF4) {
        *(f32 *)(p + 0x150) = -D_L39_0024ACF4;
    }
    func_0038D750(p + 0x80, 2, *(f32 *)(p + 0x150));

    v = *(f32 *)(*(u8 **)(g + 0x2534) + 0x104);
    if (fabs_asm(v) < 0.07f) {
        v = 0.0f;
    } else {
        v = (v - 0.07f) / 0.93f;
    }
    v = v * fabs_asm(v);
    r = func_0038DAB8(*(f32 *)(p + 0x154), v * D_L39_0024AD00);
    k = D_L39_0024ACF8;
    *(f32 *)(p + 0x154) = r;
    if (r > k) {
        *(f32 *)(p + 0x154) = k;
    }
    if (*(f32 *)(p + 0x154) < D_L39_0024ACFC) {
        *(f32 *)(p + 0x154) = D_L39_0024ACFC;
    }
    q = p + 0x120;
    func_0038D750(p + 0xC0, 1, *(f32 *)(p + 0x154));

    func_003C2EC0(a0, 2, mtx);
    pos[0] = mtx[3];
    func_0038CE20(&dir, mtx, 0.94000006f);
    *(s32 *)(p + 0x164) = func_L39_005FED60(0.008f, g, pos, &dir, q, p + 0x130, a0, 0, 0, 0, 0);
    func_0038CAD0(p + 0x168);
    if (*(s32 *)(p + 0x168) <= 0) {
        if ((*(s32 *)(*(u8 **)(g + 0x2534) + 0x1A4) & 0x28) != 0) {
            func_L39_0066E010(g, 5, func_L39_0054D4B0((s32)a0, pos, &dir, 0, (s32)a0, (s32)g), 0, q);
            *(s32 *)(p + 0x168) = 0x32;
        }
    }
}
/* localdecomp:end func_L39_00532FE0 */

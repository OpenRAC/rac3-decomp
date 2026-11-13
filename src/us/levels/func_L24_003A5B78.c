#include "common.h"

/* NTSC-U counterpart of func_L24_003A7750 (src/levels/24_insomniac_museum/L24_003A76B8.c) */
#include "vu0.h"

/* localdecomp:start func_L24_003A5B78 */
typedef struct {
    u8 pad0[0x14];
    f32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    f32 f24;
    f32 f28;
    u8 pad2C[4];
} S_3A7750;
extern S_3A7750 D_L24_002B9460_003A5B78[];
extern u8 *D_L24_001DF51C_003A5B78;
extern void func_003886C0(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L07_003E1EA0(void *, void *, void *, s32, s32, s32, f32, f32, f32);

void func_L24_003A5B78(u8 *a0, u8 *a1) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 f21 = 8.0f;
    f32 f20 = 0.6f;
    u8 *tab = D_L24_001DF51C_003A5B78;
    s32 n;
    *(vu0_q *)c = *(vu0_q *)(tab + (*(s32 *)(a1 + 0x988) << 8) + 0x10);
    *(vu0_q *)a = *(vu0_q *)(a0 + 0x10);
    a[2] += 3.5f;
    func_003886C0(b, a0 + 0xC0, a0 + 0xE0, *(f32 *)(a1 + 0x98C));
    func_00388830(b, b, 0.10000001f);
    n = *(s32 *)(a1 + 0x980);
    if (n != 0) {
        f32 s = D_L24_002B9460_003A5B78[n - 1].f28;
        f21 = s * f21;
        f20 = s * f20;
    }
    func_L07_003E1EA0(a0, a, b, 0x10001, 0x1F4, 0, f21, f20, -0.0016666667f);
}
/* localdecomp:end func_L24_003A5B78 */

#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L24_003A76B8 */
void func_L24_003A76B8(void *a0, u8 *p, s32 a2, s32 a3)
{
    if (a3 == -1 || a2 == 1) {
        f32 v = *(f32 *)(p + 0x98C) + 0.01f;
        *(f32 *)(p + 0x98C) = v;
        if (v > 0.9f) {
            *(f32 *)(p + 0x98C) = 0.9f;
        }
    }
    if (a2 == -1 || a3 == 1) {
        f32 v = *(f32 *)(p + 0x98C) - 0.01f;
        *(f32 *)(p + 0x98C) = v;
        if (v < 0.5f) {
            *(f32 *)(p + 0x98C) = 0.5f;
        }
    }
}
/* localdecomp:end func_L24_003A76B8 */

/* localdecomp:start func_L24_003A7750 */
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
extern S_3A7750 D_L24_002B9460[];
extern u8 *D_L24_001DF51C;
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L07_003E3C90(void *, void *, void *, s32, s32, s32, f32, f32, f32);

void func_L24_003A7750(u8 *a0, u8 *a1) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 f21 = 8.0f;
    f32 f20 = 0.6f;
    u8 *tab = D_L24_001DF51C;
    s32 n;
    *(vu0_q *)c = *(vu0_q *)(tab + (*(s32 *)(a1 + 0x988) << 8) + 0x10);
    *(vu0_q *)a = *(vu0_q *)(a0 + 0x10);
    a[2] += 3.5f;
    func_0038CDF8(b, a0 + 0xC0, a0 + 0xE0, *(f32 *)(a1 + 0x98C));
    func_0038CF68(b, b, 0.120000005f);
    n = *(s32 *)(a1 + 0x980);
    if (n != 0) {
        f32 s = D_L24_002B9460[n - 1].f28;
        f21 = s * f21;
        f20 = s * f20;
    }
    func_L07_003E3C90(a0, a, b, 0x10001, 0x1A1, 0, f21, f20, -0.0024f);
}
/* localdecomp:end func_L24_003A7750 */

/* localdecomp:start func_L24_003A7870 */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L24_003A7870(u8 *a0, u8 *a1, s32 a2) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 f20;
    f32 f1;
    *(vu0_q *)a = *(vu0_q *)(D_L24_001DF51C + (*(s32 *)(a1 + 0x988) << 8) + 0x10);
    vec_sub_ab(b, c, a);
    f20 = func_0038DB00(func_0038D160(b[0], b[1]), *(f32 *)(a0 + 0xF8));
    f1 = -func_0038D160(func_0038CED8(b), b[2]);
    if (f20 > 1.5707964f) {
        f20 = 1.5707964f;
    } else if (f20 < -1.5707964f) {
        f20 = -1.5707964f;
    }
    if (f1 > 0.5235988f) {
        f1 = 0.5235988f;
    } else if (f1 < -0.5235988f) {
        f1 = -0.5235988f;
    }
    qzero(a1 + 0x9F0);
    *(f32 *)(a1 + 0x2A4) = f1;
    *(f32 *)(a1 + 0x2A8) = f20 * 0.5f;
    if (a2 != 0) {
        *(f32 *)(a1 + 0x9F8) = -0.20943952f;
    }
    func_L01_0044E850(a0, a1 + 0x990, 3, 0.0432f, 0.43200004f);
}
/* localdecomp:end func_L24_003A7870 */

/* localdecomp:start func_L24_003A79F0 */
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L01_003B1750(u8 *, void *, void *, f32, s32, s32, s32, f32, s32);

void func_L24_003A79F0(u8 *a0, u8 *a1) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    s32 n;
    *(vu0_q *)b = *(vu0_q *)(a0 + 0xC0);
    b[2] += -0.2f;
    func_003C2F58(a0, 1, a);
    n = *(s32 *)(a1 + 0x980);
    if (n != 0) {
        func_L01_003B1750(a0, a, b, D_L24_002B9460[n - 1].f14, D_L24_002B9460[n - 1].f18,
                          D_L24_002B9460[n - 1].f1C, D_L24_002B9460[n - 1].f20,
                          D_L24_002B9460[n - 1].f24, D_L24_002B9460[n - 1].f18);
    }
}
/* localdecomp:end func_L24_003A79F0 */

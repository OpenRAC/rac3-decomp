#include "common.h"

/* localdecomp:start func_L39_005607A0 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 f[4];
} __attribute__((aligned(16))) V_005607A0;
extern void func_0038CE20(void *out, void *in, f32 s);
extern f32 func_0038CE68(void *a, void *b);
extern void func_0038CE90(void *out, void *a, void *b);
void func_L39_005607A0(void *m, void *n) {
    V_005607A0 x;
    V_005607A0 y;
    V_005607A0 d;
    f32 t;

    *(u128_t *)&x = 0;
    *(u128_t *)&y = 0;
    x.f[0] = 1.0f;
    y.f[1] = 1.0f;
    func_0038CE20(&d, n, -1.0f);
    t = func_0038CE68(&x, &d);
    if (fabs_asm(t) > 0.98f) {
        func_0038CE90(m, &d, &y);
    } else {
        func_0038CE90(m, &d, &x);
    }
    func_0038CE90((u8 *)m + 16, m, &d);
    *(u128_t *)((u8 *)m + 32) = *(u128_t *)&d;
}
/* localdecomp:end func_L39_005607A0 */

INCLUDE_ASM("asm/levels", func_L39_00560868);

/* localdecomp:start func_L39_00560FC0 */
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_00560618(u8 *, u8 *, s32);
extern s32 func_L39_00560330(u8 *, u8 *);
extern s32 func_L39_00560220_00560FC0(s32);
extern void func_L39_00560308_00560FC0(s32);
extern s32 func_L39_005601F8_00560FC0(s32);
extern void func_L39_00560248_00560FC0(s32, s32);
extern void func_L39_00560290(u8 *);
extern s32 D_001A5DF8[];
extern u8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B43C, 4");
__asm__(".extern D_L39_0024B40C, 4");
extern s32 D_L39_0024B43C;
extern f32 D_L39_0024B40C;

s32 func_L39_00560FC0(u8 *a0, s32 a1) {
    u8 *q = *(u8 **)(a0 + 0x68);
    s32 i;
    u8 *p;
    if (a1 != 0) {
        *(s32 *)q = -1;
        *(u32 *)(q + 4) = 0xFFFFFFFF;
        *(s32 *)(q + 0xC) = D_001A5DF8[0];
        return 0;
    }
    switch (a0[0x20]) {
    case 0:
        return 0;
    case 1:
    case 2:
        if (*(s32 *)(q + 0xC) + D_L39_0024B43C < D_001A5DF8[0]) {
            func_L01_004450F0(a0, 4, -1);
            if (func_L39_00560220_00560FC0((s32)a0) == 0) {
                func_L39_00560308_00560FC0((s32)a0);
            }
            return 0;
        }
        for (i = 0; i < 8; i++) {
            p = D_L39_0024CE20[i];
            if (p != 0 && func_L01_0040E548(p + 0xA0, a0 + 0x10) < D_L39_0024B40C
                && (func_L39_00560618(p, a0, 1) != 0 || func_L39_00560330(p, a0) != 0)) {
                func_L39_00560248_00560FC0((s32)a0, *(s32 *)p);
                break;
            }
        }
        return 0;
    case 3:
        if (func_L01_004561B8(a0) != 0) {
            if (func_L39_005601F8_00560FC0((s32)a0) == 0) {
                func_L39_00560290(a0);
            }
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L39_00560FC0 */

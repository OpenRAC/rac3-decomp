#include "common.h"

/* localdecomp:start func_L39_00551F68 */
#include "vu0.h"

typedef int u128_00551F68 __attribute__((mode(TI)));

typedef struct {
    u128_00551F68 v0;
    vu0_v4 v10;
    u128_00551F68 v20;
    u128_00551F68 v30;
    u8 v40[0x10];
    s16 h50;
    s16 h52;
    s32 i54;
    s32 i58;
    f32 f5C;
} E_00551F68;

extern u8 D_L39_003C1020[];
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);

void func_L39_00551F68(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    E_00551F68 *e = (E_00551F68 *)D_L39_003C1020 + st[0x3A];
    vu0_v4 fwd;
    vu0_v4 up;
    vu0_v4 side;
    s32 count;

    func_0038CF68(&fwd, st, 1.0f);
    *(u128_00551F68 *)&up = 0;
    up.z = 1.0f;
    up.w = 1.0f;
    func_0038CE90(&side, &fwd, &up);
    func_0038CF68(&side, &side, 1.0f);
    func_0038CE90(e->v40, &side, &fwd);
    e->v30 = *(u128_00551F68 *)&fwd;
    e->v0 = *(u128_00551F68 *)(a0 + 0x10);
    vec_add_ab(&e->v10, a0 + 0x10, st);
    e->v20 = *(u128_00551F68 *)&e->v10;
    count = 0x21;
    e->h50 = 1;
    e->h52 = count;
    e->f5C = 1.0f / count;
    e->i58 = 0;
    e->i54 = 0;
}
/* localdecomp:end func_L39_00551F68 */

/* localdecomp:start func_L39_00552070 */
typedef int Q_552070 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_552070;
extern u8 D_L39_003C1020[];
extern s32 func_0038CB00(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);

s32 func_L39_00552070(u8 *a0) {
    V4_552070 v;
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *e = D_L39_003C1020 + st[0x3A] * 0x60;
    f32 f21;
    f32 f20;
    Q_552070 x, y;

    if (*(s16 *)(e + 0x50) == 0) {
        return 0;
    }
    if (func_0038CB00(e + 0x52) != 0) {
        *(s16 *)(e + 0x50) = 0;
        return 0;
    }
    *(Q_552070 *)(e + 0x20) = *(Q_552070 *)(a0 + 0x10);
    f21 = func_0038CF00(e, e + 0x20);
    f20 = func_0038CF00(e, e + 0x10);
    if (f21 < f20) {
        *(Q_552070 *)(e + 0x10) = *(Q_552070 *)(a0 + 0x10);
        f20 = 0.0f;
    } else {
        f20 = f21 - f20;
    }
    *(f32 *)(e + 0x54) += 0.05f;
    if (*(f32 *)(e + 0x54) >= 4.0f) {
        *(f32 *)(e + 0x54) -= 4.0f;
    }
    *(f32 *)(e + 0x58) += 0.075f;
    if (*(f32 *)(e + 0x58) >= 4.0f) {
        *(f32 *)(e + 0x58) -= 4.0f;
    }
    func_0038CF68(&v, st, 0.32000002f);
    func_L01_0040E6B8(&v, &v, f21);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_552070 *)(e + 0)));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_552070 *)(e + 0)) : "j"(x));
    func_L01_0040E6B8(&v, &v, f20);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_552070 *)(e + 16)));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_552070 *)(e + 16)) : "j"(x));
    return 1;
}
/* localdecomp:end func_L39_00552070 */

INCLUDE_ASM("asm/levels", func_L39_005521F8);

#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_00325BA0);

INCLUDE_ASM("asm/levels", func_L02_00325E90);

INCLUDE_ASM("asm/levels", func_L02_00326430);

INCLUDE_ASM("asm/levels", func_L02_00326520);

INCLUDE_ASM("asm/levels", func_L02_00326600);

INCLUDE_ASM("asm/levels", func_L02_00326878);

INCLUDE_ASM("asm/levels", func_L02_00326A80);

/* localdecomp:start func_L02_00326BD8 */
typedef struct {
    char pad0[0xB9];
    u8 done;
} State;

extern State D_001426E0;
extern s32 D_L02_001DC920;
extern s32 func_L01_004527A0(s32);
extern s32 func_L01_004527F0(s32);
extern void func_0039EF28(void);
extern void func_L01_00451F60(s32, s32, s32);

void func_L02_00326BD8(void) {
    s32 a;
    s32 b;
    s32 i;

    D_L02_001DC920++;
    if (D_001426E0.done == 0) {
        a = 0;
        b = 0;
        for (i = 0; i < 36; i++) {
            a += func_L01_004527A0(i);
            b += func_L01_004527F0(i);
        }
        if (a >= b) {
            D_001426E0.done = 1;
            func_0039EF28();
            func_L01_00451F60(4784, -1, 0);
        }
    }
}
/* localdecomp:end func_L02_00326BD8 */

INCLUDE_ASM("asm/levels", func_L02_00326C90);

/* localdecomp:start func_L02_00326FC0 */
typedef int u128_00326730 __attribute__((mode(TI)));
typedef union { u128_00326730 q; f32 f[4]; s32 w[4]; } V_00326730;

extern u128_00326730 D_L02_001E12A0[];
extern void func_0038CF68(V_00326730 *, V_00326730 *, f32);
extern void func_0038CE90(void *, V_00326730 *, V_00326730 *);

void func_L02_00326FC0(V_00326730 *v, void *a1) {
    V_00326730 t;
    v->q = D_L02_001E12A0[0];
    t.q = 0;
    v->w[2] = 0;
    t.f[2] = 1.0f;
    t.f[3] = 1.0f;
    v->f[3] = 1.0f;
    func_0038CF68(v, v, 1.0f);
    func_0038CE90(a1, v, &t);
}
/* localdecomp:end func_L02_00326FC0 */

INCLUDE_ASM("asm/levels", func_L02_00327038);

INCLUDE_ASM("asm/levels", func_L02_003278C0);

INCLUDE_ASM("asm/levels", func_L02_00327960);

INCLUDE_ASM("asm/levels", func_L02_00327B50);

/* localdecomp:start func_L02_00327C70 */
void func_L02_00327C70(f32 *v, f32 x, f32 y) {
    f32 a = v[0] + x;
    f32 b = v[1] + y;

    v[0] = a - (f32)(s32)a;
    v[1] = b - (f32)(s32)b;
}
/* localdecomp:end func_L02_00327C70 */

INCLUDE_ASM("asm/levels", func_L02_00327CC0);

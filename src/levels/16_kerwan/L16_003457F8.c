#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L16_003457F8);

INCLUDE_ASM("asm/levels", func_L16_003459A0);

/* localdecomp:start func_L16_00345AD0 */
typedef int u128_t __attribute__((mode(TI)));

extern f32 func_0038CF00(void *, void *);
extern u8 *D_L16_0021ED00[];
__asm__(".extern D_L16_0021ED00, 16");
extern f32 D_L16_00278200[];
__asm__(".extern D_L16_00278200, 16");
extern s32 D_L16_001DD1A4;
__asm__(".extern D_L16_001DD1A4, 4");

void func_L16_00345AD0(s32 a0) {
    u8 *p;
    s32 i;
    s32 j;
    u128_t t1;
    u128_t t2;

    if (a0 != D_L16_001DD1A4) {
        p = D_L16_0021ED00[a0];
        if (*(s32 *)p < 0x101) {
            for (i = 0; i < *(s32 *)p; i++) {
                t1 = *(u128_t *)(p + i * 16 + 0x10);
                j = (i + 1) % *(s32 *)p;
                t2 = *(u128_t *)(p + j * 16 + 0x10);
                D_L16_00278200[i] = func_0038CF00(&t1, &t2);
            }
            D_L16_001DD1A4 = a0;
        }
    }
}
/* localdecomp:end func_L16_00345AD0 */

INCLUDE_ASM("asm/levels", func_L16_00345BB0);

INCLUDE_ASM("asm/levels", func_L16_00345DE8);

INCLUDE_ASM("asm/levels", func_L16_00345E98);

INCLUDE_ASM("asm/levels", func_L16_00345F50);

/* localdecomp:start func_L16_00346010 */

extern void func_0038CE90(float *, float *, float *);
extern void func_0038CF68(float, float *, float *);

void func_L16_00346010(void *arg0, s32 arg1, void *arg2, f32 arg3) {
    s32 n;
    vu0_v4 cur, prev, next, vC, vB, vA;

    n = *(s32 *)arg0;
    cur = *(vu0_v4 *)((u8 *)arg0 + 0x10 + 16 * (arg1 % n));
    prev = *(vu0_v4 *)((u8 *)arg0 + 0x10 + 16 * ((arg1 + n - 1) % n));
    next = *(vu0_v4 *)((u8 *)arg0 + 0x10 + 16 * ((arg1 + 1) % n));
    vec_sub_ba(&vC, &next, &prev);
    *(u128_t *)&vB = 0;
    vB.z = 1.0f;
    func_0038CE90((float *)&vA, (float *)&vB, (float *)&vC);
    func_0038CF68(arg3, (float *)&vA, (float *)&vA);
    vec_add_ab(arg2, &cur, &vA);
}
/* localdecomp:end func_L16_00346010 */

INCLUDE_ASM("asm/levels", func_L16_00346100);

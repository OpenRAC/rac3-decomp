#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003629B8);

INCLUDE_ASM("asm/levels", func_L05_00362E38);

/* localdecomp:start func_L05_00362EE0 */
typedef int u128_361BA8 __attribute__((mode(TI)));
extern void func_L05_00362F30(u8 *a0, u128_361BA8 *a1);
extern void func_L05_00363110(u8 *a0, u128_361BA8 *a1);
void func_L05_00362EE0(u8 *a0) {
    u128_361BA8 tmp;
    u128_361BA8 *p = *(u128_361BA8 **)(a0 + 104);
    tmp = *p;
    func_L05_00362F30(a0, &tmp);
    tmp = *p;
    func_L05_00363110(a0, &tmp);
}
/* localdecomp:end func_L05_00362EE0 */

INCLUDE_ASM("asm/levels", func_L05_00362F30);

INCLUDE_ASM("asm/levels", func_L05_00363110);

/* localdecomp:start func_L05_00363330 */
extern void func_L01_003303B8(void *a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3,
                          f32 f12, f32 f13, f32 f14, f32 f15,
                          s32 s0, s32 s1, s32 s2, s32 s3, s32 s4, s32 s5, s32 s6, s32 s7,
                          s32 s8, s32 s9, s32 s10, s32 s11, s32 s12, s32 s13,
                          s32 s14, s32 s15, s32 s16, s32 s17);

void func_L05_00363330(void *a0) {
    func_L01_003303B8(a0, 0, 5, 5, 5, 5, 5, 0, 0.45f, 0.0f, 0.0f, 0.0f,
                  0, 1, 1, 0, 0, 1, 0x10000, 0,
                  0x38D024, 0x38D024, 0x38D024, 0x38D024, 0x38D024, 0x38D024,
                  0x7F38D024, 0x2838D024, 0x38D024, 0);
}
/* localdecomp:end func_L05_00363330 */

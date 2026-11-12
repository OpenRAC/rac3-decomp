#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L16_00434938 */
typedef int u128_t __attribute__((mode(TI)));

void func_L01_0040C7A0(void *, s32 *);
void func_003C4C18(void *, f32);
extern s32 D_L16_001D6C48;
__asm__(".extern D_L16_001D6C48, 4");
extern u8 D_L16_001EF3D0[];
extern u8 D_L16_001EFAB0[];

void func_L16_00434938(void *arg0) {
    void *var_s0;
    void *var_s1;
    s32 var_s2;
    u8 *tmp;

    var_s0 = D_L16_001EF3D0;
    do {
        *(s32 *)((u8 *)var_s0 + 0x20) = 0x7F7F2000;
        *(s32 *)((u8 *)var_s0 + 0x24) = 0x7F7F2000;
        *(s32 *)((u8 *)var_s0 + 0x28) = 0x7F505000;
        *(s32 *)((u8 *)var_s0 + 0x2C) = 0x7F505000;
        func_L01_0040C7A0(var_s0, &D_L16_001D6C48);
        var_s0 = (u8 *)var_s0 + 0xB0;
    } while ((s32) var_s0 < (s32) (D_L16_001EF3D0 + 0x6E0));

    if (arg0 != 0) {
        tmp = D_L16_001EFAB0;
        var_s1 = tmp + 0x10;
        var_s2 = 8;
        do {
            u128_t tmp = *(u128_t *)((u8 *)arg0 + 0x10);
            var_s2 = var_s2 - 1;
            *(u128_t *)var_s1 = tmp;
            func_003C4C18(var_s1, 50.0f);
            var_s1 = (u8 *)var_s1 + 0x10;
        } while (var_s2 >= 0);
    }
}
/* localdecomp:end func_L16_00434938 */

/* localdecomp:start func_L16_00434A00 */
void func_L01_0040C948(s32, void *);
extern s32 D_L16_001D6C48;
extern u8 D_L16_001EF3D0[];

void func_L16_00434A00(void) {
    void *var_s0;

    var_s0 = D_L16_001EF3D0;
    do {
        func_L01_0040C948((s32) var_s0, &D_L16_001D6C48);
        var_s0 += 0xB0;
    } while ((s32) var_s0 < (s32) (D_L16_001EF3D0 + 0x6E0));
}
/* localdecomp:end func_L16_00434A00 */

/* localdecomp:start func_L16_00434A50 */
extern u8 D_L16_001EFAB0[];
__asm__(".extern D_L16_001EFAB0, 16");

void func_L16_00434A50(void *a0, void *a1) {
    vu0_q tmp;

    tmp = *(vu0_q *)a1;
    vec_add_ab(D_L16_001EFAB0, (u8 *)a0 + 0x10, &tmp);
}
/* localdecomp:end func_L16_00434A50 */

INCLUDE_ASM("asm/levels", func_L16_00434A78);

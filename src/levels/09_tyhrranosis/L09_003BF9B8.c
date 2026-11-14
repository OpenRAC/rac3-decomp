#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L09_003BF2F8.c, which this file was cut from */
extern void func_0038CE20(void *, void *, f32);

/* localdecomp:start func_L09_003BF9B8 */
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
__asm__(".extern D_001A4C60, 16");
extern u8 D_001A4C60[];

s32 func_L09_003BF9B8(u8 *a0) {
    u8 *v = a0 + 0xC0;
    vu0_v4 buf[2];

    func_0038CE20(buf, v, 5.0f);
    vec_add_ba(buf, a0 + 0x10, buf);
    vec_sub_ba(&buf[1], buf, D_001A4C60);
    *(s32 *)((u8 *)buf + 0x18) = 0;
    return func_0038CE68(v, &buf[1]) > 0.0f;
}
/* localdecomp:end func_L09_003BF9B8 */

INCLUDE_ASM("asm/levels", func_L09_003BFA48);

INCLUDE_ASM("asm/levels", func_L09_003BFC90);

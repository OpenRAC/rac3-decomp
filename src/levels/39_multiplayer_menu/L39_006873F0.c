#include "common.h"

typedef struct { u8 pad0[0xF4]; u8 *p; } O_A;

INCLUDE_ASM("asm/levels", func_L39_006873F0);

INCLUDE_ASM("asm/levels", func_L39_00687450);

/* localdecomp:start func_L39_00687508 */
void func_L39_0069D1F8(void *, s32, s32, s32, u32, u8, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void func_L39_0069D260(void *s, u32 *p1, u8 *p2, u32 *p3, u32 *p4, u32 *p5,
                       u32 *p6, u32 *p7, u32 *p8, u32 *p9, u32 *p10, u32 *p11);
extern void func_L39_00687268(void *, s32);

s32 func_L39_00687508(void *a0, s32 a1, s32 a2, s32 a3, s32 a4, u32 *p5, u8 *p6, u32 *p7,
                      u32 *p8, u32 *p9, u32 *p10, u32 *p11, u32 *p12, u32 *p13, u32 *p14, u32 *p15)
{
    void *o = *(void **)((u8 *)a0 + 0x98);

    if (o != 0) {
        func_L39_0069D1F8(o, a2, a3, a4, *p5, *p6, *p7, *p8, *p9, *p10, *p11, *p12, *p13, *p14, *p15);
        func_L39_00687268(a0, 0xD);
        func_L39_0069D260(o, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
    }
    return 0;
}
/* localdecomp:end func_L39_00687508 */

/* localdecomp:start func_L39_00687640 */
extern void func_L39_006A04F8(void *, s32, s32, s32, s32, s32, s32, s32, u8, u8, u8, u8, u8);
extern void func_L39_00687268(void *, s32);

void func_L39_00687640(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, u8 s0, u8 s1, u8 s2, u8 s3, u8 s4) {
    void *p = *(void **)(a0 + 0x100);
    if (p != 0) {
        func_L39_006A04F8(p, a1, a2, a3, a4, a5, a6, a7, s0, s1, s2, s3, s4);
        func_L39_00687268(a0, 0x27);
    }
}
/* localdecomp:end func_L39_00687640 */

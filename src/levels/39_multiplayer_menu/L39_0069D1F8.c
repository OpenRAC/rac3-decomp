#include "common.h"

typedef struct S_0069D260 {
    u8 pad0[0x2B0];
    u32 f2B0;
    u32 f2B4;
    u32 f2B8;
    u32 f2BC;
    u32 f2C0;
    u32 f2C4;
    u32 f2C8;
    u32 f2CC;
    u8 pad1[0x4];
    u32 f2D4;
    u32 f2D8;
    u8 f2DC;
} S_0069D260;

INCLUDE_ASM("asm/levels", func_L39_0069D1F8);

/* localdecomp:start func_L39_0069D260 */
void func_L39_0069D260(S_0069D260 *s, u32 *p1, u8 *p2, u32 *p3, u32 *p4, u32 *p5,
                       u32 *p6, u32 *p7, u32 *p8, u32 *p9, u32 *p10, u32 *p11) {
    *p1 = s->f2B0;
    *p2 = s->f2DC;
    *p3 = s->f2D8;
    *p6 = s->f2BC;
    *p7 = s->f2D4;
    *p4 = s->f2B4;
    *p5 = s->f2B8;
    *p8 = s->f2C0;
    *p9 = s->f2C4;
    *p10 = s->f2C8;
    *p11 = s->f2CC;
}
/* localdecomp:end func_L39_0069D260 */

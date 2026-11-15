#include "common.h"

/* declared by functions of L32_003B5828.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L32_003B8390 */

extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004AA7E8(u8 *, s32);
extern f32 D_L32_001DEF90;
__asm__(".extern D_L32_001DEF90, 4");
extern f32 D_L32_001DEF8C;
__asm__(".extern D_L32_001DEF8C, 4");

u8 *func_L32_003B8390(u8 *a0, f32 f20, f32 f21) {
    u8 *o;
    u8 *p2;
    s32 *q;
    s32 i;

    o = func_003C24B0(0x1C96, 0x90);
    if (o == 0) {
        return 0;
    }
    *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
    *(s32 *)(o + 0x98) = 0;
    *(u8 *)(o + 0x30) = 0xFF;
    func_L01_004AA7E8(o, 1);
    *(u128_t *)(o + 0x10) = *(u128_t *)a0;
    p2 = *(u8 **)(o + 0x68);
    q = (s32 *)(p2 + 0x7C);
    i = 31;
    do {
        *q = 0;
        q--;
        i--;
    } while (i >= 0);
    *(f32 *)(p2 + 0x80) = (0.0f < f20) ? f20 : D_L32_001DEF90;
    *(f32 *)(p2 + 0x84) = (0.0f < f21) ? f21 : D_L32_001DEF8C;
    *(s32 *)(p2 + 0x88) = 1;
    return o;
}
/* localdecomp:end func_L32_003B8390 */

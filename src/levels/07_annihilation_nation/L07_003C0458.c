#include "common.h"

typedef struct Obj_003C0638 {
    s32 f0;
    s32 f4;
    f32 f8;
    u8 fC;
} Obj_003C0638;

INCLUDE_ASM("asm/levels", func_L07_003C0458);

/* localdecomp:start func_L07_003C0638 */
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_L07_001DE538, 4");
extern s32 D_L07_001DE538;
extern u8 *D_L07_001DF41C;
extern void func_L07_003DDA38(u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L07_003C0638(u8 *a0, s32 a1) {
    u8 b;
    Obj_003C0638 *o;
    u8 *p;
    u8 *base;

    b = a1;
    o = *(Obj_003C0638 **)(a0 + 0x68);
    o->fC = b;
    base = D_L07_001DF41C;
    *(s32 *)((u8 *)o + 0x10) = D_L07_001DE538;
    *(f32 *)(a0 + 0x18) = o->f8;
    p = base + (o->f0 << 8);
    p[0xBE] &= 0xFB;
    func_L07_003DDA38(p, b);
    if (o->f4 != -1) {
        p = D_L07_001DF41C + (o->f4 << 8);
        p[0xBE] &= 0xFB;
        func_L07_003DDA38(p, b);
    }
    func_L01_004450F0(a0, 2, -1);
}
/* localdecomp:end func_L07_003C0638 */

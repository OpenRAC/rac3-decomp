/* Vidcomic 2 animation draft: 112 differing words with the owning file's
 * current flags; 10 with @ps2as (not applied to the owning file).
 * Typed input/output fields reproduce the store ordering around the random
 * position update. Remaining under @ps2as: e/g occupy f26/f25 instead of
 * f25/f26, and the e+k sum is scheduled ahead of the position update.
 * Allocation priorities: e has 3 references over 109 instructions, g has
 * 2 over 70. Reusing the high-byte scale temporary, changing lexical scope,
 * moving the sum, and computing e after g did not resolve the mismatch.
 * Three formulations retained the same 10-word difference; parked here.
 */
#include "common.h"

/* localdecomp:start func_L33_00353540 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00353540;
extern f32 D_L33_001DDBF4;
__asm__(".extern D_L33_001DDBF4, 4");
extern f32 D_L33_001DDBF8;
__asm__(".extern D_L33_001DDBF8, 4");
extern f32 D_L33_001DDBFC;
__asm__(".extern D_L33_001DDBFC, 4");
extern f32 D_L33_001DDC00;
__asm__(".extern D_L33_001DDC00, 4");
extern f32 D_L33_001DDC08;
__asm__(".extern D_L33_001DDC08, 4");
extern f32 D_L33_001DDC10;
__asm__(".extern D_L33_001DDC10, 4");
extern f32 D_L33_001DDBE4;
__asm__(".extern D_L33_001DDBE4, 4");
extern f32 D_L33_001DDBD0;
__asm__(".extern D_L33_001DDBD0, 4");
extern s32 D_L33_001DDBE0;
__asm__(".extern D_L33_001DDBE0, 4");
extern s32 D_L33_001DDBDC;
__asm__(".extern D_L33_001DDBDC, 4");
extern s32 D_L33_001DDBD8;
__asm__(".extern D_L33_001DDBD8, 4");
extern s32 D_L33_001DDBD4;
__asm__(".extern D_L33_001DDBD4, 4");

typedef struct { s32 f0, f4; s8 f8; u8 pad9; s16 fA; f32 fC, f10, f14, f18, f1C; } Output_353540;
typedef struct { u8 *f0; s32 f4; s16 f8; u16 fA; u8 fC, padD; u16 fE; s32 f10; f32 f14; s32 f18, f1C; } Input_353540;
void func_L33_00353540(Output_353540 *a, Input_353540 *b) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_003C4088(f32, f32, f32);
    extern f32 func_L03_0034B148(f32, s32, s32);
    u8 *c;
    s32 on;
    u16 hw;
    f32 one, k, e, g, h, x, ang, rad;
    V_00353540 t;

    if (b == 0) {
        return;
    }
    c = b->f0;
    on = b->f4;
    if (c != 0 && on != 0) {
        hw = b->fE;
        k = D_L33_001DDBF4 * (f32)b->f8 * (f32)(hw >> 8) * 0.00390625f;
        e = (f32)(hw & 0xFF);
        g = func_003C4088(D_L33_001DDBFC, D_L33_001DDBF8, (f32)b->fC * 0.00390625f);
        if (b->fA & 1) {
            one = 1.0f;
            ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
            rad = func_003824E0(0.0f, *(f32 *)(c + 0xC) * 0.00048828125f);
            t.x = func_0038D098(ang) * rad;
            t.z = func_0038D0B0(ang) * rad;
            t.y = 0.0f;
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(*(V_00353540 *)&a->f10)
                    : "m"(t), "m"(*(V_00353540 *)(c + 0x10))
                    : "vf1", "vf2");
            a->f14 += func_003824E0(-D_L33_001DDC10, D_L33_001DDC10);
            b->f14 = func_003824E0(0.0f, D_L33_001DDC08);
            b->f18 = func_0038DBD8(D_L33_001DDBE0, D_L33_001DDBDC, func_003824E0(0.0f, one));
            b->f1C = func_0038DBD8(D_L33_001DDBD8, D_L33_001DDBD4, func_003824E0(0.0f, one));
        }
        b->f14 += D_L33_001DDBE4;
        h = e + k;
        a->f18 += b->f14;
        x = func_L03_0034B148(0.0f, a->fA, b->f8);
        a->fC = func_003C4088(D_L33_001DDC00, g, x);
        x = func_L03_0034B148(0.0f, a->fA, b->f8);
        a->f4 = func_0038DBD8(b->f18, b->f1C, x);
        x = func_L03_0034B148(D_L33_001DDBD0, b->f8 - a->fA, b->f8);
        a->f4 = (a->f4 & 0xFFFFFF) + ((s32)(x * 128.0f) << 24);
        x = func_L03_0034B148(0.0f, a->fA, b->f8);
        a->f8 = (s32)func_003C4088(e, h, x);
    }
}
/* localdecomp:end func_L33_00353540 */

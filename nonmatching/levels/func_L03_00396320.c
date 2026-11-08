/* near miss (level 3, Starship Phoenix): 77 differences with @ps2as needed for the inline float constants (L03_00395808.c has no @ps2as): the logic is right (two pre-loop spawn calls, then a do/while with two per iteration), register allocation only: retail keeps each spawn result in $a1 and c in $s3 with t in $f20 and a in $f21, the C uses $a2/$a0 and $s4 with the float roles swapped; a shared result local and a single float were worse (80-87) */
#include "common.h"

/* localdecomp:start func_L03_00396320 */
typedef struct { u8 pad0[2]; u8 b2; u8 pad1[5]; u8 b8; } S_00396320;
typedef struct { u8 pad[0x164]; u8 *p; } G_00396320;
extern S_00396320 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 D_L03_001D66B0_00396320[];
extern u8 *D_L03_0021F3FC_00396320[];
__asm__(".extern D_L03_0021F3FC_00396320, 16");
extern u8 D_L03_001D66B0_b_00396320[];
extern u8 *D_L03_0021F3FC_b_00396320[];
__asm__(".extern D_L03_0021F3FC_b_00396320, 16");
extern G_00396320 D_L03_0021F298;
void func_L03_00396320(void *arg) {
    f32 v[4];
    f32 t;
    f32 z = 0.0f;
    s32 c = 0;
    s32 i;
    S_00396320 *s;
    S_00396320 *s2;
    S_00396320 *s3;
    S_00396320 *s4;
    s = func_L01_0046FB40(arg, D_L03_001D66B0_00396320, 15, 0xFFFFFF, 1, 127, 127, 0, 840000.0f, 420000.0f, z);
    if (s) {
        c = s->b8 + 0x20;
        s->b2 = *D_L03_0021F3FC_00396320[0];
    }
    s2 = func_L01_0046FB40(arg, D_L03_001D66B0_b_00396320, 15, 0x40FF40, 1, 64, 32, 0, 1260000.0f, 1260000.0f, z);
    if (s2) {
        s2->b8 = c;
        s2->b2 = *D_L03_0021F3FC_b_00396320[0];
    }
    i = 19;
    do {
        s32 n, r;
        f32 a, b;
        t = (func_003824E0(-1.0f, 1.0f) + 4.0f) * 0.020000001f;
        a = func_00382538();
        b = func_00382538();
        func_00382760(v, t, a, b);
        n = func_00382498(-10, 10) + 30;
        t = func_003824E0(-0.4f, 0.4f) + 0.8f;
        r = func_00382468(2);
        s3 = func_L01_0046FB40(arg, v, n, 0x40FF40, r ? -1 : 1, 64, 32, 0, t * 210000.0f, t * 210000.0f, 0.00392f);
        if (s3) {
            s3->b2 = *D_L03_0021F298.p;
            c = s3->b8 + 0x20;
        }
        r = func_00382468(2);
        s4 = func_L01_0046FB40(arg, v, n, 0xF7F7F7, r ? -1 : 1, 48, 48, 0, t * 0.6f * 210000.0f, t * 0.6f * 210000.0f, 0.00392f);
        if (s4) {
            s4->b8 = c;
            s4->b2 = *D_L03_0021F298.p;
        }
    } while (--i >= 0);
}
/* localdecomp:end func_L03_00396320 */

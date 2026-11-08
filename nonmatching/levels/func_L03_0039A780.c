/* near miss (level 3, Starship Phoenix): 137 differences with @ps2as needed for the inline float constants (162 with the default assembler; L03_00399D30.c has no @ps2as): logic, call sequence, constants and the movn/movz selects match; retail puts each func_L01_0046FB40 result in $a1 where the C uses $a2 and computes f12 = f20*0.6f then f12 *= f22 keeping f20, the C multiplies in place; separate locals per call gave 127 */
#include "common.h"

/* localdecomp:start func_L03_0039A780 */
typedef struct {
    char pad0[2];
    u8 b2;
    char pad3[5];
    u8 b8;
} S_0039A780;
typedef struct {
    char pad[0x164];
    u8 *p164;
} T_0039A780;
extern S_0039A780 *func_L01_0046FB40(s32, void *, s32, s32, f32, f32, f32, s32, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538();
extern void func_00382760(f32 *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern s32 D_L03_001D66B0;
extern u8 *D_L03_0021F3FC;
extern u8 *D_L03_0021F3FC_b[];
extern T_0039A780 D_L03_0021F298;
__asm__(".extern D_L03_0021F3FC, 448");
__asm__(".extern D_L03_0021F3FC_b, 448");
__asm__(".extern D_L03_0021F298, 360");
__asm__(".extern D_L03_001D66B0, 448");

void func_L03_0039A780(s32 arg0) {
    f32 vec[4];
    f32 a, b, c;
    S_0039A780 *o;
    s32 col = 0;
    s32 i;
    s32 id;

    o = func_L01_0046FB40(arg0, &D_L03_001D66B0, 15, 0xFFFFFF, 420000.0f, 210000.0f, 0.0f, 1, 0x7F, 0x7F, 0);
    if (o != 0) {
        col = o->b8 + 0x20;
        o->b2 = *D_L03_0021F3FC_b[0];
    }
    o = func_L01_0046FB40(arg0, &D_L03_001D66B0, 15, 0x802020, 630000.0f, 630000.0f, 0.0f, 1, 0x40, 0x20, 0);
    if (o != 0) {
        o->b8 = col;
        o->b2 = *D_L03_0021F3FC;
    }
    for (i = 19; i >= 0; i--) {
        f32 s, x, y, r;
        s = (func_003824E0(-1.0f, 1.0f) + 4.0f) * 0.0200000014f;
        x = func_00382538();
        y = func_00382538();
        func_00382760(vec, s, x, y);
        id = func_00382498(-10, 10) + 30;
        r = func_003824E0(-0.4f, 0.4f) + 0.8f;
        o = func_L01_0046FB40(arg0, vec, id, 0x802020, r * 210000.0f, r * 210000.0f, 0.00392f, func_00382468(2) ? -1 : 1, 0x40, 0x20, 0);
        if (o != 0) {
            col = o->b8 + 0x20;
            o->b2 = *D_L03_0021F298.p164;
        }
        o = func_L01_0046FB40(arg0, vec, id, 0xF7F7F7, r * 0.6f * 210000.0f, r * 0.6f * 210000.0f, 0.00392f, func_00382468(2) ? -1 : 1, 0x30, 0x30, 0);
        if (o != 0) {
            o->b8 = col;
            o->b2 = *D_L03_0021F298.p164;
        }
    }
}
/* localdecomp:end func_L03_0039A780 */

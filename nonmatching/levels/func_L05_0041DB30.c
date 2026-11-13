/* near miss (level 5, Daxx), opus pass 2026-11-13: 61 differences (default assembler, the file's flags). Logic, globals and calls are right (the L02/L17 siblings func_L02_003FC828 / func_L17_003FF1F0 are the short form). Left: register allocation of the call-argument locals: retail gives d (the func_L03_004109D8 object) $a3 ahead of the D_L05_001E6A40 base ($t0), the constant 1 ($t1) and b ($t2); ours gives them $a3/$t0/$t1 and d $t2, and the case 0 macro lw of D_L05_001D6B74 is scheduled ahead of the divisor 6. All 120 declaration orders give 61. */
#include "common.h"

/* localdecomp:start func_L05_0041DB30 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_L05_002E92A0;
typedef struct { u8 p0[0x30]; s32 f30; s32 f34; } S_L05_001E6A40;
typedef struct { u8 p0[0x3C]; s32 f3C; } S_L05_002E9360;
extern f32 D_L05_001D6B44;
extern u8 D_L05_001D6AB0;
extern u8 D_L05_001D6AA5;
extern u8 D_L05_001D6AA4;
extern u8 D_L05_001D6B70;
extern s32 D_L05_001D6B74;
__asm__(".extern D_L05_001D6B74, 16");
extern u8 D_L05_001D6B88;
extern u8 D_L05_001D6BA0;
extern s32 D_L05_001D6BB8;
extern S_L05_002E92A0 D_L05_002E92A0;
extern S_L05_001E6A40 D_L05_001E6A40;
extern S_L05_002E9360 D_L05_002E9360;
extern u8 D_L05_002E92F0[];
extern u8 D_L05_002E93C0[];
extern u8 D_L05_002E9420[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L01_00423068(void *, void *, void *, s32, s32, s32, s32);
extern void func_L03_004109D8(void *, void *, void *, s32);

void func_L05_0041DB30(void) {
    void *a;
    void *b;
    void *c;
    void *d;
    s32 e;

    D_L05_001D6B44 = 1.0f;
    D_L05_002E92A0.f20 = &D_L05_001D6AB0;
    D_L05_002E92A0.f30 = 1;
    a = 0;
    c = 0;
    b = 0;
    d = 0;
    e = 0;
    D_L05_001D6AA5 = 0;
    if (D_001D545C == 5) {
        switch (D_L05_001E6A40.f30) {
        case 0:
            b = &D_L05_001D6B88;
            if (D_L05_001E6A40.f34 < (D_L05_001D6B74 * 5 + 2) / 6) b = &D_L05_001D6B70;
            d = D_L05_002E92F0;
            break;
        case 1:
            D_L05_001D6B44 = -1.0f;
            if (D_L05_001E6A40.f34 < (D_L05_002E9360.f3C * 5 + 2) / 6) a = &D_L05_002E9360;
            else a = D_L05_002E93C0;
            break;
        case 2:
            D_L05_001D6AA4 = 1;
            d = D_L05_002E9420;
            if (D_L05_001E6A40.f34 < (D_L05_001D6BB8 * 5 + 2) / 6) b = &D_L05_001D6BA0;
            else e = 1;
            c = &D_L05_001D6BB8;
            break;
        }
    }
    if (a != 0) {
        func_L01_00423068(a, b, c, e, 0, 1, 0);
    } else if (d != 0) {
        func_L03_004109D8(d, b, c, e);
    }
}
/* localdecomp:end func_L05_0041DB30 */

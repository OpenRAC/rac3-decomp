/* PAL near miss (Codex wave 11): near miss: 146 words differ in its file's context with the file's flags.
 * Replaces the earlier draft (shared-2 worker draft (2026-11-16): does not compile under tools/check.py in its file's context with the file's flags, measured 2026-11-21;
 * this one: 146).
 * Worker's note: 146 diff (W/func_L33_00353540.checks/level_33.log): file assembler blockers: li.s 6.2831855f becomes a gp literal-pool lwc1 (retail lui/ori/mtc1) and it adds a nop after both cvt.w.s/mfc1 pairs, so @ps2as is needed on L33_003534E0.c's line; compiler-side only (f32)(hw & 0xFF) in f26 and the lerp g in f25 where retail swaps them (draft's 6 wordings already tried, priority note in the draft) and beql/beqz at the c test; VU0 add now one asm block with m operands and vf1/vf2 clobbers (draft's volatile+memory form dropped)
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

void func_L33_00353540(u8 *a, u8 *b) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_003C4088(f32, f32, f32);
    extern f32 func_L03_0034B148(f32, s32, s32);
    u8 *c;
    u16 hw;
    f32 one, k, e, g, h, x, ang, rad;
    V_00353540 t;

    if (b == 0) {
        return;
    }
    c = *(u8 **)b;
    if (c != 0 && *(s32 *)(b + 4) != 0) {
        hw = *(u16 *)(b + 0xE);
        k = D_L33_001DDBF4 * (f32)*(s16 *)(b + 8) * (f32)(hw >> 8) * 0.00390625f;
        e = (f32)(hw & 0xFF);
        g = func_003C4088(D_L33_001DDBFC, D_L33_001DDBF8, (f32)*(u8 *)(b + 0xC) * 0.00390625f);
        if (*(u16 *)(b + 0xA) & 1) {
            one = 1.0f;
            ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
            rad = func_003824E0(0.0f, *(f32 *)(c + 0xC) * 0.00048828125f);
            t.x = func_0038D098(ang) * rad;
            t.z = func_0038D0B0(ang) * rad;
            t.y = 0.0f;
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(*(V_00353540 *)(a + 0x10))
                    : "m"(t), "m"(*(V_00353540 *)(c + 0x10))
                    : "vf1", "vf2");
            *(f32 *)(a + 0x14) += func_003824E0(-D_L33_001DDC10, D_L33_001DDC10);
            *(f32 *)(b + 0x14) = func_003824E0(0.0f, D_L33_001DDC08);
            *(s32 *)(b + 0x18) = func_0038DBD8(D_L33_001DDBE0, D_L33_001DDBDC, func_003824E0(0.0f, one));
            *(s32 *)(b + 0x1C) = func_0038DBD8(D_L33_001DDBD8, D_L33_001DDBD4, func_003824E0(0.0f, one));
        }
        *(f32 *)(b + 0x14) += D_L33_001DDBE4;
        h = e + k;
        *(f32 *)(a + 0x18) += *(f32 *)(b + 0x14);
        x = func_L03_0034B148(0.0f, *(s16 *)(a + 0xA), *(s16 *)(b + 8));
        *(f32 *)(a + 0xC) = func_003C4088(D_L33_001DDC00, g, x);
        x = func_L03_0034B148(0.0f, *(s16 *)(a + 0xA), *(s16 *)(b + 8));
        *(s32 *)(a + 4) = func_0038DBD8(*(s32 *)(b + 0x18), *(s32 *)(b + 0x1C), x);
        x = func_L03_0034B148(D_L33_001DDBD0, *(s16 *)(b + 8) - *(s16 *)(a + 0xA), *(s16 *)(b + 8));
        *(s32 *)(a + 4) = (*(s32 *)(a + 4) & 0xFFFFFF) + ((s32)(x * 128.0f) << 24);
        x = func_L03_0034B148(0.0f, *(s16 *)(a + 0xA), *(s16 *)(b + 8));
        *(s8 *)(a + 8) = (s32)func_003C4088(e, h, x);
    }
}
/* localdecomp:end func_L33_00353540 */

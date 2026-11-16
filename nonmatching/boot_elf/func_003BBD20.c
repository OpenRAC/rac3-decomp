/* PAL near miss (Codex wave 8): near miss: 10 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_003BBC48; 25 words differ under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 10).
 * Worker's note: 10/39 positional differences, size -4: backward bnez at +0x70 has no delay-slot nop, so jal 0013BED0 starts at +0x74 rather than +0x78. Best build/codex/w425/func_003BBD20.a01.log; do-while same; unsized arrays worse; fixed flags, no metadata.
 */
#include "common.h"
/* localdecomp:start func_003BBD20 */
extern u32 D_001D8CE0;
extern s32 D_001DA1F4_003BBD20[1];
__asm__(".extern D_001DA1F4_003BBD20, 16");
extern s32 D_001D4B4C_003BBD20;
__asm__(".extern D_001D4B4C_003BBD20, 16");
void func_003BBD20(void) {
    extern void func_0013CA20(void);
    extern void func_0013BF00(s32);
    extern void func_0013CA28(void);
    extern s32 func_0013B620(void);
    extern void func_0013BED0(void);
    u32 i;
    s32 *p;
    func_0013CA20();
    for (i = 1; i < D_001D8CE0; i++) {
        func_0013BF00(D_001DA1F4_003BBD20[i - 1]);
    }
    func_0013CA28();
    for (;;) {
        if (func_0013B620() == 0) break;
    }
    func_0013BED0();
    D_001D4B4C_003BBD20 = 0;
}
/* localdecomp:end func_003BBD20 */

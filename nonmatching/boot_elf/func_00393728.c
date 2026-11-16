/* PAL near miss (Codex wave 6): near miss: 56 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_00393668; 57 words differ under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 56).
 * Worker's note: Best 56 diff in func_00393728.attempt04.log: address-base allocation, mixed gp/lui counter access and stores. Later owner declares void func_00393728() but retail returns f64; needs owner contract repair. No flag changes.
 */
#include "common.h"
/* localdecomp:start func_00393728 */
struct S_38EC18;
__asm__(".extern D_001D5B94_00393728, 16");
extern s32 D_1D9E88;
__asm__(".extern D_1D9E88, 16");
s32 func_00393728(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    extern void func_00393830(struct S_38EC18 *);
    S_EB *p;
    s32 index = arg0 & 15;
    s32 flags;
    p = (S_EB *)((u8 *)D_00331AE0_00393728 + index * 0x90);
    flags = arg0 & 0xFFF0;
    if (D_001D5B94_00393728 == 5 && index != 2 && index != 0) return 0;
    if (p->f2C != a5 || p->f28 != a6 || p->f20 != a1 ||
        p->f24 != flags || p->f30 != a2 || p->f34 != a3 || p->f38 != a4) {
        s32 serial = D_001D9E88_00393728;
        p->f64 = serial;
        p->f2C = a5;
        p->f28 = a6;
        p->f20 = a1;
        p->f30 = a2;
        p->f34 = a3;
        p->f38 = a4;
        D_1D9E88 = serial + 1;
        p->f68 = 1;
        p->f24 = flags;
        p->f7C = 0;
        p->f70 = 0;
        if (flags & p->f4 & 0x20) func_00393830((struct S_38EC18 *)p);
    }
    return p->f64;
}
/* localdecomp:end func_00393728 */

/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "@ps2as -O2 -G8 -fopt-stack -mno-check-zero-division" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: byte-exact with --as ps2as (retail has 0.1f as lui/ori/mtc1, the file line has no @ps2as; with default as it is a gp literal); needs .extern D_L10_001D6C50, 4 under ps2as (D read into a local before the four stores, store source order 0x24, 0x2C, 0x20, 0x28); ...
 */
#include "common.h"

/* localdecomp:start func_L10_00407750 */
extern void func_003C2F58(void *, s32, void *);
extern void func_003C4C18(void *, f32);
extern void func_L01_0040C8A0(void *, void *);
extern s32 D_L10_001D6C50;
__asm__(".extern D_L10_001D6C50, 4");

void func_L10_00407750(void *obj, void *rec_) {
    u8 *rec = (u8 *)rec_;
    void *d;

    if (obj != 0) {
        func_003C2F58(obj, 0, rec);
        func_003C4C18(rec, 0.1f);
        func_003C2F58(obj, 1, rec + 0x10);
    }
    d = (void *)D_L10_001D6C50;
    *(s32 *)(rec + 0x24) = 0x7F7F7F7F;
    *(s32 *)(rec + 0x2C) = 0x7F7F2000;
    *(s32 *)(rec + 0x20) = 0x7F7F7F7F;
    *(s32 *)(rec + 0x28) = 0x7F7F2000;
    if (d != 0) {
        func_L01_0040C8A0(rec, d);
    }
}
/* localdecomp:end func_L10_00407750 */

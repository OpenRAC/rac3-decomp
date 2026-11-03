/* Draft from the NTSC decomp (commit 13cf5c5; THIRD_PARTY_NOTICES.md).
 * NTSC-U frontbin: 0x003B87B8..0x003B880B, 84 bytes.
 * Shared PAL name: func_003BDCB0; instructions agree apart from global addresses.
 * First pointer-based do/while draft: user check reports 13 differences,
 * with the right 84-byte size and loop shape but different setup/registers.
 * This uncompiled revision uses for-loop updates to test register lifetimes.
 * The earlier indexed draft needed -mno-split-addresses; this revision uses
 * the owning file's flags:
 * -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division.
 * Retail always writes ten slots, even when n is negative or greater than ten;
 * it saves n unchanged. The meanings of the entries, flags and v are unknown.
 */
#include "common.h"

/* localdecomp:start func_003BDCB0 */
extern s32 D_001D8CFC;
extern s32 D_001D8CF8;
extern s32 D_001DA268[];
extern s8 D_001DA290[];
void func_003BDCB0(s32 n, s32 *p, s32 v) {
    s32 i = 0;
    s32 missing = -1;
    s8 *flags = D_001DA290;
    s32 *entry = D_001DA268;

    for (; i < 10; entry++, i++, p++) {
        if (i < n) {
            *entry = *p;
        } else {
            *entry = missing;
        }

        *(s8 *)(i + (s32)flags) = 0;
    }

    D_001D8CFC = v;
    D_001D8CF8 = n;
}
/* localdecomp:end func_003BDCB0 */

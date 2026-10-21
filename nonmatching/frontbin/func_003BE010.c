/* Near miss of func_003BE010 with its file's own flags: tools/check.py reports 3 diff
   (the version it replaces: 13).
*/

/* US draft of func_003BE010 (rac3-uya-decomp func_003B8B18, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */

/* D_001D6E90 is reached through the absolute (lui %hi / %lo) form in the retail, not through $gp.
   That is the form the assembler picks for a global it may not reach through $gp, so the global is
   declared here with a size above the -G8 small-data limit (the same convention the file uses for
   the other such globals, e.g. D_00142BA0[]).  The plain "extern s32 D_001D6E90;" of the file's own
   declarations makes the compiler emit ".extern D_001D6E90, 4" and the assembler would then use
   the $gp-relative form instead.  The store is a plain store to the global itself, so the
   assembler expands it into "lui $at, %hi(sym)" / "sw .., %lo(sym)($at)" like the retail does. */


/* localdecomp:start func_003BE010 */
extern u32 D_00142BA0[];
typedef struct { s32 f0; s32 f1; s32 f2; s32 f3; } S_001D6E90_003BE010;
extern S_001D6E90_003BE010 D_001D6E90_003BE010;
extern s32 func_003BB7C0();
extern s32 func_003BB7B8();
s32 func_003BE010(s32 a, s32 b, u32 c) {
    u32 w;
    if (a == -1 || func_003BB7C0() == a) {
        if (b == -1 || func_003BB7B8() == b) {
            w = c >> 2;
            if (!(D_00142BA0[w] & (1 << (c & 0x1F)))) {
                D_001D6E90_003BE010.f0 = c;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003BE010 */

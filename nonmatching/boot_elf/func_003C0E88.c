/* Near miss of func_003C0E88 with its file's own flags: tools/check.py reports 20 diff
   (the version it replaces: 24).
   What differs: 18 diffs, all from retail's two `nop`s in front of the second `div.s` (case
   3); every instruction, register and immediate otherwise matches, and the 17 branch-offset
   diffs are just the 8-byte shift those two nops cause.
*/

/* PAL candidate for func_003C0E88 (boot_elf).
   US draft of func_003C0E88 (rac3-uya-decomp func_003C0D80, commit 13cf5c5), with the
   PAL constants: the timer runs at 50 Hz in PAL, so the frame counts are 12 (0xC) and
   75 (0x4B) instead of 15 (0xF) and 90 (0x5A), and the fade step is 12.0f, not 15.0f. */

/* localdecomp:start func_003C0E88 */
extern s32 func_0038CEB0();
extern s32 func_003BE2D0();
extern void func_003BBD20();
s32 func_003C0E88(s32 a) {
    S_3BB558 *g = D_002D1FC0;
    s32 r = 0;
    s32 k;
    switch (g->w44) {
    case 0:
        if (func_0038CEB0(&g->w40) == 1) {
            g->w40 = 0xC;
            g->w44 = g->w44 + 1;
        }
        break;
    case 1:
        if (func_0038CEB0(&g->w40) == 1) {
            g->w40 = 0x4B;
            g->w44 = g->w44 + 1;
        }
        func_003BE3C0((f32)g->w40 / 12.0f);
        break;
    case 2:
        if (func_003BE2D0()) func_003BBD20();
        if (func_0038CEB0(&g->w40) == 1 && a != 0) {
            g->w40 = 0xC;
            g->w44 = g->w44 + 1;
        }
        break;
    case 3:
        if (func_0038CEB0(&g->w40) == 1) r = 1;
        func_003BE3C0(1.0f - (f32)g->w40 / 12.0f);
        break;
    }
    return r;
}
/* localdecomp:end func_003C0E88 */

/* Near miss of func_003C0AD0 with its file's own flags: tools/check.py reports 20 diff
   (the US draft it started from: 22).
   What differs: The C is byte-exact with retail except for the 2 `nop`s retail has in front of
   the second `div.s` (retail 0x3C0C0C-0x3C0C13); those come from
   `config/frontbin/divs_nops.txt`, which the PAL repo still lists with NTSC addresses (it has
   `func_003BB5C0 0 2`, the US twin of this function), so it needs the line `func_003C0AD0 0 2`
   — with that line the function matches byte for byte.
*/

/* US draft of func_003C0AD0 (rac3-uya-decomp func_003BB5C0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C0AD0 */
extern s32 func_0038CAD0();
extern s32 func_003BDF18();
extern void func_003BB968();
s32 func_003C0AD0(s32 a) {
    S_3BB558 *g = D_002D1FC0;
    s32 r = 0;
    s32 k;
    switch (g->w44) {
    case 0:
        if (func_0038CAD0(&g->w40) == 1) {
            g->w40 = 0xC;
            g->w44 = g->w44 + 1;
        }
        break;
    case 1:
        if (func_0038CAD0(&g->w40) == 1) {
            g->w40 = 0x4B;
            g->w44 = g->w44 + 1;
        }
        func_003BE008((f32)g->w40 / 12.0f);
        break;
    case 2:
        if (func_003BDF18()) func_003BB968();
        if (func_0038CAD0(&g->w40) == 1 && a != 0) {
            g->w40 = 0xC;
            g->w44 = g->w44 + 1;
        }
        break;
    case 3:
        if (func_0038CAD0(&g->w40) == 1) r = 1;
        func_003BE008(1.0f - (f32)g->w40 / 12.0f);
        break;
    }
    return r;
}
/* localdecomp:end func_003C0AD0 */

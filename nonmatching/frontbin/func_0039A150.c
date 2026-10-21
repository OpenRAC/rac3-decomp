/* Near miss of func_0039A150 with its file's own flags: tools/check.py reports 10 diff
   (the version it replaces: 16).
   What differs: 10 diffs: retail reaches the pointer at 0x001D4B50 with `lui $at` + `sw
   %lo($at)` and `lui $v0` + `lw %lo($v0)` (the retail build's Ps2EeAs expansion of a symbol
   reference; the US matched this function with @ps2as), while ee-gcc with this file's flags
   only reaches it as `lui $reg` + `op %lo($reg)` (a general-purpose base register) even for an
   unsized array alias; the store's base is $t0 instead of $at, the load's base is $a1 instead
   of $v0 (dest-as-base), and the resulting allocation/schedule differ for -0x10, 0x60 and the
   0xFFFFF000 mask; a literal address (*(s32 *)0x001D4B50) gives the...
*/

/* PAL candidate for func_0039A150 (US draft: rac3-uya-decomp func_00395360).
   Retail reaches the pointer at 0x001D4B50 with `lui $at` + `sw %lo($at)` and
   `lui $v0` + `lw %lo($v0)`, i.e. not through $gp.  With ee-gcc a sized
   extern is small data and is reached through $gp, so the global is used
   through unsized aliases: an array of unknown size is never small data and
   is reached with lui/%lo (docs/wiki/Matching-Patterns.md, "Globals: gp vs
   lui").  Retail does not share the high half between the store and the load,
   so each access has its own alias.  The shared declaration of the file
   (`s32 *D_001D4B50_0039A150`) stays as it is; the two aliases below are the
   same address 0x001D4B50 and would need their own lines in
   config/frontbin/symbol_addrs_resolved.txt to link. */

/* localdecomp:start func_0039A150 */
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x668 - 0x650]; s32 f668; s32 f66C; } S_395360;
extern S_395360 D_00160C40;
extern s32 *D_001D4B50_0039A150;
extern s32 *D_001D4B50_0039A150_u[];
extern s32 *D_001D4B50_0039A150_v[];
extern u8 D_01FF7FF0[];
extern s32 func_003A2680();
s32 func_0039A150(void) {
    S_395360 *s = &D_00160C40;
    u32 x;
    s32 *p;
    x = ((s->f66C << 11) + 0x1057) & 0xFFFFF000;
    p = (s32 *)((s32)((u32)D_01FF7FF0 - x) & -16);
    D_001D4B50_0039A150_u[0] = p;
    *p = 0x60;
    func_003A2680((s32)D_001D4B50_0039A150_v[0] + D_001D4B50_0039A150_v[0][0], s->f668 + s->f64C, s->f66C);
    return 1;
}
/* localdecomp:end func_0039A150 */
TEXT_PADDING(2);

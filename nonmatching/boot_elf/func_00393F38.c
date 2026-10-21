/* Near miss of func_00393F38 with its file's own flags: tools/check.py reports 17 diff
   (the version it replaces: 34).
   What differs: Loop body and all stores now match byte-for-byte (17 diffs left, all in the
   prologue): retail materialises the three loop base addresses (D_001425C0, D_1DAA40,
   D_00331990) with the split form `lui $v0,%hi(sym)` ... `addiu $t0,$v0,%lo(sym)` (hi half in
   a scratch register, scheduled early at positions 7/14/15, low half added late at 12/17/18),
   while the candidate still gets the coalesced `lui $t0,%hi(sym); addiu $t0,$t0,%lo(sym)`
   pair, and the whole prologue is scheduled in a different order (the ternary's two addresses
   come first in the candidate, the store operands first in retail)....
*/

/* PAL candidate for func_00393F38 (boot_elf, src/boot_elf/text/392DF8.c).

   The file's flags carry -mno-split-addresses, so the compiler puts an
   external object of known size (<= -G8) in small data and reaches it
   through $gp.  Retail reaches D_1D4C60, D_1D4C80, D_1D9EE8 and D_1D9EF0
   with %hi/%lo, so those four are declared with incomplete types here
   (the file's own declarations for them are fixed and cannot change). */

__asm__(".extern D_001D5D40, 4");
__asm__(".extern D_001D5CAC, 4");
extern s32 D_001D9EE8[];
extern s32 D_001D9EF0[];
extern s32 D_1D4C60_00393F38[];
extern s32 D_1D4C80_00393F38[];
extern s32 D_001D5D40;
extern s32 D_001D5CAC;
extern u8 D_001425C0[];
extern S_38F310 D_001DAA40_00393F38[];
extern D_393F38 D_00331990[];

void func_00393F38(s32 a) {
    s32 *p;
    s32 i;
    s32 v;
    s32 k;
    u8 *tbl;
    S_38F310 *tab;
    D_393F38 *out;
    D_001D9EE8[0] = 8;
    D_001D9EF0[0] = (s32)&D_001D5D40;
    D_001D5CAC = 0;
    p = a ? D_1D4C80_00393F38 : D_1D4C60_00393F38;
    tbl = D_001425C0;
    tab = D_001DAA40_00393F38;
    out = D_00331990;
    for (i = 0; i < 8; i++) {
        k = *((u8 *)((u32)p[i] + (u32)tbl));
        v = tab[k].h38;
        out->w0 = v;
        out->w18 = p[i];
        out++;
    }
}

/* Near miss of func_00397D48 with its file's own flags: tools/check.py reports 9 diff
   (the US draft it started from: 11).
   What differs: Retail reaches D_001D9F4C with `lui $at, 0x1e` + `sw $a1, -0x60b4($at)` (not
   through $gp), so the file's sized declaration `extern s32 D_001D9F4C;` (small data under
   -G8) makes GCC emit GPREL16 and the default assembler leaves it $gp-relative - that form was
   what the US matched under `@ps2as`. Making it unsized (`extern s32 D_001D9F4C_00397D48[];`,
   an alias needing `D_001D9F4C_00397D48 = 0x1D9F4C;` in
   config/frontbin/symbol_addrs_resolved.txt) gives the %hi/%lo pair but GCC splits the address
   into two scheduled instructions ($v0, early) -> 12 diff. The left candidate uses the
   constant...
*/

/* US draft of func_00397D48 (rac3-uya-decomp func_003934E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */

/* localdecomp:start func_00397D48 */
__asm__(".extern D_001D9F48, 4");
extern s32 D_001D5F00[];
extern s32 D_001D5EE8[];
extern s32 D_001D9F4C;
extern s32 D_001D9F48;
extern void func_13B0C8();
extern void func_00397CC0();
typedef struct { u8 pad[0x10]; s32 a; u16 b; u8 pad2[0x1A]; } S_3934E8;
void func_00397D48(s32 x, s32 y) {
    S_3934E8 s;
    s32 *p;
    s32 *q;
    p = D_001D5EE8;
    s.a = D_001D5F00[0];
    s.b = ((u16 *)D_001D5F00)[2];
    q = &s.a;
    /* Retail reaches D_001D9F4C with lui/%hi-%lo, not through $gp: the file's
       sized declaration puts it in small data (-G8) and GCC then emits GPREL16,
       which the default assembler leaves to the linker as $gp-relative (that is
       what the US build's @ps2as assembler turned into lui/%lo instead). */
    *(s32 *)0x001D9F4C = (s32)q;
    D_001D9F48 = (s32)&s;
    func_13B0C8((u8 *)q + 5);
    func_00397CC0(p, 2, &D_001D9F48);
}
/* localdecomp:end func_00397D48 */

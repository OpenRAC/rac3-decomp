/* Near miss of func_003BF7A0 with its file's own flags: tools/check.py reports 3 diff
   (the version it replaces: 37).
   What differs: only the float-constant load is one slot late: ours has `addiu $sp,$sp,-0x10;
   lui $at,0x3f80; mtc1 $at,$f0`, retail has `lui $at,0x3f80; mtc1 $at,$f0; addiu
   $sp,$sp,-0x10` (3 diffs, all other 39 instructions match)
*/

/* US draft of func_003BF7A0 (rac3-uya-decomp func_003BA2A8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */

/* Retail reaches D_001DA340, D_001DA338, D_001DA33C, D_001DA344 and D_001DA345 through
   lui/%lo, not through $gp, so they are addressed by constant address here (a sized global
   would be small data and get a $gp access, and an unsized array alias would make gcc split
   the address into a hoisted `lui` of its own). D_001D8E30 stays a sized scalar: retail
   reaches it through $gp. */

/* localdecomp:start func_003BF7A0 */
extern s32 D_001D8E30;
extern u8 D_001D8E34[];
extern void *D_002FCDA4[];
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern s32 func_003BDD38(void);
extern void func_003BDE20(s32);
extern void func_003BE308(void *);
extern void func_003BF8C0(void);
extern void func_003BF860();
extern void func_003BFC58();
__asm__(".extern D_001D8E30, 4");
s32 func_003BF7A0(void) {
    *(f32 *)0x001DA340 = 1.0f;
    *(s32 *)0x001DA338 = 0;
    *(u8 *)0x001DA33C = 0;
    *(u8 *)0x001DA344 = 0;
    *(u8 *)0x001DA345 = 0;
    func_003BBA08(0, 0);
    func_003BC408(4, &D_001D8E30);
    func_003BDCB0(3, (s32 *)D_001D8E34, D_001D8E30);
    func_003BDE20(func_003BDD38());
    func_003BE308(func_003BF860);
    func_003BF8C0();
    D_002FCDA4[0] = func_003BFC58;
    return 1;
}
/* localdecomp:end func_003BF7A0 */

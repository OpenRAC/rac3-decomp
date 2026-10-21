/* Near miss of func_003A2A80 with its file's own flags: tools/check.py reports 4 diff
   (the version it replaces: 21).
   What differs: Body is byte-identical to retail (lui+lbu / lui+sw %hi/%lo accesses to
   D_001D52E0 and D_001D4D00, lwl/lwr copy of D_001CD010[0], $gp-relative store to D_001D4D04);
   only the prologue/argument-shuffle order differs: mine emits `addiu $sp,-0x20; move $v0,$a0;
   sd $ra,0x10($sp); move $a0,$a1` where retail has `move $v0,$a0; addiu $sp,-0x20; move
   $a0,$a1; sd $ra,0x10($sp)` (4 diffs). Notes for the next attempt: the two globals must be
   reached through %hi/%lo, not $gp (the file's `extern u8 D_001D52E0;` / `extern s32
   D_001D4D00;` are small-data scalars under -G8, so the checker context forbids...
*/

/* PAL candidate for func_003A2A80 (program boot_elf).
   Retail reaches D_001D52E0 and D_001D4D00 with %hi/%lo (lui + lbu / lui + sw),
   i.e. they are not small data there, while this file's declarations make them
   1- and 4-byte scalars that -G8 puts in .sdata ($gp relative).
   They are reached through their absolute addresses instead (the same trick the
   other PAL files use, e.g. *(s32 *)0x1D4B4C = 0; in 3BCC10.c), which is what
   gives the lui + lbu / lui + sw forms.  D_001D4D04 stays a scalar: retail
   reaches it through $gp. */

/* localdecomp:start func_003A2A80 */
typedef struct { u8 b[4]; } B4_0039D5F8;
extern B4_0039D5F8 D_001CD010[];
extern u8 D_001D52E0;
extern s32 D_001D4D00;
extern s32 D_001D4D04;
extern void func_0013CD28();
extern void func_0013CA28();
extern void func_0013B620();
s32 func_003A2A80(s32 a, s32 b, s32 c) {
    B4_0039D5F8 buf;
    u8 v = *(u8 *)0x001D52E0;
    buf = D_001CD010[0];
    buf.b[1] = v;
    *(s32 *)0x001D4D00 = 0;
    D_001D4D04 = 0;
    func_0013CD28(b, c, a, &buf);
    func_0013CA28();
    func_0013B620();
    return 1;
}
/* localdecomp:end func_003A2A80 */

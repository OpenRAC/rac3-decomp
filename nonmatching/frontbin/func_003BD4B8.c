/* Near miss of func_003BD4B8 with its file's own flags: tools/check.py reports 4 diff
   (the US draft it started from: 86).
   What differs: 4 of 400 bytes differ, all in the first block: retail has `addiu $sp,-0x10;
   lui $v0,0x1d; lbu $v0,0x5bdc($v0); sd $s0,0($sp); bnez $v0; sd $ra,8($sp)`, mine has `lui
   $v0,0x1d; addiu $sp,-0x10; lbu $v1,0x5bdc($v0); ...; bnez $v1` - gcc hoists the `lui` above
   the prologue and keeps the address in $v0 while the loaded byte lands in $v1, so the pair is
   not register-coalesced the way Ps2EeAs' expansion of retail's `$gp`-relative `lbu $v0,
   D_001D5BDC($gp)` was (GNU as keeps a `$gp` access one word, so gcc must build the lui/%lo
   pair itself, and with the file's flags it either hoists the lui...
*/

/* PAL candidate for func_003BD4B8 (frontbin), matched with the file's own
   flags (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division).

   Retail reaches five of the globals through lui/%lo (split addresses), not
   through $gp: D_001D5BDC, D_001D9D04, D_001D9BC8, D_001D6E90, D_001D4B48.
   A sized scalar is small data and gets the $gp form, and an unsized alias
   whose address gcc hoists into a saved register gives an extra lui/load
   pair, so those accesses use the globals' addresses directly
   (docs/wiki/Matching-Patterns.md, "Globals: gp vs lui").  D_001D5BDC is
   read through an unsized alias instead: that keeps gcc's load in the
   prologue's first block, where retail has it.  D_001D9BC8 is stored
   through $gp, which the sized name gives. */

/* localdecomp:start func_003BD4B8 */
extern u8 D_001D5BDC_003BD4B8[];
extern u8 D_001D8CD0;
extern u8 D_001D8CD1;
extern s32 D_001D9D54;
extern s32 D_001D9BC8;
extern u8 D_001D8CF4;
extern f32 D_001D8CF0;

extern void func_0039EC28(s32, s32);
extern void func_003BCDA8(void);
extern void func_003BD030(void);
extern void func_00387EF0(void);
extern void func_003A3B70(void);
extern s32 func_003BCA48(s32);
extern void func_00387218(void);
extern void func_003BC800(void);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern void func_003A92F0(s32);
extern s32 func_0039A1E0(void);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_003BE200(void);
extern void func_00392748(s32);
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_0038A238(s32);
extern void func_003BD390(void);
s32 func_003BD4B8(void) {
    s32 r;
    if (D_001D5BDC_003BD4B8[0] == 0) func_0039EC28(0, *(s32 *)0x001D9D04);
    if (*(s32 *)0x001D9D04 < 0) {
        func_003BCDA8();
        return 1;
    }
    r = 0;
    func_003BD030();
    D_001D8CD0 = 0;
    D_001D8CD1 = 0;
    for (;;) {
        func_003A91D0();
        func_003A9150();
        func_003923D0();
        if (D_001D8CF4 != 0) func_003BE200();
        else func_00392748(1);
        func_003922B8();
        func_00392350(0);
        if (r != 0) break;
        func_00387EF0();
        func_003A3B70();
        r = func_003BCA48(D_001D8CD0);
        D_001D9D54 = 0;
        func_00387218();
        func_003BC800();
        func_0039C410();
        func_0039ADE0();
        func_003A92F0(1);
        func_12C908(0);
        D_001D9BC8 = *(s32 *)0x001D9BC8 + 1;
        if (*(s32 *)0x001D6E90 == 0) D_001D8CD1 = func_0039A1E0() != 0;
        D_001D8CD0 = *(s32 *)0x001D4B48 >= 2;
    }
    func_003A92F0(1);
    func_12C908(0);
    if (D_001D8CF0 > 0.0f) func_0038A238(2);
    func_003BD390();
    return 1;
}
/* localdecomp:end func_003BD4B8 */

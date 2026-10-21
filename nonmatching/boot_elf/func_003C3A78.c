/* Near miss of func_003C3A78 with its file's own flags: tools/check.py reports 9 diff
   (the version it replaces: 38).
   What differs: 9 of 47 instructions differ: the D_002FC1A0 address is materialised as `lui
   $v1,0x2f` + `ori $v1,$v1,0xc1a0` instead of retail's `lui $v1,0x30` + `addiu
   $v1,$v1,-0x3e60` (retail reaches it through the symbol, which splits the address; a plain
   literal is materialised lui+ori), and that difference shifts the register allocation: the
   0x1D4BB4 load lands in $t0 instead of $a2 and the D_001DA050 store's address in $a2 instead
   of $at.
*/

/* PAL candidate for func_003C3A78 (rac3-uya-decomp func_003C3960, commit 13cf5c5),
   names moved to PAL addresses where known.
   The retail build reaches these globals with lui/%lo (not $gp-relative) and with
   the loaded value in the address register, the way a plain address constant is
   reached; the file's own declarations type them as small data, so they are
   read and written through their addresses instead.
   D_001DA050 is read and written; reading it through its address and writing
   it through the symbol keeps the two accesses independent, as in the retail. */

/* localdecomp:start func_003C3A78 */
extern void func_003A9348(void *);
extern void func_003A96F0();
extern void func_003A97F8(s32, unsigned long);
extern u8 D_00110790[];
extern u8 D_00100080[];
extern u16 D_00110780[];
extern s32 D_001DA050[];
void func_003C3A78(void) {
    s32 a, b, c, d;
    func_003A96F0(D_00110790, D_00110780[0]);
    *(s32 *)0x1D9D1C = 6;
    func_003A9348(D_00100080);
    func_003A97F8(0x47, 0x5360B);
    a = *(s32 *)0x1DA050;
    b = *(s32 *)0x1D9D38;
    c = *(s32 *)0x1D4BB4;
    *(s32 *)0x1DA490 = a;
    d = *(s32 *)0x1D9D30;
    *(s32 *)0x1D4BB0 = c;
    a += 0x10;
    *(s32 *)D_001DA050 = a;
    *(u8 **)0x1DA530 = (u8 *)0x2FC1A0;
    *(s32 *)0x1DA054 = b + 0xFFFF0000;
    *(s32 *)0x1DA498 = d;
    *(s32 *)0x1DA4E4 = 0;
}
/* localdecomp:end func_003C3A78 */

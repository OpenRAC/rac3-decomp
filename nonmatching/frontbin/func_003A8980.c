/* Near miss of func_003A8980 with its file's own flags: tools/check.py reports 17 diff
   (the version it replaces: 22).
*/

/* PAL candidate for func_003A8980 (frontbin).
   The five globals retail reaches with lui/%lo (0x1DA030, 0x1DA034, 0x1DA038,
   0x1DA03C, 0x1DA044) are declared without a size: with -G8 a sized global
   goes into small data and the assembler then reaches it through $gp, which
   is not what retail does.  An unsized array is never small data, so it gets
   lui/%lo.  The file's shared declaration of these names is sized (func_003A88B8
   reaches D_001DA034 through $gp), so per-function aliases at the same
   addresses carry the unsized declaration.  D_001DA040 is reached through $gp
   in retail (its store sits in a branch delay slot, which cannot hold a
   lui/%lo pair), so it keeps its sized declaration. */

/* localdecomp:start func_003A8980 */
extern u8 D_001A30B0[];
extern s32 D_001DA030_003A8980[];
extern s32 D_001DA044_003A8980[];
extern s32 D_001DA034_003A8980[];
extern s32 D_001DA038_003A8980[];
extern s32 D_001DA03C_003A8980[];
extern s32 D_001DA040;
extern s16 D_001CD018[];
extern void func_13CF80();
extern void func_11F0A0();
extern void func_003A5430();
extern void func_003A1C28();
extern void func_0038A238();
extern void func_003A0D40();
void func_003A8980(s32 a, s32 b, s32 c, s32 d, s32 e) {
    D_001A30B0[0x43] |= 8;
    func_13CF80(2, 0, 0, 0, 0);
    func_11F0A0(0);
    func_003A5430();
    func_003A1C28();
    D_001DA030_003A8980[0] = a;
    D_001DA044_003A8980[0] = D_001CD018[0];
    D_001DA034_003A8980[0] = b;
    D_001DA038_003A8980[0] = c;
    D_001DA03C_003A8980[0] = d;
    D_001DA040 = e;
    func_0038A238(4);
    func_003A0D40();
}
/* localdecomp:end func_003A8980 */

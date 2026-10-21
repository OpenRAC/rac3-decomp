/* Near miss of func_003B66F0 with its file's own flags: tools/check.py reports 7 diff
   (the version it replaces: 27).
*/

/* PAL candidate for func_003B66F0.
 *
 * Retail reaches D_001D545C, D_001D5571 and D_001D5638 through lui/lw with
 * the address built in a register, so they are addressed directly.  The
 * stores in the else branch are reached the same way, through unsized
 * aliases of D_001D5B74 and D_001D9D04 (an unsized array is never small
 * data, so it gets the lui/lw form).  D_001D545C_gp_003B66F0 is the one
 * retail reads through $gp (it is loaded in the beqz delay slot), so it
 * stays a sized scalar.
 */

/* localdecomp:start func_003B66F0 */
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003B66F0;
extern s32 D_001D5B74_003B66F0[];
extern s32 D_001D9D04_003B66F0[];
extern s32 D_0022CF90[];
extern s32 D_001D8A9C;
extern s32 D_001D8A40_003B66F0;
extern s32 func_0039C048();
extern void func_0039C220();
extern void func_003A3FE0(void);
extern s32 func_003A2750(s32);
extern void func_0013BFE0(s32);
extern void func_003A8F50(void);
void func_003B66F0(void) {
    s32 v;
    if (func_0039C048()) {
        func_0039C220(D_001D8A9C);
        D_001D8A40_003B66F0 = 5;
        return;
    }
    D_001425AC[0] = 1;
    func_003A3FE0();
    func_003A2750(1);
    func_0013BFE0(D_00143958[0] == 0);
    v = D_001D545C_gp_003B66F0;
    if (*(s32 *)0x001D545C < 2 && *(u8 *)0x001D5571 == 0) {
        func_003A8F50();
    } else {
        D_001D5B74_003B66F0[0] = 1;
        D_001D9D04_003B66F0[0] = v;
    }
    *(u8 *)0x001D5638 = 1;
    D_0022CF90[0] = 0;
}
/* localdecomp:end func_003B66F0 */

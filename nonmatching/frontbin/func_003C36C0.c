/* Near miss of func_003C36C0 with its file's own flags: tools/check.py reports 17 diff
   (the version it replaces: 38).
*/

/* PAL candidate for func_003C36C0 (frontbin).
   Retail reaches every global of this function through lui/%lo, never through
   $gp. With this file's flags (-O2 -G8, default assembler) gcc splits a
   *symbol* address into a lui plus op(%lo) and keeps the high half in a
   register of its own, hoisting it away from the access; retail instead
   expands each reference where it stands (lui into the destination for
   loads, into $at for stores), which is what a constant address produces.
   The globals are therefore reached by address.  D_001DA050 is read and
   written, so the read keeps the symbol (a constant address used twice is
   materialised into a register by gcc) and only the write uses the address. */

/* localdecomp:start func_003C36C0 */
extern void func_003A8F90(void *);
extern u8 D_002FC1A0[];
extern void func_003A9338();
extern void func_003A9440(s32, unsigned long);
extern u8 D_00110790[];
extern u8 D_00100080[];
extern u16 D_00110780[];
extern s32 D_001DA050[];
void func_003C36C0(void) {
    s32 a, b, c, d;
    func_003A9338(D_00110790, D_00110780[0]);
    *(s32 *)0x1D9D1C = 6;
    func_003A8F90(D_00100080);
    func_003A9440(0x47, 0x5360B);
    a = D_001DA050[0];
    b = *(s32 *)0x1D9D38;
    c = *(s32 *)0x1D4BB4;
    *(s32 *)0x1DA490 = a;
    d = *(s32 *)0x1D9D30;
    *(s32 *)0x1D4BB0 = c;
    a += 0x10;
    *(s32 *)0x1DA050 = a;
    *(u8 **)0x1DA530 = D_002FC1A0;
    *(s32 *)0x1DA054 = b + 0xFFFF0000;
    *(s32 *)0x1DA498 = d;
    *(s32 *)0x1DA4E4 = 0;
}
/* localdecomp:end func_003C36C0 */

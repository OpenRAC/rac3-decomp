/* Near miss of func_003CEF40 with its file's own flags: tools/check.py reports 22 diff
   (the version it replaces: 66).
   What differs: Retail materialises every D_001DA050/D_001DA68C/D_001DA694 address with its
   own `lui` (one per access, the register reused by the access itself) because retail was
   assembled with Ps2EeAs, which expands each access separately; D_001D4BB0 and the D_001DA694
   write go through `$gp`. With the file's assembler a constant address gives retail's exact
   `lui`+`lw`/`sw` shape, but only while it is materialised again for every use: that happens
   after a call (the reload is invalidated), not before it. So the accesses before
   `func_003CFDD0()` still differ - gcc keeps the repeated address in one register...
*/

/* Candidate for func_003CEF40 (frontbin, PAL).
   Retail materialises every address with its own lui (one per access, the
   register reused by the access itself) and reaches D_001D4BB0 and the
   D_001DA694 write through $gp.  A constant address gives retail's lui/lo
   pair (the register reused) as long as it is materialised again for each
   use; before the first call gcc keeps a repeated address in one register,
   so those accesses use one alias each. */


/* localdecomp:start func_003CEF40 */
extern u32 *D_001DA050_b[];
extern u32 *D_001DA050_c[];
extern u32 *D_001DA68C_b[];
extern u32 *D_001DA68C_c[];
extern u32 *D_001DA68C_d[];
extern s32 D_001DA694_g;
extern s32 D_001D4BB0;
extern void func_003CFDD0(void);
extern s32 func_003CFF38(s32);
extern void func_003A9618(void);
void func_003CEF40(void) {
    u32 *save = *(u32 *)0x001DA050;
    s32 r;
    D_001DA050_b[0] = *(u32 *)0x001DA050 + 16;
    *(u32 *)(*(u32 *)0x001DA68C + 0) = 0x20000000;
    D_001DA68C_b[0][1] = D_001DA050_c[0];
    D_001DA68C_c[0][2] = 0;
    D_001DA68C_d[0][3] = 0;
    func_003CFDD0();
    r = func_003CFF38(D_001D4BB0);
    func_003A9618();
    if (*(s32 *)0x001DA694 < r) { D_001DA694_g = r; }
    *(u32 *)(*(u32 *)0x001DA050 + 0) = 0x20000000;
    *(u32 *)(*(u32 *)0x001DA050 + 4) = *(u32 *)0x001DA68C + 16;
    *(u32 *)(*(u32 *)0x001DA050 + 8) = 0;
    *(u32 *)(*(u32 *)0x001DA050 + 12) = 0;
    *(u32 *)0x001DA050 = *(u32 *)0x001DA050 + 16;
    save[0] = 0x20000000;
    save[1] = *(u32 *)0x001DA050;
    save[2] = 0;
    save[3] = 0;
}
/* localdecomp:end func_003CEF40 */

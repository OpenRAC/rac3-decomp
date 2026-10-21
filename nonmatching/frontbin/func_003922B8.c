/* Near miss of func_003922B8 with its file's own flags: tools/check.py reports 26 diff
   (the version it replaces: 36).
*/

/* PAL candidate for func_003922B8 (US draft: rac3-uya-decomp func_0038DA80, commit 13cf5c5).
   The US matched it with `@ps2as` and without `-mno-split-addresses`; here the file's own flags
   must do it, so the globals are reached the way retail reaches them: the reads of the pointer
   at 0x001DA050 (and of the word at 0x001D4CF8) go through unsized aliases (never small data,
   so `lui`/`lw`), while the write of the pointer itself stays on the sized declaration ($gp). */

/* localdecomp:start func_003922B8 */
extern u32 *D_001DA050;
extern u32 D_001DA050_003922B8_lui[];
extern s32 D_001D4CF8[];
extern void func_12C820(s32);

void func_003922B8(void) {
    u32 *p = (u32 *)D_001DA050_003922B8_lui[0];
    if (p != 0) {
        p[0] = 0x30000009;
        ((u32 *)D_001DA050_003922B8_lui[0])[1] = (D_001D4CF8[0] + 0x30) & 0xFFFFFFF;
        ((u32 *)D_001DA050_003922B8_lui[0])[2] = 0;
        ((u32 *)D_001DA050_003922B8_lui[0])[3] = 0x50000009;
        D_001DA050 = (u32 *)((u8 *)D_001DA050_003922B8_lui[0] + 0x10);
    } else {
        func_12C820(D_001D4CF8[0] + 0x30);
    }
}
/* localdecomp:end func_003922B8 */

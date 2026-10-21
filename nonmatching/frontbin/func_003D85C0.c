/* Near miss of func_003D85C0 with its file's own flags: tools/check.py reports 27 diff
   (the version it replaces: 31).
*/

/* PAL candidate for func_003D85C0 (retail 0x003D85C0, 0x7C bytes).
 *
 * Retail reads the two data words with absolute (lui/lw) accesses but writes
 * the pointer back with a $gp-relative store.  GCC 2.95 only uses $gp-relative
 * addressing for a declaration whose size is known and small, so the reads go
 * through array declarations of the same addresses (incomplete type -> size 0
 * -> absolute), while the write keeps the pointer declaration the source file
 * has (size 4 -> $gp relative).  Retail re-materialises the address for every
 * read, so each read gets its own name for the same address.
 */
extern s32 D_001D55F0_003D85C0[];
extern s32 D_001D55F0_003D85C0_2[];
extern s32 D_001DA050_003D85C0[];
extern s32 D_001DA050_003D85C0_2[];
extern s32 D_001DA050_003D85C0_3[];
extern s32 D_001DA050_003D85C0_4[];
extern s32 D_001DA050_003D85C0_5[];

void func_003D85C0(void) {
    D_001D934C = 0x6000;
    ((u32 *)D_001DA050_003D85C0[0])[0] = (D_001D55F0_003D85C0[0] >> 4) | 0x30000000;
    ((u32 *)D_001DA050_003D85C0_2[0])[1] = (u32)D_001D0A50;
    ((u32 *)D_001DA050_003D85C0_3[0])[2] = 0;
    ((u32 *)D_001DA050_003D85C0_4[0])[3] = (D_001D55F0_003D85C0_2[0] >> 4) | 0x50000000;
    D_001DA050 = (u32 *)D_001DA050_003D85C0_5[0] + 4;
}

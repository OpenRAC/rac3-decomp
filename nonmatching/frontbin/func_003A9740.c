/* Near miss of func_003A9740 with its file's own flags: tools/check.py reports 55 diff
   (the version it replaces: 56).
*/

/* PAL candidate for func_003A9740.

   The retail code reaches the global twice in two different ways:
   - %hi/%lo (lui + lw) loads of the pointer stored at D_001DA050, i.e. the
     global is an array-like object in .data, so it is read as D_001DA050[0];
   - a $gp-relative store of -0x2860($gp) = 0x001DA050, i.e. a small
     (4-byte) pointer global written through $gp.

   So the two accesses need two different declarations of the same address:
   an array (not small data -> lui/lw) and a pointer (small data -> $gp).
   Both names resolve to 0x001DA050 in the checker.  */

/* localdecomp:start func_003A9740 */
extern u32 *D_001DA050_arr[];
extern u32 *D_001DA050_g;
extern u8 D_00142120[];
extern u8 D_001D5330[];
extern void func_0038CC88();
void func_003A9740(void) {
    D_001DA050_arr[0][0] = 0x30000009;
    D_001DA050_arr[0][1] = (u32)D_00142120;
    D_001DA050_arr[0][2] = 0;
    D_001DA050_arr[0][3] = 0x50000009;
    D_001DA050_arr[0] = D_001DA050_arr[0] + 4;
    D_001DA050_arr[0][0] = 0x10000003;
    D_001DA050_arr[0][1] = 0;
    D_001DA050_arr[0][2] = 0;
    D_001DA050_arr[0][3] = 0x50000003;
    D_001DA050_g = D_001DA050_arr[0] + 4;
    func_0038CC88(D_001DA050_arr[0] + 4, D_001D5330, 0x30);
    D_001DA050_arr[0] = D_001DA050_arr[0] + 12;
}
/* localdecomp:end func_003A9740 */

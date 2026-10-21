/* Near miss of func_003D91F0 with its file's own flags: tools/check.py reports 10 diff
   (the version it replaces: 15).
*/

/* PAL decomp of func_003D91F0 (frontbin).

   Retail reaches the globals at 0x001D5628 and 0x001D55EC with %hi/%lo
   (lui) addressing, not through $gp, while the ones at 0x001D5634 and
   0x001D5630 are $gp-relative.  A declaration of unknown size (an array)
   is what keeps the compiler off $gp, so those globals are declared as
   arrays here.  The names are aliases of the same addresses (see
   config/frontbin/symbol_addrs_resolved.txt) with this function's suffix:
   the file's own declarations are sized scalars, which would be $gp-relative.

   D_001D55EC needs two names: retail builds the address again for the
   store instead of reusing the one of the load, which only happens when
   the two accesses are distinct symbols.
*/

/* localdecomp:start func_003D91F0 */
extern s32 func_003D6A20();
extern void func_003D8FC0(void);
extern void func_003D9100(void);
extern s32 D_001D5634;
extern s32 D_001D5630;
extern s32 D_001D5628_003D91F0[];
extern s32 D_001A1ED4[];
extern s32 D_001D55EC_003D91F0[];
extern s32 D_001D55EC_003D91F0_r[];

void func_003D91F0(void) {
    s32 spv[4];
    spv[0] = 0x37C000;
    D_001D5634 = func_003D6A20(spv, 0x40000);
    D_001D5628_003D91F0[0] = func_003D6A20(spv, 0x40000);
    D_001D5630 = D_001A1ED4[0];
    func_003D8FC0();
    func_003D9100();
    D_001D55EC_003D91F0_r[0] = D_001D55EC_003D91F0[0] | 2;
}
/* localdecomp:end func_003D91F0 */

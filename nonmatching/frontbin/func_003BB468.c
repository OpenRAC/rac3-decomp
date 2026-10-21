/* Near miss of func_003BB468 with its file's own flags: tools/check.py reports 44 diff
   (the version it replaces: 45).
   What differs: Addresses of the tables are now materialised with lui/addiu as in retail (the
   US draft's 8-byte aliases land in small data and are addressed through $gp), but the
   compiler still orders/schedules the materialisations differently from retail: the lui/addiu
   pairs are split (hi hoisted, lo later) instead of adjacent, the constant order differs
   (retail: D_1CCFD0, D_001DA1B4, -3, D_001DA1B0, 0, bound), and the loop bound is computed
   from the base register (addiu $t,$base,0x38) instead of retail's independent D_001DA1E8 pair
   (lui/addiu). Also, the source file declares the tables with a known size...
*/

/* func_003BB468 (frontbin).
   The retail PAL build reaches the tables at 0x1DA1B0 / 0x1DA1B4 with lui/addiu, so the
   candidate uses declarations of them whose size the compiler does not know (arrays of
   unspecified size), and not the 8-byte aliases of the US draft, which the compiler
   would place in small data and address through $gp.

   D_001DA1B0_003BB468b is an alias of D_001DA1B0 (0x1DA1B0) declared with an
   unspecified size; D_001DA1B4 (0x1DA1B4) and D_001DA1B4_003BB530 (0x1DA1B4) are the
   file's own declarations of that table.  D_001DA1B0_003BB468 in the source file is
   declared as E_3B5F88[1] (8 bytes), which puts it in small data. */

extern E_3B5F88 D_001DA1B0_003BB468b[];
extern s32 D_001DA1B4_003BB530[];

s32 func_003BB468(s32 id) {
    s32 i;
    s32 fb = (s32)D_001DA1B4;
    for (i = 0; i < 7; i++) {
        if (D_001DA1B0_003BB468b[i].id == id) {
            s32 *t = D_001DA1B4_003BB530;
            s32 f = *(s32 *)(fb + i * 8);
            if (f & 2) {
                if (f & 4) {
                    *(s32 *)(fb + i * 8) = f ^ 4;
                    if (D_1CCFD0_003BB468->f4 != 0) func_003A2558();
                }
                t[i * 2] &= ~2;
                return 0;
            }
        }
    }
    return 0;
}

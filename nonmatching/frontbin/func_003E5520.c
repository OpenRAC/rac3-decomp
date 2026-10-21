/* Near miss of func_003E5520 with its file's own flags: tools/check.py reports 28 diff
   (the version it replaces: 36).
*/

/* PAL candidate for func_003E5520 (frontbin).
   The US draft (rac3-uya-decomp func_003DFFD0) matched with @ps2as and used
   sized declarations, so gcc put every global in small data and reached them
   through $gp.  PAL retail reaches ten of them with lui/%lo instead, and only
   D_001D9C40 through $gp (it sits in the bne delay slot).

   An unsized array is never small data, so it always gets the lui/%lo form.
   The file's own declarations (src/frontbin/3E1340.c) are in scope in front of
   this block and give D_001D9C08/0C/10/14/38 and D_001D9EB4..EBC a size, so
   the lui ones use a per-function alias of the same address (the house rule
   for two blocks of one file needing different types for one symbol).  The
   aliases need an address in config/frontbin/symbol_addrs_resolved.txt, which
   tools/resolve_symbols.py writes from the names the sources use. */

/* localdecomp:start func_003E5520 */
extern u8 D_001A71C4[];
extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D9C40;
extern s32 D_001D9C08_003E5520[];
extern s32 D_001D9C10_003E5520[];
extern s32 D_001D9C14_003E5520[];
extern s32 D_001D9C0C_003E5520[];
extern s32 D_001D9C38_003E5520[];
extern s16 D_001D9EB4_003E5520[];
extern s16 D_001D9EB6_003E5520[];
extern s16 D_001D9EB8_003E5520[];
extern s16 D_001D9EBA_003E5520[];
extern s16 D_001D9EBC_003E5520[];

void func_003E5520(void) {
    D_001D9C08_003E5520[0] = 0;
    D_001D9C10_003E5520[0] = 0;
    D_001D9C14_003E5520[0] = 0;
    D_001D9C0C_003E5520[0] = 0;
    D_001D9C38_003E5520[0] = 0;
    D_001D9C40 = 0;
    if ((D_001A71C4[0] == 1) && !((*(s32 *)((u8 *)(*(void **)0x1D52FC) + 0x1A0)) & 0x10) && (D_001D5B94 != 4) && (D_001D5B90 != 4)) {
        D_001D9EB4_003E5520[0] = 0;
        D_001D9EB6_003E5520[0] = 0;
        D_001D9EB8_003E5520[0] = 0;
        D_001D9EBA_003E5520[0] = 0;
        D_001D9EBC_003E5520[0] = 0;
    }
}
/* localdecomp:end func_003E5520 */

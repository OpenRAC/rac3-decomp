/* Near miss of func_003CE1B0 with its file's own flags: tools/check.py reports 12 diff
   (the version it replaces: 37).
*/

/* US draft of func_003CE1B0 (rac3-uya-decomp func_003C8C40, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003CE1B0 */
extern s32 func_003CE098(s32, s32);
s32 func_003CE3E0_003CE1B0(s32);                         /* extern */

/* Retail reaches D_001DA650, D_001D9D00 and D_001DA5F0 with lui/lw, not
   through $gp. With -mno-split-addresses the compiler only forms an address
   that way for a constant, so the three globals are addressed by the
   addresses their names carry. */
void func_003CE1B0(void) {
    s32 temp_s1;
    s32 temp_s1_2;
    s32 var_s0;

    var_s0 = 0;
    temp_s1 = *(s32 *)0x001D9D00 - *(s32 *)0x001DA650;
    temp_s1_2 = (temp_s1 >= 3) ? 2 : temp_s1;
    if ((*(s16 *)((u8 *)(*(void **)0x001DA5F0) + 6)) > 0) {
        do {
            func_003CE098(var_s0, temp_s1_2);
            func_003CE3E0_003CE1B0(var_s0);
            var_s0 += 1;
        } while (var_s0 < (*(s16 *)((u8 *)(*(void **)0x001DA5F0) + 6)));
    }
    *(s32 *)0x001DA650 = *(s32 *)0x001D9D00;
}
/* localdecomp:end func_003CE1B0 */

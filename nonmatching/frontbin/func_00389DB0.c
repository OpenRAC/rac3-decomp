/* Near miss of func_00389DB0 with its file's own flags: tools/check.py reports 7 diff
   (the version it replaces: 24).
*/

/* US draft of func_00389DB0 (rac3-uya-decomp func_003856D8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */

/* Retail reaches the counter with `lui`/`lw`, not through $gp. A declared global is small data
   here, so the counter is read through its address instead. */


/* localdecomp:start func_00389DB0 */
extern void (*D_00226800[])(s32);
extern s32 D_00226900[];
void func_00389DB0(void) {
    s32 i;
    for (i = 0; i < *(s32 *)0x001D9C08; i++) D_00226800[i](D_00226900[i]);
}
/* localdecomp:end func_00389DB0 */

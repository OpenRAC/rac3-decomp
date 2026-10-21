/* US draft of func_00389E28 (rac3-uya-decomp func_00385750, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00389E28 */
extern s32 D_001D9C10_00389E28;
extern void (*D_00226C00[])(s32);
extern s32 D_00226D00[];
void func_00389E28(void) {
    s32 i;
    for (i = 0; i < D_001D9C10_00389E28; i++) D_00226C00[i](D_00226D00[i]);
}
/* localdecomp:end func_00389E28 */

/* US draft of func_003AA940 (rac3-uya-decomp func_003A53E0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


extern void func_00116F98(s32 *a0, s32 a1, s32 *a2);
/* localdecomp:start func_003AA940 */
extern char D_001D80B0[];
extern char D_001D80C8[];
extern void func_116F98(char *, s32, char *);
void func_003AA940(void *unused, f32 *out, f32 t) {
    if (!out) func_116F98(D_001D80B0, 0x3D, D_001D80C8);
    out[0] = t;
    out[1] = t * 0.5f;
    out[2] = 1.0f - t;
    out[3] = (1.0f - t) * 0.5f;
}
/* localdecomp:end func_003AA940 */

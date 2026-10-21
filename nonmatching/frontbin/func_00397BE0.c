/* US draft of func_00397BE0 (rac3-uya-decomp func_00393380, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_00397BE0 */
__asm__(".extern D_001D5EDC, 1");
__asm__(".extern D_001D5ED8, 4");
extern u8 D_001D5EDC;
extern s32 D_001D5ED8;
extern void func_0038AE20();
void func_00397BE0(void) {
    s32 v;
    f32 t;
    if (D_001D5EDC) {
        D_001D5EDC = 0;
        D_001D5ED8 = D_001D5ED8 + 1;
        if (D_001D5ED8 > 10) D_001D5ED8 = 10;
    } else {
        D_001D5ED8 = D_001D5ED8 - 1;
        if (D_001D5ED8 < 0) D_001D5ED8 = 0;
    }
    t = (f32)D_001D5ED8;
    t = t / 10.0f;
    t = t * 48.0f;
    v = (s32)t;
    if (v) func_0038AE20(0, 0, 0, v);
}
/* localdecomp:end func_00397BE0 */

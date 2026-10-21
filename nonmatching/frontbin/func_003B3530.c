/* US draft of func_003B3530 (rac3-uya-decomp func_003ADF88, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B3530 */
__asm__(".extern D_001D888C, 4");
__asm__(".extern D_001D8894, 4");
extern void func_0039BD08();
extern void func_003B39D8(void);
extern void func_003AE438();
extern void func_003B3E60(void);
extern void func_0013D3C0(s32);
extern s32 D_001D888C;
extern s32 D_001D8894;
extern s32 D_001D4CE8;
void func_003B3530(void) {
    s32 t;
    s32 v;
    switch (D_001D888C) {
    case 0:
        func_0039BD08((void *)func_003B3230, 0, 0);
        func_003AE438();
        D_001D8894 = 0x1E;
        D_001D888C = D_001D888C + 1;
        break;
    case 1:
        func_003AE438();
        v = D_001D8894;
        if (v > 0) { v = v - 1; D_001D8894 = v; }
        D_001D8894 = v;
        if (v == 0) func_003B3E60();
        break;
    case 2:
        t = D_001D4CE8;
        if (t == 1 || t == 0x12) func_0013D3C0(1);
        func_003B39D8();
        break;
    }
}
/* localdecomp:end func_003B3530 */

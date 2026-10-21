/* US draft of func_0013BC30 (rac3-uya-decomp func_0013BC30, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0013BC30 */
__asm__(".extern D_001D4DE8, 4");
__asm__(".extern D_001D4E18, 4");
__asm__(".extern D_001D4DF0, 4");
__asm__(".extern D_001D4DA8, 4");
extern s32 D_001D4DA8;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern char D_001D5018[];
extern void func_0011F698(void *, void *);
extern char D_001D4E98[];
extern s32 func_00122A10();
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_0011F0A0(s32);
void func_0013BC30(s32 a, void *b, unsigned long c) {
    D_001D4DA8 = 0;
    if (D_001D4DE8 != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D5018);
        return;
    }
    *(u32 *)&D_1D4A00 = 0xFFFFFFFFU;
    func_0011F698(&D_1D4A00, &D_1D4A04);
    D_1D4A40 = a;
    D_001D4DF0 = (s32)b;
    *(volatile long *)&D_001D4DF8 = c;
    while (func_00122A10(&D_1D49C0) != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D4E98);
        func_0013B620();
        func_0011F0A0(0);
    }
    D_001D4DE8 = 1;
    func_00122810(&D_1D49C0, 0x57, 1, &D_1D4A40, 4, &D_1D4A00, 4, 0, 0);
}
/* localdecomp:end func_0013BC30 */

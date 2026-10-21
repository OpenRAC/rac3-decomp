/* US draft of func_0013BAB8 (rac3-uya-decomp func_0013BAB8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0013BAB8 */
__asm__(".extern D_001D4DA8, 4");
__asm__(".extern D_001D4DE8, 4");
__asm__(".extern D_001D4E18, 4");
__asm__(".extern D_001D4DF0, 4");
extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_001D4DF0;
extern s32 D_1D4A00;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern s32 D_1D4A44;
extern u8 D_1D49C0_0013BAB8[8];
extern char D_001D4F20[];
extern char D_001D4F50[];
extern char D_001D4F70[];
extern char D_001D4E98[];
extern void func_0011AF48_0013BAB8(char *);
extern s32 func_0013CDF0(s32);
extern void func_0011F698(void *, void *);
extern s32 func_00122A10(void *);
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_11F0A0(s32);
void func_0013BAB8(s32 a, s32 b, void (*cb)(s32, long), long arg) {
    D_001D4DA8 = 0;
    if (D_001D4DE8 != 0) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4F20);
        return;
    }
    if (func_0013CDF0(1) == 1) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4F50);
        return;
    }
    *(u32 *)&D_1D4A00 = 0xFFFFFFFF;
    func_0011F698(&D_1D4A00, &D_1D4A04);
    D_1D4A40 = a;
    D_1D4A44 = b;
    D_001D4DF0 = (s32)cb;
    *(long *)0x1D4DF8 = arg;
    while (func_00122A10(D_1D49C0_0013BAB8) != 0) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4E98);
        func_0013B620();
        func_11F0A0(0);
    }
    D_001D4DE8 = 1;
    func_00122810(D_1D49C0_0013BAB8, 3, 1, &D_1D4A40, 8, &D_1D4A00, 4, 0, 0);
}
/* localdecomp:end func_0013BAB8 */

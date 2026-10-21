/* US draft of func_0013CD28 (rac3-uya-decomp func_0013CD28, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0013CD28 */
__asm__(".extern D_001D4DAC, 4");
__asm__(".extern D_001D4DB4, 4");
__asm__(".extern D_001D4DB8, 4");
extern s32 D_001D4DAC;
extern s32 D_001D4DB4;
extern s32 D_001D4DB8;
extern s32 D_1D4980;
extern s32 D_1D4990_0013CD28;
extern u8 D_1D49BF;
extern s32 func_0012BA20(void);
extern s32 func_0013CDF0(s32);
extern void func_0011F698(void *, void *);
extern s32 func_0013C578();
s32 func_0013CD28(s32 a, s32 b, s32 c) {
    s32 buf[3];
    if (D_001D4DAC == 0) return func_0012BA20();
    if (func_0013CDF0(1) == 1) return 0;
    *(volatile s32 *)&D_1D4980 = 1;
    *(volatile s32 *)&D_1D4990_0013CD28 = 0;
    func_0011F698(&D_1D4980, &D_1D49BF);
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    D_001D4DB4 = 1;
    D_001D4DB8 = 0;
    func_0013C578(0x38, 0xC, buf, 0, 0);
    return 1;
}
/* localdecomp:end func_0013CD28 */

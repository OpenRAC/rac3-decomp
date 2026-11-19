/* functional: high. Compiles at default flags; differs from retail only in scheduling/load style of the 0x1D52FC pointer global. */
/* localdecomp:start func_L01_004BD4A8 */
extern S_00244740 D_L01_002446C0[];
extern u8 D_001E0F30_sda;
extern u8 D_001E0F31_sda;
__asm__(".extern D_001E0F30_sda, 1");
__asm__(".extern D_001E0F31_sda, 1");
extern u8 D_00142430[];
extern u8 *D_L01_001D52FC;
__asm__(".extern D_L01_001D52FC, 16");
extern void func_L01_004BC0F8(u8 *, u8 *);
extern void func_L01_004BCFB0(u8 *, u8 *);
extern void func_L01_004BCAE8(u8 *, u8 *);
extern void func_L01_004BCD08(u8 *, u8 *);
extern s32 func_003B9BD0(s32);
extern void func_003BA4F8(s32, s32);

void func_L01_004BD4A8(void) {
    u8 *L = (u8 *)D_L01_002446C0;
    s32 st;
    s32 a, b;
    if (*(s32 *)(L + 0x84) == 0) return;
    st = *(s32 *)(L + 0x50);
    if (st == 0) {
        if (L[*(s32 *)(L + 0x80) * 0x14 + 0x153] == 0) {
            func_L01_004BC0F8(&D_001E0F30_sda, &D_001E0F31_sda);
            return;
        }
        a = 0;
        if (*(s32 *)(D_00142430 + 0x15C) < 3 && *(s32 *)(D_00142430 + 0x164) < 0 && *(s32 *)(D_00142430 + 8) == 2) {
            a = *(s32 *)(D_00142430 + 0x14) != 0;
        }
        b = 0;
        if (*(s32 *)(D_00142430 + 0x15C) < 3 && *(s32 *)(D_00142430 + 0x164) < 0 && *(s32 *)(D_00142430 + 0xA8) == 2) {
            b = *(s32 *)(D_00142430 + 0xB4) != 0;
        }
        if (a || b) *(s32 *)(L + 0x38) = 4;
        *(s32 *)(L + 0x84) = 0;
    } else if (st == 2) {
        func_L01_004BCFB0(&D_001E0F30_sda, &D_001E0F31_sda);
    } else if (st == 3) {
        func_L01_004BCAE8(&D_001E0F30_sda, &D_001E0F31_sda);
    } else if (st == 5) {
        s32 r = func_003B9BD0(0);
        func_003BA4F8(r, *(s32 *)(D_L01_001D52FC + 0x1C4));
        func_L01_004BCD08(&D_001E0F30_sda, &D_001E0F31_sda);
    }
}
/* localdecomp:end func_L01_004BD4A8 */

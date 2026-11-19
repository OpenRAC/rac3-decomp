/* functional: medium. Rewritten from PAL asm; branch conditions read directly. */
/* localdecomp:start func_L01_004C1EA0 */
extern S_00244740 D_L01_002446C0[];
extern u8 D_00142430[];
extern s32 D_001426A8[];
extern s32 func_L01_004C1E78(void);
extern s32 func_L01_004C1D38(s32);
extern void func_L01_004C21D0(void);
extern void func_L01_004BF660(void);
extern void func_L01_004BAA20(s32);

void func_L01_004C1EA0(void) {
    u8 *u = (u8 *)D_L01_002446C0;
    s32 m, v, a;

    if (*(s32 *)(u + 0x744) == 0) {
        func_L01_004C21D0();
        return;
    }
    switch (*(s32 *)(u + 0x38)) {
    case 0:
    case 1:
        if (*(s32 *)(u + 0x770) != 0) {
            *(s32 *)(u + 0x38) = 6;
            return;
        }
        if (*(s32 *)(D_00142430 + 0x15C) < 3 && *(s32 *)(D_00142430 + 0x164) < 0 &&
            (m = *(s32 *)(D_00142430 + 8)) == 2 && *(s32 *)(D_00142430 + 0x14) != 0 &&
            func_L01_004C1E78() != 0) {
            if (*(s32 *)(D_00142430 + 0x164) < 0) {
                *(s32 *)(D_00142430 + 0x168) = 0;
                *(s32 *)(D_00142430 + 0x164) = 0x18;
            }
            func_L01_004C1D38(0x17F4);
            *(s32 *)(u + 0x38) = (*(s32 *)(u + 0x38) != 1) ? m : 3;
            return;
        }
        if (*(s32 *)(u + 0x38) == 1) func_L01_004C1D38(0x17FD);
        *(s32 *)(u + 0x38) = 6;
        return;
    case 2:
    case 3:
        if (!(*(s32 *)(D_00142430 + 0x15C) < 3)) return;
        if (*(s32 *)(D_00142430 + 0x164) >= 0) return;
        if (func_L01_004C1E78() == 0) return;
        if (((s32 (*)(void))func_L01_004BF660)() != 0) func_L01_004BAA20(0);
        if (*(s32 *)(u + 0x38) == 3) {
            if (D_001426A8[0] & 0x80) {
                if (*(s32 *)(u + 0x778) == 0) func_L01_004C1D38(0x1804);
            } else {
                func_L01_004C1D38(0x17FD);
            }
        }
        v = *(s32 *)(u + 0x778);
        if (v == 1) {
            func_L01_004C1D38(0x1803);
        } else if (!(v < 2)) {
            func_L01_004C1D38(0x1802);
        }
        *(s32 *)(u + 0x38) = 6;
        return;
    case 4:
        if (!(*(s32 *)(D_00142430 + 0x15C) < 3)) return;
        if (*(s32 *)(D_00142430 + 0x164) >= 0) return;
        if (*(s32 *)(D_00142430 + 0xA8) == 2 && *(s32 *)(D_00142430 + 0xB4) != 0) {
            *(s32 *)(D_00142430 + 0x164) = 0x18;
            *(s32 *)(D_00142430 + 0x168) = 1;
            func_L01_004C1D38(0x1B90);
            *(s32 *)(u + 0x38) = 5;
        } else {
            *(s32 *)(u + 0x38) = 1;
        }
        return;
    case 5:
        if (!(*(s32 *)(D_00142430 + 0x15C) < 3)) return;
        if (*(s32 *)(D_00142430 + 0x164) >= 0) return;
        if (func_L01_004C1E78() == 0) return;
        if (((s32 (*)(void))func_L01_004BF660)() != 0) func_L01_004BAA20(0);
        if (D_001426A8[0] & 0x80) {
            v = *(s32 *)(u + 0x778);
            if (v == 0) a = 0x1804;
            else if (v == 1) a = 0x1803;
            else if (v < 2) return;
            else a = 0x1802;
            func_L01_004C1D38(a);
            *(s32 *)(u + 0x38) = 6;
        } else {
            *(s32 *)(u + 0x38) = 1;
        }
        return;
    default:
        return;
    }
}
/* localdecomp:end func_L01_004C1EA0 */

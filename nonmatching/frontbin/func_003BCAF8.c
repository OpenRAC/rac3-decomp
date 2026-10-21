/* US draft of func_003BCAF8 (rac3-uya-decomp func_003B7618, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BCAF8 */
__asm__(".extern D_001D8CD4, 4");
extern s32 D_001D9348;
extern s32 D_001D9364;
extern s32 D_001D9C10;
extern s32 D_001D9C08;
extern s32 D_001D9C0C;
extern s32 D_001A1ED0_3B7618[];
extern u8 D_00100AE0[];
extern u8 D_002FDC00[];
extern void func_003A9440(s32, unsigned long);
extern void func_003BCD50();
extern void func_003873C0();
extern void func_003861F0();
extern void func_003CF0F0();
extern void func_003A9C70(s32);
extern void func_003A96D8();
extern void func_00389240(s32);
extern void func_00389E28();
extern void func_00389370();
extern void func_003A9678();
extern void func_003C3860();
extern void func_00389DB0();
extern void func_11F0A0(s32);
extern void func_003CD3D8();
extern void func_003A8F90();
extern void func_003A92F0(s32);
extern void func_003D0180();
extern void func_003CF050();
extern void func_003C31B0();
extern void func_00389F68();
extern void func_003864C0(s32);
extern void func_003D85C0_003BCAF8(s32);
extern void func_003D8640();
extern void func_003D9260_003BCAF8(s32);
void func_003BCAF8(void) {
    D_001D9348 = 0;
    func_003873C0();
    func_003861F0();
    if (D_001D8CD4 & 1) func_003BCD50();
    if (D_001D8CD4 & 2) {
        func_003CF0F0();
        func_003A9C70(0x2010000);
    }
    if (D_001D9C10) {
        func_003A96D8();
        func_00389240(1);
        func_00389E28();
        func_00389370();
        func_003A9678();
    }
    if (D_001D8CD4 & 0xC) {
        func_003C3860();
        func_003A9C70(0x2080000);
    }
    func_00389240(1);
    if (D_001D9C08) func_00389DB0();
    func_003A96D8();
    func_003A9440(8, 5);
    func_003A9440(0x47, 0x53001);
    func_11F0A0(0);
    func_003CD3D8();
    *(volatile s32 *)&D_001D9D1C = 9;
    func_003A9440(0x47, 0x5360B);
    func_003A8F90(D_00100AE0);
    func_11F0A0(0);
    if (D_001D8CD4 & 2) {
        func_003A92F0(2);
        func_003D0180(D_002FDC00);
        func_003CF050();
    }
    if (D_001D8CD4 & 0xC) {
        func_003A92F0(0x10);
        func_003C31B0();
    }
    func_00389370();
    if (D_001D9C0C) {
        func_00389240(1);
        func_003A9440(0x4E, (D_001A1ED0_3B7618[2] >> 13) | 0x31000000 | 0x100000000UL);
        func_003A96D8();
        func_00389F68();
        func_003A9440(0x4E, 0x31000000 | (D_001A1ED0_3B7618[2] >> 13));
        func_00389370();
    }
    func_003864C0(0);
    if (D_001D9348) {
        func_003D85C0_003BCAF8(0);
        func_003D8640();
    }
    if (D_001D9364) {
        func_003D9260_003BCAF8(0);
        D_001D9364 = 0;
    }
}
/* localdecomp:end func_003BCAF8 */

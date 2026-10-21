/* US draft of func_003A1028 (rac3-uya-decomp func_0039C028, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A1028 */
__asm__(".extern D_001DA050_0039C02A, 4");
extern u32 *D_001DA050_003A1028;
extern u32 *D_001DA050_0039C02A;
extern s32 D_00227400_003A1028[];
extern s32 D_00225700_003A1028[];
extern u32 D_001D4CF8_003A1028;
extern u8 D_001D0560[];
extern void func_0038A3B8();
extern void func_00385E40();
void func_003A1028(u32 *a0) {
    D_001DA050_003A1028 = a0;
    a0[0] = 0x30000009;
    D_001DA050_003A1028[1] = (*(u32 *)0x1D4CF8 + 0xC0) & 0x0FFFFFFF;
    D_001DA050_003A1028[2] = 0;
    D_001DA050_003A1028[3] = 0x50000009;
    D_001DA050_003A1028[4] = 0x30000025;
    D_001DA050_003A1028[5] = (u32)D_001D0560;
    D_001DA050_003A1028[6] = 0;
    D_001DA050_003A1028[7] = 0x50000025;
    D_001DA050_003A1028 += 8;
    D_00225700_003A1028[13] += 1;
    if (D_00227400_003A1028[0] != 0) {
        func_0038A3B8();
        a0 = D_001DA050_0039C02A;
    } else {
        func_00385E40();
        a0 = D_001DA050_003A1028;
    }
    a0[0] = 0x70000000;
    D_001DA050_003A1028[1] = 0;
    D_001DA050_003A1028 += 4;
}
/* localdecomp:end func_003A1028 */

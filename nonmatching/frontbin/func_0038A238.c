/* US draft of func_0038A238 (rac3-uya-decomp func_00385B60, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0038A238 */
extern u32 *D_001DA050_0038A238;
__asm__(".extern D_001DA050_g, 4");
extern u32 *D_001DA050_g;
__asm__(".extern D_001D9BC8_g, 4");
extern s32 D_001D9BC8_g;
extern s32 D_001D9BC8_0038A238;
extern u8 D_00141990[];
extern void func_003A92F0(s32);
extern s32 func_12C908(s32);
extern void func_003A9108(void);
extern void func_003A91D0(void);
extern void func_003A9150();
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_003923D0(void);
extern void func_003A9440(s32, unsigned long);
void func_0038A238(s32 arg0) {
    s32 i;
    s32 t;
    func_003A92F0(1);
    i = arg0 - 1;
    func_12C908(0);
    D_001D9BC8_g = D_001D9BC8_0038A238 + 1;
    func_003A9108();
    while (i >= 0) {
        func_003922B8();
        func_00392350(1);
        func_003923D0();
        func_003A9440(0x42, 0x8000000044UL);
        t = (i << 7) / (i + 1);
        i--;
        func_003A9440(1, (long)(0x80 - t) << 24);
        D_001DA050_0038A238[0] = 0x30000014;
        D_001DA050_0038A238[1] = (u32)D_00141990;
        D_001DA050_0038A238[2] = 0;
        D_001DA050_0038A238[3] = 0x50000014;
        D_001DA050_g = D_001DA050_0038A238 + 4;
        func_003A92F0(1);
        func_12C908(0);
        D_001D9BC8_g = D_001D9BC8_0038A238 + 1;
        func_003A91D0();
        func_003A9150();
    }
    func_003A92F0(1);
    func_12C908(0);
    D_001D9BC8_g = D_001D9BC8_0038A238 + 1;
    func_003A9108();
    func_003922B8();
    func_00392350(1);
}
/* localdecomp:end func_0038A238 */

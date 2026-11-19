/* exact: high.  */
extern u8 *D_001D52FC;
extern void func_L01_004A0F28(s32);
extern void func_L01_0049FBC8(void *);
extern void func_003A5348(s32, s32, s32);
extern void *func_L01_004914D0(s32);
extern void func_L01_00517748(void *);
extern void func_L01_00516090(void *);
void func_L01_004A0430(void *a0) {
    s32 flags = *(s32 *)(D_001D52FC + 0x1C4);
    func_L01_004A0F28(flags);
    if (flags & 0xA040) {
        func_L01_0049FBC8(a0);
    } else if (flags & 0x910) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_004914D0(0));
        func_L01_00516090(a0);
    }
}

/* functional: high. 46 diff at default flags: retail reads D_001D52FC via lui in places where we emit the gp slot; same value. a0 is passed through to func_L01_004A1AC8 (register passthrough, retail leaves it in a0). */
extern u8 *D_001D52FC[];
__asm__(".extern D_L01_001D9660, 4");
extern void *func_L01_0047FE28(void);
extern void *func_L01_004914D0(s32);
extern void *func_L01_00492870(void);
extern void func_003A5348(s32, s32, s32);
extern void func_L01_00516090(s32);
void func_L01_004A1D40(void *a0) {
    s32 flags;
    s32 r;
    if (D_L01_001D9660 >= 0) {
        if (*(s32 *)(D_001D52FC[0] + 0x1C4) & 0x40) {
            func_L01_004A1AC8((s32)a0);
        }
    }
    flags = *(s32 *)(D_001D52FC[0] + 0x1C4);
    if (flags & 0x910) {
        r = (s32)func_L01_0047FE28();
    } else if (flags & 1) {
        func_003A5348(4, 0, 0);
        r = (s32)func_L01_004914D0(0);
    } else if (flags & 2) {
        func_003A5348(4, 0, 0);
        r = (s32)func_L01_00492870();
    } else {
        return;
    }
    func_L01_00517748(r);
    func_L01_00516090((s32)a0);
}

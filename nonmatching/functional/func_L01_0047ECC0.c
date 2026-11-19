/* functional: high. Button-code sequence detector (cheat input): same reads/writes/calls and order as retail; the toggle at +0xC1 and the mirrored byte D_001D5479 are written before the call as in retail. Not byte-checked. */
typedef struct {
    u8 pad0[0x1C4];
    u32 buttons;
} S_Pad1C4;
extern S_Pad1C4 *D_001D52FC;
extern s32 D_001D82B4;
extern s32 D_001D8290[];
extern u8 D_001426E0[];
extern u8 D_001D5479;

extern void func_0039EF28(void);
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_0047FE28(void);
extern void func_L01_00516090(void *);

void func_L01_0047ECC0(void) {
    u32 btn = D_001D52FC->buttons;
    s32 idx;

    if ((btn & 0xF0A0) == 0) {
        return;
    }
    idx = D_001D82B4;
    if (btn == (u32)D_001D8290[idx]) {
        idx++;
        D_001D82B4 = idx;
        if (D_001D8290[idx] != -1) {
            return;
        }
        if (D_001426E0[0xC1] != 0) {
            D_001426E0[0xC1] = 0;
            func_0039EF28();
            D_001D5479 = 0;
        } else {
            D_001426E0[0xC1] = 1;
            func_0039EF28();
            D_001D5479 = 1;
        }
        func_003A5348(4, 0, 0);
        D_001D82B4 = 0;
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090((void *)func_L01_0047FE28());
    } else {
        D_001D82B4 = 0;
        if (btn == (u32)D_001D8290[0]) {
            D_001D82B4 = 1;
        }
    }
}

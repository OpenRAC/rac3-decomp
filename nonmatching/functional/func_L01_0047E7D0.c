/* functional: high. Level-state apply/refresh: when the pending item (+0x50) differs from the current one (+0x60) it runs the item-change calls (func_0039AA38 on the item's +0x10 word, func_L01_005078C0) bracketed by func_003A2750(1); then re-applies the saved screen state (D_001D4BB4 = state+0x80, func_00393168, three func_L01_0041C4A0 steps depending on D_L01_001DFD18 fields +0x80/+0x84) and finishes through func_L01_005178A0/func_L01_00517830/func_L01_00516090(a0). Same calls, arguments and order as retail; the gp store D_001D4BB4 is done before func_00393168 as in the delay slot. Not byte-checked. */
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0xDC];
} S_002C5600_0047E7D0;
extern u8 D_L01_002E9F98[];
extern u8 D_001425C0[];
extern S_002C5600_0047E7D0 D_L01_002C5600[];
extern u8 *D_L01_001DFD18;
extern s32 D_001D4BB4;

extern void func_003A2750(s32);
extern void func_0039AA38(s32);
extern void func_L01_005078C0(s32);
extern void func_003A92F0(s32);
extern void func_003A9108(void);
extern void func_00393168(s32, s32, s32);
extern void func_L01_0041C4A0(s32);
extern void func_003A91D0(void);
extern s32 func_L01_005178A0(s32 *);
extern s32 func_L01_00517830(s32);
extern void func_L01_00516090(s32);

void func_L01_0047E7D0(s32 a0) {
    s32 *S = (s32 *)D_L01_002E9F98;
    s32 tmp;
    s32 v3;

    if (S[0x50 / 4] != 0 && S[0x60 / 4] != S[0x50 / 4]) {
        func_003A2750(1);
        func_0039AA38(D_L01_002C5600[D_001425C0[S[0x50 / 4]]].w10);
        func_L01_005078C0(S[0x50 / 4]);
        func_003A2750(1);
    }
    func_003A92F0(1);
    func_003A9108();
    D_001D4BB4 = S[0x80 / 4];
    func_00393168(0, *(s32 *)(D_L01_001DFD18 + 0x74), 0);
    func_L01_0041C4A0(2);
    v3 = *(s32 *)(D_L01_001DFD18 + 0x80);
    if (v3 != 0) {
        func_L01_0041C4A0(3);
        v3 = *(s32 *)(D_L01_001DFD18 + 0x84);
    } else {
        v3 = *(s32 *)(D_L01_001DFD18 + 0x84);
    }
    if (v3 != 0) {
        func_L01_0041C4A0(4);
    }
    func_003A91D0();
    func_003A92F0(1);
    tmp = 0;
    func_L01_005178A0(&tmp);
    func_L01_00517830(tmp);
    func_L01_00516090(a0);
}

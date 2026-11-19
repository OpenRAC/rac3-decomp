/* functional: high. Same control flow, reads, writes and calls in the same order; retail leaves buttons in a0 for func_0047EBE0 but its matched callers declare it void(void) so no argument is passed. */
extern u8 *D_001D52FC[];
extern s32 D_L01_001D8BE0;
extern u8 D_L01_001D672C[];
extern void func_L01_0047EC88(void);
extern s32 func_L01_0047EBE0(void);
extern s32 func_L01_0047FE28(void);
extern s32 func_L01_00489FD0(void);
extern s32 func_L01_004914D0(s32);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(s32);
extern void func_L01_005170B8(s32, s32);
extern void func_003A5348(s32, s32, s32);
extern s32 func_003825F8(s32, s32, s32, s32, s32, s32);
extern void func_L01_0048BFC8(void);

void func_L01_0048D588(s32 a0) {
    s32 buttons;
    s32 old;
    s32 v;
    s32 r;

    func_L01_0047EC88();
    buttons = *(s32 *)(D_001D52FC[0] + 0x1C4);
    old = D_L01_001D8BE0;
    if (buttons & 0x800) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090(a0);
    } else if (buttons & 0x10) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0047FE28());
        func_L01_00516090(a0);
    } else if (buttons & 0x1000) {
        func_003A5348(3, 0, 0);
        v = D_L01_001D8BE0;
        D_L01_001D8BE0 = v - 5;
        if (v - 5 < 0) {
            D_L01_001D8BE0 = v + 5;
        }
    } else if (buttons & 0x4000) {
        func_003A5348(3, 0, 0);
        v = D_L01_001D8BE0;
        D_L01_001D8BE0 = v + 5;
        if (v + 5 >= 10) {
            D_L01_001D8BE0 = v - 5;
        }
    } else if (buttons & 0x8000) {
        func_003A5348(3, 0, 0);
        v = D_L01_001D8BE0 - 1;
        D_L01_001D8BE0 = v;
        if (v < 0) {
            D_L01_001D8BE0 = 4;
        } else if (v == 4) {
            D_L01_001D8BE0 = 9;
        }
    } else if (buttons & 0x2000) {
        func_003A5348(3, 0, 0);
        v = D_L01_001D8BE0 + 1;
        D_L01_001D8BE0 = v;
        if (v >= 10) {
            D_L01_001D8BE0 = 5;
        } else if (v == 5) {
            D_L01_001D8BE0 = 0;
        }
    } else if (buttons & 1) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_00489FD0());
        func_L01_00516090(a0);
    } else if (buttons & 2) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_004914D0(0));
        func_L01_00516090(a0);
    }
    if (D_L01_001D8BE0 != old) {
        func_L01_005170B8(old + 0x25, 0x332299DE);
        func_003825F8(0x332299DE, 0x8066CCFF, 0x28, 0, 1, 1);
    }
    r = func_003825F8(0x332299DE, 0x8066CCFF, 0x28, 0, 0, 1);
    func_L01_005170B8(D_L01_001D8BE0 + 0x25, r);
    func_L01_0048BFC8();
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090(a0);
        if (D_L01_001D672C[0] == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}

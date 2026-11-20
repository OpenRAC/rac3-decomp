/* functional: high. Per-frame update of the item grid screen (10 columns x 2 rows): refreshes the detail panel, handles buttons (0x800/0x10 close, d-pad moves the column mod 10 / row mod 2 with sound 3, X plays 4 and opens the item or plays 5 if locked, 0x1 and 0x2 open sub-screens), positions the cursor widget 0xE0013 per visible cell, recolours the previously selected cell back to 0x8066CCFF and the new one to 0x80FFFFFF, and when the selection changed refreshes the item name widget and icon. func_L01_0047EDB0 is called with (item index, buttons) as retail leaves them in a0/a1. Not byte-checked. */
typedef struct {
    u8 pad0;
    u8 tier;
    u8 pad2[0xEE];
} S_002C5600_004863D8;
typedef struct {
    u8 pad0[0x24];
    s32 x24;
} S_2EA2D8Cell_004863D8;
typedef struct {
    u8 pad0[0x1C4];
    u32 buttons;
} S_Pad1C4;
extern S_Pad1C4 *D_001D52FC;
extern S_002C5600_004863D8 D_L01_002C5600_004863D8[];
extern u8 D_001425C0[];
extern u8 D_00142CA0[];
extern u8 D_L01_002EA2D8_004863D8[];
extern u8 D_L01_001D8558;
extern s32 D_L01_001D855C;
extern s32 D_L01_001D8560;
extern s32 D_L01_001D8564;
extern s32 D_L01_001D8568;
extern f32 D_L01_001D85AC;
extern f32 D_L01_001D85B0;
extern f32 D_L01_001D85B4;
extern f32 D_L01_001D85B8;
extern u8 D_L01_001D672C;

extern void func_L01_0047EC88(void);
extern void func_L01_00486340(void);
extern void func_003BB5D0(void);
extern void func_003BB590(s32);
extern void func_L01_00485D00(void);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(s32);
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_0047FE28(void);
extern s32 func_L01_00485A38(s32, s32);
extern void func_L01_0047EC38(s32);
extern s32 func_L01_0048EE70(void);
extern s32 func_L01_00487EB0(void);
extern void func_L01_0047EDB0(s32, u32);
extern void func_L01_00485B18(void);
extern void func_L01_004861C0(void);
extern void func_L01_00486248(void);
extern s32 func_L01_004869D8(s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00485A60(s32, s32);
extern s32 func_L01_00485A10(s32, s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00517D18(s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);

void func_L01_004863D8(s32 a0) {
    u32 btn;
    s32 i, j, idx;
    f32 f0, f2, f12;
    s32 closeV = 0;
    s32 doClose = 0;

    func_L01_0047EC88();
    func_L01_00486340();
    func_003BB5D0();
    func_003BB590(0xE000B);
    func_L01_00485D00();
    btn = D_001D52FC->buttons;
    if (btn & 0x800) {
        closeV = func_L01_0047EBE0();
        doClose = 1;
    } else if (btn & 0x10) {
        func_003A5348(4, 0, 0);
        closeV = func_L01_0047FE28();
        doClose = 1;
    } else if ((btn & 0x1000) || (btn & 0x4000)) {
        s32 t;
        func_003A5348(3, 0, 0);
        D_L01_001D8558 = 1;
        t = D_L01_001D8560 + 1;
        D_L01_001D8560 = t - (t / 2) * 2;
    } else if (btn & 0x8000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8558 = 1;
        D_L01_001D855C = (D_L01_001D855C + 9) % 10;
    } else if (btn & 0x2000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8558 = 1;
        D_L01_001D855C = (D_L01_001D855C + 1) % 10;
    } else if (btn & 0x40) {
        idx = func_L01_00485A38(D_L01_001D855C, D_L01_001D8560);
        if (D_00142CA0[idx] != 0) {
            func_003A5348(4, 0, 0);
            func_L01_0047EC38(func_L01_00485A38(D_L01_001D855C, D_L01_001D8560));
        } else {
            func_003A5348(5, 0, 0);
        }
    } else if (btn & 0x1) {
        func_003A5348(4, 0, 0);
        closeV = func_L01_0048EE70();
        doClose = 1;
    } else if (btn & 0x2) {
        func_003A5348(4, 0, 0);
        closeV = func_L01_00487EB0();
        doClose = 1;
    }
    if (doClose) {
        func_L01_00517748(closeV);
        func_L01_00516090(a0);
    }
    idx = func_L01_00485A38(D_L01_001D855C, D_L01_001D8560);
    func_L01_0047EDB0(idx, D_001D52FC->buttons);
    func_L01_00485B18();
    func_L01_004861C0();
    func_L01_00486248();
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 2; j++) {
            if (func_L01_004869D8(i, j) != 0) {
                f2 = D_L01_001D85AC + D_L01_001D85B0 * (f32)i;
                f12 = f2 + 0.001953f;
                if (j == 0) {
                    f0 = D_L01_001D85B4;
                } else {
                    f0 = D_L01_001D85B8 - 0.002404f;
                }
                func_L01_00516470(0xE0013, f12, f0 - 0.004808f);
            }
        }
    }
    if (D_L01_001D8564 != D_L01_001D855C || D_L01_001D8568 != D_L01_001D8560) {
        if (D_L01_001D8564 >= 0 && D_L01_001D8568 >= 0) {
            s32 r = func_L01_00485A60(D_L01_001D8564, D_L01_001D8568);
            func_L01_005170B8(func_L01_00485A10(r, 0xE002D, 0xE0038), 0x8066CCFF);
        }
        {
            s32 r = func_L01_00485A60(D_L01_001D855C, D_L01_001D8560);
            func_L01_005170B8(func_L01_00485A10(r, 0xE002D, 0xE0038), 0x80FFFFFF);
        }
        D_L01_001D8564 = D_L01_001D855C;
        D_L01_001D8568 = D_L01_001D8560;
    }
    if (D_L01_001D8558 != 0) {
        idx = func_L01_00485A38(D_L01_001D855C, D_L01_001D8560);
        D_L01_001D8558 = 0;
        func_L01_005170B8(0xE000B, 0x402299DE);
        func_L01_00485D00();
        func_L01_00517D18(0xE0008);
        if (D_00142CA0[idx] != 0) {
            s32 r;
            func_L01_00516D60(0xE0012, 1);
            r = func_L01_00485A60(D_L01_001D855C, D_L01_001D8560);
            func_L01_00517190(0xE0012, ((S_2EA2D8Cell_004863D8 *)(D_L01_002EA2D8_004863D8 + (D_L01_002C5600_004863D8[D_001425C0[idx]].tier * 4 + r * 0x44)))->x24 + 1);
        } else {
            func_L01_00516D60(0xE0012, 1);
            func_L01_00517190(0xE0012, 0x65);
        }
    }
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090(a0);
        if (D_L01_001D672C == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}

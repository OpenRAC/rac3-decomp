/* functional: high. Options-screen input: highlights the selected row's cursor, X toggles the row's on/off flag (+0xD) into the saved options array (D_001D5468[row type]), mirroring types 10 and 11 into two extra bytes, then replays the row colour; back button (0x10) leaves via the close handlers. Same reads/writes/calls and order as retail; not byte-checked. */
typedef struct {
    s32 strId;
    s32 type;
    s32 arg;
    u8 on;
    u8 on2;
    u8 pad[2];
    s32 (*check)(s32);
    s32 pad14;
} OptRow_00480800;
typedef struct {
    u8 pad0[0x1C4];
    u32 buttons;
} S_Pad1C4;
extern S_Pad1C4 *D_001D52FC;
extern OptRow_00480800 D_L01_002EA230[];
extern u8 D_001D5468[];
extern u8 D_001D5470;
extern u8 D_001D5471;
extern u8 D_001D672C;

extern s32 func_003B9BD0(s32);
extern void func_003BA4F8(s32, u32);
extern s32 func_003B9C58(s32);
extern s32 func_L01_00517190(s32, s32);
extern void func_003A5348(s32, s32, s32);
extern void func_L01_00498948(s32, s32, s32);
extern s32 func_L01_00492870(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(s32);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern s32 func_L01_0047EBE0(void);

void func_L01_00480800(s32 a0) {
    s32 idx;
    OptRow_00480800 *row;
    u32 btn;

    func_003BA4F8(func_003B9BD0(0), D_001D52FC->buttons);
    idx = func_003B9C58(func_003B9BD0(0));
    row = &D_L01_002EA230[idx];
    if (row->on != 0) {
        func_L01_00517190(0x520003, *(s32 *)((u8 *)row + 0x14));
    } else {
        func_L01_00517190(0x520003, 1);
    }
    btn = D_001D52FC->buttons;
    if (btn & 0x40) {
        s32 sel = func_003B9C58(func_003B9BD0(0));
        row = &D_L01_002EA230[sel];
        if (row->on != 0) {
            u8 v = row->on2 ^ 1;
            row->on2 = v;
            D_001D5468[row->type] = v;
            if (row->type == 10) {
                D_001D5470 = v;
            }
            if (row->type == 11) {
                D_001D5471 = row->on2;
            }
            func_003A5348(4, 0, 0);
            func_L01_00498948(func_003B9BD0(0), sel, row->on2 ? 3 : 0);
        }
    } else if (btn & 0x10) {
        func_L01_00517748(func_L01_00492870());
        func_L01_00516090(a0);
        func_003A5348(4, 0, 0);
    }
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090(a0);
        if (D_001D672C == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}

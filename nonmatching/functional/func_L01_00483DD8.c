/* functional: high. Per-frame input for the 3-entry popup: up/down move the selection over enabled rows with wraparound (sound 3), X calls the row's callback (+0xC), closes via func_L01_00516090 and plays sound 4, back buttons close, then places the cursor at the selected row and colours the 3 rows (enabled 0x80808080, disabled 0x80303030). The row callback is called with no arguments (retail leaves a stale a0 = row offset). Not byte-checked. */
typedef struct {
    s32 id;
    s32 pad4;
    u8 enabled;
    u8 pad9[3];
    void (*onSelect)(void);
} PopupRow_00483DD8;
typedef struct {
    u8 pad0[0x1C4];
    u32 buttons;
} S_Pad1C4;
extern S_Pad1C4 *D_001D52FC;
extern PopupRow_00483DD8 D_001D84B0[];
extern s32 D_001D84E0;
extern f32 D_001D8504;

extern void func_L01_0047EC88(void);
extern void func_003A5348(s32, s32, s32);
extern void func_L01_00516090(s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);

void func_L01_00483DD8(s32 a0) {
    u32 btn;
    s32 sel;
    s32 found;
    f32 half = 0.5f;
    f32 f1;
    PopupRow_00483DD8 *row;
    s32 n;

    func_L01_0047EC88();
    btn = D_001D52FC->buttons;
    if (btn & 0x4000) {
        found = 0;
        sel = D_001D84E0;
        do {
            sel++;
            D_001D84E0 = sel;
            if (!(sel < 3)) {
                D_001D84E0 = 0;
            }
            sel = D_001D84E0;
            if (D_001D84B0[sel].enabled != 0) {
                found = 1;
            }
        } while (found == 0);
        func_003A5348(3, 0, 0);
    } else if (btn & 0x1000) {
        found = 0;
        sel = D_001D84E0;
        do {
            sel--;
            D_001D84E0 = sel;
            if (sel < 0) {
                D_001D84E0 = 2;
            }
            sel = D_001D84E0;
            if (D_001D84B0[sel].enabled != 0) {
                found = 1;
            }
        } while (found == 0);
        func_003A5348(3, 0, 0);
    } else if (btn & 0x40) {
        row = &D_001D84B0[D_001D84E0];
        if (row->enabled != 0 && row->onSelect != 0) {
            row->onSelect();
            func_L01_00516090(a0);
            func_003A5348(4, 0, 0);
        }
    } else if (btn & 0x910) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090(a0);
    }
    f1 = D_001D8504;
    func_L01_00516470(0xD0028, half, (half - f1) + (f32)D_001D84E0 * f1);
    row = D_001D84B0;
    n = 2;
    do {
        n--;
        if (row->enabled != 0) {
            func_L01_005170B8(row->id, 0x80808080);
        } else {
            func_L01_005170B8(row->id, 0x80303030);
        }
        row++;
    } while (n >= 0);
}

/* functional: high. Menu input handler: d-pad up/down moves the selection skipping disabled rows (wrap-around), cross runs the row's callback (+0xC) and plays sound 4, other buttons play the back/cancel path, then redraws the highlights. The row callback is called with the list pointer and row count in a0/a1 as retail leaves them (callee prototypes unknown). Not byte-checked. */
typedef struct {
    s32 id;
    s32 pad4;
    u8 enabled;
    u8 pad9[3];
    void (*onSelect)();
    u8 closes;
    u8 pad11[3];
} MenuRow_0047FAC8;
typedef struct {
    u8 pad0[0x1C4];
    u32 buttons;
} S_Pad1C4;
extern S_Pad1C4 *D_001D52FC;
extern MenuRow_0047FAC8 *D_001D82E0;
extern s32 D_001D82E8;
extern s32 D_001D82EC;
extern f32 D_001D8300;
extern f32 D_001D8304;
extern f32 D_001D8308;
extern f32 D_001D830C;
extern u8 D_001D672C;

extern void func_L01_0047EC88(void);
extern void func_L01_0047ECC0(void);
extern s32 func_L01_0047F220(void);
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern void func_003BB5D0(void);
extern void func_003BB590(s32);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);

void func_L01_0047FAC8(s32 a0) {
    u32 btn;
    s32 cnt;
    s32 i;
    f32 f20;

    func_L01_0047EC88();
    func_L01_0047ECC0();
    if (func_L01_0047F220() != 0) {
        return;
    }
    btn = D_001D52FC->buttons;
    cnt = D_001D82EC;
    if (btn & 0x4000) {
        s32 found = 0;
        s32 sel = D_001D82E8;
        do {
            sel++;
            D_001D82E8 = sel;
            if (!(sel < cnt)) {
                D_001D82E8 = 0;
            }
            sel = D_001D82E8;
            if (D_001D82E0[sel].enabled != 0) {
                found = 1;
            }
        } while (found == 0);
        func_003A5348(3, 0, 0);
    } else if (btn & 0x1000) {
        s32 found = 0;
        s32 last = cnt - 1;
        s32 sel = D_001D82E8;
        do {
            sel--;
            D_001D82E8 = sel;
            if (sel < 0) {
                D_001D82E8 = last;
            }
            sel = D_001D82E8;
            if (D_001D82E0[sel].enabled != 0) {
                found = 1;
            }
        } while (found == 0);
        func_003A5348(3, 0, 0);
    } else if (btn & 0x40) {
        MenuRow_0047FAC8 *row = &D_001D82E0[D_001D82E8];
        if (row->enabled != 0 && row->onSelect != 0) {
            row->onSelect(D_001D82E0, cnt);
            row = &D_001D82E0[D_001D82E8];
            if (row->closes != 0) {
                func_L01_00516090(a0);
            }
            func_003A5348(4, 0, 0);
        }
    } else if (btn & 0x910) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090(a0);
    }
    cnt = D_001D82EC;
    f20 = 0.5f - (f32)(cnt - 1) * 0.03f;
    func_L01_00517538(0xD0028, D_001D8304, D_001D8300);
    func_L01_00516470(0xD0028, D_001D830C, f20 + (f32)D_001D82E8 * D_001D8308);
    if (D_001D82EC > 0) {
        for (i = 0; ; ) {
            MenuRow_0047FAC8 *row = &D_001D82E0[i];
            if (row->enabled != 0) {
                func_L01_005170B8(row->id, 0x8066CCFF);
                if (i == D_001D82E8) {
                    func_L01_005170B8(D_001D82E0[i].id, 0x66D6EEFA);
                }
            } else {
                func_L01_005170B8(row->id, 0x80808080);
            }
            i++;
            if (!(i < D_001D82EC)) {
                break;
            }
        }
    }
    func_003BB5D0();
    func_003BB590(0xD0028);
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090(a0);
        if (D_001D672C == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}

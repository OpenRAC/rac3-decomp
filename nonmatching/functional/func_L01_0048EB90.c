/* functional: high. D_001D545C is passed to func_003BB0E8 as in retail (loaded in the jal delay slot). */
typedef struct { s32 w0; u8 pad4[4]; s32 w8; s32 wC; u8 b10; u8 pad11[3]; } Row_0048EB90;
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern s32 D_L01_001D8C80;
extern s32 D_L01_001D8C84;
extern f32 D_L01_001D8CB0;
extern f32 D_L01_001D8CB4[];
extern f32 D_L01_001D8CB8;
extern f32 D_L01_001D8CBC[];
extern s32 D_L01_001D8C30;
extern s32 D_L01_001E0958[];
extern u8 D_L01_001D672C[];
extern void func_0039EF28(void);
extern void func_L01_0048DF60(void);
extern void func_L01_0048E028(void);
extern void func_L01_0048DE98(void);
extern void func_L01_0048D9E8(void);
extern void func_L01_0048BF30(void);
extern void func_L01_0048BF28(s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_0047DB60(void);
extern s32 func_L01_0048FB98(void);
extern s32 func_L01_0047FE28(void);
extern s32 func_L01_0048A028(void);
extern void func_003BB0E8(s32);
extern s32 func_L01_0047EBE0(void);
extern s32 func_L01_00486980(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(s32);
extern void func_003BB5D0(void);
extern void func_L01_0048EA10(void);
extern void func_L01_0048EB88(void);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);

void func_L01_0048EB90(s32 a0) {
    Row_0048EB90 *row;
    s32 buttons;
    s32 v;

    func_0039EF28();
    func_L01_0048DF60();
    func_L01_0048E028();
    func_L01_0048DE98();
    func_L01_0048D9E8();
    row = (Row_0048EB90 *)(D_L01_001D8C84 + D_L01_001D8C80 * 0x14);
    if (row->w8 == 0x8D4) {
        func_L01_0048BF30();
    } else {
        func_L01_0048BF28(row->b10);
    }
    func_L01_00516470(0x160000, D_L01_001D8CB0, D_L01_001D8CB4[0]);
    func_L01_00517538(0x160000, D_L01_001D8CB8, D_L01_001D8CBC[0]);
    buttons = *(s32 *)(D_001D52FC + 0x1C4);
    if (buttons & 0x10) {
        func_003A5348(4, 0, 0);
        if (D_L01_001D8C30 == 0) {
            if (func_L01_0047DB60() == 2) {
                v = func_L01_0048FB98();
            } else {
                v = func_L01_0047FE28();
            }
            func_L01_00517748(v);
        } else {
            func_L01_00517748(func_L01_0048A028());
        }
        func_L01_00516090(a0);
    } else if (buttons & 0xD00) {
        if (D_L01_001D8C30 != 0) {
            func_003BB0E8(D_001D545C);
        }
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090(a0);
    } else if (D_L01_001D8C30 == 0) {
        if (func_L01_0047DB60() != 2) {
            if (*(s32 *)(D_001D52FC + 0x1C4) & 2) {
                func_003A5348(4, 0, 0);
                func_L01_00517748(func_L01_00486980());
                func_L01_00516090(a0);
            }
        }
    }
    func_003BB5D0();
    if (D_L01_001E0958[0] == 0) {
        func_L01_0048EA10();
    }
    func_L01_0048EB88();
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090(a0);
        if (D_L01_001D672C[0] == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}

/* high: Same logic as func_L01_0040B300 twice over; bytes differ only in saved-register/address CSE.. Veldin-shared: two-pass setup of a 4-point interpolated vertex strip: for each of two arrays calls func_L01_0040B0B0 (fills D_L01_001DFAA0 tables, returns fractional t), optionally stores t back, then submits via func_003D3A24 after a GS-state call func_003A9440(0x42,...) */
extern s32 D_L01_001DFA90[];
extern f32 D_L01_001DFA60[];
extern u8 D_L01_001DFAA0[];
extern f32 func_L01_0040B0B0(s32 a0, f32 f12, f32 *a1, s32 a2);
extern void func_003A9440(s32 a0, long a1);
extern void func_003D3A24(s32 a0, u8 *a1, u8 *a2, u8 *a3, s32 t0);
void func_L01_0040B1F0(s32 a0, f32 *a1, f32 *a2, s32 a3, s32 t0, s32 t1, f32 f12) {
    f32 f;
    func_003A9440(66, 0x800000006AUL);
    f = func_L01_0040B0B0(a0, f12, a1, t0);
    if (a3 != 0) {
        *a1 = f;
    }
    func_003D3A24(4, ((u8 *)&D_L01_001DFA60), ((u8 *)&D_L01_001DFA90), D_L01_001DFAA0, 1);
    func_003A9440(66, 0x8000000058UL);
    f = func_L01_0040B0B0(a0, f12, a2, t1);
    if (a3 != 0) {
        *a2 = f;
    }
    func_003D3A24(4, ((u8 *)&D_L01_001DFA60), ((u8 *)&D_L01_001DFA90), D_L01_001DFAA0, 1);
}

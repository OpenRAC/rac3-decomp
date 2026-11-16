/* Near miss: game_mode_apply. Everything matches except (1) retail keeps idx*0x14C in $s1 (mult $s1,$v0,$a0) and recomputes base+prod each use, this merges it into one register, and (2) retail reloads D_L01_001D6720 after the D_L01_001DF950 = 1.0f store, this reuses $f0. The two jump-table words differ only as relocations. */
#include "common.h"
typedef struct {
    u8 pad0[0x5E];
    s16 h5E;
} S_459F60;

extern s32 D_L01_001D6690;
extern s32 D_L01_001D6694;
extern s32 D_L01_001D668C;
extern s32 D_L01_001D6674;
extern f32 D_L01_001D6720;
extern u8 D_L01_001D672D;
extern s32 D_001D545C;
extern s32 D_001D4CEC;
extern s32 D_001A7430[];
extern u8 D_00160C40[];
extern s16 D_0016C5A6[];
extern s16 D_001CCFD4[];
extern s32 D_L01_001D7DBC;
extern s32 D_L01_001D7DC0;
extern s32 D_L01_001D7DC4;
extern u8 *D_L01_001D7DCC;
extern s32 D_L01_001D9730;
extern s32 D_L01_001D9928;
extern s32 D_L01_001D9A74;
extern s32 D_L01_001D9A7C;
extern f32 D_L01_001DF950;
extern s32 D_L01_001DFB44;
extern s32 D_L01_001DFB54;
extern s32 D_L01_001E1070;
extern S_459F60 D_L01_001E6D80;
extern f32 D_L01_001E7630[];
extern s32 D_L01_001EA94C;

extern void func_L01_004C8BE8(void);
extern void func_L01_0047E568(void);
extern void func_L01_00415D78(void);
extern void func_003A8A58(void);
extern void func_L01_004B9D20(void);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_003873C0(void);
extern void func_L01_004ACDB0(void);
extern void func_L01_004BBD90(void);
extern void func_L01_004A3548(void);
extern void func_L01_004C97C8(void);
extern void func_L01_00423000(void);
extern void func_L01_0045A530(s32);
extern s32 func_L01_00415CC0(void);
extern void func_L01_0047DDC8(s32);
extern void func_L01_00415DD8(s32, s32);
extern void func_003A88B8(s32);
extern void func_L01_0045F328(s32);
extern void func_003A2750(s32);
extern s32 func_003A8770(s32);
extern void func_003A9050(void);
extern void func_003A2598(s32, s32, s32);
extern void func_003C4138(void *, f32, f32);
extern void func_L01_004B9810(s32);
extern void func_L01_004ACBC8(s32);
extern s32 func_00392DF0();
extern void func_L01_004ACD40(void);
extern void func_L01_004ACB38(void);
extern void func_L01_004BB4E0(s32);
extern void func_L01_004A34A8(s32, s32);
extern void func_L01_004C9500(void);
extern void func_003B3218(s32);
extern void func_L01_00422FE0(void);

/* game_mode_apply: leaves the old game mode (D_L01_001D6694) for the one asked for (D_L01_001D6690). */
void func_L01_00459F60(void) {
    s32 prev;
    s32 next;
    s32 stay;

    func_L01_004C8BE8();
    prev = D_L01_001D6694;
    next = D_L01_001D6690;
    D_L01_001D668C = prev;
    if (next == -2) {
        return;
    }
    if (D_L01_001D7DBC > 0) {
        D_L01_001D7DBC = D_L01_001D7DBC - 1;
        return;
    }
    if (!((prev == 0 && (D_001D4CEC & 1)) || (prev == 4 && next == 0))) {
        if (D_001A7430[0] == 0) {
            return;
        }
    }
    switch (D_L01_001D6694) {
    case 3:
        if (D_L01_001D6690 != 4 || D_L01_001D7DC0 == 8) {
            func_L01_0047E568();
        }
        break;
    case 4:
        func_L01_00415D78();
        break;
    case 1:
        func_003A8A58();
        D_L01_001E7630[0] = 0.62f;
        func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_003873C0();
        break;
    case 2:
        func_L01_004B9D20();
        D_L01_001E7630[0] = 0.62f;
        func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_003873C0();
        break;
    case 6:
        if (D_L01_001D7DC0 != 4) {
            func_L01_004ACDB0();
        }
        break;
    case 5:
        func_L01_004BBD90();
        break;
    case 7:
        func_L01_004A3548();
        break;
    case 8:
        func_L01_004C97C8();
        break;
    case 9:
        func_L01_00423000();
        break;
    case 0: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        break;
    }
    stay = 0;
    func_L01_0045A530(10);
    switch (D_L01_001D6690) {
    case 3: {
        s32 k = D_L01_001D668C;
        if (k != 4 || func_L01_00415CC0() == 8 || (D_L01_001D668C == k && func_L01_00415CC0() == 11) || D_L01_001D672D != 0) {
            func_L01_0047DDC8(D_L01_001D7DC0);
        }
        stay = 0;
    }
    case 0:
        stay = 0;
        break;
    case 4:
        func_L01_00415DD8(D_L01_001D7DC0, D_L01_001D7DC4);
        break;
    case 1:
        stay = 0;
        func_003A88B8(D_L01_001D7DC4);
        break;
    case 2:
        if (D_L01_001D6694 - 1 >= 2U) {
            if (D_L01_001E6D80.h5E == 0) {
                D_L01_001E6D80.h5E = 1;
                if (D_L01_001DF950 > D_L01_001D6720) {
                    D_L01_001D6720 = D_L01_001DF950;
                }
                func_L01_0045F328(0);
                func_003A2750(0);
                if (D_L01_001D6720 < 0.25f) {
                    s32 idx = func_003A8770(D_L01_001D7DC0);
                    u8 *base;
                    s32 off;
                    base = D_00160C40;
                    base += 0x8000;
                    off = idx * 0x14C;
                    if (*(s32 *)(base + off + 0x1254) > 0) {
                        if (D_001CCFD4[0] != 0) {
                            func_003A2750(1);
                        }
                        func_003A9050();
                        D_L01_001E1070 = D_L01_001E1070 - 0x1000;
                        func_003A2598(D_L01_001EA94C + D_L01_001E1070, *(s32 *)(base + off + 0x1250) + *(s32 *)(base + 0x121C), 1);
                    }
                }
            }
            func_003C4138(&D_L01_001D6720, 1.12f, 0.060000002f);
            D_L01_001DF950 = D_L01_001D6720;
            if (1.0f < D_L01_001D6720) {
                D_L01_001DF950 = 1.0f;
            }
            if (D_L01_001D6720 >= 1.12f) {
                stay = 0;
                D_L01_001D6720 = 1.0f;
                func_L01_004B9810(D_L01_001D7DC0);
            } else {
                stay = 1;
            }
        } else {
            func_L01_004B9810(D_L01_001D7DC0);
        }
        break;
    case 6:
        if (D_L01_001D9A7C != 0) {
            D_0016C5A6[0] = 1;
            D_L01_001D9928 = 0;
            D_L01_001D9A7C = 0;
        }
        if (D_L01_001D9A74 != 0) {
            D_L01_001DFB44 = 6;
            func_L01_004ACBC8(6);
            D_L01_001D9A74 = 0;
        } else if (D_L01_001D7DC0 == 5) {
            func_00392DF0(D_L01_001D7DC4, 1);
        } else if (D_L01_001D7DC0 == 6) {
            func_L01_004ACD40();
        } else if (D_L01_001D7DC0 == 3) {
            func_L01_004ACBC8(D_001D545C);
        } else {
            if (D_L01_001D668C == 3) {
                if (D_L01_001D6674 != 0) {
                    D_L01_001D6674 = 0;
                    D_L01_001D7DC4 = D_L01_001DFB44;
                }
                func_L01_004ACBC8(D_L01_001D7DC4);
            } else {
                func_L01_004ACB38();
            }
            D_L01_001DFB54 = 1;
        }
        break;
    case 5:
        func_L01_004BB4E0(D_L01_001D7DC0);
        break;
    case 7:
        {
            s32 alt = D_L01_001D9730;
            s32 mode = D_L01_001D7DC0;
            func_L01_004A34A8(mode ? mode : alt, D_L01_001D7DC4);
        }
        break;
    case 8:
        func_L01_004C9500();
        break;
    case 18:
        func_003B3218(D_L01_001D7DC0);
        break;
    case 9:
        func_L01_00422FE0();
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17:
        break;
    }
    if (stay == 0) {
        if (D_L01_001D7DCC != 0) {
            *D_L01_001D7DCC = 1;
        }
        D_L01_001D6694 = D_L01_001D6690;
        D_L01_001D6690 = -2;
        D_L01_001D7DCC = 0;
    }
}

/* PAL near miss (Codex wave 10): near miss: 212 words differ with the file's flags.
 * Worker's note: 215 words differ: func_L01_00459F60.diff05.log; complete PAL state transition draft. Retail switch evidence: func_L01_00459F60.switches.txt (both 19-case tables). Unresolved snippet jump-table relocations, mixed absolute/gp global loads, base/index ...
 */
#include "common.h"
/* localdecomp:start func_L01_00459F60 */
extern s32 D_L01_001D6694, D_L01_001D6690, D_L01_001D668C;
extern s32 D_L01_001D7DBC, D_L01_001D7DC0, D_L01_001D7DC4;
extern s32 D_001D4CEC;
extern s32 D_001A7430 __attribute__((section(".data")));
extern f32 D_L01_001E7630 __attribute__((section(".data")));
extern u8 D_L01_001D672D;
extern f32 D_L01_001DF950;
extern f32 D_L01_001D6720;
typedef struct { u8 pad[0x5E]; s16 active; } State_00459F60;
extern State_00459F60 D_L01_001E6D80;
extern u8 D_00160C40[];
extern s16 D_001CCFD4 __attribute__((section(".data")));
extern s32 D_L01_001E1070;
extern u8 *D_L01_001EA94C;
extern s32 D_L01_001D9A7C, D_L01_001D9928, D_L01_001D9A74;
extern s16 D_0016C5A6;
extern s32 D_L01_001DFB44, D_L01_001DFB54, D_L01_001D6674;
extern s32 D_001D545C, D_L01_001D9730;
extern u8 *D_L01_001D7DCC;
void func_L01_00459F60(void) {
    extern void func_L01_004C8BE8(void);
    extern void func_L01_0047E568(void);
    extern void func_L01_00415D78(void);
    extern void func_003A8A58(void);
    extern void func_L01_004B9D20(void);
    extern void func_00382810(f32, s32, f32, s32, f32, s32, f32);
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
    extern void func_003A2598(void *, s32, s32);
    extern void func_003C4138(f32 *, f32, f32);
    extern void func_L01_004B9810(s32);
    extern void func_L01_004ACBC8(s32);
    extern void func_00392DF0(s32, s32);
    extern void func_L01_004ACD40(void);
    extern void func_L01_004ACB38(void);
    extern void func_L01_004BB4E0(s32);
    extern void func_L01_004A34A8(s32, s32);
    extern void func_L01_004C9500(void);
    extern void func_003B3218(s32);
    extern void func_L01_00422FE0(void);
    s32 pending;
    s32 index;
    s32 amount, cursor;
    u8 *destination;
    u8 *base;
    f32 target;
    func_L01_004C8BE8();
    D_L01_001D668C = D_L01_001D6694;
    if (D_L01_001D6690 == -2) return;
    if (D_L01_001D7DBC > 0) {
        D_L01_001D7DBC--;
        return;
    }
    if (!((D_L01_001D6694 == 0 && (D_001D4CEC & 1)) ||
          (D_L01_001D6694 == 4 && D_L01_001D6690 == 0) || D_001A7430)) return;
    switch (D_L01_001D6694) {
    case 3:
        if (D_L01_001D6690 != 4 || D_L01_001D7DC0 == 8) func_L01_0047E568();
        break;
    case 4: func_L01_00415D78(); break;
    case 1: func_003A8A58(); goto fade;
    case 2: func_L01_004B9D20();
    fade:
        D_L01_001E7630 = 0.6200000047683716f;
        func_00382810(1.1100293397903442f,0,0.005f,0,0.2f,3,0.0f);
        func_003873C0();
        break;
    case 6: if (D_L01_001D7DC0 != 4) func_L01_004ACDB0(); break;
    case 5: func_L01_004BBD90(); break;
    case 7: func_L01_004A3548(); break;
    case 8: func_L01_004C97C8(); break;
    case 9: func_L01_00423000(); break;
    case 0: case 18: default: break;
    }
    func_L01_0045A530(10);
    pending = 0;
    switch (D_L01_001D6690) {
    case 3:
        pending = D_L01_001D668C;
        if (pending != 4 || func_L01_00415CC0() == 8 ||
            (D_L01_001D668C == pending && func_L01_00415CC0() == 11) || D_L01_001D672D) {
            func_L01_0047DDC8(D_L01_001D7DC0);
        }
        pending = 0;
        break;
    case 4: func_L01_00415DD8(D_L01_001D7DC0,D_L01_001D7DC4); break;
    case 1: func_003A88B8(D_L01_001D7DC4); break;
    case 2:
        if ((u32)(D_L01_001D6694 - 1) < 2) goto instant;
        if (D_L01_001E6D80.active == 0) {
            D_L01_001E6D80.active = 1;
            if (D_L01_001D6720 < D_L01_001DF950) D_L01_001D6720 = D_L01_001DF950;
            func_L01_0045F328(0);
            func_003A2750(0);
            if (D_L01_001D6720 < 0.25f) {
                index = func_003A8770(D_L01_001D7DC0) * 0x14C;
                base = (u8 *)((u32)D_00160C40 + 0x8000);
                if (*(s32 *)(base + index + 0x1254) > 0) {
                    if (D_001CCFD4) func_003A2750(1);
                    func_003A9050();
                    amount = *(s32 *)(base + index + 0x1250) + *(s32 *)(base + 0x121C);
                    cursor = D_L01_001E1070 - 0x1000;
                    D_L01_001E1070 = cursor;
                    destination = D_L01_001EA94C + cursor;
                    func_003A2598(destination, amount, 1);
                }
            }
        }
        target = 1.1200000047683716f;
        func_003C4138(&D_L01_001D6720, target, 0.06000000238418579f);
        D_L01_001DF950 = D_L01_001D6720;
        if (D_L01_001DF950 > 1.0f) D_L01_001DF950 = 1.0f;
        if (D_L01_001D6720 >= target) {
            D_L01_001D6720 = 1.0f;
            pending = 0;
            func_L01_004B9810(D_L01_001D7DC0);
        } else pending = 1;
        break;
    instant:
        func_L01_004B9810(D_L01_001D7DC0);
        pending = 0;
        break;
    case 6:
        if (D_L01_001D9A7C) {
            D_0016C5A6 = 1;
            D_L01_001D9928 = 0;
            D_L01_001D9A7C = 0;
        }
        if (D_L01_001D9A74) {
            D_L01_001DFB44 = 6;
            func_L01_004ACBC8(6);
            D_L01_001D9A74 = 0;
        } else if (D_L01_001D7DC0 == 5) {
            func_00392DF0(D_L01_001D7DC4,1);
        } else if (D_L01_001D7DC0 == 6) {
            func_L01_004ACD40();
        } else if (D_L01_001D7DC0 == 3) {
            func_L01_004ACBC8(D_001D545C);
        } else {
            if (D_L01_001D668C == 3) {
                if (D_L01_001D6674) {
                    D_L01_001D6674 = 0;
                    D_L01_001D7DC4 = D_L01_001DFB44;
                }
                func_L01_004ACBC8(D_L01_001D7DC4);
            } else func_L01_004ACB38();
            D_L01_001DFB54 = 1;
        }
        break;
    case 5: func_L01_004BB4E0(D_L01_001D7DC0); break;
    case 7: func_L01_004A34A8(D_L01_001D7DC0 ? D_L01_001D7DC0 : D_L01_001D9730, D_L01_001D7DC4); break;
    case 8: func_L01_004C9500(); break;
    case 18: func_003B3218(D_L01_001D7DC0); break;
    case 9: func_L01_00422FE0(); break;
    case 0: default: break;
    }
    if (!pending) {
        if (D_L01_001D7DCC) *D_L01_001D7DCC = 1;
        D_L01_001D6694 = D_L01_001D6690;
        D_L01_001D6690 = -2;
        D_L01_001D7DCC = 0;
    }
}
/* localdecomp:end func_L01_00459F60 */

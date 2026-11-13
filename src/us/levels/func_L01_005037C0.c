#include "common.h"

/* NTSC-U counterpart of func_L01_00507738 (src/levels/shared/L01_005063E8.c) */
typedef struct {
    u8 x0;
    u8 p1[0x89];
    u16 x8A;
    u8 p8C[0x64];
} T_503930;
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern s32 D_001D545C;
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern s32 D_001D4C38;
extern s32 D_001D545C;
extern u8 D_001A4BE0[];
typedef struct {
    u8 pad0[0x10];
    s32 arr[1];
} S_503760;
extern S_503760 D_00142660;

/* localdecomp:start func_L01_005037C0 */
typedef struct {
    u8 pad0[0x1228];
    s32 held_item; /* 9 the wrench */
    u8 pad122C[0x25F8 - 0x122C];
    s32 hand_item_request;
    u8 pad25FC[0x2880 - 0x25FC];
    s16 quick_switch_tap[2];
    u8 pad2884[0x28C0 - 0x2884];
    u8 quick_switch_request;
} Hero_507738;
typedef struct {
    u8 pad0[0x174];
    u16 quick_switches;
    u8 pad176[2];
    u32 quick_switch_time;
    u32 quick_switch_levels; /* a bit per level, and bit 31 */
} Stats_507738;
extern u8 D_001A4BE0[];
extern S_503760 D_00142660;
extern s32 D_001427F0[];
extern u8 D_001425C0[];
extern T_503930 D_L01_002C5640[];
extern Stats_507738 D_001A7C10;
extern s32 D_001D4C38;
extern s32 D_001D4C40;
extern s32 D_001D545C;
extern s32 func_L01_0050D978(s32 arg0);
extern void func_L01_00503760(s32 n);

/* hero_quick_switch: from the wrench to the equipped gun; otherwise turns the recent guns round
   among the first three until a gun with ammo leads, and asks to switch to it */
void func_L01_005037C0(void) {
    s32 gun;
    s32 first;
    u32 time;

    if (((Hero_507738 *)D_001A4BE0)->quick_switch_request == 0) {
        return;
    }
    ((Hero_507738 *)D_001A4BE0)->quick_switch_request = 0;
    if (((Hero_507738 *)D_001A4BE0)->held_item != 9) {
        first = D_00142660.arr[0];
        do {
            func_L01_00503760(3);
            gun = D_00142660.arr[0];
            /* rounds left, or a gun that uses none */
            if (D_001427F0[gun] != 0) {
                break;
            }
            if ((D_L01_002C5640 + D_001425C0[gun])->x8A == 0) {
                break;
            }
        } while (gun != first);
    } else {
        gun = func_L01_0050D978(D_001D4C40);
    }
    if (((Hero_507738 *)D_001A4BE0)->held_item == gun) {
        return;
    }
    if (D_001A7C10.quick_switches < 0xFFFF) {
        D_001A7C10.quick_switches++;
    }
    time = D_001D4C38;
    if (D_001A7C10.quick_switch_time < time) {
        D_001A7C10.quick_switch_time = time;
    }
    D_001A7C10.quick_switch_levels |= 1 << D_001D545C;
    D_001A7C10.quick_switch_levels |= 0x80000000;
    ((Hero_507738 *)D_001A4BE0)->hand_item_request = gun;
    ((Hero_507738 *)D_001A4BE0)->quick_switch_tap[0] = 0;
    ((Hero_507738 *)D_001A4BE0)->quick_switch_tap[1] = 0;
}
/* localdecomp:end func_L01_005037C0 */

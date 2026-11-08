#include "common.h"

typedef struct {
    u8 x0;
    u8 p1[0x89];
    u16 x8A;
    u8 p8C[0x64];
} T_503930;

INCLUDE_ASM("asm/levels", func_L01_005063E8);

/* localdecomp:start func_L01_00506820 */
extern u8 D_001A4BE0[];
extern void func_003C2880(s32);
void func_L01_00506820(void) {
    u8 *p = D_001A4BE0;
    u8 *q;
    if (*(s32 *)(p + 6660) != 0) {
        func_003C2880(*(s32 *)(p + 6660));
        *(s32 *)(p + 6660) = 0;
    }
    q = *(u8 **)(p + 4848);
    if (q != 0) {
        *(u16 *)(q + 52) &= 0xffbe;
    }
    q = *(u8 **)(p + 4852);
    if (q != 0) {
        *(u16 *)(q + 52) &= 0xffbe;
    }
}
/* localdecomp:end func_L01_00506820 */

INCLUDE_ASM("asm/levels", func_L01_00506888);

INCLUDE_ASM("asm/levels", func_L01_00506BB0);

INCLUDE_ASM("asm/levels", func_L01_00506E30);

INCLUDE_ASM("asm/levels", func_L01_005070E0);

INCLUDE_ASM("asm/levels", func_L01_00507268);

INCLUDE_ASM("asm/levels", func_L01_00507380);

LINKER_REMNANT("asm/levels", func_L01_005075D0);

/* localdecomp:start func_L01_005075D8 */
typedef struct {
    u8 pad0[0x1A4];
    s32 pressed;
    u8 pad1A8[0x1B8 - 0x1A8];
    s32 released;
} Pad_5075D8;
typedef struct {
    u8 pad0[0x25C4];
    s32 state;
    u8 pad25C8[0x25ED - 0x25C8];
    u8 no_firing;
    u8 pad25EE[0x2880 - 0x25EE];
    s16 quick_switch_tap[2];
    u8 pad2884[0x28C0 - 0x2884];
    u8 quick_switch_request; /* taken by hero_quick_switch */
} Hero_5075D8;
extern u8 D_001A4BE0[];
extern Pad_5075D8 *D_001D52FC;
extern s32 D_L01_002D15F0[];
extern s32 D_L01_002E5F30[];
extern void func_0038CB00(void *a0);
extern void func_L01_00422430(void);

/* hero_quick_switch_button: Triangle pressed opens a 17-frame window; released inside it, asks for a quick switch */
void func_L01_005075D8(void) {
    s16 *tap = ((Hero_5075D8 *)D_001A4BE0)->quick_switch_tap;
    Hero_5075D8 *hero = (Hero_5075D8 *)D_001A4BE0;
    s32 state;

    func_0038CB00(&tap[0]);
    func_0038CB00(&tap[1]);
    state = hero->state;
    if (state == 0x37 || state == 0x13 || state == 0x15 || state == 0x88 || state == 0x14) {
        return;
    }
    if (hero->no_firing != 0) {
        return;
    }
    if (D_L01_002D15F0[0] != 0) {
        return;
    }
    if (D_L01_002E5F30[0] != 0 || D_L01_002E5F30[9] != -1) {
        return;
    }
    if (D_001D52FC->pressed & 0x10) {
        hero->quick_switch_tap[0] = 17; /* frames */
    }
    if (hero->quick_switch_tap[0] != 0 && (D_001D52FC->released & 0x10)) {
        hero->quick_switch_request = 1;
        func_L01_00422430();
        if (hero->quick_switch_tap[1] == 0) {
            hero->quick_switch_tap[1] = 17;
        }
    }
}
/* localdecomp:end func_L01_005075D8 */

/* localdecomp:start func_L01_005076D8 */
typedef struct {
    u8 pad0[0x10];
    s32 arr[1];
} S_503760;

extern S_503760 D_00142660;

void func_L01_005076D8(s32 n) {
    s32 first = D_00142660.arr[0];
    s32 last = 0;
    s32 i;
    for (i = 1; i < n; i++) {
        if (D_00142660.arr[i] != 0) {
            D_00142660.arr[i - 1] = D_00142660.arr[i];
            last = i;
        }
    }
    D_00142660.arr[last] = first;
}
/* localdecomp:end func_L01_005076D8 */

/* localdecomp:start func_L01_00507738 */
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
extern T_503930 D_L01_002C5600[];
extern Stats_507738 D_001A7C10;
extern s32 D_001D4C38;
extern s32 D_001D4C40;
extern s32 D_001D545C;
extern s32 func_L01_00511950(s32 arg0);
extern void func_L01_005076D8(s32 n);

/* hero_quick_switch: from the wrench to the equipped gun; otherwise turns the recent guns round
   among the first three until a gun with ammo leads, and asks to switch to it */
void func_L01_00507738(void) {
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
            func_L01_005076D8(3);
            gun = D_00142660.arr[0];
            /* rounds left, or a gun that uses none */
            if (D_001427F0[gun] != 0) {
                break;
            }
            if ((D_L01_002C5600 + D_001425C0[gun])->x8A == 0) {
                break;
            }
        } while (gun != first);
    } else {
        gun = func_L01_00511950(D_001D4C40);
    }
    if (((Hero_507738 *)D_001A4BE0)->held_item == gun) {
        return;
    }
    if (D_001A7C10.quick_switches < 0xFFFF) {
        D_001A7C10.quick_switches++;
    }
    /* the frame counter times 5/6, rounded */
    time = (D_001D4C38 * 5 + 2) / 6;
    if (D_001A7C10.quick_switch_time < time) {
        D_001A7C10.quick_switch_time = time;
    }
    D_001A7C10.quick_switch_levels |= 1 << D_001D545C;
    D_001A7C10.quick_switch_levels |= 0x80000000;
    ((Hero_507738 *)D_001A4BE0)->hand_item_request = gun;
    ((Hero_507738 *)D_001A4BE0)->quick_switch_tap[0] = 0;
    ((Hero_507738 *)D_001A4BE0)->quick_switch_tap[1] = 0;
}
/* localdecomp:end func_L01_00507738 */

/* localdecomp:start func_L01_005078C0 */
extern S_503760 D_00142660;
typedef struct {
    u8 p0[0x10];
    s32 x10[8];
} L_503930;
extern s32 func_L01_00418F70(s32);
extern u8 D_001425C0[];
extern T_503930 D_L01_002C5600[];
extern s32 D_001427F0[];

void func_L01_005078C0(s32 id) {
    s32 pos;
    s32 i;
    if (id == 9 || id == 30 || id == 22 || id == 35) return;
    if (D_L01_002C5600[D_001425C0[id]].x0 == 0 && !func_L01_00418F70(id)) return;
    pos = -1;
    for (i = 0; i < 8; i++) {
        if ((*(L_503930 *)&D_00142660).x10[i] == id) {
            pos = i;
            break;
        }
    }
    if (pos == 0) return;
    if (pos >= 3 || pos == -1) {
        s32 found = -1;
        s32 j;
        for (j = 2; j >= 0; j--) {
            s32 n = (*(L_503930 *)&D_00142660).x10[j];
            if (n != 0 && D_001427F0[n] == 0 && (D_L01_002C5600 + D_001425C0[n])->x8A != 0) {
                found = j;
                break;
            }
        }
        if (found != -1) {
            for (j = found; j < 7; j++) {
                (*(L_503930 *)&D_00142660).x10[j] = (*(L_503930 *)&D_00142660).x10[j + 1];
                if (pos == j + 1) pos--;
            }
            (*(L_503930 *)&D_00142660).x10[7] = 0;
        }
    }
    if (pos != -1) {
        for (i = pos; i < 7; i++) {
            (*(L_503930 *)&D_00142660).x10[i] = (*(L_503930 *)&D_00142660).x10[i + 1];
        }
        (*(L_503930 *)&D_00142660).x10[7] = 0;
    }
    {
        s32 k;
        for (k = 7; k > 0; k--) {
            (*(L_503930 *)&D_00142660).x10[k] = (*(L_503930 *)&D_00142660).x10[k - 1];
        }
    }
    (*(L_503930 *)&D_00142660).x10[0] = id;
}
/* localdecomp:end func_L01_005078C0 */

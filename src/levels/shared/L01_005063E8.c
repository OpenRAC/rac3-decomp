#include "common.h"

typedef struct {
    u8 x0;
    u8 p1[0x89];
    u16 x8A;
    u8 p8C[0x64];
} T_503930;

/* The pad (through D_001D52FC), as the hero's button checks read it. */
typedef struct {
    u8 pad0[0x1A0];
    u32 held;                      /* 0x1A0 */
    s32 pressed;                   /* 0x1A4 */
    u8 pad1A8[0x1B8 - 0x1A8];
    s32 released;                  /* 0x1B8 */
} Pad_5075D8;

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

/* localdecomp:start func_L01_00506888 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_506888;

typedef struct {
    u8 pad0[0x48];
    s32 sequence;       /* 0x48 */
    u8 pad4C[0x50 - 0x4C];
    s32 hand_item;      /* 0x50: the item the hand needs, -1 for any */
    u8 pad54[0x58 - 0x54];
    f32 mean;           /* 0x58: seconds between plays */
    f32 cooldown;       /* 0x5C: seconds of cooldown */
    s32 cooldown_frames; /* 0x60 */
    u8 pad64[0x70 - 0x64];
} F_506888;

typedef struct {
    u8 pad0[0xE0];
    V_506888 pickup_point; /* 0xE0 */
    u8 pad_F0[0x1B8 - 0xF0];
    s32 state_timer;       /* 0x1B8 */
    u8 pad_1BC[0x208 - 0x1BC];
    s16 fidget_gap;        /* 0x208 */
    u8 pad20A[0xC08 - 0x20A];
    u32 anim_flags;        /* 0xC08: & 2 */
    u8 pad_C0C[0x25C0 - 0xC0C];
    void *hero_moby;       /* 0x25C0 */
    s32 state;             /* 0x25C4 */
    u8 pad_25C8[0x25D4 - 0x25C8];
    s32 prev_state;        /* 0x25D4 */
    u8 pad_25D8[0x25EC - 0x25D8];
    u8 hold_type;          /* 0x25EC: 0 none, 1 one hand, 2 both */
    u8 pad_25ED[0x2850 - 0x25ED];
    s32 health;            /* 0x2850 */
} H_506888;

extern u8 D_001A4BE0[];
extern s32 D_L01_002F44E0[];
extern F_506888 D_L01_002F4330[];
extern s32 D_001D545C;        /* the level number; no size hint: Ps2EeAs reads it with `lui` */
extern s32 func_L01_004DFD60(void);
extern s32 func_L01_004E9238(s32 slot);
extern f32 func_003824E0(f32 lo, f32 hi);
extern s32 func_003D3CB0(void *from, void *to, s32 mask, void *skip, s32 unk);

/* hero_fidget_pick: each idle frame picks a fidget (into *out) to play, or none. */
s32 func_L01_00506888(s32 *out) {
    H_506888 *hero = (H_506888 *)D_001A4BE0;
    s32 ready[20];
    s32 count = 0;
    s32 i;
    f32 total;
    f32 roll;

    if (hero->fidget_gap != 0) {
        return 0;
    }
    if (func_L01_004DFD60()) {
        *out = 3;
        if (D_L01_002F44E0[0] != 0) {
            return 0;
        }
        if ((hero->anim_flags & 2) == 0) {
            return 0;
        }
        if (func_003824E0(0.0f, 1.0f) < 0.33f) {
            return 1;
        }
        return 0;
    }
    for (i = 0; i < 4; i++) {
        F_506888 *f = &D_L01_002F4330[i];
        s32 item;
        if (f->cooldown_frames != 0) {
            continue;
        }
        {
            /* a mean of 0 turns the fidget off (the 0 is a local so that the loop pass hoists it
               on its first run, ahead of the probe's 8.0, as retail has them) */
            f32 off = 0.0f;
            if (f->mean == off) {
                continue;
            }
        }
        item = func_L01_004E9238(0);
        if (f->hand_item != -1 && f->hand_item != item) {
            continue;
        }
        if (i == 2) {
            V_506888 top;
            V_506888 origin;
            if (D_001D545C != -1) {
                continue;
            }
            if (((H_506888 *)D_001A4BE0)->hold_type == 2) {
                continue;
            }
            origin = ((H_506888 *)D_001A4BE0)->pickup_point;
            top = ((H_506888 *)D_001A4BE0)->pickup_point;
            top.z = top.z + 8.0f;
            if (func_003D3CB0(&origin, &top, 2, ((H_506888 *)D_001A4BE0)->hero_moby, 0)) {
                continue;
            }
        }
        if (i == 3) {
            if (((H_506888 *)D_001A4BE0)->prev_state != 1) {
                continue;
            }
            if (!(((H_506888 *)D_001A4BE0)->state_timer < 0x2B)) {
                continue;
            }
            if (!(((H_506888 *)D_001A4BE0)->health < 2)) {
                continue;
            }
        }
        ready[count] = i;
        count++;
    }
    if (count == 0) {
        return 0;
    }
    total = 0.0f;
    for (i = 0; i < count; i++) {
        total = total + 1.0f / (f32)(s32)(((F_506888 *)D_L01_002F4330)[ready[i]].mean * 50.0f);
    }
    roll = func_003824E0(0.0f, 1.0f);
    if (roll < total) {
        for (i = 0; i < count; i++) {
            *out = ready[i];
            total = total - 1.0f / (f32)(s32)(((F_506888 *)D_L01_002F4330)[ready[i]].mean * 50.0f);
            if (total < roll) {
                break;
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00506888 */

INCLUDE_ASM("asm/levels", func_L01_00506BB0);

/* localdecomp:start func_L01_00506E30 */
typedef struct {
    u8 pad0[0x178];
    f32 ground_speed;              /* 0x178: the speed the crouch jumps test (not named in hero.h) */
    u8 pad17C[0x1B8 - 0x17C];
    s32 state_timer;               /* 0x1B8: frames since the state began */
    u8 pad1BC[0x1E4 - 0x1BC];
    s16 thruster_wait;             /* 0x1E4: non-zero keeps the thruster dash from starting */
    u8 pad1E6[0x298 - 0x1E6];
    f32 f298;                      /* 0x298 */
    u8 pad29C[0x2A0 - 0x29C];
    f32 f2A0;                      /* 0x2A0 */
    u8 f2A4;                       /* 0x2A4: flag for the thruster dash */
    u8 pad2A5[0x25C4 - 0x2A5];
    s32 state;                     /* 0x25C4 */
    u8 pad25C8[0x2838 - 0x25C8];
    f32 stick_mag;                 /* 0x2838 */
    u8 pad283C[0x2884 - 0x283C];
    s16 unk_2884;                  /* 0x2884: must be 0 for the back-item jumps */
} H_506E30;
extern u8 D_001A4BE0[];
extern Pad_5075D8 *D_001D52FC;      /* a sized extern with no hint: Ps2EeAs reads it with `lui` */
extern u8 D_00142CA2[];
extern s32 func_L01_004FF5D8(void);
extern s32 func_003A3BB8(s32, s32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L01_00460778(s32, s32, s32, s32, s32);
extern s32 func_L01_004E9238(s32);
extern void func_L01_005003D0(s32, s32);

/* hero_crouch_jump: X from a crouch (or a jump's first frames) starts a jump; the back item
   says which. The flip and the back-item jumps share one state change (`change`); the standing
   jump (state 7) has its own, called as the value-returning function it is. With both calls of
   one type the compiler merges the two tails into one, which retail does not have. */
s32 func_L01_00506E30(void) {
    s32 state;
    s32 window;
    u32 r1;
    s32 item;

    if (((H_506E30 *)D_001A4BE0)->state == 14) {
        return 0;
    }
    window = func_L01_004FF5D8();
    r1 = func_003A3BB8(8, 0);
    if (!((D_001D52FC->held & r1) != 0 && window > 0
          && func_L01_00460778(func_003A3BB8(64, 0), 0x1F000, window + 4, window, 0) != 0)) {
        goto rest;
    }
    state = 11;
change:
    func_L01_005003D0(state, 1);
    return 1;
rest:
    if (((H_506E30 *)D_001A4BE0)->state_timer < 6) {
        return 0;
    }
    if (func_L01_004606E8(func_003A3BB8(64, 0), 7, 0, 0) == 0) {
        return 0;
    }
    item = func_L01_004E9238(3);
    if (item == 2 && D_00142CA2[0] != 0 && ((H_506E30 *)D_001A4BE0)->unk_2884 == 0) {
        if ((2.5f < ((H_506E30 *)D_001A4BE0)->f298 || ((H_506E30 *)D_001A4BE0)->f2A0 < 0.78539819f)
            && 0.7f < ((H_506E30 *)D_001A4BE0)->stick_mag
            && 0.018000001f < ((H_506E30 *)D_001A4BE0)->ground_speed) {
            state = 10;
            goto change;
        }
    }
    item = func_L01_004E9238(3);
    if (item == 3 && ((H_506E30 *)D_001A4BE0)->unk_2884 == 0) {
        if (0.7f < ((H_506E30 *)D_001A4BE0)->stick_mag
            && (2.5f < ((H_506E30 *)D_001A4BE0)->f298 || ((H_506E30 *)D_001A4BE0)->f2A4 != 0)
            && 0.018000001f < ((H_506E30 *)D_001A4BE0)->ground_speed) {
            if (((H_506E30 *)D_001A4BE0)->thruster_wait != 0) {
                return 1;
            }
            state = 16;
            goto change;
        }
    }
    item = func_L01_004E9238(3);
    if (item == 3 && ((H_506E30 *)D_001A4BE0)->unk_2884 == 0) {
        state = 13;
        goto change;
    }
    item = func_L01_004E9238(3);
    if (item == 2 && ((H_506E30 *)D_001A4BE0)->unk_2884 == 0 && D_00142CA2[0] != 0) {
        state = 15;
        goto change;
    }
    ((s32 (*)(s32, s32))func_L01_005003D0)(7, 1);
    return 1;
}
/* localdecomp:end func_L01_00506E30 */

INCLUDE_ASM("asm/levels", func_L01_005070E0);

INCLUDE_ASM("asm/levels", func_L01_00507268);

/* localdecomp:start func_L01_00507380 */
/* hero_lock_on (open-rac-engine lock_on.rs): picks the lock-on target through target_search
   (func_L01_004E9980). Its float arguments come before the ints in the prototype: same
   registers either way, but that order gives retail's argument setup. */
extern u8 D_001A4BE0[];
extern u8 D_00142A60[];
extern u8 D_L01_001E2A40[];
extern s32 D_001D4C38;
extern s32 D_001D545C;
extern f32 func_0038CF00(void *, void *);
extern void *func_L01_004E9980(void *from, f32 range, f32 yaw, f32 cone, f32 rise, s32 cls, s32 flag);

typedef struct {
    u8 pad0[0x80];
    f32 pos[4];
    u8 pad90[0x98 - 0x90];
    f32 yaw;
    u8 pad9C[0x1228 - 0x9C];
    s32 held_item;
    u8 pad122C[0x1430 - 0x122C];
    void *lock_target;
    u8 pad1434[0x16B0 - 0x1434];
    s32 camera_mode;
    u8 pad16B4[0x25C4 - 0x16B4];
    s32 state;
} H_507380;
typedef struct {
    u8 pad0[0x1A0];
    u32 held;
    u32 pressed;
} P_507380;
typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    u8 state;
    u8 pad21[0x30 - 0x21];
    unsigned long flags;
} T_507380;
typedef struct {
    u8 pad0[0x1B0];
    u16 count;
    u8 pad1B2[0x1B4 - 0x1B2];
    u32 time;
    u32 levels;
} K_507380;
extern K_507380 D_001A7C10_507380;
extern P_507380 *D_001D52FC_507380;

/* hero_lock_on: holding L2 and R2, a new press picks a target near the middle of the view (else
   near his facing); the target is dropped beyond 30 u, when a button is let go, or when it dies,
   and a death is counted */
void func_L01_00507380(void) {
    u32 time;
    u8 *cam;
    unsigned long flag_bits;

    if (((H_507380 *)D_001A4BE0)->held_item < 0 || !(((flag_bits = D_00142A60[((H_507380 *)D_001A4BE0)->held_item]) >> 5) & 1)
        || ((H_507380 *)D_001A4BE0)->camera_mode == 1) {
        ((H_507380 *)D_001A4BE0)->lock_target = 0;
        return;
    }
    if (((H_507380 *)D_001A4BE0)->state == 0x31) {
        ((H_507380 *)D_001A4BE0)->lock_target = 0;
        return;
    }
    if (((H_507380 *)D_001A4BE0)->lock_target != 0) {
        if (func_0038CF00(((H_507380 *)D_001A4BE0)->pos,
                          ((T_507380 *)((H_507380 *)D_001A4BE0)->lock_target)->pos) > 30.0f) {
            ((H_507380 *)D_001A4BE0)->lock_target = 0;
        }
        if ((D_001D52FC_507380->held & 3) != 3) {
            ((H_507380 *)D_001A4BE0)->lock_target = 0;
        }
        if (((H_507380 *)D_001A4BE0)->lock_target == 0) {
            return;
        }
        if ((((T_507380 *)((H_507380 *)D_001A4BE0)->lock_target)->flags & 0x100200000000UL) == 0x100000000000UL) {
            {
                u8 st = ((T_507380 *)((H_507380 *)D_001A4BE0)->lock_target)->state;
                if (st == 0xFE) goto drop;
                if (st == 0xFD) goto drop;
                if (((u8 *)((H_507380 *)D_001A4BE0)->lock_target)[0x31] != 0) {
                    return;
                }
            }
drop:
        }
        ((H_507380 *)D_001A4BE0)->lock_target = 0;
        if (D_001A7C10_507380.count < 0xFFFF) {
            D_001A7C10_507380.count++;
        }
        time = (D_001D4C38 * 5 + 2) / 6;
        if (D_001A7C10_507380.time < time) {
            D_001A7C10_507380.time = time;
        }
        D_001A7C10_507380.levels |= 1 << D_001D545C;
        D_001A7C10_507380.levels |= 0x80000000;
        return;
    }
    if ((D_001D52FC_507380->held & 3) != 3) {
        return;
    }
    if ((D_001D52FC_507380->pressed & 3) == 0) {
        return;
    }
    cam = D_L01_001E2A40;
    {
        u8 *aim = cam + 0x380;
        f32 yaw = *(f32 *)(cam + 0x18);
        ((H_507380 *)D_001A4BE0)->lock_target = func_L01_004E9980(aim, 25.0f, yaw, 0.61086524f, 1.2217305f, 5, 1);
    }
    if (((H_507380 *)D_001A4BE0)->lock_target == 0) {
        ((H_507380 *)D_001A4BE0)->lock_target = func_L01_004E9980(D_001A4BE0, 25.0f, ((H_507380 *)D_001A4BE0)->yaw, 0.61086524f, 1.2217305f, 5, 1);
    }
}
/* localdecomp:end func_L01_00507380 */

LINKER_REMNANT("asm/levels", func_L01_005075D0);

/* localdecomp:start func_L01_005075D8 */
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

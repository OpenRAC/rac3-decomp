/* func_L01_00381720 (Claude wave 14 r60, 2026-11-28). First draft kept here. */
#include "common.h"

/* func_L01_00381720 (fresh entry, first draft, written from the PAL asm; no functional draft existed).
 * The held multi-target weapon update, sibling of func_L01_0037EFC8 (same idioms: level from
 * D_001425C0[0x97]'s weapon row, the lock-on tint call func_L01_003F6F20, the light slot in
 * D_L01_001F1B40). Under the file's line: 848 positional differences (p10/check.py, level 01), 887 of
 * retail's 888 instructions, 469 LCS-aligned rows: the block structure and every call with its
 * arguments follow retail, what differs is register allocation (vars in s4 instead of s6, the hero
 * block base not kept in s0/s1/s3/s5), the frame (0x1B0, retail 0x1C0 with spills at 0x12C/0x130:
 * the shot count and m + 0xC0), and scheduling around the first func_L01_004501E8 call. Notes for the
 * next pass: retail reads the $gp-small globals (D_L01_001D6694, D_001D52FC, D_L01_001E1E90...) through
 * $gp only in branch delay slots and lui/lw elsewhere; D_L01_001EAA00's target is at 0x18; the 3-way
 * aim source (camera, D_L01_001E29E0, hero + 0x6F0) appears twice, perhaps an inline helper. */

/* localdecomp:start func_L01_00381720 */
#include "vu0.h"
#include "structs/weapon.h"
typedef int Q_00381720 __attribute__((mode(TI)));
typedef struct {
    f32 rate;                  /* 0x00 */
    u8 pad_04[0x10 - 0x04];
    u8 *target;                /* 0x10 */
    u8 pad_14[0x1C - 0x14];
    s16 light;                 /* 0x1C */
    s16 glow;                  /* 0x1E */
    s32 w20;                   /* 0x20 */
    s32 sound;                 /* 0x24 */
    f32 spin;                  /* 0x28 */
} Vars_00381720;
typedef struct {
    f32 f0, f4, f8, fC;
    vu0_v4 pos;
} Slot_00381720;
extern u8 D_001A4BE0_00381720[];
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_001425C0[];
extern vu0_v4 D_L01_001E29E0;
extern vu0_v4 D_L01_001E29C0_00381720;
extern u8 *D_L01_001EEA80_00381720[];
extern u8 D_L01_002B3B10[];
extern vu0_v4 D_L01_001D66B0_00381720;
extern Slot_00381720 D_L01_001F1B40_00381720[];
extern u8 D_L01_001DDCE0_00381720[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DDCE0_00381720, 8");
__asm__(".extern D_L01_001D673C, 4");
extern s32 D_L01_001D673C;
__asm__(".extern D_L01_001D6694, 4");
extern s32 D_L01_001D6694;
__asm__(".extern D_L01_001E1E90, 4");
extern s32 D_L01_001E1E90;
__asm__(".extern D_L01_001E1E94, 4");
extern s32 D_L01_001E1E94_00381720;
extern struct { u8 pad[0x18]; u8 *moby; } D_L01_001EAA00_00381720;

void func_L01_00381720(u8 *m) {
    extern void func_L01_0040E050(void *);
    extern void func_L01_005003D0(s32, s32);
    extern s32 func_0038CAD0(void *);
    extern void func_0038CB00(void *);
    extern void func_L01_00444F38(void *, s32, s32, s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CBA0(void *, s32);
    extern void func_L01_004C84D8(void *);
    extern void func_L01_004501E8(void *, void *, s32 *, void *, s32, s32, s32, s32 *, f32, f32, f32, f32, f32, s32, s32, s32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_004CB128(void *, s32, s32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_003D4D00(void *centre, f32 radius, s32 kinds, void *skip, s32 extra);
    extern f32 *func_00382348(s32);
    extern s32 func_003C4B50(s32);
    extern void func_L01_00382890(void *);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_L01_004C7D98(void *, void *);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L01_004AAC98(s32, s32, void *, s32);
    extern u8 *func_L01_004C83D0(void *, void *, s32, s32 *, s32);
    extern void func_L01_004C81F0(void *, void *, s32);
    extern u8 *func_L01_00383FB8(void *, void *, void *, void *, f32, f32, f32, f32);
    extern u8 *func_L01_003DCAA0(void *, void *, void *, void *, void *, s32, f32, f32, f32, f32);
    extern void func_L01_005118D0(s32, s32);
    extern void func_L01_003F2278(s32, s32);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
    extern void func_L01_00424D88(s32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_00382500(u8 *a0);
    vu0_v4 aim;
    vu0_v4 from;
    vu0_v4 at;
    u8 *list[32];
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 muzzle;
    vu0_v4 off;
    vu0_v4 side;
    s32 count;
    s32 best;
    s32 found;
    s32 shots;
    Vars_00381720 *v;
    u8 *hw;
    u8 *tgt;
    u8 *o;
    u8 *r;
    f32 *rec;
    s32 ok;
    s32 max;
    s32 n;
    s32 i;
    s32 first;
    s32 t;
    f32 range;
    f32 d;
    f32 hp;
    f32 x;
    f32 c0, c1, c2;

    v = *(Vars_00381720 **)(m + 0x68);
    if (m[0x20] == 0) {
        v->glow = 0;
        v->light = -1;
        v->target = 0;
        v->w20 = 0;
        m[0x20] = 1;
        v->sound = -1;
    }
    func_L01_0040E050(v);
    hw = D_001A4BE0_00381720;
    if (*(s32 *)(hw + 0x25C4) == 1) {
        func_L01_005003D0(0x1D, 1);
    }
    ok = 1;
    if (*(s32 *)(hw + 0x25C4) == 0x1D) {
        if (func_0038CAD0(hw + 0x28BC) == 0) {
            ok = 0;
        }
    } else {
        *(s32 *)(hw + 0x28BC) = 0x21;
    }
    if (*(s32 *)(D_001A4BE0_00381720 + 0x1430) != 0) {
        *(s32 *)(D_001A4BE0_00381720 + 0xBD8) = *(s32 *)(D_001A4BE0_00381720 + 0x1430);
    }
    t = (D_L01_002C5600 + D_001425C0[0x97])->level;
    if (t == 3) {
        *(s16 *)(m + 0x7C) = 7;
    }
    if (t == 2) {
        *(s16 *)(m + 0x7C) = 6;
    } else if (t == 1) {
        *(s16 *)(m + 0x7C) = 4;
    }
    if (m[0x42] == m[0x43] && (m[0x60] & 2)) {
        func_L01_00444F38(m, 1, 0, 2, 0);
    }
    v->w20 = 0;
    if (*(s16 *)(D_001A4BE0_00381720 + 0x2874) != 0) {
        func_0038CE20(&aim, m + 0xD0, -1.0f);
    } else if (*(s32 *)(D_001A4BE0_00381720 + 0x16B0) == 1) {
        *(Q_00381720 *)&aim = *(Q_00381720 *)&D_L01_001E29E0;
    } else {
        *(Q_00381720 *)&aim = *(Q_00381720 *)(D_001A4BE0_00381720 + 0x6F0);
    }
    hw = D_001A4BE0_00381720;
    func_0038CE20(&from, *(u8 **)(hw + 0x25C0) + 0xE0, 0.75f);
    vec_add_ba(&from, hw + 0x80, &from);
    count = 0;
    func_0038CBA0(list, 0x80);
    func_L01_004C84D8(m);
    best = -1;
    range = 48.0f;
    t = (D_L01_002C5600 + D_001425C0[0x97])->level;
    if (t >= 4) {
        range = 60.0f;
    }
    if (D_L01_001D673C != 0) {
        range = 20.0f;
    }
    max = 8;
    if (t != 0) {
        max = 0x10;
    }
    if (t >= 4) {
        func_L01_004501E8(m + 0x10, &aim, &count, list, max, 0, 1, &best, 4.712389f, 1.3962634f, range, 1.3962634f, 1.2217305f, 1, -1, 0);
        if (max < count) {
            count = max;
        }
    } else {
        func_L01_004501E8(m + 0x10, &aim, &count, list, max, 0, 1, &best, 0.43633232f, 0.43633232f, range, 0.78539819f, 0.78539819f, 1, -1, 0);
        if (max < count) {
            count = max;
        }
        for (i = 0; i < count; i++) {
            if (*(s32 *)(hw + 0x1430) == 0) {
                d = func_0038CF00(&D_L01_001E29C0_00381720, list[i] + 0x10) / 150.0f;
                func_L01_004CB128(&at, (s32)list[i], 0);
                if (i == 0) {
                    v->spin = func_0038DAB8(v->spin, 0.034906585f);
                }
                func_L01_003F6F20(0, m, 0xFF0FFF0F, &at, 0x26, -1, 4, fabs_asm(0.9f - d * 0.65f), -v->spin, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            }
        }
    }
    tgt = 0;
    if (D_L01_001D6694 == 0) {
        if (v->rate != 0.0f && func_L01_005119E0(-1) != 0) {
            goto tail;
        }
        hw = D_001A4BE0_00381720;
        if (hw[0x25ED] != 0) {
            goto tail;
        }
        if (m[0x42] >= 2) {
            goto tail;
        }
        if ((D_001D52FC_sda->mask & *(u32 *)(hw + 0x1210)) == 0) {
            goto tail;
        }
        if (*(s32 *)(hw + 0x1220) < 0x13) {
            goto tail;
        }
        if (ok == 0) {
            goto tail;
        }
        if (*(s32 *)(hw + 0x1430) != 0) {
            *(s32 *)(hw + 0xBD8) = *(s32 *)(hw + 0x1430);
        }
        if (func_L01_005119E0(-1) != 0) {
            func_L01_004EA7D8(-1);
            func_0038CE20(&pos, m + 0xD0, -1.0f);
            vec_add_ab(&pos, &pos, m + 0x10);
            func_0038CE20(&dir, m + 0xC0, 0.275f);
            vec_add_ab(&pos, &pos, &dir);
            n = func_003D4D00(&pos, 1.0f, 1, *(void **)(hw + 0x25C0), 0);
            if (n != 0) {
                for (i = 0; i < n; i++) {
                    o = D_L01_001EEA80_00381720[i];
                    rec = func_00382348((s32)o);
                    if (o[0x31] == 0 || *(s16 *)(o + 0x32) <= 0 || o == 0 || o[0x20] == 0xFE || o[0x20] == 0xFD || rec == 0) {
                        continue;
                    }
                    if (!(0.0f < rec[0]) && func_003C4B50((s32)o) == 0) {
                        continue;
                    }
                    if (*(u8 **)(o + 0x24) == 0 || (*(u8 **)(o + 0x24))[0x46] != 5) {
                        tgt = D_L01_001EAA00_00381720.moby;
                        v->target = tgt;
                        break;
                    }
                }
            }
            v->glow = 12;
            func_L01_00382890(m);
            hp = 0.0f;
            func_003C3A10(m, 2, 0, 0);
            v->sound = func_L01_003F2058(D_L01_002B3B10, 0);
            shots = 8;
            func_0038D000(&muzzle, D_L01_001DDCE0_00381720, m + 0xC0);
            vec_add_ba(&muzzle, m + 0x10, &muzzle);
            *(Q_00381720 *)&off = *(Q_00381720 *)&D_L01_001D66B0_00381720;
            if ((D_L01_002C5600 + D_001425C0[0x97])->level != 0) {
                shots = 0x10;
            }
            if ((D_L01_002C5600 + D_001425C0[0x97])->level >= 4) {
                hw = D_001A4BE0_00381720;
                func_0038CE20(&off, *(u8 **)(hw + 0x25C0) + 0xC0, 10.0f);
                func_L01_004C7D98(hw + 0x80, &side);
                func_0038CE20(&side, &side, 3.0f);
                vec_add_ba(&off, hw + 0xE0, &off);
                vec_add_ab(&off, &off, &side);
            }
            if ((D_L01_002C5600 + D_001425C0[0x97])->level != 0) {
                func_003A52A0(3, 0, m);
                if ((D_L01_002C5600 + D_001425C0[0x97])->level >= 4) {
                    func_L01_004AAC98(1, 0, *(void **)(D_001A4BE0_00381720 + 0x25C0), 500);
                }
            } else {
                func_003A52A0(1, 0, m);
            }
            for (i = 0; i < shots; i++) {
                hw = D_001A4BE0_00381720;
                first = 0;
                if ((D_L01_002C5600 + D_001425C0[0x97])->level >= 4) {
                    first = i == 0;
                }
                if (tgt == 0) {
                    found = 0;
                    tgt = func_L01_004C83D0(m, list, count, &found, -1);
                    if (tgt == 0) {
                        tgt = list[0];
                    } else if (found != 0) {
                        func_L01_004C81F0(m, tgt, 0x11);
                    }
                }
                if (tgt != 0) {
                    rec = func_00382348((s32)tgt);
                    if (rec != 0) {
                        hp = rec[4];
                    }
                }
                if ((D_L01_002C5600 + D_001425C0[0x97])->level >= 4) {
                    *(s32 *)(hw + 0xBD8) = 0;
                    tgt = 0;
                }
                if (*(s32 *)(hw + 0xBD8) != 0) {
                    if ((D_L01_002C5600 + D_001425C0[0x97])->level != 0) {
                        r = func_L01_003DCAA0(m, &muzzle, *(void **)(hw + 0xBD8), &D_L01_001D66B0_00381720, &off, first, hp, 2.0f, 5.0f, 0.6f);
                    } else {
                        r = func_L01_00383FB8(m, &muzzle, *(void **)(hw + 0xBD8), &D_L01_001D66B0_00381720, hp, 2.0f, 5.0f, 0.6f);
                    }
                } else if ((D_L01_002C5600 + D_001425C0[0x97])->level != 0) {
                    r = func_L01_003DCAA0(m, &muzzle, tgt, &D_L01_001D66B0_00381720, &off, first, hp, 2.0f, 5.0f, 0.6f);
                } else {
                    r = func_L01_00383FB8(m, &muzzle, tgt, &D_L01_001D66B0_00381720, hp, 2.0f, 5.0f, 0.6f);
                }
                if (r != 0) {
                    *(u8 **)(r + 0xB8) = m;
                }
                tgt = 0;
            }
            D_L01_001E1E94_00381720 = 8;
            func_L01_005118D0(-1, 1);
            D_L01_001E1E90 = 1;
        } else if ((*(u32 *)((u8 *)D_001D52FC_sda + 0x1A4) & *(u32 *)(hw + 0x1210)) != 0 || D_L01_001E1E90 == 1) {
            func_003A52A0(2, 0, m);
            D_L01_001E1E90 = 0;
        }
        hw = D_001A4BE0_00381720;
        if (((D_001D52FC_sda->mask & *(u32 *)(hw + 0x1210)) == 0 || hw[0x25E9] == 0) && v->sound >= 0) {
            func_L01_003F2278(v->sound, 0);
            v->sound = -1;
            func_L01_004EAA80();
        }
        if ((D_L01_002C5600 + D_001425C0[0x97])->level == 0) {
            v->rate = 1.0f / (D_L01_002C5600 + D_001425C0[0x97])->shots_per_second;
        } else {
            v->rate = 1.0f / (D_L01_002C5600 + D_001425C0[0x97])->shots_per_second * 1.3f;
        }
    }
tail:
    if (m[0x42] == m[0x43] && (m[0x60] & 2)) {
        func_L01_00444F38(m, 1, 0, 2, 0);
    }
    if (m[0x42] != 2 && v->glow > 0) {
        if (v->glow > 10) {
            x = (f32)(12 - v->glow);
            c0 = x * 0.5f;
            c2 = x * 0.8f * 0.5f;
            c1 = x * 0.5f * 0.5f;
        } else {
            x = (f32)v->glow;
            c0 = x * 0.1f;
            c1 = x * 0.5f * 0.1f;
            c2 = x * 0.8f * 0.1f;
        }
        if (*(s16 *)(D_001A4BE0_00381720 + 0x2874) != 0) {
            func_0038CE20(&dir, m + 0xD0, -1.0f);
        } else if (*(s32 *)(D_001A4BE0_00381720 + 0x16B0) == 1) {
            *(Q_00381720 *)&dir = *(Q_00381720 *)&D_L01_001E29E0;
        } else {
            *(Q_00381720 *)&dir = *(Q_00381720 *)(D_001A4BE0_00381720 + 0x6F0);
        }
        func_0038D000(&pos, D_L01_001DDCE0_00381720, m + 0xC0);
        vec_add_ba(&pos, m + 0x10, &pos);
        vec_add_ba(&pos, &pos, &dir);
        func_0038CE20(&muzzle, *(u8 **)(D_001A4BE0_00381720 + 0x25C0) + 0xE0, 0.3f);
        vec_add_ab(&pos, &pos, &muzzle);
        if (v->light == -1) {
            v->light = func_L01_00424CB0(&pos, 8.0f, 0.0f, c0, c2, c1);
        } else {
            *(Q_00381720 *)&D_L01_001F1B40_00381720[v->light].pos = *(Q_00381720 *)&pos;
            D_L01_001F1B40_00381720[v->light].f8 = c1;
            D_L01_001F1B40_00381720[v->light].pos.w = 8.0f;
            D_L01_001F1B40_00381720[v->light].f0 = c0;
            D_L01_001F1B40_00381720[v->light].f4 = c2;
        }
        func_0038CB00(&v->glow);
    } else if (v->light != -1) {
        func_L01_00424D88(v->light);
        v->light = -1;
        v->glow = 0;
    }
    if (func_0038CAD0(&D_L01_001E1E94_00381720) == 0) {
        func_L01_00404A10(func_L01_00382500, m);
    }
}
/* localdecomp:end func_L01_00381720 */

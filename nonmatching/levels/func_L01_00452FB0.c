/* func_L01_00452FB0 (Claude wave 14 r60, 2026-11-28). First draft kept here. */
#include "common.h"

/* func_L01_00452FB0 (fresh entry, first draft). Blocked in its file: func_L01_00452F78's block declares
 * `extern void func_L01_00452FB0();`, but retail returns the state in v0 (the callers in
 * L01_00353EA0.c, L01_003AF290.c and L01_003BCDF8.c use it as s32 (void *, void *, s32, s32, s32)), so
 * this definition only compiles once that declaration says s32. Measured with tools/check.py --no-context
 * (level 01): 423 positional, but LCS-aligned only 18 rows differ, all from one cause: retail keeps the
 * constant 1 of the func_L01_00447490 argument in a saved register ($s6) and reuses it for `mode = 1`
 * (move s0,s6; movn s0,zero,v0), so mode is $s0 and the two D_001425C0/D_L01_002C5600 high halves are
 * $fp/$s6; here the 1 is a fresh $v0, mode becomes a store-flag (sltiu) in $s6 and the high halves
 * shift to $s0/$fp. Tried for it: the ternary both ways, mode = 1 before/after the hit load, a
 * variable holding 1, u8/s16 mode: no change. Levers that fixed the rest: re-reading *(f32 *)cfg,
 * obj->0x2C and ai[0x77] (gcse turns them into retail's copies), the abs_asm helper for the frame
 * distance (blezl/neg, the file has no other abs), the D_L01_001DFB40 gp slot under an alias name
 * (retail reads it once absolute, once $gp-relative). */

/* localdecomp:start func_L01_00452FB0 */
#include "vu0.h"
typedef struct {
    u8 b0;
    u8 b1;
    u8 p2[0x4E];
    f32 f50;
    u8 p54[0xF0 - 0x54];
} Row_00452FB0;
extern u8 D_001425C0[];
extern Row_00452FB0 D_L01_002C5600[];
extern u8 D_001A4C60[];
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DFB40_00452FB0;
__asm__(".extern D_L01_001DFB40_00452FB0, 4");
extern u8 *D_L01_001E001C;
__asm__(".extern D_L01_001E001C, 4");
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_00452E60(u8 *m, u8 *o);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_L01_004474E8(void *, void *);
extern s32 func_L01_00452F30(s32 a0, u8 *a1);
extern void func_L01_00455E18(void *, void *, void *);
extern void func_L01_00459BE8(void *, s32, f32);
extern f32 func_L01_004510F8(void *, void *, s32);
extern void func_L01_00451048(void *, void *, void *, s32, f32);
extern s32 func_003C56E0(void *, void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00454370(void *, void *);
extern void func_003C4A40(void *, void *);
extern void func_0038CE20(void *, void *, f32);

s32 func_L01_00452FB0(u8 *self, u8 *ai, s32 o, s32 flag, s32 flag2) {
    vu0_v4 tgt;
    u8 *t;
    u8 *tm;
    u8 *cfg;
    u8 *obj;
    u8 *p;
    Row_00452FB0 *row;
    f32 hit;
    f32 dmg;
    f32 lim;
    s32 st;
    s32 mode;
    s32 thr;
    s32 d;
    s32 ok;

    st = 0;
    if (!(*(u16 *)(self + 0x34) & 0x20)) {
        return 0;
    }
    t = *(u8 **)(self + 0x68);
    cfg = *(u8 **)t;
    tm = *(u8 **)(t + 0x20);
    if (ai == 0) {
        return 0;
    }
    if (cfg == 0) {
        return 0;
    }
    func_L01_0044ABD0(self, ai);
    func_L01_00452E60(self, ai);
    hit = 0.0f;
    obj = func_L01_00447490(self, flag == 0 ? 0x10000 : 1, 0);
    mode = 0;
    if (func_0038CB00(cfg + 6) == 0) {
        obj = 0;
    }
    func_0038CAD0(ai + 0xBC);
    if (obj != 0) {
        hit = *(f32 *)(obj + 0x2C);
        mode = 1;
        if (obj[0x28] != 0xA) {
            mode = 0;
        }
        if (mode && *(s16 *)(self + 0xAA) == 0x1B39 && *(f32 *)cfg <= 0.0f) {
            mode = 0;
        }
        if (*(f32 *)(ai + 0xA8) != 0.0f && *(u8 **)(obj + 0x20) != 0
            && *(s16 *)(self + 0xAA) == *(s16 *)(*(u8 **)(obj + 0x20) + 0xAA)) {
            *(f32 *)(obj + 0x2C) = *(f32 *)(obj + 0x2C) * *(f32 *)(ai + 0xA8);
        }
        if (o) {
            *(f32 *)(obj + 0x2C) = *(f32 *)(obj + 0x2C) * *(f32 *)(ai + 0xAC);
        }
    }
    dmg = func_L01_004474E8(self, obj);
    self[0xA8] = 0xFF;
    if (func_L01_00452F30((s32)self, ai) != 0 || *(f32 *)(self + 0x18) < *(f32 *)(ai + 0x40)) {
        dmg = *(f32 *)cfg;
        obj = 0;
    }
    if (!mode) {
        *(f32 *)cfg = *(f32 *)cfg - dmg;
    }
    if (D_L01_002C5600[D_001425C0[0x37]].b1 != 0 && obj != 0) {
        p = *(u8 **)(obj + 0x20);
        if (p != 0 && (*(u16 *)(p + 0x34) & 0x20) && *(u8 **)(p + 0x68) != 0
            && **(u8 ***)(p + 0x68) != 0 && (**(u8 ***)(p + 0x68))[0x2F] != 0) {
            if (*(f32 *)cfg <= (f32)*(s16 *)(cfg + 4) * 0.75f) {
                cfg[0x2F] = 1;
            }
        }
    }
    if (tm != 0) {
        func_L01_00455E18(self, tm, cfg);
    }
    if (dmg == 0.0f) {
        return 0;
    }
    func_L01_00459BE8(self, cfg[0x17], dmg);
    *(s16 *)(ai + 0x70) = -1;
    if (obj != 0 && *(u8 **)(obj + 0x20) != 0) {
        *(s16 *)(ai + 0x70) = (*(u8 **)(obj + 0x20) - D_L01_001E001C) >> 8;
    }
    row = &D_L01_002C5600[D_001425C0[cfg[0x17]]];
    lim = (f32)*(s16 *)(cfg + 4) * *(f32 *)(ai + 0x58);
    thr = 0x12C;
    if (lim <= dmg * row->f50) {
        thr = 0x5A;
    }
    if (ai[0x77] == 0) {
        d = abs_asm(D_L01_001DFB40 - *(s32 *)(ai + 0x44));
        if ((thr * 5 + 2) / 6 < d && dmg < lim) {
            dmg = lim;
        }
    }
    if (mode) {
        st = 3;
    } else {
        if (*(f32 *)cfg <= 0.0f) {
            st = 4;
        } else if ((f32)*(s16 *)(cfg + 4) * *(f32 *)(ai + 0x5C) <= dmg) {
            st = 3;
        } else if ((f32)*(s16 *)(cfg + 4) * *(f32 *)(ai + 0x58) <= dmg) {
            st = 2;
        } else if (dmg != 0.0f && ai[0x77] == 0 && obj != 0 && *(u8 **)(obj + 0x20) != 0
                   && *(s16 *)(*(u8 **)(obj + 0x20) + 0xAA) == 0x47) {
            st = 2;
        } else if (hit != 0.0f) {
            st = 1;
        }
        if (*(f32 *)cfg <= 0.0f && *(s16 *)(self + 0xAA) == 0x19DB) {
            st = 5;
        }
        if (obj != 0 && *(u8 **)(obj + 0x20) != 0 && *(s16 *)(*(u8 **)(obj + 0x20) + 0xAA) == 0x1843
            && *(s32 *)(ai + 0xB8) == 0) {
            st = *(f32 *)cfg <= 0.0f ? 4 : 2;
        }
        if (o && (u32)(st - 1) < 3) {
            st = 6;
        }
    }
    if (st >= 2 && obj != 0 && cfg[0x17] == 9) {
        f32 r = func_L01_004510F8(self, obj + 0x10, 0);
        vec_sub_ab(obj + 0x10, self + 0x10, D_001A4C60);
        func_L01_00451048(self, obj + 0x10, obj + 0x10, 0, r);
    }
    if (st == 0) {
        return 0;
    }
    if (*(u16 *)(ai + 0x38) & 3) {
        return 0;
    }
    if (self[0x95] == ai[0x48] && st < 4) {
        if (ai[0x75] != 0) {
            return 0;
        }
        if (ai[0x1A] < 2) {
            return 0;
        }
    }
    if (obj != 0 && (*(u32 *)(obj + 0x30) & 1)) {
        *(vu0_q *)&tgt = *(vu0_q *)(obj + 0x10);
    } else {
        func_0038CE20(&tgt, self + 0xC0, -1.0f);
        tgt.z = 1.0f;
        tgt.w = 5627.925f;
    }
    ok = 1;
    if (*(u32 *)(ai + 0xB4) & 1) {
        if ((ai[0x10] == 0xFF || self[0x20] == ai[0x10]) && (ai[0x48] == 0xFF || self[0x95] == ai[0x48])) {
            if (st != 4) {
                ok = 0;
            }
        }
    }
    if ((*(s32 *)(ai + 0xBC) != 0 || flag2 != 0) && !(*(f32 *)cfg <= 0.0f)) {
        goto done;
    }
    if (!ok) {
        goto done;
    }
    if (func_003C56E0(self, ai, &tgt, st, -1) != 0) {
        *(s32 *)(ai + 0x44) = D_L01_001DFB40_00452FB0;
        if (ai[0x48] != 0xFF && ai[0x48] != 0) {
            func_L01_004450F0(self, ai[0x10], ai[0x48]);
        } else if (ai[0x10] != 0xFF && ai[0x10] != 0) {
            func_L01_004450F0(self, ai[0x10], -1);
        }
        ai[0x1A] = 0;
        func_L01_00454370(self, ai);
    }
    return st;
done:
    ai[7] = 0xFF;
    func_003C4A40(self, ai);
    return st;
}
/* localdecomp:end func_L01_00452FB0 */

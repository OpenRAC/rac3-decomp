/* functional: medium. written from the PAL asm, no draft; 343 diff words (frame 0x10 larger, scheduling, hoisted hero pointer); op multiset equals retail incl. all constants; fields at hero+0x400..0x420 form a keyframe-walker record (+0x14 table of 12-byte keys, +0x18 index, +0x1C tick, +0x20 value); sqrt.s emitted via sqrt_asm */
#include "vu0.h"
extern u8 D_001A4BE0_004F1638[];
extern vu0_q D_001A4C60[];
extern u8 D_001A4CD0[];
extern u8 D_001A30B0[];
extern u8 D_00142CA2;
extern u8 *D_001D52FC;
void func_L01_004F1638(void) {
    extern void func_L01_00511508(void *, void *, f32);
    extern void func_L01_00510F08(void *, void *, f32);
    extern void func_L01_00511280(void *, void *, f32);
    extern f32 func_L01_005114B0(void *);
    extern void func_L01_005110E8(void *, s32, f32, f32, f32);
    extern s32 func_L01_004E9238(s32);
    extern void func_L01_004F4F18(s32, s32, s32);
    extern void func_003A4F28(s32);
    extern s32 func_003A3BB8(s32, s32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern f32 func_003C4138(f32 *, f32, f32);
    u8 *h = D_001A4BE0_004F1638;
    u8 *p;
    u8 *t;
    s32 state, timer;
    s32 grounded;
    s32 flag;
    f32 scale, vz, lim;
    f32 vec_d[4];
    f32 probe_a[4];
    f32 probe_b[4];
    f32 clampv;

    state = *(s32 *)(h + 0x25C4);
    /* stage 1: damp the hero velocity depending on state and timers */
    if (state == 0x1B && *(s32 *)(h + 0x1B8) < 3) {
        /* nothing */
    } else if (state == 0x48 && *(s32 *)(h + 0x1B8) < 0xB) {
        /* nothing */
    } else {
        timer = *(s32 *)(h + 0x1B8);
        p = h + 0xF0;
        if (timer < *(s16 *)(h + 0x47C)) {
            func_L01_00511508(p, p, 0.0f);
            func_L01_00510F08(p, p, 0.0192000009f);
        } else if (h[0x46C] != 0) {
            func_L01_00511508(p, p, 0.0f);
            func_L01_00510F08(p, p, 0.0216000006f);
        } else {
            func_L01_00510F08(p, p, *(f32 *)(h + 0x4F0));
            vz = func_L01_005114B0(p);
            clampv = -*(f32 *)(h + 0x470);
            if (vz < clampv) vz = clampv;
            func_L01_00511508(p, p, vz);
        }
    }

    h = D_001A4BE0_004F1638;
    if (*(s32 *)(h + 0x25C4) == 0xE) {
        scale = 0.140000015f;
        grounded = 0;
        if (D_00142CA2 != 0 && *(s16 *)(h + 0x2884) == 0)
            grounded = (func_L01_004E9238(3) == 3);
        p = (u8 *)D_001A4C60;
        vec_sub_ab(vec_d, p, p + 0x3B0);
        vz = func_L01_005114B0(vec_d);
        if (grounded) {
            u8 *hh = p - 0x80;
            if (hh[0x46E] == 0) {
                func_L01_004F4F18(4, *(s32 *)(hh + 0x25C0), 0xD);
            } else {
                s32 idx = *(s32 *)(hh + 0x279C);
                if (idx != -1) {
                    u8 *rec = D_001A30B0 + idx * 128;
                    if (*(s32 *)(rec + 0xDC) == *(s32 *)(hh + 0x25C0) && rec[0xD0] != 0)
                        func_003A4F28(idx);
                }
                *(s32 *)(hh + 0x279C) = -1;
            }
        }
        func_L01_005110E8(probe_a, 1, 0.0f, 0.0f, 1.0f);
        func_L01_005110E8(probe_b, 1, 0.0f, 0.0f, 2.7f);
        if (!func_003D3CB0(probe_a, probe_b, 2, 0, 0)) {
            if (2.8f < vz) scale *= 0.47f;
            else if (2.2f < vz) scale *= 0.7f;
        } else {
            if (2.1f < vz) scale *= 0.45f;
            else if (1.7f < vz) scale *= 0.7f;
        }
        h = D_001A4BE0_004F1638;
        scale *= 1.25f;
        if (*(s32 *)(h + 0x1B8) < 7) {
            f32 cur;
            p = h + 0xF0;
            cur = func_L01_005114B0(p);
            lim = cur;
            if (cur < scale) func_003C4138(&lim, scale, 0.0600000024f);
            func_L01_00511508(p, p, lim);
        }
        return;
    }

    flag = 0;
    if (*(f32 *)(h + 0x480) == 0.0f && *(f32 *)(h + 0x484) == 0.0f) flag = 1;
    if ((*(s32 *)(D_001D52FC + 0x1A0) & func_003A3BB8(0x40, 0)) || flag ||
        *(s32 *)(h + 0x25C4) == 0x12) {
        f32 a = *(f32 *)(h + 0x478);
        f32 b = *(f32 *)(h + 0x4DC);
        if (a < b) {
            s32 steps = *(s16 *)(h + 0x4E8);
            if (!(steps < *(s32 *)(h + 0x1B8))) {
                a = a + (b - *(f32 *)(h + 0x4D8)) / (f32)steps;
                *(f32 *)(h + 0x478) = a;
                if (b < a) *(f32 *)(h + 0x478) = b;
                {
                    f32 s = sqrt_asm((*(f32 *)(h + 0x478) + *(f32 *)(h + 0x478)) * *(f32 *)(h + 0x4F0));
                    s = s - *(f32 *)(h + 0x484);
                    s = s - *(f32 *)(h + 0x480);
                    *(f32 *)(h + 0x480) = *(f32 *)(h + 0x480) + s;
                }
            }
        }
    }
    if (!(*(s32 *)(h + 0x1B8) < *(s16 *)(h + 0x47C))) {
        f32 e = *(f32 *)(h + 0x480);
        if (0.0f < e) {
            f32 c;
            func_L01_00511280(h + 0xF0, h + 0xF0, e);
            c = *(f32 *)(h + 0x484);
            e = *(f32 *)(h + 0x480);
            *(f32 *)(h + 0x480) = 0.0f;
            *(f32 *)(h + 0x484) = c + e;
        }
    }

    if (h[0x46D] == 0) return;
    timer = *(s32 *)(h + 0x1B8);
    if (timer < *(s32 *)(h + 0x400)) return;
    if (!(timer < *(s32 *)(h + 0x404))) return;
    t = h + 0x400;
    {
        s32 idx = *(s32 *)(t + 0x18);
        s32 cnt = *(s32 *)(t + 0x1C) + 1;
        u8 *e;
        s32 limit;
        *(s32 *)(t + 0x1C) = cnt;
        if (idx != -1) {
            e = *(u8 **)(t + 0x14) + idx * 12;
            limit = (*(s32 *)(e + 8) * 5 + 2) / 6;
            if (cnt < limit) goto advance;
        }
        for (;;) {
            u8 *tbl;
            f32 key;
            idx = *(s32 *)(t + 0x18) + 1;
            tbl = *(u8 **)(t + 0x14);
            *(s32 *)(t + 0x1C) = 0;
            *(s32 *)(t + 0x18) = idx;
            key = *(f32 *)(tbl + idx * 12);
            if (key != -999999.0f) *(f32 *)(t + 0x20) = key * 0.000400000019f;
            idx = *(s32 *)(t + 0x18);
            if (idx == -1) continue;
            e = *(u8 **)(t + 0x14) + idx * 12;
            limit = (*(s32 *)(e + 8) * 5 + 2) / 6;
            if (*(s32 *)(t + 0x1C) < limit) break;
        }
    advance:
        idx = *(s32 *)(t + 0x18);
        if (*(s32 *)(t + 0x1C) > 0) {
            *(f32 *)(t + 0x20) = *(f32 *)(t + 0x20) +
                *(f32 *)(*(u8 **)(t + 0x14) + idx * 12 + 4) * 0.000400000019f;
        }
        func_L01_00511280(D_001A4CD0, D_001A4CD0, *(f32 *)(t + 0x20));
    }
}

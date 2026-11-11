/* Level 02 (Florana), PAL. 407 diff with check.py --as ps2as --flags=-mvu0-use-vf0-vf2 and a divs_nops row `2 1 2` (the file has neither yet). The weapon auto-aim target search: scans the moby list, skips dead and excluded classes, aims at each candidate (atan2 yaw/pitch, distance), accepts a close target in a cone (two variants on hero state), otherwise checks the lead angle against the $gp range tunables and walks line of sight through up to seven blockers (collected and later restored), keeping the nearest; returns the moby and writes yaw/pitch.
   What differs: the logic follows the bytes block for block, but register allocation is far apart: retail keeps &pos ($s3), the yaw pointer ($s6), the blocker count ($s5), &tp twice ($fp, $s7) and the ok flag ($s4) in saved registers and spills self, the pitch pointer, the link, the result and the list index to the frame; this C spills other values, so most instructions differ in registers or order. Same code as its twin (other data). Twin: func_L17_0037CA28. */
#include "vu0.h"
typedef struct { u8 p0[0xA]; u8 bA; u8 pB[3]; u8 bE; u8 pF; f32 f10; } TI_37A910;
typedef struct { u8 p0[0x80]; f32 f80; f32 f84; u8 p88[0x2BC]; f32 f344; u8 p348[0x20]; s16 h368; u8 p36A[0x2256]; u8 *f25C0; } H_37A910;
extern H_37A910 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern u8 *D_L02_0021B8A0[];
extern u8 *D_L02_001E8058[];
extern vu0_v4 D_L02_001E8060;
extern s32 D_L02_001D673C[];
extern s32 D_L02_001D6740;
__asm__(".extern D_L02_001D6740, 4");
extern f32 D_L02_001DD530;
extern f32 D_L02_001DD534;
__asm__(".extern D_L02_001DD530, 4");
__asm__(".extern D_L02_001DD534, 4");
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern TI_37A910 *func_00382348(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0C8(f32);
extern void func_00382760(void *, f32, f32, f32);

u8 *func_L02_0037A910(u8 *self, vu0_v4 *from, f32 *yaw, f32 *pitch) {
    vu0_v4 pos, off, eye;
    vu0_v4 *pp;
    vu0_v4 *ptp;
    u8 *list[0x80];
    vu0_v4 tp, tmp, rel, tmp2;
    u8 *link;
    u8 *best;
    s32 i, k, n, ok;
    u8 *m;
    TI_37A910 *t;
    f32 range, a, p, dy, dist, d, l, ang, r;

    pp = &pos;
    *pp = *from;
    range = D_L02_001DD534;
    link = *(u8 **)(self + 0x68);
    best = 0;
    func_0038CE20(&off, D_001A4BE0.f25C0 + 0xE0, 0.5f);
    vec_add_ba(&eye, D_001A4BE0.f25C0 + 0x10, &off);
    if (func_003D3CB0(&eye, pp, 6, D_001A4BE0.f25C0, 0) != 0) {
        pos = D_L02_001E8060;
        return 0;
    }
    n = 0;
    for (i = 0; (m = D_L02_0021B8A0[i]) != 0; i++) {
        if (m[0x20] == 0xFE) continue;
        if (m[0x20] == 0xFD) continue;
        if (*(s16 *)(m + 0xAA) == 0x1BC3 || *(s16 *)(m + 0xAA) == 0x189B ||
            *(s16 *)(m + 0xAA) == 0x1D3E || *(s16 *)(m + 0xAA) == 0x1A90) continue;
        ptp = &tp;
        tp = *(vu0_v4 *)(m + 0x10);
        t = func_00382348(m);
        if (t == 0 || t->bE == 3) continue;
        func_0038CE20(&tmp, m + 0xE0, t->f10);
        vec_add_ab(ptp, ptp, &tmp);
        if (m == 0) continue;
        if (*(u8 **)(m + 0x24) == 0 || (*(u8 **)(m + 0x24))[0x46] != 5) continue;
        ok = 0;
        a = func_0038D160(tp.x - pp->x, tp.y - pp->y);
        p = func_0038D160(func_0038CF38(pp, ptp), tp.z - pp->z);
        dy = func_0038DBA0(*yaw, a);
        dist = func_0038CF00(pp, ptp);
        if (D_L02_001D673C[0] != 0 || D_001A4BE0.h368 != 0 || D_L02_001D6740 != 0) {
            if (dist < 2.5f) {
                vec_sub_ab(&rel, m + 0x10, D_001A4BE0.f25C0 + 0x10);
                d = func_0038CE68(&rel, D_001A4BE0.f25C0 + 0xE0);
                if (fabs_asm(d) < 2.0f) {
                    func_0038CE20(&tmp2, D_001A4BE0.f25C0 + 0xE0, d);
                    vec_sub_ab(&rel, &rel, &tmp2);
                    d = func_0038CE68(&rel, D_001A4BE0.f25C0 + 0xC0);
                    l = func_0038CEA8(&rel);
                    if (l != 0.0f) {
                        if (1.5707964f - func_0038D0C8(d / l) < 1.0471976f) ok = 1;
                    }
                }
            }
        } else {
            if (dist < 2.5f) {
                u8 *h = D_001A4BE0.f25C0;
                a = func_0038D160(*(f32 *)(m + 0x10) - D_001A4BE0.f80,
                                  *(f32 *)(m + 0x14) - D_001A4BE0.f84);
                if (func_0038DBA0(*(f32 *)(h + 0xF8), a) < 1.0471976f) {
                    if (fabs_asm(pp->z - tp.z) < 2.0f) ok = 1;
                }
            }
        }
        if (ok) {
            if (func_003D3CB0(pp, ptp, 6, D_001A4BE0.f25C0, 0) == 0) {
                *pitch = -p;
                best = m;
                *yaw = a;
                break;
            }
        }
        if (range < dist && *(u8 **)(link + 0x10) != m) continue;
        if (D_L02_001DD534 < dist) continue;
        func_00382760(&tmp, dist, *yaw, *pitch + D_001A4BE0.f344 * 0.5f);
        vec_add_ab(&tmp, &tmp, pp);
        ang = func_0038D0C8(func_0038CF00(&tmp, ptp) / (dist + dist));
        ang = ang + ang;
        if (D_L02_001DD530 * 0.017453292f < ang) {
            t = func_00382348(m);
            if (t != 0) {
                r = (f32)t->bA * 0.125f;
                l = func_0038D0C8(r / dist);
                if (r < dist) {
                    ang -= l;
                    if (ang < 0.0f) ang = 0.0f;
                }
            }
        }
        if (!(ang < D_L02_001DD530 * 0.017453292f)) continue;
        ok = 1;
        rel = pos;
        for (k = 0; k < 7; k++) {
            u8 *b;
            if (func_003D3CB0(&rel, ptp, 6, self, 0) == 0) break;
            b = D_L02_001E8058[0];
            if (b == 0) { ok = 0; break; }
            if (*(s16 *)(b + 0xAA) == 0x1BC3 || *(s16 *)(b + 0xAA) == 0x189B || *(s16 *)(b + 0xAA) == 0x1D3E) {
                list[n++] = b;
                if (n >= 0x80) break;
                *(s32 *)(b + 0x98) = 0;
                rel = D_L02_001E8060;
                continue;
            }
            if (b != m) ok = 0;
            break;
        }
        if (ok) {
            *pitch = -p;
            range = dist;
            if (dy < 0.34906584f) *yaw = a;
            best = m;
            if (*(u8 **)(link + 0x10) == m) return best;
        }
    }
    for (k = 0; k < n; k++) {
        *(s32 *)(list[k] + 0x98) = *(s32 *)(*(u8 **)(list[k] + 0x24) + 0x10);
    }
    return best;
}

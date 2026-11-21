/* functional: medium. Medium: control flow reconstructed by hand from the asm, not diffed; the 0x98 field is cleared during raycasts and restored from def->0x10 after. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L07_0037F620 */
extern u8 D_001A4BE0[];
extern u8 D_L07_001E8C00[];
extern u8 *D_0021C460[];
extern s32 D_001D673C;
extern s32 D_001D6740_sda;
extern f32 D_001DDBF0_sda;
extern f32 D_001DDBF4_sda;
__asm__(".extern D_001D6740_sda, 4");
__asm__(".extern D_001DDBF0_sda, 4");
__asm__(".extern D_001DDBF4_sda, 4");
static __inline__ void add_ab_0037F620(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void sub_ab_0037F620(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
u8 *func_L07_0037F620(u8 *self, vu0_v4 *origin, f32 *yaw, f32 *pitch) {
    extern void *func_00382348(void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038CEA8(void *);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038D0C8(f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DBA0(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    vu0_v4 pos;
    vu0_v4 half;
    vu0_v4 eye;
    u8 *list[0x80];
    vu0_v4 tpos;
    vu0_v4 offs;
    vu0_v4 delta;
    vu0_v4 tmp;
    u8 *hero = *(u8 **)(D_001A4BE0 + 0x25C0);
    u8 *state = *(u8 **)(self + 0x68);
    u8 *result = 0;
    u8 *m;
    u8 *ob;
    s32 count = 0;
    s32 i = 0;
    s32 k;
    s32 ok;
    f32 best = D_001DDBF4_sda;
    f32 heading, pitch_to, diff, dist, ang, lim, dot, len;

    *(vu0_q *)&pos = *(vu0_q *)origin;
    func_0038CE20(&half, hero + 0xE0, 0.5f);
    add_ab_0037F620(&eye, hero + 0x10, &half);
    if (func_003D3CB0(&eye, &pos, 6, hero, 0) != 0) {
        *(vu0_q *)&pos = *(vu0_q *)(D_L07_001E8C00 + 0x20);
        return 0;
    }
    for (m = D_0021C460[0]; m != 0; m = D_0021C460[i]) {
        i++;
        if (m[0x20] == 0xFE || m[0x20] == 0xFD) continue;
        if (*(s16 *)(m + 0xAA) == 0x1BC3 || *(s16 *)(m + 0xAA) == 0x189B ||
            *(s16 *)(m + 0xAA) == 0x1D3E || *(s16 *)(m + 0xAA) == 0x1A90) continue;
        *(vu0_q *)&tpos = *(vu0_q *)(m + 0x10);
        ob = func_00382348(m);
        if (ob == 0) continue;
        if (ob[0xE] == 3) continue;
        func_0038CE20(&offs, m + 0xE0, *(f32 *)(ob + 0x10));
        add_ab_0037F620(&tpos, &tpos, &offs);
        if (*(u8 **)(m + 0x24) == 0) continue;
        if ((*(u8 **)(m + 0x24))[0x46] != 5) continue;
        ok = 0;
        heading = func_0038D160(tpos.x - pos.x, tpos.y - pos.y);
        pitch_to = func_0038D160(func_0038CF38(&pos, &tpos), tpos.z - pos.z);
        diff = func_0038DBA0(*yaw, heading);
        dist = func_0038CF00(&pos, &tpos);
        if (D_001D673C != 0 || *(s16 *)(D_001A4BE0 + 0x368) != 0 || D_001D6740_sda != 0) {
            if (dist < 2.5f) {
                sub_ab_0037F620(&delta, m + 0x10, hero + 0x10);
                dot = func_0038CE68(&delta, hero + 0xE0);
                if (__builtin_fabsf(dot) < 2.0f) {
                    func_0038CE20(&tmp, hero + 0xE0, dot);
                    sub_ab_0037F620(&delta, &delta, &tmp);
                    ang = func_0038CE68(&delta, hero + 0xC0);
                    len = func_0038CEA8(&delta);
                    if (len != 0.0f) {
                        if (1.5707964f - func_0038D0C8(ang / len) < 1.0471976f) ok = 1;
                    }
                }
            }
        } else {
            if (dist < 2.5f) {
                ang = func_0038D160(*(f32 *)(m + 0x10) - *(f32 *)(D_001A4BE0 + 0x80),
                                    *(f32 *)(m + 0x14) - *(f32 *)(D_001A4BE0 + 0x84));
                if (func_0038DBA0(*(f32 *)(hero + 0xF8), ang) < 1.0471976f) {
                    if (__builtin_fabsf(pos.z - tpos.z) < 2.0f) ok = 1;
                }
            }
        }
        if (ok) {
            if (func_003D3CB0(&pos, &tpos, 6, hero, 0) == 0) {
                result = m;
                *pitch = -pitch_to;
                *yaw = heading;
                goto finish;
            }
        }
        if (best < dist) {
            if (m != *(u8 **)(state + 0x10)) continue;
        }
        if (D_001DDBF4_sda < dist) continue;
        func_00382760(&offs, dist, *yaw, *pitch + *(f32 *)(D_001A4BE0 + 0x344) * 0.5f);
        add_ab_0037F620(&offs, &offs, &pos);
        lim = func_0038D0C8(func_0038CF00(&offs, &tpos) / (dist + dist));
        lim = lim + lim;
        if (D_001DDBF0_sda * 0.017453292f < lim) {
            ob = func_00382348(m);
            if (ob != 0) {
                f32 radius = (f32)ob[0xA] * 0.125f;
                f32 a2 = func_0038D0C8(radius / dist);
                if (radius < dist) {
                    lim -= a2;
                    if (lim < 0.0f) lim = 0.0f;
                }
            }
        }
        if (!(lim < D_001DDBF0_sda * 0.017453292f)) continue;
        ok = 1;
        *(vu0_q *)&eye = *(vu0_q *)&pos;
        for (k = 0; k < 7; k++) {
            u8 *hit;
            if (func_003D3CB0(&eye, &tpos, 6, self, 0) == 0) goto decided;
            hit = *(u8 **)(D_L07_001E8C00 + 0x18);
            if (hit == 0) {
                ok = 0;
                goto decided;
            }
            if (*(s16 *)(hit + 0xAA) == 0x1BC3 || *(s16 *)(hit + 0xAA) == 0x189B ||
                *(s16 *)(hit + 0xAA) == 0x1D3E) {
                list[count++] = hit;
                *(s32 *)(hit + 0x98) = 0;
                if (count >= 0x80) goto decided;
                *(vu0_q *)&eye = *(vu0_q *)(D_L07_001E8C00 + 0x20);
            } else {
                if (hit != m) ok = 0;
                goto decided;
            }
        }
decided:
        if (ok == 0) continue;
        *pitch = -pitch_to;
        best = dist;
        if (diff < 0.17453294f) *yaw = heading;
        result = m;
        if (m == *(u8 **)(state + 0x10)) goto finish;
    }
finish:
    for (k = 0; k < count; k++) {
        *(s32 *)(list[k] + 0x98) = *(s32 *)(*(u8 **)(list[k] + 0x24) + 0x10);
    }
    return result;
}
/* localdecomp:end func_L07_0037F620 */

#include "common.h"

/* localdecomp:start func_L11_003798E8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3798E8;
typedef struct { u8 pad0[0x80]; V4_3798E8 pos; u8 pad90[0x344 - 0x90]; f32 f344; u8 pad348[0x368 - 0x348]; s16 f368; u8 pad36A[0x25C0 - 0x36A]; u8 *hero; } G_3798E8;
static __inline__ void vcopy_3798E8(V4_3798E8 *d, V4_3798E8 *s) { *(vu0_q *)d = *(vu0_q *)s; }
extern G_3798E8 D_001A4BE0;
extern u8 *D_L11_0021BD20[];
extern s32 D_L11_001D673C;
extern V4_3798E8 D_L11_001E84E0;
extern u8 *D_L11_001E84D8[];
extern f32 D_001DD8C4_sda;
extern f32 D_001DD8C0_sda;
extern s32 D_001D6740_sda;
__asm__(".extern D_001DD8C4_sda, 4");
__asm__(".extern D_001DD8C0_sda, 4");
__asm__(".extern D_001D6740_sda, 4");
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern u8 *func_00382348(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0C8(f32);
extern void func_00382760(void *, f32, f32, f32);

u8 *func_L11_003798E8(u8 *a0, V4_3798E8 *a1, f32 *a2, f32 *a3)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    V4_3798E8 pos;
    V4_3798E8 t10;
    V4_3798E8 t20;
    u8 *list[0x80];
    V4_3798E8 t230;
    V4_3798E8 t240;
    V4_3798E8 t250;
    V4_3798E8 t260;
    u8 *ret;
    u8 *e;
    u8 *o;
    u8 *r;
    s32 idx;
    s32 n;
    s32 hit;
    s32 i;
    s32 j;
    V4_3798E8 *pp = &pos;
    f32 acs, len, best, ang_a, ang_b, ang_c, dist, f20, f21;

    best = D_001DD8C4_sda;
    pos = *a1;
    ret = 0;
    func_0038CE20(&t10, D_001A4BE0.hero + 0xE0, 0.5f);
    vec_add_ba(&t20, D_001A4BE0.hero + 0x10, &t10);
    if (func_003D3CB0(&t20, pp, 6, D_001A4BE0.hero, 0) != 0) {
        vcopy_3798E8(&pos, &D_L11_001E84E0);
        return 0;
    }
    n = 0;
    idx = 0;
    e = D_L11_0021BD20[0];
    if (e != 0) {
        do {
            s32 type = e[0x20];
            s32 id;
            if (type == 0xFE) goto next;
            if (type == 0xFD) goto next;
            id = *(s16 *)(e + 0xAA);
            if (id == 0x1BC3 || id == 0x189B || id == 0x1D3E || id == 0x1A90) goto next;
            t230 = *(V4_3798E8 *)(e + 0x10);
            r = func_00382348(e);
            if (r == 0) goto next;
            if (r[0xE] == 3) goto next;
            func_0038CE20(&t240, e + 0xE0, *(f32 *)(r + 0x10));
            vec_add_ab(&t230, &t230, &t240);
            if (e != 0 && *(u8 **)(e + 0x24) != 0 && (*(u8 **)(e + 0x24))[0x46] == 5) {
                hit = 0;
                ang_b = func_0038D160(t230.x - pp->x, t230.y - pp->y);
                ang_a = func_0038D160(func_0038CF38(pp, &t230), t230.z - pp->z);
                ang_c = func_0038DBA0(*a2, ang_b);
                dist = func_0038CF00(pp, &t230);
                if (D_L11_001D673C != 0 || D_001A4BE0.f368 != 0 || D_001D6740_sda != 0) {
                    if (dist < 2.5f) {
                        f32 d;
                        vec_sub_ab(&t250, e + 0x10, D_001A4BE0.hero + 0x10);
                        d = func_0038CE68(&t250, D_001A4BE0.hero + 0xE0);
                        if (fabs_asm(d) < 2.0f) {
                            func_0038CE20(&t260, D_001A4BE0.hero + 0xE0, d);
                            vec_sub_ab(&t250, &t250, &t260);
                            f20 = func_0038CE68(&t250, D_001A4BE0.hero + 0xC0);
                            len = func_0038CEA8(&t250);
                            if (len != 0.0f) {
                                if (1.5707964f - func_0038D0C8(f20 / len) < 1.0471976f) hit = 1;
                            }
                        }
                    }
                } else {
                    if (dist < 2.5f) {
                        if (func_0038DBA0(*(f32 *)(D_001A4BE0.hero + 0xF8), func_0038D160(*(f32 *)(e + 0x10) - D_001A4BE0.pos.x, *(f32 *)(e + 0x14) - D_001A4BE0.pos.y)) < 1.0471976f) {
                            if (fabs_asm(pp->z - t230.z) < 2.0f) hit = 1;
                        }
                    }
                }
                if (hit != 0) {
                    if (func_003D3CB0(pp, &t230, 6, D_001A4BE0.hero, 0) == 0) {
                        ret = e;
                        *a3 = -ang_a;
                        *a2 = ang_b;
                        goto done;
                    }
                }
                if (best < dist && e != *(u8 **)(v + 0x10)) goto next;
                if (D_001DD8C4_sda < dist) goto next;
                func_00382760(&t240, dist, *a2, *a3 + D_001A4BE0.f344 * 0.5f);
                vec_add_ab(&t240, &t240, pp);
                f21 = func_0038D0C8(func_0038CF00(&t240, &t230) / (dist + dist));
                f21 = f21 + f21;
                if (D_001DD8C0_sda * 0.017453292f < f21) {
                    r = func_00382348(e);
                    if (r != 0) {
                        f20 = r[0xA];
                        f20 = f20 * 0.125f;
                        acs = func_0038D0C8(f20 / dist);
                        if (f20 < dist) {
                            f21 = f21 - acs;
                            if (f21 < 0.0f) f21 = 0.0f;
                        }
                    }
                }
                if (f21 < D_001DD8C0_sda * 0.017453292f) {
                    hit = 1;
                    t250 = *pp;
                    i = 0;
                    while (func_003D3CB0(&t250, &t230, 6, a0, 0) != 0 && ++i < 7) {
                        o = D_L11_001E84D8[0];
                        if (o != 0) {
                            id = *(s16 *)(o + 0xAA);
                            if (id == 0x1BC3 || id == 0x189B || id == 0x1D3E) {
                                list[n++] = o;
                                *(s32 *)(o + 0x98) = 0;
                                if (n >= 0x80) break;
                                vcopy_3798E8(&t250, &D_L11_001E84E0);
                                continue;
                            }
                            if (o == e) break;
                        }
                        hit = 0;
                        break;
                    }
                    if (hit != 0) {
                        best = dist;
                        *a3 = -ang_a;
                        if (ang_c < 0.17453292f) *a2 = ang_b;
                        ret = e;
                        if (e == *(u8 **)(v + 0x10)) return ret;
                    }
                }
            }
        next:
            idx++;
            e = D_L11_0021BD20[idx];
        } while (e != 0);
    }
done:
    for (j = 0; j < n; j++) {
        u8 *p = list[j];
        *(s32 *)(p + 0x98) = *(s32 *)(*(u8 **)(p + 0x24) + 0x10);
    }
    return ret;
}
/* localdecomp:end func_L11_003798E8 */

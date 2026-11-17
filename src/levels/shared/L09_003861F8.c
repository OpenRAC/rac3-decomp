#include "common.h"

/* localdecomp:start func_L09_003861F8 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003861F8;

typedef struct M_003861F8 {
    u8 pad0[0x10];
    V4_003861F8 pos;            /* 0x10 */
    u8 f20;                     /* 0x20 */
    u8 pad21[3];
    u8 *f24;                    /* 0x24 */
    u8 pad28[0x98 - 0x28];
    s32 f98;                    /* 0x98 */
    u8 pad9C[0xAA - 0x9C];
    s16 fAA;                    /* 0xAA */
    u8 padAC[0xC0 - 0xAC];
    V4_003861F8 fC0;            /* 0xC0 */
    u8 padD0[0x10];
    V4_003861F8 fE0;            /* 0xE0 */
    u8 padF0[8];
    f32 fF8;                    /* 0xF8 */
} M_003861F8;

typedef struct {
    u8 pad0[0x80];
    f32 f80;                    /* 0x80 */
    f32 f84;                    /* 0x84 */
    u8 pad88[0x344 - 0x88];
    f32 f344;                   /* 0x344 */
    u8 pad348[0x368 - 0x348];
    s16 f368;                   /* 0x368 */
    u8 pad36A[0x25C0 - 0x36A];
    M_003861F8 *f25C0;          /* 0x25C0 */
} H_003861F8;

extern H_003861F8 D_001A4BE0;
extern M_003861F8 *D_L09_0021D7E0[];
extern M_003861F8 *D_L09_001E98D8 __attribute__((section(".data")));
extern V4_003861F8 D_L09_001E98E0;
extern s32 D_L09_001D673C;
__asm__(".extern D_L09_001D673C, 16");
extern s32 D_L09_001D6740;
__asm__(".extern D_L09_001D6740, 4");
extern f32 D_L09_001DDD24;
__asm__(".extern D_L09_001DDD24, 4");
extern f32 D_L09_001DDD20;
__asm__(".extern D_L09_001DDD20, 4");

extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern u8 *func_00382348(void *);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF00(void *, void *);

M_003861F8 *func_L09_003861F8(M_003861F8 *self, V4_003861F8 pos, f32 *yawOut, f32 *pitchOut) {
    V4_003861F8 a;
    V4_003861F8 b;
    M_003861F8 *list[128];
    V4_003861F8 mpos;
    V4_003861F8 t240;
    V4_003861F8 v;
    V4_003861F8 t260;
    M_003861F8 *m;
    M_003861F8 *prev;
    M_003861F8 *best;
    M_003861F8 *hit;
    u8 *p;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 vis;
    f32 bestDist;
    f32 yaw, pitch, dyaw, dist, ang, r, d, c;

    bestDist = D_L09_001DDD24;
    prev = *(M_003861F8 **)((u8 *)self + 0x68);
    best = 0;
    func_0038CE20(&a, &D_001A4BE0.f25C0->fE0, 0.5f);
    vec_add_ba(&b, &D_001A4BE0.f25C0->pos, &a);
    if (func_003D3CB0(&b, &pos, 6, D_001A4BE0.f25C0, 0) != 0) {
        pos = D_L09_001E98E0;
        return 0;
    }
    n = 0;
    for (i = 0; (m = D_L09_0021D7E0[i]) != 0; i++) {
        V4_003861F8 *hitPos = &D_L09_001E98E0;

        if (m->f20 == 0xFE) continue;
        if (m->f20 == 0xFD) continue;
        if (m->fAA == 0x1BC3 || m->fAA == 0x189B || m->fAA == 0x1D3E || m->fAA == 0x1A90) continue;
        mpos = m->pos;
        p = func_00382348(m);
        if (p == 0 || p[0xE] == 3) continue;
        func_0038CE20(&t240, &m->fE0, *(f32 *)(p + 0x10));
        vec_add_ab(&mpos, &mpos, &t240);
        if (m == 0 || m->f24 == 0 || m->f24[0x46] != 5) continue;
        vis = 0;
        yaw = func_0038D160(mpos.x - pos.x, mpos.y - pos.y);
        pitch = func_0038D160(func_0038CF38(&pos, &mpos), mpos.z - pos.z);
        dyaw = func_0038DBA0(*yawOut, yaw);
        dist = func_0038CF00(&pos, &mpos);
        if (D_L09_001D673C != 0 || D_001A4BE0.f368 != 0 || D_L09_001D6740 != 0) {
            if (dist < 2.5f) {
                vec_sub_ab(&v, &m->pos, &D_001A4BE0.f25C0->pos);
                d = func_0038CE68(&v, &D_001A4BE0.f25C0->fE0);
                if (fabs_asm(d) < 2.0f) {
                    func_0038CE20(&t260, &D_001A4BE0.f25C0->fE0, d);
                    vec_sub_ab(&v, &v, &t260);
                    c = func_0038CE68(&v, &D_001A4BE0.f25C0->fC0);
                    r = func_0038CEA8(&v);
                    if (r != 0.0f) {
                        if (1.5707964f - func_0038D0C8(c / r) < 1.0471976f) vis = 1;
                    }
                }
            }
        } else {
            if (dist < 2.5f) {
                if (func_0038DBA0(D_001A4BE0.f25C0->fF8,
                                  func_0038D160(m->pos.x - D_001A4BE0.f80, m->pos.y - D_001A4BE0.f84)) < 1.0471976f) {
                    if (fabs_asm(pos.z - mpos.z) < 2.0f) vis = 1;
                }
            }
        }
        if (vis) {
            if (func_003D3CB0(&pos, &mpos, 6, D_001A4BE0.f25C0, 0) == 0) {
                best = m;
                *pitchOut = -pitch;
                *yawOut = yaw;
                break;
            }
        }
        if (bestDist < dist && m != *(M_003861F8 **)((u8 *)prev + 0x10)) continue;
        if (D_L09_001DDD24 < dist) continue;
        func_00382760(&t240, dist, *yawOut, *pitchOut + D_001A4BE0.f344 * 0.5f);
        vec_add_ab(&t240, &t240, &pos);
        ang = func_0038D0C8(func_0038CF00(&t240, &mpos) / (dist + dist));
        ang = ang + ang;
        if (D_L09_001DDD20 * 0.017453292f < ang) {
            p = func_00382348(m);
            if (p != 0) {
                f32 rad = (f32)p[0xA] * 0.125f;
                f32 t = func_0038D0C8(rad / dist);
                if (rad < dist) {
                    ang -= t;
                    if (ang < 0.0f) ang = 0.0f;
                }
            }
        }
        if (!(ang < D_L09_001DDD20 * 0.017453292f)) continue;
        vis = 1;
        v = pos;
        j = 0;
        while (func_003D3CB0(&v, &mpos, 6, self, 0) != 0 && ++j < 7) {
            hit = D_L09_001E98D8;
            if (hit != 0) {
                if (hit->fAA == 0x1BC3 || hit->fAA == 0x189B || hit->fAA == 0x1D3E) {
                    list[n++] = hit;
                    hit->f98 = 0;
                    if (n >= 0x80) break;
                    v = *hitPos;
                    continue;
                }
                if (hit == m) break;
            }
            vis = 0;
            break;
        }
        if (vis) {
            *pitchOut = -pitch;
            bestDist = dist;
            if (dyaw < 0.17453292f) *yawOut = yaw;
            best = m;
            if (m == *(M_003861F8 **)((u8 *)prev + 0x10)) return best;
        }
    }
    for (k = 0; k < n; k++) {
        list[k]->f98 = *(s32 *)(list[k]->f24 + 0x10);
    }
    return best;
}
/* localdecomp:end func_L09_003861F8 */

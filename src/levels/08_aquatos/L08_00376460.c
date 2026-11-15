#include "common.h"

/* localdecomp:start func_L08_00376460 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00376460;

typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[0x46 - 0x14];
    u8 unk_46;
} PV_00376460;

typedef struct {
    u8 pad_00[0x10];
    V_00376460 pos;          /* 0x10 */
    u8 unk_20;               /* 0x20 */
    u8 pad_21[3];
    PV_00376460 *pvar;       /* 0x24 */
    u8 pad_28[0x98 - 0x28];
    s32 unk_98;              /* 0x98 */
    u8 pad_9c[0xAA - 0x9C];
    s16 oclass;              /* 0xAA */
    u8 pad_ac[0xC0 - 0xAC];
    V_00376460 unk_c0;       /* 0xC0 */
    u8 pad_d0[0xE0 - 0xD0];
    V_00376460 unk_e0;       /* 0xE0 */
    u8 pad_f0[0xF8 - 0xF0];
    f32 unk_f8;              /* 0xF8 */
} Moby_00376460;

typedef struct {
    u8 pad_00[0x80];
    f32 unk_80;
    f32 unk_84;
    u8 pad_88[0x344 - 0x88];
    f32 unk_344;
    u8 pad_348[0x368 - 0x348];
    s16 unk_368;
    u8 pad_36a[0x25C0 - 0x36A];
    Moby_00376460 *moby;     /* 0x25C0 */
} Hero_00376460;

typedef struct {
    u8 pad_00[0xA];
    u8 radius;               /* 0x0A: in eighths */
    u8 pad_0b[3];
    u8 kind;                 /* 0x0E */
    u8 pad_0f;
    f32 height;              /* 0x10 */
} Info_00376460;

typedef struct {
    u8 pad_00[0x10];
    Moby_00376460 *target;
} Tgt_00376460;

typedef struct {
    u8 pad_00[0x68];
    Tgt_00376460 *tgt;
} Self_00376460;

extern Hero_00376460 D_001A4BE0;
extern Moby_00376460 *D_L08_0021C2E0[];
extern Moby_00376460 *D_L08_001E8A98 __attribute__((section(".data")));
extern V_00376460 D_L08_001E8AA0;
extern s32 D_L08_001D673C;
__asm__(".extern D_L08_001D673C, 16");
extern s32 D_L08_001D6740;
extern f32 D_L08_001DD870;
__asm__(".extern D_L08_001DD870, 4");
extern f32 D_L08_001DD874;
__asm__(".extern D_L08_001DD874, 4");

extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern Info_00376460 *func_00382348(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0C8(f32);
extern void func_00382760(void *, f32, f32, f32);

Moby_00376460 *func_L08_00376460(Self_00376460 *a0, V_00376460 pos, f32 *yaw, f32 *pitch) {
    V_00376460 off;
    V_00376460 eye;
    Moby_00376460 *list[128];
    V_00376460 tpos;
    V_00376460 ofs;
    V_00376460 from;
    V_00376460 proj;
    Tgt_00376460 *tgt;
    Moby_00376460 *result;
    Moby_00376460 *m;
    s32 count;
    s32 i;
    s32 found;
    s32 j;
    s32 k;
    Info_00376460 *p;
    f32 best;
    f32 ang;
    f32 elev;
    f32 diff;
    f32 dist;
    f32 a;
    f32 r;
    f32 cs;
    f32 c;

    tgt = a0->tgt;
    result = 0;
    best = D_L08_001DD874;
    func_0038CE20(&off, &D_001A4BE0.moby->unk_e0, 0.5f);
    vec_add_ba(&eye, &D_001A4BE0.moby->pos, &off);
    if (func_003D3CB0(&eye, &pos, 6, D_001A4BE0.moby, 0)) {
        pos = D_L08_001E8AA0;
        return 0;
    }
    count = 0;
    for (i = 0; (m = D_L08_0021C2E0[i]) != 0; i++) {
        V_00376460 *hp = &D_L08_001E8AA0;

        if (m->unk_20 == 0xFE) continue;
        if (m->unk_20 == 0xFD) continue;
        if (m->oclass == 0x1BC3 || m->oclass == 0x189B || m->oclass == 0x1D3E || m->oclass == 0x1A90) continue;
        tpos = m->pos;
        p = func_00382348(m);
        if (p == 0) continue;
        if (p->kind == 3) continue;
        func_0038CE20(&ofs, &m->unk_e0, p->height);
        vec_add_ab(&tpos, &tpos, &ofs);
        if (m == 0 || m->pvar == 0 || m->pvar->unk_46 != 5) continue;
        found = 0;
        ang = func_0038D160(tpos.x - pos.x, tpos.y - pos.y);
        elev = func_0038D160(func_0038CF38(&pos, &tpos), tpos.z - pos.z);
        diff = func_0038DBA0(*yaw, ang);
        dist = func_0038CF00(&pos, &tpos);
        if (D_L08_001D673C != 0 || D_001A4BE0.unk_368 != 0 || D_L08_001D6740 != 0) {
            if (dist < 2.5f) {
                vec_sub_ab(&from, &m->pos, &D_001A4BE0.moby->pos);
                a = func_0038CE68(&from, &D_001A4BE0.moby->unk_e0);
                if (fabs_asm(a) < 2.0f) {
                    func_0038CE20(&proj, &D_001A4BE0.moby->unk_e0, a);
                    vec_sub_ab(&from, &from, &proj);
                    c = func_0038CE68(&from, &D_001A4BE0.moby->unk_c0);
                    r = func_0038CEA8(&from);
                    if (r != 0.0f) {
                        if (1.5707964f - func_0038D0C8(c / r) < 1.0471976f) found = 1;
                    }
                }
            }
        } else {
            if (dist < 2.5f) {
                Moby_00376460 *hm = D_001A4BE0.moby;
                if (func_0038DBA0(hm->unk_f8, func_0038D160(m->pos.x - D_001A4BE0.unk_80, m->pos.y - D_001A4BE0.unk_84)) < 1.0471976f) {
                    if (fabs_asm(pos.z - tpos.z) < 2.0f) found = 1;
                }
            }
        }
        if (found) {
            if (!func_003D3CB0(&pos, &tpos, 6, D_001A4BE0.moby, 0)) {
                result = m;
                *pitch = -elev;
                *yaw = ang;
                break;
            }
        }
        if (best < dist && m != tgt->target) continue;
        if (D_L08_001DD874 < dist) continue;
        func_00382760(&ofs, dist, *yaw, *pitch + D_001A4BE0.unk_344 * 0.5f);
        vec_add_ab(&ofs, &ofs, &pos);
        cs = 2.0f * func_0038D0C8(func_0038CF00(&ofs, &tpos) / (dist + dist));
        if (D_L08_001DD870 * 0.017453292f < cs) {
            p = func_00382348(m);
            if (p != 0) {
                f32 rad = (f32)p->radius * 0.125f;
                f32 t = func_0038D0C8(rad / dist);
                if (rad < dist) {
                    cs -= t;
                    if (cs < 0.0f) cs = 0.0f;
                }
            }
        }
        if (cs < D_L08_001DD870 * 0.017453292f) {
            found = 1;
            from = pos;
            for (j = 0; func_003D3CB0(&from, &tpos, 6, a0, 0); ) {
                Moby_00376460 *hit;
                if (++j >= 7) break;
                hit = D_L08_001E8A98;
                if (hit != 0) {
                    if (hit->oclass == 0x1BC3 || hit->oclass == 0x189B || hit->oclass == 0x1D3E) {
                        list[count++] = hit;
                        hit->unk_98 = 0;
                        if (count >= 128) break;
                        from = *hp;
                        continue;
                    }
                    if (hit == m) break;
                }
                found = 0;
                break;
            }
            if (found) {
                *pitch = -elev;
                best = dist;
                if (diff < 0.17453292f) *yaw = ang;
                result = m;
                if (m == tgt->target) return result;
            }
        }
    }
    for (k = 0; k < count; k++) {
        list[k]->unk_98 = list[k]->pvar->unk_10;
    }
    return result;
}
/* localdecomp:end func_L08_00376460 */

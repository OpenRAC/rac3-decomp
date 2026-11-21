#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0xA];
    u8 xA;
    u8 padB[0x10 - 0xB];
    f32 x10;
} S_432D60r;

typedef struct {
    u8 pad0[0x46];
    u8 x46;
} S_432D60c;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    s8 x20;
    u8 pad21[0x24 - 0x21];
    S_432D60c *x24;
    u8 pad28[0xF8 - 0x28];
    f32 xF8;
} S_432D60m;

extern u8 D_001A4BE0[];
extern vu0_v4 D_L23_001E19C0;
extern S_432D60m *D_L23_0021C520[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern S_432D60r *func_00382348(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D0C8(f32);
extern void func_00382760(void *, f32, f32, f32);

/* localdecomp:start func_L23_00432D60 */
S_432D60m *func_L23_00432D60(S_432D60m *self, vu0_v4 *from, vu0_v4 *dirp, f32 *yaw, f32 *pitch, f32 *out,
                             f32 maxang, f32 maxdist) {
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 mpos;
    vu0_v4 v30;
    S_432D60m **list;
    S_432D60m *found;
    S_432D60m *m;
    S_432D60r *r;
    s32 i;
    f32 ay;
    f32 ap;
    f32 dist;
    f32 a;
    f32 w;
    f32 c;
    u8 *h;
    vu0_v4 *pp;
    vu0_v4 *dp;

    pp = &pos;
    dp = &dir;
    *pp = *from;
    found = 0;
    *dp = *dirp;
    *yaw = func_0038D160(dp->x, dp->y);
    *pitch = -func_0038D160(func_0038CED8(dp), dp->z);
    h = D_001A4BE0;
    for (i = 0; (m = (list = D_L23_0021C520)[i]) != 0; i++) {
        if (m->x20 < 0) {
            continue;
        }
        mpos = m->pos;
        r = func_00382348(m);
        if (r != 0) {
            mpos.z += r->x10;
        } else {
            mpos.z += 0.5f;
        }
        if (m == 0 || m->x24 == 0 || m->x24->x46 != 5) {
            continue;
        }
        ay = func_0038D160(mpos.x - pp->x, mpos.y - pp->y);
        ap = func_0038D160(func_0038CF38(pp, &mpos), mpos.z - pp->z);
        dist = func_0038CF00(pp, &mpos);
        if (dist < 7.5f) {
            if (func_0038DBA0(self->xF8, func_0038D160(m->pos.x - self->pos.x, m->pos.y - self->pos.y)) < 1.0471976f) {
                if (__builtin_fabsf(ap) < 1.0471976f) {
                    *pitch = -ap;
                    *yaw = ay;
                    return m;
                }
            }
        }
        if (maxdist < dist) {
            continue;
        }
        func_00382760(&v30, dist, *yaw, *pitch + *(f32 *)(h + 0x344) * 0.5f);
        vec_add_ab(&v30, &v30, pp);
        a = func_0038D0C8(func_0038CF00(&v30, &mpos) / (dist + dist));
        a = a + a;
        if (maxang < a && r != 0) {
            w = r->xA * 8;
            w *= 0.125f;
            c = func_0038D0C8(w / dist);
            if (w < dist) {
                a -= c;
            }
        }
        if (!(a < maxang)) {
            continue;
        }
        if (func_003D3CB0(&D_L23_001E19C0, &mpos, 6, self, 0) != 0) {
            continue;
        }
        *pitch = -ap;
        found = m;
        maxdist = dist;
        *yaw = ay;
        if (r != 0) {
            *out = r->x10;
        } else {
            *out = 0.5f;
        }
    }
    return found;
}
/* localdecomp:end func_L23_00432D60 */

#include "common.h"

/* localdecomp:start func_L39_00648258 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00648258;

typedef struct Mb_00648258 Mb_00648258;
typedef struct {
    u8 pad[28];
    s32 (*fn)(void *, s32);
} VT_00648258;
typedef struct {
    u8 pad[20];
    VT_00648258 *vt;
} Ob_00648258;
struct Mb_00648258 {
    u8 pad00[0x10];
    V_00648258 pos;          /* 0x10 */
    u8 pad20[0x11];
    u8 f31;                  /* 0x31 */
    u8 pad32[2];
    u16 f34;                 /* 0x34 */
    u8 pad36[0x62];
    void *f98;               /* 0x98 */
    u8 pad9C[0xE];
    s16 fAA;                 /* 0xAA */
    u8 padAC[0x12];
    u8 fBE;                  /* 0xBE */
    u8 padBF;
    u8 mtx[0x40];            /* 0xC0 */
};
typedef struct {
    u8 pad[0x2548];
    s32 f2548;
} Pl_00648258;
typedef struct {
    V_00648258 dir;          /* 0x00 */
    u8 pad10[0x20];
    V_00648258 pos;          /* 0x30 */
    u8 pad40[0x3C];
    f32 f7C;                 /* 0x7C */
    u8 pad80[0xC];
    Mb_00648258 *target;     /* 0x8C */
    V_00648258 last;         /* 0x90 */
    V_00648258 vel;          /* 0xA0 */
    f32 fB0;                 /* 0xB0 */
    u8 padB4[8];
    Mb_00648258 *owner;      /* 0xBC */
    u8 padC0[0x22];
    s16 fE2;                 /* 0xE2 */
    u8 padE4[0x2C];
    V_00648258 aim;          /* 0x110 */
    f32 range;               /* 0x120 */
    u8 pad124[8];
    s32 f12C;                /* 0x12C */
    Pl_00648258 *f130;       /* 0x130 */
} Self_00648258;
typedef struct {
    u8 pad[0x18];
    Mb_00648258 *target;
} G_00648258;
typedef struct {
    u8 pad[0x424];
    f32 fov;
    u8 pad428[0x38];
} Cam_00648258;
typedef struct {
    u8 pad[0x180];
    s32 f180;
} Gm_00648258;

extern G_00648258 D_L39_0025F740;
extern V_00648258 D_L39_0025F760;
extern Cam_00648258 D_L39_0024DE80[];
extern Mb_00648258 *D_L39_00264D68[];
extern Gm_00648258 *D_001D5F30_sda;

extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern u8 *func_00382348(void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D098(f32);
extern Ob_00648258 *func_L39_0061D7B0(void *);
extern s32 func_L39_006487E8(void *, void *);

void func_L39_00648258(Self_00648258 *self) {
    V_00648258 v;
    Mb_00648258 *list[16];
    V_00648258 pts[16];
    f32 dots[16];
    V_00648258 p;
    V_00648258 d;
    Mb_00648258 *prev;
    s32 mask;
    s32 found;
    s32 i;
    s32 flag;
    s32 n;
    s32 j;
    f32 best;
    f32 cosv;

    prev = self->target;
    mask = self->fE2 == 0 ? 0x10 : (self->fE2 == 1 ? 8 : 0);
    self->target = 0;
    self->fB0 = 0.0f;
    func_0038CF68(&v, self, self->range);
    vec_add_ab(&v, &v, &self->pos);
    found = 0;
    flag = 0;
    for (i = 0; func_003D3CB0(&self->pos, &v, flag, self->owner, 0) && i < 2; i++) {
        Mb_00648258 *t = D_L39_0025F740.target;
        s32 blocked = 0;
        if (t != 0 && (t->f34 & 0x1000)) {
            s32 hit = t->fBE & mask;
            blocked = hit != 0;
            if (!blocked) {
                Ob_00648258 *o = func_L39_0061D7B0(t);
                if (o != 0) {
                    blocked = 1;
                    if (!o->vt->fn(o, self->fE2)
                        && !func_L39_006487E8(D_L39_0025F740.target, o)) {
                        blocked = 0;
                        self->target = D_L39_0025F740.target;
                        self->fB0 = 1.0f;
                    }
                }
            }
        }
        if (blocked && i == 0
            && func_L01_0040E548(&self->pos, &D_L39_0025F760) < 25.0f) {
            flag = 2;
            continue;
        }
        found = 1;
        self->aim = D_L39_0025F760;
        break;
    }
    if (!found) {
        self->aim = v;
    }
    if (self->target == 0 && self->range != 0.0f) {
        Mb_00648258 **mp;
        s32 k;

        cosv = func_0038D098(self->f7C * ((D_L39_0024DE80 + self->f12C)->fov / 1.1100293f));
        n = 0;
        best = 3.7e7f;
        mp = D_L39_00264D68;
        for (k = 0; k < 256; k++, mp++) {
            Mb_00648258 *m = *mp;
            u8 *bb;
            Ob_00648258 *o;
            f32 dist, c, a, score;

            if (m == 0) continue;
            if (m->f98 == 0) continue;
            if (m == self->owner) continue;
            if (D_001D5F30_sda->f180 != 2 && (m->fBE & mask)) continue;
            if (m->f31 == 0) continue;
            bb = func_00382348(m);
            if (bb == 0) continue;
            *(vu0_q *)&d = 0;
            d.z = *(f32 *)(bb + 0x10);
            p = d;
            func_0038D000(&p, &p, m->mtx);
            vec_add_ab(&p, &p, &m->pos);
            vec_sub_ab(&d, &p, &self->pos);
            dist = func_0038CEA8(&d);
            if (self->range < dist) continue;
            func_0038CE20(&d, &d, 1.0f / dist);
            c = func_0038CE68(&d, self);
            if (c < cosv) continue;
            a = (c - cosv) / (1.0f - cosv);
            score = dist + (dist + dist) * (1.0f - a);
            o = func_L39_0061D7B0(m);
            if (o != 0 && self->f130 != 0 && o->vt->fn(o, self->f130->f2548)) continue;
            if (!(score < best)) continue;
            if (o != 0 && func_L39_006487E8(m, o)) continue;
            best = score;
            list[n] = m;
            *(pts + n) = p;
            dots[n] = a;
            n++;
            if (n >= 16) break;
        }
        for (j = n - 1; j >= 0; j--) {
            if (!func_003D3CB0(&self->pos, &pts[j], 0, self->owner, 0)
                || D_L39_0025F740.target == list[j]
                || (list[j]->fAA == 0x109F && D_L39_0025F740.target != 0
                    && D_L39_0025F740.target->fAA == 0x109E)) {
                self->target = list[j];
                self->fB0 = dots[j];
                break;
            }
        }
    }
    if (self->target != 0) {
        if (self->target == prev) {
            vec_sub_ab(&self->vel, &self->target->pos, &self->last);
            if (func_0038CEA8(&self->vel) > 0.2f) {
                func_0038CF68(&self->vel, &self->vel, 0.2f);
            }
        }
        self->last = self->target->pos;
    } else {
        qzero(&self->vel);
    }
}
/* localdecomp:end func_L39_00648258 */

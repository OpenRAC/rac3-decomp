#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_004501E8 */
typedef struct {
    u8 pad0[0x20];
    u8 type;
    u8 pad21[0x24 - 0x21];
    u8 *cls;
    u8 pad28[0x31 - 0x28];
    u8 b31;
    u8 pad32[0x34 - 0x32];
    u16 flags;
    u8 pad36[0xAA - 0x36];
    s16 id;
} M_4501E8;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4501E8;
typedef struct Node_4501E8 {
    M_4501E8 *m;
    f32 score;
    struct Node_4501E8 *next;
    struct Node_4501E8 **link;
    V4_4501E8 pos;
} Node_4501E8;

extern M_4501E8 *D_L01_0021E860[];
extern f32 *func_00382348(M_4501E8 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern s32 func_003C4B50(void *);
extern void func_L01_00439880(void *, s32 *, s32 *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
extern void func_003C5180(void *, void *, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern Node_4501E8 D_L01_00220420[];
extern s16 D_001A4F48[];
extern s32 D_L01_001D673C;

M_4501E8 *func_L01_004501E8(V4_4501E8 *pos, f32 *dir, f32 fA, f32 fB, f32 fC, f32 fD, f32 fE, s32 *count, M_4501E8 **out, s32 max, M_4501E8 **ign_a,
                            s32 flag, s32 *ign_b, s16 s0, s16 s1, s16 s2)
{
    V4_4501E8 v00, v10, d, v30, v40, v50, v60, v70, v80;
    s32 raw90, raw94;
    Node_4501E8 *head[1];
    Node_4501E8 *tail;
    Node_4501E8 *n;
    Node_4501E8 *p;
    M_4501E8 *m;
    M_4501E8 *best;
    M_4501E8 *first;
    f32 bestscore;
    f32 yawA, pitchB;
    f32 dist, score, thr, ratio;
    f32 f20, f21, f22, f23, zero, dot;
    f32 *sc;
    s32 pool;
    s32 i, k, j, l, isenemy, cone, special;

    tail = 0;
    bestscore = 999999.0f;
    best = 0;
    pool = 0;
    *count = 0;
    head[0] = 0;
    if (s1 == -1) {
        s1 = D_001A4F48[0];
    }
    if (fA == 0.0f) return 0;
    if (fB == 0.0f) return 0;
    if (fC == 0.0f) return 0;

    yawA = func_0038D160(dir[0], dir[1]);
    pitchB = func_0038D160(func_0038CED8(dir), dir[2]);

    for (i = 0; (m = D_L01_0021E860[i]) != 0; i++) {
        if (s0 != 0 && m->b31 == 0) continue;
        special = 0;
        if (m->id == 0x1A90 || m->id == 0x1ADE) special = 1;
        cone = 0;
        isenemy = func_003C4B50(m);
        if (m != 0 && m->cls != 0 && m->cls[0x46] == 0x16 && (m->flags & 0x4000) && m->b31 != 0) {
            func_L01_00439880(m, &raw90, &raw94);
            if (raw94 > 0) {
                special = 1;
                cone = 1;
            }
        }
        if (isenemy != 0 && flag == 0) continue;
        if (cone != 0 && s2 == 0) continue;
        sc = func_00382348(m);
        if ((sc == 0 || (sc[0] <= 0.0f && isenemy == 0)) && cone == 0) continue;
        if (!((m != 0 && m->cls != 0 && m->cls[0x46] == 5) || isenemy != 0 || cone != 0)) continue;

        if (ign_a != 0) {
            for (k = 0; ign_a[k] != 0; k++) {
                if (m == ign_a[k]) break;
            }
            if (ign_a[k] != 0) continue;
        }
        if (ign_b != 0) {
            s32 jj;
            for (jj = 0; ign_b[jj] != -1; jj++) {
                if (m->id == ign_b[jj]) break;
            }
            if (ign_b[jj] != -1) continue;
        }

        v10 = *(V4_4501E8 *)((u8 *)m + 0x10);
        if (sc != 0) {
            if (D_L01_001D673C != 0 || s1 != 0) {
                func_0038CE20(&v00, (u8 *)m + 0xE0, sc[4]);
                vec_add_ab(&v10, &v10, &v00);
            } else {
                v10.z = v10.z + sc[4];
            }
        } else {
            if (D_L01_001D673C != 0 || s1 != 0) {
                func_0038CE20(&v00, (u8 *)m + 0xE0, *(f32 *)((u8 *)m + 0xC) * 0.0009765625f);
                vec_add_ab(&v10, &v10, &v00);
            } else {
                v10.z = v10.z + *(f32 *)((u8 *)m + 0xC) * 0.0009765625f;
            }
        }
        vec_sub_ab(&d, &v10, pos);
        dist = func_0038CEA8(&d);
        if (fC < dist) continue;
        if (dist < 0.1f) continue;
        zero = 0.0f;
        ratio = func_L01_004451D0(-2.0f, zero, 1.0f, zero, dist / fC);
        f23 = zero;
        f22 = f23;
        if (fA < 3.1415927f || fB < 3.1415927f) {
            if (D_L01_001D673C == 0) {
                f22 = func_0038DBA0(func_0038D160(d.x, d.y), yawA);
                thr = fA;
                if (zero < fE) thr = fE + (thr - fE) * ratio;
                if (thr <= f22) continue;
                f23 = func_0038DBA0(func_0038D160(func_0038CED8(&d), d.z), pitchB);
                thr = fB;
                if (zero < fD) thr = fD + (thr - fD) * ratio;
                if (thr <= f23) continue;
            } else {
                func_003C5180(pos, &v30, 1);
                dot = func_0038CE68(&v30, &d);
                func_0038CE20(&v40, &v30, dot);
                vec_sub_ab(&v50, &d, &v40);
                dot = func_0038CE68(&v30, dir);
                func_0038CE20(&v60, &v30, dot);
                vec_sub_ba(&v70, dir, &v60);
                {
                    f32 dot2 = func_0038CE68(&v70, &v50);
                    if (dot2 < 0.0f) continue;
                    f21 = func_0038CEA8(&v50);
                    if (f21 == 0.0f) continue;
                    f20 = func_0038CEA8(&v70);
                    if (f20 == 0.0f) continue;
                    f22 = 1.5707964f - func_0038D0C8(dot2 / (f21 * f20));
                }
                thr = fA;
                if (zero < fE) thr = fE + (thr - fE) * ratio;
                if (thr <= f22) continue;
                func_0038CE20(&v80, &v50, f20 / f21);
                vec_add_ab(&v80, &v80, &v60);
                {
                    f32 len2 = func_0038CEA8(&v80);
                    f23 = 1.5707964f - func_0038D0C8(func_0038CE68(&v80, &d) / (len2 * dist));
                }
                thr = fB;
                if (zero < fD) thr = fD + (thr - fD) * ratio;
                if (thr <= f23) continue;
            }
        }
        score = f22 * 3.0f + f23 * 0.2f * dist + dist * 0.1f;
        if (isenemy != 0 || special != 0) {
            score = score * (fC * 0.8f);
        }
        if (pool < 0x20) {
            n = &D_L01_00220420[pool];
            pool++;
        } else {
            n = tail;
            *n->link = 0;
        }
        n->pos = v10;
        n->m = m;
        n->score = score;
        if (head[0] != 0) {
            p = head[0];
            while (p != 0) {
                if (n->score < p->score) break;
                p = p->next;
            }
            n->next = p;
            if (p != 0) {
                n->link = p->link;
                *p->link = n;
                p->link = &n->next;
            } else {
                tail->next = n;
                n->link = &tail->next;
                tail = n;
            }
        } else {
            tail = n;
            head[0] = n;
            n->link = head;
            n->next = 0;
        }
    }

    while (head[0] != 0) {
        m = head[0]->m;
        if (head[0]->score < bestscore) {
            if (func_003D3CB0(pos, &head[0]->pos, 0x12, m, 0) != 0) {
                head[0] = head[0]->next;
                continue;
            }
            best = m;
            bestscore = head[0]->score;
        }
        if (out != 0 && *count < max) {
            out[(*count)++] = m;
        }
        head[0] = head[0]->next;
    }

    if (out == 0) return best;
    if (best != 0) {
        for (j = 0; j < max; j++) {
            if (out[j] == best) {
                if (j != 0) {
                    first = out[0];
                    out[0] = best;
                    out[j] = first;
                }
                break;
            }
        }
        if (j == max) {
            out[0] = best;
        }
    }
    if (*count < max) {
        out[*count] = 0;
    }
    return best;
}
/* localdecomp:end func_L01_004501E8 */

#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_004453B8 */
extern f32 func_0038DB00(f32 a, f32 b);
extern f32 func_0038D098(f32 a);
extern f32 func_0038DAB8(f32 a, f32 b);

f32 func_L01_004453B8(f32 a, f32 b, f32 t) {
    f32 r = func_0038DB00(b, a);
    f32 c = func_0038D098(t * 3.1415927f);
    return func_0038DAB8(a, r * ((1.0f - c) * 0.5f));
}
/* localdecomp:end func_L01_004453B8 */

/* localdecomp:start func_L01_00445438 */
extern f32 func_0038D098(f32 a);
extern void func_0038CE20(void *, void *, f32);
void func_L01_00445438(vu0_v4 *out, vu0_v4 *a, vu0_v4 *b, f32 t) {
    vu0_v4 delta;
    f32 h;
    if (t == 0.0f) *out = *a;
    else if (t == 1.0f) *out = *b;
    else {
        h = (1.0f - func_0038D098(t * 3.1415927f)) * 0.5f;
        vec_sub_ab(&delta, b, a);
        func_0038CE20(&delta, &delta, h);
        vec_add_ab(out, a, &delta);
    }
}
/* localdecomp:end func_L01_00445438 */

/* localdecomp:start func_L01_00445510 */
extern f32 func_0038D098(f32 a);
extern f32 func_0038DB00(f32 a, f32 b);
extern f32 func_0038DAB8(f32 a, f32 b);
void func_L01_00445510(f32 *out, f32 *a, f32 *b, f32 t) {
    f32 h = (1.0f - func_0038D098(t * 3.1415927f)) * 0.5f;
    out[0] = func_0038DAB8(a[0], func_0038DB00(b[0], a[0]) * h);
    out[1] = func_0038DAB8(a[1], func_0038DB00(b[1], a[1]) * h);
    out[2] = func_0038DAB8(a[2], func_0038DB00(b[2], a[2]) * h);
}
/* localdecomp:end func_L01_00445510 */

LINKER_REMNANT("asm/levels", func_L01_004455D0);

/* localdecomp:start func_L01_004455E8 */
typedef struct { u8 pad[0xF8]; f32 angle; } S_004455E8;
void func_L01_004455E8(S_004455E8 *m, f32 *v, f32 target, f32 accel, f32 damp, f32 limit) {
    extern f32 func_0038DB00(f32 a, f32 b);
    extern f32 func_0038DAB8(f32 a, f32 b);
    f32 d = func_0038DB00(target, m->angle);
    f32 t = d / 0.15707964f;
    f32 a;
    if (t > 1.0f) t = 1.0f;
    else if (t < -1.0f) t = -1.0f;
    *v += accel * t - damp * *v;
    if (limit != 0.0f) {
        if (*v > limit) *v = limit;
        else if (*v < -limit) *v = -limit;
    }
    a = fabs_asm(d);
    if (*v > a) *v = a;
    else if (*v < -a) *v = -a;
    m->angle = func_0038DAB8(m->angle, *v);
}
/* localdecomp:end func_L01_004455E8 */

LINKER_REMNANT("asm/levels", func_L01_00445720);

/* localdecomp:start func_L01_00445728 */
typedef struct {
    u8 pad0[0x18]; s32 f18; s32 f1C;
    vu0_v4 point; vu0_v4 adjusted; vu0_v4 normal;
} Collision_00445728;
extern Collision_00445728 D_L01_001EAA00[];
extern vu0_v4 D_L01_001EAA20[];
s32 func_L01_00445728(void *obj, vu0_v4 *old, vu0_v4 *pos, s32 flags,
                     f32 height, f32 radius, f32 limit, f32 slope) {
    extern f32 func_L01_004463D0(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0012FE98(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_L01_003FB640(void *, f32, s32, void *);
    extern f32 func_0038CF38(void *, void *);
    vu0_v4 delta, scaled, start, end, offset, test;
    f32 h, angle, dot, distance;
    s32 i;
    s32 ok = 1;
    s32 collision_flags;
    collision_flags = flags & 2;
    pos->z += height;
    h = func_L01_004463D0(pos);
    pos->z -= height;
    if (limit < fabs_asm(h - old->z)) {
        if ((((flags ^ 1) & 1) && h < old->z) || old->z < h) {
            *(vu0_q *)pos = *(vu0_q *)old;
            ok = 0;
        }
    }
    vec_sub_ba(&delta, pos, old);
    func_0038CF68(&scaled, &delta, radius * 1.2f);
    *(vu0_q *)&offset = 0;
    offset.z = height;
    vec_add_ab(&start, old, &offset);
    vec_add_ab(&end, &start, &scaled);
    if (ok && func_003D3CB0(&start, &end, collision_flags | 0x24, obj, 0)) {
        Collision_00445728 *hit;
        hit = D_L01_001EAA00;
        if (hit->f1C > 0) {
            distance = func_0038CED8(&hit->normal);
            angle = func_0038D160(hit->normal.z, distance);
            if (slope <= angle) {
                hit->normal.z = 0;
                func_0012FE98(&hit->normal, &hit->normal);
                dot = -delta.x * hit->normal.x - delta.y * hit->normal.y;
                if (0.0f < dot) {
                    ok = 0;
                    func_0038CE20(&hit->normal, &hit->normal, dot);
                    vec_add_ba(&delta, &delta, &hit->normal);
                }
            }
            vec_add_ab(pos, old, &delta);
        }
    }
    if ((flags & 2) == 0) {
        f32 reach = height + radius;
        Collision_00445728 *hit;
        i = 0;
        do {
            *(vu0_q *)&test = *(vu0_q *)pos;
            test.z += reach;
            if (!func_L01_003FB640(&test, radius, 0x24, obj)) break;
            distance = func_0038CF38(pos, D_L01_001EAA20);
            hit = (Collision_00445728 *)((u8 *)D_L01_001EAA20 - 0x20);
            angle = func_0038D160(distance, hit->point.z - pos->z);
            if (hit->f18 != 0) goto push;
            if (slope < angle) {
            push:
                *(vu0_q *)pos = *(vu0_q *)&hit->adjusted;
                ok = 0;
                pos->z -= reach;
            }
            i++;
        } while (i < 6);
    }
    pos->z += height;
    h = func_L01_004463D0(pos);
    pos->z -= height;
    if (limit < fabs_asm(h - old->z)) {
        if ((((flags ^ 1) & 1) && h < old->z) || old->z < h) {
            *(vu0_q *)pos = *(vu0_q *)old;
            ok = 0;
        }
    }
    old->x = pos->x;
    old->y = pos->y;
    return ok;
}
/* localdecomp:end func_L01_00445728 */

LINKER_REMNANT("asm/levels", func_L01_00445AA8);

/* localdecomp:start func_L01_00445AD0 */
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern f32 *func_L01_00443828(u8 *moby);

/* moby_group_count: counts a moby group's members (lists at 0x21DE20, the last entry's top bit
 * set) whose state (+0x20) is not negative and not state (-1 for any), only those with health
 * left (or no damage record) if alive is set; 0 for group -1 or 0xFF. */
s32 func_L01_00445AD0(s32 group, s32 state, s32 alive) {
    s16 *list;
    s16 *entry;
    s32 count;

    if (group == -1 || group == 0xFF) return 0;
    list = D_L01_0021DE20[group];
    count = 0;
    if (list == 0) return 0;
    entry = list;
    do {
        u8 *moby = (u8 *)(((*(u16 *)entry & 0x7FFF) << 8) + (s32)D_L01_001E001C);
        if ((s8)moby[0x20] >= 0 && (state == -1 || moby[0x20] != state)) {
            if (alive) {
                f32 *health = func_L01_00443828(moby);
                if (health == 0 || 0.0f < *health) count++;
            } else {
                count++;
            }
        }
    } while (*entry++ >= 0);
    return count;
}
/* localdecomp:end func_L01_00445AD0 */

/* localdecomp:start func_L01_00445BE0 */
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;

void func_L01_00445BE0(s32 group, s32 value) {
    s16 *list = D_L01_0021DE20[group];
    s16 *entry;

    if (list != 0) {
        entry = list;
        do {
            u8 *moby = (u8 *)(((*(u16 *)entry & 0x7FFF) << 8) + (s32)D_L01_001E001C);
            moby[0xBC] = value;
        } while (*entry++ >= 0);
    }
}
/* localdecomp:end func_L01_00445BE0 */

LINKER_REMNANT("asm/levels", func_L01_00445C38);

/* localdecomp:start func_L01_00445C48 */
extern u8 *D_L01_001E0214;
extern s32 D_L01_001E0058;
extern s16 *D_L01_001E020C;
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern u16 D_L01_001E0210;
extern s32 func_L01_00445D30(u8 **out, u8 *start, s32 a2, s32 a3);

s32 func_L01_00445C48(u8 **out, s32 group, s32 a2, s32 a3) {
    s16 *entry;
    s32 index;
    s32 neg;

    if (group < 0 || D_L01_001E0058 < group) {
        *out = 0;
        return -1;
    }
    *out = 0;
    D_L01_001E0214 = 0;
    entry = D_L01_0021DE20[group];
    D_L01_001E020C = entry;
    if (entry == 0) {
        return -1;
    }
    index = *(u16 *)entry & 0x7FFF;
    D_L01_001E0210 = index;
    D_L01_001E0214 = D_L01_001E001C + (index << 8);
    *out = D_L01_001E0214;
    neg = (s8)D_L01_001E0214[32] < 0;
    if (!a2) {
        if (!a3 && !neg) goto found;
    } else if (!a3 || neg) {
        goto found;
    }
    return func_L01_00445D30(out, D_L01_001E0214, a2, a3);
found:
    return 0;
}
/* localdecomp:end func_L01_00445C48 */

/* localdecomp:start func_L01_00445D30 */
extern u8 *D_L01_001E0214;
extern s32 D_L01_001E0058;
extern s16 *D_L01_001E020C;
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern u16 D_L01_001E0210;
s32 func_L01_00445D30(u8 **out, u8 *start, s32 a2, s32 a3) {
    s16 *p;
    s32 neg;
    s32 idx;
    *out = 0;
    if (start != D_L01_001E0214) {
        if (D_L01_001E0058 < start[33]) {
            goto fail;
        }
        D_L01_001E0214 = 0;
        D_L01_001E020C = D_L01_0021DE20[start[33]];
        if (D_L01_001E020C == 0) {
        fail:
            return -1;
        }
        D_L01_001E020C = D_L01_001E020C - 1;
        do {
            p = D_L01_001E020C;
            D_L01_001E020C = p + 1;
            idx = p[1] & 0x7FFF;
            D_L01_001E0210 = idx;
            D_L01_001E0214 = D_L01_001E001C + (idx << 8);
            if (p[1] < 0) {
                goto fail;
            }
        } while (start != D_L01_001E0214);
    } else if (*D_L01_001E020C < 0) {
        goto fail;
    }
    do {
        p = D_L01_001E020C;
        D_L01_001E020C = p + 1;
        idx = p[1] & 0x7FFF;
        D_L01_001E0210 = idx;
        D_L01_001E0214 = D_L01_001E001C + (idx << 8);
        *out = D_L01_001E0214;
        neg = (s8)D_L01_001E0214[32] < 0;
        if (!a2) {
            if (a3) {
                continue;
            }
            if (!neg) {
                goto ret0;
            }
        } else if (!a3 || neg) {
        ret0:
            return 0;
        }
    } while (*D_L01_001E020C >= 0);
    *out = 0;
    return -1;
}
/* localdecomp:end func_L01_00445D30 */

LINKER_REMNANT("asm/levels", func_L01_00445E98);

/* localdecomp:start func_L01_00445EA8 */
s32 func_L01_00445EA8(s32 *a0, s32 a1) {
    s32 v = *a0;
    s32 n = (v >> 24) - a1;
    if (n < 0) {
        n = 0;
    }
    *a0 = (v & 0xFFFFFF) | (n << 24);
    return n == 0;
}
/* localdecomp:end func_L01_00445EA8 */

/* localdecomp:start func_L01_00445EE0 */
f32 func_L01_00445EE0(f32 *a0, f32 *a1, s32 *a2, f32 factor) {
    f32 b = a1[2];
    f32 a = a0[2];
    s32 n = (s32)(b / factor);
    f32 r = a + b * (f32)n - (f32)((n * n + n) >> 1) * factor;
    if (a2 != 0) {
        *a2 = n;
    }
    return r;
}
/* localdecomp:end func_L01_00445EE0 */

/* localdecomp:start func_L01_00445F40 */
extern u8 D_L01_001FDBD0[];
extern u8 *D_L01_001FD180[];
extern void func_003C29B0(u8 *);
extern void func_003C7C38(u8 *);
s32 func_L01_00445F40(u8 *m, s32 a1) {
    u8 *p;
    u8 *q;

    if (*(s16 *)(m + 170) == a1) {
        return 0;
    }
    *(s16 *)(m + 170) = a1;
    m[34] = D_L01_001FDBD0[(s16)a1];

    *(u8 **)(m + 36) = D_L01_001FD180[m[34]];
    func_003C29B0(m);
    p = *(u8 **)(m + 36);
    m[98] = p[14];
    *(f32 *)(m + 44) = *(f32 *)(p + 36);
    if (*(s32 *)(m + 152) != 0) {
        *(s32 *)(m + 152) = *(s32 *)(p + 16);
    }
    m[97] = 255;
    q = *(u8 **)(m + 36);
    if (q != 0) {
        if (*(s32 *)(q + 64) != 0) {
            *(u16 *)(m + 52) |= 0x10;
            *(s32 *)(m + 120) = *(s32 *)(q + 64);
        }
        if ((*(u8 **)(m + 36))[15] != 0) {
            m[111] = 24;
            *(u16 *)(m + 52) |= 0x400;
            *(s32 *)(m + 112) = 0;
            *(s32 *)(m + 116) = 0;
            m[189] = 0;
        }
        if ((*(u8 **)(m + 36))[6] != 0) {
            m[99] = 24;
        }
    }
    func_003C7C38(m);
    return 1;
}
/* localdecomp:end func_L01_00445F40 */

/* localdecomp:start func_L01_00446058 */
extern void func_003C7C38(u8 *);
extern void func_003C29B0(u8 *);
extern u8 *D_L01_001FD180[];
typedef struct { u8 p0[0x6]; u8 b6; u8 p7[7]; u8 bE; u8 bF; s32 w10; u8 p14[0x2C]; s32 w40; } S_442F20;
typedef struct {
    u8 p0[0x22]; u8 b22; u8 p23; S_442F20 *w24; u8 p28[0xC]; u16 h34; u8 p36[0x2B]; u8 b61; u8 b62; u8 b63;
    u8 p64[0xB]; u8 b6F; u8 p70[4]; s32 w74; s32 w78; u16 h7C; u8 p7E[0x1A]; s32 w98; u8 p9C[0xE]; s16 hAA;
} P_442F20;
extern u8 D_L01_001FDBD0[];
extern void func_L01_00443EA0(s32, s32);
extern void func_L01_00439880(P_442F20 *, u16 *, s32 *);

s32 func_L01_00446058(P_442F20 *p, s32 b, s32 c) {
    struct { u16 h; u16 pad; s32 w; } tmp;
    if (p->hAA == b) {
        return 0;
    }
    p->hAA = b;
    p->b22 = D_L01_001FDBD0[(s16)b];
    p->w24 = ((S_442F20 * *)&D_L01_001FD180)[p->b22];
    p->b61 = 0xFF;
    func_L01_00443EA0(b, c);
    ((void (*)(P_442F20 *))func_003C29B0)(p);
    p->b62 = p->w24->bE;
    if (p->w98 != 0) {
        p->w98 = p->w24->w10;
    }
    if (p->w24 != 0) {
        if (p->w24->w40 != 0) {
            p->h34 |= 0x10;
            p->w78 = p->w24->w40;
        } else {
            p->w78 = 0;
            p->h34 &= ~0x10;
        }
        if (p->w24->bF != 0) {
            p->b6F = 0x18;
            p->h34 |= 0x400;
        } else {
            p->b6F = 0;
            p->h34 &= ~0x400;
            p->w74 = 0;
        }
        if (p->w24->b6 != 0) {
            p->b63 = 0x18;
        } else {
            p->b63 = 0;
        }
        if (p->h7C != 0) {
            func_L01_00439880(p, &tmp.h, &tmp.w);
            p->h7C = tmp.h;
        }
    }
    ((void (*)(P_442F20 *))func_003C7C38)(p);
    return 1;
}
/* localdecomp:end func_L01_00446058 */

LINKER_REMNANT("asm/levels", func_L01_004461B0);

/* localdecomp:start func_L01_004461B8 */
s32 func_L01_004461B8(f32 *a0, f32 *a1, f32 a, f32 b, f32 c) {
    f32 d = b * b - a * 4.0f * c;
    f32 s;
    f32 x1;
    f32 x2;
    f32 t;
    if (d == 0.0f) {
        *a0 = -b / (a + a);
        return 1;
    }
    s = sqrt_asm(fabs_asm(d));
    x1 = (-b + s) / (a + a);
    x2 = (-b - s) / (a + a);
    *a0 = x1;
    *a1 = x2;
    t = *a0;
    if (t < x2) {
        *a1 = t;
        *a0 = x2;
    }
    return d > 0.0f ? 2 : 0;
}
/* localdecomp:end func_L01_004461B8 */

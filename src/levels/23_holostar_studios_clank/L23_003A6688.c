#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct { s32 id; f32 x4; f32 x8; s32 xC[2]; } Rec14;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    f32 m[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    V4 axis;
    V4 r[4];
} S_3A9D00;
typedef struct {
    u8 pad0[0x140];
    f32 x140;
    f32 x144;
} S_1E1880;
typedef struct {
    s32 a;
    s32 b;
} Vars_3A77F0;
typedef struct {
    f32 pos[4][4];
    u32 rgba[4];
    f32 uv[4][2];
    unsigned long count;
    unsigned long tex;
    unsigned long tex0;
    unsigned long alpha;
} Quad_3B5628;
typedef struct {
    s32 id;
    s32 x4;
    f32 x8;
    f32 xC;
    u8 pad10[4];
    s32 x14;
    s32 x18;
    s32 x1C;
    s32 x20;
    f32 x24;
    f32 x28;
    u8 pad2C[4];
    u128_t x30;
    u128_t x40;
    u8 x50[0x10];
} Vars_3A97B8;
typedef struct {
    u8 pad0[0x10];
    V4 pos;
    u8 x20;
    u8 x21;
    u8 pad22[0xA];
    f32 scale;
    u8 pad30[4];
    u16 x34;
    u8 pad36[0x32];
    Vars_3A97B8 *vars;
    u8 pad6C[0x54];
    V4 xC0;
    V4 xD0;
    V4 xE0;
} Moby_3A97B8;
typedef struct {
    V4 a;
    V4 b;
    V4 c;
    V4 pos;
} Fx_3A7048;
typedef struct {
    u8 pad0[0xC];
    f32 xC;
    u8 pad10[6];
    u8 x16;
    u8 pad17[3];
    u8 x1A;
} Ent_3A7048;

INCLUDE_ASM("asm/levels", func_L23_003A6688);

/* localdecomp:start func_L23_003A6838 */
#include "vu0.h"
typedef struct {
    s32 count;
    u8 pad4[0xC];
    V4 pts[1];
} Path_3A6838;
extern void *D_L23_0021D380[];
__asm__(".extern D_L23_001DE0C0, 4");
extern s32 D_L23_001DE0C0;
extern f32 func_0038CEA8(void *);
extern void func_003C4098(void *, void *, void *, f32);

void func_L23_003A6838(void *out, s32 idx, f32 dist, f32 *lens, s32 n) {
    Path_3A6838 *path;
    V4 a;
    V4 b;
    V4 d;
    f32 len;
    s32 i;

    path = D_L23_0021D380[idx];
    a = path->pts[0];
    if (D_L23_001DE0C0 < path->count) {
        D_L23_001DE0C0 = path->count;
    }
    for (i = 1; i < path->count; i++) {
        b = path->pts[i];
        if (lens == 0 || n < i) {
            vec_sub_ab(&d, &b, &a);
            len = func_0038CEA8(&d);
        } else {
            len = lens[i - 1];
        }
        if (dist < len) {
            func_003C4098(out, &a, &b, dist / len);
            return;
        }
        dist -= len;
        a = b;
    }
}
/* localdecomp:end func_L23_003A6838 */

/* localdecomp:start func_L23_003A6970 */
#include "vu0.h"
typedef struct {
    s32 count;
    u8 p4[0xC];
    vu0_v4 points[1];
} Path_003A6970;


extern void *D_L23_0021D380[];
extern f32 func_0038CEA8(void *);

f32 func_L23_003A6970(s32 index, f32 *lengths, s32 max) {
    Path_003A6970 *path = D_L23_0021D380[index];
    vu0_v4 prev;
    vu0_v4 cur;
    vu0_v4 d;
    f32 total = 0.0f;
    f32 len;
    s32 i;

    prev = path->points[0];
    for (i = 1; i < path->count; i++) {
        cur = path->points[i];
        vec_sub_ab(&d, &cur, &prev);
        len = func_0038CEA8(&d);
        total += len;
        if (lengths != 0 && i <= max) {
            lengths[i - 1] = len;
        }
        prev = cur;
    }
    return total;
}
/* localdecomp:end func_L23_003A6970 */

/* localdecomp:start func_L23_003A6A60 */
/* 4 diff */
#include "vu0.h"


extern s32 D_L23_001DE0C8[2];
__asm__(".extern D_L23_001DE0C8, 8");
extern f32 D_L23_001DE0C4;
__asm__(".extern D_L23_001DE0C4, 4");
extern void func_0038D570(void *, void *);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, void *, s32);

void func_L23_003A6A60(u8 *obj)
{
    f32 m[4][4] __attribute__((aligned(16)));
    Quad_3B5628 q __attribute__((aligned(16)));
    f32 s;

    func_0038D570(m, obj + 0xC0);
    *(u128_t *)m[3] = *(u128_t *)(obj + 0x10);
    m[3][3] = 1.0f;
    m[3][2] += 0.02f;
    q.tex = func_00389598(D_L23_001DE0C8[((s32)obj >> 8) % 2]);
    s = D_L23_001DE0C4;
    qzero(q.pos[0]);
    qzero(q.pos[1]);
    qzero(q.pos[2]);
    qzero(q.pos[3]);
    q.uv[1][1] = 1.0f;
    q.tex0 = 0xFF9000000379;
    q.uv[0][0] = 0.0f;
    q.uv[2][0] = 1.0f;
    q.uv[0][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.count = 5;
    q.uv[3][1] = 1.0f;
    q.alpha = 0x8000000044;
    q.uv[1][0] = 0.0f;
    q.uv[2][1] = 0.0f;
    q.rgba[3] = 0x50000000;
    q.rgba[2] = 0x50000000;
    q.pos[0][3] = 1.0f;
    q.pos[1][3] = 1.0f;
    q.rgba[1] = 0x50000000;
    q.rgba[0] = 0x50000000;
    q.pos[2][3] = 1.0f;
    q.pos[0][0] = -s;
    q.pos[2][1] = -s;
    q.pos[1][1] = s;
    q.pos[3][3] = 1.0f;
    q.pos[3][0] = s;
    func_003D2DA0(&q, m[0], 0);
}
/* localdecomp:end func_L23_003A6A60 */

/* localdecomp:start func_L23_003A6B98 */
extern u8 D_L23_001FDA19[];
extern u8 *D_L23_001FB440[];
extern s32 D_L23_001DE0D0;
__asm__(".extern D_L23_001DE0D0, 4");
extern s32 func_003A4FF8(u8 *, s32, s32, void *, s32);
extern void func_L01_004AB048(s32, s32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L23_003A6B98(u8 *self, f32 scale)
{
    s32 r;

    r = func_003A4FF8(*(u8 **)(D_L23_001FB440[D_L23_001FDA19[0]] + 0x28), 0, 0, self, 0x400);
    if (r >= 0 && scale > 1.5f)
        func_L01_004AB048(r, D_L23_001DE0D0);
    func_L01_003303B8(self, scale > 1.5f, 4, 10, 2, 10, 20, 4, scale, 0.0f, 0.0f, 0.0f,
                      0, 1, scale > 2.0f, 0, 1, 0, 0, 0, 0x388EF7, 0x63F7, 0x70000000, 0x700020FF, 0x8FAF,
                      0x70303280, 0x7F004020, 0x280000FF, 0x3064FF, 0);
}
/* localdecomp:end func_L23_003A6B98 */

/* localdecomp:start func_L23_003A6D18 */
extern s32 D_L23_001DE0D8;
__asm__(".extern D_L23_001DE0D8, 4");
extern s32 D_L23_001DEC40;

void func_L23_003A6D18(u8 *self)
{
    *(f32 *)(self + 0xF4) = (f32)(D_L23_001DEC40 % D_L23_001DE0D8) * 6.2831855f / (f32)D_L23_001DE0D8 + -3.1415927f;
}
/* localdecomp:end func_L23_003A6D18 */

/* localdecomp:start func_L23_003A6D70 */
extern f32 D_L23_001DE0DC;
extern f32 D_L23_001DE0E0;
__asm__(".extern D_L23_001DE0DC, 4");
__asm__(".extern D_L23_001DE0E0, 4");
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(u8 *);
extern void func_003A52A0(s32, s32, void *);
extern f32 func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L23_003A6D70(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        if (func_L01_00456250(m) != 0) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            func_003A52A0(0, 0, m);
            *(s32 *)v = 0;
        }
        if (func_L01_00448890(m + 0xF8, v, 1.3962634f, D_L23_001DE0DC, D_L23_001DE0DC, D_L23_001DE0E0, 0) <= 0.0f) {
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        *(u16 *)(m + 0x34) |= 2;
        break;
    }
}
/* localdecomp:end func_L23_003A6D70 */

/* localdecomp:start func_L23_003A6E68 */
extern f32 D_L23_001DE0E4;
extern f32 D_L23_001DE0E8;
__asm__(".extern D_L23_001DE0E4, 4");
__asm__(".extern D_L23_001DE0E8, 4");
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L23_003A6E68(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        if (func_L01_00456250(m) != 0) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)v = 0;
        }
        if (func_L01_00448890(m + 0xF8, v, -1.3962634f, D_L23_001DE0E4, D_L23_001DE0E4, D_L23_001DE0E8, 0) >= 0.0f) {
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        *(u16 *)(m + 0x34) |= 2;
        break;
    }
}
/* localdecomp:end func_L23_003A6E68 */

/* localdecomp:start func_L23_003A6F50 */
__asm__(".extern D_L23_001DE0EC, 4");
__asm__(".extern D_L23_001DE0F0, 4");
extern f32 D_L23_001DE0EC;
extern f32 D_L23_001DE0F0;
extern s32 func_L01_00456250(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);

void func_L23_003A6F50(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);

    if (self[0x20] == 0) {
        *(s32 *)s = 0;
        func_L01_004450F0(self, 1, -1);
    } else if (self[0x20] == 1) {
        *(f32 *)(self + 0xF4) = 1.5707964f;
        if (func_L01_00456250(self)) {
            func_003A52A0(0, 0, self);
            func_L01_004450F0(self, 2, -1);
        }
    } else if (self[0x20] == 3) {
        *(f32 *)(self + 0xF4) = 0.0f;
        *(u16 *)(self + 0x34) |= 2;
    } else if (self[0x20] == 2) {
        func_L01_00448890(self + 0xF4, s, 0.0f, D_L23_001DE0EC, D_L23_001DE0EC, D_L23_001DE0F0, 0);
        if (*(f32 *)(self + 0xF4) == 0.0f)
            func_L01_004450F0(self, 3, -1);
    }
}
/* localdecomp:end func_L23_003A6F50 */

/* localdecomp:start func_L23_003A7048 */
#include "vu0.h"
#include "structs/hero.h"
extern u16 **D_L23_001D676C;
__asm__(".extern D_L23_001D676C, 16");
extern u8 *D_L23_001DFF08;
__asm__(".extern D_L23_001DFF08, 16");
extern u8 *D_L23_001DFF10;
__asm__(".extern D_L23_001DFF10, 16");
extern u8 *D_L23_001DE2D0;
extern s32 D_L23_001DEC40;
extern struct Hero D_001A4BE0;
extern void func_L23_003A7A90(u8 *);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_004AADE8(s32, s32, void *, s32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_00404808(void (*)(u8 *), u8 *);
extern void func_L23_003A6B98(u8 *, f32);
extern void func_L23_003A77F0(u8 *);
extern u8 *func_L23_003A7908(u8 *, u8 *, vu0_q *);

void func_L23_003A7048(u8 *self)
{
    s32 *v = *(s32 **)(self + 0x68);
    Ent_3A7048 *e;
    Fx_3A7048 *m;
    f32 scale;
    s32 i;

    if (self[0x20] == 0) {
        func_L23_003A77F0(self);
    } else if (self[0x20] == 2) {
        return;
    }
    if (v[0] >= 0 && D_L23_001DEC40 % 3 == 1) {
        u16 *p =  D_L23_001D676C[v[0]];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D676C[v[0]])) {
            e = (Ent_3A7048 *)(D_L23_001DFF08 + ((*p & 0x7FFF) << 5));
            if (e == 0)
                break;
            if (!(e->x16 & 1)) {
                m = (Fx_3A7048 *)(D_L23_001DFF10 + ((*p & 0x7FFF) << 6));
                if ((fabs_asm(m->pos.z - D_001A4BE0.pos.z) < 0.5f &&
                     func_L01_0040E570(&m->pos, &D_001A4BE0.pos) < 4.0f) ||
                    (fabs_asm(m->pos.z - *(f32 *)(D_L23_001DE2D0 + 0x18)) < 0.5f &&
                     func_L01_0040E570(&m->pos, D_L23_001DE2D0 + 0x10) < 4.0f)) {
                    f32 ang;

                    func_L23_003A6B98((u8 *)&m->pos, e->xC * 0.75f);
                    scale = e->xC * 2.0f * func_003824E0(0.9f, 1.1f);
                    ang = func_003824E0(-3.1415927f, 3.1415927f);
                    m->a.x = func_0038D098(ang) * scale;
                    m->a.y = func_0038D0B0(ang) * scale;
                    m->a.z = 0.0f;
                    m->b.x = func_0038D098(func_0038DAB8(ang, 1.5707964f)) * scale;
                    m->b.y = func_0038D0B0(func_0038DAB8(ang, 1.5707964f)) * scale;
                    qzero(&m->c);
                    m->b.z = 0.0f;
                    m->c.z = scale;
                    m->pos.z += 0.2f / scale;
                    m->pos.w = 1.0f;
                    e->x16 |= 1;
                }
            }
            p++;
        }
    }
    if (v[1] >= 0 && D_L23_001DEC40 % 3 == 2) {
        u16 *p;
        s32 id;
        p =  D_L23_001D676C[v[1]];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D676C[v[1]])) {
            id = *p & 0x7FFF;
            e = (Ent_3A7048 *)(D_L23_001DFF08 + (id << 5));
            if (e == 0)
                break;
            if (!(e->x16 & 1)) {
                V4 vel;
                V4 c1;
                V4 c2;
                s32 hit = 0;

                m = (Fx_3A7048 *)(D_L23_001DFF10 + (id << 6));
                if (fabs_asm(m->pos.z - D_001A4BE0.pos.z) < 0.5f &&
                    func_L01_0040E570(&m->pos, &D_001A4BE0.pos) < 4.0f) {
                    f32 ang;

                    hit = 1;
                    ang = func_0038D160(m->pos.x - D_001A4BE0.pos.x, m->pos.y - D_001A4BE0.pos.y);
                    func_0038DAB8(ang, func_003824E0(-0.5235988f, 0.5235988f));
                    vel.x = func_0038D098(ang) * func_003824E0(0.080000006f, 0.16000001f);
                    vel.y = func_0038D0B0(ang) * func_003824E0(0.080000006f, 0.16000001f);
                    vel.z = 0.0f;
                    vec_add_ba(&vel, &vel, &D_001A4BE0.vel);
                    vel.z = 0.080000006f;
                } else if (fabs_asm(m->pos.z - *(f32 *)(D_L23_001DE2D0 + 0x18)) < 0.5f &&
                           func_L01_0040E570(&m->pos, D_L23_001DE2D0 + 0x10) < 4.0f) {
                    f32 ang;

                    hit = 1;
                    ang = func_0038D160(m->pos.x - *(f32 *)(D_L23_001DE2D0 + 0x10),
                                        m->pos.y - *(f32 *)(D_L23_001DE2D0 + 0x14));
                    func_0038DAB8(ang, func_003824E0(-0.5235988f, 0.5235988f));
                    vel.x = func_0038D098(ang) * func_003824E0(0.080000006f, 0.16000001f);
                    vel.y = func_0038D0B0(ang) * func_003824E0(0.080000006f, 0.16000001f);
                    vel.z = 0.0f;
                    vec_add_ab(&vel, &vel, *(u8 **)(D_L23_001DE2D0 + 0x68) + 0x110);
                    vel.z = 0.080000006f;
                }
                if (hit) {
                    e->x16 |= 1;
                    func_L23_003A7908((u8 *)e, (u8 *)m, (vu0_q *)&vel);
                    func_L01_004AADE8(0x10, 0, 0, 0);
                    qzero(&c1);
                    qzero(&c2);
                    for (i = 0; i < 12; i++) {
                        c1.x = func_003824E0(-0.10000001f, 0.20000002f);
                        c1.y = func_003824E0(-0.10000001f, 0.20000002f);
                        c1.z = func_003824E0(0.10000001f, 0.20000002f);
                        c2.w = c1.w = func_003824E0(0.1f, 0.4f);
                        c2.z = 0.0f;
                        func_L01_00463378(&m->pos, &c1, &c2,
                                          func_0038DBD8(0x80004080, 0x80408080, func_003824E0(0.0f, 1.0f)),
                                          func_0038DBD8(0x4080, 0x408080, func_003824E0(0.0f, 1.0f)),
                                          func_00382498(1, 8), func_00382498(8, 0x11),
                                          func_00382498(0xC, 0x19), 0x1003C);
                    }
                }
            }
            p++;
        }
    }
    func_L01_00404808(func_L23_003A7A90, self);
}
/* localdecomp:end func_L23_003A7048 */

/* localdecomp:start func_L23_003A77F0 */
extern u16 **D_L23_001D676C;
__asm__(".extern D_L23_001D676C, 16");
extern s32 D_L23_001D6770;
__asm__(".extern D_L23_001D6770, 16");
extern u8 *D_L23_001DFF08;
__asm__(".extern D_L23_001DFF08, 16");
extern s16 D_L23_00236230[];


void func_L23_003A77F0(u8 *obj) {
    Vars_3A77F0 *v = *(Vars_3A77F0 **)(obj + 0x68);
    s32 i;
    s32 nA;
    s32 nB;
    u16 *p;
    u8 *e;
    s16 type;

    v->a = -1;
    v->b = -1;
    for (i = 0; i < D_L23_001D6770; i++) {
        p = D_L23_001D676C[i];
        nA = 0;
        nB = 0;
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D676C[i])) {
            e = D_L23_001DFF08 + ((*p & 0x7FFF) << 5);
            if (e == 0)
                break;
            type = D_L23_00236230[e[0x1A]];
            if (type == 0xD9D) {
                nB++;
            } else if (type == 0xDB6) {
                nA++;
            }
            if (nB >= 4) {
                v->b = i;
                break;
            }
            if (nA >= 4) {
                v->a = i;
                break;
            }
            p++;
        }
        if (v->a >= 0 && v->b >= 0)
            break;
    }
    func_L01_004450F0(obj, 1, -1);
}
/* localdecomp:end func_L23_003A77F0 */

/* localdecomp:start func_L23_003A7908 */
#include "vu0.h"
extern s16 D_L23_00236230[];
extern s32 D_L23_001DE120;
__asm__(".extern D_L23_001DE120, 4");
extern s32 D_L23_001DE124;
__asm__(".extern D_L23_001DE124, 4");
extern s32 D_L23_001DE128;
__asm__(".extern D_L23_001DE128, 4");
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_L01_0044E820(void *, s32);
extern f32 func_0038CEA8(void *);
extern void func_0038D308(void *, void *);
extern void func_003C7DD8(void *);
extern f32 func_0038D0B0(f32);
extern void func_L01_00443B88(f32 *, f32, f32);
extern void func_L01_003F7CE0(u8 *, s32, s32, vu0_q *, vu0_q *, s32, s32, f32);
extern void func_L01_002FFF00(u8 *);

u8 *func_L23_003A7908(u8 *src, u8 *pos, vu0_q *arg)
{
    s32 cls = -1;
    s16 id = D_L23_00236230[src[0x1A]];
    u8 *m;
    f32 s;
    f32 q[4];

    if (id == D_L23_001DE124) {
        cls = 0x1BD6;
    }
    if (id == D_L23_001DE128) {
        cls = 0x1BD7;
    }
    if (cls < 0) {
        return 0;
    }
    m = func_003C24B0(cls, 0x80);
    if (m != 0) {
        func_L01_00456160(m, 0);
        func_L01_0044E820(m, D_L23_001DE120);
        *(f32 *)(m + 0x2C) *= func_0038CEA8(pos + 0x20);
        *(u128_t *)(m + 0x10) = *(u128_t *)(pos + 0x30);
        func_0038D308(m + 0xC0, m + 0xF0);
        func_003C7DD8(m);
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x100) & ~0x30;
        *(void (**)(u8 *))(m + 0x64) = func_L01_002FFF00;
        *(s32 *)(m + 0x98) = 0;
        *(s32 *)(*(u8 **)(m + 0x68) + 0x54) = 0;
        s = func_0038D0B0(0.0069813174f);
        func_L01_00443B88(q, s, s);
        q[3] = sqrt_asm(1.0f - s * s);
        func_L01_003F7CE0(m, 2, 0, arg, (vu0_q *)q, 0xFF, 0x96, 15.0f);
        *(u16 *)(m + 0x34) &= ~2;
    }
    return m;
}
/* localdecomp:end func_L23_003A7908 */

/* localdecomp:start func_L23_003A7A90 */
extern u16 **D_L23_001D676C_3A7A90;
__asm__(".extern D_L23_001D676C_3A7A90, 4");
extern u8 *D_L23_001DFF10;
__asm__(".extern D_L23_001DFF10, 16");
extern u8 D_L23_001E1A40[];
extern s32 D_L23_001DE118[2];
__asm__(".extern D_L23_001DE118, 8");
extern f32 D_L23_001DE0F8;
__asm__(".extern D_L23_001DE0F8, 4");
extern f32 D_L23_001DE0FC;
__asm__(".extern D_L23_001DE0FC, 4");
extern f32 D_L23_001DE100;
__asm__(".extern D_L23_001DE100, 4");
extern s32 D_L23_001DE104;
__asm__(".extern D_L23_001DE104, 4");
extern s32 D_L23_001DE108;
__asm__(".extern D_L23_001DE108, 4");
extern f32 D_L23_001DE10C;
__asm__(".extern D_L23_001DE10C, 4");
extern f32 D_L23_001DE110;
__asm__(".extern D_L23_001DE110, 4");
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, void *, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);

void func_L23_003A7A90(u8 *self)
{
    s32 *v = *(s32 **)(self + 0x68);
    Quad_3B5628 s;
    V4 axis;
    V4 r[4];
    u16 *p;
    u8 *e;
    u8 *m;
    s32 n = 0;
    s32 last = -1;
    s32 id;
    s32 c;
    s32 col;
    f32 ang;
    f32 d;
    f32 scale;

    s.uv[0][0] = 0.0f;
    s.uv[0][1] = 0.0f;
    s.uv[1][0] = 0.0f;
    s.uv[1][1] = 1.0f;
    s.uv[2][0] = 1.0f;
    s.uv[2][1] = 0.0f;
    s.uv[3][0] = 1.0f;
    s.uv[3][1] = 1.0f;
    qzero(s.pos[0]);
    s.tex0 = 0xFF9000000379L;
    qzero(s.pos[2]);
    s.count = 5;
    s.alpha = 0x8000000044L;
    s.pos[0][0] = -1.0f;
    qzero(s.pos[1]);
    s.pos[0][3] = 1.0f;
    s.pos[2][1] = -1.0f;
    s.pos[1][1] = 1.0f;
    s.pos[1][3] = 1.0f;
    s.pos[2][3] = 1.0f;
    qzero(s.pos[3]);
    s.pos[3][0] = 1.0f;
    s.pos[3][3] = 1.0f;
    if (v[0] >= 0) {
        p = D_L23_001D676C_3A7A90[v[0]];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D676C[v[0]])) {
            e = D_L23_001DFF08 + ((*p & 0x7FFF) << 5);
            if (e == 0)
                break;
            n++;
            if (e[0x16] & 1) {
                f32 dist;

                m = D_L23_001DFF10 + ((*p & 0x7FFF) << 6);
                ang = func_0038D160(*(f32 *)(m + 0x30) - *(f32 *)&D_L23_001E1A40[0],
                                    *(f32 *)(m + 0x34) - *(f32 *)&D_L23_001E1A40[4]);
                d = func_0038DBA0(*(f32 *)&D_L23_001E1A40[0x18], ang);
                dist = func_L01_0040E570(m + 0x30, D_L23_001E1A40);
                if (!(d > 1.2217305f && dist > 64.0f) && !(dist > 1600.0f)) {
                    if (dist > 1024.0f) {
                        c = func_0038DBD8(0x50000000, 0, (dist - 1024.0f) / (1600.0f - 1024.0f));
                        s.rgba[3] = c;
                        s.rgba[2] = c;
                        s.rgba[1] = c;
                        s.rgba[0] = c;
                    } else {
                        s.rgba[3] = 0x50000000;
                        s.rgba[2] = 0x50000000;
                        s.rgba[1] = 0x50000000;
                        s.rgba[0] = 0x50000000;
                    }
                    id = D_L23_001DE118[n % 2];
                    if (id != last) {
                        s.tex = func_00389598(id);
                        last = id;
                    }
                    func_003D2DA0(&s, m, 0);
                }
            }
            p++;
        }
    }
    s.tex = func_00389598(0x6B);
    s.uv[0][0] = 0.0f;
    s.uv[0][1] = 0.0f;
    s.uv[1][0] = 1.0f;
    s.uv[1][1] = 0.0f;
    s.uv[2][0] = 0.0f;
    s.uv[2][1] = 1.0f;
    s.uv[3][0] = 1.0f;
    s.uv[3][1] = 1.0f;
    s.pos[0][0] = -0.5f;
    *(u128_t *)&axis = 0;
    s.pos[2][0] = -0.5f;
    s.pos[0][1] = 1.0f;
    s.pos[1][0] = 0.5f;
    s.pos[3][0] = 0.5f;
    s.pos[1][1] = 1.0f;
    s.pos[2][1] = 0.0f;
    s.pos[3][1] = 0.0f;
    axis.z = 1.0f;
    axis.w = 1.0f;
    if (v[1] >= 0) {
        p = D_L23_001D676C_3A7A90[v[1]];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D676C[v[1]])) {
            e = D_L23_001DFF08 + ((*p & 0x7FFF) << 5);
            if (e == 0)
                break;
            if (!(e[0x16] & 1)) {
                f32 dist;

                scale = D_L23_001DE10C;
                col = D_L23_001DE104;
                if (D_L23_00236230[e[0x1A]] == 0xD9D) {
                    scale = D_L23_001DE110;
                    col = D_L23_001DE108;
                }
                m = D_L23_001DFF10 + ((*p & 0x7FFF) << 6);
                ang = func_0038D160(*(f32 *)(m + 0x30) - *(f32 *)&D_L23_001E1A40[0],
                                    *(f32 *)(m + 0x34) - *(f32 *)&D_L23_001E1A40[4]);
                d = func_0038DBA0(*(f32 *)&D_L23_001E1A40[0x18], ang);
                dist = func_L01_0040E570(m + 0x30, D_L23_001E1A40);
                if (!(d > 1.2217305f && dist > 64.0f) && !(dist > D_L23_001DE100)) {
                    if (dist > D_L23_001DE0FC) {
                        c = func_0038DBD8(col, 0, (dist - D_L23_001DE0FC) / (D_L23_001DE100 - D_L23_001DE0FC));
                        s.rgba[3] = c;
                        s.rgba[2] = c;
                        s.rgba[1] = c;
                        s.rgba[0] = c;
                    } else {
                        s.rgba[3] = col;
                        s.rgba[2] = col;
                        s.rgba[1] = col;
                        s.rgba[0] = col;
                    }
                    r[2].x = func_0038D098(ang);
                    r[2].y = func_0038D0B0(ang);
                    r[2].z = 0.0f;
                    func_0038CE20(&r[1], &axis, scale);
                    func_0038CE90(&r[0], &r[1], &r[2]);
                    r[3].x = func_0038D098(ang) * -D_L23_001DE0F8;
                    r[3].y = func_0038D0B0(ang) * -D_L23_001DE0F8;
                    r[3].z = 0.0f;
                    vec_add_ba(&r[3], &r[3], m + 0x30);
                    func_003D2DA0(&s, &r[0], 0);
                }
            }
            p++;
        }
    }
}
/* localdecomp:end func_L23_003A7A90 */

INCLUDE_ASM("asm/levels", func_L23_003A8028);

/* localdecomp:start func_L23_003A97B8 */
/* MATCH: needs Rec14 at the top of L23_003A6688.c changed to { s32 id; f32 x4; f32 x8; s32 xC[2]; } (same 0x14 size; only .id is used elsewhere). Verified: whole file with that change, all 16 functions MATCH (full_file_check.c). */
#include "vu0.h"
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern u8 *D_L23_001E001C;
__asm__(".extern D_L23_001E001C, 16");
extern s16 D_L23_0023A3C0[];
extern Rec14 D_L23_002BC7F8[];
extern u16 **D_L23_001D676C;
__asm__(".extern D_L23_001D676C, 16");
extern s32 D_L23_001D6770;
__asm__(".extern D_L23_001D6770, 16");
extern u8 *D_L23_001DFF10;
__asm__(".extern D_L23_001DFF10, 16");
extern s32 D_L23_001DE134;
__asm__(".extern D_L23_001DE134, 4");
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);



void func_L23_003A97B8(Moby_3A97B8 *self)
{
    Vars_3A97B8 *v = self->vars;
    u8 *best = 0;
    f32 bestz = 0.0f;
    u16 *p;
    u16 *q;
    u8 *e;
    u8 *m;
    s32 id;
    s32 j;
    s32 i;
    s32 n;
    s32 bi;
    f32 lim;
    f32 d;
    f32 t;
    V4 acc;

    p = D_L23_001D6764[v->id];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
        m = D_L23_001E001C + ((*p & 0x7FFF) << 6);
        if (m == 0)
            break;
        if (!(*(f32 *)(m + 0x38) < bestz)) {
            id = D_L23_0023A3C0[(D_L23_001E0014 + ((*p & 0x7FFF) << 5))[0x1D]];
            for (j = 0; D_L23_002BC7F8[j].id >= 0 && id != D_L23_002BC7F8[j].id; j++)
                ;
            if (D_L23_002BC7F8[j].id >= 0) {
                v->x20 = j;
                best = m;
                bestz = *(f32 *)(m + 0x38);
            }
        }
        p++;
    }
    v->x24 = func_0038CEA8(best) > func_0038CEA8(best + 0x10) ? func_0038CEA8(best) : func_0038CEA8(best + 0x10);
    v->x28 = func_0038CEA8(best + 0x20);
    if (v->x20 >= 0) {
        v->x24 *= D_L23_002BC7F8[v->x20].x4;
        v->x28 *= D_L23_002BC7F8[v->x20].x8;
    }
    self->scale *= v->x24;
    func_0038CF68(&self->xC0, best, 1.0f);
    func_0038CF68(&self->xD0, best + 0x10, 1.0f);
    func_0038CF68(&self->xE0, best + 0x20, 1.0f);
    self->pos = *(V4 *)(best + 0x30);
    v->x8 = func_003C3D30(&self->pos, 2, self, 2.0f);
    self->pos.z = *(f32 *)(best + 0x38) + v->x28;
    t = v->x24 * 0.5f + 1.0f;
    t = t * t;
    lim = t + t;
    bi = -1;
    for (i = 0; i < D_L23_001D6770; i++) {
        qzero(&acc);
        n = 0;
        q = D_L23_001D676C[i];
        while (q != 0 && ((s16)q[-1] >= 0 || q == D_L23_001D676C[i])) {
            e = D_L23_001DFF10 + ((*q & 0x7FFF) << 6);
            if (e == 0)
                break;
            vec_add_ab(&acc, e + 0x30, &acc);
            n++;
            q++;
            if (n > 16)
                break;
        }
        if (n != 0) {
            func_0038CE20(&acc, &acc, 1.0f / n);
            if (n < 0x10) {
                d = func_L01_0040E570(&acc, best + 0x30);
                if (d < lim) {
                    lim = d;
                    bi = i;
                }
            }
        }
    }
    v->x4 = bi;
    v->x1C = -1;
    v->x14 = 0;
    v->x18 = 0;
    if (v->x28 < 6.0f)
        v->xC = 25.0f;
    else if (v->x28 < 9.0f)
        v->xC = 60.0f;
    else
        v->xC = 101.0f;
    v->x30 = *(u128_t *)&self->pos;
    qzero(&v->x40);
    self->x21 = 0xFF;
    self->x34 |= 0x110;
    D_L23_001DE134 = 0;
    func_L01_0044ED88(self, v->x50, 0x10, -1, v->id, v->x4, 7, 0);
    self->x34 |= 0x41;
    func_L01_004450F0((u8 *)self, 1, -1);
}
/* localdecomp:end func_L23_003A97B8 */

/* localdecomp:start func_L23_003A9C40 */
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];
extern Rec14 D_L23_002BC7F8[];

s32 func_L23_003A9C40(s32 idx)
{
    u16 *p = D_L23_001D6764[idx];
    u8 *e;
    s32 id;
    s32 i;

    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[idx])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0)
            break;
        id = D_L23_0023A3C0[e[0x1D]];
        for (i = 0; D_L23_002BC7F8[i].id >= 0; i++) {
            if (id == D_L23_002BC7F8[i].id)
                return 1;
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003A9C40 */

/* localdecomp:start func_L23_003A9D00 */
#include "vu0.h"
extern S_1E1880 D_L23_001E1880;
extern long func_00389598(s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L23_003A9D00(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    S_3A9D00 s;
    s32 i;
    s32 n;
    s32 c;
    f32 ang;
    f32 b;
    f32 t;

    s.x78 = func_00389598(0x6A);
    s.x80 = 0xFF9000000260L;
    s.x70 = 4;
    s.x88 = 0x8000000044L;
    s.x50 = 0;
    s.x54 = 0;
    s.x58 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x64 = 0;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    c = (*(s32 *)(v + 0x2C) << 24) | 0x303030;
    qzero(s.m[0]);
    qzero(s.m[1]);
    qzero(s.m[2]);
    qzero(s.m[3]);
    *(u128_t *)&s.axis = 0;
    s.m[0][0] = 3.0f;
    s.m[0][3] = 1.0f;
    s.c4C = c;
    s.m[1][1] = 3.0f;
    s.c48 = c;
    s.m[1][3] = 1.0f;
    s.c44 = c;
    s.c40 = c;
    s.m[2][3] = 1.0f;
    s.m[2][1] = -3.0f;
    s.m[3][0] = -3.0f;
    s.m[3][3] = 1.0f;
    s.axis.z = 1.0f;
    s.axis.w = 1.0f;
    n = *(f32 *)(v + 0x24) * 8.0f / 3.0f;
    for (i = 0; i < n; ) {
        ang = func_0038D160(D_L23_001E1880.x140 - *(f32 *)(self + 0x10),
                            D_L23_001E1880.x144 - *(f32 *)(self + 0x14));
        b = func_0038DB48((f32)i * 2 * 3.1415927f / (f32)n);
        t = (f32)((D_L23_001DEC40 + i * 16) % 100) / 100.0f * 6.2831855f - 1.5707964f;
        if (func_0038DB48(ang - b) > 0.0f) {
            t = -t;
        }
        i++;
        s.r[2].x = func_0038D098(ang);
        s.r[2].y = func_0038D0B0(ang);
        s.r[2].z = 0.0f;
        func_0038D890(&s.r[0], &s.axis, &s.r[2], t);
        func_0038CE90(&s.r[1], &s.r[0], &s.r[2]);
        s.r[3].x = func_0038D098(b) * (*(f32 *)(v + 0x24) * 0.6f);
        s.r[3].y = func_0038D0B0(b) * (*(f32 *)(v + 0x24) * 0.6f);
        s.r[3].z = 0.0f;
        vec_add_ab(&s.r[3], &s.r[3], v + 0x30);
        s.r[3].z = *(f32 *)(v + 0x8) + 0.6f;
        func_003D2DA0(&s, &s.r[0], 1);
    }
}
/* localdecomp:end func_L23_003A9D00 */

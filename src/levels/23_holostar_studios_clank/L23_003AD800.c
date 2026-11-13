#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x228]; f32 f228; u8 pad22C[0x244 - 0x22C]; s32 i244;
    u8 pad248[0x2BC - 0x248]; s32 i2BC;
    V4 a2C0[8]; V4 a340[8]; V4 a3C0[8]; V4 a440[8];
} P_3AFAF0;
typedef struct { u8 pad0[0x68]; P_3AFAF0 *p; } S_3AFAF0;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 x20;
    u8 pad21[0xB];
    f32 scale;
    u8 x30;
    u8 pad31;
    s16 x32;
    u16 x34;
    u8 pad36[0x32];
    u8 *vars;
} Moby_3B12C8;
typedef struct {
    u8 pad0[0x220]; s32 w220; u8 pad224[0x22C - 0x224]; void *p22C;
    u8 pad230[0x2BC - 0x230]; s32 i2BC;
    V4 a2C0[8]; V4 a340[8];
} P_3AFC40;
typedef struct { u8 pad0[0x20]; u8 b20; u8 pad21[0x68 - 0x21]; P_3AFC40 *p; u8 pad6C[0xAA - 0x6C]; u16 hAA; } S_3AFC40;
typedef struct { u8 pad0[0x18]; u8 b18; u8 b19; u16 h1A; u8 pad1C[0x14]; } B_3AFC40;
typedef struct { u8 pad0[0x18]; void *p18; u8 pad1C[4]; u8 a20[1]; } H_3AFC40;
typedef struct {
    u8 pad0[0x10];
    V4 pos;
    u8 x20;
    u8 pad21[0x95 - 0x21];
    u8 x95;
    u8 pad96[0xA8 - 0x96];
    u8 xA8;
} Moby_3AF6E8;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B0200;
typedef struct { u8 pad0[0x12]; s16 count; u8 pad14[0xC]; s32 *ids; u8 pad24[0xC]; } Path_3B0200;
typedef struct { s32 count; u8 pad4[0x1C]; Path_3B0200 paths[1]; } Paths_3B0200;
typedef struct { u8 pad0[0x30]; V4_3B0200 pos; u8 pad40[0x40]; } Node_3B0200;
typedef struct { u8 pad0[0x180]; struct Moby *target; } Vars_3B34F8;

INCLUDE_ASM("asm/levels", func_L23_003AD800);

/* localdecomp:start func_L23_003AF6E8 */
#include "vu0.h"
extern f32 D_L23_001DE248;
__asm__(".extern D_L23_001DE248, 4");
extern f32 D_L23_001DE220;
__asm__(".extern D_L23_001DE220, 4");
extern V4 D_L23_001E87A0;
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern void func_L23_003AF9B8(u8 *self);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);
extern void *func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_00404A10(void *, s32);


void func_L23_003AF6E8(Moby_3AF6E8 *m)
{
    u8 *v = *(u8 **)((u8 *)m + 0x68);
    u8 *t;
    V4 d;
    V4 p;
    V4 q;
    f32 len;

    if (m->x20 == 0) {
        func_L23_003AF9B8((u8 *)m);
    }
    func_L01_00451DF8((u8 *)m, v + 0x190, 11, 1, 2.5f);
    t = func_L01_00447490(m, 0x1170000, 0);
    if (t != 0) {
        if (m->x20 != 20) {
            *(f32 *)(v + 0x30) -= *(f32 *)(t + 0x2C);
            v[0x167] = 0xFF;
            func_003C4A40(m, v + 0x160);
            if ((*(f32 *)(v + 0x30) <= 0.0f || 10.0f <= *(f32 *)(t + 0x2C)) && m->x95 != 1 && m->x95 != 0) {
                if (40.0f <= *(f32 *)(t + 0x2C) && *(u8 **)(t + 0x20) != 0) {
                    vec_sub_ba(&d, &m->pos, *(u8 **)(t + 0x20) + 0x10);
                    d.z = 0.0f;
                    func_0038CF68(&d, &d, D_L23_001DE220 + D_L23_001DE248);
                    p = m->pos;
                    p.z += 1.0f;
                    vec_add_ab(&q, &p, &d);
                    if (func_003D3CB0(&p, &q, 0, m, 0) != 0) {
                        vec_sub_ba(&d, &D_L23_001E87A0, &m->pos);
                        d.z = 0.0f;
                        len = func_0038CEA8(&d);
                        if (D_L23_001DE248 < len) {
                            func_0038CE20(&d, &d, (len - D_L23_001DE248) / len);
                        } else {
                            qzero(&d);
                        }
                    } else {
                        func_0038CE20(&d, &d, D_L23_001DE220 / (D_L23_001DE220 + D_L23_001DE248));
                    }
                    *(f32 *)(v + 0x2B8) = func_0038CEA8(&d);
                    *(f32 *)(v + 0x2B4) = func_0038D160(d.x, d.y);
                }
                func_L01_004450F0(m, 20, -1);
            }
        }
        m->xA8 = 0xFF;
    }
    if (m->x95 == 0 && m->pos.z < *(f32 *)(v + 0x298) - 10.0f) {
        *(s32 *)(v + 0x30) = 0;
        func_L01_004450F0(m, 20, -1);
    }
    func_L01_0044ABD0(m, v + 0x160);
    func_L01_00404A10(m, 3);
    *(struct Moby **)(v + 0x180) = D_001A4BE0.hero_moby;
    *(s16 *)(v + 0x184) = 1;
    *(u128_t *)(v + 0x170) = *(u128_t *)&D_001A4BE0.pos;
}
/* localdecomp:end func_L23_003AF6E8 */

/* localdecomp:start func_L23_003AF9B8 */
__asm__(".extern D_L23_001DE244, 4");
__asm__(".extern D_L23_001DE248, 4");
extern f32 D_L23_001DE244;
extern f32 D_L23_001DE248;
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003AF9B8(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);

    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    *(f32 *)(v + 0x40) = 1.0f;
    v[0x39] = 0;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 0x4B;
        *(f32 *)(v + 0x30) = 75.0f;
    }
    if (*(s32 *)(v + 0x220) != 0) {
        *(f32 *)(v + 0x30) *= D_L23_001DE244;
        *(s16 *)(v + 0x34) = *(f32 *)(v + 0x30);
    }
    *(f32 *)(v + 0x70) = D_L23_001DE248;
    *(f32 *)(v + 0xA4) = 0.5f;
    *(f32 *)(v + 0x74) = *(f32 *)(v + 0x70);
    *(f32 *)(v + 0x78) = 1.0f;
    *(f32 *)(v + 0x7C) = 1.5f;
    *(f32 *)(v + 0x80) = 1.4835298f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00392f;
    *(V4 *)(v + 0x250) = *(V4 *)(self + 0x10);
    *(V4 *)(v + 0x290) = *(V4 *)(self + 0x10);
    *(f32 *)(v + 0x24C) = *(f32 *)(self + 0xF8);
    *(s32 *)(v + 0x218) = 0;
    *(s32 *)(v + 0x244) = 0;
    *(s32 *)(v + 0x21C) = 0;
    *(s32 *)(v + 0x240) = 0;
    *(s32 *)(v + 0x228) = 0;
    *(s32 *)(v + 0x2BC) = 0;
    *(s32 *)(v + 0x210) = 0;
    if (self[0x21] != 0xFF)
        func_L01_004450F0(self, 1, 0);
    else
        func_L01_004450F0(self, 4, 2);
}
/* localdecomp:end func_L23_003AF9B8 */

/* localdecomp:start func_L23_003AFAF0 */
#include "vu0.h"
__asm__(".extern D_L23_001DE250, 4");
__asm__(".extern D_L23_001DE274, 4");
extern f32 D_L23_001DE250;
extern s32 D_L23_001DE274;
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00404808(void *, void *);
void func_L23_003B0480(void *);

void func_L23_003AFAF0(S_3AFAF0 *s)
{
    P_3AFAF0 *p = s->p;
    u8 buf[0x40];
    V4 v;

    if (p->i244 != 0) {
        func_003C4138(&p->f228, D_L23_001DE250, D_L23_001DE250 / 60.0f);
    } else {
        func_003C4138(&p->f228, 0.0f, D_L23_001DE250 / 30.0f);
    }
    if (++p->i2BC >= D_L23_001DE274) {
        p->i2BC = 0;
    }
    func_003C2EC0(s, 0, buf);
    func_0038CF68(&v, buf, p->f228);
    func_003C2F58(s, 1, &p->a2C0[p->i2BC]);
    func_003C2F58(s, 3, &p->a3C0[p->i2BC]);
    vec_add_ba(&p->a340[p->i2BC], &p->a2C0[p->i2BC], &v);
    vec_sub_ba(&p->a440[p->i2BC], &p->a3C0[p->i2BC], &v);
    if (0.0f < p->f228) {
        func_L01_00404808(func_L23_003B0480, s);
    }
}
/* localdecomp:end func_L23_003AFAF0 */

/* localdecomp:start func_L23_003AFC40 */
#include "vu0.h"
__asm__(".extern D_L23_001DE238, 4");
extern f32 D_L23_001DE238;
extern H_3AFC40 D_L23_001E8780;
__asm__(".extern D_L23_001E8780, 16");
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L23_003AFC40(S_3AFC40 *s)
{
    P_3AFC40 *p;
    V4 d;
    V4 t;
    B_3AFC40 b;
    void *h;
    s32 c;

    p = s->p;
    func_0038CE20(&t, (u8 *)s + 0xC0, 3.0f);
    vec_sub_ab(&d, &t, &p->a2C0[p->i2BC]);
    func_0038CF68(&d, &d, 2.5f);
    d.z = 1.0f;
    d.w = 5627.9248f;
    func_L01_00446760(&b, s, s->b20 == 0xF ? 7 : 3, &d, D_L23_001DE238 + D_L23_001DE238);
    b.b18 = 0;
    b.b19 = 1;
    b.h1A = s->hAA;
    if (func_003D3CB0(&p->a2C0[p->i2BC], &p->a340[p->i2BC], 9, s, &b) != 0) {
        h = D_L23_001E8780.p18;
        if (h != p->p22C && h != 0) {
            p->p22C = h;
            c = p->w220 ? 0x60000080 : 0x60008080;
            func_L01_003303B8(D_L23_001E8780.a20, 0, 0, 0xF, 0, 1, 0xF, 0, 0.4f, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0, 0, c, c, c, c, c, c, c, c, 0, 0);
        }
    }
}
/* localdecomp:end func_L23_003AFC40 */

/* localdecomp:start func_L23_003AFE10 */
extern f32 D_L23_001DE224;
__asm__(".extern D_L23_001DE224, 4");
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L03_0043FC00(s32, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern void func_L01_004443E8(void *, s32, s32);

void func_L23_003AFE10(u8 *o)
{
    u8 *v = *(u8 **)(o + 0x68);
    f32 d[4];

    d[0] = func_0038D098(*(f32 *)(v + 0x2B4)) *
           (D_L23_001DE224 < *(f32 *)(v + 0x2B8) ? D_L23_001DE224 * 0.5f : *(f32 *)(v + 0x2B8) * 0.5f);
    d[1] = func_0038D0B0(*(f32 *)(v + 0x2B4)) *
           (D_L23_001DE224 < *(f32 *)(v + 0x2B8) ? D_L23_001DE224 * 0.5f : *(f32 *)(v + 0x2B8) * 0.5f);
    d[2] = 0.0f;
    func_003A52A0(0, 0, o);
    func_L03_0043FC00((s32)o, 0x3FF, (u8 *)d, 3, 3, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 1.0f);
    *(s32 *)(v + 0x210) = 200;
    *(s32 *)(v + 0x228) = 0;
    *(s32 *)(v + 0x244) = 0;
    if (*(s32 *)(v + 0x2B0) == 0)
        func_L01_004443E8(o, 0, 3);
    func_L01_003303B8(o + 0x10, 1, 10, 20, 0, 4, 20, 2, 2.0f, 0.0f, 0.0f, 0.0f,
                      1, 1, 1, 0, 1, 1, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
}
/* localdecomp:end func_L23_003AFE10 */

/* localdecomp:start func_L23_003B0010 */
extern void func_L01_004450F0(void *, s32, s32);
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
extern s32 D_L23_001DF198;

void func_L23_003B0010(s32 idx) {
    u16 *p;
    u8 *e;

    if (idx < 0) {
        return;
    }
    p = D_L23_0021C0E0[idx];
    while ((idx & 0xFF) != 0xFF && idx <= D_L23_001DF198 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[idx])) {
        e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            return;
        }
        if (e[0x20] == 1) {
            func_L01_004450F0(e, 2, 1);
        }
        p++;
    }
}
/* localdecomp:end func_L23_003B0010 */

/* localdecomp:start func_L23_003B0110 */
extern void func_L01_0045AA10(void *, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0045A748(void *, void *);
extern s32 func_L23_003B0200(u8 *, s32, f32 *, void *, void *, s32);

s32 func_L23_003B0110(u8 *m, V4 *target, s32 mode, f32 speed) {
    u8 *v = *(u8 **)(m + 0x68);
    V4 pos;
    f32 before;
    f32 after;
    if (mode == 0) {
        func_L01_0045AA10(m, speed);
        func_L01_0045BD10(m, speed);
        return 1;
    }
    pos = *target;
    func_L23_003B0200(m, *(s32 *)(v + 0x23C), (f32 *)&pos, v + 0x280, v + 0x248, 0);
    before = func_L01_0040E570(&pos, m + 0x10);
    func_L01_0045A748(m, &pos);
    after = func_L01_0040E570(&pos, m + 0x10);
    return !(before > 1.0f && __builtin_fabsf(after - before) < 0.01f);
}
/* localdecomp:end func_L23_003B0110 */

/* localdecomp:start func_L23_003B0200 */
#include "common.h"
#include "vu0.h"
extern Paths_3B0200 *D_L23_001DED4C;
__asm__(".extern D_L23_001DED4C, 16");
extern Node_3B0200 *D_L23_001DF240;
__asm__(".extern D_L23_001DF240, 16");
extern f32 D_L23_001DE24C;
__asm__(".extern D_L23_001DE24C, 4");
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern int func_00382380(void *, int, int);

s32 func_L23_003B0200(u8 *m, s32 idx, f32 *out, void *a3, void *a4, s32 flag)
{
    V4_3B0200 *home = a3;
    s32 *cur = a4;
    Path_3B0200 *path;
    V4_3B0200 pos;
    V4_3B0200 tgt;
    V4_3B0200 dir;
    f32 d;
    f32 nd;
    f32 lim;
    s32 best;
    s32 i;
    s32 id;
    Node_3B0200 *e;

    if (idx >= 0 && idx < D_L23_001DED4C->count) {
    path = &D_L23_001DED4C->paths[idx];
    pos = *(V4_3B0200 *)(m + 0x10);
    tgt = *(V4_3B0200 *)out;
    pos.z += 1.0f;
    tgt.z += 1.0f;
    d = func_L01_0040E570(&pos, &tgt);
    vec_sub_ab(&dir, &tgt, &pos);
    func_0038CE20(&dir, &dir, sqrt_asm(d));
    if (flag == 0 && func_003D3CB0(&pos, &tgt, 0, m, 0) == 0) {
        *cur = -1;
        *home = *(V4_3B0200 *)out;
        return 1;
    }
    lim = d * 4.0f;
    best = -1;
    for (i = 0; i < path->count; i++) {
        id = path->ids[i];
        e = &D_L23_001DF240[id];
        if (id == *cur)
            continue;
        if (func_00382380(&pos, id, 0) != 0) {
            *cur = path->ids[i];
            continue;
        }
        nd = func_L01_0040E570(&tgt, &e->pos);
        if (lim < nd)
            continue;
        if (func_003D3CB0(&pos, &e->pos, 0, m, 0) != 0)
            continue;
        lim = nd;
        best = i;
    }
    if (best < 0) {
        if (func_L01_0040E570(out, home) > D_L23_001DE24C * D_L23_001DE24C)
            *(V4_3B0200 *)out = *home;
        else
            return 0;
    } else {
        *(V4_3B0200 *)out = D_L23_001DF240[path->ids[best]].pos;
    }
    }
    return 1;
}
/* localdecomp:end func_L23_003B0200 */

INCLUDE_ASM("asm/levels", func_L23_003B0480);

INCLUDE_ASM("asm/levels", func_L23_003B0708);

/* localdecomp:start func_L23_003B08E0 */
void func_0038CAD0(s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L23_001E1A40[];

void func_L23_003B08E0(void *arg0) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = *(s32 *)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L23_001E1A40, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
    func_0038CAD0(temp_s1 + 0x214);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L23_003B08E0 */

/* localdecomp:start func_L23_003B0978 */
extern u8 *func_003C24B0(s32, s32);
extern s32 D_L23_001DEC40;
__asm__(".extern D_L23_001DEC40, 16");

u8 *func_L23_003B0978(s32 a0, u128_t *pos, u128_t *target, s32 a3, s32 a4, s32 a5) {
    u8 *m = func_003C24B0(0x1BC8, 0x80);
    u8 *v;

    if (m != 0) {
        m[0x20] = 0;
        m[0x30] = 0xFF;
        v = *(u8 **)(m + 0x68);
        *(u128_t *)(m + 0x10) = *pos;
        *(u128_t *)(v + 0x10) = *target;
        *(s32 *)(v + 0) = a3;
        *(s32 *)(v + 4) = a0;
        *(s32 *)(v + 8) = D_L23_001DEC40 + 150;
        *(s32 *)(v + 0xC) = a5;
    }
    return m;
}
/* localdecomp:end func_L23_003B0978 */

INCLUDE_ASM("asm/levels", func_L23_003B0A20);

INCLUDE_ASM("asm/levels", func_L23_003B0CE0);

INCLUDE_ASM("asm/levels", func_L23_003B0EC0);

/* localdecomp:start func_L23_003B1230 */
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];

s32 func_L23_003B1230(s32 idx)
{
    u16 *p = D_L23_001D6764[idx];
    u8 *e;

    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[idx])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[e[0x1D]] == 0x1CCC)
            return 1;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003B1230 */

/* localdecomp:start func_L23_003B12C8 */
extern u8 *D_L23_001E001C;
__asm__(".extern D_L23_001E001C, 16");
extern u8 *D_L23_001E0014_3B12C8;
__asm__(".extern D_L23_001E0014_3B12C8, 4");
extern f32 D_L23_001DE2A8;
__asm__(".extern D_L23_001DE2A8, 4");
extern s32 D_001A71A0[];
extern s32 func_L01_0044E7D8(s32);
extern void func_L01_0044E820(void *, s32);
extern f32 func_0038CEA8(void *);

void func_L23_003B12C8(s32 id)
{
    Moby_3B12C8 *o = (Moby_3B12C8 *)func_003C24B0(0x1BD4, 0x80);
    u8 *v;
    u16 *p;
    u8 *e;
    f32 s;

    if (o == 0)
        return;
    v = o->vars;
    *(f32 *)(v + 8) = D_L23_001DE2A8;
    *(s32 *)v = id;
    o->x20 = 1;
    o->x30 = 0xFF;
    o->x32 = 0xFF;
    func_L01_0044E820(o, func_L01_0044E7D8(D_001A71A0[0]));
    o->x34 |= 0x41;
    p = D_L23_001D6764[*(s32 *)v];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[*(s32 *)v])) {
        e = D_L23_001E001C + ((*p & 0x7FFF) << 6);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[(D_L23_001E0014_3B12C8 + ((*p & 0x7FFF) << 5))[0x1D]] == 0x1CCC) {
            o->pos = *(u128_t *)(e + 0x30);
            s = func_0038CEA8(e + 0x20);
            *(f32 *)(v + 4) = s;
            o->scale *= s;
            return;
        }
        p++;
    }
}
/* localdecomp:end func_L23_003B12C8 */

/* localdecomp:start func_L23_003B1418 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
__asm__(".extern D_L23_001DE2B0, 8");
__asm__(".extern D_L23_001DE2C0, 4");
__asm__(".extern D_L23_001DE2C4, 4");
__asm__(".extern D_L23_001DE2C8, 4");
extern f32 D_L23_001DE2B0[2];
extern s32 D_L23_001DE2C0;
extern u32 D_L23_001DE2C4;
extern f32 D_L23_001DE2C8;

void func_L23_003B1418(void *arg0) {
    V4 v;
    f32 *p;

    p = *(f32 **)((u8 *)arg0 + 0x68);
    if (p != 0) {
        func_0038CE20(&v, D_L23_001DE2B0, p[1]);
        vec_add_ba(&v, &v, (u8 *)arg0 + 0x10);
        func_003D9508(&v, D_L23_001DE2C0, D_L23_001DE2C4, 1, D_L23_001DE2C8, 0.3f, 0.0f);
    }
}
/* localdecomp:end func_L23_003B1418 */

INCLUDE_ASM("asm/levels", func_L23_003B1490);

/* localdecomp:start func_L23_003B34F8 */
/* MATCH with --no-context --as ps2as. Needs L23_003AD800.c line 58 changed to
   extern void *func_L01_00447490(void *, s32, s32);  (s32 as in every other file; u32 makes -1 a lui/ori). */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern s32 D_L23_001DEC40;
__asm__(".extern D_L23_001DEC40, 16");
extern struct Moby *D_L23_001E8798[];
extern V4 D_L23_001E87A0;
__asm__(".extern D_L23_001E87A0, 16");
extern f32 D_L23_001DE338;
__asm__(".extern D_L23_001DE338, 4");
extern f32 D_L23_001DE328;
__asm__(".extern D_L23_001DE328, 4");
extern f32 D_L23_001DE32C;
__asm__(".extern D_L23_001DE32C, 4");
extern s32 D_L23_001DE2D8;
__asm__(".extern D_L23_001DE2D8, 4");
extern void *func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C4A40(void *a, void *b);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0044ABD0(void *a, void *b);
extern void func_L01_00404A10(void *, s32);
extern void func_L03_0043BE98(int, void *, int, int, int);
extern void func_L01_00404808(void *, void *);
void func_L23_003B3998(u8 *self);
void func_L23_003B44F8(u8 *self);
void func_L23_003B48D0(void *self);


void func_L23_003B34F8(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    u8 *hit;
    s32 n;
    f32 d;
    f32 len;
    V4 dir;
    V4 a;
    V4 b;

    if (self[0x20] == 0)
        func_L23_003B3998(self);
    hit = func_L01_00447490(self, -1, 0);
    if (hit != 0) {
        if (D_L23_001DEC40 >= *(s32 *)(v + 0x33C) && *(f32 *)(hit + 0x2C) > 2.0f) {
            n = (s32)*(f32 *)(hit + 0x2C) >> 1;
            if (n > 20)
                n = 20;
            *(s32 *)(v + 0x33C) = D_L23_001DEC40 + n;
            *(f32 *)(v + 0x30) -= *(f32 *)(hit + 0x2C);
            v[0x167] = 0xFF;
            func_003C4A40(self, v + 0x160);
            d = *(f32 *)(v + 0x338) - *(f32 *)(v + 0x30);
            if (*(s32 *)(v + 0x398) != 0 ? d >= 50.0f : d >= 35.0f) {
                if (self[0x20] != 3) {
                    if (self[0x20] != 4) {
                    if (*(f32 *)(hit + 0x2C) >= 35.0f && *(u8 **)(hit + 0x20) != 0) {
                        vec_sub_ba(&dir, self + 0x10, *(u8 **)(hit + 0x20) + 0x10);
                        dir.z = 0.0f;
                        func_0038CF68(&dir, &dir, D_L23_001DE338 + D_L23_001DE328);
                        a = *(V4 *)(self + 0x10);
                        a.z += 1.0f;
                        vec_add_ab(&b, &a, &dir);
                        if (func_003D3CB0(&a, &b, 0, self, 0) != 0) {
                            vec_sub_ba(&dir, &D_L23_001E87A0, self + 0x10);
                            dir.z = 0.0f;
                            len = func_0038CEA8(&dir);
                            if (len > D_L23_001DE328)
                                func_0038CE20(&dir, &dir, (len - D_L23_001DE328) / len);
                            else
                                qzero(&dir);
                        } else {
                            func_0038CE20(&dir, &dir, D_L23_001DE338 / (D_L23_001DE338 + D_L23_001DE328));
                        }
                        *(f32 *)(v + 0x380) = func_0038CEA8(&dir);
                        *(f32 *)(v + 0x384) = func_0038D160(dir.x, dir.y);
                    }
                    func_L01_004450F0(self, 0xD, -1);
                    }
                }
            }
        }
        self[0xA8] = 0xFF;
    }
    func_L01_0044ABD0(self, v + 0x160);
    func_L01_00404A10(self, 3);
    if (self[0x20] != 0xE && *(f32 *)(v + 0x30) < 0.0f) {
        if (*(s32 *)(v + 0x300) == 3) {
            *(f32 *)(v + 0x30) = 1.0f;
            func_L01_004450F0(self, 4, 3);
        } else {
            func_L01_004450F0(self, 0xE, 4);
        }
    }
    ((Vars_3B34F8 *)v)->target = D_001A4BE0.hero_moby;
    dir = *(V4 *)(self + 0x10);
    a = *(V4 *)&D_001A4BE0.pickup_point;
    dir.z += D_L23_001DE32C;
    if (func_003D3CB0(&dir, &a, 0, self, 0) == 0 || D_L23_001E8798[0] == D_001A4BE0.hero_moby)
        *(s16 *)(v + 0x184) = 1;
    else
        *(s16 *)(v + 0x184) = 0;
    func_L23_003B44F8(self);
    if (self[0x95] == 3) {
        *(V4 *)(v + 0x190) = *(V4 *)&D_001A4BE0.pos;
        *(f32 *)(v + 0x198) += 5.0f;
        func_L03_0043BE98((int)self, v + 0x190, 5, 6, 1);
    } else {
        func_L03_0043BE98((int)self, v + 0x190, 5, 6, 0);
    }
    if (D_L23_001DE2D8 != 0)
        func_L01_00404808(func_L23_003B48D0, self);
}
/* localdecomp:end func_L23_003B34F8 */

/* localdecomp:start func_L23_003B3908 */
void func_0038CAD0(s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L23_001E1A40[];

void func_L23_003B3908(void *arg0) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L23_001E1A40, arg0 + 0x10) < 9216.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x5A;
    }
    *(u16 *)((u8 *)arg0 + 0x96) = (u16) ((*(u16 *)((u8 *)arg0 + 0x96)) + 1);
    *(s32 *)((u8 *)temp_s1 + 0x31C) = (s32) ((*(s32 *)((u8 *)temp_s1 + 0x31C)) + 1);
    func_0038CAD0(temp_s1 + 0x330);
}
/* localdecomp:end func_L23_003B3908 */

INCLUDE_ASM("asm/levels", func_L23_003B3998);

#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 pos[2]; s32 color0; s32 x24; s32 color1; } Sparks;
typedef struct { s32 id; u8 pad4[0xC]; u128_t pos; u8 path[0x10]; } Vars_3B5068;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 pad20[0xC];
    f32 scale;
    u8 pad30[4];
    u16 x34;
    u8 pad36[0x32];
    Vars_3B5068 *vars;
} Moby_3B5068;
typedef struct { u8 pad0[0x12]; s16 count; u8 pad14[0xC]; s32 *ids; u8 pad24[0xC]; } Path_3B4108;
typedef struct { s32 count; u8 pad4[0x1C]; Path_3B4108 paths[1]; } Paths_3B4108;
typedef struct { u8 pad0[0x30]; V4 pos; u8 pad40[0x40]; } Node_3B4108;
typedef struct { u8 pad0[0x20]; V4 pos; } Tgt_3B4108;
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
    u8 pad0[0xA8];
    s32 xA8;
    u8 padAC[0x2C8 - 0xAC];
    s32 x2C8;
    u8 pad2CC[0x310 - 0x2CC];
    u128_t x310;
    V4 x320;
} Vars_3B67B0;

INCLUDE_ASM("asm/levels", func_L23_003B3BB8);

/* localdecomp:start func_L23_003B3EA8 */
#include "common.h"
#include "vu0.h"
extern Paths_3B4108 *D_L23_001DED4C;
__asm__(".extern D_L23_001DED4C, 16");
extern Node_3B4108 *D_L23_001DF240;
__asm__(".extern D_L23_001DF240, 16");
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern int func_00382380(void *, int, int);

s32 func_L23_003B3EA8(u8 *m, s32 idx, f32 *out, void *a3, void *a4, s32 flag)
{
    V4 *home = a3;
    s32 *cur = a4;
    Path_3B4108 *path;
    V4 pos;
    V4 tgt;
    V4 dir;
    f32 d;
    f32 nd;
    f32 lim;
    s32 best;
    s32 i;
    s32 id;
    Node_3B4108 *e;

    if (idx >= 0 && idx < D_L23_001DED4C->count) {
    path = &D_L23_001DED4C->paths[idx];
    pos = *(V4 *)(m + 0x10);
    tgt = *(V4 *)out;
    d = func_L01_0040E570(&pos, &tgt);
    vec_sub_ab(&dir, &tgt, &pos);
    func_0038CE20(&dir, &dir, sqrt_asm(d));
    if (flag == 0 && func_003D3CB0(&pos, &tgt, 2, m, 0) == 0) {
        *cur = -1;
        *home = *(V4 *)out;
        return 1;
    }
    lim = d * 10.0f;
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
        if (func_L01_0040E570(out, home) > 1.0f)
            *(V4 *)out = *home;
        else
            return 0;
    } else {
        *(V4 *)out = D_L23_001DF240[path->ids[best]].pos;
    }
    }
    return 1;
}
/* localdecomp:end func_L23_003B3EA8 */

/* localdecomp:start func_L23_003B4108 */
extern Paths_3B4108 *D_L23_001DED4C;
__asm__(".extern D_L23_001DED4C, 16");
extern Node_3B4108 *D_L23_001DF240;
extern Tgt_3B4108 D_L23_001E8780;
__asm__(".extern D_L23_001E8780, 16");
#include "structs/hero.h"
extern struct Hero D_001A4BE0_3B4108;
__asm__(".extern D_001A4BE0_3B4108, 16");
extern V4 D_001A4C60;
__asm__(".extern D_001A4C60, 16");
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

void func_L23_003B4108(V4 *out, u8 *self, s32 idx, V4 from, f32 r1, f32 r2)
{
    u8 *v = *(u8 **)(self + 0x68);
    Path_3B4108 *path = &D_L23_001DED4C->paths[idx];
    Node_3B4108 *e;
    V4 a;
    V4 b;
    f32 r1sq = r1 * r1;
    f32 r2sq = r2 * r2;
    f32 lim = r2sq * 4.0f;
    f32 d;
    f32 dh;
    s32 best = -1;
    s32 i;

    for (i = 0; i < path->count; i++) {
        e = &D_L23_001DF240[path->ids[i]];
        d = func_L01_0040E570(&from, &e->pos);
        dh = func_L01_0040E570(&D_001A4C60, &e->pos);
        if (d < r2sq && r1sq < dh && d < lim) {
            a = D_001A4C60;
            a.z = *(f32 *)(v + 0x378) + 2.0f;
            b = e->pos;
            b.z = *(f32 *)(v + 0x378) + 2.0f;
            if (func_003D3CB0(&a, &b, 0, D_001A4BE0_3B4108.hero_moby, 0) == 0) {
                lim = d;
                best = path->ids[i];
            }
        }
    }
    if (best >= 0) {
        *out = D_L23_001DF240[best].pos;
        return;
    }
    a = *(V4 *)(self + 0x10);
    a.z = 0.0f;
    if (func_003D3CB0(self + 0x10, &a, 0, self, 0) != 0 && fabsf(D_L23_001E8780.pos.z - *(f32 *)(v + 0x378)) < 0.5f) {
        *out = D_L23_001E8780.pos;
        return;
    }
    a.x += 10.0f;
    if (func_003D3CB0(self + 0x10, &a, 0, self, 0) != 0 && fabsf(D_L23_001E8780.pos.z - *(f32 *)(v + 0x378)) < 0.5f) {
        *out = D_L23_001E8780.pos;
        return;
    }
    a.x -= 20.0f;
    if (func_003D3CB0(self + 0x10, &a, 0, self, 0) != 0 && fabsf(D_L23_001E8780.pos.z - *(f32 *)(v + 0x378)) < 0.5f) {
        *out = D_L23_001E8780.pos;
        return;
    }
    a.x += 10.0f;
    a.y += 10.0f;
    if (func_003D3CB0(self + 0x10, &a, 0, self, 0) != 0 && fabsf(D_L23_001E8780.pos.z - *(f32 *)(v + 0x378)) < 0.5f) {
        *out = D_L23_001E8780.pos;
        return;
    }
    a.y -= 20.0f;
    if (func_003D3CB0(self + 0x10, &a, 0, self, 0) != 0 && fabsf(D_L23_001E8780.pos.z - *(f32 *)(v + 0x378)) < 0.5f)
        *out = D_L23_001E8780.pos;
}
/* localdecomp:end func_L23_003B4108 */

/* localdecomp:start func_L23_003B44E8 */
void func_L23_003B44E8(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x390) = 0;
}
/* localdecomp:end func_L23_003B44E8 */

INCLUDE_ASM("asm/levels", func_L23_003B44F8);

INCLUDE_ASM("asm/levels", func_L23_003B48D0);

INCLUDE_ASM("asm/levels", func_L23_003B4AD0);

/* localdecomp:start func_L23_003B5068 */
extern u16 **D_L23_001D6764;
extern u8 *D_L23_001E001C;
__asm__(".extern D_L23_001E001C, 16");
extern u8 *D_L23_001E0014_3B5068;
__asm__(".extern D_L23_001E0014_3B5068, 4");
extern s16 D_L23_0023A3C0[];
extern Moby_3B5068 *D_L23_001DE410;
__asm__(".extern D_L23_001DE410, 4");
extern s32 D_L23_001DE134;
__asm__(".extern D_L23_001DE134, 4");
extern f32 func_0038CEA8(f32 *);
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003B5068(Moby_3B5068 *o)
{
    Vars_3B5068 *v = o->vars;
    u16 *p;
    u8 *e;
    u8 *found = 0;

    p = D_L23_001D6764[v->id];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
        e = D_L23_001E001C + ((*p & 0x7FFF) << 6);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[(D_L23_001E0014_3B5068 + ((*p & 0x7FFF) << 5))[0x1D]] == 0x1D21) {
            found = e;
            break;
        }
        p++;
    }
    o->pos = *(u128_t *)(found + 0x30);
    o->scale *= func_0038CEA8((f32 *)(found + 0x20));
    o->x34 |= 0x41;
    if (D_L23_001DE410 == 0)
        D_L23_001DE410 = o;
    v->pos = o->pos;
    D_L23_001DE134 = 0;
    func_L01_0044ED88(o, v->path, 0x10, -1, v->id, -1, 7, 0);
    o->x34 |= 0x41;
    func_L01_004450F0(o, 1, -1);
}
/* localdecomp:end func_L23_003B5068 */

/* localdecomp:start func_L23_003B51C0 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
extern f32 func_L01_0040E570(void *a, void *b);
extern s32 func_00382498(s32 a, s32 b);

u8 *func_L23_003B51C0(u8 *object, u8 *skip, f32 radius) {
    u8 *list[64];
    s32 n = 0;
    u16 *p;
    u8 *e;
    if (object == 0)
        return 0;
    {
        p = D_L23_0021C0E0[object[0x21]];
        while (object[0x21] != 0xFF && object[0x21] <= D_L23_001DF198 && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[object[0x21]])) {
            e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (n < 0x40 && e != skip && e[0x20] < 3 && func_L01_0040E570(object + 0x10, e + 0x10) < radius) {
                list[n++] = e;
            }
            p++;
        }
    }
    if (n > 0)
        return list[func_00382498(0, n - 1)];
    return 0;
}
/* localdecomp:end func_L23_003B51C0 */

INCLUDE_ASM("asm/levels", func_L23_003B5318);

/* localdecomp:start func_L23_003B54A0 */
extern u16 **D_L23_001D6764;
extern u8 *D_L23_001E0014;
extern s16 D_L23_0023A3C0[];

s32 func_L23_003B54A0(s32 arg0) {
    u16 *p;
    u8 *e;

    p = D_L23_001D6764[arg0];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[arg0])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0) {
            break;
        }
        if (D_L23_0023A3C0[e[0x1D]] == 0x1D21) {
            return 1;
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003B54A0 */

/* localdecomp:start func_L23_003B5538 */
__asm__(".extern D_L23_001DE3B0, 4");
__asm__(".extern D_L23_001DE420, 4");
__asm__(".extern D_L23_001DE424, 4");
__asm__(".extern D_L23_001DE428, 4");
extern s32 D_L23_001DE3B0;
extern s32 D_L23_001DE420;
extern f32 D_L23_001DE424;
extern f32 D_L23_001DE428;
extern Sparks D_L23_002A3A80;
extern void func_L01_0040C948(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L23_003B5538(void)
{
    s32 i;
    u32 color;
    f32 size;

    func_L01_0040C948(&D_L23_002A3A80, &D_L23_001DE3B0);
    for (i = 0; i < 2; i++) {
        color = func_0038DBD8(D_L23_002A3A80.color0, D_L23_002A3A80.color1, func_003824E0(0.0f, 1.0f)) | 0x60000000;
        size = D_L23_001DE428 * func_003824E0(0.75f, 1.25f);
        func_003D9508(&D_L23_002A3A80.pos[i], D_L23_001DE420, color, 1, size, D_L23_001DE424, func_003824E0(-3.1415927f, 3.1415927f));
    }
}
/* localdecomp:end func_L23_003B5538 */

/* localdecomp:start func_L23_003B5628 */
/* 4 diff */
#include "vu0.h"


extern s32 D_L23_001DE430[2];
__asm__(".extern D_L23_001DE430, 8");
extern f32 D_L23_001DE42C;
__asm__(".extern D_L23_001DE42C, 4");
extern void func_0038D570(void *, void *);
extern long func_00389598(s32);
extern void func_003D2DA0(Quad_3B5628 *, f32 *, s32);

void func_L23_003B5628(u8 *obj)
{
    f32 m[4][4] __attribute__((aligned(16)));
    Quad_3B5628 q __attribute__((aligned(16)));
    f32 s;

    func_0038D570(m, obj + 0xC0);
    *(u128_t *)m[3] = *(u128_t *)(obj + 0x10);
    m[3][3] = 1.0f;
    m[3][2] += 0.02f;
    q.tex = func_00389598(D_L23_001DE430[((s32)obj >> 8) % 2]);
    s = D_L23_001DE42C;
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
/* localdecomp:end func_L23_003B5628 */

/* localdecomp:start func_L23_003B5760 */
extern void func_L23_003B67B0(void *owner, void *p, int z, float f, float g);

void func_L23_003B5760(unsigned char *owner)
{
    func_L23_003B67B0(owner, owner + 0x10, 0, *(float *)(owner + 0xF8), 0.0f);
}
/* localdecomp:end func_L23_003B5760 */

/* localdecomp:start func_L23_003B5788 */
extern void func_L23_003B67B0(void *, void *, int, float, float);

void func_L23_003B5788(char *obj, float x) {
    func_L23_003B67B0(obj, *(char **)(obj + 0x68) + 0x320, 3, *(float *)(obj + 0xF8), x);
}
/* localdecomp:end func_L23_003B5788 */

INCLUDE_ASM("asm/levels", func_L23_003B57B8);

INCLUDE_ASM("asm/levels", func_L23_003B6390);

INCLUDE_ASM("asm/levels", func_L23_003B65F0);

/* localdecomp:start func_L23_003B67B0 */
/* MATCH: needs -mvu0-use-vf0-vf2 on L23_003B3BB8.c (vec_* helpers) */
#include "vu0.h"

extern f32 D_L23_001DE47C;
__asm__(".extern D_L23_001DE47C, 4");
extern s32 D_L23_001DE440;
__asm__(".extern D_L23_001DE440, 4");
extern f32 D_L23_001DE460[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE460, 4");
extern f32 D_L23_001DE448[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE448, 4");
extern f32 D_L23_001DE498;
__asm__(".extern D_L23_001DE498, 4");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_0045AA10(void *, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern s32 func_L01_0045AA30(u8 *, u128_t *);
extern void func_0038CE20(void *, void *, f32);

void func_L23_003B67B0(void *owner, void *p, int z, float f, float g)
{
    u8 *m = owner;
    Vars_3B67B0 *v = *(Vars_3B67B0 **)(m + 0x68);
    V4 d;
    u128_t e;
    f32 t;

    if (z != v->x2C8) {
        if (z == 2) {
            *(f32 *)(m + 0x48) = D_L23_001DE47C;
        }
        if (D_L23_001DE440 != 0) {
            *(f32 *)(m + 0x48) = 0.1f;
        }
        func_L01_0045BD78(m, D_L23_001DE460[z] * *(f32 *)(m + 0x48), D_L23_001DE448[z] * *(f32 *)(m + 0x48),
                          *(f32 *)(m + 0x48) * 0.0050265486f, *(f32 *)(m + 0x48) * 0.12566371f);
        if (z == 3) {
            v->x310 = *(u128_t *)(m + 0x10);
            v->xA8 = 0x514;
        } else {
            v->xA8 = 0;
        }
    }
    v->x2C8 = z;
    switch (z) {
    case 0:
        func_L01_0045AA10(m, f);
        func_L01_0045BD10(m, f);
        break;
    case 1:
    case 2:
        func_L01_0045A748(m, p);
        break;
    case 3:
        t = g + g - 1.0f;
        t = (1.0f - t * t) * D_L23_001DE498;
        vec_sub_ba(&d, &v->x320, &v->x310);
        func_0038CE20(&d, &d, g);
        vec_add_ba(&d, &d, &v->x310);
        d.z += t;
        vec_sub_ba(&e, &d, m + 0x10);
        func_L01_0045AA30(m, &e);
        break;
    }
}
/* localdecomp:end func_L23_003B67B0 */

/* localdecomp:start func_L23_003B6990 */
extern u8 D_001A4BE0[];
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L01_004395E0(void *);
extern void func_L03_00433C70(void *, Vec4 *, Vec4 *, s32, f32, f32, s32, s32, s32);

void func_L23_003B6990(u8 *obj) {
    u8 *vars = *(u8 **)(obj + 0x68);
    Vec4 a;
    Vec4 b;
    u8 inRange = 0;
    f32 d;

    if (*(s32 *)(vars + 0x2CC) == 1) {
        func_003C2F58(obj, 1, &a);
        func_003C2F58(obj, 2, &b);
        d = func_L01_004395E0(obj);
        inRange = (10.0f <= d && d <= 16.0f);
    }
    if (*(s32 *)(vars + 0x304) == 0 && *(u8 **)(D_001A4BE0 + 0x2808) == obj) {
        *(s32 *)(vars + 0x304) = 1;
    }
    if (inRange) {
        func_L03_00433C70(obj, &a, &b, 1, 1.0f, 1.0f, 0, 1, 0);
    }
}
/* localdecomp:end func_L23_003B6990 */

/* localdecomp:start func_L23_003B6A80 */
void func_0038CAD0(s32);

void func_L23_003B6A80(void *arg0) {
    s32 temp_s0;
    u16 temp_v1;

    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
    func_0038CAD0(temp_s0 + 0x2C0);
    func_0038CAD0(temp_s0 + 0x2C4);
    func_0038CAD0(temp_s0 + 0x300);
}
/* localdecomp:end func_L23_003B6A80 */

/* localdecomp:start func_L23_003B6AD0 */
/* 29 diff */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L03_0043FC00(s32, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern void func_L01_004443E8(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L23_003B6AD0(u8 *m)
{
    u8 *v = *(u8 **)(m + 0x68);
    Vec4 d;
    Vec4 p;

    d.v[0] = func_0038D098(*(f32 *)(v + 0x2F8)) * (*(f32 *)(v + 0x2FC) * 0.020000001f);
    d.v[1] = func_0038D0B0(*(f32 *)(v + 0x2F8)) * (*(f32 *)(v + 0x2FC) * 0.020000001f);
    d.v[2] = 0.0f;
    func_L03_0043FC00((s32)m, 0x3FF, (u8 *)&d, 3, 3, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0.05f);
    func_L01_004443E8(m, 0, 3);
    func_003A52A0(3, 0, m);
    p = *(Vec4 *)(m + 0x10);
    p.v[2] += 0.2f;
    func_L01_003303B8((u8 *)&p, 1, 10, 20, 0, 4, 20, 2, 0.2f, 0.0f, 0.0f, 0.0f,
        1, 1, 1, 0, 1, 1, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_003C2880(m);
}
/* localdecomp:end func_L23_003B6AD0 */

/* localdecomp:start func_L23_003B6C90 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
extern void func_L01_004450F0(void *a0, s32 a1, s32 a2);

void func_L23_003B6C90(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L23_0021C0E0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L23_001DF198 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[a0[0x21]])) {
        e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (*(s16 *)(e + 0xAA) == 0x1BE3 && a0[0x95] == 2) {
            func_L01_004450F0(e, 6, 3);
        }
        p++;
    }
}
/* localdecomp:end func_L23_003B6C90 */

/* localdecomp:start func_L23_003B6D78 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
__asm__(".extern D_L23_001DF198, 16");
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003B6D78(s32 a0) {
    u16 *p;
    u8 *e;

    p = D_L23_0021C0E0[a0];
    if ((a0 & 0xFF) == 0xFF || a0 > D_L23_001DF198 || p == 0) {
        return;
    }
    for (;;) {
        e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            return;
        }
        if (*(s16 *)(e + 0xAA) == 0x1BE3 && e[0x95] == 1) {
            func_L01_004450F0(e, 4, 2);
        }
        p++;
        if ((a0 & 0xFF) == 0xFF) {
            return;
        }
        if (a0 > D_L23_001DF198) {
            return;
        }
        if (p == 0) {
            return;
        }
        if ((s16)p[-1] >= 0) {
            continue;
        }
        if (p == D_L23_0021C0E0[a0]) {
            continue;
        }
        return;
    }
}
/* localdecomp:end func_L23_003B6D78 */

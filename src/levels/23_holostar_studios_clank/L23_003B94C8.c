#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { s32 w0; f32 f4; } V_3B9940;
typedef struct {
    u8 pad0[0x10]; u128_t pos; u8 b20; u8 pad21[0xB]; f32 f2C; u8 b30; u8 pad31; u16 h32; u16 h34;
    u8 pad36[0x68 - 0x36]; V_3B9940 *vars;
} M_3B9940;
typedef struct { u8 pad0[0x20]; u8 a20[0x10]; u128_t pos; } E_3B9940;
typedef struct { u8 pad0[0x4C]; u32 w4C; } T_3B9940;
typedef struct {
    s32 id;
    f32 x4;
    s32 x8;
    f32 xC;
    u8 pad10[0x10];
    u8 x20[0x10];
} Vars_3BA3E8;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 pad20[0xC];
    f32 scale;
    u8 pad30[4];
    u16 x34;
    u8 pad36[0x32];
    Vars_3BA3E8 *vars;
    u8 pad6C[0x54];
    V4 m[3];
} Moby_3BA3E8;
typedef struct {
    u8 pad0[0x38];
    long x38;
    u8 pad40[0x24];
    void (*update)(void);
} Spawn_3B94C8;

/* localdecomp:start func_L23_003B94C8 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern E_3B9940 *D_L23_001E001C;
__asm__(".extern D_L23_001E001C, 16");
extern u8 *D_L23_001E0014_3B9940;
__asm__(".extern D_L23_001E0014_3B9940, 4");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];
extern s32 D_L23_001DEC40;
extern s32 D_L23_001DE530;
__asm__(".extern D_L23_001DE530, 4");
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L23_003B9AC0();
extern void func_L01_00439880(void *, u16 *, s32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern Spawn_3B94C8 *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_002FFF00(void);
extern void func_L01_0044E820(void *, s32);
extern void func_003C2880(void *);

void func_L23_003B94C8(Moby_3BA3E8 *self)
{
    Vars_3BA3E8 *v = self->vars;
    u8 *t;
    f32 ang;
    V4 d;
    u16 id;
    s32 count;
    Spawn_3B94C8 *s;

    if (*(u8 *)((u8 *)self + 0x20) == 1) {
        u16 *p;
        E_3B9940 *m;
        u8 *e;

        t = (u8 *)func_L01_00447490(self, -1, 0);
        if (t != 0 && *(f32 *)(t + 0x2C) > 9.0f) {
            func_L01_004450F0(self, 2, -1);
        }
        p = D_L23_001D6764[v->id];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
            m = D_L23_001E001C + (*p & 0x7FFF);
            if (m == 0)
                break;
            e = D_L23_001E0014_3B9940 + ((*p & 0x7FFF) << 5);
            if (D_L23_0023A3C0[e[0x1D]] == 0x1D51) {
                if (fabs_asm(((V4 *)&m->pos)->z - ((V4 *)&self->pos)->z) > 0.01f) {
                    func_L01_004450F0(self, 2, -1);
                }
                if (((D_L23_001DEC40 >> 3) & 3) == 0) {
                    func_L01_00404808(func_L23_003B9AC0, self);
                    e[0x1E] |= 2;
                } else {
                    e[0x1E] &= ~2;
                }
            }
            p++;
        }
    }
    if (*(u8 *)((u8 *)self + 0x20) == 2) {
        u16 *p;
        u8 *e;

        func_L01_00439880(self, &id, &count);
        while (count > 0) {
            count--;
            ang = func_0038D160(((V4 *)&self->pos)->x - D_001A4BE0.pos.x, ((V4 *)&self->pos)->y - D_001A4BE0.pos.y);
            func_0038DAB8(ang, func_003824E0(-0.5235988f, 0.5235988f));
            d.x = func_0038D098(ang) * func_003824E0(0.3f, 0.50000006f);
            d.y = func_0038D0B0(ang) * func_003824E0(0.3f, 0.50000006f);
            d.z = 0.0f;
            d.w = 1.0f;
            s = func_L01_003F79D8(self, 2, *(s16 *)((u8 *)self + 0xAA), count, &self->pos, (u8 *)self + 0xF0, &d, 0xFF, 30.0f, 15.0f, 0xB4, 0, 0x80);
            s->update = func_L01_002FFF00;
            func_L01_0044E820(s, D_L23_001DE530);
            s->x38 = *(long *)((u8 *)D_001A4BE0.hero_moby + 0x38);
        }
        p = D_L23_001D6764[v->id];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
            e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
            if (e == 0)
                break;
            if (D_L23_0023A3C0[e[0x1D]] == 0x1D51) {
                e[0x1E] |= 4;
                break;
            }
            p++;
        }
        func_003C2880(self);
    }
}
/* localdecomp:end func_L23_003B94C8 */

/* localdecomp:start func_L23_003B98A8 */
s32 func_L23_003B98A8(s32 index) {
    u16 *p = D_L23_001D6764[index];
    u8 *e;

    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[index])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[e[0x1D]] == 0x1D51)
            return 1;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003B98A8 */

/* localdecomp:start func_L23_003B9940 */
extern u8 *func_003C24B0(s32, s32);
extern u32 func_L01_0044E7D8(s32);
extern void func_L01_0044E820(void *, s32);
extern f32 func_0038CEA8(void *);
extern s32 D_001A71A0[];
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern E_3B9940 *D_L23_001E001C;
__asm__(".extern D_L23_001E001C, 16");
extern u8 *D_L23_001E0014_3B9940;
__asm__(".extern D_L23_001E0014_3B9940, 4");
extern s16 D_L23_0023A3C0[];
extern T_3B9940 *D_L23_0023A1C0[];

void func_L23_003B9940(s32 arg0)
{
    M_3B9940 *o;
    V_3B9940 *v;
    u16 *p;
    E_3B9940 *m;
    u8 *e;

    o = (M_3B9940 *)func_003C24B0(0x1C23, 0x80);
    if (o == 0) {
        return;
    }
    v = o->vars;
    v->w0 = arg0;
    o->b20 = 1;
    o->b30 = 0xFF;
    o->h32 = 0xFF;
    func_L01_0044E820(o, func_L01_0044E7D8(D_001A71A0[0]));
    o->h34 |= 0x41;
    p = D_L23_001D6764[v->w0];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->w0])) {
        m = D_L23_001E001C + (*p & 0x7FFF);
        if (m == 0) {
            break;
        }
        e = D_L23_001E0014_3B9940 + ((*p & 0x7FFF) << 5);
        p++;
        if (D_L23_0023A3C0[e[0x1D]] == 0x1D51) {
            o->pos = m->pos;
            v->f4 = func_0038CEA8(m->a20);
            o->f2C *= v->f4;
            D_L23_0023A1C0[e[0x1D]]->w4C = 0x80404080;
            return;
        }
    }
}
/* localdecomp:end func_L23_003B9940 */

/* localdecomp:start func_L23_003B9AC0 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
__asm__(".extern D_L23_001DE540, 8");
__asm__(".extern D_L23_001DE550, 4");
__asm__(".extern D_L23_001DE554, 4");
__asm__(".extern D_L23_001DE558, 4");
__asm__(".extern D_L23_001DEC40_3B9AC0, 4");
extern f32 D_L23_001DE540[2];
extern s32 D_L23_001DE550;
extern u32 D_L23_001DE554;
extern f32 D_L23_001DE558;
extern s32 D_L23_001DEC40_3B9AC0;

void func_L23_003B9AC0(void *arg0) {
    V4 v;
    f32 *p;
    f32 s;

    p = *(f32 **)((u8 *)arg0 + 0x68);
    if (p != 0) {
        s = 1.0f - (f32)(D_L23_001DEC40_3B9AC0 % 8 - 4) * 0.25f;
        func_0038CE20(&v, D_L23_001DE540, p[1]);
        vec_add_ba(&v, &v, (u8 *)arg0 + 0x10);
        func_003D9508(&v, D_L23_001DE550, D_L23_001DE554, 1, D_L23_001DE558 * s, 0.3f, 0.0f);
    }
}
/* localdecomp:end func_L23_003B9AC0 */

INCLUDE_ASM("asm/levels", func_L23_003B9B88);

/* localdecomp:start func_L23_003BA3E8 */
extern s32 D_L23_001DE134;
__asm__(".extern D_L23_001DE134, 16");
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003BA3E8(Moby_3BA3E8 *self)
{
    Vars_3BA3E8 *v = self->vars;
    E_3B9940 *e = 0;
    E_3B9940 *m;
    u16 *p;
    f32 s;

    p = D_L23_001D6764[v->id];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
        m = D_L23_001E001C + (*p & 0x7FFF);
        if (m == 0)
            break;
        if (D_L23_0023A3C0[(D_L23_001E0014_3B9940 + ((*p & 0x7FFF) << 5))[0x1D]] == 0x1CCE) {
            e = m;
            break;
        }
        p++;
    }
    if (func_0038CEA8(e) > func_0038CEA8(e->pad0 + 0x10))
        s = func_0038CEA8(e);
    else
        s = func_0038CEA8(e->pad0 + 0x10);
    v->xC = s;
    self->scale *= s;
    self->pos = e->pos;
    func_0038CF68(&self->m[0], e->pad0, 1.0f);
    func_0038CF68(&self->m[1], e->pad0 + 0x10, 1.0f);
    func_0038CF68(&self->m[2], e->a20, 1.0f);
    v->x8 = -1;
    v->x4 = 400.11f;
    self->x34 |= 0x110;
    D_L23_001DE134 = 0;
    func_L01_0044ED88(self, v->x20, 8, -1, v->id, -1, 7, 0);
    self->x34 |= 0x41;
    func_L01_004450F0(self, 1, -1);
}
/* localdecomp:end func_L23_003BA3E8 */

/* localdecomp:start func_L23_003BA5D8 */
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];

s32 func_L23_003BA5D8(s32 index) {
    u16 *p = D_L23_001D6764[index];
    u8 *e;

    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[index])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[e[0x1D]] == 0x1CCE)
            return 1;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003BA5D8 */

INCLUDE_ASM("asm/levels", func_L23_003BA670);

/* localdecomp:start func_L23_003BAEC8 */
void func_L23_003BAEC8(Moby_3BA3E8 *self)
{
    Vars_3BA3E8 *v = self->vars;
    E_3B9940 *e = 0;
    E_3B9940 *m;
    u16 *p;
    f32 s;

    p = D_L23_001D6764[v->id];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
        m = D_L23_001E001C + (*p & 0x7FFF);
        if (m == 0)
            break;
        if (D_L23_0023A3C0[(D_L23_001E0014_3B9940 + ((*p & 0x7FFF) << 5))[0x1D]] == 0x1CCF) {
            e = m;
            break;
        }
        p++;
    }
    if (func_0038CEA8(e) > func_0038CEA8(e->pad0 + 0x10))
        s = func_0038CEA8(e);
    else
        s = func_0038CEA8(e->pad0 + 0x10);
    v->xC = s;
    self->scale *= s;
    self->pos = e->pos;
    func_0038CF68(&self->m[0], e->pad0, 1.0f);
    func_0038CF68(&self->m[1], e->pad0 + 0x10, 1.0f);
    func_0038CF68(&self->m[2], e->a20, 1.0f);
    v->x8 = -1;
    v->x4 = 400.11f;
    self->x34 |= 0x110;
    D_L23_001DE134 = 0;
    func_L01_0044ED88(self, v->x20, 8, -1, v->id, -1, 7, 0);
    self->x34 |= 0x41;
    func_L01_004450F0(self, 1, -1);
}
/* localdecomp:end func_L23_003BAEC8 */

/* localdecomp:start func_L23_003BB0B8 */
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];

s32 func_L23_003BB0B8(s32 idx)
{
    u16 *p = D_L23_001D6764[idx];
    u8 *e;

    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[idx])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[e[0x1D]] == 0x1CCF)
            return 1;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003BB0B8 */

/* localdecomp:start func_L23_003BB150 */
/* MATCH (file flags as is: L23_003B94C8.c) */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern E_3B9940 *D_L23_001E001C;
__asm__(".extern D_L23_001E001C, 16");
extern u8 *D_L23_001E0014_3B9940;
__asm__(".extern D_L23_001E0014_3B9940, 4");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];
extern V4 D_L23_001DE560[2] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE560, 4");
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L23_003BB700(u8 *m);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                          f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                          s32 h, s32 k);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);

void func_L23_003BB150(Moby_3BA3E8 *self)
{
    Vars_3BA3E8 *v = self->vars;
    u8 *t;
    u16 *p;
    u16 *p2;
    E_3B9940 *m;
    u8 *e;
    f32 ang;
    V4 d;
    V4 r;
    V4 o;
    s32 i;

    if (*(u8 *)((u8 *)self + 0x20) == 1) {
        t = (u8 *)func_L01_00447490(self, -1, 0);
        if (t != 0 && *(f32 *)(t + 0x2C) > 9.0f) {
            func_L01_004450F0(self, 2, -1);
        }
        p = D_L23_001D6764[v->id];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
            m = D_L23_001E001C + (*p & 0x7FFF);
            if (m == 0)
                break;
            if (D_L23_0023A3C0[(D_L23_001E0014_3B9940 + ((*p & 0x7FFF) << 5))[0x1D]] == 0x1CF8 &&
                fabs_asm(((V4 *)&m->pos)->z - ((V4 *)&self->pos)->z) > 0.01f) {
                func_L01_004450F0(self, 2, -1);
            }
            p++;
        }
        func_L01_00404808(func_L23_003BB700, self);
    }
    if (*(u8 *)((u8 *)self + 0x20) == 2) {
        ang = func_0038D160(((V4 *)&self->pos)->x - D_001A4BE0.pos.x, ((V4 *)&self->pos)->y - D_001A4BE0.pos.y);
        d.x = func_0038D098(ang) * 0.3f;
        d.y = func_0038D0B0(ang) * 0.3f;
        d.z = 0.0f;
        d.w = 1.0f;
        func_L01_00451FE0(self, 0xFF, &d, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        p2 = D_L23_001D6764[v->id];
        while (p2 != 0 && ((s16)p2[-1] >= 0 || p2 == D_L23_001D6764[v->id])) {
            e = D_L23_001E0014 + ((*p2 & 0x7FFF) << 5);
            if (e == 0)
                break;
            if (D_L23_0023A3C0[e[0x1D]] == 0x1CF8) {
                e[0x1E] |= 4;
                break;
            }
            p2++;
        }
        for (i = 0; i < 2; i++) {
            qzero(&r);
            func_0038D000(&o, &D_L23_001DE560[i], self->m);
            func_0038CE20(&o, &o, v->x4);
            func_L02_003E2E38(self, &o, 5.0f, &r, 0x28, 0, 0, 0.40000004f, 2.0f, 10.0f, 1.0f);
        }
        func_003A52A0(0, 0, self);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L23_003BB150 */

/* localdecomp:start func_L23_003BB510 */
extern u16 **D_L23_001D6764;
extern u8 *D_L23_001E0014;
extern s16 D_L23_0023A3C0[];

s32 func_L23_003BB510(s32 arg0) {
    u16 *p;
    u8 *e;

    p = D_L23_001D6764[arg0];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[arg0])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0) {
            break;
        }
        if (D_L23_0023A3C0[e[0x1D]] == 0x1CF8) {
            return 1;
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003BB510 */

/* localdecomp:start func_L23_003BB5A8 */
extern void func_003C48A8(void *, void *);

void func_L23_003BB5A8(s32 idx)
{
    M_3B9940 *o;
    V_3B9940 *v;
    u16 *p;
    E_3B9940 *m;
    u8 *e;

    o = (M_3B9940 *)func_003C24B0(0x1C2A, 0x80);
    if (o == 0) {
        return;
    }
    v = o->vars;
    v->w0 = idx;
    o->b20 = 1;
    o->b30 = 0xFF;
    o->h32 = 0xFF;
    func_L01_0044E820(o, func_L01_0044E7D8(D_001A71A0[0]));
    o->h34 |= 0x41;
    p = D_L23_001D6764[v->w0];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->w0])) {
        m = D_L23_001E001C + (*p & 0x7FFF);
        if (m == 0) {
            break;
        }
        e = D_L23_001E0014_3B9940 + ((*p & 0x7FFF) << 5);
        if (D_L23_0023A3C0[e[0x1D]] == 0x1CF8) {
            o->pos = m->pos;
            v->f4 = func_0038CEA8(m->a20);
            o->f2C *= v->f4;
            func_003C48A8(m, (u8 *)o + 0xF0);
            return;
        }
        p++;
    }
}
/* localdecomp:end func_L23_003BB5A8 */

/* localdecomp:start func_L23_003BB700 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 x20;
    u8 pad21[0xB];
    f32 x2C;
    u8 x30;
    u8 pad31[0x37];
    u8 *vars;
    u8 pad6C[0x3E];
    u16 xAA;
} Moby_3BB7C8;
extern vu0_v4 D_L23_002BC900[];
extern s32 D_L23_001DE580;
extern s32 D_L23_001DE584;
extern f32 D_L23_001DE588;
__asm__(".extern D_L23_001DE580, 4");
__asm__(".extern D_L23_001DE584, 4");
__asm__(".extern D_L23_001DE588, 4");
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);

void func_L23_003BB700(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 p;
    s32 i;
    if (v == 0) {
        return;
    }
    for (i = 0; i < 5; i++) {
        func_0038CE20(&p, &D_L23_002BC900[i], *(f32 *)(v + 4));
        func_0038D000(&p, &p, m + 0xC0);
        vec_add_ab(&p, &p, m + 0x10);
        func_003D9508(&p, D_L23_001DE580, D_L23_001DE584, 1, D_L23_001DE588, 0.3f, 0.0f);
    }
}
/* localdecomp:end func_L23_003BB700 */

/* localdecomp:start func_L23_003BB7C8 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern s32 D_L23_001DEC40;

Moby_3BB7C8 *func_L23_003BB7C8(s32 arg0, u128_t *pos, u128_t *arg2, s32 arg3, f32 scale, f32 arg5) {
    Moby_3BB7C8 *o;
    u8 *v;

    o = (Moby_3BB7C8 *)func_003C24B0(0x1C43, 0x80);
    if (o != 0) {
        o->x20 = 0;
        o->x30 = 0xFF;
        o->x2C = scale;
        v = o->vars;
        o->pos = *pos;
        *(u128_t *)(v + 0x40) = *arg2;
        *(s32 *)(v + 0x0) = arg0;
        *(s32 *)(v + 0x4) = D_L23_001DEC40 + 300;
        func_L01_00446748(v + 0x10, o, arg3, arg5);
        *(u16 *)(v + 0x2A) = o->xAA;
        *(u8 *)(v + 0x28) = 3;
        *(u8 *)(v + 0x29) = 3;
    }
    return o;
}
/* localdecomp:end func_L23_003BB7C8 */

INCLUDE_ASM("asm/levels", func_L23_003BB8A8);

/* localdecomp:start func_L23_003BBCB0 */
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3,
                              f32 e, f32 f, f32 g);
__asm__(".extern D_L23_001DE598, 4");
__asm__(".extern D_L23_001DE59C, 4");
extern f32 D_L23_001DE598;
extern u32 D_L23_001DE59C;

void func_L23_003BBCB0(Moby_3BB7C8 *m)
{
    u128_t a;
    u128_t b;
    u8 *v;
    f32 ang;

    ang = (f32)(D_L23_001DEC40 % 50) / 50.0f * 6.2831855f - 1.5707964f;
    v = m->vars;
    func_003D9508(&m->pos, 0x67, 0x40003080, 1, m->x2C, 0.0f, ang);
    func_003D9508(&m->pos, 0x67, 0x40005080, 1, m->x2C * 1.2f, 0.0f, -ang);
    func_003D9508(&m->pos, 0x68, 0x80002080, 1, m->x2C * 0.4f, 0.0f, ang);
    func_003D9508(&m->pos, 7, 0x40008080, 1, m->x2C * 0.4f, 0.0f, ang);
    func_0038CF68(&a, v + 0x40, m->x2C);
    vec_add_ba(&a, &m->pos, &a);
    func_0038CF68(&b, v + 0x40, m->x2C * -4.0f * D_L23_001DE598);
    vec_add_ba(&b, &m->pos, &b);
    func_L01_0040A8C0(&b, &a, 0x69, 1, D_L23_001DE59C, D_L23_001DE59C, D_L23_001DE59C, D_L23_001DE59C,
                      m->x2C * D_L23_001DE598, 1.0f, 0.0f);
}
/* localdecomp:end func_L23_003BBCB0 */

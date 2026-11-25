#include "common.h"

typedef struct {
    f32 value;
    s32 pad;
} Item_408D28;

/* declared by functions of L01_0040A8B8.c, which this file was cut from */
extern s32 func_0038DBD8(u32 a, u32 b, f32 f);

/* localdecomp:start func_L01_0040B3C0 */
#include "vu0.h"

typedef struct {
    f32 *p0;
    f32 *p1;
    f32 *dir;
    f32 scale;
    f32 lo;
    f32 hi;
    f32 *a18;
    f32 *a1c;
    f32 *a20;
    f32 *a24;
    u32 c28;
    u32 c2c;
} S_0040B3C0;

typedef struct {
    u8 pad[0x38];
    f32 r0;
    f32 r1;
    s32 x40;
    s32 x44;
    s32 x48;
} O_0040B3C0;

typedef void (*Fan_0040B3C0)(f32 *dir, f32 *a, f32 *b, f32 lo, f32 hi, f32 *p);
typedef void (*Draw_0040B3C0)(s32 a0, f32 *a1, f32 *a2, f32 f12, s32 a3, s32 t0, s32 t1);

extern u8 D_L01_001E29C0[];
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_0038DBD8(u32 a, u32 b, f32 f);
extern void func_L01_0040B138(u32 a, u32 b, Item_408D28 *items);
extern void func_L01_0040AF70(f32 *dir, f32 *a, f32 *b, f32 *p, f32 lo, f32 hi);
extern void func_L01_0040B1F0(s32 a0, f32 *a1, f32 *a2, f32 f12, s32 a3, s32 t0, s32 t1);
extern void func_L01_0040B300(s32 a0, f32 *a1, f32 *a2, s32 a3, s32 t0, s32 t1, f32 f12);

void func_L01_0040B3C0(O_0040B3C0 *o, S_0040B3C0 *arg) {
    S_0040B3C0 s = *arg;
    S_0040B3C0 *p = &s;
    f32 d0 = func_L01_0040E548(D_L01_001E29C0, p->p0);
    f32 d1 = func_L01_0040E548(D_L01_001E29C0, p->p1);
    f32 t0;
    f32 t1;
    s32 c0;
    s32 c1;

    if (d0 < o->r0 * o->r0 && d1 < o->r0 * o->r0) {
        func_L01_0040B138(p->c28, p->c28, (Item_408D28 *)o->x40);
        ((Fan_0040B3C0)func_L01_0040AF70)(p->dir, p->p0, p->p1, p->lo, p->hi, (f32 *)o->x40);
        func_L01_0040B1F0((s32)o, p->a18, p->a1c, p->scale, 1, o->x48, o->x40);
        func_L01_0040B138(p->c2c, p->c2c, (Item_408D28 *)o->x44);
        ((Fan_0040B3C0)func_L01_0040AF70)(p->dir, p->p0, p->p1, p->lo, p->hi, (f32 *)o->x44);
        func_L01_0040B1F0((s32)o, p->a20, p->a24, p->scale, 0, o->x48, o->x44);
        ((Fan_0040B3C0)func_L01_0040AF70)(p->dir, p->p0, p->p1, -p->lo, -p->hi, (f32 *)o->x44);
        func_L01_0040B1F0((s32)o, p->a20, p->a24, p->scale, 1, o->x48, o->x44);
        return;
    }
    if (o->r1 * o->r1 < d0 && o->r1 * o->r1 < d1) {
        func_L01_0040B138(p->c28, p->c28, (Item_408D28 *)o->x48);
        ((Fan_0040B3C0)func_L01_0040AF70)(p->dir, p->p0, p->p1, p->lo, p->hi, (f32 *)o->x48);
        ((Draw_0040B3C0)func_L01_0040B300)((s32)o, p->a18, p->a1c, p->scale, 1, o->x48, o->x48);
        return;
    }
    t0 = (sqrt_asm(d0) - o->r0) * (1.0f / (o->r1 - o->r0));
    if (t0 > 1.0f) {
        t0 = 1.0f;
    } else if (t0 < 0.0f) {
        t0 = 0.0f;
    }
    t1 = (sqrt_asm(d1) - o->r0) * (1.0f / (o->r1 - o->r0));
    if (t1 > 1.0f) {
        t1 = 1.0f;
    } else if (t1 < 0.0f) {
        t1 = 0.0f;
    }
    c0 = func_0038DBD8(0, p->c28, t0);
    c1 = func_0038DBD8(0, p->c28, t1);
    func_L01_0040B138(c0, c1, (Item_408D28 *)o->x48);
    ((Fan_0040B3C0)func_L01_0040AF70)(p->dir, p->p0, p->p1, p->lo, p->hi, (f32 *)o->x48);
    ((Draw_0040B3C0)func_L01_0040B300)((s32)o, p->a18, p->a1c, p->scale, 1, o->x48, o->x48);
    c0 = func_0038DBD8(p->c28, 0, t0);
    c1 = func_0038DBD8(p->c28, 0, t1);
    func_L01_0040B138(c0, c1, (Item_408D28 *)o->x40);
    ((Fan_0040B3C0)func_L01_0040AF70)(p->dir, p->p0, p->p1, p->lo, p->hi, (f32 *)o->x40);
    func_L01_0040B1F0((s32)o, p->a18, p->a1c, p->scale, 1, o->x48, o->x40);
    c0 = func_0038DBD8(p->c2c, 0, t0);
    c1 = func_0038DBD8(p->c2c, 0, t1);
    func_L01_0040B138(c0, c1, (Item_408D28 *)o->x44);
    ((Fan_0040B3C0)func_L01_0040AF70)(p->dir, p->p0, p->p1, p->lo, p->hi, (f32 *)o->x44);
    func_L01_0040B1F0((s32)o, p->a20, p->a24, p->scale, 0, o->x48, o->x44);
    ((Fan_0040B3C0)func_L01_0040AF70)(p->dir, p->p0, p->p1, -p->lo, -p->hi, (f32 *)o->x44);
    func_L01_0040B1F0((s32)o, p->a20, p->a24, p->scale, 1, o->x48, o->x44);
}
/* localdecomp:end func_L01_0040B3C0 */

/* localdecomp:start func_L01_0040B858 */
typedef struct {vu0_v4 from,to; s32 state,time;} W16Line;
typedef struct {
    s32 fadein, fadeout;
    f32 fade;
    s32 a, b;
    f32 width, widthScale, first;
    f32 p0, p1, p2, p3, step;
    s32 count;
    u8 pad[8];
    void *a40, *a44, *a48;
    s32 texture;
} W16Params;
typedef struct {f32 v[4];} W16Vals;
typedef struct {void *a, *b, *cross; f32 length, width, other; f32 *f0, *f1, *f2, *f3; s32 a28, b2c;} W16Draw;
extern W16Params D_L01_002C54B0;
extern s32 D_L01_001DFB40_0040B858;
__asm__(".extern D_L01_001DFB40_0040B858, 16");
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 4");
extern s32 D_001D6430_sda;
__asm__(".extern D_001D6430_sda, 4");
extern s32 D_001D6450_sda;
__asm__(".extern D_001D6450_sda, 4");
extern s32 D_001D6410_sda;
__asm__(".extern D_001D6410_sda, 4");
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_L01_0040F518(f32, f32);
extern void func_003A9440(s32, unsigned long);
extern unsigned long func_00389598(s32);
extern void func_0038C750(void);
extern void func_0038CE20(void *, void *, f32);

static __inline__ f32 g16(f32 x) {
    return (x * 5.0f + 2.0f) / 6.0f;
}

void func_L01_0040B858(W16Line *line, W16Params *p) {
    vu0_v4 dir, cam, cross, from, to;
    W16Draw draw;
    W16Vals vals;
    f32 t, wide, total, current, firstWide, seg, end, next, r;
    s32 elapsed;
    if (!line->state) return;
    if (!p) p = &D_L01_002C54B0;
    if (line->state == 2) {
        elapsed = D_L01_001DFB40_0040B858 - line->time;
        if (elapsed >= p->fadeout) { line->state = 0; line->time = 0; return; }
        wide = 1.0f - (f32)elapsed / (f32)p->fadeout;
    } else if (line->time > 0) {
        elapsed = D_L01_001DFB40 - line->time;
        if (elapsed >= p->fadein) { line->time = 0; wide = 1.0f; }
        else wide = (f32)elapsed / (f32)p->fadein * p->fade;
    } else wide = 1.0f;
    wide = wide * p->width;
    firstWide = wide * p->widthScale;
    vec_sub_ba(&dir, &line->to, &line->from);
    total = func_0038CEA8(&dir);
    current = 0.0f;
    func_0038CF68(&dir, &dir, 1.0f);
    vec_sub_ba(&cam, D_L01_001E29C0, &line->from);
    func_0038CE90(&cross, &cam, &dir);
    func_0038CF68(&cross, &cross, 1.0f);
    if (!p->a40) p->a40 = &D_001D6430_sda;
    if (!p->a44) p->a44 = &D_001D6450_sda;
    if (!p->a48) p->a48 = &D_001D6410_sda;
    r = func_L01_0040F518((f32)D_L01_001DFB40_0040B858, g16(1.0f / p->p0));
    t = g16(1.0f / p->p1);
    vals.v[1] = r / g16(1.0f / p->p0) - 8.0f;
    r = func_L01_0040F518((f32)D_L01_001DFB40_0040B858, t);
    t = g16(1.0f / (p->p0 * p->p2));
    vals.v[0] = r / g16(1.0f / p->p1) - 8.0f;
    r = func_L01_0040F518((f32)D_L01_001DFB40_0040B858, t);
    t = g16(1.0f / (p->p1 * p->p3));
    vals.v[3] = r / g16(1.0f / (p->p0 * p->p2)) - 8.0f;
    r = func_L01_0040F518((f32)D_L01_001DFB40_0040B858, t);
    t = r / g16(1.0f / (p->p1 * p->p3)) - 8.0f;
    draw.a = &from; draw.b = &to; draw.cross = &cross;
    draw.width = wide; draw.other = wide;
    draw.f0 = &vals.v[0]; draw.f1 = &vals.v[1]; draw.f2 = &vals.v[2]; draw.f3 = &vals.v[3];
    draw.a28 = p->a; draw.b2c = p->b;
    vals.v[2] = t;
    func_003A9440(8, 0);
    func_003A9440(20, 0xff9000000260UL);
    func_003A9440(71, 0x513f1);
    func_003A9440(6, func_00389598(p->texture));
    func_0038C750();
    if (p->first > 0.0f) {
        seg = p->first;
        if (total < seg) seg = total;
        from = line->from;
        func_0038CE20(&to, &dir, seg);
        current = seg + current;
        vec_add_ab(&to, &to, &line->from);
        draw.width = firstWide; draw.length = seg;
        func_L01_0040B3C0((O_0040B3C0 *)p, (S_0040B3C0 *)&draw);
        draw.width = wide;
    }
    while (current < total - 0.05f) {
        seg = total - current;
        if (p->step * (f32)p->count < seg) seg = p->step * (f32)p->count;
        func_0038CE20(&from, &dir, current);
        next = current + seg;
        vec_add_ab(&from, &from, &line->from);
        func_0038CE20(&to, &dir, next);
        current = next;
        vec_add_ab(&to, &to, &line->from);
        draw.length = seg;
        func_L01_0040B3C0((O_0040B3C0 *)p, (S_0040B3C0 *)&draw);
    }
    func_003A9440(71, 0x5360b);
}
/* localdecomp:end func_L01_0040B858 */

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

INCLUDE_ASM("asm/levels", func_L01_0040B858);

#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void *func_003EF110();
extern void func_003EE160(void *p, s32, s32);
extern void *func_003EE760();
extern void func_003EE408(u8 *, f32, f32, f32, f32);
extern void *malloc(s32, s32) __asm__("func_003F2388");
/* --- end of declarations from other files --- */

/* declarations of 3ED988.c's earlier functions */
extern void func_003EDB68(void *, f32, f32);
typedef struct V_3E8670 { u8 pad[0x14]; s32 (*fn)(void *, s32); } V_3E8670;
typedef struct { u8 pad[8]; V_3E8670 *vt; } O_3E8670;
extern s32 func_003EDAF8();
typedef struct { u8 pad[0x18]; void (*fn)(void *, s32); } V_3E86C8;
typedef struct { u8 pad[8]; V_3E86C8 *vt; } S_3E86C8;
extern s32 func_003EDAF8(void *, s32);
extern char D_001D9670[];
extern f32 D_001D9698;
extern f32 D_001D969C;
extern s32 *func_003E6C08();
void **func_003E6CC0(s32 *, s32);
extern s32 func_003EDAF8(void *p, s32 mask);
extern void func_003EDB40(void *p, s32 *a, s32 *b);
extern void func_003EDB68(void *p, f32 x, f32 y);
extern s32 func_003EDBA8(s32 p, s32 k);
extern s32 func_003EDBD8(O_3E8670 *a, s32 b);
extern void func_003EDC30(S_3E86C8 *a, s32 b);
extern void func_003EDC80(void *arg0, s32 arg1);
extern void func_003EDCF0(void *a, f32 *b);
extern void func_003EDD40(f32 a, f32 b, f32 c, f32 d);

/* localdecomp:start func_003EE160 */
void func_003EE160(void *p, s32 m, s32 set) {
    if (set != 0) {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) |= m;
    } else {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) &= ~m;
    }
}
/* localdecomp:end func_003EE160 */

/* localdecomp:start func_003EE190 */
s32 func_003EE190(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    return (*(u8 *)((u8 *)p + 0x4c) & a1) != 0;
}
/* localdecomp:end func_003EE190 */

typedef struct { u8 b[16]; } B16_3E8C40;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E8C40;
extern s32 func_0011A264(void *, s32, s32);
/* localdecomp:start func_003EE1A8 */
/* log: from boot_elf's func_003EE560 (its twin), callees renamed, body externs moved to file scope */
extern void func_003EDB40(void *, s32 *, s32 *);
extern s32 func_003EDAF8(void *, s32);
void func_003EE1A8(O_3E8C40 *o, f32 *rect, f32 *out, s32 align)
{
    f32 vertical_scale = 2.0f;
    f32 vertical_anchor = 0.0f;
    f32 horizontal_scale = 2.0f;
    f32 horizontal_anchor = 0.0f;
    s32 horizontal, vertical;
    f32 temporary[4];
    f32 x, y, height, dx, dy;
    if (align) do {
        horizontal = 0;
        vertical = 0;
        func_003EDB40(o, &horizontal, &vertical);
        if (horizontal != 3) {
            if (horizontal == 1) {
                horizontal_anchor = 1.0f;
            } else {
                horizontal_scale = 2.0f;
                horizontal_anchor = -1.0f;
            }
        }
        if (vertical != 3) {
            if (vertical == 2) {
                vertical_scale = 2.0f;
                vertical_anchor = -1.0f;
            } else {
                vertical_scale = 2.0f;
                vertical_anchor = 1.0f;
            }
        }
    } while (0);
    x = o->f10;
    x = (rect[2] - rect[0]) * x + rect[0];
    y = o->f14;
    y = (rect[3] - rect[1]) * y + rect[1];
    out[0] = x - o->f18 * ((horizontal_anchor + 1.0f) / horizontal_scale);
    height = o->f1C;
    out[1] = (y - height / vertical_scale) + (vertical_anchor * height) / vertical_scale;
    out[2] = out[0] + o->f18;
    out[3] = out[1] + o->f1C;
    if (func_003EDAF8(o, 0x40)) {
        dx = o->f20;
        dy = o->f24;
        func_0011A264(temporary, 0, 16);
        *(B16_3E8C40 *)temporary = *(B16_3E8C40 *)out;
        temporary[0] += dx;
        temporary[2] += dx;
        temporary[1] += dy;
        temporary[3] += dy;
        out[0] = temporary[0] < out[0] ? temporary[0] : out[0];
        out[2] = out[2] < temporary[2] ? temporary[2] : out[2];
        out[3] = out[3] < temporary[3] ? temporary[3] : out[3];
        out[1] = temporary[1] < out[1] ? temporary[1] : out[1];
    }
}
/* localdecomp:end func_003EE1A8 */
TEXT_PADDING(2);

/* localdecomp:start func_003EE408 */
void func_003EE408(u8 *p, f32 a, f32 b, f32 c, f32 d) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x50) = a;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x58) = b;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x54) = c;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x5C) = d;
}
/* localdecomp:end func_003EE408 */

typedef struct O_3E8EC8 O_3E8EC8F;
typedef struct { u8 p0[0x20]; void (*f20)(O_3E8EC8F *, s32, f32 *, s32); } V_3E8EC8;
typedef struct { s32 *tbl[1]; } L_3E8EC8;
typedef struct { u8 p0[0x48]; s32 f48; } L2_3E8EC8;
typedef struct O_3E8EC8 { u8 p0[8]; V_3E8EC8 *f8; u8 pC[0x20]; struct { s32 *e[1]; u8 pad[0x44]; s32 n; } *f2C; } O_3E8EC8;
extern void func_003EDCF0();
extern void func_003EDD40(f32, f32, f32, f32);
/* localdecomp:start func_003EE430 */
extern s32 func_003EE190();
void func_003EE430(O_3E8EC8 *self, s32 b) {
    f32 v[4];
    s32 i;
    self->f8->f20(self, b, v, 1);
    func_003EDCF0(self, v);
    if (func_003EE190(self, 1)) {
        func_003EDD40(v[0], v[1], v[2], v[3]);
    }
    for (i = 0; i < self->f2C->n; i++) {
        func_003EDC80(((s32 **)self->f2C)[i], b);
    }
    if (func_003EE190(self, 1)) {
        func_003EDD40(0.0f, 0.0f, 1.0f, 1.0f);
    }
}
/* localdecomp:end func_003EE430 */

/* localdecomp:start func_003EE518 */
typedef struct { u8 b[16]; } B16_3E8FB0;
typedef struct { u8 p0[8]; s32 (**vt)(); } C_3E8FB0;
typedef struct { s32 *e[1]; u8 p0[0x40]; C_3E8FB0 *f44; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E8FB0;
typedef struct { u8 p0[0x2C]; S_3E8FB0 *f2C; } O_3E8FB0;
extern s32 func_003EDBD8();
s32 func_003EE518(O_3E8FB0 *self, f32 *b) {
    B16_3E8FB0 t;
    S_3E8FB0 *s;
    f32 dx, dy;
    s32 i;
    s = self->f2C;
    t = *(B16_3E8FB0 *)b;
    dx = b[2] - b[0];
    dy = b[3] - b[1];
    ((f32 *)&t)[0] = dx * s->f50 + b[0];
    ((f32 *)&t)[1] = dy * s->f54 + b[1];
    ((f32 *)&t)[2] = dx * s->f58 + b[0];
    ((f32 *)&t)[3] = dy * s->f5C + b[1];
    if (s->f44 != 0) {
        ((s32 (*)())(s->f44->vt[0x14 / 4]))(s->f44, &t, s);
    } else {
        for (i = 0; i < self->f2C->n; i++) {
            func_003EDBD8(((s32 **)self->f2C)[i], b);
        }
    }
    return 1;
}
/* localdecomp:end func_003EE518 */

/* localdecomp:start func_003EE630 */
typedef struct { u8 b[16]; } B16_3E90C8;
typedef struct { s32 *e[1]; u8 p0[0x44]; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E90C8;
typedef struct { u8 p0[0x2C]; S_3E90C8 *f2C; } O_3E90C8;
extern void func_003EDC30();
void func_003EE630(O_3E90C8 *self, f32 *b) {
    B16_3E90C8 t;
    S_3E90C8 *s;
    f32 dx, dy;
    s32 i;
    s = self->f2C;
    t = *(B16_3E90C8 *)b;
    dx = b[2] - b[0];
    dy = b[3] - b[1];
    ((f32 *)&t)[0] = dx * s->f50 + b[0];
    ((f32 *)&t)[1] = dy * s->f54 + b[1];
    ((f32 *)&t)[2] = dx * s->f58 + b[0];
    ((f32 *)&t)[3] = dy * s->f5C + b[1];
    for (i = 0; i < self->f2C->n; i++) {
        func_003EDC30(((s32 **)self->f2C)[i], b);
    }
}
/* localdecomp:end func_003EE630 */

/* localdecomp:start func_003EE720 */
s32 func_003EE720(void) {
    return 7;
}
/* localdecomp:end func_003EE720 */

/* localdecomp:start func_003EE728 */
s32 func_003EE728(s32 p, s32 k) {
    if (k == 7) {
        return 1;
    }
    return func_003EDBA8(p, k);
}
/* localdecomp:end func_003EE728 */

LINKER_REMNANT("asm/remnants", func_003EE758);

extern unsigned char D_001D9738[];
INCLUDE_ASM("asm/nonmatchings/text", func_003EE760);

/* localdecomp:start func_003EE7C8 */
__asm__(".extern D_001D9730_g, 4");
extern s32 D_001D9730_g;
extern s32 func_003EDBA8(s32, s32);
s32 func_003EE7C8(s32 p, s32 k) {
    if (k != D_001D9730_g) return func_003EDBA8(p, k);
    return 1;
}
/* localdecomp:end func_003EE7C8 */

/* localdecomp:start func_003EE7F8 */
extern s32 D_001D9730_g;
s32 func_003EE7F8(void) { return D_001D9730_g; }
/* localdecomp:end func_003EE7F8 */

/* localdecomp:start func_003EE800 */
void func_003EE800(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003EE800 */

/* localdecomp:start func_003EE840 */
typedef struct { u32 c0, c1, c2, c3; } Colors_003EE840;     /* one colour per corner */
typedef struct O_003EE840 O_003EE840;
typedef struct { u8 p0[0x20]; void (*rect)(O_003EE840 *, s32, f32 *, s32); } V_003EE840;
struct O_003EE840 {
    u8 p0[8];
    V_003EE840 *vt;
    u8 pC[4];
    f32 mid_x, mid_y;               /* 0x10: the bars stop at the centre */
    u8 p18[8];
    f32 shadow_dx, shadow_dy;       /* 0x20 */
    u32 shadow_color;               /* 0x28 */
    u8 p2C[4];
    u32 color;                      /* 0x30 */
    f32 width, height;              /* 0x34: the bars' thickness */
};
extern void func_003EDCF0(void *, f32 *);
extern void func_003E58C0(f32 *p, f32 lo, f32 hi);
extern f32 D_001D9698 __attribute__((section(".rodata")));
extern f32 D_001D969C __attribute__((section(".rodata")));
/* func_0038C310 with its last parameter as the by-value colours it is (EABI passes them by reference) */
extern void func_0038C310_003EE840(s32, s32, s32, s32, unsigned long, Colors_003EE840);

static __inline__ Colors_003EE840 colors_003EE840(u32 c) {
    return (Colors_003EE840){ c, c, c, c };
}

static __inline__ void fill_003EE840(Colors_003EE840 c, f32 x0, f32 y0, f32 x1, f32 y1) {
    func_0038C310_003EE840((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C),
                           (s32)(x1 * D_001D9698), (s32)(y1 * D_001D969C), 0, c);
}

void func_003EE840(O_003EE840 *o, s32 a) {
    f32 v[4];

    o->vt->rect(o, a, v, 1);
    func_003EDCF0(o, v);
    {
        f32 x0 = v[0];
        f32 y0 = v[1] + o->height;
        f32 x1 = x0 + o->width;
        f32 y1 = v[3] - o->height;
        func_003E58C0(&y0, v[1], o->mid_y);
        func_003E58C0(&x1, v[0], o->mid_x);
        func_003E58C0(&y1, o->mid_y, v[3]);
        if (func_003EDAF8(o, 0x40)) {
            f32 dx = o->shadow_dx;
            f32 dy = o->shadow_dy;
            fill_003EE840(colors_003EE840(o->shadow_color), x0 + dx, y0 + dy, x1 + dx, y1 + dy);
        }
        fill_003EE840((Colors_003EE840){ o->color, o->color, o->color, o->color }, x0, y0, x1, y1);
    }
    {
        f32 x0 = v[2] - o->width;
        f32 y0 = v[1] + o->height;
        f32 x1 = v[2];
        f32 y1 = v[3] - o->height;
        func_003E58C0(&y0, v[1], o->mid_y);
        func_003E58C0(&x0, o->mid_x, v[2]);
        func_003E58C0(&y1, o->mid_y, v[3]);
        if (func_003EDAF8(o, 0x40)) {
            f32 dx = o->shadow_dx;
            f32 dy = o->shadow_dy;
            fill_003EE840(colors_003EE840(o->shadow_color), x0 + dx, y0 + dy, x1 + dx, y1 + dy);
        }
        fill_003EE840((Colors_003EE840){ o->color, o->color, o->color, o->color }, x0, y0, x1, y1);
    }
    {
        f32 x0 = v[0];
        f32 y0 = v[1];
        f32 x1 = v[2];
        f32 y1 = y0 + o->height;
        func_003E58C0(&y1, y0, o->mid_y);
        if (func_003EDAF8(o, 0x40)) {
            f32 dx = o->shadow_dx;
            f32 dy = o->shadow_dy;
            fill_003EE840(colors_003EE840(o->shadow_color), x0 + dx, y0 + dy, x1 + dx, y1 + dy);
        }
        fill_003EE840((Colors_003EE840){ o->color, o->color, o->color, o->color }, x0, y0, x1, y1);
    }
    {
        f32 x0 = v[0];
        f32 y0 = v[3] - o->height;
        f32 x1 = v[2];
        f32 y1 = v[3];
        func_003E58C0(&y0, o->mid_y, v[3]);
        if (func_003EDAF8(o, 0x40)) {
            f32 dx = o->shadow_dx;
            f32 dy = o->shadow_dy;
            fill_003EE840(colors_003EE840(o->shadow_color), x0 + dx, y0 + dy, x1 + dx, y1 + dy);
        }
        fill_003EE840((Colors_003EE840){ o->color, o->color, o->color, o->color }, x0, y0, x1, y1);
    }
}
/* localdecomp:end func_003EE840 */

typedef struct { u8 b[16]; } B16_3E98B8;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E98B8;
extern s32 func_0011A264(void *, s32, s32);
/* localdecomp:start func_003EEE20 */
/* US draft of func_003EEE20 (rac3-uya-decomp func_003E98B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


typedef struct { u8 b[16]; } B16_3E98B8_3EEE20;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E98B8_3EEE20;
extern s32 func_0011A264(void *, s32, s32);
void func_003EEE20(O_3E98B8_3EEE20 *o, f32 *p, f32 *out, s32 flag) {
    f32 sy = 2.0f;
    f32 ay = 0.0f;
    f32 sx = 2.0f;
    f32 ax = 0.0f;
    f32 t[4];
    f32 x0, y0, h, dx, dy;
    s32 k1, k2;
    if (flag) do {
        k1 = 0;
        k2 = 0;
        func_003EDB40(o, &k1, &k2);
        if (k1 != 3) {
            if (k1 == 1) {
                ax = 1.0f;
            } else {
                sx = 2.0f;
                ax = -1.0f;
            }
        }
        if (k2 != 3) {
            if (k2 == 2) {
                sy = 2.0f;
                ay = -1.0f;
            } else {
                sy = 2.0f;
                ay = 1.0f;
            }
        }
    } while (0);
    x0 = o->f10;
    x0 = (p[2] - p[0]) * x0 + p[0];
    y0 = o->f14;
    y0 = (p[3] - p[1]) * y0 + p[1];
    out[0] = (x0 - o->f18 / sx) + (ax * o->f18) / sx;
    h = o->f1C;
    out[1] = (y0 - h / sy) + (ay * h) / sy;
    out[2] = out[0] + o->f18;
    out[3] = out[1] + o->f1C;
    if (func_003EDAF8(o, 0x40)) {
        dx = o->f20;
        dy = o->f24;
        func_0011A264(t, 0, 0x10);
        *(B16_3E98B8_3EEE20 *)t = *(B16_3E98B8_3EEE20 *)out;
        t[0] += dx;
        t[2] += dx;
        t[1] += dy;
        t[3] += dy;
        out[0] = (t[0] < out[0]) ? t[0] : out[0];
        out[2] = (out[2] < t[2]) ? t[2] : out[2];
        out[3] = (out[3] < t[3]) ? t[3] : out[3];
        out[1] = (t[1] < out[1]) ? t[1] : out[1];
    }
}
/* localdecomp:end func_003EEE20 */

/* localdecomp:start func_003EF080 */
s32 func_003EF080(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x2C);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003EF080 */

LINKER_REMNANT("asm/remnants", func_003EF0B0);

/* localdecomp:start func_003EF0B8 */
extern char D_001D9670[];
extern s32 func_003F2380();
void func_003EF0B8(u8 *p, s32 f) {
    *(void **)(p + 8) = D_001D9670;
    if (f & 1) func_003F2380(p);
}
/* localdecomp:end func_003EF0B8 */

LINKER_REMNANT("asm/remnants", func_003EF0E8);

/* localdecomp:start func_003EF110 */
extern void func_003EF1B8();
extern void func_003EF288(void *, s32, s32, s32, s32);
extern void func_003ED988_003EF110(void);
extern u8 D_001D9768[];
void *func_003EF110(void *arg0)
{
  void **new_var;
  func_003ED988_003EF110();
  *((s32 *) (((u8 *) arg0) + 0x2C)) = 0;
  *((s32 **) (((u8 *) arg0) + 8)) = D_001D9768;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x38)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x3C)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x40)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x44)) = 0x80808080;
  func_003EF288(arg0, 0x80F00000, 0x80F00000, 0x80F00000, 0x80F00000);
  *((s32 *) (((u8 *) arg0) + 0x50)) = 0;
  *((f32 *) (((u8 *) arg0) + 0x18)) = 0.5f;
  *((f32 *) (((u8 *) arg0) + 0x1C)) = 0.5f;
  func_003EF1B8(arg0, 0);
  new_var = &arg0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4C)) = 0xA;
  *((s16 *) (((u8 *) (*new_var)) + 0x4A)) = 0;
  *((s32 *) (((u8 *) (*new_var)) + 0x34)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4E)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4D)) = 0;
  return *new_var;
}
/* localdecomp:end func_003EF110 */

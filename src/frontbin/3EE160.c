#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void *func_003EF110();
extern void *func_003EFF18();
void func_003EFE98(void *, s32);
extern void func_003EFFE8(void *p, f32, f32);
extern void func_003EFFA0(u8 *p, u8, s32);
extern void func_003EE160(void *p, s32, s32);
extern s32 func_003F0BE8(u8 *arg0, s32, s32);
extern void *func_003EE760();
extern void *func_003F0708();
extern void func_003F09C8();
extern void func_003F0A48(void *, s32, s16, s16, s32);
extern void func_003F0980(void *, s32);
extern void func_003F0AC0(u8 *, s32, f32, f32);
extern void func_003F0A30(void *, f32);
extern void func_003F0A70(void *, f32);
extern s32 func_003F0A88();
extern s32 func_003F0AA0();
extern void func_003F0CD8(void *, s32);
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

/* localdecomp:start func_003EF1B8 */
typedef struct S_003E9C50_obj S_003E9C50_obj;
typedef struct {
    u8 pad0[8];
    void (*f8)(S_003E9C50_obj *, s32);
    void (*fC)(S_003E9C50_obj *);
} S_003E9C50_vt;
struct S_003E9C50_obj { s32 f0; S_003E9C50_vt *vt; };
typedef struct {
    u8 pad0[0xC]; s32 fC; u8 pad10[0x38]; u16 f48; u8 pad4A[4]; s8 f4E; u8 pad4F; S_003E9C50_obj *f50;
} S_003E9C50;

void func_003EF1B8(S_003E9C50 *arg0, s32 arg1) {
    S_003E9C50_obj *o;

    if (arg0->f48 != arg1) {
        arg0->f48 = arg1;
        if ((u16)arg1 != 0) {
            o = arg0->f50;
            if (o != 0) {
                if ((o->f0 ^ 4) == 0) {
                    o->vt->fC(o);
                }
                if (arg0->fC & 0x8000) {
                    arg0->f4E = 4;
                    return;
                }
                arg0->f50->vt->f8(arg0->f50, arg1 - 1);
            }
        }
    }
}
/* localdecomp:end func_003EF1B8 */

/* localdecomp:start func_003EF250 */
__asm__(".extern D_001D9760_g, 4");
extern s32 D_001D9760_g;
extern s32 func_003EDBA8(s32, s32);
s32 func_003EF250(s32 p, s32 k) {
    if (k != D_001D9760_g) return func_003EDBA8(p, k);
    return 1;
}
/* localdecomp:end func_003EF250 */

/* localdecomp:start func_003EF280 */
extern s32 D_001D9760_g;
s32 func_003EF280(void) {
    return D_001D9760_g;
}
/* localdecomp:end func_003EF280 */

/* localdecomp:start func_003EF288 */
void func_003EF288(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x38) = a1;
    *(s32 *)((u8 *)a0 + 0x3c) = a2;
    *(s32 *)((u8 *)a0 + 0x40) = a3;
    *(s32 *)((u8 *)a0 + 0x44) = a4;
}
/* localdecomp:end func_003EF288 */

/* localdecomp:start func_003EF2A0 */
void func_003EF2A0(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003EF2A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EF2E0);

typedef struct { s32 f0; s32 *vt4; } OB_3EA078;
typedef struct { u8 p0[8]; s32 f8; s32 fC; } PP_3EA078;
typedef struct { u8 pad0[0x20]; f32 f20, f24; s32 f28; f32 f2C; u8 pad1[0x8]; s32 f38; u8 pad2[0x14]; OB_3EA078 *f50; } O_3EA078;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern unsigned long func_0039ACA8(s32);
extern void func_0038B120(s32, s32, s32, s32, s32, s32, s32, s32, f32, unsigned long, unsigned long);
/* localdecomp:start func_003EF5E0 */
extern s32 func_003EDAF8();
extern f32 D_001D9698 __attribute__((section(".rodata")));
extern f32 D_001D969C __attribute__((section(".rodata")));
s32 func_003EF5E0(O_3EA078 *o, f32 *r) {
    OB_3EA078 *ob = o->f50;
    s32 k38;
    if ((ob->f0 ^ 2) == 0) {
        k38 = o->f38;
        if (func_003EDAF8(o, 0x40)) {
            f32 x1, y1, x0, y0, ox, oy, sc, w, h;
            s32 a, b, k28;
            unsigned long res;
            PP_3EA078 *pp;
            ox = o->f20;
            oy = o->f24;
            k28 = o->f28;
            pp = (PP_3EA078 *)((s32 (*)())*(s32 *)((u8 *)ob->vt4 + 0x18))(ob);
            x0 = r[0] + ox;
            y0 = r[1] + oy;
            x1 = r[2] + ox;
            y1 = r[3] + oy;
            sc = o->f2C;
            a = pp->f8;
            b = pp->fC;
            w = x1 - x0;
            h = y1 - y0;
            res = func_0039ACA8((s32)pp);
            func_0038B120((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C), (s32)(w * D_001D9698), (s32)(h * D_001D969C), 0, 0, a, b, sc, (unsigned long)(u32)k28, res);
        }
        {
            f32 x1, y1, x0, y0, sc;
            s32 a, b;
            unsigned long res;
            PP_3EA078 *pp;
            pp = (PP_3EA078 *)((s32 (*)())*(s32 *)((u8 *)ob->vt4 + 0x18))(ob);
            x0 = r[0];
            y0 = r[1];
            x1 = r[2] - x0;
            y1 = r[3] - y0;
            sc = o->f2C;
            a = pp->f8;
            b = pp->fC;
            res = func_0039ACA8((s32)pp);
            func_0038B120((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C), (s32)(x1 * D_001D9698), (s32)(y1 * D_001D969C), 0, 0, a, b, sc, (unsigned long)(u32)k38, res);
        }
    }
    return 0;
}
/* localdecomp:end func_003EF5E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EF7F8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031CC30);

typedef struct { u8 b[16]; } B16_3EA648;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EA648;
extern s32 func_0011A264(void *, s32, s32);
/* localdecomp:start func_003EFBB0 */
/* US draft of func_003EFBB0 (rac3-uya-decomp func_003EA648, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


typedef struct { u8 b[16]; } B16_3EA648_3EFBB0;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EA648_3EFBB0;
extern s32 func_0011A264(void *, s32, s32);
extern s32 func_003EDAF8(void *, s32);
extern void func_003EDB40(void *, s32 *, s32 *);
void func_003EFBB0(O_3EA648_3EFBB0 *o, f32 *p, f32 *out, s32 flag) {
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
        *(B16_3EA648_3EFBB0 *)t = *(B16_3EA648_3EFBB0 *)out;
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
/* localdecomp:end func_003EFBB0 */

/* localdecomp:start func_003EFE10 */
s32 func_003EFE10(void *arg0, s32 arg1) {
    s32 (*temp_v0)(s32);
    s32 temp_v1;
    void *temp_a0;

    if ((*(u16 *)((u8 *)(arg0) + 0x48)) != 0) {
        temp_a0 = (*(void **)((u8 *)(arg0) + 0x50));
        if ((temp_a0 != 0) && ((temp_v1 = (*(s32 *)((u8 *)(temp_a0) + 0)), ((temp_v1 ^ 1) == 0)) || ((temp_v1 ^ 8) == 0))) {
            (*(s32 (**)(void *, s32))((u8 *)((*(void **)((u8 *)(temp_a0) + 4))) + 8))(temp_a0, (*(u16 *)((u8 *)(arg0) + 0x48)) - 1);
        }
    }
    temp_v0 = (*(s32 (**)(s32))((u8 *)(arg0) + 0x34));
    if (temp_v0 != 0) {
        temp_v0(arg1);
    }
    return 0;
}
/* localdecomp:end func_003EFE10 */

/* localdecomp:start func_003EFE98 */
void func_003EFE98(void *p, s32 v) {
    *((u8 *)p + 0x4C) = v;
    if ((u8)v == 0) {
        *((u8 *)p + 0x4C) = 1;
    }
}
/* localdecomp:end func_003EFE98 */

/* localdecomp:start func_003EFEB8 */
extern char D_001D9670[];
extern s32 func_003F2380();
void func_003EFEB8(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003EFEB8 */

LINKER_REMNANT("asm/remnants", func_003EFEE8);

/* localdecomp:start func_003EFF10 */
s32 func_003EFF10(void) {
    return 2;
}
/* localdecomp:end func_003EFF10 */

/* localdecomp:start func_003EFF18 */
extern void func_003ED988_003EFF18(void);
extern u8 D_001D9798[];
void *func_003EFF18(void *arg0) {
    func_003ED988_003EFF18();
    (*(s32 **)((u8 *)arg0 + 8)) = D_001D9798;
    (*(s32 *)((u8 *)arg0 + 0x50)) = 0x80808080;
    (*(s8 *)((u8 *)arg0 + 0x54)) = 0x10;
    (*(s32 *)((u8 *)arg0 + 0x2C)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x30)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x38)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x3C)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x40)) = 0;
    (*(s8 *)((u8 *)arg0 + 0x44)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x48)) = 0;
    (*(f32 *)((u8 *)arg0 + 0x4C)) = 1.0f;
    (*(s32 *)((u8 *)arg0 + 0x34)) = 0;
    (*(f32 *)((u8 *)arg0 + 0x5C)) = 1.0f;
    (*(f32 *)((u8 *)arg0 + 0x60)) = 1.0f;
    (*(s32 *)((u8 *)arg0 + 0x58)) = 2;
    return arg0;
}
/* localdecomp:end func_003EFF18 */

/* localdecomp:start func_003EFFA0 */
void func_003EFFA0(u8 *p, u8 m, s32 set) {
    if (set != 0) {
        p[0x44] |= m;
    } else {
        p[0x44] &= ~m;
    }
}
/* localdecomp:end func_003EFFA0 */

/* localdecomp:start func_003EFFD0 */
s32 func_003EFFD0(void *a0, s32 a1) {
    s32 b = a1 & 0xff;
    return (*(u8 *)((u8 *)a0 + 0x44) & b) != 0;
}
/* localdecomp:end func_003EFFD0 */

/* localdecomp:start func_003EFFE8 */
void func_003EFFE8(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x48) = x;
    *(f32 *)((u8 *)p + 0x4C) = y;
}
/* localdecomp:end func_003EFFE8 */

/* localdecomp:start func_003EFFF8 */
void func_003EFFF8(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003EFFF8 */

/* localdecomp:start func_003F0038 */
typedef struct { u8 pad[0x20]; void (*f20)(void *, s32, f32 *, s32); } V_3F0038;
typedef struct {
    u8 p0[8]; V_3F0038 *vt; u8 pC[0x14]; f32 f20, f24; u32 f28; u8 p2C[0x10]; s32 f3C; u8 p40[0x10]; u32 f50; u8 p54[8]; f32 f5C, f60;
} O_3F0038;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern f32 D_001D96B4;
extern void func_0038E7E8_003F0038(unsigned long, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
void func_003F0038(O_3F0038 *p, s32 a1) {
    f32 r[4];
    f32 cy, cx, s, d;
    f32 ox, oy, z;
    s32 has;
    unsigned long a0, a5; s32 a1_; f32 e;
    if (p->f3C == 0) return;
    z = 0.0f; ox = 0.0f; has = 0; oy = 0.0f;
    p->vt->f20(p, a1, r, 1);
    func_003EDCF0(p, r);
    cx = r[0] + (r[2] - r[0]) * 0.5f;
    cy = r[1] + (r[3] - r[1]) * 0.5f;
    if (func_003EDAF8(p, 0x40)) {
        ox = p->f20;
        has = 1;
        oy = p->f24;
    }
    s = p->f60;
    d = D_001D96B4 * s;
    a5 = p->f28; a1_ = p->f3C; e = p->f5C; a0 = p->f50;
    if (has) {
        func_0038E7E8_003F0038(a0, a1_, -1, 1, has, a5,
            (f32)(s32)(cx * D_001D9698), (f32)(s32)((cy - d) * D_001D969C),
            e, s * 1.0769231f, ox * D_001D9698, oy * D_001D969C);
    } else {
        func_0038E7E8_003F0038(a0, a1_, -1, 1, has, a5,
            (f32)(s32)(cx * D_001D9698), (f32)(s32)((cy - d) * D_001D969C),
            e, s * 1.0769231f, z, z);
    }
}
/* localdecomp:end func_003F0038 */

typedef struct {
    void *vt0; void *vt4; s32 (**vt)(); u8 pad0[0x4]; f32 f10, f14, f18, f1C, f20, f24; u32 f28; u8 pad2[0xC]; s32 f38; s32 f3C; u32 f40; u32 f44; u8 pad3[0x4]; u32 f4C; u32 f50; u8 pad4[0x8]; f32 f5C; f32 f60;
} O_3EAAD0;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern f32 D_001D96B4;
extern void func_003EDCF0();
extern void func_0038E7E8_003EAAD0(unsigned long, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
/* localdecomp:start func_003F0210 */
typedef struct { u8 b[16]; } B16_003F0210;
typedef struct {
    u8 pad0[0x10]; f32 f10, f14, f18, f1C, f20, f24; u8 pad28[0x14]; s32 f3C; u8 pad40[8]; f32 f48, f4C; u8 pad50[8]; s32 f58; f32 f5C, f60;
} O_003F0210;
extern f32 D_001D96B0;
extern f32 D_001D9698_003F0210[];
extern void func_0038E150(s32);
extern s32 func_00390D20_003F0210(s32, s32, f32);
extern f32 func_00390BF8(s32, s32, s32, f32);
extern void func_003E72A0(f32 *, f32 *);
__asm__(".extern D_001D9698, 4");
void func_003F0210(O_003F0210 *o, f32 *p, f32 *out, s32 flag) {
    f32 t[4];
    f32 sy;
    f32 ay;
    f32 sx;
    f32 ax;
    f32 scale;
    f32 m;
    f32 vx, vy;
    f32 w, h, dx, dy;
    f32 x0, y0, x1, y1, nx, ny;
    s32 k1, k2;

    switch (o->f58) {
    case 1:
        func_0038E150(1);
        break;
    case 2:
        func_0038E150(0);
        break;
    case 0:
    default:
        func_0038E150(0);
        break;
    }
    if (o->f3C) {
        scale = (f32)func_00390D20_003F0210(o->f3C, -1, 1.0f) / D_001D9698_003F0210[0];
    } else {
        scale = 0.0f;
    }
    sy = 2.0f;
    ay = 0.0f;
    sx = sy;
    ax = ay;
    if (flag) {
        k1 = 0;
        k2 = 0;
        func_003EDB40(o, &k1, &k2);
        if (k1 != 3) {
            if (k1 == 1) {
                ax = 1.0f;
            } else {
                sx = -2.0f;
                ax = 1.0f;
            }
        }
        if (k2 != 3) {
            if (k2 == 2) {
                sy = -2.0f;
                ay = 1.0f;
            } else {
                sy = 2.0f;
                ay = 1.0f;
            }
        }
    }
    o->f5C = o->f18;
    o->f60 = o->f1C;
    if (func_003EFFD0(o, 1)) {
        if (o->f3C) {
            m = func_00390BF8(o->f3C, -1, (s32)(o->f48 * D_001D9698), o->f4C);
        } else {
            m = 0.0f;
        }
        o->f5C *= m;
        o->f60 *= m;
    }
    if (func_003EDAF8(o, 0x2000)) {
        vx = 0.0f;
        vy = 0.0f;
        func_003E72A0(&vx, &vy);
        o->f5C *= vx;
        o->f60 *= vy;
    }
    w = o->f5C * scale / sx;
    h = o->f60 * D_001D96B0 / sy;
    out[0] = (o->f10 - w) + w * ax;
    out[1] = (o->f14 - h) + h * ay;
    out[2] = (o->f10 + w) + w * ax;
    out[3] = (o->f14 + h) + h * ay;
    if (p[0] == 0.0f && p[2] == 1.0f && p[1] == 0.0f && p[3] == 1.0f) {
        return;
    }
    x0 = out[0];
    y0 = out[1];
    x1 = out[2];
    y1 = out[3];
    nx = (p[2] - p[0]) * x0 + p[0];
    out[0] = nx;
    ny = (p[3] - p[1]) * y0 + p[1];
    out[2] = x1 + (nx - x0);
    out[1] = ny;
    out[3] = y1 + (ny - y0);
    if (func_003EDAF8(o, 0x40)) {
        dx = o->f20;
        dy = o->f24;
        func_0011A264(t, 0, 0x10);
        *(B16_003F0210 *)t = *(B16_003F0210 *)out;
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
/* localdecomp:end func_003F0210 */

/* localdecomp:start func_003F0658 */
s32 func_003F0658(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x34);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F0658 */

/* localdecomp:start func_003F0688 */
s32 func_003F0688(s32 p, s32 k) {
    if (k != 2) {
        return func_003EDBA8(p, k);
    }
    return 1;
}
/* localdecomp:end func_003F0688 */

/* localdecomp:start func_003F06B8 */
extern char D_001D9670[];
extern s32 func_003F2380();
void func_003F06B8(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003F06B8 */

LINKER_REMNANT("asm/remnants", func_003F06E8);

/* localdecomp:start func_003F0700 */
s32 func_003F0700(void) {
    return 3;
}
/* localdecomp:end func_003F0700 */

typedef struct {
    s32 f0, f4, f8, fC, f10, f14;
    s16 f18, f1A;
    s32 f1C;
    u8 f20;
    s16 f22;
    f32 f24, f28;
    s32 f2C, f30;
    u32 f34, f38;
    s32 f3C, f40, f44;
    u8 p48[2];
    u8 f4A;
    u8 p4B[0x56 - 0x4B];
    s16 f56;
    u8 p58;
    u8 f59, f5A;
} O_3EB180;
typedef struct { u8 p0[8]; void *f8; u8 pC[0x2C - 0xC]; O_3EB180 *f2C; u8 f30; s32 f34; } T_3EB180;
typedef struct { s32 f0; s32 f4; } S_3EB180;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3EB180;
extern u8 D_001D97C8;
extern S_3EB180 D_001DA938_003F0708[];
extern s32 *func_003E6C08();
extern void *func_003ED988_003F0708();
extern void **func_003E6CC0();
/* localdecomp:start func_003F0708 */
extern u8 D_001D97C8_003F0708[];
extern void *__nw(s32, s32) __asm__("func_003F2388");
extern void func_003F0B00(u8 *, f32);
extern void func_003F0B20(T_3EB180 *, s32);
extern void func_003F0B48(u8 *, s32);
extern void func_003F0B70(u8 *, s32, s32);
void *func_003F0708(T_3EB180 *p) {
    void **t;
    O_3EB180 *o;
    S_3EB180 *q;
    s32 v;
    func_003ED988_003F0708(p);
    {
        S_3EB180 *d;
        p->f2C = 0;
        p->f8 = D_001D97C8_003F0708;
        d = D_001DA938_003F0708;
        v = d->f4;
        q = d;
        if (v == 0) q = (S_3EB180 *)func_003E6C08(q);
    }
    t = func_003E6CC0(q, 1);
    p->f30 = 0;
    p->f34 = 0;
    if (t != 0) {
        v = (s32)*t;
        o = (O_3EB180 *)__nw(0x5C, ((VT_3EB180 *)v)->f8(t, 0x5C));
        o->f34 = 0x80808080;
        o->f0 = 0;
        o->f4 = 0;
        o->f3C = 0;
        o->f40 = 0;
        o->f44 = 0;
        p->f2C = o;
        o->f24 = 1.0f;
        o->fC = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f18 = 0;
        o->f1C = 0;
        o->f20 = 0;
        o->f22 = 0;
        o->f2C = 0;
        o->f30 = 0;
        o->f8 = 0;
        o->f38 = 0x80808080;
        o->f1A = -1;
        o->f4A = 0x10;
        o->f28 = 1.0f;
        func_003F0980(p, 0x80808080);
        func_003F0AC0((u8 *)p, 1, 0.0f, 0.0f);
        func_003F0BE8((u8 *)p, 0, 0);
        func_003F0A70(p, 0.03846f);
        func_003F0CD8(p, 2);
        func_003F0B00((u8 *)p, 0.0005f);
        func_003F0B20(p, 0);
        func_003F0B48((u8 *)p, 0);
        p->f2C->f56 = 0;
        p->f2C->f59 = 0;
        func_003F0B70((u8 *)p, 4, 0);
        func_003F0B70((u8 *)p, 8, 0);
        func_003F0B70((u8 *)p, 0x10, 0);
        func_003F0B70((u8 *)p, 0x40, 1);
        p->f2C->f5A = 0;
    }
    return p;
}
/* localdecomp:end func_003F0708 */

s32 *func_003E6C08(s32 *);
void **func_003E6CC0(s32 *, s32);
void func_003F2380_003F08E0(void *);
extern u8 D_001D9670_003F08E0;
extern u8 D_001D97C8;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003EB358;
extern S_001DA9B8_003EB358 D_001DA938[];
INCLUDE_ASM("asm/nonmatchings/text", func_003F08E0);

/* localdecomp:start func_003F0980 */
void func_003F0980(void *p, s32 value) {
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x34) = value;
}
/* localdecomp:end func_003F0980 */

/* localdecomp:start func_003F0990 */
void func_003F0990(u8 *p) {
    u8 *q;
    s32 v;
    (*(u8 **)(p + 0x2C))[0x59] = 0;
    q = *(u8 **)(p + 0x2C);
    v = 0;
    if (*(u16 *)(q + 0x48) & 8) v = *(u16 *)(q + 0x4C);
    *(s16 *)(q + 0x56) = v;
    (*(u8 **)(p + 0x2C))[0x5A] = 0;
    *(s32 *)(*(u8 **)(p + 0x2C) + 0x40) = 0;
}
/* localdecomp:end func_003F0990 */

/* localdecomp:start func_003F09C8 */
typedef struct { u8 pad[0x10]; s32 w10; u8 p2[0x48-0x14]; u16 h48; } Q_3EB440;
typedef struct { u8 pad[0x2C]; Q_3EB440 *q; u8 b30; u8 p3[3]; s32 w34; } S_3EB440;
extern void func_003F0990();
void func_003F09C8(S_3EB440 *p, s32 b) {
    Q_3EB440 *q = p->q;
    if (q->w10 != b && (q->h48 & 0x20)) {
        func_003F0990((u8 *)p);
        p->b30 = 0;
        p->w34 = 0;
    }
    p->q->w10 = b;
}
/* localdecomp:end func_003F09C8 */

/* localdecomp:start func_003F0A30 */
void func_003F0A30(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x28) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0A30 */

/* localdecomp:start func_003F0A48 */
void func_003F0A48(void *p, s32 a, s16 b, s16 c, s32 d) {
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x18) = b;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x14) = a;
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x1A) = c;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x38) = d;
}
/* localdecomp:end func_003F0A48 */

/* localdecomp:start func_003F0A70 */
void func_003F0A70(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x44) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0A70 */

/* localdecomp:start func_003F0A88 */
s32 func_003F0A88(void *a0, f32 *a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *a1 = *(f32 *)((u8 *)p + 0x44);
    return 1;
}
/* localdecomp:end func_003F0A88 */

/* localdecomp:start func_003F0AA0 */
s32 func_003F0AA0(u32 a0, u32 a1, u32 a2) {
    u32 ptr;

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a1 + 0x00) = *(float *)(ptr + 0x2C);

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a2 + 0x00) = *(float *)(ptr + 0x30);

    return 1;
}
/* localdecomp:end func_003F0AA0 */

/* localdecomp:start func_003F0AC0 */
void func_003F0AC0(u8 *p, s32 a, f32 x, f32 y) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x3C) = x;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x40) = y;
    *(s16 *)(*(u8 **)(p + 0x2C) + 0x56) = 0;
    {
        u8 *q = *(u8 **)(p + 0x2C);
        if (a != 0) q[0x59] = 0;
        else q[0x59] = 1;
    }
    p[0x30] = 0;
    *(s32 *)(p + 0x34) = 0;
}
/* localdecomp:end func_003F0AC0 */

/* localdecomp:start func_003F0B00 */
void func_003F0B00(u8 *p, f32 x) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x50) = x * 0.8333333f;
}
/* localdecomp:end func_003F0B00 */

/* localdecomp:start func_003F0B20 */
void func_003F0B20(T_3EB180 *p, s32 a) {
    *(u16 *)((u8 *)p->f2C + 0x4C) = (a * 5 + 2) / 6;
}
/* localdecomp:end func_003F0B20 */

/* localdecomp:start func_003F0B48 */
/* func_003F0B48 */

void func_003F0B48(u8 *p, s32 a) {
    *(s16 *)(*(u8 **)(p + 0x2C) + 0x54) = (a * 5 + 2) / 6;
}
/* localdecomp:end func_003F0B48 */

/* localdecomp:start func_003F0B70 */
void func_003F0B70(u8 *p, s32 m, s32 on) {
    if (on) *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) |= m;
    else *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) &= ~m;
    p[0x30] = 0;
    *(s32 *)(p + 0x34) = 0;
}
/* localdecomp:end func_003F0B70 */

LINKER_REMNANT("asm/remnants", func_003F0BB0);

/* localdecomp:start func_003F0BB8 */
void func_003F0BB8(void *p, s32 *a, s32 *b) {
    *a = *(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) & 1;
    *b = ((*(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) >> 1) ^ 1) & 1;
}
/* localdecomp:end func_003F0BB8 */

/* localdecomp:start func_003F0BE8 */
void func_003F0B70_003F0BE8(void *, s32, s32);

s32 func_003F0BE8(u8 *arg0, s32 arg1, s32 arg2) {
    s32 a = 0;
    s32 ok = 1;
    s32 b = 0;

    if (arg1 != 0) {
        if (arg1 == 1) {
            a = 1;
        } else {
            ok = 0;
        }
    }
    if (arg2 == 0) {
        b = 1;
    } else if (arg2 != 1) {
        ok = 0;
    }
    func_003F0B70_003F0BE8(arg0, 1, a);
    func_003F0B70_003F0BE8(arg0, 2, b);
    *(s8 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    return ok;
}
/* localdecomp:end func_003F0BE8 */

/* localdecomp:start func_003F0C78 */
extern void func_003EDB68(void *, f32, f32);
void func_003F0C78(u8 *object, f32 *bounds) {
    register f32 x __asm__("$f12") = bounds[0];
    register f32 half __asm__("$f2") = 0.5f;
    register f32 temp __asm__("$f1") = bounds[2];
    register f32 y __asm__("$f13") = bounds[1];
    register f32 other __asm__("$f0") = bounds[3];
    temp -= x;
    other -= y;
    temp *= half;
    x += temp;
    temp = other * half;
    y += temp;
    func_003EDB68(object, x, y);
    *(volatile s32 *)(object + 0x34) = 0;
    *(volatile u8 *)(object + 0x30) = 0;
}
/* localdecomp:end func_003F0C78 */

/* localdecomp:start func_003F0CD8 */
void func_003F0CD8(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(u8 *)((u8 *)p + 0x58) = (u8)a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0CD8 */

typedef struct {
    u8 p00[0x10];
    s32 f10;
    s32 f14;
    s16 h18;
    s16 h1A;
    u8 p1C[0xC];
    f32 f28;
    f32 f2C;
    f32 f30;
    u32 f34;
    u32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    u16 h48;
    u16 p4A;
    u16 h4C;
    u16 p4E;
    f32 f50;
    u16 h54;
    u16 h56;
    u8 b58;
    u8 b59;
    u8 b5A;
} P_3EB728;
typedef struct {
    u8 p00[0x20];
    void (*f20)(void *, s32, f32 *, s32);
} VT_3EB728;
typedef struct {
    u8 p00[8];
    VT_3EB728 *vt;
    u8 p0C[0x14];
    f32 f20;
    f32 f24;
    u32 f28;
    P_3EB728 *p;
    u8 b30;
    u8 p31[3];
    f32 f34;
} O_3EB728;
typedef struct {
    s16 y0, y1, x0, x1, tx, ty, w, h, f30, flags, f34, f36, f38, f3A;
} Desc_3EB728;
extern f32 D_001D9690;
extern f32 D_001D9694;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern s32 D_001D55C4;
extern s32 D_003357E0[];
extern void func_0038E150(s32);
extern void func_003EDCF0(void *, f32 *);
extern void func_00391210();
extern void func_003911F0();
extern void func_00390CC8(void);
extern void func_00390CA8(void);
extern void func_003E7160(void);
extern long func_00389598(s32);

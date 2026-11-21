#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void *func_003EF4C8();
/* --- end of declarations from other files --- */

/* declarations of 3EE290.c's earlier functions */
extern s32 func_003EDEB0();
extern void func_003EDEF8();
extern s32 D_001D9760_g;
extern s32 func_003EDEB0(void *, s32);
extern char D_001D9670[];
extern s32 func_0011A264(void *, s32, s32);
extern void func_003EDD40(void);
extern s32 func_003EDF60(s32, s32);

/* localdecomp:start func_003EEBF8 */
typedef struct { u32 c0, c1, c2, c3; } Colors_003EEBF8;     /* one colour per corner */
typedef struct O_003EEBF8 O_003EEBF8;
typedef struct { u8 p0[0x20]; void (*rect)(O_003EEBF8 *, s32, f32 *, s32); } V_003EEBF8;
struct O_003EEBF8 {
    u8 p0[8];
    V_003EEBF8 *vt;
    u8 pC[4];
    f32 mid_x, mid_y;               /* 0x10: the bars stop at the centre */
    u8 p18[8];
    f32 shadow_dx, shadow_dy;       /* 0x20 */
    u32 shadow_color;               /* 0x28 */
    u8 p2C[4];
    u32 color;                      /* 0x30 */
    f32 width, height;              /* 0x34: the bars' thickness */
};
extern void func_003EE0A8(void *, f32 *);
extern void func_003E5C78(f32 *p, f32 lo, f32 hi);
extern f32 D_001D9698 __attribute__((section(".rodata")));
extern f32 D_001D969C __attribute__((section(".rodata")));
/* func_0038C6F0 with its last parameter as the by-value colours it is (EABI passes them by reference) */
extern void func_0038C6F0_003EEBF8(s32, s32, s32, s32, unsigned long, Colors_003EEBF8);

static __inline__ Colors_003EEBF8 colors_003EEBF8(u32 c) {
    return (Colors_003EEBF8){ c, c, c, c };
}

static __inline__ void fill_003EEBF8(Colors_003EEBF8 c, f32 x0, f32 y0, f32 x1, f32 y1) {
    func_0038C6F0_003EEBF8((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C),
                           (s32)(x1 * D_001D9698), (s32)(y1 * D_001D969C), 0, c);
}

void func_003EEBF8(O_003EEBF8 *o, s32 a) {
    f32 v[4];

    o->vt->rect(o, a, v, 1);
    func_003EE0A8(o, v);
    {
        f32 x0 = v[0];
        f32 y0 = v[1] + o->height;
        f32 x1 = x0 + o->width;
        f32 y1 = v[3] - o->height;
        func_003E5C78(&y0, v[1], o->mid_y);
        func_003E5C78(&x1, v[0], o->mid_x);
        func_003E5C78(&y1, o->mid_y, v[3]);
        if (func_003EDEB0(o, 0x40)) {
            f32 dx = o->shadow_dx;
            f32 dy = o->shadow_dy;
            fill_003EEBF8(colors_003EEBF8(o->shadow_color), x0 + dx, y0 + dy, x1 + dx, y1 + dy);
        }
        fill_003EEBF8((Colors_003EEBF8){ o->color, o->color, o->color, o->color }, x0, y0, x1, y1);
    }
    {
        f32 x0 = v[2] - o->width;
        f32 y0 = v[1] + o->height;
        f32 x1 = v[2];
        f32 y1 = v[3] - o->height;
        func_003E5C78(&y0, v[1], o->mid_y);
        func_003E5C78(&x0, o->mid_x, v[2]);
        func_003E5C78(&y1, o->mid_y, v[3]);
        if (func_003EDEB0(o, 0x40)) {
            f32 dx = o->shadow_dx;
            f32 dy = o->shadow_dy;
            fill_003EEBF8(colors_003EEBF8(o->shadow_color), x0 + dx, y0 + dy, x1 + dx, y1 + dy);
        }
        fill_003EEBF8((Colors_003EEBF8){ o->color, o->color, o->color, o->color }, x0, y0, x1, y1);
    }
    {
        f32 x0 = v[0];
        f32 y0 = v[1];
        f32 x1 = v[2];
        f32 y1 = y0 + o->height;
        func_003E5C78(&y1, y0, o->mid_y);
        if (func_003EDEB0(o, 0x40)) {
            f32 dx = o->shadow_dx;
            f32 dy = o->shadow_dy;
            fill_003EEBF8(colors_003EEBF8(o->shadow_color), x0 + dx, y0 + dy, x1 + dx, y1 + dy);
        }
        fill_003EEBF8((Colors_003EEBF8){ o->color, o->color, o->color, o->color }, x0, y0, x1, y1);
    }
    {
        f32 x0 = v[0];
        f32 y0 = v[3] - o->height;
        f32 x1 = v[2];
        f32 y1 = v[3];
        func_003E5C78(&y0, o->mid_y, v[3]);
        if (func_003EDEB0(o, 0x40)) {
            f32 dx = o->shadow_dx;
            f32 dy = o->shadow_dy;
            fill_003EEBF8(colors_003EEBF8(o->shadow_color), x0 + dx, y0 + dy, x1 + dx, y1 + dy);
        }
        fill_003EEBF8((Colors_003EEBF8){ o->color, o->color, o->color, o->color }, x0, y0, x1, y1);
    }
}
/* localdecomp:end func_003EEBF8 */

typedef struct { u8 b[16]; } B16_3E98B8;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E98B8;
extern s32 func_0011A264(void *, s32, s32);
/* localdecomp:start func_003EF1D8 */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003EDEF8();
s32 func_003EDEB0(void *p, s32 mask);
void func_003EDEF8(void *p, s32 *a, s32 *b);
typedef struct { u8 b[16]; } B16_3E98B8_3EEE20;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E98B8_3EEE20;
extern s32 func_003EDEB0();
extern s32 func_0011A264(void *, s32, s32);
extern s32 func_003EDEB0(void *, s32);
extern void func_003EDEF8(void *, s32 *, s32 *);

void func_003EF1D8(O_3E98B8_3EEE20 *o, f32 *p, f32 *out, s32 flag) {
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
        func_003EDEF8(o, &k1, &k2);
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
    if (func_003EDEB0(o, 0x40)) {
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
/* localdecomp:end func_003EF1D8 */

/* localdecomp:start func_003EF438 */
s32 func_003EF438(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x2C);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003EF438 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EF468);

/* localdecomp:start func_003EF470 */
extern char D_001D9670[];
extern s32 func_003F2738();
void func_003EF470(u8 *p, s32 f) {
    *(void **)(p + 8) = D_001D9670;
    if (f & 1) func_003F2738(p);
}
/* localdecomp:end func_003EF470 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EF4A0);

/* localdecomp:start func_003EF4C8 */
extern void func_003EF570();
extern void func_003EF640(void *, s32, s32, s32, s32);
extern void func_003EDD40(void);
extern u8 D_001D9768[];
void *func_003EF4C8(void *arg0)
{
  void **new_var;
  func_003EDD40();
  *((s32 *) (((u8 *) arg0) + 0x2C)) = 0;
  *((s32 **) (((u8 *) arg0) + 8)) = D_001D9768;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x38)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x3C)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x40)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x44)) = 0x80808080;
  func_003EF640(arg0, 0x80F00000, 0x80F00000, 0x80F00000, 0x80F00000);
  *((s32 *) (((u8 *) arg0) + 0x50)) = 0;
  *((f32 *) (((u8 *) arg0) + 0x18)) = 0.5f;
  *((f32 *) (((u8 *) arg0) + 0x1C)) = 0.5f;
  func_003EF570(arg0, 0);
  new_var = &arg0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4C)) = 0xA;
  *((s16 *) (((u8 *) (*new_var)) + 0x4A)) = 0;
  *((s32 *) (((u8 *) (*new_var)) + 0x34)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4E)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4D)) = 0;
  return *new_var;
}
/* localdecomp:end func_003EF4C8 */

/* localdecomp:start func_003EF570 */
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

void func_003EF570(S_003E9C50 *arg0, s32 arg1) {
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
/* localdecomp:end func_003EF570 */

/* localdecomp:start func_003EF608 */
extern s32 D_001D9760_g;
extern s32 func_003EDF60(s32, s32);
s32 func_003EF608(s32 p, s32 k) {
    if (k != D_001D9760_g) return func_003EDF60(p, k);
    return 1;
}
/* localdecomp:end func_003EF608 */

/* localdecomp:start func_003EF638 */
extern s32 D_001D9760_g;
s32 func_003EF638(void) {
    return D_001D9760_g;
}
/* localdecomp:end func_003EF638 */

/* localdecomp:start func_003EF640 */
void func_003EF640(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x38) = a1;
    *(s32 *)((u8 *)a0 + 0x3c) = a2;
    *(s32 *)((u8 *)a0 + 0x40) = a3;
    *(s32 *)((u8 *)a0 + 0x44) = a4;
}
/* localdecomp:end func_003EF640 */

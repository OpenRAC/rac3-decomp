#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003EE518(void *p, s32, s32);
extern void *func_003EEB18();
extern void func_003EE7C0(u8 *, f32, f32, f32, f32);
/* --- end of declarations from other files --- */

/* declarations of 3EE290.c's earlier functions */
extern s32 func_003EDEB0();
extern void func_003EDEF8();
extern s32 D_001D9730_g;
extern s32 func_003EDEB0(void *, s32);

/* localdecomp:start func_003EE518 */
void func_003EE518(void *p, s32 m, s32 set) {
    if (set != 0) {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) |= m;
    } else {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) &= ~m;
    }
}
/* localdecomp:end func_003EE518 */

/* localdecomp:start func_003EE548 */
s32 func_003EE548(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    return (*(u8 *)((u8 *)p + 0x4c) & a1) != 0;
}
/* localdecomp:end func_003EE548 */

typedef struct { u8 b[16]; } B16_3E8C40;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E8C40;
extern s32 func_0011A264(void *, s32, s32);
/* localdecomp:start func_003EE560 */
void func_003EE560(O_3E8C40 *o, f32 *rect, f32 *out, s32 align)
{
    extern void func_003EDEF8(void *, s32 *, s32 *);
    extern s32 func_003EDEB0(void *, s32);
    extern s32 func_0011A264(void *, s32, s32);
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
        func_003EDEF8(o, &horizontal, &vertical);
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
    if (func_003EDEB0(o, 0x40)) {
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
/* localdecomp:end func_003EE560 */
TEXT_PADDING(2);

/* localdecomp:start func_003EE7C0 */
void func_003EE7C0(u8 *p, f32 a, f32 b, f32 c, f32 d) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x50) = a;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x58) = b;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x54) = c;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x5C) = d;
}
/* localdecomp:end func_003EE7C0 */

/* localdecomp:start func_003EE7E8 */
typedef struct O_3E8EC8 O_3E8EC8F;
typedef struct { u8 p0[0x20]; void (*f20)(O_3E8EC8F *, s32, f32 *, s32); } V_3E8EC8;
typedef struct { s32 *tbl[1]; } L_3E8EC8;
typedef struct { u8 p0[0x48]; s32 f48; } L2_3E8EC8;
typedef struct O_3E8EC8 { u8 p0[8]; V_3E8EC8 *f8; u8 pC[0x20]; struct { s32 *e[1]; u8 pad[0x44]; s32 n; } *f2C; } O_3E8EC8;
extern void func_003EE0A8();
extern s32 func_003EE548();
extern void func_003EE0F8(f32, f32, f32, f32);
extern void func_003EE038();
void func_003EE7E8(O_3E8EC8 *self, s32 b) {
    f32 v[4];
    s32 i;
    self->f8->f20(self, b, v, 1);
    func_003EE0A8(self, v);
    if (func_003EE548(self, 1)) {
        func_003EE0F8(v[0], v[1], v[2], v[3]);
    }
    for (i = 0; i < self->f2C->n; i++) {
        func_003EE038(((s32 **)self->f2C)[i], b);
    }
    if (func_003EE548(self, 1)) {
        func_003EE0F8(0.0f, 0.0f, 1.0f, 1.0f);
    }
}
/* localdecomp:end func_003EE7E8 */

/* localdecomp:start func_003EE8D0 */
typedef struct { u8 b[16]; } B16_3E8FB0;
typedef struct { u8 p0[8]; s32 (**vt)(); } C_3E8FB0;
typedef struct { s32 *e[1]; u8 p0[0x40]; C_3E8FB0 *f44; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E8FB0;
typedef struct { u8 p0[0x2C]; S_3E8FB0 *f2C; } O_3E8FB0;
extern s32 func_003EDF90();
s32 func_003EE8D0(O_3E8FB0 *self, f32 *b) {
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
            func_003EDF90(((s32 **)self->f2C)[i], b);
        }
    }
    return 1;
}
/* localdecomp:end func_003EE8D0 */

/* localdecomp:start func_003EE9E8 */
typedef struct { u8 b[16]; } B16_3E90C8;
typedef struct { s32 *e[1]; u8 p0[0x44]; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E90C8;
typedef struct { u8 p0[0x2C]; S_3E90C8 *f2C; } O_3E90C8;
extern void func_003EDFE8();
void func_003EE9E8(O_3E90C8 *self, f32 *b) {
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
        func_003EDFE8(((s32 **)self->f2C)[i], b);
    }
}
/* localdecomp:end func_003EE9E8 */

/* localdecomp:start func_003EEAD8 */
s32 func_003EEAD8(void) {
    return 7;
}
/* localdecomp:end func_003EEAD8 */

/* localdecomp:start func_003EEAE0 */
s32 func_003EEAE0(s32 p, s32 k) {
    if (k == 7) {
        return 1;
    }
    return func_003EDF60(p, k);
}
/* localdecomp:end func_003EEAE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EEB10);

extern void func_003EDD40(void);
extern unsigned char D_001D9738[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EEB18);

/* localdecomp:start func_003EEB80 */
extern s32 D_001D9730_g;
extern s32 func_003EDF60(s32, s32);
s32 func_003EEB80(s32 p, s32 k) {
    if (k != D_001D9730_g) return func_003EDF60(p, k);
    return 1;
}
/* localdecomp:end func_003EEB80 */

/* localdecomp:start func_003EEBB0 */
extern s32 D_001D9730_g;
s32 func_003EEBB0(void) { return D_001D9730_g; }
/* localdecomp:end func_003EEBB0 */

#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003ACFF0 */
typedef struct { f32 x, y; } V2_003A7690;
typedef struct { s32 a, b, c, d, e, f; } T6_003A7690;
typedef struct {
    f32 *pos;        /* 0x000 */
    u8 pad4[4];
    u32 *color;      /* 0x008 */
    u32 *font;       /* 0x00C */
    u8 sub10[0x3C];  /* 0x010 */
    u8 sub4C[0x13C]; /* 0x04C */
    s32 w;           /* 0x188 */
    s32 h;           /* 0x18C */
    s32 count;       /* 0x190 */
    u8 pad194[8];
    s32 xoff;        /* 0x19C */
    u8 pad1A0[4];
    s32 mode;        /* 0x1A4 */
    u8 pad1A8[8];
    f32 f1B0;        /* 0x1B0 */
    u8 pad1B4[4];
    s32 text[1];     /* 0x1B8 */
} O_003A7690;
extern V2_003A7690 D_001D8440[];
extern V2_003A7690 D_001D8448[];
extern f32 D_001D8450;
extern T6_003A7690 D_001D8458[];
extern T6_003A7690 D_001D8470[];
extern s32 D_001D55E8;
extern void func_0038C6F0_003ACFF0(s32, s32, s32, s32, s32, u32 *);
extern void func_003AB288(void *, f32, f32, f32, f32);
extern void func_003AB3B0(void *, f32, f32, f32, f32);
extern void func_003AB750(void *);
extern void func_0038E530(s32);
extern void func_0038EBC8_003ACFF0(unsigned long, s32, s32, f32, f32, f32, f32, s32, s32, unsigned long, f32, f32);

void func_003ACFF0(void *arg0) {
    O_003A7690 *o = arg0;
    u32 cols[4];
    V2_003A7690 a, b;
    T6_003A7690 t1, t2;
    f32 s;
    u32 c, alpha;
    s32 ix, iy, i, lh;

    alpha = *o->color >> 24;
    if ((s32)alpha > 0x60) alpha = 0x60;
    c = *o->color & 0xFFFFFF;
    c |= alpha << 24;
    cols[0] = c;
    cols[1] = c;
    cols[2] = c;
    cols[3] = c;
    func_0038C6F0_003ACFF0(o->pos[0] - o->w, o->pos[1] - o->h, o->pos[0] + o->w + 2.0f, o->pos[1] + o->h, 0xFFFFF0, cols);
    a = D_001D8440[0];
    b = D_001D8448[0];
    s = 1.0f;
    if (o->mode == 0) s = D_001D8450;
    lh = 16;
    i = 0;
    func_003AB288(o->sub10, o->pos[0] - o->w - a.x, o->pos[1] - o->h - a.y, 0.0f, 0.0f);
    func_003AB3B0(o->sub10, -s, s, 0.0f, 0.0f);
    func_003AB750(o->sub10);
    func_003AB288(o->sub10, o->pos[0] + o->w + a.x + 1.0f, o->pos[1] - o->h - a.y, 0.0f, 0.0f);
    func_003AB3B0(o->sub10, s, s, 0.0f, 0.0f);
    func_003AB750(o->sub10);
    func_003AB288(o->sub4C, o->pos[0] + o->w + b.x, o->pos[1] - o->h - b.y, 0.0f, 0.0f);
    func_003AB3B0(o->sub4C, s, s, 0.0f, 0.0f);
    func_003AB750(o->sub4C);
    func_003AB288(o->sub4C, o->pos[0] - o->w - b.x + 1.0f, o->pos[1] - o->h - b.y, 0.0f, 0.0f);
    func_003AB3B0(o->sub4C, -s, s, 0.0f, 0.0f);
    func_003AB750(o->sub4C);
    func_003AB288(o->sub4C, o->pos[0] + o->w + b.x, o->pos[1] - o->h - b.y + o->f1B0, 0.0f, 0.0f);
    func_003AB3B0(o->sub4C, s, -s, 0.0f, 0.0f);
    func_003AB750(o->sub4C);
    func_003AB288(o->sub4C, o->pos[0] - o->w - b.x + 1.0f, o->pos[1] - o->h - b.y + o->f1B0, 0.0f, 0.0f);
    func_003AB3B0(o->sub4C, -s, -s, 0.0f, 0.0f);
    func_003AB750(o->sub4C);
    ix = o->pos[0] - o->w + o->xoff;
    iy = o->pos[1] - o->h;
    t1 = D_001D8458[0];
    t2 = D_001D8470[0];
    switch (o->mode) {
    case 0:
        if (o->text[0] != 0) {
            for (; i < o->count; i++) {
                s32 old = D_001D55E8;
                func_0038E530(1);
                func_0038EBC8_003ACFF0(*o->font, o->text[i], -1, ix + t2.c, iy + t2.d + i * lh, 1.0f, 1.0f, 0, 1, 0x80000000, 2.0f, 2.0f);
                func_0038E530(old);
            }
        }
        break;
    case 1:
        if (o->text[0] != 0) {
            for (; i < o->count; i++) {
                func_0038E530(1);
                func_0038EBC8_003ACFF0(*o->font, o->text[i], -1, ix + t1.c, iy + t1.d + i * lh + 2, 1.0f, 1.0f, 0, 1, 0x80000000, 2.0f, 2.0f);
            }
        }
        break;
    case 2:
        break;
    }
}
/* localdecomp:end func_003ACFF0 */

/* localdecomp:start func_003AD628 */
void func_003AD628(void *a) {
}
/* localdecomp:end func_003AD628 */

/* localdecomp:start func_003AD630 */
void func_003877A0();
void func_003ACFF0(void *);
void func_003AD628(void *);
typedef struct { u8 pad0[0xB0]; f32 fB0; } S_00225980_003A7CD0_003A7CD0;
extern S_00225980_003A7CD0_003A7CD0 D_00225900[];

void func_003AD630(void *arg0) {
    f32 temp_f20;
    s32 temp_v1;

    if (*(*(f32 **)((u8 *)(arg0) + 4)) != 0.0f) {
        temp_f20 = D_00225900->fB0;
        D_00225900->fB0 = 0.62f;
        func_003877A0();
        temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1A8));
        switch (temp_v1) {                          /* irregular */
        case 0:
            func_003ACFF0(arg0);
            break;
        case 2:
            func_003AD628(arg0);
            break;
        }
        D_00225900->fB0 = temp_f20;
        func_003877A0();
    }
}
/* localdecomp:end func_003AD630 */

#include "common.h"

/* localdecomp:start func_L39_006932E8 */
typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ char label[0x34];
    /* 0x38 */ f32 x;
    /* 0x3C */ f32 y;
    /* 0x40 */ f32 w;
    /* 0x44 */ f32 h;
} Base_006932E8;

typedef struct {
    Base_006932E8 b;
    u8 pad48[8];
} Plain_006932E8;

typedef struct {
    Base_006932E8 b;
    s32 f48, f4C, f50, f54, f58, f5C, f60, f64;
    u8 pad68[8];
} List_006932E8;

typedef struct {
    Base_006932E8 b;
    char text[0x50];
    u8 pad98[8];
} Text_006932E8;

typedef struct {
    Base_006932E8 b;
    char text[0x400];
    u8 pad448[8];
} Big_006932E8;

typedef struct {
    Base_006932E8 b;
    s32 f48;
    s32 count;
    Base_006932E8 *items[12];
    u8 pad80[0x150];
} Page_006932E8;

extern char D_L39_00247EE0[];
extern u8 D_L39_0047CA68[];
extern void *func_L39_00688388(void *);
extern s32 func_00381FF0(s32);
extern void func_L39_0068CD28(u8 *, s32, f32, f32, f32, f32);
extern void func_00120D28(s32, s32, s32);
extern void func_L39_00689670(void *, void *);


/* The menu items are C++ objects built on the stack; their constructors are inlined here.
 * Base: type 0, then the shared init (func_L39_0068CD28). */
static __inline__ void base_006932E8(Base_006932E8 *b, s32 label, f32 x, f32 y, f32 w, f32 h)
{
    b->type = 0;
    func_L39_0068CD28((u8 *)b, label, x, y, w, h);
}

/* plain label item (type 1) */
static __inline__ void plain_006932E8(Plain_006932E8 *p, s32 label, f32 x, f32 y, f32 w, f32 h)
{
    base_006932E8(&p->b, label, x, y, w, h);
    p->b.type = 1;
}

/* text item (type 7): copies its text, at most 0x4F characters */
static __inline__ void text_006932E8(Text_006932E8 *t, s32 label, f32 x, f32 y, f32 w, f32 h, char *src)
{
    base_006932E8(&t->b, label, x, y, w, h);
    t->b.type = 7;
    if (src != 0) {
        func_00120D28((s32)t->text, (s32)src, 0x4F);
        t->text[0x4F] = 0;
    } else {
        t->text[0] = 0;
    }
}

/* long text item (type 9): copies its text, at most 0x3FF characters */
static __inline__ void big_006932E8(Big_006932E8 *t, s32 label, f32 x, f32 y, f32 w, f32 h, char *src)
{
    base_006932E8(&t->b, label, x, y, w, h);
    t->b.type = 9;
    if (src == 0) {
        t->text[0] = 0;
    } else {
        func_00120D28((s32)t->text, (s32)src, 0x3FF);
        t->text[0x3FF] = 0;
    }
}

/* scrolling list item (type 5) */
static __inline__ void list_006932E8(List_006932E8 *l, s32 label, f32 x, f32 y, f32 w, f32 h, s32 rows, s32 sel)
{
    base_006932E8(&l->b, label, x, y, w, h);
    l->b.type = 5;
    l->f48 = 0;
    l->f4C = 0;
    l->f50 = 0;
    l->f54 = rows;
    l->f58 = 0;
    l->f5C = 0;
    l->f60 = sel;
    l->f64 = 0;
}

/* page: holds the items */
static __inline__ void page_006932E8(Page_006932E8 *p)
{
    base_006932E8(&p->b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    p->f48 = 0x2E;
    p->count = 0;
    p->b.x = 0;
    p->b.y = 0;
    p->b.w = 1.0f;
    p->b.h = 1.0f;
}

void *func_L39_006932E8(u8 *this)
{
    Plain_006932E8 title;
    List_006932E8 list;
    Text_006932E8 t0;
    Text_006932E8 t1;
    Plain_006932E8 h0;
    Text_006932E8 t2;
    Text_006932E8 t3;
    Text_006932E8 t4;
    Plain_006932E8 h1;
    Plain_006932E8 h2;
    Plain_006932E8 h3;
    Big_006932E8 big;
    Page_006932E8 page;

    func_L39_00688388(this);
    *(u8 **)(this + 0x2A4) = this + 0x3D8;
    *(u8 **)(this + 0x60) = D_L39_0047CA68;

    plain_006932E8(&title, func_00381FF0(0xFC6), 0.274f, 0.17499998f, 0.32500002f, 0.05f);

    list_006932E8(&list, (s32)D_L39_00247EE0, 0.274f, 0.525f, 0.32500002f, 0.6500001f, 13, -1);

    text_006932E8(&t0, func_00381FF0(0xF8A), 0.48550004f, 0.17316666f, 0.405f, 0.05f, D_L39_00247EE0);
    text_006932E8(&t1, func_00381FF0(0x1101), 0.48550004f, 0.2195f, 0.405f, 0.05f, D_L39_00247EE0);
    plain_006932E8(&h0, func_00381FF0(0x1654), 0.688f, 0.26583335f, 0.405f, 0.05f);
    text_006932E8(&t2, func_00381FF0(0x1334), 0.48550004f, 0.31216666f, 0.405f, 0.05f, D_L39_00247EE0);
    text_006932E8(&t3, func_00381FF0(0x1336), 0.48550004f, 0.3585f, 0.405f, 0.05f, D_L39_00247EE0);
    text_006932E8(&t4, func_00381FF0(0x1691), 0.48550004f, 0.40483335f, 0.405f, 0.05f, D_L39_00247EE0);
    plain_006932E8(&h1, func_00381FF0(0x1171), 0.688f, 0.47999996f, 0.405f, 0.05f);
    plain_006932E8(&h2, func_00381FF0(0x1172), 0.688f, 0.525f, 0.405f, 0.05f);
    plain_006932E8(&h3, func_00381FF0(0x1395), 0.688f, 0.57f, 0.405f, 0.05f);

    big_006932E8(&big, (s32)D_L39_00247EE0, 0.688f, 0.734f, 0.405f, 0.20699999f, (char *)func_00381FF0(0x1010));

    page_006932E8(&page);
    page.items[0] = &title.b;
    page.items[1] = &list.b;
    page.items[3] = &t0.b;
    page.items[4] = &t1.b;
    page.items[2] = &h0.b;
    page.items[5] = &t2.b;
    page.items[6] = &t3.b;
    page.items[7] = &t4.b;
    page.items[8] = &h1.b;
    page.items[9] = &h2.b;
    page.items[10] = &h3.b;
    page.items[11] = &big.b;
    page.count = 12;
    func_L39_00689670(this, &page);
    return this;
}
/* localdecomp:end func_L39_006932E8 */

LINKER_REMNANT("asm/levels", func_L39_006938E0);

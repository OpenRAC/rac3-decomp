#include "common.h"

/* localdecomp:start func_L39_006BA5C0 */
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern char D_L39_002493A8[];
typedef struct { s32 f0; u8 pad[0x24]; } T_006BA5C0;
extern T_006BA5C0 D_001FD630[];
typedef struct { u8 pad[0x60]; void **vt; } O_006BA5C0;
typedef struct {
    u8 pad0[8];
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad1C[0xC];
    s32 f28;
    s32 f2C;
    s32 f30;
    u8 pad34[0x190 - 0x34];
} I_006BA5C0;
s32 func_L39_006D6E50(void *, s32, s32, void *);
u8 *func_L39_006D31B8(void *, s32, s32);
u8 *func_L39_006D6CF8(void *, s32, s32, s32);
u8 *func_L39_006D98C8(void *, s32);
extern s32 func_L39_006D9328(void *, void *);
s32 func_L39_006DF598(f32, f32);
s32 func_00381FF0(s32);
s32 func_00120048(void *, char *, ...);

typedef void (*SetText_006BA5C0)(void *, void *);
typedef void (*Show_006BA5C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x140];
    O_006BA5C0 *objs[15];
    u8 pad17C[0x290 - 0x17C];
    u32 f290;
    u8 pad294[0x2AC - 0x294];
    s32 cur;
    s32 want;
} M_006BA5C0;

void func_L39_006BA5C0(M_006BA5C0 *arg0) {
    I_006BA5C0 info;
    char text[0x100];
    u8 *d = D_L39_0024D760;
    void *list = *(void **)(d + 0x48);
    void *db = *(void **)(d + 0x44);
    u8 *a;
    u8 *b;
    s32 state;
    s32 count;
    s32 i;

    if (arg0->f290 < 12) {
        arg0->want = D_001FD630[arg0->f290 - 1].f0;
    }
    if (arg0->want < 0) {
        O_006BA5C0 **p = arg0->objs;
        s32 n;
        for (n = 10; n >= 0; n--) {
            ((void (*)(void *))(*p)->vt[0xB4 / 4])(*p);
            p++;
        }
        ((Show_006BA5C0)arg0->objs[11]->vt[0x1C / 4])(arg0->objs[11], 0, 0);
        ((Show_006BA5C0)arg0->objs[12]->vt[0x1C / 4])(arg0->objs[12], 0, 0);
        ((Show_006BA5C0)arg0->objs[13]->vt[0x1C / 4])(arg0->objs[13], 0, 0);
        ((Show_006BA5C0)arg0->objs[14]->vt[0x1C / 4])(arg0->objs[14], 0, 0);
        return;
    }
    if (arg0->want == arg0->cur) {
        return;
    }
    arg0->cur = arg0->want;
    if (func_L39_006D6E50(db, arg0->cur, 0, &info)) {
        u8 *e = 0;
        u8 *p;

        if (info.f30 >= 0) {
            e = func_L39_006D31B8(*(void **)(d + 0x38), arg0->cur, info.f30);
        }
        if (e) {
            ((SetText_006BA5C0)arg0->objs[2]->vt[0xB8 / 4])(arg0->objs[2], e + 0x20);
        } else {
            ((SetText_006BA5C0)arg0->objs[2]->vt[0xB8 / 4])(arg0->objs[2], (void *)func_00381FF0(0x1328));
        }
        p = func_L39_006D6CF8(db, arg0->cur, 1, 0);
        if (p) {
            func_00120048(text, D_L39_002493A8, *(s32 *)(p + 0x1C));
        } else {
            text[0] = 0;
        }
        ((SetText_006BA5C0)arg0->objs[3]->vt[0xB8 / 4])(arg0->objs[3], text);
        func_00120048(text, D_L39_002493A8, info.f8);
        ((SetText_006BA5C0)arg0->objs[6]->vt[0xB8 / 4])(arg0->objs[6], text);
        func_00120048(text, D_L39_002493A8, info.fC);
        ((SetText_006BA5C0)arg0->objs[7]->vt[0xB8 / 4])(arg0->objs[7], text);
        func_00120048(text, D_L39_002493A8, info.f14);
        ((SetText_006BA5C0)arg0->objs[8]->vt[0xB8 / 4])(arg0->objs[8], text);
        func_00120048(text, D_L39_002493A8, info.f18);
        ((SetText_006BA5C0)arg0->objs[9]->vt[0xB8 / 4])(arg0->objs[9], text);
        func_00120048(text, D_L39_002493A8, info.f28);
        ((SetText_006BA5C0)arg0->objs[10]->vt[0xB8 / 4])(arg0->objs[10], text);
        func_00120048(text, D_L39_002493A8, info.f2C);
        ((SetText_006BA5C0)arg0->objs[5]->vt[0xB8 / 4])(arg0->objs[5], text);
    }
    state = 0;
    a = func_L39_006D98C8(list, arg0->cur);
    b = (u8 *)func_L39_006D9328(list, (void *)arg0->cur);
    if (a) {
        if (*(s32 *)(a + 0x40) == 0) {
            state = 3;
        } else if (*(s32 *)(a + 0x40) == 1) {
            state = 2;
        }
    } else if (b) {
        state = *(s32 *)(b + 0x40);
    }
    if (b) {
        f32 *f = (f32 *)(b + 0x48);
        count = 1;
        for (i = 3; i >= 0; i--) {
            if (0.0f < f[0]) {
                count = count > func_L39_006DF598(f[0], f[4]) ? count : func_L39_006DF598(f[0], f[4]);
            }
            f++;
        }
        ((Show_006BA5C0)arg0->objs[11]->vt[0x1C / 4])(arg0->objs[11], 0 < count, 0);
        ((Show_006BA5C0)arg0->objs[12]->vt[0x1C / 4])(arg0->objs[12], count >= 2, 0);
        ((Show_006BA5C0)arg0->objs[13]->vt[0x1C / 4])(arg0->objs[13], count >= 3, 0);
        ((Show_006BA5C0)arg0->objs[14]->vt[0x1C / 4])(arg0->objs[14], count >= 4, 0);
    }
    if (**(s32 **)(D_L39_0024D760 + 0x30) == arg0->cur) {
        ((SetText_006BA5C0)arg0->objs[0]->vt[0xB8 / 4])(arg0->objs[0], (void *)func_00381FF0(0xFAE));
        ((SetText_006BA5C0)arg0->objs[1]->vt[0xB8 / 4])(arg0->objs[1], (void *)func_00381FF0(0xFAC));
    } else if (state == 0) {
        ((SetText_006BA5C0)arg0->objs[0]->vt[0xB8 / 4])(arg0->objs[0], (void *)func_00381FF0(0xFAD));
        ((SetText_006BA5C0)arg0->objs[1]->vt[0xB8 / 4])(arg0->objs[1], (void *)func_00381FF0(0xFAD));
    } else if (state == 1) {
        ((SetText_006BA5C0)arg0->objs[0]->vt[0xB8 / 4])(arg0->objs[0], (void *)func_00381FF0(0xFAE));
        ((SetText_006BA5C0)arg0->objs[1]->vt[0xB8 / 4])(arg0->objs[1], (void *)func_00381FF0(0xF76));
    } else if (state == 2) {
        ((SetText_006BA5C0)arg0->objs[0]->vt[0xB8 / 4])(arg0->objs[0], (void *)func_00381FF0(0xFAE));
        ((SetText_006BA5C0)arg0->objs[1]->vt[0xB8 / 4])(arg0->objs[1], (void *)func_00381FF0(0xFAF));
    } else if (state == 3) {
        ((SetText_006BA5C0)arg0->objs[0]->vt[0xB8 / 4])(arg0->objs[0], (void *)func_00381FF0(0xFAE));
        ((SetText_006BA5C0)arg0->objs[1]->vt[0xB8 / 4])(arg0->objs[1], (void *)func_00381FF0(0xFB1));
    }
}
/* localdecomp:end func_L39_006BA5C0 */

LINKER_REMNANT("asm/levels", func_L39_006BAAF8);

/* localdecomp:start func_L39_006BAB00 */
typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ char label[0x34];
    /* 0x38 */ f32 x;
    /* 0x3C */ f32 y;
    /* 0x40 */ f32 w;
    /* 0x44 */ f32 h;
} Base_006BAB00;

typedef struct {
    Base_006BAB00 b;
    u8 pad48[8];
} Plain_006BAB00;

typedef struct {
    Base_006BAB00 b;
    s32 f48, f4C;
    char *text;
    s32 f54, f58, f5C, f60, f64;
    u8 pad68[8];
} List_006BAB00;

typedef struct {
    Base_006BAB00 b;
    s32 f48;
    f32 f4C;
    s32 f50;
    f32 f54;
    s32 f58;
    s32 f5C;
} Slot_006BAB00;

typedef struct {
    Base_006BAB00 b;
    s32 f48;
    s32 count;
    Base_006BAB00 *items[28];
    u8 padC0[0x110];
} Page_006BAB00;

extern char D_L39_00249468[];
extern char D_L39_00249470[];
extern char D_L39_00249478[];
extern u8 D_L39_0047E880[];
extern char *D_L39_003D2680[];
extern char D_L39_003CE740[128][0x70];
extern void *func_L39_00688388(void *);
extern void *func_L39_006CC120(void *);
extern void func_L39_0068CD28(u8 *, s32, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);

/* The menu items are C++ objects built on the stack; their constructors are inlined here.
 * Base: type 0, then the shared init (func_L39_0068CD28). */
static __inline__ void base_006BAB00(Base_006BAB00 *b, s32 label, f32 x, f32 y, f32 w, f32 h)
{
    b->type = 0;
    func_L39_0068CD28((u8 *)b, label, x, y, w, h);
}

/* plain label item (type 1) */
static __inline__ void plain_006BAB00(Plain_006BAB00 *p, s32 label, f32 x, f32 y, f32 w, f32 h)
{
    base_006BAB00(&p->b, label, x, y, w, h);
    p->b.type = 1;
}

/* list item with a text (type 5) */
static __inline__ void list_006BAB00(List_006BAB00 *l, s32 label, f32 x, f32 y, f32 w, f32 h, char *text, s32 rows, s32 sel)
{
    base_006BAB00(&l->b, label, x, y, w, h);
    l->b.type = 5;
    l->f48 = 0;
    l->f4C = 0;
    l->text = text;
    l->f54 = rows;
    l->f58 = 0;
    l->f5C = 0;
    l->f60 = sel;
    l->f64 = 0;
}

/* slot item (type 12) */
static __inline__ void slot_006BAB00(Slot_006BAB00 *s)
{
    base_006BAB00(&s->b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    s->b.type = 12;
    s->f58 = -1;
    s->f50 = 0;
    s->f48 = 0;
    s->f54 = 1.0f;
    s->f4C = 1.0f;
    s->f5C = 0x706EC8FF;
}

/* page: holds the items */
static __inline__ void page_006BAB00(Page_006BAB00 *p)
{
    base_006BAB00(&p->b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    p->f48 = 0x2E;
    p->count = 0;
    p->b.x = 0;
    p->b.y = 0;
    p->b.w = 1.0f;
    p->b.h = 1.0f;
}

void *func_L39_006BAB00(u8 *this)
{
    Plain_006BAB00 i0;
    Plain_006BAB00 i1;
    Plain_006BAB00 i2;
    List_006BAB00 l0;
    List_006BAB00 l1;
    Plain_006BAB00 i3;
    Plain_006BAB00 i4;
    Plain_006BAB00 i5;
    Plain_006BAB00 i6;
    Plain_006BAB00 i7;
    List_006BAB00 l2;
    Plain_006BAB00 i8;
    Slot_006BAB00 slots[16];
    Page_006BAB00 page;
    s32 i;

    func_L39_00688388(this);
    *(u8 **)(this + 0x60) = D_L39_0047E880;
    func_L39_006CC120(this + 0x8590);
    *(u8 **)(this + 0x2A4) = this + 0x8768;

    plain_006BAB00(&i0, (s32)D_L39_00249468, 0.31f, 0.18f, 0.42f, 0.04f);
    plain_006BAB00(&i1, (s32)D_L39_00249470, 0.11f, 0.18f, 0.42f, 0.04f);
    plain_006BAB00(&i2, (s32)D_L39_00249478, 0.51f, 0.18f, 0.42f, 0.04f);
    list_006BAB00(&l0, (s32)D_L39_00249468, 0.725f, 0.685f, 0.329f, 0.34f, (char *)func_00381FF0(0x1015), 7, 1);
    list_006BAB00(&l1, (s32)D_L39_00249468, 0.725f, 0.315f, 0.329f, 0.225f, (char *)func_00381FF0(0x1016), 4, 1);
    plain_006BAB00(&i3, func_00381FF0(0x1006), 0.5595f, 0.173f, 0.34f, 0.03f);
    plain_006BAB00(&i4, func_00381FF0(0x1005), 0.5595f, 0.48f, 0.34f, 0.03f);
    plain_006BAB00(&i5, func_00381FF0(0xF85), 0.31f, 0.71f, 0.42f, 0.04f);
    plain_006BAB00(&i6, func_00381FF0(0xF83), 0.31f, 0.772f, 0.42f, 0.04f);
    plain_006BAB00(&i7, func_00381FF0(0xF82), 0.31f, 0.83f, 0.42f, 0.04f);
    list_006BAB00(&l2, (s32)D_L39_00249468, 0.31f, 0.44f, 0.4f, 0.44f, (char *)func_00381FF0(0xF87), 10, -1);
    plain_006BAB00(&i8, func_00381FF0(0x1607), 0.885f, 0.173f, 0.3f, 0.05f);

    {
        Slot_006BAB00 *p = slots;
        s32 n;
        for (n = 15; n != -1; n--) {
            slot_006BAB00(p);
            p++;
        }
    }

    page_006BAB00(&page);
    page.count = 0x1C;
    page.items[0] = &i0.b;
    page.items[1] = &i1.b;
    page.items[2] = &i2.b;
    page.items[10] = &l0.b;
    page.items[8] = &l1.b;
    page.items[6] = &i7.b;
    page.items[5] = &i6.b;
    page.items[4] = &i5.b;
    page.items[3] = &l2.b;
    page.items[9] = &i4.b;
    page.items[7] = &i3.b;
    page.items[11] = &i8.b;
    for (i = 0; i < 16; i++) {
        slots[i].f58 = 0xED26;
        page.items[12 + i] = &slots[i].b;
    }
    func_L39_00689670(this, &page);

    for (i = 127; i >= 0; i--) {
        D_L39_003D2680[i] = D_L39_003CE740[i];
    }
    *(s32 *)(this + 0x290) = 0;
    return this;
}
/* localdecomp:end func_L39_006BAB00 */

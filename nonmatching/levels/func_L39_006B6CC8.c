/* NTSC-U draft (Codex wave 3): C of func_L39_006B4360, the NTSC-U twin of func_L39_006B6CC8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 72 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_006B4360", whose code is not the PAL one).
 * Worker's note: 72 diff; 13 compiles, three wordings identical complete diffs in check10/check12/check13; stack layout and constructor sequence decoded; prologue address hoisting, f20/f21 allocation, init store/copy register scheduling remain; best log ...
 */
#include "common.h"

/* localdecomp:start func_L39_006B4360 */
typedef struct { s32 kind; u8 pad04[0x34]; f32 x, y, w, h; } B_006B4360;
typedef struct {
    B_006B4360 b;
    s32 id, count;
    void *children[10];
    u8 pad78[0x158];
} Root_006B4360;
typedef struct {
    B_006B4360 b;
    u8 flag48;
    u8 pad49[0xC7];
    s32 val110;
    u8 flag114, flag115, flag116;
    u8 pad117[9];
} Large_006B4360;
typedef struct { B_006B4360 b; u8 pad48[8]; } Small_006B4360;
typedef struct { char *a, *b, *c; } Strings_006B4360;
typedef struct {
    B_006B4360 b;
    s32 count;
    Strings_006B4360 *options;
    s32 value;
    u8 pad54[0x1C];
} Select_006B4360;
typedef struct {
    B_006B4360 b;
    s32 value, max, current, limit;
    u8 pad58[8];
} Number_006B4360;
typedef struct { B_006B4360 b; char text[80]; u8 pad98[8]; } Text_006B4360;
extern u8 D_L39_0047E740[];
extern char D_L39_002492B0[];
extern char D_L39_002492B8[];
extern char D_L39_002492C0[];
extern f32 D_L39_004B1480[];
extern f32 D_L39_004B1520[];
extern void func_L39_006857E0(void *);
extern void func_L39_0068A638(void *, char *, f32, f32, f32, f32);
extern char *func_0037DF98(s32);
extern void func_00120D28(void *, void *, s32);
extern void func_L39_00686AC8(void *, void *);

static __inline__ void base_006B4360(B_006B4360 *b, char *text, f32 x, f32 y, f32 w, f32 h) {
    b->kind = 0;
    func_L39_0068A638(b, text, x, y, w, h);
}

static __inline__ Large_006B4360 *large_006B4360(Large_006B4360 *p, char *text, f32 x, f32 y, f32 w, f32 h, s32 mode, s32 enabled) {
    base_006B4360(&p->b, text, x, y, w, h);
    p->b.kind = 8;
    p->flag48 = 0;
    p->flag114 = mode;
    p->val110 = 15;
    p->flag115 = enabled;
    p->flag116 = 0;
    return p;
}
static __inline__ Small_006B4360 *small_006B4360(Small_006B4360 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006B4360(&p->b, text, x, y, w, h);
    p->b.kind = 1;
    return p;
}
static __inline__ Small_006B4360 *small2_006B4360(Small_006B4360 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006B4360(&p->b, text, x, y, w, h);
    p->b.kind = 2;
    return p;
}
static __inline__ Select_006B4360 *select_006B4360(Select_006B4360 *p, char *text, f32 x, f32 y, f32 w, f32 h, Strings_006B4360 *options) {
    base_006B4360(&p->b, text, x, y, w, h);
    p->b.kind = 3;
    p->count = 3;
    p->options = options;
    p->value = 0;
    return p;
}
static __inline__ Select_006B4360 *select_empty_006B4360(Select_006B4360 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006B4360(&p->b, text, x, y, w, h);
    p->b.kind = 3;
    p->count = 0;
    p->options = 0;
    p->value = 0;
    return p;
}
static __inline__ Number_006B4360 *number_006B4360(Number_006B4360 *p, char *text, f32 x, f32 y, f32 w, f32 h, s32 maximum, s32 limit) {
    base_006B4360(&p->b, text, x, y, w, h);
    p->b.kind = 10;
    p->value = 0;
    p->max = maximum;
    p->current = maximum;
    p->limit = limit;
    return p;
}
static __inline__ Text_006B4360 *text_006B4360(Text_006B4360 *p, char *label, f32 x, f32 y, f32 w, f32 h, char *value) {
    base_006B4360(&p->b, label, x, y, w, h);
    p->b.kind = 7;
    if (value) {
        func_00120D28(p->text, value, 79);
        p->text[79] = 0;
    } else p->text[0] = 0;
    return p;
}

static __inline__ void root_006B4360(Root_006B4360 *p) {
    base_006B4360(&p->b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    p->id = 46;
    p->b.x = 0.0f;
    p->b.y = 0.0f;
    p->b.w = 1.0f;
    p->b.h = 1.0f;
    p->count = 10;
}

static __inline__ f32 next_row_006B4360(f32 y, f32 step) {
    return y + step;
}

void *func_L39_006B4360(u8 *self) {
    Root_006B4360 root;
    Large_006B4360 a;
    Small_006B4360 b;
    Small_006B4360 c;
    Large_006B4360 d;
    Strings_006B4360 options;
    Strings_006B4360 tmp;
    Select_006B4360 e;
    Number_006B4360 n;
    Text_006B4360 t;
    Small_006B4360 f;
    Select_006B4360 g;
    Text_006B4360 t2;
    f32 y;
    f32 step;
    s32 one = 1;
    func_L39_006857E0(self);
    *(void **)(self + 0x60) = D_L39_0047E740;
    *(void **)(self + 0x2A4) = self + 0x2C8;
    root_006B4360(&root);
    y = D_L39_004B1480[1];
    root.children[0] = large_006B4360(&a, func_0037DF98(0xF5C), D_L39_004B1480[0], y, D_L39_004B1480[2], D_L39_004B1480[3], 0, one);
    step = D_L39_004B1480[5];
    y = next_row_006B4360(y, step);
    root.children[1] = small_006B4360(&b, func_0037DF98(0x18C8), D_L39_004B1480[0], y, D_L39_004B1480[2], D_L39_004B1480[3]);
    y = next_row_006B4360(y, step);
    root.children[2] = small2_006B4360(&c, func_0037DF98(0x10CD), D_L39_004B1480[0], y, D_L39_004B1480[2], D_L39_004B1480[3]);
    y = next_row_006B4360(y, step);
    root.children[3] = large_006B4360(&d, func_0037DF98(0xF5D), D_L39_004B1480[0], y, D_L39_004B1480[2], D_L39_004B1480[3], one, one);
    y = next_row_006B4360(y, step);
    tmp.a = D_L39_002492B8;
    tmp.b = D_L39_002492C0;
    tmp.c = func_0037DF98(0x10CC);
    options = tmp;
    root.children[4] = select_006B4360(&e, func_0037DF98(0x10CB), D_L39_004B1480[0], y, D_L39_004B1480[2], D_L39_004B1480[3], &options);
    y = next_row_006B4360(y, step);
    root.children[9] = number_006B4360(&n, D_L39_002492B0, D_L39_004B1480[0], y, D_L39_004B1480[2], D_L39_004B1480[3], 1024, 64);
    root.children[7] = text_006B4360(&t, func_0037DF98(0x234), D_L39_004B1480[0], y, D_L39_004B1480[2], D_L39_004B1480[3], D_L39_002492B0);
    step = D_L39_004B1480[5];
    y = next_row_006B4360(y, step);
    root.children[5] = small2_006B4360(&f, func_0037DF98(0x10CE), D_L39_004B1480[0], y, D_L39_004B1480[2], D_L39_004B1480[3]);
    y = next_row_006B4360(y, step);
    root.children[6] = select_empty_006B4360(&g, func_0037DF98(0x1632), D_L39_004B1480[0], y, D_L39_004B1480[2], D_L39_004B1480[3]);
    root.children[8] = text_006B4360(&t2, D_L39_002492B0, D_L39_004B1520[0], D_L39_004B1520[1], D_L39_004B1520[2], D_L39_004B1520[3], D_L39_002492B0);
    func_L39_00686AC8(self, &root);
    return self;
}
/* localdecomp:end func_L39_006B4360 */

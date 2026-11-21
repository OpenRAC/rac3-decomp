/* functional: high. Multiplayer create-game / settings menu constructor: builds an 11-child widget tree on the stack (4 buttons, a 3-option select, a number field, a text field, an empty select, a 2-option select and a second text field) and hands it to the menu builder. Ported from the NTSC twin draft; PAL has one more select and text widget and different child order, rechecked against asm. Not byte exact (stack temp layout, frame 0x870 vs 0x880); helper structs are widget layouts inferred from stores. */
typedef struct { s32 kind; u8 pad04[0x34]; f32 x, y, w, h; } B_006B6CC8;
typedef struct {
    B_006B6CC8 b;
    s32 id, count;
    void *children[11];
    u8 pad7C[0x154];
} Root_006B6CC8;
typedef struct {
    B_006B6CC8 b;
    u8 flag48;
    u8 pad49[0xC7];
    s32 val110;
    u8 flag114, flag115, flag116;
    u8 pad117[9];
} Large_006B6CC8;
typedef struct { B_006B6CC8 b; u8 pad48[8]; } Small_006B6CC8;
typedef struct { char *a, *b, *c; } Strings_006B6CC8;
typedef struct { char *a, *b; } Strings2_006B6CC8;
typedef struct {
    B_006B6CC8 b;
    s32 count;
    Strings_006B6CC8 *options;
    s32 value;
    u8 pad54[0x1C];
} Select_006B6CC8;
typedef struct {
    B_006B6CC8 b;
    s32 value, max, current, limit;
    u8 pad58[8];
} Number_006B6CC8;
typedef struct { B_006B6CC8 b; char text[80]; u8 pad98[8]; } Text_006B6CC8;
extern u8 D_L39_0047E680[];
extern char D_L39_00249170[];
extern f32 D_L39_004B1600[];
extern f32 D_L39_004B16B8[];
extern f32 D_L39_004B16F0[];
extern void func_L39_00688388(void *);
extern void func_L39_0068CD28(void *, char *, f32, f32, f32, f32);
extern char *func_00381FF0(s32);
extern void func_00120D28(void *, void *, s32);
extern void func_L39_00689670(void *, void *);

static __inline__ void base_006B6CC8(B_006B6CC8 *b, char *text, f32 x, f32 y, f32 w, f32 h) {
    b->kind = 0;
    func_L39_0068CD28(b, text, x, y, w, h);
}

static __inline__ Large_006B6CC8 *large_006B6CC8(Large_006B6CC8 *p, char *text, f32 x, f32 y, f32 w, f32 h, s32 mode, s32 enabled) {
    base_006B6CC8(&p->b, text, x, y, w, h);
    p->b.kind = 8;
    p->flag48 = 0;
    p->flag114 = mode;
    p->val110 = 15;
    p->flag115 = enabled;
    p->flag116 = 0;
    return p;
}
static __inline__ Small_006B6CC8 *small_006B6CC8(Small_006B6CC8 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006B6CC8(&p->b, text, x, y, w, h);
    p->b.kind = 1;
    return p;
}
static __inline__ Small_006B6CC8 *small2_006B6CC8(Small_006B6CC8 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006B6CC8(&p->b, text, x, y, w, h);
    p->b.kind = 2;
    return p;
}
static __inline__ Select_006B6CC8 *select_006B6CC8(Select_006B6CC8 *p, char *text, f32 x, f32 y, f32 w, f32 h, s32 count, void *options) {
    base_006B6CC8(&p->b, text, x, y, w, h);
    p->b.kind = 3;
    p->count = count;
    p->options = options;
    p->value = 0;
    return p;
}
static __inline__ Select_006B6CC8 *select_empty_006B6CC8(Select_006B6CC8 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006B6CC8(&p->b, text, x, y, w, h);
    p->b.kind = 3;
    p->count = 0;
    p->options = 0;
    p->value = 0;
    return p;
}
static __inline__ Number_006B6CC8 *number_006B6CC8(Number_006B6CC8 *p, char *text, f32 x, f32 y, f32 w, f32 h, s32 maximum, s32 limit) {
    base_006B6CC8(&p->b, text, x, y, w, h);
    p->b.kind = 10;
    p->value = 0;
    p->max = maximum;
    p->current = maximum;
    p->limit = limit;
    return p;
}
static __inline__ Text_006B6CC8 *text_006B6CC8(Text_006B6CC8 *p, char *label, f32 x, f32 y, f32 w, f32 h, char *value) {
    base_006B6CC8(&p->b, label, x, y, w, h);
    p->b.kind = 7;
    if (value) {
        func_00120D28(p->text, value, 79);
        p->text[79] = 0;
    } else p->text[0] = 0;
    return p;
}

static __inline__ void root_006B6CC8(Root_006B6CC8 *p) {
    base_006B6CC8(&p->b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    p->id = 46;
    p->b.x = 0.0f;
    p->b.y = 0.0f;
    p->b.w = 1.0f;
    p->b.h = 1.0f;
    p->count = 11;
}

static __inline__ f32 next_row_006B6CC8(f32 y, f32 step) {
    return y + step;
}

void *func_L39_006B6CC8(u8 *self) {
    Root_006B6CC8 root;
    Large_006B6CC8 a;
    Small_006B6CC8 b;
    Small_006B6CC8 c;
    Large_006B6CC8 d;
    Strings_006B6CC8 options;
    Strings2_006B6CC8 options2;
    Select_006B6CC8 e;
    Number_006B6CC8 n;
    Text_006B6CC8 t;
    Small_006B6CC8 f;
    Select_006B6CC8 g;
    Select_006B6CC8 h;
    Text_006B6CC8 t2;
    f32 y;
    f32 step;
    s32 one = 1;
    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047E680;
    *(void **)(self + 0x2A4) = self + 0x2C8;
    root_006B6CC8(&root);
    y = D_L39_004B1600[1];
    root.children[0] = large_006B6CC8(&a, func_00381FF0(0xF5C), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3], 0, one);
    step = D_L39_004B1600[5];
    y = y + step;
    root.children[1] = small_006B6CC8(&b, func_00381FF0(0x18C8), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3]);
    y = y + step;
    root.children[2] = small2_006B6CC8(&c, func_00381FF0(0x10CD), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3]);
    y = y + step;
    root.children[3] = large_006B6CC8(&d, func_00381FF0(0xF5D), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3], one, one);
    y = y + step;
    options.a = func_00381FF0(9);
    options.b = func_00381FF0(0x10C2);
    options.c = func_00381FF0(0x10CC);
    root.children[4] = select_006B6CC8(&e, func_00381FF0(0x10CB), D_L39_004B1600[0], y, 0.2f, 0.21f, 3, &options);
    y = y + step;
    root.children[10] = number_006B6CC8(&n, D_L39_00249170, D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3], 1024, 64);
    root.children[7] = text_006B6CC8(&t, func_00381FF0(0x234), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3], D_L39_00249170);
    step = D_L39_004B1600[5];
    y = y + step;
    root.children[5] = small2_006B6CC8(&f, func_00381FF0(0x10CE), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3]);
    y = y + step;
    root.children[6] = select_empty_006B6CC8(&g, func_00381FF0(0x1632), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3]);
    options2.a = func_00381FF0(0x1944);
    options2.b = func_00381FF0(0x1943);
    root.children[8] = select_006B6CC8(&h, func_00381FF0(0x1945), D_L39_004B16B8[0], D_L39_004B16B8[1], D_L39_004B16B8[2], D_L39_004B16B8[3], 2, &options2);
    root.children[9] = text_006B6CC8(&t2, D_L39_00249170, D_L39_004B16F0[0], D_L39_004B16F0[1], D_L39_004B16F0[2], D_L39_004B16F0[3], D_L39_00249170);
    func_L39_00689670(self, &root);
    return self;
}

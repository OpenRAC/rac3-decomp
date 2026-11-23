/* functional: high. Multiplayer lobby main screen constructor: 27-widget tree. 12 text rows down the left panel (rect D_L39_00249364..70, row k centred at (k-5.5)/12 of the height minus border), 11 large widgets (kind 8, id 0x20) down the right panel (rect 0x249374..80, (k-5)/11), and four coloured quads (kind 12, colour 0x706EC8FF) in a row below, all positioned from gp-relative layout floats (level gp 0x247FC0: D_L39_00249364.. 0x2493A0) and handed to the menu builder. Unrolled in retail with the same formula per widget; written as loops here (call order and values the same). Widget structs inferred from stores. Not byte exact (frame size/stack layout). */
typedef struct { s32 kind; u8 pad04[0x34]; f32 x, y, w, h; } B_006B9008;
typedef struct {
    B_006B9008 b;
    s32 id, count;
    void *children[27];
    u8 padBC[0x114];
} Root_006B9008;
typedef struct {
    B_006B9008 b;
    u8 flag48;
    u8 pad49[0xC7];
    s32 val110;
    u8 flag114, flag115, flag116;
    u8 pad117[9];
} Large_006B9008;
typedef struct { B_006B9008 b; u8 pad48[8]; } Small_006B9008;
typedef struct { char *a, *b, *c; } Strings_006B9008;
typedef struct { char *a, *b; } Strings2_006B9008;
typedef struct {
    B_006B9008 b;
    s32 count;
    Strings_006B9008 *options;
    s32 value;
    u8 pad54[0x1C];
} Select_006B9008;
typedef struct {
    B_006B9008 b;
    s32 value, max, current, limit;
    u8 pad58[8];
} Number_006B9008;
typedef struct { B_006B9008 b; char text[80]; u8 pad98[8]; } Text_006B9008;
extern u8 D_L39_0047E780[];
__asm__(".extern D_L39_00249364, 4");
__asm__(".extern D_L39_00249368, 4");
__asm__(".extern D_L39_0024936C, 4");
__asm__(".extern D_L39_00249370, 4");
__asm__(".extern D_L39_00249374, 4");
__asm__(".extern D_L39_00249378, 4");
__asm__(".extern D_L39_0024937C, 4");
__asm__(".extern D_L39_00249380, 4");
__asm__(".extern D_L39_00249384, 4");
__asm__(".extern D_L39_00249388, 4");
__asm__(".extern D_L39_0024938C, 4");
__asm__(".extern D_L39_002493A0, 4");
extern f32 D_L39_00249364;
extern f32 D_L39_00249368;
extern f32 D_L39_0024936C;
extern f32 D_L39_00249370;
extern f32 D_L39_00249374;
extern f32 D_L39_00249378;
extern f32 D_L39_0024937C;
extern f32 D_L39_00249380;
extern f32 D_L39_00249384;
extern f32 D_L39_00249388;
extern f32 D_L39_0024938C;
extern char D_L39_002493A0[];
extern void func_L39_00688388(void *);
extern void func_L39_0068CD28(void *, char *, f32, f32, f32, f32);
extern char *func_00381FF0(s32);
extern void func_00120D28(void *, void *, s32);
extern void func_L39_00689670(void *, void *);

static __inline__ void base_006B9008(B_006B9008 *b, char *text, f32 x, f32 y, f32 w, f32 h) {
    b->kind = 0;
    func_L39_0068CD28(b, text, x, y, w, h);
}

static __inline__ Large_006B9008 *large_006B9008(Large_006B9008 *p, char *text, f32 x, f32 y, f32 w, f32 h, s32 mode, s32 enabled, s32 val) {
    base_006B9008(&p->b, text, x, y, w, h);
    p->b.kind = 8;
    p->flag48 = 0;
    p->flag114 = mode;
    p->val110 = val;
    p->flag115 = enabled;
    p->flag116 = 0;
    return p;
}
static __inline__ Small_006B9008 *small_006B9008(Small_006B9008 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006B9008(&p->b, text, x, y, w, h);
    p->b.kind = 1;
    return p;
}
static __inline__ Small_006B9008 *small2_006B9008(Small_006B9008 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006B9008(&p->b, text, x, y, w, h);
    p->b.kind = 2;
    return p;
}
static __inline__ Select_006B9008 *select_006B9008(Select_006B9008 *p, char *text, f32 x, f32 y, f32 w, f32 h, s32 count, void *options) {
    base_006B9008(&p->b, text, x, y, w, h);
    p->b.kind = 3;
    p->count = count;
    p->options = options;
    p->value = 0;
    return p;
}
static __inline__ Select_006B9008 *select_empty_006B9008(Select_006B9008 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006B9008(&p->b, text, x, y, w, h);
    p->b.kind = 3;
    p->count = 0;
    p->options = 0;
    p->value = 0;
    return p;
}
static __inline__ Number_006B9008 *number_006B9008(Number_006B9008 *p, char *text, f32 x, f32 y, f32 w, f32 h, s32 maximum, s32 limit) {
    base_006B9008(&p->b, text, x, y, w, h);
    p->b.kind = 10;
    p->value = 0;
    p->max = maximum;
    p->current = maximum;
    p->limit = limit;
    return p;
}
static __inline__ Text_006B9008 *text_006B9008(Text_006B9008 *p, char *label, f32 x, f32 y, f32 w, f32 h, char *value) {
    base_006B9008(&p->b, label, x, y, w, h);
    p->b.kind = 7;
    if (value) {
        func_00120D28(p->text, value, 79);
        p->text[79] = 0;
    } else p->text[0] = 0;
    return p;
}

typedef struct { B_006B9008 b; f32 f48, f4C, f50, f54; u32 f58, f5C; } Quad_006B9008;
static __inline__ Quad_006B9008 *quad_006B9008(Quad_006B9008 *p, f32 x, f32 y, f32 w, f32 h) {
    base_006B9008(&p->b, D_L39_002493A0, x, y, w, h);
    p->b.kind = 12;
    p->f48 = 0.0f;
    p->f4C = 1.0f;
    p->f50 = 0.0f;
    p->f54 = 1.0f;
    p->f58 = 0xED26;
    p->f5C = 0x706EC8FF;
    return p;
}

static __inline__ void root_006B9008(Root_006B9008 *p) {
    base_006B9008(&p->b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    p->id = 46;
    p->b.x = 0.0f;
    p->b.y = 0.0f;
    p->b.w = 1.0f;
    p->b.h = 1.0f;
    p->count = 27;
}

static __inline__ f32 next_row_006B9008(f32 y, f32 step) {
    return y + step;
}

void *func_L39_006B9008(u8 *self) {
    Root_006B9008 root;
    Small_006B9008 rows[12];
    Large_006B9008 big[11];
    Quad_006B9008 quad[4];
    f32 b;
    f32 x;
    f32 y;
    f32 w;
    f32 c;
    f32 T;
    f32 sp;
    s32 i;
    s32 ids[11];
    f32 bigc[11];

    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047E780;
    *(void **)(self + 0x2A4) = self + 0x2B4;

    b = D_L39_00249384;
    ids[0] = 0xF8A;  ids[1] = 0x10FC; ids[2] = 0x1322; ids[3] = 0x1101; ids[4] = 0x160B;
    ids[5] = 0x12A4; ids[6] = 0x1334; ids[7] = 0x1335; ids[8] = 0x1336; ids[9] = 0x1337;
    ids[10] = 0x133E;

    /* 12 rows laid out down the left panel (rect 1): row k at centre offset (k - 5.5) / 12 of (h - b) */
    for (i = 0; i < 12; i++) {
        char *text = (i == 0) ? func_00381FF0(0x10ED) : D_L39_002493A0;
        c = (f32)i - 5.5f;
        x = D_L39_00249364 - D_L39_0024936C * 0.5f + b;
        y = D_L39_00249368 + (D_L39_00249370 - b) * c / 12.0f;
        w = D_L39_0024936C - (b + b);
        small_006B9008(&rows[i], text, x, y, w, 0.05f);
    }
    /* 11 big widgets down the right panel (rect 2): widget k at (k - 5) / 11 of (h - b) */
    for (i = 0; i < 11; i++) {
        c = (f32)i - 5.0f;
        x = D_L39_00249374 - D_L39_0024937C * 0.5f + b;
        y = D_L39_00249378 + (D_L39_00249380 - b) * c / 11.0f;
        w = D_L39_0024937C - (b + b);
        large_006B9008(&big[i], func_00381FF0(ids[i]), x, y, w, 0.05f, 0, 0, 0x20);
    }
    /* four coloured quads in a row along the bottom of the right panel */
    T = D_L39_00249388;
    sp = T + 0.01f;
    y = D_L39_00249378 + (-(D_L39_00249380 - b)) / 11.0f;
    for (i = 0; i < 4; i++) {
        x = D_L39_00249374 + (D_L39_0024937C * 0.5f - b - T * 0.5f) - sp * (f32)i;
        quad_006B9008(&quad[i], x, y, T, D_L39_0024938C);
    }

    root_006B9008(&root);
    for (i = 0; i < 12; i++) {
        root.children[i] = &rows[i];
    }
    for (i = 0; i < 11; i++) {
        root.children[12 + i] = &big[i];
    }
    for (i = 0; i < 4; i++) {
        root.children[23 + i] = &quad[i];
    }
    func_L39_00689670(self, &root);
    return self;
}

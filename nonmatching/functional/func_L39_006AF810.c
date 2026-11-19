/* functional: high. Multiplayer settings screen constructor: 15 stack widgets (3 labels, four 8-option selects in a row, four 7-option selects, four labels) in a root, handed to the menu builder, then calls vtable slot 0x1C of the object at self+0x114 with (0,0). Widgets are all one Select-sized cell here (retail packs the labels in 0x50 byte cells); only kinds, fields and creation order matter. Float rect constants and string ids rechecked against asm; D_L39_00248C9C/CFC/CAC/CB0 are level-$gp-relative floats (level gp 0x247FC0). Not byte exact. */
typedef struct { s32 kind; u8 pad04[0x34]; f32 x, y, w, h; } B_006AF810;
typedef struct {
    B_006AF810 b;
    s32 id, count;
    void *children[15];
    u8 pad8C[0x144];
} Root_006AF810;
typedef struct {
    B_006AF810 b;
    u8 flag48;
    u8 pad49[0xC7];
    s32 val110;
    u8 flag114, flag115, flag116;
    u8 pad117[9];
} Large_006AF810;
typedef struct { B_006AF810 b; u8 pad48[8]; } Small_006AF810;
typedef struct { char *a, *b, *c; } Strings_006AF810;
typedef struct { char *a, *b; } Strings2_006AF810;
typedef struct {
    B_006AF810 b;
    s32 count;
    Strings_006AF810 *options;
    s32 value;
    u8 pad54[0x1C];
} Select_006AF810;
typedef struct {
    B_006AF810 b;
    s32 value, max, current, limit;
    u8 pad58[8];
} Number_006AF810;
typedef struct { B_006AF810 b; char text[80]; u8 pad98[8]; } Text_006AF810;
extern u8 D_L39_0047DFA0[];
extern char D_L39_00248D38[];
__asm__(".extern D_L39_00248C9C, 4");
__asm__(".extern D_L39_00248CFC, 4");
__asm__(".extern D_L39_00248CAC, 4");
__asm__(".extern D_L39_00248CB0, 4");
extern f32 D_L39_00248C9C;
extern f32 D_L39_00248CFC;
extern f32 D_L39_00248CAC;
extern f32 D_L39_00248CB0;
extern void func_L39_00688388(void *);
extern void func_L39_0068CD28(void *, char *, f32, f32, f32, f32);
extern char *func_00381FF0(s32);
extern void func_00120D28(void *, void *, s32);
extern void func_L39_00689670(void *, void *);

static __inline__ void base_006AF810(B_006AF810 *b, char *text, f32 x, f32 y, f32 w, f32 h) {
    b->kind = 0;
    func_L39_0068CD28(b, text, x, y, w, h);
}

static __inline__ Large_006AF810 *large_006AF810(Large_006AF810 *p, char *text, f32 x, f32 y, f32 w, f32 h, s32 mode, s32 enabled) {
    base_006AF810(&p->b, text, x, y, w, h);
    p->b.kind = 8;
    p->flag48 = 0;
    p->flag114 = mode;
    p->val110 = 15;
    p->flag115 = enabled;
    p->flag116 = 0;
    return p;
}
static __inline__ Small_006AF810 *small_006AF810(Small_006AF810 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006AF810(&p->b, text, x, y, w, h);
    p->b.kind = 1;
    return p;
}
static __inline__ Small_006AF810 *small2_006AF810(Small_006AF810 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006AF810(&p->b, text, x, y, w, h);
    p->b.kind = 2;
    return p;
}
static __inline__ Select_006AF810 *select_006AF810(Select_006AF810 *p, char *text, f32 x, f32 y, f32 w, f32 h, s32 count, void *options) {
    base_006AF810(&p->b, text, x, y, w, h);
    p->b.kind = 3;
    p->count = count;
    p->options = options;
    p->value = 0;
    return p;
}
static __inline__ Select_006AF810 *select_empty_006AF810(Select_006AF810 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006AF810(&p->b, text, x, y, w, h);
    p->b.kind = 3;
    p->count = 0;
    p->options = 0;
    p->value = 0;
    return p;
}
static __inline__ Number_006AF810 *number_006AF810(Number_006AF810 *p, char *text, f32 x, f32 y, f32 w, f32 h, s32 maximum, s32 limit) {
    base_006AF810(&p->b, text, x, y, w, h);
    p->b.kind = 10;
    p->value = 0;
    p->max = maximum;
    p->current = maximum;
    p->limit = limit;
    return p;
}
static __inline__ Text_006AF810 *text_006AF810(Text_006AF810 *p, char *label, f32 x, f32 y, f32 w, f32 h, char *value) {
    base_006AF810(&p->b, label, x, y, w, h);
    p->b.kind = 7;
    if (value) {
        func_00120D28(p->text, value, 79);
        p->text[79] = 0;
    } else p->text[0] = 0;
    return p;
}

static __inline__ void root_006AF810(Root_006AF810 *p) {
    base_006AF810(&p->b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    p->id = 46;
    p->b.x = 0.0f;
    p->b.y = 0.0f;
    p->b.w = 1.0f;
    p->b.h = 1.0f;
    p->count = 15;
}

static __inline__ f32 next_row_006AF810(f32 y, f32 step) {
    return y + step;
}

typedef void (*Vf_006AF810)(void *, s32, s32);

void *func_L39_006AF810(u8 *self) {
    Root_006AF810 root;
    Select_006AF810 w[15];
    char *opts8[8];
    char *opts7[7];
    f32 y1, y2, y3, step, x;
    s32 i;
    s32 one = 1;
    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047DFA0;
    opts7[0] = func_00381FF0(0xF22);
    opts7[1] = func_00381FF0(0xF23);
    opts7[2] = func_00381FF0(0xF24);
    opts7[3] = func_00381FF0(0xF25);
    opts7[4] = func_00381FF0(0xF26);
    opts7[5] = func_00381FF0(0xF27);
    opts7[6] = func_00381FF0(0xF28);
    for (i = 0; i < 8; i++) {
        opts8[i] = func_00381FF0(0xF1A + i);
    }
    *(void **)(self + 0x2A4) = self + 0x2A8;
    y1 = 0.6f;
    y2 = 0.65f;
    y3 = 0.7f;
    x = 0.1f;
    step = D_L39_00248CFC;
    /* w[0..2]: three plain labels */
    small_006AF810((Small_006AF810 *)&w[0], D_L39_00248D38, D_L39_00248C9C, 0.25f, 1.0f, 1.0f);
    small_006AF810((Small_006AF810 *)&w[1], func_00381FF0(0x1330), 0.5f, 0.5f, 3.0f, 3.0f);
    small_006AF810((Small_006AF810 *)&w[2], func_00381FF0(0xFF9), D_L39_00248CAC, D_L39_00248CB0, 1.0f, 1.0f);
    /* w[3..6]: four selects of 8 options in a row, x advancing by step; w[6] is followed by a reset of x */
    for (i = 3; i < 7; i++) {
        select_006AF810(&w[i], func_00381FF0(0xF12), x, y1, 0.5f, 0.05f, 8, opts8);
        if (i < 6) {
            x = step + x;
        } else {
            x = 0.1f;
        }
    }
    /* w[7..10]: four selects of 7 options at y2 */
    for (i = 7; i < 11; i++) {
        select_006AF810(&w[i], func_00381FF0(0xF13), x, y2, 0.5f, 0.05f, 7, opts7);
        x = x + step;
        if (i == 10) {
            x = 0.1f;
        }
    }
    /* w[11..14]: four labels at y3 */
    for (i = 11; i < 15; i++) {
        small_006AF810((Small_006AF810 *)&w[i], func_00381FF0(0x1102), x, y3, 1.0f, 1.0f);
        x = x + step;
    }
    root_006AF810(&root);
    for (i = 0; i < 15; i++) {
        root.children[i] = &w[i];
    }
    func_L39_00689670(self, &root);
    (*(Vf_006AF810 *)(*(u8 **)(*(u8 **)(self + 0x114) + 0x60) + 0x1C))(*(u8 **)(self + 0x114), 0, 0);
    return self;
}

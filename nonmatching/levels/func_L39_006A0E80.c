/* PAL near miss (wave 13 r26), the first draft of func_L39_006A0E80 (fresh entry; from the functional C and
 * retail, in the style of the level's other menu builders): the four option arrays built in a temporary and
 * copied, the selects/text/labels/spin/cells as inline constructors over func_L39_0068CD28, a 13-entry root.
 * Nested blocks give retail's stack layout (the option temporaries at 0x30/0x40/0x60/0x90 freed and reused,
 * the one-entry array at 0x7E0 after the root). 467 diff under the file's line: retail builds its ~45 float
 * constants with lui/ori/mtc1 (Ps2EeAs li.s, an @ps2as line) where this line's GNU as loads them from the gp
 * literal pool (1 row instead of 3 each, which shifts all later rows). Besides those: the %hi of
 * D_L39_002485E0 is hoisted to the prologue in retail, the spill slots of color / &l0 / &l1 are in another
 * order (retail 0x7EC / 0x7E4 / 0x7E8), the cells store tex/v0/v1/color through their pointer register where
 * this stores color sp-relative, and a few temporaries of the struct copies use other registers.
 */
#include "common.h"

/* localdecomp:start func_L39_006A0E80 */
typedef struct { s32 kind; u8 pad04[0x34]; f32 x, y, w, h; } B_006A0E80;
typedef struct {
    B_006A0E80 b;
    s32 id, count;
    void *children[13];
    u8 pad84[0x14C];
} Root_006A0E80;
typedef struct {
    B_006A0E80 b;
    s32 count;
    void *options;
    s32 value;
    u8 pad54[0x1C];
} Select_006A0E80;
typedef struct { B_006A0E80 b; u8 pad48[8]; } Small_006A0E80;
typedef struct { B_006A0E80 b; char text[80]; u8 pad98[8]; } Text_006A0E80;
typedef struct {
    B_006A0E80 b;
    s32 f48, f4C;
    char *label;
    s32 max;
    s32 f58, f5C;
    s32 sel;
    s32 f64;
    u8 pad68[8];
} Spin_006A0E80;
typedef struct {
    B_006A0E80 b;
    f32 u0, v0, u1, v1;
    s32 tex;
    u32 color;
} Cell_006A0E80;
typedef struct { char *s[11]; } Strings11_006A0E80;
typedef struct { char *s[4]; } Strings4_006A0E80;
typedef struct { char *s[2]; } Strings2_006A0E80;
typedef struct { char *s[8]; } Strings8_006A0E80;
typedef struct { char *s[1]; } Strings1_006A0E80;
extern u8 D_L39_0047D730[];
extern char D_001DCED0_sda;
extern char D_L39_002485E0[];
extern char D_L39_002485E8[];
extern char D_L39_002485F0[];
extern char D_L39_002485F8[];
extern char D_L39_00248600[];
extern char D_L39_00248608[];
extern char D_L39_00248610[];
extern char D_L39_00248618[];
extern void func_L39_00688388(void *);
extern void func_L39_006CC120(void *);
extern char *func_00381FF0(s32);
extern void func_00120D28(void *, void *, s32);
extern void func_L39_0068CD28(void *, char *, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);

static __inline__ void base_006A0E80(B_006A0E80 *b, char *text, f32 x, f32 y, f32 w, f32 h) {
    b->kind = 0;
    func_L39_0068CD28(b, text, x, y, w, h);
}
static __inline__ Select_006A0E80 *select_006A0E80(Select_006A0E80 *p, char *text, f32 y, s32 count, void *options) {
    base_006A0E80(&p->b, text, 0.10500002f, y, 0.39f, 0.05f);
    p->b.kind = 3;
    p->count = count;
    p->options = options;
    p->value = 0;
    return p;
}
static __inline__ Small_006A0E80 *small_006A0E80(Small_006A0E80 *p, char *text, f32 x, f32 y, f32 w, f32 h) {
    base_006A0E80(&p->b, text, x, y, w, h);
    p->b.kind = 1;
    return p;
}
static __inline__ Text_006A0E80 *text_006A0E80(Text_006A0E80 *p, char *label, f32 x, f32 y, f32 w, f32 h, char *value) {
    base_006A0E80(&p->b, label, x, y, w, h);
    p->b.kind = 7;
    if (value) {
        func_00120D28(p->text, value, 79);
        p->text[79] = 0;
    } else p->text[0] = 0;
    return p;
}
static __inline__ Spin_006A0E80 *spin_006A0E80(Spin_006A0E80 *p, char *label) {
    base_006A0E80(&p->b, &D_001DCED0_sda, 0.716f, 0.52f, 0.36f, 0.6f);
    p->b.kind = 5;
    p->label = label;
    p->f48 = 0;
    p->f4C = 0;
    p->max = 12;
    p->f58 = 0;
    p->f5C = 0;
    p->sel = -1;
    p->f64 = 0;
    return p;
}
static __inline__ Cell_006A0E80 *cell_006A0E80(Cell_006A0E80 *p, f32 x, u32 color) {
    base_006A0E80(&p->b, &D_001DCED0_sda, x, 0.50883335f, 0.03f, 0.04f);
    p->b.kind = 12;
    p->u0 = 0.0f;
    p->v0 = 1.0f;
    p->u1 = 0.0f;
    p->v1 = 1.0f;
    p->tex = 0xED26;
    p->color = color;
    return p;
}
static __inline__ void root_006A0E80(Root_006A0E80 *p) {
    base_006A0E80(&p->b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    p->id = 46;
    p->count = 0;
    p->b.x = 0.0f;
    p->b.y = 0.0f;
    p->b.w = 1.0f;
    p->b.h = 1.0f;
}

void *func_L39_006A0E80(u8 *self) {
    Strings11_006A0E80 a;

    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047D730;
    func_L39_006CC120(self + 0x10C4);
    func_L39_006CC120(self + 0x1298);
    func_L39_006CC120(self + 0x146C);
    *(void **)(self + 0x2A4) = self + 0x1644;
    {
        Strings11_006A0E80 tmp;

        tmp.s[0] = func_00381FF0(0xFBF);
        tmp.s[1] = func_00381FF0(0xBB1);
        tmp.s[2] = func_00381FF0(0xBB2);
        tmp.s[3] = func_00381FF0(0xDA);
        tmp.s[4] = func_00381FF0(0xBB4);
        tmp.s[5] = func_00381FF0(0xD8);
        tmp.s[6] = func_00381FF0(0xD4);
        tmp.s[7] = func_00381FF0(0x18C4);
        tmp.s[8] = func_00381FF0(0x18C5);
        tmp.s[9] = func_00381FF0(0x18C6);
        tmp.s[10] = func_00381FF0(0x18C7);
        a = tmp;
    }
    {
        Strings4_006A0E80 d;

        {
            Strings4_006A0E80 tmp;

            tmp.s[0] = func_00381FF0(0xFBF);
            tmp.s[1] = func_00381FF0(0x1024);
            tmp.s[2] = func_00381FF0(0x10E2);
            tmp.s[3] = func_00381FF0(0x1026);
            d = tmp;
        }
        {
            Strings2_006A0E80 e;

            {
                Strings2_006A0E80 tmp;

                tmp.s[0] = func_00381FF0(0x116C);
                tmp.s[1] = func_00381FF0(0xF67);
                e = tmp;
            }
            {
                Strings8_006A0E80 g;
                Strings1_006A0E80 one;

                one.s[0] = D_L39_002485E0;
                {
                    Strings8_006A0E80 tmp;

                    tmp.s[0] = func_00381FF0(0xFBF);
                    tmp.s[1] = D_L39_002485E8;
                    tmp.s[2] = D_L39_002485F0;
                    tmp.s[3] = D_L39_002485F8;
                    tmp.s[4] = D_L39_00248600;
                    tmp.s[5] = D_L39_00248608;
                    tmp.s[6] = D_L39_00248610;
                    tmp.s[7] = D_L39_00248618;
                    g = tmp;
                }
                {
                    Select_006A0E80 s0;
                    Select_006A0E80 s1;
                    Select_006A0E80 s2;
                    Text_006A0E80 t;
                    Select_006A0E80 s3;
                    Select_006A0E80 s4;
                    u32 color;
                    Small_006A0E80 l0;
                    Small_006A0E80 l1;
                    Spin_006A0E80 sp;
                    Cell_006A0E80 c0;
                    Cell_006A0E80 c1;
                    Cell_006A0E80 c2;
                    Cell_006A0E80 c3;
                    Root_006A0E80 root;

                    select_006A0E80(&s0, func_00381FF0(0xFEA), 0.20383331f, 2, &e);
                    select_006A0E80(&s1, func_00381FF0(0xFBA), 0.3055f, 11, &a);
                    select_006A0E80(&s2, func_00381FF0(0xFBB), 0.40716666f, 4, &d);
                    text_006A0E80(&t, func_00381FF0(0x160B), 0.10500002f, 0.50883335f, 0.39f, 0.05f,
                                  func_00381FF0(0xFBF));
                    select_006A0E80(&s3, func_00381FF0(0xFB8), 0.6105f, 8, &g);
                    select_006A0E80(&s4, func_00381FF0(0x116C), 0.71216667f, 1, &one);
                    color = 0x706EC8FF;
                    small_006A0E80(&l0, func_00381FF0(0x10E9), 0.3f, 0.82f, 0.39f, 0.05f);
                    small_006A0E80(&l1, func_00381FF0(0x10EA), 0.715f, 0.19f, 1.0f, 1.0f);
                    spin_006A0E80(&sp, func_00381FF0(0x1016));
                    cell_006A0E80(&c0, 0.48f, color);
                    cell_006A0E80(&c1, 0.445f, color);
                    cell_006A0E80(&c2, 0.405f, color);
                    cell_006A0E80(&c3, 0.37f, color);
                    root_006A0E80(&root);
                    root.count = 13;
                    root.children[0] = &s0;
                    root.children[1] = &s1;
                    root.children[2] = &s2;
                    root.children[3] = &t;
                    root.children[4] = &s3;
                    root.children[5] = &s4;
                    root.children[6] = &l0;
                    root.children[7] = &l1;
                    root.children[8] = &sp;
                    root.children[9] = &c0;
                    root.children[10] = &c1;
                    root.children[11] = &c2;
                    root.children[12] = &c3;
                    func_L39_00689670(self, &root);
                }
            }
        }
    }
    self[0x2A8] = 0;
    *(s32 *)(self + 0x2B0) = 0;
    *(s32 *)(self + 0x2B4) = 0;
    *(s32 *)(self + 0x1640) = 0;
    return self;
}
/* localdecomp:end func_L39_006A0E80 */

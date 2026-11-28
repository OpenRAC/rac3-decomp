#include "common.h"

/* localdecomp:start func_L39_006B6A80 */
typedef struct S_6B6A80_C S_6B6A80_C;
typedef struct S_6B6A80_B {
    char _p0[0x24];
    void (*f24)(S_6B6A80_C *arg0);
} S_6B6A80_B;
struct S_6B6A80_C {
    char _p0[0x60];
    S_6B6A80_B *f60;
};
typedef struct S_6B6A80_A {
    char _p0[0x110];
    S_6B6A80_C *f110;
} S_6B6A80_A;

/* from rac4-decomp's func_L00_0071AB38 */
void func_L39_006B6A80(S_6B6A80_A *arg0) {
    S_6B6A80_C *o = arg0->f110;
    o->f60->f24(o);
}
/* localdecomp:end func_L39_006B6A80 */

/* localdecomp:start func_L39_006B6AA8 */
typedef struct T3_6B6AA8 T3_6B6AA8;
typedef struct T2_6B6AA8 {
    char _p0[0xB8];
    void (*fB8)(T3_6B6AA8 *arg0);
} T2_6B6AA8;
struct T3_6B6AA8 {
    char _p0[0x60];
    T2_6B6AA8 *f60;
};
typedef struct T1_6B6AA8 {
    char _p0[0x114];
    T3_6B6AA8 *f114;
} T1_6B6AA8;

/* from rac4-decomp's func_L00_0071AB38 */
void func_L39_006B6AA8(T1_6B6AA8 *arg0) {
    T3_6B6AA8 *o = arg0->f114;
    o->f60->fB8(o);
}
/* localdecomp:end func_L39_006B6AA8 */

/* localdecomp:start func_L39_006B6AD0 */
s32 func_L39_006B6AD0(s32 arg0) {
    return arg0 + 0x2A8;
}
/* localdecomp:end func_L39_006B6AD0 */

/* localdecomp:start func_L39_006B6AD8 */
typedef struct V_006B6AD8 {
    char _p0[0x1C];
    s32 (*f1C)(void *, s32, s32);
} V_006B6AD8;
typedef struct O_006B6AD8 {
    char _p0[0x60];
    V_006B6AD8 *f60;
} O_006B6AD8;
typedef struct S_006B6AD8 {
    char _p0[0x118];
    O_006B6AD8 *f118;
    O_006B6AD8 *f11C;
    O_006B6AD8 *f120;
    O_006B6AD8 *f124;
    char _p1[0x1F4];
    s32 f31C;
} S_006B6AD8;

void func_L39_006B6AD8(S_006B6AD8 *arg0, s32 arg1) {
    arg0->f31C = ((arg1 >> 4) & 1) + (((arg1 >> 3) & 1) + (((arg1 >> 2) & 1) + (arg1 & 1)));
    arg0->f11C->f60->f1C(arg0->f11C, (arg1 & 1) ? 3 : 0, 0);
    arg0->f118->f60->f1C(arg0->f118, (arg1 & 4) ? 3 : 0, 0);
    arg0->f120->f60->f1C(arg0->f120, (arg1 & 8) ? 3 : 0, 0);
    arg0->f124->f60->f1C(arg0->f124, (arg1 & 0x10) ? 3 : 0, 0);
}
/* localdecomp:end func_L39_006B6AD8 */

/* localdecomp:start func_L39_006B6BC0 */
s32 func_L39_006B6BC0(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x318));
}
/* localdecomp:end func_L39_006B6BC0 */

LINKER_REMNANT("asm/levels", func_L39_006B6BC8);

/* localdecomp:start func_L39_006B6BD0 */
void func_0038CC88(void *, void *, s32);
extern u8 D_001FC6B0[];
extern u8 D_L39_0037C848[];

void func_L39_006B6BD0(void) {
    func_0038CC88(D_001FC6B0, D_L39_0037C848, 0xF80);
}
/* localdecomp:end func_L39_006B6BD0 */

/* localdecomp:start func_L39_006B6C00 */
void func_0038CC88(void *, void *, s32);
extern u8 D_001FC6B0[];
extern u8 D_L39_0037C848[];

void func_L39_006B6C00(void) {
    func_0038CC88(D_L39_0037C848, D_001FC6B0, 0xF80);
}
/* localdecomp:end func_L39_006B6C00 */

/* localdecomp:start func_L39_006B6C30 */
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern u8 D_001DDA58_sda;

void func_L39_006B6C30(void) {
    D_00241440 = 7;
    D_001DDA58_sda = 1;
}
/* localdecomp:end func_L39_006B6C30 */

/* localdecomp:start func_L39_006B6C48 */
extern u8 D_00249170 __attribute__((section(".data")));
void *func_0011D534(void *, s32, s32);
typedef struct { u8 a; u8 b; s32 c; } E_006B6C48;
typedef struct { u8 pad0[4]; E_006B6C48 e[3]; u8 f1C; u8 f1D; u8 pad1E[0x3D-0x1E]; u8 f3D; u8 pad3E[0x50-0x3E]; u8 f50; u8 pad51[0x171-0x51]; u8 f171; s16 f172; } S_006B6C48;
void func_L39_006B6C48(void *arg0) {
    S_006B6C48 *p = arg0;
    func_0011D534(p, 0, 0x1F0);
    p->f1D = D_00249170;
    p->f3D = D_00249170;
    p->f1C = 0;
    p->f50 = 0;
    p->e[0].a = 1; p->e[0].b = 1; p->e[0].c = 0x32;
    p->e[1].a = 1; p->e[1].b = 1; p->e[1].c = 0x32;
    p->e[2].a = 1; p->e[2].b = 1;
    p->f172 = 0x300;
    p->f171 = 1;
    p->e[2].c = 0x32;
}
/* localdecomp:end func_L39_006B6C48 */

/* localdecomp:start func_L39_006B6CC8 */
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
typedef struct { char *a, *b, *c; } Strings3_006B6CC8;
typedef struct { char *a, *b; } Strings2_006B6CC8;
typedef struct {
    B_006B6CC8 b;
    s32 count;
    void *options;
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
extern u8 D_00249170 __attribute__((section(".data")));
extern const f32 D_L39_004B1600[];
extern const f32 D_L39_004B16B8[];
extern const f32 D_L39_004B16F0[];
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

void *func_L39_006B6CC8(u8 *self) {
    Root_006B6CC8 root;
    Large_006B6CC8 a;
    Small_006B6CC8 b;
    Small_006B6CC8 c;
    Large_006B6CC8 d;
    Strings3_006B6CC8 options;
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
    y += step;
    root.children[1] = small_006B6CC8(&b, func_00381FF0(0x18C8), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3]);
    y += step;
    root.children[2] = small2_006B6CC8(&c, func_00381FF0(0x10CD), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3]);
    y += step;
    root.children[3] = large_006B6CC8(&d, func_00381FF0(0xF5D), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3], one, one);
    y += step;
    {
        Strings3_006B6CC8 tmp;

        tmp.a = func_00381FF0(9);
        tmp.b = func_00381FF0(0x10C2);
        tmp.c = func_00381FF0(0x10CC);
        options = tmp;
    }
    {
        Select_006B6CC8 e;
        Number_006B6CC8 n;
        Text_006B6CC8 t;

        root.children[4] = select_006B6CC8(&e, func_00381FF0(0x10CB), D_L39_004B1600[0], y, 0.2f, 0.21f, 3, &options);
        y += step;
        root.children[10] = number_006B6CC8(&n, (char *)&D_00249170, D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3], 1024, 64);
        root.children[7] = text_006B6CC8(&t, func_00381FF0(0x234), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3], (char *)&D_00249170);
        {
        Small_006B6CC8 f;
        Select_006B6CC8 g;
        f32 step = D_L39_004B1600[5];

        y += step;
        root.children[5] = small2_006B6CC8(&f, func_00381FF0(0x10CE), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3]);
        y += step;
        root.children[6] = select_empty_006B6CC8(&g, func_00381FF0(0x1632), D_L39_004B1600[0], y, D_L39_004B1600[2], D_L39_004B1600[3]);
        {
            Strings2_006B6CC8 opt2;

            {
                Strings2_006B6CC8 tmp2;

                tmp2.a = func_00381FF0(0x1944);
                tmp2.b = func_00381FF0(0x1943);
                opt2 = tmp2;
            }
            {
                Select_006B6CC8 h;
                Text_006B6CC8 t2;

                root.children[8] = select_006B6CC8(&h, func_00381FF0(0x1945), D_L39_004B16B8[0], D_L39_004B16B8[1], D_L39_004B16B8[2], D_L39_004B16B8[3], 2, &opt2);
                root.children[9] = text_006B6CC8(&t2, (char *)&D_00249170, D_L39_004B16F0[0], D_L39_004B16F0[1], D_L39_004B16F0[2], D_L39_004B16F0[3], (char *)&D_00249170);
                func_L39_00689670(self, &root);
            }
        }
        }
    }
    return self;
}
/* localdecomp:end func_L39_006B6CC8 */

LINKER_REMNANT("asm/levels", func_L39_006B7180);

/* localdecomp:start func_L39_006B7188 */
extern u8 D_L39_0047E680[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B7188(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E680;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B7188 */

LINKER_REMNANT("asm/levels", func_L39_006B71B0);

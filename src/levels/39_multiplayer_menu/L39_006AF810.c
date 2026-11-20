#include "common.h"

/* localdecomp:start func_L39_006AF810 */
typedef struct H_006AF810 {
    s32 type;
    char name[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} H_006AF810;
typedef struct I50_006AF810 {
    H_006AF810 h;
    s32 f48;
    s32 f4C;
} I50_006AF810;
typedef struct I70_006AF810 {
    H_006AF810 h;
    s32 count;
    s32 *list;
    s32 sel;
    char _p0[0x1C];
} I70_006AF810;
typedef struct M_006AF810 {
    H_006AF810 h;
    s32 f48;
    s32 f4C;
    void *items[0x60];
} M_006AF810;
typedef struct N7_006AF810 {
    s32 s[7];
} N7_006AF810;
typedef struct N8_006AF810 {
    s32 s[8];
} N8_006AF810;
typedef struct T_006AF810 {
    u8 pad[0x60];
    void *vt;
    u8 pad64[0x2A4 - 0x64];
    void *list;
    u8 items[4];
} T_006AF810;
typedef struct O_006AF810 {
    u8 pad[0x60];
    void **vt;
} O_006AF810; /* the type-1 widget built by func_L39_00689670 (vtable D_L39_0047B6C0); slot 0x1C is func_L39_0067EF00, which returns s32 */

__asm__(".extern D_001DD58C_sda, 4");
__asm__(".extern D_001DD5EC_sda, 4");
__asm__(".extern D_001DD59C_sda, 4");
__asm__(".extern D_001DD5A0_sda, 4");
extern u8 D_L39_0047DFA0[];
extern char D_L39_00248D38[];
extern f32 D_001DD58C_sda;
extern f32 D_001DD5EC_sda;
extern f32 D_001DD59C_sda;
extern f32 D_001DD5A0_sda;
void *func_L39_00688388(void *);
extern s32 func_00381FF0(s32);
void func_L39_00689670(void *, void *);
void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

static __inline__ void *item_006AF810(void *it, s32 name, f32 x, f32 y, f32 w, f32 h) {
    ((H_006AF810 *)it)->type = 0;
    func_L39_0068CD28((u8 *)it, name, x, y, w, h);
    return it;
}

static __inline__ void list_006AF810(M_006AF810 *l) {
    l->h.type = 0;
    func_L39_0068CD28((u8 *)l, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    l->f48 = 0x2E;
    l->f4C = 0;
    l->h.x = 0.0f;
    l->h.y = 0.0f;
    l->h.w = 1.0f;
    l->h.h = 1.0f;
}

void *func_L39_006AF810(void *const arg0) {
    func_L39_00688388(arg0);
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047DFA0;
    {
    N7_006AF810 n7 = { { func_00381FF0(0xF22), func_00381FF0(0xF23), func_00381FF0(0xF24), func_00381FF0(0xF25),
                          func_00381FF0(0xF26), func_00381FF0(0xF27), func_00381FF0(0xF28) } };
    N8_006AF810 n8 = { { func_00381FF0(0xF1A), func_00381FF0(0xF1B), func_00381FF0(0xF1C), func_00381FF0(0xF1D),
                          func_00381FF0(0xF1E), func_00381FF0(0xF1F), func_00381FF0(0xF20), func_00381FF0(0xF21) } };
    I50_006AF810 it0, it1, it2;
    I70_006AF810 it3, it4, it5, it6, it7, it8, it9, it10;
    I50_006AF810 it11, it12, it13, it14;
    M_006AF810 menu;
    I50_006AF810 *p0, *p1, *p2;
    I70_006AF810 *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10;
    I50_006AF810 *p11, *p12, *p13, *p14;
    M_006AF810 *pm;
    O_006AF810 *o;
    f32 x, step;
    s32 name;
    f32 y0, y1, y2;

    y0 = 0.6f;
    x = 0.1f;
    y1 = 0.65f;
    y2 = 0.7f;
    p0 = &it0;
    ((T_006AF810 *)arg0)->list = ((T_006AF810 *)arg0)->items;
    item_006AF810(p0, (s32)D_L39_00248D38, D_001DD58C_sda, 0.25f, 1.0f, 1.0f);
    it0.h.type = 1;
    step = D_001DD5EC_sda;
    name = func_00381FF0(0x1330);
    p1 = &it1;
    item_006AF810(p1, name, 0.5f, 0.5f, 3.0f, 3.0f);
    it1.h.type = 1;
    name = func_00381FF0(0xFF9);
    p2 = &it2;
    item_006AF810(p2, name, D_001DD59C_sda, D_001DD5A0_sda, 1.0f, 1.0f);
    it2.h.type = 1;

    name = func_00381FF0(0xF12);
    p3 = &it3;
    item_006AF810(p3, name, x, y0, 0.5f, 0.05f);
    x += step;
    it3.h.type = 3;
    p3->count = 8;
    p3->list = n8.s;
    it3.sel = 0;
    name = func_00381FF0(0xF12);
    p4 = &it4;
    item_006AF810(p4, name, x, y0, 0.5f, 0.05f);
    x += step;
    it4.h.type = 3;
    p4->count = 8;
    p4->list = n8.s;
    it4.sel = 0;
    name = func_00381FF0(0xF12);
    p5 = &it5;
    item_006AF810(p5, name, x, y0, 0.5f, 0.05f);
    x += step;
    it5.h.type = 3;
    p5->count = 8;
    p5->list = n8.s;
    it5.sel = 0;
    name = func_00381FF0(0xF12);
    p6 = &it6;
    item_006AF810(p6, name, x, y0, 0.5f, 0.05f);
    x = 0.1f;
    it6.h.type = 3;
    p6->count = 8;
    p6->list = n8.s;
    it6.sel = 0;

    name = func_00381FF0(0xF13);
    p7 = &it7;
    item_006AF810(p7, name, x, y1, 0.5f, 0.05f);
    x += step;
    it7.h.type = 3;
    p7->count = 7;
    it7.list = n7.s;
    it7.sel = 0;
    name = func_00381FF0(0xF13);
    p8 = &it8;
    item_006AF810(p8, name, x, y1, 0.5f, 0.05f);
    x += step;
    it8.h.type = 3;
    p8->count = 7;
    it8.list = n7.s;
    it8.sel = 0;
    name = func_00381FF0(0xF13);
    p9 = &it9;
    item_006AF810(p9, name, x, y1, 0.5f, 0.05f);
    x += step;
    it9.h.type = 3;
    p9->count = 7;
    it9.list = n7.s;
    it9.sel = 0;
    name = func_00381FF0(0xF13);
    p10 = &it10;
    item_006AF810(p10, name, x, y1, 0.5f, 0.05f);
    x = 0.1f;
    it10.h.type = 3;
    p10->count = 7;
    it10.list = n7.s;
    it10.sel = 0;

    name = func_00381FF0(0x1102);
    p11 = &it11;
    item_006AF810(p11, name, x, y2, 1.0f, 1.0f);
    x += step;
    it11.h.type = 1;
    name = func_00381FF0(0x1102);
    p12 = &it12;
    item_006AF810(p12, name, x, y2, 1.0f, 1.0f);
    x += step;
    it12.h.type = 1;
    name = func_00381FF0(0x1102);
    p13 = &it13;
    item_006AF810(p13, name, x, y2, 1.0f, 1.0f);
    x += step;
    it13.h.type = 1;
    name = func_00381FF0(0x1102);
    p14 = &it14;
    item_006AF810(p14, name, x, y2, 1.0f, 1.0f);
    it14.h.type = 1;

    pm = &menu;
    list_006AF810(&menu);
    menu.f4C = 0xF;
    menu.items[0] = p0;
    menu.items[1] = p1;
    menu.items[2] = p2;
    menu.items[3] = p3;
    menu.items[4] = p4;
    menu.items[5] = p5;
    menu.items[6] = p6;
    menu.items[7] = p7;
    menu.items[8] = p8;
    menu.items[9] = p9;
    menu.items[10] = p10;
    menu.items[11] = p11;
    menu.items[12] = p12;
    menu.items[13] = p13;
    menu.items[14] = p14;
    func_L39_00689670(arg0, pm);
    o = *(O_006AF810 **)((u8 *)arg0 + 0x114);
    ((s32 (*)(void *, s32, s32))o->vt[0x1C / 4])(o, 0, 0);
    }
    return arg0;
}
/* localdecomp:end func_L39_006AF810 */

LINKER_REMNANT("asm/levels", func_L39_006AFF40);

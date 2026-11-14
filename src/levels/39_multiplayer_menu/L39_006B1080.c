#include "common.h"

/* localdecomp:start func_L39_006B1080 */
typedef struct H_006B1080 {
    s32 type;
    char name[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} H_006B1080;
typedef struct I50_006B1080 {
    H_006B1080 h;
    u8 b48;
    s32 f4C;
} I50_006B1080;
typedef struct I70_006B1080 {
    H_006B1080 h;
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    char _p0[0x8];
} I70_006B1080;
typedef struct I450_006B1080 {
    H_006B1080 h;
    u8 b48;
    char _p0[0x407];
} I450_006B1080;
typedef struct M_006B1080 {
    H_006B1080 h;
    s32 f48;
    s32 f4C;
    void *items[0x60];
} M_006B1080;

extern u8 D_L39_0047E210[];
extern char D_L39_00248EA0[];
void func_L39_00688388(void *);
void *func_L39_006CC120(void *);
void func_L39_00689670(void *, void *);
void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern s32 func_00381FF0(s32);

static __inline__ void *item_006B1080(void *it, s32 name, f32 x, f32 y, f32 w, f32 h) {
    ((H_006B1080 *)it)->type = 0;
    func_L39_0068CD28((u8 *)it, name, x, y, w, h);
    return it;
}
static __inline__ void *blank_006B1080(void *it, f32 x, f32 y, f32 w, f32 h) {
    ((H_006B1080 *)it)->type = 0;
    func_L39_0068CD28((u8 *)it, (s32)D_L39_00248EA0, x, y, w, h);
    return it;
}

void *func_L39_006B1080(void *arg0) {
    I50_006B1080 it0;
    I50_006B1080 it1;
    I50_006B1080 it2;
    I50_006B1080 it3;
    I50_006B1080 it4;
    I50_006B1080 it5;
    I50_006B1080 it6;
    I50_006B1080 it7;
    I50_006B1080 it8;
    I50_006B1080 it9;
    I70_006B1080 it10;
    I450_006B1080 it11;
    M_006B1080 menu;
    I50_006B1080 *p0, *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9;
    I70_006B1080 *p10;
    I450_006B1080 *p11;
    M_006B1080 *pm;
    s32 name;

    func_L39_00688388(arg0);
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047E210;
    func_L39_006CC120((u8 *)arg0 + 0x2B8);
    *(void **)((u8 *)arg0 + 0x2A4) = (u8 *)arg0 + 0x2898;

    name = func_00381FF0(0x10DA);
    p0 = &it0;
    item_006B1080(p0, name, 0.272f, 0.17500001f, 0.33200002f, 0.05f);
    it0.h.type = 1;
    name = func_00381FF0(0xF82);
    p1 = &it1;
    item_006B1080(p1, name, 0.272f, 0.23f, 0.33200002f, 0.05f);
    it1.h.type = 1;
    name = func_00381FF0(0xF65);
    p2 = &it2;
    item_006B1080(p2, name, 0.272f, 0.285f, 0.33200002f, 0.05f);
    it2.h.type = 1;
    name = func_00381FF0(0x10DB);
    p3 = &it3;
    item_006B1080(p3, name, 0.272f, 0.34f, 0.33200002f, 0.05f);
    it3.h.type = 1;
    name = func_00381FF0(0xF66);
    p4 = &it4;
    item_006B1080(p4, name, 0.272f, 0.395f, 0.33200002f, 0.05f);
    it4.h.type = 1;
    name = func_00381FF0(0xF67);
    p5 = &it5;
    item_006B1080(p5, name, 0.272f, 0.45f, 0.33200002f, 0.05f);
    it5.h.type = 1;
    name = func_00381FF0(0xF68);
    p6 = &it6;
    item_006B1080(p6, name, 0.272f, 0.505f, 0.33200002f, 0.05f);
    it6.h.type = 1;
    name = func_00381FF0(0x1655);
    p7 = &it7;
    item_006B1080(p7, name, 0.272f, 0.56f, 0.33200002f, 0.05f);
    it7.h.type = 1;

    p8 = &it8;
    blank_006B1080(p8, 0.688f, 0.34f, 0.42499998f, 0.385f);
    it8.h.type = 4;
    it8.f4C = 0;
    it8.b48 = 1;

    name = func_00381FF0(0x117E);
    p9 = &it9;
    item_006B1080(p9, name, 0.728f, 0.58516663f, 0.32700002f, 0.05f);
    it9.h.type = 1;

    p10 = &it10;
    blank_006B1080(p10, 0.728f, 0.7301666f, 0.32700002f, 0.24166667f);
    it10.h.type = 5;
    it10.f48 = 0;
    it10.f4C = 0;
    it10.f50 = 0;
    p10->f54 = 5;
    it10.f58 = 0;
    it10.f5C = 0;
    p10->f60 = -1;
    it10.f64 = 0;

    p11 = &it11;
    blank_006B1080(p11, 0.312f, 0.706f, 0.42999998f, 0.29f);
    it11.h.type = 9;
    it11.b48 = 0;

    pm = &menu;
    item_006B1080(pm, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    pm->f48 = 0x2E;
    menu.f4C = 0;
    menu.h.x = 0;
    menu.h.y = 0;
    pm->h.w = 1.0f;
    pm->h.h = 1.0f;
    menu.f4C = 0xC;
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
    func_L39_00689670(arg0, pm);
    return arg0;
}
/* localdecomp:end func_L39_006B1080 */

LINKER_REMNANT("asm/levels", func_L39_006B15A0);

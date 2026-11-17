#include "common.h"

/* declared by functions of L39_0068C4E0.c, which this file was cut from */
void func_00120D28(s32, s32, s32);

/* localdecomp:start func_L39_0068CDA8 */
extern void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_00120D28(s32, s32, s32);
extern u8 D_L39_0047C520[];
extern void func_L39_00688388(void *);
extern void func_L39_00689670(void *, void *);
extern s32 D_00247BC0[];
__asm__(".extern D_001DC480_sda, 4");
extern f32 D_001DC480_sda;
__asm__(".extern D_001DC484_sda, 4");
extern f32 D_001DC484_sda;
__asm__(".extern D_001DC488_sda, 4");
extern f32 D_001DC488_sda;
__asm__(".extern D_001DC48C_sda, 4");
extern f32 D_001DC48C_sda;
__asm__(".extern D_001DC490_sda, 4");
extern f32 D_001DC490_sda;

typedef struct {
    s32 type;
    char name[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} H_0068CDA8;
typedef struct {
    H_0068CDA8 h;
    char text[0x50];
    u8 pad98[0x8];
} T_0068CDA8;
typedef struct {
    H_0068CDA8 h;
    s32 f48;
    s32 count;
    void *items[0x60];
} M_0068CDA8;

static __inline__ void *item_0068CDA8(void *it, s32 name, f32 x, f32 y, f32 w, f32 h) {
    ((H_0068CDA8 *)it)->type = 0;
    func_L39_0068CD28((u8 *)it, name, x, y, w, h);
    return it;
}

static __inline__ T_0068CDA8 *text_0068CDA8(T_0068CDA8 *it, s32 s, f32 x, f32 y, f32 w, f32 h) {
    item_0068CDA8(it, s, x, y, w, h);
    it->h.type = 7;
    if (s != 0) {
        func_00120D28((s32)it->text, s, 0x4F);
        it->text[0x4F] = 0;
    } else {
        it->text[0] = 0;
    }
    return it;
}

void *func_L39_0068CDA8(void *arg0)
{
    T_0068CDA8 it0, it1, it2, it3, it4, it5;
    M_0068CDA8 menu;
    T_0068CDA8 *p1, *p2, *p3, *p4, *p5;
    M_0068CDA8 *pm;
    f32 x, y, w;

    func_L39_00688388(arg0);
    x = D_001DC480_sda;
    y = D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -3.5f * 0.125f;
    w = D_001DC488_sda - (D_001DC490_sda + D_001DC490_sda);
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047C520;
    *(void **)((u8 *)arg0 + 0x2A4) = (u8 *)arg0 + 0x2C4;
    text_0068CDA8(&it0, (s32)D_00247BC0, x, y, w, 0.05f);
    p1 = text_0068CDA8(&it1, (s32)D_00247BC0, D_001DC480_sda,
                  D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -2.5f * 0.125f,
                  D_001DC488_sda - (D_001DC490_sda + D_001DC490_sda), 0.05f);
    p2 = text_0068CDA8(&it2, (s32)D_00247BC0, D_001DC480_sda,
                  D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -1.5f * 0.125f,
                  D_001DC488_sda - (D_001DC490_sda + D_001DC490_sda), 0.05f);
    p3 = text_0068CDA8(&it3, (s32)D_00247BC0, D_001DC480_sda,
                  D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -0.5f * 0.125f,
                  D_001DC488_sda - (D_001DC490_sda + D_001DC490_sda), 0.05f);
    p4 = text_0068CDA8(&it4, (s32)D_00247BC0, D_001DC480_sda,
                  D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * 0.5f * 0.125f,
                  D_001DC488_sda - (D_001DC490_sda + D_001DC490_sda), 0.05f);
    p5 = text_0068CDA8(&it5, (s32)D_00247BC0, D_001DC480_sda,
                  D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * 1.5f * 0.125f,
                  D_001DC488_sda - (D_001DC490_sda + D_001DC490_sda), 0.05f);

    pm = &menu;
    item_0068CDA8(pm, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    pm->f48 = 0x2E;
    menu.count = 0;
    menu.h.x = 0;
    menu.h.y = 0;
    pm->h.w = 1.0f;
    pm->h.h = 1.0f;
    menu.items[0] = &it0;
    menu.items[1] = p1;
    menu.items[2] = p2;
    menu.items[3] = p3;
    menu.items[4] = p4;
    menu.items[5] = p5;
    menu.count = 6;
    func_L39_00689670(arg0, pm);
    return arg0;
}
/* localdecomp:end func_L39_0068CDA8 */

LINKER_REMNANT("asm/levels", func_L39_0068D1C0);

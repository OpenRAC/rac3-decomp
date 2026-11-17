#include "common.h"

/* localdecomp:start func_L39_0069CE50 */
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
void func_L39_006B7E90(s32, s32, s32, s32, s32);
s32 func_L39_0068AEF8(void *, s32);
s32 func_L39_00688340(s32, s32, s32);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);

typedef struct S_0069CE50_Obj S_0069CE50_Obj;
typedef struct {
    u8 pad0[0x1C];
    void (*setState)(S_0069CE50_Obj *, s32, s32);
    u8 pad20[0x10];
    void (*getPos)(S_0069CE50_Obj *, f32 *, f32 *);
    u8 pad34[0x2C];
    void (*setEnabled)(S_0069CE50_Obj *, s32);
    s32 (*getValue)(S_0069CE50_Obj *);
    u8 pad68[0x24];
    s32 (*getSelected)(S_0069CE50_Obj *);
    u8 pad90[0x1C];
    s32 (*getNumber)(S_0069CE50_Obj *);
} S_0069CE50_Vt;
struct S_0069CE50_Obj {
    u8 pad0[4];
    s32 type;
    u8 pad8[0x58];
    S_0069CE50_Vt *vt;
};
typedef struct {
    u8 pad0[0x110];
    S_0069CE50_Obj *items[12];
    u8 pad140[0x150];
    s32 sel;
    u8 pad294[0x18];
    s32 f2AC;
    s32 f2B0;
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    s32 f2C0;
    s32 f2C4;
    s32 f2C8;
    s32 f2CC;
    u8 pad2D0[4];
    s32 f2D4;
    s32 f2D8;
    u8 f2DC;
} S_0069CE50_Self;

s32 func_L39_0069CE50(S_0069CE50_Self *s, s32 event) {
    f32 x;
    f32 y;
    s32 v;
    s32 i;
    s32 first;
    s32 last;
    s32 t;

    func_L39_006B7E90(1, 0, 0x190, 0, 0x82);
    if (func_L39_0068AEF8(s, event)) {
        switch (s->sel) {
        case 0:
            s->f2B0 = s->items[0]->vt->getValue(s->items[0]) == 0;
            break;
        case 1:
            s->f2DC = s->items[1]->vt->getValue(s->items[1]);
            break;
        case 7:
            s->f2D8 = s->items[7]->vt->getNumber(s->items[7]);
            break;
        case 8:
            s->f2B4 = s->items[8]->vt->getValue(s->items[8]) != 0;
            break;
        case 2:
            s->f2B8 = s->items[2]->vt->getValue(s->items[2]) != 0;
            break;
        case 9:
            s->f2BC = s->items[9]->vt->getSelected(s->items[9]);
            break;
        case 11:
            v = s->items[11]->vt->getSelected(s->items[11]);
            s->f2BC = v;
            if (s->f2AC != 0) {
                break;
            }
            if (v == 1) {
                s->f2DC = v;
                s->items[1]->vt->setEnabled(s->items[1], 1);
                s->items[1]->vt->setState(s->items[1], 2, 0);
                s->f2C0 = v;
                s->items[3]->vt->setEnabled(s->items[3], 1);
                s->items[3]->vt->setState(s->items[3], 2, 0);
            } else {
                s->items[1]->vt->setState(s->items[1], 3, 0);
                s->items[3]->vt->setState(s->items[3], 3, 0);
            }
            break;
        case 10:
            s->f2D4 = s->items[10]->vt->getNumber(s->items[10]);
            break;
        case 3:
            s->f2C0 = s->items[3]->vt->getValue(s->items[3]) != 0;
            break;
        case 4:
            s->f2C4 = s->items[4]->vt->getValue(s->items[4]) != 0;
            break;
        case 5:
            s->f2C8 = s->items[5]->vt->getValue(s->items[5]) != 0;
            break;
        case 6:
            s->f2CC = s->items[6]->vt->getValue(s->items[6]) != 0;
            break;
        }
        return 1;
    }
    if ((u32)(event - 5) < 2) {
        func_L39_00688340(0x17, 0, 0);
        D_L39_00247914[0x284 / 4] = 0x2C;
        return 1;
    }
    s->items[s->sel]->vt->getPos(s->items[s->sel], &x, &y);
    first = -1;
    last = -1;
    for (i = 0; i < 12; i++) {
        if ((t = s->items[i]->type) == 3 || t == 4 || t == 5) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    func_L39_0068A2D0(s, (s->sel != first) | ((s->sel != last) ? 2 : 0), 3, 3, 0.602f, y + -0.0015f);
    return 0;
}
/* localdecomp:end func_L39_0069CE50 */

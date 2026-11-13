#include "common.h"

/* localdecomp:start func_L39_005FFE38 */
typedef struct {
    f32 x;
    f32 y;
} Pt_L39_005FFE38;
typedef struct {
    Pt_L39_005FFE38 *p0;
    Pt_L39_005FFE38 *p4;
    u8 pad8[0x80];
    u8 f88[1];
    u8 pad89[0xFE];
    u8 b187;
    u8 pad188[8];
    s32 f190;
    u8 pad194[4];
    s32 f198;
    u8 pad19C[8];
    s32 f1A4;
    u8 pad1A8[0xC];
    s32 f1B4;
    void *f1B8;
} Obj_L39_005FFE38;

extern s32 *D_L39_002412A0;
extern f32 D_L39_002412D0;
extern s32 func_L01_00410120(void *, s32);
extern s32 func_L01_004100D8(void *, s32);
extern s32 func_L01_00444338_005FFE38(void *, s32, f32);

void func_L39_005FFE38(Obj_L39_005FFE38 *o, s32 mode, s32 arg2, f32 x, f32 y) {
    void *list = o->f88;
    s32 t;

    o->p0->x = x;
    o->p0->y = y;
    o->f198 = arg2;
    o->b187 = 0;
    o->f1B8 = list;
    o->f1A4 = mode;
    switch (mode) {
    case 0:
        o->f1B4 = func_L01_00410120(list, -1);
        break;
    case 1:
        t = *D_L39_002412A0;
        if (t > 1) {
            s32 i = t - 1;

            o->f1B4 = func_L01_00444338_005FFE38(list, -1, (&D_L39_002412D0)[i] / D_L39_002412D0);
        } else {
            o->f1B4 = func_L01_004100D8(list, -1);
        }
        break;
    case 2:
        break;
    }
    o->f190 = 1;
    o->p4->x = 1.0f;
}
/* localdecomp:end func_L39_005FFE38 */

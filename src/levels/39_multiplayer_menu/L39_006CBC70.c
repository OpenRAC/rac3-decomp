#include "common.h"

/* localdecomp:start func_L39_006CBC70 */
typedef struct S_006CBC70V {
    u8 pad[0x30];
    void (*f30)(void *, f32 *, f32 *);
    u8 pad2[0x88 - 0x34];
    void (*f88)(void *, s32);
    s32 (*f8C)(void *);
} S_006CBC70V;
typedef struct S_006CBC70D { u8 pad[4]; s32 f4; u8 pad2[0x60 - 8]; S_006CBC70V *vt; } S_006CBC70D;
typedef struct S_006CBC70O {
    u8 pad[0x110];
    S_006CBC70D *dev[2];
    u8 pad2[0x290 - 0x118];
    s32 f290;
    u8 pad3[0x2A8 - 0x294];
    s32 *p2A8;
    s32 *p2AC;
    s32 f2B0;
    u8 pad4[0x2B9 - 0x2B4];
    u8 b2B9;
    u8 b2BA;
} S_006CBC70O;
typedef struct S_006CBC70T { u8 pad[0xE0]; s16 hE0[8]; s16 hF0[8]; } S_006CBC70T;
typedef struct S_006CBC70G { u8 pad[8]; s32 f8; u8 rest[0x700]; } S_006CBC70G;

extern s32 func_L39_00686138(void *, s32);
extern void func_L39_006CC018(void *);
extern s32 func_L39_00688340(s32, s32, s32);
extern s32 func_L39_0068B1E0(void *, s32);
extern s32 func_L39_0068B260(void *, s32);
extern s32 func_L39_0068B2F8(void *, s32, s32);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);
extern u8 *D_001DC204_sda;
extern s32 D_001DDA50_sda;
extern s32 D_001DDA54_sda;
extern S_006CBC70T *D_L39_00241640;
extern s32 D_L39_00249160_006CBC70;
extern u8 *D_L39_00247914;
extern S_006CBC70G D_001A5CD0;

s32 func_L39_006CBC70(S_006CBC70O *object, s32 mode)
{
    s32 sel;
    s32 i;
    s32 j;
    s32 idx;
    s32 first;
    s32 last;
    s32 kind;
    f32 pos[2];
    u8 *p;
    s32 sel2;
    s32 r;

    if (object->f2B0 != 0) {
        mode = func_L39_00686138(D_001DC204_sda, object->f2B0);
    }
    func_L39_006CC018(object);
    if (object->f290 == 1) {
        sel = object->dev[1]->vt->f8C(object->dev[1]);
        if (mode == 3 || mode == 4) {
            func_L39_00688340(3, 0, 0);
            if (mode == 3) {
                sel--;
                if (sel < 0) {
                    sel = object->b2B9 ? 0x15 : 0x14;
                }
                if (sel == 0x12 && object->b2BA == 0) {
                    sel = 0x11;
                }
            } else if (mode == 4) {
                sel++;
                if (sel == 0x12 && object->b2BA == 0) {
                    sel = 0x13;
                }
                if (sel == 0x15 && object->b2B9 == 0) {
                    sel = 0x16;
                }
                if (sel >= 0x16) {
                    sel = 0;
                }
            }
            object->dev[1]->vt->f88(object->dev[1], sel);
            *object->p2AC = sel;
            D_001DDA50_sda = sel;
            return 1;
        }
    }
    if (object->p2A8 != 0) {
        *object->p2A8 = object->dev[0]->vt->f8C(object->dev[0]);
    }
    if (object->p2AC != 0) {
        *object->p2AC = object->dev[1]->vt->f8C(object->dev[1]);
    }
    D_L39_00249160_006CBC70 = *object->p2AC;
    D_001DDA54_sda = *object->p2A8;

    idx = -1;
    for (i = 0; i < 8; i++) {
        if (D_L39_00241640->hE0[i] == D_001A5CD0.f8) {
            idx = i;
            break;
        }
    }
    if (D_L39_00241640 != 0 && idx >= 0 && D_L39_00241640->hF0[idx] == 5) {
        goto use_sda;
    }
    if (object->f2B0 != 0) {
        if (mode == 2) {
            func_L39_0068B2F8(object, func_L39_0068B1E0(object, -1), 0);
            return 1;
        }
        if (mode == 1) {
            func_L39_0068B2F8(object, func_L39_0068B260(object, -1), 0);
            return 1;
        }
        if (mode == 5) {
            goto use_sda;
        }
    }
    if (mode != 7) goto rest;
    p = D_L39_00247914;
    goto tail;
use_sda:
    p = D_001DC204_sda;
tail:
    *(s32 *)(p + 0x284) = 0x2C;
    return 1;
rest:
    if (func_L39_0068AEF8(object, mode) != 0) {
        return 1;
    }
    object->dev[object->f290]->vt->f30(object->dev[object->f290], &pos[0], &pos[1]);
    first = -1;
    last = -1;
    for (j = 0; j < 2; j++) {
        if ((kind = object->dev[j]->f4) == 3 || kind == 4 || kind == 5) {
            if (first == -1) {
                first = j;
            }
            last = j;
        }
    }
    sel2 = 0;
    if (object->f290 != first) {
        sel2 |= 1;
    }
    if (object->f290 != last) {
        sel2 |= 2;
    }
    func_L39_0068A2D0(object, sel2, 3, 3, 0.602f, pos[1] + -0.0015f);
    r = 0;
    if (object->f2B0 != 0) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L39_006CBC70 */

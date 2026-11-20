#include "common.h"

/* localdecomp:start func_L39_00539268 */
typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(void *, s32);
} VT_00539268;
typedef struct {
    u8 pad0[3];
    u8 b3;
    u8 pad4[0x14 - 4];
    VT_00539268 *vt;
    u8 pad18[0x1A14 - 0x18];
    u8 b1A14;
} T_00539268;
typedef struct {
    u8 pad0[0xAA];
    s16 hAA;
    u8 padAC[0xBE - 0xAC];
    u8 bBE;
} O_00539268;
extern s32 func_L39_0061D7B0(void *);
extern s32 func_L39_005B8928(u8 *);

s32 func_L39_00539268(s32 mode, O_00539268 *obj, T_00539268 *t) {
    s32 id;

    if (obj == 0) {
        return 0;
    }
    if (t == 0) {
        t = (T_00539268 *)func_L39_0061D7B0(obj);
        if (t == 0) {
            if (mode == 0 && (obj->bBE & 8)) {
                return 1;
            }
            if (mode == 1 && (obj->bBE & 0x10)) {
                return 1;
            }
            return 0;
        }
    }
    if ((t->b3 & 0xF) == 0 && t->b1A14 == 0) {
        return 0;
    }
    if (t->vt->f1C(t, mode)) {
        return 0;
    }
    if (func_L39_005B8928((u8 *)obj) != 0) {
        return 0;
    }
    id = obj->hAA;
    if (id == 0x107C || id == 0x107E || id == 0x10C2 || id == 0x109D) {
        if (t->vt->f1C(t, -1) != 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00539268 */

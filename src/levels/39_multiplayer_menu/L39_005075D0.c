#include "common.h"

/* localdecomp:start func_L39_005075D0 */
/* func_L39_005075D0 log (ee296check.sh): written as func_L39_00507268, its twin (vtable slot 0x18 for 0x14). */
typedef struct S_005075D0_vt {
    s32 (*f0)(s32 *, s32, s32);
    s32 (*f4)(s32, s32, s32, s32, void *, s32, s32);
    u8 pad8[0x10];
    s32 (*f18)(void *);
} S_005075D0_vt;

typedef struct S_005075D0_obj {
    u8 pad0[0xC];
    S_005075D0_vt *vt;
} S_005075D0_obj;

typedef struct S_005075D0 {
    u8 pad0[8];
    s32 f8;
    u8 padC[4];
    s32 f10;
} S_005075D0;

s32 func_L39_004F7460(void *, s32);
s32 func_L39_00508278(s32);

s32 func_L39_005075D0(S_005075D0 *p, s32 arg1, s32 arg2, S_005075D0_obj *obj, s32 arg4, s32 arg5) {
    s32 len;
    s32 err;
    s32 r;

    err = obj->vt->f0(&len, arg1, p->f8);
    if (err != 0) {
        return func_L39_00508278(err);
    }
    r = func_L39_004F7460(&p->f10, len);
    if (r != 0) {
        return r;
    }
    if (obj->vt->f18 != 0) {
        err = obj->vt->f18(&p->f10);
        if (err != 0) {
            return func_L39_00508278(err);
        }
    }
    err = obj->vt->f4(p->f10, arg1, p->f8, arg2, obj, arg4, arg5);
    if (err != 0) {
        return func_L39_00508278(err);
    }
    return err;
}
/* localdecomp:end func_L39_005075D0 */

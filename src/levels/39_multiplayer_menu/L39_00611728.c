#include "common.h"

/* localdecomp:start func_L39_00611728 */
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_00611728_mgr;
typedef s32 (*S_00611728_cb)(void *, s32, s32, s32, s32);
extern S_00611728_mgr D_L39_0024CD50;
extern u8 D_L39_002F9FC8[];
extern s32 D_001DA4F8_sda;
extern void *func_003E6C08();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_L01_00519B10(void *, u32);

s32 func_L39_00611728(s32 arg0, s32 a1, s16 a2, s16 a3, s32 a4)
{
    s32 r;
    s32 t;
    void *base;
    void *p;
    S_00611728_cb cb;
    S_00611728_mgr *q;

    r = 0;
    q = &D_L39_0024CD50;
    if (q->f4 != 0) {
        base = q;
    } else {
        base = func_003E6C08();
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if (p == 0 || (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001DA4F8_sda) == 0) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (S_00611728_cb)func_L01_00519B10(D_L39_002F9FC8, t);
        if (cb != 0) {
            r = cb(p, a1, a2, a3, a4);
        }
    }
    return r;
}
/* localdecomp:end func_L39_00611728 */

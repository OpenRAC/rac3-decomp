#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00611CA0);

/* localdecomp:start func_L39_00611D78 */
extern s32 func_L39_00611D78(s32, s32);
extern s32 func_L39_00611D78();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L39_001DA4F8;
extern s32 func_003E6DE8();

extern u8 func_L01_00519E18[];
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2808;
extern S_003E2808 D_L39_0024CD50;
extern u8 D_L39_002FA0A0[];
s32 func_L39_00611D78(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2808 *q;

    r = 0;
    q = &D_L39_0024CD50;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L39_001DA4F8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519E18)(D_L39_002FA0A0, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_L39_00611D78 */

/* localdecomp:start func_L39_00611E50 */
extern S_003E2808 D_L39_0024CD50;
extern s32 func_L39_00611E50(s32, s32, s32);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L39_001DA4F8;

extern u8 func_L01_00519680[];
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E23C0;
extern u8 D_L39_002FA0E8[];
s32 func_L39_00611E50(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E23C0 *q;

    r = 0;
    q = &(*(S_003E23C0 *)&D_L39_0024CD50);
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L39_001DA4F8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519680)(D_L39_002FA0E8, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_L39_00611E50 */

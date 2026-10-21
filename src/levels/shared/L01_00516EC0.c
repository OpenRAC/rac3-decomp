#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2618;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2808;

LINKER_REMNANT("asm/levels", func_L01_00516EC0);

/* localdecomp:start func_L01_00516EC8 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;
extern s32 func_003E6DE8();

extern u8 func_L01_00519A10[];
extern S_003E2618 D_L01_001E15E0;
extern u8 D_L01_0026DF60[];
s32 func_L01_00516EC8(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 *base;
    s32 (*cb)(void *, s32, s32, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2618 *q;

    r = 0;
    q = &D_L01_001E15E0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519A10)(D_L01_0026DF60, t);
        if (cb != 0) {
            r = cb(p, a1, a2, a3, a4);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00516EC8 */

LINKER_REMNANT("asm/levels", func_L01_00516FD0);

/* localdecomp:start func_L01_00516FD8 */
extern S_003E2618 D_L01_001E15E0;
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00516FD8();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;
extern s32 func_003E6DE8();

extern u8 func_L01_00519A90[];
extern u8 D_L01_0026DAE0[];
s32 func_L01_00516FD8(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2808 *q;

    r = 0;
    q = &(*(S_003E2808 *)&D_L01_001E15E0);
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519A90)(D_L01_0026DAE0, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00516FD8 */

LINKER_REMNANT("asm/levels", func_L01_005170B0);

/* localdecomp:start func_L01_005170B8 */
extern S_003E2618 D_L01_001E15E0;
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_005170B8();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;
extern s32 func_003E6DE8();

extern u8 func_L01_00519B90[];
extern u8 D_L01_0026DB70[];
s32 func_L01_005170B8(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2808 *q;

    r = 0;
    q = &(*(S_003E2808 *)&D_L01_001E15E0);
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519B90)(D_L01_0026DB70, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_L01_005170B8 */

/* localdecomp:start func_L01_00517190 */
extern S_003E2618 D_L01_001E15E0;
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00517190();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;
extern s32 func_003E6DE8();

extern u8 func_L01_00519B90[];
extern u8 D_L01_0026DC90[];
s32 func_L01_00517190(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2808 *q;

    r = 0;
    q = &(*(S_003E2808 *)&D_L01_001E15E0);
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519B90)(D_L01_0026DC90, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00517190 */

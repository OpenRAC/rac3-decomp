#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E23C0;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1E50;

INCLUDE_ASM("asm/levels", func_L01_00517340);

/* localdecomp:start func_L01_00517448 */
extern s32 func_L01_00517448(s32, s32, s32);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;

extern u8 func_L01_00519D18_00517448[];
extern S_003E23C0 D_L01_001E15E0;
extern u8 D_L01_0026DDB0[];
s32 func_L01_00517448(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E23C0 *q;

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
        cb = (void *)((void *(*)(void *, s32))func_L01_00519D18_00517448)(D_L01_0026DDB0, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00517448 */

LINKER_REMNANT("asm/levels", func_L01_00517530);

/* localdecomp:start func_L01_00517538 */
extern S_003E23C0 D_L01_001E15E0;
extern s32 func_L01_00517538(s32, f32, f32);

extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_L01_00519600[];
extern s32 D_L01_001DC0B8;
extern u8 D_L01_0026DA98[];
s32 func_L01_00517538(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E1E50 *q;

    r = 0;
    q = &(*(S_003E1E50 *)&D_L01_001E15E0);
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
        cb = (void *)((void *(*)(void *, s32))func_L01_00519600)(D_L01_0026DA98, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00517538 */

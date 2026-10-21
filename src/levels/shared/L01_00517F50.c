#include "common.h"

/* localdecomp:start func_L01_00517F50 */
typedef struct Obj Obj;
typedef struct {
    void *pad0;
    void *pad4;
    void *pad8;
    void *padC;
    s32 (*check)(Obj *, s32);
} ObjVtbl;

struct Obj {
    u8 pad0[8];
    ObjVtbl *vt;
    u8 padC[0x3E];
    s16 field_4A;
};

extern s32 D_L01_001E15E0[];
extern s32 D_L01_001DC1B0;
extern void *func_003E6C08(void);
extern void *func_003E6DE8(void *);
extern Obj *func_003E6378(void *, s32);
extern void func_003EF1B8(Obj *, s32);

s32 func_L01_00517F50(s32 a0, s32 a1, s32 a2) {
    s32 *g;
    void *p;
    Obj *o;
    s32 r = 0;

    g = D_L01_001E15E0;
    if (g[1] != 0) p = g;
    else p = func_003E6C08();
    o = func_003E6378(func_003E6DE8(p), a0);
    if (o == 0 || o->vt->check(o, D_L01_001DC1B0) == 0) o = 0;
    if (o != 0) {
        func_003EF1B8(o, a1);
        r = 1;
        o->field_4A = a2;
    }
    return r;
}
/* localdecomp:end func_L01_00517F50 */

INCLUDE_ASM("asm/levels", func_L01_00518010);

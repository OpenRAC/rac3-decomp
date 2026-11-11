#include "common.h"

/* localdecomp:start func_L39_004C3428 */
s32 func_0011D534();
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
void *func_L39_004BEED8(s32);

void *func_L39_004C3428(void) {
    void *p;
    p = func_L39_004BEED8(0x70);
    if (p == 0) {
        func_L39_004BC6C8(0x14, 0xA3, 0x21, 0, 0);
        return 0;
    }
    func_0011D534(p, 0, 0x70);
    *(void **)((u8 *)p + 4) = (u8 *)p + 0x40;
    *(s32 *)((u8 *)p + 0x6C) = 1;
    return p;
}
/* localdecomp:end func_L39_004C3428 */

INCLUDE_ASM("asm/levels", func_L39_004C3498);

INCLUDE_ASM("asm/levels", func_L39_004C35C8);

/* localdecomp:start func_L39_004C35D8 */
typedef struct S_004C35D8_B {
    s32 f0;
} S_004C35D8_B;

typedef struct S_004C35D8_T {
    u8 pad0[0x18];
    s32 f18;
    u8 pad1c[0x74];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
} S_004C35D8_T;

typedef struct S_004C35D8 {
    u8 pad0[0xDC];
    S_004C35D8_T *fDC;
    u8 padE0[8];
    long fE8;
} S_004C35D8;

extern s32 func_L39_004BC348(void *, void *, s32, s32, void *);
extern s32 func_L39_004BC390(void *, void *, s32, s32, s32, void *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004DE0C8(void);

s32 func_L39_004C35D8(S_004C35D8 *arg0, S_004C35D8_B *arg1) {
    S_004C35D8_T *t;
    s32 r;

    if (arg1 == 0 || arg1->f0 == 0) {
        return 0;
    }
    t = arg0->fDC;
    if (t->f98 != 0) {
        r = func_L39_004BC348(arg0, arg1, t->f98, t->f9C, &arg0->fE8);
    } else {
        r = func_L39_004BC390(arg0, arg1, t->f18, t->f90, t->f94, &arg0->fE8);
    }
    if (arg0->fE8 == 0x32) {
        func_L39_004BC6C8(0x14, 0xD0, 0xC2, 0, 0);
    }
    if (r != 0) {
        func_L39_004DE0C8();
    }
    return r;
}
/* localdecomp:end func_L39_004C35D8 */

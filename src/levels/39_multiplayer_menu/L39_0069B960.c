#include "common.h"

typedef struct Vt_0069C088 Vt_0069C088;
typedef struct Obj_0069C088 Obj_0069C088;
typedef struct Self_0069C088 Self_0069C088;
struct Vt_0069C088 {
    u8 pad0[0x78];
    s32 (*f78)(void *);
    u8 pad1[0x10];
    s32 (*f8C)(void *);
};
struct Obj_0069C088 {
    u8 pad0[0x60];
    Vt_0069C088 *f60;
};
struct Self_0069C088 {
    u8 pad0[0x118];
    Obj_0069C088 *f118;
    u8 pad1[0x2A8 - 0x11C];
    s32 f2A8;
    s32 f2AC;
    u8 pad2[0x2B8 - 0x2B0];
    s32 f2B8;
    u8 pad3[0x2C4 - 0x2BC];
    s32 f2C4;
    u8 pad4[0x2E8 - 0x2C8];
    u8 f2E8;
};

INCLUDE_ASM("asm/levels", func_L39_0069B960);

INCLUDE_ASM("asm/levels", func_L39_0069BA50);

INCLUDE_ASM("asm/levels", func_L39_0069BED8);

/* localdecomp:start func_L39_0069C088 */
extern void func_19AE90(s32);

void func_L39_0069C088(Self_0069C088 *self)
{
    Obj_0069C088 *p;
    s32 v;
    s32 t;

    p = self->f118;
    self->f2AC = p->f60->f8C(p);
    p = self->f118;
    v = p->f60->f78(p);
    if (v - 1 != 2) {
        self->f2AC++;
    }
    t = self->f2AC;
    if (t == 2) {
        self->f2E8 = 0;
        v = self->f2A8 == 3;
    } else {
        v = 1;
        self->f2E8 = v;
    }
    do {
        self->f2B8 = v;
    } while (0);
    if (self->f2AC == 1) {
        self->f2C4 = 0;
    } else {
        self->f2C4 = 1;
    }
    func_19AE90(self->f2AC);
}
/* localdecomp:end func_L39_0069C088 */

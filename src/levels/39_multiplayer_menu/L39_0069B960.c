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

/* localdecomp:start func_L39_0069B960 */
extern u8 D_1A5D8E[];
extern u8 D_00248268[];
extern void func_L39_006CC798(void *, void *);
extern void func_1206F4(void *, void *);
extern void func_1200E0(void *, void *, void *);

typedef struct S_0069B960 {
    u8 pad0[0x2A8];
    s32 f2A8;
    u8 pad1[0x2B8 - 0x2AC];
    s32 f2B8;
    u8 pad2[0x2EC - 0x2BC];
    s32 f2EC;
    s32 f2F0;
    s32 f2F4;
    u8 pad3[0x2FC - 0x2F8];
    s32 f2FC;
    s32 f300;
    u8 pad4[0x344 - 0x304];
    u8 f344[0x18];
    u8 pad5[0x35E - 0x35C];
    u8 f35E[0x384 - 0x35E];
    u8 f384[1];
} S_0069B960;

void func_L39_0069B960(S_0069B960 *self, s32 mode, s32 a, s32 b, s32 c)
{
    s32 i;
    u8 *p;

    self->f2A8 = mode;
    self->f300 = 0;
    self->f2B8 = (mode == 3) ? 1 : self->f2B8;
    if (mode == 3) {
        self->f2EC = a;
        self->f2F0 = b;
        self->f2F4 = c;
    } else if (mode == 4) {
        func_L39_006CC798(self->f384, &D_1A5D8E[0x3CE]);
        self->f2FC = *(s32 *)&D_1A5D8E[0x3CE + 0x14];
        func_1206F4(self->f344, D_1A5D8E);
        func_1200E0(self->f35E, D_00248268, &self->f300);
        self->f300++;
        if (self->f344[0] == '#' || self->f344[0] == '@') {
            p = &self->f344[1];
            for (i = 15; i >= 0; i--) {
                p[-1] = p[0];
                p++;
            }
            self->f344[0x11] = ' ';
        }
        self->f344[0x12] = 0;
    }
}
/* localdecomp:end func_L39_0069B960 */

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

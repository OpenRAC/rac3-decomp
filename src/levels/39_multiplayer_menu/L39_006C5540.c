#include "common.h"

/* localdecomp:start func_L39_006C5540 */
typedef struct W_006C5540 W_006C5540;
typedef struct V_006C5540 {
    u8 pad0[0x1C];
    void (*f1C)(W_006C5540 *, s32, s32);
    u8 pad20[0x38 - 0x20];
    void (*f38)(W_006C5540 *, f32, f32);
    u8 pad3C[0x40 - 0x3C];
    void (*f40)(W_006C5540 *, s32);
    void (*f44)(W_006C5540 *, s32, f32, f32);
    void (*f48)(W_006C5540 *, s32, s32);
    void (*f4C)(W_006C5540 *, s32, s32);
    void (*f50)(W_006C5540 *, s32);
    u8 pad54[0x68 - 0x54];
    void (*f68)(W_006C5540 *);
    u8 pad6C[0x84 - 0x6C];
    void (*f84)(W_006C5540 *, s32);
    u8 pad88[0x90 - 0x88];
    void (*f90)(W_006C5540 *, f32);
    void (*f94)(W_006C5540 *, f32);
    u8 pad98[0xB8 - 0x98];
    void (*fB8)(W_006C5540 *, s32);
} V_006C5540;
struct W_006C5540 {
    u8 pad[0x60];
    V_006C5540 *vt;
};
typedef struct T_006C5540 {
    u8 pad0[0x110];
    W_006C5540 *w[35];
    u8 pad19C[0x2AC - 0x19C];
    u8 f2AC;
    u8 pad2AD[0xB60 - 0x2AD];
    u8 fB60;
    u8 fB61;
    u8 padB62[0xB68 - 0xB62];
    s32 fB68;
    u8 padB6C[0xBA8 - 0xB6C];
    s32 fBA8;
    s32 fBAC;
    u8 fBB0;
    u8 padBB1[0xBB4 - 0xBB1];
    s32 fBB4;
    u8 padBB8[0xD48 - 0xBB8];
    s32 fD48;
} T_006C5540;
extern u8 D_00249778[];
extern s32 D_001DE028_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DE028_sda, 8");
extern s32 D_001DDF0C_sda;
extern f32 D_001DDF10_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DDF10_sda, 4");
extern f32 D_001DDF14_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DDF14_sda, 4");
extern u8 D_001E1B50_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001E1B50_sda, 8");
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern s32 func_00381FF0(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_00120884(s32);
extern void func_L39_005958A0(u8 *, s32, s32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689E58(void *, u8 *, u32, f32, f32);
extern void func_L39_00689DB8(void *, s32);
extern void func_L39_00689B80(void *);
extern void func_L39_0068AAB8(void *);
extern void func_L39_006C69C0(void *, s32);
extern void func_L39_006C7D28(void *, s32, s32, u8 **);
extern void func_L39_006C7E10(void *, s32);
extern void func_L39_006C6B30(void *, s32, s32);
extern void func_L39_006C7C40(void *, s32);
extern s32 func_L39_0068B2F8(void *, s32, s32);
extern void func_L39_006C5B60(void *);

void func_L39_006C5540(T_006C5540 *self)
{
    u8 buf[32];
    u8 *strs[1];
    s32 i;
    s32 a;

    func_L39_0067F100(0x430000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(self, func_00381FF0(0xF68));
    func_L39_00689D28(self, func_00381FF0(0x124));
    func_00120048(buf, D_00249778, func_00381FF0(0x1340));
    func_L39_00689E58(self, buf, 0x706EC8FF, 0.8f, 0.9f);
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_00689B80(self);
    func_L39_0068AAB8(self);
    self->f2AC = 1;

    for (i = 0; i < 7; i++) {
        self->w[i]->vt->f4C(self->w[i], 0x40, 1);
        self->w[i]->vt->f38(self->w[i], 0.8f, 1.0f);
    }
    self->w[10]->vt->f4C(self->w[10], 0x40, 1);
    self->w[10]->vt->f38(self->w[10], 0.85f, 1.0f);
    self->w[8]->vt->f4C(self->w[8], 0x40, 1);
    self->w[8]->vt->f48(self->w[8], 3, 3);
    self->w[8]->vt->f38(self->w[8], 0.7f, 1.0f);
    self->w[8]->vt->fB8(self->w[8], func_00381FF0(D_001DE028_sda[self->fBB0]));
    self->w[12]->vt->f4C(self->w[12], 0x40, 1);
    self->w[12]->vt->f48(self->w[12], 3, 3);
    self->w[12]->vt->f38(self->w[12], 0.75f, 1.0f);
    self->w[14]->vt->f4C(self->w[14], 0x40, 1);
    self->w[14]->vt->f48(self->w[14], 1, 3);
    self->w[14]->vt->f38(self->w[14], 0.8f, 1.0f);
    self->w[13]->vt->f4C(self->w[13], 0x40, 1);
    self->w[13]->vt->f48(self->w[13], 1, 3);
    self->w[13]->vt->f38(self->w[13], 0.8f, 1.0f);
    self->w[14]->vt->f50(self->w[14], D_001DDF0C_sda);
    self->w[13]->vt->f50(self->w[13], D_001DDF0C_sda);
    self->w[11]->vt->f48(self->w[11], 3, 3);
    self->w[11]->vt->f4C(self->w[11], 0x40, 1);

    for (i = 15; i < 35; i++) {
        self->w[i]->vt->f4C(self->w[i], 0x40, 1);
        self->w[i]->vt->f1C(self->w[i], 1, 0);
        self->w[i]->vt->f40(self->w[i], 1);
        if (i >= 25) {
            self->w[i]->vt->f48(self->w[i], 2, 3);
            self->w[i]->vt->f44(self->w[i], 1, 0.1f, 0.0f);
        } else {
            self->w[i]->vt->f48(self->w[i], 1, 3);
            self->w[i]->vt->f44(self->w[i], 1, 0.27f, 0.0f);
        }
    }

    strs[0] = (u8 *)func_00381FF0(0x1341);
    a = func_00381FF0(0x1341);
    func_L39_005958A0(D_001E1B50_sda, a, func_00120884(func_00381FF0(0x1341)));
    strs[0] = D_001E1B50_sda;

    self->w[7]->vt->f68(self->w[7]);
    self->w[7]->vt->f84(self->w[7], 1);
    self->w[7]->vt->f4C(self->w[7], 0x40, 1);
    self->w[7]->vt->f90(self->w[7], D_001DDF10_sda + D_001DDF14_sda);
    self->w[7]->vt->f38(self->w[7], 0.53f, 0.9f);
    self->w[7]->vt->f94(self->w[7], 0.7f);
    self->w[7]->vt->f40(self->w[7], 1);

    func_L39_006C69C0(self, 0);
    func_L39_006C7D28(self, 0, 1, strs);
    func_L39_006C7E10(self, 1);
    if (self->fB61) {
        func_L39_006C6B30(self, 1, self->fB60);
        func_L39_006C7C40(self, self->fB68);
    } else {
        self->fD48 = 0;
        self->fBB4 = 0;
        func_L39_006C6B30(self, 0, 0);
        func_L39_0068B2F8(self, 0, 0);
        self->fBAC = 0x7FFFFFFF;
        self->fBA8 = 1;
        self->fB60 = 0;
        self->fBB0 = 0;
        self->fB68 = 0;
    }
    func_L39_006C5B60(self);
}
/* localdecomp:end func_L39_006C5540 */

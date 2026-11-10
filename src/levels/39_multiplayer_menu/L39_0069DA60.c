#include "common.h"

/* localdecomp:start func_L39_0069DA60 */
typedef struct V_0069DA60 V_0069DA60;
typedef struct W_0069DA60 {
    u8 pad[0x60];
    V_0069DA60 *vt;
} W_0069DA60;
struct V_0069DA60 {
    u8 pad0[0x1C];
    void (*f1C)(W_0069DA60 *, s32, s32);
    u8 pad20[0x40 - 0x20];
    void (*f40)(W_0069DA60 *, s32);
    u8 pad44[0x48 - 0x44];
    void (*f48)(W_0069DA60 *, s32, s32);
    void (*f4C)(W_0069DA60 *, s32, s32);
    void (*f50)(W_0069DA60 *, s32);
    u8 pad54[0x60 - 0x54];
    void (*f60)(W_0069DA60 *, s32);
    u8 pad64[0x88 - 0x64];
    void (*f88)(W_0069DA60 *, s32);
    u8 pad8C[0xA8 - 0x8C];
    void (*fA8)(W_0069DA60 *, s32);
};
typedef struct E_0069DA60 {
    u8 b;
    u8 c;
    u8 pad[2];
    s32 a;
} E_0069DA60;
typedef struct D_0069DA60 {
    s32 f0;
    E_0069DA60 e[4];
    u8 pad24[0x171 - 0x24];
    u8 f171;
} D_0069DA60;
typedef struct C_0069DA60 {
    s32 f0;
    u8 f4;
    u8 pad5[3];
    E_0069DA60 e[3];
} C_0069DA60;
typedef struct T_0069DA60 {
    u8 pad0[0x110];
    W_0069DA60 *w[7];
    u8 pad12C[0x2A8 - 0x12C];
    C_0069DA60 c;
    D_0069DA60 *d;
} T_0069DA60;
extern s32 D_001DCC24_sda;
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern s32 func_00381FF0(s32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689DB8(void *, s32);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A4A8(void *, s32, s32, u32, f32, f32, f32, f32);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_0069E1B0(void *);

void func_L39_0069DA60(T_0069DA60 *self)
{
    s32 i;
    D_0069DA60 *d;
    s32 j;


    func_L39_0067F100(0x1D0000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(self, func_00381FF0(0x18C8));
    func_L39_00689D28(self, func_00381FF0(0x124));
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_0068A6D0(self, 0, 0.5f, 0.346f, 0.82f, 0.41f, 0x332299DE);
    func_L39_0068A6D0(self, 1, 0.5f, 0.71f, 0.82f, 0.3f, 0x332299DE);
    func_L39_0068A4A8(self, 0, 4, 0x331465B7, 0.5f, 0.626f, 0.055999994f, 0.78f);
    func_L39_00689F00(self, 0, 3, 3, 2.0f, 2.0f, 0.8f, 0.04f, 0.045f, 0.0f);
    func_L39_0068AAB8(self);

    for (i = 0; i < 6; i++) {
        if (i != 3) {
            self->w[i]->vt->f40(self->w[i], 1);
            self->w[i]->vt->f4C(self->w[i], 0x40, 1);
            self->w[i]->vt->f1C(self->w[i], 3, 0);
        }
    }
    self->w[6]->vt->f50(self->w[6], D_001DCC24_sda);
    self->w[4]->vt->f1C(self->w[4], 1, 0);
    self->w[3]->vt->f1C(self->w[3], 3, 0);
    self->w[4]->vt->f48(self->w[4], 1, 3);

    d = self->d;
    if (d != 0) {
        self->c.f0 = d->e[3].b;
        self->c.f4 = d->f171 != 0;
        for (j = 0; j < 3; j++) {
            self->c.e[j].a = self->d->e[j].a;
            self->c.e[j].b = self->d->e[j].b;
            self->c.e[j].c = self->d->e[j].c;
        }
        self->w[0]->vt->f88(self->w[0], self->d->e[3].b);
        self->w[1]->vt->f88(self->w[1], self->d->e[self->d->e[3].b].c);
        if (self->d->e[3].b == 0) {
            self->w[2]->vt->f88(self->w[2], self->d->e[self->d->e[3].b].b ^ 1);
        } else {
            self->w[2]->vt->f88(self->w[2], self->d->e[self->d->e[3].b].b);
        }
        self->w[3]->vt->fA8(self->w[3], self->d->e[self->d->e[3].b].a);
        self->w[5]->vt->f60(self->w[5], self->c.f4);
    }
    func_L39_0069E1B0(self);
}
/* localdecomp:end func_L39_0069DA60 */

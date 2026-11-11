#include "common.h"

/* localdecomp:start func_L39_0069C788 */
typedef struct W_0069C788 W_0069C788;
typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(W_0069C788 *, s32, s32);
    u8 pad20[0x20];
    void (*f40)(W_0069C788 *, s32);
    void (*f44)(W_0069C788 *, s32, f32, f32);
    u8 pad48[0x4];
    void (*f4C)(W_0069C788 *, s32, s32);
    u8 pad50[0x10];
    s32 (*f60)(W_0069C788 *, s32);
    u8 pad64[0x24];
    void (*f88)(W_0069C788 *, s32);
    u8 pad8C[0x1C];
    void (*fA8)(W_0069C788 *, s32);
} VT_0069C788;
struct W_0069C788 {
    u8 pad0[0x60];
    VT_0069C788 *vt;
};
typedef struct {
    u8 pad0[0x110];
    W_0069C788 *w[12];
    u8 pad140[0x2A8 - 0x140];
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    s32 f2C0;
    s32 f2C4;
    s32 f2C8;
    s32 f2CC;
    s32 f2D0;
    s32 f2D4;
    s32 f2D8;
    u8 b2DC;
} S_0069C788;

extern void func_L39_0067F100(s32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, s32);
extern void func_L39_00689F00(void *, f32, f32, f32, f32, f32, f32, s32, s32, s32);


void func_L39_0069C788(S_0069C788 *self)
{
    s32 i;
    W_0069C788 **wp;

    func_L39_0067F100(0x2E0000);
    func_L39_0068AAB8(self);
    func_L39_0068A4A8(self, 0, 8, 0.602f, 0.41927778720855713f, 0.05277779698371887f, 0.45499998f, 0x332299DE);
    func_L39_00689F00(self, 1.5f, 1.5f, 0.45499998f, 0.035f, 0.041f, 0.1f, 0, 3, 3);

    wp = self->w;
    for (i = 11; i >= 0; i--) {
        (*wp)->vt->f40(*wp, 1);
        (*wp)->vt->f4C(*wp, 0x40, 1);
        wp++;
    }

    if (self->f2AC == 0) {
        self->w[1]->vt->f1C(self->w[1], 3, 0);
        self->w[3]->vt->f1C(self->w[3], 3, 0);
        self->w[11]->vt->f1C(self->w[11], 3, 0);
        self->w[8]->vt->f1C(self->w[8], 0, 0);
        self->w[7]->vt->f1C(self->w[7], 0, 0);
        self->w[9]->vt->f1C(self->w[9], 0, 0);
        self->w[10]->vt->f1C(self->w[10], 0, 0);
    } else if (self->f2AC == 1) {
        self->w[1]->vt->f1C(self->w[1], 3, 0);
        self->w[3]->vt->f1C(self->w[3], 3, 0);
        self->w[9]->vt->f1C(self->w[9], 3, 0);
        self->w[10]->vt->f1C(self->w[10], 3, 0);
        self->w[8]->vt->f1C(self->w[8], 0, 0);
        self->w[7]->vt->f1C(self->w[7], 0, 0);
        self->w[11]->vt->f1C(self->w[11], 0, 0);
    } else {
        self->w[8]->vt->f1C(self->w[8], 3, 0);
        self->w[7]->vt->f1C(self->w[7], 3, 0);
        self->w[1]->vt->f1C(self->w[1], 2, 0);
        self->w[3]->vt->f1C(self->w[3], 2, 0);
        self->w[9]->vt->f1C(self->w[9], 0, 0);
        self->w[10]->vt->f1C(self->w[10], 0, 0);
        self->w[11]->vt->f1C(self->w[11], 0, 0);
    }

    self->w[3]->vt->f44(self->w[3], 1, 0.32625002f, 0.0f);
    self->w[4]->vt->f44(self->w[4], 1, 0.32625002f, 0.0f);
    self->w[5]->vt->f44(self->w[5], 1, 0.32625002f, 0.0f);
    self->w[6]->vt->f44(self->w[6], 1, 0.32625002f, 0.0f);

    if (self->f2A8 == 2 && self->f2AC == 2) {
        self->f2B4 = 1;
        self->w[8]->vt->f1C(self->w[8], 2, 0);
    }

    self->w[0]->vt->f60(self->w[0], self->f2B0 == 0);
    self->w[1]->vt->f60(self->w[1], self->b2DC);
    self->w[7]->vt->fA8(self->w[7], self->f2D8);
    self->w[8]->vt->f60(self->w[8], self->f2B4 == 1);
    self->w[2]->vt->f60(self->w[2], self->f2B8 == 1);
    self->w[9]->vt->f88(self->w[9], self->f2BC);
    self->w[11]->vt->f88(self->w[11], self->f2BC);
    self->w[10]->vt->fA8(self->w[10], self->f2D4);
    self->w[3]->vt->f60(self->w[3], self->f2C0 == 1);
    self->w[4]->vt->f60(self->w[4], self->f2C4 == 1);
    self->w[5]->vt->f60(self->w[5], self->f2C8 == 1);
    self->w[6]->vt->f60(self->w[6], self->f2CC == 1);

    if (self->f2D0 >= 5) {
        self->f2B0 = 1;
        self->w[0]->vt->f1C(self->w[0], 2, 0);
    } else {
        self->w[0]->vt->f1C(self->w[0], 3, 0);
    }

    if (self->f2D0 >= 6 || self->f2AC == 2) {
        self->b2DC = 0;
        self->w[1]->vt->f1C(self->w[1], 2, 0);
        self->f2C0 = 0;
        self->w[3]->vt->f1C(self->w[3], 2, 0);
    } else {
        self->w[1]->vt->f1C(self->w[1], 3, 0);
        self->w[3]->vt->f1C(self->w[3], 3, 0);
    }

    if (self->f2AC == 0) {
        if (self->f2BC == 1) {
            self->b2DC = 1;
            self->w[1]->vt->f60(self->w[1], 1);
            self->w[1]->vt->f1C(self->w[1], 2, 0);
            self->f2C0 = 1;
            self->w[3]->vt->f60(self->w[3], 1);
            self->w[3]->vt->f1C(self->w[3], 2, 0);
        } else {
            self->w[1]->vt->f1C(self->w[1], 3, 0);
            self->w[3]->vt->f1C(self->w[3], 3, 0);
        }
    }
}
/* localdecomp:end func_L39_0069C788 */

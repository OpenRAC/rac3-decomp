#include "common.h"

/* localdecomp:start func_L39_006AC1A0 */
typedef struct VT_006AC1A0 {
    char _p0[0x40];
    void (*f40)(void *, s32);
    char _p44[0x8];
    void (*f4C)(void *, s32, s32);
} VT_006AC1A0;
typedef struct O_006AC1A0 {
    char _p0[0x60];
    VT_006AC1A0 *vt;
} O_006AC1A0;
typedef struct S_006AC1A0 {
    char _p0[0x110];
    O_006AC1A0 *f110[5];
    O_006AC1A0 *f124;
    O_006AC1A0 *f128;
} S_006AC1A0;
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern s32 func_00381FF0(s32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689E58(void *, s32, u32, f32, f32);
extern void func_L39_00689DB8(void *, s32);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, u32);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_006ACC60(void *);

void func_L39_006AC1A0(S_006AC1A0 *self)
{
    s32 i;
    O_006AC1A0 *o;

    f32 x0, x1, y0, h;

    func_L39_0067F100(0x360000);
    x0 = 0.293f;
    x1 = 0.708f;
    func_L39_0068A9B8(0);
    y0 = 0.405f;
    h = 0.39f;
    func_L39_00689BD8(self, func_00381FF0(0xFE5));
    func_L39_00689D28(self, func_00381FF0(0x124));
    func_L39_00689E58(self, func_00381FF0(0x132B), 0x706EC8FF, 1.0f, 1.0f);
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_0068A6D0(self, 0, x0, 0.5f, 0.41f, 0.725f, 0x332299DE);
    func_L39_0068A6D0(self, 1, x1, 0.266f, y0, 0.255f, 0x332299DE);
    func_L39_0068A6D0(self, 2, x1, 0.631f, y0, 0.461f, 0x332299DE);
    func_L39_0068A4A8(self, 0, 9, x0, 0.19685711f, 0.050357163f, h, 0x332299DE);
    func_L39_00689F00(self, 0, 3, 3, 1.5f, 1.5f, h, 0.035f, 0.041f, 0.1f);
    func_L39_0068AAB8(self);
    for (i = 0; i < 5; i++) {
        o = self->f110[i];
        o->vt->f40(o, 1);
        o = self->f110[i];
        o->vt->f4C(o, 0x40, 1);
    }
    self->f124->vt->f4C(self->f124, 0x8000, 1);
    self->f128->vt->f4C(self->f128, 0x8000, 1);
    func_L39_006ACC60(self);
}
/* localdecomp:end func_L39_006AC1A0 */

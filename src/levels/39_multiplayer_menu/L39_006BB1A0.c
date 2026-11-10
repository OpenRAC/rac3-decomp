#include "common.h"

/* localdecomp:start func_L39_006BB1A0 */
typedef struct VT_006BB1A0 {
    u8 pad0[0x1C];
    void (*f1C)(void *, s32, s32);
    void (*f20)(void *, s32, s32);
    u8 pad24[0x4];
    void (*f28)(void *, f32, f32);
    void (*f2C)(void *, f32, f32);
    u8 pad30[0x8];
    void (*f38)(void *, f32, f32);
    u8 pad3C[0x4];
    void (*f40)(void *, s32);
    void (*f44)(void *, s32, f32, f32);
    void (*f48)(void *, s32, s32);
    void (*f4C)(void *, s32, s32);
    u8 pad50[0x40];
    void (*f90)(void *, f32);
    void (*f94)(void *, f32);
    u8 pad98[0x44];
    void (*fDC)(void *, s32);
    u8 padE0[0x4];
    void (*fE4)(void *, f32);
    void (*fE8)(void *, s32);
} VT_006BB1A0;

typedef struct O_006BB1A0 {
    u8 pad0[0x60];
    VT_006BB1A0 *vt;
} O_006BB1A0;

typedef struct S_006BB1A0 {
    u8 pad0[0x110];
    O_006BB1A0 *objs[28];
} S_006BB1A0;


__asm__(".extern D_L39_0024947C, 4");
__asm__(".extern D_L39_00249480, 4");
__asm__(".extern D_L39_00249484, 4");
__asm__(".extern D_L39_00249488, 4");
__asm__(".extern D_L39_0024948C, 4");
__asm__(".extern D_L39_00249490, 4");
__asm__(".extern D_L39_00249494, 4");
__asm__(".extern D_L39_00249498, 4");
__asm__(".extern D_L39_002494A8, 4");
__asm__(".extern D_L39_002494B8, 4");
extern f32 D_L39_0024947C;
extern f32 D_L39_00249480;
extern f32 D_L39_00249484;
extern f32 D_L39_00249488;
extern f32 D_L39_0024948C;
extern f32 D_L39_00249490;
extern f32 D_L39_00249494;
extern f32 D_L39_00249498;
extern f32 D_L39_002494A8;
extern f32 D_L39_002494B8;
extern f32 D_L39_0024949C;
extern f32 D_L39_002494A0;
extern f32 D_L39_002494A4;
extern f32 D_L39_002494AC;
extern f32 D_L39_002494B0;
extern f32 D_L39_002494B4;
extern f32 D_L39_002494BC;
extern f32 D_L39_002494C0;
extern f32 D_L39_002494C4;

void func_L39_0067F100(s32);
void func_L39_0068A9B8(s32);
s32 func_00381FF0(s32);
void func_L39_00689D28(void *, s32);
void func_L39_00689E58(void *, s32, f32, f32, u32);
void func_L39_00689DB8(void *, s32);
void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
void func_L39_0068A7B8(void *, s32, f32, f32, f32, f32, u32);
void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, u32);
void func_L39_0068AAB8(void *);
void func_L39_00689BB0(void *, s32, s32);
void func_L39_006BD788(void *);
void func_L39_0068B2F8(void *, s32, s32);

/* matches with the file flags plus @ps2as (inline lui/ori float immediates, mixed $gp/lui floats) */
void func_L39_006BB1A0(u8 *arg0) {
    S_006BB1A0 *self = (S_006BB1A0 *)arg0;
    O_006BB1A0 **objs = self->objs;
    O_006BB1A0 **p;
    s32 i;

    func_L39_0067F100(0x3F0000);
    func_L39_0068A9B8(0);
    func_L39_00689D28(arg0, func_00381FF0(0x124));
    func_L39_00689E58(arg0, func_00381FF0(0x1924), 0.7f, 1.0f, 0x706EC8FF);
    func_L39_00689DB8(arg0, func_00381FF0(0xCD5));
    func_L39_0068A6D0(arg0, 0, 0.311f, 0.404f, 0.443f, 0.53f, 0x332299DE);
    func_L39_0068A7B8(arg0, 0, 0.311f, 0.22f, 0.435f, 0.4f, 0x331465B7);
    func_L39_0068A6D0(arg0, 1, 0.725f, 0.287f, 0.37f, 0.29924f, 0x332299DE);
    func_L39_0068A7B8(arg0, 1, 0.725f, 0.195f, 0.227f, 0.33f, 0x331465B7);
    func_L39_0068A4A8(arg0, 1, 3, D_L39_00249498, D_L39_0024949C, D_L39_002494A0, D_L39_002494A4, 0x192299DE);
    func_L39_0068A6D0(arg0, 2, 0.311f, 0.769f, 0.443f, 0.185f, 0x332299DE);
    func_L39_0068A4A8(arg0, 2, 2, D_L39_002494A8, D_L39_002494AC, D_L39_002494B0, D_L39_002494B4, 0x192299DE);
    func_L39_0068A6D0(arg0, 3, 0.725f, 0.6525f, 0.37f, 0.42f, 0x332299DE);
    func_L39_0068A7B8(arg0, 3, 0.723f, 0.509f, 0.338f, 0.332f, 0x331465B7);
    func_L39_0068A4A8(arg0, 3, 6, D_L39_002494B8, D_L39_002494BC, D_L39_002494C0, D_L39_002494C4, 0x192299DE);
    func_L39_0068AAB8(arg0);

    self->objs[10]->vt->fE8(self->objs[10], 1);
    self->objs[10]->vt->f90(self->objs[10], 0.045f);
    self->objs[10]->vt->f94(self->objs[10], 0.85f);
    self->objs[10]->vt->fE4(self->objs[10], 0.31f);
    self->objs[8]->vt->fE8(self->objs[8], 1);
    self->objs[8]->vt->f90(self->objs[8], 0.045f);
    self->objs[8]->vt->f94(self->objs[8], 1.0f);
    self->objs[3]->vt->fE8(self->objs[3], 1);
    self->objs[3]->vt->f38(self->objs[3], 0.4f, 0.44f);
    self->objs[3]->vt->f94(self->objs[3], 1.0f);
    self->objs[11]->vt->f40(self->objs[11], 1);
    self->objs[11]->vt->f48(self->objs[11], 2, 3);
    self->objs[11]->vt->f4C(self->objs[11], 0x40, 1);
    self->objs[11]->vt->f28(self->objs[11], 0.885f, 0.173f);
    self->objs[11]->vt->f2C(self->objs[11], 0.3f, 0.05f);
    self->objs[11]->vt->f44(self->objs[11], 1, 0.12000000476837158f, 0.0f);
    self->objs[11]->vt->f1C(self->objs[11], 1, 0);
    self->objs[7]->vt->f48(self->objs[7], 1, 3);
    self->objs[7]->vt->f4C(self->objs[7], 0x40, 1);
    self->objs[7]->vt->f28(self->objs[7], 0.5595f, 0.173f);
    self->objs[7]->vt->f40(self->objs[7], 1);
    self->objs[9]->vt->f48(self->objs[9], 1, 3);
    self->objs[9]->vt->f4C(self->objs[9], 0x40, 1);
    self->objs[9]->vt->f28(self->objs[9], 0.5595f, 0.48f);
    self->objs[9]->vt->f40(self->objs[9], 1);
    self->objs[5]->vt->f20(self->objs[5], 0, 0);
    self->objs[5]->vt->f4C(self->objs[5], 0x40, 1);
    self->objs[5]->vt->f28(self->objs[5], 0.31f, 0.772f);
    self->objs[4]->vt->f4C(self->objs[4], 0x40, 1);
    self->objs[4]->vt->f28(self->objs[4], 0.31f, 0.71f);
    self->objs[6]->vt->f4C(self->objs[6], 0x40, 1);
    self->objs[6]->vt->f28(self->objs[6], 0.31f, 0.83f);
    self->objs[1]->vt->f48(self->objs[1], 1, 3);
    self->objs[2]->vt->f48(self->objs[2], 2, 3);
    self->objs[0]->vt->f4C(self->objs[0], 0x40, 1);
    self->objs[0]->vt->f44(self->objs[0], 1, 0.4f, 0.0f);
    self->objs[1]->vt->f20(self->objs[1], 0, 0);
    self->objs[2]->vt->f20(self->objs[2], 0, 0);
    self->objs[0]->vt->f38(self->objs[0], D_L39_0024947C, D_L39_00249480);
    self->objs[1]->vt->f38(self->objs[1], D_L39_00249490, D_L39_00249494);
    self->objs[2]->vt->f38(self->objs[2], D_L39_00249490, D_L39_00249494);
    self->objs[1]->vt->f28(self->objs[1], D_L39_00249484, D_L39_00249488);
    self->objs[2]->vt->f28(self->objs[2], D_L39_0024948C, D_L39_00249488);

    p = &self->objs[4];
    for (i = 2; i >= 0; i--) {
        (*p)->vt->f44(*p, 1, 0.4229999780654907f, 0.0f);
        p++;
    }

    p = &objs[12];
    for (i = 0; i < 16; i++) {
        f32 x = i % 4;
        f32 y = i / 4;
        (*p)->vt->f2C(*p, 0.0275f, 0.035f);
        (*p)->vt->f28(*p, 0.875f - x * 0.032f, y * 0.0575f + 0.223f);
        (*p)->vt->fDC(*p, 0xED26);
        p++;
    }

    *(s32 *)(arg0 + 0x2FC) = 0;
    *(s32 *)(arg0 + 0x300) = 0;
    func_L39_00689BB0(arg0, 0x40, 1);
    func_L39_006BD788(arg0);
    if (*(s32 *)(arg0 + 0x2F0) == 2) {
        self->objs[0]->vt->f1C(self->objs[0], 3, 0);
        func_L39_0068B2F8(arg0, 4, 0);
    } else if (*(s32 *)(arg0 + 0x2F0) == 3) {
        self->objs[0]->vt->f1C(self->objs[0], 1, 0);
        func_L39_0068B2F8(arg0, 4, 0);
    } else {
        self->objs[0]->vt->f1C(self->objs[0], 3, 0);
        func_L39_0068B2F8(arg0, 0, 0);
    }
    *(s32 *)(arg0 + 0x310) = 250;
    *(s32 *)(arg0 + 0x8764) = 6;
}
/* localdecomp:end func_L39_006BB1A0 */

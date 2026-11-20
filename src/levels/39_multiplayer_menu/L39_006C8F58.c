#include "common.h"

/* localdecomp:start func_L39_006C8F58 */
typedef struct S_006C8F58_obj S_006C8F58_obj;
typedef struct {
    char *s[2];
} S_006C8F58_two;


typedef struct {
    char pad0[0x1C];
    void (*m1C)(S_006C8F58_obj *, s32, s32);
    char pad20[0x20];
    void (*m40)(S_006C8F58_obj *, s32);
    void (*m44)(S_006C8F58_obj *, s32, f32, f32);
    char pad48[0x4];
    void (*m4C)(S_006C8F58_obj *, s32, s32);
    char pad50[0x1C];
    s32 (*m6C)(S_006C8F58_obj *, s32, char **);
    char pad70[0x14];
    void (*m84)(S_006C8F58_obj *, s32);
    char pad88[0x8];
    void (*m90)(S_006C8F58_obj *, f32);
    void (*m94)(S_006C8F58_obj *, f32);
    char pad98[0x4C];
    void (*mE4)(S_006C8F58_obj *, f32);
} S_006C8F58_vt;

struct S_006C8F58_obj {
    char pad[0x60];
    S_006C8F58_vt *vt;
};

typedef struct {
    char pad0[0x110];
    S_006C8F58_obj *f110;
    S_006C8F58_obj *f114;
    S_006C8F58_obj *f118[3];
    char pad124[0x184];
    u8 f2A8;
    char pad2A9[0x10B];
    u8 f3B4;
} S_006C8F58_self;

extern char D_L39_002498D0[];
char *func_00381FF0(s32);
s32 func_L39_0067F100(s32);
void func_L39_0068A9B8(s32);
void func_L39_00689D28(void *, char *);
void func_L39_00689DB8(void *, char *);
void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
void func_L39_0068A7B8(void *, s32, f32, f32, f32, f32, u32);
void func_L39_0068AAB8(void *);
s32 func_L39_0068B2F8(void *, s32, s32);

void func_L39_006C8F58(S_006C8F58_self *self)
{
    S_006C8F58_two q;
    S_006C8F58_two p;
    S_006C8F58_two p2;
    S_006C8F58_obj **objs;
    s32 i;

    objs = self->f118;
    func_L39_0067F100(0x2B0000);
    func_L39_0068A9B8(0);
    func_L39_00689D28(self, func_00381FF0(0x124));
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_0068A6D0(self, 0, 0.291f, 0.297f, 0.402f, 0.315f, 0x332299DE);
    func_L39_0068A6D0(self, 1, 0.291f, 0.623f, 0.402f, 0.315f, 0x332299DE);
    func_L39_0068A6D0(self, 2, 0.291f, 0.825f, 0.402f, 0.07f, 0x332299DE);
    func_L39_0068A6D0(self, 3, 0.706f, 0.5f, 0.41f, 0.72f, 0x332299DE);
    func_L39_0068A7B8(self, 0, 0.291f, 0.1945f, 0.245f, 0.38200003f, 0x332299DE);
    func_L39_0068A7B8(self, 1, 0.291f, 0.5205f, 0.245f, 0.38200003f, 0x332299DE);
    func_L39_0068AAB8(self);
    p.s[0] = D_L39_002498D0;
    p.s[1] = func_00381FF0(0x100F);
    q = p;
    self->f110->vt->m6C(self->f110, 2, q.s);
    self->f110->vt->mE4(self->f110, 0.35476002f);
    self->f110->vt->m94(self->f110, 0.85f);
    self->f110->vt->m1C(self->f110, 2, 0);
    self->f110->vt->m84(self->f110, 1);
    self->f110->vt->m40(self->f110, 1);
    self->f110->vt->m90(self->f110, 0.049000002f);
    p2.s[0] = D_L39_002498D0;
    p2.s[1] = func_00381FF0(0x100C);
    q = p2;
    self->f114->vt->m6C(self->f114, 2, q.s);
    self->f114->vt->mE4(self->f114, 0.35476002f);
    self->f114->vt->m94(self->f114, 0.85f);
    self->f114->vt->m1C(self->f114, 2, 0);
    self->f114->vt->m84(self->f114, 1);
    self->f114->vt->m40(self->f114, 1);
    self->f114->vt->m90(self->f114, 0.049000002f);
    for (i = 2; i >= 0; i--) {
        (*objs)->vt->m1C(*objs, 3, 0);
        (*objs)->vt->m4C(*objs, 0x40, 1);
        (*objs)->vt->m44(*objs, 1, 0.382f, 0.0f);
        objs++;
    }
    self->f2A8 = 1;
    self->f3B4 = 1;
    func_L39_0068B2F8(self, 4, 0);
}
/* localdecomp:end func_L39_006C8F58 */

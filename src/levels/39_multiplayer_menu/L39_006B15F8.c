#include "common.h"

/* declared by functions of L39_006B0720.c, which this file was cut from */
void func_L39_00688400(void *, s32);

/* localdecomp:start func_L39_006B15F8 */
typedef struct S_006B15F8_obj S_006B15F8_obj;

typedef struct {
    char pad0[0x1C];
    void (*m1C)(S_006B15F8_obj *, s32, s32);
    char pad20[0x20];
    void (*m40)(S_006B15F8_obj *, s32);
    char pad44[0x0];
    void (*m44)(S_006B15F8_obj *, s32, f32, f32);
    char pad48[0x4];
    void (*m4C)(S_006B15F8_obj *, s32, s32);
    char pad50[0x1C];
    s32 (*m6C)(S_006B15F8_obj *, s32, char **);
    char pad70[0x14];
    void (*m84)(S_006B15F8_obj *, s32);
    char pad88[0x8];
    void (*m90)(S_006B15F8_obj *, f32);
} S_006B15F8_vt;

struct S_006B15F8_obj {
    char pad[0x60];
    S_006B15F8_vt *vt;
};

typedef struct {
    char pad0[0x110];
    S_006B15F8_obj *f110[8];
    char pad130[0x4];
    S_006B15F8_obj *f134;
    S_006B15F8_obj *f138;
    S_006B15F8_obj *f13C;
    char pad140[0x16C];
    s32 f2AC;
    s32 f2B0;
    char pad2B4[0x1D8];
    u8 f48C;
} S_006B15F8_self;

extern char D_L39_00248EA0[];
char *func_00381FF0(s32);
s32 func_L39_0067F100(s32);
void func_L39_0068A9B8(s32);
void func_L39_00689BD8(void *, void *);
void func_L39_00689D28(void *, char *);
void func_L39_00689DB8(void *, char *);
void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
void func_L39_0068A4A8(void *, s32, s32, s32, f32, f32, f32, f32);
void func_L39_0068AAB8(void *);
s32 func_L39_0068B2F8(void *, s32, s32);

void func_L39_006B15F8(S_006B15F8_self *self)
{
    S_006B15F8_obj **objs;
    s32 i;

    objs = self->f110;
    func_L39_0067F100(0x390000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(self, func_00381FF0(0xF5B));
    func_L39_00689D28(self, func_00381FF0(0x124));
    func_L39_00689DB8(self, func_00381FF0(0x18D5));
    func_L39_0068A6D0(self, 0, 0.272f, 0.34f, 0.372f, 0.405f, 0x332299DE);
    func_L39_0068A6D0(self, 1, 0.688f, 0.34f, 0.445f, 0.405f, 0x332299DE);
    func_L39_0068A6D0(self, 2, 0.312f, 0.706f, 0.45f, 0.31f, 0x332299DE);
    func_L39_0068A6D0(self, 3, 0.728f, 0.706f, 0.367f, 0.31f, 0x332299DE);
    func_L39_0068A4A8(self, 0, 6, 0x332299DE, 0.272f, 0.2025f, 0.054999992f, 0.33200002f);
    func_L39_0068AAB8(self);
    {
        char *two[2] = { D_L39_00248EA0, func_00381FF0(0x100C) };
        self->f138->vt->m6C(self->f138, 2, two);
    }
    self->f138->vt->m1C(self->f138, 2, 0);
    self->f138->vt->m84(self->f138, 1);
    self->f138->vt->m40(self->f138, 1);
    self->f138->vt->m90(self->f138, 0.048333347f);
    self->f134->vt->m1C(self->f134, 1, 0);
    self->f134->vt->m4C(self->f134, 0x40, 1);
    self->f134->vt->m44(self->f134, 1, 0.32700002f, 0.0f);
    for (i = 7; i >= 0; i--) {
        (*objs)->vt->m1C(*objs, 3, 0);
        (*objs)->vt->m4C(*objs, 0x40, 1);
        (*objs)->vt->m44(*objs, 1, 0.33200002f, 0.0f);
        objs++;
    }
    self->f13C->vt->m1C(self->f13C, 0, 0);
    self->f13C->vt->m40(self->f13C, 1);
    self->f110[7]->vt->m1C(self->f110[7], 0, 0);
    func_L39_0068B2F8(self, 0, 0);
    self->f2B0 = 0;
    self->f48C = 1;
    self->f2AC = 0;
}
/* localdecomp:end func_L39_006B15F8 */

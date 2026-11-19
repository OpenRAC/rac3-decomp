#include "common.h"

/* localdecomp:start func_L39_006B41E8 */
extern u8 D_L39_0047E438[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B41E8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E438;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B41E8 */

/* localdecomp:start func_L39_006B4210 */
typedef struct O_006B4210 O_006B4210;
typedef struct VT_006B4210 {
    u8 pad0[0x1C];
    s32 (*fn1C)(O_006B4210 *, s32, s32);
    u8 pad20[0x40 - 0x20];
    s32 (*fn40)(O_006B4210 *, s32);
    s32 (*fn44)(O_006B4210 *, s32, f32, f32);
    u8 pad48[0x4C - 0x48];
    s32 (*fn4C)(O_006B4210 *, s32, s32);
    u8 pad50[0x54 - 0x50];
    void (*fn54)(O_006B4210 *, s32);
    u8 pad58[0x5C - 0x58];
    void (*fn5C)(O_006B4210 *, f32);
    u8 pad60[0xB4 - 0x60];
    void (*fnB4)(O_006B4210 *);
} VT_006B4210;
struct O_006B4210 {
    u8 pad0[0x60];
    VT_006B4210 *vt;
};
typedef struct S_006B4210 {
    u8 pad0[0x110];
    O_006B4210 *f110[26];
    u8 pad178[0x2B5 - 0x178];
    u8 f2B5;
    u8 f2B6;
    u8 pad2B7[0x2D8 - 0x2B7];
    u8 f2D8;
    u8 f2D9;
    u8 pad2DA[0x2E0 - 0x2DA];
    u8 f2E0;
    u8 pad2E1[0x2E8 - 0x2E1];
    u8 f2E8;
    u8 f2E9;
    u8 f2EA;
    u8 f2EB;
} S_006B4210;
typedef struct G_006B4210 {
    u8 pad0[0x38];
    void *f38;
} G_006B4210;

__asm__(".extern D_0024D760, 16");
extern s32 *D_0024D760;
extern f32 D_001DD854_sda;
extern f32 D_001DD858_sda;
extern f32 D_001DD85C_sda;
extern f32 D_001DD860_sda;
extern f32 D_001DD864_sda;
extern f32 D_001DD868_sda;
extern f32 D_001DD86C_sda;
extern f32 D_001DD870_sda;
extern f32 D_001DD874_sda;
extern f32 D_001DD878_sda;
extern f32 D_001DD87C_sda;
extern f32 D_001DD880_sda;
extern f32 D_001DD884_sda;
extern f32 D_001DD888_sda;
extern f32 D_001DD88C_sda;
extern f32 D_001DD890_sda;
extern f32 D_001DD894_sda;
extern f32 D_001DD898_sda;
extern f32 D_001DD89C_sda;
extern f32 D_001DD8A0_sda;
extern f32 D_001DD8A4_sda;
extern f32 D_001DD8A8_sda;
extern f32 D_001DD8AC_sda;
extern f32 D_001DD8B0_sda;
extern f32 D_001DD8B4_sda;
extern s32 func_00381FF0(s32);
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689DB8(void *, s32);
extern void func_L39_00689E58(void *, s32, u32, f32, f32);
extern void func_L39_0068A6D0(void *, s32, u32, f32, f32, f32, f32);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L39_0068A4A8(void *, s32, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_006CEA18(void *, s32);

void func_L39_006B4210(S_006B4210 *self)
{
    O_006B4210 *o;
    s32 i;

    func_L39_0067F100(0x3B0000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(self, func_00381FF0(0xF88));
    func_L39_00689D28(self, func_00381FF0(0x124));
    func_L39_00689E58(self, func_00381FF0(0x160E), 0x706EC8FF, 1.0f, 1.0f);
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_0068A6D0(self, 0, 0x332299DE, D_001DD854_sda, D_001DD858_sda, D_001DD85C_sda, D_001DD860_sda);
    func_L39_0068A6D0(self, 1, 0x332299DE, D_001DD864_sda, D_001DD868_sda, D_001DD86C_sda, D_001DD870_sda);
    func_L39_0068A6D0(self, 2, 0x332299DE, D_001DD874_sda, D_001DD878_sda, D_001DD87C_sda, D_001DD880_sda);
    func_L39_0068A6D0(self, 3, 0x332299DE, D_001DD884_sda, D_001DD888_sda, D_001DD88C_sda, D_001DD890_sda);
    func_L39_0068A6D0(self, 4, 0x332299DE, D_001DD894_sda, D_001DD898_sda, D_001DD89C_sda, D_001DD8A0_sda);
    func_L39_00689F00(self, 0, 3, 3, 1.5f, 1.5f, D_001DD89C_sda - D_001DD8A4_sda, D_001DD8AC_sda, D_001DD8B0_sda, D_001DD8B4_sda);

    func_L39_0068A4A8(self, 0, 2, 0x332299DE, D_001DD874_sda,
                      (D_001DD878_sda + ((D_001DD880_sda - D_001DD8A4_sda) * -0.5f) / 3.0f) + D_001DD8A8_sda,
                      (D_001DD878_sda + ((D_001DD880_sda - D_001DD8A4_sda) * 0.5f) / 3.0f) - (D_001DD878_sda + ((D_001DD880_sda - D_001DD8A4_sda) * -0.5f) / 3.0f),
                      D_001DD87C_sda - D_001DD8A4_sda);
    func_L39_0068A4A8(self, 1, 7, 0x332299DE, D_001DD884_sda,
                      (D_001DD888_sda + ((D_001DD890_sda - D_001DD8A4_sda) * -3.0f) / 8.0f) + D_001DD8A8_sda,
                      (D_001DD888_sda + ((D_001DD890_sda - D_001DD8A4_sda) * -2.0f) / 8.0f) - (D_001DD888_sda + ((D_001DD890_sda - D_001DD8A4_sda) * -3.0f) / 8.0f),
                      D_001DD88C_sda - D_001DD8A4_sda);
    func_L39_0068A4A8(self, 2, 4, 0x332299DE, D_001DD894_sda,
                      (D_001DD898_sda + ((D_001DD8A0_sda - D_001DD8A4_sda) * -1.5f) / 5.0f) + D_001DD8A8_sda,
                      (D_001DD898_sda + ((D_001DD8A0_sda - D_001DD8A4_sda) * -0.5f) / 5.0f) - (D_001DD898_sda + ((D_001DD8A0_sda - D_001DD8A4_sda) * -1.5f) / 5.0f),
                      D_001DD89C_sda - D_001DD8A4_sda);
    func_L39_0068AAB8(self);

    o = self->f110[1];
    o->vt->fn1C(o, 1, 0);
    o = self->f110[1];
    o->vt->fnB4(o);
    o = self->f110[1];
    o->vt->fn54(o, 0);
    for (i = 0; i < 9; i++) {
        self->f110[i + 2]->vt->fn4C(self->f110[i + 2], 0x40, 1);
        self->f110[i + 2]->vt->fn44(self->f110[i + 2], 1, D_001DD89C_sda - D_001DD8A4_sda, 0.0f);
    }
    o = self->f110[13];
    o->vt->fnB4(o);
    o = self->f110[14];
    o->vt->fnB4(o);
    o = self->f110[15];
    o->vt->fnB4(o);
    o = self->f110[16];
    o->vt->fnB4(o);
    o = self->f110[17];
    o->vt->fnB4(o);
    o = self->f110[18];
    o->vt->fnB4(o);
    o = self->f110[19];
    o->vt->fnB4(o);
    o = self->f110[20];
    o->vt->fnB4(o);
    o = self->f110[21];
    o->vt->fnB4(o);
    o = self->f110[2];
    o->vt->fn1C(o, 2, 0);
    o = self->f110[3];
    o->vt->fn1C(o, 2, 0);
    o = self->f110[4];
    o->vt->fn1C(o, 2, 0);
    o = self->f110[5];
    o->vt->fn1C(o, 0, 0);
    o = self->f110[6];
    o->vt->fn1C(o, 2, 0);
    o = self->f110[7];
    o->vt->fn1C(o, 0, 0);
    o = self->f110[8];
    o->vt->fn1C(o, 2, 0);
    o = self->f110[9];
    o->vt->fn1C(o, 0, 0);
    o = self->f110[10];
    o->vt->fn1C(o, 0, 0);
    o = self->f110[20];
    o->vt->fn44(o, 1, 1.0f, 0.0f);
    for (i = 0; i < 10; i++) {
        O_006B4210 *p = self->f110[i + 11];
        p->vt->fn40(p, 1);
        p->vt->fn5C(p, 0.375f);
        p->vt->fn54(p, 1);
        p->vt->fn1C(p, 1, 0);
        p->vt->fnB4(p);
    }
    {
        O_006B4210 *p = self->f110[21];
        p->vt->fn40(p, 1);
        p->vt->fn1C(p, 1, 0);
    }
    o = self->f110[22];
    o->vt->fn1C(o, 0, 0);
    o = self->f110[23];
    o->vt->fn1C(o, 0, 0);
    o = self->f110[24];
    o->vt->fn1C(o, 0, 0);
    o = self->f110[25];
    o->vt->fn1C(o, 0, 0);
    self->f2E9 = 1;
    self->f2D8 = 1;
    self->f2EA = 0;
    self->f2EB = 0;
    func_L39_006CEA18((void *)D_0024D760[0x38 / 4], 0);
    self->f2D9 = 1;
    self->f2E0 = 1;
    self->f2E8 = 1;
    self->f2B6 = 1;
    self->f2B5 = 1;
}
/* localdecomp:end func_L39_006B4210 */

/* localdecomp:start func_L39_006B4898 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006B4898(void *);

extern void func_L39_0067F168();
void func_L39_006B4898(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006B4898 */

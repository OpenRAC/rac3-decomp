#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L02_0039C730);

/* localdecomp:start func_L02_0039CD18 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_39CD18;
typedef struct P_39CD18 {
    V4_39CD18 v;
    struct O_39CD18 *owner;
    float f14;
    char pad18[8];
    float f20;
    int f24;
} P_39CD18;
typedef struct O_39CD18 {
    char pad0[0x10];
    V4_39CD18 v10;
    unsigned char b20;
    char pad21[2];
    unsigned char b23;
    char pad24[8];
    float f2C;
    unsigned char b30;
    unsigned char b31;
    short s32;
    unsigned short flags;
    char pad36[2];
    long q38;
    char pad40[0x28];
    P_39CD18 *p68;
    char pad6C[0x54];
    V4_39CD18 vC0;
    char padD0[0x20];
    V4_39CD18 vF0;
} O_39CD18;
extern O_39CD18 *func_003C24B0(int a, int b);
extern void func_0038D308(V4_39CD18 *a, V4_39CD18 *b);
O_39CD18 *func_L02_0039CD18(O_39CD18 *a, V4_39CD18 *b, V4_39CD18 *c, float f) {
    O_39CD18 *o = func_003C24B0(0x18A5, 0x80);
    P_39CD18 *p;
    V4_39CD18 tmp;
    if (o != 0) {
        o->b30 = 255;
        o->s32 = 255;
        o->b31 = 1;
        o->b20 = 0;
        p = o->p68;
        o->q38 = a->q38;
        o->v10 = *c;
        p->v = *b;
        p->f14 = f;
        p->f20 = 0.15f;
        p->owner = a;
        o->flags |= 0x208;
        o->vF0 = a->vF0;
        func_0038D308(&o->vC0, &o->vF0);
        o->flags |= 0x100;
        o->b23 = 0x80;
        o->f2C = 1.0f;
        p->f24 = 0;
        tmp = *c;
    }
    return o;
}
/* localdecomp:end func_L02_0039CD18 */

/* localdecomp:start func_L02_0039CE20 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_39CE20;
typedef struct B_39CE20 {
    char pad0[0x6C];
    int f6C;
    float f70;
    int f74;
    short f78;
    short f7A;
    short f7C;
    short f7E;
    float f80, f84, f88, f8C;
} B_39CE20;
typedef struct S_39CE20 {
    char pad0[0x10];
    float f10, f14, f18, f1C;
    unsigned char f20;
    char pad21[0x47];
    B_39CE20 *p68;
    char pad6C[0x84];
    float fF0;
} S_39CE20;
typedef struct G_39CE20 {
    char pad0[0x35C];
    struct S_39CE20 *f35C;
    int f360;
} G_39CE20;
extern G_39CE20 D_001A4BE0_39CE20;
__asm__(".extern D_001A4BE0_39CE20, 16");
extern void func_L02_0039D160();
extern int func_L01_004AA710(void *, int);
extern int func_003A52A0(int, int, void *);
extern int func_0038CB00(void *);
extern void func_L01_00443B88(V4_39CE20 *v, float a, float b);
extern float func_003C3BE8(float a, float b, float c);

void func_L02_0039CE20(S_39CE20 *self) {
    B_39CE20 *p = self->p68;
    V4_39CE20 tmp;
    func_L02_0039D160(self);
    if (self->f20 != 0) {
        if (func_L01_004AA710(self, p->f74) == 0) {
            p->f74 = func_003A52A0(0, 4, self);
        }
    }
    switch (self->f20) {
    case 1:
        if (D_001A4BE0_39CE20.f35C == self && D_001A4BE0_39CE20.f360 >= 2) {
            self->f20 = 2;
            p->f78 = (p->f7C * 5 + 2) / 6;
            p->f70 = 1.0f / p->f78;
            func_003A52A0(2, 0, self);
        }
        break;
    case 2:
        if (func_0038CB00(&p->f78)) {
            p->f6C &= -2;
            self->f20 = 3;
            p->f78 = (p->f7E * 5 + 2) / 6;
            p->f70 = 1.0f / p->f78;
            self->f10 = p->f80;
            self->f14 = p->f84;
            self->f18 = p->f88;
            self->f1C = p->f8C;
            p->f7A = 1;
            func_003A52A0(3, 0, self);
        } else if (p->f7A != 0) {
            p->f80 = self->f10;
            p->f84 = self->f14;
            p->f88 = self->f18;
            p->f8C = self->f1C;
            func_L01_00443B88(&tmp, 0.0f, 0.1f);
            vec_add_ab(&self->f10, &self->f10, &tmp);
            p->f7A = 0;
        } else {
            self->f10 = p->f80;
            self->f14 = p->f84;
            self->f18 = p->f88;
            self->f1C = p->f8C;
            p->f7A = 1;
        }
        break;
    case 3:
        if (func_0038CB00(&p->f78)) {
            p->f78 = 250;
            self->f20 = 4;
        } else {
            self->fF0 = func_003C3BE8(1.3089969f, 0.0f, p->f78 * p->f70);
        }
        break;
    case 4:
        if (func_0038CB00(&p->f78)) {
            func_003A52A0(3, 0, self);
            p->f78 = (p->f7E * 15 + 2) / 6;
            p->f70 = 1.0f / p->f78;
            self->f20 = 5;
        }
        break;
    case 5:
        if (func_0038CB00(&p->f78)) {
            self->f20 = 1;
        } else {
            self->fF0 = func_003C3BE8(0.0f, 1.3089969f, p->f78 * p->f70);
        }
        break;
    case 6:
        break;
    }
}
/* localdecomp:end func_L02_0039CE20 */

/* localdecomp:start func_L02_0039D160 */
typedef struct {
    u8 pad0[0x6C];
    u32 flags6C;
    u8 pad70[0xA];
    s16 f7A;
    u16 f7C;
} B_39D160;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x47];
    B_39D160 *p68;
    u8 pad6C[0x44];
    u8 fB0;
} S_39D160;
extern s32 D_001C5290[][16];
__asm__(".extern D_001C5290, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");

void func_L02_0039D160(S_39D160 *self) {
    B_39D160 *p;
    s32 v;
    if (self->f20 == 0) {
        p = self->p68;
        p->f7A = 1;
        p->flags6C |= 1;
        self->f20 = 1;
        v = D_001C5290[D_001D545C][self->fB0];
        if (v >= 4) v = 3;
        p->f7C = p->f7C * (s32)(v * 0.3f + 1.0f);
    }
}
/* localdecomp:end func_L02_0039D160 */

INCLUDE_ASM("asm/levels", func_L02_0039D200);

/* localdecomp:start func_L02_0039D680 */
typedef struct {
    u8 pad0[4];
    s16 f4;
    s16 f6;
    float f8;
    float fC;
    float v10[4];
    u8 pad20[0x54];
    float f74;
    u8 pad78[0x18];
    s32 f90;
    u8 pad94[0x10];
    s32 fA4;
} B_39D680;
typedef struct {
    u8 pad0[0x18];
    float f18;
    u8 pad1C[4];
    u8 f20;
    u8 pad21[0x47];
    B_39D680 *p68;
    u8 pad6C[0x44];
    u8 fB0;
    u8 padB1[0x43];
    float fF4;
} S_39D680;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern u8 D_001BBC40[][16];
__asm__(".extern D_001BBC40, 16");
extern void func_L01_0044E850(void *a, void *b, int c, float x, float y);

void func_L02_0039D680(S_39D680 *self) {
    B_39D680 *p;
    float t;
    u8 st;
    float one;
    if (self->f20 == 0) {
        p = self->p68;
        p->fC = self->f18;
        p->f74 = 0;
        p->f8 = 0.01f;
        one = 1.0f;
        t = p->f74;
        func_L01_0044E850(self, p->v10, 0, one, t);
        p->f74 = t;
        func_L01_0044E850(self, p->v10, 0, one, t);
        if (p->f6 != 0) {
            if (p->fA4 == 0 || (D_001BBC40[D_001D545C_sda][self->fB0] & 0x80) == 0) {
                if (p->f90 != 0) {
                    self->fF4 = -1.5707964f;
                    self->f18 = p->fC + 10.0f;
                } else {
                    self->fF4 = 1.5707964f;
                }
            }
            st = 2;
        } else st = 1;
        self->f20 = st;
    }
}
/* localdecomp:end func_L02_0039D680 */

LINKER_REMNANT("asm/levels", func_L02_0039D7C0);

INCLUDE_ASM("asm/levels", func_L02_0039D7D0);

/* localdecomp:start func_L02_0039E208 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_39E208;
typedef struct B_39E208 {
    char pad0[4];
    int timer;
    char pad1[6];
    unsigned char kind;
    char pad2[1];
    V4_39E208 v;
} B_39E208;
typedef struct A_39E208 {
    char pad0[0x10];
    V4_39E208 v;
    unsigned char active;
    char pad1[0xF];
    unsigned char flag;
    char pad2[0x37];
    B_39E208 *b;
} A_39E208;

void func_L02_0039E208(A_39E208 *a) {
    B_39E208 *b;
    if (a->active == 0) {
        b = a->b;
        b->v = a->v;
        if (b->kind == 0) {
            b->timer = 0;
        } else if (b->kind == 1) {
            b->timer = 30;
        } else {
            b->timer = 60;
        }
        a->flag = 255;
        a->active = 1;
    }
}
/* localdecomp:end func_L02_0039E208 */

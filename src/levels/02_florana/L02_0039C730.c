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

/* localdecomp:start func_L02_0039D200 */
typedef struct {
    s32 f0;
    s16 f4;
    s16 f6;
    float f8;
    float fC;
    float v10[4];
    u8 pad20[0x54];
    float f74;
    u8 pad78[0x18];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    s32 fA0;
    s32 fA4;
} B_39D200;
typedef struct {
    u8 pad0[0x18];
    float f18;
    u8 pad1C[4];
    u8 f20;
    u8 pad21[0x47];
    B_39D200 *p68;
    u8 pad6C[0x44];
    u8 fB0;
    u8 padB1[0x43];
    float fF4;
} S_39D200;
typedef struct {
    u8 pad0[0xD0];
    u8 fD0;
    u8 padD1[0xB];
    S_39D200 *fDC;
} E_39D200;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern u8 D_001BBC40[][16];
__asm__(".extern D_001BBC40, 16");
extern u8 D_001A4C60[];
extern s16 *D_L02_0021B460[];
extern u8 D_001A30B0[];
extern void func_L01_0044E850(void *a, void *b, int c, float x, float y);
extern void func_L02_0039D680();
extern s32 func_L01_00456500(void *, s32);
extern void func_003C5D60(s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern int func_0038CB00(void *);
extern float func_003C3BE8(float, float, float);
extern int func_L01_004AA710(void *, int);
extern int func_003A52A0(int, int, void *);
extern void func_003A4F28(s32);
extern s32 func_00382380(void *, s32, s32);

void func_L02_0039D200(S_39D200 *self) {
    B_39D200 *p = self->p68;
    float one, t, a;
    E_39D200 *e;
    s32 i;
    func_L02_0039D680(self);
    switch (self->f20) {
    case 1:
        if (p->f0 == -1) break;
        if (func_L01_00456500(D_001A4C60, p->f0) == 0) break;
        if (p->fA4 != 0 && (D_001BBC40[D_001D545C_sda][self->fB0] & 0x80)) break;
        if (p->fA0 != -1) func_003C5D60(p->fA0);
        self->f20 = 3;
        p->f74 = 0;
        p->f4 = 100;
        one = 1.0f;
        t = p->f74;
        func_L01_0044E850(self, p->v10, 0, one, t);
        break;
    case 2:
        if (p->f0 != -1 && func_L01_00456500(D_001A4C60, p->f0) != 0) {
            self->f20 = 4;
            p->f74 = 0;
            p->f4 = 100;
            one = 1.0f;
            t = p->f74;
            func_L01_0044E850(self, p->v10, 0, one, t);
        }
        if (p->f98 != 0xFF && D_L02_0021B460[p->f98] != 0) {
            if (func_L01_00445AD0(p->f98, -1, 0) == 0) {
                self->f20 = 4;
                p->f74 = 0;
                p->f4 = 100;
                one = 1.0f;
                t = p->f74;
                func_L01_0044E850(self, p->v10, 0, one, t);
            } else {
                if (D_001BBC40[D_001D545C_sda][self->fB0] & 0x80) {
                    self->f20 = 4;
                    p->f74 = 0;
                    p->f4 = 100;
                    one = 1.0f;
                    t = p->f74;
                    func_L01_0044E850(self, p->v10, 0, one, t);
                }
                break;
            }
        }
        if (D_001BBC40[D_001D545C][self->fB0] & 0x80) {
            self->f20 = 4;
            p->f74 = 0;
            p->f4 = 100;
            one = 1.0f;
            t = p->f74;
            func_L01_0044E850(self, p->v10, 0, one, t);
        }
        break;
    case 3:
        if (func_0038CB00(&p->f4)) {
            self->f20 = 6;
            break;
        }
        a = (float)p->f4 * p->f8;
        if (p->f90 != 0) {
            p->f74 = func_003C3BE8(6.2831855f, 0.0f, a);
            func_L01_0044E850(self, p->v10, 0, 1.0f, 0.0f);
            self->fF4 = func_003C3BE8(-1.5707964f, 0.0f, a);
            self->f18 = func_003C3BE8(p->fC + 10.0f, p->fC, a);
        } else {
            self->fF4 = func_003C3BE8(1.5707964f, 0.0f, a);
        }
        goto tail;
    case 4:
        if (func_0038CB00(&p->f4)) {
            self->f20 = 5;
            break;
        }
        a = (float)p->f4 * p->f8;
        if (p->f90 != 0) {
            p->f74 = func_003C3BE8(0.0f, 6.2831855f, a);
            func_L01_0044E850(self, p->v10, 0, 1.0f, 0.0f);
            self->fF4 = func_003C3BE8(0.0f, -1.5707964f, a);
            self->f18 = func_003C3BE8(p->fC, p->fC + 10.0f, a);
        } else {
            self->fF4 = func_003C3BE8(0.0f, 1.5707964f, a);
        }
    tail:
        if (func_L01_004AA710(self, p->f94) == 0) {
            p->f94 = func_003A52A0(0, 4, self);
        }
        break;
    case 5:
    case 6:
        p->f74 = 0;
        one = 1.0f;
        t = p->f74;
        func_L01_0044E850(self, p->v10, 0, one, t);
        i = p->f94;
        if (i != -1) {
            e = (E_39D200 *)&D_001A30B0[i << 7];
            if (e->fDC == self && e->fD0 != 0) func_003A4F28(i);
        }
        p->f94 = -1;
        if (self->f20 == 6) {
            if (func_00382380(D_001A4C60, p->f9C, 0) != 0) {
                self->f20 = 4;
                p->f74 = 0;
                p->f4 = 100;
                one = 1.0f;
                t = p->f74;
                func_L01_0044E850(self, p->v10, 0, one, t);
            }
        }
        break;
    }
}
/* localdecomp:end func_L02_0039D200 */

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

/* localdecomp:start func_L02_0039D7D0 */
typedef struct {
    s32 f0;
    s32 f4;
    f32 f8;
    u8 fC;
    u8 padD;
    u8 fE;
    u8 fF;
    vu0_v4 v10;
    s32 f20;
    s32 f24;
} P_39D7D0;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0x47];
    P_39D7D0 *p;
    u8 pad6C[0x3E];
    s16 fAA;
    u8 padAC[0xC];
    void *fB8;
    u8 padBC[4];
    vu0_v4 vC0;
    vu0_v4 vD0;
    vu0_v4 vE0;
    vu0_v4 rot;
} O_39D7D0;
typedef struct { vu0_v4 v; s32 owner; s32 mode; u8 f18; u8 f19; s16 f1A; f32 f1C; s32 f20; } S_39D7D0;
typedef struct { u8 pad[0x9C]; s32 f9C; } C_39D7D0;
typedef struct {
    u8 pad0[0x90];
    vu0_v4 rot;
    u8 padA0[0x16E];
    s16 f20E;
    u8 pad210[0x14C];
    O_39D7D0 *f35C;
    s32 f360;
    u8 pad364[0x1F6C];
    f32 f22D0;
    f32 f22D4;
    f32 f22D8;
    u8 pad22DC[0x2E4];
    C_39D7D0 *f25C0;
    u8 pad25C4[0x2C4];
    s16 f2888;
} G_39D7D0;
typedef struct { u8 pad[0xD0]; u8 fD0; u8 padD1[0xB]; void *fDC; u8 padE0[0x20]; } E_39D7D0;

extern G_39D7D0 D_001A4BE0;
extern u8 D_001A30B0[];
extern f32 D_L02_001DDBF8;
__asm__(".extern D_L02_001DDBF8, 4");
extern O_39D7D0 *D_L02_001EC0C0[];
extern u8 D_L02_001E1300[];
extern f32 D_L02_002EF1F0[];
typedef struct { u8 *p[24]; } T_39D7D0;
extern T_39D7D0 D_L02_0021E0D8;

extern void func_L02_0039E208();
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_L01_00446760(void *, void *, s32, f32, void *);
extern void func_L01_00446978(void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L02_004D36C0(s32, s32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_003D4D00(void *, f32, s32, void *, s32);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_004F4E70(s32, s32);
extern s32 func_L01_003F1F20(s32, s32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_L01_0044AE78(f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_003C4C18(void *, f32);
extern void func_L01_00470668(void *, void *, s32, f32);
extern s32 func_L01_004AA710(void *, s32);
extern void func_003A4F28(s32);

void func_L02_0039D7D0(O_39D7D0 *self) {
    P_39D7D0 *p;
    s32 i;
    s32 j;
    s32 id;
    s32 n;
    s32 found;
    E_39D7D0 *e;

    func_L02_0039E208(self);
    p = self->p;

    if (D_001A4BE0.f35C == self && D_001A4BE0.f360 >= 2) {
        S_39D7D0 s;
        {
        func_L01_00446748(&s, self, 0x10001, func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f);
        s.f18 = 0;
        s.f19 = 1;
        s.f1A = self->fAA;
        func_L01_00446978(D_001A4BE0.f25C0, &s);
        }
    }
    switch (self->state) {
    case 2:
        if (func_0038CAD0(&p->f4)) {
            self->state = 3;
            p->f4 = 30;
        }
        break;
    case 3:
        if (func_0038CAD0(&p->f4)) {
            self->state = 4;
            p->fC = 0;
            p->f4 = 20;
            p->f8 = 0.05f;
            p->f20 = func_003A52A0(0, 4, self);
        }
        break;
    case 4:
        if (func_0038CAD0(&p->f4)) {
            self->state = 5;
            p->f4 = 90;
            p->f8 = 0.011111111f;
        } else {
            vu0_v4 w;
            vu0_v4 v;
            {
            *(vu0_q *)&v = 0;
            v.x = func_003C4088(4.6f, 0.0f, (f32)p->f4 * p->f8);
            w = v;
            func_0038D000(&w, &w, &self->vC0);
            vec_add_ab(&self->pos, &p->v10, &w);
            }
            if (p->f24 != 0 && p->fC != 0) {
                func_L02_004D36C0(0x31, 1);
                D_001A4BE0.f25C0->f9C = -1;
                if (func_0038CE68(&self->rot, &D_001A4BE0.rot) > 0.0f) {
                    D_001A4BE0.rot.z = func_0038DAB8(self->rot.z, 1.5707964f);
                } else {
                    D_001A4BE0.rot.z = func_0038DAB8(self->rot.z, -1.5707964f);
                }
                D_001A4BE0.f2888 = 1;
                D_001A4BE0.f22D0 = D_001A4BE0.f22D8 = 1.3f;
                D_001A4BE0.f22D4 = 0.2f;
            }
        }
        if (p->f24 != 0) {
            vu0_v4 v;
            vu0_v4 u;
            vu0_v4 d;
            S_39D7D0 s;
            {
            *(vu0_q *)&v = 0;
            v.x = 7.5f;
            v.z = 1.5f;
            func_0038D000(&v, &v, &self->vC0);
            found = 0;
            vec_add_ab(&u, &p->v10, &v);
            if (p->fC == 0 && p->f4 < 2 && p->f0 != -1) {
                n = func_003D4D00(&u, D_L02_001DDBF8, 0, self->fB8, 0);
                if (n != 0) {
                    *(vu0_q *)&d = 0;
                    d.x = -1.0f;
                    d.y = 1.0f;
                    d.w = 5627.9248f;
                    for (j = 0; j < n; j++) {
                        if (D_L02_001EC0C0[j]->fAA == 0x18BD) continue;
                        if (func_L01_00456500(&D_L02_001EC0C0[j]->pos, p->f0) == 0) continue;
                        if (D_L02_001EC0C0[j]->fAA == 0) p->fC = 1;
                        func_L01_00446760(&s, self, 0x10001, func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f, &d);
                        s.f18 = 0;
                        s.f19 = 1;
                        s.f1A = self->fAA;
                        func_L01_00446978(D_L02_001EC0C0[j], &s);
                        found = 1;
                    }
                }
            }
            if (found) {
                func_003A52A0(3, 0, self);
                if (p->fC != 0) {
                    func_L01_004F4E70(0x14, 0);
                    func_L01_003F1F20(0x12, 0);
                    D_001A4BE0.f20E = 0x25;
                }
            }
            }
        }
        if (self->state == 5) {
            vu0_v4 v;
            vu0_v4 u;
            vu0_v4 w;
            vu0_v4 q;
            f32 f;
            u8 *rr;
            s32 cnt;
            s32 r;
            {
            *(vu0_q *)&v = 0;
            v.x = 3.2f;
            v.z = 1.5f;
            cnt = 75;
            func_0038D000(&v, &v, &self->vC0);
            vec_add_ba(&v, &self->pos, &v);
            if (func_0038CF38(&self->pos, D_L02_001E1300) > 20.0f) cnt = 25;
            for (i = 0; i < cnt; i++) {
                f = func_003824E0(0.25f, 1.5f) * 210000.0f;
                func_003C4840(&q, &self->vC0, func_L01_0044AE78((f32)i * 0.41887903f + func_L01_00443A18(0.0f, 0.06981317f)));
                func_0038D850(&w, &self->vE0, &q);
                vec_add_ab(&u, &v, &w);
                func_0038CE20(&w, &w, func_003824E0(3.0f, 5.0f) * 0.020000001f);
                r = func_00382468(3) - 1;
                rr = func_L01_0046FB40(&u, &w, (func_00382498(40, 70) * 5 + 2) / 6, 0x7F7F7F, r, 0x40, 0, f, f, 0.0f, 0);
                if (rr != 0) {
                    rr[2] = D_L02_0021E0D8.p[23][0];
                    rr[3] = 0x44;
                }
                if (func_00382468(3) == 0) {
                    func_0038CE20(&w, &w, 4.0f);
                    func_003C4C18(&w, 0.040000003f);
                    func_L01_00470668(&u, &w, (func_00382498(10, 20) * 5 + 2) / 6, 0.0f);
                }
            }
            if (func_L01_004AA710(self, p->f20) != 0) {
                id = p->f20;
                if (id != -1) {
                    e = (E_39D7D0 *)&D_001A30B0[id << 7];
                    if (e->fDC == self && e->fD0 != 0) func_003A4F28(id);
                }
                p->f20 = -1;
            }
            func_003A52A0(1, 0, self);
            }
        }
        break;
    case 5:
        if (func_0038CAD0(&p->f4)) {
            if (p->fF != 0) {
                self->state = 3;
                p->f4 = 30;
            } else {
                self->state = 1;
            }
            if (func_L01_004AA710(self, p->f20) != 0) {
                id = p->f20;
                if (id != -1) {
                    e = (E_39D7D0 *)&D_001A30B0[id << 7];
                    if (e->fDC == self && e->fD0 != 0) func_003A4F28(id);
                }
                p->f20 = -1;
            }
        } else {
            vu0_v4 w;
            vu0_v4 v;
            if (func_L01_004AA710(self, p->f20) == 0) {
                p->f20 = func_003A52A0(2, 4, self);
            }
            *(vu0_q *)&v = 0;
            v.x = func_003C3BE8(0.0f, 4.6f, (f32)p->f4 * p->f8);
            w = v;
            func_0038D000(&w, &w, &self->vC0);
            vec_add_ab(&self->pos, &p->v10, &w);
        }
        if (p->f24 != 0 && p->fC != 0) {
            if (p->f4 < 50) {
                if (p->f4 >= 34) {
                    f32 t;
                    func_L02_004D36C0(0x74, 1);
                    D_001A4BE0.f25C0->f9C = -1;
                    t = 1.0f / (f32)(p->f4 - 33);
                    D_001A4BE0.f2888 = 1;
                    D_001A4BE0.f22D0 = D_001A4BE0.f22D8 = 1.3f - t * 0.3f;
                    D_001A4BE0.f22D4 = t * 0.8f + 0.2f;
                } else {
                    func_L02_004D36C0(0, 1);
                    D_001A4BE0.f25C0->f9C = 0;
                    D_001A4BE0.f2888 = 0;
                    p->fC = 0;
                }
            } else {
                func_L02_004D36C0(0x31, 1);
                D_001A4BE0.f25C0->f9C = -1;
                if (func_0038CE68(&self->rot, &D_001A4BE0.rot) > 0.0f) {
                    D_001A4BE0.rot.z = func_0038DAB8(self->rot.z, 1.5707964f);
                } else {
                    D_001A4BE0.rot.z = func_0038DAB8(self->rot.z, -1.5707964f);
                }
                D_001A4BE0.f2888 = 1;
                D_001A4BE0.f22D0 = D_001A4BE0.f22D8 = 1.3f;
                D_001A4BE0.f22D4 = 0.2f;
            }
        }
        break;
    case 1:
        if (p->fF != 0) {
            if (p->fE == 0) {
                p->f4 = 0;
            } else if (p->fE == 1) {
                p->f4 = 30;
            } else {
                p->f4 = 60;
            }
            self->state = 2;
            p->fF = 0;
        }
        break;
    }
}
/* localdecomp:end func_L02_0039D7D0 */

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

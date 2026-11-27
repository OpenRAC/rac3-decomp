#include "common.h"

typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad21[16];
    u8 unk31;
    u8 pad32[2];
    u16 unk34;
} M3C7568;
typedef struct Moby Moby;
typedef struct {
    char pad0[0x550];
    Moby *child;
} Vars;
struct Moby {
    char pad0[0x42];
    unsigned char anim;
    char pad43[0x48 - 0x43];
    float animSpeed;
    char pad4C[0x68 - 0x4C];
    Vars *vars;
};
typedef int u128_3C9E88 __attribute__((mode(TI)));
typedef struct { u8 pad[0x10]; u128_3C9E88 pos; u8 pad20[0xE0]; } M_3C9E88;
typedef struct { u8 pad[0x30]; u128_3C9E88 x30; u8 pad40[0x40]; } E_3C9E88;
typedef struct { u8 pad[0x60]; s32 x60; s32 x64; } T_3C9E88;
typedef struct { u8 pad[0x47C]; s32 x47C; u8 pad480[0x10]; u8 x490; u8 x491; u8 pad492[0x4A0 - 0x492]; u128_3C9E88 x4A0; } V_3C9E88;
typedef struct O_3C9E88 O_3C9E88;
struct O_3C9E88 { u8 pad[0x20]; u8 x20; u8 pad21[0x68 - 0x21]; void *x68; u8 pad6C[0xB8 - 0x6C]; O_3C9E88 *xB8; u8 xBC; };
typedef struct M_3CC220 M_3CC220;
typedef struct {
    u8 pad0[0xB0];
    u8 bB0[0xC4 - 0xB0];
    M_3CC220 *tgt;
    u8 padC8[0xD4 - 0xC8];
    f32 fD4;
} V_3CC220;
struct M_3CC220 {
    u8 pad0[0x10];
    u8 pos[0x10];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3CC220 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
};
typedef struct {
    u8 pad0[0x18];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[0x30 - 0x1C];
} L_3CC220;
typedef struct {
    u8 pad0[0x18];
    M_3CC220 *m18;
} G_3CC220;
typedef struct {
    u8 pad0[44];
    s32 w2C;
    u8 pad1[64 - 48];
    s32 w40;
} Obj3CEDD0;
typedef struct {
    u8 pad0[32];
    u8 b20;
    u8 pad1[170 - 33];
    s16 hAA;
} Moby3CEDD0;
typedef struct {
    void (*f0)(Moby3CEDD0 *);
    s32 pad;
    s32 (*f8)(Moby3CEDD0 *);
} Vt3CEDD0;
typedef int s128 __attribute__((mode(TI)));
typedef struct S_3CF0C0o {
    u8 pad0[0x10];
    s128 x10;
    u8 x20;
    u8 pad21[0xAA - 0x21];
    s16 xAA;
    u8 padac[0xF8 - 0xAC];
    f32 xF8;
    u8 padfc[4];
} S_3CF0C0o;
typedef struct S_3CF0C0f {
    u8 pad0[8];
    s32 (*x8)(S_3CF0C0o *);
    u8 padc[8];
    void (*x14)(S_3CF0C0o *, s32, s128 *, f32 *);
} S_3CF0C0f;
typedef struct S_3CF0C0p {
    u8 pad0[0x28];
    s32 x28;
    s32 x2C;
    u8 pad30[0x10];
    s32 x40;
    u8 pad44[0xE8 - 0x44];
    s32 xE8;
    s32 xEC;
} S_3CF0C0p;

typedef struct {
    u8 pad0[0xF8];
    f32 xF8;
} Self_003D0850;
typedef struct {
    u8 pad0[0x2C];
    s32 w2C;
    u8 pad30[0x40 - 0x30];
    s32 w40;
    u8 pad44[0xBC - 0x44];
    s32 xBC[4];
    u8 padCC[0x130 - 0xCC];
    f32 x130;
} Obj_003D0850;
typedef struct {
    u8 pad0[32];
    u8 b20;
    u8 pad1[170 - 33];
    s16 hAA;
} Moby_003D0850;
typedef struct {
    void (*f0)(Moby_003D0850 *);
    void (*f4)(Moby_003D0850 *, f32, f32, f32);
    s32 (*f8)(Moby_003D0850 *);
} Vt_003D0850;

typedef struct {
    u8 pad0[0x68];
    u8 *vars;
} O_003CB9B0;
typedef struct {
    u8 pad0[0x491];
    u8 x491;
    u8 pad492[0x550 - 0x492];
    u8 *child;
} V_003CB9B0;


/* localdecomp:start func_L01_003CFB08 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;              /* 0x10 */
    u8 state;                /* 0x20 */
    u8 pad21[0x30 - 0x21];
    u8 b30;                  /* 0x30 */
    u8 pad31[0xC0 - 0x31];
    vu0_v4 mtx[3];           /* 0xC0 */
    u8 padF0[0xF8 - 0xF0];
    f32 fF8;                 /* 0xF8 */
} Self_003CFB08;

typedef struct {
    s32 i0;                  /* 0x00 */
    u8 pad4[0x24 - 0x4];
    s32 i24;                 /* 0x24 */
    s32 i28;                 /* 0x28 */
    s32 i2C;                 /* 0x2C */
    u8 pad30[0x38 - 0x30];
    s32 i38;                 /* 0x38 */
    u8 pad3C[0x40 - 0x3C];
    s32 i40;                 /* 0x40 */
    s32 i44;                 /* 0x44 */
    u8 pad48[0x4C - 0x48];
    s32 sound;               /* 0x4C */
    u8 pad50[0x54 - 0x50];
    f32 f54;                 /* 0x54 */
    u8 pad58[0x60 - 0x58];
    s32 i60;                 /* 0x60 */
    s32 i64;                 /* 0x64 */
    s32 i68;                 /* 0x68 */
    s32 i6C;                 /* 0x6C */
    u8 pad70[0xB0 - 0x70];
    u8 bB0;                  /* 0xB0 */
    u8 bB1;                  /* 0xB1 */
    u8 padB2[0xB4 - 0xB2];
    s32 iB4;                 /* 0xB4 */
    s32 iB8;                 /* 0xB8 */
    u8 padBC[0x130 - 0xBC];
    f32 f130;                /* 0x130 */
    f32 f134;                /* 0x134 */
    u8 pad138[0x140 - 0x138];
    vu0_v4 v140;             /* 0x140 */
    vu0_v4 v150;             /* 0x150 */
} Obj_003CFB08;

typedef struct { u8 pad[0xAA]; u16 oClass; } Moby_003CFB08;

typedef struct {
    u8 pad_0[0x80];
    vu0_v4 pos;                /* 0x80 */
    u8 pad_90[0x33C - 0x90];
    f32 f33C;                  /* 0x33C */
    u8 pad_340[0x35C - 0x340];
    Moby_003CFB08 *m35C;       /* 0x35C */
    s32 i360;                  /* 0x360 */
    u8 pad_364[0x36E - 0x364];
    s16 h36E;                  /* 0x36E */
    u8 pad_370[0x25C4 - 0x370];
    s32 state;                 /* 0x25C4 */
    u8 pad_25C8[0x2850 - 0x25C8];
    s32 i2850;                 /* 0x2850 */
} Hero_003CFB08;

typedef struct { u8 pad[0x30]; vu0_v4 pos; u8 pad40[0x30]; vu0_v4 v70; } Ent_003CFB08;
typedef struct { u8 pad[0x10]; vu0_v4 pos; u8 pad20[0x14]; u16 flags; u8 pad36[0x100 - 0x36]; } Spot_003CFB08;
typedef struct { u8 pad[0xD0]; u8 playing; u8 padD1[0xDC - 0xD1]; void *owner; } Chan_003CFB08;

extern Hero_003CFB08 D_001A4BE0_003CFB08;
extern u8 D_001A30B0_003CFB08[];
extern Ent_003CFB08 *D_L01_001E0100_003CFB08;
extern Spot_003CFB08 *D_L01_001E001C_003CFB08;
extern s32 D_L01_001DFB40;
extern f32 D_L01_001DF2A8, D_L01_001DF2BC, D_L01_001DF2C0, D_L01_001DF2C4;
__asm__(".extern D_L01_001DF2A8, 4");
__asm__(".extern D_L01_001DF2BC, 4");
__asm__(".extern D_L01_001DF2C0, 4");
__asm__(".extern D_L01_001DF2C4, 4");

#define HERO D_001A4BE0_003CFB08
#define CHAN(h) ((Chan_003CFB08 *)(D_001A30B0_003CFB08 + (h) * 0x80))

/* Update of a Veldin-style interactive object: a 12-state machine (0 init, 1 wait for its trigger,
 * 2 arm and check the hero's zone, 3-9 activation and cool-down phases, 10 a looping sound while the
 * hero rides it, 11 wait for the linked spot, 12 shut down). Each state ends by setting the next one
 * (func_L01_004450F0). */
void func_L01_003CFB08(Self_003CFB08 *self) {
    extern s32 func_L01_003D0530();
    extern s32 func_L01_003D06E0();
    extern void func_L01_003D0850();
    extern void func_L01_003D09D0();
    extern void func_L01_003D0B70();
    extern void func_L01_003D0BD0();
    extern void func_L01_003D0D48();
    extern void func_L01_003D1210();
    extern void func_L01_003D1848();
    extern void func_L01_003D18C0();
    extern void func_L01_003D1A50();
    extern void func_L01_003D1C60();
    extern void func_L01_003D2158();
    extern void func_L01_003D2278();
    extern void func_L01_003D22A8();
    extern void func_L01_003D3090();
    extern s32 func_0038CAD0(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_003C2880(void *);
    extern s32 func_00382380(void *, s32, s32);
    extern void func_003A4F28(s32);
    extern void func_L01_0043B510(s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
    extern s32 func_L01_004561B8(void *);
    extern s32 func_L01_004AAC98(s32, s32, void *, s32);
    extern void func_L01_004F50C8(void *, void *, s32, s32);
    extern s32 func_L01_005003D0(s32, s32);
    extern void func_L01_00511A40(void *, s32, f32);
    Obj_003CFB08 *obj = (Obj_003CFB08 *)*(void **)((u8 *)self + 0x68);
    vu0_v4 v;
    vu0_v4 *m;
    Ent_003CFB08 *ent;
    s32 t;
    s32 state;
    s32 h1, h2, h3;
    s32 idx;
    f32 d;

    if (self->state == 0) {
        func_L01_003D0530(self, obj);
        return;
    }
    switch (self->state) {
    case 1:
        if ((obj->i2C == -1 && obj->i40 == -1) || func_L01_003D06E0(self, obj)) {
            func_L01_004450F0(self, 2, -1);
        }
        break;
    case 2:
        t = HERO.state;
        if (t == 0x74 || t == 0x31 || t == 0x65) {
            break;
        }
        if (obj->iB4 == D_L01_001DFB40 - 1) {
        if (obj->i6C != -1 && func_00382380(&HERO.pos, obj->i6C, 0)) {
            ent = &D_L01_001E0100_003CFB08[obj->i68];
            if (obj->i60) {
                func_L01_003D2158(self, obj);
                func_L01_004F50C8(&ent->pos, &ent->v70, 0x74, 1);
                func_L01_003D1848(self, obj);
                func_L01_003D09D0(self, obj);
                func_L01_003D1C60(self, obj);
                func_L01_003D0B70(self, obj);
                func_L01_003D0BD0(self, obj);
                func_L01_004450F0(self, 6, -1);
                break;
            }
            if (obj->i64 != -1) {
                func_L01_003D2158(self, obj);
            }
            func_L01_004F50C8(&ent->pos, &ent->v70, 0xB0, 1);
            func_L01_003D1848(self, obj);
            func_L01_003D09D0(self, obj);
            func_L01_003D0B70(self, obj);
            self->b30 = 0xFF;
            obj->i38 = 0;
            obj->v150 = obj->v140;
            obj->f134 = obj->f54;
            obj->i44 = 0;
            func_L01_004450F0(self, 9, -1);
            break;
        }
        if (func_00382380(&HERO.pos, obj->i0, 0)) {
            func_L01_003D1848(self, obj);
            func_L01_003D09D0(self, obj);
            func_L01_003D1A50(self, obj);
            func_L01_003D0B70(self, obj);
            func_L01_004450F0(self, 3, -1);
        }
        } else {
            if ((obj->i6C != -1 && func_00382380(&HERO.pos, obj->i6C, 0)) || func_00382380(&HERO.pos, obj->i0, 0)) {
                func_L01_003D22A8(self);
            }
            obj->iB4 = D_L01_001DFB40;
            obj->bB1 = 0;
        }
        break;
    case 3:
        t = func_L01_004561B8(self);
        m = self->mtx;
        if (t) {
            if (obj->i28 != -1) {
                obj->f130 = func_0038CE68(&D_L01_001E001C_003CFB08[obj->i28].pos, m);
            } else {
                obj->f130 = func_0038CE68(&self->pos, m);
            }
        }
        func_L01_003D1848(self, obj);
        func_L01_003D0BD0(self, obj);
        func_L01_003D09D0(self, obj);
        func_L01_003D18C0(self, obj);
        d = func_0038CE68(&HERO.pos, m) - obj->f130;
        if (D_L01_001DF2BC < d) {
            func_0038CE20(&v, m, 20.0f);
            vec_add_ab(&v, &v, &D_L01_001E0100_003CFB08[obj->i0].pos);
            func_L01_00511A40(&v, 0, self->fF8);
            func_L01_003D0850(self, obj);
            func_L01_004450F0(self, 4, -1);
        }
        break;
    case 4:
        func_L01_003D1848(self, obj);
        func_L01_003D0BD0(self, obj);
        func_L01_003D18C0(self, obj);
        d = func_0038CE68(&HERO.pos, self->mtx) - obj->f130;
        if (D_L01_001DF2C0 < d || (obj->i60 && D_L01_001DF2C4 < d)) {
            func_L01_005003D0(0x69, 1);
            func_L01_004450F0(self, 5, -1);
        }
        break;
    case 5:
        func_L01_003D1848(self, obj);
        func_L01_003D0BD0(self, obj);
        func_L01_003D18C0(self, obj);
        if (HERO.pos.z < D_L01_001E0100_003CFB08[obj->i0].pos.z && 3.0f < HERO.f33C) {
            func_L01_005003D0(0xB0, 1);
            self->b30 = 0xFF;
            func_L01_004450F0(self, 10, -1);
            obj->v150 = obj->v140;
            obj->f134 = obj->f54;
            obj->i38 = 0;
            obj->i44 = 0;
        }
        break;
    case 6:
        if (func_L01_004561B8(self)) {
            if (obj->i28 != -1) {
                obj->f130 = func_0038CE68(&D_L01_001E001C_003CFB08[obj->i28].pos, self->mtx);
            } else {
                obj->f130 = func_0038CE68(&self->pos, self->mtx);
            }
            obj->iB4 = 0x43;
        }
        func_L01_003D1848(self, obj);
        func_L01_003D0BD0(self, obj);
        func_L01_003D09D0(self, obj);
        func_L01_003D18C0(self, obj);
        if (func_0038CAD0(&obj->iB4)) {
            func_0038CE20(&v, self->mtx, 20.0f);
            vec_add_ab(&v, &v, &D_L01_001E0100_003CFB08[obj->i0].pos);
            func_L01_00511A40(&v, 0, self->fF8);
            func_L01_004450F0(self, 7, -1);
        }
        break;
    case 7:
        func_L01_003D1848(self, obj);
        func_L01_003D0BD0(self, obj);
        func_L01_003D09D0(self, obj);
        func_L01_003D18C0(self, obj);
        d = func_0038CE68(&HERO.pos, self->mtx) - obj->f130;
        if (D_L01_001DF2C0 < d || (obj->i60 && D_L01_001DF2C4 < d)) {
            func_L01_005003D0(0x69, 1);
            func_L01_004450F0(self, 8, -1);
        }
        break;
    case 8:
        func_L01_003D1848(self, obj);
        func_L01_003D0BD0(self, obj);
        func_L01_003D09D0(self, obj);
        func_L01_003D18C0(self, obj);
        if (HERO.pos.z < D_L01_001E0100_003CFB08[obj->i0].pos.z && 3.0f < HERO.f33C) {
            func_L01_003D2278(self, obj);
            func_L01_005003D0(0xB0, 1);
            self->b30 = 0xFF;
            func_L01_004450F0(self, 9, -1);
            obj->v150 = obj->v140;
            obj->f134 = obj->f54;
            obj->i38 = 0;
            obj->i44 = 0;
        }
        break;
    case 9:
        func_L01_003D1848(self, obj);
        if (func_L01_004561B8(self)) {
            obj->iB4 = obj->iB8;
            func_L01_003D1A50(self, obj);
        }
        func_L01_003D09D0(self, obj);
        func_L01_003D18C0(self, obj);
        func_L01_003D1210(self, obj);
        func_L01_003D0D48(self, obj, 1);
        if (func_0038CAD0(&obj->iB4)) {
            func_L01_003D0850(self, obj);
            func_L01_004450F0(self, 10, -1);
        }
        break;
    case 10:
        func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
        func_L01_003D1848(self, obj);
        state = HERO.state;
        if (state != 0xB0 && state != 0x16 && state != 0x39) {
            if (obj->i24 != -1 && HERO.i2850 > 0) {
                func_L01_0043B510(obj->i24);
            }
            func_L01_003D0D48(self, obj, 0);
            h1 = obj->sound;
            if (h1 != -1 && CHAN(h1)->owner == self && CHAN(h1)->playing) {
                func_003A4F28(h1);
            }
            obj->sound = -1;
            func_L01_004450F0(self, 12, -1);
            break;
        }
        func_L01_003D1210(self, obj);
        if (D_L01_001DF2A8 < HERO.f33C ||
            (HERO.m35C != 0 && (u32)(HERO.m35C->oClass - 0x191F) < 2)) {
            func_L01_003D0D48(self, obj, 1);
            h2 = obj->sound;
            if (h2 == -1 || CHAN(h2)->owner != self || !CHAN(h2)->playing) {
                obj->sound = func_L01_004AAC98(2, 4, self, 0x1D84);
            }
        } else {
            func_L01_003D0D48(self, obj, 0);
            h3 = obj->sound;
            if (h3 != -1 && CHAN(h3)->owner == self && CHAN(h3)->playing) {
                func_003A4F28(h3);
            }
            obj->sound = -1;
        }
        func_L01_003D3090(self, obj);
        func_L01_003D18C0(self, obj);
        break;
    case 11:
        idx = obj->i40;
        if (idx != -1) {
            if (((Spot_003CFB08 *)((u8 *)D_L01_001E001C_003CFB08 + (idx << 8)))->flags & 2) {
                func_L01_004450F0(self, 1, -1);
            }
        } else {
            func_L01_004450F0(self, 1, -1);
        }
        break;
    case 12:
        if (HERO.i360 != 0 && HERO.h36E == 0) {
            if (obj->bB0 != 0 || obj->i40 != -1) {
                func_L01_004450F0(self, 11, -1);
            } else {
                func_003C2880(self);
            }
        } else {
            func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
        }
        break;
    }
}
/* localdecomp:end func_L01_003CFB08 */

/* localdecomp:start func_L01_003D0530 */
typedef struct {
    u8 pad0[0x50];
    s32 (*f50)(u8 *);
} Vt_003D0530;
typedef struct Node_003D0530 Node_003D0530;
struct Node_003D0530 {
    u8 pad0[0x28];
    Node_003D0530 *next;
    u8 pad2C[4];
};
typedef struct {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[0x40 - 0x28];
    s32 w40;
    u8 pad44[0x48 - 0x44];
    s32 w48;
    s32 w4C;
    s32 w50;
    u8 pad54[0x6C - 0x54];
    s32 w6C;
    u8 pad70[0xB0 - 0x70];
    u8 bB0;
    u8 bB1;
    u8 padB2[2];
    s32 wB4;
    u8 padB8[0xE4 - 0xB8];
    s32 wE4;
    u8 padE8[0x138 - 0xE8];
    Node_003D0530 *w138;
    u8 pad13C[0x180 - 0x13C];
    Node_003D0530 nodes[160];
} V_003D0530;

extern Vt_003D0530 *func_L01_0043B548(s32, s32);
extern void func_003C2880(void *);
extern void func_0038CB78(void *, s32, s32);
extern void func_0038D308(void *, void *);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_0014275B[];
extern f32 D_L01_001DAA38;
extern f32 D_L01_002F16F0[];

s32 func_L01_003D0530(u8 *a0, V_003D0530 *v) {
    Vt_003D0530 *t;
    Node_003D0530 *p;
    s32 level;

    t = func_L01_0043B548(0x19E1, 0x6C);
    if (t != 0 && t->f50(a0 + 0x10) != 0) {
        v->bB0 = 1;
    } else {
        v->bB0 = 0;
    }
    v->bB1 = 0;
    if (v->w24 != -1 && (D_001BBC40[D_001D545C][v->w24] & 0x80) && v->bB0 == 0 && v->w40 == -1) {
        func_003C2880(a0);
        return 0;
    }
    if (v->w6C == -1) {
        a0[0x30] = 0x40;
    } else {
        a0[0x30] = 0xFF;
    }
    do {
        Node_003D0530 *n;
        s32 i;

        p = v->nodes;
        func_0038CB78(p, 0, 0x1E00);
        n = p;
        for (i = 0; i < 159; i++) {
            n->next = n + 1;
            n++;
        }
    } while (0);
    v->w138 = p;
    if (v->wE4 < 0) {
        v->wE4 = 0;
    }
    func_0038D308(a0 + 0xC0, a0 + 0xF0);
    v->w50 = 0;
    v->wB4 = 0;
    v->w4C = -1;
    if (func_L01_0041A4F0()) {
        level = D_001D545C;
        v->w48 = (s32)((f32)v->w48 * (level == 7 && D_0014275B[0] ? D_L01_001DAA38 : D_L01_002F16F0[level]));
    }
    func_L01_004450F0(a0, 1, -1);
    return 1;
}
/* localdecomp:end func_L01_003D0530 */

/* localdecomp:start func_L01_003D06E0 */
extern M_3C9E88 *D_L01_001E001C;



extern s32 D_L01_001E0058;
extern u16 *D_L01_0021DE20[];
extern Vt3CEDD0 *func_L01_0043B568(s32, s32, s32);
s32 func_L01_003D06E0(s32 a0, Obj3CEDD0 *obj) {
    u8 *m;
    u8 *p;
    u16 *list;
    Moby3CEDD0 *e;
    Vt3CEDD0 *h;

    if (obj->w40 != -1) {
        m = (*(u8 * *)&D_L01_001E001C) + (obj->w40 << 8);
        if (*(u16 *)(m + 52) & 2) {
            return 0;
        }
        p = *(u8 **)(*(u8 **)(m + 104) + 284);
        if (p == 0) {
            return 0;
        }
        obj->w2C = p[33];
    }
    for (list = D_L01_0021DE20[obj->w2C];
         (obj->w2C & 0xFF) != 255 && obj->w2C <= D_L01_001E0058 && list != 0
         && (((s16 *)list)[-1] >= 0 || list == D_L01_0021DE20[obj->w2C]);
         list++) {
        e = (Moby3CEDD0 *)((*(u8 * *)&D_L01_001E001C) + ((*list & 0x7FFF) << 8));
        if (e == 0) {
            break;
        }
        if (e->b20 == 254) {
            continue;
        }
        if (e->b20 == 253) {
            continue;
        }
        if (obj->w40 != -1) {
            h = func_L01_0043B568(e->hAA, 1, 28);
            if (h == 0) {
                continue;
            }
            if (h->f8(e) != 0) {
                continue;
            }
        }
        h = func_L01_0043B568(7032, 0, 16);
        h->f0(e);
    }
    return 1;
}
/* localdecomp:end func_L01_003D06E0 */

/* localdecomp:start func_L01_003D0850 */
__asm__(".extern D_L01_001DF2C0, 4");
__asm__(".extern D_L01_001DF2C8, 8");
extern s32 D_L01_001E0058;
extern u16 *D_L01_0021DE20[];
extern f32 D_L01_001DF2C0;
extern f32 D_L01_001DF2C8[2];

void func_L01_003D0850(Self_003D0850 *self, Obj_003D0850 *obj) {
    u16 *list;
    Moby_003D0850 *e;
    Vt_003D0850 *h;
    s32 n;

    n = 0;
    for (list = D_L01_0021DE20[obj->w2C];
         (obj->w2C & 0xFF) != 255 && obj->w2C <= D_L01_001E0058 && list != 0
         && (((s16 *)list)[-1] >= 0 || list == D_L01_0021DE20[obj->w2C]);
         list++) {
        e = (Moby_003D0850 *)((*(u8 **)&D_L01_001E001C) + ((*list & 0x7FFF) << 8));
        if (e == 0) {
            break;
        }
        obj->xBC[n] = 0;
        if (e->b20 == 254) {
            n++;
            continue;
        }
        if (e->b20 == 253) {
            n++;
            continue;
        }
        if (obj->w40 != -1) {
            h = ((Vt_003D0850 * (*)(s32, s32, s32))func_L01_0043B568)(e->hAA, 1, 28);
            if (h == 0) {
                continue;
            }
            if (h->f8(e) != 0) {
                continue;
            }
        }
        h = ((Vt_003D0850 * (*)(s32, s32, s32))func_L01_0043B568)(7032, 0, 16);
        h->f4(e, self->xF8, D_L01_001DF2C8[n], obj->x130 + D_L01_001DF2C0);
        n++;
    }
}
/* localdecomp:end func_L01_003D0850 */

/* localdecomp:start func_L01_003D09D0 */
extern Vt3CEDD0 *func_L01_0043B568(s32, s32, s32);
extern M_3C9E88 *D_L01_001E001C;


extern s32 D_L01_001E0058;
extern u16 *D_L01_0021DE20[];

void func_L01_003D09D0(s32 a0, S_3CF0C0p *p) {
    S_3CF0C0o *src;
    S_3CF0C0o *o;
    S_3CF0C0f *h;
    S_3CF0C0f *f;
    u16 *list;
    s32 n;
    s128 buf;
    f32 val;

    if (p->x2C == -1 || p->x28 == -1) {
        return;
    }
    src = &(*(S_3CF0C0o * *)&D_L01_001E001C)[p->x28];
    h = ((S_3CF0C0f * (*)(s32, s32, s32))func_L01_0043B568)(6877, 0, 104);
    n = 0;
    for (list = D_L01_0021DE20[p->x2C];
         (p->x2C & 0xFF) != 255 && p->x2C <= D_L01_001E0058 && list != 0
         && (((s16 *)list)[-1] >= 0 || list == D_L01_0021DE20[p->x2C]);
         list++) {
        o = &(*(S_3CF0C0o * *)&D_L01_001E001C)[*list & 0x7FFF];
        if (o == 0) {
            break;
        }
        if (o->x20 == 254) {
            continue;
        }
        if (o->x20 == 253) {
            continue;
        }
        if (p->x40 != -1) {
            f = ((S_3CF0C0f * (*)(s32, s32, s32))func_L01_0043B568)(o->xAA, 1, 28);
            if (f == 0) {
                continue;
            }
            if (f->x8(o) != 0) {
                continue;
            }
        }
        h->x14(src, n, &buf, &val);
        n++;
        o->x10 = buf;
        o->xF8 = val;
    }
    p->xEC = 0;
    p->xE8 = 5;
}
/* localdecomp:end func_L01_003D09D0 */

/* localdecomp:start func_L01_003D0B70 */
extern void func_L01_003D22A8(s32);
extern s32 func_L01_00513EF0(void);
extern void func_L01_003F5AC0(s32, s32);
extern u8 *D_L01_001E2A90[];

void func_L01_003D0B70(s32 a0, u8 *a1) {
    func_L01_003D22A8(a0);
    if (func_L01_00513EF0()) return;
    if (*(s16 *)(D_L01_001E2A90[0] + 134)) return;
    func_L01_003F5AC0(0, 1);
    a1[177] = 1;
}
/* localdecomp:end func_L01_003D0B70 */

/* localdecomp:start func_L01_003D0BD0 */
extern void func_L01_003D22A8_003D0BD0(s32);
extern s32 func_L01_00513EF0_003D0BD0(void);
extern u8 *D_L01_001E2A90_003D0BD0[];
extern void func_L01_003D0B70_003D0BD0(s32 a0, u8 *a1);
extern void func_L01_003E8F90_003D0BD0(s32, s32);
extern void func_L01_003E8BD0_003D0BD0(s32, s32, f32, f32);
extern void func_L01_003E8C28_003D0BD0(s32, f32, f32);
extern void func_L01_003E8C70_003D0BD0(s32, s32, f32, f32);
extern void func_L01_003E8E70_003D0BD0(s32);
extern void func_L01_003E9250_003D0BD0(s32, void *, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
__asm__(".extern D_L01_001DF270_003D0BD0, 4");
__asm__(".extern D_L01_001DF274_003D0BD0, 4");
__asm__(".extern D_L01_001DF278_003D0BD0, 4");
__asm__(".extern D_L01_001DF27C_003D0BD0, 4");
__asm__(".extern D_L01_001DF280_003D0BD0, 4");
__asm__(".extern D_L01_001DF284_003D0BD0, 4");
extern f32 D_L01_001DF270_003D0BD0;
extern f32 D_L01_001DF274_003D0BD0;
extern f32 D_L01_001DF278_003D0BD0;
extern f32 D_L01_001DF27C_003D0BD0;
extern f32 D_L01_001DF280_003D0BD0;
extern f32 D_L01_001DF284_003D0BD0;

static inline void func_L01_003D0BD0_aim(u8 *self, f32 off) {
    f32 v[3];
    f32 ang = func_0038DAB8(*(f32 *)(self + 0xF8), off);
    v[0] = func_0038D098(ang);
    v[1] = func_0038D0B0(ang);
    v[2] = 0.0f;
    func_L01_003E9250_003D0BD0(0, v, 0.2617994f, v[2]);
}

void func_L01_003D0BD0(u8 *self, u8 *a1) {

    func_L01_003D22A8_003D0BD0((s32)self);
    if (func_L01_00513EF0_003D0BD0()) return;
    if (*(s16 *)(D_L01_001E2A90_003D0BD0[0] + 134)) return;
    if (!a1[0xB1]) func_L01_003D0B70_003D0BD0((s32)self, a1);
    func_L01_003E8F90_003D0BD0(0, -1);
    func_L01_003E8BD0_003D0BD0(0, 0, D_L01_001DF270_003D0BD0, 0.003f);
    func_L01_003E8C28_003D0BD0(0, D_L01_001DF274_003D0BD0, 0.003f);
    func_L01_003E8C70_003D0BD0(0, 0, D_L01_001DF278_003D0BD0, 0.005f);
    func_L01_003E8E70_003D0BD0(0);
    if (self[0x20] == 3) {
        func_L01_003D0BD0_aim(self, D_L01_001DF27C_003D0BD0);
    } else if ((u8)(self[0x20] - 6) < 3) {
        func_L01_003E8BD0_003D0BD0(0, 0, D_L01_001DF280_003D0BD0, 0.003f);
        func_L01_003D0BD0_aim(self, D_L01_001DF284_003D0BD0);
    } else {
        func_L01_003E9250_003D0BD0(0, self + 0xC0, 0.15707964f, 0.0f);
    }
}
/* localdecomp:end func_L01_003D0BD0 */

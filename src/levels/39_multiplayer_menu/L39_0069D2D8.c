#include "common.h"

/* localdecomp:start func_L39_0069D2D8 */
typedef struct H_0069D2D8 {
    s32 type;
    char text[0x34];
    f32 x, y, w, h;
} H_0069D2D8;

typedef struct S_0069D2D8 {
    H_0069D2D8 h;
    s32 count;
    s32 *values;
    s32 x50;
    u8 pad54[0x70 - 0x54];
} S_0069D2D8;

typedef struct A_0069D2D8 {
    H_0069D2D8 h;
    s32 x48;
    s32 x4C;
} A_0069D2D8;

typedef struct B_0069D2D8 {
    H_0069D2D8 h;
    u8 b48;
    u8 pad49[3];
    s32 x4C;
} B_0069D2D8;

typedef struct N_0069D2D8 {
    H_0069D2D8 h;
    s32 x48;
    s32 x4C;
    s32 x50;
    s32 x54;
    u8 pad58[8];
} N_0069D2D8;

typedef struct D_0069D2D8 {
    H_0069D2D8 h;
    s32 x48;
    s32 x4C;
    void *items[0x60];
} D_0069D2D8;

typedef struct P_0069D2D8 {
    f32 x;
    f32 y;
    s32 v;
} P_0069D2D8;

extern u8 D_L39_0047D210[];
extern u8 D_L39_00248338[];
extern u8 D_L39_00248340[];
extern P_0069D2D8 D_L39_004B03A0[];
void func_L39_00688388(void *);
void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
s32 func_00381FF0(s32);
void func_L39_00689670(void *, void *);

static __inline__ void lab_0069D2D8(H_0069D2D8 *t, s32 text, f32 x, f32 y, f32 w, f32 h) {
    t->type = 0;
    func_L39_0068CD28((u8 *)t, text, x, y, w, h);
}

static __inline__ void S_init_0069D2D8(S_0069D2D8 *t, s32 text, f32 x, f32 y, f32 w, f32 h, s32 count, s32 *values) {
    lab_0069D2D8(&t->h, text, x, y, w, h);
    t->h.type = 3;
    t->count = count;
    t->values = values;
    t->x50 = 0;
}

static __inline__ void A_init_0069D2D8(A_0069D2D8 *t, s32 text, f32 x, f32 y, f32 w, f32 h) {
    lab_0069D2D8(&t->h, text, x, y, w, h);
    t->h.type = 1;
}

static __inline__ void C_init_0069D2D8(A_0069D2D8 *t, s32 text, f32 x, f32 y, f32 w, f32 h) {
    lab_0069D2D8(&t->h, text, x, y, w, h);
    t->h.type = 2;
}

static __inline__ void B_init_0069D2D8(B_0069D2D8 *t, s32 text, f32 x, f32 y, f32 w, f32 h, s32 n) {
    lab_0069D2D8(&t->h, text, x, y, w, h);
    t->h.type = 4;
    t->x4C = n;
    t->b48 = 0;
}

static __inline__ void N_init_0069D2D8(N_0069D2D8 *t, s32 text, f32 x, f32 y, f32 w, f32 h, s32 value, s32 a, s32 b) {
    lab_0069D2D8(&t->h, text, x, y, w, h);
    t->h.type = 10;
    t->x48 = 0;
    t->x4C = value;
    t->x50 = a;
    t->x54 = b;
}

static __inline__ void I_init_0069D2D8(A_0069D2D8 *t, f32 x, f32 y, s32 v) {
    lab_0069D2D8(&t->h, (s32)D_L39_00248340, x, y, 1.0f, 1.0f);
    t->h.type = 0xB;
    t->x48 = v;
}

static __inline__ void D_init_0069D2D8(D_0069D2D8 *t) {
    lab_0069D2D8(&t->h, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->x48 = 0x2E;
    t->x4C = 0;
    t->h.x = 0;
    t->h.y = 0;
    t->h.w = 1.0f;
    t->h.h = 1.0f;
}

void *func_L39_0069D2D8(u8 *const self)
{
    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047D210;
    *(void **)(self + 0x2A4) = self + 0x2CC;
    {
        s32 a[3] = { func_00381FF0(0xF2A), func_00381FF0(0xF2B), func_00381FF0(0xF29) };
        s32 b[2] = { func_00381FF0(0xF2D), func_00381FF0(0xF2C) };
        s32 c[2] = { func_00381FF0(0xF2C), func_00381FF0(0xF2D) };
        S_0069D2D8 i0, i1, i2;
        A_0069D2D8 i3, i4;
        B_0069D2D8 i5;
        N_0069D2D8 i6;
        A_0069D2D8 ic[12];
        D_0069D2D8 d;

        S_init_0069D2D8(&i0, func_00381FF0(0x18C9), 0.11f, 0.598f, 0.78f, 0.04f, 3, a);
        S_init_0069D2D8(&i1, func_00381FF0(0x191), 0.11f, 0.654f, 0.78f, 0.04f, 2, c);
        S_init_0069D2D8(&i2, func_00381FF0(0x190), 0.11f, 0.71f, 0.78f, 0.04f, 2, b);
        A_init_0069D2D8(&i3, func_00381FF0(0x18CA), 0.11f, 0.766f, 0.78f, 0.04f);
        C_init_0069D2D8(&i4, func_00381FF0(0x149), 0.11f, 0.82199997f, 0.78f, 0.04f);
        B_init_0069D2D8(&i5, (s32)D_L39_00248338, 0.5f, 0.346f, 0.8f, 0.39f, 0x47);
        N_init_0069D2D8(&i6, func_00381FF0(0x18CA), 0.7875f, 0.766f, 0.195f, 0.04f, 100, 5, 5);
        I_init_0069D2D8(&ic[0], D_L39_004B03A0[0].x, D_L39_004B03A0[0].y, D_L39_004B03A0[0].v);
        I_init_0069D2D8(&ic[1], D_L39_004B03A0[1].x, D_L39_004B03A0[1].y, D_L39_004B03A0[1].v);
        I_init_0069D2D8(&ic[2], D_L39_004B03A0[2].x, D_L39_004B03A0[2].y, D_L39_004B03A0[2].v);
        I_init_0069D2D8(&ic[3], D_L39_004B03A0[3].x, D_L39_004B03A0[3].y, D_L39_004B03A0[3].v);
        I_init_0069D2D8(&ic[4], D_L39_004B03A0[4].x, D_L39_004B03A0[4].y, D_L39_004B03A0[4].v);
        I_init_0069D2D8(&ic[5], D_L39_004B03A0[5].x, D_L39_004B03A0[5].y, D_L39_004B03A0[5].v);
        I_init_0069D2D8(&ic[6], D_L39_004B03A0[6].x, D_L39_004B03A0[6].y, D_L39_004B03A0[6].v);
        I_init_0069D2D8(&ic[7], D_L39_004B03A0[7].x, D_L39_004B03A0[7].y, D_L39_004B03A0[7].v);
        I_init_0069D2D8(&ic[8], D_L39_004B03A0[8].x, D_L39_004B03A0[8].y, D_L39_004B03A0[8].v);
        I_init_0069D2D8(&ic[9], D_L39_004B03A0[9].x, D_L39_004B03A0[9].y, D_L39_004B03A0[9].v);
        I_init_0069D2D8(&ic[10], D_L39_004B03A0[10].x, D_L39_004B03A0[10].y, D_L39_004B03A0[10].v);
        I_init_0069D2D8(&ic[11], D_L39_004B03A0[11].x, D_L39_004B03A0[11].y, D_L39_004B03A0[11].v);
        D_init_0069D2D8(&d);
        d.x4C = 19;
        d.items[0] = &i0;
        d.items[1] = &i1;
        d.items[2] = &i2;
        d.items[3] = &i6;
        d.items[4] = &i3;
        d.items[5] = &i4;
        d.items[6] = &i5;
        d.items[7] = &ic[0];
        d.items[8] = &ic[1];
        d.items[9] = &ic[2];
        d.items[10] = &ic[3];
        d.items[11] = &ic[4];
        d.items[12] = &ic[5];
        d.items[13] = &ic[6];
        d.items[14] = &ic[7];
        d.items[15] = &ic[8];
        d.items[16] = &ic[9];
        d.items[17] = &ic[10];
        d.items[18] = &ic[11];
        func_L39_00689670(self, &d);
    }
    return self;
}
/* localdecomp:end func_L39_0069D2D8 */

LINKER_REMNANT("asm/levels", func_L39_0069DA30);

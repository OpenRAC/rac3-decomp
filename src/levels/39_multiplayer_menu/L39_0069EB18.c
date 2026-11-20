#include "common.h"

/* localdecomp:start func_L39_0069EB18 */
typedef struct {
    s32 type;
    u8 name[0x34];
    f32 x, y, w, h;
} H_0069EB18;

typedef struct {
    H_0069EB18 h;
    f32 u0, u1, v0, v1;
    s32 tex;
    u32 color;
} I_0069EB18;

typedef struct {
    H_0069EB18 h;
    u8 pad48[8];
} A_0069EB18;

typedef struct {
    H_0069EB18 h;
    s32 x48;
    s32 x4C;
    void *items[9];
    u8 pad74[0x1D0 - 0x74];
} D_0069EB18;

__asm__(".extern D_001DCD74_sda, 4");
__asm__(".extern D_001DCD78_sda, 4");
__asm__(".extern D_001DCD7C_sda, 4");
__asm__(".extern D_001DCD80_sda, 4");
__asm__(".extern D_001DCD84_sda, 4");
__asm__(".extern D_001DCD88_sda, 4");
__asm__(".extern D_001DCD8C_sda, 4");
extern f32 D_001DCD74_sda;
extern f32 D_001DCD78_sda;
extern f32 D_001DCD7C_sda;
extern f32 D_001DCD80_sda;
extern f32 D_001DCD84_sda;
extern f32 D_001DCD88_sda;
extern f32 D_001DCD8C_sda;
extern u8 D_002484A8[];
extern u8 D_L39_0047D410[];
extern void *func_L39_00688388(void *);
extern void func_L39_0068CD28(u8 *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_L39_00689670(void *, void *);

typedef struct {
    u8 pad0[0x60];
    void *vt;
    u8 pad64[0x2A4 - 0x64];
    void *p2A4;
    u8 pad2A8[0x2B4 - 0x2A8];
    u8 buf[4];
} S_0069EB18;

static __inline__ void lab_0069EB18(H_0069EB18 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    t->type = 0;
    func_L39_0068CD28((u8 *)t, text, x, y, w, h);
}

static __inline__ void I_init_0069EB18(I_0069EB18 *t, void *text, f32 x, f32 y, f32 w, f32 h, s32 tex, u32 color) {
    lab_0069EB18(&t->h, text, x, y, w, h);
    t->h.type = 12;
    t->tex = tex;
    t->u0 = 0.0f;
    t->v0 = 0.0f;
    t->u1 = 1.0f;
    t->v1 = 1.0f;
    t->color = color;
}

static __inline__ void A_init_0069EB18(A_0069EB18 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_0069EB18(&t->h, text, x, y, w, h);
    t->h.type = 1;
}

static __inline__ void D_init_0069EB18(D_0069EB18 *t) {
    lab_0069EB18(&t->h, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->x48 = 0x2E;
    t->x4C = 0;
    t->h.x = 0;
    t->h.y = 0;
    t->h.w = 1.0f;
    t->h.h = 1.0f;
}

void *func_L39_0069EB18(const s32 arg) {
    S_0069EB18 *self = (S_0069EB18 *)arg;
    I_0069EB18 i0, i1, i2, i3, i4, i5, i6, i7;
    A_0069EB18 a;
    D_0069EB18 d;

    func_L39_00688388(self);
    self->p2A4 = self->buf;
    self->vt = D_L39_0047D410;

    I_init_0069EB18(&i0, D_002484A8,
        D_001DCD74_sda + (D_001DCD7C_sda - D_001DCD8C_sda - D_001DCD8C_sda) * -1.5f * 0.25f,
        D_001DCD78_sda + -(D_001DCD80_sda - D_001DCD8C_sda) / 3.0f, D_001DCD84_sda, D_001DCD88_sda, 0xED32, 0x706EC8FF);
    I_init_0069EB18(&i1, D_002484A8,
        D_001DCD74_sda + (D_001DCD7C_sda - D_001DCD8C_sda - D_001DCD8C_sda) * -0.5f * 0.25f,
        D_001DCD78_sda + -(D_001DCD80_sda - D_001DCD8C_sda) / 3.0f, D_001DCD84_sda, D_001DCD88_sda, 0xED2E, 0x706EC8FF);
    I_init_0069EB18(&i2, D_002484A8,
        D_001DCD74_sda + (D_001DCD7C_sda - D_001DCD8C_sda - D_001DCD8C_sda) * 0.5f * 0.25f,
        D_001DCD78_sda + -(D_001DCD80_sda - D_001DCD8C_sda) / 3.0f, D_001DCD84_sda, D_001DCD88_sda, 0xED31, 0x706EC8FF);
    I_init_0069EB18(&i3, D_002484A8,
        D_001DCD74_sda + (D_001DCD7C_sda - D_001DCD8C_sda - D_001DCD8C_sda) * 1.5f * 0.25f,
        D_001DCD78_sda + -(D_001DCD80_sda - D_001DCD8C_sda) / 3.0f, D_001DCD84_sda, D_001DCD88_sda, 0xED2F, 0x706EC8FF);
    I_init_0069EB18(&i4, D_002484A8,
        D_001DCD74_sda + (D_001DCD7C_sda - D_001DCD8C_sda - D_001DCD8C_sda) * -1.5f * 0.25f,
        D_001DCD78_sda + (D_001DCD80_sda - D_001DCD8C_sda) * 0.0f / 3.0f, D_001DCD84_sda, D_001DCD88_sda, 0xED4F, 0x706EC8FF);
    I_init_0069EB18(&i5, D_002484A8,
        D_001DCD74_sda + (D_001DCD7C_sda - D_001DCD8C_sda - D_001DCD8C_sda) * -0.5f * 0.25f,
        D_001DCD78_sda + (D_001DCD80_sda - D_001DCD8C_sda) * 0.0f / 3.0f, D_001DCD84_sda, D_001DCD88_sda, 0xED2D, 0x706EC8FF);
    I_init_0069EB18(&i6, D_002484A8,
        D_001DCD74_sda + (D_001DCD7C_sda - D_001DCD8C_sda - D_001DCD8C_sda) * 0.5f * 0.25f,
        D_001DCD78_sda + (D_001DCD80_sda - D_001DCD8C_sda) * 0.0f / 3.0f, D_001DCD84_sda, D_001DCD88_sda, 0xEA77, 0x706EC8FF);
    I_init_0069EB18(&i7, D_002484A8,
        D_001DCD74_sda + (D_001DCD7C_sda - D_001DCD8C_sda - D_001DCD8C_sda) * 1.5f * 0.25f,
        D_001DCD78_sda + (D_001DCD80_sda - D_001DCD8C_sda) * 0.0f / 3.0f, D_001DCD84_sda, D_001DCD88_sda, 0xEA69, 0x706EC8FF);
    A_init_0069EB18(&a, D_002484A8, D_001DCD74_sda,
        D_001DCD78_sda + (D_001DCD80_sda - D_001DCD8C_sda) / 3.0f, D_001DCD7C_sda - D_001DCD8C_sda * 2.0f, 0.05f);
    D_init_0069EB18(&d);
    d.x4C = 9;
    d.items[0] = &i0;
    d.items[1] = &i1;
    d.items[2] = &i2;
    d.items[3] = &i3;
    d.items[4] = &i4;
    d.items[5] = &i5;
    d.items[6] = &i6;
    d.items[7] = &i7;
    d.items[8] = &a;
    func_L39_00689670(self, &d);
    return self;
}
/* localdecomp:end func_L39_0069EB18 */

LINKER_REMNANT("asm/levels", func_L39_0069F0F8);

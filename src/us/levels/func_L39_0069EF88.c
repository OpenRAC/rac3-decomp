#include "common.h"

/* NTSC-U counterpart of func_L39_006A1798 (src/levels/39_multiplayer_menu/L39_006A1798.c) */
typedef struct { char pad[0x70]; char *f70; } T;

/* localdecomp:start func_L39_0069EF88 */
typedef struct W_006A1798 W_006A1798;
typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(W_006A1798 *, s32, s32);
    u8 pad20[0x40 - 0x20];
    s32 (*f40)(W_006A1798 *, s32);
    s32 (*f44)(W_006A1798 *, s32, f32, f32);
    u8 pad48[0x4C - 0x48];
    s32 (*f4C)(W_006A1798 *, s32, s32);
    u8 pad50[0x54 - 0x50];
    s32 (*f54)(W_006A1798 *, s32);
    u8 pad58[0x5C - 0x58];
    s32 (*f5C)(W_006A1798 *, f32);
    u8 pad60[0x6C - 0x60];
    s32 (*f6C)(W_006A1798 *, s32, void *);
    u8 pad70[0x84 - 0x70];
    s32 (*f84)(W_006A1798 *, s32);
    s32 (*f88)(W_006A1798 *, s32);
    u8 pad8C[0x90 - 0x8C];
    s32 (*f90)(W_006A1798 *, f32);
    s32 (*f94)(W_006A1798 *, f32);
    u8 pad98[0xE4 - 0x98];
    s32 (*fE4)(W_006A1798 *, f32);
} V_006A1798;
struct W_006A1798 {
    u8 pad[0x60];
    V_006A1798 *vt;
    u8 pad64[0xB4 - 0x64];
    s32 fB4;
};
typedef struct {
    u8 pad0[0x80];
    u8 b80;
    u8 pad81[0x88 - 0x81];
    s32 x88;
    u8 pad8C[0x104 - 0x8C];
    u8 b104;
    u8 pad105[0x10C - 0x105];
    s32 x10C;
    u8 pad110[0x134 - 0x110];
    u8 b134;
    u8 pad135[0x13C - 0x135];
    s32 x13C;
    u8 b140;
    u8 pad141[0x148 - 0x141];
    s32 x148;
} Q_006A1798;
typedef struct {
    u8 pad0[0x110];
    W_006A1798 *w[13];
    u8 pad144[0x2A8 - 0x144];
    u8 b2A8;
    u8 pad2A9[3];
    s32 x2AC;
    s32 x2B0;
    u8 pad2B4[4];
    u8 b2B8;
    u8 b2B9;
    u8 b2BA;
    u8 pad2BB[0x10C4 - 0x2BB];
    u8 s10C4[0x1298 - 0x10C4];
    u8 s1298[0x146C - 0x1298];
    u8 s146C[0x1640 - 0x146C];
    Q_006A1798 *p1640;
} S_006A1798;

extern void func_L39_0067C5E0(s32);
extern void func_L39_00687E10(s32);
extern s32 func_0037DF98(s32);
extern void func_L39_00687030(void *, s32);
extern void func_L39_00687180(void *, s32);
extern void func_L39_00687210(void *, s32);
extern void func_L39_00686FD8(void *);
extern void func_L39_00687B28(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_00687900(void *, s32, s32, u32, f32, f32, f32, f32);
extern void func_L39_00687C10(void *, s32, u32, f32, f32, f32, f32);
extern void func_L39_0069F828(void *);
extern void func_L39_00687F10(void *);
extern void func_L39_00688750(void *, s32, s32);
extern void func_L39_006C9E00(void *, s32, s32, s32);
extern void func_L39_005945F0(void *, void *, s32);
extern s32 func_00120884(char *);
extern s32 func_L01_00514020(s32, s32);
extern s32 func_003E3330(s32, f32, f32);
extern void *func_L39_006A01C0(s32, s32);
extern s32 func_L39_006C9E40(void *);
extern void func_L39_006C9E28(void *, s32);
__asm__(".extern D_001E19E8_sda, 8");
extern u8 D_001E19E8_sda[] __attribute__((section(".sdata")));
typedef struct { u8 pad[0xB7]; u8 bB7; } G_006A1798;
extern G_006A1798 D_001A5990;
__asm__(".extern D_L39_0024D860, 16");
extern T *D_L39_0024D860;

void func_L39_0069EF88(S_006A1798 *self) {
    void *buf[2];
    void *t;
    W_006A1798 *w;
    Q_006A1798 *q;
    s32 v;
    s32 vb;
    s32 v2;
    s32 v3;
    s32 i;

    func_L39_0067C5E0(0x300000);
    func_L39_00687E10(0);
    func_L39_00687030(self, func_0037DF98(0xF65));
    func_L39_00687180(self, func_0037DF98(0x124));
    func_L39_00687210(self, func_0037DF98(0xCD5));
    func_L39_00686FD8(self);
    func_L39_00687B28(self, 0, 0.3f, 0.458f, 0.42f, 0.63f, 0x332299DE);
    func_L39_00687900(self, 0, 5, 0x332299DE, 0.3f, 0.2546667f, 0.10166669f, 0.39f);
    func_L39_00687B28(self, 1, 0.3f, 0.82f, 0.42f, 0.075f, 0x332299DE);
    func_L39_00687B28(self, 2, 0.715f, 0.5f, 0.39f, 0.712f, 0x332299DE);
    func_L39_00687900(self, 3, 0xB, 0x332299DE, 0.715f, 0.26f, 0.05f, 0.36f);
    func_L39_00687C10(self, 0, 0x331465B7, 0.715f, 0.21f, 0.63f, 0.36f);
    self->w[7]->vt->f1C(self->w[7], 1, 0);
    self->w[9]->vt->f1C(self->w[9], 1, 0);
    self->w[10]->vt->f1C(self->w[10], 1, 0);
    self->w[11]->vt->f1C(self->w[11], 1, 0);
    self->w[12]->vt->f1C(self->w[12], 1, 0);
    func_L39_0069F828(self);
    func_L39_00687F10(self);
    func_L39_00688750(self, 6, 0);
    self->b2A8 = 0;
    func_L39_006C9E00(self->s10C4, 0xC, 2, 0);
    func_L39_006C9E00(self->s10C4, 0xD, 2, self->x2AC);
    func_L39_006C9E00(self->s10C4, 3, 0, 8);
    func_L39_006C9E00(self->s1298, 0xC, 2, 0);
    func_L39_006C9E00(self->s1298, 0xD, 2, self->x2AC);
    func_L39_006C9E00(self->s1298, 3, 0, 8);
    func_L39_006C9E00(self->s146C, 0xC, 2, 1);
    func_L39_006C9E00(self->s146C, 0xD, 2, self->x2AC);
    func_L39_006C9E00(self->s146C, 3, 0, 8);
    self->b2A8 = 1;
    buf[0] = (void *)func_0037DF98(0x1008);
    t = (void *)func_0037DF98(0x1008);
    func_L39_005945F0(D_001E19E8_sda, t, func_00120884((char *)func_0037DF98(0x1008)));
    buf[0] = D_001E19E8_sda;
    self->w[8]->vt->f6C(self->w[8], 1, buf);
    self->w[8]->vt->fE4(self->w[8], 0.35f);
    self->w[8]->vt->f94(self->w[8], 0.8f);
    self->w[8]->vt->f90(self->w[8], 0.05f);
    self->w[8]->vt->f1C(self->w[8], 2, 0);
    self->w[3]->vt->f54(self->w[3], 1);
    self->w[3]->vt->f5C(self->w[3], 0.39f);
    w = self->w[3];
    func_L01_00514020(w->fB4, 1);
    func_003E3330(w->fB4, 0.24f, 0.0f);
    for (i = 0; i < 9; i++) {
        self->w[i]->vt->f4C(self->w[i], 0x40, 1);
    }
    D_L39_0024D860->f70[0x10] = 0;
    q = self->p1640;
    v = 0;
    if (q == (Q_006A1798 *)self->s10C4 || q == (Q_006A1798 *)self->s1298) {
        func_L39_006C9E00(q, 0xC, 2, 0);
        q = self->p1640;
    }
    if (q->b104) {
        v = q->x10C;
    }
    self->w[0]->vt->f88(self->w[0], v);
    self->x2B0 = 0;
    buf[1] = func_L39_006A01C0((s32)self, 0);
    self->w[5]->vt->f6C(self->w[5], 1, &buf[1]);
    q = self->p1640;
    v2 = 0;
    if (q->b80) {
        v2 = q->x88 - 1;
    }
    self->w[4]->vt->f88(self->w[4], v2);
    q = self->p1640;
    v3 = 0;
    if (q->b140) {
        v3 = q->x148 + 1;
    }
    self->w[2]->vt->f88(self->w[2], v3);
    vb = 0;
    q = self->p1640;
    if (q->b134) {
        vb = q->x13C;
    }
    self->w[0]->vt->f40(self->w[0], 1);
    self->w[5]->vt->f40(self->w[5], 1);
    self->w[4]->vt->f40(self->w[4], 1);
    self->w[1]->vt->f40(self->w[1], 1);
    self->w[2]->vt->f40(self->w[2], 1);
    self->w[3]->vt->f40(self->w[3], 1);
    switch (D_001A5990.bB7) {
    case 2:
        self->w[0]->vt->f44(self->w[0], 1, 0.24f, 0.0f);
        self->w[1]->vt->f44(self->w[1], 1, 0.26f, 0.0f);
        break;
    case 4:
        self->w[0]->vt->f44(self->w[0], 1, 0.24f, 0.0f);
        self->w[1]->vt->f44(self->w[1], 1, 0.31f, 0.0f);
        break;
    case 3:
    case 5:
        self->w[0]->vt->f44(self->w[0], 1, 0.23f, 0.0f);
        self->w[1]->vt->f44(self->w[1], 1, 0.29f, 0.0f);
        break;
    default:
        self->w[0]->vt->f44(self->w[0], 1, 0.25f, 0.0f);
        self->w[1]->vt->f44(self->w[1], 1, 0.34f, 0.0f);
        break;
    }
    self->w[1]->vt->f88(self->w[1], vb);
    func_L39_006C9E40(self->p1640);
    self->w[8]->vt->f84(self->w[8], 1);
    self->w[8]->vt->f6C(self->w[8], 1, buf);
    self->w[8]->vt->f1C(self->w[8], 2, 0);
    func_L39_006C9E28(self->p1640, 0xD);
    func_L39_006C9E28(self->p1640, 0xE);
    func_L39_006C9E40(self->p1640);
    self->b2B9 = 0;
    self->b2B8 = 1;
    self->b2BA = 0;
}
/* localdecomp:end func_L39_0069EF88 */

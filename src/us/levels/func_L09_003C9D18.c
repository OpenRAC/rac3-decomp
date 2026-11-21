#include "common.h"

/* NTSC-U counterpart of func_L09_003CB7B0 (src/levels/shared/L09_003CB6C0.c): h12E threshold 120 against PAL's 100 (60 Hz) */
/* localdecomp:start func_L09_003C9D18 */
#include "vu0.h"

typedef int Q_003C9D18 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x10];
    f32 f24;
    u8 pad28[0x1C];
    u16 h44;
    u8 b46;
} Cls_003C9D18;
typedef struct {
    u8 pad0[0xC0];
    Q_003C9D18 qC0;
    u8 padD0[0x10];
    Q_003C9D18 qE0;
    Q_003C9D18 qF0;
    void *p100;
    u8 pad104[0x20];
    s16 h124;
    u8 pad126[4];
    s16 h12A;
    u8 pad12C[2];
    s16 h12E;
    u8 pad130[8];
    f32 f138;
} Obj_003C9D18;
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[0x3E];
} Slot_003C9D18;
typedef struct Sub_003C9D18 {
    f32 *p0;
    u8 pad4[0x2C];
    f32 f30;
    s16 h34;
    u8 pad36[8];
    u8 b3E;
    u8 pad3F;
    f32 f40;
    u8 pad44[0x1E];
    u8 b62;
    u8 pad63[0x16D];
    s32 w1D0;
    u8 pad1D4[0xA];
    u8 b1DE;
    u8 b1DF;
    Slot_003C9D18 slots[17];
    u8 pad620[0x30];
    f32 f650;
    f32 f654;
    f32 f658;
    u8 pad65C[0x74];
    Obj_003C9D18 *p6D0;
    u8 pad6D4[8];
    f32 f6DC;
    u8 pad6E0[0x30];
    u16 h710;
    u8 pad712[3];
    u8 b715;
    u8 pad716[0xA];
    void *p720;
    u8 pad724[0x34];
    s32 w758;
    s32 w75C;
    s16 h760;
    s16 h762;
    s32 w764[5];
    s32 w778;
    s32 w77C;
    s32 w780;
    s32 w784;
    s32 w788;
    u8 pad78C[4];
    s32 w790[4];
    u8 pad7A0[0x14];
    s32 w7B4[7];
    s32 w7D0;
} Sub_003C9D18;
typedef struct Moby_003C9D18 {
    u8 pad0[0x10];
    f32 pos[4] __attribute__((aligned(16)));
    u8 b20;
    u8 pad21[3];
    Cls_003C9D18 *p24;
    u8 pad28[4];
    f32 f2C;
    u8 b30;
    u8 b31;
    s16 h32;
    u16 h34;
    u8 pad36[0x32];
    Sub_003C9D18 *sub;
    u8 pad6C[3];
    u8 b6F;
    u8 pad70[0x26];
    s16 h96;
    s32 w98;
    u8 pad9C[0x20];
    u8 bBC;
    u8 padBD[0x33];
    Q_003C9D18 qF0;
} Moby_003C9D18;

extern Moby_003C9D18 *D_L09_001E011C;
extern s32 D_L09_001D6694;
extern u8 D_0014275B __attribute__((section(".data")));
extern f32 D_L09_001DAA38;
extern f32 D_L09_002F1FB0[];
extern f32 D_L09_001DE8F0;
extern f32 D_L09_001DE8F4;
extern Obj_003C9D18 D_L09_002A2EB0[];
extern Obj_003C9D18 D_L09_002A2FF0[];
extern u8 D_L09_002BB3A0[];
extern u8 D_L09_002BB42C[];
extern s32 D_001A71A4[];
extern u8 D_L09_001E2C00[];
extern struct { u8 pad[0x1A4]; u32 w1A4; } *D_001D52FC;

extern s32 func_L01_00448E90(void *);
extern void func_003BD360(void *);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L01_00417EA0(void);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_00388440(void *, s32, s32);
extern void func_L09_003C6188(u8 *);
extern void func_L09_003C9C28(u8 *);
extern void func_L01_00437350(void *, s32, void *);
extern void (**func_L01_00438468(s32, s32))(void *);
extern void func_L09_003C4550(void *);
extern void func_L09_003C91D8(u8 *);
extern void func_L09_003C78E0(void *);
extern void func_L09_003C8F00(void *);
extern void func_L09_003C53D8(void *);
extern void func_L09_003C52C0(u8 *);
extern void func_L09_003C9218(u8 *);
extern void func_L01_004EA040(void);
extern void func_L09_003C4A30(void *);
extern void func_L09_003C5F38(void *);
extern void func_L01_00456960(s32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);

extern s32 D_001D545C;
extern void func_L09_003C93D0(void *);

void func_L09_003C9D18(Moby_003C9D18 *self) {
    Sub_003C9D18 *s;
    Obj_003C9D18 *o;
    Moby_003C9D18 *m;
    f32 k;
    s32 i;
    s32 j;
    s32 n;
    s32 v;
    void (**fp)(void *);

    if (func_L01_00448E90(self->pos) == 0) {
        return;
    }
    s = self->sub;
    if (s->b62 == 1) {
        func_003BD360(self);
        return;
    }
    if (D_L09_001D6694 == 2) {
        if ((*(u8 *)&self->h34 ^ 1) & 1) {
            self->w98 = 0;
            self->h34 = (self->h34 | 0x41) & ~0x1000;
            func_L01_004A6DF8(self, 1);
            s->w7D0 = 1;
        }
    } else if (s->w7D0 != 0) {
        self->h34 &= ~0x41;
        self->h34 |= self->p24->h44 & 0x1000;
        self->w98 = self->p24->w10;
        s->w7D0 = 0;
    }
    o = s->p6D0;
    switch (self->b20) {
    case 0:
        for (i = 0; i < 7; i++) {
            if (s->w7B4[i] != -1) {
                Moby_003C9D18 *q = &D_L09_001E011C[s->w7B4[i]];
                q->w98 = 0;
                q->h34 |= 0x41;
            }
        }
        self->p24->b46 = 13;
        s->p0 = &self->sub->f30;
        self->h34 |= 0x5020;
        k = 1.0f;
        if (func_L01_00417EA0()) {
            v = D_001D545C;
            if (v == 7 && D_0014275B != 0) {
                k = D_L09_001DAA38;
            } else {
                k = D_L09_002F1FB0[v];
            }
        }
        if (D_001D545C == 0x12) {
            s->f30 = D_L09_001DE8F4 * k;
            s->h34 = s->f30;
        } else if (D_001D545C == 0x14) {
            s->f30 = 200.0f * k;
            s->h34 = s->f30;
        } else {
            s->f30 = D_L09_001DE8F0 * k;
            s->h34 = s->f30;
        }
        s->b3E = 3;
        s->f40 = 0.95f;
        self->h32 = 0x1FF;
        self->b30 = 0xFF;
        if (s->w758 != -1) {
            m = &D_L09_001E011C[s->w758];
            func_L01_00441FB8((u8 *)m, 1, -1);
            m->h34 |= 0x100;
            m->f2C = m->p24->f24 * 0.78f;
        }
        if (self->pos[2] < 600.0f) {
            func_00388440(D_L09_002A2EB0, 0, 0x140);
            s->p6D0 = D_L09_002A2EB0;
        } else {
            func_00388440(D_L09_002A2FF0, 0, 0x140);
            s->p6D0 = D_L09_002A2FF0;
        }
        s->p6D0->h124 = 0;
        s->p6D0->p100 = self;
        s->h760 = 0;
        s->w764[0] = 0;
        s->w764[1] = 0;
        s->w764[2] = 0;
        s->w764[3] = 0;
        s->w764[4] = 0;
        s->h762 = 0;
        s->w778 = -1;
        s->w77C = -1;
        s->w780 = -1;
        s->w784 = -1;
        s->w788 = 2;
        for (n = 3; n >= 0; n--) {
            s->w790[n] = 0;
        }
        s->w75C = 0;
        s->f6DC = self->pos[2];
        if (D_001D545C == 0x15CC || D_001D545C == 0xBC2 || D_001D545C == 0x18) {
            s->b715 = 0;
            s->p720 = D_L09_002BB3A0;
        } else {
            s->b715 = 1;
            s->p720 = D_L09_002BB42C;
        }
        func_L09_003C6188((u8 *)self);
        func_L09_003C9C28((u8 *)self);
        s->p6D0->qE0 = *(Q_003C9D18 *)self->pos;
        s->p6D0->qF0 = self->qF0;
        self->f2C = self->p24->f24 * 0.75f;
        for (j = 0; j < 17; j++) {
            if ((s->slots + j)->b1 == 0) {
                func_L01_00437350(self, j, s->slots + j);
            }
        }
        if (s->w1D0 > 0) {
            fp = func_L01_00438468(0x19E1, 0x6C);
            s->w1D0 = -1;
            s->b1DE = 5;
            s->b1DF = 0;
            (*fp)(self);
        } else {
            if (s->w758 != -1) {
                func_L09_003C4550(self);
            }
            func_L01_00441FB8((u8 *)self, 1, -1);
        }
        break;
    case 2:
        func_L09_003C91D8((u8 *)self);
        func_L09_003C78E0(self);
        func_L09_003C8F00(self);
        if (s->w758 == -1) {
            func_L09_003C53D8(self);
        }
        if (D_001D52FC->w1A4 & 0x10) {
            func_L09_003C52C0((u8 *)self);
        }
        break;
    case 3:
        if (__builtin_fabsf(s->p6D0->f138) < 0.001f && __builtin_fabsf(s->f650) < 0.001f
            && __builtin_fabsf(s->f654) < 0.001f && __builtin_fabsf(s->f658) < 0.001f) {
            o->f138 = 0.0f;
            qzero(&o->qC0);
            func_L01_00441FB8((u8 *)self, 1, -1);
        } else {
            func_L09_003C78E0(self);
            func_L09_003C8F00(self);
        }
    case 1:
        func_L09_003C9218((u8 *)self);
        break;
    case 4:
        if (self->bBC == 0) {
            if (D_001A71A4[0] == 0x31) {
                func_L09_003C52C0((u8 *)self);
                func_L01_004EA040();
            }
            func_L01_00441FB8((u8 *)self, 1, -1);
            if (s->w758 != -1) {
                Moby_003C9D18 *q = &D_L09_001E011C[s->w758];
                q->h34 &= ~0x41;
                q->h34 |= q->p24->h44 & 0x1000;
                q->w98 = q->p24->w10;
            }
        }
        break;
    }
    if (s->w758 != -1) {
        if (s->h710 & 4) {
            func_L09_003C4A30(self);
        }
        func_L09_003C4550(self);
    }
    func_L09_003C5F38(self);
    self->h96++;
    if (s->p6D0 != 0) {
        if (s->p6D0->h12A != 0) {
            s->p6D0->h12E = s->p6D0->h12A;
        }
        if (D_001D545C == 0x12 && s->p6D0->h12A == 0 && s->p6D0->h12E > 120) {
            func_L01_00456960(0);
        }
    }
    if (self->b31 != 0) {
        if (func_L01_0040C018(D_L09_001E2C00, self->pos) < 484.0f) {
            func_L01_00444188(self);
            self->b6F = 20;
        }
    }
    func_L09_003C93D0(self);
}
/* localdecomp:end func_L09_003C9D18 */

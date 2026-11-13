#include "common.h"

/* declared by functions of L39_006BA5C0.c, which this file was cut from */
void func_L39_00688400(void *, s32);
void func_L39_0067F168(void);
void func_L39_0068ADC8(void *);

/* localdecomp:start func_L39_006C0F38 */
typedef struct V_006C0F38 V_006C0F38;
typedef struct W_006C0F38 {
    u8 pad[0x60];
    V_006C0F38 *vt;
} W_006C0F38;
struct V_006C0F38 {
    u8 pad0[0x1C];
    void (*f1C)(W_006C0F38 *, s32, s32);
    u8 pad20[0x24 - 0x20];
    void (*f24)(W_006C0F38 *, void *);
    u8 pad28[0x40 - 0x28];
    void (*f40)(W_006C0F38 *, s32);
    void (*f44)(W_006C0F38 *, s32, f32, f32);
    void (*f48)(W_006C0F38 *, s32, s32);
    u8 pad4C[0x50 - 0x4C];
    void (*f50)(W_006C0F38 *, s32);
};
typedef struct T_006C0F38 {
    u8 pad0[0x110];
    W_006C0F38 *w110;
    W_006C0F38 *w114;
    W_006C0F38 *w118;
    u8 pad11C[0x120 - 0x11C];
    W_006C0F38 *w120;
    u8 pad124[0x12C - 0x124];
    W_006C0F38 *w12C;
    W_006C0F38 *w130;
    u8 pad134[0x138 - 0x134];
    W_006C0F38 *w138;
    W_006C0F38 *w13C;
    W_006C0F38 *w140;
    W_006C0F38 *w144;
    W_006C0F38 *w148;
    W_006C0F38 *grid[10][8];
    u8 pad28C[0x2A8 - 0x28C];
    u8 b2A8;
    u8 pad2A9[0x2B5 - 0x2A9];
    u8 b2B5;
    u8 b2B6;
    u8 pad2B7;
    s32 s2B8;
    u8 pad2BC[0x2C4 - 0x2BC];
    s32 s2C4;
    u8 b2C8;
    u8 b2C9;
    u8 pad2CA[0x2F8 - 0x2CA];
    s32 s2F8;
    s32 s2FC;
} T_006C0F38;

extern f32 D_002495A0;
extern f32 D_002495A4;
extern f32 D_002495B8;
extern f32 D_002495BC;
extern f32 D_002495C0;
extern u8 D_00249558[];
typedef struct S_006C0F38 {
    u8 pad[0x134];
    s32 f134;
} S_006C0F38;
extern S_006C0F38 D_1A5CD0;
extern void **D_0024D760;
extern void func_1990D8(void);
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern s32 func_00381FF0(s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689DB8(void *, s32);
extern void func_L39_00689E58(void *, s32, u32, f32, f32);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A4A8(void *, s32, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_00685CF8(void *, f32);
extern s32 func_L39_006C45C8(void *, s32, s32 *);
extern void func_L39_0059A638(s32);
extern void func_L39_006C2C40(void *);
extern void func_L39_006C3AA8(void *);
extern void func_L39_006C20B0(void *);
extern s32 func_L39_006D08E8(void *);
extern s32 func_L39_006CD768(u8 *);
extern void func_L39_005C1A60(s32, s32, s32);

void func_L39_006C0F38(T_006C0F38 *self)
{
    s32 i;
    s32 j;
    s32 tmp;
    W_006C0F38 **g;

    func_1990D8();
    func_L39_0067F100(0x410000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(self, func_00381FF0(0xFF4));
    func_L39_00689D28(self, func_00381FF0(0x124));
    func_L39_00689E58(self, func_00381FF0(0x1102), 0x706EC8FF, 1.0f, 1.0f);
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_0068A6D0(self, 0, 0.5f, 0.163f, 0.825f, 0.05f, 0x332299DE);
    func_L39_0068A6D0(self, 1, 0.287f, 0.248f, 0.4f, 0.104f, 0x332299DE);
    func_L39_0068A6D0(self, 2, 0.287f, 0.366f, 0.4f, 0.118f, 0x332299DE);
    func_L39_0068A6D0(self, 3, 0.704f, 0.31f, 0.42f, 0.23f, 0x332299DE);
    func_L39_0068A6D0(self, 4, 0.5f, 0.648f, 0.825f, 0.432f, 0x332299DE);
    func_L39_0068A4A8(self, 0, 1, 0x332299DE, 0.287f, 0.365f, 0.048999995f, 0.38f);
    func_L39_0068AAB8(self);

    g = self->grid[9];
    for (i = 0; i < 8; i++) {
        g[-72]->vt->f1C(g[-72], 0, 0);
        g[-64]->vt->f1C(g[-64], 0, 0);
        g[-56]->vt->f1C(g[-56], 0, 0);
        g[-48]->vt->f1C(g[-48], 0, 0);
        g[-40]->vt->f1C(g[-40], 0, 0);
        g[-32]->vt->f1C(g[-32], 0, 0);
        g[-16]->vt->f1C(g[-16], 0, 0);
        g[-24]->vt->f1C(g[-24], 0, 0);
        g[-8]->vt->f1C(g[-8], 0, 0);
        g[0]->vt->f1C(g[0], 0, 0);
        g[-72]->vt->f48(g[-72], 1, 3);
        g[-8]->vt->f48(g[-8], 3, 3);
        g[-72]->vt->f44(g[-72], 1, D_002495A0, 0.0f);
        g[-8]->vt->f44(g[-8], 1, D_002495BC, 0.0f);
        g[-72]->vt->f40(g[-72], 1);
        g[-8]->vt->f40(g[-8], 1);
        g[0]->vt->f50(g[0], func_0038DBD8(0x8066CCFF, 0x8000FF00, 0.5f));
        g++;
    }
    self->w144->vt->f1C(self->w144, 0, 0);
    self->w148->vt->f1C(self->w148, 0, 0);
    self->w110->vt->f1C(self->w110, 1, 0);
    self->w114->vt->f1C(self->w114, 1, 0);
    self->w114->vt->f40(self->w114, 1);
    self->w118->vt->f1C(self->w118, 1, 0);
    self->w118->vt->f40(self->w118, 1);
    self->w118->vt->f24(self->w118, D_00249558);
    self->w120->vt->f24(self->w120, (void *)func_00381FF0(0xFF9));
    self->w120->vt->f40(self->w120, 0);
    func_L39_00685CF8(self->w144, -1.5707964f);
    func_L39_00685CF8(self->w148, -1.5707964f);
    self->w12C->vt->f48(self->w12C, 1, 3);
    self->w12C->vt->f1C(self->w12C, 1, 0);
    self->w12C->vt->f40(self->w12C, 1);
    self->w12C->vt->f44(self->w12C, 1, D_002495A0, 0.0f);
    self->w130->vt->f1C(self->w130, 1, 0);
    self->w130->vt->f40(self->w130, 1);
    self->w130->vt->f44(self->w130, 1, D_002495A4 * 5.0f, 0.0f);
    self->w138->vt->f1C(self->w138, 1, 0);
    self->w138->vt->f40(self->w138, 1);
    self->w138->vt->f44(self->w138, 1, D_002495B8, 0.0f);
    self->w13C->vt->f1C(self->w13C, 1, 0);
    self->w13C->vt->f40(self->w13C, 1);
    self->w13C->vt->f44(self->w13C, 1, D_002495BC, 0.0f);
    self->w140->vt->f1C(self->w140, 1, 0);
    self->w140->vt->f40(self->w140, 1);
    self->w140->vt->f44(self->w140, 1, D_002495C0, 0.0f);

    self->b2B6 = 1;
    self->b2B5 = 1;
    self->s2B8 = 0;
    self->b2A8 = 0;
    self->s2F8 = D_1A5CD0.f134;
    self->b2C8 = 0;
    self->b2C9 = 0;
    self->s2C4 = 500;
    self->s2FC = 1;

    for (j = 0; j < 8; j++) {
        if (func_L39_006C45C8(self, j, &tmp)) {
            func_L39_0059A638(tmp);
        }
    }
    func_L39_006C2C40(self);
    func_L39_006C3AA8(self);
    func_L39_006C20B0(self);
    if (*(s32 *)D_0024D760[0xE] >= 0) {
        func_L39_006D08E8(D_0024D760[0xE]);
    }
    func_L39_006CD768(D_0024D760[0xD]);
    func_L39_005C1A60(1, 1, 0x400);
}
/* localdecomp:end func_L39_006C0F38 */

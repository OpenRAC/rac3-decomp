#include "common.h"

/* NTSC-U counterpart of func_L39_006C5540 (src/levels/39_multiplayer_menu/L39_006C5540.c) */
/* localdecomp:start func_L39_006C2A28 */
typedef struct W_006C5540 W_006C5540;
typedef struct V_006C5540 {
    u8 pad0[0x1C];
    void (*f1C)(W_006C5540 *, s32, s32);
    u8 pad20[0x38 - 0x20];
    void (*f38)(W_006C5540 *, f32, f32);
    u8 pad3C[0x40 - 0x3C];
    void (*f40)(W_006C5540 *, s32);
    void (*f44)(W_006C5540 *, s32, f32, f32);
    void (*f48)(W_006C5540 *, s32, s32);
    void (*f4C)(W_006C5540 *, s32, s32);
    void (*f50)(W_006C5540 *, s32);
    u8 pad54[0x68 - 0x54];
    void (*f68)(W_006C5540 *);
    u8 pad6C[0x84 - 0x6C];
    void (*f84)(W_006C5540 *, s32);
    u8 pad88[0x90 - 0x88];
    void (*f90)(W_006C5540 *, f32);
    void (*f94)(W_006C5540 *, f32);
    u8 pad98[0xB8 - 0x98];
    void (*fB8)(W_006C5540 *, s32);
} V_006C5540;
struct W_006C5540 {
    u8 pad[0x60];
    V_006C5540 *vt;
};
typedef struct T_006C5540 {
    u8 pad0[0x110];
    W_006C5540 *w[35];
    u8 pad19C[0x2AC - 0x19C];
    u8 f2AC;
    u8 pad2AD[0xB60 - 0x2AD];
    u8 fB60;
    u8 fB61;
    u8 padB62[0xB68 - 0xB62];
    s32 fB68;
    u8 padB6C[0xBA8 - 0xB6C];
    s32 fBA8;
    s32 fBAC;
    u8 fBB0;
    u8 padBB1[0xBB4 - 0xBB1];
    s32 fBB4;
    u8 padBB8[0xD48 - 0xBB8];
    s32 fD48;
} T_006C5540;
extern u8 D_L39_002498C8[];
extern s32 D_001DDFF8_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DDFF8_sda, 8");
extern s32 D_001DDEDC_sda;
extern f32 D_001DDEE0_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DDEE0_sda, 4");
extern f32 D_001DDEE4_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DDEE4_sda, 4");
extern u8 D_001E1AD0_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001E1AD0_sda, 8");
extern void func_L39_0067C5E0(s32);
extern void func_L39_00687E10(s32);
extern s32 func_0037DF98(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_00120884(s32);
extern void func_L39_005945F0(u8 *, s32, s32);
extern void func_L39_00687030(void *, s32);
extern void func_L39_00687180(void *, s32);
extern void func_L39_006872B0(void *, u8 *, u32, f32, f32);
extern void func_L39_00687210(void *, s32);
extern void func_L39_00686FD8(void *);
extern void func_L39_00687F10(void *);
extern void func_L39_006C3ED0(void *, s32);
extern void func_L39_006C5238(void *, s32, s32, u8 **);
extern void func_L39_006C5320(void *, s32);
extern void func_L39_006C4040(void *, s32, s32);
extern void func_L39_006C5150(void *, s32);
extern s32 func_L39_00688750(void *, s32, s32);
extern void func_L39_006C3050(void *);

void func_L39_006C2A28(T_006C5540 *self)
{
    u8 buf[32];
    u8 *strs[1];
    s32 i;
    s32 a;

    func_L39_0067C5E0(0x430000);
    func_L39_00687E10(0);
    func_L39_00687030(self, func_0037DF98(0xF68));
    func_L39_00687180(self, func_0037DF98(0x124));
    func_00120048(buf, D_L39_002498C8, func_0037DF98(0x1340));
    func_L39_006872B0(self, buf, 0x706EC8FF, 0.8f, 0.9f);
    func_L39_00687210(self, func_0037DF98(0xCD5));
    func_L39_00686FD8(self);
    func_L39_00687F10(self);
    self->f2AC = 1;

    for (i = 0; i < 7; i++) {
        self->w[i]->vt->f4C(self->w[i], 0x40, 1);
        self->w[i]->vt->f38(self->w[i], 0.8f, 1.0f);
    }
    self->w[10]->vt->f4C(self->w[10], 0x40, 1);
    self->w[10]->vt->f38(self->w[10], 0.85f, 1.0f);
    self->w[8]->vt->f4C(self->w[8], 0x40, 1);
    self->w[8]->vt->f48(self->w[8], 3, 3);
    self->w[8]->vt->f38(self->w[8], 0.75f, 1.0f);
    self->w[8]->vt->fB8(self->w[8], func_0037DF98(D_001DDFF8_sda[self->fBB0]));
    self->w[12]->vt->f4C(self->w[12], 0x40, 1);
    self->w[12]->vt->f48(self->w[12], 3, 3);
    self->w[12]->vt->f38(self->w[12], 0.75f, 1.0f);
    self->w[14]->vt->f4C(self->w[14], 0x40, 1);
    self->w[14]->vt->f48(self->w[14], 1, 3);
    self->w[14]->vt->f38(self->w[14], 0.8f, 1.0f);
    self->w[13]->vt->f4C(self->w[13], 0x40, 1);
    self->w[13]->vt->f48(self->w[13], 1, 3);
    self->w[13]->vt->f38(self->w[13], 0.8f, 1.0f);
    self->w[14]->vt->f50(self->w[14], D_001DDEDC_sda);
    self->w[13]->vt->f50(self->w[13], D_001DDEDC_sda);
    self->w[11]->vt->f48(self->w[11], 3, 3);
    self->w[11]->vt->f4C(self->w[11], 0x40, 1);

    for (i = 15; i < 35; i++) {
        self->w[i]->vt->f4C(self->w[i], 0x40, 1);
        self->w[i]->vt->f1C(self->w[i], 1, 0);
        self->w[i]->vt->f40(self->w[i], 1);
        if (i >= 25) {
            self->w[i]->vt->f48(self->w[i], 2, 3);
            self->w[i]->vt->f44(self->w[i], 1, 0.1f, 0.0f);
        } else {
            self->w[i]->vt->f48(self->w[i], 1, 3);
            self->w[i]->vt->f44(self->w[i], 1, 0.27f, 0.0f);
        }
    }

    strs[0] = (u8 *)func_0037DF98(0x1341);
    a = func_0037DF98(0x1341);
    func_L39_005945F0(D_001E1AD0_sda, a, func_00120884(func_0037DF98(0x1341)));
    strs[0] = D_001E1AD0_sda;

    self->w[7]->vt->f68(self->w[7]);
    self->w[7]->vt->f84(self->w[7], 1);
    self->w[7]->vt->f4C(self->w[7], 0x40, 1);
    self->w[7]->vt->f90(self->w[7], D_001DDEE0_sda + D_001DDEE4_sda);
    self->w[7]->vt->f38(self->w[7], 0.53f, 0.9f);
    self->w[7]->vt->f94(self->w[7], 0.7f);
    self->w[7]->vt->f40(self->w[7], 1);

    func_L39_006C3ED0(self, 0);
    func_L39_006C5238(self, 0, 1, strs);
    func_L39_006C5320(self, 1);
    if (self->fB61) {
        func_L39_006C4040(self, 1, self->fB60);
        func_L39_006C5150(self, self->fB68);
    } else {
        self->fD48 = 0;
        self->fBB4 = 0;
        func_L39_006C4040(self, 0, 0);
        func_L39_00688750(self, 0, 0);
        self->fBAC = 0x7FFFFFFF;
        self->fBA8 = 1;
        self->fB60 = 0;
        self->fBB0 = 0;
        self->fB68 = 0;
    }
    func_L39_006C3050(self);
}
/* localdecomp:end func_L39_006C2A28 */

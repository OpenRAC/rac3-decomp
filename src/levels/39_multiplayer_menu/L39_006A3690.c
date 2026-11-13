#include "common.h"

/* declared by functions of L39_006A29D0.c, which this file was cut from */
extern void *func_00381FF0(s32);

/* localdecomp:start func_L39_006A3690 */
typedef struct S_006A3690_VT {
    u8 pad0[0x1C];
    void (*f1C)(void *, s32, s32);
    u8 pad20[0xC];
    void (*f2C)(void *, f32, f32);
    u8 pad30[0x14];
    void (*f44)(void *, f32, f32, s32);
    u8 pad48[0x4C];
    void (*f94)(void *, f32);
    u8 pad98[0x4C];
    void (*fE4)(void *, f32);
} S_006A3690_VT;
typedef struct S_006A3690_W { u8 pad[0x60]; S_006A3690_VT *vt; } S_006A3690_W;
typedef struct S_006A3690_Obj {
    u8 pad0[0x110];
    S_006A3690_W *w[21];
    S_006A3690_W *panel;
    u8 pad168[0x2C8 - 0x168];
    s32 sel;
    u8 pad2CC[0x318 - 0x2CC];
    u8 buf[8];
} S_006A3690_Obj;

__asm__(".extern D_L39_002486A4, 16");
extern f32 D_L39_002486A4;
__asm__(".extern D_L39_002486A8, 16");
extern f32 D_L39_002486A8;
__asm__(".extern D_L39_002486AC, 16");
extern f32 D_L39_002486AC;
__asm__(".extern D_L39_002486C4, 16");
extern f32 D_L39_002486C4;
__asm__(".extern D_L39_002486C8, 16");
extern f32 D_L39_002486C8;
__asm__(".extern D_L39_002486CC, 16");
extern f32 D_L39_002486CC;
__asm__(".extern D_L39_002486E4, 16");
extern f32 D_L39_002486E4;
__asm__(".extern D_L39_002486E8, 16");
extern f32 D_L39_002486E8;
__asm__(".extern D_L39_002486EC, 16");
extern f32 D_L39_002486EC;
__asm__(".extern D_L39_002486F0, 16");
extern f32 D_L39_002486F0;
__asm__(".extern D_L39_00248704, 16");
extern f32 D_L39_00248704;
__asm__(".extern D_L39_00248708, 16");
extern f32 D_L39_00248708;
__asm__(".extern D_L39_0024870C, 16");
extern f32 D_L39_0024870C;
__asm__(".extern D_L39_00248724, 16");
extern f32 D_L39_00248724;
__asm__(".extern D_L39_00248728, 16");
extern f32 D_L39_00248728;
__asm__(".extern D_L39_0024872C, 16");
extern f32 D_L39_0024872C;
__asm__(".extern D_L39_00248730, 16");
extern f32 D_L39_00248730;
__asm__(".extern D_L39_0024873C, 16");
extern f32 D_L39_0024873C;
__asm__(".extern D_L39_00248740, 16");
extern f32 D_L39_00248740;
__asm__(".extern D_L39_00248744, 16");
extern f32 D_L39_00248744;
__asm__(".extern D_L39_00248748, 16");
extern f32 D_L39_00248748;
__asm__(".extern D_L39_00248754, 16");
extern f32 D_L39_00248754;
__asm__(".extern D_L39_00248758, 16");
extern f32 D_L39_00248758;
__asm__(".extern D_L39_0024875C, 16");
extern f32 D_L39_0024875C;
__asm__(".extern D_001DCF90_sda, 4");
extern f32 D_001DCF90_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DCFB0_sda, 4");
extern f32 D_001DCFB0_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DCFD0_sda, 4");
extern f32 D_001DCFD0_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DCFE4_sda, 4");
extern f32 D_001DCFE4_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DCFF0_sda, 4");
extern f32 D_001DCFF0_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DD010_sda, 4");
extern f32 D_001DD010_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DD028_sda, 4");
extern f32 D_001DD028_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DD040_sda, 4");
extern f32 D_001DD040_sda __attribute__((section(".sdata")));
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern void *func_00381FF0(s32);
extern void func_L39_00689BD8(void *, void *);
extern void func_L39_00689D28(void *, void *);
extern void func_L39_00689DB8(void *, void *);
extern void func_L39_00689B80(void *);
extern void *func_0011D534(void *, s32, s32);
extern void func_L39_006A4510(void *, s32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_0068A6D0(void *, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068A4A8(void *, s32, s32, u32, f32, f32, f32, f32);
extern void func_L39_006A4CB8(void *);

void func_L39_006A3690(S_006A3690_Obj *self) {
    s32 i;
    s32 j;

    self->panel->vt->fE4(self->panel, 0.4f);
    self->panel->vt->f94(self->panel, 0.9f);
    for (i = 0; i < 24; i++) {
        self->w[i]->vt->f1C(self->w[i], 2, 0);
    }
    for (i = 5; i < 13; i++) {
        self->w[i]->vt->f2C(self->w[i], 0.0f, 0.0f);
    }
    for (i = 0; i < 4; i++) {
        j = i + 1;
        self->w[j]->vt->f2C(self->w[j], 0.0f, 0.0f);
    }
    func_L39_0067F100(0x310000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(self, func_00381FF0(0xFF0));
    func_L39_00689D28(self, func_00381FF0(0x124));
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_00689B80(self);
    self->sel = -1;
    func_0011D534(self->buf, 0, 8);
    func_L39_006A4510(self, 1);
    func_L39_0068AAB8(self);
    for (i = 13; i < 19; i++) {
        self->w[i]->vt->f44(self->w[i], D_L39_002486C8 - 0.02f, 0.0f, 1);
    }
    func_L39_0068A6D0(self, 0, 0x332299DE, D_001DCF90_sda, D_L39_002486A4, D_L39_002486A8, D_L39_002486AC);
    func_L39_0068A6D0(self, 1, 0x332299DE, D_001DCFB0_sda, D_L39_002486C4, D_L39_002486C8, D_L39_002486CC);
    func_L39_0068A4A8(self, 1, D_001DCFD0_sda, 0x332299DE, D_L39_002486E4, D_L39_002486E8, D_L39_002486EC, D_L39_002486F0);
    func_L39_0068A4A8(self, 2, 1, 0x332299DE, D_L39_002486E4, D_001DCFE4_sda, D_L39_002486EC, D_L39_002486F0);
    func_L39_0068A6D0(self, 2, 0x332299DE, D_001DCFF0_sda, D_L39_00248704, D_L39_00248708, D_L39_0024870C);
    func_L39_0068A4A8(self, 3, D_001DD010_sda, 0x192299DE, D_L39_00248724, D_L39_00248728, D_L39_0024872C, D_L39_00248730);
    func_L39_0068A4A8(self, 4, 1, 0x332299DE, D_L39_00248724, 0.3575f, D_L39_0024872C, D_L39_00248730);
    func_L39_0068A6D0(self, 3, 0x332299DE, D_001DD040_sda, D_L39_00248754, D_L39_00248758, D_L39_0024875C);
    func_L39_0068A4A8(self, 5, D_001DD028_sda, 0x332299DE, D_L39_0024873C, D_L39_00248740, D_L39_00248744, D_L39_00248748);
    func_L39_006A4CB8(self);
}
/* localdecomp:end func_L39_006A3690 */

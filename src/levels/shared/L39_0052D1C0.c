#include "common.h"

/* localdecomp:start func_L39_0052D1C0 */
#include "vu0.h"

typedef struct Obj_0052D1C0 {
    u8 pad0[0x30];
    u8 b30[1];
    u8 pad31[0xD0 - 0x31];
    u8 bD0[1];
    u8 padD1[0x138 - 0xD1];
    f32 f138;
    u8 pad13C[0x150 - 0x13C];
    u8 b150[1];
    u8 pad151[0x1B8 - 0x151];
    f32 f1B8;
    u8 pad1BC[0x1D0 - 0x1BC];
    f32 f1D0;
    f32 f1D4;
    u8 pad1D8[0x1E0 - 0x1D8];
    f32 f1E0;
    u8 pad1E4[0x1F4 - 0x1E4];
    s32 w1F4;
    u8 pad1F8[0x240 - 0x1F8];
    f32 f240;
    u8 pad244[0x260 - 0x244];
    f32 f260;
} Obj_0052D1C0;

typedef struct Slot_0052D1C0 {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    void *wDC;
} Slot_0052D1C0;

typedef struct Self_0052D1C0 {
    u8 pad0[0x10];
    vu0_q q10;
    u8 pad20[0x68 - 0x20];
    Obj_0052D1C0 *p68;
    u8 pad6C[0xF0 - 0x6C];
    vu0_q qF0;
    f32 fF8_;
} Self_0052D1C0;

extern u8 D_001FE020[];
extern u8 D_L39_00242930[8];
__asm__(".extern D_L39_00242930, 16");
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005F3088(s32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L39_0052D1C0(Self_0052D1C0 *self) {
    Obj_0052D1C0 *o;
    struct {
        vu0_q a;
        vu0_q b;
        vu0_q c;
    } L;

    L.b = self->qF0;
    L.a = self->q10;
    o = self->p68;
    *(f32 *)((u8 *)self + 0xF8) = o->f240;
    o->f1E0 = o->f260;
    o->f138 = o->f260;
    o->f1B8 = o->f260;
    func_L01_0044E850(self, o->bD0, 2, 1.0f, 0.0f);
    func_L01_0044E850(self, o->b150, 3, 1.0f, 0.0f);
    if (fabs_asm(o->f1D0) > 0.0f || fabs_asm(o->f1D4) > 0.0f) {
        s32 idx = o->w1F4;
        if (idx == -1 || ((Slot_0052D1C0 *)(D_001FE020 + (idx << 7)))->wDC != self || ((Slot_0052D1C0 *)(D_001FE020 + (idx << 7)))->bD0 == 0) {
            o->w1F4 = func_L39_005F33E0(4, 4, self);
        }
    } else {
        s32 idx2 = o->w1F4;
        if (idx2 != -1 && ((Slot_0052D1C0 *)(D_001FE020 + (idx2 << 7)))->wDC == self && ((Slot_0052D1C0 *)(D_001FE020 + (idx2 << 7)))->bD0 != 0) {
            func_L39_005F3088(idx2);
        }
        o->w1F4 = -1;
    }
    vec_sub_ba(&L.c, &self->q10, &L.a);
    func_003C4DA8(o->b30, D_L39_00242930, &L.b, &self->qF0);
}
/* localdecomp:end func_L39_0052D1C0 */

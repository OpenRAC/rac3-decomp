#include "common.h"
#include "vu0.h"

typedef int Quad_3543C8 __attribute__((mode(TI)));
typedef struct Obj_3543C8 {
    u8 pad0[0x10];
    Quad_3543C8 pos;
    u8 pad20[4];
    u8 *def;
    u8 pad28[0xC];
    u16 flags;
    u8 pad36[0x32];
    u8 *vars;
    u8 pad6C[0x2A];
    u16 timer;
    s32 w98;
    u8 pad9C[0xC];
    u8 alpha;
    u8 padA9[0x13];
    u8 state;
    u8 padBD[0x33];
    Quad_3543C8 pos2;
} Obj_3543C8;
typedef struct Vars_3543C8 {
    u8 pad0[0x30];
    f32 hp;
    s16 maxhp;
    s16 hurt;
    u8 pad38[0x48];
    s32 w80;
    u8 pad84[0x2FE];
    u8 b382;
    u8 pad383[0x7D];
    Quad_3543C8 q400;
    Quad_3543C8 q410;
} Vars_3543C8;

/* localdecomp:start func_L18_00350FB0 */
typedef int Quad_00350FB0 __attribute__((mode(TI)));
typedef union QF_00350FB0 {
    Quad_00350FB0 q;
    f32 f[4];
} QF_00350FB0;
typedef struct Obj_00350FB0 {
    u8 pad00[0x10];
    Quad_00350FB0 q10;
    u8 pad20[0x68 - 0x20];
    u8 *vars;
    u8 pad6C[0xF0 - 0x6C];
    Quad_00350FB0 qF0;
} Obj_00350FB0;
typedef struct G_00350FB0 {
    u8 pad00[0x80];
    Quad_00350FB0 q80;
    Quad_00350FB0 q90;
    u8 padA0[0x30];
    QF_00350FB0 qD0;
    u8 padE0[0x110 - 0xE0];
    Quad_00350FB0 q110;
    u8 pad120[0x25C0 - 0x120];
    Obj_00350FB0 *x25C0;
    u8 pad25C4[0x25E5 - 0x25C4];
    u8 b25E5;
} G_00350FB0;

extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00430118(void *);
extern G_00350FB0 D_001A4BE0_00350FB0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");

void func_L18_00350FB0(Obj_00350FB0 *self) {
    Quad_00350FB0 *p = &D_001A4BE0_00350FB0.q110;
    Quad_00350FB0 *q;

    *p = *(Quad_00350FB0 *)(self->vars + 0x290);
    func_003C2F58(self, 8, (u8 *)D_001A4BE0_00350FB0.x25C0 + 0x10);
    q = &D_001A4BE0_00350FB0.q80;
    *q = D_001A4BE0_00350FB0.x25C0->q10;
    *(Quad_00350FB0 *)((u8 *)D_001A4BE0_00350FB0.x25C0 + 0xF0) = self->qF0;
    D_001A4BE0_00350FB0.q90 = D_001A4BE0_00350FB0.x25C0->qF0;
    D_001A4BE0_00350FB0.b25E5 = 1;
    D_001A4BE0_00350FB0.qD0.q = self->q10;
    D_001A4BE0_00350FB0.qD0.f[2] += 0.5f;
    if (D_001D545C == 0x1A) {
        func_L01_00430118(q);
    }
}
/* localdecomp:end func_L18_00350FB0 */

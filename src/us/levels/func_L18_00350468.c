#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L18_00351068 (src/levels/shared/L18_00351068.c): f108 = 1/6 (PAL 0.2f = 1/6 * 1.2) */
/* localdecomp:start func_L18_00350468 */
typedef int Quad_00350468 __attribute__((mode(TI)));
typedef union QF_00350468 {
    Quad_00350468 q;
    f32 f[4];
} QF_00350468;
typedef struct Obj_00350468 {
    u8 pad00[0x10];
    QF_00350468 pos;
    u8 pad20[4];
    u8 *def;
    u8 pad28[0x68 - 0x28];
    u8 *vars;
    u8 pad6C[0x98 - 0x6C];
    s32 w98;
    s32 w9C;
} Obj_00350468;
typedef struct G_00350468 {
    u8 pad00[0x80];
    QF_00350468 q80;
    u8 pad90[0x108 - 0x90];
    f32 f108;
    u8 pad10C[0x19E0 - 0x10C];
    s32 w19E0;
    s16 h19E4;
    u8 pad19E6[0x25C0 - 0x19E6];
    Obj_00350468 *x25C0;
    s32 x25C4;
    u8 pad25C8[0x25E5 - 0x25C8];
    u8 b25E5;
} G_00350468;
typedef struct H_00350468 {
    s32 w0;
    void (*f4)(void);
    void (*f8)(void);
} H_00350468;

extern G_00350468 D_001A4BE0;
extern Quad_00350468 D_L18_001E2AE0;
extern Quad_00350468 D_L18_001EAB20;
extern s32 D_001D545C;
extern void func_L01_004FC518(s32, s32);
extern void func_00388830(void *, void *, f32);
extern H_00350468 *func_L01_00438488(s32, s32, s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern void func_L01_003F3918(s32, s32);

void func_L18_00350468(Obj_00350468 *self) {
    u8 *vars = self->vars;
    H_00350468 *h;
    QF_00350468 v;
    QF_00350468 *q;

    vars[0x382] = 1;
    D_001A4BE0.b25E5 = 0;
    if (D_001A4BE0.x25C4 == 0x31) {
        func_L01_004FC518(0, 1);
    }
    D_001A4BE0.h19E4 = -1;
    v.q = D_L18_001E2AE0;
    D_001A4BE0.f108 = 0.16666667f;
    v.f[2] = 0.0f;
    D_001A4BE0.w19E0 = 0;
    func_00388830(&v, &v, 2.5f);
    v.f[2] = 0.7f;
    vec_add_ab(&v, &self->pos, &v);
    self->w98 = 0;
    h = func_L01_00438488(0x1E6F, 0, 0xC);
    if (h != 0) {
        h->f4();
    }
    if (func_003CE740(&D_001A4BE0.q80, &v, 2, D_001A4BE0.x25C0, 0) != 0) {
        v.q = D_L18_001EAB20;
        if (func_L01_003F9498(&v, 2, D_001A4BE0.x25C0, 0.4f) != 0) {
            v.q = D_L18_001EAB20;
        }
    }
    q = &D_001A4BE0.q80;
    q->q = v.q;
    if (D_001D545C == 0xB || D_001D545C == 0x44C) {
        D_001A4BE0.q80.f[0] = 524.33f;
        D_001A4BE0.q80.f[1] = 151.41f;
        D_001A4BE0.q80.f[2] = 825.34f;
        self->pos.f[0] = 522.42f;
        self->pos.f[1] = 151.61f;
        self->pos.f[2] = 828.06f;
        *(Quad_00350468 *)(vars + 0x420) = self->pos.q;
        func_L01_003F3918(0, 1);
    }
    self->w98 = *(s32 *)(self->def + 0x10);
    D_001A4BE0.x25C0->w9C = 0;
    if (h != 0) {
        h->f8();
    }
}
/* localdecomp:end func_L18_00350468 */

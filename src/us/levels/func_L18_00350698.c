#include "common.h"

/* NTSC-U counterpart of func_L18_00351298 (src/levels/shared/L18_00351068.c): 60 Hz value (1/6 against 0.2f at +0x108) */
/* localdecomp:start func_L18_00350698 */
#include "vu0.h"

typedef int Quad_00350698 __attribute__((mode(TI)));
typedef struct H_00350698 {
    s32 w0;
    void (*f4)(void);
    void (*f8)(void);
} H_00350698;
extern s32 D_001D545C;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00351298;
typedef struct {
    u8 pad0[0x10];
    V4_00351298 pos;
    u8 pad20[4];
    u8 *def;
    u8 pad28[0x40];
    u8 *vars;
    u8 pad6C[0x2C];
    s32 w98;
    s32 w9C;
} O_00351298;
typedef struct {
    u8 pad0[0x80];
    V4_00351298 q80;
    u8 pad90[0x108 - 0x90];
    f32 f108;
    u8 pad10C[0x19E0 - 0x10C];
    s32 w19E0;
    s16 h19E4;
    u8 pad19E6[0x25C0 - 0x19E6];
    O_00351298 *x25C0;
    u8 pad25C4[0x25E5 - 0x25C4];
    u8 b25E5;
} G_00351298;
extern G_00351298 D_001A4BE0_00350698;
extern Quad_00350698 D_L18_001E2AE0;
extern Quad_00350698 D_L18_001EAB20;
extern void func_L01_004FC518(s32, s32);
extern void func_00388830(void *, void *, f32);
extern H_00350698 *func_L01_00438488(s32, s32, s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern void func_L01_003F3918(s32, s32);

void func_L18_00350698(O_00351298 *self) {
    u8 *vars;
    V4_00351298 t;
    void (**prof)(void);

    vars = self->vars;
    vars[0x382] = 1;
    D_001A4BE0_00350698.b25E5 = 0;
    ((s32 (*)(s32, s32))func_L01_004FC518)(0, 1);
    t = *(V4_00351298 *)&D_L18_001E2AE0;
    D_001A4BE0_00350698.h19E4 = -1;
    D_001A4BE0_00350698.f108 = 0.16666667f;
    t.z = 0.0f;
    D_001A4BE0_00350698.w19E0 = 0;
    func_00388830(&t, &t, 2.5f);
    t.z = 0.7f;
    vec_add_ab(&t, &self->pos, &t);
    self->w98 = 0;
    prof = (void (**)(void))func_L01_00438488(0x1E6F, 0, 0xC);
    if (prof != 0) {
        prof[1]();
    }
    if (func_003CE740(&D_001A4BE0_00350698.q80, &t, 2, D_001A4BE0_00350698.x25C0, 0) != 0) {
        t = *(V4_00351298 *)&D_L18_001EAB20;
        if (func_L01_003F9498(&t, 2, (u8 *)D_001A4BE0_00350698.x25C0, 0.4f) != 0) {
            t = *(V4_00351298 *)&D_L18_001EAB20;
        }
    }
    { V4_00351298 *q = &D_001A4BE0_00350698.q80; *q = t; }
    if (D_001D545C == 0xB || D_001D545C == 0x44C) {
        D_001A4BE0_00350698.q80.x = 152.18f;
        D_001A4BE0_00350698.q80.y = 395.98f;
        D_001A4BE0_00350698.q80.z = 227.5f;
        self->pos.x = 149.16f;
        self->pos.y = 394.52f;
        self->pos.z = 220.35f;
        *(V4_00351298 *)(vars + 0x420) = self->pos;
        func_L01_003F3918(0, 1);
    }
    self->w98 = *(s32 *)(self->def + 0x10);
    D_001A4BE0_00350698.x25C0->w9C = 0;
    if (prof != 0) {
        prof[2]();
    }
}
/* localdecomp:end func_L18_00350698 */

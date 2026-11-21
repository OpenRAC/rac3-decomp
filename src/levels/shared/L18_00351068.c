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

/* declared by functions of L18_00350FB0.c, which this file was cut from */
extern s32 D_001D545C;

/* localdecomp:start func_L18_00351068 */
typedef int Quad_00351068 __attribute__((mode(TI)));
typedef union QF_00351068 {
    Quad_00351068 q;
    f32 f[4];
} QF_00351068;
typedef struct Obj_00351068 {
    u8 pad00[0x10];
    QF_00351068 pos;
    u8 pad20[4];
    u8 *def;
    u8 pad28[0x68 - 0x28];
    u8 *vars;
    u8 pad6C[0x98 - 0x6C];
    s32 w98;
    s32 w9C;
} Obj_00351068;
typedef struct G_00351068 {
    u8 pad00[0x80];
    QF_00351068 q80;
    u8 pad90[0x108 - 0x90];
    f32 f108;
    u8 pad10C[0x19E0 - 0x10C];
    s32 w19E0;
    s16 h19E4;
    u8 pad19E6[0x25C0 - 0x19E6];
    Obj_00351068 *x25C0;
    s32 x25C4;
    u8 pad25C8[0x25E5 - 0x25C8];
    u8 b25E5;
} G_00351068;
typedef struct H_00351068 {
    s32 w0;
    void (*f4)(void);
    void (*f8)(void);
} H_00351068;

extern G_00351068 D_001A4BE0_00351068;
extern Quad_00351068 D_L18_001E2A60;
extern Quad_00351068 D_L18_001EAAA0;
extern s32 D_001D545C;
extern void func_L01_005003D0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern H_00351068 *func_L01_0043B568(s32, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_003F5AC0(s32, s32);

void func_L18_00351068(Obj_00351068 *self) {
    u8 *vars = self->vars;
    H_00351068 *h;
    QF_00351068 v;
    QF_00351068 *q;

    vars[0x382] = 1;
    D_001A4BE0_00351068.b25E5 = 0;
    if (D_001A4BE0_00351068.x25C4 == 0x31) {
        func_L01_005003D0(0, 1);
    }
    D_001A4BE0_00351068.h19E4 = -1;
    v.q = D_L18_001E2A60;
    D_001A4BE0_00351068.f108 = 0.20000002f;
    v.f[2] = 0.0f;
    D_001A4BE0_00351068.w19E0 = 0;
    func_0038CF68(&v, &v, 2.5f);
    v.f[2] = 0.7f;
    vec_add_ab(&v, &self->pos, &v);
    self->w98 = 0;
    h = func_L01_0043B568(0x1E6F, 0, 0xC);
    if (h != 0) {
        h->f4();
    }
    if (func_003D3CB0(&D_001A4BE0_00351068.q80, &v, 2, D_001A4BE0_00351068.x25C0, 0) != 0) {
        v.q = D_L18_001EAAA0;
        if (func_L01_003FB640(&v, 2, D_001A4BE0_00351068.x25C0, 0.4f) != 0) {
            v.q = D_L18_001EAAA0;
        }
    }
    q = &D_001A4BE0_00351068.q80;
    q->q = v.q;
    if (D_001D545C == 0xB || D_001D545C == 0x44C) {
        D_001A4BE0_00351068.q80.f[0] = 524.33f;
        D_001A4BE0_00351068.q80.f[1] = 151.41f;
        D_001A4BE0_00351068.q80.f[2] = 825.34f;
        self->pos.f[0] = 522.42f;
        self->pos.f[1] = 151.61f;
        self->pos.f[2] = 828.06f;
        *(Quad_00351068 *)(vars + 0x420) = self->pos.q;
        func_L01_003F5AC0(0, 1);
    }
    self->w98 = *(s32 *)(self->def + 0x10);
    D_001A4BE0_00351068.x25C0->w9C = 0;
    if (h != 0) {
        h->f8();
    }
}
/* localdecomp:end func_L18_00351068 */

/* localdecomp:start func_L18_00351298 */
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
extern G_00351298 D_001A4BE0_00351298;
extern Quad_00351068 D_L18_001E2A60;
extern Quad_00351068 D_L18_001EAAA0;
extern void func_L01_005003D0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern H_00351068 *func_L01_0043B568(s32, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_003F5AC0(s32, s32);

void func_L18_00351298(O_00351298 *self) {
    u8 *vars;
    V4_00351298 t;
    void (**prof)(void);

    vars = self->vars;
    vars[0x382] = 1;
    D_001A4BE0_00351298.b25E5 = 0;
    ((s32 (*)(s32, s32))func_L01_005003D0)(0, 1);
    t = *(V4_00351298 *)&D_L18_001E2A60;
    D_001A4BE0_00351298.h19E4 = -1;
    D_001A4BE0_00351298.f108 = 0.20000002f;
    t.z = 0.0f;
    D_001A4BE0_00351298.w19E0 = 0;
    func_0038CF68(&t, &t, 2.5f);
    t.z = 0.7f;
    vec_add_ab(&t, &self->pos, &t);
    self->w98 = 0;
    prof = (void (**)(void))func_L01_0043B568(0x1E6F, 0, 0xC);
    if (prof != 0) {
        prof[1]();
    }
    if (func_003D3CB0(&D_001A4BE0_00351298.q80, &t, 2, D_001A4BE0_00351298.x25C0, 0) != 0) {
        t = *(V4_00351298 *)&D_L18_001EAAA0;
        if (func_L01_003FB640(&t, 2, (u8 *)D_001A4BE0_00351298.x25C0, 0.4f) != 0) {
            t = *(V4_00351298 *)&D_L18_001EAAA0;
        }
    }
    { V4_00351298 *q = &D_001A4BE0_00351298.q80; *q = t; }
    if (D_001D545C == 0xB || D_001D545C == 0x44C) {
        D_001A4BE0_00351298.q80.x = 152.18f;
        D_001A4BE0_00351298.q80.y = 395.98f;
        D_001A4BE0_00351298.q80.z = 227.5f;
        self->pos.x = 149.16f;
        self->pos.y = 394.52f;
        self->pos.z = 220.35f;
        *(V4_00351298 *)(vars + 0x420) = self->pos;
        func_L01_003F5AC0(0, 1);
    }
    self->w98 = *(s32 *)(self->def + 0x10);
    D_001A4BE0_00351298.x25C0->w9C = 0;
    if (prof != 0) {
        prof[2]();
    }
}
/* localdecomp:end func_L18_00351298 */

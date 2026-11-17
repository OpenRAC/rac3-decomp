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

/* localdecomp:start func_L18_00353138 */
typedef int Q_00353138 __attribute__((mode(TI)));

typedef struct G_00353138 {
    u8 pad0[0x19E0];
    void *x19E0;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 x25C4;
} G_00353138;

extern G_00353138 D_001A4BE0_00353138;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
extern void func_L18_004614F8(void *, void *, void *, f32, f32, f32);

void func_L18_00353138(void *arg0) {
    u8 *a0 = arg0;
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 t;
    f32 w;

    t = func_0038DAB8(*(f32 *)(s + 0x358), 0.024434611f);
    *(f32 *)(s + 0x358) = t;
    w = func_0038D0B0(t) * 0.02f;
    *(f32 *)(s + 0x35C) = w;
    if (*(s32 *)(s + 0x3BC) != 0) {
        *(f32 *)(a0 + 0x18) = *(f32 *)(s + 0x368) + w;
        *(Q_00353138 *)v = *(Q_00353138 *)(a0 + 0xF0);
        func_L01_0044EBA0(a0, s + 0x360, s + 0x364, 0.02617994f, 0.009773845f, 0.04468043f);
        if (D_001A4BE0_00353138.x25C4 == 0x31 && D_001A4BE0_00353138.x19E0 == a0) {
            *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), v[0]);
            *(f32 *)(a0 + 0xF4) = func_0038DAB8(*(f32 *)(a0 + 0xF4), v[1]);
        }
    } else {
        func_0038CE20(v, s + 0x3C0, w);
        vec_add_ab(a0 + 0x10, s + 0x420, v);
        func_L18_004614F8(a0, s + 0x360, s + 0x364, 0.02617994f, 0.009773845f, 0.04468043f);
    }
}
/* localdecomp:end func_L18_00353138 */

INCLUDE_ASM("asm/levels", func_L18_00353280);

INCLUDE_ASM("asm/levels", func_L18_00353658);

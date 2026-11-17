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

/* localdecomp:start func_L18_003514B8 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
void func_L18_003514B8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);
    *(u128_t *)(s + 752) = *(u128_t *)(s + 960);
    func_0038CE90(s + 736, s + 752, s + 720);
    func_0038CF68(s + 736, s + 736, 1.0f);
    func_0038CE90(s + 720, s + 736, s + 752);
    *(s32 *)(s + 732) = 0;
    *(s32 *)(s + 748) = 0;
    *(s32 *)(s + 764) = 0;
}
/* localdecomp:end func_L18_003514B8 */

INCLUDE_ASM("asm/levels", func_L18_00351548);

INCLUDE_ASM("asm/levels", func_L18_00351908);

/* localdecomp:start func_L18_00352288 */
typedef struct G_352288 {
    u8 pad0[0x19E0];
    void *x19E0;
    u8 pad19E4[0xBE0];
    s32 x25C4;
} G_352288;

extern void func_L18_00351908(void *);
extern G_352288 D_001A4BE0;

void func_L18_00352288(void *arg0) {
    u8 *v = *(u8 **)((u8 *)arg0 + 0x68);

    *(f32 *)(v + 0x290) = *(f32 *)(v + 0x290) - *(f32 *)(v + 0x290) * 0.060000002f;
    if (fabs_asm(*(f32 *)(v + 0x290)) < 0.001f) {
        *(f32 *)(v + 0x290) = 0.0f;
    }
    *(f32 *)(v + 0x294) = *(f32 *)(v + 0x294) - *(f32 *)(v + 0x294) * 0.060000002f;
    if (fabs_asm(*(f32 *)(v + 0x294)) < 0.001f) {
        *(f32 *)(v + 0x294) = 0.0f;
    }
    *(f32 *)(v + 0x298) -= 0.00392f;
    if (D_001A4BE0.x25C4 != 0x31 || D_001A4BE0.x19E0 != arg0) {
        *(f32 *)(v + 0x298) -= 0.00392f;
    }
    func_L18_00351908(arg0);
}
/* localdecomp:end func_L18_00352288 */

INCLUDE_ASM("asm/levels", func_L18_00352350);

INCLUDE_ASM("asm/levels", func_L18_00352AF8);

INCLUDE_ASM("asm/levels", func_L18_00352D30);

/* localdecomp:start func_L18_00353110 */
void func_L18_00353110(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (*(s32 *)(s + 0x3BC) != 0) {
        *(f32 *)(a0 + 0x18) = *(f32 *)(s + 0x368);
    } else {
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(s + 0x420);
    }
}
/* localdecomp:end func_L18_00353110 */

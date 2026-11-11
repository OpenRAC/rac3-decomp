#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;


INCLUDE_ASM("asm/levels", func_L01_00311430);

/* localdecomp:start func_L01_003119D8 */
extern s32 D_L01_001DC6A8_003119D8;

void func_L01_003119D8(void) { D_L01_001DC6A8_003119D8 = 0; }
/* localdecomp:end func_L01_003119D8 */

/* localdecomp:start func_L01_003119E0 */
extern s32 D_L01_001E1730[];
extern s32 D_L01_001DC6A8;

void func_L01_003119E0(void) {
    D_L01_001E1730[0] = 0;
    D_L01_001DC6A8 = 0;
}
/* localdecomp:end func_L01_003119E0 */

INCLUDE_ASM("asm/levels", func_L01_003119F0);

INCLUDE_ASM("asm/levels", func_L01_00311C60);

/* localdecomp:start func_L01_00311D08 */



extern s32 func_L01_00457458(s32 a0, s32 a1);
extern void func_L01_003119E0();
extern void func_003C2880(S_311A18 *a0);
extern s32 func_0038DC20(s128 *a0, f32 f12);
extern void func_L01_00311DE8(S_311A18 *a0);
extern void func_L01_00312030_00311D08(S_311A18 *a0);
extern void func_L01_00311C60(S_311A18 *a0);
extern void func_L01_00312270(S_311A18 *a0);
extern void func_L01_003126C8(S_311A18 *a0);
extern void func_L01_00312D70(S_311A18 *a0);

void func_L01_00311D08(S_311A18 *o) {
    S_311A18m *m;
    s128 v;

    m = o->p68;
    if (o == 0) {
        return;
    }
    if (o->b20 == 254) {
        return;
    }
    if (o->b20 == 253) {
        return;
    }
    if (m == 0) {
        return;
    }
    if (func_L01_00457458(o->hAA, m->w28) == 0) {
        func_L01_003119E0();
        func_003C2880(o);
        return;
    }
    v = o->q10;
    ((f32 *)&v)[3] = 2.0f;
    if (func_0038DC20(&v, 100.0f) == -1) {
        return;
    }
    if (o->b20 != 6) {
        func_L01_00311DE8(o);
        func_L01_00312030_00311D08(o);
        func_L01_00311C60(o);
    }
    func_L01_00312270(o);
    func_L01_003126C8(o);
    func_L01_00312D70(o);
}
/* localdecomp:end func_L01_00311D08 */

INCLUDE_ASM("asm/levels", func_L01_00311DE8);

INCLUDE_ASM("asm/levels", func_L01_00312030);

INCLUDE_ASM("asm/levels", func_L01_00312270);

INCLUDE_ASM("asm/levels", func_L01_003126C8);

INCLUDE_ASM("asm/levels", func_L01_00312B60);

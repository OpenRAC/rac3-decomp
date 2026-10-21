#include "common.h"

typedef struct Obj_004CE458 Obj_004CE458;
typedef struct {
    u8 pad[8];
    void (*fn8)(Obj_004CE458 *);
} Vt_004CE458;
struct Obj_004CE458 {
    u8 pad[36];
    Vt_004CE458 *vt;
    u8 pad2[20];
};

INCLUDE_ASM("asm/levels", func_L01_004D2110);

/* localdecomp:start func_L01_004D2118 */

extern f32 *func_L01_004CC748_004D2118(Obj_004CE458 *);
extern void func_L01_004CCE00(Obj_004CE458 *, s32, s32);
extern void func_L01_004CCE40(Obj_004CE458 *, s32, s32);
extern void func_L01_004CD640(Obj_004CE458 *, s32);

void func_L01_004D2118(Obj_004CE458 (*base)[26], s32 i, s32 j, s32 x, s32 y, s32 z) {
    Obj_004CE458 *o = &base[i][j];

    func_L01_004CC748_004D2118(o)[0] = x;
    func_L01_004CC748_004D2118(o)[1] = y;
    func_L01_004CCE00(o, z, z);
    func_L01_004CCE40(o, z, z);
    func_L01_004CD640(o, z << 24);
    o->vt->fn8(o);
}
/* localdecomp:end func_L01_004D2118 */

INCLUDE_ASM("asm/levels", func_L01_004D21E0);

/* localdecomp:start func_L01_004D23E8 */
extern void func_L01_004D2470(void *p, s32 i);
extern s32 D_001D545C[];
extern void func_L01_004D0E90(u8 *, s32);
extern void func_003ACBC0(u8 *);

void func_L01_004D23E8(u8 *m) {
    s32 i;

    if (D_001D545C[0] != -2) {
        for (i = 0; i < 1; i++) {
            func_L01_004D0E90(m + 6304 + i * 2896, i);
            ((void (*)(u8 *, s32))func_L01_004D2470)(m, i);
        }
        func_003ACBC0(m + 20176);
    }
}
/* localdecomp:end func_L01_004D23E8 */

INCLUDE_ASM("asm/levels", func_L01_004D2470);

INCLUDE_ASM("asm/levels", func_L01_004D2498);

INCLUDE_ASM("asm/levels", func_L01_004D24C0);

/* localdecomp:start func_L01_004D25D0 */
s32 func_L01_004D25D0(s32 a, s32 b, s32 c) {
    return a + b * 1560;
}
/* localdecomp:end func_L01_004D25D0 */

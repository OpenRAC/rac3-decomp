#include "common.h"

typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_00422FE0 */
extern void func_L01_003FE938_00422FE0();

void func_L01_00422FE0(void) {
    func_L01_003FE938_00422FE0();
}
/* localdecomp:end func_L01_00422FE0 */

INCLUDE_ASM("asm/levels", func_L01_00423000);

/* localdecomp:start func_L01_00423020 */
extern void func_L01_003FEA68_00423020();

void func_L01_00423020(void) {
    func_L01_003FEA68_00423020();
}
/* localdecomp:end func_L01_00423020 */

/* localdecomp:start func_L01_00423040 */
extern void func_L01_003FF240_00423040();

void func_L01_00423040(void) {
    func_L01_003FF240_00423040();
}
/* localdecomp:end func_L01_00423040 */

LINKER_REMNANT("asm/levels", func_L01_00423060);

INCLUDE_ASM("asm/levels", func_L01_00423068);

LINKER_REMNANT("asm/levels", func_L01_004234E0);

/* localdecomp:start func_L01_004234E8 */
extern s32 D_L01_001DFE10;
extern s128 D_L01_001DFDD0[];

void func_L01_004234E8(s128 *a0, s32 a1) {
    s32 i;

    D_L01_001DFE10 = a1;
    for (i = 0; i < 4; i++) {
        D_L01_001DFDD0[i] = a0[i];
        ((f32 *)&D_L01_001DFDD0[i])[3] = 1.0f;
    }
}
/* localdecomp:end func_L01_004234E8 */

/* localdecomp:start func_L01_00423530 */
extern s32 D_L01_001DFE60;
extern s128 D_L01_001DFE20[];

void func_L01_00423530(s128 *a0, s32 a1) {
    s32 i;

    D_L01_001DFE60 = a1;
    for (i = 0; i < 4; i++) {
        D_L01_001DFE20[i] = *a0++;
        ((f32 *)&D_L01_001DFE20[i])[3] = 1.0f;
    }
}
/* localdecomp:end func_L01_00423530 */

LINKER_REMNANT("asm/levels", func_L01_00423578);

/* localdecomp:start func_L01_00423580 */
typedef struct { u8 pad[8]; s32 x8; s32 xC; s32 x10; } G_00423580;
typedef struct { s128 pos[4]; s32 rgba[4]; f32 uv[4][2]; long a, tex, c, d; } P_00423580;
extern G_00423580 *D_L01_001DFE10_00423580;
extern u8 D_L01_001D6AF4;
__asm__(".extern D_L01_001D6AF4, 1");
extern u8 D_L01_002E68E0[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00388258(void *, void *, s32);

void func_L01_00423580(void) {
    P_00423580 prim;
    s32 c;
    s32 i;

    func_003D93B0(&prim, D_L01_001DFE10_00423580->x8, D_L01_001DFE10_00423580->x10, 0x80);
    c = D_L01_001DFE10_00423580->xC;
    prim.rgba[3] = c;
    prim.rgba[2] = c;
    prim.rgba[1] = c;
    prim.rgba[0] = c;
    if (D_L01_001D6AF4 == 0) {
        prim.uv[0][0] = 0.0f;
        prim.uv[0][1] = 1.0f;
        prim.uv[1][0] = 0.0f;
        prim.uv[1][1] = 0.0f;
        prim.uv[2][0] = 1.0f;
        prim.uv[2][1] = 1.0f;
        prim.uv[3][0] = 1.0f;
        prim.uv[3][1] = 0.0f;
    } else {
        prim.uv[0][0] = 0.0f;
        prim.uv[0][1] = 0.0f;
        prim.uv[1][0] = 0.0f;
        prim.uv[1][1] = 1.0f;
        prim.uv[2][0] = 1.0f;
        prim.uv[2][1] = 0.0f;
        prim.uv[3][0] = 1.0f;
        prim.uv[3][1] = 1.0f;
    }
    D_L01_001D6AF4 = 0;
    for (i = 0; i < 4; i++) {
        prim.pos[i] = D_L01_001DFDD0[i];
        ((f32 *)&prim.pos[i])[3] = 1.0f;
    }
    func_003D2DA0(&prim, 0, 0);
    func_00388258(&D_L01_002E68E0, &prim, D_L01_001DFE10_00423580->x8);
}
/* localdecomp:end func_L01_00423580 */

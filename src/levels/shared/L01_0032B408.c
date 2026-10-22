#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0032B408);

INCLUDE_ASM("asm/levels", func_L01_0032BCB0);

INCLUDE_ASM("asm/levels", func_L01_0032BDD8);

INCLUDE_ASM("asm/levels", func_L01_0032BE90);

INCLUDE_ASM("asm/levels", func_L01_0032BEF0);

INCLUDE_ASM("asm/levels", func_L01_0032BF70);

INCLUDE_ASM("asm/levels", func_L01_0032C220);

INCLUDE_ASM("asm/levels", func_L01_0032C390);

INCLUDE_ASM("asm/levels", func_L01_0032C5D0);

INCLUDE_ASM("asm/levels", func_L01_0032C6B8);

INCLUDE_ASM("asm/levels", func_L01_0032C7A0);

INCLUDE_ASM("asm/levels", func_L01_0032C9F0);

/* localdecomp:start func_L01_0032CA80 */
extern u8 D_L01_00276E60[];
extern void func_L01_004CAE90(void *a0);

void func_L01_0032CA80(void) {
    func_L01_004CAE90(D_L01_00276E60);
}
/* localdecomp:end func_L01_0032CA80 */

INCLUDE_ASM("asm/levels", func_L01_0032CAA0);

INCLUDE_ASM("asm/levels", func_L01_0032CB38);

INCLUDE_ASM("asm/levels", func_L01_0032CE18);

INCLUDE_ASM("asm/levels", func_L01_0032CEB8);

/* localdecomp:start func_L01_0032CF48 */
typedef struct { u8 p0[0x68]; u8 *w68; } M_32CAB0;
extern s32 func_0038CAD0(u8 *);
extern void func_L01_0032D348(M_32CAB0 *);
extern void func_L01_0032CE18(M_32CAB0 *);

void func_L01_0032CF48(M_32CAB0 *m) {
    if (func_0038CAD0(m->w68 + 68) == 0) {
        func_L01_0032D348(m);
    }
    func_L01_0032CE18(m);
}
/* localdecomp:end func_L01_0032CF48 */

INCLUDE_ASM("asm/levels", func_L01_0032CF90);

INCLUDE_ASM("asm/levels", func_L01_0032D348);

INCLUDE_ASM("asm/levels", func_L01_0032D7E8);

INCLUDE_ASM("asm/levels", func_L01_0032DB08);

INCLUDE_ASM("asm/levels", func_L01_0032DED0);

/* localdecomp:start func_L01_0032E2B0 */
void func_L01_0032E2B0(void *arg0) {
    if ((u8) (*(u8 *)((u8 *)arg0 + 0x20)) < 8U) {
        *(u8 *)((u8 *)arg0 + 0x20) = 8U;
    }
}
/* localdecomp:end func_L01_0032E2B0 */

INCLUDE_ASM("asm/levels", func_L01_0032E2D0);

INCLUDE_ASM("asm/levels", func_L01_0032EE48);

INCLUDE_ASM("asm/levels", func_L01_0032EF88);

INCLUDE_ASM("asm/levels", func_L01_0032F020);

/* localdecomp:start func_L01_0032F0D8 */
extern void func_003C2F58(u8 *, s32, f32 *);
extern s32 func_L01_003FB640(f32 *, s32, u8 *, f32);
extern s32 D_L01_001EAA1C[];

void func_L01_0032F0D8(u8 *a0) {
    f32 v[4];

    func_003C2F58(a0, 0, v);
    if (func_L01_003FB640(v, 2, a0, 0.25f) && D_L01_001EAA1C[0] > 0) {
        a0[32] = 8;
    }
}
/* localdecomp:end func_L01_0032F0D8 */

INCLUDE_ASM("asm/levels", func_L01_0032F138);

INCLUDE_ASM("asm/levels", func_L01_0032F1B8);

INCLUDE_ASM("asm/levels", func_L01_0032F3E0);

INCLUDE_ASM("asm/levels", func_L01_0032F4E0);

INCLUDE_ASM("asm/levels", func_L01_0032F718);

INCLUDE_ASM("asm/levels", func_L01_0032F800);

INCLUDE_ASM("asm/levels", func_L01_0032F8E8);

INCLUDE_ASM("asm/levels", func_L01_0032FB18);

INCLUDE_ASM("asm/levels", func_L01_0032FB80);

/* localdecomp:start func_L01_0032FBA0 */
extern s32 func_0038CAD0(u8 *);
extern void func_L01_0032FF68(void *);

void func_L01_0032FBA0(u8 *a) {
    if (((s32 (*)(s32))func_0038CAD0)(*(s32 *)(a + 104) + 68) == 0) {
        func_L01_0032FF68(a);
    }
}
/* localdecomp:end func_L01_0032FBA0 */

INCLUDE_ASM("asm/levels", func_L01_0032FBE0);

INCLUDE_ASM("asm/levels", func_L01_0032FC70);

INCLUDE_ASM("asm/levels", func_L01_0032FF68);

/* localdecomp:start func_L01_00330390 */
void func_L01_00330390(void *arg0) {
    if ((u8) (*(u8 *)((u8 *)arg0 + 0x20)) < 8U) {
        *(u8 *)((u8 *)arg0 + 0x20) = 8U;
    }
}
/* localdecomp:end func_L01_00330390 */

LINKER_REMNANT("asm/levels", func_L01_003303B0);

INCLUDE_ASM("asm/levels", func_L01_003303B8);

INCLUDE_ASM("asm/levels", func_L01_00330820);

INCLUDE_ASM("asm/levels", func_L01_00331230);

INCLUDE_ASM("asm/levels", func_L01_00331D28);

INCLUDE_ASM("asm/levels", func_L01_00331DD0);

INCLUDE_ASM("asm/levels", func_L01_00332160);

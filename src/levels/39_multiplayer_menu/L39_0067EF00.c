#include "common.h"

typedef struct S_0067EF00 {
    s32 f0;
    s32 f4;
    s32 f8;
} S_0067EF00;

/* localdecomp:start func_L39_0067EF00 */
s32 func_L39_0067EF00(S_0067EF00 *p, s32 v) {
    s32 t = p->f4;

    if (t == 2) {
        if (v == 3) {
            p->f8 = 1;
        }
    } else if (t == 3) {
        if (v == 4) {
            p->f8 = 2;
        } else if (v == 2) {
            p->f8 = 6;
        }
    } else if (t == 4) {
        if (v == 3) {
            p->f8 = 5;
        } else if (v == 5) {
            p->f8 = 3;
        }
    } else if (t == 5) {
        if (v == 4) {
            p->f8 = v;
        }
    }
    p->f4 = v;
    return t;
}
/* localdecomp:end func_L39_0067EF00 */

INCLUDE_ASM("asm/levels", func_L39_0067EFA0);

/* localdecomp:start func_L39_0067F010 */
/* from rac2-decomp's func_00343028, renamed, constants adapted */
void func_L39_0067F010(u8 *a0, f32 a1, f32 a2) { *(f32 *)(a0 + 0x50) = a1; *(f32 *)(a0 + 0x54) = a2; }
/* localdecomp:end func_L39_0067F010 */

/* localdecomp:start func_L39_0067F020 */
/* from rac2-decomp's func_00343028, renamed, constants adapted */
void func_L39_0067F020(u8 *a0, f32 a1, f32 a2) { *(f32 *)(a0 + 0x58) = a1; *(f32 *)(a0 + 0x5c) = a2; }
/* localdecomp:end func_L39_0067F020 */

/* localdecomp:start func_L39_0067F030 */
extern void *D_001DBC4C_sda;
void func_003E82F8(void *);

/* from rac4-decomp's func_L01_00446AC0 */
void func_L39_0067F030(void *object) {
    D_001DBC4C_sda = object;
    func_003E82F8(object);
}
/* localdecomp:end func_L39_0067F030 */

/* localdecomp:start func_L39_0067F050 */
extern s32 D_001DBC50_sda;
extern s32 D_001DBC58_sda;

void func_L39_0067F050(s32 arg0) {
    D_001DBC50_sda = arg0;
    D_001DBC58_sda = -1;
}
/* localdecomp:end func_L39_0067F050 */

INCLUDE_ASM("asm/levels", func_L39_0067F060);

INCLUDE_ASM("asm/levels", func_L39_0067F0A0);

INCLUDE_ASM("asm/levels", func_L39_0067F100);

INCLUDE_ASM("asm/levels", func_L39_0067F168);

INCLUDE_ASM("asm/levels", func_L39_0067F1B0);

INCLUDE_ASM("asm/levels", func_L39_0067F210);

INCLUDE_ASM("asm/levels", func_L39_0067F3B8);

INCLUDE_ASM("asm/levels", func_L39_0067F648);

INCLUDE_ASM("asm/levels", func_L39_0067F6E8);

INCLUDE_ASM("asm/levels", func_L39_0067F7B0);

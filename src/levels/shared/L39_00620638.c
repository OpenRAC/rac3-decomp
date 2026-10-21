#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00620638);

INCLUDE_ASM("asm/levels", func_L39_00620AF8);

INCLUDE_ASM("asm/levels", func_L39_00620BE8);

INCLUDE_ASM("asm/levels", func_L39_00620CF8);

INCLUDE_ASM("asm/levels", func_L39_00620E28);

INCLUDE_ASM("asm/levels", func_L39_006212E8);

INCLUDE_ASM("asm/levels", func_L39_00621308);

/* localdecomp:start func_L39_00621370 */
typedef int u128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0xA0];
    u128 xA0;
    u8 padB0[0x1DC0 - 0xB0];
    u128 x1DC0;
    u8 pad1DD0[0x2348 - 0x1DD0];
    s32 x2348;
    s32 x234C;
} func_0061EBD0_t;

void func_L39_00621370(func_0061EBD0_t *a) {
    a->x2348 = 1;
    a->x1DC0 = a->xA0;
    a->x234C = 1;
}
/* localdecomp:end func_L39_00621370 */

INCLUDE_ASM("asm/levels", func_L39_00621388);

INCLUDE_ASM("asm/levels", func_L39_00621600);

INCLUDE_ASM("asm/levels", func_L39_006217C0);

INCLUDE_ASM("asm/levels", func_L39_00621D30);

INCLUDE_ASM("asm/levels", func_L39_00621D60);

INCLUDE_ASM("asm/levels", func_L39_00622288);

/* localdecomp:start func_L39_006223B0 */
typedef struct {
    u8 pad0[12];
    s16 h12;
    u8 pad1[33 - 14];
    s8 b33;
    u8 pad2[128 - 34];
} Ent_0061FC10;
extern Ent_0061FC10 D_L39_0049C890[];
extern s32 func_L39_00648AE0(u8 *, s32);
s32 func_L39_006223B0(u8 *p, s32 a) {
    s32 i;
    Ent_0061FC10 *e;
    if (a != 0) {
        if (p[6661] == 0) return 0;
        if (p[6664] != 0) return 0;
        i = -1;
        if (*(s32 *)(p + 1140) == 2) i = *(s32 *)(p + 1144);
        if (i == -1) return 0;
        if (func_L39_00648AE0(p, i)) {
            e = &D_L39_0049C890[D_L39_0049C890[i].b33];
        } else {
            e = &D_L39_0049C890[i];
        }
        return e->h12;
    }
    return 0;
}
/* localdecomp:end func_L39_006223B0 */

INCLUDE_ASM("asm/levels", func_L39_00622450);

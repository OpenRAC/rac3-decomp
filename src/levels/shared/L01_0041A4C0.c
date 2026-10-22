#include "common.h"

/* localdecomp:start func_L01_0041A4C0 */
extern s32 D_L01_001D6674;

s32 func_L01_0041A4C0(void) {
    return D_L01_001D6674 != 0;
}
/* localdecomp:end func_L01_0041A4C0 */

LINKER_REMNANT("asm/levels", func_L01_0041A4D0);

/* localdecomp:start func_L01_0041A4F0 */
extern u8 D_00142692[];

s32 func_L01_0041A4F0(void) {
    return D_00142692[0] != 0;
}
/* localdecomp:end func_L01_0041A4F0 */

LINKER_REMNANT("asm/levels", func_L01_0041A500);

INCLUDE_ASM("asm/levels", func_L01_0041A508);

LINKER_REMNANT("asm/levels", func_L01_0041A510);

/* localdecomp:start func_L01_0041A518 */
s32 func_L01_0041A518(s32 a0) {
    return (u32)(a0 - 30) < 7;
}
/* localdecomp:end func_L01_0041A518 */

INCLUDE_ASM("asm/levels", func_L01_0041A528);

/* localdecomp:start func_L01_0041A5B0 */
typedef struct {
    s32 f0;
    u8 pad[32];
    s32 f24;
    s32 f28;
    u8 pad2[20];
    s32 f40;
    s32 f44;
} S_00417F60;

typedef struct {
    u8 pad[36];
    s32 f24;
    u8 pad2[68];
    s32 f6C;
    u8 pad3[36];
    s32 f94;
} P_00417F60;

typedef struct {
    u16 h0;
    u8 pad[10];
} T_00417F60;

extern S_00417F60 D_L01_002E5F30;
extern P_00417F60 D_001CCFD0;
extern T_00417F60 D_001A7E18[];
extern s32 D_L01_001D6694;
extern s32 D_L01_001DFB40;
extern void func_L01_0041BD48(s32);

s32 func_L01_0041A5B0(s32 id, s32 idx) {
    S_00417F60 *s = &D_L01_002E5F30;
    P_00417F60 *p;

    if (s->f0 != 0) {
        return 0;
    }
    if (s->f24 == -1) {
        p = &D_001CCFD0;
        if (p->f6C == 0 && p->f24 == s->f24 && p->f94 == 0) {
            if (D_001A7E18[idx].h0 == 0xFFFF || D_L01_001D6694 == 6 || D_L01_001DFB40 < 6) {
                return 0;
            }
            s->f28 = idx;
            s->f24 = id;
            s->f40 = 0;
            s->f44 = 0;
            func_L01_0041BD48(id);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0041A5B0 */

INCLUDE_ASM("asm/levels", func_L01_0041A678);

/* localdecomp:start func_L01_0041A6B0 */
extern u8 D_001638C8[];

void *func_L01_0041A6B0(void) {
    return D_001638C8;
}
/* localdecomp:end func_L01_0041A6B0 */

INCLUDE_ASM("asm/levels", func_L01_0041A6BC);

/* localdecomp:start func_L01_0041A6C8 */
extern u8 D_00164548[];

void *func_L01_0041A6C8(void) {
    return D_00164548;
}
/* localdecomp:end func_L01_0041A6C8 */

INCLUDE_ASM("asm/levels", func_L01_0041A6D4);

INCLUDE_ASM("asm/levels", func_L01_0041A6E0);

INCLUDE_ASM("asm/levels", func_L01_0041A7D0);

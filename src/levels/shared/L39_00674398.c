#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00674398);

INCLUDE_ASM("asm/levels", func_L39_00674E08);

INCLUDE_ASM("asm/levels", func_L39_00674F50);

INCLUDE_ASM("asm/levels", func_L39_00675830);

INCLUDE_ASM("asm/levels", func_L39_00675908);

INCLUDE_ASM("asm/levels", func_L39_006761D0);

/* localdecomp:start func_L39_006770F8 */
extern u8 D_L39_001DAE88[8];
void func_L39_006770F8(s32 i) {
    D_L39_001DAE88[i] = 1;
}
/* localdecomp:end func_L39_006770F8 */

/* localdecomp:start func_L39_00677110 */
extern u8 D_L39_001DAE88[8];

u8 func_L39_00677110(s32 a0) {
    return D_L39_001DAE88[a0];
}
/* localdecomp:end func_L39_00677110 */

/* localdecomp:start func_L39_00677120 */
extern u8 D_L39_001DAE88[8];

void func_L39_00677120(s32 a0) {
    D_L39_001DAE88[a0] = 0;
}
/* localdecomp:end func_L39_00677120 */

/* localdecomp:start func_L39_00677130 */
extern s32 D_L39_001DAE90[2];
void func_L39_00677130(s32 i) {
    D_L39_001DAE90[i] = 0;
}
/* localdecomp:end func_L39_00677130 */

INCLUDE_ASM("asm/levels", func_L39_00677148);

/* localdecomp:start func_L39_00677170 */
extern s32 D_L39_001DAE90[2];

s32 func_L39_00677170(s32 i) {
    return D_L39_001DAE90[i] == 3;
}
/* localdecomp:end func_L39_00677170 */

INCLUDE_ASM("asm/levels", func_L39_00677190);

INCLUDE_ASM("asm/levels", func_L39_006772B8);

/* localdecomp:start func_L39_006772F8 */
extern s32 func_L39_006772B8(s32, s32);
extern void func_L39_005DEF18(s32, s32);
extern void func_L39_005DC180(s32, s32);

void func_L39_006772F8(s32 a0, s32 a1) {
    if (func_L39_006772B8(a0, a1)) {
        func_L39_005DEF18(a0, a1);
    } else {
        func_L39_005DC180(a0, a1);
    }
}
/* localdecomp:end func_L39_006772F8 */

/* localdecomp:start func_L39_00677348 */
extern s32 func_L39_006772B8(s32, s32);
extern void func_L39_005DEF78(s32, s32);
extern void func_L39_005DC248(s32, s32);

void func_L39_00677348(s32 a0, s32 a1) {
    if (func_L39_006772B8(a0, a1)) {
        func_L39_005DEF78(a0, a1);
    } else {
        func_L39_005DC248(a0, a1);
    }
}
/* localdecomp:end func_L39_00677348 */

/* localdecomp:start func_L39_00677398 */
extern s32 func_L39_006772B8(s32, s32);
extern void func_L39_005DC260(void *a0);
extern void func_L39_005DEF90(void *a0);
void func_L39_00677398(void *a0) {
    if (((s32 (*)(void *a0))func_L39_006772B8)(a0) == 0) {
        func_L39_005DC260(a0);
    } else {
        func_L39_005DEF90(a0);
    }
}
/* localdecomp:end func_L39_00677398 */

/* localdecomp:start func_L39_006773E0 */
extern s32 func_L39_006772B8(s32, s32);
extern void func_L39_005DEFA8(s32, s32);
extern void func_L39_005DC278(s32, s32);

void func_L39_006773E0(s32 a0, s32 a1) {
    if (func_L39_006772B8(a0, a1)) {
        func_L39_005DEFA8(a0, a1);
    } else {
        func_L39_005DC278(a0, a1);
    }
}
/* localdecomp:end func_L39_006773E0 */

/* localdecomp:start func_L39_00677430 */
extern s32 func_L39_006772B8(s32, s32);
extern void func_L39_005DC140(void *a0);
extern void func_L39_005DEED8(void *a0);
void func_L39_00677430(void *a0) {
    if (((s32 (*)(void *a0))func_L39_006772B8)(a0) == 0) {
        func_L39_005DC140(a0);
    } else {
        func_L39_005DEED8(a0);
    }
}
/* localdecomp:end func_L39_00677430 */

/* localdecomp:start func_L39_00677478 */
extern s32 func_L39_006772B8(s32, s32);
extern void func_L39_005DEFC0(s32, s32);
extern void func_L39_005DC290(s32, s32);

void func_L39_00677478(s32 a0, s32 a1) {
    if (func_L39_006772B8(a0, a1)) {
        func_L39_005DEFC0(a0, a1);
    } else {
        func_L39_005DC290(a0, a1);
    }
}
/* localdecomp:end func_L39_00677478 */

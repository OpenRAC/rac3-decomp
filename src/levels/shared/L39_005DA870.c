#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005DA870);

INCLUDE_ASM("asm/levels", func_L39_005DAC98);

/* localdecomp:start func_L39_005DADF8 */
extern unsigned char D_L39_00243690[8];
extern int D_L39_00243698[2];
extern unsigned char D_L39_00243668[8];
extern int D_L39_00243670[2];
extern int D_L39_00243680[2];
extern char D_L39_002B5780[][24];
extern char D_L39_00243740[];
extern char D_L39_00243748[];
extern int func_00120048(char *, char *, ...);

void func_L39_005DADF8(int a, int b, int idx)
{
    if (D_L39_00243690[idx])
        D_L39_00243698[idx] = 0;
    D_L39_00243690[idx] = 0;
    if (D_L39_00243668[idx]) {
        D_L39_00243670[idx] = a;
        D_L39_00243680[idx] = b;
    }
    if (a == 0 && b == 0)
        func_00120048(D_L39_002B5780[idx], D_L39_00243740);
    else
        func_00120048(D_L39_002B5780[idx], D_L39_00243748, a, b);
}
/* localdecomp:end func_L39_005DADF8 */

INCLUDE_ASM("asm/levels", func_L39_005DAEB8);

/* localdecomp:start func_L39_005DB0E0 */
extern int D_L39_00243698[2];
extern u8 D_L39_00243690[8];
extern s32 D_L39_002436A8[2];
void func_L39_005DB0E0(s32 a0, s32 a1, f32 a2) {
    f32 *p;
    D_L39_00243690[a1] = 1;
    p = &((f32 *)&D_L39_00243698)[a1];
    *p = 1.0f - a2;
    if (*p > 1.0f) {
        *p = 1.0f;
    }
    if (*p < 0.0f) {
        *p = 0.0f;
    }
    D_L39_002436A8[a1] = a0;
}
/* localdecomp:end func_L39_005DB0E0 */

/* localdecomp:start func_L39_005DB148 */
extern f32 D_L39_002436C0[2];
extern s32 D_L39_002436D0[2];

void func_L39_005DB148(s32 a0, f32 a1)
{
    f32 *p;

    p = &D_L39_002436C0[a0];
    *p = 1.0f - a1;
    if (*p > 1.0f) {
        *p = 1.0f;
    }
    if (*p < 0.0f) {
        *p = 0.0f;
    }
    D_L39_002436D0[a0] = 2;
}
/* localdecomp:end func_L39_005DB148 */

INCLUDE_ASM("asm/levels", func_L39_005DB1A8);

INCLUDE_ASM("asm/levels", func_L39_005DB370);

INCLUDE_ASM("asm/levels", func_L39_005DB618);

INCLUDE_ASM("asm/levels", func_L39_005DB700);

INCLUDE_ASM("asm/levels", func_L39_005DB800);

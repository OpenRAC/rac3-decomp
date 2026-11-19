#include "common.h"

/* localdecomp:start func_L39_006770F8 */
extern u8 D_L39_00246598[8];
void func_L39_006770F8(s32 i) {
    D_L39_00246598[i] = 1;
}
/* localdecomp:end func_L39_006770F8 */

/* localdecomp:start func_L39_00677110 */
extern u8 D_L39_00246598[8];

u8 func_L39_00677110(s32 a0) {
    return D_L39_00246598[a0];
}
/* localdecomp:end func_L39_00677110 */

/* localdecomp:start func_L39_00677120 */
extern u8 D_L39_00246598[8];

void func_L39_00677120(s32 a0) {
    D_L39_00246598[a0] = 0;
}
/* localdecomp:end func_L39_00677120 */

/* localdecomp:start func_L39_00677130 */
extern s32 D_L39_002465A0[2];
void func_L39_00677130(s32 i) {
    D_L39_002465A0[i] = 0;
}
/* localdecomp:end func_L39_00677130 */

/* localdecomp:start func_L39_00677148 */
extern s32 D_L39_002465A0[2];
void func_L39_00677148(s32 i) {
    if (D_L39_002465A0[i] == 0) {
        D_L39_002465A0[i] = 1;
    }
}
/* localdecomp:end func_L39_00677148 */

/* localdecomp:start func_L39_00677170 */
extern s32 D_L39_002465A0[2];

s32 func_L39_00677170(s32 i) {
    return D_L39_002465A0[i] == 3;
}
/* localdecomp:end func_L39_00677170 */

/* localdecomp:start func_L39_00677190 */
typedef struct {
    u8 pad0[0x1C0];
    u32 w1C0;
} Obj_00677190;
typedef struct {
    u8 pad0[0x2534];
    Obj_00677190 *p2534;
} Pl_00677190;
extern s32 D_L39_002465A0[2];
extern s32 D_L39_002465B0_00677190;
extern s32 D_L39_0024CFA8[] __attribute__((section(".sdata")));
extern u8 *func_L39_0061BF38(s32);
extern u8 func_L39_00677110(s32);
extern void func_L39_00677120(s32);
extern void func_L39_00677130(s32);

void func_L39_00677190(s32 i) {
    Pl_00677190 *pl = (Pl_00677190 *)func_L39_0061BF38(i);
    s32 *st = &D_L39_002465A0[i];
    switch (*st) {
    case 0:
        break;
    case 1:
        D_L39_0024CFA8[i] = D_L39_002465B0_00677190;
        *st = 2;
        break;
    case 2:
        D_L39_0024CFA8[i]--;
        if (func_L39_00677110(i) != 0) {
            func_L39_00677120(i);
            func_L39_00677130(i);
            return;
        }
        if (D_L39_0024CFA8[i] == 0) {
            if (pl->p2534->w1C0 & 0x10) {
                (*st)++;
                return;
            }
        } else if (pl->p2534->w1C0 & 0x10) {
            return;
        }
        D_L39_002465A0[i] = 0;
        break;
    }
}
/* localdecomp:end func_L39_00677190 */

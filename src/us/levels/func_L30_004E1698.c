#include "common.h"

/* NTSC-U counterpart of func_L30_004E5598 (src/levels/shared/L30_004E5370.c): 0.22 -> 0.183333; 6 -> 7 */
typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;
extern S_004E6988 D_001A4BE0;
#include "vu0.h"

/* localdecomp:start func_L30_004E1698 */
#include "vu0.h"
/* log: switch with three separate (identical) case bodies gives retail's 1/<2/0/2 decision tree
 * (a merged case 0..2 gives a range check); fabs_asm (as func_L30_004E5410) schedules abs.s after
 * c.lt.s where __builtin_fabsf put it before -> MATCH. 0x3E6147AF is 0.22000001f. */
typedef struct {
    u8 pad0[0x1B4];
    f32 f1B4;
    s32 w1B8;
    u8 pad1[0x344 - 0x1BC];
    f32 f344;
    u8 pad2[0xBDC - 0x348];
    s16 hBDC;
    u8 pad3[0x25C0 - 0xBDE];
    u8 *p25C0;
    s32 w25C4;
} S_004E5598;

extern void func_L01_004F02A0(void *, void *);
extern void func_L01_004EB3A0(f32);

void func_L30_004E1698(void) {
    f32 g;
    f32 dir;
    s32 n;
    f32 buf[4];

    if (((S_004E5598 *)&D_001A4BE0)->w25C4 != 0x9D) {
        return;
    }
    dir = 1.0f;
    if (*(u16 *)(((S_004E5598 *)&D_001A4BE0)->p25C0 + 0x34) & 0x8000) {
        dir = -1.0f;
    }
    g = 0.0f;
    n = 0;
    switch (((S_004E5598 *)&D_001A4BE0)->hBDC) {
    case 0:
        g = 0.183333337f;
        n = 7;
        break;
    case 1:
        g = 0.183333337f;
        n = 7;
        break;
    case 2:
        g = 0.183333337f;
        n = 7;
        break;
    }
    dir *= 1.7f;
    func_L01_004F02A0((u8 *)&D_001A4BE0 + 0x2C0, buf);
    ((S_004E5598 *)&D_001A4BE0)->f344 = buf[1];
    if (((S_004E5598 *)&D_001A4BE0)->w1B8 < n) {
        ((S_004E5598 *)&D_001A4BE0)->f1B4 = fabs_asm(g * dir);
        if (dir > 0.0f) {
            func_L01_004EB3A0(0.0f);
        } else {
            func_L01_004EB3A0(3.1415927f);
        }
    } else {
        ((S_004E5598 *)&D_001A4BE0)->f1B4 = 0.0f;
    }
}
/* localdecomp:end func_L30_004E1698 */

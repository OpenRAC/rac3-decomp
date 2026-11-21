#include "common.h"

/* NTSC-U counterpart of func_L01_004C1D38 (src/levels/shared/L01_004C1D38.c): 6141 -> 6140; 6148 -> 6144; 6147 -> 6143; 6146 -> 6142 */
/* localdecomp:start func_L01_004BE190 */
extern s32 func_L01_004BE138(s32 id, f32 x, f32 y, s32 a, s32 b);
s32 func_L01_004BE190(s32 id) {
    if (id == 0x1B8 || id == 0x17F4) {
        return func_L01_004BE138(id, 0.65f, 0.25f, 0, 0);
    } else if (id == 0x17FC) {
        return func_L01_004BE138(0x17FC, 0.65f, 0.13f, 0x40, 1);
    } else if (id == 0x1800) {
        return func_L01_004BE138(0x1800, 0.65f, 0.16f, 0x40, 1);
    } else if (id == 0x17FF) {
        return func_L01_004BE138(0x17FF, 0.65f, 0.16f, 0x40, 1);
    } else if (id == 0x17FE) {
        return func_L01_004BE138(0x17FE, 0.65f, 0.16f, 0x40, 1);
    } else if (id == 0x17F7) {
        return func_L01_004BE138(0x17F7, 0.65f, 0.32f, 0x40, 1);
    } else {
        return func_L01_004BE138(id, 0.65f, 0.26f, 0x40, 1);
    }
}
/* localdecomp:end func_L01_004BE190 */

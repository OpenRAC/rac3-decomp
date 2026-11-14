/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_004BE190, the NTSC-U twin of func_L01_004C1D38, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L01_004BA278.c's current line.
 * Worker's note: 59 diff; default assembler emits lit4 lwc1 instead of retail inline 0.65/0.13/0.16/0.26/0.32 constants; documented assembler mismatch, no flags_alt; best log w111/func_L01_004BE190.01.log
 */
#include "common.h"

/* localdecomp:start func_L01_004BE190 */
extern int func_L01_004BE138(int, float, float, int, int);

int func_L01_004BE190(int message) {
    if (message == 0x1B8 || message == 0x17F4) {
        return func_L01_004BE138(message, 0.65f, 0.25f, 0, 0);
    } else if (message == 0x17FC) {
        return func_L01_004BE138(0x17FC, 0.65f, 0.13f, 64, 1);
    } else if (message == 0x1800) {
        return func_L01_004BE138(0x1800, 0.65f, 0.16f, 64, 1);
    } else if (message == 0x17FF) {
        return func_L01_004BE138(0x17FF, 0.65f, 0.16f, 64, 1);
    } else if (message == 0x17FE) {
        return func_L01_004BE138(0x17FE, 0.65f, 0.16f, 64, 1);
    } else if (message == 0x17F7) {
        return func_L01_004BE138(0x17F7, 0.65f, 0.32f, 64, 1);
    } else {
        return func_L01_004BE138(message, 0.65f, 0.26f, 64, 1);
    }
}
/* localdecomp:end func_L01_004BE190 */

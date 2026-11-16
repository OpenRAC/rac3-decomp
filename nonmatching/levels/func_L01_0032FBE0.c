/* NTSC-U draft (Codex wave 4): C of func_L01_0032F6B8, the NTSC-U twin of func_L01_0032FBE0, with NTSC-U names and addresses.
 * near miss: 28 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_0032F6B8").
 * Worker's note: sister build/codex/pool/X4/us_func_L01_0032F6B8_rac2.c; best log build/codex/w165/func_L01_0032F6B8.check01.log; 28 word diffs: required instruction sequence triggers default assembler mtc1 hazard nop at +0x24; all following words align after removing that ...
 */
#include "common.h"
/* localdecomp:start func_L01_0032F6B8 */
/* Ported from rac2-decomp rac2-decomp/src/game/00300618.c:689-717. */

void func_L01_0032F6B8(char *p)
{
    *(long *)(p + 112) = 0L;
    *(int *)(p + 80) = 0;
    *(int *)(p + 84) = 0;
    *(float *)(p + 88) = 1.0f;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(float *)(p + 100) = 1.0f;
    *(float *)(p + 104) = 1.0f;
    *(float *)(p + 108) = 1.0f;
    *(float *)(p + 8) = -2.0f;
    *(float *)(p + 24) = 2.0f;
    *(float *)(p + 40) = -2.0f;
    *(float *)(p + 56) = 2.0f;
    *(float *)(p + 4) = -2.0f;
    *(float *)(p + 36) = 2.0f;
    *(int *)(p + 0) = 0;
    *(int *)(p + 16) = 0;
    *(int *)(p + 32) = 0;
    *(int *)(p + 48) = 0;
    *(float *)(p + 12) = 1.0f;
    *(float *)(p + 28) = 1.0f;
    *(float *)(p + 44) = 1.0f;
    *(long *)(p + 128) = 0x0000FF9000000260L;
    *(float *)(p + 20) = -2.0f;
    *(float *)(p + 52) = 2.0f;
    *(float *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0032F6B8 */

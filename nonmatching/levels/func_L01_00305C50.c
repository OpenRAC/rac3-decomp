/* NTSC-U draft (Codex wave 4): C of func_L01_003059F0, the NTSC-U twin of func_L01_00305C50, with NTSC-U names and addresses.
 * near miss: 20 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003059F0").
 * Worker's note: sister build/codex/pool/X4/us_func_L01_003059F0_rac2.c; best log build/codex/w165/func_L01_003059F0.check01.log; 20 word diffs: one default-assembler mtc1 hazard nop at +0x1c shifts all following instructions; the instruction sequence otherwise matches; ...
 */
#include "common.h"

/* localdecomp:start func_L01_003059F0 */
void func_L01_003059F0(char *quadPacket)
{
    *(long *)(quadPacket + 112) = 0;
    *(float *)(quadPacket + 8) = -1.0f;
    *(float *)(quadPacket + 24) = 1.0f;
    *(float *)(quadPacket + 40) = -1.0f;
    *(float *)(quadPacket + 56) = 1.0f;
    *(float *)(quadPacket + 4) = -1.0f;
    *(float *)(quadPacket + 36) = 1.0f;
    *(float *)(quadPacket + 52) = 1.0f;
    *(int *)(quadPacket + 0) = 0;
    *(int *)(quadPacket + 16) = 0;
    *(int *)(quadPacket + 32) = 0;
    *(int *)(quadPacket + 48) = 0;
    *(float *)(quadPacket + 12) = 1.0f;
    *(float *)(quadPacket + 28) = 1.0f;
    *(float *)(quadPacket + 44) = 1.0f;
    *(long *)(quadPacket + 128) = 0x0000FF9000000260L;
    *(float *)(quadPacket + 20) = -1.0f;
    *(float *)(quadPacket + 60) = 1.0f;
}
/* localdecomp:end func_L01_003059F0 */

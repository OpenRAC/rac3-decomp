/* NTSC-U draft (Codex wave 3): C of func_L01_004D4108, the NTSC-U twin of func_L01_004D7DC8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 90 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_004D4108", whose code is not the PAL one).
 * Worker's note: 90 diff; allowed flags verified once; frame 0x50 vs retail 0x90, sd/ld vs sq/lq, GNU literal pool vs inline lui/ori/mtc1; documented compiler/assembler profile mismatch; no unlisted flags tried; best log func_L01_004D4108.01.log
 */
#include "common.h"
/* localdecomp:start func_L01_004D4108 */
extern s32 D_L01_001DFBC0 __attribute__((section(".data")));
extern float func_00388978(float);
extern s32 func_003894A0(s32,s32,float);
void func_L01_004D4108(u8 *m,s32 blue,s32 green,s32 red,s32 alpha,s32 ba,s32 ga,s32 ra,s32 period) {
 float phase=(float)(D_L01_001DFBC0%period)/(float)period;
 float wave=func_00388978((phase+phase)*3.1415927f+(-3.1415927f));
 red+=(s32)(wave*(float)ra)+ra/2;
 green+=(s32)(wave*(float)ga)+ga/2;
 blue+=(s32)(wave*(float)ba)+ba/2;
 *(s32 *)(m+0x78)=func_003894A0(*(s32 *)(m+0x78),(alpha<<24)|(red<<16)|(green<<8)|blue,0.05f);
}
/* localdecomp:end func_L01_004D4108 */

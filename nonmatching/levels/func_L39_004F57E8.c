/* NTSC-U draft (Claude wave S/us): C of func_L39_004F55E8, the NTSC-U twin of func_L39_004F57E8, with NTSC-U names and addresses.
 * near miss: 4 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "@ee296 @eeas -O2 -G0") (NTSC-U twin "func_L39_004F55E8").
 * Worker's note: 4 diff words / 2 adjacent swaps (prior draft kept): prologue retail "sd s0; move s0,a0; sd s1; sd ra" vs mine "sd s0; sd s1; move s0,a0"; epilogue retail "move v0,zero; ld s0" vs mine "ld s0; move v0,zero"; @ee29 -O2 -G8 -fno-strict-aliasing gives 11 diff ...
 */
#include "common.h"

/* localdecomp:start func_L39_004F55E8 */
/* func_L39_004F6220 sets up a DES key schedule; func_L39_004F61B8 sets it up reversed (decrypt) */
extern s32 func_L39_004F6220(void *schedule, void *key);
extern s32 func_L39_004F61B8(void *schedule, void *key);

s32 func_L39_004F55E8(u8 *schedules, u8 *key) {
    func_L39_004F6220(schedules, key);
    func_L39_004F61B8(schedules + 0x80, key + 8);
    func_L39_004F6220(schedules + 0x100, key + 0x10);
    return 0;
}
/* localdecomp:end func_L39_004F55E8 */

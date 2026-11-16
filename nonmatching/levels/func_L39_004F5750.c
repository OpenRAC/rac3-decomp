/* NTSC-U draft (Claude wave S/us): C of func_L39_004F5550, the NTSC-U twin of func_L39_004F5750, with NTSC-U names and addresses.
 * near miss: 4 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "@ee296 @eeas -O2 -G0") (NTSC-U twin "func_L39_004F5550").
 * Worker's note: 4 diff, unchanged after 4 more wordings (extra key+8 local 6, alias locals 4, void 8, r-r 4): prologue order (retail sd s0; move s0,a0; sd s1; move s1,a1; ours sd s1 before move s0) and epilogue (retail move v0,zero before ld s0) are sched2 tie-breaks on insn ...
 */
#include "common.h"

/* localdecomp:start func_L39_004F5550 */
/* func_L39_004F6220 sets up a DES key schedule; func_L39_004F61B8 sets it up reversed (decrypt) */
extern s32 func_L39_004F6220(void *schedule, void *key);
extern s32 func_L39_004F61B8(void *schedule, void *key);

s32 func_L39_004F5550(u8 *schedules, u8 *key) {
    func_L39_004F61B8(schedules + 0x100, key);
    func_L39_004F6220(schedules + 0x80, key + 8);
    func_L39_004F61B8(schedules, key + 0x10);
    return 0;
}
/* localdecomp:end func_L39_004F5550 */

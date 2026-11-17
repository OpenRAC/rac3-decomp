/* func_L01_00409428 (level 01, 0x16C bytes, bucket mmi).
 *
 * C body is byte-exact. The remaining difference is retail's prologue/epilogue:
 * frame 0xA0 with 16-byte slots, $s0..$s7/$fp ascending from 0x00 and $ra at
 * 0x90, all saved/restored with sq/lq (the documented "saves $ra with sq" class,
 * Matching-Patterns.md). gcc 2.95.3 at the file's flags writes 8-byte sd/ld slots
 * with -fopt-stack (26 diff); with -fopt-stack removed it writes sq 16-byte slots
 * but lays them out descending with $ra lowest and an sd $ra (20 diff).
 *
 * Two repo metadata changes make it MATCH (verified locally by adding the name
 * to the sq_ra list in memory, without touching config/):
 *   1. config/levels/sq_ra_funcs.txt: add the line  func_L01_00409428
 *   2. this function needs its own file/slice with -O2 -G8 -mno-check-zero-division
 *      (no -fopt-stack), per config/levels/text_parts.txt.
 * Check with: check.py func.c func_L01_00409428 --target level_01 --flags=-fno-opt-stack
 */
#include "common.h"
/* localdecomp:start func_L01_00409428 */
typedef int Q_00409428 __attribute__((mode(TI)));
s32 func_L01_00409428(u8 *obj, s16 *timer, s16 *state, Q_00409428 *position, Q_00409428 *rotation, s32 fadeOut, s32 fadeIn, s32 duration, s32 arg8, s32 arg9) {
    extern s32 func_0038CB00(s16 *);
    extern s32 func_L01_00409070(u8 *, s32, s32);
    if (obj==0) return 0;
    if (*state==2) {
        obj[0x23]=0x80;
        return 0;
    }
    if (*state==0) {
        if (func_0038CB00(timer)==0) {
            obj[0x23]-=fadeOut;
            if (func_L01_00409070(obj,arg8,arg9)==0) *state=2;
        } else {
            *state=1;
            obj[0x23]=0;
            *timer=duration;
            *(Q_00409428 *)(obj+0x10)=*position;
            *(Q_00409428 *)(obj+0xF0)=*rotation;
        }
    } else if (*state==1) {
        if (func_0038CB00(timer)==0) {
            obj[0x23]+=fadeIn;
            if (obj[0x23]>0x80) obj[0x23]=0x80;
            if (func_L01_00409070(obj,arg8,arg9)==0) *state=2;
        } else {
            obj[0x23]=0x80;
            *state=2;
        }
    }
    return 1;
}
/* localdecomp:end func_L01_00409428 */

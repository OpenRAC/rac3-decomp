/* PAL near miss (Codex wave 8): near miss: 26 words differ with the file's flags.
 * Worker's note: 26 diff / 91 words; all body instructions match, only frame/save/stack-argument offsets differ. Fixed -fopt-stack produces 0x50 frame with sd/ld, retail 0xA0 with sq/lq. --sq-ra trial gives 24 diff and cannot expand slots/frame; not requested metadata. Best ...
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

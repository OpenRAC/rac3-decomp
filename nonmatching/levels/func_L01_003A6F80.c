/* PAL near miss (Codex wave 6): near miss: 6 words differ with the file's flags.
 * Worker's note: 6 diff, same size: flags and 255 use swapped v0/v1; three forms unchanged, 64-bit local worse. Best build/codex/w321/F80-final.log, bytes F80-01.log. Claude context review: preceding func_L01_00456C98 is void in owner; a nonvoid return could explain occupied ...
 */
#include "common.h"
/* localdecomp:start func_L01_003A6F80 */
void func_L01_003A6F80(Obj_003A5118 *obj) {
    extern f32 *func_00382348(u8 *);
    extern u8 *func_L01_00448FF0(void *);
    extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);
    extern void func_L01_004AA7E8(S_3A9AC0m *, int);
    extern s32 func_L01_004AA710(void *, s32);
    extern void func_003A4F28(int);
    extern void func_L01_004450F0(S_3A9AC0m *, int, int);
    u8 *o = (u8 *)obj;
    f32 *hp;
    u8 *v;
    s32 i = 0;
    o[0x7F] = 0;
    hp = func_00382348(o);
    *hp = (f32)*(s16 *)((u8 *)hp + 4);
    v = func_L01_00448FF0(o);
    *(s16 *)(v + 0x38) = 0;
    v[7] = 0;
    v[9] = 0;
    v[8] = 0;
    func_L01_00456C98(o, -1, 0, 0, 0, 0, 3, 0, 0.0f, 0.0f, 1.0f, 0, 0);
    o[0xA8] = 255;
    ((S_3A9AC0m *)o)->h34 |= 0x43;
    ((S_3A9AC0m *)o)->h34 &= 0xEFFF;
    ((S_3A9AC0m *)o)->x98 = 0;
    func_L01_004AA7E8((S_3A9AC0m *)o, 1);
    do {
        if (func_L01_004AA710(o, i) != 0) func_003A4F28(i);
        i++;
    } while (i < 52);
    func_L01_004450F0((S_3A9AC0m *)o, 16, 6);
}
/* localdecomp:end func_L01_003A6F80 */

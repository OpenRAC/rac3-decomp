/* PAL near miss (Codex wave 8): near miss: 25 words differ with the file's flags.
 * Worker's note: 25 diff; w394/func_L01_004C98A8.check1.log; context correction required: func_L01_004C9848 is void(u8*) but retail forwards kind in a1; retained exact existing prototype, no cast/alias.
 */
#include "common.h"
/* localdecomp:start func_L01_004C98A8 */
typedef int Q_004C98A8 __attribute__((mode(TI)));
extern Obj_4C5DE0 *D_L01_001E1138;
u8 *func_L01_004C98A8(s32 kind, s32 animation, u8 *object) {
    extern void func_L01_004C9848(u8 *a0);
    extern void func_003C3938(void *, s32, s32);
    u8 *p = (u8 *)D_L01_001E1138;
    if (object) p = object;
    func_L01_004C9848(p);
    *(u16 *)(p + 0x34) &= 0xFFBC;
    *(Q_004C98A8 *)(p + 0xF0) = 0;
    p[0x30] = 255;
    *(u16 *)(p + 0x32) = 32;
    p[0x31] = 1;
    *(f32 *)(p + 0x14) = 5.0f;
    *(f32 *)(p + 0x18) = 900.0f;
    *(f32 *)(p + 0x1C) = 1.0f;
    *(f32 *)(p + 0x10) = 5.0f;
    if (animation >= 0) func_003C3938(p, animation, 0);
    else if (*(u8 **)(p + 0x24) && (*(u8 **)(p + 0x24))[0xC] >= 2) func_003C3938(p, 1, 0);
    if (!(*(u16 *)(p + 0x34) & 4)) func_003C7C38(p);
    return p;
}
/* localdecomp:end func_L01_004C98A8 */

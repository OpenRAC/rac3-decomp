/* PAL near miss (Codex wave 6): near miss: 12 words differ with the file's flags.
 * Worker's note: 12 diff, -4 bytes: sltiu replaces retail beql/addiu final boolean; 3 wordings unchanged (L21-01/02/04.log), long result worse (L21-03.log). Best build/codex/w321/L21-01.log.
 */
#include "common.h"
/* localdecomp:start func_L21_00338C20 */
extern u8 *D_L21_001DED9C_00338B00;
s32 func_L21_00338C20(u8 *arg0)
{
    extern s32 func_L01_0043B568(s32, s32, s32);
    u8 *p = *(u8 **)(arg0 + 0x68);
    u8 *e = D_L21_001DED9C_00338B00 + (*(s32 *)(p + 0x24) << 8);
    s32 result = 0;
    u8 *r = (u8 *)func_L01_0043B568(0x1BC5, 0, 0x44);
    switch (p[0x7A]) {
    case 1:
        if (((s32 (*)(u8 *))(*(void **)(r + 0x2C)))(e) == -1)
            break;
    case 0:
        if (p[0x7B] == 0) {
            if (p[0x7E] == 0)
                result = 1;
        }
        break;
    }
    return result;
}
/* localdecomp:end func_L21_00338C20 */

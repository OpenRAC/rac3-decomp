/* PAL near miss (Codex wave 8): near miss: 7 words differ with the file's flags.
 * Worker's note: 6 diff w443/func_003F0EB8.01.log: fixed default assembler emits literal-pool lwc1 for 0x3F555555; retail uses lui/ori/mtc1. Raw, rational and typed forms identical. Union materialization worsens to 8 diff. Fixed flags unchanged.
 */
#include "common.h"
/* localdecomp:start func_003F0EB8 */
void func_003F0EB8(u8 *object, f32 value) {
    *(f32 *)(*(u8 **)(object + 0x2C) + 0x50) = value * 0.8333333f;
}
/* localdecomp:end func_003F0EB8 */

/* PAL near miss (Codex wave 6): near miss: 47 words differ with the file's flags.
 * Worker's note: 47 diff; logs/func_L01_003A6DA8.05.wrapper.log; group-list collection and ten-slot reset reconstructed; residual loop block order/register allocation; three alternate return/type/counter forms were identical at 59 diff.
 */
#include "common.h"
/* localdecomp:start func_L01_003A6DA8 */
extern u8 *D_L01_001E001C;
extern u16 *D_L01_0021DE20[];
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
void func_L01_003A6DA8(u8 *obj, u8 *parent, s32 group) {
    u8 *v = *(u8 **)(obj + 0x68);
    u16 *p;
    u8 *m;
    s32 i;
    *(s32 *)(v + 0x318) = parent != 0 ? ((s32)parent - (s32)D_L01_001E001C) >> 8 : -1;
    if (group != 255) {
        p = D_L01_0021DE20[group];
        i = 0;
        while ((group & 255) != 255 && group <= D_001E0058_sda && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L01_0021DE20[group])) {
            m = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (m == 0) break;
            *(s32 *)(v + 0x360 + i * 4) = ((s32)m - (s32)D_L01_001E001C) >> 8;
            i++;
            *(u16 *)(m + 0x34) |= 2;
            p++;
        }
    } else {
        for (i = 9; i >= 0; i--) {
            *(s32 *)(v + 0x360 + i * 4) = -1;
        }
    }
}
/* localdecomp:end func_L01_003A6DA8 */

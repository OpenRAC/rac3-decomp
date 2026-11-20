#include "common.h"

/* localdecomp:start func_L39_006AF7A8 */
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern void func_L39_006DCAD0(s32, s32);

/* from rac4-decomp's func_L00_00708980 */
void func_L39_006AF7A8(void) {
    func_L39_006DCAD0(*(s32 *)(D_L39_0024D760 + 0x50), 0);
}
/* localdecomp:end func_L39_006AF7A8 */

/* localdecomp:start func_L39_006AF7D0 */
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern s32 func_L39_006DE180(s32);
extern s32 func_L01_003A4720(s32);

void func_L39_006AF7D0(void) {
    func_L39_006DE180(*(s32 *)(D_L39_0024D760 + 0x54));
    func_L01_003A4720(*(s32 *)(D_L39_0024D760 + 0x30));
}
/* localdecomp:end func_L39_006AF7D0 */

LINKER_REMNANT("asm/levels", func_L39_006AF808);

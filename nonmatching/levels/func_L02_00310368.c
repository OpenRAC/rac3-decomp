/* PAL near miss (Claude wave S/pal): near miss: 26 words differ with the file's flags.
 * Worker's note: 26 diff (NEEDS divs row 'func_L02_00310368 2'): math right (a=(100-p[0x3D])*2.55 -> D_E0, b=(100-p[0x3E])*2.55 -> D_E4, z0/z1=f40/f44*1024, inv=1/(z1-z0), D_EC=(a*z1-b*z0)*inv, D_E8=(b-a)*D_5EE0*inv); declaring D_L02_001E5EE0 as an array gives retail's lui ...
 */
#include "common.h"

/* localdecomp:start func_L02_00310368 */
__asm__(".extern D_L02_001E00E0_00310368, 16");
__asm__(".extern D_L02_001E00E4_00310368, 16");
__asm__(".extern D_L02_001E00E8_00310368, 16");
__asm__(".extern D_L02_001E00EC_00310368, 16");
__asm__(".extern D_L02_001E5EE0_00310368, 16");
extern f32 D_L02_001E00E0_00310368;
extern f32 D_L02_001E00E4_00310368;
extern f32 D_L02_001E00E8_00310368;
extern f32 D_L02_001E00EC_00310368;
extern f32 D_L02_001E5EE0_00310368[];

void func_L02_00310368(void *arg0) {
    u8 *p = arg0;
    f32 a = (100.0f - (f32)p[0x3D]) * 2.55f;
    f32 b = (100.0f - (f32)p[0x3E]) * 2.55f;
    f32 z0 = *(f32 *)(p + 0x40) * 1024.0f;
    f32 z1 = *(f32 *)(p + 0x44) * 1024.0f;
    f32 inv;

    D_L02_001E00E4_00310368 = b;
    D_L02_001E00E0_00310368 = a;
    inv = 1.0f / (z1 - z0);
    D_L02_001E00EC_00310368 = (a * z1 - b * z0) * inv;
    D_L02_001E00E8_00310368 = (b - a) * D_L02_001E5EE0_00310368[0] * inv;
}
/* localdecomp:end func_L02_00310368 */

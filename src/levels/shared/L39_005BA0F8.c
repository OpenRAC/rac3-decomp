#include "common.h"

/* localdecomp:start func_L39_005BA0F8 */
typedef struct {
    s32 index;
} S_005BA0F8;

__asm__(".extern D_L39_00241180, 16");
__asm__(".extern D_L39_00241184, 16");
__asm__(".extern D_L39_00241188, 16");
__asm__(".extern D_L39_0024118C, 16");
__asm__(".extern D_L39_00241190, 16");
__asm__(".extern D_L39_00241194, 16");
__asm__(".extern D_L39_00241198, 16");
__asm__(".extern D_L39_0024119C, 16");

extern S_005BA0F8 D_001A5810[];
extern f32 D_L39_00241180;
extern f32 D_L39_00241184;
extern f32 D_L39_00241188;
extern f32 D_L39_0024118C;
extern f32 D_L39_00241190;
extern f32 D_L39_00241194;
extern s32 D_L39_00241198;
extern f32 D_L39_0024119C;

void func_L39_005BA0F8(s32 mode) {
    if (mode == 0) {
        D_001A5810[0].index = 0;
        D_L39_00241180 = 1.0f;
        D_L39_00241184 = 1.0f;
        D_L39_00241188 = 1.0f;
        D_L39_0024118C = 0.0166666675f;
        D_L39_00241190 = 0.000277777785f;
        D_L39_00241194 = 4.62962953e-06f;
        D_L39_00241198 = 5;
        D_L39_0024119C = 0.0166666675f;
    } else {
        D_001A5810[0].index = 1;
        D_L39_00241180 = 1.20000005f;
        D_L39_00241184 = 1.44000006f;
        D_L39_00241188 = 0.833333313f;
        D_L39_0024118C = 0.0200000014f;
        D_L39_00241190 = 0.000400000019f;
        D_L39_00241194 = 7.99999998e-06f;
        D_L39_00241198 = 6;
        D_L39_0024119C = 0.0199999996f;
    }
}
/* localdecomp:end func_L39_005BA0F8 */

LINKER_REMNANT("asm/levels", func_L39_005BA218);

#include "common.h"

/* localdecomp:start func_L03_0040E698 */
extern s32 D_L03_001E68B4[];
extern s16 D_001A4DEE[];

/* If the first entry of a global table equals current, stores next minus that entry as a short in a
 * global (D_001A4DEE). */
void func_L03_0040E698(s32 current, s32 next) {
    s32 previous = D_L03_001E68B4[0];
    if (previous == current) {
        previous = next - previous;
        D_001A4DEE[0] = (s16)previous;
    }
}
/* localdecomp:end func_L03_0040E698 */

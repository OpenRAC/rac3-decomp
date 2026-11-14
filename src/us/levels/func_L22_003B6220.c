#include "common.h"

/* localdecomp:start func_L22_003B6220 */
extern void func_00389920(s32);
extern s32 func_00389D18(u8 *, s32, f32);
extern u8 D_L22_002A21B0[];
extern s32 D_L22_001DE558;
__asm__(".extern D_L22_001DE558, 4");

void func_L22_003B6220(u8 *a0) {
    u8 *p;
    u8 *start;
    s32 width;
    u8 *out;
    u8 *end;

    func_00389920(1);
    p = a0;
    start = p;
    width = 0;
    out = D_L22_002A21B0;
    end = out + 0xFF;
    for (; *p != 0 && out != end; out++) {
        *out = *p;
        if (out <= end) {
            out[1] = 0;
        }
        if (func_00389D18(out, 1, 1.0f) <= 20) {
            width += func_00389D18(out, 1, 1.0f);
        } else {
            width += 20;
        }
        if (D_L22_001DE558 < width) {
            if (*p != ' ') {
                if (p == start) {
                    *out = 0;
                    return;
                }
                do {
                    p--;
                    out--;
                } while (*p != ' ' && p != start);
            }
            width = 0;
            if (p == start) {
                break;
            }
            *out = 1;
            p++;
        } else {
            p++;
        }
    }
    *out = 0;
}
/* localdecomp:end func_L22_003B6220 */

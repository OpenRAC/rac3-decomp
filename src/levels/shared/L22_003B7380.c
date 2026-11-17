#include "common.h"

typedef struct {
    u8 p0[4];
    s32 n[16];
    s32 b[16];
    s32 a[16];
    u8 p1[0x188 - 0xC4];
} Rec188;

INCLUDE_ASM("asm/levels", func_L22_003B7380);

/* localdecomp:start func_L22_003B7A70 */
extern void func_0038E150(s32);
extern s32 func_0038E548(u8 *, s32, f32);
extern u8 D_L22_002A21B0[];
extern s32 D_L22_001DE518;
__asm__(".extern D_L22_001DE518, 4");

void func_L22_003B7A70(s32 arg) {
    u8 *p;
    u8 *start;
    s32 width;
    u8 *out;
    u8 *end;

    func_0038E150(1);
    p = (u8 *)arg;
    start = p;
    width = 0;
    out = D_L22_002A21B0;
    end = out + 0xFF;
    for (; *p != 0 && out != end; out++) {
        *out = *p;
        if (*out & 0x80) {
            if (out <= end) {
                out[1] = p[1];
            }
        }
        if (*out & 0x80) {
            if (out < end) {
                out[2] = 0;
            }
        } else {
            if (out <= end) {
                out[1] = 0;
            }
        }
        if (func_0038E548(out, (*out & 0x80) ? 2 : 1, 1.0f) <= 20) {
            width += func_0038E548(out, (*out & 0x80) ? 2 : 1, 1.0f);
        } else {
            width += 20;
        }
        if (D_L22_001DE518 < width) {
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
            if (p == start) {
                break;
            }
            width = 0;
            *out = 1;
        }
        if (*out & 0x80) {
            out++;
            p++;
        }
        p++;
    }
    *out = 0;
}
/* localdecomp:end func_L22_003B7A70 */

INCLUDE_ASM("asm/levels", func_L22_003B7C20);

#include "common.h"

typedef struct {
    s32 id;
    s32 f4;
    s32 kind;
    s32 color;
    u8 pad[32];
} Ent4BD808;

/* localdecomp:start func_L01_004C13B0 */

extern s32 func_L01_0040F598(s32, s32);
extern void func_L01_005170B8_004C13B0(s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);

void func_L01_004C13B0(s32 alpha, Ent4BD808 *list) {
    s32 i;

    for (i = 0; list[i].id != 0; i++) {
        if (list[i].kind != 0) {
            func_L01_005170B8_004C13B0(list[i].id, func_L01_0040F598(list[i].color, (alpha << 24) + 0x808080));
        }
        if (list[i].kind == 4) {
            func_L01_00516AA0(list[i].id, 64, alpha > 64);
        }
    }
}
/* localdecomp:end func_L01_004C13B0 */

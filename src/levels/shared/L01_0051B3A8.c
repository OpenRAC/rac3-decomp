#include "common.h"

/* localdecomp:start func_L01_0051B3A8 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); u8 pad14[0x20 - 0x14]; void (*fn)(void *, void *, void *, s32); } VT_0051B3A8;
typedef struct { u8 b[16]; } Raw16_0051B3A8;
extern s32 func_L01_0051B3A8(u8 *p, f32 *a, f32 *b, f32 *c, f32 *d);
__asm__(".extern D_L01_001DC210_0051B3A8, 4");
extern s32 D_L01_001DC210_0051B3A8;
extern Raw16_0051B3A8 D_L01_001DC110;

s32 func_L01_0051B3A8(u8 *p, f32 *a, f32 *b, f32 *c, f32 *d) {
    Raw16_0051B3A8 in;
    f32 out[4];
    if ((*(VT_0051B3A8 **)(p + 8))->isA(p, D_L01_001DC210_0051B3A8)) {
        in = D_L01_001DC110;
        (*(VT_0051B3A8 **)(p + 8))->fn(p, &in, out, 1);
        *a = out[0];
        *b = out[1];
        *c = out[2];
        *d = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B3A8 */

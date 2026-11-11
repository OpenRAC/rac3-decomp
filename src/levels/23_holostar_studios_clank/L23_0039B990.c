#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

/* localdecomp:start func_L23_0039B990 */
void func_L23_0039B990(u8 *m, V4 pos) {
    u8 *v = *(u8 **)(m + 0x68);
    *(V4 *)(v + 0x550) = pos;
    *(s32 *)(v + 0x3D4) = 2;
    *(s16 *)(v + 0x3B8) = 1;
}
/* localdecomp:end func_L23_0039B990 */

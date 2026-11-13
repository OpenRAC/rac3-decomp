#include "common.h"

/* localdecomp:start func_L39_00637D38 */
typedef int u128_00637D38 __attribute__((mode(TI)));

extern s32 func_0038CB00(void *);
extern void func_L39_00637E10(void *);

void func_L39_00637D38(u8 *g) {
    s32 b;
    s32 h;
    f32 f;

    *(u128_00637D38 *)(g + 0x3D0) = *(u128_00637D38 *)(g + 0xFC0);
    *(f32 *)(g + 0x3E8) = *(f32 *)(g + 0xFD0);
    func_0038CB00(g + 0x3F8);
    func_0038CB00(g + 0x3FA);
    b = g[0x3E7];
    f = 1.0f;
    if (b == 0) {
        *(s16 *)(g + 0x3FA) = 3;
        if (*(s16 *)(g + 0x3F8) != 0) {
            f = (f32)(b / 3);
        }
    } else if (b == 1) {
        *(s16 *)(g + 0x3F8) = 3;
        h = *(s16 *)(g + 0x3FA);
        if (h != 0) {
            f = (f32)((3 - h) / 3);
        }
    }
    *(f32 *)(g + 0xFB4) *= f;
    func_L39_00637E10(g);
    *(s32 *)(g + 0xFD8) = 0;
    *(s32 *)(g + 0xFD4) = 0;
}
/* localdecomp:end func_L39_00637D38 */

#include "common.h"

/* localdecomp:start func_L39_005D8708 */
extern s32 func_L01_005131A0(s32, s32);
extern void func_L01_00512480(s32, f32, f32);
extern void func_L01_00512AB0(s32, s32, s32);

void func_L39_005D8708(s32 a, s32 b, s32 c) {
    f32 f;

    func_L01_005131A0(0x20016, a);
    if (a == 0xED36) {
        f = 0.1f;
        func_L01_00512480(0x20017, f, 0.866f);
        func_L01_00512480(0x20018, f, 0.91f);
    } else if (a == 0xED37) {
        f = 0.1f;
        func_L01_00512480(0x20017, f, 0.854f);
        func_L01_00512480(0x20018, f, 0.89f);
    } else if (a == 0xED4B) {
        func_L01_00512480(0x20017, 0.1f, 0.854f);
    }
    if (b != 0) {
        func_L01_00512AB0(0x20017, 1, 1);
    }
    if (c != 0) {
        func_L01_00512AB0(0x20018, 1, 1);
    }
}
/* localdecomp:end func_L39_005D8708 */

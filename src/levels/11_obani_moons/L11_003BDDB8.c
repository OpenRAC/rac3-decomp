#include "common.h"

/* localdecomp:start func_L11_003BDDB8 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004C7D98(void *, void *);
extern void func_L11_003BDA60(void *, s32, void *, s32, s32, s32, s32, s32, s32, f32, f32);

void func_L11_003BDDB8(u8 *o) {
    u8 buf[16];

    func_L01_004C7D98(o + 16, buf);
    if (func_L01_00447490(o, -1, 0) != 0) {
        func_L11_003BDA60(o, 3, buf, 1, 0x1ED7, 1, 1, 1, 0x80302020, 1.5f, 0.6f);
    }
}
/* localdecomp:end func_L11_003BDDB8 */

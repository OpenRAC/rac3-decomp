#include "common.h"

/* localdecomp:start func_L11_003BDE48 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BDE48;
extern void func_L01_004C7D98(void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L11_003BDA60(u8 *, s32, V4_3BDE48 *, s32, s32, s32, s32, s32, f32, f32, s32);

void func_L11_003BDE48(u8 *a0)
{
    V4_3BDE48 p;

    func_L01_004C7D98(a0 + 0x10, &p);
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L11_003BDA60(a0, 3, &p, 1, 0x1EDD, 1, 1, 1, 2.0f, 1.0f, 0x80302020);
    }
}
/* localdecomp:end func_L11_003BDE48 */

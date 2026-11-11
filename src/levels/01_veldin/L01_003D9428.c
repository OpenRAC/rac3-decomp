#include "common.h"

/* localdecomp:start func_L01_003D9428 */
extern u8 D_L01_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_004AABF0(s32, s32, void *);
extern void func_L01_00451FE0(f32, f32, f32, f32, f32, f32, f32, f32, void *, s32, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void *func_L01_00452460(void *, s32, s32);
extern void func_00439300(void *);

void func_L01_003D9428(u8 *o) {
    u8 *p;
    if (func_L01_00447490(o, -1, 0) != 0) {
        func_004AABF0(0, 0, o);
        func_L01_00451FE0(2.0f, 3.0f, 2.0f, 4.0f, -1.0f, -1.0f, 1.0f, 1.0f, o, 0x7F, D_L01_001D66B0, 255, 180, 0, 0, 35, 0, 3);
        p = func_L01_00452460(o, 0x1E80, 0);
        if (p != 0) *(s32 *)(p + 0x98) = *(s32 *)(*(u8 **)(p + 0x24) + 0x10);
        func_L01_00451E78(o, 1, 0.0f);
        func_00439300(o);
    }
}
/* localdecomp:end func_L01_003D9428 */

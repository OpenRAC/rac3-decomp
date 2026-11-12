#include "common.h"

/* localdecomp:start func_L14_00353F00 */
extern u8 D_L14_002B4E60[];
extern u8 D_L14_001E2140[];
extern s32 *func_L01_0043B568(s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
void func_L14_00353F00(u8 *a0) {
    s32 *r;
    s32 h;
    switch (a0[0x20]) {
    case 0:
        r = func_L01_0043B568(0x194C, 0, 4);
        if (r != 0) {
            ((void (*)(void *, void *))r[0])(a0, D_L14_002B4E60);
        }
        goto trans;
    case 3:
        h = *(u16 *)(a0 + 0x96) + 1;
        *(u16 *)(a0 + 0x96) = h;
        if ((u16)h < 0x1F5) {
            break;
        }
    trans:
        func_L01_004450F0(a0, 1, -1);
    case 1:
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a0, 1);
        *(u16 *)(a0 + 0x34) |= 2;
        break;
    case 2:
        break;
    }
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L14_001E2140, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L14_00353F00 */

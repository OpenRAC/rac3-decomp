#include "common.h"

/* NTSC-U counterpart of func_L14_003622D0 (src/levels/14_koros/L14_003622D0.c) */
#include "vu0.h"

/* localdecomp:start func_L14_003611C8 */
typedef struct {
    u8 pad[0x30];
    s32 f30;
    s32 f34;
} S_3622D0;
extern S_3622D0 D_L14_001E6480_003611C8;
__asm__(".extern D_L14_001DD90C, 4");
__asm__(".extern D_L14_001DD910, 4");
__asm__(".extern D_L14_001DD914, 4");
__asm__(".extern D_L14_001DD918, 4");
extern s32 D_L14_001DD90C;
extern s32 D_L14_001DD910;
extern f32 D_L14_001DD914;
extern f32 D_L14_001DD918;
extern s32 func_L01_004B6C68(void);
extern u8 *func_L10_00403490(s32);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern void func_00388BD0(void *, void *);
extern void func_L14_00360948(u8 *, u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
s32 func_L14_003611C8(u8 *a0, u8 *a1) {
    vu0_v4 v;
    u8 *o;
    f32 f;
    if (func_L01_004B6C68() != 0) {
        if (D_L14_001E6480_003611C8.f30 == 1) {
            if (D_L14_001E6480_003611C8.f34 == D_L14_001DD90C) {
                o = func_L10_00403490(0x1C93);
                if (o == 0) {
                    goto state1;
                }
                vec_sub_ab(&v, o + 0x10, a0 + 0x10);
                v.x += D_L14_001DD914;
                v.z += D_L14_001DD918;
                *(f32 *)(a1 + 0x18) = func_00388A28(func_003887A0(&v), v.z);
                f = func_00388A28(v.x, v.y);
                *(f32 *)(a1 + 0x1C) = f;
                *(f32 *)(a0 + 0xF8) = f;
                func_00388BD0(a0 + 0xC0, a0 + 0xF0);
                *(s32 *)(a1 + 0x24) = 0;
                *(f32 *)(a1 + 0x1F4) = *(f32 *)(a1 + 0x18);
                *(s32 *)(a1 + 0x20) = 0;
                *(f32 *)(a1 + 0x214) = *(f32 *)(a1 + 0x18);
                goto state1;
            }
            if (D_L14_001E6480_003611C8.f34 == D_L14_001DD910) {
                o = func_L10_00403490(0x1C93);
                if (o != 0) {
                    vec_sub_ab(&v, o + 0x10, a0 + 0x10);
                    *(f32 *)(a1 + 0x18) = func_00388A28(func_003887A0(&v), v.z);
                    *(f32 *)(a1 + 0x1C) = func_00388A28(v.x, v.y);
                    func_L01_00441FB8(a0, 3, -1);
                return 1;
                }
            }
        } else {
            *(f32 *)(a1 + 0x18) = 0.0f;
            *(f32 *)(a1 + 0x1C) = 0.0f;
            if (a0[0x20] == 2) {
                func_L01_00441FB8(a0, 3, -1);
                return 1;
            }
            goto check6;
        }
    }
    if (a0[0x20] == 2) {
        func_L14_00360948(a0, a1);
        func_L01_00441FB8(a0, 3, -1);
                return 1;
    }
check6:
    if (a0[0x20] == 6) {
        goto state1;
    }
    return 0;
state1:
    func_L01_00441FB8(a0, 1, -1);
    return 1;
}
/* localdecomp:end func_L14_003611C8 */

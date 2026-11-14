#include "common.h"

/* NTSC-U counterpart of func_L39_00560FC0 (src/levels/shared/L39_005607A0.c) */
#include "vu0.h"

/* localdecomp:start func_L39_00560510 */
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern f32 func_L01_0040C018(void *, void *);
extern s32 func_L39_0055FB68(u8 *, u8 *, s32);
extern s32 func_L39_0055F880(u8 *, u8 *);
extern s32 func_L39_0055F770_00560510(s32);
extern void func_L39_0055F858_00560510(s32);
extern s32 func_L39_0055F748_00560510(s32);
extern void func_L39_0055F798_00560510(s32, s32);
extern void func_L39_0055F7E0(u8 *);
extern s32 D_001A5F78[];
extern u8 *D_L39_0024CF20[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B54C, 4");
__asm__(".extern D_L39_0024B51C, 4");
extern s32 D_L39_0024B54C;
extern f32 D_L39_0024B51C;

s32 func_L39_00560510(u8 *a0, s32 a1) {
    u8 *q = *(u8 **)(a0 + 0x68);
    s32 i;
    u8 *p;
    if (a1 != 0) {
        *(s32 *)q = -1;
        *(u32 *)(q + 4) = 0xFFFFFFFF;
        *(s32 *)(q + 0xC) = D_001A5F78[0];
        return 0;
    }
    switch (a0[0x20]) {
    case 0:
        return 0;
    case 1:
    case 2:
        if (*(s32 *)(q + 0xC) + D_L39_0024B54C < D_001A5F78[0]) {
            func_L01_00441FB8(a0, 4, -1);
            if (func_L39_0055F770_00560510((s32)a0) == 0) {
                func_L39_0055F858_00560510((s32)a0);
            }
            return 0;
        }
        for (i = 0; i < 8; i++) {
            p = D_L39_0024CF20[i];
            if (p != 0 && func_L01_0040C018(p + 0xA0, a0 + 0x10) < D_L39_0024B51C
                && (func_L39_0055FB68(p, a0, 1) != 0 || func_L39_0055F880(p, a0) != 0)) {
                func_L39_0055F798_00560510((s32)a0, *(s32 *)p);
                break;
            }
        }
        return 0;
    case 3:
        if (func_L01_00452EC8(a0) != 0) {
            if (func_L39_0055F748_00560510((s32)a0) == 0) {
                func_L39_0055F7E0(a0);
            }
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L39_00560510 */

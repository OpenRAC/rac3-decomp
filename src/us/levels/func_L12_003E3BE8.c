#include "common.h"

/* NTSC-U counterpart of func_L12_003E5CA8 (src/levels/shared/L12_003E5CA8.c): 0.02 -> 0.0166667 */
/* localdecomp:start func_L12_003E3BE8 */
typedef struct {
    u8 pad[0x100];
} S_003E5CA8;

typedef struct {
    u8 pad00[0x54];
    s32 i54;
    s32 i58;
    f32 f5C;
    u8 b60;
    u8 b61;
    u8 b62;
} V_003E5CA8;

extern s32 func_L12_003E3E68_003E3BE8(u8 *, void *);
extern void func_L12_003E40A0(u8 *m, s32 b);
extern void func_L12_003E4120(void *);
extern s32 func_L01_00452F60(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004026A0(void *, void *);
extern void func_003C26C8(void *);
extern struct Obj_003E6790 *D_L12_001DFD9C;
__asm__(".extern D_L12_001DFD9C, 16");
extern S_003E5CA8 *D_L12_001DFD9C_003E3BE8;
__asm__(".extern D_L12_001DFD9C_003E3BE8, 4");
extern f32 D_L12_001DF320;
__asm__(".extern D_L12_001DF320, 4");
extern f32 D_L12_001DF324_003E3BE8;
__asm__(".extern D_L12_001DF324_003E3BE8, 4");
extern f32 D_L12_001DF328_003E3BE8;
__asm__(".extern D_L12_001DF328_003E3BE8, 4");
extern f32 D_L12_001DF32C_003E3BE8;
__asm__(".extern D_L12_001DF32C_003E3BE8, 4");

void func_L12_003E3BE8(u8 *a0) {
    V_003E5CA8 *v = *(V_003E5CA8 **)(a0 + 0x68);

    if (a0[0x20] == 0) {
        if (func_L12_003E3E68_003E3BE8(a0, v) == 0) {
            return;
        }
    }
    switch (a0[0x20]) {
    case 1:
        if (func_L01_00452F60((S_003E5CA8 *)D_L12_001DFD9C + v->i54)) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 2:
        v->f5C += D_L12_001DF320 * 0.0166666675f;
        if (1.0f <= v->f5C) {
            v->f5C = 1.0f;
            func_L01_00441FB8(a0, 4, -1);
        }
        if (v->f5C > D_L12_001DF328_003E3BE8) {
            v->b60 = 1;
            if (v->b62 == 0) {
                *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            }
        }
        func_L01_004026A0(func_L12_003E4120, a0);
        break;
    case 3:
        v->f5C -= D_L12_001DF324_003E3BE8 * 0.0166666675f;
        if (v->f5C <= 0.0f) {
            v->f5C = 0.0f;
            func_L01_00441FB8(a0, 1, -1);
            if (v->b61 == 0) {
                func_L12_003E40A0(a0, 1);
                return;
            }
        }
        if (v->f5C < D_L12_001DF32C_003E3BE8) {
            v->b60 = 0;
            if (v->b62 == 0) {
                *(s32 *)(a0 + 0x98) = 0;
            }
        }
        if (a0[0x20] != 1) {
            func_L01_004026A0(func_L12_003E4120, a0);
        }
        break;
    case 4:
        if (v->i58 != -1) {
            if (v->i54 == v->i58) {
                if (!func_L01_00452F60(D_L12_001DFD9C_003E3BE8 + v->i58)) {
                    func_L01_00441FB8(a0, 3, -1);
                }
            } else {
                if (func_L01_00452F60(D_L12_001DFD9C_003E3BE8 + v->i58)) {
                    func_L01_00441FB8(a0, 3, -1);
                }
            }
        }
        func_L01_004026A0(func_L12_003E4120, a0);
        break;
    }
    if (v->b60) {
        *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        func_003C26C8(a0);
        *(s32 *)(a0 + 0x98) = 0;
    }
}
/* localdecomp:end func_L12_003E3BE8 */

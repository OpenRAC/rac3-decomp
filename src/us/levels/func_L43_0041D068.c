#include "common.h"

/* NTSC-U counterpart of func_L43_0041D990 (src/levels/shared/L43_0041D990.c) */
/* localdecomp:start func_L43_0041D068 */
extern u8 *D_001DCCCC_sda_0041D068;
typedef struct { u8 pad[0xA8]; s32 a[1]; } T_0041D990;
extern T_0041D990 *D_L43_0034F4AC __attribute__((section(".data")));
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00389380(f32, f32);

void func_L43_0041D068(u8 *a0) {
    u8 *obj = *(u8 **)(a0 + 0x68);
    s32 i;
    s32 j;
    s32 k;
    f32 target;
    f32 cur;

    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        *(u8 *)(a0 + 0x30) = 0xFF;
        if (*(s32 *)(obj + 8) != 0) {
            *(f32 *)(a0 + 0xF0) = -0.43633232f;
        }
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        i = *(s32 *)obj;
        if (i < 0) {
            break;
        }
        j = *(s32 *)(*(u8 **)(D_001DCCCC_sda_0041D068 + (i << 8) + 0x68) + 0x2C);
        if (j < 0) {
            break;
        }
        k = D_L43_0034F4AC->a[j];
        target = 0.0f;
        if (*(s32 *)(obj + 4) == k) {
            target = -0.43633232f;
        }
        if (k == -1) {
            break;
        }
        cur = *(f32 *)(a0 + 0xF0);
        if (cur == target) {
            break;
        }
        if (cur < target) {
            *(f32 *)(a0 + 0xF0) = func_00389380(cur, 0.0014544411096721888f);
        } else {
            *(f32 *)(a0 + 0xF0) = func_00389380(cur, -0.0014544411096721888f);
        }
        if (*(f32 *)(a0 + 0xF0) > 0.0f) {
            *(f32 *)(a0 + 0xF0) = 0.0f;
        }
        if (*(f32 *)(a0 + 0xF0) < -0.43633232f) {
            *(f32 *)(a0 + 0xF0) = -0.43633232f;
        }
        break;
    }
}
/* localdecomp:end func_L43_0041D068 */

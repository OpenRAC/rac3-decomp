#include "common.h"

/* localdecomp:start func_L43_0041D990 */
extern u8 *D_001DCCCC_sda;
typedef struct { u8 pad[0xA8]; s32 a[1]; } T_0041D990;
extern T_0041D990 *D_L43_0034F32C __attribute__((section(".data")));
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);

void func_L43_0041D990(u8 *a0) {
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
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        i = *(s32 *)obj;
        if (i < 0) {
            break;
        }
        j = *(s32 *)(*(u8 **)(D_001DCCCC_sda + (i << 8) + 0x68) + 0x2C);
        if (j < 0) {
            break;
        }
        k = D_L43_0034F32C->a[j];
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
            *(f32 *)(a0 + 0xF0) = func_0038DAB8(cur, 0.0017453294f);
        } else {
            *(f32 *)(a0 + 0xF0) = func_0038DAB8(cur, -0.0017453294f);
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
/* localdecomp:end func_L43_0041D990 */

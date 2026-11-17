#include "common.h"

/* localdecomp:start func_L07_0035CA80 */
extern s32 D_001E0F90;

void func_L07_0035CA80(s32 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((&D_001E0F90)[i] == arg0) {
            (&D_001E0F90)[i] = 0;
            return;
        }
    }
}
/* localdecomp:end func_L07_0035CA80 */

/* localdecomp:start func_L07_0035CAB8 */
typedef struct St_0035CAB8 {
    u8 pad0;
    u8 b1;
    u8 pad2[106];
    f32 f6C;
    u8 pad70[128];
} St_0035CAB8;

extern St_0035CAB8 D_L07_002C72C0[];
extern u8 D_001425C0[];
extern s32 D_L07_001DD6A8;
extern void func_L07_0035CA80(s32);
extern void func_L01_004C7D98(u8 *, u8 *);
extern u8 *func_L01_00392908(u8 *, u8 *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                             s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(u8 *);

void func_L07_0035CAB8(u8 *arg0) {
    u8 buf[16];
    u8 x;

    x = D_L07_002C72C0[D_001425C0[87]].b1;
    if (x != 0) {
        func_L01_004C7D98(arg0 + 16, buf);
        func_L01_00392908(arg0 + 16, buf);
    } else {
        func_L01_003303B8(arg0 + 16, 0, 0x14, 0x14, 0x14, 0x14, 0, 2, 0.4f, 0.0f, 5.0f, 2.0f,
                          1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                          0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    func_L07_0035CA80(arg0);
    D_L07_001DD6A8--;
    func_003C2880(arg0);
}
/* localdecomp:end func_L07_0035CAB8 */

INCLUDE_ASM("asm/levels", func_L07_0035CC10);

/* localdecomp:start func_L07_0035D080 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L07_001E8C18[4];
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

void func_L07_0035D080(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];

    *(u128_t *)v = *(u128_t *)(a0 + 0x10);
    v[2] = v[2] + 0.1f;
    *(u128_t *)w = *(u128_t *)(s + 0x190);
    v[2] = v[2] + *(f32 *)(s + 0x38);
    w[2] = w[2] + *(f32 *)(s + 0x38);
    if (func_003D3CB0(v, w, 0x10, a0, 0) != 0) {
        if (D_L07_001E8C18[0] == 0) {
            return;
        }
        if (D_L07_001E8C18[0] != *(s32 *)(s + 0x1D0)) {
            return;
        }
    }
    *(u128_t *)(s + 0x180) = *(u128_t *)(s + 0x190);
    *(u128_t *)(s + 0x1A0) = *(u128_t *)(s + 0x190);
}
/* localdecomp:end func_L07_0035D080 */

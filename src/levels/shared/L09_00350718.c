#include "common.h"

typedef int Q __attribute__((mode(TI)));
typedef int U64 __attribute__((mode(DI)));
typedef struct { u8 pad[0x30]; u8 a,b; short c; u16 flags; u16 pad36; U64 data; } M;

/* localdecomp:start func_L09_00350718 */
/* log:
 * v1: modelled on func_L08_00310D78 (case 0 / case 1 shape)
 */
#include "vu0.h"

extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L09_00350B30(u8 *);
extern u8 *D_L09_001E98D8 __attribute__((section(".data")));

void func_L09_00350718(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    s32 hit;
    u8 *g;
    u8 *g2;
    vu0_v4 v90;
    u8 vA0[0x30] __attribute__((aligned(16)));
    vu0_v4 vD0;

    *(s32 *)(st + 0x24) += 1;
    if (*(s32 *)(st + 0x24) > 0xF0) {
        func_L01_004450F0(a0, 1, -1);
    }
    switch (a0[0x20]) {
    case 0:
        vec_add_ba(&v90, a0 + 0x10, st);
        func_L01_00446760(vA0, a0, 0x10001, st, *(f32 *)(st + 0x14));
        *(u16 *)(vA0 + 0x1A) = *(u16 *)(a0 + 0xAA);
        func_L01_004CB320();
        hit = func_003D3CB0(a0 + 0x10, &v90, 0, a0, vA0);
        if (hit != 0) {
            g = D_L09_001E98D8;
            if (g != 0 && *(s16 *)(g + 0xAA) == 0x186D && g[0x20] != 2 && g[0x20] != 5) {
                g[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit != 0) {
            g2 = D_L09_001E98D8;
            if (g2 == 0 || g2 != *(u8 **)(st + 0x10)) {
                func_L01_004450F0(a0, 1, -1);
                return;
            }
        }
        *(vu0_v4 *)(a0 + 0x10) = v90;
        func_0038CE20(&vD0, st, -0.5f);
        break;
    case 1:
        func_L01_003303B8(a0 + 0x10, 0, 5, 5, 5, 5, 15, 0, 0.25f, 0.0f, 0.0f, 2.0f,
                          0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003C2880(a0);
        return;
    }
    func_L01_00404A10(func_L09_00350B30, a0);
}
/* localdecomp:end func_L09_00350718 */

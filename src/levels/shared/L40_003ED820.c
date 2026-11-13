#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L40_003ED820 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003ED820;
extern u8 *D_L40_0025B998[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L40_003ED820(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V_003ED820 a;
    V_003ED820 b;

    a = *(V_003ED820 *)(m + 0x10);
    b = *(V_003ED820 *)(v + 0x270);
    a.z += *(f32 *)(v + 0x78);
    b.z += *(f32 *)(v + 0x78);
    if (func_0038CF00(&a, &b) < 30.0f && func_003D3CB0(&a, &b, 0x10, m, 0) == 0) {
        *(u128_t *)(v + 0x260) = *(u128_t *)(v + 0x270);
        *(u128_t *)(v + 0x280) = *(u128_t *)(v + 0x270);
        return;
    }
    if (D_L40_0025B998[0] != 0 && D_L40_0025B998[0] == *(u8 **)(v + 0x230)) {
        *(u128_t *)(v + 0x260) = *(u128_t *)(v + 0x270);
        *(u128_t *)(v + 0x280) = *(u128_t *)(v + 0x270);
    }
}
/* localdecomp:end func_L40_003ED820 */

/* localdecomp:start func_L40_003ED8F8 */
extern s32 D_L40_00241118;
extern s32 D_L40_00242914;
extern void func_L01_00451F60(s32, s32, s32);

s32 func_L40_003ED8F8(u8 *a0, s32 a1) {
    s32 id;
    u8 *p;
    s32 v;

    p = *(u8 **)(a0 + 144);
    id = 2250;
    if (a1 != 0) {
        id = 2244;
    }
    if (p != 0) {
        v = p[9417];
        if (v != D_L40_00241118) {
            return 0;
        }
        if (D_L40_00242914 == 0) {
            func_L01_00451F60(id, 4, 0);
        } else {
            func_L01_00451F60(id, 4, v);
        }
    }
    return 0;
}
/* localdecomp:end func_L40_003ED8F8 */

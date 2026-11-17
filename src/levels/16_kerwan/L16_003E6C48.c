#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L16_003E6C48 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L16_003E7350(u8 *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_L16_001DF558;
extern vu0_v4 D_L16_001D66B0 __attribute__((section(".sdata")));

typedef struct {
    s32 unk0;
    u8 *parent;
    s32 unk8;
    u8 padC[4];
    s32 unk10;
    f32 unk14;
    f32 unk18;
    s32 unk1C;
    u128_t unk20;
} V_003E6C48;

u8 *func_L16_003E6C48(u8 *a0, u128_t *a1, f32 a2, f32 a3) {
    u8 *m;
    V_003E6C48 *v;
    s32 t;

    m = func_003C24B0(0x1D01, 0x80);
    if (m != 0) {
        m[0x30] = 0xFF;
        v = *(V_003E6C48 **)(m + 0x68);
        *(u16 *)(m + 0x32) = *(u16 *)(a0 + 0x32);
        *(u128_t *)(m + 0x10) = *a1;
        v->parent = a0;
        v->unk14 = a3;
        t = D_L16_001DF558;
        v->unk18 = a2;
        v->unk1C = t << 5;
        v->unk0 = 0;
        v->unk8 = -1;
        v->unk10 = 0;
        D_L16_001DF558 = (t + 1) % 8;
        qzero(&v->unk20);
        func_L16_003E7350(m, &D_L16_001D66B0, 1);
        func_L01_004450F0(m, 0, -1);
    }
    return m;
}
/* localdecomp:end func_L16_003E6C48 */

INCLUDE_ASM("asm/levels", func_L16_003E6D40);

/* localdecomp:start func_L16_003E7280 */
extern f32 func_0038CEA8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_L16_001DFC40;
__asm__(".extern D_L16_001DFC40, 16");
extern s32 D_L16_001DF4D8;

void func_L16_003E7280(u8 *a0, u128_t *a1, u128_t *a2, s32 a3) {
    u8 *p = *(u8 **)(a0 + 0x68);
    *(s32 *)(p + 8) = D_L16_001DFC40 + D_L16_001DF4D8;
    *(u128_t *)(p + 0x20) = *a1;
    *(u128_t *)(p + 0x30) = *a2;
    *(f32 *)(p + 0xC) = func_0038CEA8(a1);
    *(s32 *)(p + 0x10) = a3;
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L16_003E7280 */

/* localdecomp:start func_L16_003E7300 */
void func_L16_003E7300(u8 *a0, u128_t *a1, u128_t *a2, f32 f) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (1.0f < f) { *(f32 *)p = f; } else { *(f32 *)p = f; }
    vec_sub_ab(p + 0x20, a1, a0 + 0x10);
    *(u128_t *)(p + 0x30) = *a2;
}
/* localdecomp:end func_L16_003E7300 */

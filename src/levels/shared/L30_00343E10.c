#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_00343E10);

/* localdecomp:start func_L30_00344188 */
typedef struct {
    u8 pad0[0x80];
    f32 x80;
    u8 pad84[4];
    f32 x88;
    u8 pad8C[0x35C - 0x8C];
    u8 *x35C;
    u8 pad360[0x25C4 - 0x360];
    s32 x25C4;
} H_00344188;
__asm__(".extern D_L30_001DCECC, 4");
extern s32 D_L30_001DCECC;
extern u8 *D_L30_00283960[];
extern H_00344188 D_001A4BE0;
extern void func_L30_00343AC8(u8 *, s32, f32 *, f32 *);
void func_L30_00344188(f32 a) {
    s32 i;
    u8 *o;
    u8 *v;
    f32 r[2];
    f32 hx;
    f32 vx;
    for (i = 0; i < D_L30_001DCECC; i++) {
        f32 zero = 0.0f;

        o = D_L30_00283960[i];
        v = *(u8 **)(o + 0x68);
        if ((u32)(D_001A4BE0.x25C4 - 0xA8) < 3) {
            a = 1.0f;
        }
        if (a != zero) {
            if (*(s32 *)(v + 0x198) == 2) {
                *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
            } else if (*(s32 *)(v + 0x198) == 1) {
                *(s32 *)(o + 0x98) = 0;
            }
            *(s32 *)(v + 0x198) = 0;
        } else if (*(s32 *)(v + 0x198) == 0) {
            if (*(s32 *)(o + 0x98) != 0) {
                *(s32 *)(v + 0x198) = 2;
            } else {
                *(s32 *)(v + 0x198) = 1;
            }
            func_L30_00343AC8(o, 0, &r[0], &r[1]);
            if (D_001A4BE0.x88 < *(f32 *)(v + 0x138) && D_001A4BE0.x35C != o) {
                hx = D_001A4BE0.x80;
                vx = *(f32 *)(v + 0x130);
                if (__builtin_fabsf(hx - vx) < r[0]) {
                    *(s32 *)(o + 0x98) = 0;
                } else if (v[0x1B4] == 0 && vx < hx) {
                    *(s32 *)(o + 0x98) = 0;
                } else if (v[0x1B3] == 0 && hx < vx) {
                    *(s32 *)(o + 0x98) = 0;
                }
            }
        }
    }
}
/* localdecomp:end func_L30_00344188 */

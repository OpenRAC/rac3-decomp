#include "common.h"

/* NTSC-U counterpart of func_L08_00311438 (src/levels/08_aquatos/L08_00310D78.c): 0.251327 -> 0.20944; 0.753982 -> 0.628319 */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L08_00311088 */
extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern u8 D_001A30B0[];

u8 *func_L08_00311088(u8 *a0, u128_t *a1, u128_t *a2, s32 a3, s32 a4, f32 a5) {
    u8 *p;
    u8 *q;
    u8 *e;
    s32 idx;
    p = func_003C24B0(0xB7F, 0x80);
    if (p != 0) {
        p[0x30] = 0xFF;
        *(s16 *)(p + 0x32) = 0xFF;
        p[0x31] = 1;
        p[0x20] = 0;
        q = *(u8 **)(p + 0x68);
        *(long *)(p + 0x38) = *(long *)(a0 + 0x38);
        *(u128_t *)(p + 0x10) = *a2;
        *(u128_t *)q = *a1;
        *(u8 **)(q + 0x10) = a0;
        *(f32 *)(q + 0x14) = a5;
        *(f32 *)(q + 0x18) = func_00382538();
        *(f32 *)(q + 0x1C) = func_003824E0(0.209439531f, 0.628318548f);
        *(f32 *)(q + 0x20) = 1.0f;
        *(s32 *)(q + 0x24) = a4;
        p[0x23] = 0x5D;
        *(u16 *)(p + 0x34) |= 0x100;
        *(f32 *)(p + 0x2C) = func_003824E0(0.01f, 0.0125f) * *(f32 *)(q + 0x20);
        idx = *(s32 *)(q + 0x28);
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(u8 **)(e + 0xDC) != p || e[0xD0] == 0) {
                *(s32 *)(q + 0x28) = func_003A52A0(0, 4, p);
            }
        } else {
            *(s32 *)(q + 0x28) = func_003A52A0(0, 4, p);
        }
    }
    return p;
}
/* localdecomp:end func_L08_00311088 */

#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
extern u8 D_1A4C60[];

/* localdecomp:start func_L32_003A4270 */
extern f32 D_L32_001DE9C4;
extern f32 D_L32_001DE930;

void func_L32_003A4270(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 hi = *(f32 *)(p + 0x178) + D_L32_001DE9C4;
    f32 lo = *(f32 *)(p + 0x180) - D_L32_001DE9C4;
    s32 mode;

    *(f32 *)(p + 0xE4) = *(f32 *)((u8 *)arg0 + 0x14);
    *(f32 *)(p + 0xE8) = *(f32 *)(p + 0x174);
    mode = *(s32 *)(p + 0xF4);
    if (mode == 0 || mode == 2 || mode == -1) {
        if (*(f32 *)((u8 *)arg0 + 0x10) < *(f32 *)(p + 0x178) + D_L32_001DE9C4 + D_L32_001DE930) {
            *(f32 *)(p + 0xE0) = lo;
        } else if (*(f32 *)(p + 0x180) - D_L32_001DE9C4 - D_L32_001DE930 < *(f32 *)((u8 *)arg0 + 0x10)) {
            *(f32 *)(p + 0xE0) = hi;
        } else {
            *(f32 *)(p + 0xE0) = *(s32 *)(p + 0x100) != 0 ? hi : lo;
        }
    } else if (mode == 1) {
        if (*(s32 *)(p + 0xFC) != 0) {
            *(f32 *)(p + 0xE0) = *(f32 *)D_1A4C60;
        } else {
            *(f32 *)(p + 0xE0) = *(f32 *)((u8 *)arg0 + 0x10) < *(f32 *)D_1A4C60 ? hi : lo;
        }
    }
}
/* localdecomp:end func_L32_003A4270 */

/* localdecomp:start func_L32_003A4360 */
extern f32 D_L32_001DE9C0;
extern f32 D_L32_001DE9C4;
extern f32 func_003824E0(f32, f32);

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A4360;

void func_L32_003A4360(void *arg0) {
    u8 *a0 = arg0;
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 lo = *(f32 *)(p + 0x178) + D_L32_001DE9C4;
    f32 hi = *(f32 *)(p + 0x180) - D_L32_001DE9C4;
    f32 t;
    s32 s;

    *(V_003A4360 *)(p + 0xE0) = *(V_003A4360 *)(a0 + 0x10);
    *(f32 *)(p + 0xE8) = *(f32 *)(p + 0x174);
    s = *(s32 *)(p + 0xF4);
    if (s == 1) {
        if (*(f32 *)(a0 + 0x10) < *(f32 *)D_1A4C60) {
            t = *(f32 *)(a0 + 0x10) - D_L32_001DE9C0;
            if (t < *(f32 *)(p + 0x178) + D_L32_001DE9C4) {
                t = *(f32 *)(p + 0x178) + D_L32_001DE9C4;
            }
            if (*(f32 *)(p + 0xE0) < lo || t < *(f32 *)(p + 0xE0)) {
                *(f32 *)(p + 0xE0) = func_003824E0(lo, t);
            }
        } else {
            t = *(f32 *)(a0 + 0x10) + D_L32_001DE9C0;
            if (*(f32 *)(p + 0x180) - D_L32_001DE9C4 < t) {
                t = *(f32 *)(p + 0x180) - D_L32_001DE9C4;
            }
            if (*(f32 *)(p + 0xE0) < t || hi < *(f32 *)(p + 0xE0)) {
                *(f32 *)(p + 0xE0) = func_003824E0(t, hi);
            }
        }
    } else if (s == 2 || s == 0 || s == -1) {
        *(f32 *)(p + 0xE0) = *(f32 *)(a0 + 0x10) < *(f32 *)D_1A4C60 ? lo : hi;
    }
}
/* localdecomp:end func_L32_003A4360 */

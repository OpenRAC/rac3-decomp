#include "common.h"

/* localdecomp:start func_L04_003E51D0 */
typedef struct { u8 pad_0[0xB0]; u8 flag; } MobyA_003E51D0;
typedef struct { u8 pad_0[0x70]; s32 index; } MobyB_003E51D0;

extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern u8 D_001BBC40[];
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 func_L01_00456250(u8 *);

s32 func_L04_003E51D0(MobyA_003E51D0 *a0, MobyB_003E51D0 *a1) {
    s32 v;

    v = a1->index;
    if (v >= 0) {
        if (func_L01_00456250(D_L04_001DFD9C + (v << 8)) != 0) {
            return 1;
        }
    }
    if (a0->flag != 0xFF) {
        if ((D_001BBC40[a0->flag + (D_001D545C_sda << 4)] & 0x80) != 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L04_003E51D0 */

INCLUDE_ASM("asm/levels", func_L04_003E5250);

INCLUDE_ASM("asm/levels", func_L04_003E5788);

/* localdecomp:start func_L04_003E5898 */
extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern s32 D_L04_001DFDD8;

s32 func_L04_003E5898(u8 *a0, s32 a1) {
    u16 *p;
    u8 *e;
    p = D_L04_0021C9A0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L04_001DFDD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[a0[0x21]])) {
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (e[0x43] != a1) return 0;
    }
    return 1;
}
/* localdecomp:end func_L04_003E5898 */

INCLUDE_ASM("asm/levels", func_L04_003E5940);

/* localdecomp:start func_L04_003E5D88 */
typedef struct { f32 f[6]; } V_003E5D88;

extern u8 D_L04_001DF278[];
extern s32 D_001DF270_sda;
__asm__(".extern D_001DF270_sda, 4");
extern s32 func_00382468(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_004AB048(s32, s32);

void func_L04_003E5D88(void *a0) {
    u8 *s0;
    V_003E5D88 v;
    s32 idx;
    s32 r;
    f32 f20;
    f32 val;

    s0 = *(u8 **)((u8 *)a0 + 0x68);
    v = *(V_003E5D88 *)D_L04_001DF278;
    idx = func_00382468(5);
    f20 = 1024.0f;
    val = *(f32 *)(s0 + 0x8C);
    if (idx == D_001DF270_sda) {
        idx++;
    }
    D_001DF270_sda = idx;
    if (val != 0.0f) {
        f20 = 512.0f;
    }

    r = func_003A52A0(0, 0, a0);
    if (r != -1) {
        func_L01_004AB048(r, (s32)(f20 * v.f[idx]));
    }
}
/* localdecomp:end func_L04_003E5D88 */

INCLUDE_ASM("asm/levels", func_L04_003E5E78);

/* localdecomp:start func_L04_003E5FB8 */
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 D_001DF294;
extern f32 D_001DF298;

void func_L04_003E5FB8(u8 *arg0, f32 fparg0) {
    u8 *s0;
    f32 t;
    f32 x;

    s0 = *(u8 **)(arg0 + 0x68);
    t = func_0038DB00(fparg0, *(f32 *)(arg0 + 0xF0));
    x = *(f32 *)(s0 + 0x78);
    *(f32 *)(s0 + 0x78) = x + (t * D_001DF294 + x * D_001DF298);
    *(f32 *)(arg0 + 0xF0) = func_0038DAB8(*(f32 *)(arg0 + 0xF0), *(f32 *)(s0 + 0x78));
}
/* localdecomp:end func_L04_003E5FB8 */

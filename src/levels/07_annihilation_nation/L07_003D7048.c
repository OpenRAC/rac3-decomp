#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003D7048);

/* localdecomp:start func_L07_003D7350 */
typedef int Quad_003D7350 __attribute__((mode(TI)));
extern u8 D_L07_001DE890;
__asm__(".extern D_L07_001DE890, 1");
extern s32 D_L07_002A3740[];
extern s32 D_L07_002A38C0[];
extern f32 D_L07_002A3A40[][2];
void func_L07_003D7350(u8 *obj)
{
    extern u8 *func_003C24B0(s32, s32);
    extern void func_003C7C38(void *);
    extern void func_L07_003D74A0(u8 *);
    u8 *state;
    u8 *p;
    s32 i;
    if (obj[0x20] == 0) {
        state = *(u8 **)(obj + 0x68);
        if (!D_L07_001DE890) {
            for (i = 0; i < 96; i++) {
                D_L07_002A3740[i] = -1;
                D_L07_002A38C0[i] = 0x20FF8000;
                D_L07_002A3A40[i][0] = (i & 2) >> 1;
                D_L07_002A3A40[i][1] = i & 1;
            }
            D_L07_001DE890 = 1;
        }
        p = func_003C24B0(0x1D2D, 0x80);
        if (p) {
            u8 *model = *(u8 **)(p + 0x24);
            p[0x31] = 1;
            *(u16 *)(p+0x32) = *(u16 *)(obj+0x32);
            p[0x30] = obj[0x30];
            *(unsigned long *)(p+0x38) = *(unsigned long *)(obj+0x38);
            *(f32 *)(p+0x2C) = *(f32 *)(model+0x24) * 1.6f;
            *(Quad_003D7350 *)(p+0x10) = *(Quad_003D7350 *)(obj+0x10);
            *(Quad_003D7350 *)(p+0xF0) = *(Quad_003D7350 *)(obj+0xF0);
            func_003C7C38(p);
        }
        *(u8 **)(state+0x10) = p;
        *(void (**)(u8 *))(state+4) = func_L07_003D74A0;
        func_L07_003D74A0(obj);
    }
}
/* localdecomp:end func_L07_003D7350 */

/* localdecomp:start func_L07_003D74A0 */
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C7C38(void *);
extern void func_L01_004AA760(s32, void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003D74A0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 r;

    *(s32 *)(s + 0x14) = 0;
    r = func_003C3BE8(3.1415927f, *(f32 *)(s + 0x14), *(f32 *)(s + 0x14));
    *(f32 *)(a0 + 0xF0) = r;
    *(f32 *)(*(u8 **)(s + 0x10) + 0xF0) = r;
    func_003C7C38(*(void **)(s + 0x10));
    func_L01_004AA760(1, a0);
    s[8] = 1;
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L07_003D74A0 */

INCLUDE_ASM("asm/levels", func_L07_003D7520);

/* localdecomp:start func_L07_003D7628 */
extern void func_L07_003D7680(void *, f32, f32, s32);

void func_L07_003D7628(void *arg0) {
    func_L07_003D7680(arg0, 2.5f, 0.0f, 8);
    func_L07_003D7680(arg0, 1.2f, 0.5235988f, 6);
}
/* localdecomp:end func_L07_003D7628 */

INCLUDE_ASM("asm/levels", func_L07_003D7680);

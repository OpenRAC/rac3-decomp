#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_00366800);

INCLUDE_ASM("asm/levels", func_L04_00366AC8);

INCLUDE_ASM("asm/levels", func_L04_00366DC8);

/* localdecomp:start func_L04_00367068 */
extern void func_L04_003672E8(void *);
extern void func_L04_00367150(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_0038CAD0(void *);

void func_L04_00367068(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);

    switch (a0[0x20]) {
    case 0:
        *(s32 *)p = 8;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00447490(a0, -1, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        func_L04_003672E8(a0);
        func_L01_004450F0(a0, 3, -1);
        break;
    case 3:
        if (func_0038CAD0(p) != 0) {
            func_L04_00367150(a0);
        }
        break;
    }
    *(u8 *)(a0 + 0xA8) = 0xFF;
}
/* localdecomp:end func_L04_00367068 */

/* localdecomp:start func_L04_00367150 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_367150;
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

void func_L04_00367150(void *a0) {
    u8 *p = (u8 *)a0;
    V4_367150 a;
    V4_367150 b;
    s32 r;
    s32 *q;

    q = *(s32 **)(p + 0x68);
    b = (V4_367150){0.0f, 0.0f, 0.0f, 0.0f};
    a = (V4_367150){0.0f, 0.0f, 5.0f, 0.0f};
    b.x = 0.040000003f;
    b.z = 0.040000003f;
    func_0038D000(&b, &b, p + 0xC0);
    r = func_00382498(3, 6);
    func_L02_003E2E38(p, &a, 0.0f, &b, r, 0, 0, 0.040000003f, 0.5f, 15.0f, 1.0f);
    b.x = -0.040000003f;
    b.z = 0.048000004f;
    func_0038D000(&b, &b, p + 0xC0);
    r = func_00382498(3, 6);
    func_L02_003E2E38(p, &a, 0.0f, &b, r, 1, 0, 0.040000003f, 0.5f, 15.0f, 1.0f);
    r = func_00382498(0x5A, 0xB4);
    *q = (r * 5 + 2) / 6;
}
/* localdecomp:end func_L04_00367150 */

INCLUDE_ASM("asm/levels", func_L04_003672E8);

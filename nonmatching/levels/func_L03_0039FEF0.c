/* near miss (level 3, Starship Phoenix): needs real VU0: case 11 contains lqc2 / vadd.xyz / sqc2 at 0x3A00E8-0x3A0110 (not reachable from plain C, inline asm is not allowed; the todo bucket says switch because it classifies by the jump table first); the C approximates it with an lq/sq copy plus float adds, and a $s1/$s2 swap (retail keeps obj in $17, s in $18) shifts about 100 lines (174 counted); every other case is structurally identical */
#include "common.h"

/* localdecomp:start func_L03_0039FEF0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0039FEF0;
extern void func_003C3A10();
extern void func_L03_0032DA08(void *);
extern void func_L03_0032D6B8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0044E318();
extern void func_L01_0044E340(void *, s32, s32, f32);
extern void func_L01_004450F0();

void func_L03_0039FEF0(u8 *obj, s32 st) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *q;
    V4_0039FEF0 v;
    switch (st) {
    case 1:
        if (obj[0x43] != 2) func_003C3A10(obj, 2, 0, 0);
        break;
    case 2:
        if (obj[0x43] != 2) func_003C3A10(obj, 2, 0, 0);
    case 3:
        *(u16 *)(obj + 0x34) |= 0x5000;
        break;
    case 4:
        break;
    case 5:
        func_L03_0032DA08(obj);
        if (obj[0x43] != 2) func_003C3A10(obj, 2, 0, 2);
        break;
    case 6: {
        u8 *p = s + 0x150;
        *(f32 *)(p + 0x20) = 0.016f;
        *(f32 *)(p + 0x28) = 0.16f;
        *(s32 *)(p + 0x38) &= ~0x10;
        *(f32 *)(p + 0x24) = 0.016f;
        if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 2);
        break; }
    case 7:
        func_L03_0032D6B8(obj);
        if (obj[0x43] != 4) func_003C3A10(obj, 4, 0, 2);
        break;
    case 8:
        if (obj[0x43] != 5) func_003C3A10(obj, 5, 0, 2);
        break;
    case 9: {
        u8 *p = s + 0x150;
        func_L03_0032D6B8(obj);
        *(f32 *)(p + 0x20) = 0.0012f;
        *(f32 *)(p + 0x28) = 0.060000002f;
        *(s32 *)(p + 0x38) |= 0x10;
        *(f32 *)(p + 0x24) = 0.0012f;
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 7);
        break; }
    case 10:
        s[0x45A] = 0;
        if (obj[0x43] != 6) func_003C3A10(obj, 6, 0, 7);
        break;
    case 11:
        q = s + 0x2F0;
        func_0038CF68(&v, obj + 0xC0, 6.0f);
        *(V4_0039FEF0 *)(s + 0x440) = *(V4_0039FEF0 *)(obj + 0x10);
        ((V4_0039FEF0 *)(s + 0x440))->x += v.x;
        ((V4_0039FEF0 *)(s + 0x440))->y += v.y;
        ((V4_0039FEF0 *)(s + 0x440))->z += v.z;
        func_L01_0045BD78(obj, 0.12000000476f, 1.0000001f, 0.0012566371588f, 0.06283186f);
        *(s32 *)(s + 0x188) |= 0x10;
        func_L01_0044E318(obj, q);
        func_L01_0044E340(q, 0x40, 1, 1.1f);
        func_L01_0044E340(q, 0x30, 2, 1.1f);
        func_L01_0044E340(q, 0x20, 3, 1.1f);
        func_L01_0044E340(q, 0x10, 4, 1.1f);
        if (obj[0x43] != 7) func_003C3A10(obj, 7, 0, 2);
        break;
    case 12:
        if (obj[0x43] != 8) func_003C3A10(obj, 8, 0, 2);
        break;
    case 13: {
        u8 *p = s + 0x150;
        *(f32 *)(p + 0x20) = 0.0012f;
        *(f32 *)(p + 0x28) = 0.060000002f;
        *(s32 *)(p + 0x38) |= 0x10;
        *(f32 *)(p + 0x24) = 0.0012f;
        if (obj[0x43] != 1) func_003C3A10(obj, 1, 5, 2);
        break; }
    case 14: {
        u8 *p = s + 0x150;
        *(f32 *)(p + 0x20) = 0.00080000003799f;
        *(f32 *)(p + 0x28) = 0.04000000283f;
        *(s32 *)(p + 0x38) |= 0x10;
        *(f32 *)(p + 0x24) = 0.00080000003799f;
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 2);
        break; }
    }
    func_L01_004450F0(obj, st, -1);
}
/* localdecomp:end func_L03_0039FEF0 */

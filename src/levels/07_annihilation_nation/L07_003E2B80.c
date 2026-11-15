#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003E2B80);

INCLUDE_ASM("asm/levels", func_L07_003E2DB0);

/* localdecomp:start func_L07_003E2EC8 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_0038CF68(void *, void *, f32);

void func_L07_003E2EC8(u8 *arg0) {
    u8 *p;
    s32 r;

    p = *(u8 **)(arg0 + 0x68);
    if (arg0[0x20] != 4) {
        r = func_L01_00447490(arg0, -1, 0);
        if (r != 0) {
            func_0038CF68(p + 0x220, (void *)(r + 0x10), 0.50000006f);
            *(s16 *)(p + 0x25C) = 0x2A;
            arg0[0x30] = 0xFF;
            func_L01_004450F0(arg0, 4, -1);
        }
    }
}
/* localdecomp:end func_L07_003E2EC8 */

/* localdecomp:start func_L07_003E2F48 */
extern void func_L01_0045A898(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern u8 D_001A4BE0[];

void func_L07_003E2F48(u8 *arg0) {
    u8 *p;
    u8 *q;
    u8 *h;
    f32 t;
    f32 y;
    f32 ang;
    f32 d;

    p = *(u8 **)(arg0 + 0x68);
    q = arg0 + 0xF8;

    *(f32 *)(arg0 + 0x18) = *(f32 *)(arg0 + 0x18) - *(f32 *)(p + 0x274);
    func_L01_0045A898(*(f32 *)(arg0 + 0xF8));
    t = func_0038DAB8(*(f32 *)(p + 0x270), *(f32 *)(p + 0x278));
    *(f32 *)(p + 0x270) = t;
    *(f32 *)(p + 0x274) = func_0038D0B0(t) * *(f32 *)(p + 0x27C);
    y = *(f32 *)(arg0 + 0x18) + *(f32 *)(p + 0x274);
    *(f32 *)(arg0 + 0x18) = y;

    h = D_001A4BE0;
    ang = func_0038D160(*(f32 *)(h + 0x80) - *(f32 *)(arg0 + 0x10),
                        *(f32 *)(h + 0x84) - *(f32 *)(arg0 + 0x14));
    func_L01_00448890(q, p + 0xE4, 0, ang, 0.0025132743f, 0.0025132743f,
                  0.12566371f);

    d = func_0038CF38(arg0 + 0x10, h + 0x80);
    *(f32 *)(p + 0x184) = -func_0038D160(d, *(f32 *)(h + 0x88) - *(f32 *)(arg0 + 0x18));
}
/* localdecomp:end func_L07_003E2F48 */

INCLUDE_ASM("asm/levels", func_L07_003E3050);

/* localdecomp:start func_L07_003E31F8 */
void func_L07_003E31F8(u8 *arg0) {
    f32 k = 0.96400005f;
    *(f32 *)(arg0 + 0xF0) *= k;
    *(f32 *)(arg0 + 0xF4) *= k;
}
/* localdecomp:end func_L07_003E31F8 */

INCLUDE_ASM("asm/levels", func_L07_003E3220);

INCLUDE_ASM("asm/levels", func_L07_003E3388);

INCLUDE_ASM("asm/levels", func_L07_003E3458);

/* localdecomp:start func_L07_003E34D8 */
extern void func_L07_003BB148(void *);
extern void func_L01_004AA7E8(void *, s32);

void func_L07_003E34D8(u8 *arg0) {
    func_L07_003BB148(arg0);
    *(s32 *)(arg0 + 0x98) = 0;
    arg0[0xA8] = 0xFF;
    *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(arg0, 1);
    *(u16 *)(arg0 + 0x34) |= 6;
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003E34D8 */

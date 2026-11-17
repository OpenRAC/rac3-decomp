#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L07_003D48D0);

INCLUDE_ASM("asm/levels", func_L07_003D4DB8);

/* localdecomp:start func_L07_003D5008 */
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C7C38(void *);
extern void func_L07_003D5170(u8 *);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D5008;

void func_L07_003D5008(u8 *a0) {
    u8 *p;
    u8 *m;
    u8 *q;
    s32 i;
    f32 ang;
    V4_3D5008 off;

    if (a0[0x20] != 0) {
        return;
    }
    p = *(u8 **)(a0 + 0x68);
    ang = 0.0f;
    for (i = 0; i < 5; i++) {
        m = func_003C24B0(0x1C24, 0x80);
        if (m != 0) {
            m[0x31] = 1;
            *(u16 *)(m + 0x32) = *(u16 *)(a0 + 0x32);
            m[0x30] = a0[0x30];
            *(unsigned long *)(m + 0x38) = *(unsigned long *)(a0 + 0x38);
            off.x = func_0038D098(ang) * 6.0f;
            off.y = func_0038D0B0(ang) * 6.0f;
            off.z = 0.0f;
            vec_add_ab(m + 0x10, a0 + 0x10, &off);
            *(u16 *)(m + 0x34) |= 0x20;
            *(f32 *)(m + 0xF8) = ang;
            *(s16 *)(m + 0x7C) = 3;
            q = *(u8 **)(m + 0x68);
            *(u8 **)(q + 8) = q + 0x30;
            func_003C7C38(m);
        }
        ((u8 **)(p + 0x10))[i] = m;
        ang = func_0038DAB8(ang, 1.2566371f);
    }
    *(u16 *)(a0 + 0x34) |= 0x41;
    *(void **)(p + 4) = func_L07_003D5170;
    func_L07_003D5170(a0);
}
/* localdecomp:end func_L07_003D5008 */

/* localdecomp:start func_L07_003D5170 */
extern void func_L07_003D51D8(u8 *);
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern u8 *D_L07_001DF41C[];

void func_L07_003D5170(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 x;
    u8 *base;
    *(s32 *)(p + 0x28) = 0;
    func_L07_003D51D8(a0);
    x = *(s32 *)(p + 0x24);
    base = D_L07_001DF41C[0];
    func_L01_00456230(base + (x << 8), 0);
    *(u8 *)(p + 8) = 1;
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L07_003D5170 */

INCLUDE_ASM("asm/levels", func_L07_003D51D8);

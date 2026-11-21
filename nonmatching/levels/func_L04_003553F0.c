/* PAL draft (2026-11-20, Promises fleet rac3-w3): PAL names and PAL's constants (the effect calls pass 12, not 15).
 * check.py at level 04: 72 diff with `--as ps2as`, 133 with the file's current line (no @ps2as): retail
 * builds every float constant inline with lui/ori/mtc1, which only Ps2EeAs does, so the file
 * (src/levels/shared/L04_003553F0.c) needs `@ps2as`; its matched func_L04_00355678 has only a lui-only constant.
 * What still differs is register allocation: retail has velocity in $s3, m in $s2, m + 0x10 in $s1;
 * this C gives velocity $s1, m + 0x10 $s2, m $s3, and the three byte/halfword stores at 0x30-0x32 come
 * in another order (retail: 0x31, 0x30, 0x32, source order). Tried without change (all 72): a `p = m + 0x10`
 * local (three placements), a velocity copy local, f32-array access to velocity, declaration and
 * assignment of m apart, another order of the 0x30/0x31 stores, the init stores in an inline helper.
 * Moving the velocity copy before the size store took it from 76 to 72.
 * Earlier header (NTSC-U draft):
 */
/* NTSC-U draft (2026-11-14, Codex worker): C of func_L04_003544D0, the NTSC-U twin of func_L04_003553F0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L04_00354AE8.c's current line.
 * Worker's note: 133 diff; Best log func_L04_003544D0.02.log; complete spawn/effect draft. GNU assembler emits lit4 loads for 0.15f/0.8f/other literals where retail has inline constants; no flags_alt. Register/store-order differences also remain. Uses unsigned long for retail ld/sd 64-bit copy.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003553F0 */
extern s32 D_001DD308_sda, D_001DD30C_sda;
__asm__(".extern D_001DD308_sda, 4");
__asm__(".extern D_001DD30C_sda, 4");
extern u8 D_L04_001D66B0[];
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_0038D308(void *, void *);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_0046B458(void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);
extern void func_003A52A0(s32, s32, void *);

u8 *func_L04_003553F0(u8 *source, vu0_v4 *velocity, vu0_v4 *position, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 size) {
    u8 *m = func_003C24B0(0xEA7, 0x80);
    u8 *d;
    f32 radius, speed;
    if (m) {
        m[0x31] = 1;
        m[0x30] = 0xFF;
        *(u16 *)(m + 0x32) = 0xFF;
        m[0x20] = 0;
        d = *(u8 **)(m + 0x68);
        *(unsigned long *)(m + 0x38) = *(unsigned long *)(source + 0x38);
        *(vu0_v4 *)(m + 0x10) = *position;
        *(vu0_v4 *)d = *velocity;
        *(f32 *)(d + 0x14) = size;
        *(u8 **)(d + 0x10) = source;
        *(f32 *)(d + 0x20) = 0.15f;
        *(u16 *)(m + 0x34) |= 0x208;
        *(s32 *)(d + 0x2C) = arg3;
        *(s32 *)(d + 0x30) = arg4;
        d[0x34] = arg5;
        speed = func_0038CEA8(velocity) * 0.8f;
        *(f32 *)(d + 0x3C) = speed;
        *(f32 *)(d + 0x38) = -speed;
        *(f32 *)(m + 0xF8) = func_0038DAB8(func_0038D160(velocity->x, velocity->y), 1.5707963705062866f);
        *(f32 *)(m + 0xF0) = -func_0038D160(func_0038CED8(velocity), velocity->z);
        func_0038D308(m + 0xC0, m + 0xF0);
        *(u16 *)(m + 0x34) |= 0x100;
        m[0x23] = 0x80;
        *(f32 *)(m + 0x2C) = 0.0725f;
        *(s32 *)(d + 0x24) = 0;
        radius = func_003824E0(1.5f, 3.0f);
        *(s32 *)(d + 0x4C) = arg6;
        *(s32 *)(d + 0x40) = D_001DD308_sda;
        *(s32 *)(d + 0x44) = D_001DD30C_sda;
        *(s32 *)(d + 0x48) = 0x80803010;
        func_L01_0046B458(m + 0x10, 12, 0x80803010, 0, 10, D_L04_001D66B0, 0, radius * 0.3f, radius, 0.0f);
        func_L01_0046B458(m + 0x10, 12, -1, 1, -10, D_L04_001D66B0, 0, radius * 0.04f, radius * 0.4f, 0.0f);
        func_003A52A0(0, 0, m);
    }
    return m;
}
/* localdecomp:end func_L04_003553F0 */

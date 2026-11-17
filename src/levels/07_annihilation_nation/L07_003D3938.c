#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003D3938);

/* localdecomp:start func_L07_003D41D8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D41D8;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0044A7D0(u8 *);
extern f32 func_0038CEA8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_00382538(void);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_0038D308(void *, void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_003C7C38(void *);
extern u32 D_L07_001DE7B8[2];
__asm__(".extern D_L07_001DE7B8, 8");

u8 *func_L07_003D41D8(void *owner, V4_003D41D8 *pos, f32 *dir, u8 kind, f32 speed) {
    u8 *m = func_003C24B0(0x1C81, 0x80);
    u8 *pv;

    if (m != 0) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        *(void **)(m + 0xB8) = owner;
        m[0x20] = 0;
        pv = *(u8 **)(m + 0x68);
        func_L01_0044A7D0(m);
        *(V4_003D41D8 *)(m + 0x10) = *pos;
        *(V4_003D41D8 *)(pv + 0x10) = *(V4_003D41D8 *)dir;
        *(f32 *)(pv + 0x8) = func_0038CEA8(dir);
        *(f32 *)(pv + 0x4) = speed;
        pv[0xC] = kind;
        func_L01_004450F0(m, 1, -1);
        *(s32 *)pv = 0x53;
        *(u16 *)(m + 0x34) |= 0x100;
        *(f32 *)(m + 0xF0) = func_00382538();
        *(f32 *)(m + 0xF8) = func_0038D160(dir[0], dir[1]);
        *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CED8(dir), dir[2]);
        func_0038D308(m + 0xC0, m + 0xF0);
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.25f;
        func_0038CC88(pv + 0x30, D_L07_001DE7B8, 0x10);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L07_003D41D8 */

INCLUDE_ASM("asm/levels", func_L07_003D4330);

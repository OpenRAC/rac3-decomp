/* NTSC-U draft (2026-11-14, Claude worker): C of func_L08_0039A7F0, the NTSC-U twin of func_L08_0039C220, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 8 words differ with its file's flags.
 */
#include "common.h"

/* localdecomp:start func_L08_0039A7F0 */
/* Needs @ps2as (float immediates) beyond the PAL file's flags. */
typedef int u128_0039A7F0 __attribute__((mode(TI)));
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern f32 func_0037E2A8(void);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern f32 func_003BE7F0(void *, f32, s32, s32);

s32 func_L08_0039A7F0(void *self) {
    u8 *a0 = self;
    u8 *st = *(u8 **)(a0 + 0x68);
    f32 f;
    f32 r;

    *(u128_0039A7F0 *)(st + 0x2E0) = *(u128_0039A7F0 *)(a0 + 0x10);
    r = func_0037E2A8();
    st[0x1D7] = 1;
    st[0x1D8] = 0;
    st[0x1D9] = 0;
    st[0x1DA] = 0;
    *(f32 *)(st + 0x210) = 1.0f;
    *(f32 *)(st + 0x78) = 1.0f;
    st[0x170] = 8;
    st[0x1A8] = 3;
    *(f32 *)(st + 0x31C) = r;
    st[0x1DB] = 0xFF;
    *(f32 *)(st + 0x19C) = 0.15f;
    *(f32 *)(st + 0x70) = 0.5f;
    *(f32 *)(st + 0x74) = 0.25f;
    *(f32 *)(st + 0x7C) = 1.25f;
    *(f32 *)(st + 0x80) = 1.6580628f;
    *(f32 *)(st + 0xA0) = 0.34906584f;
    *(f32 *)(st + 0x9C) = 0.0027222224f;
    *(f32 *)(st + 0x190) = 0.5f;
    *(f32 *)(st + 0x194) = 0.5f;
    func_L01_00458A70(a0, 0.0044444446f, 0.06666667f, 0.0069813174f, 0.20943953f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(f32 *)(st + 0x30) = 1.0f;
        *(s16 *)(st + 0x34) = 1;
    }
    *(f32 *)(st + 0x40) = 1.0f;
    st[0x39] = 1;
    st[0x3E] = 1;
    st[0x3F] = 0;
    func_L01_00441FB8(a0, 1, 0);
    if (a0[0x43] != 3) func_003BE4F0(a0, 3, 0, 0);
    if (*(s32 *)(st + 0x300) != -1 || *(s32 *)(st + 0x308) != -1) {
        if (D_001D545C_sda != 8) {
            func_L01_00441FB8(a0, 9, 4);
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(a0, 1);
        }
    }
    if (*(s32 *)(st + 0x314) != 0) {
        f = func_003BE7F0(a0 + 0x10, 0.5f, 0, 0);
        if (*(f32 *)(a0 + 0x18) - f > 3.0f) f = *(f32 *)(a0 + 0x18);
        *(f32 *)(a0 + 0x18) = f - 1.0f;
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004A6DF8(a0, 1);
    }
    return 0;
}
/* localdecomp:end func_L08_0039A7F0 */

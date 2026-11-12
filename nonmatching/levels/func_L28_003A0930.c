/* near miss (level 28): 7 diff with --as ps2as; every instruction is right; only the order of the ten float stores into the state block differs (the scheduler puts 194/74/7C after 80/A0/9C where retail has them first); the file is already @ps2as; four store orders and a local per constant tried; its signature must be (void *) because func_L28_003A0708's block declares it */
#include "common.h"

/* localdecomp:start func_L28_003A0930 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 D_L28_001DE040;
extern f32 D_L28_001DE044;
extern u8 D_L28_001DE070;
__asm__(".extern D_L28_001DE040, 4");
__asm__(".extern D_L28_001DE044, 4");
__asm__(".extern D_L28_001DE070, 1");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C7DD8(void *);
s32 func_L28_003A0930(void *self) {
    u8 *a0 = self;
    f32 fa, fb;
    u8 *st = *(u8 **)(a0 + 0x68);
    *(u128_t *)(st + 0x2D0) = *(u128_t *)(a0 + 0x10);
    if (*(s16 *)(a0 + 0xB2) == 0) {
        *(s32 *)(st + 0x2F0) = -1;
        *(s32 *)(st + 0x2F8) = -1;
    }
    a0[0x23] = 0x70;
    *(u16 *)(a0 + 0x34) |= 0x2100;
    *(s32 *)(a0 + 0xB8) = 0;
    st[0x170] = 8;
    st[0x1DB] = 0xFF;
    st[0x1A8] = 1;
    st[0x1D7] = 1;
    st[0x1D8] = 0;
    st[0x1D9] = 0;
    st[0x1DA] = 0;
    fa = D_L28_001DE044 * 0.00040000002f;
    fb = D_L28_001DE040 * 0.020000001f;
    *(s32 *)(st + 0xA8) |= 5;
    *(f32 *)(st + 0x70) = 1.0f;
    *(f32 *)(st + 0x80) = 12.566371f;
    *(f32 *)(st + 0xA0) = 0.34906584f;
    *(f32 *)(st + 0x9C) = 0.00392f;
    *(f32 *)(st + 0x190) = 0.5f;
    *(f32 *)(st + 0x19C) = 0.15000001f;
    *(f32 *)(st + 0x78) = 2.0f;
    *(f32 *)(st + 0x194) = 0.5f;
    *(f32 *)(st + 0x74) = 0.15000001f;
    *(f32 *)(st + 0x7C) = 2.0f;
    func_L01_0045BD78(a0, fa, fb, 0.010053097f, 0.25132743f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(s16 *)(st + 0x34) = 10;
        *(f32 *)(st + 0x30) = 10.0f;
    }
    *(f32 *)(st + 0x40) = 0.25f;
    st[0x39] = D_L28_001DE070;
    st[0x3E] = 1;
    st[0x3F] = 0;
    func_L01_004450F0(a0, 3, -1);
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 0);
    if (*(s32 *)(st + 0x2F0) != -1 || *(unsigned long *)(st + 0x2F8) != 0xFFFFFFFFUL) {
        func_L01_004450F0(a0, 1, -1);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
    }
    func_003C7DD8(a0);
    return 0;
}
/* localdecomp:end func_L28_003A0930 */

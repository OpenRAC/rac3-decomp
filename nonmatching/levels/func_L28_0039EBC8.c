/* near miss (level 28, Opus): 6 diff with the file's flags; see nonmatching/README.md */
#include "common.h"

/* localdecomp:start func_L28_0039EBC8 */
typedef int u128_0039EBC8 __attribute__((mode(TI)));
extern f32 D_L28_001DDF00;
extern f32 D_L28_001DDF04;
extern u8 D_L28_001DDF30;
__asm__(".extern D_L28_001DDF00, 4");
__asm__(".extern D_L28_001DDF04, 4");
__asm__(".extern D_L28_001DDF30, 1");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C7DD8(void *);
s32 func_L28_0039EBC8(void *self) {
    u8 *a0 = self;
    f32 fa, fb;
    u8 *st = *(u8 **)(a0 + 0x68);
    *(u128_0039EBC8 *)(st + 0x1A0) = *(u128_0039EBC8 *)(a0 + 0x10);
    if (*(s16 *)(a0 + 0xB2) == 0) {
        *(s32 *)(st + 0x1C0) = -1;
        *(s32 *)(st + 0x1C8) = -1;
    }
    a0[0x23] = 0x70;
    *(u16 *)(a0 + 0x34) |= 0x2100;
    *(s32 *)(a0 + 0xB8) = 0;
    fa = D_L28_001DDF04 * 0.00040000002f;
    fb = D_L28_001DDF00 * 0.020000001f;
    *(s32 *)(st + 0xA8) |= 5;
    *(f32 *)(st + 0x78) = 2.0f;
    *(f32 *)(st + 0x70) = 0.75f;
    *(f32 *)(st + 0x74) = 0.15000001f;
    *(f32 *)(st + 0x7C) = 2.0f;
    *(f32 *)(st + 0x80) = 12.566371f;
    *(f32 *)(st + 0xA0) = 0.34906584f;
    *(f32 *)(st + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, fa, fb, 0.010053097f, 0.25132743f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(s16 *)(st + 0x34) = 10;
        *(f32 *)(st + 0x30) = 10.0f;
    }
    *(f32 *)(st + 0x40) = 0.25f;
    st[0x39] = D_L28_001DDF30;
    st[0x64] = 1;
    st[0x3E] = 1;
    st[0x3F] = 0;
    func_L01_004450F0(a0, 3, -1);
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 0);
    if (*(s32 *)(st + 0x1C0) != -1 || *(unsigned long *)(st + 0x1C8) != 0xFFFFFFFFUL) {
        func_L01_004450F0(a0, 1, -1);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
    }
    func_003C7DD8(a0);
    return 0;
}
/* localdecomp:end func_L28_0039EBC8 */

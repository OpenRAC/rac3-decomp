#include "common.h"

/* localdecomp:start func_L32_0039FE78 */
#include "vu0.h"
typedef int u128_0039FE78 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_L32_0039F828(u8 *, s32);
extern void func_L30_003A2C68(u8 *, s32);
extern s32 D_L32_001DE4EC;
__asm__(".extern D_L32_001DE4EC, 4");
extern s32 D_L32_001DE4F0;
__asm__(".extern D_L32_001DE4F0, 4");

u8 *func_L32_0039FE78(u128_0039FE78 *pos, s32 a1, s32 flags, f32 *p3, f32 *p4) {
    u8 *m;
    u8 *v;

    if ((flags & 1) && !(D_L32_001DE4EC < D_L32_001DE4F0)) {
        return 0;
    }
    m = func_003C24B0(0x1946, 0x190);
    if (m == 0) {
        return 0;
    }
    if (flags & 1) {
        D_L32_001DE4EC++;
    }
    *(u128_0039FE78 *)(m + 0x10) = *pos;
    m[0x30] = 0xFF;
    *(s16 *)(m + 0x32) = 0x40;
    v = *(u8 **)(m + 0x68);
    qzero(v + 0x20);
    *(f32 *)(v + 0x28) = -1.0f;
    *(u128_0039FE78 *)(v + 0x30) = *(u128_0039FE78 *)(m + 0x10);
    *(s32 *)(v + 0x54) = flags;
    func_L32_0039F828(m, a1);
    if (p3) {
        *(f32 *)(v + 0x78) = *p3;
    }
    if (p4) {
        *(f32 *)(v + 0x74) = *p4;
    }
    if (*(s32 *)(v + 0x54) & 0x10) {
        func_L30_003A2C68(m, 4);
    } else {
        func_L30_003A2C68(m, 2);
    }
    return m;
}
/* localdecomp:end func_L32_0039FE78 */

/* PAL near miss (Codex wave 10): near miss: 53 words differ with the file's flags.
 * Worker's note: 53/155 words differ; s0/s1 and s2/s3 allocation plus float/scheduling residual; repeated formulations did not improve. Best log build/codex/w525/func_L01_003968F8.03.log
 */
#include "common.h"
/* localdecomp:start func_L01_003968F8 */
typedef struct { u8 pad[0xBD8]; void *target; } Hero_003968F8;
extern Hero_003968F8 D_001A4BE0;
__asm__(".extern D_L01_001DE0B0, 4");
__asm__(".extern D_L01_001DE0B4, 4");
__asm__(".extern D_L01_001DE0B8, 4");
extern s32 D_L01_001DE0B0;
extern f32 D_L01_001DE0B4, D_L01_001DE0B8;
extern s32 D_L01_001E2030, D_L01_001E2034, D_L01_001E2038;
u8 *func_L01_003968F8(u8 *owner, s32 type, s128 *pos, s128 *direction, s32 arg4, s32 arg5) {
    extern void *func_003C24B0(s32, s32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_L01_00395498(s32 n);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_00457588(void *, void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L01_004C85C8(void *, void *, f32, f32, f32);
    V_003919E0 scatter;
    u8 *v;
    u8 *m;
    u8 *ownerVars;
    f32 length;
    s32 base;
    m = func_003C24B0(0x1893, 0x80);
    if (m != 0) {
        m[0x20] = 0;
        v = *(u8 **)(m + 0x68);
        m[0x30] = 0xFF;
        *(u16 *)(m + 0x32) = 0xFF;
        *(f32 *)(v + 0x54) = func_00382538();
        *(f32 *)(v + 0x58) = func_003824E0(0.44680431485176086f, 0.7539823055267334f);
        *(s32 *)(v + 0x64) = *(s16 *)(owner + 0xAA);
        *(s32 *)(v + 0x74) = arg5;
        *(s32 *)(v + 0x6C) = 0;
        *(s128 *)(m + 0x10) = *pos;
        *(u16 *)(m + 0x34) |= 0x100;
        m[0x23] = 0x50;
        *(f32 *)(m + 0x2C) = 0.025f;
        *(u32 *)(m + 0x78) = 0x7F4080FF;
        *(s32 *)(v + 0x70) = arg4;
        *(s32 *)(v + 0x60) = type;
        ownerVars = *(u8 **)(owner + 0x68);
        if (!D_L01_001DE0B0) {
            base = *(s32 *)(ownerVars + 8);
            D_L01_001E2030 = base;
            base = func_L01_00395498(base + 0x100);
            D_L01_001E2034 = base;
            base = func_L01_00395498(base + 0x4B00);
            D_L01_001E2038 = base;
            func_L01_00395498(base + 0xA0);
            D_L01_001DE0B0 = 1;
        }
        if (D_001A4BE0.target) {
            length = func_0038CEA8(direction);
            if (length == 0.0f) length = 1.0f;
            func_L01_00457588(D_001A4BE0.target, pos, direction, length);
        }
        *(s128 *)v = *direction;
        scatter.q = *direction;
        scatter.f[0] += func_003824E0(-0.15f, 0.15f);
        scatter.f[1] += func_003824E0(-0.15f, 0.15f);
        func_0038CF68(&scatter, &scatter, func_003824E0(D_L01_001DE0B8 * 0.020000001415610313f, D_L01_001DE0B4 * 0.020000001415610313f) * 0.5f);
        *(s32 *)(v + 0x5C) = 96;
        *(s32 *)(v + 0x50) = 0x237;
        *(s32 *)(v + 0x68) = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
    }
    return m;
}
/* localdecomp:end func_L01_003968F8 */

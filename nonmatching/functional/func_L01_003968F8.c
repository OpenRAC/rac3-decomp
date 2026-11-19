/* functional: high. rewritten from the disassembly (no outside draft); 77-word diff is moby/pvars register swap and hoisted lui; opcode multiset equal. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_003968F8 */
extern s32 D_001DE0B0_sda;
__asm__(".extern D_001DE0B0_sda, 4");
extern f32 D_001DE0B4_sda;
__asm__(".extern D_001DE0B4_sda, 4");
extern f32 D_001DE0B8_sda;
__asm__(".extern D_001DE0B8_sda, 4");
extern s32 D_L01_001E2030;
extern s32 D_L01_001E2034;
extern s32 D_L01_001E2038;
typedef struct { vu0_q quad; u8 pad10[0x44]; s32 w54_58[2]; s32 w5C, w60, w64, w68, w6C, w70, w74; } Vars_003968F8;
u8 *func_L01_003968F8(u8 *owner, s32 arg, vu0_q *position, vu0_q *direction, s32 a4, s32 a5) {
        extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_L01_00395498(s32);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_00457588(s32, void *, f32, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L01_004C85C8(void *, void *, f32, f32, f32);
    u8 *m = (u8 *)func_003C24B0(0x1893, 0x80);
    u8 *v;
    vu0_v4 jitter;
    f32 len, r;
    s32 base, r1, r2;
    if (m) {
        m[0x20] = 0;
        v = *(u8 **)(m + 0x68);
        m[0x30] = 255;
        *(s16 *)(m + 0x32) = 255;
        r = func_00382538();
        *(f32 *)(v + 0x54) = r;
        *(f32 *)(v + 0x58) = func_003824E0(0.44680431485176086f, 0.7539823055267334f);
        *(s32 *)(v + 0x74) = a5;
        *(s32 *)(v + 0x64) = *(s16 *)(owner + 0xAA);
        *(s32 *)(v + 0x6C) = 0;
        *(u16 *)(m + 0x34) |= 0x100;
        m[0x23] = 0x50;
        *(vu0_q *)(m + 0x10) = *position;
        *(f32 *)(m + 0x2C) = 0.025f;
        *(u32 *)(m + 0x78) = 0x7F4080FF;
        *(s32 *)(v + 0x70) = a4;
        *(s32 *)(v + 0x60) = arg;
        if (D_001DE0B0_sda == 0) {
            base = *(s32 *)(*(u8 **)(owner + 0x68) + 8);
            D_L01_001E2030 = base;
            r1 = func_L01_00395498(base + 0x100);
            D_L01_001E2034 = r1;
            r2 = func_L01_00395498(r1 + 0x4B00);
            D_L01_001E2038 = r2;
            func_L01_00395498(r2 + 0xA0);
            D_001DE0B0_sda = 1;
        }
        if (*(s32 *)(D_001A4BE0 + 0xBD8)) {
            len = func_0038CEA8(direction);
            if (len == 0.0f) len = 1.0f;
            func_L01_00457588(*(s32 *)(D_001A4BE0 + 0xBD8), position, len, direction);
        }
        *(vu0_q *)v = *direction;
        *(vu0_q *)&jitter = *direction;
        ((f32 *)&jitter)[0] += func_003824E0(-0.15f, 0.15f);
        ((f32 *)&jitter)[1] += func_003824E0(-0.15f, 0.15f);
        func_0038CF68(&jitter, &jitter, func_003824E0(D_001DE0B8_sda * 0.020000001f, D_001DE0B4_sda * 0.020000001f) * 0.5f);
        *(s32 *)(v + 0x5C) = 0x60;
        *(s32 *)(v + 0x50) = 0x237;
        *(s32 *)(v + 0x68) = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
    }
    return m;
}
/* localdecomp:end func_L01_003968F8 */

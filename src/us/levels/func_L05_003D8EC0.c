#include "common.h"

/* NTSC-U counterpart of func_L05_003DB2D0 (src/levels/05_daxx/L05_003DB1C0.c): 0.02 -> 0.0166667; 0.04 -> 0.0333333; 0.1 -> 0.0833333 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
struct R_3DB1C0 {
    u8 pad[0x24];
    f32 f24;
};
typedef struct S_3DB1C0 {
    u8 pad0[0x10];
    u128_t v10;
    u8 pad1[4];
    struct R_3DB1C0 *p24;
    u8 pad2[4];
    f32 f2c;
    u8 f30;
    u8 f31;
    u16 f32h;
    u16 f34;
    u8 pad3[2];
    unsigned long f38;
    u8 pad4[0xB0];
    u128_t vF0;
} S_3DB1C0;

/* localdecomp:start func_L05_003D8EC0 */
extern f32 D_L05_001DF190_003D8EC0;
__asm__(".extern D_L05_001DF190_003D8EC0, 4");
extern f32 D_L05_001DF194;
__asm__(".extern D_L05_001DF194, 4");
extern u8 D_L05_001D66B0_003D8EC0[8];
__asm__(".extern D_L05_001D66B0_003D8EC0, 16");
extern void func_003886E8(void *, void *, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, f32, s32, s32, f32, f32, f32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L05_003D8EC0(u8 *o) {
    vu0_v4 c;
    vu0_v4 b;
    vu0_v4 d;
    vu0_v4 *cp;
    u8 *r;
    s32 i;

    cp = &c;
    c = *(vu0_v4 *)(o + 0xC0);
    func_003886E8(&c, &c, D_L05_001DF190_003D8EC0 * 0.0166666675f);
    func_0039FE80(0, 0, o);
    func_L01_0044ED60(o, 0x1FF, cp, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    r = (u8 *)func_L05_003D8DB0((S_3DB1C0 *)o, 0x1E42, 0);
    *(s32 *)(o + 0x98) = 0;
    o[0x31] = 0;
    *(u16 *)(o + 0x34) |= 1;
    if (r != 0) {
        *(s32 *)(r + 0x98) = *(s32 *)(*(u8 **)(r + 0x24) + 0x10);
    }
    *(vu0_q *)&b = 0;
    b.x = 1.0f;
    for (i = 0; i < 10; i++) {
        func_0037E2F0(&c, 0.0166666675f, 0.0333333351f);
        func_003886E8(&d, &b, 0.0833333358f);
        vec_add_ab(&c, &d, &c);
        func_L02_003E0520(o, D_L05_001D66B0_003D8EC0, 0.0f, &c, func_0037E208(3, 6), 0.0f, 3, 0, 1.5f, 20.0f, 1.0f);
    }
    func_L01_0032FE90(o + 0x10, 0, 0, 0, 0, 2, 5, 0, D_L05_001DF194, 0.0f, 0.0f, 0.0f,
                      0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x7FD68F, 0xFF8400, 0, 0, 0, 0,
                      0x7F60A0FF, 0x280000FF, 0, 0);
    func_L01_0044EBF8(o, 1, 0.0f);
    func_003BD360(o);
}
/* localdecomp:end func_L05_003D8EC0 */

#include "common.h"

/* NTSC-U counterpart of func_L24_0034F080 (src/levels/24_insomniac_museum/L24_0034F040.c): 0.2 -> 0.166667 */
#include "vu0.h"
typedef struct {
    u8 p0[0x80];
    vu0_q x80;
    vu0_q x90;
    u8 pA0[0x30];
    vu0_q xD0;
    u8 pE0[0x108 - 0xE0];
    f32 x108;
    u8 p10C[0x19E0 - 0x10C];
    s32 x19E0;
    s16 x19E4;
    u8 p19E6[0x25C0 - 0x19E6];
    u8 *x25C0;
    u8 p25C4[0x25E5 - 0x25C4];
    u8 x25E5;
} S_34F040;
extern S_34F040 D_001A4BE0;

/* localdecomp:start func_L24_0034E1A0 */
#include "vu0.h"
typedef struct {
    vu0_q x0;
    u8 p10[0x2540 - 0x10];
    u8 *x2540;
} S_34F080;
extern S_34F080 D_001A4C60;
extern vu0_q D_L24_001E21A0_0034E1A0;
extern vu0_q D_L24_001E8F60_0034E1A0;
extern s32 func_L24_00419D90(s32, s32, s32);
extern s32 func_L01_004FC518(s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);

void func_L24_0034E1A0(u8 *obj) {
    S_34F040 *g;
    f32 v[4];
    vu0_q a, c, r;

    func_L24_00419D90(0, 0, 1);
    g = &D_001A4BE0;
    g->x25E5 = 0;
    func_L01_004FC518(0, 1);
    *(vu0_q *)v = D_L24_001E21A0_0034E1A0;
    g->x19E4 = -1;
    g->x108 = 0.166666672f;
    g->x19E0 = 0;
    v[2] = 0.0f;
    func_00388830(v, v, 2.5f);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(vu0_v4 *)(obj + 0x10)));
    *(s32 *)(obj + 0x98) = 0;
    v[2] = 0.7f;
    __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*(vu0_v4 *)v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(c));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)v) : "j"(r));
    if (func_003CE740(&g->x80, v, 2, g->x25C0, 0) != 0) {
        *(vu0_q *)v = D_L24_001E8F60_0034E1A0;
        if (func_L01_003F9498(v, 2, g->x25C0, 0.4f) != 0) {
            *(vu0_q *)v = D_L24_001E8F60_0034E1A0;
        }
    }
    D_001A4C60.x0 = *(vu0_q *)v;
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    *(s32 *)(D_001A4C60.x2540 + 0x9C) = 0;
}
/* localdecomp:end func_L24_0034E1A0 */

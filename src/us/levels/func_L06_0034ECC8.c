#include "common.h"

/* NTSC-U counterpart of func_L06_0034F9B8 (src/levels/shared/L06_0034A2B8.c) */
#include "vu0.h"
extern s32 func_0037E1D8(s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
#include "vu0.h"
extern s32 func_L06_0034ECC8(u8 *);

/* localdecomp:start func_L06_0034ECC8 */
/* func_L06_0034ECC8: from the NTSC-U draft of func_L06_0034ECC8, with PAL names, PAL (50 Hz) constants and PAL anim ids 3/5/8;
 * the store order (0x190 before 0x1A8, 0x194 after it; 0x180/0x184/0x188) and the u128 temp scope fix the scheduling and register choice */
typedef int u128_0034F9B8 __attribute__((mode(TI)));
extern s32 func_0037E1D8(s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L06_00349480(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
s32 func_L06_0034ECC8(u8 *a) {
    u8 *d = *(u8 **)(a + 0x68);
    { u128_0034F9B8 t = *(u128_0034F9B8 *)(a + 0x10);
      *(u128_0034F9B8 *)(d + 0x910) = t;
      d[0x170] = 41; }
    *(f32 *)(d + 0x190) = 0.5f;
    d[0x1A8] = 3;
    *(f32 *)(d + 0x194) = 0.5f;
    *(f32 *)(d + 0x19C) = 0.15f;
    d[0x171] = 22;
    d[0x172] = 24;
    d[0x176] = 26;
    if (!func_0037E1D8(3)) d[0x176] = 25;
    else if (!func_0037E1D8(2)) d[0x176] = 255;
    if (d[0x176] == 25) {
        d[0x1D3] = 12; d[0x1D2] = 7;
        *(f32 *)(d + 0x17C) = 0.9166666865f;
        *(f32 *)(d + 0x180) = 0.21666668f;
        *(f32 *)(d + 0x184) = 0.21666668f;
        *(f32 *)(d + 0x188) = 0.21666668f;
    }
    *(s32 *)(d + 0xAC) = *(s32 *)(d + 0x97C);
    d[0x1D7] = 1; d[0x1A9] = 1;
    *(f32 *)(d + 0x70) = 0.65f; *(f32 *)(d + 0x74) = 0.2f;
    *(f32 *)(d + 0x78) = 0.5f; *(f32 *)(d + 0x7C) = 1.5f;
    *(f32 *)(d + 0x80) = 1.5184364f; *(f32 *)(d + 0xA0) = 0.34906584f;
    *(f32 *)(d + 0x9C) = 0.0027222223f;
    func_L01_00458A70(a, 0.005f, 0.13333334f, 0.0069813174f, 0.20943953f);
    d[0x58] = 20; d[0x5A] = 14;
    if (!*(s16 *)(d + 0x34)) { *(s16 *)(d + 0x34) = 20; *(f32 *)(d + 0x30) = 20.0f; }
    d[0x3E] = 1; d[0x39] = 0; d[0x3F] = 0; *(f32 *)(d + 0x40) = 1.0f;
    func_L06_00349480(a);
    *(s32 *)(d + 0x934) = -1;
    func_L01_00441FB8(a, 1, 0);
    if (a[0x43]) func_003BE4F0(a, 0, 0, 0);
    if (*(s32 *)(d + 0x94C)) {
        func_L01_00441FB8(a, 31, -1);
        if (a[0x43] != 5) func_003BE4F0(a, 5, 0, 4);
    }
    if (*(s32 *)(d + 0x954)) {
        if (a[0x43] != 6) func_003BE4F0(a, 6, 0, 6);
        func_L01_00441FB8(a, 4, -1);
    }
    if (*(s32 *)(d + 0x950) != -1) {
        func_L01_00441FB8(a, 5, -1);
        if (a[0x43] != 6) func_003BE4F0(a, 6, 0, 10);
    }
    if (*(s32 *)(d + 0x958)) {
        *(s32 *)(a + 0x98) = 0;
        *(u16 *)(a + 0x34) = (*(u16 *)(a + 0x34) | 0x41) & 0xEFFF;
        func_L01_004A6DF8(a, 1);
        func_L01_00441FB8(a, 37, 5);
    }
    return 0;
}
/* localdecomp:end func_L06_0034ECC8 */

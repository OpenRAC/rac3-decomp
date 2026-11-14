#include "common.h"

/* NTSC-U counterpart of func_L19_003B1730 (src/levels/19_thran_asteroid_belt/L19_003AFB40.c) */
/* localdecomp:start func_L19_003AFAE0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B1730;
extern s32 D_L19_001E198C_003AFAE0;
extern s32 D_L19_001E1990_003AFAE0;
extern s32 D_L19_001E1984_003AFAE0;
extern s32 D_L19_001E1988_003AFAE0;
__asm__(".extern D_L19_001E1970_003AFAE0, 16");
extern s32 D_L19_001E1970_003AFAE0;
extern s32 func_0037E1D8(s32);
extern void func_L01_00458A70(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern f32 func_003BE7F0(void *, s32, void *, f32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

s32 func_L19_003AFAE0(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    s32 a[5];
    s32 i;
    s32 r;
    s32 k;
    s32 t;
    u8 *p;

    D_L19_001E1984_003AFAE0 = func_0037E1D8(2);
    D_L19_001E1988_003AFAE0 = 0;
    D_L19_001E198C_003AFAE0 = -600;
    D_L19_001E1990_003AFAE0 = -600;
    for (i = 0; i < 3; i++)
        a[i] = ((s32 *)(v + 0x3B4))[i];
    for (i = 0; i < 2; i++)
        a[i + 3] = ((s32 *)(v + 0x3C8))[i];
    k = 0;
    for (i = 5; i > 0; i--) {
        r = func_0037E1D8(i);
        t = a[r];
        a[r] = a[i - 1];
        (&D_L19_001E1970_003AFAE0)[k++] = t;
    }
    *(f32 *)(v + 0x1BC) = 2.0f;
    v[0x170] = 0x1D;
    v[0x1A8] = 3;
    v[0x1D7] = 1;
    *(s16 *)(v + 0x378) = 1;
    *(f32 *)(v + 0x1B8) = 0.3f;
    *(f32 *)(v + 0x74) = 0.25f;
    *(f32 *)(v + 0x70) = 1.0f;
    *(f32 *)(v + 0x78) = 1.0f;
    *(f32 *)(v + 0x7C) = 1.75f;
    *(f32 *)(v + 0x80) = 1.65806282f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.0027222223579883575f;
    *(s32 *)(v + 0x370) = 1;
    *(s32 *)(v + 0xA8) |= 0x10;
    func_L01_00458A70(self, 0.004166666883975267f, 0.125f, 0.0069813174195587635f, 0.20943953096866608f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 100;
        *(f32 *)(v + 0x30) = 100.0f;
    }
    v[0x3F] = 0;
    *(f32 *)(self + 0x18) = func_003BE7F0(self + 0x10, 0, 0, 0.5f);
    *(f32 *)(v + 0x40) = 2.0f;
    v[0x3E] = 1;
    v[0x3F] = 0;
    p = func_003BCFB0(0x1D62, 0);
    *(u8 **)(v + 0x39C) = p;
    *(V4_3B1730 *)(p + 0x10) = *(V4_3B1730 *)(self + 0x10);
    if (*(s32 *)(v + 0x37C) != -1) {
        func_L01_00441FB8(self, 2, 4);
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(self + 0x98) = 0;
        func_L01_004A6DF8(self, 1);
    } else if (*(s16 *)(v + 0x3A8) != 0) {
        func_L01_00441FB8(self, 5, 0);
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(self + 0x98) = 0;
        func_L01_004A6DF8(self, 1);
    } else if (*(s16 *)(v + 0x3AA) != 0) {
        func_L01_00441FB8(self, 4, 0);
    } else {
        func_L01_00441FB8(self, 1, 0);
    }
    func_003BE4F0(self, 0, 0, 0);
    *(s16 *)(self + 0x7C) = 0x1EFF;
    *(s16 *)(v + 0x380) = -1;
    *(s16 *)(v + 0x382) = 4;
    *(s32 *)(v + 0x398) = 12;
    return 0;
}
/* localdecomp:end func_L19_003AFAE0 */

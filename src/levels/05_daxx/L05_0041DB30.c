#include "common.h"

/* localdecomp:start func_L05_0041DB30 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_L05_002E92A0;
typedef struct { u8 p0[0x30]; s32 f30; s32 f34; } S_L05_001E6A40;
typedef struct { u8 p0[0x3C]; s32 f3C; } S_L05_002E9360;
extern f32 D_001D6B44_sda;
extern u8 D_001D6AB0_sda;
extern u8 D_001D6AA5_sda;
extern u8 D_001D6AA4_sda;
extern u8 D_001D6B70_sda;
typedef struct { u8 p0[4]; s32 f4; } R_0041DB30;
extern R_0041DB30 D_001D6B70_0041DB30;
__asm__(".extern D_001D6B70_0041DB30, 16");
extern u8 D_001D6B88_sda;
extern u8 D_001D6BA0_sda;
extern s32 D_001D6BB8_sda;
extern S_L05_002E92A0 D_L05_002E92A0;
extern S_L05_001E6A40 D_L05_001E6A40;
extern S_L05_002E9360 D_L05_002E9360;
extern u8 D_L05_002E92F0[];
extern u8 D_L05_002E93C0[];
extern u8 D_L05_002E9420[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);
extern void func_L03_004109D8(void *, void *, void *, s32);

void func_L05_0041DB30(void) {
    void *a;
    void *b;
    void *c;
    void *d;
    s32 e;

    D_001D6B44_sda = 1.0f;
    D_L05_002E92A0.f20 = &D_001D6AB0_sda;
    D_L05_002E92A0.f30 = 1;
    a = 0;
    c = 0;
    b = 0;
    d = 0;
    e = 0;
    D_001D6AA5_sda = 0;
    if (D_001D545C == 5) {
        switch (D_L05_001E6A40.f30) {
        case 0:
            d = D_L05_002E92F0;
            b = &D_001D6B88_sda;
            if (D_L05_001E6A40.f34 < (D_001D6B70_0041DB30.f4 * 5 + 2) / 6) b = &D_001D6B70_sda;
            break;
        case 1:
            D_001D6B44_sda = -1.0f;
            if (D_L05_001E6A40.f34 < (D_L05_002E9360.f3C * 5 + 2) / 6) a = &D_L05_002E9360;
            else a = D_L05_002E93C0;
            break;
        case 2:
            D_001D6AA4_sda = 1;
            d = D_L05_002E9420;
            if (D_L05_001E6A40.f34 >= (D_001D6BB8_sda * 5 + 2) / 6) e = 1;
            else b = &D_001D6BA0_sda;
            c = &D_001D6BB8_sda;
            break;
        }
    }
    if (a != 0) {
        func_L01_00423068(a, (s32)b, (s32)c, e, 0, 1, 0);
    } else if (d != 0) {
        func_L03_004109D8(d, b, c, e);
    }
}
/* localdecomp:end func_L05_0041DB30 */

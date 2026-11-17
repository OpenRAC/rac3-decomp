#include "common.h"

typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; void *w68; } M_3D5548;
typedef struct {
    void (*fn0)(void *);
} Iface;
typedef struct {
    char pad0[0x30];
    int timer;
    char pad34[0x3E - 0x34];
    unsigned char b62;
    char pad3F[0x40 - 0x3F];
    float f64;
} Vars;
typedef struct {
    char pad0[0x30];
    unsigned char b48;
    char pad31[0x32 - 0x31];
    short h50;
} Obj;

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L12_003D4B18);

/* localdecomp:start func_L12_003D50C8 */
/* PAL port of the NTSC-U match src/us/levels/func_L12_003D3430.c */


extern s32 D_001A65C0[];
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(Obj *, int, int);
extern void func_003C7C38(void *);

u8 *func_L12_003D50C8(u8 *a0, u8 *a1, u8 *a2, u8 *a3, f32 f12) {
    u8 *m;
    u8 *d;

    m = func_003C24B0(0x1C17, 0x80);
    if (m != 0) {
        d = *(u8 **)(m + 0x68);
        *(u8 **)(m + 0xB8) = a0;
        *(u8 **)(d + 0x28) = a1;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0x40;
        m[0x31] = 1;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 0.75f;
        *(u128_t *)(m + 0x10) = *(u128_t *)a2;
        *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CED8(a3), *(f32 *)(a3 + 8));
        *(f32 *)(m + 0xF8) = func_0038D160(*(f32 *)a3, *(f32 *)(a3 + 4));
        func_0038D308(m + 0xC0, m + 0xF0);
        *(u128_t *)d = *(u128_t *)a3;
        *(f32 *)(d + 0x38) = func_0038CEA8(a3);
        *(f32 *)(d + 0x20) = f12;
        if (D_001A65C0[0] != 0) {
            *(s32 *)(d + 0x24) = 350;
        } else {
            *(s32 *)(d + 0x24) = 133;
        }
        *(s32 *)(d + 0x2C) = 0;
        *(s32 *)(d + 0x3C) = -1;
        func_L01_004450F0(m, 1, -1);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L12_003D50C8 */

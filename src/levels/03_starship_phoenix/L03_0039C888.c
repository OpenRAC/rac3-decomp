#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0039C888);

INCLUDE_ASM("asm/levels", func_L03_0039D038);

/* localdecomp:start func_L03_0039D188 */
extern u8 D_001426E0[];
extern u16 D_00143954[];
extern u16 D_001A864C[];
extern s32 D_L03_002E52F0[];
extern u8 D_001A4C60[];
extern s32 D_L03_001DF99C_0039D188;
extern s32 D_00142C10[];
extern u8 D_L03_001E24C0[];
extern s32 func_00382380_0039D188();
extern void func_L01_00456230();
extern void func_0039EF28();
extern void func_L03_0039D578();
extern f32 func_L01_0040E548();
extern void func_L01_004472C0();
extern s32 func_L01_00447490();
extern void func_003C3A10();
extern void func_L01_004450F0();

typedef struct {
    u8 p0[0x20]; u8 x20; u8 p21[0xF]; u8 x30; u8 x31; u8 p32[2]; u8 x34; u8 p35[0xE]; u8 x43;
    u8 p44[0x23]; u8 x67; u8 p68[4]; u8 x6C; u8 p6D[2]; u8 x6F; u8 p70[0x38]; u8 xA8;
} S_0039D188;
typedef struct { u8 p[0x310]; s32 x310; u8 p314[4]; s32 x318; } T_0039D188;

void func_L03_0039D188(S_0039D188 *a) {
    T_0039D188 *p = *(T_0039D188 **)((u8 *)a + 0x68);
    if (D_001426E0[8] == 0) {
        if (D_00143954[0] == 0 || (D_001A864C[0] != 0 && D_L03_002E52F0[0] == 0 && D_L03_002E52F0[9] == -1)) {
            if (func_00382380_0039D188(D_001A4C60, p->x310, 0) != 0) {
                func_L01_00456230(D_L03_001DF99C_0039D188 + (p->x318 << 8), 1);
                D_001426E0[8] = 1;
                func_0039EF28();
            }
        }
    }
    if (a->x20 < 6 && (D_00142C10[0] & 0x10000)) {
        func_L03_0039D578(a, p);
    }
    if (((a->x34) ^ 1) & 1) {
        if (a->x31 != 0) {
            if (func_L01_0040E548(D_L03_001E24C0, (u8 *)a + 0x10) < 576.0f) {
                func_L01_004472C0(a);
                a->x6F = 0x16;
            }
        }
    }
    if ((u8)(a->x20 - 1) < 4) {
        if (func_L01_00447490(a, -1, 0) != 0) {
            if (a->x43 != 10) func_003C3A10(a, 10, 4, 2);
            func_L01_004450F0(a, 5, -1);
        }
    } else {
        if (a->x20 == 6) {
            if (func_L01_00447490(a, -1, 0) != 0) {
                if (a->x43 != 10) func_003C3A10(a, 10, 4, 2);
                func_L01_004450F0(a, 11, -1);
            }
        }
    }
    a->xA8 = 0xFF;
}
/* localdecomp:end func_L03_0039D188 */

INCLUDE_ASM("asm/levels", func_L03_0039D380);

/* localdecomp:start func_L03_0039D418 */
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_0038CF68(u8 *, u8 *, f32);
extern void func_L01_00459188(u8 *, u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern u8 *D_001A71A0[];

void func_L03_0039D418(u8 *a0, u8 *a1) {
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 8);
    *(f32 *)(a1 + 0x50) = 0.002f;
    *(f32 *)(a1 + 0x54) = 0.004f;
    *(f32 *)(a1 + 0x58) = 0.0600000024f;
    if (0.0600000024f < *(f32 *)(a1 + 0xE0)) {
        func_0038CF68(a1 + 0xD0, a1 + 0xD0, 0.0600000024f);
        *(f32 *)(a1 + 0xE0) = *(f32 *)(a1 + 0x58);
    }
    func_L01_00459188(a0, D_001A71A0[0], a1 + 0x120);
    func_L01_004450F0(a0, 3, -1);
}
/* localdecomp:end func_L03_0039D418 */

/* localdecomp:start func_L03_0039D4D8 */
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_00459188(u8 *, u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern u8 *D_001A71A0[];

void func_L03_0039D4D8(u8 *a0, u8 *a1) {
    if (a0[0x43] != 2) {
        func_003C3A10(a0, 2, 0, 8);
    }
    *(f32 *)(a1 + 0x58) = 0.24000001f;
    *(f32 *)(a1 + 0x50) = 0.0048f;
    *(f32 *)(a1 + 0x54) = 0.006f;
    func_L01_00459188(a0, D_001A71A0[0], a1 + 0x120);
    func_L01_004450F0(a0, 2, -1);
}
/* localdecomp:end func_L03_0039D4D8 */

/* localdecomp:start func_L03_0039D578 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern u8 *D_L03_0021D8C0[];
extern s32 D_00142C14[];
extern s32 D_001DE390_sda;
__asm__(".extern D_001DE390_sda, 4");

void func_L03_0039D578(u8 *a0, u8 *a1) {
    *(u128_t *)(a0 + 0x10) = *(u128_t *)(D_L03_0021D8C0[*(s32 *)(a1 + 0x314)] + 0x10);
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 0);
    *(f32 *)(a1 + 0x58) = 0.060000002f;
    *(f32 *)(a1 + 0x4C) = 0.12566371f;
    *(f32 *)(a1 + 0x50) = 0.0025132743f;
    *(f32 *)(a1 + 0x54) = 0.0025132743f;
    a1[0x344] = 0xFF;
    *(s16 *)(a1 + 0x338) = 1;
    *(s16 *)(a1 + 0x33A) = 1;
    func_L01_004450F0(a0, 6, -1);
    a0[0x30] = 0x40;
    if (D_00142C14[0] & 0x200000) {
        *(u128_t *)(a0 + 0x10) = *(u128_t *)&D_001DE390_sda;
        *(f32 *)(a0 + 0xF8) = 1.5707964f;
        if (a0[0x43] != 7) func_003C3A10(a0, 7, 0, 0);
        func_L01_004450F0(a0, 12, -1);
    }
}
/* localdecomp:end func_L03_0039D578 */

INCLUDE_ASM("asm/levels", func_L03_0039D6A8);

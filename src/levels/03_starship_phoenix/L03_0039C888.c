#include "common.h"

/* localdecomp:start func_L03_0039C888 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_00142CBE[]; __asm__(".extern D_00142CBE, 16");
extern u8 D_001426EB[]; __asm__(".extern D_001426EB, 16");
extern s32 D_001D6694_sda; __asm__(".extern D_001D6694_sda, 4");
extern f32 D_001DE380_sda[2]; __asm__(".extern D_001DE380_sda, 8");
extern f32 D_001DE388_sda[2]; __asm__(".extern D_001DE388_sda, 8");
extern u8 D_001A4C60[];
extern u128_t *D_L03_0021D8C0_0039C888[]; __asm__(".extern D_L03_0021D8C0_0039C888, 16");
extern void func_L03_0039D038();
extern void func_003C2880();
extern s32 func_L01_004BA800();
extern void func_L03_0039D188();
extern f32 func_0038CF38();
extern void func_L01_0045A9F0();
extern s32 func_0038CAD0();
extern s32 func_00382498();
extern s32 func_00382468();
extern void func_003C3A10();
extern void func_L01_004450F0();
extern s32 func_L01_00456500();
extern void func_L01_00458F78();
extern void func_L03_0039D6A8();
extern void func_L03_0039D4D8();
extern void func_L01_0045A748();
extern void func_L03_0039D380();
extern void func_L03_0039D418();
extern f32 func_L01_0040E570();
extern f32 func_L01_004395E0();
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CB00();
extern s32 func_L01_004561B8();

typedef struct S_0039C888 S_0039C888;
typedef struct T_0039C888 T_0039C888;
struct T_0039C888 {
    u8 p0[0x120]; u8 x120[0x80]; u8 x1A0[0x174]; s32 x314; u8 p318[4]; s32 x31C; u8 p320[0x10];
    f32 x330; f32 x334; s16 x338; s16 x33A; s16 x33C; s16 x33E; s32 x340;
};
struct S_0039C888 {
    u8 p0[0x10]; u8 x10[8]; f32 x18; u8 p1C[4]; u8 x20; u8 p21[0xF]; u8 x30; u8 x31; u8 p32[2]; u16 x34;
    u8 p36[0xC]; u8 x42; u8 x43; u8 p44[0x1C]; u8 x60; u8 p61[7]; T_0039C888 *x68; u8 p6C[0x8C]; f32 xF8;
};

void func_L03_0039C888(S_0039C888 *a) {
    T_0039C888 *p;
    f32 f;
    int r;
    func_L03_0039D038(a);
    if (D_00142CBE[0] != 0) {
        func_003C2880(a);
        return;
    }
    if (D_001D6694_sda == 2) {
        a->x31 = 0;
        a->x34 |= 1;
        return;
    }
    if (func_L01_004BA800() == 0) {
        a->x31 = 1;
        a->x34 &= 0xFFFE;
    }
    func_L03_0039D188(a);
    p = a->x68;
    f = func_0038CF38(a->x10, D_001A4C60);
    switch (a->x20) {
    case 1:
        func_L01_0045A9F0(a);
        if (func_0038CAD0(&p->x340)) {
            r = func_00382498(600, 900);
            p->x340 = (r * 5 + 2) / 6;
            if (func_00382468(2)) {
                if (a->x43 != 8) func_003C3A10(a, 8, 0, 8);
            } else {
                if (a->x43 != 3) func_003C3A10(a, 3, 0, 8);
            }
            func_L01_004450F0(a, 4, -1);
        }
        if (f > 10.0f) {
            if (func_L01_00456500(D_001A4C60, p->x31C) == 0) {
                if (f >= 18.0f) {
                    func_L03_0039D4D8(a, p);
                } else {
                    func_L03_0039D418(a, p);
                }
            }
        }
        break;
    case 4:
    case 5:
        if (a->x60 & 2) {
            func_L03_0039D380(a, p);
        }
        break;
    case 3:
        func_L01_00458F78(a, p->x120, 0, 0);
        func_L03_0039D6A8(a, p->x120, p);
        if (f < 6.0f || func_L01_00456500(D_001A4C60, p->x31C) != 0) {
            func_L03_0039D380(a, p);
        } else if (f > 20.0f) {
            func_L03_0039D4D8(a, p);
        }
        break;
    case 2:
        func_L01_00458F78(a, p->x120, 0, 0);
        func_L01_0045A748(a, p->x120);
        if (f < 4.0f || func_L01_00456500(D_001A4C60, p->x31C) != 0) {
            func_L03_0039D380(a, p);
        } else if (f < 16.0f) {
            func_L03_0039D418(a, p);
        }
        break;
    case 6: {
        u128_t *tab = D_L03_0021D8C0_0039C888[p->x314];
        u128_t v = tab[p->x338 + 1];
        func_L03_0039D6A8(a, &v, p);
        if (D_001426EB[0] == 0 && func_00382468(0x2D0) == 0) {
            if (func_00382468(2)) {
                if (a->x43 != 3) func_003C3A10(a, 3, 0, 3);
            } else {
                if (a->x43 != 8) func_003C3A10(a, 8, 0, 3);
            }
            func_L01_004450F0(a, 10, -1);
        } else {
            f = func_L01_0040E570(a->x10, (u8 *)tab + ((p->x338 << 4) + 0x10));
            if (f < 0.0001f) {
                u128_t *t2 = D_L03_0021D8C0_0039C888[p->x314];
                u16 s = p->x338;
                p->x33E = s;
                p->x338 = s + (u16)p->x33A;
                if (p->x338 >= *(s32 *)t2) {
                    int n = *(u16 *)t2 - 2;
                    p->x33A = -1;
                    p->x338 = n;
                }
                if (p->x338 < 0) {
                    p->x338 = 1;
                    p->x33A = 1;
                }
                if (p->x33E < 2) {
                    if (func_00382468(4) == 0) {
                        p->x330 = a->x18;
                        p->x334 = 0;
                        if (a->x43 != 4) func_003C3A10(a, 4, 0, 3);
                        func_L01_004450F0(a, 7, -1);
                    }
                }
            }
        }
        break;
    }
    case 7:
        if (a->x42 == 4 && func_L01_004395E0(a) > 8.0f) {
            int i = p->x33E;
            p->x334 += (D_001DE380_sda[i] - p->x334) * 0.18f;
            a->xF8 = func_0038DAB8(a->xF8, func_0038DB00(D_001DE388_sda[i], a->xF8) * 0.1f);
            a->x18 = p->x330 + p->x334;
        }
        if (a->x60 & 2) {
            r = func_00382498(60, 120);
            p->x33C = (r * 5 + 2) / 6;
            if (a->x43 != 5) func_003C3A10(a, 5, 0, 3);
            func_L01_004450F0(a, 8, -1);
        }
        break;
    case 8:
        if (func_0038CB00(&p->x33C)) {
            if (a->x43 != 6) func_003C3A10(a, 6, 0, 3);
            func_L01_004450F0(a, 9, -1);
        }
        break;
    case 9:
        if (a->x42 == 6 && func_L01_004395E0(a) > 1.0f) {
            p->x334 = p->x334 * 0.96000004f;
            a->x18 = p->x330 + p->x334;
        }
        if (a->x60 & 2) {
            if (a->x43 != 1) func_003C3A10(a, 1, 0, 3);
            func_L01_004450F0(a, 6, -1);
        }
        break;
    case 10:
    case 11:
        if (a->x60 & 2) {
            if (a->x43 != 1) func_003C3A10(a, 1, 0, 3);
            func_L01_004450F0(a, 6, -1);
        }
        break;
    case 12:
        if (func_L01_004561B8(a)) {
            p->x340 = func_00382498(0x177, 0x2EE);
        }
        if (func_0038CAD0(&p->x340)) {
            if (a->x43 != 9) func_003C3A10(a, 9, 0, 15);
            func_L01_004450F0(a, 13, -1);
        }
        break;
    case 13:
        if (a->x60 & 2) {
            if (a->x43 != 7) func_003C3A10(a, 7, 0, 15);
            func_L01_004450F0(a, 12, -1);
        }
        break;
    }
    func_L03_0043BE98(a, p->x1A0, 2, 4, a->x20 == 1 || a->x20 == 12);
}
/* localdecomp:end func_L03_0039C888 */

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

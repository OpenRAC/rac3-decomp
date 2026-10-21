#include "common.h"

typedef struct {
    u8 pad[104];
    s32 f68;
} Moby_0031BEF0;
typedef struct {
    u8 pad0[0x24];
    u8 *x24;
    u8 pad28[0xC];
    u16 h34;
} T_31DB28;
typedef struct {
    u8 pad0[0x18];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 pad1C[0x14];
} H_31DB28;
typedef struct {
    u8 pad0[0x6C];
    f32 f6C;
    u8 pad70[0x80];
} G_31DB28;
typedef struct {
    u8 pad0[0x18];
    T_31DB28 *x18;
} D_31DB28;
typedef struct { u8 b[320]; } E320_321CB8;
typedef struct { u8 b[160]; } E160_321CB8;
typedef struct { u8 x0; u8 x1; u8 pad[238]; } E240_321CB8;
typedef struct { u8 pad[80]; s32 idx; } Sub_00322E00;
typedef struct { u8 pad[104]; Sub_00322E00 *sub; } Moby_00322E00;

INCLUDE_ASM("asm/levels", func_L01_0031C1D0);

/* localdecomp:start func_L01_0031C348 */

extern s32 func_0038CAD0(s32);
extern void func_003C2880(Moby_0031BEF0 *);
extern void func_L01_00404A10_0031C348(void *, Moby_0031BEF0 *);
extern void func_L01_0031C398();

void func_L01_0031C348(Moby_0031BEF0 *m) {
    if (func_0038CAD0(m->f68)) {
        func_003C2880(m);
    } else {
        func_L01_00404A10_0031C348(func_L01_0031C398, m);
    }
}
/* localdecomp:end func_L01_0031C348 */

INCLUDE_ASM("asm/levels", func_L01_0031C398);

/* localdecomp:start func_L01_0031C770 */
void func_L01_0031C770(u8 *a0, u8 *a1, s8 *a2, s32 a3);

#define CHK(m) ((m) != 0 && *(u8 **)((m) + 36) != 0 && (*(u8 **)((m) + 36))[70] == 18)

void func_L01_0031C770(u8 *a0, u8 *a1, s8 *a2, s32 a3) {
    if (a1 == 0) {
        return;
    }
    if (*(s16 *)(a1 + 170) == 5669 && *(u8 **)(a1 + 104) != 0 && *(u8 **)(*(u8 **)(a1 + 104) + 1004) != 0) {
        func_L01_0031C770(a0, *(u8 **)(*(u8 **)(a1 + 104) + 1004), a2, a3);
    }
    if (a3 != 0) {
        if (a2[120] > 0) {
            *(u16 *)(a1 + 52) &= ~2;
        } else if (a2[120] < 0) {
            *(u16 *)(a1 + 52) |= 2;
        }
        if (a2[121] > 0 && !CHK(a1)) {
            a1[49] = 1;
            *(u16 *)(a1 + 52) &= ~1;
        } else if (a2[121] < 0 && !CHK(a1)) {
            a1[49] = 0;
            *(u16 *)(a1 + 52) |= 1;
        }
        if (a2[123] > 0 && *(u8 **)(a1 + 36) != 0) {
            *(s32 *)(a1 + 152) = *(s32 *)(*(u8 **)(a1 + 36) + 16);
        } else if (a2[123] < 0 && *(u8 **)(a1 + 36) != 0) {
            *(s32 *)(a1 + 152) = 0;
        }
        if (a2[124] != 0) {
            *(u16 *)(a0 + 52) |= 2;
        }
    } else {
        if (a2[120] > 0 && !CHK(a1)) {
            *(u16 *)(a1 + 52) |= 2;
        } else if (a2[120] < 0 && !CHK(a1)) {
            *(u16 *)(a1 + 52) &= ~2;
        }
        if (a2[121] > 0 && !CHK(a1)) {
            a1[49] = 0;
            *(u16 *)(a1 + 52) |= 1;
        } else if (a2[121] < 0 && !CHK(a1)) {
            a1[49] = 1;
            *(u16 *)(a1 + 52) &= ~1;
        }
        if (a2[123] > 0) {
            *(s32 *)(a1 + 152) = 0;
        } else if (a2[123] < 0) {
            *(s32 *)(a1 + 152) = *(s32 *)(*(u8 **)(a1 + 36) + 16);
        }
    }
}
/* localdecomp:end func_L01_0031C770 */

/* localdecomp:start func_L01_0031CA18 */
extern void func_L01_0031C770(u8 *a0, u8 *a1, s8 *a2, s32 a3);
extern short *D_L01_0021DE20[];
extern int D_L01_001E001C;

void func_L01_0031CA18(void *a0, void *a1, int a2, void *a3) {
    short *p = D_L01_0021DE20[a2];

    if (p != 0) {
        do {
            ((void (*)(void *, int, void *, void *))func_L01_0031C770)(a0, D_L01_001E001C + ((*p & 0x7FFF) << 8), a1, a3);
        } while (*p++ >= 0);
    }
}
/* localdecomp:end func_L01_0031CA18 */

INCLUDE_ASM("asm/levels", func_L01_0031CAA8);

/* localdecomp:start func_L01_0031CC48 */
extern void func_003C2880(Moby_0031BEF0 *);
extern s32 func_L01_003F7EE8(u8 *a0);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
void func_L01_0031CC48(u8 *a0) {
    switch (a0[32]) {
    case 0:
        if (func_L01_003F7EE8(a0)) {
            func_L01_004450F0(a0, 1, -1);
            *(u16 *)(a0 + 52) |= 0x2000;
        }
        break;
    case 1:
        func_L01_003F7EE8(a0);
        if (a0[35] < 2) {
            ((void (*)(u8 *a0))func_003C2880)(a0);
        } else {
            a0[35] -= 2;
        }
        break;
    }
}
/* localdecomp:end func_L01_0031CC48 */

LINKER_REMNANT("asm/levels", func_L01_0031CCE0);

INCLUDE_ASM("asm/levels", func_L01_0031CCE8);

INCLUDE_ASM("asm/levels", func_L01_0031D188);

/* localdecomp:start func_L01_0031D1D8 */
extern u8 *func_L01_0031D3D0(s32, s32, s32);

void func_L01_0031D1D8(u8 *a0, s32 a1, s32 a2) {
    u8 *r = func_L01_0031D3D0(a1, a2, *(s16 *)(a0 + 170) == 0xE9E);
    if (r != 0) {
        *(u8 **)(r + 184) = a0;
    }
}
/* localdecomp:end func_L01_0031D1D8 */

INCLUDE_ASM("asm/levels", func_L01_0031D218);

/* localdecomp:start func_L01_0031D398 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_0031D398(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0031D398 */

INCLUDE_ASM("asm/levels", func_L01_0031D3D0);

INCLUDE_ASM("asm/levels", func_L01_0031D510);

/* localdecomp:start func_L01_0031DB60 */
void func_L01_0031DB60(u8 *a) {
    a[32] = 2;
}
/* localdecomp:end func_L01_0031DB60 */

INCLUDE_ASM("asm/levels", func_L01_0031DB70);

INCLUDE_ASM("asm/levels", func_L01_0031DE80);

/* localdecomp:start func_L01_0031DFD8 */

extern D_31DB28 D_L01_001EAA00[];
extern T_31DB28 *D_001A71A0[];
extern u8 D_0014263F[];
extern G_31DB28 D_L01_002C5600[];
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern void func_0038CF68(f32 *, s32, f32);
extern void func_L01_00446760(H_31DB28 *, u8 *, s32, f32 *, f32);
extern void func_L01_00446978(T_31DB28 *, H_31DB28 *);
extern void func_L01_0031E3B8(u8 *, s32, s32, u8 *);

void func_L01_0031DFD8(u8 *obj, void *a1) {
    f32 v[4];
    H_31DB28 h;
    s32 m = *(s32 *)(obj + 104);
    T_31DB28 *t;

    if (func_003D3CB0(a1, obj + 16, 0, obj, 0) == 0) {
        return;
    }
    t = D_L01_001EAA00[0].x18;
    if (t != 0) {
        if (t != D_001A71A0[0] && (t->x24[70] == 5 || (t->h34 & 0x4000))) {
            func_0038CF68(v, m, 1.0f);
            func_L01_00446760(&h, obj, 0x410000, v, (D_L01_002C5600 + D_0014263F[0])->f6C * 0.1f);
            h.b18 = 5;
            h.b19 = 3;
            h.h1A = *(u16 *)(obj + 170);
            func_L01_00446978(D_L01_001EAA00[0].x18, &h);
            func_L01_0031E3B8(obj + 16, 10, 1, obj);
        }
        if (D_L01_001EAA00[0].x18 != 0) {
            obj[32] = 2;
            return;
        }
    }
    func_L01_0031E3B8(obj + 16, 15, 0, obj);
    obj[32] = 2;
}
/* localdecomp:end func_L01_0031DFD8 */

INCLUDE_ASM("asm/levels", func_L01_0031E148);

INCLUDE_ASM("asm/levels", func_L01_0031E3B8);

INCLUDE_ASM("asm/levels", func_L01_0031E788);

INCLUDE_ASM("asm/levels", func_L01_0031E968);

/* localdecomp:start func_L01_0031F258 */
void func_L01_0031F258(u8 *a) {
    a[32] = 2;
}
/* localdecomp:end func_L01_0031F258 */

INCLUDE_ASM("asm/levels", func_L01_0031F268);

INCLUDE_ASM("asm/levels", func_L01_0031F2E8);

INCLUDE_ASM("asm/levels", func_L01_0031F688);

INCLUDE_ASM("asm/levels", func_L01_0031FBC0);

INCLUDE_ASM("asm/levels", func_L01_0031FC60);

INCLUDE_ASM("asm/levels", func_L01_0031FD50);

INCLUDE_ASM("asm/levels", func_L01_00320088);

INCLUDE_ASM("asm/levels", func_L01_00321608);

INCLUDE_ASM("asm/levels", func_L01_00321710);

INCLUDE_ASM("asm/levels", func_L01_003218A8);

INCLUDE_ASM("asm/levels", func_L01_00321A80);

INCLUDE_ASM("asm/levels", func_L01_00321F88);

INCLUDE_ASM("asm/levels", func_L01_003220A0);

INCLUDE_ASM("asm/levels", func_L01_003220D0);

INCLUDE_ASM("asm/levels", func_L01_00322100);

INCLUDE_ASM("asm/levels", func_L01_00322180);

/* localdecomp:start func_L01_003221B8 */
extern G_31DB28 D_L01_002C5600[];

extern s32 D_L01_001E17B0;
extern s32 D_L01_001DBCA0;
extern u8 D_00142607[];
extern E320_321CB8 D_L01_00276AA0[];
extern E160_321CB8 D_L01_00276D20[];
extern f32 func_003824E0(f32, f32);
extern void func_L01_003225F8(void *, s32, s32, u32, f32, f32, u32, s32, void *, s32, s32);

void func_L01_003221B8(u8 *a0) {
    s32 half;
    s32 i;
    f32 f;

    s32 t;
    half = D_L01_001E17B0 / 2;
    t = *(s32 *)(*(u8 **)(a0 + 104) + 68);
    D_L01_001DBCA0 |= 1;
    if (t != 0) {
        for (i = 0; i < 2; i++) {
            f = func_003824E0(0.025f, 0.03f);
            func_L01_003225F8(&D_L01_00276AA0[i], 20, half, 0x7F7F7F, f, func_003824E0(1.5f, 2.5f), 0xFF2020, 0, a0, 0, 1);
        }
        if (D_L01_001E17B0 >= 20 && (((E240_321CB8 *)&D_L01_002C5600) + D_00142607[0])->x1 >= 2) {
            for (i = 0; i < 2; i++) {
                f = func_003824E0(0.015f, 0.02f);
                func_L01_003225F8(&D_L01_00276D20[i], 10, half, 0xFF7F7F7F, f, func_003824E0(1.2f, 1.8f), 0xFFFF2020, 0, a0, 1, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_003221B8 */

INCLUDE_ASM("asm/levels", func_L01_00322398);

/* localdecomp:start func_L01_00322570 */
void func_L01_00322570(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_00322570 */

INCLUDE_ASM("asm/levels", func_L01_003225F8);

INCLUDE_ASM("asm/levels", func_L01_00322F80);

INCLUDE_ASM("asm/levels", func_L01_00323080);

LINKER_REMNANT("asm/levels", func_L01_00323118);

INCLUDE_ASM("asm/levels", func_L01_00323120);

/* localdecomp:start func_L01_00323300 */
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
void func_L01_00323300(Moby_00322E00 *m) {
    Sub_00322E00 *s = m->sub;
    s32 i = s->idx;
    if (i != -1) {
        u8 *e = D_001A30B0 + i * 128;
        if (*(Moby_00322E00 **)(e + 220) == m && e[208] != 0) func_003A4F28(i);
    }
    s->idx = -1;
}
/* localdecomp:end func_L01_00323300 */

INCLUDE_ASM("asm/levels", func_L01_00323368);

INCLUDE_ASM("asm/levels", func_L01_00323A18);

INCLUDE_ASM("asm/levels", func_L01_00323C68);

INCLUDE_ASM("asm/levels", func_L01_00323F38);

LINKER_REMNANT("asm/levels", func_L01_00324160);

INCLUDE_ASM("asm/levels", func_L01_00324180);

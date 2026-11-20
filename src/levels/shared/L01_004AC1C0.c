#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_004AC1C0);

LINKER_REMNANT("asm/levels", func_L01_004AC610);

/* localdecomp:start func_L01_004AC618 */
/* localdecomp:start func_L01_004AC618 */
#include "vu0.h"
typedef struct {
    vu0_v4 verts[4];
    u32 colors[4];
    u8 tag[0x20];
    long q0, q1, q2, q3;
} Quad_4AC618_004AC618;
extern s32 D_L01_001D673C_004AC618;
extern s32 D_L01_001D6694_004AC618;
typedef struct { u8 pad[0x20]; s16 h20, h22; } T_16C580_4AC618_004AC618;
extern T_16C580_4AC618_004AC618 D_0016C580_004AC618;
extern u8 D_L01_001D9940_004AC618[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D9940_004AC618, 8");
extern f32 D_L01_001D9960_004AC618[][4] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D9960_004AC618, 8");
extern void func_0038CE50(void *, void *, f32);
extern s32 func_L01_0040F6E8_004AC618(void *, s32 *, f32);
extern long func_00389598(s32);
extern void func_0038CD28(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

void func_L01_004AC618(u8 *obj)
{
    f32 pos[4];
    Quad_4AC618_004AC618 quad;
    f32 tmp[4];
    s32 alpha;
    f32 z;
    s32 i;

    if (D_L01_001D673C_004AC618 != 0) {
        return;
    }
    alpha = 0;
    func_0038CE50(pos, obj, 0.0009765625f);
    if (func_L01_0040F6E8_004AC618(pos, &alpha, 32.0f) < 0) {
        return;
    }
    if (D_L01_001D6694_004AC618 == 6 && D_0016C580_004AC618.h20 == 1
        && D_0016C580_004AC618.h22 >= 0x7E) {
        alpha -= D_0016C580_004AC618.h22;
        if (alpha <= 0) {
            return;
        }
    }
    quad.q1 = func_00389598(0);
    quad.q2 = 0xFF9000000260L;
    quad.q3 = 0x8000000044L;
    quad.q0 = 0;
    func_0038CD28(quad.tag, D_L01_001D9940_004AC618, 0x20);
    func_0038CE20(tmp, obj, 0.0009765625f);
    z = *(f32 *)(obj + 0x18) + 0.1f;
    if (D_L01_001D6694_004AC618 == 6 || D_L01_001D6694_004AC618 == 0 || D_L01_001D6694_004AC618 == 4) {
        z = func_003C3D30(obj + 0x10, 0, 0, 0.5f) + 0.1f;
    }
    for (i = 0; i < 4; i++) {
        quad.colors[i] = ((alpha >> 1) << 24) | 0x808080;
        func_0038D000(&quad.verts[i], D_L01_001D9960_004AC618[i], obj + 0xC0);
        vec_add_ab(&quad.verts[i], &quad.verts[i], obj + 0x10);
        quad.verts[i].z = z;
    }
    func_003D2DA0(quad.verts, 0, 0);
}
/* localdecomp:end func_L01_004AC618 */
/* localdecomp:end func_L01_004AC618 */

LINKER_REMNANT("asm/levels", func_L01_004AC838);

/* localdecomp:start func_L01_004AC840 */
extern s32 D_0016C580_s __attribute__((section(".data")));
extern s32 D_L01_0023AC70[];

/* from rac2-decomp's func_L08_0036EFC8, renamed */
void func_L01_004AC840(void)
{
    s32 i;

    if (D_0016C580_s != 0) {
        *(u16 *)(D_0016C580_s + 0x34) |= 3;
        *(s32 *)(D_0016C580_s + 0x98) = 0;
        for (i = 0; D_L01_0023AC70[i] != 0; i++) {
            *(u16 *)(D_L01_0023AC70[i] + 0x34) |= 3;
            *(s32 *)(D_L01_0023AC70[i] + 0x98) = 0;
        }
    }
}
/* localdecomp:end func_L01_004AC840 */

/* localdecomp:start func_L01_004AC8A8 */
typedef struct {
    u8 pad0[16];
    s32 f10;
} Sub_4A8EB8;
typedef struct {
    u8 pad0[36];
    Sub_4A8EB8 *p24;
    u8 pad28[12];
    u16 h34;
    u8 pad36[98];
    s32 f98;
} Obj_4A8EB8;
extern Obj_4A8EB8 *D_0016C580[];
extern void func_003A56A0(void);
extern void func_003A58C0(Obj_4A8EB8 *, s32);
void func_L01_004AC8A8(void) {
    Obj_4A8EB8 *o = D_0016C580[0];
    if (o != 0) {
        o->h34 &= 0xFFFC;
        func_003A56A0();
        func_003A58C0(D_0016C580[0], 0);
        D_0016C580[0]->f98 = D_0016C580[0]->p24->f10;
    }
}
/* localdecomp:end func_L01_004AC8A8 */

/* localdecomp:start func_L01_004AC900 */
typedef struct {
    u8 *p0;
    u8 pad4[4];
    s32 w8;
    u8 padC[0x14];
    s16 h20;
    s16 h22;
    u8 pad24[6];
    s16 h2A;
    u8 pad2C[0x40];
    s32 w6C;
} T_16C580_004AC900;
typedef struct {
    u8 pad0[0x68];
    s32 w68;
    s32 w6C;
} Scene_004AC900;
typedef struct {
    u8 pad0[0xC];
    s32 wC;
    s32 w10;
} H_004AC900;
typedef struct {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x70];
    s16 h76;
    u8 pad78[0x20];
    s16 h98;
    u8 pad9A[4];
    s16 h9E;
} K_004AC900;
typedef struct {
    u8 pad0[0x25E5];
    u8 b25E5;
} A_004AC900;
extern T_16C580_004AC900 D_0016C580_004AC900;
extern Scene_004AC900 D_L01_001E6D80_004AC900;
extern s32 D_L01_001E13E0_004AC900;
extern u8 D_L01_00251400_004AC900[][64];
extern s32 D_L01_001E1420_004AC900;
extern s32 D_L01_001E1070;
extern H_004AC900 D_L01_001EA940_004AC900;
extern f32 D_L01_001DF950_004AC900[1];
extern s32 D_L01_001DF958_004AC900[1];
extern A_004AC900 D_001A4BE0_004AC900;
extern K_004AC900 D_001CCFD0_004AC900;
extern void func_0038CB78(void *, s32, s32);
extern void func_003A9050(void);
extern s32 func_L01_005003D0(s32, s32);
extern void func_L01_005108C0(s32);
extern void func_L01_004B9798(s32);
extern void func_0038A238(s32);
extern void func_003A2750(s32);
extern void func_L01_0042C740(s32, s32);
extern void func_003A2B68(s32, s32);
extern void func_0039A690(s32);
extern void func_003A4288(void);
extern s32 func_0012C908(s32);
extern void func_003A1798(void);

void func_L01_004AC900(s32 a0)
{
    s32 i;
    s32 n;

    D_0016C580_004AC900.h20 = a0;
    D_0016C580_004AC900.h22 = -1;
    D_0016C580_004AC900.w8 = 0;
    D_0016C580_004AC900.w6C = 0;
    func_0038CB78(&D_L01_001E6D80_004AC900, 0, 0x1E0);
    func_0038CB78(&D_L01_001E13E0_004AC900, 0, 0x40);
    func_0038CB78(D_L01_00251400_004AC900[0], 0, 0x40);
    func_0038CB78(D_L01_00251400_004AC900[1], 0, 0x40);
    func_0038CB78(&D_L01_001E1420_004AC900, 0, 0x40);
    func_003A9050();
    D_L01_001E1070 -= 0x60000;
    D_L01_001E6D80_004AC900.w68 = D_L01_001EA940_004AC900.wC + D_L01_001E1070;
    D_L01_001E6D80_004AC900.w6C = D_L01_001EA940_004AC900.w10 + D_L01_001E1070;
    for (i = 0; i < 1; i++) {
        D_L01_001DF950_004AC900[i] = 1.0f;
        D_L01_001DF958_004AC900[i] = 0;
    }
    func_L01_005003D0(0x65, 2);
    D_001A4BE0_004AC900.b25E5 = 1;
    func_L01_005108C0(0);
    func_L01_004B9798(1);
    *(u16 *)(D_0016C580_004AC900.p0 + 0x34) |= 1;
    if (D_001CCFD0_004AC900.h4 != 0) {
        func_0038A238(5);
        func_003A2750(1);
    }
    if (a0 == 0) {
        n = 2;
        func_L01_0042C740(1, 5);
    } else {
        s32 h = D_0016C580_004AC900.h2A;
        func_L01_0042C740(0, h ? 0 : 2);
        n = h == 0;
    }
    func_003A2B68(n + 5000, 0);
    func_0039A690(0);
    while (D_001CCFD0_004AC900.h76 != 0 || D_001CCFD0_004AC900.h9E != 3 || D_001CCFD0_004AC900.h98 >= 7000) {
        func_003A4288();
        func_0012C908(0);
    }
    func_003A1798();
}
/* localdecomp:end func_L01_004AC900 */

/* localdecomp:start func_L01_004ACB38 */
extern u8 D_001A4BE0[];
extern u8 D_001CCFD0[];
extern u16 D_0016C5AA[];
extern void func_L01_0045F328(s32);
extern void func_003A4288(void);
extern void func_L01_0041A6E0(void);
extern void func_L01_004AC900(s32);

void func_L01_004ACB38(void)
{
    u8 *g = D_001A4BE0;
    u8 *p;

    if (*(s32 *)(g + 10320) <= 0) {
        *(s32 *)(g + 10320) = 1;
    }
    func_L01_0045F328(0);
    p = D_001CCFD0;
    if (*(u16 *)(p + 118) != 6 && *(u16 *)(p + 118) != 7) {
        *(u16 *)(p + 118) = 5;
    }
    if (*(u16 *)(p + 158) != 6 && *(u16 *)(p + 158) != 7) {
        *(u16 *)(p + 158) = 5;
    }
    func_003A4288();
    func_L01_0041A6E0();
    func_L01_004AC900(0);
    D_0016C5AA[0] = 0;
}
/* localdecomp:end func_L01_004ACB38 */

/* localdecomp:start func_L01_004ACBC8 */
extern f32 D_L01_001DF950_004ACBC8[1];
extern s32 D_L01_001DF958_004ACBC8[1];
typedef struct { u8 pad[0x20]; s16 h20, h22; } T_16C580_004ACBC8;
extern T_16C580_004ACBC8 D_0016C580_004ACBC8;
extern s32 D_001D545C;
extern s32 D_00143950 __attribute__((section(".data")));
typedef struct {
    u8 pad0[0x34];
    s32 frame;
    s32 tick;
    s32 chunk;
} Scene_004ACBC8;
extern Scene_004ACBC8 D_L01_001E6D80_004ACBC8;
extern s32 D_L01_001D673C;
extern s32 D_L01_001DFB44;
extern s32 D_L01_001D6674;
extern u8 D_001D5638;
extern s32 D_L01_001E1070;
extern u8 *D_L01_001E1060_004ACBC8[];
extern void func_0039A690(s32);
extern void func_0039EC28(s32, s32);
extern s32 func_L01_005003D0(s32, s32);
extern void func_L01_005108C0(s32);
extern void func_L01_004B9798(s32);
extern void func_003A9050(void);
extern void func_003A8220(void *);

void func_L01_004ACBC8(s32 a0)
{
    s32 i;
    s32 t;

    for (i = 0; i < 1; i++) {
        D_L01_001DF950_004ACBC8[i] = 1.0f;
        D_L01_001DF958_004ACBC8[i] = 0;
    }
    D_0016C580_004ACBC8.h20 = 0;
    D_0016C580_004ACBC8.h22 = -1;
    if (D_001D545C == a0) {
        s32 n;
        func_L01_004AC900(3);
        n = D_00143950 ? 0x50 : 0x60;
        D_L01_001E6D80_004ACBC8.frame = 0;
        D_L01_001E6D80_004ACBC8.chunk = D_L01_001E6D80_004ACBC8.frame / n;
        func_0039A690(D_L01_001E6D80_004ACBC8.chunk);
        D_L01_001E6D80_004ACBC8.tick = D_L01_001E6D80_004ACBC8.frame % n;
        return;
    }
    if (D_L01_001D673C != 0) {
        D_L01_001DFB44 = a0;
        D_L01_001D6674 = 1;
        return;
    }
    if (D_001D5638 != 0) {
        D_001D5638 = 0;
    } else {
        func_0039EC28(0, a0);
    }
    func_L01_005003D0(0x65, 2);
    D_001A4BE0[0x25E5] = 1;
    func_L01_005108C0(0);
    func_L01_004B9798(1);
    D_L01_001DFB44 = a0;
    D_0016C580_004ACBC8.h20 = 1;
    D_0016C580_004ACBC8.h22 = -1;
    func_003A9050();
    t = D_L01_001E1070 - 0x60000;
    D_L01_001E1070 = t;
    func_003A8220(D_L01_001E1060_004ACBC8[0] + t);
}
/* localdecomp:end func_L01_004ACBC8 */

/* localdecomp:start func_L01_004ACD40 */
typedef struct { u8 pad[0x20]; s16 h20, h22; } T_16C580;
extern T_16C580 D_0016C580_004ACD40;
extern f32 D_L01_001DF950_004ACD40[] __attribute__((section(".sdata")));
extern s32 D_L01_001E6D80_004ACD40[];
extern void func_L01_004AC900(s32);

void func_L01_004ACD40(void) {
    s32 i;

    for (i = 0; i >= 0; i--) {
        D_L01_001DF950_004ACD40[i] = 1.0f;
    }
    D_0016C580_004ACD40.h20 = 0;
    D_0016C580_004ACD40.h22 = -1;
    func_L01_004AC900(3);
    D_L01_001E6D80_004ACD40[13] = 1;
}
/* localdecomp:end func_L01_004ACD40 */

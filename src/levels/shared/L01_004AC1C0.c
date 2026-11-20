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

INCLUDE_ASM("asm/levels", func_L01_004AC900);

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

INCLUDE_ASM("asm/levels", func_L01_004ACBC8);

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

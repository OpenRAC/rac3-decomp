#include "common.h"

typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;
typedef struct { u8 pad[16]; u8 sub[248 - 16]; f32 f; } S457;
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_0045B538 */
extern void func_L01_0045B6C8(u8 *, u8 *, f32);
extern u8 *func_L01_00448FF0(u8 *);
extern void func_L01_0045B8F0(u8 *, u8 *);
extern s32 func_L01_0045D0B0(u8 *);
extern s32 func_L01_0045D158(u8 *, u8 *);
extern void func_L01_00446BC8(u8 *, s32, s32, u8 *, f32);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define U16(p, o) (*(u16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

void func_L01_0045B538(u8 *a0, u8 *a1) {
    s32 hit = 0;
    u8 *p;
    f32 y;
    f32 lim;

    func_L01_0045B6C8(a0, a1, 0.0f);
    if (S32(a1, 216) != -1 && S16(a1, 192) != 0) {
        p = func_L01_00448FF0(a0);
        if (p != 0 && U8(p, 73) != 0 && U16(p, 74) != 0 &&
            ((U16(p, 74) >> S32(a1, 216)) & 1)) {
            hit = 1;
            S32(a1, 148) |= 0x200;
        }
    }
    if (hit) {
        func_L01_0045B8F0(a0, a1);
        func_L01_0045B6C8(a0, a1, 0.0f);
    }
    y = F32(a0, 24);
    lim = F32(a1, 144);
    if (y <= lim) {
        if (lim <= y - F32(a1, 168)) {
            F32(a0, 24) = lim;
        }
        U16(a1, 194) = 0;
        U16(a1, 192)++;
    } else {
        U16(a1, 192) = 0;
        U16(a1, 194)++;
    }
    if (S32(a1, 156) & 1) {
        if (func_L01_0045D0B0(a0)) {
            S32(a1, 156) &= ~1;
        } else {
            S32(a1, 148) |= 0x100;
        }
    }
    if (S32(a1, 56) & 0x200) {
        if (func_L01_0045D158(a0, a1)) {
            func_L01_00446BC8(a0, 0, 0x10000, a0 + 16, 255.0f);
        }
    }
}
/* localdecomp:end func_L01_0045B538 */

INCLUDE_ASM("asm/levels", func_L01_0045B6C8);

/* localdecomp:start func_L01_0045B8D8 */
extern u128_t D_L01_001E0240[] __attribute__((section(".sdata")));

void func_L01_0045B8D8(u8 *a0, u8 *a1) {
    D_L01_001E0240[0] = *(u128_t *)(a0 + 0x10);
}
/* localdecomp:end func_L01_0045B8D8 */

/* localdecomp:start func_L01_0045B8F0 */
extern u128_t D_L01_001E0240[] __attribute__((section(".sdata")));

void func_L01_0045B8F0(u8 *a0, u8 *a1) {
    *(u128_t *)(a0 + 0x10) = D_L01_001E0240[0];
}
/* localdecomp:end func_L01_0045B8F0 */

/* localdecomp:start func_L01_0045B908 */
extern int func_L01_0044C638(u8 *a, int b, u8 *c, u8 *d, u8 *e, u8 *f);

void func_L01_0045B908(u8 *a0, u8 *a1)
{
    int v = *(int *)(a1 + 136);
    if (v != 0) {
        if (func_L01_0044C638(a0, v, a0 + 16, a0 + 240, a0 + 16, a0 + 240) != 0) {
            *(int *)(a1 + 148) |= 0x40;
        }
    }
}
/* localdecomp:end func_L01_0045B908 */

/* localdecomp:start func_L01_0045B958 */
typedef struct { u8 pad[0x1C]; S_4574A0 *target; } Link_45B958;
/* from rac4-decomp's func_00142220 */
S_4574A0 *func_L01_0045B958(M_4574A0 *m) {
    return (*(Link_45B958 **)((u8 *)m + 0x68))->target;
}
/* localdecomp:end func_L01_0045B958 */

INCLUDE_ASM("asm/levels", func_L01_0045B968);

INCLUDE_ASM("asm/levels", func_L01_0045BAC0);

INCLUDE_ASM("asm/levels", func_L01_0045BB60);

/* localdecomp:start func_L01_0045BD10 */
extern void func_L01_00448890(char *a0, char *a1, int a2, float f12, float f13,
                          float f14, float f15);

/* from rac2-decomp's func_L01_00322288, renamed */
int func_L01_0045BD10(int a0, float f12) {
    char *p = func_L01_0045B958(a0);
    if (p == 0)
        return 0;
    func_L01_00448890((char *)a0 + 0xF8, p + 0xB4, 0, f12, *(float *)(p + 0x14),
                  *(float *)(p + 0x18), *(float *)(p + 0x1C));
    return 1;
}
/* localdecomp:end func_L01_0045BD10 */

LINKER_REMNANT("asm/levels", func_L01_0045BD70);

/* localdecomp:start func_L01_0045BD78 */
extern S_4574A0 *func_L01_0045B958(M_4574A0 *);
void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d)
{
    u8 *p = ((u8 * (*)(u8 *a0))func_L01_0045B958)(a0);

    if (p != 0) {
        *(f32 *)(p + 32) = a;
        *(f32 *)(p + 36) = a;
        *(f32 *)(p + 40) = b;
        *(f32 *)(p + 20) = c;
        *(f32 *)(p + 24) = c;
        *(f32 *)(p + 28) = d;
    }
}
/* localdecomp:end func_L01_0045BD78 */

LINKER_REMNANT("asm/levels", func_L01_0045BDE0);

/* localdecomp:start func_L01_0045BDE8 */
extern s32 D_L01_0021F6C0[];
extern s32 func_L01_0045BE38(void *a0, s32 a1);
s32 func_L01_0045BDE8(void *a0, s32 a1) {
    s32 v;
    if (a1 == -1) return 0;
    v = D_L01_0021F6C0[a1];
    if (v == 0) return 0;
    return func_L01_0045BE38(a0, v);
}
/* localdecomp:end func_L01_0045BDE8 */

INCLUDE_ASM("asm/levels", func_L01_0045BE38);

LINKER_REMNANT("asm/levels", func_L01_0045C148);

/* localdecomp:start func_L01_0045C150 */
extern S_4574A0 *func_L01_0045B958(M_4574A0 *);
s32 func_L01_0045C150(void *a0, u16 *a1, s32 a2, s32 a3) {
    u8 *p;

    p = ((u8 * (*)(void *))func_L01_0045B958)(a0);
    if (p == 0) {
        return 0;
    }
    *(u16 **)(p + 196) = a1;
    *(s32 *)(p + 156) &= ~4;
    if (a2 == -1) {
        *(s16 *)(p + 202) = *a1 - 1;
    } else {
        *(s16 *)(p + 202) = a2;
    }
    *(s16 *)(p + 200) = a3;
    return 1;
}
/* localdecomp:end func_L01_0045C150 */

INCLUDE_ASM("asm/levels", func_L01_0045C1D0);

/* localdecomp:start func_L01_0045C240 */
extern s32 D_L01_001D7DDC;
extern f32 D_L01_001D7DD4;
void func_L01_0045C240(void) {
    D_L01_001D7DDC++;
    D_L01_001D7DD4 += (f32)*(volatile u32 *)0x10000000;
}
/* localdecomp:end func_L01_0045C240 */

LINKER_REMNANT("asm/levels", func_L01_0045C298);

INCLUDE_ASM("asm/levels", func_L01_0045C2A0);

INCLUDE_ASM("asm/levels", func_L01_0045C510);

INCLUDE_ASM("asm/levels", func_L01_0045C7A8);

INCLUDE_ASM("asm/levels", func_L01_0045C950);

INCLUDE_ASM("asm/levels", func_L01_0045CC18);

INCLUDE_ASM("asm/levels", func_L01_0045CCD8);

INCLUDE_ASM("asm/levels", func_L01_0045CDA0);

INCLUDE_ASM("asm/levels", func_L01_0045CED0);

INCLUDE_ASM("asm/levels", func_L01_0045CF00);

LINKER_REMNANT("asm/levels", func_L01_0045D0A8);

/* localdecomp:start func_L01_0045D0B0 */
extern S_4574A0 *func_L01_0045B958(M_4574A0 *);
extern s32 D_L01_0021F6C0[];
extern s32 func_L01_004463F8(u8 *, u8 *, s32);
extern s32 func_L01_00476F10(s32, f32, u8 *, f32 *);

s32 func_L01_0045D0B0(u8 *a) {
    u8 *o;
    u8 *e;
    u8 *p;
    f32 buf[4];

    o = ((u8 * (*)(u8 *))func_L01_0045B958)(a);
    if (o == 0 || *(s32 *)(o + 60) == -1) {
        return 0;
    }
    e = ((u8 * *)&D_L01_0021F6C0)[*(s32 *)(o + 60)];
    p = a + 16;
    if (func_L01_004463F8(p, e + 16, *(s32 *)e) != 0) {
        if (func_L01_00476F10(*(s32 *)(o + 60), *(f32 *)o, p, buf) == 0) {
            return 1;
        }
    }
    *(s32 *)(o + 156) |= 1;
    return 0;
}
/* localdecomp:end func_L01_0045D0B0 */

INCLUDE_ASM("asm/levels", func_L01_0045D158);

INCLUDE_ASM("asm/levels", func_L01_0045D218);

INCLUDE_ASM("asm/levels", func_L01_0045D248);

LINKER_REMNANT("asm/levels", func_L01_0045D4A8);

INCLUDE_ASM("asm/levels", func_L01_0045D4B8);

INCLUDE_ASM("asm/levels", func_L01_0045D5C0);

/* localdecomp:start func_L01_0045D728 */
extern f32 func_0038CED8(u8 *);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);

f32 func_L01_0045D728(u8 *a0, void *a1) {
    f32 v[4];
    f32 m[12];
    func_L01_0040EE50(m, a0 + 192);
    func_0038D000(v, a1, m);
    return func_0038D160(v[2], ((f32 (*)(void *))func_0038CED8)(v));
}
/* localdecomp:end func_L01_0045D728 */

INCLUDE_ASM("asm/levels", func_L01_0045D788);

INCLUDE_ASM("asm/levels", func_L01_0045DA60);

INCLUDE_ASM("asm/levels", func_L01_0045DBF0);

INCLUDE_ASM("asm/levels", func_L01_0045DF48);

INCLUDE_ASM("asm/levels", func_L01_0045E010);

INCLUDE_ASM("asm/levels", func_L01_0045E0D8);

/* localdecomp:start func_L01_0045E1B8 */
extern void func_0038CE20(void *, void *, float);
extern void func_L01_0045E0D8(void *, void *, void *);
void func_L01_0045E0D8(void *a0, void *a1, void *a2);

/* from rac2-decomp's func_002B03B8, renamed */
void func_L01_0045E1B8(void *first, void *second, void *third) {
    float vector[4];
    func_0038CE20(vector, second, -1.0f);
    func_L01_0045E0D8(first, vector, third);
}
/* localdecomp:end func_L01_0045E1B8 */

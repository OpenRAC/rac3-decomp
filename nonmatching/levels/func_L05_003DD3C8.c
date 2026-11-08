/* near miss (level 5, Daxx): 10 differences: needs @ps2as; D_001DF1E0_sda and p->f8 in swapped float registers on the first-frame path, and in case 2 the constant 3 in v1 (retail v0) with the D_L05_001DF8B8 lui scheduled earlier; swapping the add operands or the two stores gave 12 */
#include "common.h"

/* localdecomp:start func_L05_003DD3C8 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct P_3DD3C8 {
    u8 pad0[0x8];
    f32 f8;
    u8 pad1[0x4];
    f32 f10;
    s16 f14;
} P_3DD3C8;

typedef struct S_3DD3C8 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x4];
    u8 f20;
    u8 pad2[0x10];
    u8 f31;
    u8 pad3[0x2];
    u16 f34;
    u8 pad4[0xC];
    u8 f42;
    u8 f43;
    u8 pad5[0x1C];
    u8 f60;
    u8 pad6[0x7];
    P_3DD3C8 *f68;
    u8 pad7[0x44];
    u8 fB0;
    u8 pad8[0x3F];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} S_3DD3C8;

extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001CCFD0[];
extern u8 D_001BBC40[];
extern u8 D_00142CBD[];
extern s32 D_001A6290[];
extern s32 D_L05_001DF8B8[];
extern s32 D_001D545C_sda;
extern f32 D_001DF1E0_sda;
extern f32 D_001DF1E4_sda;
extern s32 D_001DF4DC_sda;
__asm__(".extern D_001D545C_sda, 4");
__asm__(".extern D_001DF1E0_sda, 4");
__asm__(".extern D_001DF1E4_sda, 4");
__asm__(".extern D_001DF4DC_sda, 4");
__asm__(".extern D_L05_001DF8B8, 16");

void func_L05_003DDB90(void *);
void func_L05_003DD790(void *);
void func_L04_003E3978(void *);
void func_003A1798(void);
void func_L01_00419188(s32);
void func_L01_004F50C8(void *, void *, s32, s32);
void func_L01_003EB5E0(s32, s32);
void func_L01_0043B510(s32);
void func_0039EC28(s32, s32);
void func_L01_004450F0(void *, s32, s32);
void func_003C3A10(void *, s32, s32, s32);
void func_L01_00451F60(s32, s32, s32);
void func_L01_004A3610(void *, void *);
void func_003C2880(void *);
void func_L01_0050FB40(s32, s32, f32);
s32 func_L01_004561B8(void *);
s32 func_0038CB00(void *);
s32 func_L01_0041A5B0(s32, s32);
f32 func_0038DAB8(f32, f32);
f32 func_L01_0040E548(void *, void *);
f32 func_L01_0040E570(void *, void *);

void func_L05_003DD3C8(void *m) {
    S_3DD3C8 *s = m;
    P_3DD3C8 *p;
    u8 *c;
    u8 *g;
    s32 r;

    p = s->f68;
    if (s->f20 == 0) {
        if (D_00142CBD[0] != 0) {
            if (D_001BBC40[s->fB0 + (D_001D545C_sda << 4)] & 0x80) {
                func_003C2880(s);
                return;
            }
            s->f31 = 0;
            s->f34 = s->f34 | 1;
            func_L01_004450F0(s, 5, -1);
        } else {
            f32 t;
            *(u128_t *)p = *(u128_t *)((u8 *)s + 0x10);
            t = D_001DF1E0_sda + p->f8;
            p->f10 = s->fF8;
            s->fF4 = 1.5707964f;
            s->f18 = t;
            func_L01_004450F0(s, 1, -1);
        }
    }

    switch (s->f20) {
    case 1:
        func_L05_003DDB90(s);
        s->fF0 = func_0038DAB8(s->fF0, D_001DF1E4_sda * 0.017453292f * 0.020000001f);
        if (func_L01_0040E548((u8 *)s + 0x10, D_001A4C60) < 9.0f) {
            func_L05_003DD790(s);
        }
        break;
    case 2:
        c = D_001CCFD0;
        if (*(s16 *)(c + 0x76) == 0) {
            if (*(s16 *)(c + 0x9E) == 3 && *(s16 *)(c + 0x98) < 0x1B58) {
                if (func_L01_004561B8(s)) {
                    func_003A1798();
                }
            }
        }
        g = D_001A4BE0;
        *(s16 *)(g + 0x1DC) = 3;
        D_L05_001DF8B8[0] = 1;
        func_L04_003E3978(s);
        *(u128_t *)((u8 *)s + 0x10) = *(u128_t *)(g + 0x80);
        *(u128_t *)((u8 *)s + 0xF0) = *(u128_t *)(g + 0x90);
        if (*(u32 *)(g + 0xC08) & 2) {
            func_L01_0050FB40(0, 0, 25.0f);
        }
        if (s->f42 == 1) {
            func_L05_003DDB90(s);
            if (s->f60 & 2) {
                if (s->f43 != 0) {
                    func_003C3A10(s, 0, 0, 0);
                }
                s->f31 = 0;
                s->f34 = s->f34 | 1;
                func_L01_004450F0(s, 3, -1);
            }
        }
        break;
    case 3:
        if (func_0038CB00((u8 *)p + 0x14) != 0) {
            func_L01_00419188(0x1D);
            {
                u8 *h = D_001A4BE0;
                *(s32 *)(h + 0x25FC) = 0x1D;
                D_001DF4DC_sda = 0;
                func_L01_004F50C8(h + 0x80, h + 0x90, 0, 0);
            }
            func_L01_003EB5E0(0, 0);
            func_L01_0043B510(s->fB0);
            p->f14 = 0x32;
            func_0039EC28(0, -1);
            func_L01_004450F0(s, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(s)) {
            func_L01_00451F60(0xD2B, 0x64, 0);
        }
        if (func_0038CB00((u8 *)p + 0x14)) {
            if (D_001A6290[0] == 0) {
                r = func_L01_0041A5B0(0x1053, 0xC2);
            } else {
                r = func_L01_0041A5B0(0x1054, 0xC3);
            }
            if (r) {
                func_003C2880(s);
            }
        }
        break;
    case 5:
        if (func_L01_0040E570((u8 *)s + 0x10, D_001A4C60) < 72.25f) {
            func_L01_0043B510(s->fB0);
            func_L01_004A3610(D_001A4C60, D_001A4C60 + 0x10);
            func_L01_00451F60(0x25A, 0x4B, 0);
            func_003C2880(s);
        }
        break;
    }
}
/* localdecomp:end func_L05_003DD3C8 */

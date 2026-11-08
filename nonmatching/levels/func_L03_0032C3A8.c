/* near miss (level 3, Starship Phoenix): 267 differences (interrupted attempt, about 20 variants measured afterwards at 267-270): the jump-table switch is written but the structure and register allocation are far from retail; no variant came close, so this needs a fresh look; needs no @ps2as (L03_0032C3A8.c cannot take it) */
#include "common.h"

/* localdecomp:start func_L03_0032C3A8 */
typedef struct S_0032C3A8 {
    char pad0[0x18];
    f32 f18;
    char pad1[0x20 - 0x1C];
    u8 f20;
    char pad2[0x68 - 0x21];
    struct S_0032C3A8_p *p;
} S_0032C3A8;
typedef struct S_0032C3A8_p {
    char pad0[0x18];
    f32 f18;
    char pad1[0x60 - 0x1C];
    s32 a60[8];
    char pad2[0xCC - 0x80];
    s32 fCC;
    char pad3[0xDC - 0xD0];
    s32 fDC;
    char pad4[0xEC - 0xE0];
    s32 fEC;
    u8 fF0;
    u8 fF1;
    u16 fF2;
    u8 fF4;
    char padF5;
    u8 fF6;
    char padF7;
    s32 fF8;
    char padFC[0x104 - 0xFC];
    s32 f104;
} S_0032C3A8_p;
typedef struct E_0032C3A8 {
    s16 h0;
    char pad2[2];
    struct { u8 b; char pad[3]; } *p4;
    u8 f8;
    char pad[0x28 - 9];
} E_0032C3A8;

extern f32 D_L03_001DF2D0;
__asm__(".extern D_L03_001DF2D0, 16");
extern f32 D_001DF2D0_sda;
__asm__(".extern D_001DF2D0_sda, 4");
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern u8 *D_001DF99C_sda;
__asm__(".extern D_001DF99C_sda, 4");
extern u8 D_001DD10A_sda;
__asm__(".extern D_001DD10A_sda, 1");
extern u8 D_001BBB30;
__asm__(".extern D_001BBB30, 16");
extern E_0032C3A8 D_L03_002AE4D0_0032C3A8[];
typedef struct S_0032C3A8_g {
    char pad0[0x2824];
    f32 f2824;
    char pad1[0x2850 - 0x2828];
    s32 f2850;
} S_0032C3A8_g;
extern S_0032C3A8_g D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern s32 D_00142660[];
__asm__(".extern D_00142660, 16");
extern u8 D_L03_00235A10[];

void func_L03_0032C918();
void func_L03_0032CBD8();
void func_L03_0032CED0();
void func_L03_0032D228();
s32 func_L03_0032D2D8();
void func_L03_0032DF60();
s32 func_L03_0032E6F0();
void func_L03_0032E8D8();
void func_L03_0032E900();
void func_L03_0032EB30();
void func_L03_0032EBF0();
s32 func_L03_0032F038();
void func_L03_0032F520();
void func_L03_003302D0();
void func_L03_00330380();
void func_L03_00330530();
void func_L03_003A1B70();
s32 func_L03_00399D20();
s32 func_0038CB00();
s32 func_0038CAD0();
void func_003A0EC0();
void func_003A4F28();
void func_L01_00404AD8();
void func_L01_004450F0();
void func_L01_004596E8();
s32 func_L01_00436620();
s32 func_L01_004561B8();
void func_L01_004F50C8();

void func_L03_0032C3A8(S_0032C3A8 *a) {
    S_0032C3A8_p *s;
    E_0032C3A8 *e;
    s32 i, ok, z;
    s32 *pp;
    f32 f;

    func_L03_0032C918(a);
    func_L03_0032CBD8(a);
    s = a->p;
    switch (a->f20) {
    case 1:
        break;
    case 2:
        f = D_L03_001DF2D0 - 0.120000005f;
        D_001DF2D0_sda = f;
        if (f <= 0.0f) {
            func_003A0EC0(3, 1, 0x11, 0, 0);
            func_L01_004450F0(a, 3, -1);
        }
        break;
    case 3:
        break;
    case 4:
        if (func_0038CB00(&s->fF2)) {
            func_L03_003302D0(a);
            func_L01_004450F0(a, 5, -1);
        }
        break;
    case 5:
        e = &D_L03_002AE4D0_0032C3A8[s->fF1];
        func_L03_0032E8D8(a, e->p4[s->fF0].b);
        func_L03_0032E900(a);
        if (e->f8 != 0) {
            func_L03_0032EB30(a);
        }
        func_L01_004450F0(a, 6, -1);
        break;
    case 6: {
        pp = s->a60;
        ok = 1;
        z = func_L03_0032F038(a) == 0;
        for (i = 0; i < 8; i++) {
            if (func_L03_00399D20(D_001DF99C_sda + (*pp << 8)) == 0) {
                ok = 0;
                break;
            }
            pp++;
        }
        if (ok == 0) return;
        func_L03_0032D2D8(a);
        if (z == 0) return;
        func_L01_004450F0(a, 7, -1);
        break;
    }
    case 7:
        func_L03_0032DF60(a);
        if (func_L03_0032D2D8(a) != 0) return;
        func_L01_004450F0(a, 8, -1);
        break;
    case 8: {
        E_0032C3A8 *e8 = &D_L03_002AE4D0_0032C3A8[s->fF1];
        s32 i8 = s->fF0;
        if (i8 < e8->h0 - 1) {
            s->fF8 = 0;
            s->fF0 = i8 + 1;
            func_L03_00330380(a);
            func_L01_004450F0(a, 5, -1);
        } else {
            s->fF4 = 1;
            if (func_L03_0032E6F0(a, s->fF1) == 0) goto l700;
            func_L01_004450F0(a, 10, -1);
        }
        break;
    }
    case 9: {
        D_001A4BE0.f2824 = 200.0f;
        func_L01_00404AD8(func_L03_00330530, a);
        if (func_0038CAD0(&s->fEC)) {
            if (s->f104 != -1) {
                func_003A4F28();
                s->f104 = -1;
            }
        }
        if (func_0038CB00(&s->fF2) == 0) return;
        D_001A4BE0.f2850 = D_00142660[2];
        func_L03_0032EBF0(a);
        if (s->fF1 >= 9) {
            s32 op;
            func_L03_0032F520();
            if (D_001DD10A_sda == 0) {
                func_L01_004F50C8(D_L03_00235A10, D_L03_00235A10 + 0x10, 0, 1);
                func_L01_004596E8(0, 0);
                op = 1;
            } else {
                op = 11;
            }
            func_L01_004450F0(a, op, -1);
        } else {
            func_L01_004450F0(a, 11, -1);
        }
        D_001A4BE0.f2850 = D_00142660[2];
        break;
    }
    case 10:
        if (D_001BBB30 != 0) {
            if (func_L01_00436620(0) != 0) return;
l700:
            func_L03_0032D228(a);
            return;
        }
        if (func_L01_004561B8(a) != 0) s->fF6 = 0;
        func_L03_0032F038(a);
        {
            u8 *b = D_L03_001DF99C + (s->fDC << 8);
            f32 g = a->f18;
            if (1.0f < *(f32 *)(b + 0x18) - g) {
                S_0032C3A8_p *t = *(S_0032C3A8_p **)(b + 0x68);
                t->f18 = g * 0.01f + t->f18 * 0.99f;
            }
        }
        break;
    case 11:
        f = D_L03_001DF2D0 + 0.120000005f;
        D_001DF2D0_sda = f;
        if (1.0f <= f) {
            D_L03_001DF2D0 = 1.0f;
            func_L01_004596E8(0, 0);
            func_L03_0032CED0(a);
        }
        break;
    case 12:
        f = D_L03_001DF2D0 + 0.120000005f;
        D_001DF2D0_sda = f;
        if (1.0f <= f) {
            D_L03_001DF2D0 = 1.0f;
            func_L03_003A1B70(D_L03_001DF99C + (s->fCC << 8), 0);
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 13:
        break;
    }
}
/* localdecomp:end func_L03_0032C3A8 */

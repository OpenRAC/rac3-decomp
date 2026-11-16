/* NTSC-U draft (Claude wave K): C of func_L01_0033B940, the NTSC-U twin of func_L01_0033C030, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L01_0033B940", whose code is not the PAL one).
 * Worker's note: first draft (was skip): 103 aligned, 280 vs 289 words, whole function decoded (death handler: flag spilled in the same 0x30(sp) local x later passed as &x to func_L01_00440E98; hAA 0x1F5/0x200 -> tail, 0x1F7 -> save-data hword 0x7048 + hero ...
 */
#include "common.h"

/* NTSC-U counterpart of the L01 object-death handler (src/levels/shared) */
#include "vu0.h"

/* localdecomp:start func_L01_0033B940 */
typedef int u128_0033B940 __attribute__((mode(TI)));
typedef struct V_0033B940 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0033B940;

typedef struct HeroS_0033B940 {
    u8 p0[0x230];
    s32 w230;
    u8 p234[0x28C8 - 0x234];
    u8 b28C8;
} HeroS_0033B940;

typedef struct TS_0033B940 {
    u8 p0[0xF6];
    s16 hF6;
    u8 pF8[3];
    u8 bFB;
    u8 pFC[0x30];
    void *w12C;
} TS_0033B940;

extern s32 D_001DCFF0_sda;
__asm__(".extern D_001DCFF0_sda, 4");
extern u8 D_001A7E18[];
extern HeroS_0033B940 D_001A4BE0;
extern u8 *D_L01_00221118[];
extern u8 D_L01_001D66B0[];
extern u16 D_001A8A9C;

extern s32 func_0037E1D8(s32);
extern void func_L01_004412D0(void *, s32, s32);
extern void func_L01_00417F60(s32, s32);
extern void func_L01_0044EBF8(void *, s32, s32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_0037E2F0(void *, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0046FE70(void *, void *, s32, f32);
extern s32 func_L01_00440E98(void *, void *);
extern void func_L01_0030EF98(void *, s32, s32, s32);

void func_L01_0033B940(u8 *self) {
    TS_0033B940 *t;
    s32 lv;
    s32 k;
    s32 n;
    s32 x;
    s32 sel;
    u8 *sv;
    u8 *p;
    V_0033B940 v0;
    V_0033B940 v1;
    V_0033B940 v2;
    f32 z;
    f32 big;
    f32 six;

    t = *(TS_0033B940 **)(self + 0x68);
    x = t->hF6 == 0;
    if (*(s16 *)(self + 0xAA) == 0x1F5 || *(s16 *)(self + 0xAA) == 0x200 || *(s16 *)(self + 0xAA) == 0x1F7 || *(s16 *)(self + 0xAA) == 0x1FA) {
        x = 0;
    }
    if (x != 0) {
        lv = D_001DCFF0_sda;
        if (lv >= 0x15) {
            k = 0;
        } else {
            k = 2;
            if (lv >= 0xB) {
                k = 1;
            }
        }
        func_L01_004412D0(self, 0x100, func_0037E1D8(2) + k);
        return;
    }
    if (*(s16 *)(self + 0xAA) == 0x1F5 || *(s16 *)(self + 0xAA) == 0x200) {
        goto tail;
    }
    if (*(s16 *)(self + 0xAA) == 0x1F7) {
        sv = D_001A7E18 + 0x8000;
        if (*(u16 *)(sv + 0x7048) == 0) {
            func_L01_00417F60(0x1406, 0x108);
            if (*(u16 *)(sv + 0x7048) == 0) {
                *(u16 *)(sv + 0x7048) = 1;
            }
        }
        z = 0.0f;
        D_001A4BE0.b28C8 = D_001A4BE0.b28C8 + 1;
        big = 157488.0f;
        D_001A4BE0.w230 = D_001A4BE0.w230 + 0x708;
        func_L01_0044EBF8(self, 1, D_001A4BE0.b28C8);
        k = 1;
        six = 6.0f;
        *(u128_0033B940 *)&v0 = *(u128_0033B940 *)(self + 0x10);
        v0.z = v0.z + 0.5f;
        do {
            p = func_L01_00466F98(&v0, D_L01_001D66B0, 0x3C, 6, 0x904020, (s32)func_L01_00440918(1.0f, -1.0f), big * six, 1000.0f, z, z, z);
            if (p != 0) {
                p[2] = D_L01_00221118[0x170 / 4][1];
            }
            k--;
        } while (k >= 0);
        six = 5.0f;
        k = 1;
        do {
            p = func_L01_00466F98(&v0, D_L01_001D66B0, 0x3C, 0x7F, 0x804020, (s32)func_L01_00440918(1.0f, -1.0f), big * six, 1000.0f, z, z, z);
            if (p != 0) {
                p[2] = D_L01_00221118[0x170 / 4][0];
            }
            k--;
        } while (k >= 0);
        n = 0x1D;
        do {
            func_0037E2F0(&v1, 1.5f, 2.0f);
            vec_add_ba(&v1, &v1, &v0);
            vec_sub_ab(&v2, &v0, &v1);
            func_00388830(&v2, &v2, 0.33333334f);
            func_L01_0046FE70(&v1, &v2, 0x2D, 5.0f);
            n--;
        } while (n >= 0);
        goto tail2;
    }
    if (*(s16 *)(self + 0xAA) == 0x1FA) {
        ((u8 *)((TS_0033B940 *)t)->w12C)[0xBC] = 1;
        *(s32 *)((u8 *)t->w12C + 0xB8) = 0;
        if (D_001A8A9C == 0) {
            func_L01_00417F60(0x1409, 0x10B);
        }
        goto tail2;
    }
    switch (t->bFB) {
    case 0: sel = 0x27; break;
    case 1: sel = 0x2F; break;
    case 2: sel = 0x47; break;
    case 3: sel = 0x37; break;
    case 4: sel = 0x6F; break;
    case 5: sel = 0x3F; break;
    case 6: sel = 0x5F; break;
    case 7: sel = 0x11; break;
    case 8: sel = 0x7F; break;
    case 9: sel = 0x77; break;
    case 10: sel = 0x57; break;
    case 11: sel = 0x4F; break;
    case 12: sel = 0x67; break;
    case 13: sel = 0x97; break;
    case 14: sel = 0x13; break;
    case 15: sel = 0x16; break;
    default: sel = -1; break;
    }
    x = sel;
    n = func_L01_00440E98(self, &x);
    if (n > 0) {
        do {
            func_L01_0030EF98(self + 0x10, x, -1, 0);
            n--;
        } while (n != 0);
    }
tail2:
tail:
    if (*(s16 *)(self + 0xB4) != 0) {
        *(s16 *)(self + 0xB4) = 0;
    }
    func_L01_004412D0(self, 0x100, 0);
}
/* localdecomp:end func_L01_0033B940 */

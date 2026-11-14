#include "common.h"

/* localdecomp:start func_L07_00330370 */
typedef struct { u8 b0; u8 b1; u8 b2; u8 b3; s32 w4; s32 w8; } Ent_00330370;
typedef struct { u8 pad0[0xC]; u8 bC; u8 padD[3]; } Row_00330370;
typedef struct {
    u8 pad0[0x90];
    u16 h90[7];
    u8 b9E;
    u8 b9F;
    u8 padA0[4];
    s16 hA4;
    u8 padA6[4];
    u8 bAA;
    u8 bAB;
    s32 wAC;
    u8 padB0[8];
    s32 wB8;
    u16 hBC;
    u8 bBE;
    u8 padBF[0x1D];
    u8 bDC;
    u8 bDD;
    u8 padDE[2];
    u8 padE0[4];
    s32 wE4;
    s32 wE8;
} St_00330370;
typedef struct { u8 pad0[0x68]; St_00330370 *p68; } Obj_00330370;
typedef struct { u8 pad0[0x234]; s32 w234; } G_001A4BE0_00330370;
typedef struct { u16 v; u16 w; } Pair_00330370;

extern u8 D_L07_002B0D40_00330370[];
extern G_001A4BE0_00330370 D_001A4BE0;
extern u8 D_001427F0[];
extern u8 D_001427C3[];
extern u8 D_00142CB6[];
extern Pair_00330370 D_001DCEB8_sda[2];
__asm__(".extern D_001DCEB8_sda, 8");
extern s32 func_L01_005130C8(s32, s32);
extern Ent_00330370 *func_L07_00332D20(s32, s32);
extern void func_L01_0044ECE0(s32, s32, s32);
extern s32 func_L01_005131A0(s32, s32);
extern void func_L01_004C5900(void);
extern s32 func_0037E1D8(s32);
extern void func_L07_003A0BC0(s32, void *, s32, s32);
extern void func_003DF7C0(s32);
extern void func_L07_00332108(void *);
extern void func_L07_00332190(void *);
extern void func_L07_00331198(void *);
extern void func_L07_00331AF0(void *, s32);
extern void func_L07_00334D60(void *);
extern void func_L03_003AD760(s32);
extern u8 func_L07_00333180(s32, s32);
extern void func_L01_0045BE58(s32, s32);

void func_L07_00330370(Obj_00330370 *a) {
    St_00330370 *s = a->p68;
    Ent_00330370 *prev;
    Ent_00330370 *cur;
    s32 n;
    s32 i;
    s32 j;
    u16 *dst;

    if (((Row_00330370 *)((s->b9E << 4) + (s32)D_L07_002B0D40_00330370))->bC != 0 || s->b9F == 0xFF) {
        s->bBE = 0;
        for (i = 0; i < 8; i++) {
            func_L01_005130C8(0x150008 + i, 0x8066CCFF);
        }
        n = 0;
        s->wB8 = 0;
        prev = 0;
        if (s->b9F != 0xFF) {
            prev = func_L07_00332D20(s->b9E, s->b9F);
        }
        s->b9F = s->b9F + 1;
        cur = func_L07_00332D20(s->b9E, s->b9F);
        s->hA4 = -1;
        if (cur->w4 != -1) {
            s->hA4 = cur->w4;
        }
        if (s->hA4 != -1) {
            n = 1;
            func_L01_0044ECE0(0x125E, -1, 0);
            func_L01_005131A0(0x150008, 0xEC5A);
            s->bBE |= 1;
        }
        if (cur->b0 == 0) {
            {
                u8 *q = D_001427F0;
                {
                    u8 *q = D_001427F0;
                    if (*(s32 *)(q + 0x58) != 0) {
                        u8 c = q[0x58];
                        *(s32 *)(q + 0x58) = 0;
                        D_001427C3[0] = c + 1;
                    }
                }
            }
            func_L01_004C5900();
            func_L01_005131A0(n + 0x150008, 0xEC56);
            if (prev == 0 || prev->b0 != 0) {
                s->bBE |= 1 << n;
            }
            n++;
        }
        if (cur->w8 != -1) {
            if (D_00142CB6[0] != 0) {
                {
                    u8 *q = D_001427F0;
                    if (*(s32 *)(q + 0x58) != 0) {
                        u8 c = q[0x58];
                        *(s32 *)(q + 0x58) = 0;
                        D_001427C3[0] = c + 1;
                    }
                }
                func_L01_004C5900();
            }
            func_L01_005131A0(n + 0x150008, 0xEC58);
            if (prev == 0 || prev->w8 != cur->w8) {
                s->bBE |= 1 << n;
            }
            n++;
        }
        if (cur->b2 != 0) {
            func_L01_005131A0(n + 0x150008, 0xEC57);
            if (prev == 0 || prev->b2 == 0) {
                s->bAB = 0;
                s->wAC = 0;
                func_L01_0044ECE0(0x125F, -1, 0);
                s->bBE |= 1 << n;
            }
            n++;
        }
        if (prev != 0 && prev->b2 != 0 && cur->b2 == 0) {
            s->bDD = 4;
            s->bDC = s->bDC + s->bAB;
            func_003DF7C0(0x1E);
        }
        if (cur->b3 != 0) {
            if (prev == 0 || prev->b3 == 0) {
                if (D_001A4BE0.w234 > 2) {
                    D_001A4BE0.w234 = 2;
                }
                func_L07_00332108(a);
                func_L01_0044ECE0(0x1260, -1, 0);
            }
        } else {
            func_L07_00332190(a);
        }
        if (s->bBE != 0) {
            s->hBC = 0xF0;
        }
        if (s->b9F != 0) {
            if (s->bBE != 0) {
                func_L07_003A0BC0(0x3B, a, 0, 0x78);
            } else if (func_0037E1D8(0xF) == 0) {
                func_L07_003A0BC0(0x2A, a, 0, 0x78);
            }
        }
        func_L03_003AD760(n);
    } else {
        s->b9F = s->b9F + 1;
        if (func_0037E1D8(0xF) == 0) {
            func_L07_003A0BC0(0x2A, a, 0, 0x78);
        }
    }
    func_L07_00331198(a);
    s->bAA = func_L07_00333180(s->b9E, s->b9F);
    if (s->bAA != 0) {
        if (D_001A4BE0.w234 > 2) {
            D_001A4BE0.w234 = 2;
        }
        func_L07_00331AF0(a, 1);
        func_L01_0045BE58(s->wE8, -1);
    } else {
        func_L01_0045BE58(s->wE4, -1);
    }
    dst = s->h90;
    for (j = 0; j < 7; j++) {
        dst[j] = D_001DCEB8_sda[j].v;
    }
    func_L07_00334D60(a);
}
/* localdecomp:end func_L07_00330370 */

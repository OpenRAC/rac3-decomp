#include "common.h"

/* NTSC-U counterpart of func_L39_005C2148 (src/levels/shared/L39_005C1F38.c) */
typedef struct { u32 f0; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; u8 fE[2]; } S_005C1F38;
extern void func_0039DA08(s32, long);

/* localdecomp:start func_L39_005C0100 */
typedef struct {
    u32 f0; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; s16 fE; s16 f10; s16 f12;
    s32 f14; s32 f18; s32 f1C; s32 f20; s32 f24;
} Ch_005C2148;
typedef struct {
    u8 p0[4]; s16 h4; u8 b6; u8 b7; s32 w8; u8 pC[4]; s32 w10; s32 w14;
    void (*w18)(s32, s32); s32 w1C; u8 p20[4]; s32 w24; s32 w28; s16 h2C; u8 p2E[2];
    s32 w30; s32 w34; s32 w38; s16 h3C; s16 h3E; u8 p40[4];
    Ch_005C2148 ch[4];
} M_005C2148;
extern M_005C2148 D_L39_002257E0;
__asm__(".extern D_001D59B0_sda_005C0100, 4");
__asm__(".extern D_L39_00240598, 16");
__asm__(".extern D_L39_00241241, 16");
__asm__(".extern D_L39_00241240, 16");
extern u8 D_L39_00240598;
extern u8 D_L39_00241240;
extern u8 D_L39_00241241;
extern u8 D_001D59B0_sda_005C0100;
typedef union { u32 w[2]; u8 b[8]; } B_005C2148;
extern s32 D_001D7D28_sda;
extern s32 D_001D7D2C_sda;
extern f32 D_001D7CF0_sda;
extern f32 D_001D7CF4_sda;
extern u32 D_L39_0024BAC8;
__asm__(".extern D_L39_0024BAC8, 16");
extern void func_L39_005BFA78(s32, s32, s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L39_005BFB70(s32, s32, s32);
extern s32 func_00388398(void *);
extern s32 func_L39_005BFC70(s32, s32, s32, s32);
extern void func_L39_005BF6B8(s32, s32, s32, void *, s32);
extern void func_L39_005BF920(s32, s32, s32);
extern void func_0039DA08(s32, long);
extern void func_00193FF8(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_00193FD8(s32, s32, s32, s32, s32, s32);
extern void func_00194978(s32);
extern s32 func_00194B28(s32);
extern s32 func_L39_005C0958(s32, s32, s32);
extern int func_L39_005F1060(unsigned int, int);
extern void func_L39_005BFEF0(S_005C1F38 *);
/* the hash helpers in the form of func_L39_006D9328's hide_006D9328: reveal reads a hidden word, hide stores one */
static __inline__ u32 reveal_005C2148(u8 *slot, s32 step) {
    B_005C2148 b;
    u8 *q = slot;
    u32 v, t;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*slot == 0) {
        return 0;
    }
    k = ((u32)q - *q) & 7;
    m = *q + 1;
    d = b.b;
    for (i = 0; i < step * 8; i += step) {
        s32 o = ((k + i) & 7) * 4;

        *d++ = (&D_L39_00241240)[m + o];
    }
    b.w[0] ^= (u32)q;
    v = b.w[1] ^ b.w[0];
    t = v >> 16;
    b.w[1] = ~(t | (v ^ t));
    return b.w[1];
}

static __inline__ void hide_005C2148(u8 *slot, u32 v, s32 step) {
    B_005C2148 b;
    u8 *q = slot;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*slot == 0) {
        *slot = D_001D59B0_sda_005C0100 = D_L39_00241240 + 1;
    } else {
        s32 t = *slot;
        *slot = D_L39_00241241;
        D_L39_00241241 = t;
    }
    v = ~v;
    key = ((u32 *)&D_L39_00241240)[((u32)slot * D_L39_0024BAC8) % 8];
    k = ((u32)q - *q) & 7;
    b.w[0] = (u32)q ^ key;
    b.w[1] = ((v & 0xFFFF) | (v << 16)) ^ key;
    m = *q + 1;
    d = b.b;
    for (i = 0; i < step * 8; i += step) {
        s32 o = ((k + i) & 7) * 4;

        (&D_L39_00241240)[m + o] = *d++;
    }
}

void func_L39_005C0100(void) {
    s16 s;
    if (D_L39_002257E0.b7 == 0) {
        if (!(D_L39_002257E0.ch[0].fC & 0x8000) && !(D_L39_002257E0.ch[0].fA & 0x8000)) {
            if (D_L39_002257E0.ch[0].f0 == 0 && (D_L39_002257E0.ch[0].f8 & 1) && D_L39_002257E0.h3C == -1) {
                func_L39_005BFA78(D_L39_002257E0.ch[0].f4, D_L39_002257E0.ch[0].f8, D_L39_002257E0.ch[0].f6);
            } else if ((D_L39_002257E0.ch[0].f0 != 0 && D_L39_002257E0.ch[0].f0 != -1 && D_L39_002257E0.ch[0].fA == 8)
                       || ((D_L39_002257E0.ch[0].f8 & 1) && D_L39_002257E0.ch[0].f18 < 3000 && D_L39_002257E0.ch[0].f14 < 2)) {
                s32 r = func_L39_005B24C8(1, D_001D7D2C_sda - 2);
                func_L39_005BFB70((D_L39_002257E0.ch[0].f4 - D_001D7D28_sda * 2 + r * 2) % (D_001D7D2C_sda * 2) + D_001D7D28_sda * 2,
                                  D_L39_002257E0.ch[0].f8, D_L39_002257E0.ch[0].f6);
            }
        }
        if (func_00388398(&D_L39_002257E0.w38)) {
            if (D_L39_002257E0.h3C != -1 && D_L39_002257E0.h2C == 0) {
                if (D_L39_002257E0.ch[0].f4 != D_L39_002257E0.h3C) {
                  if (D_L39_002257E0.h3E == -1) {
                    if (D_L39_002257E0.ch[0].fA & 0x8000) {
                        D_L39_002257E0.h2C = 3;
                        D_L39_002257E0.ch[0].fA = 5;
                    } else {
                        D_L39_002257E0.w34 = 15;
                        D_L39_002257E0.ch[3].f18 = 15;
                        D_L39_002257E0.h2C = 6;
                    }
                    D_L39_002257E0.w38 = 0x12C;
                } else if (func_L39_005BFC70(D_L39_002257E0.h3C, D_L39_002257E0.h3E, D_L39_002257E0.ch[0].f8, D_L39_002257E0.ch[0].f6)) {
                    D_L39_002257E0.w38 = 0x1A4;
                  }
                } else {
                    D_L39_002257E0.h3C = -1;
                }
            }
        }
        if (D_L39_002257E0.w24 >= 0) {
            if (D_L39_002257E0.ch[2].f0 == 0) {
                func_L39_005BF6B8(D_L39_002257E0.w24, 0, D_L39_002257E0.w28, &D_L39_002257E0.ch[2], 0x400);
                D_L39_002257E0.w28 = 0;
                D_L39_002257E0.w24 = -1;
            } else if (D_L39_002257E0.ch[2].fA != 6 && D_L39_002257E0.ch[2].fA != 7) {
                D_L39_002257E0.ch[2].fA = 5;
            }
        }
        if (D_L39_002257E0.ch[0].fA != 9 && D_L39_002257E0.ch[0].f0 != -1 && !(D_L39_002257E0.ch[0].fC & 0x8000)
            && !(D_L39_002257E0.ch[0].fA & 0x8000)
            && (D_L39_002257E0.h3E == -1 || (!(D_L39_002257E0.ch[3].fC & 0x8000) && !(D_L39_002257E0.ch[3].fA & 0x8000)))) {
            switch (D_L39_002257E0.h2C) {
            case 6: {
                s32 old = D_L39_002257E0.ch[0].f0;
                D_L39_002257E0.ch[0].f0 = -1;
                func_00193FF8(old, 5, D_L39_002257E0.ch[0].f6 * D_L39_002257E0.ch[3].f18 / D_L39_002257E0.w34, 0, 0, 0,
                            func_0039DA08, (long)&D_L39_002257E0.ch[0]);
                if (func_00388398(&D_L39_002257E0.ch[3].f18)) {
                    D_L39_002257E0.h2C = 3;
                    D_L39_002257E0.ch[0].fA = 5;
                }
                break;
            }
            case 2: {
                s32 n = D_L39_002257E0.ch[0].f6 * (D_L39_002257E0.w34 - (D_L39_002257E0.w30 - D_L39_002257E0.ch[3].f18)) / D_L39_002257E0.w34;
                if (!(n > 0 && ((D_L39_002257E0.ch[3].fA == 4 && D_L39_002257E0.ch[3].f10 != 0) || D_L39_002257E0.ch[3].f0 != 0)
                    && D_L39_002257E0.ch[0].f0 != 0)) {
                    D_L39_002257E0.h2C = 3;
                    D_L39_002257E0.ch[0].fA = 5;
                } else if (D_L39_002257E0.ch[0].fA != 9) {
                    s32 old = D_L39_002257E0.ch[0].f0;
                    D_L39_002257E0.ch[0].f0 = -1;
                    func_00193FF8(old, 5, n, 0, 0, 0, func_0039DA08, (long)&D_L39_002257E0.ch[0]);
                }
                break;
            }
            case 3:
                if (D_L39_002257E0.ch[0].fA == 0) {
                    if (D_L39_002257E0.ch[3].f10 != 0 || D_L39_002257E0.ch[3].f0 == 0) {
                        func_L39_005BF920(D_L39_002257E0.h3C, D_L39_002257E0.ch[0].f8, D_L39_002257E0.ch[0].f6);
                        D_L39_002257E0.h3C = -1;
                        D_L39_002257E0.h2C = 4;
                    }
                }
                break;
            case 4:
                if (D_L39_002257E0.ch[0].fA == 3) {
                    if (D_L39_002257E0.ch[3].f18 < D_L39_002257E0.w34 || D_L39_002257E0.ch[3].fA != 4
                        || (D_L39_002257E0.ch[3].f10 == 0 && D_L39_002257E0.ch[3].f0 == 0)) {
                        func_00194978(D_L39_002257E0.ch[0].f0);
                        D_L39_002257E0.ch[0].fA = 8;
                        D_L39_002257E0.h2C = 5;
                    }
                }
                break;
            case 5:
                if (D_L39_002257E0.ch[3].fA != 4 || D_L39_002257E0.ch[3].f10 == 0) D_L39_002257E0.h2C = 0;
                break;
            }
        }
        {
            hide_005C2148(&D_L39_00240598, reveal_005C2148(&D_L39_00240598, 5), 5);
        }
        {
            s32 v;
            Ch_005C2148 *c;
            c = &D_L39_002257E0.ch[0];
            v = (s32)(D_001D7CF0_sda * 1024.0f);
            if (c->fA == 4 && c->f0 != -1)
                func_00193FD8(c->f0, 1, v, 0, 0, 0);
            c = &D_L39_002257E0.ch[1];
            v = (s32)(D_001D7CF4_sda * 1024.0f);
            if (c->fA == 4 && c->f0 != -1 && c->f20 != -1)
                func_L39_005F1060(c->f20, v);
        }
        func_L39_005BFEF0((S_005C1F38 *)&D_L39_002257E0.ch[0]);
        func_L39_005BFEF0((S_005C1F38 *)&D_L39_002257E0.ch[3]);
        func_L39_005BFEF0((S_005C1F38 *)&D_L39_002257E0.ch[1]);
        func_L39_005BFEF0((S_005C1F38 *)&D_L39_002257E0.ch[2]);
        if (D_L39_002257E0.ch[2].fA == 2 && D_L39_002257E0.ch[2].f24 < 0) {
            if ((u16)(D_L39_002257E0.ch[1].fA - 6) >= 2) D_L39_002257E0.ch[1].fA = 5;
            if ((u16)(D_L39_002257E0.ch[2].fA - 6) >= 2) D_L39_002257E0.ch[2].fA = 5;
        } else {
            D_L39_002257E0.ch[2].f24--;
        }
        if (D_L39_002257E0.b6) {
            if (func_00194B28(1)) return;
            D_L39_002257E0.h4 = 0;
            D_L39_002257E0.b6 = 0;
            if (D_L39_002257E0.w18 == 0) return;
            {
                void (*fn)(s32, s32) = D_L39_002257E0.w18;
                s32 a = D_L39_002257E0.w1C;
                D_L39_002257E0.w18 = 0;
                D_L39_002257E0.w1C = 0;
                fn(a, 0);
            }
        } else {
            s = D_L39_002257E0.h4;
            if (s == 2) {
                D_L39_002257E0.h4 = 0;
                func_L39_005C0958(D_L39_002257E0.w14, D_L39_002257E0.w8, D_L39_002257E0.w10);
                if (D_L39_002257E0.h4 == 0) D_L39_002257E0.h4 = s;
            }
        }
    }
}
/* localdecomp:end func_L39_005C0100 */

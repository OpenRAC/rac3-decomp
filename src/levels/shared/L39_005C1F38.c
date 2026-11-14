#include "common.h"

typedef struct { u32 f0; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; u8 fE[2]; } S_005C1F38;

/* localdecomp:start func_L39_005C1F38 */
extern void func_193D98(s32);
extern void func_194858(s32);
extern void func_194888(s32);
extern void func_1948B8(s32, void *, unsigned long);
extern void func_1948E8(s32, void *, unsigned long);
extern void func_193E80(s32, void *, unsigned long);
extern void func_194918(s32, void *, unsigned long);
extern s32 func_0038CB00(void *);
extern void func_003A2AD0(s32, long);
extern void func_003A2AE8(s32, long);
extern void func_003A2A90(s32, long);
extern void func_003A2888(s32, long);
void func_L39_005C1F38(S_005C1F38 *s) {
    s32 h;
    if (s->fA != 9 && s->f0 != 0 && s->f0 != 0xFFFFFFFF) {
        if (s->fA == 5) {
            if (s->f0 == 0) {
                s->fA = 0;
            } else {
                func_193D98(s->f0);
                s->fA = 6;
            }
        } else if (s->fA == 6) {
            if (s->f0 == 0) s->fA = 0;
        }
        if (s->f0 != 0) {
            if (s->fC & 0x8000) {
                if (!(s->fA & 0x8000)) {
                    func_194858(s->f0);
                    s->fA |= 0x8000;
                }
                if (func_0038CB00(s->fE) == 2) s->fC = 4;
            } else if (s->fA & 0x8000) {
                func_194888(s->f0);
                s->fA ^= 0x8000;
            }
            if (!(s->fA & 0x8000)) {
                if (s->fA == 1 || s->fA == 8 || s->fA == 9) {
                } else if (s->fA != 2 && s->fA != 3) {
                    h = s->f0;
                    s->f0 = 0xFFFFFFFF;
                    func_1948B8(h, func_003A2AD0, (u32)s);
                    func_1948E8(h, func_003A2AE8, (u32)s);
                    func_193E80(h, func_003A2A90, (u32)s);
                } else if (s->f0 != 0xFFFFFFFF && s->fA == 2) {
                    func_194918(s->f0, func_003A2888, (u32)s);
                }
            }
        }
    } else if (s->fA == 7 || s->f0 == 0) {
        s->fA = 0;
    }
    if (s->fA == 0) s->f4 = -1;
}
/* localdecomp:end func_L39_005C1F38 */

/* localdecomp:start func_L39_005C2148 */
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
extern M_005C2148 D_L39_00225660;
__asm__(".extern D_001D59B0_sda, 4");
__asm__(".extern D_L39_00240418, 16");
__asm__(".extern D_L39_002410C1, 16");
__asm__(".extern D_L39_002410C0, 16");
extern u8 D_L39_00240418;
extern u8 D_L39_002410C0;
extern u8 D_L39_002410C1;
extern u8 D_001D59B0_sda;
typedef union { u32 w[2]; u8 b[8]; } B_005C2148;
extern s32 D_001D7D68_sda;
extern s32 D_001D7D6C_sda;
extern f32 D_001D7D30_sda;
extern f32 D_001D7D34_sda;
extern u32 D_L39_0024B9C8;
__asm__(".extern D_L39_0024B9C8, 16");
extern void func_L39_005C1AC0(s32, s32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_005C1BB8(s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L39_005C1CB8(s32, s32, s32, s32);
extern void func_L39_005C1700(s32, s32, s32, void *, s32);
extern void func_L39_005C1968(s32, s32, s32);
extern void func_003A2A90(s32, long);
extern void func_00193F08(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_00193EE8(s32, s32, s32, s32, s32, s32);
extern void func_00194888(s32);
extern s32 func_00194A38(s32);
extern s32 func_L39_005C29A0(s32, s32, s32);
extern int func_L39_005F3760(unsigned int, int);
extern void func_L39_005C1F38(S_005C1F38 *);
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

        *d++ = (&D_L39_002410C0)[m + o];
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
        *slot = D_001D59B0_sda = D_L39_002410C0 + 1;
    } else {
        s32 t = *slot;
        *slot = D_L39_002410C1;
        D_L39_002410C1 = t;
    }
    v = ~v;
    key = ((u32 *)&D_L39_002410C0)[((u32)slot * D_L39_0024B9C8) % 8];
    k = ((u32)q - *q) & 7;
    b.w[0] = (u32)q ^ key;
    b.w[1] = ((v & 0xFFFF) | (v << 16)) ^ key;
    m = *q + 1;
    d = b.b;
    for (i = 0; i < step * 8; i += step) {
        s32 o = ((k + i) & 7) * 4;

        (&D_L39_002410C0)[m + o] = *d++;
    }
}

void func_L39_005C2148(void) {
    s16 s;
    if (D_L39_00225660.b7 == 0) {
        if (!(D_L39_00225660.ch[0].fC & 0x8000) && !(D_L39_00225660.ch[0].fA & 0x8000)) {
            if (D_L39_00225660.ch[0].f0 == 0 && (D_L39_00225660.ch[0].f8 & 1) && D_L39_00225660.h3C == -1) {
                func_L39_005C1AC0(D_L39_00225660.ch[0].f4, D_L39_00225660.ch[0].f8, D_L39_00225660.ch[0].f6);
            } else if ((D_L39_00225660.ch[0].f0 != 0 && D_L39_00225660.ch[0].f0 != -1 && D_L39_00225660.ch[0].fA == 8)
                       || ((D_L39_00225660.ch[0].f8 & 1) && D_L39_00225660.ch[0].f18 < 3000 && D_L39_00225660.ch[0].f14 < 2)) {
                s32 r = func_L39_005B43C8(1, D_001D7D6C_sda - 2);
                func_L39_005C1BB8((D_L39_00225660.ch[0].f4 - D_001D7D68_sda * 2 + r * 2) % (D_001D7D6C_sda * 2) + D_001D7D68_sda * 2,
                                  D_L39_00225660.ch[0].f8, D_L39_00225660.ch[0].f6);
            }
        }
        if (func_0038CAD0(&D_L39_00225660.w38)) {
            if (D_L39_00225660.h3C != -1 && D_L39_00225660.h2C == 0) {
                if (D_L39_00225660.ch[0].f4 != D_L39_00225660.h3C) {
                  if (D_L39_00225660.h3E == -1) {
                    if (D_L39_00225660.ch[0].fA & 0x8000) {
                        D_L39_00225660.h2C = 3;
                        D_L39_00225660.ch[0].fA = 5;
                    } else {
                        D_L39_00225660.w34 = 12;
                        D_L39_00225660.ch[3].f18 = 12;
                        D_L39_00225660.h2C = 6;
                    }
                    D_L39_00225660.w38 = 0xFA;
                } else if (func_L39_005C1CB8(D_L39_00225660.h3C, D_L39_00225660.h3E, D_L39_00225660.ch[0].f8, D_L39_00225660.ch[0].f6)) {
                    D_L39_00225660.w38 = 0x15E;
                  }
                } else {
                    D_L39_00225660.h3C = -1;
                }
            }
        }
        if (D_L39_00225660.w24 >= 0) {
            if (D_L39_00225660.ch[2].f0 == 0) {
                func_L39_005C1700(D_L39_00225660.w24, 0, D_L39_00225660.w28, &D_L39_00225660.ch[2], 0x400);
                D_L39_00225660.w28 = 0;
                D_L39_00225660.w24 = -1;
            } else if (D_L39_00225660.ch[2].fA != 6 && D_L39_00225660.ch[2].fA != 7) {
                D_L39_00225660.ch[2].fA = 5;
            }
        }
        if (D_L39_00225660.ch[0].fA != 9 && D_L39_00225660.ch[0].f0 != -1 && !(D_L39_00225660.ch[0].fC & 0x8000)
            && !(D_L39_00225660.ch[0].fA & 0x8000)
            && (D_L39_00225660.h3E == -1 || (!(D_L39_00225660.ch[3].fC & 0x8000) && !(D_L39_00225660.ch[3].fA & 0x8000)))) {
            switch (D_L39_00225660.h2C) {
            case 6: {
                s32 old = D_L39_00225660.ch[0].f0;
                D_L39_00225660.ch[0].f0 = -1;
                func_00193F08(old, 5, D_L39_00225660.ch[0].f6 * D_L39_00225660.ch[3].f18 / D_L39_00225660.w34, 0, 0, 0,
                            func_003A2A90, (long)&D_L39_00225660.ch[0]);
                if (func_0038CAD0(&D_L39_00225660.ch[3].f18)) {
                    D_L39_00225660.h2C = 3;
                    D_L39_00225660.ch[0].fA = 5;
                }
                break;
            }
            case 2: {
                s32 n = D_L39_00225660.ch[0].f6 * (D_L39_00225660.w34 - (D_L39_00225660.w30 - D_L39_00225660.ch[3].f18)) / D_L39_00225660.w34;
                if (!(n > 0 && ((D_L39_00225660.ch[3].fA == 4 && D_L39_00225660.ch[3].f10 != 0) || D_L39_00225660.ch[3].f0 != 0)
                    && D_L39_00225660.ch[0].f0 != 0)) {
                    D_L39_00225660.h2C = 3;
                    D_L39_00225660.ch[0].fA = 5;
                } else if (D_L39_00225660.ch[0].fA != 9) {
                    s32 old = D_L39_00225660.ch[0].f0;
                    D_L39_00225660.ch[0].f0 = -1;
                    func_00193F08(old, 5, n, 0, 0, 0, func_003A2A90, (long)&D_L39_00225660.ch[0]);
                }
                break;
            }
            case 3:
                if (D_L39_00225660.ch[0].fA == 0) {
                    if (D_L39_00225660.ch[3].f10 != 0 || D_L39_00225660.ch[3].f0 == 0) {
                        func_L39_005C1968(D_L39_00225660.h3C, D_L39_00225660.ch[0].f8, D_L39_00225660.ch[0].f6);
                        D_L39_00225660.h3C = -1;
                        D_L39_00225660.h2C = 4;
                    }
                }
                break;
            case 4:
                if (D_L39_00225660.ch[0].fA == 3) {
                    if (D_L39_00225660.ch[3].f18 < D_L39_00225660.w34 || D_L39_00225660.ch[3].fA != 4
                        || (D_L39_00225660.ch[3].f10 == 0 && D_L39_00225660.ch[3].f0 == 0)) {
                        func_00194888(D_L39_00225660.ch[0].f0);
                        D_L39_00225660.ch[0].fA = 8;
                        D_L39_00225660.h2C = 5;
                    }
                }
                break;
            case 5:
                if (D_L39_00225660.ch[3].fA != 4 || D_L39_00225660.ch[3].f10 == 0) D_L39_00225660.h2C = 0;
                break;
            }
        }
        {
            hide_005C2148(&D_L39_00240418, reveal_005C2148(&D_L39_00240418, 5), 5);
        }
        {
            s32 v;
            Ch_005C2148 *c;
            c = &D_L39_00225660.ch[0];
            v = (s32)(D_001D7D30_sda * 1024.0f);
            if (c->fA == 4 && c->f0 != -1)
                func_00193EE8(c->f0, 1, v, 0, 0, 0);
            c = &D_L39_00225660.ch[1];
            v = (s32)(D_001D7D34_sda * 1024.0f);
            if (c->fA == 4 && c->f0 != -1 && c->f20 != -1)
                func_L39_005F3760(c->f20, v);
        }
        func_L39_005C1F38((S_005C1F38 *)&D_L39_00225660.ch[0]);
        func_L39_005C1F38((S_005C1F38 *)&D_L39_00225660.ch[3]);
        func_L39_005C1F38((S_005C1F38 *)&D_L39_00225660.ch[1]);
        func_L39_005C1F38((S_005C1F38 *)&D_L39_00225660.ch[2]);
        if (D_L39_00225660.ch[2].fA == 2 && D_L39_00225660.ch[2].f24 < 0) {
            if ((u16)(D_L39_00225660.ch[1].fA - 6) >= 2) D_L39_00225660.ch[1].fA = 5;
            if ((u16)(D_L39_00225660.ch[2].fA - 6) >= 2) D_L39_00225660.ch[2].fA = 5;
        } else {
            D_L39_00225660.ch[2].f24--;
        }
        if (D_L39_00225660.b6) {
            if (func_00194A38(1)) return;
            D_L39_00225660.h4 = 0;
            D_L39_00225660.b6 = 0;
            if (D_L39_00225660.w18 == 0) return;
            {
                void (*fn)(s32, s32) = D_L39_00225660.w18;
                s32 a = D_L39_00225660.w1C;
                D_L39_00225660.w18 = 0;
                D_L39_00225660.w1C = 0;
                fn(a, 0);
            }
        } else {
            s = D_L39_00225660.h4;
            if (s == 2) {
                D_L39_00225660.h4 = 0;
                func_L39_005C29A0(D_L39_00225660.w14, D_L39_00225660.w8, D_L39_00225660.w10);
                if (D_L39_00225660.h4 == 0) D_L39_00225660.h4 = s;
            }
        }
    }
}
/* localdecomp:end func_L39_005C2148 */

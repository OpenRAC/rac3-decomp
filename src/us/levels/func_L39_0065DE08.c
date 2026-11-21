#include "common.h"

/* NTSC-U counterpart of func_L39_006606E0 (src/levels/shared/L39_0065D0A0.c) */
extern u8 D_L39_004998A0[];
extern u8 D_L39_004998A0[];
extern s32 D_L39_002412AC;

/* localdecomp:start func_L39_0065DE08 */
typedef struct Ent_006606E0 {
    /* 0x00 */ u8 b0;
    /* 0x01 */ u8 pad1[7];
    /* 0x08 */ s32 f8;
    /* 0x0C */ u8 padC[0x11 - 0xC];
    /* 0x11 */ u8 b11;
    /* 0x12 */ u8 pad12[0x18 - 0x12];
    /* 0x18 */ s32 f18;
    /* 0x1C */ s32 f1C;
    /* 0x20 */ s32 f20;
    /* 0x24 */ u8 pad24[0x50 - 0x24];
} Ent_006606E0;

typedef struct Tab_006606E0 {
    /* 0x00 */ u8 pad0[0xB];
    /* 0x0B */ s8 b0B;
    /* 0x0C */ u8 pad0C[0x21 - 0xC];
    /* 0x21 */ s8 b21;
    /* 0x22 */ u8 pad22[0x28 - 0x22];
    /* 0x28 */ f32 f28;
    /* 0x2C */ u8 pad2C[0x80 - 0x2C];
} Tab_006606E0;

typedef struct Self_006606E0 {
    /* 0x000 */ u8 pad0[0x2F0];
    /* 0x2F0 */ s32 s2F0;
    /* 0x2F4 */ u8 pad2F4[0x320 - 0x2F4];
    /* 0x320 */ s16 h320;
    /* 0x322 */ u8 pad322[0x328 - 0x322];
    /* 0x328 */ f32 f328;
    /* 0x32C */ u8 pad32C[0x458 - 0x32C];
    /* 0x458 */ Ent_006606E0 ent[1];
    /* 0x4A8 */ u8 pad4A8[0x628 - 0x4A8];
    /* 0x628 */ f32 f628;
    /* 0x62C */ u8 pad62C[0x14E4 - 0x62C];
    /* 0x14E4 */ s32 s14E4;
    /* 0x14E8 */ u8 pad14E8[0x153C - 0x14E8];
    /* 0x153C */ u8 b153C;
    /* 0x153D */ u8 pad153D[0x19E4 - 0x153D];
    /* 0x19E4 */ u8 b19E4;
    /* 0x19E5 */ u8 pad19E5;
    /* 0x19E6 */ u8 b19E6;
    /* 0x19E7 */ u8 pad19E7[0x1A07 - 0x19E7];
    /* 0x1A07 */ u8 b1A07;
    /* 0x1A08 */ unsigned long q1A08;
    /* 0x1A10 */ u8 pad1A10[0x1A40 - 0x1A10];
    /* 0x1A40 */ u8 b1A40;
    /* 0x1A41 */ u8 pad1A41;
    /* 0x1A42 */ u8 b1A42[1];
    /* 0x1A43 */ u8 pad1A43[0x2488 - 0x1A43];
    /* 0x2488 */ s16 h2488;
    /* 0x248A */ u8 pad248A[0x2534 - 0x248A];
    /* 0x2534 */ void *p2534;
} Self_006606E0;

typedef union Buf_006606E0 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_006606E0;

extern u8 D_L39_004998A0[];

static inline u32 Dec_006606E0(u8 *q) {
    Buf_006606E0 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static inline s32 DecEq_006606E0(u8 *q, s32 v) {
    return Dec_006606E0(q) == v;
}

__asm__(".extern D_L39_002412AC, 16");
extern s32 D_L39_002412AC;
extern u32 D_L39_0024BAC8;
extern u8 D_L39_0049AB80[];
extern u8 D_L39_0049AB81[];
extern Tab_006606E0 D_L39_0049C950[];

extern s32 func_L39_005C0F08(void *);
extern s32 func_L39_0061E558(void *, s32);
extern s32 func_L39_0061E688(void *, s32, s32);
extern s32 func_L39_00646268(u8 *, s32);
extern void func_L39_00670488(void *, s32, s32, s32, s32, s32);

static inline Self_006606E0 *Slot_006606E0(Self_006606E0 *s, s32 i) {
    return (Self_006606E0 *)((u8 *)s + i * 0x50);
}

static inline Tab_006606E0 *TabGet_006606E0(Self_006606E0 *s, s32 mode) {
    Tab_006606E0 *e;
    if (func_L39_00646268((u8 *)s, mode)) {
        e = &D_L39_0049C950[((Tab_006606E0 *)((u8 *)D_L39_0049C950 + (mode << 7)))->b21];
    } else {
        e = (Tab_006606E0 *)((u8 *)D_L39_0049C950 + (mode << 7));
    }
    return e;
}

static inline void Prep_006606E0(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_0049AB80[0];
    } else {
        t = *q;
        *q = D_L39_0049AB81[0];
        D_L39_0049AB81[0] = t;
    }
}

static inline void SetW_006606E0(u8 *q, s32 v) {
    u8 *hk = q;
    Buf_006606E0 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_006606E0(q);
    key = ((u32 *)D_L39_0049AB80)[((u32)hk * D_L39_0024BAC8) % 0x182];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = v ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_0049AB80[m + ((k + i) & 7) * 0xC1] = *d++;
    }
}

void func_L39_0065DE08(Self_006606E0 *s, s32 i) {
    s32 mode = Slot_006606E0(s, i)->ent[0].f20;
    s32 ok;
    s32 f;
    Tab_006606E0 *t;
    Self_006606E0 *e;

    if (i == 0) {
        if (mode != 10 && s->h320 == 0 && s->ent[0].f18 >= 5) {
            ok = 0;
            f = 0;
            if ((s->q1A08 & 0xFFFFFF00000000UL) != 0 ||
                DecEq_006606E0(&s->b19E6, 0x14) || DecEq_006606E0(&s->b19E4, 0x66) ||
                DecEq_006606E0(&s->b19E4, 0x64) || s->h2488 != 0) {
                f = 1;
            }
            if (f == 0 && (func_L39_005C0F08(s->p2534) & (e = Slot_006606E0(s, i))->ent[0].f8) != 0) {
                ok = 1;
                if (func_L39_0061E558(s, mode)) {
                    if (e->ent[0].b0 == 0) {
                        e->ent[0].b0 = 1;
                        func_L39_00670488(&s->b1A40, 1, -1, -1, 0, 0);
                    }
                } else if (e->ent[0].b0 == 1) {
                    e->ent[0].b0 = 0;
                    func_L39_00670488(&s->b1A40, 2, -1, -1, 0, 0);
                }
            } else if (Slot_006606E0(s, i)->ent[0].b0 == 1) {
                Slot_006606E0(s, i)->ent[0].b0 = 0;
                func_L39_00670488(&s->b1A40, 2, -1, -1, 0, 0);
            }
            if (f != 0) {
                return;
            }
            if (DecEq_006606E0(&s->b19E4, 0x1D) && s->s2F0 < 0x14) {
                return;
            }
            if (Slot_006606E0(s, i)->ent[0].f18 < 0x17) {
                return;
            }
            if (s->f328 != 0.0f) {
                return;
            }
            if (DecEq_006606E0(&s->b19E4, 0xE) && 25.0f < s->f628 && s->f628 < 35.0f) {
                return;
            }
            if (DecEq_006606E0(&s->b19E4, 0xB) && s->s14E4 == 3 && 10.0f < s->f628 &&
                s->f628 < 20.0f) {
                return;
            }
            if (ok == 0) {
                return;
            }
            t = TabGet_006606E0(s, mode);
            if (t->b0B != 0 ||
                ((DecEq_006606E0(&s->b19E6, 0) || DecEq_006606E0(&s->b19E6, 1) ||
                  DecEq_006606E0(&s->b19E6, 0xC) || DecEq_006606E0(&s->b19E6, 5) ||
                  DecEq_006606E0(&s->b19E6, 0xF) ||
                  (DecEq_006606E0(&s->b19E6, 4) && s->b153C != 0)) &&
                 s->b1A07 == 0) ||
                (DecEq_006606E0(&s->b19E4, 0x22) && 20.0f < s->f628)) {
                t = TabGet_006606E0(s, mode);
                if ((t->b0B == 0 && func_L39_0061E558(s, -1)) || func_L39_0061E688(s, -1, 1)) {
                    func_L39_00670488(&s->b1A40, 8, -1, -1, 0, 0);
                    t = TabGet_006606E0(s, mode);
                    if (t->b0B == 0) {
                        s->ent[0].b11 = 0x14;
                    }
                } else {
                    func_L39_00670488(&s->b1A40, 4, -1, -1, 0, 0);
                }
                t = TabGet_006606E0(s, mode);
                s->f328 = 1.0f / t->f28;
                SetW_006606E0(&s->b1A42[mode], D_L39_002412AC);
            }
        }
    }
}
/* localdecomp:end func_L39_0065DE08 */

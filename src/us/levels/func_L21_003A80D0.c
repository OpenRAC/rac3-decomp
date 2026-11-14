#include "common.h"

/* localdecomp:start func_L21_003A80D0 */
typedef struct S_003A80D0 {
    u8 pad00[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0xD0 - 0x36];
    u8 bD0[0x11];
    u8 bE1;
    u8 bE2;
    u8 padE3[0x280 - 0xE3];
    u8 b280[0x84];
    s16 h304;
    u8 pad306[8];
    s16 h30E;
} S_003A80D0;

typedef struct T_003A80D0 {
    u8 pad00[0x20];
    s32 w20;
    u8 pad24[8];
    f32 f2C;
} T_003A80D0;

extern u8 D_001426E0[];
extern u8 D_L21_001E1780[];
extern u8 D_L21_001DCF70;
extern f32 D_L21_001DCF80;

extern void func_00399F90(void);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern T_003A80D0 *func_L01_00444358(void *, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern s32 func_003883C8(void *);
extern void func_L01_004538E0(void *, s32);
extern void func_L01_004539A8(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_0044EB78(void *, void *, s32, s32, f32);

void func_L21_003A80D0(u8 *o) {
    S_003A80D0 *s;
    T_003A80D0 *t;
    s32 i;
    f32 d;
    f32 k;

    s = *(S_003A80D0 **)(o + 0x68);
    if ((*(unsigned long *)(o + 0x90) & 0xFFFF00FF00000000UL) == 0) {
        for (i = 0; i < 7; i++) {
            if ((u32)i < 8 && ((D_001426E0[0xD5] >> i) & 1)) {
                u32 j;
                D_001426E0[0xD5] &= ~(1 << i);
                func_00399F90();
                j = i + 1;
                if (j < 8) {
                    D_001426E0[0xD5] |= 1 << j;
                }
                func_00399F90();
                break;
            }
        }
    }
    if (o[0x31] != 0) {
        if (func_L01_0040C018(D_L21_001E1780, o + 0x10) < 1024.0f) {
            func_L01_00444188(o);
            o[0x6F] = 0x1E;
        }
    }
    t = func_L01_00444358(o, -1, 0);
    if (t != 0) {
        f32 f3 = s->f30;
        f32 diff = f3 - t->f2C;
        f32 scaled = (f32)(s->h34 * s->h304) * 0.01f;
        if (diff < scaled) {
            t->f2C = (f3 - scaled) + 1.0f;
        }
    }
    if (o[0x20] == 0xD && t != 0) {
        if (func_0037E1D8(4) == 0) {
            o[0xA8] = 0xFF;
            func_L01_00441FB8(o, func_0037E208(14, 15), -1);
        }
    }
    if (o[0x20] != 0x17) {
        if (s->h30E != 0) {
            s->bE1 = 0xFF;
            s->bE2 = 0xFF;
        } else {
            s->bE1 = 0x15;
            s->bE2 = 0x17;
        }
    }
    if (s->f30 <= 0.0f) {
        s->bE1 = 0x15;
        s->bE2 = 0x17;
    }
    if (o[0x20] != 0x17 || s->f30 <= 0.0f) {
        func_L01_0044FCD0(o, s->bD0, 0, 0, 0);
    }
    if (t != 0 && t->w20 != 0 && s->h30E == 0) {
        s->h30E = 0x5A;
    } else {
        func_003883C8(&s->h30E);
    }
    if ((*(unsigned long *)(o + 0x30) & 0x104100000000UL) == 0x4100000000UL && *(s32 *)(o + 0x98) == 0) {
    } else {
        if (0.0f < s->f30) {
            func_L01_004538E0(o, 3);
        }
    }
    func_L01_004539A8(o, -1, &D_L21_001DCF70, 0, 0, 0, 2, 0, 0, 0, D_L21_001DCF80, 10.0f, 1.0f);
    if (*(u16 *)(o + 0x96) <= 0xFFFE) {
        *(u16 *)(o + 0x96) += 1;
    }
    func_L01_0044EB78(o, s->b280, 5, 1, 2.5f);
}
/* localdecomp:end func_L21_003A80D0 */

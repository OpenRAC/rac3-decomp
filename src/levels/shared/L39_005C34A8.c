#include "common.h"

/* localdecomp:start func_L39_005C34A8 */
typedef struct {
    u8 pad0[0x100];
    f32 a[16];       /* 0x100 */
    f32 b[16];       /* 0x140 */
    u8 pad180[0x18E - 0x180];
    s16 head;        /* 0x18E */
    s32 cnt;         /* 0x190 */
    u8 pad194[0x1A0 - 0x194];
    s32 f1A0, f1A4, f1A8, f1AC, f1B0, f1B4, f1B8, f1BC, f1C0, f1C4, f1C8, f1CC, f1D0, f1D4, f1D8;
    u8 pad1DC[4];
    s32 hist[30];    /* 0x1E0 */
    f32 hy[30];      /* 0x258 */
    f32 hx[30];      /* 0x2D0 */
    s32 f348;
    s32 idx;         /* 0x34C */
    s32 n;           /* 0x350 */
    s32 arr[7];      /* 0x354 */
    s32 arr2[7];     /* 0x370 */
    f32 g[7][16];    /* 0x38C */
    u8 pad54C;
    u8 b54D, b54E, b54F;
    u8 pad550[0x568 - 0x550];
    s32 f568;
} S_005C34A8;

extern u8 D_L39_002412F7 __attribute__((section(".data")));
extern s32 D_L39_00241128;
extern s32 D_L39_00242A00;
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);

void func_L39_005C34A8(u8 *a0, u8 *a1, s32 n) {
    S_005C34A8 *s = (S_005C34A8 *)a0;
    s32 w;
    s32 w2;
    s32 m;
    s32 i, j, k;
    f32 v[2];
    f32 mag;
    f32 ang;

    s->arr[s->idx] = ((a1[2] << 8) | a1[3]) ^ 0xFFFF;
    s->arr2[s->idx] = s->arr[s->idx];
    for (i = 0; i < 16; i++) {
        s->g[s->idx][i] = 0.0f;
    }
    if (n >= 8) {
        for (i = 0; i < 4; i++) {
            s32 t = a1[4 + i] - 0x7F;
            if (t < 0) {
                t = -t;
            }
            if (t >= 0x30) {
                s->g[s->idx][i] = (f32)(t - 0x30) / 76.0f;
                if (1.0f < s->g[s->idx][i]) {
                    s->g[s->idx][i] = 1.0f;
                }
                if (a1[4 + i] < 0x7F) {
                    s->g[s->idx][i] = -s->g[s->idx][i];
                }
            }
        }
    }
    if (n >= 20) {
        for (i = 4; i < 16; i++) {
            s->g[s->idx][i] = (f32)a1[4 + i] * 0.003921569f;
        }
    }
    if (D_L39_002412F7 != 0) {
        s->g[s->idx][2] = -s->g[s->idx][2];
        s->g[s->idx][0] = -s->g[s->idx][0];
        if (s->arr[s->idx] & 0x8000) {
            s->arr[s->idx] = s->arr[s->idx] & ~0x8000;
            s->arr[s->idx] |= 0x2000;
        } else if (s->arr[s->idx] & 0x2000) {
            s->arr[s->idx] = s->arr[s->idx] & ~0x2000;
            s->arr[s->idx] |= 0x8000;
        }
        s->arr2[s->idx] = s->arr[s->idx];
    }
    if (D_L39_00241128 == 7) {
        if (s->g[s->idx][2] < 0.0f) {
            s->arr[s->idx] |= 0x8000;
        }
        if (s->g[s->idx][2] > 0.0f) {
            s->arr[s->idx] |= 0x2000;
        }
        if (s->g[s->idx][3] < 0.0f) {
            s->arr[s->idx] |= 0x1000;
        }
        if (s->g[s->idx][3] > 0.0f) {
            s->arr[s->idx] |= 0x4000;
        }
    }
    if (s->n >= s->f568) {
        s->f1A0 = s->arr[(s->idx - s->f568 + 7) % 7];
        s->f1B0 = s->arr2[(s->idx - s->f568 + 7) % 7];
        for (i = 0; i < 16; i++) {
            s->a[i] = s->g[(s->idx - s->f568 + 7) % 7][i];
        }
    } else {
        s->f1A0 = s->f1AC;
        s->f1B0 = s->f1BC;
    }
    s->idx = (s->idx + 1) % 7;
    s->n++;
    if (s->f568 < s->n) {
        s->n = s->f568;
    }
    for (i = 0; i < 16; i++) {
        s->b[i] = s->a[i];
    }
    if (s->a[2] != 0.0f || s->a[3] != 0.0f) {
        s->f1D8 = 1;
    } else {
        s->f1D8 = 0;
    }
    if (s->a[2] < 0.0f) {
        s->f1A0 |= 0x8000;
    }
    if (s->a[2] > 0.0f) {
        s->f1A0 |= 0x2000;
    }
    if (s->a[3] < 0.0f) {
        s->f1A0 |= 0x1000;
    }
    if (s->a[3] > 0.0f) {
        s->f1A0 |= 0x4000;
    }
    w = s->f1A0;
    s->f1D4 = (w & 0xF000) == 0;
    s->f1D0 = w == 0;
    s->f1A4 = ~s->f1AC & w;
    s->f1A8 = ~w & s->f1AC;
    s->f1B4 = ~s->f1AC & s->f1B0;
    s->f1B8 = ~w & s->f1BC;
    s->f1C4 = s->f1A4;
    s->f1C8 = s->f1A8;
    s->f1C0 = w;
    s->f348 = w;
    if (D_L39_002412F7 != 0) {
        s->b[2] = -s->b[2];
        s->b[0] = -s->b[0];
        if (s->f1C0 & 0x8000) {
            s->f1C0 = (s->f1C0 & ~0x8000) | 0x2000;
        } else if (s->f1C0 & 0x2000) {
            s->f1C0 = (s->f1C0 & ~0x2000) | 0x8000;
        }
        if (s->f1C4 & 0x8000) {
            s->f1C4 = (s->f1C4 & ~0x8000) | 0x2000;
        } else if (s->f1C4 & 0x2000) {
            s->f1C4 = (s->f1C4 & ~0x2000) | 0x8000;
        }
        if (s->f1C8 & 0x8000) {
            s->f1C8 = (s->f1C8 & ~0x8000) | 0x2000;
        } else if (s->f1C8 & 0x2000) {
            s->f1C8 = (s->f1C8 & ~0x2000) | 0x8000;
        }
    }
    if (s->f1CC == 1) {
        s->f1A0 &= ~0x5030;
        s->f1A4 &= ~0x5030;
        s->f1A8 &= ~0x5030;
        s->a[0] = 0.0f;
        s->a[1] = 0.0f;
        if (D_L39_00242A00 != 0) {
            s->f1CC = 0;
        }
    }
    if (s->f1CC == 2) {
        s->f1A0 &= 0x900;
        s->f1A4 &= 0x900;
        s->f1A8 &= 0x900;
        s->f1B0 &= 0x900;
        s->f1D4 = 1;
        s->a[2] = 0.0f;
        s->a[3] = 0.0f;
        if (D_L39_00242A00 != 0) {
            s->f1CC = 0;
        }
    }
    v[0] = s->a[2];
    v[1] = s->a[3];
    mag = func_0038CED8(v);
    ang = func_0038D160(v[0], v[1]);
    s->hx[s->head] = mag;
    s->hy[s->head] = ang;
    if (0.9f < mag) {
        for (j = 1; j < 3; j++) {
            m = (s->head + 30 - j) % 30;
            if (0.9f < s->hx[m]) {
                break;
            }
            if (s->hx[m] < 0.25f) {
                s->f1A4 |= 0x10000;
                break;
            }
        }
        if (!(s->f1A4 & 0x10000)) {
            for (k = 1; k < 4; k++) {
                if (0.9599311f < func_0038DBA0(s->hy[(s->head - k + 30) % 30], ang)) {
                    s->f1A4 |= 0x10000;
                    break;
                }
            }
        }
    }
    if (D_L39_00241128 != -1) {
        s->hist[s->head] = s->f1A4;
        s->head = (s->head + 1) % 30;
        s->cnt++;
        if (s->cnt >= 31) {
            s->cnt = 30;
        }
    }
    if (s->b54E != 0) {
        w2 = s->f1A0;
        if (w2 != 0 && w2 == s->f1AC) {
            s->b54F--;
            if (s->b54F == 0 || s->b54F == 0xFF) {
                s->b54F = s->b54E;
                s->f1A4 = w2;
            }
        } else {
            s->b54F = s->b54D;
        }
    }
}
/* localdecomp:end func_L39_005C34A8 */

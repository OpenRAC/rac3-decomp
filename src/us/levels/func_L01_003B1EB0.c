#include "common.h"

/* NTSC-U counterpart of func_L01_003B36A8 (src/levels/shared/L01_003B36A8.c): 50 -> 60 */
extern u8 *D_L01_001E009C;
extern s32 func_L01_003B1EB0(u8 *, u8 *);
extern s32 D_L01_001DE674_003B1EB0;
extern s32 func_L01_003B4340(u8 *);

/* localdecomp:start func_L01_003B1EB0 */
typedef struct {
    s32 w0; s32 w4; u8 *w8; s32 wC; u8 pad10[0x24]; s32 w34; s32 w38; s32 w3C; s32 w40; s32 w44;
    s32 w48; s32 w4C; s32 w50; s32 w54; f32 f58; s32 w5C; f32 f60; s32 w64; s32 w68;
} S_003B36A8;
extern s32 D_L01_001DFBC0_003B1EB0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E00D8;
extern u16 *D_L01_0021DEA0[];
extern u8 *D_L01_001E009C_003B1EB0[] __attribute__((section(".sdata")));
extern u8 D_001A4C60[];
__asm__(".extern D_L01_001DE674_003B1EB0, 4");
extern s32 func_L01_003B4388_003B1EB0(u8 *, s32);
extern f32 func_L01_003B4480(u8 *, s32, s32, f32 *, f32 *);
extern s32 func_L01_003B46F0_003B1EB0(u8 *, s32);
extern s32 func_L01_003B4700(u8 *);
extern s32 func_L01_003B4730_003B1EB0(u8 *, s32);
extern f32 func_L01_003B4760_003B1EB0(u8 *, s32);
extern s32 func_L01_003B47C8_003B1EB0(u8 *, s32);
extern s32 func_L01_00326E30(void);
extern s32 func_L01_00453210(void *, s32);
extern s32 func_L01_00452F60(u8 *);
extern s32 func_L01_00442998(s32, s32, s32);

s32 func_L01_003B1EB0(u8 *a0, u8 *a1) {
    S_003B36A8 *st = (S_003B36A8 *)a1;
    u8 *vars = *(u8 **)(st->w8 + 0x68);
    u8 *m;
    u8 *v;
    u8 *first;
    u16 *p;
    s32 n, sum1, sum2;
    f32 sum, total, damage;
    f32 out[2];

    if (st->w34 && D_L01_001DFBC0_003B1EB0[0] - st->w4 < st->w34 * 60) return 0;
    if (st->w38 && D_L01_001DFBC0_003B1EB0[0] - *(s32 *)(vars + 0x60) < st->w38 * 60) return 0;
    if (st->w40) {
        for (p = D_L01_0021DEA0[st->wC];
             (st->wC & 0xFF) != 0xFF && st->wC <= D_L01_001E00D8 && p != 0 &&
             ((s16)p[-1] >= 0 || p == D_L01_0021DEA0[st->wC]);
             p++) {
            m = D_L01_001E009C_003B1EB0[0] + ((*p & 0x7FFF) << 8);
            if (m == 0) break;
            if (func_L01_003B4340(m) && !func_L01_003B4388_003B1EB0(m, 0)) return 0;
        }
    }
    if (st->w44) {
        for (p = D_L01_0021DEA0[st->wC];
             (st->wC & 0xFF) != 0xFF && st->wC <= D_L01_001E00D8 && p != 0 &&
             ((s16)p[-1] >= 0 || p == D_L01_0021DEA0[st->wC]);
             p++) {
            m = D_L01_001E009C_003B1EB0[0] + ((*p & 0x7FFF) << 8);
            if (m == 0) break;
            if (func_L01_003B4700(m) && !func_L01_003B4730_003B1EB0(m, 0)) return 0;
        }
    }
    first = (u8 *)D_L01_001DE674_003B1EB0;
    if (first) {
        m = first;
        sum = 0.0f;
        sum1 = 0;
        sum2 = 0;
        n = 0;
        total = 0.0f;
        damage = 0.0f;
        do {
            v = *(u8 **)(m + 0x68);
            if (func_L01_003B4340(m)) {
                if (st->f58 >= 0.0f) {
                    if (func_L01_003B4480(m, 0, 1, &out[0], &out[1]) >= 0.0f) {
                        sum += out[0];
                        total += out[1];
                    }
                } else if (st->w5C >= 0) {
                    sum1 += func_L01_003B46F0_003B1EB0(m, 0);
                } else if (!func_L01_003B4388_003B1EB0(m, 0)) {
                    return 0;
                }
            } else if (func_L01_003B4700(m)) {
                if (st->f60 >= 0.0f) {
                    damage += func_L01_003B4760_003B1EB0(m, 0);
                    n++;
                } else if (st->w64 < 0) {
                    if (!func_L01_003B4730_003B1EB0(m, 0)) return 0;
                } else {
                    sum2 += func_L01_003B47C8_003B1EB0(m, 0);
                    n++;
                }
            }
            m = *(u8 **)(v + 0x58);
        } while (m);
        if (st->f58 >= 0.0f) {
            f32 ratio = 0.0f;
            if (total > 0.0f) ratio = sum / total;
            if (ratio < st->f58) return 0;
        } else if (st->w5C >= 0 && sum1 < st->w5C) {
            return 0;
        }
        if (st->f60 >= 0.0f) {
            if (n > 1) damage /= (f32)n;
            if (damage < st->f60) return 0;
        } else if (st->w64 >= 0 && sum2 < st->w64) {
            return 0;
        }
    }
    if (st->w68 && func_L01_00326E30()) return 0;
    if (st->w3C != -1 && !func_L01_00453210(D_001A4C60, st->w3C)) return 0;
    if (st->w48 != -1 && !func_L01_00452F60(D_L01_001E009C + (st->w48 << 8))) return 0;
    if (st->w4C != -1) {
        u16 *q;
        for (q = D_L01_0021DEA0[st->w4C];
             (st->w4C & 0xFF) != 0xFF && st->w4C <= D_L01_001E00D8 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L01_0021DEA0[st->w4C]);
             q++) {
            u8 *e = D_L01_001E009C_003B1EB0[0] + ((*q & 0x7FFF) << 8);
            if (e == 0) break;
            if (!func_L01_00452F60(e)) return 0;
        }
    }
    if (st->w50 != -1) {
        u8 *e = D_L01_001E009C + (st->w50 << 8);
        if (e && e[0x20] != 0xFE && e[0x20] != 0xFD) return 0;
    }
    if (st->w54 != -1 && func_L01_00442998(st->w54, -1, 0)) return 0;
    return 1;
}
/* localdecomp:end func_L01_003B1EB0 */

/* NTSC-U draft (Codex wave 3): C of func_L01_003B1EB0, the NTSC-U twin of func_L01_003B36A8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 274 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003B1EB0", whose code is not the PAL one).
 * Worker's note: 274 diff; best log w148/func_L01_003B1EB0.02.log; iterator loop rotation and table address materialization remain; scoped iterators and byte-table/typed-table/goto variants not closer (three variants same 307 diff); 9 compiles; divs_table 2 0 tested in .08 ...
 */
#include "common.h"

/* localdecomp:start func_L01_003B1EB0 */
extern s32 D_L01_001DFBC0[];
extern u8 *D_L01_001E009C;
extern u8 *D_L01_001E009C_003B1EB0[];
extern s32 D_L01_001E00D8;
extern s16 *D_L01_0021DEA0[];
extern u8 *D_L01_001DE674;
extern u8 D_001A4C60[];
extern s32 func_L01_003B4340(u8 *);
extern s32 func_L01_003B4388(u8 *, s32);
extern s32 func_L01_003B4700(u8 *);
extern s32 func_L01_003B4730(u8 *, s32);
extern f32 func_L01_003B4480(u8 *, s32, s32, f32 *, f32 *);
extern s32 func_L01_003B46F0(u8 *, s32);
extern f32 func_L01_003B4760(u8 *, s32);
extern s32 func_L01_003B47C8(u8 *, s32);
extern s32 func_L01_00326E30(void);
extern s32 func_L01_00453210(u8 *, s32);
extern s32 func_L01_00452F60(u8 *);
extern s32 func_L01_00442998(s32, s32, s32);

typedef struct { s32 w0; s32 w4; u8 *w8; s32 wC; s32 w10; s32 w14; s32 w18; s32 w1C; s32 w20; s32 w24; s32 w28; s32 w2C; s32 w30; s32 w34; s32 w38; s32 w3C; s32 w40; s32 w44; s32 w48; s32 w4C; s32 w50; s32 w54; f32 w58; s32 w5C; f32 w60; s32 w64; s32 w68; } State_3B1EB0;
s32 func_L01_003B1EB0(u8 *owner, State_3B1EB0 *st) {
    u8 *vars = *(u8 **)(st->w8 + 0x68);
    u8 *m;
    u8 *v;
    s16 *iter;
    s32 i, n, sum1, sum2;
    f32 sum, total, damage;
    f32 out1, out2;
    if (st->w34 && D_L01_001DFBC0[0] - st->w4 < st->w34 * 60) return 0;
    if (st->w38 && D_L01_001DFBC0[0] - *(s32 *)(vars + 0x60) < st->w38 * 60) return 0;
    if (st->w40) {
        i = st->wC;
        iter = D_L01_0021DEA0[i];
        while ((i & 255) != 255 && D_L01_001E00D8 >= i && iter && (iter[-1] >= 0 || iter == D_L01_0021DEA0[i])) {
            m = D_L01_001E009C_003B1EB0[0] + ((*iter & 0x7FFF) << 8);
            if (!m) break;
            if (func_L01_003B4340(m) && !func_L01_003B4388(m, 0)) return 0;
            iter++;
            i = st->wC;
        }
    }
    if (st->w44) {
        i = st->wC;
        iter = D_L01_0021DEA0[i];
        while ((i & 255) != 255 && D_L01_001E00D8 >= i && iter && (iter[-1] >= 0 || iter == D_L01_0021DEA0[i])) {
            m = D_L01_001E009C_003B1EB0[0] + ((*iter & 0x7FFF) << 8);
            if (!m) break;
            if (func_L01_003B4700(m) && !func_L01_003B4730(m, 0)) return 0;
            iter++;
            i = st->wC;
        }
    }
    m = D_L01_001DE674;
    if (m) {
        sum = 0.0f;
        sum1 = 0;
        sum2 = 0;
        n = 0;
        total = 0.0f;
        damage = 0.0f;
        do {
            v = *(u8 **)(m + 0x68);
            if (func_L01_003B4340(m)) {
                if (st->w58 >= 0.0f) {
                    if (func_L01_003B4480(m, 0, 1, &out1, &out2) >= 0.0f) {
                        sum += out1;
                        total += out2;
                    }
                } else if (st->w5C >= 0) {
                    sum1 += func_L01_003B46F0(m, 0);
                } else if (!func_L01_003B4388(m, 0)) return 0;
            } else if (func_L01_003B4700(m)) {
                if (st->w60 >= 0.0f) {
                    damage += func_L01_003B4760(m, 0);
                    n++;
                } else if (st->w64 < 0) {
                    if (!func_L01_003B4730(m, 0)) return 0;
                } else {
                    sum2 += func_L01_003B47C8(m, 0);
                    n++;
                }
            }
            m = *(u8 **)(v + 0x58);
        } while (m);
        if (st->w58 >= 0.0f) {
            f32 ratio = 0.0f;
            if (total > 0.0f) ratio = sum / total;
            if (ratio < st->w58) return 0;
        } else if (st->w5C >= 0 && sum1 < st->w5C) return 0;
        if (st->w60 >= 0.0f) {
            if (n > 1) damage /= (f32)n;
            if (damage < st->w60) return 0;
        } else if (st->w64 >= 0 && sum2 < st->w64) return 0;
    }
    if (st->w68 && func_L01_00326E30()) return 0;
    if (st->w3C != -1 && !func_L01_00453210(D_001A4C60, st->w3C)) return 0;
    if (st->w48 != -1 && !func_L01_00452F60(D_L01_001E009C + (st->w48 << 8))) return 0;
    i = st->w4C;
    if (i != -1) {
        iter = D_L01_0021DEA0[i];
        while ((i & 255) != 255 && D_L01_001E00D8 >= i && iter && (iter[-1] >= 0 || iter == D_L01_0021DEA0[i])) {
            m = D_L01_001E009C_003B1EB0[0] + ((*iter & 0x7FFF) << 8);
            if (!m) break;
            if (!func_L01_00452F60(m)) return 0;
            iter++;
            i = st->w4C;
        }
    }
    i = st->w50;
    if (i != -1) {
        m = D_L01_001E009C + (i << 8);
        if (m && m[0x20] != 254 && m[0x20] != 253) return 0;
    }
    i = st->w54;
    if (i != -1 && func_L01_00442998(i, -1, 0)) return 0;
    return 1;
}
/* localdecomp:end func_L01_003B1EB0 */

#include "common.h"

typedef struct {
    u8 pad[0x34];
    u16 h34;
    u8 pad36[0x32];
    s32 *w68;
} Moby_003B3CC0;
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x1C - 0x14];
    s32 w1C;
    u8 pad20[0x30 - 0x20];
    s32 w30;
} S_3B4CC0b;
typedef struct {
    u8 pad0[0x68];
    S_3B4CC0b *p68;
} S_3B4CC0;
typedef int u128_3B5048 __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; s32 w10; u8 p14[0x30]; u16 h44; } C_3B5048;
typedef struct { u8 p0[0x81]; u8 b81; u16 h82; } V_3B5048;
typedef struct {
    u8 p0[0x10]; u128_3B5048 pos; u8 b20; u8 b21; u8 p22[2]; C_3B5048 *w24; u8 p28[8];
    u8 b30; u8 b31; u16 h32; u16 h34; u8 p36[0x32]; V_3B5048 *w68; u8 p6C[0x13]; u8 b7F; u8 p80[0x15]; u8 b95;
    u8 p96[2]; s32 w98; u8 p9C[0x24]; u8 vC0[0x30]; u128_3B5048 vF0;
} M_3B5048;
typedef struct { f32 f0; s16 h4; } A_3B5048;
typedef struct { s16 h0; s16 h2; u8 b4; u8 b5; u8 b6; u8 p7[0x13]; u8 b1A; u8 p1B[0x1D]; s16 h38; } B_3B5048;
typedef struct { u8 p0[8]; void *w8; } E_3B5048;
typedef struct Obj_003B51A0 {
    u8 pad[0x24];
    s32 w24;
    u8 pad28[0x3C];
    void (*fn64)(struct Obj_003B51A0 *);
} Obj_003B51A0;
typedef void (*Fn_003B52B0)(u8 *, s32);

extern void func_L01_004450F0(s32, s32, s32);
extern u8 *D_L01_001E001C;
extern void func_L01_003B3368(u8 *a0);
extern u8 *func_L01_003B3430(u8 *a0);
extern u8 *D_L01_001E0100[];
extern void func_L01_004F50C8(u8 *, u8 *, s32, s32);
extern void func_L01_003EE650(s32);
extern s32 func_L01_003B3548(u8 *);

/* declared by functions of L01_003B2F80.c, which this file was cut from */
extern s32 func_L01_003B36A8(u8 *, u8 *);
extern s32 D_L01_001DE634;
extern s32 func_L01_003B5B40(u8 *);

/* localdecomp:start func_L01_003B36A8 */
typedef struct {
    s32 w0; s32 w4; u8 *w8; s32 wC; u8 pad10[0x24]; s32 w34; s32 w38; s32 w3C; s32 w40; s32 w44;
    s32 w48; s32 w4C; s32 w50; s32 w54; f32 f58; s32 w5C; f32 f60; s32 w64; s32 w68;
} S_003B36A8;
extern s32 D_L01_001DFB40_003B36A8[] __attribute__((section(".sdata")));
extern s32 D_L01_001E0058;
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C_003B36A8[] __attribute__((section(".sdata")));
extern u8 D_001A4C60[];
__asm__(".extern D_L01_001DE634, 4");
extern s32 func_L01_003B5B88_003B36A8(u8 *, s32);
extern f32 func_L01_003B5C80(u8 *, s32, s32, f32 *, f32 *);
extern s32 func_L01_003B5EF0_003B36A8(u8 *, s32);
extern s32 func_L01_003B5F00(u8 *);
extern s32 func_L01_003B5F30_003B36A8(u8 *, s32);
extern f32 func_L01_003B5F60_003B36A8(u8 *, s32);
extern s32 func_L01_003B5FC8_003B36A8(u8 *, s32);
extern s32 func_L01_00327330(void);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_00456250(u8 *);
extern s32 func_L01_00445AD0(s32, s32, s32);

s32 func_L01_003B36A8(u8 *a0, u8 *a1) {
    S_003B36A8 *st = (S_003B36A8 *)a1;
    u8 *vars = *(u8 **)(st->w8 + 0x68);
    u8 *m;
    u8 *v;
    u8 *first;
    u16 *p;
    s32 n, sum1, sum2;
    f32 sum, total, damage;
    f32 out[2];

    if (st->w34 && D_L01_001DFB40_003B36A8[0] - st->w4 < st->w34 * 50) return 0;
    if (st->w38 && D_L01_001DFB40_003B36A8[0] - *(s32 *)(vars + 0x60) < st->w38 * 50) return 0;
    if (st->w40) {
        for (p = D_L01_0021DE20[st->wC];
             (st->wC & 0xFF) != 0xFF && st->wC <= D_L01_001E0058 && p != 0 &&
             ((s16)p[-1] >= 0 || p == D_L01_0021DE20[st->wC]);
             p++) {
            m = D_L01_001E001C_003B36A8[0] + ((*p & 0x7FFF) << 8);
            if (m == 0) break;
            if (func_L01_003B5B40(m) && !func_L01_003B5B88_003B36A8(m, 0)) return 0;
        }
    }
    if (st->w44) {
        for (p = D_L01_0021DE20[st->wC];
             (st->wC & 0xFF) != 0xFF && st->wC <= D_L01_001E0058 && p != 0 &&
             ((s16)p[-1] >= 0 || p == D_L01_0021DE20[st->wC]);
             p++) {
            m = D_L01_001E001C_003B36A8[0] + ((*p & 0x7FFF) << 8);
            if (m == 0) break;
            if (func_L01_003B5F00(m) && !func_L01_003B5F30_003B36A8(m, 0)) return 0;
        }
    }
    first = (u8 *)D_L01_001DE634;
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
            if (func_L01_003B5B40(m)) {
                if (st->f58 >= 0.0f) {
                    if (func_L01_003B5C80(m, 0, 1, &out[0], &out[1]) >= 0.0f) {
                        sum += out[0];
                        total += out[1];
                    }
                } else if (st->w5C >= 0) {
                    sum1 += func_L01_003B5EF0_003B36A8(m, 0);
                } else if (!func_L01_003B5B88_003B36A8(m, 0)) {
                    return 0;
                }
            } else if (func_L01_003B5F00(m)) {
                if (st->f60 >= 0.0f) {
                    damage += func_L01_003B5F60_003B36A8(m, 0);
                    n++;
                } else if (st->w64 < 0) {
                    if (!func_L01_003B5F30_003B36A8(m, 0)) return 0;
                } else {
                    sum2 += func_L01_003B5FC8_003B36A8(m, 0);
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
    if (st->w68 && func_L01_00327330()) return 0;
    if (st->w3C != -1 && !func_L01_00456500(D_001A4C60, st->w3C)) return 0;
    if (st->w48 != -1 && !func_L01_00456250(D_L01_001E001C + (st->w48 << 8))) return 0;
    if (st->w4C != -1) {
        u16 *q;
        for (q = D_L01_0021DE20[st->w4C];
             (st->w4C & 0xFF) != 0xFF && st->w4C <= D_L01_001E0058 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L01_0021DE20[st->w4C]);
             q++) {
            u8 *e = D_L01_001E001C_003B36A8[0] + ((*q & 0x7FFF) << 8);
            if (e == 0) break;
            if (!func_L01_00456250(e)) return 0;
        }
    }
    if (st->w50 != -1) {
        u8 *e = D_L01_001E001C + (st->w50 << 8);
        if (e && e[0x20] != 0xFE && e[0x20] != 0xFD) return 0;
    }
    if (st->w54 != -1 && func_L01_00445AD0(st->w54, -1, 0)) return 0;
    return 1;
}
/* localdecomp:end func_L01_003B36A8 */

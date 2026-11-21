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
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L01_003B56B8(u8 *a0, u8 *a1);

/* localdecomp:start func_L01_003B56B8 */
typedef struct {
    u8 p0[4];
    s32 w4;
    s32 w8;
    f32 fC;
    s32 w10;
    f32 f14;
    u8 p18[0x30 - 0x18];
    s32 w30;
    u8 p34[0x54 - 0x34];
    s32 w54;
    s32 w58;
    u8 p5C[0x78 - 0x5C];
    s32 w78;
    u8 p7C[0xB0 - 0x7C];
    s32 wB0;
    s32 wB4;
    s32 wB8;
    s32 wBC;
    u8 pC0[0xC8 - 0xC0];
    s32 wC8;
    s32 wCC;
    s32 aD0[4];
    s32 aE0[4];
    u8 pF0[0x100 - 0xF0];
    s32 a100[4];
} V_003B56B8;
extern s16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;

void func_L01_003B56B8(u8 *a0, u8 *a1) {
    V_003B56B8 *s = (V_003B56B8 *)a1;
    s16 *q;
    u8 *m;
    s32 n;
    s32 total;
    s32 i;

    a0[0x30] = 0xFF;
    s->wBC = s->w10;
    if (s->w30 < 0) {
        s->wBC = -1;
    } else {
        s->wBC += s->w30;
    }
    n = 0;
    if (s->w4 != -1) {
        q = D_L01_0021DE20[s->w4];
        while ((s->w4 & 0xFF) != 0xFF && s->w4 <= D_L01_001E0058 && q != 0 && (q[-1] >= 0 || q == D_L01_0021DE20[s->w4])) {
            m = D_L01_001E001C + ((*(u16 *)q & 0x7FFF) << 8);
            if (m == 0) break;
            n++;
            q++;
        }
    }
    s->wB0 = n;
    if (s->w8 != -1) n++;
    s->wB4 = n;
    total = 0;
    s->wC8 = 0;
    s->wCC = 0;
    for (i = 0; i < 4; i++) {
        s->a100[i] = 0;
        if (s->aD0[i] != -1) {
            q = D_L01_0021DE20[s->aD0[i]];
            while ((s->aD0[i] & 0xFF) != 0xFF && s->aD0[i] <= D_L01_001E0058 && q != 0 && (q[-1] >= 0 || q == D_L01_0021DE20[s->aD0[i]])) {
                m = D_L01_001E001C + ((*(u16 *)q & 0x7FFF) << 8);
                if (m == 0) break;
                s->a100[i]++;
                q++;
            }
            total += s->a100[i];
            if (s->wC8 < i) {
                s->aD0[s->wC8] = s->aD0[i];
                s->aD0[i] = -1;
                s->a100[s->wC8] = s->a100[i];
                s->a100[i] = 0;
            }
            s->wC8++;
        }
        if (s->aE0[i] != -1) {
            total++;
            if (s->wCC < i) {
                s->aE0[s->wCC] = s->aE0[i];
                s->aE0[i] = -1;
            }
            s->wCC++;
        }
    }
    s->wB8 = total;
    if (s->fC < 0.0f) {
        if (total == 0) {
            s->fC = 1.0f;
        } else {
            s->fC = (f32)n / (f32)(n + total);
            if (s->fC > 1.0f) {
                s->fC = 1.0f;
            } else if (s->fC < 0.0f) {
                s->fC = 0.0f;
            }
        }
    } else if (s->fC > 1.0f) {
        s->fC = 1.0f;
    }
    if (s->f14 < 0.0f) {
        if (total == 0) {
            s->f14 = 1.0f;
        } else {
            s->f14 = (f32)n / (f32)(n + total);
            if (s->f14 > 1.0f) {
                s->f14 = 1.0f;
            } else if (s->f14 < 0.0f) {
                s->f14 = 0.0f;
            }
        }
    } else if (s->f14 > 1.0f) {
        s->f14 = 1.0f;
    }
    s->w54 = 0;
    s->w58 = 0;
    s->w78 = 0;
    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(a0, 1, -1);
}
/* localdecomp:end func_L01_003B56B8 */

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
extern s32 func_L01_003B7AA8(u8 *a0, u8 *a1);

/* localdecomp:start func_L01_003B7AA8 */
extern u8 D_001BBC40[];
extern s32 D_001D545C_003B7AA8;
extern s32 func_L01_00326DD0(s32, s32);

s32 func_L01_003B7AA8(u8 *a0, u8 *s) {
    s32 n;
    s32 c;
    s32 r;
    s32 t;
    s32 lim;
    s32 d;
    if (*(s32 *)(s + 0x110) != -1 && !(D_001BBC40[*(s32 *)(s + 0x110) + D_001D545C_003B7AA8 * 16] & 0x80)) {
        return 0;
    }
    if (*(s32 *)(s + 0x114) != -1 && (D_001BBC40[*(s32 *)(s + 0x114) + D_001D545C_003B7AA8 * 16] & 0x80)) {
        return 0;
    }
    n = *(s32 *)(s + 0x18);
    if (n <= 0) {
        return 0;
    }
    if (*(s32 *)(s + 0x30) == 0) {
        return 0;
    }
    if (*(s32 *)(s + 0x88) != 0 && *(s32 *)(s + 0x8C) >= *(s32 *)(s + 0x88)) {
        return 0;
    }
    c = *(s32 *)(s + 0xC0) - *(s32 *)(s + 0xC4);
    if (c >= n) {
        return 0;
    }
    r = n - c;
    if (r < *(s32 *)(s + 0x1C)) {
        return 0;
    }
    t = func_L01_00326DD0(*(s32 *)s, r);
    if (t < r) {
        r = t;
    }
    if (r == 0) {
        return 0;
    }
    lim = *(s32 *)(s + 0x1C);
    if (lim < r) {
        r = lim;
    }
    if (*(s32 *)(s + 0x30) > 0) {
        d = *(s32 *)(s + 0xBC) - *(s32 *)(s + 0xC0);
        if (d <= 0) {
            return 0;
        }
        if (d < r) {
            r = d;
        }
        if (r < lim) {
            return 0;
        }
    }
    return r;
}
/* localdecomp:end func_L01_003B7AA8 */

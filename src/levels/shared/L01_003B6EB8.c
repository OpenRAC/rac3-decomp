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
extern Fn_003B52B0 *func_L01_00326D78(s32);

/* localdecomp:start func_L01_003B6EB8 */
typedef struct {
    s32 w0;
    u8 p4[0x78 - 0x4];
    s32 w78;
    s32 w7C;
    u8 p80[0x90 - 0x80];
    s32 w90[4];
    s32 wA0[4];
    u8 pB0[0xD0 - 0xB0];
    s32 wD0[4];
    u8 pE0[0xF0 - 0xE0];
    s32 wF0[4];
} S_003B6EB8;

extern Fn_003B52B0 *func_L01_00326D78(s32);
extern u8 *func_L01_003B6AB0(u8 *a0, s32 *a1, s32 a2, s32 a3, Fn_003B52B0 *cb);
extern s32 func_L01_003B69E0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_L01_003B69A0(void *a, void *b, Obj_003B51A0 *o);
extern u8 *D_L01_001E001C_003B6EB8;
__asm__(".extern D_L01_001E001C_003B6EB8, 16");
extern s32 D_L01_001E0058_003B6EB8;
__asm__(".extern D_L01_001E0058_003B6EB8, 16");
extern u16 *D_L01_0021DE20[];

static __inline__ u8 *moby_003B6EB8(s32 idx) {
    return D_L01_001E001C_003B6EB8 + (idx << 8);
}

void func_L01_003B6EB8(u8 *a0, u8 *a1, s32 a2) {
    S_003B6EB8 *s = (S_003B6EB8 *)a1;
    Fn_003B52B0 *t;
    s32 i;
    s32 j;
    s32 n;
    s32 a;
    s32 m;
    s32 grp;
    u8 *r;
    u16 *q;

    t = func_L01_00326D78(s->w0);
    for (i = 0; i < 4; i++) {
        s->wA0[i] = -1;
    }
    for (j = 0; j < 4; j++) {
        i = (j + s->w7C) % 4;
        if (s->wD0[i] == -1) continue;
        n = s->w90[i];
        if (n == 0) continue;
        a = s->wF0[i];
        grp = 0xFF;
        s->w78 = 1;
        m = 0;
        while (n != 0 && a2 > 0) {
            u16 *p = &D_L01_0021DE20[s->wD0[i]][m];
            r = func_L01_003B6AB0(a0, (s32 *)s, (s32)moby_003B6EB8(*p & 0x7FFF), s->w0, t);
            m++;
            if (r == 0) break;
            grp = func_L01_003B69E0((s32)a0, (s32)s, (s32)r, grp, a);
            n--;
            a2--;
        }
        s->w78 = 0;
        for (q = D_L01_0021DE20[grp]; (grp & 0xFF) != 0xFF && grp <= D_L01_001E0058_003B6EB8 && q != 0 && ((s16)q[-1] >= 0 || q == D_L01_0021DE20[grp]); q++) {
            r = moby_003B6EB8(*q & 0x7FFF);
            if (r == 0) break;
            if (r[0x20] == 0) {
                func_L01_003B69A0(a0, s, (Obj_003B51A0 *)r);
            }
        }
        s->wA0[i] = grp;
    }
    s->w7C = i + 1;
}
/* localdecomp:end func_L01_003B6EB8 */

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

/* localdecomp:start func_L01_003B6B68 */
typedef struct {
    s32 w0;
    u8 p4[0x24 - 0x4];
    s32 w24;
    s32 w28;
    s32 w2C;
    u8 p30[0x68 - 0x30];
    s32 w68;
    u8 p6C[0xF0 - 0x6C];
    s32 wF0[13];
    s32 w124;
} S_003B6B68;
typedef struct {
    u8 p0[0x10];
    s32 w10;
    u8 p14[0x44 - 0x14];
    u16 h44;
} C_003B6B68;
typedef struct {
    u8 p0[0x20];
    u8 b20;
    u8 p21[0x24 - 0x21];
    C_003B6B68 *w24;
    u8 p28[0x34 - 0x28];
    u16 h34;
    u8 p36[0x98 - 0x36];
    s32 w98;
} M_003B6B68;

typedef void (*Fn_003B6B68)(u8 *, s32);

extern Fn_003B6B68 *func_L01_00326D78(s32);
extern u8 *func_L01_003B64F0(u8 *, f32, f32, s32 *);
extern u8 *func_L01_003B6AB0(u8 *a0, s32 *a1, s32 a2, s32 a3, Fn_003B6B68 *cb);
extern s32 func_L01_003B69E0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_L01_003B69A0_003B6B68(void *a, void *b, M_003B6B68 *o);
extern void func_L01_003B6A80(void *a, char *b, char *c);
extern s32 func_003C4B40(s32);
extern void func_003C7C38_003B6B68(M_003B6B68 *);
extern u8 *D_L01_001E001C_003B6B68;
extern s32 D_L01_001E0058_003B6B68;
extern u16 *D_L01_0021DE20[];

static __inline__ u8 *moby_003B6B68(s32 idx) {
    return D_L01_001E001C_003B6B68 + (idx << 8);
}

s32 func_L01_003B6B68(u8 *a0, u8 *a1, f32 f, s32 oclass, s32 count, s32 flag) {
    S_003B6B68 *s = (S_003B6B68 *)a1;
    Fn_003B6B68 *t;
    f32 v1;
    s32 color;
    s32 i;
    s32 idx;
    s32 k;
    u8 *obj;
    M_003B6B68 *r;

    t = func_L01_00326D78(oclass);
    if (t[1] != 0) {
        v1 = ((f32 (*)(void))t[1])();
    } else {
        v1 = 0.0f;
    }
    color = 0xFF;
    if (s->w28 != 0 && s->w2C != 0) {
        color = s->w68;
    }
    for (i = 0; i < count; i++) {
        obj = func_L01_003B64F0(a1, f, v1, &idx);
        if (obj == 0) {
            s->w24 = 1;
            break;
        }
        if (idx < 0) {
            k = s->w124;
        } else {
            k = s->wF0[idx];
        }
        r = (M_003B6B68 *)func_L01_003B6AB0(a0, (s32 *)a1, (s32)obj, oclass, t);
        if (r == 0) {
            break;
        }
        if ((s->w28 != 0 && count >= 2) || k >= 0) {
            color = func_L01_003B69E0((s32)a0, (s32)a1, (s32)r, color, k);
        }
        if (color == 0xFF) {
            func_L01_003B69A0_003B6B68(a0, a1, r);
        }
        if (flag != 0) {
            ((void (*)(void *, u8 *, u8 *, s32, s32))func_L01_003B6A80)(a0, a1, (u8 *)r, 0, 0);
        }
    }
    if (color != 0xFF) {
        if (func_003C4B40(oclass) != 0) {
            u16 *q;
            for (q = D_L01_0021DE20[color]; (color & 0xFF) != 0xFF && color <= D_L01_001E0058_003B6B68 && q != 0 && ((s16)q[-1] >= 0 || q == D_L01_0021DE20[color]); q++) {
                r = (M_003B6B68 *)moby_003B6B68(*q & 0x7FFF);
                if (r == 0) break;
                r->h34 &= ~0x41;
                r->h34 |= r->w24->h44 & 0x1000;
                r->w98 = r->w24->w10;
                func_003C7C38_003B6B68(r);
            }
        }
        {
            u16 *q;
            for (q = D_L01_0021DE20[color]; (color & 0xFF) != 0xFF && color <= D_L01_001E0058_003B6B68 && q != 0 && ((s16)q[-1] >= 0 || q == D_L01_0021DE20[color]); q++) {
                r = (M_003B6B68 *)moby_003B6B68(*q & 0x7FFF);
                if (r == 0) break;
                if (r->b20 == 0) {
                    func_L01_003B69A0_003B6B68(a0, a1, r);
                }
            }
        }
    }
    s->w68 = color;
    return color;
}
/* localdecomp:end func_L01_003B6B68 */

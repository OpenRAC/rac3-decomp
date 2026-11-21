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
extern s32 func_L01_003B3C48(u8 *, u8 *);
extern s32 D_L01_001DE634;
extern s32 func_L01_003B5B68(u8 *);

/* localdecomp:start func_L01_003B3C48 */
typedef struct {
    u8 p0[0x58];
    u8 *next;
    u8 p5C[4];
    s32 time;
} St_003B3C48;
typedef struct {
    u8 p0[0x68];
    St_003B3C48 *st;
} Ob_003B3C48;
typedef struct {
    s32 w0;
    s32 time;
    Ob_003B3C48 *obj;
    s32 group;
    u8 p10[0x6C];
    s32 timeout;
    s32 timeout2;
    s32 check;
    s32 first;
    s32 second;
    s32 single;
    s32 all;
    s32 dead;
    s32 other;
    f32 val;
    s32 count;
    f32 val2;
    s32 count2;
} Cond_003B3C48;

extern s16 *D_L01_0021DE20[];
extern s32 D_L01_001DFB40_003B3C48;
__asm__(".extern D_L01_001DFB40_003B3C48, 16");
extern u8 *D_L01_001E001C_003B3C48;
__asm__(".extern D_L01_001E001C_003B3C48, 16");
extern s32 D_L01_001E0058;
__asm__(".extern D_L01_001E0058, 4");
extern u8 D_001A4C60[];
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L01_003B5F10(u8 *);
extern f32 func_L01_003B5C80(u8 *, s32, s32, s32, s32);
extern s32 func_L01_003B5B88_003B3C48(u8 *, s32);
extern s32 func_L01_003B5F30_003B3C48(u8 *, s32);
extern s32 func_L01_003B5EF0_003B3C48(u8 *, s32);
extern f32 func_L01_003B5F60_003B3C48(u8 *, s32);
extern s32 func_L01_003B5FC8_003B3C48(u8 *, s32);

s32 func_L01_003B3C48(u8 *a0, u8 *a1) {
    Cond_003B3C48 *c = (Cond_003B3C48 *)a1;
    St_003B3C48 *init = c->obj->st;

    if (c->timeout != 0 && c->timeout * 50 < D_L01_001DFB40_003B3C48 - c->time) {
        return 1;
    }
    if (c->timeout2 != 0 && c->timeout2 * 50 < D_L01_001DFB40_003B3C48 - init->time) {
        return 1;
    }
    if (c->first != 0) {
        s16 *q = D_L01_0021DE20[c->group];
        while ((c->group & 0xFF) != 0xFF && c->group <= D_L01_001E0058 && q != 0 &&
               (q[-1] >= 0 || q == D_L01_0021DE20[c->group])) {
            u8 *r = D_L01_001E001C_003B3C48 + ((*(u16 *)q & 0x7FFF) << 8);
            if (r == 0) break;
            if (func_L01_003B5B68(r) && func_L01_003B5B88_003B3C48(r, 1)) {
                return 1;
            }
            q++;
        }
    }
    if (c->second != 0) {
        s16 *q = D_L01_0021DE20[c->group];
        while ((c->group & 0xFF) != 0xFF && c->group <= D_L01_001E0058 && q != 0 &&
               (q[-1] >= 0 || q == D_L01_0021DE20[c->group])) {
            u8 *r = D_L01_001E001C_003B3C48 + ((*(u16 *)q & 0x7FFF) << 8);
            if (r == 0) break;
            if (func_L01_003B5F10(r) && func_L01_003B5F30_003B3C48(r, 1)) {
                return 1;
            }
            q++;
        }
    }
    if (D_L01_001DE634 != 0) {
        u8 *o = (u8 *)D_L01_001DE634;
        f32 sum, sum2;
        s32 n, n2, total, total2;
        sum2 = 0.0f;
        total = 0;
        total2 = 0;
        n = 0;
        n2 = 0;
        sum = sum2;
        do {
            St_003B3C48 *p = ((Ob_003B3C48 *)o)->st;
            if (func_L01_003B5B68(o)) {
                if (c->val >= 0.0f) {
                    f32 v = func_L01_003B5C80(o, 1, 1, 0, 0);
                    if (v >= 0.0f) {
                        sum += v;
                        n++;
                    }
                } else if (c->count >= 0) {
                    total += func_L01_003B5EF0_003B3C48(o, 1);
                    n++;
                } else if (func_L01_003B5B88_003B3C48(o, 1)) {
                    return 1;
                }
            } else if (func_L01_003B5F10(o)) {
                if (c->val2 >= 0.0f) {
                    sum2 += func_L01_003B5F60_003B3C48(o, 1);
                    n2++;
                } else if (c->count2 < 0) {
                    if (func_L01_003B5F30_003B3C48(o, 1)) {
                        return 1;
                    }
                } else {
                    total2 += func_L01_003B5FC8_003B3C48(o, 1);
                    n2++;
                }
            }
            o = p->next;
        } while (o != 0);
        if (c->val >= 0.0f) {
            if (n >= 2) sum /= n;
            if (c->val <= sum) return 1;
        } else if (c->count >= 0 && total >= c->count) {
            return 1;
        }
        if (c->val2 >= 0.0f) {
            if (n2 >= 2) sum2 /= n2;
            if (c->val2 <= sum2) return 1;
        } else if (c->count2 >= 0 && total2 >= c->count2) {
            return 1;
        }
    }
    if (c->check != -1 && func_L01_00456500(D_001A4C60, c->check)) {
        return 1;
    }
    if (c->single != -1 && func_L01_00456250(D_L01_001E001C + (c->single << 8))) {
        return 1;
    }
    if (c->all != -1) {
        s32 ok = 1;
        s16 *q = D_L01_0021DE20[c->all];
        while ((c->all & 0xFF) != 0xFF && c->all <= D_L01_001E0058 && q != 0 &&
               (q[-1] >= 0 || q == D_L01_0021DE20[c->all])) {
            u8 *r = D_L01_001E001C_003B3C48 + ((*(u16 *)q & 0x7FFF) << 8);
            if (r == 0) break;
            if (!func_L01_00456250(r)) {
                ok = 0;
                break;
            }
            q++;
        }
        if (ok) return 1;
    }
    if (c->dead != -1) {
        u8 *r = D_L01_001E001C + (c->dead << 8);
        if (r == 0) return 1;
        if (r[0x20] == 0xFE) return 1;
        if (r[0x20] == 0xFD) return 1;
    }
    if (c->other != -1 && !func_L01_00445AD0(c->other, -1, 0)) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003B3C48 */

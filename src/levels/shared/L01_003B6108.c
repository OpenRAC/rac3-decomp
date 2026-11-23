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
extern Fn_003B52B0 *func_L01_00326D98(void);

/* localdecomp:start func_L01_003B6108 */
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L01_003B3450(s32 a0);

void func_L01_003B6108(u8 *obj)
{
    u8 *vars = *(u8 **)(obj + 104);

    if (*(s32 *)(vars + 80) != 0 && *(s32 *)(vars + 84) == 0) {
        ((void (*)(void))func_L01_003B3450)();
    }
    if (*(s32 *)(vars + 196) < *(s32 *)(vars + 192)) {
        ((void (*)(u8 *, s32, s32))func_L01_004450F0)(obj, 3, -1);
    } else if (obj[32] == 4) {
        obj[188] = 1;
    } else {
        ((void (*)(u8 *, s32, s32))func_L01_004450F0)(obj, 1, -1);
    }
}
/* localdecomp:end func_L01_003B6108 */

/* localdecomp:start func_L01_003B61A0 */
/* Retail reads this variable through lui/lw here, the file's sized D_L01_001E001C through $gp: an unsized alias. */
extern u8 *D_L01_001E001C_003B61A0[];
extern void func_L01_0043B840(s32, u8 *);
extern void func_L01_003B6250(u8 *, u8 *, s32);

void func_L01_003B61A0(u8 *a0, u8 *a1) {
    u8 *vars = *(u8 **)(a0 + 104);
    s32 idx = *(s32 *)(vars + 108);

    if (idx != -1 && a1 == D_L01_001E001C_003B61A0[0] + (idx << 8)) {
        *(s32 *)(vars + 140) += 1;
        return;
    }
    if (a1[33] != 0xFF) {
        func_L01_0043B840(a1[33], a1);
    }
    func_L01_003B6250(a0, a1, 0);
    if (*(s16 *)(a1 + 170) == *(s32 *)vars) {
        *(s32 *)(vars + 196) += 1;
    }
}
/* localdecomp:end func_L01_003B61A0 */

/* localdecomp:start func_L01_003B6250 */
extern s32 func_L01_00456250(u8 *);
extern void func_L01_00456230(u8 *, s32);
void func_L01_003B6250(u8 *a0, u8 *a1, s32 a2) {
    u8 *s = *(u8 **)(a0 + 104);
    s32 r;
    u8 x, y;
    if (*(s16 *)(a1 + 170) == *(s32 *)s) {
        r = func_L01_00456250(a1);
        x = a2 != 0;
        y = r == 0;
        x ^= y;
        if (!x) {
            if (r != 0) {
                *(s32 *)(s + 76) -= 1;
            } else {
                *(s32 *)(s + 76) += 1;
            }
            func_L01_00456230(a1, a2);
        }
    }
}
/* localdecomp:end func_L01_003B6250 */

/* localdecomp:start func_L01_003B62E0 */
extern u8 *D_L01_001E001C_003B62E0[];
extern void func_L01_0043B840(s32, u8 *);

void func_L01_003B62E0(u8 *a0, u8 *a1) {
    u8 *vars = *(u8 **)(a0 + 104);
    s16 h;

    if (a1 != D_L01_001E001C_003B62E0[0] + (*(s32 *)(vars + 0x6C) << 8)) {
        if (a1[0x21] != 0xFF) {
            func_L01_0043B840(a1[0x21], a1);
        }
        h = *(s16 *)(a1 + 0xAA);
        if (h == *(s32 *)vars) {
            if (*(s32 *)(vars + 0x84) != 0) {
                *(s32 *)(vars + 0xC4) += 1;
            } else {
                *(s32 *)(vars + 0xC0) -= 1;
            }
        }
    }
}
/* localdecomp:end func_L01_003B62E0 */

/* localdecomp:start func_L01_003B6370 */
extern void func_L01_0043B840(s32, u8 *);
extern void func_L01_003B6250(u8 *, u8 *, s32);
extern Fn_003B52B0 *func_L01_00326D78(s32);
extern u8 *D_L01_001E001C_003B6370[];

void func_L01_003B6370(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a0 + 104);
    s32 idx = *(s32 *)(s + 0x6C);
    Fn_003B52B0 *t;
    if (idx != -1 && a1 == D_L01_001E001C_003B6370[0] + (idx << 8)) {
        return;
    }
    if (a1[0x21] != 0xFF) {
        func_L01_0043B840(a1[0x21], a1);
    }
    if (*(s16 *)(a1 + 0xAA) == *(s32 *)s) {
        func_L01_003B6250(a0, a1, 0);
        if (*(s32 *)(s + 0x6C) != -1 && *(s32 *)(s + 0x84) != 0) {
            *(s32 *)(s + 0xC4) += 1;
        } else {
            *(s32 *)(s + 0xC0) -= 1;
        }
        if (a1 == *(u8 **)(s + 0x11C)) {
            *(s32 *)(s + 0x11C) = 0;
        }
    }
    t = func_L01_00326D78(*(s16 *)(a1 + 0xAA));
    ((void (*)(u8 *))t[3])(a1);
}
/* localdecomp:end func_L01_003B6370 */

/* localdecomp:start func_L01_003B6458 */
extern Fn_003B52B0 *func_L01_00326D98(void);

void func_L01_003B6458(u8 *a0) {
    s32 idx = *(s32 *)(*(u8 **)(a0 + 0x68) + 0x6C);
    u8 *p;
    Fn_003B52B0 *r;
    if (idx != -1) {
        p = D_L01_001E001C + (idx << 8);
        r = func_L01_00326D98();
        if (((s32 (*)(u8 *))r[2])(p) == 0) {
            ((void (*)(u8 *))r[3])(p);
        }
    }
}
/* localdecomp:end func_L01_003B6458 */

/* localdecomp:start func_L01_003B64C0 */


s32 func_L01_003B64C0(S_3B4CC0 *a0) {
    s32 r = a0->p68->w10 * 0;
    S_3B4CC0b *p = a0->p68;
    r = p->w10;
    if (p->w30 > 0) {
        r += p->w30;
    } else if (p->w30 < 0) {
        r += p->w1C * 2;
    }
    return r;
}
/* localdecomp:end func_L01_003B64C0 */

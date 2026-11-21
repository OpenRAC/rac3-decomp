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
extern s32 func_0038CAD0(u8 *);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L01_003B54C0(Moby_003B3CC0 *m, s32 value);

/* localdecomp:start func_L01_003B5498 */
extern void func_L01_004450F0(s32, s32, s32);
void func_L01_003B5498(u8 *obj) {
    obj[48] = 255;
    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(obj, 1, -1);
}
/* localdecomp:end func_L01_003B5498 */

/* localdecomp:start func_L01_003B54C0 */
extern void func_L01_004450F0(s32, s32, s32);


void func_L01_003B54C0(Moby_003B3CC0 *m, s32 value) {
    m->w68[3] = value;
    ((void (*)(Moby_003B3CC0 *, s32, s32))func_L01_004450F0)(m, 2, -1);
    m->h34 &= ~2;
}
/* localdecomp:end func_L01_003B54C0 */

/* localdecomp:start func_L01_003B5500 */
extern u8 *D_L01_001E0100[];
extern void func_L01_004F50C8(u8 *, u8 *, s32, s32);
void func_L01_003B5500(s32 a0, s32 a1, s32 a2) {
    u8 *p = D_L01_001E0100[0] + (a2 << 7);
    func_L01_004F50C8(p + 48, p + 112, 0, 1);
}
/* localdecomp:end func_L01_003B5500 */

/* localdecomp:start func_L01_003B5538 */
extern s32 D_L01_001DE758;
s32 *func_L01_003B5538(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 6) {
        *a2 = 4;
        return &D_L01_001DE758;
    }
    return 0;
}
/* localdecomp:end func_L01_003B5538 */

/* localdecomp:start func_L01_003B5558 */
extern void func_L01_003B56B8(u8 *a0, u8 *a1);
extern s32 func_L01_003B7AA8(u8 *a0, u8 *a1);
extern void func_L01_003B78F8(u8 *a0, u8 *s, s32 a2, f32 t);
extern Fn_003B52B0 *func_L01_00326D98(void);
extern u8 *D_L01_001E001C_003B5558[];

void func_L01_003B5558(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);
    Fn_003B52B0 *t;
    s32 r;
    if (a0[32] == 0) {
        func_L01_003B56B8(a0, s);
    }
    switch (a0[32]) {
    case 1:
        *(u16 *)(a0 + 52) |= 2;
        break;
    case 2:
        if (*(s32 *)(s + 36) != 0) {
            if (func_0038CAD0(s + 36) != 0) {
                r = func_L01_003B7AA8(a0, s);
                if (r != 0) {
                    func_L01_003B78F8(a0, s, r, *(f32 *)(s + 12));
                }
            }
        } else {
            if (func_L01_003B7AA8(a0, s) != 0) {
                *(s32 *)(s + 36) = *(s32 *)(s + 32);
            }
        }
        break;
    case 3:
        if (*(s32 *)(s + 196) == *(s32 *)(s + 192)) {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    case 4:
        if (func_0038CAD0(s + 36) != 0) {
            t = func_L01_00326D98();
            if (((s32 (*)(u8 *))t[2])(D_L01_001E001C_003B5558[0] + (*(s32 *)(s + 108) << 8)) != 0) {
                func_L01_004450F0(a0, a0[188], -1);
            }
        }
        break;
    }
}
/* localdecomp:end func_L01_003B5558 */

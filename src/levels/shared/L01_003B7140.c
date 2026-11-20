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
extern Fn_003B52B0 *func_L01_00326D98(void);
extern void func_L01_003B6848(void *owner, M_3B5048 *m, M_3B5048 *src);
extern u8 *func_L01_00326A10(s32);

/* localdecomp:start func_L01_003B7140 */
extern Fn_003B52B0 *func_L01_00326D98(void);
extern u8 *D_L01_001E001C_003B7140[];

void func_L01_003B7140(u8 *a0, s32 *a1) {
    Fn_003B52B0 *r;
    u8 *p;

    r = func_L01_00326D98();
    p = D_L01_001E001C_003B7140[0] + (a1[27] << 8);
    func_L01_003B6848(a0, (M_3B5048 *)p, 0);
    (*r)(p, 0);
}
/* localdecomp:end func_L01_003B7140 */

/* localdecomp:start func_L01_003B71B0 */
extern Fn_003B52B0 *func_L01_00326D98(void);
extern u8 *func_L01_00326A10(s32);
extern u8 *D_L01_001E001C_003B71B0[];

s32 func_L01_003B71B0(u8 *a0, u8 *a1) {
    Fn_003B52B0 *r;
    u8 *p;
    u8 *q;
    s32 i;
    r = func_L01_00326D98();
    p = D_L01_001E001C_003B71B0[0] + (*(s32 *)(a1 + 0x6C) << 8);
    for (i = 3; i >= 0; i--) {
        *(s32 *)(a1 + 0xA0 + i * 4) = -1;
    }
    q = func_L01_00326A10(*(s32 *)a1);
    if (q == 0) {
        return 0;
    }
    ((void (*)(u8 *, u8 *))r[5])(q, p);
    func_L01_003B6848(a0, (M_3B5048 *)q, 0);
    (*r)(q, 0);
    *(s32 *)(a1 + 0xC0) += 1;
    return 1;
}
/* localdecomp:end func_L01_003B71B0 */

/* localdecomp:start func_L01_003B7290 */
extern Fn_003B52B0 *func_L01_00326D78_003B7290(s32);
extern u8 *func_L01_003B64F0_003B7290(u8 *, f32, f32, s32 *);
extern u8 *func_L01_003B6AB0_003B7290(u8 *a0, s32 *a1, s32 a2, s32 a3, Fn_003B52B0 *cb);
extern s32 func_L01_003B69E0_003B7290(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_L01_003B69A0_003B7290(void *a, void *b, Obj_003B51A0 *o);
extern void func_L01_003B6A80_003B7290(void *a, char *b, char *c);
extern void func_L01_003B6B68_003B7290(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 a4);

void func_L01_003B7290(u8 *a0, u8 *a1, s32 count, f32 f) {
    s32 i;
    Fn_003B52B0 *t1;
    Fn_003B52B0 *t2;
    f32 v1;
    f32 v2;
    s32 color;
    s32 idx;
    s32 idx2;
    u8 *tbl;

    t1 = func_L01_00326D78_003B7290(0x18AD);
    if (t1[1] != 0) {
        v1 = ((f32 (*)(void))t1[1])();
    } else {
        v1 = 0.0f;
    }
    v2 = 0.0f;
    t2 = func_L01_00326D78_003B7290(0x16E4);
    if (t2 != 0 && t2[1] != 0) {
        v2 = ((f32 (*)(void))t2[1])();
    }
    tbl = a1 + 0xF0;
    color = 0xFF;
    for (i = 0; i < count; i++) {
        u8 *obj;
        u8 *info;
        s32 s19;
        u8 *r21;
        u8 *r22;
        s32 x;

        obj = func_L01_003B64F0_003B7290(a1, f, v1, &idx);
        if (obj == 0) {
            *(s32 *)(a1 + 0x24) = 1;
            break;
        }
        info = *(u8 **)(obj + 0x68);
        if (idx < 0) {
            s19 = *(s32 *)(a1 + 0x124);
        } else {
            s19 = *(s32 *)(tbl + (idx << 2));
        }
        r21 = func_L01_003B6AB0_003B7290(a0, (s32 *)a1, (s32)obj, 0x18AD, t1);
        if (r21 == 0) {
            return;
        }
        if ((*(s32 *)(a1 + 0x28) != 0 && count >= 2) || s19 >= 0) {
            color = func_L01_003B69E0_003B7290((s32)a0, (s32)a1, (s32)r21, color, s19);
        }
        r22 = 0;
        if (*(s32 *)(info + 0x3C) != 0 && func_L01_003B64F0_003B7290(a1, 0.0f, v2, &idx2) != 0) {
            s32 s17;
            if (idx2 < 0) {
                s17 = *(s32 *)(a1 + 0x124);
            } else {
                s17 = *(s32 *)(tbl + (idx2 << 2));
            }
            r22 = func_L01_003B6AB0_003B7290(a0, (s32 *)a1, (s32)obj, 0x16E4, t2);
            if (r22 != 0) {
                if ((*(s32 *)(a1 + 0x28) != 0 && count >= 2) || s19 >= 0) {
                    color = func_L01_003B69E0_003B7290((s32)a0, (s32)a1, (s32)r22, color, s17);
                }
                func_L01_003B69A0_003B7290(a0, a1, (Obj_003B51A0 *)r22);
            }
        }
        *(s32 *)(a1 + 0x78) = 2;
        x = 0xFF;
        if (*(s32 *)(info + 0x4C) != 0) {
            x = ((s32 (*)(u8 *, u8 *, f32, s32, s32, s32))func_L01_003B6B68_003B7290)(a0, a1, 0.0f, 0x16BD, *(s32 *)(info + 0x4C), 0);
        }
        *(s32 *)(a1 + 0x78) = 0;
        ((void (*)(u8 *, u8 *, s32))t1[6])(r21, r22, x);
        func_L01_003B69A0_003B7290(a0, a1, (Obj_003B51A0 *)r21);
        ((void (*)(void *, u8 *, u8 *, s32, s32))func_L01_003B6A80_003B7290)(a0, a1, r21, 0, 0);
    }
}
/* localdecomp:end func_L01_003B7290 */

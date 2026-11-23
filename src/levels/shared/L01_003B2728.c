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

/* declared by functions of L01_003B2688.c, which this file was cut from */
extern u8 *D_L01_001E001C;
extern void func_L01_004450F0(s32, s32, s32);

/* localdecomp:start func_L01_003B2728 */
extern u8 *D_L01_001E001C;
extern f32 D_L01_001DF950;
extern s32 D_001A7430[];
extern s32 D_00142668[];
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L01_003B2DC8_003B2728(void);
extern s32 func_L01_00327408(void);
extern void func_L01_00456230(void *, s32);
extern void func_L01_003B2AA0(void *, void *);

typedef struct {
    u8 pad0[0x30];
    s32 (*fn30)(s32);
    s32 (*fn34)(void);
    u8 pad38[4];
    s32 (*fn3C)(s32);
} T_003B2728;
extern T_003B2728 *func_L01_0043B548(s32, s32);

typedef struct {
    u8 pad0[0x30];
    s32 w30;
    s32 w34;
    u8 pad38[4];
    s32 w3C;
    u8 pad40[0x50 - 0x40];
    u8 b50;
    u8 pad51[0x64 - 0x51];
    s32 w64;
} V_003B2728;
typedef struct {
    u8 pad0[0x30];
    u8 b30;
    u8 pad31[3];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_003B2728 *w68;
} M_003B2728;

void func_L01_003B2728(u8 *moby) {
    M_003B2728 *a0 = (M_003B2728 *)moby;
    V_003B2728 *v = a0->w68;
    T_003B2728 *t = func_L01_0043B548(0x19E1, 0x6C);
    s32 id;
    M_003B2728 *q;

    func_L01_003B2DC8_003B2728();
    if (v->w30 == 0) {
        D_001A7430[0] = D_00142668[0];
    }
    a0->h34 &= ~2;
    id = v->w30 == 0 ? -2 : v->b50 != 0 ? -3 : v->w34;
    if (t->fn30(id) == 0 && func_L01_00327408() == 0 && t->fn34() != 0) {
        D_L01_001DF950 = 2.0f;
        v->w64 = 0x11;
        func_L01_004450F0((s32)a0, 2, -1);
        return;
    }
    if (v->w3C != -1) {
        q = (M_003B2728 *)(D_L01_001E001C + (v->w3C << 8));
        q->b30 = 0xFF;
        q->h34 &= ~2;
        func_L01_00456230(q, 1);
        func_L01_004450F0((s32)a0, 4, -1);
        D_L01_001DF950 = 2.0f;
        return;
    }
    if (id != -3 && t->fn30(id) == 0) {
        if (t->fn3C(id) != 0) {
            D_L01_001DF950 = 2.0f;
            v->w64 = 0x11;
            func_L01_004450F0((s32)a0, 3, -1);
            return;
        }
    }
    func_L01_003B2AA0(a0, v);
}
/* localdecomp:end func_L01_003B2728 */

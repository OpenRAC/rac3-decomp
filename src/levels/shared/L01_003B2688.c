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

/* localdecomp:start func_L01_003B2688 */
extern u8 *D_L01_001E001C;
extern void func_L01_004450F0(s32, s32, s32);

typedef struct {
    s32 w0;
    u8 pad4[4];
    void *w8;
} V_003B2688;
typedef struct {
    u8 pad0[0x30];
    u8 b30;
    u8 pad31[0x68 - 0x31];
    V_003B2688 *w68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_003B2688;
typedef struct {
    u8 pad0[0x18];
    s32 w18;
    u8 pad1C[0x2C - 0x1C];
    f32 f2C;
    s32 w30;
} A_003B2688;

void func_L01_003B2688(void *arg0, void *arg1) {
    M_003B2688 *a0 = arg0;
    A_003B2688 *a1 = arg1;
    s32 idx;
    M_003B2688 *p;
    V_003B2688 *v;

    a0->b30 = 0xFF;
    idx = a1->w18;
    if (idx != -1) {
        p = (M_003B2688 *)(D_L01_001E001C + (idx << 8));
        for (;;) {
            if (p->hAA == 0x19E3) {
                v = p->w68;
                v->w8 = a0;
                p = (M_003B2688 *)(D_L01_001E001C + (v->w0 << 8));
                continue;
            }
            p->w68->w0 = (s32)a0;
            break;
        }
    }
    if (a1->w30 == 0) {
        if (a1->f2C == -8.0f) {
            a1->f2C = 0.0f;
        }
    }
    func_L01_004450F0((s32)a0, 1, -1);
}
/* localdecomp:end func_L01_003B2688 */

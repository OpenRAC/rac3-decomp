#include "common.h"

/* NTSC-U counterpart of func_L07_003AE410 (src/levels/07_annihilation_nation/L07_003ADF68.c): 0.00392 -> 0.00272222; 0.0048 -> 0.00333333; 0.24 -> 0.2; 0.00251327 -> 0.00174533; 0.125664 -> 0.10472 */
/* localdecomp:start func_L07_003ACBB8 */
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    f32 f34;
    u8 pad38[8];
    f32 f40;
    u8 pad44[0x18];
    f32 f5c;
    f32 f60;
    u8 pad64[0xB8];
    s32 f11c;
    f32 hp;
    s16 life;
    u8 pad126[14];
    u8 d0;
    u8 d1;
    u8 d2;
    u8 pad137[0x39];
    u8 b170;
    u8 b171;
    u8 b172;
    u8 pad173[0x35];
    u8 b1a8;
    u8 pad1a9[0x9B];
    void (*cb244)(int *);
    void (*cb248)(s32);
    s16 h24c;
    u8 pad24e[15];
    u8 b25d;
    u8 pad25e[1];
    u8 b25f;
} Vars_003AE410;

extern s32 func_L07_003C01A8(u8 *);
extern f32 func_L07_003C01F0(s32);
extern void func_L01_00442F20(void *, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
void func_L07_003AD480(int *);
void func_L07_003AD450(s32);

void func_L07_003ACBB8(u8 *m) {
    Vars_003AE410 *v = *(Vars_003AE410 **)(m + 0x68);
    s32 kind = func_L07_003C01A8(m);
    u8 *q = (u8 *)v + 0x120;
    f32 scale = func_L07_003C01F0(kind);

    *(s16 *)(q + 4) = v->life * scale;
    v->hp = *(s16 *)(q + 4);
    q[0x14] = v->d0 * scale;
    q[0x15] = v->d1 * scale;
    q[0x16] = v->d2 * scale;
    if (kind == 1 || kind == 3) {
        func_L01_00442F20(m, 0x1D88, 0x19D2);
    }
    q[0x28] = 20;
    *(f32 *)(q + 0x10) = 0.25f;
    q[9] = 0;
    q[0x2A] = 14;
    v->f11c = 0;
    v->b170 = 5;
    v->b1a8 = 255;
    v->b171 = 255;
    v->b172 = 255;
    v->f30 = 0.8f;
    v->f34 = -0.3f;
    v->f40 = 3.1415927f;
    v->f60 = 0.7853982f;
    v->f5c = 0.00272222236f;
    func_L01_00458A70(m, 0.00333333341f, 0.200000018f, 0.00174532935f, 0.104719765f);
    v->cb244 = func_L07_003AD480;
    v->cb248 = func_L07_003AD450;
    v->b25d = 6;
    v->h24c = -1;
    v->b25f = 7;
    func_L07_003AD450((s32)m);
}
/* localdecomp:end func_L07_003ACBB8 */

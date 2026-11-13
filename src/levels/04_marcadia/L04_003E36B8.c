#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003E36B8 */
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[0x94 - 0x70]; s32 i94; } G_3E36B8;
typedef int u128_t_3E36B8 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 D_001D5469;
extern s32 D_L04_001DF75C;
extern G_3E36B8 D_001CCFD0;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038A238(s32);
extern void func_L01_004ED658(s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_003A2B68(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L04_003E36B8(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    f32 v2[4];
    f32 w2[4];
    u8 *h;

    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    v[0] = func_0038D098(*(f32 *)(q + 0x14)) * 2.5f;
    v[1] = func_0038D0B0(*(f32 *)(q + 0x14)) * 2.5f;
    v[2] = 0.0f;
    vec_add_ab(v, v, q);
    qzero(w);
    w[2] = func_0038DAB8(*(f32 *)(q + 0x14), 3.1415927f);
    func_0038A238(8);
    h = D_001A4BE0;
    if (h[0x25E4] == 3) {
        func_L01_004ED658(0);
    }
    func_L01_004F50C8(v, w, 0x74, 0);
    v2[0] = func_0038D098(*(f32 *)(q + 0x14)) * 1.25f;
    v2[1] = func_0038D0B0(*(f32 *)(q + 0x14)) * 1.25f;
    v2[2] = 0.0f;
    v2[0] = v2[0] + func_0038D098(func_0038DAB8(*(f32 *)(q + 0x14), 1.5707964f)) * 4.0f;
    v2[1] = v2[1] + func_0038D0B0(func_0038DAB8(*(f32 *)(q + 0x14), 1.5707964f)) * 4.0f;
    vec_add_ab(v2, v2, q);
    v2[2] = v2[2] + 1.0f;
    qzero(w2);
    w2[2] = func_0038DB00(*(f32 *)(q + 0x14), 1.5707964f);
    func_L01_003EB438(0, v2, w2, 1, 0, 0);
    func_L01_003EB350(0, v2);
    func_L01_003EB3C0(0, w2);
    *(u128_t_3E36B8 *)(a0 + 0x10) = *(u128_t_3E36B8 *)(h + 0x80);
    *(u128_t_3E36B8 *)(a0 + 0xF0) = *(u128_t_3E36B8 *)(h + 0x90);
    if (a0[0x43] != 1) {
        func_003C3A10(a0, 1, 2, 0);
    }
    func_L01_0050FB40(0x66, 0, 0.0f);
    if (D_001D5469 != 0) {
        *(u16 *)(a0 + 0x34) |= 0x8000;
    }
    h[0x25F0] = 1;
    D_L04_001DF75C = 1;
    *(s16 *)(q + 0x18) = 0x32;
    if (D_001CCFD0.i6C == 0) {
        if (D_001CCFD0.i24 == -1 && D_001CCFD0.i94 == 0) {
            func_003A2B68(0xEB8, 0);
        }
    }
    func_L01_004450F0(a0, 2, -1);
}
/* localdecomp:end func_L04_003E36B8 */

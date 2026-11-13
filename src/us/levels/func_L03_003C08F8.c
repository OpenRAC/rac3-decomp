#include "common.h"

/* NTSC-U counterpart of func_L03_003C2718 (src/levels/03_starship_phoenix/L03_003C21A0.c): 8 -> 10; 50 -> 60 */
#include "vu0.h"

/* localdecomp:start func_L03_003C08F8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[6]; s16 h76; u8 pad78[0x94 - 0x78]; s32 i94; s16 h98; u8 pad9A[4]; s16 h9E; } G_003C2718;
extern u8 D_001A4BE0[];
extern u8 D_001D5469;
extern s32 D_L03_001DF35C;
extern G_003C2718 D_001CCFD0;
extern void func_003C26C8(void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_00385B60(s32);
extern void func_L01_004E9888(s32);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L01_003E94A0(s32, void *);
extern void func_L01_003E9510(s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_0050BB98(s32, s32, f32);
extern void func_0039DAE0(s32, s32);
extern void func_0039C710(void);
void func_L03_003C08F8(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    f32 v2[4];
    f32 w2[4];
    u8 *h;
    *(s32 *)(a0 + 0x98) = 0;
    func_003C26C8(a0);
    v[0] = func_00388960(*(f32 *)(q + 0x2C)) * 2.5f;
    v[1] = func_00388978(*(f32 *)(q + 0x2C)) * 2.5f;
    v[2] = 0.0f;
    vec_add_ab(v, v, q + 0x20);
    qzero(w);
    w[2] = func_00389380(*(f32 *)(q + 0x2C), 3.1415927f);
    func_00385B60(10);
    h = D_001A4BE0;
    if (h[0x25E4] == 3) {
        func_L01_004E9888(0);
    }
    func_L01_004F12C0(v, w, 0x74, 0);
    func_0039FE80(0, 0, a0);
    v2[0] = func_00388960(*(f32 *)(q + 0x2C)) * 1.25f;
    v2[1] = func_00388978(*(f32 *)(q + 0x2C)) * 1.25f;
    v2[2] = 0.0f;
    v2[0] = v2[0] + func_00388960(func_00389380(*(f32 *)(q + 0x2C), 1.5707964f)) * 4.0f;
    v2[1] = v2[1] + func_00388978(func_00389380(*(f32 *)(q + 0x2C), 1.5707964f)) * 4.0f;
    vec_add_ab(v2, v2, q + 0x20);
    v2[2] = v2[2] + 1.0f;
    qzero(w2);
    w2[2] = func_003893C8(*(f32 *)(q + 0x2C), 1.5707964f);
    func_L01_003E9588(0, v2, w2, 1, 0, 0);
    func_L01_003E94A0(0, v2);
    func_L01_003E9510(0, w2);
    *(u128_t *)(a0 + 0x10) = *(u128_t *)(h + 0x80);
    *(u128_t *)(a0 + 0xF0) = *(u128_t *)(h + 0x90);
    if (a0[0x43] != 1) {
        func_003BE4F0(a0, 1, 0, 0);
    }
    func_L01_0050BB98(0x66, 0, 0.0f);
    if (D_001D5469 != 0) {
        *(u16 *)(a0 + 0x34) |= 0x8000;
    }
    h[0x25F0] = 1;
    D_L03_001DF35C = 1;
    a0[0x20] = 2;
    *(s32 *)(q + 0x7C) = 0x3C;
    if (D_001CCFD0.i6C == 0) {
        if (D_001CCFD0.i24 == -1 && D_001CCFD0.i94 == 0) {
            func_0039DAE0(0xEB8, 0);
        }
    }
    if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
        func_0039C710();
    }
}
/* localdecomp:end func_L03_003C08F8 */

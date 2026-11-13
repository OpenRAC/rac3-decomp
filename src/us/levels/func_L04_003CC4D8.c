#include "common.h"

/* NTSC-U counterpart of func_L04_003CE348 (src/levels/04_marcadia/L04_003CD2C0.c): 0.00392 -> 0.00272222 */
extern void func_L04_003CC8F0(u8 *, s32, s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_L04_003CC4D8(u8 *a0);

/* localdecomp:start func_L04_003CC4D8 */
typedef int u128_3CE348 __attribute__((mode(TI)));

typedef struct S_3CE348 {
    u8 pad0[0x30];
    f32 f30;
    s16 f34;
    u8 pad36[0x2];
    u8 f38;
    u8 f39;
    u8 pad3A[0x6];
    f32 f40;
    u8 f44;
    u8 pad45[0x13];
    u8 f58;
    u8 pad59[0x1];
    u8 f5A;
    u8 pad5B[0x15];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x18];
    f32 f9C;
    f32 fA0;
    u8 padA4[0xCC];
    u8 f170;
    u8 f171;
    u8 f172;
    u8 pad173[0x3];
    u8 f176;
    u8 pad177[0x19];
    f32 f190;
    f32 f194;
    s16 f198;
    u8 pad19A[0x2];
    f32 f19C;
    u8 pad1A0[0x8];
    u8 f1A8;
    u8 pad1A9[0x2E];
    u8 f1D7;
    u8 f1D8;
    u8 f1D9;
    u8 f1DA;
    u8 f1DB;
    u8 pad1DC[0x64];
    s32 f240;
    u8 pad244[0xA];
    u8 f24E;
    u8 f24F;
    u8 pad250[0x80];
    u128_3CE348 f2D0;
    u8 pad2E0[0x10];
    s32 f2F0;
    s32 f2F4;
    s32 f2F8;
    u8 pad2FC[0x4];
    void * f300;
    s32 f304;
    s32 f308;
    s16 f30C;
    s16 f30E;
} S_3CE348;

extern void *func_003C24B0(s32 a0, s32 a1);
extern s32 func_L01_00452E70(void *a0, u8 *a1);
extern void (**func_L01_00438468(s32 a0, s32 a1))(u8 *);
extern void func_003C2880(u8 *a0);
extern void func_L04_003CC8F0(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_L01_00441FB8(u8 *a0, s32 a1, s32 a2);

s32 func_L04_003CC4D8(u8 *a0) {
    S_3CE348 *s1 = *(S_3CE348 **)(a0 + 0x68);
    s16 h34;
    u128_3CE348 position;
    void *p;
    void (**t)(u8 *);

    position = *(u128_3CE348 *)(a0 + 0x10);
    s1->f198 = 0;
    s1->f2D0 = position;
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
    h34 = s1->f34;
    s1->f1A8 = 255;
    s1->f190 = 0.5f;
    s1->f1D8 = 2;
    s1->f1DA = 0;
    s1->f1DB = 255;
    s1->f176 = 255;
    s1->f171 = 255;
    s1->f170 = 12;
    s1->f194 = 0.5f;
    s1->f19C = 0.15f;
    s1->f1D7 = 1;
    s1->f1D9 = 2;
    s1->f172 = 255;
    s1->f70 = 0.75f;
    s1->f74 = 0.2f;
    s1->f78 = 1.0f;
    s1->f7C = 1.75f;
    s1->f80 = 1.3089969f;
    s1->fA0 = 0.34906584f;
    s1->f9C = 0.00272222236f;
    s1->f58 = 20;
    s1->f5A = 14;

    if (h34 == 0 || s1->f30 <= 0.0f) {
        s1->f34 = 10;
        s1->f30 = 10.0f;
    }
    if (s1->f44 == 0) {
        s1->f44 = 1;
    }
    s1->f40 = 2.0f;
    s1->f38 = 1;
    s1->f39 = 1;
    if (s1->f300 == 0) {
        p = func_003C24B0(0x19C1, 0x80);
        s1->f300 = p;
        func_L01_00452E70(p, a0);
    }

    s1->f30C = (s1->f304 == -1);
    s1->f30E = (s1->f308 == -1);
    s1->f2F0 = 0;
    s1->f2F4 = 0;
    s1->f2F8 = 0;
    if (s1->f240 > 0) {
        t = func_L01_00438468(0x19E1, 0x6C);
        s1->f240 = -1;
        func_L04_003CC8F0(a0, 0, 0, 1);
        s1->f24E = 11;
        s1->f24F = 4;
        (*t)(a0);
        if (s1->f300 != 0) {
            func_003C2880(s1->f300);
            s1->f300 = 0;
        }
    } else {
        func_L01_00441FB8(a0, 3, 0);
        func_L04_003CC8F0(a0, 0, 0, 1);
    }
    return 0;
}
/* localdecomp:end func_L04_003CC4D8 */

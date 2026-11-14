#include "common.h"

/* NTSC-U counterpart of func_L40_003EC050 (src/levels/shared/L40_003EBB98.c) */
/* localdecomp:start func_L40_003EBBF8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003EC050;
typedef struct { u8 pad[0x128]; s32 w128; } G_003EC050;
extern G_003EC050 D_001A5E50;
extern void func_L39_00669B68(void *);
extern s32 func_L40_0053BEB0(s32 uid, void *pos, s32 a2, s32 a3);
extern s32 func_L39_005F0D88(s32, s32, void *, s32);
extern s32 func_L40_0053C768(void *);
extern void func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L40_003ECDC8(void *);
extern void func_L40_0053CE30(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L39_005F08F8(void *, s32);
extern u8 *func_L39_00669AC0(u8 *, void *);
extern f32 func_00388800(void *, void *);

void func_L40_003EBBF8(void *a, void *b) {
    u8 *m = b;
    u8 *v = *(u8 **)(m + 0x68);
    u8 *net = *(u8 **)(m + 0x90);
    u8 *n;
    s32 *e;
    s32 r;
    s32 t;
    V_003EC050 pos;

    if (v[0x3E] == 2) {
        func_L39_00669B68(a);
        func_L40_0053CE30(m);
        func_L01_00441FB8(m, 0x25, -1);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
        func_L39_005F08F8(m, 1);
        return;
    }
    for (n = *(u8 **)(net + 0x38); n != 0; ) {
        e = (s32 *)(n + 8);
        if (D_001A5E50.w128 < e[2]) {
            n = *(u8 **)(n + 0x84);
            continue;
        }
        switch (e[0]) {
        case 1:
            r = func_L40_0053BEB0(e[3], &pos, -1, 0);
            if (r != 0) {
                func_L39_005F0D88(3, 0, m, 0x109A);
                *(s32 *)(v + 0x230) = r;
                *(s32 *)(v + 0x2B4) = e[3];
            }
            break;
        case 2:
            if (func_L40_0053C768(m) == 0) {
                func_L01_0032FE90(m + 0x10, 0, 10, 4, 5, 5, 10, 0, 0.8f, 3.0f, 2.0f, 2.0f,
                                  0, 1, 0, 0, 1, 0, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                                  0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
            func_L40_003ECDC8(m);
        func_L40_0053CE30(m);
        func_L01_00441FB8(m, 0x25, -1);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
        func_L39_005F08F8(m, 1);
            return;
        }
        n = func_L39_00669AC0(n, net + 0x38);
    }
    if (*(s32 *)(v + 0x2B4) != 0) {
        *(s16 *)(v + 0x234) = 0;
        t = func_L40_0053BEB0(*(s32 *)(v + 0x2B4), v + 0x220, *(s32 *)(v + 0x2AC), 0);
        *(s32 *)(v + 0x230) = t;
        if (t != 0 && func_00388800(m + 0x10, v + 0x220) <= *(f32 *)(v + 0x244) + 5.0f &&
            func_00388800(m + 0x10, v + 0x2C0) < *(f32 *)(v + 0x244) * 3.0f) {
            *(s16 *)(v + 0x234) = 1;
        }
    }
}
/* localdecomp:end func_L40_003EBBF8 */

#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_00300930 */
typedef int U128_00300930 __attribute__((mode(TI)));
typedef union { U128_00300930 q; f32 f[4]; } Vec4_00300930;

extern s32 D_L03_001D6694_00300930;
extern s32 D_L03_001D673C;
typedef struct { u8 pad0[0x25C4]; s32 state; } Hero_00300930;
extern Hero_00300930 D_001A4BE0;
extern u8 D_001BBC40[];
extern u8 *D_001DFA1C_sda;
extern s32 D_001D545C_sda_00300930;
__asm__(".extern D_001D545C_sda_00300930, 4");

extern void func_L01_00438908(u8 *, s32, s32, s32);
extern void func_L03_003D7F00(s32);
extern void func_L03_003D8038(s32, void *);
extern void func_L01_0044E010(void *, void *, s32);
extern void func_L01_0044E358(void *, void *, s32);
extern void func_00388BD0(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern f32 func_00389380(f32, f32);
extern s32 func_L03_003F4470(void *, void *, void *, s32, s32);
extern s32 func_L01_004562A0(void *, s32, f32);
extern void func_L01_00402560_00300930(void (*)(void *), void *);
extern void func_L03_00300BF8(void *);
extern void func_L03_00300DA8(void *);

void func_L03_00300930(u8 *a0) {
    u8 *p;
    u8 *e;
    s32 t;
    u16 f;
    s32 id;
    s32 u;
    u8 *g;
    Vec4_00300930 v;
    f32 m[12];
    p = *(u8 **)(a0 + 0x68);
    if (D_L03_001D6694_00300930 == 2) {
        return;
    }
    switch (a0[0x20]) {
    case 0:
        f = *(u16 *)(a0 + 0x34) | 0x1000;
        *(u16 *)(a0 + 0x34) = f;
        if (*(s32 *)(p + 0x30) != -1 ||
            !((t = *(s32 *)(p + 0x3C)) == -1 || (e = D_001DFA1C_sda + t * 256) == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD)) {
            a0[0x30] = 0xFF;
            *(u16 *)(a0 + 0x34) = f | 0x41;
            a0[0x20] = 2;
        } else {
            func_L01_00438908(a0, 0xC0, 0xC0, 0xC0);
            func_L03_003D7F00(0);
            if (D_L03_001D673C != 0) {
                *(u16 *)(a0 + 0x34) |= 0x100;
                func_L01_0044E010(a0, &v, 1);
                func_L01_0044E358(a0 + 0xC0, &v, 0);
            }
            a0[0x20] = 1;
        }
        break;
    case 1:
        id = *(s16 *)(a0 + 0xAA);
        if (id == 0x323 || id == 0x19C4 || id == 0x2F6) {
            if (D_L03_001D673C != 0) {
                qzero(&v);
                v.f[2] = 0.0523598827f;
                func_00388BD0(m, &v);
                func_00388EB8(a0 + 0xC0, a0 + 0xC0, m);
            } else {
                *(f32 *)(a0 + 0xF8) = func_00389380(*(f32 *)(a0 + 0xF8), 0.0523598827f);
            }
        }
        if (D_001A4BE0.state != 0x2B) {
            func_L03_003D8038(0, a0);
        }
        break;
    case 2:
        if (D_001BBC40[*(s32 *)(p + 0x30) + D_001D545C_sda_00300930 * 16] != 0 ||
            ((u = *(s32 *)(p + 0x3C)) != -1 &&
             ((g = D_001DFA1C_sda + u * 256) == 0 || g[0x20] == 0xFE || g[0x20] == 0xFD))) {
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x1000) & 0xFFBE;
            func_L03_003F4470(a0, a0 + 0x10, a0 + 0xF0, 0, 0);
            *(s32 *)(p + 0x30) = -1;
            a0[0x20] = 0;
        }
        break;
    }
    v.q = *(U128_00300930 *)(a0 + 0x10);
    v.f[3] = 2.0f;
    if (func_L01_004562A0(&v, 0, 64.0f) > 0) {
        if (*(s16 *)(a0 + 0xAA) != 0x2F6) {
            func_L01_00402560_00300930(func_L03_00300BF8, a0);
        } else {
            func_L01_00402560_00300930(func_L03_00300DA8, a0);
        }
    }
}
/* localdecomp:end func_L03_00300930 */

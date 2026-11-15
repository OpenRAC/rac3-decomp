#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L24_003B7820.c, which this file was cut from */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* localdecomp:start func_L24_003B8278 */
#include "vu0.h"

typedef struct { s32 a; s32 b; } __attribute__((aligned(8))) V2_003B8278;

extern f32 D_L24_001DD578;
__asm__(".extern D_L24_001DD578, 16");
extern u8 *D_L24_0021EFD8[];
extern u8 D_001D66B0;
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L24_003B8878(void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);

void func_L24_003B8278(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *q;
    u8 **r;
    s32 i;
    u8 t;

    switch (a0[0x20]) {
    case 2:
        if (*(u8 **)(a0 + 0xB8) != 0) {
            if (func_0038CF38(a0 + 0x10, *(u8 **)(a0 + 0xB8) + 0x10) >= D_L24_001DD578) {
                *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            }
        }
        if (a0[0xBC] == 0) {
            a0[0xBC] = 0x56;
            *(V2_003B8278 *)p = *(V2_003B8278 *)(a0 + 0x38);
            ((V2_003B8278 *)p)->a = ((V2_003B8278 *)(a0 + 0x38))->a;
            ((V2_003B8278 *)p)->b = 0x15;
        }
        t = a0[0xBC];
        if (t % 50 >= 34 || t < 12) {
            func_L01_0043B9E8(a0, 200, 64, 64);
        } else {
            *(V2_003B8278 *)(a0 + 0x38) = *(V2_003B8278 *)p;
        }
        if (func_L01_00447490(a0, -1, 0) != 0 && a0[0xBC] >= 7) {
            a0[0xBC] = 6;
        }
        if (a0[0xBC] == 1) {
            *(V2_003B8278 *)(a0 + 0x38) = *(V2_003B8278 *)p;
            func_L01_003303B8(a0 + 0x10, 0, 0x1E, 0x19, 0x19, 0x19, 0x19, 3, 1.0f, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 1, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            *(f32 *)(a0 + 0x18) += 0.75f;
            a0[0x31] = 0;
            *(u16 *)(a0 + 0x34) |= 1;
            func_L01_004450F0(a0, 4, -1);
        }
        a0[0xA8] = 0xFF;
        a0[0xBC]--;
        break;
    case 4:
        if (func_0038CAD0(p + 4) != 0) {
            s32 k;
            q = *(u8 **)(a0 + 0xB8);
            if (*(s16 *)(q + 0xAA) == 0x1B5B) {
                r = (u8 **)(*(u8 **)(q + 0x68) + 0x910);
                for (k = 7; k >= 0; k--, r++) if (*r == a0) *r = 0;
            }
            q = *(u8 **)(a0 + 0xB8);
            if (*(s16 *)(q + 0xAA) == 0x1B97) {
                r = (u8 **)(*(u8 **)(q + 0x68) + 0x940);
                for (k = 7; k >= 0; k--, r++) if (*r == a0) *r = 0;
            }
            q = *(u8 **)(a0 + 0xB8);
            if (*(s16 *)(q + 0xAA) == 0x1B96) {
                r = (u8 **)(*(u8 **)(q + 0x68) + 0x130);
                for (k = 7; k >= 0; k--, r++) if (*r == a0) *r = 0;
            }
            q = *(u8 **)(a0 + 0xB8);
            if (*(s16 *)(q + 0xAA) == 0x1B9A) {
                r = (u8 **)(*(u8 **)(q + 0x68) + 0x170);
                for (k = 7; k >= 0; k--, r++) if (*r == a0) *r = 0;
            }
            func_003C2880(a0);
        } else {
            vu0_v4 v90;
            vu0_v4 vA0;
            vu0_v4 vB0;
            vu0_v4 vC0;
            f32 s;
            s32 j;
            u8 *part;

            i = 0;
            do {
                if (i == 0 || i == 1) *(u128_t *)&v90 = *(u128_t *)(a0 + 0xC0);
                else *(u128_t *)&v90 = *(u128_t *)(a0 + 0xD0);
                s = -1.0f;
                if (i & 1) s = 1.0f;
                func_0038CE20(&vA0, &v90, s);
                {
                s32 n2 = i + 1;
                func_0038CE20(&v90, &v90, *(f32 *)(p + 8) * s);
                vec_add_ba(&vB0, a0 + 0x10, &v90);
                vec_add_ab(&vA0, a0 + 0x10, &vA0);
                if (func_003D3CB0(a0 + 0x10, &vA0, 2, a0, 0) == 0) {
                    func_L24_003B8878(a0, a0 + 0x10, &vB0, 0x110000, 0, 1, 0, 10.0f, 2.5f);
                    for (j = 0; j < 30; j++) {
                        s32 n, m;
                        func_0038CDF8(&vC0, a0 + 0x10, &vB0, func_003824E0(0.0f, 1.0f));
                        n = (func_00382498(5, 10) * 5 + 2) / 6;
                        m = func_00382498(-1, -3);
                        part = func_L01_004713C8(&vC0, &D_001D66B0, n, 0x204080, m, 0x50, 0, 0,
                            168000.0f, func_003824E0(1.4f, 1.6f) * 210000.0f, -0.00040000002f);
                        if (part != 0) part[2] = D_L24_0021EFD8[0x68][func_00382498(0, 3)];
                    }
                }
                i = n2;
                }
            } while (i < 4);
        }
        break;
    }
}
/* localdecomp:end func_L24_003B8278 */

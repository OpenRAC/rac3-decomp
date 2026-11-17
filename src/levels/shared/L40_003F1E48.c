#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct Moby Moby;
typedef struct {
    u8 pad0[0x29C];
    s32 field_29C;
    u8 pad2A0[0x5C];
    s32 count;
    s32 field_300;
    s32 field_304;
    u8 pad308[8];
    Moby *items[1];
} Vars;
typedef struct {
    u8 pad0[0x354];
    s32 field_354;
    u8 pad358[8];
    Vec4 pos;
} VarsB;
struct Moby {
    u8 pad0[0x10];
    Vec4 pos;
    u8 field_20;
    u8 pad21[0x47];
    void *pVar;
};
typedef int u128_3F1460 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec4_003F1538;

/* localdecomp:start func_L40_003F1E48 */
extern s32 D_L40_0024112C;
extern u8 *func_L01_0045B958(u8 *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0045B6C8(u8 *, u8 *, f32);
extern void func_L40_003F1FA0(u8 *, u8 *, Vec4 *, Vec4 *);
extern void func_L01_0045B110(u8 *, u8 *, void *);
extern void func_L01_0045BB60(u8 *, u8 *, f32);
extern void func_L01_0045C240(void);

s32 func_L40_003F1E48(u8 *a0, void *a1, f32 a2) {
    u8 *s;
    Vec4 pos;
    Vec4 out;
    s32 flags;
    s32 t;
    s32 g;

    s = func_L01_0045B958(a0);
    if (func_0038CF38(a0 + 0x10, a1) < *(f32 *)(s + 0x34)) {
        return 0;
    }
    if (s == 0) {
        return 8;
    }
    g = D_L40_0024112C;
    if (g != *(s32 *)(s + 0xBC)) {
        flags = *(s32 *)(s + 0x38);
        *(s32 *)(s + 0x38) = flags | 4;
        *(s32 *)(s + 0xA8) = 0;
        *(s32 *)(s + 0x98) = *(s32 *)(s + 0x94);
        *(s32 *)(s + 0x94) = 0;
        pos = *(Vec4 *)(a0 + 0x10);
        t = *(s32 *)(s + 0xBC);
        if (g - t >= 2 || t == 0) {
            func_L01_0045B6C8(a0, s, 0.0f);
            *(f32 *)(s + 0xB4) = 0.0f;
            *(u8 *)(s + 0xEA) = 0xFF;
            *(s32 *)(s + 0x9C) &= ~2;
            *(s32 *)(s + 0x80) = 0;
        }
        *(s32 *)(s + 0xBC) = D_L40_0024112C;
        func_L40_003F1FA0(a0, s, &pos, &out);
        func_L01_0045B110(a0, s, a1);
        func_L01_0045BB60(a0, s, a2);
        func_L01_0045C240();
        *(s32 *)(s + 0x38) = flags;
    }
    return *(s32 *)(s + 0x94);
}
/* localdecomp:end func_L40_003F1E48 */

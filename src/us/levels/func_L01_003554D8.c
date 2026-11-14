#include "common.h"

/* NTSC-U counterpart of func_L01_00353EA0 (src/levels/01_veldin/L01_00353EA0.c) */
/* localdecomp:start func_L01_003554D8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { void (*f0)(void *); } V_3554D8;
extern u8 *D_L01_001E009C;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_00455F28(void *, void *, s32, void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern V_3554D8 *func_L01_00438468(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(void *, void *);

s32 func_L01_003554D8(u8 *o) {
    u8 *st;
    u8 *v;
    V_3554D8 *r;
    u8 *p;
    s32 t;
    s32 w;
    s16 h;

    st = *(u8 **)(o + 0x68);
    if (func_0037E1D8(2) != 0) {
        *(u16 *)(o + 0x34) |= 0x8000;
    }
    *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
    *(u128_t *)(st + 0x300) = *(u128_t *)(o + 0x10);
    *(u128_t *)(st + 0x320) = *(u128_t *)(o + 0x10);
    *(f32 *)(st + 0x318) = func_L01_00440918(0.0f, 20.0f) * 0.017453292f;
    func_L01_00455F28(o, st + 0x3F0, 0xC, st + 0x36C);
    st[0x1D7] = 1;
    st[0x170] = 0x1B;
    st[0x1A8] = 7;
    *(f32 *)(st + 0x190) = 0.5f;
    *(f32 *)(st + 0x194) = 0.5f;
    *(f32 *)(st + 0x19C) = 0.15f;
    if (func_0037E1D8(2) != 0) {
        st[0x1D3] = 0x11;
        st[0x1D2] = 0xB;
        st[0x176] = 0;
    } else {
        st[0x176] = 1;
        st[0x1D3] = 0x13;
        st[0x1D2] = 0xA;
    }
    *(f32 *)(st + 0x17C) = 0.25f;
    *(f32 *)(st + 0x180) = 0.016666668f;
    *(f32 *)(st + 0x184) = 0.0069444445f;
    *(f32 *)(st + 0x188) = 0.009722222574055195f;
    *(f32 *)(st + 0x18C) = 0.00055555557f;
    st[0x1DB] = 0xFF;
    st[0x1D8] = 0;
    st[0x1D9] = 0;
    st[0x1DA] = 0;
    *(f32 *)(st + 0x1A0) = *(f32 *)(o + 0x18) - 10.0f;
    *(f32 *)(st + 0x78) = 0.5f;
    *(f32 *)(st + 0x7C) = 1.0f;
    *(f32 *)(st + 0x210) = 1.0f;
    *(f32 *)(st + 0x70) = 0.45f;
    *(f32 *)(st + 0x74) = 0.25f;
    *(f32 *)(st + 0x80) = 1.3089969158172607f;
    *(f32 *)(st + 0xA0) = 0.3490658402442932f;
    *(f32 *)(st + 0x9C) = 0.0013888889f;
    func_L01_00458A70(o, 0.0022222223f, 0.083333336f, 0.0034906587f, 0.10471976548433304f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(f32 *)(st + 0x30) = 1.0f;
        *(s16 *)(st + 0x34) = 1;
    }
    *(f32 *)(st + 0x40) = 0.5f;
    st[0x38] = 0;
    st[0x39] = 1;
    st[0x3E] = 1;
    st[0x5E] = 0;
    st[0x5F] = 0;
    *(s32 *)(st + 0x2F0) = 0;
    *(s16 *)(st + 0x2F4) = 0;
    *(s32 *)(st + 0x2F8) = 0;
    *(s32 *)(st + 0x340) = 0;
    *(s32 *)(st + 0x35C) = 0;
    t = 0;
    w = *(s32 *)(st + 0x250);
    if (w > 0) {
        r = func_L01_00438468(0x19E1, 0x6C);
        *(s32 *)(st + 0x250) = -1;
        t = 1;
        if (o[0x43] != 5) {
            func_003BE4F0(o, 5, 0, 0);
        }
        st[0x25E] = 0x1A;
        st[0x25F] = 6;
        r->f0(o);
    } else if (*(s32 *)(st + 0x350) != 0) {
        func_L01_00441FB8(o, 0x18, 5);
        *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(o + 0x98) = 0;
        func_L01_004A6DF8(o, 1);
        p = *(u8 **)(st + 0x360);
        if (p != 0) {
            *(u16 *)(p + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(st + 0x360) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(st + 0x360) + 0x98) = 0;
            func_L01_004A6DF8(*(u8 **)(st + 0x360), 1);
        }
    } else {
        w = *(s32 *)(st + 0x344);
        if (w != -1) {
            v = D_L01_001E009C + (w << 8);
            h = *(s16 *)(v + 0xAA);
            if (h == 0x19B1 || h == 0x1AB4) {
                t = 1;
            }
            func_L01_00441FB8(o, 3, 0);
            if (o[0x43] != 5) {
                func_003BE4F0(o, 5, func_0037E208(0, 5), 0);
            }
        } else {
            func_L01_00441FB8(o, 7, 1);
            if (o[0x43] != 0x12) {
                func_003BE4F0(o, 0x12, func_0037E208(0, 10), 0);
            }
        }
    }
    if ((D_001D545C == 1 || D_001D545C == 0x60) && t == 0) {
        *(u8 **)(st + 0x360) = func_003BCFB0(0x1AA2, 0x80);
        func_L01_00452E70(*(u8 **)(st + 0x360), o);
        *(u8 **)(st + 0x240) = *(u8 **)(st + 0x360);
    }
    return 0;
}
/* localdecomp:end func_L01_003554D8 */

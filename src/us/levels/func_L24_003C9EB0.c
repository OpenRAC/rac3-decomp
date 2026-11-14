#include "common.h"

/* localdecomp:start func_L24_003C9EB0 */
typedef struct {
    s32 f00;
    f32 f04;
    f32 f08;
    f32 f0C;
    u8 *f10;
    s32 f14;
    s32 f18;
    s32 f1C;
} Sub_3C9EB0;

typedef struct {
    u8 pad_0[0x1A4];
    s32 f1A4;
} Hero_3C9EB0;

extern f32 D_001DEB90_sda;
__asm__(".extern D_001DEB90_sda, 4");
extern f32 D_001DEB8C_sda;
__asm__(".extern D_001DEB8C_sda, 4");
extern s32 D_001DEB88_sda[1];
__asm__(".extern D_001DEB88_sda, 4");
extern u32 D_001DEB80_sda[2];
__asm__(".extern D_001DEB80_sda, 8");
extern u32 D_001DEB78_sda[2];
__asm__(".extern D_001DEB78_sda, 8");
extern s32 D_L24_001DF0C0_003C9EB0;
__asm__(".extern D_L24_001DF0C0_003C9EB0, 16");
extern s32 D_001A4F3C[];
extern u8 D_001A4BE0[];
extern Hero_3C9EB0 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern void func_L24_003CA290();

extern f32 func_003BE7F0(void *, s32, s32, f32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(void *, void *);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_00388BD0(void *, void *);
extern void func_0013D3D0(s32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_L03_0043BF68(f32, s32, s32);
extern void func_003C26C8(void *);

void func_L24_003C9EB0(u8 *obj) {
    Sub_3C9EB0 *sub = *(Sub_3C9EB0 **)(obj + 0x68);
    u8 *hero;
    u8 *e;
    f32 ang;
    s32 r;
    s32 n;
    s32 c2;
    s32 w;
    s32 c1;
    s32 tA;
    s32 tB;
    s32 tC;
    s32 tD;

    switch (obj[0x20]) {
    case 0:
        *(f32 *)(obj + 0x18) = func_003BE7F0(obj + 0x10, 0, 0, 0.5f);
        if (sub->f1C != 0) {
            sub->f10 = func_003BCFB0(0x19E0, 0x80);
            if (sub->f10 != 0) {
                *(u16 *)(sub->f10 + 0x34) |= 0x10;
                func_L01_00452E70(sub->f10, obj);
                sub->f10[0x21] = obj[0x21];
            }
        }
        *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + (func_0037E250(0.0f, 0.5f) * 2.0f + 3.0f);
        *(f32 *)(obj + 0xF8) = *(f32 *)(obj + 0xF8) + (f32)func_0037E208(0, 0x5A) * 0.017453292f;
        func_00388BD0(obj + 0xC0, obj + 0xF0);
        sub->f0C = *(f32 *)(obj + 0x18);
        if (sub->f00 != 0) {
            func_0013D3D0(*(volatile s32 *)0x10000800);
            sub->f00 = func_0037E1D8(1);
            sub->f1C = 0;
        }
        *(s16 *)(obj + 0x7C) = 1 << D_001DEB88_sda[sub->f00];
        sub->f14 = D_001DEB78_sda[D_001DEB88_sda[sub->f00]];
        e = (u8 *)&D_001DEB78_sda[D_001DEB88_sda[sub->f00]];
        w = *(s32 *)e;
        c1 = e[1];
        c2 = e[2];
        tA = (u32)w >> 25;
        tA = tA << 24;
        tD = w & 0xFF;
        tD = tD >> 1;
        tB = c2 >> 1;
        tB = tB << 16;
        tC = c1 >> 1;
        tC = tC << 8;
        sub->f18 = tA | tB | tC | tD;
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        if (sub->f1C != 0 && sub->f10 != 0) {
            if (D_001A4F3C[0] != 0 && D_001A4F3C[0] == (s32)sub->f10) {
                if (D_001DEB80_sda[sub->f00] != 0) {
                    func_L01_0044F2E8(0, 0xD, 0x16FF, 1, 0, 0, 0);
                    if ((D_001D52FC->f1A4 & 0x10) != 0) {
                        func_L01_00441FB8(obj, 2, -1);
                    }
                }
            }
        }
        break;
    case 2:
        hero = D_001A4BE0;
        hero[0x25ED] = 1;
        *(s16 *)(hero + 0x1E0) = 5;
        func_L01_004026A0(func_L24_003CA290, obj);
        if ((D_001D52FC->f1A4 & 0x10) != 0 || *(u16 *)(obj + 0x96) >= 0x258) {
            func_L01_00441FB8(obj, 1, -1);
        }
        break;
    }
    func_L01_0044B860(obj, &sub->f04, &sub->f08, D_001DEB8C_sda, D_001DEB90_sda * 0.017453292f * 0.016666668f, sub->f0C);
    *(f32 *)(obj + 0xF8) = func_00389380(*(f32 *)(obj + 0xF8), 0.017453292f);
    *(u16 *)(obj + 0x96) = 0;
    if (obj[0x31] != 0) {
        n = 120;
        r = D_L24_001DF0C0_003C9EB0 % n;
        ang = (f32)r * 6.2831855f / (f32)n - 3.1415927f;
        *(s32 *)(obj + 0x78) = func_L03_0043BF68(ang, sub->f14, sub->f18);
        if (sub->f10 != 0) {
            *(s32 *)(sub->f10 + 0x78) = *(s32 *)(obj + 0x78);
            func_003C26C8(sub->f10);
        }
    }
    *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
}
/* localdecomp:end func_L24_003C9EB0 */

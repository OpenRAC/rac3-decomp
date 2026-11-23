#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00381140 */
extern void func_00397D48(s32, s32);

void func_00381140(void) {
    func_00397D48(0, 0);
}
/* localdecomp:end func_00381140 */

/* localdecomp:start func_00381160 */
extern void func_003BB7B0(s32);
extern void func_003B3228(void *);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern u8 D_001E22C0[];

void func_00381160(void) {
    func_003BB7B0(1);
    func_003B3228(D_001E22C0);
    func_003A0EC0(0x12, 1, 7, 0, 0);
}
/* localdecomp:end func_00381160 */

/* localdecomp:start func_003811A0 */
extern void func_003BB7B0(s32);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);

void func_003811A0(void) {
    func_003BB7B0(1);
    func_003A0EC0(0x12, 1, 8, 0, 0);
}
/* localdecomp:end func_003811A0 */

/* localdecomp:start func_003811D8 */
s32 func_003811D8(void) {
}
/* localdecomp:end func_003811D8 */

LINKER_REMNANT("asm/remnants", func_003811E0);

/* localdecomp:start func_003811E8 */
typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern Struct227600 D_00227580;
extern s32 D_001D5C78;
extern s32 D_00143950_003811E8[];
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003F2388(s32, s32);
extern void * func_003AF0B8();
extern void func_003AAE60(s32);
void func_003811E8(void) {
    func_0011A264(D_00227580.f84, 0xCD, 0x40000);
    D_001D5C78 = (s32)func_003AF0B8(func_003F2388(0x24F10, D_00227580.f84), 0x40000);
    func_003AAE60(D_00143950_003811E8[0]);
}
/* localdecomp:end func_003811E8 */

/* localdecomp:start func_00381250 */
typedef struct { u8 p0[4]; s32 f4; u8 p8[4]; s32 fC; u8 p10[0x14]; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; } S_1A1ED0_00381250;
typedef struct { u8 p0[0x18]; u8 *f18; u8 p1C[0x5C]; s32 f78; } S_227580_00381250;
typedef struct { u8 p0[7]; u8 f7; u8 p8[0x1C]; s32 f24; u8 p28[0x14]; s16 f3C; u8 p3E[2]; u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; u8 p48[6]; s16 f4E; u8 p50[0x1C]; s32 f6C; u8 p70[6]; s16 f76; u8 p78[0x44]; s32 fBC; u8 pC0[6]; s16 fC6; } S_1CCFD0_00381250;
typedef struct { u8 p0[0x18]; s32 f18; u8 p1C[0x14]; s32 f30; } S_16C580_00381250;
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x38]; s32 f688; s32 f68C; } S_160C40_00381250;
typedef struct { s32 f0; u8 p4[0xB3]; u8 fB7; } S_143950_00381250;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_00381250;
typedef struct { u8 p0[0x2C]; s32 f2C; } S_31CC80_00381250;
typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } S_pad_00381250;
typedef struct { s32 a; s32 b; } E_00381250;

extern S_1A1ED0_00381250 D_001A1ED0_00381250;
extern S_227580_00381250 D_00227580_00381250;
extern S_1CCFD0_00381250 D_001CCFD0_00381250;
extern S_16C580_00381250 D_0016C580_00381250;
extern S_160C40_00381250 D_00160C40_00381250;
extern S_143950_00381250 D_00143950_00381250;
extern S_142430_00381250 D_00142430_00381250;
extern S_31CC80_00381250 D_0031CC80_00381250;
extern u8 D_001D5BDC;
extern s32 D_001D4BB4;
extern s32 D_001D4BB0;
extern s32 D_001D4B64;
extern s32 D_001D4B60;
extern s32 D_001D4B90;
extern s32 D_001D4BA0;
extern s32 D_001D4B4C;
extern s32 D_001A7430[];
extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D5B8C;
extern s32 D_001D9D08;
extern s32 D_001D9BC8;
extern s32 D_001D5B9C;
extern s32 D_001D9D2C;
extern u8 D_0031CCD0[];
extern void *D_001D99A0;
extern s32 D_001D5B74;
extern unsigned long D_001D4AC0;
extern s32 D_001D5750;
extern s32 D_001D574C;
extern s32 D_001D5738[2];
extern E_00381250 D_001D5758_00381250[1];
extern S_pad_00381250 *D_001D52FC_00381250;
extern s32 D_001D5680;
extern s32 D_001D5684;
extern s32 D_001D5688;
extern s32 D_001D568C;
extern s32 D_001D5690;
extern s32 D_001D5694;
extern s32 D_00227400[];
extern s32 D_001D4D40;
extern s32 D_00142BA4[];
extern s32 D_001D9D04;
extern f32 D_001D9D0C;
extern u8 D_001D5570[8];

/* Ps2EeAs reaches these through $gp only if it knows their size before the use. */
__asm__(".extern D_001D5750, 4");
__asm__(".extern D_001D574C, 4");
__asm__(".extern D_001D5738, 8");
__asm__(".extern D_001D5758_00381250, 8");
__asm__(".extern D_001D5680, 4");
__asm__(".extern D_001D5684, 4");
__asm__(".extern D_001D5688, 4");
__asm__(".extern D_001D568C, 4");
__asm__(".extern D_001D5690, 4");

extern void func_003A8630(void);
extern void func_003A1330(void);
extern void func_003A9050(void);
extern void func_00397EA8(void);
extern void func_00387268(void);
extern void func_003A9108(void);
extern void func_003A9A40(void);
extern void func_0039A6E0(void);
extern s32 func_003A2598(s32, s32, s32);
extern void func_00392260(s32, long, long);
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_00387F68(void);
extern s32 func_12C908(s32);
extern void func_00392290(void);
extern s32 func_003A2750(s32);
extern void func_003A0760(u8 *, u32);
extern void func_003A11F0(s32 a, s32 idx);
extern void func_00398E50(void);
extern void func_003A0D48(void);
extern void func_003811E8(void);
extern s32 func_003B2E50(void);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern void func_00381080(void);
extern void func_003A3B70(void);
extern void func_00381D88(void);
extern s32 func_13D3C8(void);
extern void func_13D3C0(s32);
extern s32 func_00392B20();
extern s32 func_00392C78();
extern void func_0038E150(s32);
extern void func_003B3050(void);
extern void func_003B3088();
extern long func_003A9830(s32 src, s32 dst, s32 w, s32 h);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_003BB0B0(void);
extern s32 func_003E8528(s32, s32 *);
extern s32 func_003E6FE8();
extern s32 func_003E84B0(s32);
extern void *func_003B4FD0();
extern void func_003E6FE0(void *);
extern s32 func_003E8440(s32 arg0);
extern s32 func_003A4288_00381250(void);
extern void func_003A9440(s32, unsigned long);
extern void func_00389240(s32);
extern void func_003B30E8(void);
extern void func_003B3158(s32);
extern void func_003B3120(void);
extern s32 func_00381FF0(s32);
extern void func_0038E7E8_00381250(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
extern void func_00389370(void);
extern void func_003A8B10(void);
extern void func_003A1F30();
extern void func_003B3910(void);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern void func_003A92F0(s32);
extern void func_00388138(void);
extern void func_003A78B8(void);

void func_00381250(void) {
    u8 *img;
    u8 *dst;
    u8 *lang;
    u8 *heap;
    s32 *p;
    s32 i;
    s32 state;
    s32 idx;
    s32 cnt;
    s32 mode;
    s32 handle;

    D_001D5BDC = 1;
    func_003A8630();
    func_003A1330();
    func_003A9050();
    func_00397EA8();

    D_001D4BB0 = D_001A1ED0_00381250.fC;
    D_001D4BB4 = D_001A1ED0_00381250.fC;
    D_001A1ED0_00381250.f28 = 0x60000;
    D_001A1ED0_00381250.f2C = 0x70000;
    D_001A1ED0_00381250.f30 = 0xB0000;
    D_001A1ED0_00381250.f34 = 0xF0000;
    D_001A1ED0_00381250.f38 = 0x160000;
    D_001A1ED0_00381250.f3C = 0x1D0000;
    D_001A1ED0_00381250.f24 = 0;
    D_001D4BA0 = D_001D4B90 = D_001D4B60 = -1;
    D_0016C580_00381250.f30 = -1;
    D_001D4B64 = D_00227580_00381250.f78;
    D_0016C580_00381250.f18 = -1;
    D_001CCFD0_00381250.f24 = -1;
    D_001CCFD0_00381250.f3C = -1;
    D_001CCFD0_00381250.f41 = 0;
    D_001CCFD0_00381250.f42 = 0;
    D_001CCFD0_00381250.f43 = 0;
    D_001CCFD0_00381250.f44 = 0;
    D_001CCFD0_00381250.f4E = 0;
    D_001CCFD0_00381250.f6C = 0;
    D_001CCFD0_00381250.f76 = 0;
    D_001CCFD0_00381250.fBC = 0;
    D_001CCFD0_00381250.fC6 = 0;
    D_001A1ED0_00381250.f40 = 0x1E0000;
    D_001CCFD0_00381250.f40 = 0x20;
    func_00387268();
    func_003A9108();
    func_003A9A40();
    func_0039A6E0();

    img = D_00227580_00381250.f18 + 0x400000;
    func_003A2598((s32)img, D_00160C40_00381250.f688 + D_00160C40_00381250.f64C, D_00160C40_00381250.f68C);
    dst = img + 0x200000;
    func_00392260(0, 0, 0);
    func_003922B8();
    func_00392350(0);
    func_00387F68();
    D_001A7430[0] = 1;
    D_001CCFD0_00381250.f7 = 0;
    D_001D5B90 = -2;
    D_001D5B94 = 0;
    D_001D5B8C = 0;
    D_001D9D08 = 0;
    D_001D9BC8 = 0;
    func_12C908(0);
    func_00392290();
    D_001D9BC8 = 0;
    func_12C908(0);
    func_00392290();
    func_003A2750(1);
    func_003A0760(img + *(s32 *)(img + 0x60), (u32)dst);
    func_003A11F0((s32)dst, 0);
    lang = img + *(s32 *)(img + 0x58);
    D_001D5B9C = 0x13;
    D_001D9D2C = (s32)D_0031CCD0;
    dst += 0x32000;
    func_003A0760(lang, (u32)dst);
    p = (s32 *)(img + 0x28);
    for (i = 5; i >= 0; i--) {
        *p -= 0x10;
        p += 2;
    }
    /* D_001D4B50, as the word after D_001D4B4C: a declared scalar goes into the jal's delay slot */
    (&D_001D4B4C)[1] = (s32)(img + 0x10);
    func_00398E50();

    lang = 0;
    switch (D_00143950_00381250.fB7) {
    case 0:
    case 1:
        lang = img + *(s32 *)(img + 0x00);
        break;
    case 2:
        lang = img + *(s32 *)(img + 0x08);
        break;
    case 3:
        lang = img + *(s32 *)(img + 0x10);
        break;
    case 4:
        lang = img + *(s32 *)(img + 0x18);
        break;
    case 5:
        lang = img + *(s32 *)(img + 0x20);
        break;
    }
    func_003A0760(lang, (u32)D_00227580_00381250.f18);

    heap = D_00227580_00381250.f18;
    D_0031CC80_00381250.f2C = *(u32 *)heap >> 4;
    D_001D99A0 = heap;
    for (i = 0; i < D_0031CC80_00381250.f2C; i++) {
        *(s32 *)(heap + i * 16) += (s32)heap;
    }
    func_003A0D48();
    func_003811E8();
    func_003B2E50();

    while (D_001D5B74 == 0) {
        D_001D4AC0 += *(volatile u32 *)0x10000800;
        *(volatile u32 *)0x10000800 = 0;
        func_003A91D0();
        func_003A9150();
        func_003923D0();
        func_00392748(1);
        func_00381080();
        func_003922B8();
        func_00392350(0);
        state = D_001D5B94;
        handle = 0;
        D_001D4BB0 = D_001A1ED0_00381250.fC;
        switch (state + 1) {
        case 0:
        case 1:
            func_003A3B70();
            if (D_001D5750 >= 0) {
                if (D_001D5750 > 0 && (D_001D52FC_00381250->f1A4 & 4)) {
                    D_001D5750--;
                } else {
                    idx = D_001D5750 + 1;
                    if (D_001D5758_00381250[idx].a > 0 && (D_001D52FC_00381250->f1A4 & 8)) {
                        D_001D5750 = idx;
                    }
                }
            } else {
                if ((D_001D52FC_00381250->f1A0 & 0x600) != 0x600) {
                    D_001D574C = 0;
                } else if (D_001D52FC_00381250->f1A4 != 0) {
                    if ((D_001D52FC_00381250->f1A4 & D_001D5738[D_001D574C]) == D_001D5738[D_001D574C]) {
                        D_001D574C++;
                        if (D_001D5738[D_001D574C] == -1) {
                            D_001D5750 = 0;
                        }
                    } else {
                        D_001D574C = 0;
                    }
                }
            }
            if (D_001D52FC_00381250->f1A0 != 0 || D_00142430_00381250.f15C >= 3 || D_00142430_00381250.f164 >= 0) {
                D_001D5688 = 0;
            }
            if (D_001D568C != 0) {
                func_00381D88();
            } else {
                cnt = D_001D5680;
                if (cnt < 0) {
                    cnt = 0;
                }
                D_001D5680 = --cnt;
                if (cnt <= 0 && (D_001D52FC_00381250->f1A0 & 0xF) == 0xF) {
                    D_001D568C = 1;
                    D_001D5690 = 9;
                    D_001D5680 = 0;
                    D_001D5694 = 0;
                } else {
                    if (func_13D3C8() == 7) {
                        func_13D3C0(5);
                        D_001D4D40 = 1;
                        D_00227400[0] = 1;
                        func_00392B20(D_00227400, 0);
                        func_00392C78(D_00227400);
                        func_13D3C0(9);
                        D_001D5688 = 0;
                    } else if (D_001D5688++ > 6000) {
                        if (func_13D3C8() == 0) {
                            func_13D3C0(5);
                        }
                    }
                    mode = func_13D3C8();
                    func_0038E150(0);
                    func_003B3050();
                    func_003B3088(0);
                    switch (mode) {
                    case 0:
                        func_003A9830((s32)(dst + 0x10), D_001A1ED0_00381250.f4, 0x200, 0x1A0);
                        func_0038AE20(0, 0, 0, 0x60);
                        break;
                    case 1:
                        func_13D3C0(2);
                        break;
                    case 3: {
                        unsigned long t = D_00142BA4[0];
                        if (!((t >> 6) & 1)) {
                            break;
                        }
                    }
                    case 2:
                        func_13D3C0(4);
                        break;
                    case 4:
                        D_001D5B74 = 1;
                        D_001D9D04 = 1;
                        func_13D3C0(0);
                        break;
                    case 5:
                        func_003BB0B0();
                        func_13D3C0(6);
                        break;
                    case 6:
                        func_003A9830((s32)(dst + 0x10), D_001A1ED0_00381250.f4, 0x200, 0x1A0);
                        func_0038AE20(0, 0, 0, 0x60);
                        func_003E8528(D_001D5684, &handle);
                        if (handle == 0 || func_003E6FE8(handle) == 0) {
                            func_13D3C0(7);
                        }
                        break;
                    case 7:
                        break;
                    case 10:
                        func_003E8528(D_001D5684, &handle);
                        if (handle != 0 && func_003E6FE8(handle) != 0) {
                            func_003E84B0(D_001D5684);
                        }
                        func_13D3C0(8);
                        break;
                    case 8:
                        func_003E8528(D_001D5684, &handle);
                        if (handle == 0 || func_003E6FE8(handle) == 0) {
                            func_003E6FE0(func_003B4FD0());
                            D_001D5684 = func_003E8440((s32)func_003B4FD0());
                            func_13D3C0(0);
                        }
                        D_001D5688 = 0;
                        break;
                    case 9:
                        D_001D5688 = 0;
                        func_13D3C0(10);
                        break;
                    }
                }
            }
            func_003A4288_00381250();
            if (D_001D568C == 0 || D_001D5690 != 9) {
                func_00387F68();
                func_003A9440(0x47, 0x33001);
                func_00389240(0);
                func_003B30E8();
                func_003B3158(0);
                func_003B3120();
                if (D_001D5750 >= 0) {
                    f32 sz = 32.0f;
                    s32 tex = func_00381FF0(D_001D5758_00381250[D_001D5750].b);
                    func_0038E7E8_00381250(sz, sz, 1.0f, 0x80808080, tex, -1, 1.0f, 0, 0, 0x80000000, 0.0f, 0.0f);
                }
                func_00389370();
            }
            break;
        case 2:
            func_003A8B10();
            break;
        case 4:
        case 5:
        case 19:
            func_003A3B70();
            func_003A2750(0);
            func_003A1F30();
            func_003B3910();
            break;
        }

        D_001D9D08++;
        func_003A4288_00381250();
        func_0039C410();
        func_0039ADE0();
        func_003A92F0(1);
        D_001D9D0C = (f32)*(volatile u32 *)0x10000800 / (D_00143950_00381250.f0 != 0 ? 11520.0f : 9600.0f);
        func_00388138();
        func_003A0D48();
        if (D_001D5B94 != state) {
            D_001D9D08 = 0;
        }
        D_001D9BC8++;
        func_12C908(0);
    }

    if (D_001D5750 >= 0) {
        s32 n = D_001D5758_00381250[D_001D5750].a;
        if (D_001D5570[n] != 0) {
            D_001D9D04 = n;
        }
    }
    func_003A78B8();
}
/* localdecomp:end func_00381250 */

extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003F2388(s32, s32);
extern void * func_003AF0B8();
extern s32 D_001D5C78;
extern Struct227600 D_00227580;
extern s32 D_00227580_0037D1A8[];
extern s32 D_001D5C78_0037D1A8[];
extern void func_11A264(s32, s32, s32);
extern s32 func_003F2388(s32, s32);
extern void * func_003AF0B8();
typedef struct { u8 p0[4]; s32 f4; u8 p8[4]; s32 fC; u8 p10[0x14]; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; } S_1A1ED0_37D200;
typedef struct { u8 p0[0x18]; u8 *f18; u8 p1C[0x5C]; s32 f78; } S_227600_37D200;
typedef struct { u8 p0[7]; u8 f7; u8 p8[0x1C]; s32 f24; u8 p28[0x14]; s16 f3C; u8 p3E[2]; u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; u8 p48[6]; s16 f4E; u8 p50[0x1C]; s32 f6C; u8 p70[6]; s16 f76; u8 p78[0x44]; s32 fBC; u8 pC0[6]; s16 fC6; } S_1CCFD0_37D200;
typedef struct { u8 p0[0x18]; s32 f18; u8 p1C[0x14]; s32 f30; } S_16C580_37D200;
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x38]; s32 f688; s32 f68C; } S_160C40_37D200;
typedef struct { s32 f0; u8 p4[0xB3]; u8 fB7; } S_143950_37D200;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_37D200;
typedef struct { u8 p0[0x2C]; s32 f2C; } S_318CC0_37D200;
typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } S_pad_37D200;
typedef struct { s32 a; s32 b; } E_37D200;
typedef struct { s32 off; s32 size; } H_37D200;
extern S_1A1ED0_37D200 D_001A1ED0;
extern S_227600_37D200 D_00227580_0037D200;
extern S_1CCFD0_37D200 D_001CCFD0;
extern S_16C580_37D200 D_0016C580;
extern S_160C40_37D200 D_00160C40;
extern S_143950_37D200 D_00143950;
extern S_142430_37D200 D_00142430;
extern S_318CC0_37D200 D_0031CC80_0037D200;
extern u8 D_001D5BDC;
extern s32 D_001D4BB4;
extern s32 D_001D4BB0;
extern s32 D_001D4B64;
extern s32 D_001D4B60;
extern s32 D_001D4B90;
extern s32 D_001D4BA0;
extern void *D_001D4B50;
extern s32 D_001A7430[];
extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D5B8C;
extern s32 D_001D9D08;
extern s32 D_001D9BC8;
extern s32 D_001D5B9C;
extern s32 D_001D9D2C;
extern u8 D_0031CCD0[];
extern void *D_001D99A0;
extern s32 D_001D5B74;
extern unsigned long D_001D4AC0;
extern s32 D_001D5750;
extern s32 D_001D574C;
extern E_37D200 D_001D5758[1];
extern s32 D_001D575C[2];
extern s32 D_001D5738[2];
extern void *D_001D52FC;
extern s32 D_001D5680;
extern s32 D_001D5684;
extern s32 D_001D5688;
extern s32 D_001D568C;
extern s32 D_001D5690;
extern s32 D_001D5694;
extern s32 D_00227400[];
extern s32 D_001D4D40;
extern s32 D_00142BA4[];
extern s32 D_001D9D04;
extern f32 D_001D9D0C;
extern u8 D_001D5570[8];
extern void func_003A8630(void);
extern void func_003A1330(void);
extern void func_003A9050(void);
extern void func_00397EA8(void);
extern void func_00387268(void);
extern void func_003A9108(void);
extern void func_003A9A40(void);
extern void func_0039A6E0(void);
extern s32 func_003A2598(s32, s32, s32);
extern void func_00392260(s32, long, long);
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_00387F68(void);
extern s32 func_12C908(s32);
extern void func_00392290(void);
extern s32 func_003A2750(s32);
extern void func_003A0760(u8 *, u32);
extern void func_003A11F0(s32 a, s32 idx);
extern void func_00398E50(void);
extern void func_003A0D48(void);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern void func_003A3B70(void);
extern void func_00381D88(void);
extern s32 func_13D3C8(void);
extern void func_13D3C0(s32);
extern s32 func_00392B20();
extern s32 func_00392C78();
extern void func_0038E150(s32);
extern void func_003B3050(void);
extern void func_003B3088();
extern void func_003A9830_0037D200(u8 *, s32, s32, s32);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_003BB0B0(void);
extern s32 func_003E8528(s32 arg0, s32 *arg1);
extern s32 func_003E6FE8();
extern s32 func_003E84B0(s32 a);
extern void *func_003B4FD0();
extern void func_003E6FE0(void *);
extern s32 func_003E8440(s32 arg0);
extern void func_003A9440(s32, unsigned long);
extern void func_00389240(s32);
extern void func_003B30E8(void);
extern void func_003B3158(s32);
extern void func_003B3120(void);
extern s32 func_00381FF0(s32);
extern void func_0038E7E8_0037D200(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
extern void func_00389370(void);
extern void func_003A8B10(void);
extern void func_003A1F30();
extern void func_003B3910(void);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern void func_003A92F0(s32);
extern void func_00388138(void);

/* localdecomp:start func_00381C88 */
s32 func_00381C88(void) {
    return 0;
}
/* localdecomp:end func_00381C88 */

/* localdecomp:start func_00381C90 */
s32 func_00381C90(void) {
}
/* localdecomp:end func_00381C90 */

/* localdecomp:start func_00381C98 */
s32 func_00381C98(void) {
}
/* localdecomp:end func_00381C98 */

/* localdecomp:start func_00381CA0 */
s32 func_00381CA0(void) {
}
/* localdecomp:end func_00381CA0 */

/* localdecomp:start func_00381CA8 */
s32 func_00381CA8(void) {
}
/* localdecomp:end func_00381CA8 */

/* localdecomp:start func_00381CB0 */
extern u8 D_001427AB[];
u8 func_00381CB0(void) {
    return D_001427AB[0];
}
/* localdecomp:end func_00381CB0 */

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
/* localdecomp:start func_00381CC0 */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
__asm__(".extern D_001D9898, 4");
__asm__(".extern D_001D9880, 8");
extern s32 D_001D9898;
extern s32 D_001D9880[2];
s32 *func_00381CC0(void) {
    if (D_001D9898 == 0) {
        func_003E6FA0(D_001D9880, 0, 0, 0, 0, 0);
        D_001D9898 = 1;
    }
    return D_001D9880;
}
/* localdecomp:end func_00381CC0 */

/* localdecomp:start func_00381D08 */
extern s32 * func_00381CC0();
void func_00381D08(void) {
    func_00381CC0();
}
/* localdecomp:end func_00381D08 */

LINKER_REMNANT("asm/remnants", func_00381D28);

/* localdecomp:start func_00381D30 */
s32 func_00381D30(void) {
}
/* localdecomp:end func_00381D30 */

/* localdecomp:start func_00381D38 */
s32 func_00381D38(void) {
}
/* localdecomp:end func_00381D38 */

/* localdecomp:start func_00381D40 */
s32 func_00381D40(void) {
}
/* localdecomp:end func_00381D40 */

/* localdecomp:start func_00381D48 */
s32 func_00381D48(void) {
    return 0;
}
/* localdecomp:end func_00381D48 */

/* localdecomp:start func_00381D50 */
s32 func_00381D50(void) {
    return 0;
}
/* localdecomp:end func_00381D50 */

/* localdecomp:start func_00381D58 */
s32 func_00381D58(void) {
}
/* localdecomp:end func_00381D58 */

/* localdecomp:start func_00381D60 */
s32 func_00381D60(void) {
}
/* localdecomp:end func_00381D60 */

/* localdecomp:start func_00381D68 */
s32 func_00381D68(void) {
}
/* localdecomp:end func_00381D68 */

/* localdecomp:start func_00381D70 */
s32 func_00381D70(void) {
}
/* localdecomp:end func_00381D70 */

/* localdecomp:start func_00381D78 */
s32 func_00381D78(void) {
    return 0;
}
/* localdecomp:end func_00381D78 */

/* localdecomp:start func_00381D80 */
s32 func_00381D80(void) {
    return 1;
}
/* localdecomp:end func_00381D80 */

typedef struct { u8 p0[0xAD]; u8 bAD; } S_143950_37DD30;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; } S_142430_37DD30;
extern S_143950_37DD30 D_00143950_00381D88;
extern S_142430_37DD30 D_00142430_00381D88;
extern s32 D_001D568C;
extern s32 D_001D5690;
extern s32 D_001D5694;
extern s32 D_00227400[];
extern s32 D_001D4D40;
extern void func_0038E150(s32);
extern void func_13D3C0(s32);
extern s32 func_00392B20();
extern s32 func_00392C78();
extern s32 func_00381FF0(s32);
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
/* localdecomp:start func_00381D88 */
__asm__(".extern D_001D568C, 4");
__asm__(".extern D_001D5690, 4");
__asm__(".extern D_001D5694, 4");
extern void func_003820C8(void);
extern void func_0038FA18(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_00381D88(void) {
    s16 buf[16];
    s32 x;
    if (D_001D5694 < 0x4B) x = (D_001D5694 - 0xC) * 0xE0 / 0x19;
    else x = (0x8A - D_001D5694) * 0xE0 / 0x19;
    if (x < 0) x = 0;
    if (x > 0xE0) x = 0xE0;
    D_001D5694++;
    x = (x | (((x << 16) | 0x80000000) | (x << 8)));
    func_0038E150(1);
    switch (D_001D5690) {
    case 7:
        D_001D4D40 = 0;
        if (D_00143950_00381D88.bAD != 0) func_00392B20(D_00227400, 0x1D);
        else func_00392B20(D_00227400, 0x1F);
        D_00227400[0] = 4;
        func_00392C78(D_00227400);
        D_001D5694 = 0;
        D_001D5690 = 8;
        break;
    case 8:
        D_001D568C = 0;
        func_13D3C0(10);
        if (D_00142430_00381D88.f15C == 2 && D_00142430_00381D88.f164 < 0) {
            D_00142430_00381D88.f168 = 0;
            D_00142430_00381D88.f164 = 0x18;
        }
        break;
    case 9:
        D_001D568C = 1;
        func_003910C0(buf, 0, 0x1E0, 0x20, 0x1E0, 0x100, 0xC8, 0x10, 3);
        ((void (*)(s16 *, s32, s32, s32, unsigned long, f32, f32))func_0038FA18)(buf, x, func_00381FF0(0x1700), -1, 0x80000000UL, 1.0f, 1.0f);
        if (D_001D5694 >= 0x97) func_003820C8();
        break;
    }
}
/* localdecomp:end func_00381D88 */

LINKER_REMNANT("asm/remnants", func_00381F78);

extern void *D_001D99A0;
typedef struct { u8 pad0[0x2C]; s32 f2C; } S_00318CC0_0037DF28;
extern S_00318CC0_0037DF28 D_0031CC80[];
/* localdecomp:start func_00381F80 */
__asm__(".extern D_001D99A0, 16");
typedef struct { s32 unk00; s32 key; s32 unk08; s32 unk0C; } SelectorEntry_00381F80;

s32 func_00381F80(s32 key)
{
    s32 found = -1;
    s32 i;
    for (i = 0; i < D_0031CC80[0].f2C; i++) {
        if (((SelectorEntry_00381F80 *)D_001D99A0)[i].key == key) {
            found = i;
            break;
        }
    }
    return found;
}
/* localdecomp:end func_00381F80 */

extern s32 func_00381F80(s32);
/* localdecomp:start func_00381FF0 */
extern u8 D_001D5788;
__asm__(".extern D_001D5788, 1");
s32 func_00381FF0(s32 key) {
    s32 i = func_00381F80(key);
    if (i >= 0) {
        return ((SelectorEntry_00381F80 *)D_001D99A0)[i].unk00;
    }
    return (s32)&D_001D5788;
}
/* localdecomp:end func_00381FF0 */

/* localdecomp:start func_00382030 */
__asm__(".extern D_001D99A0, 16");
__asm__(".extern D_001D52FC, 16");
extern void *D_001D52FC;
s32 func_00382030(fallback)
s32 fallback;
{
    s32 index = func_00381F80(fallback);
    register s32 value __asm__("$4") = *(s16 *)((u8 *)D_001D99A0 + (index * 0x10) + 0xC);
    register s32 result __asm__("$2") = fallback;
    if (value > 0) {
        register u8 flag __asm__("$3");
        result = (s32)D_001D52FC;
        flag = *(volatile u8 *)(result + 0x550);
        result = value;
        __asm__ volatile("" : "+r"(result));
        if (flag == 0) {
            result = fallback;
        }
    }
    return result;
}
/* localdecomp:end func_00382030 */

/* localdecomp:start func_00382088 */
extern s32 func_00382030();
void func_00382088(void) {
    func_00381FF0(func_00382030());
}
/* localdecomp:end func_00382088 */

/* localdecomp:start func_003820B0 */
extern s32 D_001D5688;
void func_003820B0(void) { D_001D5688 = 0; }
/* localdecomp:end func_003820B0 */

/* US draft of func_003820B8 (rac3-uya-decomp func_0037E060, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


extern s32 D_001D5680;
/* localdecomp:start func_003820B8 */
extern s32 D_001D5680;
void func_003820B8(void) { D_001D5680 = 8; }
/* localdecomp:end func_003820B8 */

/* localdecomp:start func_003820C8 */
extern void func_00397CC0();
extern u8 D_001D5790[];
 
void func_003820C8(void) {
    func_00397CC0(D_001D5790, 0, 0);
}
/* localdecomp:end func_003820C8 */

/* localdecomp:start func_003820F0 */
#include "vu0.h"
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; u8 pE[6]; s32 f14; } Img_003820F0;
typedef struct {
    u8 *f0; u8 *f4; u8 p8[0xC]; s32 f14; s32 f18; u8 p1C[0x10]; s32 f2C; u8 p30[0xC]; s32 f3C;
    u8 p40[0xC]; s32 f4C; s32 f50;
} Tex_003820F0;
extern void func_0038CB78(void *, s32, s32);
extern void func_12C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_003820F0(Img_003820F0 *img, unsigned long *out, s32 tbp, s32 cbp) {
    Tex_003820F0 t;
    u8 buf[0x60];
    s32 w, h, lz, lz2, c;
    func_0038CB78(&t, 0, sizeof(t));
    t.f0 = (u8 *)img + 0x20;
    if (img->f14 == 0) t.f14 = 0x400; else t.f14 = 0x200;
    w = *(s32 *)((u8 *)img + 8);
    h = *(s32 *)((u8 *)img + 0xC);
    lz = plzcw_asm(w);
    t.f4C = 30 - lz;
    lz2 = plzcw_asm(h);
    t.f50 = 30 - lz2;
    t.f4 = (u8 *)img + (t.f14 + 0x20);
    t.f18 = w * h;
    c = cbp >> 8;
    func_12C9A0(buf, c, 1, img->f14, 0, 0, 0x10, 0x10);
    func_11F0A0(0);
    func_12CCC8(buf, t.f0);
    func_12A9F0(0, 0);
    t.f3C = *(s32 *)((u8 *)img + 8) >> 6;
    if (t.f3C <= 0) t.f3C = 1;
    t.f2C = tbp >> 8;
    func_12C9A0(buf, t.f2C, t.f3C, 0x1B, 0, 0, img->h8, img->hC);
    func_11F0A0(0);
    func_12CCC8(buf, t.f4);
    func_12A9F0(0, 0);
    out[0] = ((unsigned long)t.f2C << 0) | ((unsigned long)t.f3C << 14) | ((unsigned long)0x1B << 20)
        | ((unsigned long)t.f4C << 26) | ((unsigned long)t.f50 << 30) | ((unsigned long)1 << 34)
        | ((unsigned long)0 << 35) | ((unsigned long)c << 37) | ((unsigned long)img->f14 << 51)
        | ((unsigned long)0 << 55) | ((unsigned long)0 << 56) | ((unsigned long)4 << 61);
    out[1] = 1;
    out[2] = 0;
}
/* localdecomp:end func_003820F0 */

/* localdecomp:start func_003822C8 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern unsigned long D_001D4D38_003822C8;
__asm__(".extern D_001D4D38_003822C8, 16");
typedef struct { u8 p0[0x64C]; s32 f64C; s32 f650; s32 f654; } S_160C40_3826C8;
extern S_160C40_3826C8 D_160C40_003826A8;
extern u8 D_2D2100[];
extern s32 D_1A1F0C[];
extern s32 func_003A26F0(s32, s32, s32);
extern void func_003820F0_003822C8(void *, unsigned long *, s32, s32);
void func_003822C8(void) {
    unsigned long out[4];
    S_160C40_3826C8 *g = &D_160C40_003826A8;
    func_003A26F0((s32)D_2D2100, g->f650 + g->f64C, g->f654);
    func_003820F0_003822C8(D_2D2100, out, D_1A1F0C[0], 0x3FFC00);
    D_001D4D38_003822C8 = out[0];
}
/* localdecomp:end func_003822C8 */

LINKER_REMNANT("asm/remnants", func_00382338);

/* localdecomp:start func_00382348 */
s32 func_00382348(u8 *p) {
    s32 *q;
    if (p == 0 || (q = *(s32 **)(p + 0x68)) == 0 || !(*(u16 *)(p + 0x34) & 0x20)) {
        return 0;
    }
    return *q;
}
/* localdecomp:end func_00382348 */

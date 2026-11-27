#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

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
extern void func_003983C8(void);
extern void func_00387268(void);
extern void func_003A9108(void);
extern void func_003A9A40(void);
extern void func_0039A6E0(void);
extern s32 func_003A2998(s32, s32, s32);
extern void func_00392640(s32, long, long);
extern void func_00392698(void);
extern void func_00392730(s32);
extern void func_00388348(void);
extern s32 func_12C908(s32);
extern void func_00392670(void);
extern s32 func_003A2B50(s32);
extern void func_003A0B60(u8 *, u32);
extern void func_003A15F0(s32 a, s32 idx);
extern void func_00399230(void);
extern void func_003A1148(void);
extern void func_003811E8(void);
extern s32 func_003B3208(void);
extern void func_003A9588(void);
extern void func_003A9508(void);
extern void func_003927B0(void);
extern void func_00392B28(s32);
extern void func_00381080(void);
extern void func_003A3F70(void);
extern void func_00381C98(void);
extern s32 func_13D3C8(void);
extern void func_13D3C0(s32);
extern s32 func_00392F00();
extern s32 func_00393058();
extern void func_0038E530(s32);
extern void func_003B3408(void);
extern void func_003B3440();
extern long func_003A9BE8(s32 src, s32 dst, s32 w, s32 h);
extern void func_0038B200(s32, s32, s32, s32);
extern void func_003BB468(void);
extern s32 func_003E88E0(s32, s32 *);
extern s32 func_003E73A0();
extern s32 func_003E8868(s32);
extern void *func_003B5388();
extern void func_003E7398(void *);
extern s32 func_003E87F8(s32 arg0);
extern s32 func_003A4688_00381250(void);
extern void func_003A97F8(s32, unsigned long);
extern void func_00389620(s32);
extern void func_003B34A0(void);
extern void func_003B3510(s32);
extern void func_003B34D8(void);
extern s32 func_003823D0(s32);
extern void func_0038EBC8_00381250(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
extern void func_00389750(void);
extern void func_003A8EC8(void);
extern void func_003A2330();
extern void func_003B3CC8(void);
extern void func_0039C7F0(void);
extern void func_0039B1C0(void);
extern void func_003A96A8(s32);
extern void func_00388518(void);
extern void func_003A7CB8(void);

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
    func_003983C8();

    img = D_00227580_00381250.f18 + 0x400000;
    func_003A2998((s32)img, D_00160C40_00381250.f688 + D_00160C40_00381250.f64C, D_00160C40_00381250.f68C);
    dst = img + 0x200000;
    func_00392640(0, 0, 0);
    func_00392698();
    func_00392730(0);
    func_00388348();
    D_001A7430[0] = 1;
    D_001CCFD0_00381250.f7 = 0;
    D_001D5B90 = -2;
    D_001D5B94 = 0;
    D_001D5B8C = 0;
    D_001D9D08 = 0;
    D_001D9BC8 = 0;
    func_12C908(0);
    func_00392670();
    D_001D9BC8 = 0;
    func_12C908(0);
    func_00392670();
    func_003A2B50(1);
    func_003A0B60(img + *(s32 *)(img + 0x60), (u32)dst);
    func_003A15F0((s32)dst, 0);
    lang = img + *(s32 *)(img + 0x58);
    D_001D5B9C = 0x13;
    D_001D9D2C = (s32)D_0031CCD0;
    dst += 0x32000;
    func_003A0B60(lang, (u32)dst);
    p = (s32 *)(img + 0x28);
    for (i = 5; i >= 0; i--) {
        *p -= 0x10;
        p += 2;
    }
    /* D_001D4B50, as the word after D_001D4B4C: a declared scalar goes into the jal's delay slot */
    (&D_001D4B4C)[1] = (s32)(img + 0x10);
    func_00399230();

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
    func_003A0B60(lang, (u32)D_00227580_00381250.f18);

    heap = D_00227580_00381250.f18;
    D_0031CC80_00381250.f2C = *(u32 *)heap >> 4;
    D_001D99A0 = heap;
    for (i = 0; i < D_0031CC80_00381250.f2C; i++) {
        *(s32 *)(heap + i * 16) += (s32)heap;
    }
    func_003A1148();
    func_003811E8();
    func_003B3208();

    while (D_001D5B74 == 0) {
        D_001D4AC0 += *(volatile u32 *)0x10000800;
        *(volatile u32 *)0x10000800 = 0;
        func_003A9588();
        func_003A9508();
        func_003927B0();
        func_00392B28(1);
        func_00381080();
        func_00392698();
        func_00392730(0);
        state = D_001D5B94;
        handle = 0;
        D_001D4BB0 = D_001A1ED0_00381250.fC;
        switch (state + 1) {
        case 0:
        case 1:
            func_003A3F70();
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
                func_00381C98();
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
                        func_00392F00(D_00227400, 0);
                        func_00393058(D_00227400);
                        func_13D3C0(9);
                        D_001D5688 = 0;
                    } else if (D_001D5688++ > 6000) {
                        if (func_13D3C8() == 0) {
                            func_13D3C0(5);
                        }
                    }
                    mode = func_13D3C8();
                    func_0038E530(0);
                    func_003B3408();
                    func_003B3440(0);
                    switch (mode) {
                    case 0:
                        func_003A9BE8((s32)(dst + 0x10), D_001A1ED0_00381250.f4, 0x200, 0x1A0);
                        func_0038B200(0, 0, 0, 0x60);
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
                        func_003BB468();
                        func_13D3C0(6);
                        break;
                    case 6:
                        func_003A9BE8((s32)(dst + 0x10), D_001A1ED0_00381250.f4, 0x200, 0x1A0);
                        func_0038B200(0, 0, 0, 0x60);
                        func_003E88E0(D_001D5684, &handle);
                        if (handle == 0 || func_003E73A0(handle) == 0) {
                            func_13D3C0(7);
                        }
                        break;
                    case 7:
                        break;
                    case 10:
                        func_003E88E0(D_001D5684, &handle);
                        if (handle != 0 && func_003E73A0(handle) != 0) {
                            func_003E8868(D_001D5684);
                        }
                        func_13D3C0(8);
                        break;
                    case 8:
                        func_003E88E0(D_001D5684, &handle);
                        if (handle == 0 || func_003E73A0(handle) == 0) {
                            func_003E7398(func_003B5388());
                            D_001D5684 = func_003E87F8((s32)func_003B5388());
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
            func_003A4688_00381250();
            if (D_001D568C == 0 || D_001D5690 != 9) {
                func_00388348();
                func_003A97F8(0x47, 0x33001);
                func_00389620(0);
                func_003B34A0();
                func_003B3510(0);
                func_003B34D8();
                if (D_001D5750 >= 0) {
                    f32 sz = 32.0f;
                    s32 tex = func_003823D0(D_001D5758_00381250[D_001D5750].b);
                    func_0038EBC8_00381250(sz, sz, 1.0f, 0x80808080, tex, -1, 1.0f, 0, 0, 0x80000000, 0.0f, 0.0f);
                }
                func_00389750();
            }
            break;
        case 2:
            func_003A8EC8();
            break;
        case 4:
        case 5:
        case 19:
            func_003A3F70();
            func_003A2B50(0);
            func_003A2330();
            func_003B3CC8();
            break;
        }

        D_001D9D08++;
        func_003A4688_00381250();
        func_0039C7F0();
        func_0039B1C0();
        func_003A96A8(1);
        D_001D9D0C = (f32)*(volatile u32 *)0x10000800 / (D_00143950_00381250.f0 != 0 ? 11520.0f : 9600.0f);
        func_00388518();
        func_003A1148();
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
    func_003A7CB8();
}
/* localdecomp:end func_00381250 */

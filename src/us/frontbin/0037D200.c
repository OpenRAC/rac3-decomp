#include "common.h"

/* Adapted from the NTSC decomp, src/frontbin/37D100.c (see THIRD_PARTY_NOTICES.md). */
/* localdecomp:start func_U_0037D200 */
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

__asm__(".extern D_U_001D5750, 4");
__asm__(".extern D_U_001D574C, 4");
__asm__(".extern D_U_001D5758, 8");
__asm__(".extern D_U_001D5738, 8");
__asm__(".extern D_U_001D5680, 4");
__asm__(".extern D_U_001D5684, 4");
__asm__(".extern D_U_001D5688, 4");
__asm__(".extern D_U_001D568C, 4");
__asm__(".extern D_U_001D5690, 4");
__asm__(".extern D_U_001D5694, 4");

extern S_1A1ED0_37D200 D_001A1ED0;
extern S_227600_37D200 D_U_00227600;
extern S_1CCFD0_37D200 D_001CCFD0;
extern S_16C580_37D200 D_0016C580;
extern S_160C40_37D200 D_00160C40;
extern S_143950_37D200 D_00143950;
extern S_142430_37D200 D_00142430;
extern S_318CC0_37D200 D_U_00318CC0;
extern u8 D_U_001D5BDC;
extern s32 D_001D4BB4;
extern s32 D_001D4BB0;
extern s32 D_001D4B64;
extern s32 D_001D4B60;
extern s32 D_001D4B90;
extern s32 D_001D4BA0;
extern u32 D_001D4B4C[2];
extern s32 D_001A7430[];
extern s32 D_U_001D5B90;
extern s32 D_U_001D5B94;
extern s32 D_U_001D5B8C;
extern s32 D_U_001D9D88;
extern s32 D_U_001D9C48;
extern s32 D_U_001D5B9C;
extern s32 D_U_001D9DAC;
extern u8 D_U_00318D10[];
extern void *D_U_001D9A20;
extern s32 D_U_001D5B74;
extern unsigned long D_001D4AC0;
extern s32 D_U_001D5750;
extern s32 D_U_001D574C;
extern E_37D200 D_U_001D5758[] __attribute__((section(".sdata")));
extern s32 D_U_001D575C[] __attribute__((section(".sdata")));
extern s32 D_U_001D5738[] __attribute__((section(".sdata")));
extern void *D_001D52FC;
extern s32 D_U_001D5680;
extern s32 D_U_001D5684;
extern s32 D_U_001D5688;
extern s32 D_U_001D568C;
extern s32 D_U_001D5690;
extern s32 D_U_001D5694;
extern s32 D_U_00227480[];
extern s32 D_001D4D40;
extern s32 D_00142BA4[];
extern s32 D_U_001D9D84;
extern f32 D_U_001D9D8C;
extern u8 D_001D5570[8];

extern void func_U_003A30E0(void);
extern void func_U_0039C2A8(void);
extern void func_U_003A3B00(void);
extern void func_U_00393580(void);
extern void func_U_00382F90(void);
extern void func_U_003A3BB8(void);
extern void func_U_003A44F0(void);
extern void func_U_003958F0(void);
extern s32 func_U_0039D510(s32, s32, s32);
extern void func_U_0038DA28(s32, long, long);
extern void func_U_0038DA80(void);
extern void func_U_0038DB18(s32);
extern void func_U_003838C0(void);
extern s32 func_0012C908(s32);
extern void func_U_0038DA58(void);
extern s32 func_U_0039D6C8(s32);
extern void func_U_0039B760(u8 *, u32);
extern void func_U_0039C1C8(s32 a, s32 idx);
extern void func_U_00394060(void);
extern void func_U_0039BD48(void);
extern void func_U_0037D1A8(void);
extern s32 func_U_003AD8A8(void);
extern void func_U_003A3C80(void);
extern void func_U_003A3C00(void);
extern void func_U_0038DB98(void);
extern void func_U_0038DF10(s32);
extern void func_U_0039E8E0(void);
extern void func_U_0037DD30(void);
extern s32 func_0013D3C8(void);
extern void func_0013D3C0(s32);
extern s32 func_U_0038E2E8();
extern s32 func_U_0038E440();
extern void func_U_00389920(s32);
extern void func_U_003ADAA8(void);
extern void func_U_003ADAE0();
extern void func_U_003A42E0(u8 *, s32, s32, s32);
extern void func_U_003866E8(s32, s32, s32, s32);
extern void func_U_003B5BD0(void);
extern s32 func_U_003E2FC0(s32 arg0, s32 *arg1);
extern s32 func_U_003E1A98();
extern s32 func_U_003E2F48(s32 a);
extern void *func_U_003AFA18();
extern void func_U_003E1A90(void *);
extern s32 func_U_003E2ED8(s32 arg0);
extern s32 func_U_0039EE68(void);
extern void func_U_003A3EF0(s32, unsigned long);
extern void func_U_00384B68(s32);
extern void func_U_003ADB40(void);
extern void func_U_003ADBB0(s32);
extern void func_U_003ADB78(void);
extern s32 func_U_0037DF98(s32);
extern void func_U_00389FB8(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
extern void func_U_00384C98(void);
extern void func_U_003A35C0(void);
extern void func_U_0039CEA8();
extern void func_U_003AE368(void);
extern void func_U_00397490(void);
extern void func_U_00395FF0(void);
extern void func_U_003A3DA0(s32);
extern void func_U_00383A90(void);
extern void func_U_003A2460(void);

void func_U_0037D200(void) {
    u8 *base;
    u8 *buf;
    s32 cur;
    s32 obj;

    D_U_001D5BDC = 1;
    func_U_003A30E0();
    func_U_0039C2A8();
    func_U_003A3B00();
    func_U_00393580();
    D_001D4BB0 = D_001A1ED0.fC;
    D_001A1ED0.f24 = 0;
    D_001D4B60 = -1;
    D_001D4B90 = -1;
    D_001D4BB4 = D_001A1ED0.fC;
    D_001A1ED0.f28 = 0x60000;
    D_001D4BA0 = -1;
    D_0016C580.f30 = -1;
    D_001CCFD0.f41 = 0;
    D_001CCFD0.f42 = 0;
    D_001A1ED0.f2C = 0x70000;
    D_001A1ED0.f30 = 0xB0000;
    D_001CCFD0.f24 = -1;
    D_001A1ED0.f34 = 0xF0000;
    D_001A1ED0.f38 = 0x160000;
    D_001A1ED0.f3C = 0x1D0000;
    D_001CCFD0.f43 = 0;
    D_001CCFD0.f44 = 0;
    D_001D4B64 = D_U_00227600.f78;
    D_0016C580.f18 = -1;
    D_001CCFD0.f4E = 0;
    D_001CCFD0.f6C = 0;
    D_001CCFD0.f3C = -1;
    D_001CCFD0.f40 = 0x20;
    D_001CCFD0.f76 = 0;
    D_001A1ED0.f40 = 0x1E0000;
    D_001CCFD0.fBC = 0;
    D_001CCFD0.fC6 = 0;
    func_U_00382F90();
    func_U_003A3BB8();
    func_U_003A44F0();
    func_U_003958F0();
    base = D_U_00227600.f18 + 0x400000;
    func_U_0039D510((s32)base, D_00160C40.f688 + D_00160C40.f64C, D_00160C40.f68C);
    buf = base + 0x200000;
    func_U_0038DA28(0, 0, 0);
    func_U_0038DA80();
    func_U_0038DB18(0);
    func_U_003838C0();
    D_001A7430[0] = 1;
    D_001CCFD0.f7 = 0;
    D_U_001D5B90 = -2;
    D_U_001D5B94 = 0;
    D_U_001D5B8C = 0;
    D_U_001D9D88 = 0;
    D_U_001D9C48 = 0;
    func_0012C908(0);
    func_U_0038DA58();
    D_U_001D9C48 = 0;
    func_0012C908(0);
    func_U_0038DA58();
    func_U_0039D6C8(1);
    func_U_0039B760(base + ((H_37D200 *)base)[12].off, (u32)buf);
    func_U_0039C1C8((s32)buf, 0);
    D_U_001D5B9C = 0x13;
    D_U_001D9DAC = (s32)D_U_00318D10;
    buf += 0x32000;
    func_U_0039B760(base + ((H_37D200 *)base)[11].off, (u32)buf);
    {
        s32 i;
        for (i = 5; i < 11; i++) {
            ((H_37D200 *)base)[i].off -= 0x10;
        }
    }
    D_001D4B4C[1] = (u32)(base + 0x10);
    func_U_00394060();
    {
        u8 *p = 0;
        switch (D_00143950.fB7) {
        case 0:
        case 1:
            p = base + ((H_37D200 *)base)[0].off;
            break;
        case 2:
            p = base + ((H_37D200 *)base)[1].off;
            break;
        case 3:
            p = base + ((H_37D200 *)base)[2].off;
            break;
        case 4:
            p = base + ((H_37D200 *)base)[3].off;
            break;
        case 5:
            p = base + ((H_37D200 *)base)[4].off;
            break;
        }
        func_U_0039B760(p, (u32)D_U_00227600.f18);
    }
    {
        u8 *q = D_U_00227600.f18;
        s32 i;
        u32 n = *(u32 *)q >> 4;
        D_U_001D9A20 = q;
        D_U_00318CC0.f2C = n;
        for (i = 0; i < D_U_00318CC0.f2C; i++) {
            *(u32 *)(q + i * 16) += (u32)q;
        }
    }
    func_U_0039BD48();
    func_U_0037D1A8();
    func_U_003AD8A8();
    while (D_U_001D5B74 == 0) {
        D_001D4AC0 += *(volatile u32 *)0x10000800;
        *(volatile u32 *)0x10000800 = 0;
        func_U_003A3C80();
        func_U_003A3C00();
        func_U_0038DB98();
        func_U_0038DF10(1);
        func_U_0038DA80();
        func_U_0038DB18(0);
        cur = D_U_001D5B94;
        obj = 0;
        D_001D4BB0 = D_001A1ED0.fC;
        switch (cur) {
        case -1:
        case 0:
            func_U_0039E8E0();
            if (D_U_001D5750 >= 0) {
                if (D_U_001D5750 > 0 && (((S_pad_37D200 *)D_001D52FC)->f1A4 & 4)) {
                    D_U_001D5750 = D_U_001D5750 - 1;
                } else {
                    s32 n = D_U_001D5750 + 1;
                    if (D_U_001D5758[n].a > 0 && (((S_pad_37D200 *)D_001D52FC)->f1A4 & 8)) {
                        D_U_001D5750 = n;
                    }
                }
            } else {
                S_pad_37D200 *pad = D_001D52FC;
                if ((pad->f1A0 & 0x600) == 0x600) {
                    if (pad->f1A4 != 0) {
                        s32 k = D_U_001D574C;
                        if ((pad->f1A4 & D_U_001D5738[k]) == D_U_001D5738[k]) {
                            D_U_001D574C = k + 1;
                            if (D_U_001D5738[k + 1] == -1) {
                                D_U_001D5750 = 0;
                            }
                        } else {
                            D_U_001D574C = 0;
                        }
                    }
                } else {
                    D_U_001D574C = 0;
                }
            }
            if (((S_pad_37D200 *)D_001D52FC)->f1A0 != 0 || D_00142430.f15C >= 3 || D_00142430.f164 >= 0) {
                D_U_001D5688 = 0;
            }
            if (D_U_001D568C != 0) {
                func_U_0037DD30();
            } else {
                s32 t = D_U_001D5680;
                if (t < 0) t = 0;
                t = t - 1;
                D_U_001D5680 = t;
                if (t <= 0 && (((S_pad_37D200 *)D_001D52FC)->f1A0 & 0xF) == 0xF) {
                    D_U_001D568C = 1;
                    D_U_001D5690 = 9;
                    D_U_001D5680 = 0;
                    D_U_001D5694 = 0;
                } else {
                    s32 st;
                    if (func_0013D3C8() == 7) {
                        func_0013D3C0(5);
                        D_001D4D40 = 1;
                        D_U_00227480[0] = 1;
                        func_U_0038E2E8(D_U_00227480, 0);
                        func_U_0038E440(D_U_00227480);
                        func_0013D3C0(9);
                        D_U_001D5688 = 0;
                    } else if (D_U_001D5688++ > 0x1C20 && func_0013D3C8() == 0) {
                        func_0013D3C0(5);
                    }
                    st = func_0013D3C8();
                    func_U_00389920(0);
                    func_U_003ADAA8();
                    func_U_003ADAE0(0);
                    switch (st) {
                    case 0:
                        func_U_003A42E0(buf + 0x10, D_001A1ED0.f4, 0x200, 0x1A0);
                        func_U_003866E8(0, 0, 0, 0x60);
                        break;
                    case 1:
                        func_0013D3C0(2);
                        break;
                    case 3:
                        {
                            unsigned long t = D_00142BA4[0];
                            if (!((t >> 6) & 1)) break;
                        }
                    case 2:
                        func_0013D3C0(4);
                        break;
                    case 4:
                        D_U_001D5B74 = 1;
                        D_U_001D9D84 = 1;
                        func_0013D3C0(0);
                        break;
                    case 5:
                        func_U_003B5BD0();
                        func_0013D3C0(6);
                        break;
                    case 6:
                        func_U_003A42E0(buf + 0x10, D_001A1ED0.f4, 0x200, 0x1A0);
                        func_U_003866E8(0, 0, 0, 0x60);
                        func_U_003E2FC0(D_U_001D5684, &obj);
                        if (obj == 0 || func_U_003E1A98(obj) == 0) {
                            func_0013D3C0(7);
                        }
                        break;
                    case 10:
                        func_U_003E2FC0(D_U_001D5684, &obj);
                        if (obj != 0 && func_U_003E1A98(obj) != 0) {
                            func_U_003E2F48(D_U_001D5684);
                        }
                        func_0013D3C0(8);
                        break;
                    case 8:
                        func_U_003E2FC0(D_U_001D5684, &obj);
                        if (obj == 0 || func_U_003E1A98(obj) == 0) {
                            func_U_003E1A90(func_U_003AFA18());
                            D_U_001D5684 = func_U_003E2ED8((s32)func_U_003AFA18());
                            func_0013D3C0(0);
                        }
                        D_U_001D5688 = 0;
                        break;
                    case 9:
                        D_U_001D5688 = 0;
                        func_0013D3C0(10);
                        break;
                    case 7:
                        break;
                    }
                }
            }
            func_U_0039EE68();
            if (D_U_001D568C == 0 || D_U_001D5690 != 9) {
                func_U_003838C0();
                func_U_003A3EF0(0x47, 0x33001);
                func_U_00384B68(0);
                func_U_003ADB40();
                func_U_003ADBB0(0);
                func_U_003ADB78();
                if (D_U_001D5750 >= 0) {
                    f32 s = 32.0f;
                    s32 r = func_U_0037DF98(D_U_001D575C[D_U_001D5750 * 2]);
                    func_U_00389FB8(s, s, 1.0f, 0x80808080, r, -1, 1.0f, 0, 0, 0x80000000, 0.0f, 0.0f);
                }
                func_U_00384C98();
            }
            break;
        case 1:
            func_U_003A35C0();
            break;
        case 3:
        case 4:
        case 18:
            func_U_0039E8E0();
            func_U_0039D6C8(0);
            func_U_0039CEA8();
            func_U_003AE368();
            break;
        }
        D_U_001D9D88++;
        func_U_0039EE68();
        func_U_00397490();
        func_U_00395FF0();
        func_U_003A3DA0(1);
        {
            D_U_001D9D8C = (f32)*(volatile u32 *)0x10000800 / (D_00143950.f0 != 0 ? 11520.0f : 9600.0f);
        }
        func_U_00383A90();
        func_U_0039BD48();
        if (D_U_001D5B94 != cur) {
            D_U_001D9D88 = 0;
        }
        D_U_001D9C48++;
        func_0012C908(0);
    }
    if (D_U_001D5750 >= 0) {
        s32 v = D_U_001D5758[D_U_001D5750].a;
        if (D_001D5570[v] != 0) {
            D_U_001D9D84 = v;
        }
    }
    func_U_003A2460();
}
/* localdecomp:end func_U_0037D200 */

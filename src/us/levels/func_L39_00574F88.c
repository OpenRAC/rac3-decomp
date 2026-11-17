#include "common.h"

/* NTSC-U counterpart of func_L39_00575CC8 (src/levels/shared/L39_00575CC8.c) */
/* localdecomp:start func_L39_00574F88 */
typedef struct { u8 p0[0x28]; s16 h28; s16 h2A; s16 h2C; } S_1FC340_00575CC8;
typedef struct {
    u8 p0[4]; s32 f4; s32 f8; s32 fC; u8 p10[0x118]; s32 f128; u8 p12C[0x3C];
    u8 b168; u8 p169[3]; s32 f16C; s32 f170; u8 p174[0x660]; u8 b7D4;
} S_1A5CD0_00575CC8;
typedef struct {
    u8 p0[0xE0]; s16 a[8]; s16 b[8]; u8 p100[0x70]; s32 f170; u8 p174[4]; s32 f178;
} S_241640_00575CC8;
typedef struct { u8 p0[0x1A0]; s16 h1A0; s16 h1A2; u8 p1A4[2]; s16 h1A6; u8 p1A8[0xC70 - 0x1A8]; } S_22F3D0_00575CC8;
typedef struct { u8 p0[0x458]; s32 f458; u8 p45C[4]; } S_24DE80_00575CC8;
typedef struct { s32 i; u8 p4[2]; u8 b6; u8 p7[0x19]; } Ev_00575CC8;

__asm__(".extern D_001D5A0C_sda_00574F88, 4");
__asm__(".extern D_001D5A08_sda_00574F88, 4");
__asm__(".extern D_L39_0024BC40, 4");
__asm__(".extern D_L39_0024B904, 4");
__asm__(".extern D_L39_0024B900, 4");
__asm__(".extern D_001D6330_sda_00574F88, 4");
__asm__(".extern D_001D6334_sda_00574F88, 4");
__asm__(".extern D_001D6340_sda_00574F88, 1");
__asm__(".extern D_001D633C_sda_00574F88, 4");
__asm__(".extern D_001D6338_sda_00574F88, 1");
__asm__(".extern D_001D4F30_sda_00574F88, 4");
__asm__(".extern D_001D729E_sda_00574F88, 1");
extern s32 D_L39_0024145C;
extern s32 D_L39_002415C0;
extern s32 D_L39_00242A90;
extern s32 D_L39_002412A8;
extern s32 D_L39_00242A8C;
extern s32 D_L39_0024BC44;
extern s32 D_L39_00242A94;
extern s32 D_L39_00242A74;
extern s32 D_L39_0024BC50_00574F88;
extern s32 D_L39_0024BAC8;
extern s32 D_L39_00241520;
extern s32 *D_L39_002412A0;
extern S_241640_00575CC8 *D_L39_002417C0;
extern unsigned long D_L39_00240380;
extern S_24DE80_00575CC8 D_L39_0024DF80[];
extern f32 D_L39_0024BC48;
__asm__(".extern D_L39_0024BC48, 4");
extern s32 D_001D5A0C_sda_00574F88;
extern s32 D_001D5A08_sda_00574F88;
extern s32 D_L39_0024BC40;
extern s32 D_L39_0024B904;
extern s32 D_L39_0024B900;
extern s32 D_001D6330_sda_00574F88;
extern s32 D_001D6334_sda_00574F88;
extern u8 D_001D6340_sda_00574F88;
extern s32 D_001D633C_sda_00574F88;
extern u8 D_001D6338_sda_00574F88;
extern s32 D_001D4F30_sda_00574F88;
extern s8 D_001D729E_sda_00574F88;
extern S_1FC340_00575CC8 D_L39_001FC4C0;
extern S_1A5CD0_00575CC8 D_001A5E50;
extern S_22F3D0_00575CC8 D_L39_0022F550[8];
extern u8 D_001A4854[];
extern s32 D_001A5990[];
extern s32 D_L39_0024CF20[8] __attribute__((section(".sdata")));

extern void func_L01_003EF248(void);
extern s32 func_L39_00576AD8(void);
extern void func_L39_006199A0(void);
extern void func_L39_0059C7A8(void);
extern void func_L39_005A2628(s32, s32);
extern void func_L01_004198E0(void);
extern void func_L39_005A7520(void);
extern void func_L39_005D3F98(void);
extern void func_L01_003F00C0(void);
extern void func_L39_00589460(s32);
extern void func_L01_003EFF28(void);
extern void func_L39_00619880(void);
extern void func_L39_005BFA18(s32, s32, s32);
extern void func_L01_0045BF98(s32);
extern void func_00194758(void);
extern void func_L39_005BD4E8(void);
extern void func_0039CC78(void);
extern void func_L39_0058BA98(void);
extern void func_L39_005FA660(void);
extern void func_003A3C00(void);
extern void func_0038DB98(void);
extern void func_0038DF10(s32);
extern void func_L39_00596BA0(void);
extern s32 func_00193680(void);
extern void func_L01_0045E370(void);
extern void func_0019C288(void);
extern void func_L39_005F9780(void);
extern void func_L01_004017F8(void);
extern void func_L39_00576490(void);
extern void func_L39_005FD1B8(void);
extern void func_L01_004C6C60(void);
extern void func_L01_00401820(void);
extern s32 func_L01_004573E8(void);
extern s32 func_00195AE8(void);
extern void func_003AE368(void);
extern void func_L39_0067AC48(void);
extern void func_L01_0047C810_00574F88(void);
extern void func_L39_00679F08_00574F88(void);
extern void func_L39_005EF018(void);
extern void func_L39_00679E90(void);
extern void func_L01_004B5B50(void);
extern void func_L01_004018D8(void);
extern s32 func_L39_00572710(s32);
extern s32 func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern void func_L39_005726D0(void);
extern void func_001999B8(void *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern s32 func_00388398(void *);
extern void func_L01_0044ECE0(s32, s32, s32);
extern void func_L39_005A70C0(void);
extern void func_L39_005F9670(void);
extern void func_L39_0057A218(void);
extern void func_L39_005F91C8(void);
extern void func_L39_005F9EF0(void);
extern void func_L01_00401848(void);
extern void func_L39_00589B10(void);
extern void func_L39_00597BB0(void);
extern void func_L01_00401878(void);
extern void func_L01_0047C5A8_00574F88(void);
extern void func_L01_0047C620_00574F88(void);
extern void func_L01_00457248(void);
extern void func_L39_00577308(void);
extern void func_L39_005A43D8(void);
extern void func_L39_005A33A0(void);
extern void func_L39_00575B88(void);
extern void func_003A3DA0(s32);
extern void func_L39_00575DE8(void);
extern void func_L39_005D3E98(void);
extern void func_L39_00575F70(void);
extern s32 func_00139E08(s32);
extern void func_00383A90(void);
extern void func_003A3BB8(void);
extern void func_L39_00595C30(void);
extern void func_L39_00595F80(s32, s32, s32, s32, s32, s32);
extern void func_003D3DC8(void);
extern void func_L39_00619C88(void);
extern void func_L39_005F1758(void);

void func_L39_00574F88(void) {
    s32 saved;
    s32 i;
    s32 a, b, c;
    s32 j;
    s32 cnt;
    s32 n;
    s32 ok;
    S_241640_00575CC8 *p;
    Ev_00575CC8 ev;
    s32 old;
    S_241640_00575CC8 *np;
    S_241640_00575CC8 *r;
    s32 *level = &D_L39_0024145C;

    func_L01_003EF248();
    if (*level != 0x27 && func_L39_00576AD8()) {
        func_L39_006199A0();
    }
    if (D_L39_0024145C == 0x27) {
        D_L39_00242A90 = 0xC;
        D_L39_002412A8 = 0;
        D_L39_00242A8C = 0;
        if (D_L39_002415C0 != 4 && D_L39_002415C0 != 6 && D_L39_002415C0 != 3 && D_L39_002415C0 != 5 &&
            D_L39_002415C0 != 9) {
            D_L39_002415C0 = 0;
        }
    } else {
        D_L39_002412A8 = 0x11;
        D_L39_00242A8C = 0x11;
        D_L39_00242A90 = 0x11;
    }
    D_L39_0024BC44 = 0;
    func_L39_0059C7A8();
    func_L39_005A2628(1, 0);
    func_L01_004198E0();
    func_L39_005A7520();
    func_L39_005D3F98();
    func_L01_003F00C0();
    if (D_L39_001FC4C0.h2C != 0) {
        func_L39_00589460(10);
        D_L39_001FC4C0.h2C = 0;
    }
    func_L01_003EFF28();
    D_L39_001FC4C0.h2A = 1;
    if (D_L39_001FC4C0.h28 != 0) {
        D_L39_001FC4C0.h28 = 0;
    }
    if (func_L39_00576AD8() && D_L39_0024145C != 0x27) {
        func_L39_00619880();
        D_L39_002412A8 = 0x11;
    }
    func_L39_00589460(4);
    D_L39_0024BAC8 = 0;
    if (D_L39_0024145C == 0x27) {
        func_L39_005BFA18(0, 0, 0x400);
    } else {
        func_L39_005BFA18(4, 0xD, 0x400);
    }
    func_L01_0045BF98(0);
    func_00194758();
    func_L39_005BD4E8();
    func_0039CC78();

    while (D_L39_00242A74 == 0) {
        D_L39_00240380 += (*(volatile u32 *)0x10000800);
        (*(volatile u32 *)0x10000800) = 0;
        D_L39_0024BC50_00574F88 = 0;
        saved = D_L39_002412A8;
        func_L39_0058BA98();
        func_L39_005FA660();
        func_003A3C00();
        func_0038DB98();
        switch (D_L39_002412A8) {
        case 0:
        case 2:
            func_0038DF10(1);
            break;
        default:
            func_0038DF10(1);
            break;
        }
        func_L39_00596BA0();
        func_00193680();
        if (D_L39_0024B904 == 0) {
            D_L39_0024B904 = 1;
            D_L39_0024B900 = D_L39_00241520;
        }
        switch (D_L39_002412A8) {
        case -1:
        case 0:
            switch (D_L39_00242A94) {
            case 0:
                D_001D5A0C_sda_00574F88 = 0;
                D_001D5A08_sda_00574F88 = 0;
                func_L01_0045E370();
                func_0019C288();
                func_L39_005F9780();
                func_0019C288();
                if (D_001D6330_sda_00574F88 == 1) {
                    D_L39_00240380 += (*(volatile u32 *)0x10000800);
                    (*(volatile u32 *)0x10000800) = 0;
                    func_L01_0045E370();
                    func_L39_005F9780();
                    func_0019C288();
                }
                func_L01_004017F8();
                func_0019C288();
                break;
            case 1:
            case 2:
            case 3:
                func_L39_00576490();
                break;
            }
            break;
        case 8:
            func_L01_0045E370();
            func_L39_005FD1B8();
            func_L01_004C6C60();
            break;
        case 14:
            func_L01_0045E370();
            func_L39_005F9780();
            func_L01_00401820();
            break;
        case 18:
            if (func_L01_004573E8() == 0xC) {
                func_00195AE8();
            }
            func_003AE368();
            break;
        case 11:
            func_L01_0045E370();
            func_L39_0067AC48();
            func_L39_00679F08_00574F88();
            func_L39_005EF018();
            break;
        case 10:
            func_L01_0045E370();
            func_L01_0047C810_00574F88();
            func_L39_00679F08_00574F88();
            func_L39_005EF018();
            break;
        case 12:
            func_L01_0045E370();
            func_L39_00679E90();
            if (D_L39_00242A74 == 0) {
                func_L39_00679F08_00574F88();
            }
            break;
        case 7:
            func_L01_0045E370();
            func_L01_004B5B50();
            func_L01_004018D8();
            break;
        case 17:
            func_0019C288();
            ok = 0;
            func_00195AE8();
            if (D_001A5E50.f170 != 0 && func_L39_00572710(1)) {
                if (D_001D6340_sda_00574F88 != 0) {
                    if (func_L39_00572710(0)) {
                        D_001D633C_sda_00574F88 = 0x1518;
                        func_L39_005BD7D8(0, 2, 0, 0, 0);
                        break;
                    }
                } else {
                    func_L39_005726D0();
                    D_001D6340_sda_00574F88 = 1;
                }
            } else if (D_001A5E50.b168 != 0) {
                if (D_L39_002417C0->b[0] != 8) {
                    p = D_L39_002417C0;
                    n = 0;
                    for (a = 1; a < 8; a++) {
                        if (p->a[a] != D_001A5E50.f8 && p->a[a] != -1 && p->b[a] == 8) {
                            n++;
                        }
                    }
                    ok = n == D_L39_002417C0->f178 - *D_L39_002412A0;
                }
            }
            for (i = 0; i < 8; i++) {
                S_22F3D0_00575CC8 *q = &D_L39_0022F550[i];
                if (q->h1A2 != 0 && q->h1A6 == 0 && q->h1A0 == 0) {
                    func_001999B8(q);
                }
            }
            if (func_L39_00572710(1) &&
                ((D_001A5E50.b168 == 0 && D_001D6338_sda_00574F88 == 0) || ok)) {
                np = D_L39_002417C0;
                cnt = 0;
                for (b = 0; b < 8; b++) {
                    if (D_L39_0024CF20[b] != 0) {
                        cnt++;
                    }
                }
                if (cnt == np->f178) {
                    D_001D6338_sda_00574F88 = 1;
                    if (D_001A5E50.b168 != 0) {
                        np->f170 = D_001A5E50.f128 + 0x226;
                        for (c = 0; c < 8; c++) {
                            if (D_L39_002417C0->a[c] == D_001A5E50.f8) {
                                D_L39_002417C0->b[c] = 8;
                            }
                        }
                    }
                    for (i = 0; i < D_001A5E50.fC; i++) {
                        ev.b6 = 8;
                        ev.i = i;
                        if (D_001A5E50.f170 == 0) {
                            func_0014AD08(D_001A5E50.b7D4 | 0x40, D_001A5E50.f4, D_001A5E50.f16C, D_001D4F30_sda_00574F88, 0x20, &ev);
                        }
                    }
                }
            }
            if (func_00388398(&D_001D633C_sda_00574F88)) {
                D_L39_002417C0->b[0] = 8;
                D_L39_002417C0->f170 = D_001A5E50.f128;
                D_001D633C_sda_00574F88 = 0x1518;
            }
            if (func_L39_00572710(1)) {
                r = D_L39_002417C0;
                if (r->b[0] == 8 &&
                    (D_001A5E50.f128 >= r->f170 || D_001A5E50.f128 + 0x258 < r->f170)) {
                    if (D_001D6340_sda_00574F88 != 0) {
                        if (func_L39_00572710(0)) {
                            D_001D6338_sda_00574F88 = 0;
                            D_001D633C_sda_00574F88 = 0x1518;
                            func_L39_005BD7D8(0, 2, 0, 0, 0);
                            for (j = 0; j < *D_L39_002412A0; j++) {
                                D_L39_0024DF80[j].f458 = 2;
                            }
                        }
                    } else {
                        func_L39_005726D0();
                        D_001D6340_sda_00574F88 = 1;
                    }
                }
            }
            old = *D_L39_002412A0;
            *D_L39_002412A0 = 1;
            if (D_L39_0024BC44 >= 0x1F5) {
                func_L01_0044ECE0(0x1DB2, 2, 0);
            }
            func_L39_005A70C0();
            func_L39_005F9670();
            func_L39_0057A218();
            func_L01_004017F8();
            *D_L39_002412A0 = old;
            break;
        case 1:
            func_L39_005F91C8();
            break;
        case 2:
            func_L01_0045E370();
            func_L39_005F9EF0();
            func_L01_00401848();
            func_L39_00589B10();
            break;
        case 4:
            if (func_L01_004573E8() == 0xC || func_L01_004573E8() == 0x12) {
                func_00195AE8();
            }
            func_L01_0045E370();
            func_L39_00597BB0();
            func_L01_00401878();
            break;
        case 3:
        case 5:
        case 6:
        case 16:
            func_L01_0045E370();
            break;
        case 9:
            func_L01_0045E370();
            func_L01_0047C5A8_00574F88();
            func_L01_0047C620_00574F88();
            break;
        case -2:
        case 19:
        default:
            break;
        }
        D_L39_0024BC44 = D_L39_0024BC44 + 1;
        func_L01_00457248();
        if (D_L39_002412A8 == 0) {
            func_L39_00577308();
        }
        func_L39_005A43D8();
        func_L39_005A33A0();
        func_L39_00575B88();
        func_003A3DA0(1);
        D_L39_0024BC48 = (f32)(*(volatile u32 *)0x10000800) / (D_001A5990[0] != 0 ? 11520.0f : 9600.0f);
        if (D_L39_0024BC50_00574F88 == 0) {
            if (D_L39_002412A8 == 0) {
                func_L39_00575DE8();
                func_L39_005D3E98();
            } else if (D_L39_002412A8 == 2) {
                func_L39_00575F70();
                func_L39_005D3E98();
            } else {
                func_00139E08(0);
                D_001D6330_sda_00574F88 = 0;
                D_001D6334_sda_00574F88 = 0;
                D_L39_0024BAC8 = D_L39_0024BAC8 + 1;
                func_L39_005D3E98();
            }
            if (D_L39_002412A8 != 3) {
                D_001D729E_sda_00574F88 = 0;
            }
        }
        func_00383A90();
        func_L39_005BD4E8();
        if (D_L39_002412A8 != saved) {
            D_L39_0024BC44 = 0;
        }
        if (D_L39_0024BC50_00574F88 != 0) {
            func_003A3BB8();
        }
        if (D_L39_0024B900 != D_L39_00241520) {
            D_L39_0024B900 = D_L39_00241520;
            func_L39_00595C30();
            if (D_L39_00241520 != 0) {
                func_L39_00595F80(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
            } else {
                func_L39_00595F80(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
            }
            func_003D3DC8();
        }
    }
    if (D_L39_0024BC40 != D_L39_0024145C) {
        D_001A4854[0] = *(u8 *)&D_L39_0024145C;
    }
    if (D_L39_0024145C != 0x27 && func_L39_00576AD8()) {
        func_L39_00619C88();
    }
    func_L39_005F1758();
}
/* localdecomp:end func_L39_00574F88 */

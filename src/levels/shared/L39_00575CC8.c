#include "common.h"

/* localdecomp:start func_L39_00575CC8 */
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

__asm__(".extern D_001D5A0C_sda, 4");
__asm__(".extern D_001D5A08_sda, 4");
__asm__(".extern D_L39_0024BB40, 4");
__asm__(".extern D_L39_0024B804, 4");
__asm__(".extern D_L39_0024B800, 4");
__asm__(".extern D_001D6330_sda, 4");
__asm__(".extern D_001D6334_sda, 4");
__asm__(".extern D_001D6340_sda, 1");
__asm__(".extern D_001D633C_sda, 4");
__asm__(".extern D_001D6338_sda, 1");
__asm__(".extern D_001D4F30_sda, 4");
__asm__(".extern D_001D729E_sda, 1");
extern s32 D_L39_002412DC;
extern s32 D_L39_00241440;
extern s32 D_L39_00242910;
extern s32 D_L39_00241128;
extern s32 D_L39_0024290C;
extern s32 D_L39_0024BB44;
extern s32 D_L39_00242914;
extern s32 D_L39_002428F4;
extern s32 D_L39_0024BB50;
extern s32 D_L39_0024B9C8;
extern s32 D_L39_002413A0;
extern s32 *D_L39_00241120;
extern S_241640_00575CC8 *D_L39_00241640;
extern unsigned long D_L39_00240200;
extern S_24DE80_00575CC8 D_L39_0024DE80[];
extern f32 D_L39_0024BB48;
__asm__(".extern D_L39_0024BB48, 4");
extern s32 D_001D5A0C_sda;
extern s32 D_001D5A08_sda;
extern s32 D_L39_0024BB40;
extern s32 D_L39_0024B804;
extern s32 D_L39_0024B800;
extern s32 D_001D6330_sda;
extern s32 D_001D6334_sda;
extern u8 D_001D6340_sda;
extern s32 D_001D633C_sda;
extern u8 D_001D6338_sda;
extern s32 D_001D4F30_sda;
extern s8 D_001D729E_sda;
extern S_1FC340_00575CC8 D_001FC340;
extern S_1A5CD0_00575CC8 D_001A5CD0;
extern S_22F3D0_00575CC8 D_0022F3D0[8];
extern u8 D_001A46D4[];
extern s32 D_001A5810[];
extern s32 D_L39_0024CE20[8] __attribute__((section(".sdata")));

extern void func_L01_003F1188(void);
extern s32 func_L39_00577818(void);
extern void func_L39_0061C118(void);
extern void func_L39_0059DB38(void);
extern void func_L39_005A4290(s32, s32);
extern void func_L01_0041BFE8(void);
extern void func_L39_005A9338(void);
extern void func_L39_005D6508(void);
extern void func_L01_003F2000(void);
extern void func_L39_0058A5D0(s32);
extern void func_L01_003F1E68(void);
extern void func_L39_0061BFF8(void);
extern void func_L39_005C1A60(s32, s32, s32);
extern void func_L01_0045F328(s32);
extern void func_00194668(void);
extern void func_L39_005BF490(void);
extern void func_003A1D00(void);
extern void func_L39_0058CC68(void);
extern void func_L39_005FCDF8(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern void func_L39_00597E70(void);
extern s32 func_00193590(void);
extern void func_L01_00461818(void);
extern void func_0019C148(void);
extern void func_L39_005FBF18(void);
extern void func_L01_00403B68(void);
extern void func_L39_005771D0(void);
extern void func_L39_005FF958(void);
extern void func_L01_004CA8C8(void);
extern void func_L01_00403B90(void);
extern s32 func_L01_0045A6F0(void);
extern s32 func_001959F8(void);
extern void func_003B3910(void);
extern void func_L39_0067D758(void);
extern void func_L01_00480070_00575CC8(void);
extern void func_L39_0067C9C0(void);
extern void func_L39_005F1718(void);
extern void func_L39_0067C948(void);
extern void func_L01_004B96E8(void);
extern void func_L01_00403C48(void);
extern s32 func_L39_00573438(s32);
extern s32 func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L39_005733F8(void);
extern void func_00199878(void *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_L39_005A8ED8(void);
extern void func_L39_005FBE08(void);
extern void func_L39_0057B1C0(void);
extern void func_L39_005FB960(void);
extern void func_L39_005FC688(void);
extern void func_L01_00403BB8(void);
extern void func_L39_0058ACE0(void);
extern void func_L39_00598E80(void);
extern void func_L01_00403BE8(void);
extern void func_L01_0047FE08_00575CC8(void);
extern void func_L01_0047FE80_00575CC8(void);
extern void func_L01_0045A550(void);
extern void func_L39_00578048(void);
extern void func_L39_005A61D8(void);
extern void func_L39_005A5010(void);
extern void func_L39_005768C8(void);
extern void func_003A92F0(s32);
extern void func_L39_00576B28(void);
extern void func_L39_005D6408(void);
extern void func_L39_00576CB0(void);
extern s32 func_00139E08(s32);
extern void func_00388138(void);
extern void func_003A9108(void);
extern void func_L39_00596EE0(void);
extern void func_L39_00597230(s32, s32, s32, s32, s32, s32);
extern void func_003D9338(void);
extern void func_L39_0061C400(void);
extern void func_L39_005F3E58(void);

void func_L39_00575CC8(void) {
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
    s32 *level = &D_L39_002412DC;

    func_L01_003F1188();
    if (*level != 0x27 && func_L39_00577818()) {
        func_L39_0061C118();
    }
    if (D_L39_002412DC == 0x27) {
        D_L39_00242910 = 0xC;
        D_L39_00241128 = 0;
        D_L39_0024290C = 0;
        if (D_L39_00241440 != 4 && D_L39_00241440 != 6 && D_L39_00241440 != 3 && D_L39_00241440 != 5 &&
            D_L39_00241440 != 9) {
            D_L39_00241440 = 0;
        }
    } else {
        D_L39_00241128 = 0x11;
        D_L39_0024290C = 0x11;
        D_L39_00242910 = 0x11;
    }
    D_L39_0024BB44 = 0;
    func_L39_0059DB38();
    func_L39_005A4290(1, 0);
    func_L01_0041BFE8();
    func_L39_005A9338();
    func_L39_005D6508();
    func_L01_003F2000();
    if (D_001FC340.h2C != 0) {
        func_L39_0058A5D0(8);
        D_001FC340.h2C = 0;
    }
    func_L01_003F1E68();
    D_001FC340.h2A = 1;
    if (D_001FC340.h28 != 0) {
        D_001FC340.h28 = 0;
    }
    if (func_L39_00577818() && D_L39_002412DC != 0x27) {
        func_L39_0061BFF8();
        D_L39_00241128 = 0x11;
    }
    func_L39_0058A5D0(4);
    D_L39_0024B9C8 = 0;
    if (D_L39_002412DC == 0x27) {
        func_L39_005C1A60(0, 0, 0x400);
    } else {
        func_L39_005C1A60(4, 0xD, 0x400);
    }
    func_L01_0045F328(0);
    func_00194668();
    func_L39_005BF490();
    func_003A1D00();

    while (D_L39_002428F4 == 0) {
        D_L39_00240200 += (*(volatile u32 *)0x10000800);
        (*(volatile u32 *)0x10000800) = 0;
        D_L39_0024BB50 = 0;
        saved = D_L39_00241128;
        func_L39_0058CC68();
        func_L39_005FCDF8();
        func_003A9150();
        func_003923D0();
        switch (D_L39_00241128) {
        case 0:
        case 2:
            func_00392748(1);
            break;
        default:
            func_00392748(1);
            break;
        }
        func_L39_00597E70();
        func_00193590();
        if (D_L39_0024B804 == 0) {
            D_L39_0024B804 = 1;
            D_L39_0024B800 = D_L39_002413A0;
        }
        switch (D_L39_00241128) {
        case -1:
        case 0:
            switch (D_L39_00242914) {
            case 0:
                D_001D5A0C_sda = 0;
                D_001D5A08_sda = 0;
                func_L01_00461818();
                func_0019C148();
                func_L39_005FBF18();
                func_0019C148();
                if (D_001D6330_sda == 1) {
                    D_L39_00240200 += (*(volatile u32 *)0x10000800);
                    (*(volatile u32 *)0x10000800) = 0;
                    func_L01_00461818();
                    func_L39_005FBF18();
                    func_0019C148();
                }
                func_L01_00403B68();
                func_0019C148();
                break;
            case 1:
            case 2:
            case 3:
                func_L39_005771D0();
                break;
            }
            break;
        case 8:
            func_L01_00461818();
            func_L39_005FF958();
            func_L01_004CA8C8();
            break;
        case 14:
            func_L01_00461818();
            func_L39_005FBF18();
            func_L01_00403B90();
            break;
        case 18:
            if (func_L01_0045A6F0() == 0xC) {
                func_001959F8();
            }
            func_003B3910();
            break;
        case 11:
            func_L01_00461818();
            func_L39_0067D758();
            func_L39_0067C9C0();
            func_L39_005F1718();
            break;
        case 10:
            func_L01_00461818();
            func_L01_00480070_00575CC8();
            func_L39_0067C9C0();
            func_L39_005F1718();
            break;
        case 12:
            func_L01_00461818();
            func_L39_0067C948();
            if (D_L39_002428F4 == 0) {
                func_L39_0067C9C0();
            }
            break;
        case 7:
            func_L01_00461818();
            func_L01_004B96E8();
            func_L01_00403C48();
            break;
        case 17:
            func_0019C148();
            ok = 0;
            func_001959F8();
            if (D_001A5CD0.f170 != 0 && func_L39_00573438(1)) {
                if (D_001D6340_sda != 0) {
                    if (func_L39_00573438(0)) {
                        D_001D633C_sda = 0x1518;
                        func_L39_005BF798(0, 2, 0, 0, 0);
                        break;
                    }
                } else {
                    func_L39_005733F8();
                    D_001D6340_sda = 1;
                }
            } else if (D_001A5CD0.b168 != 0) {
                if (D_L39_00241640->b[0] != 8) {
                    p = D_L39_00241640;
                    n = 0;
                    for (a = 1; a < 8; a++) {
                        if (p->a[a] != D_001A5CD0.f8 && p->a[a] != -1 && p->b[a] == 8) {
                            n++;
                        }
                    }
                    ok = n == D_L39_00241640->f178 - *D_L39_00241120;
                }
            }
            for (i = 0; i < 8; i++) {
                S_22F3D0_00575CC8 *q = &D_0022F3D0[i];
                if (q->h1A2 != 0 && q->h1A6 == 0 && q->h1A0 == 0) {
                    func_00199878(q);
                }
            }
            if (func_L39_00573438(1) &&
                ((D_001A5CD0.b168 == 0 && D_001D6338_sda == 0) || ok)) {
                np = D_L39_00241640;
                cnt = 0;
                for (b = 0; b < 8; b++) {
                    if (D_L39_0024CE20[b] != 0) {
                        cnt++;
                    }
                }
                if (cnt == np->f178) {
                    D_001D6338_sda = 1;
                    if (D_001A5CD0.b168 != 0) {
                        np->f170 = D_001A5CD0.f128 + 0x226;
                        for (c = 0; c < 8; c++) {
                            if (D_L39_00241640->a[c] == D_001A5CD0.f8) {
                                D_L39_00241640->b[c] = 8;
                            }
                        }
                    }
                    for (i = 0; i < D_001A5CD0.fC; i++) {
                        ev.b6 = 8;
                        ev.i = i;
                        if (D_001A5CD0.f170 == 0) {
                            func_0014AD08(D_001A5CD0.b7D4 | 0x40, D_001A5CD0.f4, D_001A5CD0.f16C, D_001D4F30_sda, 0x20, &ev);
                        }
                    }
                }
            }
            if (func_0038CAD0(&D_001D633C_sda)) {
                D_L39_00241640->b[0] = 8;
                D_L39_00241640->f170 = D_001A5CD0.f128;
                D_001D633C_sda = 0x1518;
            }
            if (func_L39_00573438(1)) {
                r = D_L39_00241640;
                if (r->b[0] == 8 &&
                    (D_001A5CD0.f128 >= r->f170 || D_001A5CD0.f128 + 0x258 < r->f170)) {
                    if (D_001D6340_sda != 0) {
                        if (func_L39_00573438(0)) {
                            D_001D6338_sda = 0;
                            D_001D633C_sda = 0x1518;
                            func_L39_005BF798(0, 2, 0, 0, 0);
                            for (j = 0; j < *D_L39_00241120; j++) {
                                D_L39_0024DE80[j].f458 = 2;
                            }
                        }
                    } else {
                        func_L39_005733F8();
                        D_001D6340_sda = 1;
                    }
                }
            }
            old = *D_L39_00241120;
            *D_L39_00241120 = 1;
            if (D_L39_0024BB44 >= 0x1A2) {
                func_L01_00451F60(0x1DB2, 2, 0);
            }
            func_L39_005A8ED8();
            func_L39_005FBE08();
            func_L39_0057B1C0();
            func_L01_00403B68();
            *D_L39_00241120 = old;
            break;
        case 1:
            func_L39_005FB960();
            break;
        case 2:
            func_L01_00461818();
            func_L39_005FC688();
            func_L01_00403BB8();
            func_L39_0058ACE0();
            break;
        case 4:
            if (func_L01_0045A6F0() == 0xC || func_L01_0045A6F0() == 0x12) {
                func_001959F8();
            }
            func_L01_00461818();
            func_L39_00598E80();
            func_L01_00403BE8();
            break;
        case 3:
        case 5:
        case 6:
        case 16:
            func_L01_00461818();
            break;
        case 9:
            func_L01_00461818();
            func_L01_0047FE08_00575CC8();
            func_L01_0047FE80_00575CC8();
            break;
        case -2:
        case 19:
        default:
            break;
        }
        D_L39_0024BB44 = D_L39_0024BB44 + 1;
        func_L01_0045A550();
        if (D_L39_00241128 == 0) {
            func_L39_00578048();
        }
        func_L39_005A61D8();
        func_L39_005A5010();
        func_L39_005768C8();
        func_003A92F0(1);
        D_L39_0024BB48 = (f32)(*(volatile u32 *)0x10000800) / (D_001A5810[0] != 0 ? 11520.0f : 9600.0f);
        if (D_L39_0024BB50 == 0) {
            if (D_L39_00241128 == 0) {
                func_L39_00576B28();
                func_L39_005D6408();
            } else if (D_L39_00241128 == 2) {
                func_L39_00576CB0();
                func_L39_005D6408();
            } else {
                func_00139E08(0);
                D_001D6330_sda = 0;
                D_001D6334_sda = 0;
                D_L39_0024B9C8 = D_L39_0024B9C8 + 1;
                func_L39_005D6408();
            }
            if (D_L39_00241128 != 3) {
                D_001D729E_sda = 0;
            }
        }
        func_00388138();
        func_L39_005BF490();
        if (D_L39_00241128 != saved) {
            D_L39_0024BB44 = 0;
        }
        if (D_L39_0024BB50 != 0) {
            func_003A9108();
        }
        if (D_L39_0024B800 != D_L39_002413A0) {
            D_L39_0024B800 = D_L39_002413A0;
            func_L39_00596EE0();
            if (D_L39_002413A0 != 0) {
                func_L39_00597230(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
            } else {
                func_L39_00597230(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
            }
            func_003D9338();
        }
    }
    if (D_L39_0024BB40 != D_L39_002412DC) {
        D_001A46D4[0] = *(u8 *)&D_L39_002412DC;
    }
    if (D_L39_002412DC != 0x27 && func_L39_00577818()) {
        func_L39_0061C400();
    }
    func_L39_005F3E58();
}
/* localdecomp:end func_L39_00575CC8 */

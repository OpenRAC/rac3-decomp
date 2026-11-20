#include "common.h"

/* localdecomp:start func_L01_004596E8 */
extern u8 *D_L01_001E0020;
extern u8 *D_L01_001E0024;
extern void func_L01_0035C6B0(u8 *);
extern void func_L01_00385EA0(u8 *);
extern void func_L01_003C38D0(u8 *);
extern void func_L01_0032E2B0(u8 *);
extern void func_L01_00330390(u8 *);
extern void func_L01_00379368(u8 *);
extern void func_L01_003D42D0(u8 *);
extern void func_L01_0039FEB0(u8 *);
extern void func_L01_003DABC8(u8 *);
extern void func_L01_00309B70(u8 *);
extern void func_L01_00371C98(u8 *);
extern void func_L01_003E1550(u8 *);
extern void func_L01_0038FCA8(u8 *);
extern void func_L01_00362600(u8 *);
extern void func_L01_0035FEB8(u8 *);
extern void func_L01_0038C9A0(u8 *);
extern void func_L01_003837A8(u8 *);
extern void func_L01_003968E8(u8 *);
extern void func_L01_00399A40(u8 *);
extern void func_L01_00344A40(u8 *);
extern void func_L01_0030C860(u8 *);
extern void func_L01_0031DB60(u8 *);
extern void func_L01_0031F258(u8 *);
extern void func_003C2880(u8 *);
extern void func_L01_00303658(u8 *);

void func_L01_004596E8(s32 (*filter)(u8 *), void (*deflt)(u8 *))
{
    u8 *m;
    s32 (*f)(u8 *) = filter;
    void (*d)(u8 *) = deflt;

    for (m = D_L01_001E0020; m < D_L01_001E0024; m += 256) {
        if (m == 0) continue;
        if (m[32] == 254) continue;
        if (m[32] == 253) continue;
        if (filter != 0 && f(m) == 0) continue;
        switch (*(s16 *)(m + 170)) {
        case 6225:
            func_L01_0035C6B0(m);
            break;
        case 6273:
            func_L01_00385EA0(m);
            break;
        case 6874:
            func_L01_003C38D0(m);
            break;
        case 4966:
            func_L01_0032E2B0(m);
            break;
        case 4967:
            func_L01_00330390(m);
            break;
        case 6253:
            func_L01_00379368(m);
            break;
        case 7107:
            func_L01_003D42D0(m);
            break;
        case 6299:
            func_L01_0039FEB0(m);
            break;
        case 7486:
            func_L01_003DABC8(m);
            break;
        case 2473:
            func_L01_00309B70(m);
            break;
        case 6247:
            func_L01_00371C98(m);
            break;
        case 7685:
            func_L01_003E1550(m);
            break;
        case 6282:
            func_L01_0038FCA8(m);
            break;
        case 6234:
            func_L01_00362600(m);
            break;
        case 6232:
            func_L01_0035FEB8(m);
            break;
        case 6280:
            func_L01_0038C9A0(m);
            break;
        case 6258:
            func_L01_003837A8(m);
            break;
        case 6291:
            func_L01_003968E8(m);
            break;
        case 6292:
            func_L01_00399A40(m);
            break;
        case 2690:
            func_L01_00344A40(m);
            break;
        case 2715:
            func_L01_0030C860(m);
            break;
        case 3684:
            func_L01_0031DB60(m);
            break;
        case 3790:
        case 6295:
            func_L01_0031F258(m);
            break;
        case 3291:
            func_003C2880(m);
            break;
        case 806:
            if (*(u8 **)(m + 184) == m) func_L01_00303658(m);
            break;
        default:
            if (deflt != 0) d(m);
            break;
        }
    }
}
/* localdecomp:end func_L01_004596E8 */

LINKER_REMNANT("asm/levels", func_L01_00459AF0);

/* localdecomp:start func_L01_00459AF8 */
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[130];
    u16 f84;
    u8 pad86[4];
    u16 f8A;
    u8 pad8C[100];
} __attribute__((aligned(16))) Ent_00456808;
extern Ent_00456808 D_L01_002C5600[];
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
void func_L01_00459AF8(void) {
    Ent_00456808 e;
    s32 i;
    for (i = 0; i < 156; i++) {
        e = D_L01_002C5600[i];
        if (e.f0 != 0 && e.f1 == 0) {
            if (D_00142CA0[i] != 0) {
                e = D_L01_002C5600[D_001425C0[i]];
                if (e.f84 != 0) {
                    D_001427F0[i] = e.f8A;
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00459AF8 */

/* localdecomp:start func_L01_00459BE8 */
extern s32 D_L01_001E0200[2];
extern s32 D_L01_0021FF38[];
void func_L01_00459BE8(s32 a0, s32 a1, f32 f12) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (D_L01_001E0200[i] == a0) {
            s32 *q = (s32 *)((u8 *)D_L01_0021FF38 + a1 * 4 + i * 0x270);
            *q += (s32)(f12 * 32.0f);
        }
    }
}
/* localdecomp:end func_L01_00459BE8 */

/* localdecomp:start func_L01_00459C50 */
typedef struct {
    u8 pad[186];
    u8 b186;
} St_00456960;

extern u8 D_001D54B0[1];
extern s32 D_L01_001D6790;
extern St_00456960 D_001426E0;
extern void func_003A5348(s32, s32, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_0039EF28(void);

void func_L01_00459C50(s32 idx) {
    s32 i;

    if (D_001D54B0[idx] == 0) {
        D_001D54B0[idx] = 1;
        func_003A5348(1, 0, 0);
        func_L01_00451F60(1734, -1, 0);
        D_L01_001D6790 = 1;
        if (D_001426E0.b186 == 0) {
            for (i = 0; i < 30; i++) {
                if (D_001D54B0[i] == 0) {
                    return;
                }
            }
            func_L01_00451F60(4785, -1, 0);
            D_001426E0.b186 = 1;
            func_0039EF28();
        }
    }
}
/* localdecomp:end func_L01_00459C50 */

/* localdecomp:start func_L01_00459D18 */
extern Ent_00456808 D_L01_002C5600[];
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[14];
    s128 rest[14];
} E_00456A28;

extern u8 D_00142CA0[];
extern u8 D_001425C0[];

s32 func_L01_00459D18(void) {
    E_00456A28 e;
    s32 i;

    for (i = 0; i < 156; i++) {
        e = ((E_00456A28 *)&D_L01_002C5600)[i];
        if (e.b0 != 0 && e.b1 == 0 && D_00142CA0[i] != 0) {
            e = ((E_00456A28 *)&D_L01_002C5600)[D_001425C0[i]];
            if (i == 151) {
                if (e.b1 < 4) {
                    return 0;
                }
            } else if (e.b1 < 7) {
                return 0;
            }
        }
    }
    return 1;
}
/* localdecomp:end func_L01_00459D18 */

LINKER_REMNANT("asm/levels", func_L01_00459E10);

INCLUDE_ASM("asm/levels", func_L01_00459EF0);

/* localdecomp:start func_L01_00459F60 */
typedef struct {
    u8 pad0[0x5E];
    s16 h5E;
} S_459F60;

/* The WAD table (as func_L01_00425FE0 reads it): the level entries of 0x14C bytes from 0x9250 */
typedef struct { s32 sector; s32 size; u8 pad8[0x14C - 0x8]; } Level_459F60;
typedef struct {
    u8 pad0[0x921C];
    s32 base;                  /* 0x921C */
    u8 pad9220[0x9250 - 0x9220];
    Level_459F60 levels[1];    /* 0x9250 */
} Wad_459F60;
extern s32 D_L01_001D6690;
extern s32 D_L01_001D6694;
extern s32 D_L01_001D668C;
extern s32 D_L01_001D6674;
extern f32 D_L01_001D6720;
extern u8 D_L01_001D672D;
extern s32 D_001D545C;
extern s32 D_001D4CEC;
extern s32 D_001A7430[];
extern u8 D_00160C40[];
extern s16 D_0016C5A6[];
extern s16 D_001CCFD4[];
extern s32 D_L01_001D7DBC;
extern s32 D_L01_001D7DC0;
extern s32 D_L01_001D7DC4;
extern u8 *D_L01_001D7DCC;
extern s32 D_L01_001D9730;
extern s32 D_L01_001D9928;
extern s32 D_L01_001D9A74;
extern s32 D_L01_001D9A7C;
/* a one-element .sdata array: gcc then cannot tell its stores from D_L01_001D6720, and reloads
   D_L01_001D6720 after the clamp as retail does */
extern f32 D_L01_001DF950[1] __attribute__((section(".sdata")));
extern s32 D_L01_001DFB44;
extern s32 D_L01_001DFB54;
extern s32 D_L01_001E1070;
extern S_459F60 D_L01_001E6D80;
extern f32 D_L01_001E7630[];
extern s32 D_L01_001EA94C[];

extern void func_L01_004C8BE8(void);
extern void func_L01_0047E568(void);
extern void func_L01_00415D78(void);
extern void func_003A8A58(void);
extern void func_L01_004B9D20(void);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_003873C0(void);
extern void func_L01_004ACDB0(void);
extern void func_L01_004BBD90(void);
extern void func_L01_004A3548(void);
extern void func_L01_004C97C8(void);
extern void func_L01_00423000_00459F60(void);
extern void func_L01_0045A530(s32);
extern s32 func_L01_00415CC0_00459F60(void);
extern void func_L01_0047DDC8(s32);
extern void func_L01_00415DD8(s32, s32);
extern void func_003A88B8(s32);
extern void func_L01_0045F328(s32);
extern void func_003A2750(s32);
extern s32 func_003A8770(s32);
extern void func_003A9050(void);
extern void func_003A2598(s32, s32, s32);
extern void func_003C4138(void *, f32, f32);
extern void func_L01_004B9810(s32);
extern void func_L01_004ACBC8(s32);
extern s32 func_00392DF0();
extern void func_L01_004ACD40(void);
extern void func_L01_004ACB38(void);
extern void func_L01_004BB4E0(s32);
extern void func_L01_004A34A8(s32, s32);
extern void func_L01_004C9500(void);
extern void func_003B3218(s32);
extern void func_L01_00422FE0_00459F60(void);

/* game_mode_apply: leaves the old game mode (D_L01_001D6694) for the one asked for (D_L01_001D6690). */
/* game_mode_apply */
void func_L01_00459F60(void) {
    s32 prev;
    s32 next;
    s32 stay;

    func_L01_004C8BE8();
    prev = D_L01_001D6694;
    next = D_L01_001D6690;
    D_L01_001D668C = prev;
    if (next == -2) {
        return;
    }
    if (D_L01_001D7DBC > 0) {
        D_L01_001D7DBC = D_L01_001D7DBC - 1;
        return;
    }
    if (!((prev == 0 && (D_001D4CEC & 1)) || (prev == 4 && next == 0))) {
        if (D_001A7430[0] == 0) {
            return;
        }
    }
    switch (D_L01_001D6694) {
    case 3:
        if (D_L01_001D6690 != 4 || D_L01_001D7DC0 == 8) {
            func_L01_0047E568();
        }
        break;
    case 4:
        func_L01_00415D78();
        break;
    case 1:
        func_003A8A58();
        D_L01_001E7630[0] = 0.62f;
        func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_003873C0();
        break;
    case 2:
        func_L01_004B9D20();
        D_L01_001E7630[0] = 0.62f;
        func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_003873C0();
        break;
    case 6:
        if (D_L01_001D7DC0 != 4) {
            func_L01_004ACDB0();
        }
        break;
    case 5:
        func_L01_004BBD90();
        break;
    case 7:
        func_L01_004A3548();
        break;
    case 8:
        func_L01_004C97C8();
        break;
    case 9:
        func_L01_00423000_00459F60();
        break;
    case 0: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        break;
    }
    stay = 0;
    func_L01_0045A530(10);
    switch (D_L01_001D6690) {
    case 3: {
        s32 k = D_L01_001D668C;
        if (k != 4 || func_L01_00415CC0_00459F60() == 8 || (D_L01_001D668C == k && func_L01_00415CC0_00459F60() == 11) || D_L01_001D672D != 0) {
            func_L01_0047DDC8(D_L01_001D7DC0);
        }
        stay = 0;
    }
    case 0:
        stay = 0;
        break;
    case 4:
        func_L01_00415DD8(D_L01_001D7DC0, D_L01_001D7DC4);
        break;
    case 1:
        stay = 0;
        func_003A88B8(D_L01_001D7DC4);
        break;
    case 2:
        if (D_L01_001D6694 - 1 >= 2U) {
            if (D_L01_001E6D80.h5E == 0) {
                D_L01_001E6D80.h5E = 1;
                if (D_L01_001DF950[0] > D_L01_001D6720) {
                    D_L01_001D6720 = D_L01_001DF950[0];
                }
                func_L01_0045F328(0);
                func_003A2750(0);
                if (D_L01_001D6720 < 0.25f) {
                    s32 idx = func_003A8770(D_L01_001D7DC0);
                    if (((Wad_459F60 *)D_00160C40)->levels[idx].size > 0) {
                        if (D_001CCFD4[0] != 0) {
                            func_003A2750(1);
                        }
                        func_003A9050();
                        D_L01_001E1070 -= 0x1000;
                        func_003A2598(D_L01_001EA94C[0] + D_L01_001E1070, ((Wad_459F60 *)D_00160C40)->levels[idx].sector + ((Wad_459F60 *)D_00160C40)->base, 1);
                    }
                }
            }
            func_003C4138(&D_L01_001D6720, 1.12f, 0.060000002f);
            D_L01_001DF950[0] = D_L01_001D6720;
            if (1.0f < D_L01_001D6720) {
                D_L01_001DF950[0] = 1.0f;
            }
            if (D_L01_001D6720 >= 1.12f) {
                stay = 0;
                D_L01_001D6720 = 1.0f;
                func_L01_004B9810(D_L01_001D7DC0);
            } else {
                stay = 1;
            }
        } else {
            func_L01_004B9810(D_L01_001D7DC0);
        }
        break;
    case 6:
        if (D_L01_001D9A7C != 0) {
            D_0016C5A6[0] = 1;
            D_L01_001D9928 = 0;
            D_L01_001D9A7C = 0;
        }
        if (D_L01_001D9A74 != 0) {
            D_L01_001DFB44 = 6;
            func_L01_004ACBC8(6);
            D_L01_001D9A74 = 0;
        } else if (D_L01_001D7DC0 == 5) {
            func_00392DF0(D_L01_001D7DC4, 1);
        } else if (D_L01_001D7DC0 == 6) {
            func_L01_004ACD40();
        } else if (D_L01_001D7DC0 == 3) {
            func_L01_004ACBC8(D_001D545C);
        } else {
            if (D_L01_001D668C == 3) {
                if (D_L01_001D6674 != 0) {
                    D_L01_001D6674 = 0;
                    D_L01_001D7DC4 = D_L01_001DFB44;
                }
                func_L01_004ACBC8(D_L01_001D7DC4);
            } else {
                func_L01_004ACB38();
            }
            D_L01_001DFB54 = 1;
        }
        break;
    case 5:
        func_L01_004BB4E0(D_L01_001D7DC0);
        break;
    case 7:
        {
            s32 alt = D_L01_001D9730;
            s32 mode = D_L01_001D7DC0;
            func_L01_004A34A8(mode ? mode : alt, D_L01_001D7DC4);
        }
        break;
    case 8:
        func_L01_004C9500();
        break;
    case 18:
        func_003B3218(D_L01_001D7DC0);
        break;
    case 9:
        func_L01_00422FE0_00459F60();
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17:
        break;
    }
    if (stay == 0) {
        if (D_L01_001D7DCC != 0) {
            *D_L01_001D7DCC = 1;
        }
        D_L01_001D6694 = D_L01_001D6690;
        D_L01_001D6690 = -2;
        D_L01_001D7DCC = 0;
    }
}
/* localdecomp:end func_L01_00459F60 */

INCLUDE_ASM("asm/levels", func_L01_0045A520);

/* localdecomp:start func_L01_0045A530 */
extern s32 D_L01_001D7DB8;

void func_L01_0045A530(s32 arg0) {
    D_L01_001D7DB8 = (s32) ((arg0 * 5) + 2) / 6;
}
/* localdecomp:end func_L01_0045A530 */

/* localdecomp:start func_L01_0045A550 */
extern s32 D_L01_001D7DB8;
__asm__(".extern D_L01_001D7DB8, 4");

void func_L01_0045A550(void) {
    D_L01_001D7DB8--;
    if (D_L01_001D7DB8 < 0) {
        D_L01_001D7DB8 = 0;
    }
}
/* localdecomp:end func_L01_0045A550 */

/* localdecomp:start func_L01_0045A570 */
extern s32 D_L01_001D7DBC;

void func_L01_0045A570(s32 a) {
    D_L01_001D7DBC = a;
}
/* localdecomp:end func_L01_0045A570 */

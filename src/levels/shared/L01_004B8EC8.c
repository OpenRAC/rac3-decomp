#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x30];
    s32 w30;
    s32 w34;
    u8 pad38[4];
    s32 w3C;
    u8 pad40[8];
    s16 h48;
    u8 pad4A[0xE];
    s32 w58;
    u8 pad5C[2];
    s16 h5E;
    u8 pad60[8];
    s32 w68;
    s32 w6C;
    s32 w70;
    s32 w74;
    s32 w78;
    s16 h7C;
    s16 h7E;
    f32 f80;
    f32 f84;
    f32 f88;
    f32 f8C;
} G_004B5C78;
typedef struct {
    u8 pad0[0x25C0];
    s32 w25C0;
    u8 pad25C4[0x21];
    u8 b25E5;
} A_004B5C78;
typedef struct {
    u8 pad0[0xC];
    s32 wC;
    s32 w10;
} H_004B5C78;
typedef struct {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x70];
    s16 h76;
    u8 pad78[0x20];
    s16 h98;
    u8 pad9A[4];
    s16 h9E;
} K_004B5C78;

typedef struct {
    u8 pad0[0x64];
    void (*f64)(void *);
} Obj_004B96E8;

/* localdecomp:start func_L01_004B8EC8 */
s32 func_L01_004B8EC8(void) {
    return 0;
}
/* localdecomp:end func_L01_004B8EC8 */

/* localdecomp:start func_L01_004B8ED0 */
typedef struct {
    u8 p0[0x1E0];
    s16 h1E0;
    u8 p1E2[0x103A];
    u8 b121C;
    u8 p121D[0xB];
    s32 w1228;
    u8 p122C[0x7B4];
    s32 w19E0p;
    u8 p19E4[0xBE0];
    s32 w25C4;
    u8 p25C8[4];
    s32 w25CC;
    u8 p25D0[0x14];
    u8 b25E4;
    u8 p25E5[0xD];
    u8 b25F2;
} H_004B8ED0;
typedef struct {
    u8 p0[0xAA];
    s16 hAA;
} O_004B8ED0;
typedef struct {
    u8 p0[0x1A4];
    s32 w1A4;
    u8 p1A8[8];
    s32 w1B0;
} P_004B8ED0;
typedef struct {
    u8 p0[0x6C];
    u16 h6C;
    u8 p6E[2];
    u32 w70;
    u32 w74;
    u8 p78[0x12C];
    u16 h1A4;
    u8 p1A6[2];
    u32 w1A8;
    u32 w1AC;
} R_004B8ED0;
__asm__(".extern D_L01_001DAB2C, 4");
__asm__(".extern D_L01_001DAB30, 1");
extern H_004B8ED0 D_001A4BE0_004B8ED0;
extern R_004B8ED0 D_001A7C10;
extern P_004B8ED0 *D_001D52FC;
extern s32 D_001D4CEC_sda;
extern s32 D_L01_001D6694_004B8ED0;
extern u8 D_L01_001D672D_004B8ED0;
extern s32 D_L01_001D673C_004B8ED0;
extern s32 D_L01_001D6740_004B8ED0;
extern s32 D_L01_001D6698;
extern s32 D_L01_001DAB2C;
extern u8 D_L01_001DAB30;
extern s32 D_L01_001DBCC0;
typedef struct { s32 a; s32 b; } S_DBCB8;
extern S_DBCB8 D_L01_001DBCB8;
extern s32 D_L01_001DBCC4_004B8ED0;
extern s32 D_L01_001DFB48_004B8ED0;
extern f32 D_L01_001DF950_004B8ED0[1];
extern s32 D_L01_002D15F0_004B8ED0[];
extern u8 D_00143A06[];
extern u8 D_001D4CF4;
extern s32 D_001D545C;
extern s32 D_001D4C38;
extern s32 D_00142660[];
extern s32 D_L01_001DFC28;
extern s32 D_L01_001D7EA0[4];
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern s32 func_L01_00432F50(void);
extern s32 func_L01_00432F68(void);
extern s32 func_L01_004B8EC8_004B8ED0(void);
extern s32 func_L01_00514378_004B8ED0(void);
extern s32 func_L01_00514380_004B8ED0(void);
extern s32 func_L01_005143C0(s32);
extern s32 func_L01_00514490(void);
extern void func_L01_00422480(void);
extern s32 func_L01_0045A520_004B8ED0(void);
extern s32 func_L01_0041A518(s32);
extern s32 func_L01_003F08C0_004B8ED0(void);
extern void func_L01_0045A570(s32);
extern void func_L01_0047DA90_004B8ED0(void);
extern void func_00397C90(void);
extern s32 func_00397CA8(void);
extern void func_L01_005075D8(void);
extern void func_L01_00452508(void);
extern void func_003E4D10(s32);
extern void func_003E54E0(s32);
extern void func_003E5520(void);
extern void func_L01_004C8B38(void);
extern void func_L01_00438EA0(void);
extern void func_003CD058(void);
extern void func_L01_004AB0E0(void);
extern void func_L01_004E20E8(void);
extern void func_003CD350(void);
extern void func_00384D88(void);
extern void func_L01_004A9E58(void);
extern void func_003A4288(void);
extern void func_003D0B20(void);
extern void func_L01_0043AB98(void);
extern void func_00396568(s32);
extern void func_003AF498(void);
extern void func_L01_00478898(void);
extern void func_L01_004788D0(s32);
extern void func_L01_0041AB50(void);
extern void func_003E55B8(void);

void func_L01_004B8ED0(void) {
    s32 flag;
    s32 i;
    s32 r;
    s32 a;
    s32 m;
    P_004B8ED0 *p;
    O_004B8ED0 *o;
    O_004B8ED0 *o2;

    if (D_L01_001D6694_004B8ED0 == 0 && D_L01_001D672D_004B8ED0 == 0 && (D_001D4CEC_sda & 1)) {
        func_003A0EC0(4, 1, 1, 0, 0);
        return;
    }
    if (func_L01_00432F50() && D_L01_001D6694_004B8ED0 == 0 && (D_001D4CEC_sda & 0x600)) {
        if (func_003A0EC0(4, 1, 1, 0, 0) == 0) {
            return;
        }
    }
    if (func_L01_00432F68() && D_L01_001D6694_004B8ED0 == 0 && func_L01_00432F50()) {
        if (func_003A0EC0(4, 1, 1, 0, 0) == 0) {
            return;
        }
    }
    if (func_L01_004B8EC8_004B8ED0() != 0) {
        return;
    }
    flag = D_001A4BE0_004B8ED0.w25C4 != 0x31;
    a = 0;
    o = (O_004B8ED0 *)D_001A4BE0_004B8ED0.w19E0p;
    if (o != 0) {
        s32 h = o->hAA;
        if (h == 0x905 || h == 0x85C || h == 0xEEF || h == 0x10EE) {
            a = 1;
        }
    }
    flag |= a;
    o2 = (O_004B8ED0 *)D_001A4BE0_004B8ED0.w19E0p;
    r = 0;
    if (o2 != 0) {
        r = o2->hAA == 0x1A17;
    }
    flag |= r;
    flag = (flag != 0) | (func_L01_00514378_004B8ED0() != 0);
    flag |= func_L01_005143C0(3) != 0;
    flag |= func_L01_005143C0(5) != 0;
    flag |= func_L01_00514490() != 0;
    func_L01_00422480();

    if ((D_001D52FC->w1B0 & 0x10)
        && !(D_001D52FC->w1A4 & 0x10)
        && D_L01_001DFB48_004B8ED0 >= 8
        && D_001A4BE0_004B8ED0.b25F2 == 0
        && D_001A4BE0_004B8ED0.w25C4 != 0x74
        && D_001A4BE0_004B8ED0.w25C4 != 0x58
        && D_001A4BE0_004B8ED0.w25C4 != 0x39
        && D_001A4BE0_004B8ED0.b121C != 2
        && D_001A4BE0_004B8ED0.w25C4 != 0x31
        && flag != 0
        && D_001A4BE0_004B8ED0.w25C4 != 0x1C
        && D_L01_001D6694_004B8ED0 == 0
        && D_L01_001DF950_004B8ED0[0] < 0.2f
        && (D_001A4BE0_004B8ED0.b25E4 < 2 || D_001A4BE0_004B8ED0.b25E4 == 3)
        && D_L01_002D15F0_004B8ED0[0] == 0
        && D_00143A06[0] != 0) {
        D_L01_001DAB2C++;
        if (D_L01_001DAB2C >= 3) {
            D_L01_001DAB2C = 2;
        }
        if (D_L01_001DAB2C >= 2) {
            func_00397C90();
            if (func_00397CA8() != 0) {
                if (D_001A4BE0_004B8ED0.b25E4 != 1) {
                    func_L01_005075D8();
                }
                func_003A0EC0(4, 1, 7, 0, 0);
                D_L01_001DBCC4_004B8ED0 = D_L01_001DBCC0;
                D_L01_001DBCB8.b = D_L01_001DBCC0;
                return;
            }
        }
    } else {
        D_L01_001DAB2C = 0;
    }

    if (func_L01_0045A520_004B8ED0() == 0) {
        if ((D_001D52FC->w1A4 & 0x800) || D_001D4CF4 != 0) {
            if (D_L01_001DFB48_004B8ED0 >= 8) {
                if (D_001A4BE0_004B8ED0.w25C4 != 0x74 && D_001A4BE0_004B8ED0.w25C4 != 0x58) {
                    if (D_001A4BE0_004B8ED0.b121C != 2 || D_001A4BE0_004B8ED0.w1228 == 9) {
                        if (flag != 0 && D_L01_001D6694_004B8ED0 == 0 && D_001A4BE0_004B8ED0.h1E0 == 0) {
                            if (D_L01_001DAB30 != 0) {
                                func_003A0EC0(3, 1, 8, 0, 0);
                            } else if (func_L01_0041A518(D_001D545C) != 0) {
                                func_003A0EC0(3, 1, 5, 0, 0);
                            } else {
                                func_003A0EC0(3, 1, 1, 0, 0);
                            }
                            func_L01_0045A570(func_L01_003F08C0_004B8ED0() != 0);
                            func_L01_0047DA90_004B8ED0();
                            return;
                        }
                    }
                }
            }
        }
    }

    if (D_001A4BE0_004B8ED0.h1E0 == 0 && D_L01_001DFB48_004B8ED0 >= 8) {
        if ((D_001D52FC->w1A4 & 0x500) && D_001A4BE0_004B8ED0.w25CC != 0x16) {
            if (D_001A4BE0_004B8ED0.w25C4 != 0x74 && D_001A4BE0_004B8ED0.w25C4 != 0x58 && flag != 0 && D_001A4BE0_004B8ED0.w25C4 != 0x1C && D_001A4BE0_004B8ED0.w25C4 != 0xB0 && D_001A4BE0_004B8ED0.w25C4 != 0x16 && D_001A4BE0_004B8ED0.w25C4 != 0x39
                && D_L01_001D6694_004B8ED0 == 0 && !(func_L01_00514378_004B8ED0() != 0 && func_L01_00514380_004B8ED0() != 0)
                && func_L01_0041A518(D_001D545C) == 0) {
                if (D_L01_001D673C_004B8ED0 != 0 && D_L01_001D6740_004B8ED0 == 0) {
                    R_004B8ED0 *q;
                    s32 x;
                    if (D_001D545C == 0x1A || (D_001A4BE0_004B8ED0.w25C4 != 0x5F && D_001A4BE0_004B8ED0.w25C4 != 0x5C)) {
                        func_003A0EC0(4, 1, 6, 0, 0);
                    }
                    q = &D_001A7C10;
                    if (q->h1A4 <= 0xFFFE) {
                        q->h1A4++;
                    }
                    x = D_001D4C38;
                    x = (x * 5 + 2) / 6;
                    if (q->w1A8 < x) {
                        q->w1A8 = x;
                    }
                    q->w1AC = q->w1AC | (1 << D_001D545C) | 0x80000000;
                    return;
                } else {
                    R_004B8ED0 *q;
                    s32 x;
                    func_003A0EC0(3, 1, 2, 0, 0);
                    func_L01_0045A570(func_L01_003F08C0_004B8ED0() != 0);
                    q = &D_001A7C10;
                    if (q->h6C <= 0xFFFE) {
                        q->h6C++;
                    }
                    x = D_001D4C38;
                    x = (x * 5 + 2) / 6;
                    if (q->w70 < x) {
                        q->w70 = x;
                    }
                    q->w74 = q->w74 | (1 << D_001D545C) | 0x80000000;
                    return;
                }
            }
        }
    }
    if (D_001A4BE0_004B8ED0.w25C4 != 0x1C) {
        func_L01_00452508();
    }
    p = D_001D52FC;
    if ((p->w1A4 & 0x200) && D_001A4BE0_004B8ED0.w25C4 != 0x1C && D_001A4BE0_004B8ED0.w25C4 != 0x31
        && D_001A4BE0_004B8ED0.b25E4 != 2 && (u32)(D_001D545C - 0x1E) >= 6) {
        func_003E4D10(300);
        func_003E54E0(150);
    }
    m = D_L01_001DFC28;
    if (m != 0) {
        if (func_003A0EC0(6, 1, 0, 0, 0) == 0) {
            func_L01_0045A570(func_L01_003F08C0_004B8ED0() != 0);
            D_L01_001DFC28 = 0;
            return;
        }
    }
    func_003E5520();
    func_L01_004C8B38();
    func_L01_00438EA0();
    func_003CD058();
    func_L01_004AB0E0();
    func_L01_004E20E8();
    func_003CD350();
    qzero(D_L01_001D7EA0);
    func_00384D88();
    if (D_L01_001D6698 != 0) {
        func_L01_004A9E58();
    } else {
        func_003A4288();
    }
    func_003D0B20();
    func_L01_0043AB98();
    if (D_00142660[0] > 99999999) {
        D_00142660[0] = 99999999;
    }
    func_00396568(1);
    func_003AF498();
    func_L01_00478898();
    for (i = 0; i <= 0; i++) {
        func_L01_004788D0(i);
    }
    func_L01_0041AB50();
    func_003E55B8();
}
/* localdecomp:end func_L01_004B8ED0 */

/* localdecomp:start func_L01_004B96E8 */
extern s32 D_L01_001D6694_004B96E8;
extern s32 D_001D4CEC_sda;
extern Obj_004B96E8 *D_L01_001D9730_004B96E8;

extern void func_00392260(s32, s32, s32);
extern s32 func_003A0EC0_004B96E8(s32, s32, s32, s32, u8 *);
extern s32 func_L01_004B8EC8_004B96E8(void);
extern void func_003E5520_004B96E8(void);
extern void func_003A4288_004B96E8(void);
extern void func_003CD350(void);
extern void func_L01_00438EA0(void);
extern void func_003E55B8_004B96E8(void);
extern void func_L01_0041AB50_004B96E8(void);

void func_L01_004B96E8(void) {
    Obj_004B96E8 *object;

    func_00392260(0, 0, 0);
    if (D_L01_001D6694_004B96E8 == 0 && (D_001D4CEC_sda & 1)) {
        func_003A0EC0_004B96E8(4, 1, 1, 0, 0);
        return;
    }
    if (func_L01_004B8EC8_004B96E8() != 0) {
        return;
    }
    func_003E5520_004B96E8();
    func_003A4288_004B96E8();
    func_003CD350();
    func_L01_00438EA0();
    object = D_L01_001D9730_004B96E8;
    object->f64(object);
    func_003E55B8_004B96E8();
    func_L01_0041AB50_004B96E8();
}
/* localdecomp:end func_L01_004B96E8 */

/* localdecomp:start func_L01_004B9798 */
typedef struct {
    char p0[32];
    u8 f20;
    char p21[19];
    u16 f34;
    char p36[116];
    s16 fAA;
    char pAC[84];
} Type1;
extern Type1 *D_L01_001E0020;

/* from rac4-decomp's func_004E55C0 */
void func_L01_004B9798(s32 enabled)
{
    Type1 *p = D_L01_001E0020;
    while (p->f20 != 255) {
        if (!(p->f20 & 128) && (p->fAA == 0x183A || p->fAA == 0x183C)) {
            if (enabled)
                p->f34 |= 128;
            else
                p->f34 &= 0xFF7F;
        }
        p++;
    }
}
/* localdecomp:end func_L01_004B9798 */

/* localdecomp:start func_L01_004B9810 */




extern u32 D_00142BA0[];
extern s32 D_L01_001EA7C0[];
extern G_004B5C78 D_L01_001E6D80;
extern s32 D_L01_001E14A0;
extern s32 D_L01_001E13E0;
extern u8 D_L01_00251400[][64];
extern s32 D_L01_001E1420;
extern s32 D_L01_001E1460;
extern u8 D_L01_00244500[][64];
extern s32 D_L01_001E1070;
extern H_004B5C78 D_L01_001EA940;
extern f32 D_L01_001D6718;
extern s32 D_L01_001D671C;
extern f32 D_L01_001DF950[1];
extern s32 D_L01_001DF958[1];
extern A_004B5C78 D_001A4BE0;
extern u8 D_L01_001DF9E4;
extern u8 D_L01_001DF9E5;
extern u8 D_L01_001DF9E6;
extern f32 D_L01_001DF9E8;
extern f32 D_L01_001DF9EC;
extern f32 D_L01_001DF9F0;
extern f32 D_L01_001DF9F4;
extern s32 D_L01_001D6694;
extern s32 D_L01_001D6720;
extern u8 *D_L01_001DFC18;
extern K_004B5C78 D_001CCFD0;
extern s32 D_L01_001DF95C;
extern s32 D_L01_001DF960;
extern u8 D_00143950[];
extern s32 D_001D545C;

extern void func_00392BB8(s32 *);
extern s32 func_003A8770(s32);
extern void func_L01_0045F328(s32);
extern void func_003A2750(s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_0041A6E0(void);
extern s32 func_L01_005003D0(s32, s32);
extern void func_L01_005108C0(s32);
extern void func_L01_004AC840(void);
extern void func_L01_0042C3C0(s32, s32);
extern s32 func_L01_0042C1F8(s32, s32);
extern s32 func_L01_0042C458(s32);
extern void func_L01_0042C278(void);
extern void func_L01_004B9798(s32);
extern void func_0039A438(void);
extern void func_L01_0040E2B0(s32, s32, s32);
extern void func_003A1F30(void);
extern void func_003A2B68(s32, s32);
extern void func_L01_00460228(void);
extern void func_003A4288(void);
extern s32 func_0012C908(s32);
extern void func_L01_00460200_004B9810(f32);
extern void func_003A1798(void);

void func_L01_004B9810(s32 a0) {
    s32 id;
    s32 i;
    s32 j;
    s32 k;
    f32 *pf;
    s32 *pi;
    s32 v;
    s32 w;
    s32 lo;
    s32 hi;
    s32 r;

    if (a0 >= 0) {
        u32 *bits = &D_00142BA0[(u32)a0 >> 2];
        *bits |= 1 << (a0 & 0x1F);
    }
    func_00392BB8(D_L01_001EA7C0);
    id = func_003A8770(a0);
    if (id < 0) {
        return;
    }
    if (D_L01_001E6D80.h5E == 0) {
        func_L01_0045F328(0);
        func_003A2750(0);
    }
    func_0038CB78(&D_L01_001E6D80, 0, 480);
    func_0038CB78(&D_L01_001E14A0, 0, 64);
    func_0038CB78(&D_L01_001E13E0, 0, 64);
    func_0038CB78(D_L01_00251400[0], 0, 64);
    func_0038CB78(D_L01_00251400[1], 0, 64);
    func_0038CB78(&D_L01_001E1420, 0, 64);
    func_0038CB78(&D_L01_001E1460, 0, 64);
    for (j = 0; j < 7; j++) {
        func_0038CB78(D_L01_00244500[j], 0, 64);
    }
    D_L01_001D6718 = 1.0f;
    D_L01_001D671C = 0;
    D_L01_001E6D80.w30 = id;
    D_L01_001E6D80.w34 = 0;
    D_L01_001E6D80.w3C = 0;
    D_L01_001E1070 -= 0x90000;
    D_L01_001E6D80.w68 = D_L01_001EA940.wC + D_L01_001E1070;
    D_L01_001E6D80.w6C = D_L01_001E6D80.w68 + 0x60000;
    D_L01_001E6D80.w58 = D_L01_001EA940.w10 + D_L01_001E1070;
    func_L01_0041A6E0();
    pi = D_L01_001DF958;
    pf = D_L01_001DF950;
    for (k = 0; k < 1; k++) {
        *pf++ = 1.0f;
        *pi++ = 0;
    }
    D_L01_001D6694 = 2;
    D_L01_001E6D80.w70 = D_L01_001DF9E4;
    D_L01_001E6D80.w74 = D_L01_001DF9E5;
    D_L01_001E6D80.w78 = D_L01_001DF9E6;
    D_L01_001E6D80.f80 = D_L01_001DF9E8;
    D_L01_001E6D80.f84 = D_L01_001DF9EC;
    D_L01_001E6D80.f88 = D_L01_001DF9F0;
    D_L01_001E6D80.f8C = D_L01_001DF9F4;
    D_L01_001D6720 = 0;
    if (D_001A4BE0.w25C0 != 0) {
        func_L01_005003D0(101, 2);
        D_001A4BE0.b25E5 = 1;
        func_L01_005108C0(0);
    }
    func_L01_004AC840();
    if (D_L01_001DFC18 != 0) {
        *(u16 *)(D_L01_001DFC18 + 0x34) |= 1;
    }
    D_L01_001DF95C = 1;
    D_L01_001DF960 = 52;
    if (D_001CCFD0.h4 != 0) {
        func_003A2750(1);
    }
    if (D_00143950[6] != 0) {
        func_L01_0042C3C0(D_001D545C, id);
    }
    r = func_L01_0042C1F8(D_001D545C, id);
    func_L01_0042C458(0);
    if (r != 0) {
        func_L01_0042C278();
    }
    func_L01_004B9798(1);
    if (D_001CCFD0.h4 != 0) {
        func_003A2750(1);
    }
    func_0039A438();
    if (D_L01_001E6D80.h7E != 0 && D_L01_001E6D80.h7C != 0) {
        lo = D_L01_001E6D80.h7E << 11;
        hi = D_L01_001E6D80.h7C << 11;
        if (lo <= 0x2FFFF) {
            if (hi <= 0x5FFFF) {
                v = D_L01_001EA940.wC + D_L01_001E1070 + 0x90000;
                v -= lo;
                func_L01_0040E2B0(v, D_L01_001E6D80.w6C, lo);
                D_L01_001E6D80.w6C = v;
                D_L01_001E6D80.w68 = v - hi;
                func_0039A438();
                D_L01_001E1070 = D_L01_001E6D80.w68 - D_L01_001EA940.wC;
                w = D_L01_001E6D80.w58 - D_L01_001EA940.w10;
                if (w < D_L01_001E1070) {
                    D_L01_001E1070 = w;
                }
            }
        }
    }
    if (D_001CCFD0.h76 != 6 && D_001CCFD0.h76 != 7) {
        D_001CCFD0.h76 = 5;
    }
    if (D_001CCFD0.h9E != 6 && D_001CCFD0.h9E != 7) {
        D_001CCFD0.h9E = 5;
    }
    func_003A1F30();
    func_003A2B68(D_L01_001E6D80.w30, 0);
    func_L01_00460228();
    i = 0;
    for (;;) {
        func_003A4288();
        func_0012C908(0);
        if (i > 300) {
            break;
        }
        i++;
        if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 7000) {
            break;
        }
    }
    func_L01_00460200_004B9810(0.82f);
    i = 0;
    D_L01_001E6D80.h48 = -3;
    func_003A1798();
    func_L01_0042C458(1);
    while (D_L01_001E6D80.h48 < i) {
        func_0012C908(0);
        i--;
    }
}
/* localdecomp:end func_L01_004B9810 */

INCLUDE_ASM("asm/levels", func_L01_004B9D20);

LINKER_REMNANT("asm/levels", func_L01_004BA0A0);

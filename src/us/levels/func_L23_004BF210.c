#include "common.h"
#include "vu0.h"
typedef struct { f32 v[4]; } __attribute__((aligned(16))) V4_4C2CE8;
typedef struct { u8 p0[0x10]; u8 b10; } A_4C2CE8;
typedef struct { u8 p0[0x48]; A_4C2CE8 *a48[1]; } C_4C2CE8;
typedef struct {
    u8 p0[5];
    u8 b5;
    u8 p6[2];
    f32 f8;
    u8 pC[0x15];
    u8 b21;
    u8 p22[6];
    f32 f28;
} I_4C2CE8;
typedef struct {
    u8 p0[0x10];
    V4_4C2CE8 v10;
    u8 p20[4];
    C_4C2CE8 *p24;
    u8 p28[0xC];
    u16 h34;
    u8 p36[0xA];
    u8 b40, b41, b42, b43;
    f32 f44, f48, f4C;
    u8 p50[8];
    s32 w58;
    s32 w5C;
    u8 p60[0xF];
    u8 b6F;
    u8 p70[0x50];
    u8 aC0[0x30];
    u8 aF0[0x10];
} M_4C2CE8;
typedef struct {
    V4_4C2CE8 v0;
    u8 p10[0x80 - 0x10];
    V4_4C2CE8 v80;
    V4_4C2CE8 v90;
    u8 pA0[0x1E0 - 0xA0];
    s16 h1E0;
    s16 h1E2;
    u8 p1E4[0x238 - 0x1E4];
    s32 w238;
    u8 p23C[0x35C - 0x23C];
    s32 w35C;
    u8 p360[0x500 - 0x360];
    V4_4C2CE8 v500;
    u8 p510[0xBF8 - 0x510];
    M_4C2CE8 *wBF8;
    u8 pBFC[0x1420 - 0xBFC];
    V4_4C2CE8 v1420;
    u8 p1430[4];
    s16 h1434;
    u8 b1436;
    u8 p1437;
    f32 f1438;
    u8 p143C[0x16B0 - 0x143C];
    s32 w16B0;
    u8 p16B4[0x1A80 - 0x16B4];
    I_4C2CE8 *w1A80;
    u8 p1A84[0x1A8C - 0x1A84];
    s32 w1A8C;
    s32 w1A90;
    s32 w1A94;
    s32 w1A98;
    u8 p1A9C[0x22C0 - 0x1A9C];
    V4_4C2CE8 v22C0;
    u8 p22D0[0x25C0 - 0x22D0];
    M_4C2CE8 *w25C0;
    s32 w25C4;
    u8 p25C8[0x25E4 - 0x25C8];
    u8 b25E4;
    u8 p25E5[0x25F8 - 0x25E5];
    s32 w25F8;
    u8 p25FC[0x2838 - 0x25FC];
    f32 f2838;
    u8 p283C[0x286C - 0x283C];
    u8 *p286C;
    u8 p2870[0x2888 - 0x2870];
    s16 h2888;
    s16 h288A;
    s16 h288C;
    u8 p288E[0x28A8 - 0x288E];
    s16 h28A8;
    s16 h28AA;
} G_4C2CE8;

extern G_4C2CE8 D_001A4BE0;

/* NTSC-U counterpart of func_L23_004C2EF0. */
/* localdecomp:start func_L23_004BF210 */
extern u8 *D_001D52FC;
extern s32 D_L23_001DBDAC;
__asm__(".extern D_L23_001DBDAC, 4");
extern f32 D_L23_001DBD0C;
__asm__(".extern D_L23_001DBD0C, 4");
extern u8 *D_L23_001DE310;
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L23_00309720(void *);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern void func_L23_00309600(void *, V4_4C2CE8, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_00439D70(void *, void *);
extern u8 *func_L01_00439CB8(void *, s32, s32, s32);
extern void func_L01_0043A1E8(void *, u8 *, s32, s32, s32, s32);
extern void func_L01_00439E10(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00450E48(void *, void *, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern u8 *func_L23_0042FAB8(void *, V4_4C2CE8 *, V4_4C2CE8 *, f32, f32, void *, void *, void *);
extern s32 func_L01_004F4E70(s32, s32);
extern u8 *func_L23_00336B70(void *src, V4_4C2CE8 *pos, s32 arg);

void func_L23_004BF210(void)
{
    V4_4C2CE8 buf;
    V4_4C2CE8 q;
    s32 a[3];
    s32 far;
    s32 i;
    f32 ang;

    if (D_001A4BE0.h1E0 != 0 || D_001A4BE0.w25C4 == 0x74) {
        return;
    }
    if (D_001A4BE0.w25C4 == 1 && D_001A4BE0.w1A98 == 0 && func_L01_004606E8(0x10, 7, 0, 0) != 0 && func_L23_00309720(D_001A4BE0.w25C0) == 0) {
        D_001A4BE0.w1A98 = 0xB4;
        func_L01_005110E8(&buf, 1, 2.0f, -2.1f, 8.7f);
        func_L23_00309600(D_001A4BE0.w25C0, buf, 1);
    }
    far = 1;
    if (D_001A4BE0.w25C4 == 0x61 || D_001A4BE0.w25C4 == 0x62) {
        far = 0;
    }
    if (D_001A4BE0.w1A8C != 0) {
        if (D_001A4BE0.w1A80 != 0) {
            if (D_001A4BE0.w1A80->b5 & 2) {
                D_001A4BE0.w1A90 = 1;
            }
            if (D_001A4BE0.w1A90 != 0) {
                if (D_001A4BE0.w1A80->f8 == 0.0f) {
                    func_L01_00439D70(D_001A4BE0.w25C0, &D_001A4BE0.w1A80);
                    D_001A4BE0.w1A8C = 0;
                    return;
                }
                func_003C4138(&D_001A4BE0.w1A80->f8, 0.0f, 0.07f);
            }
        } else {
            D_001A4BE0.w1A8C = 0;
        }
        if (D_001A4BE0.w1A8C != 0) {
            if (!(*(s32 *)(D_001D52FC + 0x1A0) & 0x20) || !far) {
                if (D_001A4BE0.w1A80 != 0) {
                    if (D_001A4BE0.w1A80->b5 & 2) {
                        D_001A4BE0.w1A90 = 1;
                    }
                    if (D_001A4BE0.w1A90 != 0) {
                        if (D_001A4BE0.w1A80->f8 == 0.0f) {
                            func_L01_00439D70(D_001A4BE0.w25C0, &D_001A4BE0.w1A80);
                            D_001A4BE0.w1A8C = 0;
                            return;
                        }
                        func_003C4138(&D_001A4BE0.w1A80->f8, 0.0f, 0.07f);
                    }
                } else {
                    D_001A4BE0.w1A8C = 0;
                }
            } else {
                D_001A4BE0.w1A90 = 0;
            }
            if (D_001A4BE0.w1A8C != 0) {
                goto active;
            }
        }
    }
    if (far && func_L01_004606E8(0x20, 8, 0, 0) != 0) {
        u8 *t = func_L01_00439CB8(D_001A4BE0.w25C0, 2, D_L23_001DBDAC, 0xFC0);
        D_001A4BE0.w1A90 = 0;
        D_001A4BE0.w1A80 = (I_4C2CE8 *)t;
        if (t != 0) {
            D_001A4BE0.w1A8C = 1;
            func_L01_0043A1E8(D_001A4BE0.w25C0, t, 0xD, 0, 9, 1);
        }
    }
    if (D_001A4BE0.w1A8C == 0) {
        return;
    }
active:
    if (D_001A4BE0.w1A80 == 0 || D_001A4BE0.w1A90 != 0) {
        return;
    }
    func_003C4138(&D_001A4BE0.w1A80->f8, 1.0f, 0.13f);
    D_001A4BE0.w1A80->f28 = 2.0f;
    func_L01_00439E10(D_001A4BE0.w25C0, D_001A4BE0.w1A80);
    func_0038CAD0(&D_001A4BE0.w1A94);
    if (D_001A4BE0.w1A80->b21 != 4 || D_001A4BE0.w1A94 != 0) {
        return;
    }
    D_001A4BE0.w1A94 = 5;
    for (i = 0; i < 2; i++) {
        u8 *t = 0;
        func_003C2F58(D_001A4BE0.w25C0, i + 3, &buf);
        func_L01_00450E48(D_001A4BE0.w25C0, &buf, D_L23_001DBD0C * 1.4f, 0.0f, 0.0f);
        if (D_L23_001DE310 != 0) {
            ang = func_0038D160(*(f32 *)(D_L23_001DE310 + 0x10) - D_001A4BE0.v80.v[0], *(f32 *)(D_L23_001DE310 + 0x14) - D_001A4BE0.v80.v[1]);
            if (func_0038DBA0(D_001A4BE0.v90.v[2], ang) < 0.9599311f && func_0038CF38(&D_001A4BE0.v80, D_L23_001DE310 + 0x10) < 50.0f) {
                t = D_L23_001DE310;
            }
        }
        if (t == 0) {
            q = D_001A4BE0.v0;
            t = func_L23_0042FAB8(D_001A4BE0.w25C0, &buf, &q, 0.34906584f, 10000.0f, &a[0], &a[1], &a[2]);
        }
        func_L01_004F4E70(5, 0);
        func_L23_00336B70(D_001A4BE0.w25C0, &buf, (s32)t);
    }
}
/* localdecomp:end func_L23_004BF210 */

#include "common.h"
#include "vu0.h"
typedef struct { f32 v[4]; } __attribute__((aligned(16))) V4_4C2CE8;
typedef struct { V4_4C2CE8 m[4]; } Mtx_4C2CE8;
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
typedef struct {
    u8 p0[0x12F8];
    f32 f12F8;
    u8 p12FC[0x1334 - 0x12FC];
    f32 f1334;
    f32 f1338;
    u8 p133C[0x1458 - 0x133C];
    f32 f1458;
    u8 p145C[0x1494 - 0x145C];
    f32 f1494;
    f32 f1498;
} S_4C3330;

extern G_4C2CE8 D_001A4BE0;
extern s32 D_001D545C;
extern u8 D_L23_00254D40[];
extern void func_003C2EC0(void *, s32, Mtx_4C2CE8 *);
extern void func_0038D590(void *, void *);
extern void func_003C48A8(void *, void *);
extern s32 func_L01_004DFCC8(M_4C2CE8 *, s32, s32, void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_003C7C38(void *);
extern u8 *D_001D52FC;
extern s32 D_L23_001DBD6C;
extern f32 D_L23_001DBD0C;
extern u8 *D_L23_001DE2D0;
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern s32 func_L23_003099A8(void *);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern void func_L23_00309888(void *, V4_4C2CE8, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_00439D70(void *, void *);
extern u8 *func_L01_00439CB8(void *, s32, s32, s32);
extern void func_L01_0043A1E8(void *, u8 *, s32, s32, s32, s32);
extern void func_L01_00439E10(void *, void *);
extern s32 func_00388398(void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_0044DBC8(void *, void *, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern u8 *func_L23_00432D60(void *, V4_4C2CE8 *, V4_4C2CE8 *, f32, f32, void *, void *, void *);
extern s32 func_L01_004F4E70(s32, s32);
extern u8 *func_L23_003373D0(void *src, V4_4C2CE8 *pos, s32 arg);

/* localdecomp:start func_L23_004BF658 */
extern G_4C2CE8 D_001A4BE0;
extern S_4C3330 D_L23_002F55C0;
extern f32 D_L23_002F679C[];
__asm__(".extern D_L23_002F679C, 16");
extern f32 D_L23_002F69AC[];
__asm__(".extern D_L23_002F69AC, 16");
extern s32 D_L23_001D673C;
extern u8 D_001D5470;
__asm__(".extern D_001D5470, 16");
extern f32 D_L23_001DBD0C;
__asm__(".extern D_L23_001DBD0C, 4");
extern f32 D_L23_001DBD3C;
__asm__(".extern D_L23_001DBD3C, 4");
extern void func_L01_0050BF58(void);
extern void func_L01_004EA708(void);
extern void func_L01_004E3EF0(void);
extern s32 func_L01_004E4550(s8 *, s8 *, s8 *);
extern void func_L01_004EFDD8(void);
extern s32 func_00388398(void *);
extern void func_L01_0044DBC8(void *, void *, f32, f32, f32);
extern void func_L01_00443648(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern f32 func_L01_004F1018(void *, int);
extern f32 func_003893C8(f32, f32);
extern void func_L01_004DCF08(void);
extern void func_L01_004DCFA0(void);
extern void func_L23_004E6F00(void);
extern void func_L01_004C8A20(void);
extern void func_L01_004F1208(void);
extern void func_L01_004DC790(void);
extern void func_L01_004E09A8(void);
extern void func_L01_004DF380(void);
extern void func_L01_0050EE90(void);
extern void func_L01_004DF108(void);
extern void func_L01_004DCC10(void);
extern void func_L01_004DCFC8(void);
extern void func_L01_004DD310(void);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0042D288(void *);
void func_L23_004BF210(void);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_004DF4A0(void);
extern void func_L01_004E0B00(void);
extern void func_L01_004405F4(void *);

void func_L23_004BF658(void)
{
    V4_4C2CE8 v;
    f32 f;

    func_L01_0050BF58();
    func_L01_004EA708();
    func_L01_004E3EF0();
    if (D_001A4BE0.b25E4 == 1) {
        func_L01_004E4550((s8 *)&D_001A4BE0.v80, (s8 *)&D_001A4BE0.v90, (s8 *)&D_001A4BE0.v500);
        func_L01_004EFDD8();
    }
    if (D_001A4BE0.b25E4 == 2) {
        func_00388398(&D_001A4BE0.w1A98);
        if (D_001A4BE0.w35C != 0) {
            func_L01_0044DBC8(D_001A4BE0.w25C0, &v, 0.0f, 0.0f, D_L23_001DBD0C * 2.5f);
            vec_add_ab(&v, &v, &D_001A4BE0.v80);
            func_L01_00443648((u8 *)D_001A4BE0.w25C0, (u8 *)&v, 0x80000, 0, 1, 0, D_L23_001DBD0C * 4.0f, 100.0f, 1.0f);
        }
        if (D_001A4BE0.h1434 != 0 || (D_001A4BE0.w16B0 == 1 && func_L01_0045D358(0x28, 2, 0, 0) != 0)) {
            if (0.15f < D_001A4BE0.f2838 && D_001A4BE0.b1436 == 0) {
                D_L23_002F55C0.f1498 = 0.27f;
                D_L23_002F55C0.f1494 = 0.037f;
                D_L23_002F55C0.f1334 = 0.025f;
                D_L23_002F55C0.f1338 = 0.27f;
                if (D_L23_001D673C != 0) {
                    f = func_L01_004F1018(&D_001A4BE0.v1420, 0);
                } else {
                    f = func_003893C8(D_001A4BE0.f1438, D_001A4BE0.v90.v[2]);
                }
                D_L23_002F55C0.f1458 = f;
                D_L23_002F55C0.f12F8 = -f;
            }
        }
    }
    if (D_001A4BE0.b25E4 == 1) {
        func_L01_004DCF08();
        func_L01_004DCFA0();
    }
    D_001A4BE0.w238 = 4;
    func_L23_004E6F00();
    func_L01_004C8A20();
    if (D_001A4BE0.b25E4 == 0) {
        return;
    }
    func_L01_004F1208();
    func_L01_004DC790();
    if (D_001A4BE0.b25E4 == 0) {
        return;
    }
    func_L01_004E09A8();
    func_L01_004DF380();
    func_L01_0050EE90();
    func_L01_004DF108();
    if (D_001A4BE0.b25E4 == 1) {
        D_L23_002F679C[0] = D_L23_001DBD3C;
        func_L01_004DCC10();
        func_L01_004DCFC8();
        func_L01_004DD310();
        if (D_001A4BE0.p286C != 0) {
            func_0039FE80((s32)(D_001A4BE0.p286C + 0x10), 0, D_001A4BE0.w25C0);
            D_001A4BE0.h28A8 = 0x39;
            D_001A4BE0.h28AA = (s32)D_001A4BE0.p286C;
        }
        D_001A4BE0.p286C = 0;
    }
    func_L01_0042D288(&D_001A4BE0.v80);
    if (D_001A4BE0.b25E4 == 2) {
        if (D_001D5470 != 0) {
            D_L23_002F69AC[0] = D_L23_001DBD3C * 1.4f;
        }
        if (D_001A4BE0.h1E2 < 10000) {
            D_001A4BE0.h1E2++;
        }
        func_L01_004DCC10();
        func_L23_004BF008();
        func_L23_004BF210();
        if ((*(u8 *)&D_001A4BE0.w25C0->h34 ^ 1) & 1) {
            func_003BDA38(D_001A4BE0.w25C0, 6, &v);
            D_001A4BE0.v22C0 = v;
            func_L01_004DF4A0();
        }
    }
    if (D_001A4BE0.b25E4 == 3) {
        if (D_001A4BE0.w25F8 != 0 && D_001A4BE0.w25F8 != 0x1E) {
            if (D_001A4BE0.h288C == 0) {
                D_001A4BE0.h2888 = 1;
                D_001A4BE0.h288C = 0x12;
                D_001A4BE0.h288A = 1;
            }
        } else {
            D_001A4BE0.w25F8 = 0;
        }
    }
    func_L01_004E0B00();
    func_L01_004405F4(D_001A4BE0.w25C0);
}
/* localdecomp:end func_L23_004BF658 */

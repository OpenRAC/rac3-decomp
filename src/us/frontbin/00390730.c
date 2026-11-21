#include "common.h"

/* NTSC-U version of func_00394F90 (frontbin): 150 -> 180 */
#include "common.h"





extern s32 D_U_001D5CAC;
extern s32 D_U_001D9FAC;
extern s32 D_U_001D9FB0;
extern s32 D_U_001D9FA8;
extern void func_U_003DE8B8(void);
extern void func_U_003DE870(void);
extern s32 func_U_0039FF28(s32, s32, s32);
extern f32 func_U_00388A28(f32, f32);
extern s32 func_U_0038EC80(s32);
typedef struct { u8 p0[0x64]; s32 f64; u8 p68[4]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_390730;
typedef struct { u8 p0[0x148]; f32 f148; f32 f14C; u8 p150[0x70]; s32 f1C0; s32 f1C4; s32 f1C8; s32 f1CC; } P_390730;
typedef struct { u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; } T_390730;
typedef struct { u8 p0[0x286C]; s32 f286C; } G_390730;
extern P_390730 *D_001D52FC_00394F90;
extern s16 D_U_001D9F34;
extern s16 D_U_001D9F38;
extern s16 D_U_001D9F3A;
extern s16 D_U_001D9F3C;
extern s32 D_U_001D9F68_00394F90;
extern s32 D_U_001D9F70_00394F90;
extern s32 D_U_001D9C48_00394F90;
extern s32 D_U_001D9FA8;
extern s32 D_U_001D9FAC;
extern s32 D_U_001D9FB0;
extern u8 D_00143A06[];
extern G_390730 D_001A4BE0_00394F90;
extern void func_U_003DE8B8(void);
extern f32 func_U_00388A28(f32, f32);
extern s32 func_U_0039FF28(s32, s32, s32);
extern void func_U_003DE870(void);
extern s32 func_U_0038EC80(s32);
/* localdecomp:start func_U_00390730 */
#include "vu0.h"
/* nav defaults: D_001D5D00..0C (func_00393C40's menu) and D_001D5D20..2C (this one) */
extern s32 D_U_001D5D00_00394F90[12] __attribute__((section(".sdata")));
extern s32 func_U_0037E368(s32, s32, s32, s32, s32, s32);
void func_U_00390730(S_390730 *p) {
    u8 *b = p->b70;
    f32 x, y, len, ang;
    s32 old;
    func_U_003DE8B8();
    p->f7C = 180;
    p->f6C = 24;
    {
        P_390730 *pd = D_001D52FC_00394F90;
        pd->f1CC = 2;
        x = pd->f148;
        y = pd->f14C;
    }
    len = sqrt_asm(x * x + y * y);
    if (len != 0.0f) {
        x = x / len;
        y = y / len;
    }
    ang = func_U_00388A28(x, y);
    if ((p->f78 >> 24) == 0 && D_U_001D9F34 != 0) {
        if ((D_001D52FC_00394F90->f1C4 & 0xF000) || len < 0.5f || (p->f78 = p->f78 - 1) == -1) {
            p->f74 = -1;
            p->f78 = 0x10000FF;
        }
    }
    old = p->f74;
    if (((s8 *)&p->f78)[3] == 1) {
        if (0.0f < len) {
            if (0.9f < len) {
                s32 n;
                f32 a;
                a = ang + 3.1415927f;
                n = D_U_001D9F68_00394F90;
                a = a + 3.1415927f;
                p->f74 = (s32)((a + 1.5707964f + 3.1415927f / (f32)n) * ((f32)n / 6.2831855f)) % n;
            }
        } else {
            if (D_001D52FC_00394F90->f1C4 & 0xF000) {
                s32 sel = old;
                s32 t;
                if (D_001D52FC_00394F90->f1C4 & 0x1000) {
                    if (sel == -1) t = D_U_001D5D00_00394F90[10]; else t = ((T_390730 *)(((s32 *)D_U_001D9F70_00394F90)[D_U_001D5CAC] + sel * 0x1C))->f10; sel = t;
                }
                if (D_001D52FC_00394F90->f1C4 & 0x4000) {
                    if (sel == -1) t = D_U_001D5D00_00394F90[11]; else t = ((T_390730 *)(((s32 *)D_U_001D9F70_00394F90)[D_U_001D5CAC] + sel * 0x1C))->f14; sel = t;
                }
                if (D_001D52FC_00394F90->f1C4 & 0x8000) {
                    if (sel == -1) t = D_U_001D5D00_00394F90[8]; else t = ((T_390730 *)(((s32 *)D_U_001D9F70_00394F90)[D_U_001D5CAC] + sel * 0x1C))->f8; sel = t;
                }
                if (D_001D52FC_00394F90->f1C4 & 0x2000) {
                    if (sel == -1) t = D_U_001D5D00_00394F90[9]; else t = ((T_390730 *)(((s32 *)D_U_001D9F70_00394F90)[D_U_001D5CAC] + sel * 0x1C))->fC; sel = t;
                }
                p->f74 = sel;
            }
        }
    }
    if (p->f74 != old) {
        func_U_0037E368(0, 0, 1, 0, 1, 0);
        b[1] = 0;
        func_U_0039FF28(3, 0, 0);
    } else {
        if (b[1] < 8) b[1]++;
    }
    if (!(D_001D52FC_00394F90->f1C0 & 0x10)) {
        if (D_001D52FC_00394F90->f1C8 & 0x10) {
            if (p->f74 == -1) D_001A4BE0_00394F90.f286C = 0;
            else D_001A4BE0_00394F90.f286C = ((T_390730 *)(((s32 *)D_U_001D9F70_00394F90)[D_U_001D5CAC] + p->f74 * 0x1C))->f18;
        }
        if (D_00143A06[0] != 0) func_U_003DE870();
        if (b[0]) b[0]--;
    } else {
        if (b[0] < 8) b[0]++;
    }
    if (D_001A4BE0_00394F90.f286C == 6 && D_U_001D9F38 == 0) D_001A4BE0_00394F90.f286C = 0;
    if (D_001A4BE0_00394F90.f286C == 7 && D_U_001D9F3C == 0) D_001A4BE0_00394F90.f286C = 0;
    if (D_001A4BE0_00394F90.f286C == 5 && D_U_001D9F3A == 0) D_001A4BE0_00394F90.f286C = 0;
    if (b[0] == 0) {
        D_U_001D9FB0 = p->f74;
        D_U_001D9FAC = p->f78;
        func_U_0038EC80(p->f64);
        p->f6C = -6;
        D_U_001D9FA8 = D_U_001D9C48_00394F90;
    }
}
/* localdecomp:end func_U_00390730 */

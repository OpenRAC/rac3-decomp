#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 394F48.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 D_001D5CAC;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern s32 D_001D9F28;
extern void func_003E3E08(void);
extern void func_003E3DC0(void);
extern s32 func_003A5348(s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern s32 func_003934B8(s32);

typedef struct { u8 p0[0x64]; s32 f64; u8 p68[4]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_390730;
typedef struct { u8 p0[0x148]; f32 f148; f32 f14C; u8 p150[0x70]; s32 f1C0; s32 f1C4; s32 f1C8; s32 f1CC; } P_390730;
typedef struct { u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; } T_390730;
typedef struct { u8 p0[0x286C]; s32 f286C; } G_390730;
extern P_390730 *D_001D52FC_00394F90;
extern s16 D_001D9EB4;
extern s16 D_001D9EB8;
extern s16 D_001D9EBA;
extern s16 D_001D9EBC;
extern s32 D_001D9EE8_00394F90;
extern s32 D_001D9EF0_00394F90;
extern s32 D_001D9BC8_00394F90;
extern volatile s32 D_001D5D20;
extern volatile s32 D_001D5D24;
extern volatile s32 D_001D5D28;
extern volatile s32 D_001D5D2C;
extern s32 D_001D9F28;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern u8 D_00143A06[];
extern G_390730 D_001A4BE0_00394F90;
extern void func_003E3E08(void);
extern f32 func_0038D160(f32, f32);
extern s32 func_003A5348(s32, s32, s32);
extern void func_003E3DC0(void);
extern s32 func_003934B8(s32);
/* localdecomp:start func_00394F90 */
#include "vu0.h"
/* nav defaults: D_001D5D00..0C (func_00393C40's menu) and D_001D5D20..2C (this one) */
extern s32 D_001D5D00_00394F90[12] __attribute__((section(".sdata")));
extern s32 func_003825F8(s32, s32, s32, s32, s32, s32);
void func_00394F90(S_390730 *p) {
    u8 *b = p->b70;
    f32 x, y, len, ang;
    s32 old;
    func_003E3E08();
    p->f7C = 150;
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
    ang = func_0038D160(x, y);
    if ((p->f78 >> 24) == 0 && D_001D9EB4 != 0) {
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
                n = D_001D9EE8_00394F90;
                a = a + 3.1415927f;
                p->f74 = (s32)((a + 1.5707964f + 3.1415927f / (f32)n) * ((f32)n / 6.2831855f)) % n;
            }
        } else {
            if (D_001D52FC_00394F90->f1C4 & 0xF000) {
                s32 sel = old;
                s32 t;
                if (D_001D52FC_00394F90->f1C4 & 0x1000) {
                    if (sel == -1) t = D_001D5D00_00394F90[10]; else t = ((T_390730 *)(((s32 *)D_001D9EF0_00394F90)[D_001D5CAC] + sel * 0x1C))->f10; sel = t;
                }
                if (D_001D52FC_00394F90->f1C4 & 0x4000) {
                    if (sel == -1) t = D_001D5D00_00394F90[11]; else t = ((T_390730 *)(((s32 *)D_001D9EF0_00394F90)[D_001D5CAC] + sel * 0x1C))->f14; sel = t;
                }
                if (D_001D52FC_00394F90->f1C4 & 0x8000) {
                    if (sel == -1) t = D_001D5D00_00394F90[8]; else t = ((T_390730 *)(((s32 *)D_001D9EF0_00394F90)[D_001D5CAC] + sel * 0x1C))->f8; sel = t;
                }
                if (D_001D52FC_00394F90->f1C4 & 0x2000) {
                    if (sel == -1) t = D_001D5D00_00394F90[9]; else t = ((T_390730 *)(((s32 *)D_001D9EF0_00394F90)[D_001D5CAC] + sel * 0x1C))->fC; sel = t;
                }
                p->f74 = sel;
            }
        }
    }
    if (p->f74 != old) {
        func_003825F8(0, 0, 1, 0, 1, 0);
        b[1] = 0;
        func_003A5348(3, 0, 0);
    } else {
        if (b[1] < 8) b[1]++;
    }
    if (!(D_001D52FC_00394F90->f1C0 & 0x10)) {
        if (D_001D52FC_00394F90->f1C8 & 0x10) {
            if (p->f74 == -1) D_001A4BE0_00394F90.f286C = 0;
            else D_001A4BE0_00394F90.f286C = ((T_390730 *)(((s32 *)D_001D9EF0_00394F90)[D_001D5CAC] + p->f74 * 0x1C))->f18;
        }
        if (D_00143A06[0] != 0) func_003E3DC0();
        if (b[0]) b[0]--;
    } else {
        if (b[0] < 8) b[0]++;
    }
    if (D_001A4BE0_00394F90.f286C == 6 && D_001D9EB8 == 0) D_001A4BE0_00394F90.f286C = 0;
    if (D_001A4BE0_00394F90.f286C == 7 && D_001D9EBC == 0) D_001A4BE0_00394F90.f286C = 0;
    if (D_001A4BE0_00394F90.f286C == 5 && D_001D9EBA == 0) D_001A4BE0_00394F90.f286C = 0;
    if (b[0] == 0) {
        D_001D9F30 = p->f74;
        D_001D9F2C = p->f78;
        func_003934B8(p->f64);
        p->f6C = -6;
        D_001D9F28 = D_001D9BC8_00394F90;
    }
}
/* localdecomp:end func_00394F90 */

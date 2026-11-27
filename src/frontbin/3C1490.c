#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BC768();
extern void func_003BDF40();
extern void func_003C0CA0();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C1490 */
extern void func_003A6790(void *);
extern void func_003A7AF8(void *);
extern void func_003A8450();
void func_003C1490(u8 *p) {
    if (p[0x95] < 11) return;
    func_003A6790(p);
    func_003A7AF8(p);
    func_003A8450();
}
/* localdecomp:end func_003C1490 */

/* localdecomp:start func_003C14D8 */
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3BBFC8;
extern u8 D_002D2008[];
extern S_3BBFC8 D_00225700_003C14D8;
extern void func_003BCAF8();
extern void func_0038E150(s32);
extern void func_00389240();
extern void func_00389370();
extern void func_0038E7E8_003C14D8(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
void func_003C14D8(void) {
    s32 v;
    u8 *s;
    S_3BBFC8 *g;
    func_003BCAF8();
    s = D_002D2008;
    if (s[0x51] != 0) {
        func_0038E150(1);
        func_00389240(1);
        g = &D_00225700_003C14D8;
        v = 0xE0 - (g->h40 - g->f34) * 3;
        if (v < 0) v = 0;
        if (v > 0xC0) v = 0xC0;
        if (v > 0) {
            func_0038E7E8_003C14D8(70.0f, (f32)(*(s32 *)0x1D4BC4 - 0x5A), (v << 24) | 0xC37A33, s + 0x10, -1, 1.5f, 1.5f, 0, 1, (unsigned long)(s32)0x80000000, 2.0f, 2.0f);
        }
        func_00389370();
    }
}
/* localdecomp:end func_003C14D8 */

/* localdecomp:start func_003C15C8 */
extern s16 D_0016C5AC[];
 
void func_003C15C8(void) {
    func_003BDF40();
    func_003BC768();
    func_003C0CA0();
    D_0016C5AC[0] = 1;
}
/* localdecomp:end func_003C15C8 */

extern s32 func_00381FF0(s32);
extern void func_003BBA08(s32, s32);
extern void func_003BC408(s32, s32);
extern s32 func_0011B754(void *, s32);
extern u8 D_001D9088;
extern volatile s32 D_001D4B4C;
typedef struct { u8 n0[0x10]; u8 n1[0x10]; u8 n2[0x10]; s32 f30, f34, f38, f3C, f40, f44, f48, f4C, f50; u8 p54[0xC]; s8 f60; } S_BC0F0;
extern S_BC0F0 D_002D2060[];
typedef struct { u8 pad[0x1AF8]; s32 f1AF8; u8 p2[0x1B14-0x1AFC]; s32 f1B14, f1B18, f1B1C; } S_BC0F0b;
extern S_BC0F0b D_001A4BE0[];
/* localdecomp:start func_003C1600 */
__asm__(".extern D_001D4B4C, 16");
s32 func_003C1600(s32 arg0, s32 arg1) {
    S_BC0F0 *p = D_002D2060;
    S_BC0F0b *q;
    func_0011B754(p->n0, func_00381FF0(0x1645));
    func_0011B754(p->n1, func_00381FF0(0x1646));
    func_0011B754(p->n2, func_00381FF0(0xF07));
    p->f30 = 0;
    q = D_001A4BE0;
    p->f34 = q->f1B14;
    p->f38 = q->f1B1C;
    p->f3C = q->f1B18;
    p->f40 = arg1;
    if (arg1 != 0 && q->f1AF8 != 0) {
        p->f40 = 0;
    }
    D_002D2060->f44 = arg0;
    D_002D2060->f60 = 0;
    func_003BBA08(0, 0);
    if (D_002D2060->f40 == 0) {
        D_002D2060->f48 = 0;
        D_002D2060->f4C = 0x32;
        D_002D2060->f50 = 0;
        D_001D4B4C = 0;
    } else {
        D_002D2060->f48 = 0;
        D_002D2060->f4C = 0x32;
        func_003BC408(3, (s32)&D_001D9088);
    }
    return 1;
}
/* localdecomp:end func_003C1600 */

/* localdecomp:start func_003C1728 */
/* D_002D2060 (S_BC0F0, above) seen with its float fields as floats: f30 and f50 are written with swc1. */
typedef struct { u8 n[0x30]; f32 f30; s32 f34, f38, f3C, f40, f44, f48, f4C; f32 f50; u8 p54[0xC]; u8 f60; } T_3C1728;
extern s32 D_001D9094;
extern f32 D_001D9044;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern void func_003BB848(s32);
extern s32 func_0038CAD0(void *);
extern s32 func_003BDF18();
extern void func_003BB968();
extern s32 func_003BE300(void);
extern void func_003BB8F0(s32, f32);
extern f32 func_0038DAB8(f32, f32);
s32 func_003C1728(void) {
    s32 done = 0;

    if (((T_3C1728 *)D_002D2060)->f60 == 0) {
        func_003BB848(2);
        ((T_3C1728 *)D_002D2060)->f60 = 1;
    }
    if (((T_3C1728 *)D_002D2060)->f40) {
        switch (((T_3C1728 *)D_002D2060)->f48) {
        case 0:
            ((T_3C1728 *)D_002D2060)->f30 = 1.0f - (f32)((T_3C1728 *)D_002D2060)->f4C / 50.0f;
            if (func_0038CAD0(&((T_3C1728 *)D_002D2060)->f4C)) {
                ((T_3C1728 *)D_002D2060)->f48 = 1;
                ((T_3C1728 *)D_002D2060)->f4C = 75;
            }
            break;
        case 1:
            if (func_0038CAD0(&((T_3C1728 *)D_002D2060)->f4C)) {
                ((T_3C1728 *)D_002D2060)->f48 = 2;
                ((T_3C1728 *)D_002D2060)->f4C = ((T_3C1728 *)D_002D2060)->f34 * 3;
            }
            break;
        case 2:
            ((T_3C1728 *)D_002D2060)->f30 = 1.0f;
            if ((((T_3C1728 *)D_002D2060)->f34 * 3 - ((T_3C1728 *)D_002D2060)->f4C) % D_001D9094 == 0) {
                func_003BB848(0);
            }
            if (func_0038CAD0(&((T_3C1728 *)D_002D2060)->f4C)) {
                ((T_3C1728 *)D_002D2060)->f48 = 3;
                ((T_3C1728 *)D_002D2060)->f4C = 75;
                func_003BB848(1);
            }
            break;
        case 3:
            ((T_3C1728 *)D_002D2060)->f30 = 1.0f;
            if (func_0038CAD0(&((T_3C1728 *)D_002D2060)->f4C)) {
                ((T_3C1728 *)D_002D2060)->f48 = 4;
                ((T_3C1728 *)D_002D2060)->f4C = 100;
            }
            if (*(u32 *)(D_001D52FC + 0x1C4) & 0x40) {
                ((T_3C1728 *)D_002D2060)->f4C = 0;
            }
            break;
        case 4:
            if (func_003BDF18()) {
                func_003BB968();
            }
            if (func_003BE300()) {
                if (func_0038CAD0(&((T_3C1728 *)D_002D2060)->f4C)) {
                    ((T_3C1728 *)D_002D2060)->f48 = 5;
                    ((T_3C1728 *)D_002D2060)->f4C = 50;
                }
            }
            break;
        case 5:
            done = (func_0038CAD0(&((T_3C1728 *)D_002D2060)->f4C) == 1);
            ((T_3C1728 *)D_002D2060)->f30 = (f32)((T_3C1728 *)D_002D2060)->f4C / 50.0f;
            func_003BB8F0(2, ((T_3C1728 *)D_002D2060)->f30);
            break;
        }
    } else {
        switch (((T_3C1728 *)D_002D2060)->f48) {
        case 0:
            ((T_3C1728 *)D_002D2060)->f30 = 1.0f - (f32)((T_3C1728 *)D_002D2060)->f4C / 50.0f;
            if (func_0038CAD0(&((T_3C1728 *)D_002D2060)->f4C)) {
                ((T_3C1728 *)D_002D2060)->f48 = 1;
                ((T_3C1728 *)D_002D2060)->f4C = 100;
            }
            break;
        case 1:
            ((T_3C1728 *)D_002D2060)->f30 = 1.0f;
            if (func_003BE300()) {
                if (func_0038CAD0(&((T_3C1728 *)D_002D2060)->f4C)) {
                    ((T_3C1728 *)D_002D2060)->f48 = 2;
                    ((T_3C1728 *)D_002D2060)->f4C = 50;
                }
            }
            break;
        case 2:
            if (func_0038CAD0(&((T_3C1728 *)D_002D2060)->f4C) == 1) {
                done = 1;
            }
            ((T_3C1728 *)D_002D2060)->f30 = (f32)((T_3C1728 *)D_002D2060)->f4C / 50.0f;
            break;
        }
        ((T_3C1728 *)D_002D2060)->f50 = func_0038DAB8(((T_3C1728 *)D_002D2060)->f50, D_001D9044);
    }
    return done;
}
/* localdecomp:end func_003C1728 */
INCLUDE_RODATA("asm/nonmatchings/text/rodata", D_0031C9B8);

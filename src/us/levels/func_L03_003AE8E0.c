#include "common.h"

/* NTSC-U counterpart of func_L03_003B0290 (src/levels/03_starship_phoenix/L03_003AF410.c) */
/* localdecomp:start func_L03_003AE8E0 */
typedef struct { u8 pad0[0x128]; int f128; int f12C; int f130; int f134; int f138; u8 pad13C[0x190-0x13C]; int f190; int f194; int f198; int f19C; } S_003B0290;
typedef struct { u8 pad0[0x24]; int f24; u8 pad28[0x6C-0x28]; int f6C; u8 pad70[0x94-0x70]; int f94; } D_003B0290;
typedef struct { u8 pad[0x68]; S_003B0290 *p; } A_003B0290;
extern char D_001A4C60_003AE8E0[];
extern D_003B0290 D_001CCFD0_003AE8E0;
int func_0037E0F0();
int func_0037E208();
void func_00388398();
int func_L03_003AE888_003AE8E0();
void func_L03_003AED98_003AE8E0();
int func_L03_003AEE48_003AE8E0();
void func_L03_003AE790_003AE8E0();
void func_L03_003AE608_003AE8E0();
void func_L03_003AE6D8_003AE8E0();
int func_L03_003AE5B8_003AE8E0();
int func_L03_003AE4B0_003AE8E0();
void func_L03_003AE568_003AE8E0();

void func_L03_003AE8E0(A_003B0290 *a) {
    S_003B0290 *s = a->p;
    if (func_0037E0F0(D_001A4C60_003AE8E0, s->f138, 0) == 0) {
        if (s->f130 != 0) {
            s->f130 = 7;
        }
        return;
    }
    if (s->f130 != 0) {
        if (func_L03_003AE888_003AE8E0() == 0) {
            return;
        }
    }
    switch (s->f130) {
    case 0:
        s->f134 = 0x12C;
        func_L03_003AED98_003AE8E0(a);
        s->f130 = 1;
    case 1:
        if (func_L03_003AEE48_003AE8E0(a) != 0) {
            s->f130 = 2;
        }
        break;
    case 2:
        if (s->f134 == 0) {
            func_L03_003AE790_003AE8E0(a, s->f128, s->f12C);
            func_L03_003AE608_003AE8E0(a, s->f128, 0);
            func_L03_003AE6D8_003AE8E0(a, s->f128, s->f12C);
            if (s->f12C == 0) {
                func_L03_003AE790_003AE8E0(a, 0, s->f128);
            }
            s->f130 = 3;
        }
        break;
    case 3:
        if (func_L03_003AE5B8_003AE8E0(a, s->f128) != 0) {
            if (func_L03_003AE4B0_003AE8E0(a, s->f190, s->f128) != 0) {
                s->f130 = 4;
            }
        }
        break;
    case 4:
        if (s->f134 == 0) {
            if (func_L03_003AE4B0_003AE8E0(a, s->f194, s->f12C) != 0) {
                func_L03_003AE790_003AE8E0(a, s->f12C, s->f128);
                func_L03_003AE608_003AE8E0(a, s->f128, 5);
                func_L03_003AE608_003AE8E0(a, s->f12C, 0);
                func_L03_003AE6D8_003AE8E0(a, s->f12C, s->f128);
                s->f130 = 5;
            }
        }
        break;
    case 5:
        if (s->f134 == 0) {
            if (func_L03_003AE4B0_003AE8E0(a, s->f198, s->f128) != 0) {
                func_L03_003AE608_003AE8E0(a, s->f128, 4);
                func_L03_003AE608_003AE8E0(a, s->f12C, 1);
                s->f130 = 6;
            }
        }
        break;
    case 6:
        if (s->f134 == 0) {
            if (func_L03_003AE4B0_003AE8E0(a, s->f19C, s->f12C) != 0) {
                func_L03_003AE608_003AE8E0(a, s->f128, 1);
                func_L03_003AE608_003AE8E0(a, s->f12C, 2);
                s->f130 = 7;
            }
        }
        break;
    case 7:
        if (s->f134 == 0) {
            if (D_001CCFD0_003AE8E0.f6C == 0 && D_001CCFD0_003AE8E0.f24 == -1 && D_001CCFD0_003AE8E0.f94 == 0) {
                int r = func_0037E208(300, 700);
                s->f130 = 1;
                s->f134 = r;
                func_L03_003AE608_003AE8E0(a, s->f128, 3);
                func_L03_003AE608_003AE8E0(a, s->f12C, 3);
                func_L03_003AE6D8_003AE8E0(a, s->f128, -1);
                func_L03_003AE6D8_003AE8E0(a, s->f12C, -1);
                func_L03_003AE790_003AE8E0(a, s->f128, -1);
                func_L03_003AE790_003AE8E0(a, s->f12C, -1);
            }
        }
        break;
    }
    func_00388398(&s->f134);
    func_L03_003AE568_003AE8E0();
}
/* localdecomp:end func_L03_003AE8E0 */

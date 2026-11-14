/* NTSC-U draft (2026-11-14, Claude worker): C of func_L08_003C17D8, the NTSC-U twin of func_L08_003C39B0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "@ps2as" (src/levels/08_aquatos/L08_003C39B0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* localdecomp:start func_L08_003C17D8 */
typedef struct P_003C17D8 {
    u8 padC0[0xC0];
    s32 wC0;
    s32 wC4;
    s32 wC8;
    s32 wCC;
} P_003C17D8;

typedef struct H_003C17D8 {
    u8 pad00[0x35C];
    u8 *w35C;
    s32 w360;
} H_003C17D8;

extern s32 D_L08_001DEDC0;
extern u8 *D_L08_001DF300;
extern H_003C17D8 D_001A4BE0;

extern void func_003BE418(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_00452F40(void *, s32);
extern s32 func_00388398(void *);
extern void func_L02_003C3A40(void);
extern void func_L01_003EAB30(s32);
extern s32 func_L08_003CE910(void);
extern s32 func_L01_00452EF0(void *);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L03_0043BF68(s32, s32, f32);

void func_L08_003C17D8(u8 *o) {
    P_003C17D8 *p;
    u8 st;
    s32 per;
    f32 f;

    st = o[0x20];
    p = *(P_003C17D8 **)(o + 0x68);
    switch (st) {
    case 0:
        func_003BE418(o, 1, 4);
        *(s32 *)(o + 0x48) = 0;
        func_L01_00441FB8(o, 1, -1);
        break;
    case 1:
        break;
    case 2:
        if (func_L01_00452EC8(o) != 0) {
            p->wC4 = (s32)((f32)p->wC0 * 60.0f);
        }
        if (func_00388398(&p->wC4) != 0) {
            func_L01_00441FB8(o, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(o) != 0) {
            func_L01_00452F40(o, 1);
            if (p->wC8 != -1) {
                func_L02_003C3A40();
                func_L01_003EAB30(p->wC8);
            }
        } else {
            if (p->wC8 != -1 && func_L08_003CE910() != 0) {
                if (func_L01_00452EF0(o) != 0) {
                    u8 *e = D_L08_001DF300 + (p->wCC << 7);
                    func_L01_004F12C0(e + 0x30, e + 0x70, 0x74, 0);
                }
            }
        }
        break;
    }
    if (o[0x31] != 0) {
        per = 120;
        f = (f32)(D_L08_001DEDC0 % per) * 6.2831855f / (f32)per - 3.1415927f;
        if (D_001A4BE0.w35C == o && D_001A4BE0.w360 != 0) {
            *(s32 *)(o + 0x78) = func_L03_0043BF68(0x40, 0x20, f);
        } else {
            *(s32 *)(o + 0x78) = func_L03_0043BF68(0x404040, 0x202020, f);
        }
    }
}
/* localdecomp:end func_L08_003C17D8 */

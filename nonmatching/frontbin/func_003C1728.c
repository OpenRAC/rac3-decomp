/* PAL near miss: about 94 words differ with the file's flags (tools/check.py, aligned diff).
 * The C follows retail's control flow (the boot_elf twin's draft, func_003C1AE0, with frontbin's
 * names; func_0038DAB8 under a suffixed name, since its file declares it void(f32, f32)).
 * What differs is register allocation: retail keeps %hi(D_002D2060) in $s2, leaves the base
 * pointer unallocated and rebuilds it in each case block (addiu $s0, $s2, %lo; or from
 * D_002D20AC, then -0x4C); gcc here keeps the pointer or the %hi in $s0, with a 0x20 frame
 * where retail has 0x30 (4 saved registers). A local pointer, the direct global, a switch
 * value in a local and declaration order all stayed at 94 to 106 words.
 * Needs the file's other declarations: S_BC0F0 and D_002D2060 (src/frontbin/3C0CA0.c).
 */
#include "common.h"
typedef struct { u8 n0[0x10]; u8 n1[0x10]; u8 n2[0x10]; s32 f30, f34, f38, f3C, f40, f44, f48, f4C, f50; u8 p54[0xC]; s8 f60; } S_BC0F0;
extern S_BC0F0 D_002D2060[];
/* localdecomp:start func_003C1728 */
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
extern f32 func_0038DAB8_003C1728(f32, f32);
s32 func_003C1728(void) {
    S_BC0F0 *g = D_002D2060;
    s32 done = 0;
    s32 st;

    if (((u8 *)g)[0x60] == 0) {
        func_003BB848(2);
        ((u8 *)g)[0x60] = 1;
    }
    st = g->f48;
    if (g->f40) {
        switch (st) {
        case 0:
            *(f32 *)&g->f30 = 1.0f - (f32)g->f4C / 50.0f;
            if (func_0038CAD0(&g->f4C)) {
                g->f4C = 75;
                g->f48 = 1;
            }
            break;
        case 1:
            if (func_0038CAD0(&g->f4C)) {
                g->f48 = 2;
                g->f4C = g->f34 * 3;
            }
            break;
        case 2:
            *(f32 *)&g->f30 = 1.0f;
            if ((g->f34 * 3 - g->f4C) % D_001D9094 == 0) {
                func_003BB848(0);
            }
            if (func_0038CAD0(&g->f4C)) {
                g->f4C = 75;
                g->f48 = 3;
                func_003BB848(1);
            }
            break;
        case 3:
            *(f32 *)&g->f30 = 1.0f;
            if (func_0038CAD0(&g->f4C)) {
                g->f48 = 4;
                g->f4C = 100;
            }
            if (*(u32 *)(D_001D52FC + 0x1C4) & 0x40) {
                g->f4C = 0;
            }
            break;
        case 4:
            if (func_003BDF18()) {
                func_003BB968();
            }
            if (func_003BE300()) {
                if (func_0038CAD0(&g->f4C)) {
                    g->f48 = 5;
                    g->f4C = 50;
                }
            }
            break;
        case 5:
            done = (func_0038CAD0(&g->f4C) == 1);
            *(f32 *)&g->f30 = (f32)g->f4C / 50.0f;
            func_003BB8F0(2, *(f32 *)&g->f30);
            break;
        }
    } else {
        switch (st) {
        case 0:
            *(f32 *)&g->f30 = 1.0f - (f32)g->f4C / 50.0f;
            if (func_0038CAD0(&g->f4C)) {
                g->f48 = 1;
                g->f4C = 100;
            }
            break;
        case 1:
            *(f32 *)&g->f30 = 1.0f;
            if (func_003BE300()) {
                if (func_0038CAD0(&g->f4C)) {
                    g->f4C = 50;
                    g->f48 = 2;
                }
            }
            break;
        case 2:
            done = (func_0038CAD0(&g->f4C) == 1);
            *(f32 *)&g->f30 = (f32)g->f4C / 50.0f;
            break;
        }
        *(f32 *)&g->f50 = func_0038DAB8_003C1728(*(f32 *)&g->f50, D_001D9044);
    }
    return done;
}
/* localdecomp:end func_003C1728 */

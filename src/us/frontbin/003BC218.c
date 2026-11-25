#include "common.h"

/* Adapted from the PAL draft in nonmatching/frontbin/func_003C1728.c. */
/* localdecomp:start func_U_003BC218 */
typedef struct {
    u8 pad00[0x30];
    f32 f30;
    s32 f34, f38, f3C, f40, f44, f48, f4C;
    f32 f50;
    u8 pad54[0xC];
    u8 f60;
} State_003BC218;
extern State_003BC218 D_U_002CE0E0[];
extern s32 D_U_001D90C4;
extern f32 D_U_001D9074;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern void func_U_003B6368(s32);
extern s32 func_U_00388398(void *);
extern s32 func_U_003B8A20();
extern void func_U_003B6488();
extern s32 func_U_003B8E08(void);
extern void func_U_003B6410(s32, f32);
extern f32 func_U_00389380(f32, f32);

s32 func_U_003BC218(void)
{
    s32 done = 0;

    if (D_U_002CE0E0->f60 == 0) {
        func_U_003B6368(2);
        D_U_002CE0E0->f60 = 1;
    }
    if (D_U_002CE0E0->f40) {
        switch (D_U_002CE0E0->f48) {
        case 0:
            D_U_002CE0E0->f30 = 1.0f - (f32)D_U_002CE0E0->f4C / 60.0f;
            if (func_U_00388398(&D_U_002CE0E0->f4C)) {
                D_U_002CE0E0->f48 = 1;
                D_U_002CE0E0->f4C = 90;
            }
            break;
        case 1:
            if (func_U_00388398(&D_U_002CE0E0->f4C)) {
                D_U_002CE0E0->f48 = 2;
                D_U_002CE0E0->f4C = D_U_002CE0E0->f34 * 4;
            }
            break;
        case 2:
            D_U_002CE0E0->f30 = 1.0f;
            if ((D_U_002CE0E0->f34 * 4 - D_U_002CE0E0->f4C) % D_U_001D90C4 == 0) {
                func_U_003B6368(0);
            }
            if (func_U_00388398(&D_U_002CE0E0->f4C)) {
                D_U_002CE0E0->f48 = 3;
                D_U_002CE0E0->f4C = 90;
                func_U_003B6368(1);
            }
            break;
        case 3:
            D_U_002CE0E0->f30 = 1.0f;
            if (func_U_00388398(&D_U_002CE0E0->f4C)) {
                D_U_002CE0E0->f48 = 4;
                D_U_002CE0E0->f4C = 120;
            }
            if (*(u32 *)(D_001D52FC + 0x1C4) & 0x40) {
                D_U_002CE0E0->f4C = 0;
            }
            break;
        case 4:
            if (func_U_003B8A20()) {
                func_U_003B6488();
            }
            if (func_U_003B8E08()) {
                if (func_U_00388398(&D_U_002CE0E0->f4C)) {
                    D_U_002CE0E0->f48 = 5;
                    D_U_002CE0E0->f4C = 60;
                }
            }
            break;
        case 5:
            done = (func_U_00388398(&D_U_002CE0E0->f4C) == 1);
            D_U_002CE0E0->f30 = (f32)D_U_002CE0E0->f4C / 60.0f;
            func_U_003B6410(2, D_U_002CE0E0->f30);
            break;
        }
    } else {
        switch (D_U_002CE0E0->f48) {
        case 0:
            D_U_002CE0E0->f30 = 1.0f - (f32)D_U_002CE0E0->f4C / 60.0f;
            if (func_U_00388398(&D_U_002CE0E0->f4C)) {
                D_U_002CE0E0->f48 = 1;
                D_U_002CE0E0->f4C = 120;
            }
            break;
        case 1:
            D_U_002CE0E0->f30 = 1.0f;
            if (func_U_003B8E08()) {
                if (func_U_00388398(&D_U_002CE0E0->f4C)) {
                    D_U_002CE0E0->f48 = 2;
                    D_U_002CE0E0->f4C = 60;
                }
            }
            break;
        case 2:
            if (func_U_00388398(&D_U_002CE0E0->f4C) == 1) {
                done = 1;
            }
            D_U_002CE0E0->f30 = (f32)D_U_002CE0E0->f4C / 60.0f;
            break;
        }
        D_U_002CE0E0->f50 = func_U_00389380(D_U_002CE0E0->f50, D_U_001D9074);
    }
    return done;
}
/* localdecomp:end func_U_003BC218 */

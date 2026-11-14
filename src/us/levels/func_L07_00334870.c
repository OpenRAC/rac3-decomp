#include "common.h"

/* NTSC-U counterpart of func_L07_00334FB0 (src/levels/07_annihilation_nation/L07_00334B68.c) */
/* localdecomp:start func_L07_00334870 */
typedef struct {
    u8 pad0[0xC];
    u8 b0C;
    u8 pad0D[3];
} E_00334870;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 b3;
    s32 w4;
    s32 w8;
} R_00334870;

extern E_00334870 D_L07_002B0D40_00334870[];
extern R_00334870 *func_L07_00332D20(s32, s32);
extern void func_L07_003A0BC0(s32, void *, s32, s32);
extern s32 func_0037E208(s32, s32);

void func_L07_00334870(u8 *obj)
{
    u8 *p = *(u8 **)(obj + 0x68);
    s32 done = 0;
    R_00334870 *r;

    if (((E_00334870 *)((p[0x9E] << 4) + (s32)D_L07_002B0D40_00334870))->b0C == 0) {
        r = func_L07_00332D20(p[0x9E], p[0x9F]);
        if (r->w4 != -1) {
            func_L07_003A0BC0(0x2B, obj, 0, 0x78);
            done = 1;
        }
        if (done == 0 && r->b2 != 0) {
            func_L07_003A0BC0(0x37, obj, 0, 0x78);
            done = 1;
        }
        if (done == 0 && r->w8 != -1) {
            func_L07_003A0BC0(0x2E, obj, 0, 0x78);
            done = 1;
        }
        if (done == 0 && r->b3 != 0) {
            func_L07_003A0BC0(0x30, obj, 0, 0x78);
            done = 1;
        }
    } else {
        func_L07_003A0BC0(0x3A, obj, 0, 0x78);
        done = 1;
    }
    if (done == 0) {
        func_L07_003A0BC0((u8)func_0037E208(0x27, 0x29), obj, 0, 0x78);
    }
}
/* localdecomp:end func_L07_00334870 */

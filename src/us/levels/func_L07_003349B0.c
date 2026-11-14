#include "common.h"

/* localdecomp:start func_L07_003349B0 */
typedef struct {
    u8 pad[0xC];
    u8 f0C;
    u8 pad2[3];
} Ent_002B0D40;

extern Ent_002B0D40 D_L07_002B0D40_003349B0[];
extern u8 *func_L07_00332D20(s32, s32);
extern s32 func_L07_003A0BC0(s32, u8 *, s32, s32);
extern s32 func_0037E208(s32, s32);

void func_L07_003349B0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 idx = s[0x9E];
    u8 *r;
    s32 done = 0;

    if (((Ent_002B0D40 *)((u8 *)D_L07_002B0D40_003349B0 + (idx << 4)))->f0C == 0) {
        r = func_L07_00332D20(idx, s[0x9F]);
        if (*(s32 *)(r + 4) != -1) {
            func_L07_003A0BC0(0x2B, a0, 0, 0x78);
            done = 1;
        }
        if (done == 0) {
            if (r[2] != 0) {
                func_L07_003A0BC0(0x36, a0, 0, 0x78);
                done = 1;
            }
        }
        if (done == 0) {
            if (*(s32 *)(r + 8) != -1) {
                func_L07_003A0BC0(0x2D, a0, 0, 0x78);
                done = 1;
            }
        }
        if (done == 0) {
            if (r[3] != 0) {
                func_L07_003A0BC0(0x2F, a0, 0, 0x78);
                done = 1;
            }
        }
    } else {
        func_L07_003A0BC0(0x3A, a0, 0, 0x78);
        done = 1;
    }
    if (done == 0) {
        func_L07_003A0BC0(func_0037E208(0x27, 0x29) & 0xFF, a0, 0, 0x78);
    }
}
/* localdecomp:end func_L07_003349B0 */

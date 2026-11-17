/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_003B2F18, the NTSC-U twin of func_L01_003B4718, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 6 words differ with its file's flags.
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_003B4718 (src/levels/shared/L01_003B1F50.c) */
/* localdecomp:start func_L01_003B2F18 */
extern u8 *D_001DE670_sda;
extern s32 D_001DE678_sda;
extern s32 D_001DE67C_sda;
extern s32 D_001DE680_sda;
extern s32 D_001DE684_sda;
extern s32 D_001DE688_sda;
extern s32 D_001DFBC0_sda;
extern s32 D_L01_001DFBC0_003B2F18[];
extern void func_L01_003B2AE8(s32, s32, s32, s32);

static inline s32 Frame(void) {
    return D_L01_001DFBC0_003B2F18[0];
}

s32 func_L01_003B2F18(void) {
    u8 *p;
    s32 dt;
    s32 x;
    s32 r;

    if (D_001DE670_sda == 0) {
        if (D_001DE688_sda != 0) {
            if (D_001DE688_sda + 1 < D_001DFBC0_sda) {
                D_001DE678_sda = 0;
                D_001DE67C_sda = 0;
                D_001DE680_sda = 0;
                D_001DE684_sda = 0;
                D_001DE688_sda = 0;
            } else {
                func_L01_003B2AE8(D_001DE678_sda, D_001DE67C_sda, D_001DE680_sda, D_001DE684_sda);
            }
        }
        return 1;
    }
    p = *(u8 **)(D_001DE670_sda + 0x68);
    { s32 t = Frame(); dt = t - *(s32 *)(p + 4); }
    x = *(s32 *)(p + 0x10);
    if (x == 0 || dt >= 0x12C) {
        r = *(s32 *)(p + 0x14);
        if (r == 0 || *(s32 *)(p + 0x18) >= dt) {
            goto tail;
        }
        dt -= *(s32 *)(p + 0x18);
        x = *(s32 *)(p + 0x1C);
        if (dt % x >= 0x12C) {
            goto tail;
        }
        x = r;
    }
    func_L01_003B2AE8(x, 0, 0, 0);
    return 1;
tail:
    if (D_001DE688_sda != 0) {
        if (D_001DE688_sda + 1 < Frame()) {
            D_001DE678_sda = 0;
            D_001DE67C_sda = 0;
            D_001DE680_sda = 0;
            D_001DE684_sda = 0;
            D_001DE688_sda = 0;
        } else {
            func_L01_003B2AE8(D_001DE678_sda, D_001DE67C_sda, D_001DE680_sda, D_001DE684_sda);
        }
    }
    return 1;
}
/* localdecomp:end func_L01_003B2F18 */

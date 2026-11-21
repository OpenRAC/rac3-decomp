#include "common.h"

/* NTSC-U counterpart of func_L01_003B4718 (src/levels/shared/L01_003B4718.c) */
extern s32 D_L01_001DE670_003B2F18;
extern s32 D_L01_001DE678_003B2F18;
extern s32 D_L01_001DE67C_003B2F18;
extern s32 D_L01_001DE680_003B2F18;
extern s32 D_L01_001DE684_003B2F18;
extern s32 D_L01_001DE688_003B2F18;
extern s32 D_L01_001DFBC0_003B2F18_b[];

/* localdecomp:start func_L01_003B2F18 */
extern s32 D_L01_001DFBC0_003B2F18;
extern void func_L01_003B2AE8(s32, s32, s32, s32);

static __inline__ s32 Frame_003B4718(void) {
    return D_L01_001DFBC0_003B2F18_b[0];
}

s32 func_L01_003B2F18(s32 a0) {
    u8 *p;
    s32 dt;
    s32 x; /* p->0x10, set once: its load keeps sched1's birthing boost */
    s32 r;
    s32 a; /* the call argument: p->0x10, the period at 0x1C, then p->0x14 */

    if (D_L01_001DE670_003B2F18 == 0) {
        if (D_L01_001DE688_003B2F18 != 0) {
            if (D_L01_001DE688_003B2F18 + 1 < D_L01_001DFBC0_003B2F18) {
                D_L01_001DE678_003B2F18 = 0;
                D_L01_001DE67C_003B2F18 = 0;
                D_L01_001DE680_003B2F18 = 0;
                D_L01_001DE684_003B2F18 = 0;
                D_L01_001DE688_003B2F18 = 0;
            } else {
                func_L01_003B2AE8(D_L01_001DE678_003B2F18, D_L01_001DE67C_003B2F18, D_L01_001DE680_003B2F18, D_L01_001DE684_003B2F18);
            }
        }
        return 1;
    }
    p = *(u8 **)(D_L01_001DE670_003B2F18 + 0x68);
    dt = Frame_003B4718() - *(s32 *)(p + 4);
    x = *(s32 *)(p + 0x10);
    if (x != 0) {
        a = x;
        if (dt < 300) {
            goto show;
        }
    }
    r = *(s32 *)(p + 0x14);
    if (r != 0 && *(s32 *)(p + 0x18) < dt) {
        dt -= *(s32 *)(p + 0x18);
        a = *(s32 *)(p + 0x1C);
        if (dt % a < 300) {
            a = r;
show:
            func_L01_003B2AE8(a, 0, 0, 0);
            return 1;
        }
    }
    if (D_L01_001DE688_003B2F18 != 0) {
        if (D_L01_001DE688_003B2F18 + 1 < Frame_003B4718()) {
            D_L01_001DE678_003B2F18 = 0;
            D_L01_001DE67C_003B2F18 = 0;
            D_L01_001DE680_003B2F18 = 0;
            D_L01_001DE684_003B2F18 = 0;
            D_L01_001DE688_003B2F18 = 0;
        } else {
            func_L01_003B2AE8(D_L01_001DE678_003B2F18, D_L01_001DE67C_003B2F18, D_L01_001DE680_003B2F18, D_L01_001DE684_003B2F18);
        }
    }
    return 1;
}
/* localdecomp:end func_L01_003B2F18 */

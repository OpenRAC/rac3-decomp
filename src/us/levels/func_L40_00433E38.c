#include "common.h"

/* NTSC-U counterpart of func_L40_004349A0 (src/levels/shared/L40_00434048.c) */
extern s32 func_L39_005B2498(s32);
extern s32 D_001A5E50[];

/* localdecomp:start func_L40_00433E38 */
extern s32 D_001A5E50[];
extern s32 func_L39_005B2498(s32);
extern s32 func_L40_004336E0(s32 a0);
extern void func_L40_00433708(u8 *a0);

s32 func_L40_00433E38(u8 *a0, s32 a1) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 n;
    s32 lim;
    s32 t;
    s32 r;
    s32 q;
    s32 rem;

    if (a1 == 0) {
        n = a0[0x20];
        if (n != 0) {
            if (n != 1) {
                return 0;
            }
            lim = D_001A5E50[0x12C / 4];
            if (lim > 8) {
                lim = 8;
            }
            if (lim < 1) {
                lim = 1;
            }
            t = D_001A5E50[0x128 / 4];
            r = t % (lim * 10000);
            q = r / 10000;
            rem = r - q * 10000;
            if (q > 7) {
                q = 7;
            }
            if (q < 0) {
                q = 0;
            }
            if (q == D_001A5E50[2]) {
                if (rem >= 5000) {
                    return 0;
                }
                if (*(s32 *)(p + 0x10) != 0) {
                    return 0;
                }
                if (*(s32 *)(p + 4) + 45000 >= t) {
                    return 0;
                }
                if (func_L39_005B2498(250) != 1) {
                    return 0;
                }
                if (func_L40_004336E0((s32)a0) != 0) {
                    return 0;
                }
                func_L40_00433708(a0);
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L40_00433E38 */

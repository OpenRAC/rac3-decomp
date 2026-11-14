#include "common.h"

/* NTSC-U counterpart of func_L40_003D6070 (src/levels/shared/L40_003D5818.c) */
/* localdecomp:start func_L40_003D5ED8 */
/* section(".sdata") on D_L40_002494B0: gcc then emits the address as one `la` macro (lui+addiu into $s2), as retail has; the plain extern splits it and the lui lands in a delay slot. */
typedef struct {
    s32 a;
    u32 b;
    s32 pad[3];
    s32 t0;
    s32 t1;
} S_003D6070;
extern f32 func_L01_0040C018(void *, void *);
extern s32 func_L40_003D56A8(u8 *, u8 *);
extern void func_L39_0055D170(s32, s32);
extern s32 func_L39_0053D198(s32);
extern s32 *D_L40_002494B0[] __attribute__((section(".sdata")));
extern f32 D_L40_00246B04;
extern s32 D_001A5F78[];
s32 func_L40_003D5ED8(u8 *p, s32 a1) {
    S_003D6070 *q = *(S_003D6070 **)(p + 0x68);
    s32 *e;
    s32 i;

    if (a1 != 0) {
        q->a = -1;
        q->b = 0xFFFFFFFF;
        return 0;
    }
    switch (p[0x20]) {
    case 0:
        break;
    case 1:
    case 2:
        for (i = 0; i < 8; i++) {
            e = D_L40_002494B0[i];
            if (e != 0 && func_L01_0040C018((u8 *)e + 0xA0, p + 0x10) < D_L40_00246B04 && func_L40_003D56A8((u8 *)e, p) != 0) {
                break;
            }
        }
        if (i < 8) {
            func_L39_0055D170((s32)p, *e);
        }
        break;
    case 3:
        if (q->t0 > 0 && q->t1 > 0) {
            if (q->t0 < D_001A5F78[0] - q->t1) {
                if (func_L39_0053D198((s32)p) == 0) {
                    func_L40_003D5680((s32)p);
                }
            }
        }
        break;
    }
    return 0;
}
/* localdecomp:end func_L40_003D5ED8 */

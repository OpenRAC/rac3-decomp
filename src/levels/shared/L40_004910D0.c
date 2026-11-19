#include "common.h"

/* localdecomp:start func_L40_004910D0 */
extern s32 D_L40_00243380;
__asm__(".extern D_L40_00243380, 4");
extern s32 D_L40_00243384;
__asm__(".extern D_L40_00243384, 4");
extern s32 D_L40_00243388;
__asm__(".extern D_L40_00243388, 4");
extern void func_L01_00423020(void *, s32);
extern void func_L40_00491130(void);
extern void func_L40_00491270(void);
extern void func_L40_004913B8(void);

void func_L40_004910D0(void) {
    if (D_L40_00243380 != 0) {
        func_L01_00423020(func_L40_00491130, 0);
    }
    if (D_L40_00243384 != 0) {
        func_L01_00423020(func_L40_00491270, 0);
    }
    if (D_L40_00243388 != 0) {
        func_L01_00423020(func_L40_004913B8, 0);
    }
}
/* localdecomp:end func_L40_004910D0 */

/* localdecomp:start func_L40_00491130 */
typedef int u128_00491130 __attribute__((mode(TI)));
typedef union {
    u128_00491130 q;
    f32 f[4];
} V_00491130;

typedef struct {
    u128_00491130 pos;
    V_00491130 *pts;
    s32 n;
    f32 x18;
    f32 x1C;
} E_00491130;

extern s32 D_L40_00248620;
extern E_00491130 D_L40_00290EE0[];
extern void func_L40_00491768(void *, void *, s32, f32);

void func_L40_00491130(void) {
    V_00491130 a;
    V_00491130 b;
    s32 i;
    s32 j;

    for (i = 0; i < D_L40_00248620; i++) {
        for (j = 0; j < D_L40_00290EE0[i].n - 1; j++) {
            a.q = D_L40_00290EE0[i].pts[j].q;
            a.f[2] += 0.05f;
            b.q = D_L40_00290EE0[i].pts[(j + 1) % D_L40_00290EE0[i].n].q;
            b.f[2] += 0.05f;
            func_L40_00491768(&a, &b, 0x6000FFFF, 0.2f);
        }
    }
}
/* localdecomp:end func_L40_00491130 */

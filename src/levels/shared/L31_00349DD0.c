#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[8];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);


/* localdecomp:start func_L31_00349DD0 */
typedef struct {
    u8 pad[0x4C];
    f32 hist[16];
} Hist_003491F0;

typedef struct {
    u8 pad[0x68];
    Hist_003491F0 *w68;
} Moby_003491F0;

extern s32 D_L31_001DD0B0;

void func_L31_00349DD0(Moby_003491F0 *m, f32 value) {
    Hist_003491F0 *h;
    s32 i;
    h = m->w68;
    for (i = D_L31_001DD0B0 - 1; i >= 0; i--) {
        h->hist[i + 1] = h->hist[i];
    }
    h->hist[1] = value;
}
/* localdecomp:end func_L31_00349DD0 */

INCLUDE_ASM("asm/levels", func_L31_00349E10);

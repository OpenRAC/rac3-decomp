/* near miss (level 31: 73 diff with @ps2as, needs @ps2as) */
#include "common.h"

/* localdecomp:start func_L31_00345398 */#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_345398;
typedef struct {
    s16 type;
    char _p2[6];
    s32 f8;
    char _pC[4];
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    char _p20[0x30 - 0x20];
} E_345398;
typedef struct {
    char _p0[0x68];
    E_345398 *f68;
} M_345398;

extern char *D_L31_001DF79C;
extern void func_L31_003494B0(f32 *, s32);
extern void *func_L31_003A12B0(void *, V4_345398 *, f32 *, V4_345398 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00456230(void *, s32);
extern void *func_L31_003A5958(f32 *, s32);

void func_L31_00345398(M_345398 *a0, s32 idx, f32 *a2) {
    void *m;
    V4_345398 a;
    V4_345398 b;

    switch (a0->f68[idx].type) {
    case 0x18C5:
        m = a0;
        if (a0->f68[idx].f8 != -1) {
            m = D_L31_001DF79C + (a0->f68[idx].f8 << 8);
        }
        qzero(&a);
        qzero(&b);
        a.x = a0->f68[idx].f10;
        a.z = a0->f68[idx].f14;
        b.x = a0->f68[idx].f18;
        b.z = a0->f68[idx].f1C;
        func_L01_00456230(func_L31_003A12B0(m, &a, a2, &b, 0x222222, 0x333366, 0x1650, 0x3080, 1, 20.0f, 0.05f, 0.5f), 1);
        break;
    case 0x1644:
        a2[2] += a0->f68[idx].f10;
        func_L31_003494B0(a2, -1);
        break;
    case 0x1A9A:
        func_L31_003A5958(a2, -1);
        break;
    }
}
/* localdecomp:end func_L31_00345398 */

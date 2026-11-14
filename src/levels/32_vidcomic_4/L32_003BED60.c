#include "common.h"

typedef struct S_003BED60 {
    u8 pad00[4];
    u8 f04[8];
    f32 f0C;
    f32 f10;
    u8 pad14[0x28];
    s32 f3C;
} S_003BED60;
typedef struct S_003BED60_arg {
    u8 pad00[0x68];
    S_003BED60 *f68;
} S_003BED60_arg;

/* declared by functions of L32_003BE008.c, which this file was cut from */
void func_L32_003BED60(void *);
void func_L01_004450F0(void *, s32, s32);

/* localdecomp:start func_L32_003BED60 */
extern u8 D_001A30B0[];
extern f32 D_L32_001DF1E0;
extern f32 D_L32_001DF1E4;
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);

void func_L32_003BED60(void *a) {
    S_003BED60_arg *arg0 = a;
    S_003BED60 *p;
    u8 *t;
    f32 a;
    f32 b;

    p = arg0->f68;
    a = func_0038DAB8(p->f0C, D_L32_001DF1E0);
    p->f0C = a;
    b = func_0038DAB8(p->f10, D_L32_001DF1E4);
    p->f10 = b;
    if (p->f3C != -1) {
        t = D_001A30B0 + p->f3C * 0x80;
        if (*(void **)(t + 0xDC) == arg0) {
            if (t[0xD0] != 0) {
                goto skip;
            }
        }
    }
    p->f3C = func_L01_004AAC98(10, 4, (s32)arg0, 0x19D1);
skip:
    if (func_0038CAD0(p->f04) != 0) {
        func_L01_004450F0(arg0, 2, -1);
    }
}
/* localdecomp:end func_L32_003BED60 */

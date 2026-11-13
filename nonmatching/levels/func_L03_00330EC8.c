/* near miss (level 3, Starship Phoenix): 150 differences, register allocation: the loop structure, constants (0.40000004f, 22.83f) and calls are right but retail keeps the moby in $fp and the s->p68 pointer spilled to 0x30($sp) with every $s register busy, the C allocates $s3..$s7 differently and does not spill; a first draft */
#include "common.h"

/* localdecomp:start func_L03_00330EC8 */
#include "vu0.h"
typedef struct { u8 pad0[0xF7]; u8 bF7; f32 fF8; } S_00330EC8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_00330EC8 *p68; } A_00330EC8;
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_00474078(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32);

void func_L03_00330EC8(void *arg) {
    A_00330EC8 *a = arg;
    S_00330EC8 *s = a->p68;
    f32 k;
    int i;
    k = 2.0f - s->fF8;
    if (k > 1.0f) k = 1.0f;
    for (i = 0; i < 5; i++) {
        int n;
        int ix, iy;
        f32 lo, hi;
        if (!((s->bF7 >> i) & 1)) continue;
        n = 4;
        if (i == 4) {
            n = 8;
            lo = 0.0f;
            hi = 10.5f;
            ix = -1;
            iy = -1;
        } else {
            lo = 10.5f;
            hi = 22.83f;
            ix = i % 2;
            iy = 1 - i / 2;
        }
        while (n != 0) {
            vu0_v4 off;
            vu0_v4 pos;
            vu0_v4 rot;
            int c, sg;
            f32 ang;
            c = ix;
            if (ix == -1) c = func_00382468(2);
            if (iy == -1) {
                sg = func_00382468(2) != 0 ? 1 : -1;
            } else {
                sg = iy != 0 ? 1 : -1;
            }
            qzero(&off);
            n--;
            (&off.x)[c] = func_003824E0(lo, hi) * (f32)sg;
            vec_add_ab(&pos, &a->pos, &off);
            ang = func_00382538();
            func_00382760(&rot, 0.40000004f, ang, func_003824E0(1.0f, k) * 1.5707964f);
            func_L01_00474078(&pos, &rot, 0x11, 0x80FF2020, 0x80404040, 0xA, 0, 0.08f, 2.0f, 1.5f, 1.0f);
        }
    }
}
/* localdecomp:end func_L03_00330EC8 */

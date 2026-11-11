#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003B21A8);

/* localdecomp:start func_L05_003B2348 */
#include "vu0.h"
extern int abs(int);
typedef struct {
    char pad0[0x10];
    vu0_v4 pos;
    char pad20[0xC];
    f32 f2C;
    char pad30[0x90];
    char mat[0x38];
    f32 fF8;
} S_3B2348;

__asm__(".extern D_L05_001DE7A0, 4");
extern s32 D_L05_001DE7A0;
extern s32 D_L05_001DE7C0[2];
extern f32 D_L05_001DE7D8[2];
extern f32 D_L05_001DE7E8[2];
extern f32 D_L05_001DE7F8[2];
extern f32 D_L05_001DE808[2];
extern s32 func_00382468(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L05_003B24B8(u8 *, f32, f32);

void func_L05_003B2348(S_3B2348 *p) {
    s32 i;
    vu0_v4 v;
    for (i = 0; i < 5; i++) {
        s32 a;
        s32 k;
        if (i < D_L05_001DE7A0 && func_00382468(7) != 0) {
            continue;
        }
        a = D_L05_001DE7C0[i];
        *(vu0_q *)&v = 0;
        k = 2 - abs(2 - a);
        v.x = D_L05_001DE7D8[k];
        v.y = D_L05_001DE7E8[k];
        v.z = D_L05_001DE7F8[k];
        if (a >= 3) {
            v.y = -v.y;
        }
        func_0038CE20(&v, &v, p->f2C);
        func_0038D000(&v, &v, p->mat);
        vec_add_ab(&v, &p->pos, &v);
        func_L05_003B24B8((u8 *)&v, func_0038DAB8(p->fF8, 3.1415927f), D_L05_001DE808[k]);
    }
}
/* localdecomp:end func_L05_003B2348 */

/* localdecomp:start func_L05_003B24B8 */
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L05_003B24B8(u8 *p, f32 a, f32 b) {
    f32 v[4];
    s32 n;
    s32 n2;
    s32 sg;
    f32 s1;
    f32 t2;
    f32 t3;
    f32 t4;
    f32 t5;

    s32 r;
    r = func_00382498(4, 8);
    if (r > 0) {
        n = r;
        do {
            n--;
            s1 = func_003824E0(15.0f, 20.0f) * 0.020000001f;
            t2 = func_003824E0(-0.52359879f, 0.52359879f);
            t3 = func_0038DAB8(a, t2);
            t4 = func_003824E0(-0.52359879f, 0.52359879f);
            func_00382760(v, s1, t3, t4);
            t5 = func_003824E0(2.5f, 3.0f) * b;
            n2 = func_00382498(4, 10);
            sg = func_00382468(2) != 0 ? 1 : -1;
            func_L01_0046FB40(p, v, n2, 0x204080, sg, 110, 32, 0, t5 * 210000.0f, t5 * 0.75f * 210000.0f, 0.0f);
        } while (n != 0);
    }
}
/* localdecomp:end func_L05_003B24B8 */

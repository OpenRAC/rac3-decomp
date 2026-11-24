/* Unlinked regional matching draft. NTSC-U: 78 positional differences in the focused check; retail size recovered, but constant hoisting and loop scheduling differ. */
#include "common.h"


/* localdecomp:start func_L30_003B1CD0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003B3358;
extern u8 *D_L30_0021F098[];
extern void func_0037E2F0(void *, f32, f32);
extern s32 D_L30_001DED34;
__asm__(".extern D_L30_001DED34, 4");
extern s32 D_L30_001DED38;
__asm__(".extern D_L30_001DED38, 4");
extern f32 D_L30_001DED3C;
__asm__(".extern D_L30_001DED3C, 4");
extern f32 D_L30_001DED40;
__asm__(".extern D_L30_001DED40, 4");
extern f32 D_L30_001DED44;
__asm__(".extern D_L30_001DED44, 4");
extern s32 func_0037E208(s32, s32);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_0046D570(u8 *position, s32 life, s32 colour, s32 a3, s32 spin, void *velocity, s32 t2,
                             s32 t3, s16 arg8, s32 arg9, f32 size, f32 start_size);

void func_L30_003B1CD0(u8 *moby, s32 n) {
    V_003B3358 a;
    V_003B3358 b;
    V_003B3358 d;
    V_003B3358 c;
    vu0_q qb, qc, qr;
    u8 *p;
    s32 r;
    s32 i;

    for (i = 0; i < n; i++) {
        r = func_0037E208(D_L30_001DED34 - 5, D_L30_001DED34);
        func_0037E2F0(&a, D_L30_001DED3C * 0.7f, D_L30_001DED3C);
        a.y = -fabs_asm(a.y);
        func_0037E2F0(&b, D_L30_001DED40 * 0.7f, D_L30_001DED40);
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %3\n\tsqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(a), "=m"(c) : "m"(a), "m"(*(vu0_v4 *)(moby + 0x10)) : "vf1", "vf2");
        __asm__("lqc2 %0, %2\n\tlqc2 %1, %3" : "=j"(qb), "=j"(qc) : "m"(b), "m"(c));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qb), "j"(qc));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(qr));
        vec_sub_ab(&d, &b, &a);
        {
            f32 len = func_00388770(&d);
            f32 scale;
            do {
                scale = len / (f32)r * 1.3f;
            } while (0);
            func_00388830(&d, &d, scale);
        }
        p = func_L01_0046D570((u8 *)&a, r, D_L30_001DED38, 0, 1, &d, 0, 0, 6, 0,
                              D_L30_001DED44 * 0.25f, D_L30_001DED44);
        if (p != 0) {
            p[2] = D_L30_0021F098[0x5C][1];
        }
    }
}
/* localdecomp:end func_L30_003B1CD0 */

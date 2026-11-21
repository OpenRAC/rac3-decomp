#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00423AB8 */
typedef struct {
    s16 id;
    s16 arg;
    f32 f;
} B_00420D88;

typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[30];
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2C[20];
} T_00420D88;

extern u8 D_001D5471;
typedef struct {
    u8 pad0[68];
    s16 count;
    u8 pad46[346];
    u8 *list[1];
} G_00420D88;

extern G_00420D88 D_L01_001E6D80;
extern T_00420D88 D_L01_00244500[];
extern void func_0011A264(void *buf, s32 c, s32 n);
extern void func_L01_0043A430(u8 *m, s32 arg, T_00420D88 *e);

void func_L01_00423AB8(void) {
    B_00420D88 buf[2];
    u8 *m;
    T_00420D88 *e;
    s32 i;
    s32 j;
    s32 k;
    f32 f;

    if (D_001D5471 == 0) {
        return;
    }
    func_0011A264(buf, 0, 8);
    for (i = 0; i < D_L01_001E6D80.count; i++) {
        m = D_L01_001E6D80.list[i];
        if (*(s32 *)(m + 84) == 0) {
            for (j = 0; buf[j].id != 0; j++) {
                if (*(s16 *)(m + 170) != buf[j].id) {
                    continue;
                }
                f = buf[j].f;
                for (k = 0; k < 7; k++) {
                    if (D_L01_00244500[k].b1 == 0) {
                        break;
                    }
                }
                if (k < 7) {
                    e = &D_L01_00244500[k];
                    func_L01_0043A430(m, buf[j].arg, e);
                    e->f20 = f;
                    e->f24 = f;
                    e->f28 = f;
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00423AB8 */

/* localdecomp:start func_L01_00423C48 */
extern vu0_v4 D_L01_001E29C0[];
extern void func_0038D000(void *, void *, void *);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);

void func_L01_00423C48(vu0_v4 *a0, f32 a, f32 b, f32 c) {
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 x;
    vu0_q q;
    s32 r;

    v = *a0;
    qzero(&w);
    func_0038D000(&v, &v, &D_L01_001E29C0[2]);
    func_003C4C18(&w, a);
    b = b * w.z;
    /* x = D[0]: lqc2 into a VU0 register, stored by the compiler (a plain sqc2) */
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(D_L01_001E29C0[0]));
    *(vu0_q *)&x = q;
    w.z = b;
    /* w += v; w = x + w: one VU0 sequence */
    __asm__(
        "lqc2 $vf2, %1\n\t"
        "lqc2 $vf1, %0\n\t"
        "vadd.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %0\n\t"
        "lqc2 $vf1, %0\n\t"
        "lqc2 $vf2, %2\n\t"
        "vadd.xyz $vf1, $vf2, $vf1\n\t"
        "sqc2 $vf1, %0"
        : "+m"(w) : "m"(v), "m"(x) : "memory");
    r = func_L01_003303B8((u8 *)&w, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, c * func_003824E0(0.2f, 0.4f), 0.0f, 0.0f, 2.0f, 1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    if (r != 0) {
        func_L01_004AAC98(0, 0, (void *)r, 0x1F7B);
    }
}
/* localdecomp:end func_L01_00423C48 */

/* localdecomp:start func_L01_00423DF0 */
extern s32 D_L01_001E6DB4[];
extern void func_0013D3D0(s32);

void func_L01_00423DF0(void) {
    if (D_L01_001E6DB4[0] == 1) {
        func_0013D3D0(100);
    }
}
/* localdecomp:end func_L01_00423DF0 */

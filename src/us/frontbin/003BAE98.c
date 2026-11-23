#include "common.h"

/* NTSC-U version of func_003C03A8 (frontbin): 0.02 -> 0.0166667 */

typedef int Q_3BAE98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BAE98;
extern f32 D_U_001D8E90;
extern f32 D_U_001D8FF8;
extern s32 D_U_001D8FC4;
extern s32 D_U_001D8EB0;
extern s32 D_U_001D8FCC;
extern s32 D_U_001D8FC8;
extern f32 D_U_001D8FD0;
extern f32 D_U_001D8FD4;
extern f32 D_U_001D8FD8;
extern f32 D_U_001D8FDC;
extern f32 D_U_001D8FE8;
extern f32 D_U_001D8FEC;
extern f32 D_U_001D8FF0;
extern f32 D_U_001D8FF4;
extern s32 D_U_001D8FE0;
extern s32 D_U_001D8FE4;
extern s32 D_U_001D8FC0;
extern f32 D_U_001DA3B4;
extern s32 D_U_001D9D80;
extern void func_U_003A3EF0(s32, unsigned long);
extern void func_U_00388018(void);
extern void func_U_003888F0();
extern s32 func_U_003894A0(s32, s32, f32);
extern void func_U_003886E8(f32 *, void *, f32);
extern void func_U_003D41E0(void *, s32, s32, s32, s32, f32);
/* localdecomp:start func_U_003BAE98 */
/* Based on the existing PAL source and the NTSC decomp draft for its boot counterpart. */

#include "vu0.h"
__asm__(".extern D_U_001D8E90, 4");
__asm__(".extern D_U_001D8FF8, 4");
__asm__(".extern D_U_001D8FC4, 4");
__asm__(".extern D_U_001D8EB0, 4");
__asm__(".extern D_U_001D8FCC, 4");
__asm__(".extern D_U_001D8FC8, 4");
__asm__(".extern D_U_001D8FD0, 4");
__asm__(".extern D_U_001D8FD4, 4");
__asm__(".extern D_U_001D8FD8, 4");
__asm__(".extern D_U_001D8FDC, 4");
__asm__(".extern D_U_001D8FE8, 4");
__asm__(".extern D_U_001D8FEC, 4");
__asm__(".extern D_U_001D8FF0, 4");
__asm__(".extern D_U_001D8FF4, 4");
__asm__(".extern D_U_001D8FE0, 4");
__asm__(".extern D_U_001D8FE4, 4");
__asm__(".extern D_U_001D8FC0, 4");
extern s32 D_U_001DA3B8;
extern void func_U_003BD9A0();
void func_U_003BAE98(void *p) {
    V4_3BAE98 m0[3];
    V4_3BAE98 m30;
    V4_3BAE98 m40[3];
    V4_3BAE98 m70;
    V4_3BAE98 m80[4];
    f32 k, ph, t, s, w;
    s32 i, j, n, col, al, lo;
    u8 ob;
    k = D_U_001DA3B4 / (D_U_001D8E90 * 0.0166666675f);
    if (D_U_001D8FF8 < k) {
        func_U_003BD9A0(p, 0, m80);
        k = 1.0f;
        ph = (f32)(D_U_001D9D80 % D_U_001D8FC4) / (f32)D_U_001D8FC4;
        func_U_003A3EF0(8, 0);
        func_U_003A3EF0(0x14, 0xFF9000000260UL);
        func_U_003A3EF0(0x47, 0x533F1);
        func_U_00388018();
        for (i = 0; i < 4; i++) {
            m0[0] = m80[1];
            m0[1] = m80[2];
            m0[2] = m80[0];
            func_U_003888F0(&m30, (V4_3BAE98 *)&D_U_001D8EB0 + i, m80);
            for (j = 0; j < D_U_001D8FCC; j++) {
                n = D_U_001D8FC8;
                t = (f32)((D_U_001DA3B8 + n / D_U_001D8FCC * j) % n) / (f32)n;
                ob = i & 1;
                if (ob) {
                    t += 0.5f;
                    if (1.0f < t) t -= 1.0f;
                }
                t = t * t;
                if (i < 2) {
                    w = (D_U_001D8FD4 - D_U_001D8FD0) * t * k + D_U_001D8FD0;
                    s = (D_U_001D8FDC - D_U_001D8FD8) * t + D_U_001D8FD8;
                } else {
                    w = (D_U_001D8FEC - D_U_001D8FE8) * t * k + D_U_001D8FE8;
                    s = (D_U_001D8FF4 - D_U_001D8FF0) * t + D_U_001D8FF0;
                }
                col = func_U_003894A0(D_U_001D8FE0, D_U_001D8FE4, t);
                lo = col & 0xFFFFFF;
                al = (s32)((f32)((u32)(col & 0xFF000000) >> 24) * k);
                col = lo | (al << 24);
                func_U_003886E8((f32 *)&m40[0], &m0[0], s);
                func_U_003886E8((f32 *)&m40[1], &m0[1], s);
                func_U_003886E8((f32 *)&m40[2], &m0[2], w);
                vec_sub_ab(&m70, &m30, &m40[2]);
                func_U_003D41E0(m40, D_U_001D8FC0, col, 4, 1, ph + t + (f32)(i & 1) * 0.5f);
            }
        }
        func_U_003A3EF0(0x47, 0x5360B);
    }
}
/* localdecomp:end func_U_003BAE98 */

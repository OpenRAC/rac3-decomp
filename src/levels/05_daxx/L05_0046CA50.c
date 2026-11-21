#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_0046CA50 */
typedef struct {
    f32 pos[3];
    f32 f0C;
    f32 f10;
    u8 b14;
    u8 b15;
    u8 pad16[6];
    void *fn;
} S_46CA50_Sub;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_46CA50;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    V4_46CA50 v10;
    S_46CA50_Sub sub;
} S_46CA50;
extern S_46CA50 *func_L01_004618E0(s32 size);
extern s32 func_00382468(s32);
extern u8 *D_L05_00220918[];
extern void func_L01_00473860(void);
S_46CA50 *func_L05_0046CA50(V4_46CA50 *a0, f32 *a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, f32 f12, f32 f13, f32 f14, s32 st) {
    S_46CA50 *p;
    S_46CA50_Sub *s;
    s32 d, n;
    p = func_L01_004618E0(0x70);
    if (p) {
        p->v10 = *a0;
        p->v10.w = (f32)st;
        p->w4 = (t1 << 24) | a3;
        p->b9 = 0x44;
        p->b3 = 0x48;
        p->b1 = 0;
        p->fC = f12;
        p->b8 = func_00382468(255);
        d = t2 - t1;
        n = d / a2;
        p->b2 = D_L05_00220918[0][t3];
        s = &p->sub;
        s->pos[0] = a1[0];
        s->pos[1] = a1[1];
        s->pos[2] = a1[2];
        s->f0C = f14;
        s->b15 = t0;
        if (n != 0) {
            a2 = d / n;
        }
        s->b14 = n;
        s->f10 = (f13 - f12) / (f32)a2;
        a2 = abs_asm(a2);
        p->hA = a2;
        s->fn = func_L01_00473860;
    }
    return p;
}
/* localdecomp:end func_L05_0046CA50 */

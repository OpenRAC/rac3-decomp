#include "common.h"

/* localdecomp:start func_L39_0056F820 */
/* decode loop from func_L39_00558E68 (same file family) */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L39_004997E0[];
typedef struct {
    u8 p0[0x19E4];
    u8 b19E4;
    u8 p19E5[0x1A0A - 0x19E5];
    u8 b1A0A;
    u8 p1A0B[0x24FE - 0x1A0B];
    u8 b24FE;
    u8 p24FF;
    u8 b2500;
} G_0056F820;
typedef struct {
    u8 p0[0x200];
    u8 b200[0x30];
    u128_t q230;
    u8 p240[0x2A0 - 0x240];
    s16 h2A0;
    u8 p2A2[0x2C0 - 0x2A2];
    f32 f2C0;
    u8 p2C4[0x460 - 0x2C4];
} E_0056F820;
typedef struct {
    u8 p0[0x30];
    u128_t q30;
    u8 p40[0x94 - 0x40];
    s32 w94;
} O_0056F820;
typedef union { u8 b[8]; u32 w[2]; } Buf_0056F820;
extern E_0056F820 D_L39_0024DE80[];
extern void func_0038CC88(O_0056F820 *, void *, s32);
extern G_0056F820 *func_L39_0061BF38(s32);

void func_L39_0056F820(O_0056F820 *o) {
    E_0056F820 *e = &D_L39_0024DE80[o->w94];
    G_0056F820 *p;
    G_0056F820 *g;
    Buf_0056F820 buf;
    u8 *q;
    u8 *q2;
    u32 a, b, a2, b2, r, r2;
    s32 n, k, mm, i, n2, k2, mm2, i2;
    u8 *d;
    u8 *d2;
    s32 flag;

    o->q30 = e->q230;
    ((void (*)(O_0056F820 *, u8 *, s32))func_0038CC88)(o, e->b200, 0x30);
    if (e->h2A0 == 3 && e->f2C0 >= 0.5f) {
        func_L39_0061BF38(o->w94);
        if (func_L39_0061BF38(o->w94)->b1A0A != 0) {
            e->f2C0 = 1.0f;
        } else {
            g = func_L39_0061BF38(o->w94);
            if (g != 0) g->b1A0A = 1;
        }
    } else {
        p = func_L39_0061BF38(o->w94);
        if (e->h2A0 == 0 && p != 0) {
            flag = 0;
            q = &p->b19E4;
            if (*q == 0) {
                r = 0;
            } else {
                n = *q;
                k = ((u32)q - n) & 7;
                mm = n + 1;
                d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[mm + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                r = b;
            }
            if ((r ^ 1) == 0) {
                flag = 1;
            } else {
                q2 = &p->b19E4;
                if (*q2 == 0) {
                    r2 = 0;
                } else {
                    n2 = *q2;
                    k2 = ((u32)q2 - n2) & 7;
                    mm2 = n2 + 1;
                    d2 = buf.b;
                    for (i2 = 0; i2 < 40; i2 += 5) {
                        *d2++ = D_L39_004997E0[mm2 + ((k2 + i2) & 7) * 255];
                    }
                    a2 = buf.w[0] ^ (u32)q2;
                    b2 = buf.w[1] ^ a2;
                    buf.w[0] = a2;
                    buf.w[1] = b2;
                    r2 = b2;
                }
                if ((r2 ^ 0x1D) == 0 || p->b24FE != 0 || p->b2500 != 0) {
                    flag = 1;
                }
            }
            if ((u8)flag) {
                g = func_L39_0061BF38(o->w94);
                if (g != 0) g->b1A0A = 1;
            }
        }
    }
}
/* localdecomp:end func_L39_0056F820 */

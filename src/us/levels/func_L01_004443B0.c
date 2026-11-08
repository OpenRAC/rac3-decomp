#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    union {
        s128 q;
        f32 f[4];
    } pos;
    s128 col;
} E_001E8D00;

typedef struct {
    u8 pad0[4];
    s16 s4;
    u8 pad6[0x11];
    u8 b17;
    u8 *p18;
    s16 s1C;
} Rec_004474E8;
typedef struct {
    u8 pad0[0x20];
    u8 *p20;
    u32 f24;
    u8 b28;
    u8 pad29[3];
    f32 f2C;
} Src_004474E8;

extern f32 fe_func_003C3D30(void *, s32, s32, f32);
extern s32 fe_func_003D5630(void);
extern void fe_func_0038DBD8_00447470();
/* localdecomp:start func_L01_004443B0 */
extern Rec_004474E8 *func_0037E0B8(s32 a0);
extern u8 func_L01_00449C10(u8 *p);
extern u8 *func_L01_00445EB8(s32 a0);

f32 func_L01_004443B0(s32 a0, Src_004474E8 *a1) {
    Rec_004474E8 *p = func_0037E0B8(a0);
    f32 f = 0.0f;
    if (p != 0) {
        u8 *q = p->p18;
        if (q != 0) {
            u8 c = q[0x20];
            if (c != 0xFE) {
                if (c == 0xFD) {
                    p->s1C = 0;
                    p->p18 = 0;
                }
            } else {
                p->s1C = 0;
                p->p18 = 0;
            }
        }
        {
            short t = p->s1C;
            if (t != 0) {
                p->s1C = (unsigned short)p->s1C + 1;
                if (t >= 0x79) {
                    p->p18 = 0;
                    p->s1C = 0;
                }
            }
        }
        if (a1 != 0) {
            u8 *x = a1->p20;
            f = a1->f2C;
            if (x != 0) {
                if (p->p18 != x) {
                    p->p18 = x;
                    p->b17 = func_L01_00449C10(a1->p20);
                    p->s1C = 1;
                } else {
                    if (a1->b28 == 9) {
                        if (p->s1C < 0x3C) f = 0.0f;
                        else p->s1C = 1;
                    } else {
                        if (p->s1C < 10) f = 0.0f;
                        p->s1C = 1;
                    }
                }
            }
            if ((f32)p->s4 <= 1.0f && f > 0.0f && f < 1.0f) f = 1.0f;
            if (a1->f24 & 0x100000) {
                u8 *o = func_L01_00445EB8(a0);
                if (o != 0) o[0x18] = 1;
            } else if (a1->f24 & 0x200000) {
                u8 *o = func_L01_00445EB8(a0);
                if (o != 0) o[0x18] = 2;
            } else if (a1->f24 & 0x400000) {
                u8 *o = func_L01_00445EB8(a0);
                if (o != 0) o[0x18] = 3;
            } else if (a1->f24 & 0x10000000) {
                u8 *o = func_L01_00445EB8(a0);
                if (o != 0) o[0x18] = 4;
            } else {
                u8 *o = func_L01_00445EB8(a0);
                if (o != 0) o[0x18] = 0;
            }
        }
    }
    return f;
}
/* localdecomp:end func_L01_004443B0 */

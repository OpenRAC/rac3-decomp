#include "common.h"

/* localdecomp:start func_L01_003D8DA0 */
#include "vu0.h"

extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00471BF0(void *, void *, s32);
extern s32 D_L01_001DF4D0_003D8DA0;
__asm__(".extern D_L01_001DF4D0_003D8DA0, 4");
extern s32 D_L01_001DF4D4_003D8DA0;
__asm__(".extern D_L01_001DF4D4_003D8DA0, 4");
extern f32 D_L01_001DF4D8_003D8DA0;
__asm__(".extern D_L01_001DF4D8_003D8DA0, 4");

void func_L01_003D8DA0(void *pos) {
    vu0_v4 a;
    vu0_v4 b;
    func_00382580(&a, 0.25f, 0.75f);
    vec_add_ab(&a, &a, pos);
    vec_sub_ba(&b, &a, pos);
    func_0038CE20(&b, &b, func_003824E0(2.0f, 3.0f) * 0.020000001f);
    b.z += D_L01_001DF4D8_003D8DA0;
    func_L01_00471BF0(&a, &b, func_00382498(D_L01_001DF4D4_003D8DA0, D_L01_001DF4D0_003D8DA0));
}
/* localdecomp:end func_L01_003D8DA0 */

/* localdecomp:start func_L01_003D8E60 */
#include "vu0.h"

extern f32 D_L01_001DF4E0_003D8E60;
__asm__(".extern D_L01_001DF4E0_003D8E60, 4");
extern f32 D_L01_001DF4E4_003D8E60;
__asm__(".extern D_L01_001DF4E4_003D8E60, 4");
extern u8 D_L01_001DF4EC_003D8E60;
__asm__(".extern D_L01_001DF4EC_003D8E60, 1");
extern s32 D_L01_001DF4F0_003D8E60;
__asm__(".extern D_L01_001DF4F0_003D8E60, 4");
extern u8 *D_L01_00221098_003D8E60[];
extern s32 func_L01_00459590_003D8E60(void *, s32, f32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_0046FB40_003D8E60(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_00475C60_003D8E60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_003D8DA0_003D8E60(void *);
extern void func_L01_003D8C80_003D8E60(void *);

void func_L01_003D8E60(void *pos, void *vel, s32 a2, s32 a3, s32 a4, s32 count, s32 size, s32 a7, f32 height, f32 r, f32 f) {
    vu0_v4 sphere;
    vu0_v4 p;
    vu0_v4 v;
    u8 *e;
    vu0_q qv;
    s32 tag;
    s32 i;
    f32 s;

    *(vu0_q *)&sphere = *(vu0_q *)pos;
    sphere.w = r + r;
    s = 128.0f;
    if (size > 0x40) {
        s = size;
    }
    if (func_L01_00459590_003D8E60(&sphere, 0, s) < 0) {
        return;
    }
    if (count > 0) {
        tag = (size >> 5) * 16 + 2;
        for (i = count; i != 0; i--) {
            vu0_q qa;

            func_00382580(&p, r * 0.15f, r * 0.4f);
            vec_add_ab(&p, &p, pos);
            __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(*(vu0_v4 *)vel));
            qzero(&v);
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qv));
            __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qa));
            if (a7 == 0 || func_00382468(a7)) {
                e = func_L01_0046FB40_003D8E60(&p, &v, (a2 * 5 + 2) / 6, 0x808080, func_00382498(-5, 5), D_L01_001DF4EC_003D8E60, 0, 0,
                                      D_L01_001DF4E0_003D8E60 * r * 210000.0f, D_L01_001DF4E4_003D8E60 * r * 210000.0f,
                                      func_003824E0(f * 0.00040000002f, -0.00080000004f));
                if (e != 0) {
                    e[9] = tag;
                    if (a7 == 0 && func_00382468(D_L01_001DF4F0_003D8E60)) {
                        e[2] = D_L01_00221098_003D8E60[91][0];
                        e[3] = 0x48;
                    } else {
                        e[2] = D_L01_00221098_003D8E60[91][4];
                        e[3] = func_00382468(4) ? 0x44 : 0x48;
                    }
                }
            } else {
                u8 *e2;

                r *= 0.8f;
                e2 = func_L01_00475C60_003D8E60(&p, &v, (a2 * 5 + 2) / 6, func_00382498(-1, 2), 0x7F407FFF, 0x407FFF,
                                      D_L01_001DF4E4_003D8E60 * r * 210000.0f, D_L01_001DF4E4_003D8E60 * r * 210000.0f,
                                      func_003824E0(f * 1.5f, f), 0);
                if (e2 != 0) {
                    e2[9] = tag;
                    e2[2] = D_L01_00221098_003D8E60[97][3];
                }
            }
        }
    }
    if (height == -100000.0f || height + 2.0f < ((f32 *)pos)[2]) {
        if (a3 != 0 && !func_00382468(10 - a3)) {
            func_L01_003D8DA0_003D8E60(pos);
        }
        if (a4 != 0 && !func_00382468(20 - a4)) {
            func_L01_003D8C80_003D8E60(pos);
        }
    }
}
/* localdecomp:end func_L01_003D8E60 */

/* localdecomp:start func_L01_003D9240 */
typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x34 - 0x21];
    u16 flags;
    u8 pad36[0x68 - 0x36];
    void *pvars;
} M_3D9240;

typedef struct {
    M_3D9240 *mobys[15];
    s16 count;
    s16 timer;
    f32 f40;
    f32 f44;
    u8 pad48[2];
    u8 b4A;
    u8 b4B;
} V_3D9240;

extern u16 D_L01_001DF4F4;
__asm__(".extern D_L01_001DF4F4, 2");
extern u8 D_L01_001D66B0;
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00450F00(void *, void *);
extern void func_L01_003D8E60(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_0038CB00(s16 *);
extern void func_003C2880(void *);

void func_L01_003D9240(M_3D9240 *self) {
    V_3D9240 *v = self->pvars;
    M_3D9240 *m;
    s32 i;
    s32 done;
    u8 buf[0x10];

    switch (self->state) {
    case 0:
        func_L01_004450F0(self, 1, -1);
        v->timer = D_L01_001DF4F4;
        if (v->f44 == -100000.0f) {
            v->f44 = func_003C3D30((u8 *)self + 0x10, 0, 0, 0.5f) + 0.1f;
        }
        break;
    case 1:
        done = 0;

        for (i = 0; v != 0 && i < v->count; i++) {
            m = v->mobys[i];
            if (m == 0 || m->state == 0xFE || m->state == 0xFD || (m->flags & 2) || m->pvars == 0) {
                done++;
            } else {
                func_L01_00450F00(m, buf);
                func_L01_003D8E60(buf, &D_L01_001D66B0, 30, 7, 6, 2, 0x40, 2, v->f44, v->f40, -11.0f);
            }
        }
        if ((!v->b4A && (done == v->count || func_0038CB00(&v->timer))) || (v->b4A && v->b4B)) {
            func_003C2880(self);
        }
        break;
    }
}
/* localdecomp:end func_L01_003D9240 */

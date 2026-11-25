#include "common.h"

#include "structs/moby.h"
#include "vu0.h"

/* localdecomp:start func_U_L07_003A5E00 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
} R_003A5E00;
extern s32 D_L07_001DE410;
__asm__(".extern D_L07_001DE410, 4");
extern f32 D_L07_001DE418;
__asm__(".extern D_L07_001DE418, 4");
extern void func_L07_003A62C8(R_003A5E00 *, f32, void *, void *);
extern void func_L07_003A61F8(void *, void *, s32, s32, f32);
extern void func_U_0040CA00(void *, void *, f32);
extern void func_U_0040C7A0(void *, void *, f32);
extern void func_U_0044D078(struct Moby *, void *, s32, s32);
extern void func_U_0040CBE0(void *, void *, void *);
extern f32 func_U_0040C8A0(void *);

void func_U_L07_003A5E00(void *object) {
    u8 *o = object;
    u8 *s = *(u8 **)(o + 0x68);
    R_003A5E00 r;
    vu0_v4 g;
    vu0_v4 t;
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 e;
    u8 *pp;
    u8 *w;
    s32 a;
    s32 i;
    s32 j;
    s32 jj;
    s32 k;
    s32 m;
    f32 len;
    f32 f20;
    f32 x;
    vu0_v4 *q;
    vu0_v4 *q2;
    vu0_v4 *p3;

    func_L07_003A62C8(&r, (f32)*(u16 *)(o + 0x96) * *(f32 *)(s + 0x29C), *(void **)(s + 0x290), *(void **)(s + 0x294));
    if (*(u16 *)(o + 0x96) < D_L07_001DE410) {
        r.f8 = D_L07_001DE418;
    }
    *(vu0_q *)&t = 0;
    t.z = r.f4;
    w = s + 0x280;
    g = t;
    func_U_0044D078(*(struct Moby **)(o + 0xB8), object, s[0x2BA], 0);
    *(u16 *)(o + 0x34) = *(u16 *)(o + 0x34) & 0xFFFD;
    *(vu0_q *)s = *(vu0_q *)(o + 0x10);
    *(vu0_q *)(s + 0x140) = *(vu0_q *)(o + 0x10);
    func_U_0040CA00(&t, o + 0xC0, r.f0);
    pp = (u8 *)&p;
    for (a = 1; a < r.b15; a++) {
        vec_add_ab(s + a * 16, s + a * 16 - 16, &t);
        *(vu0_q *)(s + a * 16 + 0x140) = *(vu0_q *)(s + a * 16);
    }
    q = (vu0_v4 *)s + r.b15;
    q2 = (vu0_v4 *)s + (r.b15 + 20);
    for (j = r.b15; j < 20; j++, q++, q2++) {
        p = *q;
        vec_sub_ba(&d, q, q2);
        func_U_0040C7A0(&d, &d, r.f8);
        vec_add_ab(q, q, &d);
        vec_add_ba(q, q, &g);
        *(vu0_q *)q2 = *(vu0_q *)&p;
    }
    for (k = 0; k < r.b14; k++) {
        for (p3 = (vu0_v4 *)s, jj = 0; jj < 19; p3++, jj++) {
            m = 1;
            if (r.b17 != 0 && jj + 1 < 20) {
                for (;;) {
                    s32 ok;
                    f32 dist = (f32)m * r.f0;
                    func_L07_003A61F8(p3, p3 + m, jj >= r.b15, jj + m >= r.b15, dist * dist);
                    m++;
                    ok = (jj + m < 20);
                    if (m > r.b17 || !ok) {
                        break;
                    }
                }
            }
        }
    }
    func_U_0040CBE0(pp, w, *(u8 **)(o + 0xB8) + 0xC0);
    vec_add_ba(&p, &p, *(u8 **)(o + 0xB8) + 0x10);
    for (q = (vu0_v4 *)s, i = 0; i < 20; i++, q++) {
        f32 minz = r.fC + *(f32 *)(s + 0x298);
        if (q->z < minz) {
            q->z = minz;
        }
        if (i < r.b16) {
            continue;
        }
        vec_sub_ab(&d, &p, q);
        f20 = r.f10 * r.f10;
        len = func_U_0040C8A0(&d);
        x = f20 / (len + f20) - 0.5f;
        if (0.0f < x) {
            func_U_0040C7A0(&e, &d, x + x);
            vec_sub_ab(q, q, &e);
        }
        if (!(q->z < p.z)) {
            continue;
        }
        d.z = 0.0f;
        len = func_U_0040C8A0(&d);
        x = f20 / (len + f20) - 0.5f;
        if (0.0f < x) {
            func_U_0040C7A0(&e, &d, x + x);
            vec_sub_ab(q, q, &e);
        }
    }
}
/* localdecomp:end func_U_L07_003A5E00 */

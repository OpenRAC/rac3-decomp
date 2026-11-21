#include "common.h"

/* localdecomp:start func_L16_003E8D20 */
#include "vu0.h"
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);

void func_L16_003E8D20(void *out, void *base, f32 lo, f32 hi)
{
    vu0_v4 v;
    f32 ang;

    qzero(&v);
    ang = func_00382538();
    v.x = func_0038D098(ang);
    v.y = func_0038D0B0(ang);
    func_0038CE20(&v, &v, func_003824E0(lo, hi));
    vec_add_ba(out, &v, base);
}
/* localdecomp:end func_L16_003E8D20 */

/* localdecomp:start func_L16_003E8DC0 */
extern void func_L16_003E8D20(void *out, void *base, f32 lo, f32 hi);
extern void *func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 D_L16_001DF638;
extern f32 D_L16_001DF63C;
__asm__(".extern D_L16_001DF638, 4");
__asm__(".extern D_L16_001DF63C, 4");

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad1[0x10];
    u8 a;
    u8 pad2;
    s16 b;
    u8 pad3[0x34];
    u8 *sub;
} L16Obj;

void *func_L16_003E8DC0(void *pos, u8 *q, f32 *r, u8 tag, s32 val, f32 f0, f32 fu, f32 f1)
{
    L16Obj *o;
    u8 *p;
    s32 i;
    s32 flag;

    o = func_003C24B0(0x1D2C, 0x90);
    if (o == 0) return 0;
    p = o->sub;
    o->b = 0xFF;
    o->a = 0xFF;
    flag = 1;
    vec_add_ba(&o->pos, pos, q);
    *(vu0_q *)(p + 0x40) = *(vu0_q *)r;
    p[0x6E] = 4;
    *(s32 *)(p + 0x68) = val;
    *(f32 *)(p + 0x64) = f1;
    p[0x6F] = tag;
    *(f32 *)(p + 0x60) = f0;
    i = 0;
    q = p;
    r = (f32 *)(p + 0x50);
    for (; i < 4 && i < p[0x6E]; i++, r++, q += 16) {
        if (i < (s32)(p[0x6E] * 0.5f)) {
            if (i == 0) {
                *(vu0_q *)p = *(vu0_q *)&o->pos;
            } else {
                func_L16_003E8D20(q, pos, 1.5f, f0 * 0.8f);
            }
            ((f32 *)q)[3] = D_L16_001DF638 + func_003824E0(-0.5f, 3.0f);
            *r = func_003824E0(-5.0f, 5.0f);
        } else {
            if (flag) {
                flag = 0;
                vec_sub_ab(p + 0x80, p + 0x10, p);
                func_0038CE20(p + 0x80, p + 0x80, 0.5f);
                vec_add_ab(p + 0x80, p + 0x80, p);
                func_L16_003E8D20(q, p + 0x80, 0.2f, f0 * 0.3f);
            } else {
                func_L16_003E8D20(q, p + 0x70, 0.25f, 0.75f);
            }
            *(vu0_q *)(p + 0x70) = *(vu0_q *)q;
            ((f32 *)q)[3] = D_L16_001DF63C + func_003824E0(0.0f, 0.3f);
            *r = *(f32 *)(p + 0x64) * func_003824E0(0.75f, 0.95f);
        }
    }
    func_L01_004450F0(o, 0, -1);
    return o;
}
/* localdecomp:end func_L16_003E8DC0 */

/* localdecomp:start func_L16_003E9068 */
extern vu0_v4 D_001E2B00;
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);

void func_L16_003E9068(void *pos, void *dir, f32 len, f32 f1, f32 f2, f32 width, f32 f4,
                       s32 a2, s32 a3, u8 alpha0, u8 alpha1, s32 tex)
{
    vu0_v4 d;
    vu0_v4 s;
    vu0_v4 b;
    vu0_v4 a;

    vec_sub_ab(&a, &D_001E2B00, pos);
    func_0038CF68(&a, &a, len);
    vec_add_ba(&a, &a, pos);
    func_0038CE20(&b, dir, width * 0.5f);
    vec_add_ab(&s, &a, &b);
    a2 += alpha0 << 24;
    a3 += alpha1 << 24;
    a2 += alpha0 << 24;
    a3 += alpha1 << 24;
    vec_sub_ab(&d, &a, &b);
    func_L01_0040A8C0(&d, &s, tex, 1, a2, a2, a3, a3, f1, f2, f4);
}
/* localdecomp:end func_L16_003E9068 */

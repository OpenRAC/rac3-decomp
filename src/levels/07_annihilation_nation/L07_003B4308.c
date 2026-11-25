#include "common.h"
#include "structs/moby.h"
#include "vu0.h"

/* localdecomp:start func_L07_003B4308 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B4308;
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L07_003BF158(u8 *, void *, void *, s32, u8, s32, s32);
void func_L07_003B4308(u8 *obj) {
    V4_003B4308 joint, sum;
    struct Moby *m = (struct Moby *)obj;
    u8 *p = m->pvar;
    func_003C2F58(obj, 13, (f32 *)&joint);
    vec_add_ba(&sum, &m->rotation, p + 0x610);
    func_L07_003BF158(obj, &joint, &sum, *(s32 *)(p + 0x90), p[0x45], 4, 0);
}
/* localdecomp:end func_L07_003B4308 */

/* localdecomp:start func_L07_003B4370 */
extern void func_L07_003B37D0(u8 *, s32);
extern s32 func_00382468(s32);

void func_L07_003B4370(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);

    switch (arg0[0x95]) {
    case 1:
        if (p[0x668] >= 6) {
            p[0x668] = 0;
            func_L07_003B37D0(arg0, 6);
            *(s16 *)(p + 0x660) = func_00382468(0x53) + 0xD0;
            break;
        }
        /* fall through */
    case 0:
        func_L07_003B37D0(arg0, 9);
        p[0x666] = 3;
        break;
    case 2:
        if (p[0x668] >= 3) {
            p[0x668] = 0;
            func_L07_003B37D0(arg0, 6);
            *(s16 *)(p + 0x660) = func_00382468(0xA7) + 0x1A1;
        } else {
            func_L07_003B37D0(arg0, 9);
            p[0x666] = func_00382468(2) + 3;
        }
        break;
    case 3:
        func_L07_003B37D0(arg0, 7);
        *(s16 *)(p + 0x660) = func_00382468(0x14D) + 0x341;
        break;
    }
}
/* localdecomp:end func_L07_003B4370 */

/* localdecomp:start func_L07_003B4470 */
#include "vu0.h"
__asm__(".extern D_L07_001DE468, 4");
extern f32 D_L07_001DE468[3] __attribute__((section(".sdata")));
void func_L07_003B4470(u8 *obj, vu0_v4 *ref) {
    extern void func_003CA4A0(void *, s32, s32 *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D688(void *, void *, void *);
    vu0_v4 sum, diff;
    vu0_v4 matrix[4];
    vu0_v4 quat;
    s32 joint;
    s32 *jointp=&joint;
    vu0_v4 *row3=&matrix[3];
    vu0_v4 *matp=matrix;
    u8 *p = *(u8 **)(obj+0x68);
    u8 *q=p+0x1C0;
    vu0_v4 *out=(vu0_v4 *)(p+0x330);
    s32 i=0;
    f32 angle, length, scale, turn;
    do {
        f32 size=*(f32 *)(obj+0x2C);
        size*=0.0009765625f;
        joint=i;
        func_003CA4A0(obj,1,jointp,matp);
        func_0038CE20(&sum,row3,size);
        func_0038D000(&sum,&sum,obj+0xC0);
        vec_add_ab(&sum,&sum,obj+0x10);
        *out=sum;
        vec_sub_ab(&diff,&sum,ref);
        angle=func_0038CE68(&diff,obj+0xC0)/D_L07_001DE468[i%3]*0.75f;
        length=func_0038CEA8(&diff);
        turn=angle+(angle<0.0f ? length * -0.25f : length * 0.25f);
        i++; ref++; out++;
        func_003C4840(&quat,&matrix[1],-turn);
        func_0038D688(q,q,&quat);
        scale=1.0f/sqrt_asm(func_0038CE68(q,q)+*(f32 *)(q+12)**(f32 *)(q+12));
        func_0038CE20(q,q,scale);
        *(f32 *)(q+12) *= scale;
        q+=0x40;
    }while(i<6);
}
/* localdecomp:end func_L07_003B4470 */

/* localdecomp:start func_L07_003B4688 */
extern void func_003C2F58(void *, s32, void *);

void func_L07_003B4688(void *arg0) {
    s32 i;
    u8 *p;

    i = 0;
    p = (u8 *)(*(s32 *)((u8 *)arg0 + 0x68)) + 0x330;
    do {
        func_003C2F58(arg0, i, p);
        i++;
        p += 0x10;
    } while (i < 6);
}
/* localdecomp:end func_L07_003B4688 */

/* localdecomp:start func_L07_003B46E8 */
void func_L07_003B46E8(u8 *obj) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_003C3BE8(f32, f32, f32);
    extern f32 func_L07_003B48E8(f32 x, f32 lo, f32 hi);
    extern void func_L01_0044E850(void *, void *, s32, f32, f32);
    extern void func_0038D750(void *, s32, f32);
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *a, *b, *matrix;
    s32 i, j, k;
    if (*(s32 *)(p + 0xD8) & 0x10) {
        *(f32 *)(p + 0x638) = func_0038DB00(func_0038D160(*(f32 *)(p + 0x80) - *(f32 *)(obj + 0x10), *(f32 *)(p + 0x84) - *(f32 *)(obj + 0x14)), *(f32 *)(obj + 0xF8));
        if (obj[0x20] == 7) {
            f32 t = *(f32 *)(p + 0x658);
            if (t > 1.0f) t = 2.0f - t;
            *(f32 *)(p + 0x638) = func_0038DAB8(*(f32 *)(p + 0x638), func_003C3BE8(-0.34906584f, 0.34906584f, t));
        }
        *(f32 *)(p + 0x638) = func_L07_003B48E8(*(f32 *)(p + 0x638), -1.0471976f, 1.0471976f);
    } else *(s32 *)(p + 0x638) = 0;
    func_L01_0044E850(obj, p + 0x5D0, 12, 0.014400000683963299f, 0.4320000410079956f);
    matrix = p + 0x3A0;
    k = 7;
    b = p + 0x4D0;
    j = 6;
    a = p + 0x3D0;
    for (i = 1; i >= 0; i--) {
        func_L01_0044E850(obj, a, j, 0.0432f, 0.4320000410079956f);
        j += 3;
        a += 0x80;
        func_L01_0044E850(obj, b, k, 0.0432f, 0.4320000410079956f);
        k += 3;
        b += 0x80;
    }
    *(f32 *)(p + 0x654) = func_0038DAB8(*(f32 *)(p + 0x654), 0.25132743f);
    func_0038D750(matrix, 1, *(f32 *)(p + 0x654));
}
/* localdecomp:end func_L07_003B46E8 */

/* localdecomp:start func_L07_003B48E8 */
/* localdecomp:start func_L07_003B48E8 */
/* Fold x into [lo, hi]: relative position, absolute value, 0.4/0.5 wrap, sign back. */
f32 func_L07_003B48E8(f32 x, f32 lo, f32 hi) {
    f32 denom = hi - lo;
    f32 mid = (lo + hi) * 0.5f;
    f32 t;
    s32 neg = 0;

    t = x - mid / denom;
    if (t < 0.0f) {
        t = -t;
        neg = 1;
    }
    if (0.4f < t) {
        f32 u = (t - 0.4f) * 0.5f + 0.4f;

        if (0.5f < u)
            u = 0.5f;
        t = u;
    }
    if (neg)
        t = -t;
    return mid + denom * t;
}
/* localdecomp:end func_L07_003B48E8 */
/* localdecomp:end func_L07_003B48E8 */

/* localdecomp:start func_L07_003B4978 */
typedef struct { u8 pad[0x16C]; u8 *p; } Data_003B4978;
extern Data_003B4978 D_L07_0021EC98_003B4978;
void func_L07_003B4978(void *obj, u8 side) {
    extern void func_003C2EC0(void *, s32, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C4C18(void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    struct { vu0_q matrix[4]; vu0_q position, direction, jitter, velocity; } v;
    s32 i;
    s32 life;
    f32 a,b;
    u8 *p;
    func_003C2EC0(obj, side * 3 + 8, v.matrix);
    v.direction = v.matrix[0];
    if (side == 1) vec_neg(&v.direction, &v.direction);
    func_0038CE20(&v.position, &v.direction, 1.0f);
    vec_add_ab(&v.position, &v.matrix[3], &v.position);
    i=1;
    do {
        v.jitter = v.position;
        func_003C4C18(&v.jitter, 1.0f);
        func_0038CE20(&v.velocity, &v.direction, func_003824E0(0.10000001f, 0.50000006f));
        func_003C4C18(&v.velocity, 0.060000002f);
        life = func_00382498(20,30);
        a = func_003824E0(52500.0f,105000.0f);
        b = func_003824E0(315000.0f,525000.0f);
        p = func_L01_0046FB40(&v.position,&v.velocity,life,0x808080,func_00382468(2) ? 3 : -3,127,0,0,a,b,0.0f);
        if (p) p[2] = *D_L07_0021EC98_003B4978.p;
        --i;
    } while (i >= 0);
}
/* localdecomp:end func_L07_003B4978 */

/* localdecomp:start func_L07_003B4B68 */
void func_L07_003B4C30(void *, u8, f32, u8);

void func_L07_003B4B68(void *arg0, s16 arg1, f32 arg2) {
    s32 i;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    if (arg1 != -1 && arg1 < 0x15) {
        return;
    }
    for (i = 0; i < 2; i++) {
        if ((arg1 & 3) == 0 && arg1 != -1) {
            func_L07_003B4C30(arg0, i, arg2, p[0x44]);
        } else {
            func_L07_003B4C30(arg0, i, arg2, 0);
        }
    }
}
/* localdecomp:end func_L07_003B4B68 */

/* localdecomp:start func_L07_003B4C30 */
#include "vu0.h"
extern u8 *D_L07_0021EE04 __attribute__((section(".data")));
void func_L07_003B4C30(void *self, u8 side, f32 amount, u8 kind)
{
    extern void func_003C2EC0(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003C4C18(void *, f32);
    extern u8 *func_L01_00475128(void *, void *, void *, f32, f32, f32, u32, s32, s32, s32, s32);
    vu0_v4 matrix[4];
    vu0_v4 position;
    vu0_v4 velocity;
    u8 *effect;
    func_003C2EC0(self, side * 3 + 8, matrix);
    if (side == 1) vec_neg(matrix, matrix);
    func_0038CF68(&position, matrix, 1.0f);
    vec_add_ab(&position, &matrix[3], &position);
    func_0038CF68(&velocity, matrix, 0.40000003576278687f);
    func_003C4C18(&velocity, 0.04000000283122063f);
    effect = func_L01_00475128(self, &position, &velocity, *(f32 *)((u8 *)self + 0x18), 84000.0f, amount * 420000.0f,
        0x7F808080, (s32)(amount * 42.0f), 5, kind, 0);
    if (effect) effect[2] = D_L07_0021EE04[0];
    if (amount >= 1.0f) {
        func_003C4C18(&position, 0.2f);
        effect = func_L01_00475128(self, &position, &velocity, *(f32 *)((u8 *)self + 0x18), 84000.0f, 84000.0f,
            0x7F808080, 8, 0, 0, 0);
        if (effect) effect[2] = D_L07_0021EE04[0];
    }
}
/* localdecomp:end func_L07_003B4C30 */

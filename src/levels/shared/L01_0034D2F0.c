#include "common.h"

typedef struct {
    char pad0[0x10];
    char pos[0x2];
    s16 active;
    char pad14[0x18 - 0x14];
    f32 unk18;
    f32 unk1C;
    char pad20[0x40 - 0x20];
} Entry;
typedef struct {
    char pad0[0x1A];
    s16 unk1A;
} Vars;
typedef struct {
    char pad0[0x68];
    Vars *vars;
} Moby;
typedef struct {
    s32 unk0;
    s32 offset;
} Info;
typedef struct {
    u8 pad0[24];
    s32 x18;
    u8 pad1[20];
} S_27F600;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    u8 f10[16];
} Src_0034C508;
typedef struct {
    u8 pad0[24];
    Src_0034C508 *src;
    u8 pad1C[20];
} Ent_0034C508;
typedef struct {
    u8 pad0[124];
    s32 f124;
    u8 pad128[8];
    s32 f136;
    u8 pad140[20];
} Sub_0034CC80;
typedef struct {
    u8 pad0[48];
    Sub_0034CC80 sub;
} Entry_0034CC80;
typedef int s128 __attribute__((mode(TI)));



/* declared by earlier blocks of L01_00348620.c, which this file was cut from */
extern s32 func_0038CB00(void *);
extern void func_0038CE20(f32 *, f32 *, f32);

/* localdecomp:start func_L01_0034D2F0 */
#include "vu0.h"
extern Entry_0034CC80 D_L01_0027FB20[];
void func_L01_0034D2F0(u8 *owner) {
    extern u8 *func_00382348(void *);
    extern void func_003C5180(void *, f32 *, s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern s32 func_0038CAD0(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_0034E080(void *, s32, s32);
    vu0_v4 delta;
    vu0_q damage[3];
    vu0_v4 first, second, temporary;
    s32 i;
    for (i = 0; i < 48; i++) {
        u8 *p = (u8 *)&D_L01_0027FB20[i];
        u8 *info;
        if (*(u8 **)(p + 0xAC) != owner) continue;
        *(vu0_q *)(p + 0x20) = *(vu0_q *)(p + 0x40);
        if (*(u8 **)(p + 0xB4)) {
            info = func_00382348(*(u8 **)(p + 0xB4));
            if (info) {
                func_003C5180(*(u8 **)(p + 0xB4) + 0x10, (f32 *)&delta, 1);
                func_0038CE20((f32 *)&delta, (f32 *)&delta, *(f32 *)(info + 0x10));
                vec_copy(&temporary, &delta);
                __asm__(
                    "lqc2 $vf2, %3\n\t"
                    "lqc2 $vf1, %4\n\t"
                    "sqc2 $vf2, %1\n\t"
                    "lqc2 $vf2, %5\n\t"
                    "vadd.xyz $vf1, $vf2, $vf1\n\t"
                    "sqc2 $vf1, %0\n\t"
                    "lqc2 $vf1, %0\n\t"
                    "lqc2 $vf2, %1\n\t"
                    "vadd.xyz $vf1, $vf1, $vf2\n\t"
                    "sqc2 $vf1, %2"
                    : "=m"(delta), "=m"(first), "=m"(*(vu0_v4 *)(p + 0x20))
                    : "m"(*(vu0_v4 *)(p + 0x20)), "m"(*(vu0_v4 *)(*(u8 **)(p + 0xB4) + 0x10)), "m"(temporary)
                    : "vf1", "vf2");
            } else {
                *(vu0_q *)(p + 0x20) = *(vu0_q *)(*(u8 **)(p + 0xB4) + 0x10);
            }
        }
        if (*(s32 *)(p + 0xB8)) {
            *(f32 *)(p + 0x60) = func_0038DAB8(*(f32 *)(p + 0x60), *(f32 *)(p + 0x6C) * 100.0f);
            *(f32 *)(p + 0x64) = func_0038DAB8(*(f32 *)(p + 0x64), *(f32 *)(p + 0x70) * 100.0f);
            *(f32 *)(p + 0x68) = func_0038DAB8(*(f32 *)(p + 0x68), *(f32 *)(p + 0x74) * 100.0f);
            *(f32 *)(p + 0x84) = func_0038DAB8(*(f32 *)(p + 0x84), *(f32 *)(p + 0x90) * 100.0f);
            *(f32 *)(p + 0x88) = func_0038DAB8(*(f32 *)(p + 0x88), *(f32 *)(p + 0x94) * 100.0f);
            *(f32 *)(p + 0x8C) = func_0038DAB8(*(f32 *)(p + 0x8C), *(f32 *)(p + 0x98) * 100.0f);
        } else {
            *(f32 *)(p + 0x60) = func_0038DAB8(*(f32 *)(p + 0x60), *(f32 *)(p + 0x6C));
            *(f32 *)(p + 0x64) = func_0038DAB8(*(f32 *)(p + 0x64), *(f32 *)(p + 0x70));
            *(f32 *)(p + 0x68) = func_0038DAB8(*(f32 *)(p + 0x68), *(f32 *)(p + 0x74));
            *(f32 *)(p + 0x84) = func_0038DAB8(*(f32 *)(p + 0x84), *(f32 *)(p + 0x90));
            *(f32 *)(p + 0x88) = func_0038DAB8(*(f32 *)(p + 0x88), *(f32 *)(p + 0x94));
            *(f32 *)(p + 0x8C) = func_0038DAB8(*(f32 *)(p + 0x8C), *(f32 *)(p + 0x98));
        }
        *(f32 *)(p + 0) = func_0038D098(*(f32 *)(p + 0x60)) * *(f32 *)(p + 0x78);
        *(f32 *)(p + 4) = func_0038D0B0(*(f32 *)(p + 0x64)) * *(f32 *)(p + 0x7C);
        *(f32 *)(p + 8) = -func_0038D0B0(*(f32 *)(p + 0x68)) * *(f32 *)(p + 0x80);
        *(f32 *)(p + 0x10) = func_0038D098(*(f32 *)(p + 0x84)) * *(f32 *)(p + 0x9C);
        *(f32 *)(p + 0x14) = func_0038D0B0(*(f32 *)(p + 0x88)) * *(f32 *)(p + 0xA0);
        *(f32 *)(p + 0x18) = -func_0038D0B0(*(f32 *)(p + 0x8C)) * *(f32 *)(p + 0xA4);
        *(vu0_q *)(p + 0x30) = *(vu0_q *)(p + 0x50);
        if (*(u8 **)(p + 0xB0)) {
            info = func_00382348(*(u8 **)(p + 0xB0));
            if (info) {
                func_003C5180(*(u8 **)(p + 0xB0) + 0x10, (f32 *)&delta, 1);
                func_0038CE20((f32 *)&delta, (f32 *)&delta, *(f32 *)(info + 0x10));
                vec_copy(&temporary, &delta);
                __asm__(
                    "lqc2 $vf2, %3\n\t"
                    "lqc2 $vf1, %4\n\t"
                    "sqc2 $vf2, %1\n\t"
                    "lqc2 $vf2, %5\n\t"
                    "vadd.xyz $vf1, $vf2, $vf1\n\t"
                    "sqc2 $vf1, %0\n\t"
                    "lqc2 $vf1, %0\n\t"
                    "lqc2 $vf2, %1\n\t"
                    "vadd.xyz $vf1, $vf1, $vf2\n\t"
                    "sqc2 $vf1, %2"
                    : "=m"(delta), "=m"(second), "=m"(*(vu0_v4 *)(p + 0x30))
                    : "m"(*(vu0_v4 *)(p + 0x30)), "m"(*(vu0_v4 *)(*(u8 **)(p + 0xB0) + 0x10)), "m"(temporary)
                    : "vf1", "vf2");
            } else {
                *(vu0_q *)(p + 0x30) = *(vu0_q *)(*(u8 **)(p + 0xB0) + 0x10);
            }
        }
        func_0038CDF8(p + 0x30, p + 0x20, p + 0x30, 1.0f - (f32)*(s32 *)(p + 0xB8) / (f32)*(s32 *)(p + 0xBC));
        if (func_0038CAD0(p + 0xB8)) {
            if (*(s32 *)(*(u8 **)(p + 0xB0) + 0x98) && !*(s32 *)(p + 0xC0) && *(s32 *)(p + 0xC4)) {
                vec_sub_ab(&delta, p + 0x30, p + 0x20);
                func_0038CF68(&delta, &delta, 0.0400000028f);
                {
                    f32 dmg = *(f32 *)(p + 0xC8);
                    *(s32 *)(owner + 0xB8) = *(s32 *)(*(u8 **)(p + 0xCC) + 0x20);
                    func_L01_00446760(damage, owner, 0x410000, &delta, dmg);
                }
                ((u8 *)damage)[0x18] = 5;
                ((u8 *)damage)[0x19] = 3;
                *(u16 *)((u8 *)damage + 0x1A) = *(u16 *)(owner + 0xAA);
                func_L01_00446978(*(u8 **)(p + 0xB0), damage);
                *(s32 *)(p + 0xC0) = 1;
                func_L01_0034E080(p + 0x30, 10, 1);
            }
            if (func_0038CAD0(p + 0xA8)) *(s32 *)(p + 0xAC) = 0;
        }
    }
}
/* localdecomp:end func_L01_0034D2F0 */

/* localdecomp:start func_L01_0034D700 */


extern Entry_0034CC80 D_L01_0027FB20[];
extern void func_L01_0034D9E0(s32, Entry_0034CC80 *);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L01_0034D700(s32 arg0) {
    s32 i;
    Entry_0034CC80 *e;
    Sub_0034CC80 *s;

    for (i = 47; i >= 0; i--) {
        e = &D_L01_0027FB20[47 - i];
        s = &e->sub;
        if (s->f124 == arg0) {
            func_L01_0034D9E0(arg0, e);
            if (s->f136 == 0) {
                func_003D9508(s, 49, (func_00382498(80, 96) << 24) | 0x103080, 1, 0.5f, 0.1f, func_00382538());
                func_003D9508(s, 49, (func_00382498(80, 96) << 24) | 0xFFFFFF, 1, 0.5f, 0.1f, func_00382538());
            }
        }
    }
}
/* localdecomp:end func_L01_0034D700 */

/* localdecomp:start func_L01_0034D840 */
void func_L01_0034D840(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0034D840 */

/* localdecomp:start func_L01_0034D8C8 */
typedef int Quad_0034D8C8 __attribute__((mode(TI)));
void func_L01_0034D8C8(f32 *dst, f32 *a, f32 *b, f32 *c, f32 *d, f32 t)
{
    f32 t2, t3, p, q, r, s;
    if (t == 0.0f) {
        *(Quad_0034D8C8 *)dst = *(Quad_0034D8C8 *)a;
        return;
    }
    if (t == 1.0f) {
        *(Quad_0034D8C8 *)dst = *(Quad_0034D8C8 *)b;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    p = (d[0] - b[0]) - (c[0] - a[0]);
    q = (c[0] - a[0]) - p;
    r = b[0] - c[0];
    s = a[0];
    dst[0] = p * t3 + q * t2 + r * t + s;
    p = (d[1] - b[1]) - (c[1] - a[1]);
    q = (c[1] - a[1]) - p;
    r = b[1] - c[1];
    s = a[1];
    dst[1] = p * t3 + q * t2 + r * t + s;
    p = (d[2] - b[2]) - (c[2] - a[2]);
    q = (c[2] - a[2]) - p;
    r = b[2] - c[2];
    s = a[2];
    dst[2] = p * t3 + q * t2 + r * t + s;
    dst[3] = 0.0f;
}
/* localdecomp:end func_L01_0034D8C8 */

/* localdecomp:start func_L01_0034D9E0 */
typedef struct {
    f32 pos[4], second[4], origin[4], attached[4];
    f32 angle[3], velocity[3], scale[3];
    f32 angle2[3], velocity2[3], scale2[3];
    s32 timer, kind;
    u8 *owner;
    s32 remaining, duration, finished;
} Effect_0034D9E0;
#include "vu0.h"
void func_L01_0034D9E0(s32 owner_, Entry_0034CC80 *in_) {
    u8 *owner = (u8 *)owner_;
    void *in = in_;
    extern void func_L01_0034D8C8_0034D9E0(void *, void *, void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_0034DBE8_0034D9E0(void *, s32, void *, s32);
    Effect_0034D9E0 *input = (Effect_0034D9E0 *)in;
    vu0_q points[25];
    vu0_v4 a, b, random;
    vu0_q *out = points;
    s32 i;
    for (i = 0; i < 24; i++, out++) {
        /* both ends go into VU0 registers first; the "j" class has only vf1 and vf2, so the second
           is spilled to the stack around the first sum (retail's sqc2/lqc2 at sp+0x1C0) */
        vu0_q qo, qe, qa, qb;
        __asm__("lqc2 %0, %1" : "=j"(qo) : "m"(*(vu0_v4 *)input->origin));
        __asm__("lqc2 %0, %1" : "=j"(qe) : "m"(*(vu0_v4 *)input->attached));
        *(vu0_q *)&a = *(vu0_q *)input->pos;
        *(vu0_q *)&b = *(vu0_q *)input->second;
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)&a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qo));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&a) : "j"(qa));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)&b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qe));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&b) : "j"(qb));
        func_L01_0034D8C8_0034D9E0(out, input->origin, input->attached, &a, &b, (f32)i / 23.0f);
        random.w = 0.0f;
        random.x = func_003824E0(-1.0f, 1.0f);
        random.y = func_003824E0(-1.0f, 1.0f);
        random.z = func_003824E0(-1.0f, 1.0f);
        func_0038CF68(&random, &random, 0.075f);
        vec_add_ab(out, out, &random);
    }
    if (*(s32 *)((u8 *)input + 0xA8) >= 8) func_L01_0034DBE8_0034D9E0(owner, func_00382498(64, 128), points, 25);
    else func_L01_0034DBE8_0034D9E0(owner, func_00382498(0, 64), points, 25);
}
/* localdecomp:end func_L01_0034D9E0 */

/* localdecomp:start func_L01_0034DBA8 */
#include "vu0.h"
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_0034DBA8;
void func_L01_0034DBA8(Vec_0034DBA8 *p, s32 n)
{
    Vec_0034DBA8 delta;
    vec_sub_ab(&delta, &p[n - 2], &p[n - 3]);
    vec_add_ab(&p[n - 1], &p[n - 2], &delta);
}
/* localdecomp:end func_L01_0034DBA8 */

/* localdecomp:start func_L01_0034DBE8 */
extern u8 D_L01_001E29C0[];
extern struct Hero D_001A4BE0;
#include "vu0.h"
void func_L01_0034DBE8(s32 unused, s32 colour, f32 (*pts)[4], s32 count) {
    extern long func_00389598(s32);
    extern void func_L01_0034DBA8(Vec_0034DBA8 *, s32);
    extern void func_L01_0034D840(u8 *);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D028(void *, void *, void *);
    f32 a[36] __attribute__((aligned(16)));
    f32 b[36] __attribute__((aligned(16)));
    f32 axis[4] __attribute__((aligned(16)));
    f32 eye[4] __attribute__((aligned(16)));
    f32 side[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 inner[4] __attribute__((aligned(16)));
    f32 outer[4] __attribute__((aligned(16)));
    s32 edgeColour = 0x80FF0000;
    s32 i;
    unsigned long texture;
    f32 u, v;
    f32 k;
    if (*(s32 *)((u8 *)&D_001A4BE0 + 0x1228) == 47) edgeColour = 0x800000FF; /* hero.held_item */
    texture = func_00389598(43);
    *(unsigned long *)(a + 32) = 0x0000FF9000000260UL;
    *(unsigned long *)(a + 34) = ((unsigned long)(u32)colour << 32) | 104;
    *(s32 *)(a + 17) = 0x7FFFFFFF;
    *(s32 *)(a + 16) = 0x7FFFFFFF;
    *(unsigned long *)(a + 30) = texture;
    *(unsigned long *)(a + 28) = 0;
    texture = func_00389598(43);
    *(unsigned long *)(b + 28) = 0;
    *(unsigned long *)(b + 32) = 0x0000FF9000000260UL;
    *(unsigned long *)(b + 34) = ((unsigned long)(u32)(colour / 3) << 32) | 104;
    *(unsigned long *)(b + 30) = texture;
    *(vu0_q *)inner = 0;
    *(vu0_q *)outer = 0;
    inner[2] = 0.05f;
    outer[2] = 0.2f;
    *(s32 *)(a + 17) = edgeColour;
    *(s32 *)(b + 16) = edgeColour;
    inner[3] = 1.0f; outer[3] = 1.0f;
    func_L01_0034DBA8((Vec_0034DBA8 *)pts, count);
    func_L01_0034D840((u8 *)a);
    func_L01_0034D840((u8 *)b);
    a[20]=0.0f; a[21]=0.0f; a[22]=0.0f; a[23]=1.0f;
    a[24]=1.0f; a[25]=0.0f; a[26]=1.0f; a[27]=1.0f;
    b[20]=0.0f; b[21]=0.0f; b[22]=0.0f; b[23]=1.0f;
    b[24]=0.33f; b[25]=0.0f; b[26]=0.33f; b[27]=1.0f;
    vec_sub_ba(axis, pts[1], pts[0]);
    func_0038CF68(axis, axis, 1.0f);
    vec_sub_ab(eye, (f32 *)D_L01_001E29C0, pts[0]);
    func_0038CE90(side, eye, axis);
    func_0038CF68(side, side, 1.0f);
    func_0038CE90(eye, axis, side);
    *(vu0_q *)pos = *(vu0_q *)pts[0];
    *(vu0_q *)a = *(vu0_q *)inner;
    func_0038CE20(a + 4, a, -1.0f);
    func_0038D028(a, a, axis);
    func_0038D028(a + 4, a + 4, axis);
    *(vu0_q *)b = *(vu0_q *)outer;
    func_0038CE20(b + 4, b, -1.0f);
    func_0038D028(b, b, axis);
    func_0038D028(b + 4, b + 4, axis);
    for (i = 1; i < count - 1; i++) {
        *(vu0_q *)(a + 8) = *(vu0_q *)inner;
        func_0038CE20(a + 12, a + 8, -1.0f);
        *(vu0_q *)(b + 8) = *(vu0_q *)outer;
        func_0038CE20(b + 12, b + 8, -1.0f);
        vec_sub_ab(axis, pts[i + 1], pts[i]);
        func_0038CF68(axis, axis, 1.0f);
        vec_sub_ab(eye, (f32 *)D_L01_001E29C0, pts[i]);
        func_0038CE90(side, eye, axis);
        func_0038CF68(side, side, 1.0f);
        func_0038CE90(eye, axis, side);
        *(vu0_q *)pos = *(vu0_q *)pts[i];
        func_0038D028(a + 8, a + 8, axis);
        func_0038D028(a + 12, a + 12, axis);
        func_0038D028(b + 8, b + 8, axis);
        k = 0.33f;
        func_0038D028(b + 12, b + 12, axis);
        *(s32 *)(a + 19) = 0x7F7F7F7F;
        *(s32 *)(a + 18) = 0x7F7F7F7F;
        *(s32 *)(b + 19) = edgeColour;
        *(s32 *)(b + 18) = edgeColour;
        func_003D2DA0(a, 0, 0);
        func_003D2DA0(b, 0, 0);
        u = i * k;
        v = u + k;
        if (u >= 1.0f) { u -= 1.0f; v -= 1.0f; }
        b[20] = u; b[24] = v; b[22] = u; b[26] = v;
        *(vu0_q *)a = *(vu0_q *)(a + 8);
        *(vu0_q *)(a + 4) = *(vu0_q *)(a + 12);
        *(vu0_q *)b = *(vu0_q *)(b + 8);
        *(vu0_q *)(b + 4) = *(vu0_q *)(b + 12);
    }
}
/* localdecomp:end func_L01_0034DBE8 */

INCLUDE_ASM("asm/levels", func_L01_0034E080);

/* localdecomp:start func_L01_0034E558 */
#include "vu0.h"
#include "structs/hero.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_0034E558;
extern struct Hero D_001A4BE0;
extern f32 D_001A4C70[];
extern s32 D_L01_001DD44C;
extern s32 D_L01_001DD3F8;
extern s32 D_L01_001DD3FC;
extern u8 D_L01_00283BA0[][160];
extern u8 D_L01_00283E20[][320];
extern V_0034E558 D_L01_001EAA20;
__asm__(".extern D_L01_001DD44C, 4");
__asm__(".extern D_L01_001DD3F8, 4");
__asm__(".extern D_L01_001DD3FC, 4");
u8 *func_L01_0034E558(u8 *owner,s32 unused,s128 *direction,u8 *parent,s32 joint)
{
    extern u8 *func_003C24B0(s32,s32);
    extern void func_0038D308(void *,void *);
    extern void func_003C2F58(void *,s32,void *);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern s32 func_003D3CB0(void *,void *,s32,void *,s32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_L01_0034E9E0(char *);
    V_0034E558 saved;
    V_0034E558 *savedp=&saved;
    s32 slot;
    V_0034E558 v;
    u8 *m,*p;
    *(s128 *)savedp=*direction;
    m=func_003C24B0(4501,128);
    if(m) {
        m[0x20]=1;
        m[0x30]=255;
        p=(u8 *)((Moby *)m)->vars;
        *(s16 *)(p+0x1E)=(D_L01_001DD44C*5+2)/6;
        *(s32 *)(p+0x18)=-1;
        func_0038D308(m+0xC0,D_001A4C70);
        slot=D_L01_001DD3F8;
        { u8 *a=D_L01_00283BA0[slot];
          u8 *b=D_L01_00283E20[slot];
          *(u8 **)(p+0)=a;
          *(u8 **)(p+4)=b; }
        if((u32)slot>=4)D_L01_001DD3F8=0;
        D_L01_001DD3F8=(D_L01_001DD3F8+1)%4;
        *(u8 **)(p+0x20)=owner;
        if(parent) {
            if(*(s16 *)(parent+0xAA)==6251) *(s32 *)(p+0x24)=0x800530;
            else *(s32 *)(p+0x24)=D_L01_001DD3FC;
        } else *(s32 *)(p+0x24)=D_L01_001DD3FC;
        *(s128 *)(p+0x30)=*(s128 *)savedp;
        if(parent && (*(s16 *)(parent+0xAA)==6222 || *(s16 *)(parent+0xAA)==6253)) {
            *(u8 **)(p+0x40)=parent;
            *(s32 *)(p+0x44)=joint;
            func_003C2F58(parent,joint,m+16);
        } else if(parent && *(s16 *)(parent+0xAA)==6251) {
            *(u8 **)(p+0x40)=parent;
            *(s128 *)(m+16)=*(s128 *)(parent+16);
        } else {
            func_0038CE20((f32 *)&v,(f32 *)((u8 *)D_001A4BE0.hero_moby+0xE0),0.75f);
            vec_add_ab((V_0034E558 *)(m+16), &(D_001A4BE0.pos), &v);
        }
        if(*(f32 *)(p+0x30)==0 && *(f32 *)(p+0x34)==0 && *(f32 *)(p+0x38)==0)
            *(s128 *)(p+0x30)=*(s128 *)(*(u8 **)(p+0x20)+16);
        if(func_003D3CB0(m+16,p+0x30,16,D_001A4BE0.hero_moby,0)) {
            vec_sub_ab(&v, (V_0034E558 *)(m+16), &D_L01_001EAA20);
            func_0038CF68(&v,&v,0.2f);
            vec_add_ab((V_0034E558 *)(p+0x30), &D_L01_001EAA20, &v);
        }
        func_L01_0034E9E0((char *)m);
    }
    return m;
}
/* localdecomp:end func_L01_0034E558 */

/* localdecomp:start func_L01_0034E808 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; s128 pos; u8 state; u8 pad21[0xAA-0x21]; s16 cls; u8 padAC[0xE0-0xAC]; f32 axis[4]; } Obj_0034E808;
typedef struct { u8 pad0[0x18]; s32 slot; u8 pad1C[2]; s16 timer; Obj_0034E808 *owner; u8 pad24[12]; s128 pos; Obj_0034E808 *target; s32 joint; } State_0034E808;
typedef struct { u8 pad[0x80]; s128 pos; u8 pad90[0x25C0-0x90]; Obj_0034E808 *obj; } Hero_0034E808;
static __inline__ s32 cls_0034E808(Obj_0034E808 *t) { s32 value=t->cls; return value; }
extern Hero_0034E808 D_001A4BE0_0034E808;
extern u8 D_001A30B0[];
void func_L01_0034E808(char *obj) {
    extern void func_003C2880(char *);
    extern void func_003C2F58(Obj_0034E808 *,s32,s128 *);
    extern void *func_00382348(Obj_0034E808 *);
    extern void func_L01_0034F7E8_0034E808(char *);
    extern void func_L01_0034EAA0(char *);
    extern void func_003A4F28(s32);
    vu0_v4 temp;
    State_0034E808 *s=*(State_0034E808 **)(obj+0x68);
    Obj_0034E808 *t;
    if(func_0038CB00(&s->timer)) {
        func_003C2880(obj);
        return;
    }
    t=s->target;
    if(!t) goto fallback;
    { s32 cls=t->cls; s32 state;
    if(cls==0xDC1) goto fallback;
    state=t->state;
    if(state==0xFE) goto joint;
    if(state==0xFD) goto joint;
    if(cls==0x186B) {
        *(s128 *)(obj+0x10)=t->pos;
        goto positioned;
    }
    }
joint:
    t=s->target;
    if(!t) goto fallback;
    if(t->state==0xFE) goto fallback;
    if(t->state==0xFD) goto fallback;
    if(cls_0034E808(t)==0x184E || cls_0034E808(t)==0x186D) {
        func_003C2F58(t,s->joint,(s128 *)(obj+0x10));
        goto positioned;
    }
fallback:
    func_0038CE20((f32 *)&temp,D_001A4BE0_0034E808.obj->axis,0.75f);
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(s128 *)(obj+0x10)) : "m"(D_001A4BE0_0034E808.pos),"m"(temp) : "vf1","vf2");
positioned:
    if(s->owner) {
        if(s->owner->state==0xFE) goto clear_owner;
        if(s->owner->state==0xFD) {
clear_owner:
            s->owner=0;
        }
        if(s->owner) {
            void *info;
            s->pos=s->owner->pos;
            info=func_00382348(s->owner);
            if(info) {
                func_0038CE20((f32 *)&temp,s->owner->axis,*(f32 *)((u8 *)info+0x10));
                __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(s->pos) : "m"(s->pos),"m"(temp) : "vf1","vf2");
            }
        }
    }
    if((u8)obj[0x20]==1) {
        func_L01_0034F7E8_0034E808(obj);
        func_L01_0034EAA0(obj);
    } else if(s->slot>=0) {
        if(s->slot!=-1) {
            u8 *row=D_001A30B0+(s->slot<<7);
            if(*(char **)(row+0xDC)==obj && row[0xD0]) func_003A4F28(s->slot);
        }
        s->slot=-1;
    }
}
/* localdecomp:end func_L01_0034E808 */

/* localdecomp:start func_L01_0034E9E0 */
void func_L01_0034E9E0(char *object)
{
    char *state = *(char **)(object + 0x68);
    int i;

    for (i = 0; i < 10; i++) {
        *(int *)(*(char **)(state + 0) + i * 16 + 0) = 0;
        *(int *)(*(char **)(state + 0) + i * 16 + 4) = 0;
        *(int *)(*(char **)(state + 0) + i * 16 + 8) = 0;
        *(float *)(*(char **)(state + 0) + i * 16 + 12) = 1.0f;
    }

    for (i = 0; i < 20; i++) {
        *(int *)(*(char **)(state + 4) + i * 16 + 0) = 0;
        *(int *)(*(char **)(state + 4) + i * 16 + 4) = 0;
        *(int *)(*(char **)(state + 4) + i * 16 + 8) = 0;
        *(float *)(*(char **)(state + 4) + i * 16 + 12) = 1.0f;
    }

    *(int *)(state + 0xC) = 0;
    *(short *)(state + 0x1C) = 5;
    *(int *)(state + 0x10) = 0;
    *(int *)(state + 0x14) = 0;
    *(int *)(state + 0x8) = 0;
}
/* localdecomp:end func_L01_0034E9E0 */

INCLUDE_ASM("asm/levels", func_L01_0034EAA0);

/* localdecomp:start func_L01_0034F0B0 */
__asm__(".extern D_L01_001DD438, 4");
__asm__(".extern D_L01_001DD43C, 4");
__asm__(".extern D_L01_001DD440, 4");
__asm__(".extern D_L01_001DD444, 4");
__asm__(".extern D_L01_001DD448, 4");
extern s32 D_L01_001DD438;
extern s32 D_L01_001DD43C;
extern s32 D_L01_001DD440;
extern s32 D_L01_001DD444;
extern f32 D_L01_001DD448;
extern void func_003A9440(s32, unsigned long);
extern void func_L01_0034F168(u8 *bolt, s32 line, s32 core_alpha, s32 glow_alpha, s32 points);

/* lightning_bolt_draw: scrolls the ribbons' u, then draws each of the bolt's two lines as
   two added ribbons, a core and a glow in the bolt's colour. */
void func_L01_0034F0B0(u8 *bolt)
{
    u8 *vars = *(u8 **)(bolt + 0x68);
    f32 u;

    /* u scrolls 0.2 a frame (D_L01_001DD448), x 1.2 for PAL's 50 Hz, wrapping by 8 */
    u = *(f32 *)(vars + 0x14) - D_L01_001DD448 * 1.2f;
    *(f32 *)(vars + 0x14) = u;
    if (u <= -8.0f) {
        *(f32 *)(vars + 0x14) = u + 8.0f;
    }
    func_003A9440(0x47, 0x51001);
    /* the core at alpha 0x80, the glow at 0x40; the first line of 10 points, the second of 20 */
    func_L01_0034F168(bolt, *(s32 *)vars, D_L01_001DD438, D_L01_001DD440, 10);
    func_L01_0034F168(bolt, *(s32 *)(vars + 4), D_L01_001DD43C, D_L01_001DD444, 20);
}
/* localdecomp:end func_L01_0034F0B0 */

INCLUDE_ASM("asm/levels", func_L01_0034F168);

/* localdecomp:start func_L01_0034F7E8 */
void func_L01_0034F7E8(void) {

}
/* localdecomp:end func_L01_0034F7E8 */

/* localdecomp:start func_L01_0034F7F0 */
extern s32 D_L01_001E2EC4[];
extern f32 D_L01_001E2EC8[];
extern s32 D_L01_001E1A0C;
extern s32 D_001D545C;
extern s128 D_L01_002B2AB0[];
extern void func_L01_0034FA00(u8 *);
extern f32 func_L01_0034F908(u8 *);
extern void func_L01_0034FC28();
extern void func_L01_00404808(void (*)(void), u8 *);
void func_L01_0034F7F0(u8 *m) {
    s128 *v = *(s128 **)(m + 104);
    s32 t;
    s32 i;
    switch (m[32]) {
    case 0:
        m[48] = 255;
        m[32] = 1;
        D_L01_001E2EC4[0] = 0;
        t = D_001D545C;
        i = 0;
        if (t == 1) {
            D_L01_001E1A0C = 100;
        } else if (t == 2) {
            D_L01_001E1A0C = 101;
            i = 1;
        } else if (t == 5) {
            D_L01_001E1A0C = 105;
            i = 2;
        } else if (t == 16) {
            D_L01_001E1A0C = 100;
            i = 3;
        } else if (t == 26) {
            D_L01_001E1A0C = 100;
            i = 5;
        }
        *v = D_L01_002B2AB0[i];
        func_L01_0034FA00(m);
        break;
    case 1:
        D_L01_001E2EC8[0] = func_L01_0034F908(m);
        func_L01_00404808(func_L01_0034FC28, m);
        break;
    }
}
/* localdecomp:end func_L01_0034F7F0 */

/* localdecomp:start func_L01_0034F908 */
#include "vu0.h"
/* VU0 j-form: needs -mvu0-use-vf0-vf2 on this file (config/levels/text_parts.txt). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_0034F908;
extern u8 D_L01_001E29C0[];
extern s32 D_001D4BC0;
extern s32 D_001D4BC0_0034F908[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1A08, 4");
extern f32 D_L01_001E1A08;
f32 func_L01_0034F908(u8 *m)
{
    extern f32 func_0038CE68(void *, void *);
    extern void func_L01_0044FBC8(void *, s32 *, s32 *);
    extern s32 func_L01_00407808(s32, u16, u16, s32, s32, s32, f32 *);
    Vec_0034F908 v;
    s32 x, y;
    s32 t;
    u8 *p = *(u8 **)(m + 0x68);
    f32 d;
    {
        vu0_q a, b, r;
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(Vec_0034F908 *)D_L01_001E29C0));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(Vec_0034F908 *)p));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(r));
    }

    d = func_0038CE68(&v, D_L01_001E29C0 + 0x20);
    func_L01_0044FBC8(p, &x, &y);
    t = x;
    if (t < 0 || t >= D_001D4BC0 - 16) goto invalid;
    t = y;
    if (t < 0 || t >= D_001D4BC0_0034F908[1] - 8 || !(d > 0.0f)) goto invalid;
    if (func_L01_00407808(-1, x, y, 16, 8, 0, &D_L01_001E1A08) == -1) {
invalid:
        D_L01_001E1A08 = -1.0f;
    }
    return D_L01_001E1A08;
}
/* localdecomp:end func_L01_0034F908 */

/* localdecomp:start func_L01_0034FA00 */
#include "vu0.h"
typedef struct {
    u8 *owner;          /* 0x00: the moby that set the flare up */
    s32 initialized;    /* 0x04 */
    f32 value8;         /* 0x08: overall brightness */
    s32 valueC;
    s16 alpha[16];      /* 0x10 */
    s16 interval[16];   /* 0x30: texture index offset */
    s32 color[16];      /* 0x50 */
    f32 phase[16];      /* 0x90: place along the line through the screen centre */
    f32 size[16];       /* 0xD0 */
} State_0034FA00;
extern State_0034FA00 D_L01_001E2EC0;
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);

void func_L01_0034FA00(u8 *obj) {
    s32 i;
    s32 v;
    s32 r, g;
    f32 t;
    if (D_L01_001E2EC0.initialized == 1) return;
    D_L01_001E2EC0.owner = obj;
    D_L01_001E2EC0.initialized = 1;
    for (i = 1; i < 14; i++) {
        v = func_00382468(63) + 1;
        switch (func_00382468(6)) {
        case 0: D_L01_001E2EC0.color[i] = 0x202080 - (v << 16) + v; break;
        case 1: D_L01_001E2EC0.color[i] = 0x202080 + (v << 8) + v; break;
        case 2: D_L01_001E2EC0.color[i] = 0x202080 + (func_00382468(v) << 8) + v; break;
        case 3:
            r = func_00382468(v);
            g = func_00382468(v);
            D_L01_001E2EC0.color[i] = 0x202080 + (r << 16) + (g << 8) + v;
            break;
        default: D_L01_001E2EC0.color[i] = 0x202080; break;
        }
        D_L01_001E2EC0.interval[i] = func_00382468(30) / 10 + 1;
        D_L01_001E2EC0.phase[i] = func_003824E0(-0.95f, 2.4f);
        t = fabs_asm(func_0038D098(func_0038DB48(D_L01_001E2EC0.phase[i] + 1.0f)));
        D_L01_001E2EC0.size[i] = t * t * t * 1.4f;
        D_L01_001E2EC0.alpha[i] = 32;
    }
    D_L01_001E2EC0.phase[0] = -1.0f;
    D_L01_001E2EC0.size[0] = 2.0f;
    D_L01_001E2EC0.color[0] = 0x808080;
    D_L01_001E2EC0.interval[0] = 0;
    D_L01_001E2EC0.alpha[0] = 127;
}
/* localdecomp:end func_L01_0034FA00 */

/* localdecomp:start func_L01_0034FC28 */
#include "vu0.h"
/* the same object as func_L01_0034FA00's D_L01_001E2EC0 */
typedef struct {
    u8 *owner;
    s32 initialized;
    f32 value8;
    s32 valueC;
    s16 alpha[16];
    s16 interval[16];
    s32 color[16];
    f32 phase[16];
    f32 size[16];
} State_0034FC28;
extern State_0034FC28 D_L01_001E2EC0_0034FC28;
extern s32 D_L01_001E1A0C;
extern u8 D_L01_001E29C0[];
extern s32 D_001D4BC8;
extern s32 D_001D4BCC;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
__asm__(".extern D_001D4BC8, 16");
__asm__(".extern D_001D4BCC, 16");
__asm__(".extern D_001D4BD0, 16");
__asm__(".extern D_001D4BD4, 16");
extern f32 func_0038CF00(void *, void *);
extern void func_003860A8(f32 *, void *);
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);

void func_L01_0034FC28(u8 *m) {
    u8 *vars = *(u8 **)(m + 0x68);
    f32 pos[4];
    f32 scr[4];
    f32 d[4];
    f32 o[4];
    f32 q[4];
    f32 vis;
    f32 a, b, e;
    s32 n;
    s32 i;
    s32 sz;
    s32 rgba;
    long tex;

    if (D_L01_001E2EC0_0034FC28.initialized != 1) {
        D_L01_001E2EC0_0034FC28.initialized = 0;
        return;
    }
    if (D_L01_001E2EC0_0034FC28.owner[0x20] & 0x80) {
        D_L01_001E2EC0_0034FC28.initialized = 0;
        return;
    }
    if (D_L01_001E2EC0_0034FC28.value8 <= 0.0f) return;
    vis = func_0038CF00(D_L01_001E29C0, vars);
    scr[0] = D_001D4BC8;
    scr[1] = D_001D4BCC;
    i = 0;
    n = 64;
    func_003860A8(pos, vars);
    pos[0] = (pos[0] - D_001D4BD0) * 0.0625f;
    pos[1] = (pos[1] - D_001D4BD4) * 0.0625f;
    d[0] = scr[0] - pos[0];
    d[1] = scr[1] - pos[1];
    for (; i < 14; i++) {
        tex = func_00389598(D_L01_001E1A0C + D_L01_001E2EC0_0034FC28.interval[i]);
        o[0] = d[0] * D_L01_001E2EC0_0034FC28.phase[i];
        o[1] = d[1] * D_L01_001E2EC0_0034FC28.phase[i];
        q[0] = scr[0] + o[0];
        q[1] = scr[1] + o[1];
        a = vis - 5.0f;
        if (a > 1.0f) a = 1.0f;
        else if (a < 0.0f) a = 0.0f;
        b = fabs_asm(d[0]) / scr[0] * -5.0f + 5.5f;
        if (b > 1.0f) b = 1.0f;
        else if (b < 0.0f) b = 0.0f;
        e = fabs_asm(d[1]) / scr[1] * -5.0f + 5.5f;
        if (e > 1.0f) e = 1.0f;
        else if (e < 0.0f) e = 0.0f;
        a = a * (b * e * D_L01_001E2EC0_0034FC28.value8);
        rgba = ((s32)(a * D_L01_001E2EC0_0034FC28.alpha[i]) << 24)
             | (D_L01_001E2EC0_0034FC28.color[i] & 0xFFFFFF);
        sz = (f32)n * D_L01_001E2EC0_0034FC28.size[i];
        func_003A9440(0x42, 0x8000000048);
        func_0038B4D0(q[0] - (sz >> 1), q[1] - (sz >> 1), sz, sz, 0, 0, 64, 64, rgba, tex);
    }
    D_L01_001E2EC0_0034FC28.value8 = 0.0f;
}
/* localdecomp:end func_L01_0034FC28 */

/* localdecomp:start func_L01_0034FFE8 */
extern void func_003C2880(char *object);

/* from rac2-decomp's func_L00_0040DF00, renamed */
void func_L01_0034FFE8(char *object)
{
    char *handle = *(char **)(object + 104);
    if (func_0038CB00(handle) == 0)
        func_0038CB00(handle + 4);
    else
        func_003C2880(object);
}
/* localdecomp:end func_L01_0034FFE8 */

#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t v0, v1, v2;
    u128_t matrix[3];
} Local_51FC18;

typedef struct __attribute__((packed)) { s32 values[2]; } Pair;

/* declared by functions of L39_0051F740.c, which this file was cut from */
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L39_005203E0(char *);
extern void func_L39_00520630(char *);

INCLUDE_ASM("asm/levels", func_L39_005203E0);

/* localdecomp:start func_L39_00520630 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V_00520630 __attribute__((aligned(16)));
typedef struct {
    V_00520630 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_00520630;
extern s32 D_L39_0024A978;
extern s32 D_L39_0024A97C;
extern s32 D_L39_0024A980;
extern s32 D_L39_0024A984;
extern s32 D_L39_0024A988;
extern s32 D_L39_0024A98C;
extern s32 D_L39_0024A990;
extern f32 D_L39_0024A994;
__asm__(".extern D_L39_0024A978, 4");
__asm__(".extern D_L39_0024A97C, 4");
__asm__(".extern D_L39_0024A980, 4");
__asm__(".extern D_L39_0024A984, 4");
__asm__(".extern D_L39_0024A988, 4");
__asm__(".extern D_L39_0024A98C, 4");
__asm__(".extern D_L39_0024A990, 4");
__asm__(".extern D_L39_0024A994, 4");
extern s16 D_L39_0046FB30[][4][2];
extern V_00520630 D_L39_0046F630[];
extern f32 D_L39_0046FF30[][2];
extern unsigned long func_L39_00589890(int);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);
extern void func_L39_005BC330(void *, void *, s32);

void func_L39_00520630(char *obj)
{
    S_00520630 s;
    V_00520630 mtx[3];
    V_00520630 pos;
    char *data = *(char **)(obj + 0x68);
    s32 i;
    s32 j;
    s32 c;
    s32 k;

    s.x78 = func_L39_00589890(D_L39_0024A98C);
    s.x88 = D_L39_0024A978 | ((long)D_L39_0024A97C << 2) | ((long)D_L39_0024A980 << 4)
          | ((long)D_L39_0024A984 << 6) | ((long)D_L39_0024A988 << 32);
    s.x80 = 0xFF9000000260L;
    s.x70 = 0;
    qzero(&mtx[0]);
    qzero(&mtx[1]);
    qzero(&mtx[2]);
    mtx[0].x = *(f32 *)(data + 0x10);
    mtx[1].y = *(f32 *)(data + 0x10);
    mtx[2].z = *(f32 *)(data + 0x10) * 0.125f;
    c = D_L39_0024A990 + (*(s32 *)(data + 0x24) << 24);
    s.c4C = c;
    s.c48 = c;
    s.c44 = c;
    s.c40 = c;
    func_L39_005BC330(obj + 0x10, &pos, 1);
    func_0038CE20(&pos, &pos, 0.25f);
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 4; j++) {
            k = D_L39_0046FB30[i][j][1];
            func_0038CE20(&s.m[j], &D_L39_0046F630[D_L39_0046FB30[i][j][0]], D_L39_0024A994);
            s.uv[j][0] = D_L39_0046FF30[k][0];
            s.uv[j][1] = D_L39_0046FF30[k][1];
            func_0038D000(&s.m[j], &s.m[j], mtx);
            func_0038D000(&s.m[j], &s.m[j], obj + 0xC0);
            vec_add_ab(&s.m[j], &s.m[j], obj + 0x10);
            vec_add_ab(&s.m[j], &s.m[j], &pos);
        }
        func_003D2DA0(&s, 0, 0);
    }
}
/* localdecomp:end func_L39_00520630 */

INCLUDE_ASM("asm/levels", func_L39_00520870);

INCLUDE_ASM("asm/levels", func_L39_005210A0);

INCLUDE_ASM("asm/levels", func_L39_00521BC0);

/* localdecomp:start func_L39_00521DE8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00521DE8;
typedef struct {
    u8 pad0[0x23A0];
    V4_00521DE8 v23A0;
} T_00521DE8;
typedef struct {
    V4_00521DE8 v0;
    V4_00521DE8 v10;
    u8 pad20[0x38];
    T_00521DE8 *p58;
    u8 pad5C[8];
    s16 s64;
} D_00521DE8;
typedef struct {
    u8 pad0[0x10];
    V4_00521DE8 v10;
    u8 pad20[0x48];
    D_00521DE8 *p68;
    u8 pad6C[0x54];
    V4_00521DE8 mC0;
    V4_00521DE8 vD0;
} O_00521DE8;
typedef struct {
    V4_00521DE8 v[4];
    s32 c[4];
    s32 f50;
    s32 f54;
    s32 f58;
    f32 f5C;
    f32 f60;
    s32 f64;
    f32 f68;
    f32 f6C;
    u8 pad70[0x20];
    V4_00521DE8 v90;
} P_00521DE8;
extern f32 func_L39_005B4410(f32, f32);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L39_00521DE8(void *arg) {
    O_00521DE8 *obj = arg;
    D_00521DE8 *data = obj->p68;
    T_00521DE8 *t = data->p58;
    V4_00521DE8 m[4];
    P_00521DE8 p;
    f32 s1, s2;
    s32 i;
    vu0_q qa, qb;

    s1 = func_L39_005B4410(0.75f, 0.95f);
    s2 = func_L39_005B4410(2.0f, 2.5f);
    m[0] = obj->vD0;
    vec_sub_ba(&m[1], &t->v23A0, &obj->v10);
    func_0038CE90(&m[2], &m[1], &m[0]);
    func_0038CF68(&m[2], &m[2], s1);
    func_0038CF68(&m[0], &m[0], s2);
    m[0].w = 0.0f;
    m[1].w = 0.0f;
    m[2].w = 0.0f;
    func_003D93B0(&p, 0x3F, 1, 0x80);
    p.f50 = 0;
    p.f54 = 0;
    p.f58 = 0;
    p.f5C = 1.0f;
    p.f60 = 1.0f;
    p.f64 = 0;
    p.f68 = 1.0f;
    p.f6C = 1.0f;
    for (i = 0; i < 4; i++) {
        qzero(&p.v[i]);
        if (i < 2) {
            p.v[i].x = 0.0f;
        } else {
            p.v[i].x = 1.0f;
        }
        p.v[i].y = 0.0f;
        if (i & 1) {
            p.v[i].z = 1.0f;
        } else {
            p.v[i].z = -1.0f;
        }
        p.v[i].w = 1.0f;
        p.c[i] = 0x7FFFFFFF;
    }
    *(u128_t *)&p.v90 = 0;
    p.v90.y = -2.0f;
    func_0038D000(&m[3], &p.v90, &obj->mC0);
    if (data->s64 != 0) {
        __asm__ __volatile__("lqc2 $vf2, %0" : : "m"(data->v0));
    } else {
        __asm__ __volatile__("lqc2 $vf2, %0" : : "m"(data->v10));
    }
    __asm__ __volatile__(
        "lqc2 $vf1, %0\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        : : "m"(m[3]) : "memory");
    m[3].w = 1.0f;
    func_003D2DA0(&p, m, 0);
}
/* localdecomp:end func_L39_00521DE8 */

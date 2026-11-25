#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L05_003629B8);

/* localdecomp:start func_L05_00362E38 */
extern char *func_003C24B0(int, int);

void *func_L05_00362E38(char *owner, u128_t *a, u128_t *b, float f)
{
    float va[4] __attribute__((aligned(16)));
    float vb[4] __attribute__((aligned(16)));
    char *obj;
    char *v;

    *(u128_t *)va = *a;
    *(u128_t *)vb = *b;
    obj = func_003C24B0(0x16F1, 0x80);
    if (obj != 0) {
        *(unsigned char *)(obj + 0x30) = 0xFF;
        *(short *)(obj + 0x32) = 0xFF;
        *(unsigned char *)(obj + 0x31) = 1;
        *(unsigned char *)(obj + 0x20) = 0;
        *(char **)(obj + 0xB8) = owner;
        v = *(char **)(obj + 0x68);
        *(long *)(obj + 0x38) = *(long *)(owner + 0x38);
        *(u128_t *)(obj + 0x10) = *(u128_t *)v;
        *(u128_t *)v = *(u128_t *)va;
        *(u128_t *)(v + 0x20) = *(u128_t *)vb;
        *(float *)(v + 0x3C) = f;
        *(int *)(v + 0x38) = 0;
        *(int *)(v + 0x34) = 0;
    }
    return obj;
}
/* localdecomp:end func_L05_00362E38 */

/* localdecomp:start func_L05_00362EE0 */
typedef int u128_361BA8 __attribute__((mode(TI)));
extern void func_L05_00362F30_00362EE0(u8 *a0, u128_361BA8 *a1);
extern void func_L05_00363110_00362EE0(u8 *a0, u128_361BA8 *a1);
void func_L05_00362EE0(u8 *a0) {
    u128_361BA8 tmp;
    u128_361BA8 *p = *(u128_361BA8 **)(a0 + 104);
    tmp = *p;
    func_L05_00362F30_00362EE0(a0, &tmp);
    tmp = *p;
    func_L05_00363110_00362EE0(a0, &tmp);
}
/* localdecomp:end func_L05_00362EE0 */

/* localdecomp:start func_L05_00362F30 */
#include "vu0.h"
typedef struct { f32 a; f32 b; } P_00362F30;
typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    P_00362F30 p[4];
    long z;
    long r;
    long k;
    long m;
} S_00362F30;
extern vu0_v4 D_L05_001E2680_00362F30;
__asm__(".extern D_L05_001E2680_00362F30, 16");
extern f32 D_L05_001DDA80[2];
extern f32 D_L05_001DDA84[2];
extern f32 D_L05_001DDA64;
__asm__(".extern D_L05_001DDA64, 4");
extern s32 D_L05_001DDA6C;
__asm__(".extern D_L05_001DDA6C, 4");
extern s32 D_L05_001DDA74;
__asm__(".extern D_L05_001DDA74, 4");
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);

void func_L05_00362F30(u8 *a0, u128_361BA8 *a1) {
    vu0_v4 arg;
    S_00362F30 s;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 g;
    u8 *p;
    s32 i;
    f32 *pu;
    f32 *pv;
    u128_361BA8 tu;
    vu0_q M;
    vu0_q T;
    vu0_q cs;

    tu = *a1;
    vec_copy(&f, &D_L05_001E2680_00362F30);
    vec_copy(&g, &D_L05_001E2680_00362F30);
    *(u128_361BA8 *)&arg = tu;
    p = *(u8 **)(a0 + 0x68);
    __asm__("lqc2 %0, %1" : "=j"(cs) : "m"(*(vu0_v4 *)(p + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(M) : "m"(*(vu0_v4 *)p));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(M) : "j"(M), "j"(cs));
    __asm__("sqc2 %1, %0" : "=m"(c) : "j"(M));
    __asm__("lqc2 %0, %1" : "=j"(M) : "m"(f));
    __asm__("lqc2 %0, %1" : "=j"(T) : "m"(*(vu0_v4 *)p));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(T) : "j"(T), "j"(M));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(T));
    __asm__("lqc2 %0, %1" : "=j"(T) : "m"(g));
    __asm__("lqc2 %0, %1" : "=j"(M) : "m"(*(vu0_v4 *)(p + 0x10)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(M) : "j"(M), "j"(T));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(M));
    func_0038CE90(&a, &a, &c);
    func_0038CF68(&a, &a, D_L05_001DDA64);
    func_0038CE90(&b, &b, &c);
    func_0038CF68(&b, &b, D_L05_001DDA64);
    s.r = func_00389598(0xE);
    s.k = 0x0000FF9000000260;
    s.m = ((long)D_L05_001DDA6C << 32) | 0x48;
    s.z = 0;
    s.c[0] = s.c[1] = s.c[2] = s.c[3] = D_L05_001DDA74;
    pu = &s.p[0].a;
    pv = &s.p[0].b;
    for (i = 0; i < 4; i++) {
        pu[i * 2] = D_L05_001DDA80[i * 2];
        pv[i * 2] = D_L05_001DDA84[i * 2];
    }
    vec_sub_ba(&e, p, &a);
    d = e;
    s.v[0] = d;
    vec_add_ba(&e, p, &a);
    d = e;
    s.v[1] = d;
    vec_sub_ba(&e, p + 0x10, &b);
    d = e;
    s.v[2] = d;
    vec_add_ab(&e, p + 0x10, &b);
    d = e;
    s.v[3] = d;
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L05_00362F30 */

/* localdecomp:start func_L05_00363110 */
#include "vu0.h"
typedef struct { f32 a; f32 b; } P_00363110;
typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    P_00363110 p[4];
    long z;
    long r;
    long k;
    long m;
} S_00363110;
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001E2680, 16");
extern f32 D_L05_001DDA80[2];
extern f32 D_L05_001DDA84[2];
extern f32 D_L05_001DDA68;
__asm__(".extern D_L05_001DDA68, 4");
extern s32 D_L05_001DDA70;
__asm__(".extern D_L05_001DDA70, 4");
extern s32 D_L05_001DDA78;
__asm__(".extern D_L05_001DDA78, 4");
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);

void func_L05_00363110(u8 *a0, u128_361BA8 *a1) {
    vu0_v4 arg;
    S_00363110 s;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 g;
    u8 *p;
    s32 i;
    f32 *pu;
    f32 *pv;
    u128_361BA8 tu;
    vu0_q M;
    vu0_q T;
    vu0_q cs;

    tu = *a1;
    vec_copy(&f, &D_L05_001E2680);
    vec_copy(&g, &D_L05_001E2680);
    *(u128_361BA8 *)&arg = tu;
    p = *(u8 **)(a0 + 0x68);
    __asm__("lqc2 %0, %1" : "=j"(cs) : "m"(*(vu0_v4 *)(p + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(M) : "m"(*(vu0_v4 *)p));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(M) : "j"(M), "j"(cs));
    __asm__("sqc2 %1, %0" : "=m"(c) : "j"(M));
    __asm__("lqc2 %0, %1" : "=j"(M) : "m"(f));
    __asm__("lqc2 %0, %1" : "=j"(T) : "m"(*(vu0_v4 *)p));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(T) : "j"(T), "j"(M));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(T));
    __asm__("lqc2 %0, %1" : "=j"(T) : "m"(g));
    __asm__("lqc2 %0, %1" : "=j"(M) : "m"(*(vu0_v4 *)(p + 0x10)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(M) : "j"(M), "j"(T));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(M));
    func_0038CE90(&a, &a, &c);
    func_0038CF68(&a, &a, D_L05_001DDA68);
    func_0038CE90(&b, &b, &c);
    func_0038CF68(&b, &b, D_L05_001DDA68);
    s.r = func_00389598(0x13);
    s.k = 0x0000FF9000000260;
    s.m = ((long)D_L05_001DDA70 << 32) | 0x48;
    s.z = 0;
    s.c[0] = s.c[1] = s.c[2] = s.c[3] = D_L05_001DDA78;
    pu = &s.p[0].a;
    pv = &s.p[0].b;
    for (i = 0; i < 4; i++) {
        pu[i * 2] = D_L05_001DDA80[i * 2];
        pv[i * 2] = D_L05_001DDA84[i * 2];
    }
    vec_sub_ba(&e, p, &a);
    d = e;
    s.v[0] = d;
    vec_add_ba(&e, p, &a);
    d = e;
    s.v[1] = d;
    vec_sub_ba(&e, p + 0x10, &b);
    d = e;
    s.v[2] = d;
    vec_add_ba(&e, p + 0x10, &b);
    d = e;
    s.v[3] = d;
    func_003D2DA0(&s, 0, 0);
    s.r = func_00389598(0x17);
    s.k = 0x0000FF9000000260;
    s.m = 0x0000008000000048;
    s.z = 0;
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L05_00363110 */

/* localdecomp:start func_L05_00363330 */
extern void func_L01_003303B8(void *a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3,
                          f32 f12, f32 f13, f32 f14, f32 f15,
                          s32 s0, s32 s1, s32 s2, s32 s3, s32 s4, s32 s5, s32 s6, s32 s7,
                          s32 s8, s32 s9, s32 s10, s32 s11, s32 s12, s32 s13,
                          s32 s14, s32 s15, s32 s16, s32 s17);

void func_L05_00363330(void *a0) {
    func_L01_003303B8(a0, 0, 5, 5, 5, 5, 5, 0, 0.45f, 0.0f, 0.0f, 0.0f,
                  0, 1, 1, 0, 0, 1, 0x10000, 0,
                  0x38D024, 0x38D024, 0x38D024, 0x38D024, 0x38D024, 0x38D024,
                  0x7F38D024, 0x2838D024, 0x38D024, 0);
}
/* localdecomp:end func_L05_00363330 */

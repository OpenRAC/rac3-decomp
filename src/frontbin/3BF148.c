#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BF2A0();


typedef int Q_3B9C50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9C50;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u8 padA[2];
    s32 wC;
    Q_3B9C50 q10;
    V4_3B9C50 v20;
    Q_3B9C50 q30;
} S_3B9C50;
typedef struct { u8 pad[4]; u8 b4; } T_3B9C50;
extern f32 D_001D8E00;
extern f32 D_001D8E04;
extern s32 D_001D8E08;
extern s32 D_001D8E0C;
extern s32 D_001D8E10;
extern s32 D_001D8E14;
extern s32 D_001D8E18;
extern s32 D_001D8E1C;
extern f32 D_001D8E20;
extern u8 D_001D8E24;
extern u8 D_001D8E28;
extern T_3B9C50 *D_002FD004[];
extern void *func_003CD108(s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(s32, s32, f32);
/* localdecomp:start func_003BF148 */
typedef struct { u8 pad[4]; u8 b4; } T_3B9C50_003BF148;
__asm__(".extern D_001D8E00_003BF148, 4");
__asm__(".extern D_001D8E04_003BF148, 4");
__asm__(".extern D_001D8E08_003BF148, 4");
__asm__(".extern D_001D8E0C_003BF148, 4");
__asm__(".extern D_001D8E10_003BF148, 4");
__asm__(".extern D_001D8E14_003BF148, 4");
__asm__(".extern D_001D8E18_003BF148, 4");
__asm__(".extern D_001D8E1C_003BF148, 4");
__asm__(".extern D_001D8E20_003BF148, 4");
__asm__(".extern D_001D8E24_003BF148, 1");
__asm__(".extern D_001D8E28_003BF148, 1");
extern f32 D_001D8E00_003BF148;
extern f32 D_001D8E04_003BF148;
extern s32 D_001D8E08_003BF148;
extern s32 D_001D8E0C_003BF148;
extern s32 D_001D8E10_003BF148;
extern s32 D_001D8E14_003BF148;
extern s32 D_001D8E18_003BF148;
extern s32 D_001D8E1C_003BF148;
extern f32 D_001D8E20_003BF148;
extern u8 D_001D8E24_003BF148;
extern u8 D_001D8E28_003BF148;
extern T_3B9C50_003BF148 *D_002FD004_003BF148[];
extern void *func_003CD108_003BF148(s32);
extern f32 func_003824E0_003BF148(f32, f32);
extern s32 func_00382498_003BF148(s32, s32);
extern void func_0038CF68_003BF148(s32, s32, f32);
S_3B9C50 *func_003BF148(V4_3B9C50 *a, V4_3B9C50 *b) {
    S_3B9C50 *p = func_003CD108_003BF148(0);
    V4_3B9C50 v, w, t;
    f32 f, k, z;
    s32 r1, r2;
    Q_3B9C50 x, y;
    if (p == 0) return 0;
    k = D_001D8E20_003BF148;
    f = func_003824E0_003BF148(D_001D8E00_003BF148, D_001D8E04_003BF148);
    r1 = func_00382498_003BF148(D_001D8E0C_003BF148, D_001D8E10_003BF148);
    r2 = func_00382498_003BF148(D_001D8E18_003BF148, D_001D8E1C_003BF148);
    *(Q_3B9C50 *)&v = *(Q_3B9C50 *)b;
    func_0038CF68_003BF148((s32)&v, (s32)&v, f);
    p->w4 = D_001D8E08_003BF148 | (r1 << 24);
    p->wC = D_001D8E14_003BF148 | (r2 << 24);
    p->b9 = 0x64;
    p->b3 = D_001D8E28_003BF148;
    p->b1 = D_001D8E24_003BF148;
    p->b2 = D_002FD004_003BF148[0]->b4;
    p->q10 = *(Q_3B9C50 *)a;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(x));
    w = t;
    p->v20 = w;
    *(f32 *)((u8 *)p + 0x1C) = k;
    p->v20.w = 1.0f;
    z = a->z + 5.0f;
    p->q30 = *(Q_3B9C50 *)b;
    *(f32 *)((u8 *)p + 0x3C) = z;
    return p;
}
/* localdecomp:end func_003BF148 */

typedef int Q_3B9DA8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9DA8;
typedef struct {
    u8 pad0[0x10];
    V4_3B9DA8 v10;
    V4_3B9DA8 v20;
    V4_3B9DA8 v30;
} S_3B9DA8;
extern void func_003CD250(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BF2A0);

typedef int Q_3B9E98 __attribute__((mode(TI)));
typedef struct { V4_3B9C50 a; V4_3B9C50 b; } E_3B9E98;
extern s32 func_003C2B88_003BF390(void *, s32);
extern S_3B9C50 *func_003BF148(V4_3B9C50 *, V4_3B9C50 *);
extern void func_00382580(V4_3B9C50 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
/* localdecomp:start func_003BF390 */
/* US draft of func_003BF390 (rac3-uya-decomp func_003B9E98, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


extern s32 func_003C2B88_003BF390_003BF390(void *, s32);
extern S_3B9C50 *func_003BF148_003BF390(V4_3B9C50 *, V4_3B9C50 *);
extern void func_00382580_003BF390(V4_3B9C50 *, f32, f32);
extern f32 func_003824E0_003BF390(f32, f32);
extern void func_0038CDF8_003BF390(void *, void *, void *, f32);
void func_003BF390(void *a) {
    V4_3B9C50 v;
    V4_3B9C50 w;
    V4_3B9C50 t;
    Q_3B9E98 x, y;
    E_3B9E98 *e;
    s32 n;
    s32 i;
    e = (E_3B9E98 *)0x70000000;
    n = func_003C2B88_003BF390_003BF390(a, 0);
    *(Q_3B9E98 *)&v = 0;
    v.z = 0.2f;
    *(f32 *)((u8 *)e + 0x1D4) += 1.32f;
    *(f32 *)((u8 *)e + 0x204) += -1.32f;
    func_003BF148_003BF390((V4_3B9C50 *)0x700001D0, &v);
    func_003BF148_003BF390((V4_3B9C50 *)0x70000200, &v);
    *(f32 *)((u8 *)e + 0x180) += -0.2f;
    *(f32 *)((u8 *)e + 0x188) += -0.15f;
    *(f32 *)((u8 *)e + 0x120) += -0.2f;
    *(f32 *)((u8 *)e + 0x128) += -0.15f;
    func_003BF148_003BF390((V4_3B9C50 *)0x70000180, &v);
    func_003BF148_003BF390((V4_3B9C50 *)0x70000120, &v);
    for (i = 0; i < n; i++, e++) {
        if (e->b.w == 0.0f) {
            *(Q_3B9E98 *)&w = *(Q_3B9E98 *)&e->a;
            w.w = 1.0f;
            func_00382580_003BF390(&t, 0.0f, e->a.w);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(w));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(w) : "j"(x));
        } else {
            func_0038CDF8_003BF390(&w, &e->a, &e->b, func_003824E0_003BF390(0.0f, 0.9f));
            w.x += func_003824E0_003BF390(-e->a.w * 0.4f, e->a.w * 0.4f);
            w.y += func_003824E0_003BF390(-e->a.w * 0.4f, e->a.w * 0.4f);
            w.w = 1.0f;
        }
        func_003BF148_003BF390(&w, &v);
    }
}
/* localdecomp:end func_003BF390 */

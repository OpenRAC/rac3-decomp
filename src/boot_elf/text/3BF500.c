#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3BE710.c's earlier functions (tools/port_from_us.py) */
extern s32 D_001DA2D0_003BE800;
extern u8 D_001DA2D4_003BE800;
extern s32 D_001DA2D8_003BE800;
extern s32 D_001DA2DC_003BE800;
extern s32 D_001D8D28_003BE800;
extern s32 D_001D8D40_003BE800;
extern u8 D_001D8D2C_003BE800[8];
extern u8 D_001D8D44_003BE800[8];
extern s32 D_002FCDC4[];
extern void func_003BBDC0(s32, s32);
extern void func_003BC7C0();
extern void func_003BE068(s32, s32 *, s32);
extern s32 func_003BE0F0();
extern void func_003BE1D8();
extern void func_003BE6C0();
extern void func_003BE8E0();
extern void func_003BE948();
extern s32 func_003BE940();
extern void func_003BF130();
typedef int Q_3B9098 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9098;
typedef struct { f32 f0, f4, f8, fC, f10; u8 b14, b15; } Sub_3B9098;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    u8 hA[2];
    f32 fC;
    V4_3B9098 v10;
    Sub_3B9098 s20;
} S_3B9098;
extern s32 func_0038CEE0(void *);
extern void func_003CD608(s32);
typedef int u128_3B9160 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, fC, f10;
    u8 b14, b15;
    u8 pad16[6];
    void *f1C;
} Q_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_3B9160 v10;
    Q_3B9160 q;
} P_3B9160;
extern void *func_003CD4C0(s32);
extern s32 func_00382848(s32);
extern u8 *D_002FCF20[];
extern void func_003BE948();
typedef struct { f32 f0, f4, f8, fC, f10; u8 b14, b15; u8 pad16[6]; void *f1C; } Sub_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3B9160 q10;
    Sub_3B9160 s20;
} S_3B9160;
typedef int Q_3B92B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B92B8;
extern void func_0038D348(s32, s32, f32);
extern void func_0038D270(void *, void *, void *);
extern f32 func_0038D288(void *);
extern void func_0038D218(void *, void *, f32);
extern f32 func_0038D478(f32);
extern s32 func_00382848();
extern f32 func_003828C0(f32, f32);
extern S_3B9160 *func_003BEA10(Q_3B9160 *, f32 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_003BF168();
extern void func_0038A2F8();
extern void func_003BEFE0(void *);
typedef struct { u8 b[8]; } V8_3B98B8;
typedef struct { u128_t q[4]; } M4_3B98B8;
extern V8_3B98B8 D_001D8D80[];
extern M4_3B98B8 D_001D8D90[];
extern u8 D_001D8DD0;
extern s32 D_001D9348;
extern void func_003C33A0();
extern void func_003D9808();
extern void func_003D3158();
extern u8 D_001DA2D4[];
extern u8 D_001DA300[];
extern s32 D_001D9364[];
u8 func_003BDFB0(void);
extern u8 D_001DA2D4_003BF2B8;
extern volatile u8 D_001DA300_003BF2B8;
extern s32 D_001DA2D0;
extern s32 D_001D8D28;
extern s32 D_001D8D40;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern S_3B9A08 D_00225700_003BF2B8;
extern void func_003BCB20();
extern s32 func_003BE2C8();
extern s32 func_003BE2D0();
extern void func_003BE520();
extern void func_003BBD20();
extern s32 func_003BE0F0();
extern void func_003BE218();
extern void func_003BE6C0();
extern void func_003BE2F8();
extern void func_003882D0();
extern void func_003BE8E0();
extern void func_003BE318();
extern void func_003BE2F8();
extern void func_003BCB20();
extern u8 D_001DA310;
extern u8 D_001DA311;
extern s32 D_001D8DF0;
extern s32 D_001D8DF4;
extern void *D_002FCC40[];
extern void func_003BBDC0(s32, s32);
extern void func_003BC7C0();
extern void func_003BE068(s32, s32 *, s32);
extern s32 func_003BE0F0(void);
extern void func_003BE1D8(s32);
extern void func_003BF658();
extern void func_003BF498();
extern void func_003BE6C0(void *);
extern void func_003BE5B0(s32);
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x74]; s16 hAA; } S_3B9BE8;
extern s32 D_001D4B60[];
extern u8 func_00381BC0(void);

/* localdecomp:start func_003BF500 */
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
__asm__(".extern D_001D8E00, 4");
__asm__(".extern D_001D8E04, 4");
__asm__(".extern D_001D8E08, 4");
__asm__(".extern D_001D8E0C, 4");
__asm__(".extern D_001D8E10, 4");
__asm__(".extern D_001D8E14, 4");
__asm__(".extern D_001D8E18, 4");
__asm__(".extern D_001D8E1C, 4");
__asm__(".extern D_001D8E20, 4");
__asm__(".extern D_001D8E24, 1");
__asm__(".extern D_001D8E28, 1");
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
extern void *func_003CD4C0(s32);
extern f32 func_003828C0(f32, f32);
extern s32 func_00382878(s32, s32);
extern void func_0038D348(s32, s32, f32);
S_3B9C50 *func_003BF500(V4_3B9C50 *a, V4_3B9C50 *b) {
    S_3B9C50 *p = func_003CD4C0(0);
    V4_3B9C50 v, w, t;
    f32 f, k, z;
    s32 r1, r2;
    Q_3B9C50 x, y;
    if (p == 0) return 0;
    k = D_001D8E20;
    f = func_003828C0(D_001D8E00, D_001D8E04);
    r1 = func_00382878(D_001D8E0C, D_001D8E10);
    r2 = func_00382878(D_001D8E18, D_001D8E1C);
    *(Q_3B9C50 *)&v = *(Q_3B9C50 *)b;
    func_0038D348((s32)&v, (s32)&v, f);
    p->w4 = D_001D8E08 | (r1 << 24);
    p->wC = D_001D8E14 | (r2 << 24);
    p->b9 = 0x64;
    p->b3 = D_001D8E28;
    p->b1 = D_001D8E24;
    p->b2 = D_002FD004[0]->b4;
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
/* localdecomp:end func_003BF500 */

typedef int Q_3B9DA8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9DA8;
typedef struct {
    u8 pad0[0x10];
    V4_3B9DA8 v10;
    V4_3B9DA8 v20;
    V4_3B9DA8 v30;
} S_3B9DA8;
extern void func_003CD608(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BF658);

/* localdecomp:start func_003BF748 */
typedef int Q_3B9E98 __attribute__((mode(TI)));
typedef struct { V4_3B9C50 a; V4_3B9C50 b; } E_3B9E98;
extern s32 func_003C2F40_003BF748(void *, s32);
extern S_3B9C50 *func_003BF500(V4_3B9C50 *, V4_3B9C50 *);
extern void func_00382960(V4_3B9C50 *, f32, f32);
extern f32 func_003828C0(f32, f32);
extern void func_0038D1D8(void *, void *, void *, f32);
void func_003BF748(void *a) {
    V4_3B9C50 v;
    V4_3B9C50 w;
    V4_3B9C50 t;
    Q_3B9E98 x, y;
    E_3B9E98 *e;
    s32 n;
    s32 i;
    e = (E_3B9E98 *)0x70000000;
    n = func_003C2F40_003BF748(a, 0);
    *(Q_3B9E98 *)&v = 0;
    v.z = 0.2f;
    *(f32 *)((u8 *)e + 0x1D4) += 1.32f;
    *(f32 *)((u8 *)e + 0x204) += -1.32f;
    func_003BF500((V4_3B9C50 *)0x700001D0, &v);
    func_003BF500((V4_3B9C50 *)0x70000200, &v);
    *(f32 *)((u8 *)e + 0x180) += -0.2f;
    *(f32 *)((u8 *)e + 0x188) += -0.15f;
    *(f32 *)((u8 *)e + 0x120) += -0.2f;
    *(f32 *)((u8 *)e + 0x128) += -0.15f;
    func_003BF500((V4_3B9C50 *)0x70000180, &v);
    func_003BF500((V4_3B9C50 *)0x70000120, &v);
    for (i = 0; i < n; i++, e++) {
        if (e->b.w == 0.0f) {
            *(Q_3B9E98 *)&w = *(Q_3B9E98 *)&e->a;
            w.w = 1.0f;
            func_00382960(&t, 0.0f, e->a.w);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(w));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(w) : "j"(x));
        } else {
            func_0038D1D8(&w, &e->a, &e->b, func_003828C0(0.0f, 0.9f));
            w.x += func_003828C0(-e->a.w * 0.4f, e->a.w * 0.4f);
            w.y += func_003828C0(-e->a.w * 0.4f, e->a.w * 0.4f);
            w.w = 1.0f;
        }
        func_003BF500(&w, &v);
    }
}
/* localdecomp:end func_003BF748 */

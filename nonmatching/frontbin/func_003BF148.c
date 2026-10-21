/* US draft of func_003BF148 (rac3-uya-decomp func_003B9C50, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BF148 */
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
extern void *func_003CD108(s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(s32, s32, f32);
S_3B9C50 *func_003BF148(V4_3B9C50 *a, V4_3B9C50 *b) {
    S_3B9C50 *p = func_003CD108(0);
    V4_3B9C50 v, w, t;
    f32 f, k, z;
    s32 r1, r2;
    Q_3B9C50 x, y;
    if (p == 0) return 0;
    k = D_001D8E20;
    f = func_003824E0(D_001D8E00, D_001D8E04);
    r1 = func_00382498(D_001D8E0C, D_001D8E10);
    r2 = func_00382498(D_001D8E18, D_001D8E1C);
    *(Q_3B9C50 *)&v = *(Q_3B9C50 *)b;
    func_0038CF68((s32)&v, (s32)&v, f);
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
/* localdecomp:end func_003BF148 */

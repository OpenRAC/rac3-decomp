#include "common.h"

/* declared by functions of L30_003468C8.c, which this file was cut from */
extern void func_L30_00346988();

/* localdecomp:start func_L30_00346988 */
#include "vu0.h"
typedef struct {
    u8 p0[0x40];
    s32 f40[4];
    u8 p50[0x20];
    long f70;
    long f78;
    long f80;
    long f88;
} S_00346988;
__asm__(".extern D_L30_001DCF78_00346988, 4");
__asm__(".extern D_L30_001DCF7C, 4");
__asm__(".extern D_L30_001DCFB4, 4");
__asm__(".extern D_L30_001DCFB8, 4");
__asm__(".extern D_L30_001DCFBC, 4");
__asm__(".extern D_L30_001DCFC0, 4");
__asm__(".extern D_L30_001DCFCC, 4");
__asm__(".extern D_L30_001DCFD0, 4");
__asm__(".extern D_L30_001DCFD4, 4");
__asm__(".extern D_L30_001DCFD8, 4");
__asm__(".extern D_L30_001DCFDC, 4");
__asm__(".extern D_L30_001DCFE0, 4");
__asm__(".extern D_L30_001DCFE4, 4");
__asm__(".extern D_L30_001DCFE8, 4");
__asm__(".extern D_L30_001DCFEC, 4");
extern s32 D_L30_001DCF78_00346988;
extern s32 D_L30_001DCF7C;
extern s32 D_L30_001DCFB4;
extern s32 D_L30_001DCFB8;
extern s32 D_L30_001DCFBC;
extern s32 D_L30_001DCFC0;
extern f32 D_L30_001DCFCC;
extern f32 D_L30_001DCFD0;
extern s32 D_L30_001DCFD4;
extern f32 D_L30_001DCFD8;
extern f32 D_L30_001DCFDC;
extern f32 D_L30_001DCFE0;
extern f32 D_L30_001DCFE4;
extern f32 D_L30_001DCFE8;
extern f32 D_L30_001DCFEC;
extern S_00346988 D_L30_00283D60;
extern S_00346988 D_L30_00283DF0;
typedef struct { f32 x, y; } P_00346988;
typedef struct { f32 v[4]; } Q_00346988;
typedef struct {
    s32 e[16][2];
    u8 p80[0x10];
    f32 f90[4];
    f32 fA0;
} M_00346988;
extern P_00346988 D_L30_00283E40[];
extern Q_00346988 D_L30_00283E80[];
extern void func_L24_00358F70(f32 *m, s32 a1, f32 a, f32 b, f32 c, f32 d, f32 e);
extern long func_00389598(s32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L30_0034C540(void *, void *, f32, f32, s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_00389478(void *, f32 *, f32 *);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, void *, s32);

void func_L30_00346988(u8 *moby) {
    f32 v[4] __attribute__((aligned(16)));
    M_00346988 *p = *(M_00346988 **)(moby + 0x68);
    s32 i;
    s32 j;
    f32 t;
    f32 a;
    f32 b;
    f32 s;

    func_L24_00358F70((f32 *)&D_L30_00283D60, 1, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
    D_L30_00283D60.f78 = func_00389598(0x3B);
    D_L30_00283D60.f88 = (0x8000L << 24) | 0x6A;
    D_L30_00283D60.f80 = (0xFF90L << 32) | 0x260;
    D_L30_00283D60.f70 = 0;
    D_L30_00283DF0.f78 = func_00389598(-1);
    D_L30_00283DF0.f80 = (0xFF90L << 32) | 0x260;
    D_L30_00283DF0.f70 = 0;
    for (i = 0; i < 16; i++) {
        t = func_L03_0034B440(1, 0, 0, (f32)p->e[i][0], (f32)D_L30_001DCFD4, 1.0f);
        a = func_003C4088(D_L30_001DCFEC, D_L30_001DCFE8, t);
        b = func_003C4088(D_L30_001DCFD0, D_L30_001DCFCC, t);
        func_0038CE20(v, p->f90, (D_L30_001DCFE4 - 1.0f) * (f32)(D_L30_001DCFD4 - p->e[i][0]));
        vec_add_ab(v, v, moby + 0x10);
        v[1] -= D_L30_001DCFE0 * (1.0f - t);
        func_L30_0034C540(&D_L30_00283D60, v, a, b, 0, p->fA0);
        for (j = 0; j < 4; j++) {
            D_L30_00283D60.f40[j] = func_0038DBD8(D_L30_001DCF7C, D_L30_001DCF78_00346988, t);
        }
        func_L30_0034C540(&D_L30_00283DF0, v, a, b, 0, p->fA0);
        D_L30_00283DF0.f40[0] = func_0038DBD8(D_L30_001DCFB8, D_L30_001DCFB4, t);
        D_L30_00283DF0.f40[1] = func_0038DBD8(D_L30_001DCFB8, D_L30_001DCFB4, t);
        D_L30_00283DF0.f40[2] = func_0038DBD8(D_L30_001DCFC0, 0x800000FF, t);
        D_L30_00283DF0.f40[3] = func_0038DBD8(D_L30_001DCFC0, D_L30_001DCFBC, t);
        s = func_003C4088(D_L30_001DCFD8, D_L30_001DCFDC, t);
        func_L30_0034C540(D_L30_00283E80, v, a * s, b * s, 0, p->fA0);
        for (j = 0; j < 4; j++) {
            func_00389478(&D_L30_00283E80[j], &D_L30_00283E40[j].x, &D_L30_00283E40[j].y);
        }
        func_003A9440(0x47, 0x31001);
        func_003D2DA0(&D_L30_00283D60, 0, 0);
        if (i & 1) {
            D_L30_00283DF0.f88 = (0x8000L << 24) | 0x58;
        }
        func_003A9440(0x47, 0x53001);
        func_003D2DA0(&D_L30_00283DF0, 0, 0);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L30_00346988 */

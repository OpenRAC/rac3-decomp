#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[8];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);

/* localdecomp:start func_L31_0034CC30 */
typedef struct {
    u8 pad[0x40];
} S_0034CC30;

typedef struct {
    u8 pad0[0xE8];
    s32 xE8;
    u8 padEC[0x154 - 0xEC];
    s32 x154;
    u8 pad158[0x15C - 0x158];
    s32 x15C;
} V_0034CC30;

typedef struct {
    u8 pad0[0x68];
    V_0034CC30 *vars;
    u8 pad6C[0x94 - 0x6C];
    u8 b94;
} M_0034CC30;

extern S_0034CC30 D_L31_00284110[];
extern void *D_L31_001E12D0[] __attribute__((section(".sdata")));
extern u8 *D_L31_001DF79C;
extern u8 D_00142660[];
extern void func_003C2C98(void *, void *);
extern void func_L01_00456230(void *, s32);
extern void func_L31_0034D390(void *, s32);
extern void func_003C2880(void *);

void func_L31_0034CC30(M_0034CC30 *m) {
    V_0034CC30 *v = m->vars;
    s32 i;
    s32 j;

    for (i = 0; i < 31; i++) {
        func_003C2C98(m, &D_L31_00284110[i]);
    }
    for (j = 13; j >= 0; j--) {
        D_L31_001E12D0[j] = 0;
    }
    v->x15C = 0;
    if (m->b94) {
        if (v->xE8 != -1) {
            func_L01_00456230(D_L31_001DF79C + v->xE8 * 0x100, 0);
        }
        if (v->x154 == 0) {
            D_00142660[0x77] |= 0x10;
            func_L31_0034D390(m, 0);
        }
    }
    func_003C2880(m);
}
/* localdecomp:end func_L31_0034CC30 */

/* localdecomp:start func_L31_0034CD18 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x80];
    s32 x80[0x12];
    s32 xC8;
    u8 padCC[0xF8 - 0xCC];
    s32 xF8;
    u8 padFC[0x130 - 0xFC];
    f32 x130;
    f32 x134;
    u8 pad138[0x140 - 0x138];
    u8 x140[0x10];
    s32 x150;
    s32 x154;
} V_0034CD18;
typedef struct {
    u8 pad0[0x68];
    V_0034CD18 *x68;
    u8 pad6C[0xF8 - 0x6C];
    f32 xF8;
} M_0034CD18;
typedef struct {
    s32 n;
    u8 pad4[0xC];
    struct {
        f32 x;
        u8 pad4[0xC];
    } e[1];
} K_0034CD18;

typedef struct {
    u8 pad0[0x80];
} S80_0034CD18;
extern S80_0034CD18 *D_L31_001DF880_0034CD18;
extern f32 D_L31_00284A10_0034CD18[];
extern f32 D_L31_001E12B4_0034CD18;
extern s32 D_L31_001E12B0_0034CD18;
extern K_0034CD18 *D_L31_0021D740_0034CD18[];
__asm__(".extern D_L31_001DD1C0_0034CD18, 4");
__asm__(".extern D_L31_001DD1AC_0034CD18, 4");
extern f32 D_L31_001DD1C0_0034CD18;
extern s32 D_L31_001DD1AC_0034CD18;
extern f32 D_001A4C60[];
extern void func_L30_0034CCD0_0034CD18(void *, f32 *, f32 *, f32 *, f32 *);
extern void func_L31_0034B850_0034CD18(M_0034CD18 *, f32 *, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_L31_0034E0F0_0034CD18(void *, s32, s32, s32, s32);

void func_L31_0034CD18(M_0034CD18 *m) {
    V_0034CD18 *v = m->x68;
    f32 p0[4];
    f32 p1[4];
    f32 pos[4];
    f32 ax, ay, az, aw;
    f32 bx, by, bz, bw;
    s32 i;
    f32 t0, t1, d, x;
    K_0034CD18 *k;
    s32 r;

    aw = az = ay = ax = 0.0f;
    if (v->xF8 != -1) {
        func_L30_0034CCD0_0034CD18(&D_L31_001DF880_0034CD18[v->xF8], &ax, &ay, &az, &aw);
    }
    v->x130 = 0.0f;
    v->x134 = 1.0f;
    D_L31_001E12B4_0034CD18 = 0.0f;
    D_L31_00284A10_0034CD18[0] = 0.0f;
    for (i = 1; i < 0x200; i++) {
        t0 = (f32)(i - 1) / 511.0f;
        func_L31_0034B850_0034CD18(m, p0, t0);
        t1 = (f32)i / 511.0f;
        func_L31_0034B850_0034CD18(m, p1, t1);
        d = func_0038CF00(p0, p1);
        D_L31_001E12B4_0034CD18 += d;
        D_L31_00284A10_0034CD18[i] = D_L31_001E12B4_0034CD18;
        if ((p0[0] - ax) * (p1[0] - ax) < 0.0f) {
            v->x130 = func_003C4088(t0, t1, fabsf(ax - p0[0]) / fabsf(p1[0] - p0[0]));
        }
        if ((p0[0] - ay) * (p1[0] - ay) < 0.0f) {
            v->x134 = func_003C4088(t0, t1, fabsf(ay - p0[0]) / fabsf(p1[0] - p0[0]));
        }
    }
    k = D_L31_0021D740_0034CD18[v->x80[v->xC8]];
    r = k->e[0].x < k->e[k->n - 1].x;
    D_L31_001E12B0_0034CD18 = r;
    if (r) {
        m->xF8 = 0.0f;
    } else {
        m->xF8 = 3.1415927f;
    }
    if (v->x150 == 0 && v->x154 == 0) {
        func_L30_0034CCD0_0034CD18(&D_L31_001DF880_0034CD18[v->xF8], &bx, &by, &bz, &bw);
        x = (bx + by) * 0.5f;
        x += func_00382498(0, 1) ? 4.0f : 0.0f;
        pos[0] = x + (func_00382498(0, 1) ? -4.0f : 0.0f);
        pos[1] = D_001A4C60[1];
        pos[2] = bw + D_L31_001DD1C0_0034CD18;
        v->x150 = func_L31_0034E0F0_0034CD18(pos, 1, D_L31_001DD1AC_0034CD18, 0, -1);
        qzero(v->x140);
    }
}
/* localdecomp:end func_L31_0034CD18 */

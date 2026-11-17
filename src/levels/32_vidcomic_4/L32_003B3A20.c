#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L32_003B3A20 */
extern f32 D_L32_001DED40;
__asm__(".extern D_L32_001DED40, 4");
extern s32 D_L32_001DED48;
__asm__(".extern D_L32_001DED48, 4");
extern f32 D_L32_001DED38;
__asm__(".extern D_L32_001DED38, 4");
extern f32 D_L32_001DED3C;
extern s32 D_L32_001DED1C;
__asm__(".extern D_L32_001DED1C, 4");
extern s32 D_L32_001DED20;
__asm__(".extern D_L32_001DED20, 4");
extern s32 D_L32_001DED4C;
__asm__(".extern D_L32_001DED4C, 4");
extern s32 D_L32_001DED18;
__asm__(".extern D_L32_001DED18, 4");
extern f32 D_L32_001DED28;
__asm__(".extern D_L32_001DED28, 4");
extern f32 D_L32_002A40D0[];
extern s32 D_L32_002A43D0[];
extern f32 D_L32_002A4450[];
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern void func_L32_003B41E8(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 *arg4);

typedef struct {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    f32 f3C;
    s32 f40;
    f32 f44;
    f32 f48;
} S_003B3A20;

void func_L32_003B3A20(u8 *a0) {
    S_003B3A20 *p = *(S_003B3A20 **)(a0 + 0x68);
    vu0_v4 pts[16];
    vu0_v4 up;
    vu0_v4 diff;
    vu0_v4 side;
    f32 t;
    f32 start;
    f32 prev;
    f32 w;
    f32 h;
    f32 f;
    f32 fi;
    f32 a;
    s32 i;
    s32 n;
    s32 m;
    s32 k;
    s32 col;
    s32 c;

    start = p->f34 - p->f3C;
    start = (start < 0.0f) ? 0.0f : start;
    prev = -1.0f;
    for (i = 0; i < 16; i++) {
        t = func_003C4088(start, p->f34, (f32)i / 15.0f);
        func_L32_003B41E8(a0, &pts[i], prev, fabs_asm(p->f34 - start) * 0.03125f, &t);
        prev = t;
    }
    qzero(&up);
    up.y = 1.0f;
    for (i = 0, k = 0; i < 16; k += 6, i++) {
        fi = (f32)i;
        h = fi / 15.0f;
        n = D_L32_001DED48;
        if (i < n) {
            w = D_L32_001DED40 * fi / (f32)n;
        } else {
            f = (f32)(i - n) / (f32)(15 - n);
            w = D_L32_001DED40 * sqrt_asm(1.0f - f * f);
        }
        if (i > 0) {
            vec_sub_ab(&diff, &pts[i], &pts[i - 1]);
        } else {
            vec_sub_ab(&diff, &pts[1], &pts[0]);
        }
        func_0038CE90(&side, &diff, &up);
        func_0038CF68(&side, &side, w);
        D_L32_002A40D0[k] = pts[i].x + side.x;
        D_L32_002A40D0[k + 1] = pts[i].y + side.y;
        D_L32_002A40D0[k + 2] = pts[i].z + side.z;
        D_L32_002A40D0[k + 3] = pts[i].x - side.x;
        D_L32_002A40D0[k + 4] = pts[i].y - side.y;
        D_L32_002A40D0[k + 5] = pts[i].z - side.z;
        if (p->f40 != 0) {
            col = D_L32_001DED1C;
        } else {
            col = D_L32_001DED20;
        }
        m = D_L32_001DED4C;
        a = (f32)(i - m) / (f32)(16 - m);
        c = func_0038DBD8(D_L32_001DED18, col, (a < 0.0f) ? 0.0f : a);
        D_L32_002A43D0[i * 2] = c;
        D_L32_002A43D0[i * 2 + 1] = c;
        D_L32_002A4450[i * 4] = D_L32_001DED38;
        D_L32_002A4450[i * 4 + 2] = D_L32_001DED3C;
        D_L32_002A4450[i * 4 + 1] = D_L32_002A4450[i * 4 + 3] = p->f48 + D_L32_001DED28 * h;
    }
    func_003D3A24(0x20, D_L32_002A40D0, D_L32_002A43D0, D_L32_002A4450, 1);
}
/* localdecomp:end func_L32_003B3A20 */

/* localdecomp:start func_L32_003B3D88 */
extern f32 D_L32_001DED44;
__asm__(".extern D_L32_001DED44, 4");
extern s32 D_L32_001DED48;
__asm__(".extern D_L32_001DED48, 4");
extern f32 D_L32_001DECE8;
__asm__(".extern D_L32_001DECE8, 4");
extern s32 D_L32_001DED1C;
__asm__(".extern D_L32_001DED1C, 4");
extern s32 D_L32_001DED20;
__asm__(".extern D_L32_001DED20, 4");
extern s32 D_L32_001DED4C;
__asm__(".extern D_L32_001DED4C, 4");
extern s32 D_L32_001DED18;
__asm__(".extern D_L32_001DED18, 4");
extern f32 D_L32_001DED28;
__asm__(".extern D_L32_001DED28, 4");
extern f32 D_L32_002A4250[];
extern s32 D_L32_002A43D0[];
extern f32 D_L32_002A4550[];
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern void func_L32_003B41E8(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 *arg4);

typedef struct {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    f32 f3C;
    s32 f40;
} S_003B3D88;

void func_L32_003B3D88(u8 *a0) {
    S_003B3D88 *p = *(S_003B3D88 **)(a0 + 0x68);
    vu0_v4 pts[16];
    vu0_v4 up;
    vu0_v4 diff;
    vu0_v4 side;
    f32 t;
    f32 start;
    f32 prev;
    f32 w;
    f32 h;
    f32 f;
    f32 fi;
    f32 a;
    s32 i;
    s32 n;
    s32 m;
    s32 k;
    s32 col;
    s32 c;

    start = p->f34 - p->f3C;
    start = (start < 0.0f) ? 0.0f : start;
    prev = -1.0f;
    for (i = 0; i < 16; i++) {
        t = func_003C4088(start, p->f34, (f32)i / 15.0f);
        func_L32_003B41E8(a0, &pts[i], prev, fabs_asm(p->f34 - start) * 0.03125f, &t);
        prev = t;
    }
    qzero(&up);
    up.y = 1.0f;
    for (i = 0, k = 0; i < 16; k += 6, i++) {
        fi = (f32)i;
        h = fi / 15.0f;
        n = D_L32_001DED48;
        if (i < n) {
            w = D_L32_001DED44 * fi / (f32)n;
        } else {
            f = (f32)(i - n) / (f32)(15 - n);
            w = D_L32_001DED44 * sqrt_asm(1.0f - f * f);
        }
        if (i > 0) {
            vec_sub_ab(&diff, &pts[i], &pts[i - 1]);
        } else {
            vec_sub_ab(&diff, &pts[1], &pts[0]);
        }
        func_0038CE90(&side, &diff, &up);
        func_0038CF68(&side, &side, w);
        D_L32_002A4250[k] = pts[i].x + side.x;
        D_L32_002A4250[k + 1] = pts[i].y + side.y + D_L32_001DECE8;
        D_L32_002A4250[k + 2] = pts[i].z + side.z;
        D_L32_002A4250[k + 3] = pts[i].x - side.x;
        D_L32_002A4250[k + 4] = pts[i].y - side.y + D_L32_001DECE8;
        D_L32_002A4250[k + 5] = pts[i].z - side.z;
        if (p->f40 != 0) {
            col = D_L32_001DED1C;
        } else {
            col = D_L32_001DED20;
        }
        m = D_L32_001DED4C;
        a = (f32)(i - m) / (f32)(16 - m);
        c = func_0038DBD8(D_L32_001DED18, col, (a < 0.0f) ? 0.0f : a);
        D_L32_002A43D0[i * 2] = c;
        D_L32_002A43D0[i * 2 + 1] = c;
        D_L32_002A4550[i * 4] = 0.0f;
        D_L32_002A4550[i * 4 + 3] = D_L32_001DED28 * h;
        D_L32_002A4550[i * 4 + 2] = 1.0f;
        D_L32_002A4550[i * 4 + 1] = D_L32_001DED28 * h;
    }
    func_003D3A24(0x20, D_L32_002A4250, D_L32_002A43D0, D_L32_002A4550, 1);
}
/* localdecomp:end func_L32_003B3D88 */

#include "common.h"

/* declared by functions of L01_0044E130.c, which this file was cut from */
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038D590(void *, void *);

/* localdecomp:start func_L01_0044FD88 */
typedef int s128_44CB08 __attribute__((mode(TI)));

extern void func_003C2EC0(u8 *, int, s128_44CB08 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C6FE0(u8 *);
extern void func_003C7C38(u8 *);
extern void func_0038D590(void *, void *);
extern void func_L01_00448E10(void *);
extern void func_003C7DD8(u8 *);

void func_L01_0044FD88(u8 *src, u8 *m, int arg, int flags) {
    s128_44CB08 mat[4];

    func_003C2EC0(src, arg, mat);
    *(s128_44CB08 *)(m + 0x10) = mat[3];
    if (flags & 1) {
        func_0038CE20(&mat[0], &mat[0], -1.0f);
    }
    if (flags & 2) {
        func_0038CE20(&mat[1], &mat[1], -1.0f);
    }
    if (flags & 4) {
        func_0038CE20(&mat[2], &mat[2], -1.0f);
    }
    func_003C6FE0(m);
    if (!(*(u16 *)(m + 0x34) & 4)) {
        func_003C7C38(m);
    }
    func_0038D590(m + 0xC0, mat);
    func_L01_00448E10(m + 0xC0);
    func_003C7DD8(m);
    if (*(u16 *)(src + 0x34) & 1) {
        *(u16 *)(m + 0x34) |= 0x41;
    } else {
        *(u16 *)(m + 0x34) &= ~0x41;
    }
    *(u16 *)(m + 0x34) |= 6;
}
/* localdecomp:end func_L01_0044FD88 */

/* localdecomp:start func_L01_0044FE98 */
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_003C4B50(f32 *);

f32 func_L01_0044FE98(f32 *a0, f32 *a1, s32 *a2, f32 f12, f32 f13, f32 f14, f32 f15) {
    f32 dist;
    f32 yaw;
    f32 pitch;
    f32 r;
    *a2 = 0;
    dist = ((f32 (*)(f32 *, f32 *))func_0038CF00)(a0, a1 + 4);
    if (f13 < dist) {
        *a2 = 1;
    }
    yaw = func_0038DBA0(func_0038D160(a1[4] - a0[0], a1[5] - a0[1]), f12);
    pitch = func_0038DBA0(func_0038D160(func_0038CF38(a0, a1 + 4), a1[6] - a0[2]), 0.0f);
    if (0.0f < f14 && f14 < yaw) {
        *a2 = 1;
    }
    if (0.0f < f15 && f15 < pitch) {
        *a2 = 1;
    }
    r = dist + yaw * dist;
    if (func_003C4B50(a1)) {
        r += 8.0f;
    }
    return r;
}
/* localdecomp:end func_L01_0044FE98 */

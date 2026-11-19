/* functional: high. Same branch structure and call sequence as retail (30 jals, 3 branch regions); differences: obj table pointers (+0x40/+0x44/+0x48) are loaded once instead of before each call, sqrt.s dest reg, branch-likely forms, nops before sqrt.s (needs divs_nops line). Retail reloads them after each callee, which do not write obj. B1F0/B300/AF70 prototypes added locally (file context lacks them). */
#include "vu0.h"
typedef struct {
    f32 *p0;
    f32 *p1;
    f32 *dir;
    f32 width;
    f32 lo;
    f32 hi;
    f32 *c0;
    f32 *c1;
    f32 *c2;
    f32 *c3;
    s32 col0;
    s32 col1;
} Seg_0040B3C0;
extern f32 D_L01_001E29C0[];
extern void func_L01_0040AF70(f32 *, f32 *, f32 *, f32 *, f32, f32);
extern void func_L01_0040B300(s32 a0, f32 *a1, f32 *a2, s32 a3, s32 t0, s32 t1, f32 f12);
extern void func_L01_0040B138(u32, u32, Item_408D28 *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_0040B1F0(s32 a0, f32 *a1, f32 *a2, s32 a3, s32 t0, s32 t1, f32 f12);
void func_L01_0040B3C0(u8 *obj, Seg_0040B3C0 *arg) {
    Seg_0040B3C0 s = *arg;
    f32 d0, d1, near, far, nearSq, farSq, t0, t1;
    Item_408D28 *tNear = *(Item_408D28 **)(obj + 0x40);
    Item_408D28 *tMid = *(Item_408D28 **)(obj + 0x44);
    Item_408D28 *tFar = *(Item_408D28 **)(obj + 0x48);
    s32 c0, c1;
    d0 = func_L01_0040E548(D_L01_001E29C0, s.p0);
    d1 = func_L01_0040E548(D_L01_001E29C0, s.p1);
    near = *(f32 *)(obj + 0x38);
    nearSq = near * near;
    far = *(f32 *)(obj + 0x3C);
    if (d0 < nearSq && d1 < nearSq) {
        func_L01_0040B138(s.col0, s.col0, tNear);
        func_L01_0040AF70(s.dir, s.p0, s.p1, (f32 *)tNear, s.lo, s.hi);
        func_L01_0040B1F0((s32)obj, s.c0, s.c1, 1, (s32)tFar, (s32)tNear, s.width);
        func_L01_0040B138(s.col1, s.col1, tMid);
        func_L01_0040AF70(s.dir, s.p0, s.p1, (f32 *)tMid, s.lo, s.hi);
        func_L01_0040B1F0((s32)obj, s.c2, s.c3, 0, (s32)tFar, (s32)tMid, s.width);
        func_L01_0040AF70(s.dir, s.p0, s.p1, (f32 *)tMid, -s.lo, -s.hi);
        func_L01_0040B1F0((s32)obj, s.c2, s.c3, 1, (s32)tFar, (s32)tMid, s.width);
        return;
    }
    farSq = far * far;
    if (farSq < d0 && farSq < d1) {
        func_L01_0040B138(s.col0, s.col0, tFar);
        func_L01_0040AF70(s.dir, s.p0, s.p1, (f32 *)tFar, s.lo, s.hi);
        func_L01_0040B300((s32)obj, s.c0, s.c1, 1, (s32)tFar, (s32)tFar, s.width);
        return;
    }
    t0 = (sqrt_asm(d0) - near) * (1.0f / (far - near));
    if (t0 > 1.0f) {
        t0 = 1.0f;
    } else if (t0 < 0.0f) {
        t0 = 0.0f;
    }
    t1 = (sqrt_asm(d1) - near) * (1.0f / (far - near));
    if (t1 > 1.0f) {
        t1 = 1.0f;
    } else if (t1 < 0.0f) {
        t1 = 0.0f;
    }
    c0 = func_0038DBD8(0, s.col0, t0);
    c1 = func_0038DBD8(0, s.col0, t1);
    func_L01_0040B138(c0, c1, tFar);
    func_L01_0040AF70(s.dir, s.p0, s.p1, (f32 *)tFar, s.lo, s.hi);
    func_L01_0040B300((s32)obj, s.c0, s.c1, 1, (s32)tFar, (s32)tFar, s.width);
    c0 = func_0038DBD8(s.col0, 0, t0);
    c1 = func_0038DBD8(s.col0, 0, t1);
    func_L01_0040B138(c0, c1, tNear);
    func_L01_0040AF70(s.dir, s.p0, s.p1, (f32 *)tNear, s.lo, s.hi);
    func_L01_0040B1F0((s32)obj, s.c0, s.c1, 1, (s32)tFar, (s32)tNear, s.width);
    c0 = func_0038DBD8(s.col1, 0, t0);
    c1 = func_0038DBD8(s.col1, 0, t1);
    func_L01_0040B138(c0, c1, tMid);
    func_L01_0040AF70(s.dir, s.p0, s.p1, (f32 *)tMid, s.lo, s.hi);
    func_L01_0040B1F0((s32)obj, s.c2, s.c3, 0, (s32)tFar, (s32)tMid, s.width);
    func_L01_0040AF70(s.dir, s.p0, s.p1, (f32 *)tMid, -s.lo, -s.hi);
    func_L01_0040B1F0((s32)obj, s.c2, s.c3, 1, (s32)tFar, (s32)tMid, s.width);
}

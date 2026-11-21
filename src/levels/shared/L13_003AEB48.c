#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* declared by functions of L13_003ADA98.c, which this file was cut from */
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L13_003AEB48(void *);
extern void func_L13_003AEBC8(void *);

/* localdecomp:start func_L13_003AEB48 */
extern f32 D_L13_001DE678;
__asm__(".extern D_L13_001DE678, 4");
extern f32 D_L13_001DE67C;
__asm__(".extern D_L13_001DE67C, 4");
extern f32 D_L13_001DE680;
__asm__(".extern D_L13_001DE680, 4");
extern void func_L13_003AF048(u8 *, f32, f32, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L13_003AEB48(void *arg) {
    u8 *obj = arg;
    func_L13_003AF048(*(u8 **)(obj + 0x68) + 0x150, D_L13_001DE678 * 0.020000001f, D_L13_001DE67C * 0.00040000002f, D_L13_001DE680 * 0.00040000002f);
    if (obj[0x43] != 2) {
        func_003C3A10(obj, 2, 0, 10);
    }
}
/* localdecomp:end func_L13_003AEB48 */

/* localdecomp:start func_L13_003AEBC8 */
extern f32 D_L13_001DE684;
__asm__(".extern D_L13_001DE684, 4");
extern f32 D_L13_001DE688;
__asm__(".extern D_L13_001DE688, 4");
extern f32 D_L13_001DE68C;
__asm__(".extern D_L13_001DE68C, 4");
extern void func_L13_003AF048(u8 *, f32, f32, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L13_003AEBC8(void *arg) {
    u8 *obj = arg;
    func_L13_003AF048(*(u8 **)(obj + 0x68) + 0x150, D_L13_001DE684 * 0.020000001f, D_L13_001DE688 * 0.00040000002f, D_L13_001DE68C * 0.00040000002f);
    if (obj[0x43] != 3) {
        func_003C3A10(obj, 3, 0, 8);
    }
}
/* localdecomp:end func_L13_003AEBC8 */

/* localdecomp:start func_L13_003AEC48 */
#include "vu0.h"
extern f32 D_L13_001DE6DC, D_L13_001DE6E0, D_L13_001DE6EC;
__asm__(".extern D_L13_001DE6DC, 4");
__asm__(".extern D_L13_001DE6E0, 4");
__asm__(".extern D_L13_001DE6EC, 4");
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);

void func_L13_003AEC48(u8 *obj) {
    f32 *o = (f32 *)obj;
    u8 *d = *(u8 **)(obj + 0x68);
    f32 k;

    func_L01_0044EAE0(obj, d + 0x3B0, d + 0x3B4, D_L13_001DE6DC, D_L13_001DE6E0 * 0.017453292f * 0.020000001f, -1.0f);
    qzero(d + 0x1F0);
    k = 1.0f - D_L13_001DE6EC;
    *(s32 *)(d + 0x204) = 0;
    o[0xF0 / 4] *= k;
    o[0xF4 / 4] *= k;
}
/* localdecomp:end func_L13_003AEC48 */

/* localdecomp:start func_L13_003AECE0 */
__asm__(".extern D_L13_001DE6DC, 4");
__asm__(".extern D_L13_001DE6E0, 4");
extern f32 D_L13_001DE6DC;
extern f32 D_L13_001DE6E0;
extern s32 func_L01_0045A748(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L13_003AEEB0(u8 *, u8 *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);

s32 func_L13_003AECE0(u8 *o) {
    u8 *p;
    s32 r;
    f32 a;
    u8 *q = o + 0xF8;

    p = *(u8 **)(o + 0x68);
    *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) - *(f32 *)(p + 0x3B4);
    r = func_L01_0045A748(o);
    a = func_0038DAB8(*(f32 *)(p + 0x3B0), D_L13_001DE6E0 * 0.017453292f * 0.020000001f);
    *(f32 *)(p + 0x3B0) = a;
    *(f32 *)(p + 0x3B4) = func_0038D0B0(a) * D_L13_001DE6DC;
    *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + *(f32 *)(p + 0x3B4);
    func_L13_003AEEB0(o, p + 0x1F0, *(f32 *)(p + 0x204));
    a = func_0038D160(*(f32 *)(p + 0x130) - *(f32 *)(o + 0x10), *(f32 *)(p + 0x134) - *(f32 *)(o + 0x14));
    func_L01_00448890(q, p + 0x204, 0, a, *(f32 *)(p + 0x164), *(f32 *)(p + 0x168), *(f32 *)(p + 0x16C));
    return r;
}
/* localdecomp:end func_L13_003AECE0 */

/* localdecomp:start func_L13_003AEDD8 */
extern s32 func_L01_0045BDE8(void *, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern void func_L13_003AEEB0(u8 *, u8 *, f32);
extern f32 D_L13_001DE6E0;
__asm__(".extern D_L13_001DE6E0, 4");
extern f32 D_L13_001DE6DC;
__asm__(".extern D_L13_001DE6DC, 4");

s32 func_L13_003AEDD8(u8 *obj, s32 arg1) {
    u8 *sub = *(u8 **)(obj + 0x68);
    s32 result;
    f32 a;

    *(f32 *)(obj + 0x18) -= *(f32 *)(sub + 0x3B4);
    result = func_L01_0045BDE8(obj, arg1);
    a = func_0038DAB8(*(f32 *)(sub + 0x3B0), D_L13_001DE6E0 * 0.017453292f * 0.020000001f);
    *(f32 *)(sub + 0x3B0) = a;
    *(f32 *)(sub + 0x3B4) = func_0038D0B0(a) * D_L13_001DE6DC;
    *(f32 *)(obj + 0x18) += *(f32 *)(sub + 0x3B4);
    func_L13_003AEEB0(obj, sub + 0x1F0, *(f32 *)(sub + 0x204));
    func_L01_0045BD10(obj, func_0038D160(*(f32 *)(sub + 0x130) - *(f32 *)(obj + 0x10), *(f32 *)(sub + 0x134) - *(f32 *)(obj + 0x14)));
    return result;
}
/* localdecomp:end func_L13_003AEDD8 */

/* localdecomp:start func_L13_003AEEB0 */
__asm__(".extern D_L13_001DE6E8, 4");
__asm__(".extern D_L13_001DE6EC, 4");
__asm__(".extern D_L13_001DE6E4, 4");
__asm__(".extern D_L13_001DE660, 4");
extern f32 D_L13_001DE6E8;
extern f32 D_L13_001DE6EC;
extern f32 D_L13_001DE6E4;
extern f32 D_L13_001DE660;
extern f32 func_0038CE68(void *, void *);

void func_L13_003AEEB0(u8 *self, u8 *a1, f32 f) {
    f32 g;
    f32 h;
    f32 t;
    f32 u;

    f32 q0 = *(f32 *)(self + 0xF0);
    g = -(D_L13_001DE6E4 * 0.017453292f);
    *(f32 *)(self + 0xF0) = q0 - f * D_L13_001DE6E8 * D_L13_001DE6EC;
    t = (func_0038CE68(a1, self + 0xD0) / (D_L13_001DE660 * 0.020000001f) < 1.0f)
            ? g * (func_0038CE68(a1, self + 0xD0) / (D_L13_001DE660 * 0.020000001f))
            : g;
    h = D_L13_001DE6E4 * 0.017453292f;
    *(f32 *)(self + 0xF0) = *(f32 *)(self + 0xF0) * (1.0f - D_L13_001DE6EC) + t * D_L13_001DE6EC;
    u = (func_0038CE68(a1, self + 0xC0) / (D_L13_001DE660 * 0.020000001f) < 1.0f)
            ? h * (func_0038CE68(a1, self + 0xC0) / (D_L13_001DE660 * 0.020000001f))
            : h;
    *(f32 *)(self + 0xF4) = *(f32 *)(self + 0xF4) * (1.0f - D_L13_001DE6EC) + u * D_L13_001DE6EC;
}
/* localdecomp:end func_L13_003AEEB0 */

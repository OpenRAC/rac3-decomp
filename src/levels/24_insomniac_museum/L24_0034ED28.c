#include "common.h"

/* localdecomp:start func_L24_0034ED28 */
#include "vu0.h"
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void func_0038D750(void *, s32, f32);
__asm__(".extern D_L24_001DD3D4, 4");
__asm__(".extern D_L24_001DD3D8, 4");
__asm__(".extern D_L24_001DD3DC, 4");
__asm__(".extern D_L24_001DD3E0, 4");
__asm__(".extern D_L24_001DD3E4, 4");
__asm__(".extern D_L24_001DD3F0, 4");
__asm__(".extern D_L24_001DD4B8, 4");
extern f32 D_L24_001DD3D4;
extern f32 D_L24_001DD3D8;
extern f32 D_L24_001DD3DC;
extern f32 D_L24_001DD3E0;
extern f32 D_L24_001DD3E4;
extern f32 D_L24_001DD3F0;
extern f32 D_L24_001DD4B8;
typedef struct {
    u8 p0[0x18];
    s32 x18;
    s32 x1C;
    u8 p20[8];
    f32 x28;
    u8 p2C[4];
    vu0_v4 x30;
} S_34ED28;
extern S_34ED28 D_L24_001E8F40;

static __inline__ vu0_q vadd1_ab_34ED28(void *d1, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d1) : "j"(qr));
    return qr;
}

static __inline__ vu0_q vadd1_ba_34ED28(void *d1, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d1) : "j"(qr));
    return qr;
}

s32 func_L24_0034ED28(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 t[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    f32 h;
    f32 k;
    f32 z;
    f32 w;
    s32 r = 0;

    *(vu0_q *)v = vadd1_ab_34ED28(obj + 0x10, obj + 0x10, s + 0x100);
    k = D_L24_001DD3D4;
    k = k + (D_L24_001DD3D8 - k) * *(f32 *)(s + 0x154);
    h = func_003C3D30(obj + 0x10, 0, obj, 3.0f) + k;
    func_0038CE20(s + 0x100, s + 0x100, *(f32 *)(s + 0x154));
    if (*(f32 *)(obj + 0x18) <= h) {
        if (*(f32 *)(s + 0x108) < 0.0f) {
            *(f32 *)(s + 0x108) = 0.0f;
        }
        r = 1;
        *(f32 *)(s + 0x108) = *(f32 *)(s + 0x108) + (h - *(f32 *)(obj + 0x18)) * (D_L24_001DD4B8 * 1.2f);
        *(f32 *)(obj + 0x18) = h;
    }
    z = D_L24_001DD3E4;
    w = D_L24_001DD3E0;
    *(f32 *)(s + 0x108) = *(f32 *)(s + 0x108) - D_L24_001DD3DC * 0.00040000002f;
    *(vu0_q *)v = *(vu0_q *)(obj + 0x10);
    v[2] = v[2] + z;
    if (func_L01_003FB640(v, 0, obj, w) != 0) {
        if (*(f32 *)(obj + 0x18) < D_L24_001E8F40.x28) {
            if (D_L24_001E8F40.x18 != 0 && D_L24_001E8F40.x1C < 0 && D_L24_001E8F40.x30.z > v[2]) {
                D_L24_001E8F40.x30.z = v[2];
            }
            D_L24_001E8F40.x30.z = D_L24_001E8F40.x30.z - D_L24_001DD3E4;
            vec_sub_ab(e, &D_L24_001E8F40.x30, obj + 0x10);
            *(vu0_q *)t = *(vu0_q *)e;
            *(vu0_q *)d = *(vu0_q *)e;
            func_L01_0040E6B8(d, d, (D_L24_001DD3F0 + D_L24_001DD3F0) * 0.020000001f);
            d[2] = 0.0f;
            *(vu0_q *)t = vadd1_ba_34ED28(s + 0x100, s + 0x100, d);
            *(vu0_q *)t = vadd1_ab_34ED28(obj + 0x10, obj + 0x10, d);
            if (*(f32 *)(obj + 0x18) <= h) {
                *(f32 *)(obj + 0x18) = h;
                r = 1;
            }
        }
    }
    func_0038D750(s + 0x90, 2, *(f32 *)(s + 0x140));
    func_0038D750(s + 0xD0, 1, *(f32 *)(s + 0x148));
    if (*(f32 *)(obj + 0x10) < 10.0f) *(f32 *)(obj + 0x10) = 10.0f;
    if (1013.0f < *(f32 *)(obj + 0x10)) *(f32 *)(obj + 0x10) = 1013.0f;
    if (*(f32 *)(obj + 0x14) < 10.0f) *(f32 *)(obj + 0x14) = 10.0f;
    if (1013.0f < *(f32 *)(obj + 0x14)) *(f32 *)(obj + 0x14) = 1013.0f;
    if (*(f32 *)(obj + 0x18) < 10.0f) *(f32 *)(obj + 0x18) = 10.0f;
    if (1013.0f < *(f32 *)(obj + 0x18)) *(f32 *)(obj + 0x18) = 1013.0f;
    return r;
}
/* localdecomp:end func_L24_0034ED28 */

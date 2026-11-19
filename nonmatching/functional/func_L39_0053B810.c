/* functional: high. Same operations as retail; vector zero/add scheduling and register allocation differ. */
#include "vu0.h"

extern s32 D_001DF698_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DF698_sda, 4");
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003C4D58(void *);
extern void func_L39_005FF198(void *, void *, void *);
extern void func_L01_0040E790(void *, void *, void *);

void func_L39_0053B810(void *pos, u8 *m, void *offset) {
    vu0_v4 b;
    vu0_v4 a;
    vu0_v4 c;
    u8 *p = *(u8 **)(m + 0x68);
    u8 *o = 0;
    u8 *v;
    s16 sign;
    u16 index = *(u16 *)(p + 0x7C);

    if (index < 8) {
        o = D_L39_0024CE20[(s16)index];
    }
    if (o == 0) {
        return;
    }
    a.x = 0.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    a.w = 0.0f;
    a.x = func_L39_005B4410(-1.0f, 1.0f);
    a.y = func_L39_005B4410(-1.0f, 1.0f);
    a.z = func_L39_005B4410(-1.0f, 1.0f);
    *(f32 *)(m + 0x2C) = *(f32 *)(m + 0x2C) / 0.649999976f;
    b = a;
    m[0x20] = 1;
    func_0038CF68(&b, &b, func_L39_005B4410(0.000199999995f, 0.00200000009f));
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(p)) : "m"(*(vu0_v4 *)(&b)), "m"(*(vu0_v4 *)(offset)) : "vf1", "vf2");
    if (*(void **)(o + 0x2CC) != 0 && func_003C4D58(*(void **)(o + 0x2CC)) != 0) {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(p)) : "m"(*(vu0_v4 *)(p)), "m"(*(vu0_v4 *)(o + 0x140)) : "vf1", "vf2");
    }
    *(s16 *)(p + 0x34) = 100;
    *(vu0_v4 *)(m + 0x10) = *(vu0_v4 *)pos;
    sign = 1;
    if (*(s16 *)(o + 0x2D8) != 0) {
        sign = -1;
    }
    *(s16 *)(p + 0x36) = sign;
    func_L39_005FF198(o, m + 0x10, p + 0x20);
    func_0038CF68(p + 0x20, p + 0x20, 0.00472000008f);
    a = *(vu0_v4 *)(*(u8 **)(o + 0x2524) + 0x10);
    a.z = ((f32 *)pos)[2];
    if (func_003D3CB0((f32 *)&a, (u8 *)pos, D_001DF698_sda, *(u8 **)(o + 0x2524), 0) != 0) {
        v = D_L39_0025F760;
        *(vu0_v4 *)(m + 0x10) = *(vu0_v4 *)v;
        func_0038CF68(&c, v + 0x20, 0.00388000021f);
        v += 0x20;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(m + 0x10)) : "m"(*(vu0_v4 *)(m + 0x10)), "m"(*(vu0_v4 *)(&c)) : "vf1", "vf2");
        func_L01_0040E790(p, p, v);
        func_0038CE20((f32 *)p, p, 0.600000024f);
    }
}

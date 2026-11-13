#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* localdecomp:start func_L39_00558DB8 */
typedef int Q_00558DB8 __attribute__((mode(TI)));
typedef struct V4_00558DB8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00558DB8;

__asm__(".extern D_L39_0024B30C, 4");
extern f32 D_L39_0024B30C;
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);

s32 func_L39_00558DB8(u8 *a0, u8 *a1, V4_00558DB8 *out) {
    if (func_0038CF38(a1 + 0x10, *(u8 **)(a0 + 0x2524) + 0x10) < D_L39_0024B30C) {
        V4_00558DB8 v;
        V4_00558DB8 d;
        Q_00558DB8 qa, qb, qr;
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(V4_00558DB8 *)(a1 + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(V4_00558DB8 *)(*(u8 **)(a0 + 0x2524) + 0x10)));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qr));
        v = d;
        out->x = -v.x;
        out->y = -v.y;
        out->z = 0.0f;
        func_0038CF68(out, out, 1.0f);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00558DB8 */

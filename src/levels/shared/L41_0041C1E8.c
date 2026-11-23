#include "common.h"

/* localdecomp:start func_L41_0041C1E8 */
#include "vu0.h"
typedef struct { u8 p0[0x18]; u8 *x18; u8 p1c[4]; vu0_q v20; } G_0041C1E8;
extern G_0041C1E8 D_L41_0025BAC0_0041C1E8;
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

u8 *func_L41_0041C1E8(u8 *obj) {
    u8 *e = func_L01_00447490(obj, -1, 0);
    if (e != 0) {
        if (e[0x29] >= 3) {
            if (*(s16 *)(*(u8 **)(e + 0x20) + 0xAA) == 0x108F) {
                vu0_v4 a;
                vu0_v4 b;
                vu0_q q1, q2, qr;
                qzero(&a);
                a.z = 0.25f;
                qzero(&b);
                b.z = -0.25f;
                __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(a));
                __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(vu0_v4 *)(*(u8 **)(e + 0x20) + 0x10)));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(q2), "j"(q1));
                __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qr));
                vec_add_ab(&b, &b, *(u8 **)(e + 0x20) + 0x10);
                if (func_003D3CB0(&a, &b, 1, *(void **)(e + 0x20), 0) != 0 && D_L41_0025BAC0_0041C1E8.x18 == obj) {
                    *(vu0_q *)e = D_L41_0025BAC0_0041C1E8.v20;
                } else {
                    qzero(e);
                }
            }
        } else {
            obj[0xA8] = 0xFF;
            e = 0;
        }
    }
    return e;
}
/* localdecomp:end func_L41_0041C1E8 */

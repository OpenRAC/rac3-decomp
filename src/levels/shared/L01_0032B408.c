#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L01_0032B408);

INCLUDE_ASM("asm/levels", func_L01_0032BCB0);

INCLUDE_ASM("asm/levels", func_L01_0032BDD8);

INCLUDE_ASM("asm/levels", func_L01_0032BE90);

/* localdecomp:start func_L01_0032BEF0 */
extern void func_L01_0044C638(void *, s32, void *, void *, void *, void *);
extern void func_003C3D30(void *, s32, s32, f32);
extern s32 D_001D545C;
extern s32 D_L01_001EAA18[];

void func_L01_0032BEF0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    func_L01_0044C638(a0, *(s32 *)(s + 0x70), a0 + 0x10, a0 + 0xF0, a0 + 0x10, a0 + 0xF0);
    if (D_001D545C == 7) {
        func_003C3D30(a0 + 0x10, 0, 0, 0.5f);
        if (D_L01_001EAA18[0] == 0) {
            *(s32 *)(s + 0x70) = 0;
        }
    }
}
/* localdecomp:end func_L01_0032BEF0 */

INCLUDE_ASM("asm/levels", func_L01_0032BF70);

/* localdecomp:start func_L01_0032C220 */
extern void *func_00382348(void *);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);

void func_L01_0032C220(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *t;
    u8 *m;
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40[3];
    vu0_q qa, qb, qr;
    f32 f;

    t = func_00382348(*(void **)(s + 0x68));
    func_L01_004C7D98(a0 + 0x10, &v10);
    *(vu0_q *)&v0 = *(vu0_q *)(*(u8 **)(s + 0x68) + 0x10);
    if (t != 0) {
        func_0038CE20(&v30, *(u8 **)(s + 0x68) + 0xE0, *(f32 *)(t + 0x10));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v0));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v30));
    } else {
        *(vu0_q *)&v0 = *(vu0_q *)(*(u8 **)(*(u8 **)(s + 0x68) + 0x24) + 0x30);
        f = *(f32 *)(*(u8 **)(s + 0x68) + 0x2C) * 0.0009765625f;
        func_0038CE20(&v0, &v0, f);
        v0.w = v0.w * f;
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v0));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(*(u8 **)(s + 0x68) + 0x10)));
    }
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(v0) : "j"(qr));
    m = *(u8 **)(s + 0x68);
    if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD || (*(u16 *)(m + 0x34) & 0x1000) == 0) {
        a0[0x20] = 3;
        *(s32 *)(s + 0x68) = 0;
    } else {
        s += 0x20;
        func_003C2F58(a0, 0, &v20);
        vec_sub_ab(&v30, &v0, &v20);
        func_0038CF68(s, &v30, 1.0f);
        func_L01_0040EE50(v40, a0 + 0xC0);
        func_0038D000(s, s, v40);
    }
}
/* localdecomp:end func_L01_0032C220 */

INCLUDE_ASM("asm/levels", func_L01_0032C390);

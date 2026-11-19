#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L01_0032B408);

/* localdecomp:start func_L01_0032BCB0 */
typedef int s128 __attribute__((mode(TI)));

extern f32 D_L01_001DCE30;
__asm__(".extern D_L01_001DCE30, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
typedef struct {
    u8 pad0[0x100];
    s32 w100[0x40];
} T_0032BCB0;
extern T_0032BCB0 D_L01_00276E60;
extern void func_L01_004C7D40(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_004CADE8(void *, void *);
extern void func_L01_0032CA80(void);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00444F38(void *, s32, s32, s32, s32);

void func_L01_0032BCB0(u8 *self) {
    f32 old[4] __attribute__((aligned(16)));
    u8 *s;

    *(s128 *)old = *(s128 *)(self + 0x10);
    s = *(u8 **)(self + 0x68);
    vec_add_ab(self + 0x10, self + 0x10, s);
    func_L01_004C7D40(self + 0x10, s, D_L01_001DCE30 * 0.00040000002f * 0.1f);
    if (func_003D3CB0(old, self + 0x10, 0x10, self, 0) != 0) {
        self[0x20] = 8;
        if (D_001D545C == 0x1C) {
            s[0x4E] = func_L01_004CADE8(&D_L01_00276E60, self);
            func_L01_0032CA80();
            if (D_L01_00276E60.w100[(s8)s[0x4E]] != 0) {
                self[0x20] = 2;
                func_003A52A0(1, 0, self);
                func_L01_00444F38(self, 1, 0, 0, 0);
            } else {
                self[0x20] = 6;
            }
        }
    }
}
/* localdecomp:end func_L01_0032BCB0 */

INCLUDE_ASM("asm/levels", func_L01_0032BDD8);

/* localdecomp:start func_L01_0032BE90 */
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003FB640(f32 *, s32, u8 *, f32);
extern s32 D_L01_001EAA1C_0032BE90[];

void func_L01_0032BE90(u8 *a0) {
    f32 v[4];

    func_003C2F58(a0, 0, v);
    if (func_L01_003FB640(v, 2, a0, 0.2f) && D_L01_001EAA1C_0032BE90[0] > 0) {
        a0[32] = 8;
    }
}
/* localdecomp:end func_L01_0032BE90 */

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

/* localdecomp:start func_L01_0032C390 */
typedef struct { u8 pad[0x15]; u8 index; } State_0032C390;
typedef struct { u8 pad[0x4C]; f32 speed, delay; u8 tail[0x9C]; } Row_0032C390;
extern State_0032C390 D_001425C0;
extern Row_0032C390 D_L01_002C5600[];
extern s32 D_L01_001DCE48;
__asm__(".extern D_L01_001DCE48, 4");
extern void func_L01_004CABD8(void *, void *, void *);
extern void func_L01_0032CAA0(void *, void *);
extern s32 func_003C4B50(void *);


void func_L01_0032C390(u8 *m) {
    vu0_v4 direction, target, delta, reference, forward;
    u8 *p = *(u8 **)(m + 0x68);
    u8 *desc;
    f32 scale;
    func_003C2F58(m, 1, &reference);
    func_L01_004C7D98(m + 0x10, &direction);
    if (*(f32 *)(p + 0x5C) == 0.0f && *(s32 *)(p + 0x50) && *(u8 **)(p + 0x68)) {
        desc = func_00382348(*(u8 **)(p + 0x68));
        target = *(vu0_v4 *)(*(u8 **)(p + 0x68) + 0x10);
        if (desc) {
            func_0038CE20(&forward, *(u8 **)(p + 0x68) + 0xE0, *(f32 *)(desc + 0x10));
            vec_add_ab(&target, &target, &forward);
        } else {
            target = *(vu0_v4 *)(*(u8 **)(*(u8 **)(p + 0x68) + 0x24) + 0x30);
            scale = *(f32 *)(*(u8 **)(p + 0x68) + 0x2C) * 0.0009765625f;
            func_0038CE20(&target, &target, scale);
            target.w *= scale;
            vec_add_ab(&target, *(u8 **)(p + 0x68) + 0x10, &target);
        }
        vec_sub_ab(&delta, &target, &reference);
        func_0038CF68(&delta, &delta, D_001425C0.index[D_L01_002C5600].speed * 0.020000001f);
        func_L01_004CABD8(&delta, &delta, &reference);
        func_L01_0032CAA0(m, &delta);
        func_003A52A0(0, 0, m);
        *(s32 *)(p + 0x40) = (D_L01_001DCE48 * 5 + 2) / 6;
        *(s32 *)(p + 0x44) = 5;
        if (!func_003C4B50(*(u8 **)(p + 0x68))) (*(u16 *)(p + 0x64))--;
        if (*(s16 *)(p + 0x64) <= 0) m[0x20] = 8;
        *(f32 *)(p + 0x5C) = 1.0f / D_L01_002C5600[D_001425C0.index].delay;
    }
}
/* localdecomp:end func_L01_0032C390 */

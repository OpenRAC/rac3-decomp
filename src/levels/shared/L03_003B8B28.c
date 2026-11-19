#include "common.h"

/* localdecomp:start func_L03_003B8B28 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x1A];
    s16 h1A;
    u8 pad1C[0x14];
} Hit_003B8B28;
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446748_003B8B28(void *, void *, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640_003B8B28(void *, s32, u8 *, f32);
extern void func_L03_003ADF38_003B8B28(void);
extern void func_L03_003ADF48_003B8B28(void);
extern void func_L03_003B8FA0_003B8B28(vu0_v4 *, s32, u32, u32);
extern s32 func_L01_004AAC98_003B8B28(s32, s32, s32, s32);
extern void func_L01_00446780_003B8B28(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_003C2880(void *);
extern void func_L03_003B8F10_003B8B28(u8 *);
extern u8 *D_L03_001E9218_003B8B28[];

void func_L03_003B8B28(u8 *self) {
    u8 *d = *(u8 **)(self + 0x68);
    vu0_v4 dir;
    vu0_v4 old;
    Hit_003B8B28 hit;
    u8 *e;
    s32 st;
    u8 *t;
    vu0_v4 q;

    func_003C2F58(*(void **)(d + 0x28), *(s32 *)(d + 0x2C), d + 0x10);
    func_003C2F58(*(void **)(d + 0x28), *(s32 *)(d + 0x2C) - 0x20, d);
    *(f32 *)(d + 0x24) += *(f32 *)(d + 0x20);
    old = *(vu0_v4 *)(self + 0x10);
    vec_sub_ba(&dir, d, d + 0x10);
    func_0038CF68(&dir, &dir, *(f32 *)(d + 0x24));
    vec_add_ab(self + 0x10, d + 0x10, &dir);
    func_L01_00446748_003B8B28(&hit, self, 1, 1.0f);
    hit.h1A = *(s16 *)(self + 0xAA);
    if (func_003D3CB0(&old, self + 0x10, 0, self, &hit) != 0 || func_L01_003FB640_003B8B28(self + 0x10, 0, self, 0.3f) != 0) {
        e = D_L03_001E9218_003B8B28[0];
        if (e != 0 && (*(s16 *)(e + 0xAA) == 0x1C04 || *(s16 *)(e + 0xAA) == 0x1C06)) {
            if (*(s16 *)(e + 0xAA) != 0x1C06) {
                if (*(s16 *)(e + 0xAA) == 0x1C04) {
                    st = *(s32 *)(*(u8 **)(e + 0x68) + 0x24);
                    if (st != 0 && st != 3 && st != 6) {
                        func_L03_003ADF48_003B8B28();
                        q = *(vu0_v4 *)(self + 0x10);
                        func_L03_003B8FA0_003B8B28(&q, 100, 0x88202020, 0x88208020);
                        func_L01_004AAC98_003B8B28(0xB, 0, *(s32 *)(self + 0xB8), 0x1AE0);
                    } else {
                        q = *(vu0_v4 *)(self + 0x10);
                        func_L03_003B8FA0_003B8B28(&q, 100, 0xDD0044FF, 0xFF0010FF);
                        func_L01_004AAC98_003B8B28(4, 0, *(s32 *)(self + 0xB8), 0x1AE0);
                    }
                }
                func_L01_00446780_003B8B28(self, self + 0x10, 0x10000, 0, 1, 0, 0.3f, 1.0f, 0.0f);
            } else {
                func_L03_003ADF38_003B8B28();
                q = *(vu0_v4 *)(self + 0x10);
                func_L03_003B8FA0_003B8B28(&q, 0x14, 0xDD0044FF, 0xFF0010FF);
                t = *(u8 **)(self + 0xB8);
                if (t != 0 && *(s16 *)(t + 0xAA) == 0x1AE0) {
                    func_L01_004AAC98_003B8B28(0xA, 0, (s32)t, 0x1AE0);
                }
            }
            func_003C2880(self);
            return;
        }
    }
    if (func_0038CF38(self + 0x10, d) <= *(f32 *)(d + 0x20) * 0.88f) {
        func_003C2880(self);
    } else {
        func_L03_003B8F10_003B8B28(self);
    }
}
/* localdecomp:end func_L03_003B8B28 */

/* localdecomp:start func_L03_003B8DF8 */
typedef int u128_3B8DF8 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L03_003B9130(u8 *, void *);
__asm__(".extern D_L03_001DEA88, 4");
extern s32 D_L03_001DEA88;
extern u8 D_L03_001E1E08[8];

u8 *func_L03_003B8DF8(u8 *a0, s32 a1, f32 a2) {
    u8 *m = func_003C24B0(0x1C16, 0x80);
    u8 *mv;
    u8 *pv;
    if (m != 0) {
        mv = *(u8 **)(m + 0x68);
        m[0x30] = 0xFF;
        *(u16 *)(m + 0x32) = 0x40;
        m[0x31] = 1;
        *(u8 **)(m + 0xB8) = a0;
        *(f32 *)(mv + 0x20) = a2 * 0.020000001f;
        *(s32 *)(mv + 0x24) = 0;
        *(s32 *)(mv + 0x2C) = a1;
        pv = *(u8 **)(a0 + 0x68);
        func_003C2F58(*(void **)pv, a1, mv + 0x10);
        func_003C2F58(*(void **)pv, a1 - 0x20, mv);
        *(s32 *)(mv + 0x28) = *(s32 *)pv;
        *(u128_3B8DF8 *)(m + 0x10) = *(u128_3B8DF8 *)(mv + 0x10);
    }
    if (D_L03_001DEA88 == 0) {
        D_L03_001DEA88 = 1;
        func_L03_0034B218(D_L03_001E1E08, 0x19, 0x11, 2.1f, 2, func_L03_003B9130);
    }
    return m;
}
/* localdecomp:end func_L03_003B8DF8 */

#include "common.h"

/* NTSC-U counterpart of func_L01_003F8208 (src/levels/shared/L01_003F79D8.c): 0.04 -> 0.0333333; 0.0028 -> 0.00194444 */
#include "vu0.h"
extern s32 func_L01_003F6060(u8 *self);
extern void func_00388830(void *a, void *b, f32 s);
extern void func_00388758(void *out, void *m, void *v);
extern void func_003BFC18(void *a, void *b, s32 c);
extern s32 func_0039FE80(s32 a, s32 b, u8 *c);

/* localdecomp:start func_L01_003F6060 */
#include "vu0.h"

typedef struct {
    f32 v[4];
} V4_003F5ED8_003F8208;

extern void func_L01_003F63A8_003F6060(u8 *a0);
extern s32 func_L01_003F68E8_003F6060(u8 *self);
extern void func_00388830(void *a, void *b, f32 s);
extern void func_00388758(void *out, void *m, void *v);
extern void func_L01_003F6CD0_003F6060(u8 *self, void *a, void *b);
extern void func_003BFC18(void *a, void *b, s32 c);
extern f32 func_00388730(f32 *, f32 *);
extern f32 func_00388770(f32 *);
extern void func_003BEBF8(f32 *, f32, f32);
extern void func_003BF778(u8 *a0, void *a1, f32 f12);
extern void func_00388F90(void *, void *, void *, f32);
extern s32 func_0039FE80(s32 a, s32 b, u8 *c);
extern s32 func_0039FF28(s32, s32, s32);
extern void func_L01_004A75E0_003F6060(s32 a, void *b);
extern void func_L01_0040C260_003F6060(void *, void *, void *);
extern u8 D_L01_001EAAC0_003F6060[];

s32 func_L01_003F6060(u8 *self) {
    V4_003F5ED8_003F8208 a;
    V4_003F5ED8_003F8208 b;
    V4_003F5ED8_003F8208 c;
    V4_003F5ED8_003F8208 d;
    f32 len;
    u8 *v;
    f32 dist;
    f32 half;
    s32 h;

    v = *(u8 **)(self + 104);
    func_L01_003F63A8_003F6060(self);
    if (func_L01_003F68E8_003F6060(self) != 0) {
        func_00388830(D_L01_001EAAC0_003F6060, D_L01_001EAAC0_003F6060, 1.0f);
        func_00388758(&a, D_L01_001EAAC0_003F6060, v);
        func_L01_003F6CD0_003F6060(self, v + 16, &a);
        func_003BFC18(self + 16, &b, 1);
        if (func_00388730(&b, D_L01_001EAAC0_003F6060) > 0.7f) {
            dist = func_00388730(v, D_L01_001EAAC0_003F6060);
            half = dist * 0.5f;
            if (fabs_asm(half) < 0.0333333351f) {
                half = 0.0f;
            }
            func_00388830(&c, D_L01_001EAAC0_003F6060, dist + half);
            vec_sub_ab(v, v, &c);
            if (half == 0.0f) {
                len = func_00388770(v);
                func_003BEBF8(&len, 0.0333333351f, 0.00194444449f);
                func_00388830(v, v, len);
                func_00388758(&d, v, D_L01_001EAAC0_003F6060);
                func_003BF778(&d, &d, (func_00388770(&d) * -0.5f) / *(f32 *)(v + 44));
                func_00388F90(v + 16, v + 16, &d, 0.1f);
            }
            if (fabs_asm(dist) >= 0.0333333351f) {
                if (v[94] != 255) {
                    h = func_0039FE80(v[94], 0, self);
                } else {
                    h = func_0039FF28(8, 0, (s32)self);
                }
                if (h != -1) {
                    func_L01_004A75E0_003F6060(h, v + 32);
                }
            }
        } else {
            func_L01_0040C260_003F6060(v, v, D_L01_001EAAC0_003F6060);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003F6060 */

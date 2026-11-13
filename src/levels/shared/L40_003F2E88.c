#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_003F2E88);

/* localdecomp:start func_L40_003F3828 */
#include "vu0.h"

typedef struct {
    f32 x, y;
} F2_003F3828;
typedef struct {
    u8 pad0[0x14];
    f32 f14;
    f32 f18;
    u8 pad1C[4];
    f32 f20;
    u8 pad24[0x30 - 0x24];
    s32 w30;
    f32 f34;
    s32 w38;
} S_003F3828;

extern s32 D_L40_00264E00 __attribute__((section(".data")));
extern vu0_v4 D_L40_00249F40;
extern vu0_v4 D_001DE050_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DE050_sda, 8");
extern f32 D_001DE074_sda;
extern F2_003F3828 D_L40_00249770[2] __attribute__((section(".sdata")));
extern F2_003F3828 D_L40_00246ED0[2] __attribute__((section(".sdata")));
extern f32 D_L40_00249780;
extern f32 D_L40_00249784;
extern f32 *D_L40_00243264;
extern s32 D_L40_0024112C;
extern f32 D_L40_0024119C;
extern f32 D_001DB7B0_sda[2] __attribute__((section(".sdata")));
__asm__(".extern D_001DB7B0_sda, 8");
extern F2_003F3828 D_001DB7C0_sda[2] __attribute__((section(".sdata")));
__asm__(".extern D_001DB7C0_sda, 8");
extern void func_L40_003F2E88();
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004048D0(void *, void *);
extern void func_L01_00404808(void *, void *);

void func_L40_003F3828(u8 *m) {
    S_003F3828 *s;
    vu0_v4 d;
    vu0_v4 v;
    f32 *a;
    f32 *b;
    s32 i;
    f32 t;

    s = *(S_003F3828 **)(m + 0x68);
    if (D_L40_00264E00 != s->w30) {
        return;
    }
    if (m[0x20] == 0) {
        m[0x20] = 1;
        m[0x30] = 0xFF;
        for (i = 0; i < 2; i++) {
            D_L40_00249770[i].x = 0.0f;
            D_L40_00249770[i].y = 0.0f;
        }
        D_001DE050_sda = D_L40_00249F40;
        D_001DE074_sda = s->f14;
        return;
    }
    t = s->f14;
    vec_sub_ab(&d, &D_L40_00249F40, &D_001DE050_sda);
    D_001DE050_sda = D_L40_00249F40;
    D_001DE074_sda = t;
    if (!(s->f20 < D_L40_00249F40.z)) {
        return;
    }
    b = &D_L40_00249770[0].y;
    a = &D_L40_00249770[0].x;
    for (i = 0; i < 2; i++) {
        func_0038CE20(&v, &d, (D_001DB7B0_sda[i] + D_001DB7B0_sda[i]) / (s->f18 * 5.0f));
        if (v.x > 1.0f || v.x < 1.0f) {
            v.x = v.x - (f32)(s32)v.x;
        }
        if (v.y > 1.0f || v.y < 1.0f) {
            v.y = v.y - (f32)(s32)v.y;
        }
        a[i * 2] += v.x;
        b[i * 2] += v.y;
        if (a[i * 2] > 1.0f) {
            a[i * 2] -= 1.0f;
        }
        if (a[i * 2] < -1.0f) {
            a[i * 2] += 1.0f;
        }
        if (b[i * 2] > 1.0f) {
            b[i * 2] -= 1.0f;
        }
        if (b[i * 2] < -1.0f) {
            b[i * 2] += 1.0f;
        }
    }
    t = func_0038D0B0((f32)(D_L40_0024112C % 360) * 0.017444445f - 3.14f);
    D_L40_00243264 = &D_L40_00249780;
    D_L40_00249780 = D_L40_00249784 + t * s->f34;
    for (i = 0; i < 2; i++) {
        D_L40_00249770[i].x += D_001DB7C0_sda[i].x * D_L40_0024119C;
        if (D_L40_00249770[i].x > 1.0f) {
            D_L40_00249770[i].x -= 1.0f;
        }
        if (D_L40_00249770[i].x < -1.0f) {
            D_L40_00249770[i].x += 1.0f;
        }
        D_L40_00249770[i].y += D_L40_00246ED0[i].y * D_L40_0024119C;
        if (D_L40_00249770[i].y > 1.0f) {
            D_L40_00249770[i].y -= 1.0f;
        }
        if (D_L40_00249770[i].y < -1.0f) {
            D_L40_00249770[i].y += 1.0f;
        }
    }
    if (s->w38 != 0) {
        func_L01_004048D0(func_L40_003F2E88, m);
    } else {
        func_L01_00404808(func_L40_003F2E88, m);
    }
}
/* localdecomp:end func_L40_003F3828 */

INCLUDE_ASM("asm/levels", func_L40_003F3C60);

INCLUDE_ASM("asm/levels", func_L40_003F4080);

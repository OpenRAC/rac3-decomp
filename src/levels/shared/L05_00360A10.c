#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L05_00360A10);

INCLUDE_ASM("asm/levels", func_L05_00360AE0);

/* localdecomp:start func_L05_00361498 */
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L05_00468EA8(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001DD8A0, 8");
extern u8 D_L05_001DD8A0[8];
__asm__(".extern D_L05_001DD8E0, 8");
extern u8 D_L05_001DD8E0[8];
__asm__(".extern D_L05_001DD8B8, 4");
extern s32 D_L05_001DD8B8;
__asm__(".extern D_L05_001DD8BC, 4");
extern f32 D_L05_001DD8BC;
__asm__(".extern D_L05_001DD8C0, 4");
extern f32 D_L05_001DD8C0;
__asm__(".extern D_L05_001DD8C4, 4");
extern f32 D_L05_001DD8C4;
__asm__(".extern D_L05_001DD8C8, 4");
extern f32 D_L05_001DD8C8;
__asm__(".extern D_L05_001DD8CC, 4");
extern f32 D_L05_001DD8CC;
__asm__(".extern D_L05_001DD8D0, 4");
extern f32 D_L05_001DD8D0;

void func_L05_00361498(u8 *a0) {
    vu0_v4 r;
    vu0_v4 p;
    vu0_v4 d;
    s32 i;

    *(vu0_q *)&r = 0;
    func_0038D000(&p, D_L05_001DD8E0, a0 + 0xC0);
    vec_add_ba(&p, a0 + 0x10, &p);
    vec_sub_ab(&d, &D_L05_001E2680, &p);
    func_0038CF68(&d, &d, D_L05_001DD8D0);
    vec_add_ab(&p, &p, &d);
    for (i = 0; i < D_L05_001DD8B8; i++) {
        func_003C4C18(&p, D_L05_001DD8BC);
        r.x = func_003824E0(D_L05_001DD8C0, D_L05_001DD8C4) * 0.020000001f;
        r.y = func_003824E0(D_L05_001DD8C0, D_L05_001DD8C4) * 0.020000001f;
        r.z = func_003824E0(D_L05_001DD8C8, D_L05_001DD8CC) * 0.020000001f;
        func_L05_00468EA8(&p, &r, D_L05_001DD8A0, func_00382468(2), func_00382468(3) - 1);
    }
}
/* localdecomp:end func_L05_00361498 */

/* localdecomp:start func_L05_003615D8 */
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L05_00468EA8(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001DD910, 8");
extern u8 D_L05_001DD910[8];
__asm__(".extern D_L05_001DD950, 8");
extern u8 D_L05_001DD950[8];
__asm__(".extern D_L05_001DD928, 4");
extern s32 D_L05_001DD928;
__asm__(".extern D_L05_001DD92C, 4");
extern f32 D_L05_001DD92C;
__asm__(".extern D_L05_001DD930, 4");
extern f32 D_L05_001DD930;
__asm__(".extern D_L05_001DD934, 4");
extern f32 D_L05_001DD934;
__asm__(".extern D_L05_001DD938, 4");
extern f32 D_L05_001DD938;
__asm__(".extern D_L05_001DD93C, 4");
extern f32 D_L05_001DD93C;
__asm__(".extern D_L05_001DD940, 4");
extern f32 D_L05_001DD940;

void func_L05_003615D8(u8 *a0) {
    vu0_v4 r;
    vu0_v4 p;
    vu0_v4 d;
    s32 i;

    *(vu0_q *)&r = 0;
    func_0038D000(&p, D_L05_001DD950, a0 + 0xC0);
    vec_add_ba(&p, a0 + 0x10, &p);
    vec_sub_ab(&d, &D_L05_001E2680, &p);
    func_0038CF68(&d, &d, D_L05_001DD940);
    vec_add_ab(&p, &p, &d);
    for (i = 0; i < D_L05_001DD928; i++) {
        func_003C4C18(&p, D_L05_001DD92C);
        r.x = func_003824E0(D_L05_001DD930, D_L05_001DD934) * 0.020000001f;
        r.y = func_003824E0(D_L05_001DD930, D_L05_001DD934) * 0.020000001f;
        r.z = func_003824E0(D_L05_001DD938, D_L05_001DD93C) * 0.020000001f;
        func_L05_00468EA8(&p, &r, D_L05_001DD910, func_00382468(2), func_00382468(3) - 1);
    }
}
/* localdecomp:end func_L05_003615D8 */

/* localdecomp:start func_L05_00361718 */
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C5458(void *, s32, f32, f32);
extern vu0_v4 D_L05_001E2680;
extern u8 D_L05_001DD970[8];
__asm__(".extern D_L05_001DD970, 8");
extern f32 D_L05_001DD980;
__asm__(".extern D_L05_001DD980, 4");
extern s32 D_L05_001DD988;
__asm__(".extern D_L05_001DD988, 4");
extern s32 D_L05_001DD984;
__asm__(".extern D_L05_001DD984, 4");
extern f32 D_L05_001DD964;
__asm__(".extern D_L05_001DD964, 4");
extern f32 D_L05_001DD960;
__asm__(".extern D_L05_001DD960, 4");

void func_L05_00361718(u8 *a0) {
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 n;
    f32 dot;
    func_0038D000(&p, D_L05_001DD970, a0 + 0xC0);
    vec_add_ba(&p, a0 + 0x10, &p);
    vec_sub_ab(&d, &D_L05_001E2680, &p);
    func_0038CF68(&d, &d, 1.0f);
    func_0038CE20(&n, a0 + 0xE0, -1.0f);
    dot = func_0038CE68(&d, &n);
    if (D_L05_001DD980 < dot) {
        dot = dot * dot;
        func_003C5458(&p, func_0038DBD8(D_L05_001DD988, D_L05_001DD984, dot), D_L05_001DD964, D_L05_001DD960);
    }
}
/* localdecomp:end func_L05_00361718 */

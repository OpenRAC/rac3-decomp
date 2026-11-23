#include "common.h"

/* localdecomp:start func_L20_003FF448 */
#include "vu0.h"

/* follows func_L05_00361498 (level 5, the same particle loop) */
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L05_00468EA8(void *, void *, void *, s32, s32);
extern vu0_v4 D_L20_001E2E00;
__asm__(".extern D_L20_001DF698, 8");
extern u8 D_L20_001DF698[8];
__asm__(".extern D_L20_001DF6D0, 8");
extern u8 D_L20_001DF6D0[8];
__asm__(".extern D_L20_001DF6B0, 4");
extern s32 D_L20_001DF6B0;
__asm__(".extern D_L20_001DF6B4, 4");
extern f32 D_L20_001DF6B4;
__asm__(".extern D_L20_001DF6B8, 4");
extern f32 D_L20_001DF6B8;
__asm__(".extern D_L20_001DF6BC, 4");
extern f32 D_L20_001DF6BC;
__asm__(".extern D_L20_001DF6C0, 4");
extern f32 D_L20_001DF6C0;
__asm__(".extern D_L20_001DF6C4, 4");
extern f32 D_L20_001DF6C4;
__asm__(".extern D_L20_001DF6C8, 4");
extern f32 D_L20_001DF6C8;

void func_L20_003FF448(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 r;
    vu0_v4 p;
    u8 m[0x40] __attribute__((aligned(16)));
    vu0_v4 o;
    vu0_v4 d;
    s32 i;
    s32 j;

    *(vu0_q *)&r = 0;
    for (i = 0; i < 2; i++) {
        func_003C2F58(*(void **)(s + 0x3EC), 2, &p);
        func_003C2EC0(*(void **)(s + 0x3EC), 2, m);
        func_0038D028(&o, D_L20_001DF6D0 + i * 16, m);
        vec_add_ab(&p, &p, &o);
        vec_sub_ba(&d, &D_L20_001E2E00, &p);
        func_0038CF68(&d, &d, D_L20_001DF6C8);
        vec_add_ab(&p, &p, &d);
        for (j = 0; j < D_L20_001DF6B0; j++) {
            func_003C4C18(&p, D_L20_001DF6B4);
            r.x = func_003824E0(D_L20_001DF6B8, D_L20_001DF6BC) * 0.020000001f;
            r.y = func_003824E0(D_L20_001DF6B8, D_L20_001DF6BC) * 0.020000001f;
            r.z = func_003824E0(D_L20_001DF6C0, D_L20_001DF6C4) * 0.020000001f;
            func_L05_00468EA8(&p, &r, D_L20_001DF698, func_00382468(2), func_00382468(3) - 1);
        }
    }
}
/* localdecomp:end func_L20_003FF448 */

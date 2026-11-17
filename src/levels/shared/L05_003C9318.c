#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003C9318 */
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L05_00468EA8(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001DED68, 8");
extern u8 D_L05_001DED68[8];
__asm__(".extern D_L05_001DED80, 4");
extern s32 D_L05_001DED80;
__asm__(".extern D_L05_001DED84, 4");
extern f32 D_L05_001DED84;
__asm__(".extern D_L05_001DED88, 4");
extern f32 D_L05_001DED88;
__asm__(".extern D_L05_001DED8C, 4");
extern f32 D_L05_001DED8C;
__asm__(".extern D_L05_001DED90, 4");
extern f32 D_L05_001DED90;
__asm__(".extern D_L05_001DED94, 4");
extern f32 D_L05_001DED94;
__asm__(".extern D_L05_001DED98, 4");
extern f32 D_L05_001DED98;
__asm__(".extern D_L05_001DED9C, 4");
extern f32 D_L05_001DED9C;

void func_L05_003C9318(vu0_v4 *a0) {
    vu0_v4 r;
    vu0_v4 p;
    vu0_v4 d;
    s32 i;

    *(vu0_q *)&r = 0;
    *(vu0_q *)&p = *(vu0_q *)a0;
    p.w = 0.0f;
    p.z += D_L05_001DED98;
    vec_sub_ab(&d, &D_L05_001E2680, &p);
    d.z = 0.0f;
    func_0038CF68(&d, &d, D_L05_001DED9C);
    vec_add_ab(&p, &p, &d);
    for (i = 0; i < D_L05_001DED80; i++) {
        func_003C4C18(&p, D_L05_001DED84);
        r.x = func_003824E0(D_L05_001DED88, D_L05_001DED8C) * 0.020000001f;
        r.y = func_003824E0(D_L05_001DED88, D_L05_001DED8C) * 0.020000001f;
        r.z = func_003824E0(D_L05_001DED90, D_L05_001DED94) * 0.020000001f;
        func_L05_00468EA8(&p, &r, D_L05_001DED68, func_00382468(2), 1);
    }
}
/* localdecomp:end func_L05_003C9318 */

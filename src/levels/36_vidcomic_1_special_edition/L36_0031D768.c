#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L36_0031D768 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern s32 func_0038CAD0(u8 *);
extern void func_L36_0031D878(u8 *);
extern u8 D_L36_001E9540[];
void func_L36_0031D768(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 old;
    vu0_v4 w;
    u8 *pos;
    u8 *g;
    if (s != 0) {
        pos = a0 + 0x10;
        {
            vu0_q qp, qd, qs;
            __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)pos));
            old = *(vu0_v4 *)pos;
            __asm__("vmr32.xyzw %0, $vf0" : "=j"(qd));
            __asm__("lqc2 %0, %1" : "=j"(qs) : "m"(*(vu0_v4 *)s));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qs) : "j"(qs), "j"(qp));
            __asm__("sqc2 %1, %0" : "=m"(w) : "j"(qd));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)pos) : "j"(qs));
        }
        func_0038CE20(&w, &w, 0.0044f);
        vec_sub_ab(s, s, &w);
        if (func_003D3CB0(&old, pos, 0x10, a0, 0) != 0) {
            g = D_L36_001E9540;
            if (*(s32 *)(g + 0x18) != 0 || *(s32 *)(g + 0x1C) > 0) {
                *(vu0_q *)pos = *(vu0_q *)(g + 0x20);
                *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + 1.0f;
                func_L36_0031D878(a0);
            }
        } else if (func_0038CAD0(s + 0x18) != 0) {
            func_L36_0031D878(a0);
        }
    }
}
/* localdecomp:end func_L36_0031D768 */

/* localdecomp:start func_L36_0031D878 */
__asm__(".extern D_L36_001DC7C8, 4");
__asm__(".extern D_L36_001DC7CC, 4");
__asm__(".extern D_L36_001DC7D0, 4");
__asm__(".extern D_L36_001DC7D4, 4");
__asm__(".extern D_L36_001DC7D8, 4");
__asm__(".extern D_L36_001DC7DC, 4");
__asm__(".extern D_L36_001DC7E0, 2");
__asm__(".extern D_L36_001DC7E4, 2");
__asm__(".extern D_L36_001DC7E8, 2");
__asm__(".extern D_L36_001DC7EC, 2");
__asm__(".extern D_L36_001DC7F0, 2");
__asm__(".extern D_L36_001DC7C0, 4");
__asm__(".extern D_L36_001DC7BC, 4");
__asm__(".extern D_L36_001DC7B8, 4");
extern f32 D_L36_001DC7C8;
extern s32 D_L36_001DC7CC;
extern s32 D_L36_001DC7D0;
extern s32 D_L36_001DC7D4;
extern s32 D_L36_001DC7D8;
extern s32 D_L36_001DC7DC;
extern s16 D_L36_001DC7E0;
extern s16 D_L36_001DC7E4;
extern s16 D_L36_001DC7E8;
extern s16 D_L36_001DC7EC;
extern s16 D_L36_001DC7F0;
extern f32 D_L36_001DC7C0;
extern f32 D_L36_001DC7BC;
extern f32 D_L36_001DC7B8;
extern u8 D_001A4C60[];
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, u8 *, s32, void *, f32);
extern s32 func_003D4D00(u8 *, s32, u8 *, void *, f32);
extern void func_003C2880(u8 *);
extern s32 func_L01_003303B8(f32, f32, f32, f32, u8 *, s32, s32, s32, s32, s32, s32, s32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_L36_0031D878(u8 *a0) {
    u8 obj[0x30];
    vu0_v4 v;
    func_L01_003303B8(D_L36_001DC7C8, 0.0f, 0.0f, 0.0f, 
                      a0 + 0x10, D_L36_001DC7CC, D_L36_001DC7D0, D_L36_001DC7D4, D_L36_001DC7D8, D_L36_001DC7DC, D_L36_001DC7E0, D_L36_001DC7E4,
                      D_L36_001DC7E8, D_L36_001DC7EC, D_L36_001DC7F0, 0, 1, 0, 0, 0,
                      0x804020, 0x806040, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F804020, 0x28802020, 0x602010, 0);
    vec_sub_ab(&v, D_001A4C60, a0 + 0x10);
    func_0038CF68(&v, &v, D_L36_001DC7C0);
    func_L01_00446760(obj, a0, 0x10001, &v, D_L36_001DC7BC);
    func_003D4D00(a0 + 0x10, 0x10001, a0, obj, D_L36_001DC7B8);
    func_003C2880(a0);
}
/* localdecomp:end func_L36_0031D878 */

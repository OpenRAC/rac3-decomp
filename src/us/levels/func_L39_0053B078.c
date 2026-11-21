#include "common.h"

/* NTSC-U counterpart of func_L39_0053B810 (src/levels/shared/L39_0053B810.c): 0.0002 -> 0.000166667; 0.002 -> 0.00166667; 100 -> 120; 0.00472 -> 0.00327778; 0.00388 -> 0.00269444 */
extern f32 func_L39_005B2510(f32, f32);
extern u8 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
extern u8 D_L39_0025F860[];
extern s32 func_003CE740(f32 *, u8 *, s32, u8 *, s32);
extern void func_003886E8(f32 *, void *, f32);

/* localdecomp:start func_L39_0053B078 */
#include "vu0.h"
extern u8 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CF20, 32");
extern u8 D_L39_0025F860[];
__asm__(".extern D_L39_0024AEB8_0053B078, 4");
extern s32 D_L39_0024AEB8_0053B078;
extern s32 func_003CE740(f32 *, u8 *, s32, u8 *, s32);
extern void func_003886E8(f32 *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003BF7E8(s32);
extern void func_L39_005FC9F8(u8 *, u8 *, f32 *);
extern f32 func_L39_005B2510(f32, f32);
extern void func_L01_0040C260(f32 *, f32 *, f32 *);

void func_L39_0053B078(u8 *a0, u8 *m, u8 *a2) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *obj = 0;
    vu0_v4 d;
    vu0_v4 r;
    vu0_v4 w;

    if (*(u16 *)(v + 0x7C) < 8) {
        obj = D_L39_0024CF20[*(s16 *)(v + 0x7C)];
    }
    if (obj == 0) {
        return;
    }
    *(vu0_q *)&r = 0;
    r.x = func_L39_005B2510(-1.0f, 1.0f);
    r.y = func_L39_005B2510(-1.0f, 1.0f);
    r.z = func_L39_005B2510(-1.0f, 1.0f);
    *(f32 *)(m + 0x2C) /= 0.65f;
    d = r;
    m[0x20] = 1;
    func_00388830(&d, &d, func_L39_005B2510(0.000166666665f, 0.00166666682f));
    vec_add_ba(v, &d, a2);
    if (*(s32 *)(obj + 0x2CC) != 0 && func_003BF7E8(*(s32 *)(obj + 0x2CC)) != 0) {
        vec_add_ab(v, v, obj + 0x140);
    }
    *(s16 *)(v + 0x34) = 120;
    *(vu0_q *)(m + 0x10) = *(vu0_q *)a0;
    *(s16 *)(v + 0x36) = (obj != 0 && *(s16 *)(obj + 0x2D8) != 0) ? -1 : 1;
    func_L39_005FC9F8(obj, m + 0x10, (f32 *)(v + 0x20));
    func_00388830(v + 0x20, v + 0x20, 0.00327777793f);
    *(vu0_q *)&r = *(vu0_q *)(*(u8 **)(obj + 0x2524) + 0x10);
    r.z = *(f32 *)(a0 + 8);
    if (func_003CE740(&r.x, a0, D_L39_0024AEB8_0053B078, *(u8 **)(obj + 0x2524), 0) != 0) {
        *(vu0_q *)(m + 0x10) = *(vu0_q *)D_L39_0025F860;
        func_00388830(&w, D_L39_0025F860 + 0x20, 0.0026944445f);
        vec_add_ab(m + 0x10, m + 0x10, &w);
        func_L01_0040C260((f32 *)v, (f32 *)v, (f32 *)(D_L39_0025F860 + 0x20));
        func_003886E8((f32 *)v, v, 0.6f);
    }
}
/* localdecomp:end func_L39_0053B078 */

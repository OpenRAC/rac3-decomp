#include "common.h"

/* declared by functions of L39_00537998.c, which this file was cut from */
extern f32 func_L39_005B4410(f32, f32);
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
extern u8 D_L39_0025F760[];
extern s32 func_003D3CB0(f32 *, u8 *, s32, u8 *, s32);
extern void func_0038CE20(f32 *, void *, f32);

/* localdecomp:start func_L39_0053B810 */
#include "vu0.h"
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CE20, 32");
extern u8 D_L39_0025F760[];
__asm__(".extern D_L39_0024ADA8, 4");
extern s32 D_L39_0024ADA8;
extern s32 func_003D3CB0(f32 *, u8 *, s32, u8 *, s32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003C4D58(s32);
extern void func_L39_005FF198(u8 *, u8 *, f32 *);
extern f32 func_L39_005B4410(f32, f32);
extern void func_L01_0040E790(f32 *, f32 *, f32 *);

void func_L39_0053B810(u8 *a0, u8 *m, u8 *a2) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *obj = 0;
    vu0_v4 d;
    vu0_v4 r;
    vu0_v4 w;

    if (*(u16 *)(v + 0x7C) < 8) {
        obj = D_L39_0024CE20[*(s16 *)(v + 0x7C)];
    }
    if (obj == 0) {
        return;
    }
    *(vu0_q *)&r = 0;
    r.x = func_L39_005B4410(-1.0f, 1.0f);
    r.y = func_L39_005B4410(-1.0f, 1.0f);
    r.z = func_L39_005B4410(-1.0f, 1.0f);
    *(f32 *)(m + 0x2C) /= 0.65f;
    d = r;
    m[0x20] = 1;
    func_0038CF68(&d, &d, func_L39_005B4410(0.000200000009f, 0.002f));
    vec_add_ba(v, &d, a2);
    if (*(s32 *)(obj + 0x2CC) != 0 && func_003C4D58(*(s32 *)(obj + 0x2CC)) != 0) {
        vec_add_ab(v, v, obj + 0x140);
    }
    *(s16 *)(v + 0x34) = 100;
    *(vu0_q *)(m + 0x10) = *(vu0_q *)a0;
    *(s16 *)(v + 0x36) = (obj != 0 && *(s16 *)(obj + 0x2D8) != 0) ? -1 : 1;
    func_L39_005FF198(obj, m + 0x10, (f32 *)(v + 0x20));
    func_0038CF68(v + 0x20, v + 0x20, 0.00472f);
    *(vu0_q *)&r = *(vu0_q *)(*(u8 **)(obj + 0x2524) + 0x10);
    r.z = *(f32 *)(a0 + 8);
    if (func_003D3CB0(&r.x, a0, D_L39_0024ADA8, *(u8 **)(obj + 0x2524), 0) != 0) {
        *(vu0_q *)(m + 0x10) = *(vu0_q *)D_L39_0025F760;
        func_0038CF68(&w, D_L39_0025F760 + 0x20, 0.00388000021f);
        vec_add_ab(m + 0x10, m + 0x10, &w);
        func_L01_0040E790((f32 *)v, (f32 *)v, (f32 *)(D_L39_0025F760 + 0x20));
        func_0038CE20((f32 *)v, v, 0.6f);
    }
}
/* localdecomp:end func_L39_0053B810 */

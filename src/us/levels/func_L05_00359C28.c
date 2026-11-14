#include "common.h"

/* NTSC-U counterpart of func_L05_0035AD60 (src/levels/shared/L05_00355DD8.c): 0.2 -> 0.166667 */
#include "vu0.h"
extern s32 func_L05_00359AD0(u8 *);
extern void func_00388830(void *, void *, f32);
extern void func_003BDA38(s32, s32, void *);

/* localdecomp:start func_L05_00359C28 */
extern s32 func_0037E1D8(s32);
extern s32 func_L05_00359AD0(u8 *);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_003BDA38(s32, s32, void *);
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L05_003C6778(void *, void *, void *, void *, f32);
extern void func_0039FE80(s32, s32, void *);

void func_L05_00359C28(u8 *arg0)
{
    u8 *v;
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 t;
    vu0_v4 r;
    vu0_v4 m[4];

    v = *(u8 **)(arg0 + 0x68);
    t = *(vu0_v4 *)(v + 0x220);
    if (func_0037E1D8(4) == 0 && func_L05_00359AD0(arg0) == 0) {
        func_L01_00440A88(&r, 0.8f, 1.2f);
        if (func_0037E1D8(2)) {
            r.x = -r.x;
        }
        if (func_0037E1D8(2)) {
            r.y = -r.y;
        }
        vec_add_ab(&t, &t, &r);
    }
    func_003BDA38(*(s32 *)(v + 0x3EC), 0, &p);
    func_003BD9A0(*(void **)(v + 0x3EC), 0, m);
    func_00388830(&a, m, 0.1f);
    vec_add_ba(&p, &p, &a);
    vec_sub_ab(&d, &t, &p);
    func_00388830(&d, &d, 0.166666672f);
    func_L05_003C6778(arg0, *(void **)(v + 0x230), &p, &d, v[0x44]);
    func_0039FE80(3, 0, arg0);
}
/* localdecomp:end func_L05_00359C28 */

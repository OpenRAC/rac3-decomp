#include "common.h"

/* localdecomp:start func_L39_00596E58 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_003EB350(void *, void *);
extern void func_L01_003EB3C0(void *, void *);

void func_L39_00596E58(u8 *o, void *x) {
    f32 v[4];
    f32 t[4];
    *(u128_t *)t = 0;
    t[1] = *(f32 *)(o + 0x60);
    t[2] = *(f32 *)(o + 0x40);
    *(u128_t *)v = *(u128_t *)t;
    v[1] = func_0038DAB8(v[1], *(f32 *)(o + 0xD4));
    v[2] = func_0038DAB8(v[2], *(f32 *)(o + 0xD8));
    func_L01_003EB350(x, o + 0x30);
    func_L01_003EB3C0(x, v);
}
/* localdecomp:end func_L39_00596E58 */

/* localdecomp:start func_L39_00596EE0 */
extern void func_00133100(void), func_001393E8(s32, s32, s32, s32);
extern s32 D_001A5810[];
extern s32 D_002413A0;

/* from rac4-decomp's func_00458670 */
void func_L39_00596EE0(void)
{
    s32 mode;
    func_00133100();
    mode = D_001A5810[0];
    if (mode)
        D_002413A0 = 0;
    if (D_002413A0)
        func_001393E8(0, 0, 80, 1);
    else
        func_001393E8(0, 1, mode ? 3 : 2, 0);
}
/* localdecomp:end func_L39_00596EE0 */

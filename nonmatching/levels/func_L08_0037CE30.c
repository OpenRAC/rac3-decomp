/* NTSC-U draft (2026-11-14, Claude worker): C of func_L08_0037B8B8, the NTSC-U twin of func_L08_0037CE30, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 @ps2as" (src/levels/08_aquatos/L08_0037CD98.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L08_0037B8B8 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct V_0037B8B8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0037B8B8;

extern u8 **D_L08_0021EBA0;

extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E208(s32, s32);
extern void func_003888C8(void *, void *, void *);
extern u8 *func_L01_00468DC0(void *, void *, u32, s32, s32, s32, s32, s32, f32);

void func_L08_0037B8B8(u8 *o) {
    V_0037B8B8 a;
    V_0037B8B8 b;
    u8 *p;
    u8 *q;
    f32 ang;
    f32 s;
    f32 sz;
    s32 life;

    p = *(u8 **)(o + 0x68);
    if (func_0037E1D8(*(s32 *)(p + 0x20)) != 0) {
        return;
    }
    *(u128_t *)&b = 0;
    b.z = func_0037E250(*(f32 *)p, *(f32 *)(p + 4)) * 0.016666668f;
    func_003888C8(&b, &b, o + 0xC0);
    ang = func_0037E2A8();
    s = func_0037E250(*(f32 *)(p + 0x18), *(f32 *)(p + 0x1C));
    a.x = func_00388960(ang) * s;
    a.y = func_00388978(ang) * s;
    a.z = 0.0f;
    func_003888C8(&a, &a, o + 0xC0);
    vec_add_ba(&a, &a, o + 0x10);
    life = func_0037E208(*(s32 *)(p + 0x10), *(s32 *)(p + 0x14));
    sz = func_0037E250(*(f32 *)(p + 8), *(f32 *)(p + 0xC));
    q = func_L01_00468DC0(&a, &b, 0x4F808080, life, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0, sz);
    if (q != 0) {
        q[2] = **D_L08_0021EBA0;
        q[9] = ((*(s32 *)(p + 0x28) >> 5) << 4) + 4;
    }
}
/* localdecomp:end func_L08_0037B8B8 */

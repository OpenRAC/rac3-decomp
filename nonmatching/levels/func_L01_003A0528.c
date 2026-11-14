/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0039EF18, the NTSC-U twin of func_L01_003A0528, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0039E1B0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0039EF18 */
typedef struct V_0039EF18 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0039EF18;

extern void func_L01_004C41E8(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_003D4768(void *, void *, s32, s32, s32);

void func_L01_0039EF18(u8 *o) {
    V_0039EF18 v;
    V_0039EF18 c;
    V_0039EF18 a;
    V_0039EF18 b;
    V_0039EF18 e;
    V_0039EF18 d;
    u8 *p;
    u8 *r;
    f32 z;
    f32 ang;
    f32 el;
    f32 spd;

    p = *(u8 **)(o + 0x68);
    func_L01_004C41E8(o + 0x10, &a);
    z = 0.0f;
    b.x = a.z;
    b.y = a.z;
    b.z = -(a.x + a.y);
    func_00388830(&v, &b, 1.0f);
    func_00388758(&c, &v, &a);
    a.w = z;
    c.w = z;
    v.w = z;
    spd = func_0037E250(160.0f, 200.0f);
    ang = func_00389380(*(f32 *)(o + 0xF8), spd * 0.017453292f);
    el = func_0037E250(0.17453292f, 0.87266463f);
    spd = func_0037E250(2.0f, 5.0f);
    func_0037E4B8(&e, spd * 0.016666668f, ang, el);
    e.w = z;
    func_003888C8(&e, &e, &v);
    *(s32 *)(p + 0xA0) = func_0037E208(0x3C, 0x78);
    func_L01_004C41E8(o + 0x10, &d);
    func_00388830(&d, &d, 0.2f);
    vec_add_ba(&d, o + 0x10, &d);
    r = func_L01_003D4768(&d, &e, 0, 0, 0);
    if (r != 0) {
        *(s32 *)(r + 0xB8) = *(s32 *)(o + 0xB8);
    }
}
/* localdecomp:end func_L01_0039EF18 */

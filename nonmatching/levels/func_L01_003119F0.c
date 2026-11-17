/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00311700, the NTSC-U twin of func_L01_003119F0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as (no -mno-split-addresses) + divs row 1" (src/levels/shared/L01_00311430.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_311700;

extern V4_311700 D_L01_001E2AC0;
extern f32 func_00388770(void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E208(s32, s32);
extern s32 func_0013D3E0(void);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0040C188(void *, void *, f32);
extern void func_L01_002FB638(void *, void *, s32, s32, s32, s32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);

/* localdecomp:start func_L01_00311700 */
void func_L01_00311700(u8 *obj, f32 *pos) {
    V4_311700 d;
    V4_311700 w;
    V4_311700 v;
    f32 len;
    f32 a;
    f32 b;
    s32 i;
    s32 flag;

    vec_sub_ab(&d, &D_L01_001E2AC0, pos);
    len = func_00388770(&d);
    v = (V4_311700){0.0f, 0.0f, 0.0f, 0.0f};
    v.x = func_0037E250(-1.0f, 1.0f);
    v.y = func_0037E250(-1.0f, 1.0f);
    v.z = func_0037E250(-1.0f, 1.0f);
    w = v;
    d.z = d.z + len * 0.5f;
    func_00388830(&w, &w, len / 5.0f * 0.016666668f);
    func_00388830(&d, &d, (len + len) * 0.016666668f);
    vec_add_ab(&w, &w, &d);
    func_L01_0040C188(&w, &w, 0.16666667f);
    func_L01_002FB638(pos, &w, func_0037E208(60, 90), 0, 0, 0);
    for (i = 8; i >= 0; i--) {
        a = func_0037E250(0.2617994f, 1.3089969f);
        b = func_0037E2A8();
        func_0037E4B8(&v, func_0037E250(8.0f, 12.0f) * 0.016666668f, b, a);
        v.z = v.z + 0.0500000045f;
        if (func_0013D3E0() % 3 == 0) {
            flag = 1;
        } else {
            flag = 0;
        }
        func_003888C8(&v, &v, obj + 0xC0);
        func_L01_002FB638(pos, &v, func_0037E208(60, 90), flag, 0, 0);
    }
}
/* localdecomp:end func_L01_00311700 */

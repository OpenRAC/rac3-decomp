/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_0054BAE8, the NTSC-U twin of func_L39_0054C400, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2" (src/levels/shared/L39_0054A250.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L39_0054BAE8 */
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[2];
    f32 f24;
    u8 pad28[0x58];
} Row_54BAE8;

extern Row_54BAE8 D_L39_0049C950[];
extern s32 func_L39_00646268(s32, s32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B2498(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 D_L39_00242AB0;
__asm__(".extern D_L39_00242AB0, 16");

void func_L39_0054BAE8(u8 *o, vu0_v4 *pos, s32 mode) {
    vu0_v4 p;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    u8 *st;
    Row_54BAE8 *row;
    vu0_v4 *pp;
    f32 dur;
    f32 fn;
    f32 sz;
    s32 n;
    s32 c;
    s32 id;

    id = 4;
    p = *pos;
    pp = &p;
    st = *(u8 **)(o + 0x68);
    if (func_L39_00646268(*(s32 *)(st + 0x58), id) != 0) {
        row = &D_L39_0049C950[D_L39_0049C950[id].b21];
    } else {
        row = &D_L39_0049C950[id];
    }
    dur = row->f24 * 0.016666668f;
    n = (s32)(dur / 0.1f);
    switch (mode) {
    case 2:
        n = (s32)((f32)n * 0.6f);
        break;
    case 3:
        n = (s32)((f32)n * 0.3f);
        break;
    }
    fn = (f32)n;
    v10 = *pp;
    vec_sub_ab(&v20, o + 0x10, pp);
    func_00388830(&v20, &v20, dur / fn);
    func_003886E8(&v40, &v20, 1.0f / fn);
    if (n > 0) {
        do {
            sz = func_L39_005B2510(0.1f, 0.3f) * *(f32 *)(st + 0x5C);
            n--;
            c = func_L39_005B2498(0xFF);
            func_L01_00440A88(&v30, 0.0f, 0.1f);
            vec_add_ab(&v30, &v30, &v10);
            func_L01_0046C468(&v30, &D_L39_00242AB0, 0xF, 0x80FFFFFF, c, 0x20, 0, sz * 2.1e+05f, sz * 0.2f * 2.1e+05f, 0.0f, 0);
            vec_add_ab(&v10, &v10, &v40);
        } while (n != 0);
    }
}
/* localdecomp:end func_L39_0054BAE8 */

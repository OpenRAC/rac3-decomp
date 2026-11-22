#include "common.h"

/* NTSC-U counterpart of PAL func_L07_003B0738. */
/* localdecomp:start func_L07_003AEEB8 */
#include "vu0.h"

typedef struct V4_3B0738 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_3B0738;
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_0037E208(s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_004708F8(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);

void func_L07_003AEEB8(u8 *obj) {
    V4_3B0738 w;
    V4_3B0738 q;
    u8 *vars;
    f32 t;
    f32 scale;
    f32 ang;
    s32 n;
    s32 i;
    s32 s;

    vars = *(u8 **)(obj + 0x68);
    t = 1.0f - (f32)*(s32 *)(vars + 0xA0) / 60.0f;
    n = (s32)(t * 4.0f + 2.0f);
    scale = (t * 0.8f + 0.2f) * 12.0f;
    for (i = 0; i < n; i++) {
        {
            ang = func_00389380(*(f32 *)(obj + 0xF8), func_0037E250(-0.7853982f, 0.7853982f));
            func_0037E4B8(&w, scale, ang, func_0037E250(-0.7853982f, 0.7853982f));
            func_003BDA38(obj, 1, &q);
            if (*(s32 *)(vars + 0xA0) < func_0037E208(0x14, 0x28)) {
                s = *(s32 *)(vars + 0xA0);
            } else {
                s = func_0037E208(0x14, 0x28);
            }
            vec_add_ab(&q, &q, &w);
            func_003886E8(&w, &w, -1.0f / (f32)s);
            func_L01_004708F8(&q, &w, s, 0.15f, 0.75f, 1.2f, 1.0f, 0x8020FF40, 0x40A0FFA0, 0, 0);
        }
    }
}
/* localdecomp:end func_L07_003AEEB8 */

#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L10_003C64B0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C64B0;
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D328(void *, void *);
extern s32 func_00382498(s32, s32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern void func_003C7C38(u8 *);

u8 *func_L10_003C64B0(u8 *src, s32 cls, s32 a2) {
    V4_3C64B0 m[2];
    V4_3C64B0 t[2];
    u8 *o;
    f32 a;

    o = func_003C24B0(cls, 0x80);
    if (o != 0) {
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        *(f32 *)(o + 0x2C) = *(f32 *)(o + 0x2C) * (*(f32 *)(src + 0x2C) / *(f32 *)(*(u8 **)(src + 0x24) + 0x24));
        *(V4_3C64B0 *)(o + 0x10) = *(V4_3C64B0 *)(src + 0x10);
        func_0038D328(m, src + 0xF0);
        a = (f32)func_00382498(0, 7) * 3.1415927f * 0.25f;
        func_0038D890(&m[0], &m[0], t, a);
        func_0038D890(&m[1], &m[1], t, a);
        func_003C48A8(m, o + 0xF0);
        *(unsigned long *)(o + 0x38) = *(unsigned long *)(src + 0x38);
        o[0x30] = a2;
        *(s16 *)(o + 0x34) = 0;
        func_003C7C38(o);
        return o;
    }
    return 0;
}
/* localdecomp:end func_L10_003C64B0 */

/* localdecomp:start func_L10_003C65D8 */
typedef int u128_t_3C65D8 __attribute__((mode(TI)));
__asm__(".extern D_L10_001DE8A4, 4");
extern f32 D_L10_001DE8A4;
extern u8 D_L10_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L10_003C65D8(u8 *m) {
    V4_3C64B0 p;
    V4_3C64B0 a;

    if (func_L01_00447490(m, -1, 0) != 0) {
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 0xF, D_L10_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L10_003C64B0(m, 0x1EB2, 0);
        *(u128_t_3C65D8 *)&a = 0;
        a.z = D_L10_001DE8A4 * 29.976019f * *(f32 *)(m + 0x2C);
        p = a;
        func_0038D000(&p, &p, m + 0xC0);
        vec_add_ab(&p, &p, m + 0x10);
        func_L01_003303B8(&p, 0, 0, 0, 0, 2, 5, 0, *(f32 *)(m + 0x2C) * 10.491607f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_00451E78(m, 1, 0.0f);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L10_003C65D8 */

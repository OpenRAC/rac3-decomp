#include "common.h"

/* localdecomp:start func_L08_003BE9C0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BE9C0;
__asm__(".extern D_L08_001DE818, 4");
__asm__(".extern D_L08_001DE81C, 4");
__asm__(".extern D_L08_001DE820, 4");
__asm__(".extern D_L08_001DE824, 4");
extern s32 D_L08_001DE818;
extern s32 D_L08_001DE81C;
extern f32 D_L08_001DE820;
extern f32 D_L08_001DE824;
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *out, void *v, f32 r);
extern s32 func_00382498(s32, s32);
extern void *func_L01_00470668(void *, void *, s32, f32);

void func_L08_003BE9C0(V4_003BE9C0 *at, V4_003BE9C0 *offset, f32 scale) {
    V4_003BE9C0 pos;
    V4_003BE9C0 v;
    f32 r;
    s32 i;
    s32 n;

    pos = *at;
    for (i = 0; i < D_L08_001DE818; i++) {
        r = D_L08_001DE820 * scale;
        func_00382580(&v, r * 0.5f, r);
        vec_add_ab(&v, &v, offset);
        func_0038CF68(&v, &v, func_003824E0(D_L08_001DE824 * 0.5f, D_L08_001DE824) * 0.020000001f);
        n = (func_00382498((f32)D_L08_001DE81C * 0.5f, D_L08_001DE81C) * 5 + 2) / 6;
        func_L01_00470668(&pos, &v, n, func_003824E0(10.0f, 15.0f) * 0.00040000002f);
    }
}
/* localdecomp:end func_L08_003BE9C0 */

/* localdecomp:start func_L08_003BEB20 */
#include "vu0.h"

extern u8 D_L08_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L08_003BE9C0(V4_003BE9C0 *, V4_003BE9C0 *, f32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_003C2880(void *);

void func_L08_003BEB20(u8 *m) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    f32 f;

    if (func_L01_00447490(m, -1, 0) == 0) {
        return;
    }
    func_L01_00451FE0(m, 0x3F, D_L08_001D66B0, 1.0f, 3.0f, 1.0f, 3.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    func_003A52A0(0, 0, m);
    f = *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
    func_L01_00451E78(m, 1, 0.0f);
    *(vu0_q *)&a = 0;
    *(vu0_q *)&b = 0;
    a.x = -0.46f;
    b.x = 8.06f;
    func_0038D000(&a, &a, m + 0xC0);
    func_0038D000(&b, &b, m + 0xC0);
    func_0038CE20(&c, &a, f);
    vec_add_ab(&a, &c, m + 0x10);
    func_0038CE20(&c, &b, f);
    vec_add_ab(&b, &c, m + 0x10);
    func_0038CE20(&c, m + 0xE0, -1.0f);
    func_L08_003BE9C0((V4_003BE9C0 *)&a, (V4_003BE9C0 *)&c, f);
    func_L08_003BE9C0((V4_003BE9C0 *)&b, (V4_003BE9C0 *)&c, f);
    func_L01_00452460(m, 0x1CF3, 0);
    func_003C2880(m);
}
/* localdecomp:end func_L08_003BEB20 */

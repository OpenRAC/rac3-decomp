/* PAL near miss (k6 a6, 2026-11-26): func_L01_003AE1A0 (1048 B), written from retail. 30 diff with its
 * file's line: everything matches except the three func_L01_00304018 colour arguments. Retail reads each
 * colour word once (lw), takes bytes 1-3 from the register (sra/andi, srl) and byte 0 with its own lbu
 * from $gp; this C (u8 prototype, D >> 8 ...) gets byte 0 from the lw and narrows bytes 1-2 to lbu at
 * D + 1 / D + 2. A local copy, an inline helper taking the colour, s32/u32 and & 0xFF forms all narrow
 * the same way. */
#include "common.h"
/* localdecomp:start func_L01_003AE1A0 */
#include "vu0.h"
__asm__(".extern D_L01_001DE4BC, 4");
__asm__(".extern D_L01_001DE4C0, 4");
__asm__(".extern D_L01_001DE4C4, 4");
__asm__(".extern D_L01_001DE4C8, 4");
__asm__(".extern D_L01_001DE4CC, 4");
__asm__(".extern D_L01_001DE4D0, 4");
__asm__(".extern D_L01_001DE4D4, 4");
extern s32 D_L01_001DE4BC;
extern f32 D_L01_001DE4C0;
extern s32 D_L01_001DE4C4;
extern s32 D_L01_001DE4C8;
extern s32 D_L01_001DE4CC;
extern s32 D_L01_001DE4D0;
extern s32 D_L01_001DE4D4;

extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void *func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_L01_00464690(u8 *, vu0_v4 *, s32, s32, f32, s32, s32, s32, s32, f32);
extern void func_L01_00304018(u8 *, u8 *, vu0_v4 *, s32, u8, u8, u8, u8, f32);
void func_L01_003AE1A0(u8 *m) {
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;
    u8 *vars;
    s32 i;
    s32 n;
    f32 d;
    f32 extra;
    f32 s;
    s32 c;

    *(vu0_q *)&v0 = 0;
    v0.z = 0.040000003f;
    vars = *(u8 **)(m + 0x68);
    for (i = 0; i < D_L01_001DE4BC; i++) {
        *(vu0_q *)&v2 = 0;
        v2.x = func_003824E0(-1.0f, 1.0f);
        v2.y = func_003824E0(-1.0f, 1.0f);
        v1 = v2;
        func_0038CF68(&v1, &v1, func_003824E0(6.5f, 10.0f) * 0.020000001f);
        v1.z = D_L01_001DE4C0 * 0.020000001f;
        func_L01_002FB660(m + 0x10, &v1, func_00382498(50, 75), 1, 4, 0);
    }
    vec_sub_ba(&v1, &D_L01_001E2A40, m + 0x10);
    d = func_0038CEA8(&v1);
    *(vu0_q *)&v3 = 0;
    v3.x = func_003824E0(-1.0f, 1.0f);
    v3.y = func_003824E0(-1.0f, 1.0f);
    v3.z = func_003824E0(-1.0f, 1.0f);
    v1.z += d * 0.5f;
    v2 = v3;
    func_0038CF68(&v2, &v2, d * 0.2f * 0.020000001f);
    func_0038CF68(&v1, &v1, (d + d) * 0.020000001f);
    vec_add_ab(&v2, &v2, &v1);
    func_L01_0040E6B8(&v2, &v2, 0.20000002f);
    func_L01_002FB660(m + 0x10, &v2, func_00382498(50, 75), 1, 4, 0);
    if (d < 6.0f) {
        n = (s32)d + 1;
    } else {
        n = 4;
    }
    extra = 0.0f;
    if (d < 7.0f) {
        extra = 7.0f - d;
    }
    if (n > 0) {
        i = n;
        do {
            s32 a, b;
            s = func_003824E0(8.0f, 10.0f) * 0.020000001f - extra * 0.020000001f;
            a = func_00382498(12, 17);
            b = func_00382498(21, 25);
            func_L01_00464690(m + 0x10, &v0, D_L01_001DE4D0, D_L01_001DE4D4, 400000.0f, a, b, 0, 0, s);
        } while (--i != 0);
    }
    if (9.0f < d) {
        func_L01_00304018(m, m + 0x10, &v0, 0x14, D_L01_001DE4C8, D_L01_001DE4C8 >> 8, D_L01_001DE4C8 >> 16, D_L01_001DE4C8 >> 24, 3.0f);
    }
    func_L01_00304018(m, m + 0x10, &v0, 0x11, D_L01_001DE4C4, D_L01_001DE4C4 >> 8, D_L01_001DE4C4 >> 16, D_L01_001DE4C4 >> 24, 3.0f);
    func_L01_00304018(m, m + 0x10, &v0, 0x18, D_L01_001DE4CC, D_L01_001DE4CC >> 8, D_L01_001DE4CC >> 16, D_L01_001DE4CC >> 24, 2.0f);
    *(s32 *)vars = 0;
}
/* localdecomp:end func_L01_003AE1A0 */

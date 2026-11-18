/* PAL near miss (Sonnet worker b10-u1): 5 diff with `-mvu0-use-vf0-vf2` and `--as ps2as`; the file's flags would need both (and its other blocks re-checked).
 * Only difference: retail stores the copy of the position (sqc2 $vf1, 0x60($sp)) right after the add.s, before `addiu $a3, $sp, 0x50`; this C schedules it after the argument setup.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L32_003A1E58 */
extern u8 D_1A4C60[];
extern u8 *D_L32_001DFF00;
extern f32 D_L32_001DE6AC;
__asm__(".extern D_L32_001DFF00, 16");
__asm__(".extern D_L32_001DE6AC, 4");
extern s32 func_00382380(void *, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L30_0034CE78(u8 *);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);

void func_L32_003A1E58(void *arg0) {
    u8 *v = *(u8 **)((u8 *)arg0 + 0x68);
    vu0_v4 best;
    vu0_v4 t10;
    vu0_v4 t20;
    vu0_v4 t30;
    vu0_v4 t40;
    vu0_v4 t50;
    vu0_v4 t60;
    f32 d0;
    f32 d1;
    s32 *p;
    s32 i;
    s32 j;

    p = (s32 *)(v + 0xA0);
    j = 0;
    d0 = 0.0f;
    d1 = d0;
    best = *(vu0_v4 *)((u8 *)((s32)(*p << 7) + (s32)D_L32_001DFF00) + 0x30);
    for (i = 0; i < 8; i++) {
        if (*p != -1) {
            if (*(s32 *)(v + j + 0xC0) != -1) {
                if (func_00382380(D_1A4C60, *(s32 *)(v + j + 0xC0), 0)) {
                    if (func_003D3CB0((u8 *)arg0 + 0x10, D_L32_001DFF00 + (*p << 7) + 0x30, 2, arg0, 0) == 0) {
                        t30 = *(vu0_v4 *)D_1A4C60;
                        t30.z += func_L30_0034CE78(*(u8 **)(D_1A4C60 + 0x2540));
                        vec_copy(&t60, (u8 *)arg0 + 0x10);
                        vec_sub_ba(&t10, (u8 *)((s32)(*p << 7) + (s32)D_L32_001DFF00) + 0x30, (u8 *)arg0 + 0x10);
                        vec_sub_ab(&t20, &t30, &t60);
                        func_L02_003BA9F8(&t20, &t10, &t40, &t50);
                        if (D_L32_001DE6AC <= d0) {
                            if (D_L32_001DE6AC <= func_0038CEA8(&t50)) {
                                if (d1 < func_0038CF00(D_1A4C60, D_L32_001DFF00 + (*p << 7) + 0x30)) goto take;
                            }
                        }
                        if (d0 < D_L32_001DE6AC && d0 < func_0038CEA8(&t50)) {
take:
                            best = *(vu0_v4 *)((u8 *)((s32)(*p << 7) + (s32)D_L32_001DFF00) + 0x30);
                            d0 = func_0038CEA8(&t50);
                            d1 = func_0038CF00(D_1A4C60, D_L32_001DFF00 + (*p << 7) + 0x30);
                        }
                    }
                }
            }
        }
        p++;
        j += 4;
    }
    *(vu0_v4 *)(v + 0x1C0) = best;
}
/* localdecomp:end func_L32_003A1E58 */

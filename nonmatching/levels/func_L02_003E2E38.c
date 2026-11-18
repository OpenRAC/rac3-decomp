/* PAL port of func_L02_003E2E38 (from the NTSC-U draft of the same function): 4 words differ with the file's line changed to
 * `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as` (the file holds only this function; the vec_add_ab helper
 * needs the vu0 flag) and the divs row `func_L02_003E2E38 2 2` in config/levels/divs_nops.txt.
 * PAL differs from the NTSC-U code in: k = 0.00040000002f, the 50 Hz rescale of both counts ((r * 10.0f * 5.0f + 2.0f) / 6.0f,
 * (r * 40.0f * 5.0f + 2.0f) / 6.0f), the last float argument 0.0020000001f.
 * Left: in the func_L01_004713C8 call retail computes `srl $t1; and $a3` before `addiu $a1; move $a2` (the draft's 4 words);
 * tried: argument locals, fl as the flags argument, c0 << 8 >> 8, swapping the two branches (29 diffs): no change or worse.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_003E2E38 */

typedef int u128_t __attribute__((mode(TI)));

extern s32 D_L02_001D673C;
extern void func_L01_00443B88(void *, f32, f32);
extern void func_L02_00428520(void *, void *, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);

void func_L02_003E2E38(u8 *self, u8 *pos, u8 *vel, s32 count, u8 mode, s32 flag, f32 a, f32 b, f32 c, f32 d, f32 e) {
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    f32 r;
    f32 r2;
    s32 n1;
    s32 n2;
    s32 c0;
    s32 c1;
    s32 i;
    f32 k = d * 0.00040000002f;
    s32 fl = 0x1003C;

    for (i = 0; i < count; i++) {
        if (flag == 0) {
            func_L01_00443B88(&v10, 0.0f, a);
            vec_add_ab(&v10, &v10, pos);
            func_L02_00428520(self, &v10, v10.x, v10.y, v10.z);
        } else {
            *(u128_t *)&v10 = *(u128_t *)pos;
        }
        func_L01_00443B88(&v20, 0.0f, b);
        vec_add_ab(&v20, &v20, vel);
        func_0038D000(&v20, &v20, self + 0xC0);
        r = e * func_003824E0(0.5f, 1.5f);
        n2 = (s32)((r * 10.0f * 5.0f + 2.0f) / 6.0f);
        n1 = (s32)((r * 40.0f * 5.0f + 2.0f) / 6.0f);
        r2 = func_003824E0(0.1f, 0.4f);
        qzero(&v30);
        v20.w = c * r2;
        v30.z = -k * (f32)(n2 + n1 + n2);
        vec_add_ab(&v30, &v30, &v20);
        switch (mode) {
        case 1:
            c0 = func_0038DBD8(func_003824E0(0.0f, 1.0f), 0x80102040, 0x801010A0);
            c1 = func_0038DBD8(func_003824E0(0.0f, 1.0f), 0x00102040, 0x001010A0);
            break;
        case 3:
            c0 = func_0038DBD8(func_003824E0(0.0f, 1.0f), 0x80201608, 0x80402510);
            c1 = func_0038DBD8(func_003824E0(0.0f, 1.0f), 0x00201608, 0x00402510);
            break;
        case 2:
            c0 = func_0038DBD8(func_003824E0(0.0f, 1.0f), 0x80104010, 0x8020A020);
            c1 = func_0038DBD8(func_003824E0(0.0f, 1.0f), 0x00104010, 0x0020A020);
            break;
        case 0:
        default:
            c0 = func_0038DBD8(func_003824E0(0.0f, 1.0f), 0x80004080, 0x80408080);
            c1 = func_0038DBD8(func_003824E0(0.0f, 1.0f), 0x00004080, 0x00408080);
            break;
        }
        if (D_L02_001D673C == 0) {
            func_L01_00463378(&v10, &v20, &v30, c0, c1, n2, n1, n2, fl);
        } else {
            func_L01_004713C8(&v10, &v20, n2, c0 & 0xFFFFFF, 0, (u32)c0 >> 24, (u32)c1 >> 24, 0x1003C, 210000.0f, 0.0f, 0.0020000001f);
        }
    }
}
/* localdecomp:end func_L02_003E2E38 */

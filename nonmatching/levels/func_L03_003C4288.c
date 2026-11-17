/* func_L03_003C4288: 157 diff with the file's flags. Logic, call sequence, constants and VU0 helpers match; retail's frame is 0xA0 (7 saved s-regs) while this one hoists the lui of the byte read of D_L03_001DF4C0 and the constant 255 into s7/s5 (frame 0xB0), and retail loads that word with lui/lw before the loop but with $gp inside it. Tried: literal 0.02f vs a local, ternary for the 255-v select, a carried t reloaded at loop end (worse). Sibling func_L03_003C4288/003C2448 are the same code with $gp offsets +0xA0. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003C4288 */
extern s32 D_L03_001DED78;
extern s32 D_L03_001DED74;
extern s32 D_L03_001DED7C;
extern s32 D_L03_001DED88;
extern s32 D_L03_001DED8C;
extern s32 D_L03_001DED98;
extern s32 D_L03_001DED9C;
extern f32 D_L03_001DED64;
extern f32 D_L03_001DED68;
extern f32 D_L03_001DED6C;
extern f32 D_L03_001DED70;
extern f32 D_L03_001DED80;
extern f32 D_L03_001DED84;
extern f32 D_L03_001DED90;
extern f32 D_L03_001DED94;
extern s32 D_L03_001DF4C0;
extern u8 D_L03_001DF4C0_003C4288[];
extern s32 D_L03_001DEDA0;
__asm__(".extern D_L03_001DED78, 4");
__asm__(".extern D_L03_001DED74, 4");
__asm__(".extern D_L03_001DED7C, 4");
__asm__(".extern D_L03_001DED88, 4");
__asm__(".extern D_L03_001DED8C, 4");
__asm__(".extern D_L03_001DED98, 4");
__asm__(".extern D_L03_001DED9C, 4");
__asm__(".extern D_L03_001DED64, 4");
__asm__(".extern D_L03_001DED68, 4");
__asm__(".extern D_L03_001DED6C, 4");
__asm__(".extern D_L03_001DED70, 4");
__asm__(".extern D_L03_001DED80, 4");
__asm__(".extern D_L03_001DED84, 4");
__asm__(".extern D_L03_001DED90, 4");
__asm__(".extern D_L03_001DED94, 4");
__asm__(".extern D_L03_001DF4C0, 4");
__asm__(".extern D_L03_001DEDA0, 4");
__asm__(".extern D_L03_001DF4C0_003C4288, 16");
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_L01_0046C470(void *, void *, s32, s32, s32, f32, s32, s32, s32);
extern void func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);

typedef struct { u8 pad0[0x10]; vu0_v4 v10; u8 pad20[4]; u8 *p24; u8 pad28[4]; f32 f2C; } A_003C4288;

void func_L03_003C4288(void *arg) {
    A_003C4288 *a = arg;
    vu0_v4 v0, v1, v2, v3, v4;
    s32 i, off;
    func_0038D000(&v0, &D_L03_001DEDA0, (u8 *)a + 0xC0);
    vec_add_ab(&v0, &v0, &a->v10);
    if (func_00382468(4) == 0) {
        func_L01_00443B88(&v1, D_L03_001DED64 * 0.020000001f, D_L03_001DED68 * 0.020000001f);
        func_L01_0046C470(&v0, &v1, D_L03_001DED78, D_L03_001DED74, func_00382468(255) & 0xFF, D_L03_001DED80, 0, 0x40, 0);
        i = 2;
        do {
            func_L01_00443B88(&v2, D_L03_001DED6C * 0.020000001f, D_L03_001DED70 * 0.020000001f);
            vec_add_ab(&v1, &v1, &v2);
            func_L01_0046C470(&v0, &v1, D_L03_001DED7C, D_L03_001DED74, func_00382468(255) & 0xFF, D_L03_001DED84, 0, 0x40, 0);
        } while (--i >= 0);
    }
    vec_sub_ab(&v3, &D_L03_001E2440, &v0);
    func_0038CF68(&v3, &v3, -0.3f);
    func_0038CF68(&v4, &v3, 0.1f);
    vec_add_ab(&v3, &v3, &v0);
    off = 0;
    for (i = 0; i < 4; i++) {
        s32 c, v;
        f32 t = (f32)(212 - (((D_L03_001DF4C0 + off) & 0xFF) * 5 + 2) / 6) / 212.0f;
        c = func_0038DBD8(D_L03_001DED88, D_L03_001DED8C, fabs_asm(0.5f - t));
        v = D_L03_001DF4C0_003C4288[0];
        if (i & 2) v *= 2;
        if (i & 1) v = 255 - v;
        func_L01_0046C2E8(&v3, c, v & 0xFF, D_L03_001DED9C, D_L03_001DED98, 2, 0, 0, (D_L03_001DED90 + (f32)i * D_L03_001DED94) * (a->f2C / *(f32 *)(a->p24 + 0x24)));
        vec_add_ab(&v3, &v3, &v4);
        off += 20;
    }
}
/* localdecomp:end func_L03_003C4288 */

INCLUDE_ASM("asm/levels", func_L03_003C4288);

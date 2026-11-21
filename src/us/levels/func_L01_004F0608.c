#include "common.h"

/* NTSC-U counterpart of func_L01_004F4410 (src/levels/shared/L01_004EF3A8.c): spring gains 0.035f/0.3f/0.001f for PAL's 0.0504f/0.432f/0.00144f, state timer limit 10 for 8 */
/* localdecomp:start func_L01_004F0608 */
#include "vu0.h"
typedef int s128_004F0608 __attribute__((mode(TI)));
typedef struct {
    u8 pad[128];
    s128_004F0608 out;
    u8 pad2[9972 - 144];
    s32 idx;
    s32 count;
} St_004F0608;
extern St_004F0608 D_001A4BE0;
typedef struct {
    f32 v[4];
} Vec_004F0608;
typedef struct { u8 pad[0x218]; s16 h218; u8 pad21A[0x2C0 - 0x21A]; vu0_v4 direction; u8 pad2D0[0x33C - 0x2D0]; f32 f33C; u8 pad340[0x36E - 0x340]; s16 h36E; u8 pad370[0x25F4 - 0x370]; u8 mode; } Hero_004F0608;
extern void func_003888F0(f32 *, void *, void *);
extern void func_003886E8(Vec_004F0608 *, Vec_004F0608 *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_L01_004F0340(void *, vu0_q *, void *, f32, f32, f32);
void func_L01_004F0608(void) {
    vu0_q matrix[4];
    vu0_v4 dir, before, after, copy;
    Hero_004F0608 *h = (Hero_004F0608 *)&D_001A4BE0;
    f32 a, b;
    *(vu0_q *)&dir = 0;
    *(vu0_q *)&before = 0;
    *(vu0_q *)&after = 0;
    dir.z = 1.0f;
    after.z = before.z = 0.8f;
    func_003888F0(&before.x, &before, h);
    a = 0.035f;
    b = 0.3f;
    { s32 mode = h->mode;
    dir = h->direction;
    if (mode == 2) func_003886E8((Vec_004F0608 *)&dir, (Vec_004F0608 *)((u8 *)h + 0x2E0), -1.0f); }
    if (h->mode == 1 && (*(s16 *)((u8 *)h + 0x36E) < 10 || h->f33C < 1.0f))
        dir = h->direction;
    if (((Hero_004F0608 *)&D_001A4BE0)->h36E != 0 && ((Hero_004F0608 *)&D_001A4BE0)->h218 != 0) a = b = 0.001f;
    h = (Hero_004F0608 *)&D_001A4BE0;
    if (*(s32 *)((u8 *)h + 0x16B0)) func_003888C8((u8 *)h + 0x1630, (u8 *)h + 0x1630, (u8 *)h + 0x40);
    func_L01_004F0340(&dir, matrix, 0, a, b, 0.0f);
    if (*(s32 *)((u8 *)h + 0x16B0)) func_003888C8((u8 *)h + 0x1630, (u8 *)h + 0x1630, matrix);
    if (h->mode == 1 && *(s16 *)((u8 *)h + 0x36E) != 0) {
        func_003888F0(&after.x, &after, matrix);
        __asm__(
            "lqc2 $vf1, %2\n\t"
            "lqc2 $vf2, %0\n\t"
            "vsub.xyz $vf2, $vf2, $vf1\n\t"
            "lqc2 $vf1, %3\n\t"
            "sqc2 $vf1, %1\n\t"
            "sqc2 $vf2, %0\n\t"
            "lqc2 $vf1, %0\n\t"
            "lqc2 $vf2, %1\n\t"
            "vadd.xyz $vf1, $vf1, $vf2\n\t"
            "sqc2 $vf1, %0"
            : "+m"(*(vu0_v4 *)((u8 *)h + 0x80)), "=m"(copy)
            : "m"(after), "m"(before)
            : "vf1", "vf2");
    }
}
/* localdecomp:end func_L01_004F0608 */

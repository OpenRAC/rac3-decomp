#include "common.h"

/* NTSC-U counterpart of func_L01_00337F38 (src/levels/shared/L01_003326A8.c): 25 -> 30 */
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];

/* localdecomp:start func_L01_003378E0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_337F38;

extern u8 D_001A4BE0[];
extern s32 func_L01_0032FE90(f32 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern void func_00382760(Vec_337F38 *out, f32 length, f32 yaw, f32 pitch);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_00467DA8(f32 *position, s32 life, s32 colour, s32 roll_kind, s32 spin, Vec_337F38 *velocity,
                             f32 size, f32 start_size, f32 unk, s32 delay);

/* wrench_spark_burst: a burst of count flashes at position (wrench_sparks adds it in the jump
 * attack); with Giant Clank in a wrench attack state, an explosion instead. */
void func_L01_003378E0(f32 *position, s32 count)
{
    Vec_337F38 velocity;
    Vec_337F38 at;       /* unread */
    f32 size;
    f32 yaw;
    f32 pitch;
    s32 spin;
    s32 state;
    s32 i;
    u8 *hero = D_001A4BE0;

    if (*(s32 *)(hero + 0x234) != 0) { /* Giant Clank */
        state = *(s32 *)(hero + 0x25C4);
        /* the combo, 0x20, the grind attack, 0x72 and the jump attack: an explosion at S 0.5 */
        if (state == 0x13 || state == 0x20 || state == 0x2A || state == 0x72 || state == 0x14) {
            func_L01_0032FE90(position, 0, 10, 10, 10, 20, 0, 1, 0.5f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            return;
        }
    }
    for (i = 0; i < count; i++) {
        size = func_003824E0(0.1f, 2.0f);
        spin = func_00382468(2);
        if (spin == 0) {
            spin--;
        }
        yaw = func_00382538();
        pitch = func_003824E0(0.34906584f, 1.5358897f); /* 20 to 88 degrees up */
        func_00382760(&velocity, func_003824E0(0.05f, 0.1f), yaw, pitch);
        at = *(Vec_337F38 *)position; /* a copy retail makes and never reads */
        position[0] += func_L01_00440918(0.0f, 0.15f);
        position[1] += func_L01_00440918(0.0f, 0.15f);
        position[2] += func_L01_00440918(0.0f, 0.15f);
        func_L01_00467DA8(position, 30, 0x7F207F7F, 0, spin, &velocity, size * 0.1f, size, 0.003f, 0);
        func_L01_00467DA8(position, 30, 0x7F7F7F7F, 1, -spin, &velocity, size * 0.07f, size * 0.7f, 0.003f, 0);
    }
}
/* localdecomp:end func_L01_003378E0 */

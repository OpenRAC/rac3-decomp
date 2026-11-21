/* PAL draft (2026-11-21, Promises), from the NTSC-U draft of func_L03_003A06C8 with PAL names and
 * PAL's 50 Hz constants (0.020000001f, (n * 5 + 2) / 6, 0.00392f). check.py: MATCH in level 03
 * and level 06 with its file's flags; 1 diff in level 07 (--target level_07): the first colour
 * is 0xFF8020 there, 0x808020 in levels 03 and 06. The catalogue folds the three places because
 * identity() masks lui/ori pairs as address halves; it needs a config/levels/split_places.tsv
 * line for 07:003D7AD0 (a catalogue change) before this C can land. */
#include "common.h"

/* localdecomp:start func_L03_003A1EB0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003A1EB0;

typedef struct {
    u8 pad0[0x164];
    u8 *sounds;
} Tab_003A1EB0;
extern Tab_003A1EB0 D_L03_0021F298;
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C4C18(void *, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L03_003A1EB0(void *arg) {
    V4_003A1EB0 *origin = arg;
    V4_003A1EB0 pos;
    V4_003A1EB0 vel;
    s32 n;
    s32 i;
    s32 spin;
    s32 life;
    u8 tint;
    f32 speed;
    f32 heading;
    f32 elevation;
    f32 size;
    u8 *p;

    n = func_00382498(1, 3);
    for (i = 0; i < n; i++) {
        pos = *origin;
        func_003C4C18(&pos, 0.3f);
        tint = 0;
        speed = func_003824E0(3.0f, 5.5f) * 0.020000001f;
        heading = func_00382538();
        elevation = func_003824E0(1.0471976f, 3.1415927f);
        func_00382760(&vel, speed, heading, elevation);
        spin = func_00382468(2) == 0 ? 3 : 0xFD;
        life = (func_00382498(20, 40) * 5 + 2) / 6;
        size = func_003824E0(0.25f, 0.75f) * 210000.0f;
        p = func_L01_0046FB40(&pos, &vel, life, 0x808020, spin, 0x7F, 0, size, size, 0.00392f, 0);
        if (p != 0) {
            p[2] = D_L03_0021F298.sounds[0];
            tint = p[8] + 0x20;
        }
        size *= 0.3f;
        p = func_L01_0046FB40(&pos, &vel, life, 0xFFFFFF, spin, 0x7F, 0x40, size, size, 0.00392f, 0);
        if (p != 0) {
            p[8] = tint;
            p[2] = D_L03_0021F298.sounds[0];
        }
    }
}
/* localdecomp:end func_L03_003A1EB0 */

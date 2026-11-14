/* NTSC-U draft (2026-11-14, Claude worker): C of func_L03_003A06C8, the NTSC-U twin of func_L03_003A1EB0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L03_003A1D48.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003A06C8 */
typedef struct {
    u8 pad0[0x164];
    u8 *sounds;
} Tab_003A06C8;
extern Tab_003A06C8 D_L03_0021F318;
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003BF6A8(void *, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L03_003A06C8(vu0_v4 *origin) {
    vu0_v4 pos;
    vu0_v4 vel;
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

    n = func_0037E208(1, 3);
    for (i = 0; i < n; i++) {
        pos = *origin;
        func_003BF6A8(&pos, 0.3f);
        tint = 0;
        speed = func_0037E250(3.0f, 5.5f) * 0.016666668f;
        heading = func_0037E2A8();
        elevation = func_0037E250(1.0471976f, 3.1415927f);
        func_0037E4B8(&vel, speed, heading, elevation);
        spin = func_0037E1D8(2) == 0 ? 3 : 0xFD;
        life = func_0037E208(20, 40);
        size = func_0037E250(0.25f, 0.75f) * 210000.0f;
        p = func_L01_0046C468(&pos, &vel, life, 0x808020, spin, 0x7F, 0, size, size, 0.0027222224f, 0);
        if (p != 0) {
            p[2] = D_L03_0021F318.sounds[0];
            tint = p[8] + 0x20;
        }
        size *= 0.3f;
        p = func_L01_0046C468(&pos, &vel, life, 0xFFFFFF, spin, 0x7F, 0x40, size, size, 0.0027222224f, 0);
        if (p != 0) {
            p[8] = tint;
            p[2] = D_L03_0021F318.sounds[0];
        }
    }
}
/* localdecomp:end func_L03_003A06C8 */

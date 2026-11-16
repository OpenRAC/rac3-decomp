/* PAL near miss (Codex wave 6): near miss: 1 words differ with the file's flags.
 * Worker's note: 1 diff at +0xB4: addu v1,s0,s2 instead of retail v1,s2,s0; raw pointer, struct member and integer address forms give identical bytes; build/codex/w292/func_L01_0037C978.integer.log. Fixed flags, no metadata.
 */
#include "common.h"
/* localdecomp:start func_L01_0037C978 */
#include "vu0.h"
void func_L01_0037C978(u8 *moby, s32 id, s32 value)
{
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    u8 *vars = *(u8 **)(moby + 0x68);
    u8 *p;
    u8 *rotation;
    s32 i;
    f32 a, b;
    for (i = 0; i < 12; i++) {
        if (*(s32 *)(vars + 0x134 + i * 0xB0) == id) return;
    }
    for (i = 0; i < 12; i++) {
        if (*(s32 *)(vars + i * 0xB0 + 0x130) != 0) continue;
        p = vars + 0x90 + i * 0xB0;
        rotation = p + 0x40;
        *(u8 **)(p + 0xA0) = moby;
        *(s32 *)(p + 0xA4) = id;
        ++*(s32 *)(vars + 0x50);
        *(f32 *)(p + 0x50) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x54) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x58) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x74) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x78) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x7C) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x5C) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x60) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x64) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x80) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x84) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x88) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x68) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(f32 *)(p + 0x6C) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(f32 *)(p + 0x70) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(f32 *)(p + 0x8C) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(f32 *)(p + 0x90) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(f32 *)(p + 0x94) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(s32 *)(p + 0x9C) = value;
        *(s32 *)(p + 0x98) = value;
        qzero(p + 0x10);
        qzero(p);
        a = func_00382538();
        b = func_00382538();
        func_00382760(rotation, *(f32 *)(vars + 0x2C), a, b);
        return;
    }
}
/* localdecomp:end func_L01_0037C978 */

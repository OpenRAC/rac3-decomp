/* PAL near miss (Codex wave 8): near miss: 91 words differ with the file's flags.
 * Worker's note: Best ordinary 90 diff: func_L01_00344A88.ordinary.log; retail 0xC0 frame has 16-byte sq slots, fixed -fopt-stack emits 0x70 frame and 8-byte sd slots. --sq-ra changes mnemonics but cannot expand slots/frame (89 diff, 02.log); no alternate flags tested. Extra ...
 */
#include "common.h"
/* localdecomp:start func_L01_00344A88 */
typedef int Q_00344A88 __attribute__((mode(TI)));
extern s32 D_L01_001DFF40;
u8 *func_L01_00344A88(Q_00344A88 *position, void *direction, u8 r, u8 g, u8 b, u8 alpha, u16 flags, s32 owner, f32 speed, f32 scale, f32 width, f32 life, s32 mode, s32 extra)
{
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
    extern void func_003C7C38(void *);
    u8 *object;
    u8 *vars;
    if (D_L01_001DFF40 < 17) return 0;
    object = func_003C24B0(0xA82, 0xC0);
    if (object) {
        vars = *(u8 **)(object + 0x68);
        *(Q_00344A88 *)(object + 0x10) = *position;
        func_0038CF68(vars, direction, speed * 0.020000001f);
        object[0x20] = 0;
        object[0x30] = 0xFF;
        *(s16 *)(object + 0x32) = 0xFF;
        *(s32 *)(vars + 0x50) = owner;
        *(s32 *)(vars + 0x54) = 0;
        *(u16 *)(object + 0x34) |= 0x100;
        *(f32 *)(vars + 0x60) = speed;
        *(f32 *)(vars + 0x68) = scale;
        *(f32 *)(vars + 0x70) = width;
        vars[0x78] = r;
        vars[0x79] = g;
        vars[0x7A] = b;
        vars[0x7B] = alpha;
        *(f32 *)(vars + 0x74) = life;
        *(u16 *)(vars + 0x7E) = flags;
        *(s32 *)(vars + 0x5C) = 0;
        *(s32 *)(vars + 0x58) = 0;
        vars[0x81] = extra;
        vars[0x80] = mode;
        *(f32 *)(object + 0x2C) = mode ? 0.025f : 0.015f;
        *(u16 *)(object + 0x96) = 0;
        *(f32 *)(vars + 0x84) = func_00382538();
        *(f32 *)(vars + 0x88) = func_L01_00443A18(3.0f, 5.0f);
        if (owner == 0) vars[0x7C] = 1;
        else vars[0x7C] = 0;
        *(s16 *)(vars + 0x6E) = func_L01_004C85C8(object, 0, 1.0f, 1.0f, 1.0f);
        func_003C7C38(object);
    }
    return object;
}
/* localdecomp:end func_L01_00344A88 */

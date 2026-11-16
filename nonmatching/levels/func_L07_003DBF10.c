/* PAL near miss (Codex wave 8): near miss: 45 words differ with the file's flags.
 * Worker's note: Best 45 diff, 02.log and ordinary.log. Struct vector copy fixes full prologue and saved-position handling. Fixed default assembler emits lwc1 from .lit4 for 0.3f whereas retail uses lui/ori/mtc1; residual scheduling near initialization. No alternate flags ...
 */
#include "common.h"
/* localdecomp:start func_L07_003DBF10 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003DBF10;
u8 *func_L07_003DBF10(u8 *owner, void *target, V_003DBF10 *position, f32 duration, f32 strength)
{
    extern u8 *func_003C24B0(s32, s32);
    extern void func_L01_004450F0(s32, s32, s32);
    extern void func_L01_0044FD88(void *, void *, void *, s32);
    extern void func_003C7C38(void *);
    extern void func_L07_003DC040(void *);
    V_003DBF10 pos = *position;
    u8 *object = func_003C24B0(0x1D3F, 0x130);
    u8 *vars;
    if (object) {
        object[0x30] = 0xFF;
        *(u16 *)(object + 0x32) = *(u16 *)(owner + 0x32);
        *(u16 *)(object + 0x34) |= 0x100;
        vars = *(u8 **)(object + 0x68);
        *(f32 *)(object + 0x2C) = *(f32 *)(*(u8 **)(object + 0x24) + 0x24) * 0.3f;
        func_L01_004450F0((s32)object, 0, 0);
        *(u8 **)(object + 0xB8) = owner;
        func_L01_0044FD88(owner, object, target, 0);
        *(u16 *)(object + 0x34) &= ~2;
        *(f32 *)(vars + 0x11C) = strength;
        *(void **)(vars + 0x118) = target;
        *(f32 *)(vars + 0x128) = duration;
        *(V_003DBF10 *)(vars + 0x100) = pos;
        func_003C7C38(object);
        func_L07_003DC040(object);
        *(s32 *)(vars + 0x124) = -1;
    }
    return object;
}
/* localdecomp:end func_L07_003DBF10 */

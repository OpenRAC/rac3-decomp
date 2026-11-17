/* PAL near miss (Codex wave 8): near miss: 72 words differ with the file's flags.
 * Worker's note: 72 positional word differences; w441/func_L01_003E0058.04.log and .05.log. Extra materialization of 255 for byte/halfword initializers and shifted zero-byte store; remaining body displaced by one instruction. Three initializer formulations retain residual ...
 */
#include "common.h"
/* localdecomp:start func_L01_003E0058 */
Obj_003DC268 *func_L01_003E0058(u128_t *position, u128_t *direction) {
    extern Obj_003DC268 *func_003C24B0(s32, s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern void func_0038D308(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_003C4840(f32, void *, void *);
    extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
    extern void func_003C7C38(void *);
    Obj_003DC268 *obj = func_003C24B0(0x1E05, 0x80);
    u8 *state;
    if (obj != 0) {
        obj->pad20[0] = 0;
        obj->flags = obj->opacity = 255;
        state = (u8 *)obj->vars;
        obj->position = *position;
        *(u128_t *)state = *direction;
        *(s16 *)(state + 0x20) = (func_00382498(300, 500) * 5 + 2) / 6;
        *(u16 *)((u8 *)obj + 0x34) |= 0x100;
        *(f32 *)((u8 *)obj + 0xF0) = func_00382538();
        *(f32 *)((u8 *)obj + 0xF4) = func_00382538();
        *(f32 *)((u8 *)obj + 0xF8) = func_00382538();
        obj->pad20[3] = 64;
        func_0038D308((u8 *)obj + 0xC0, (u8 *)obj + 0xF0);
        func_003C4840(func_003824E0(0.05235988f, 0.10471976f), state + 0x10, (u8 *)obj + 0xD0);
        *(f32 *)((u8 *)obj + 0x2C) = *(f32 *)(*(u8 **)((u8 *)obj + 0x24) + 0x24) * func_003824E0(0.25f, 0.3f);
        *(s32 *)(state + 0x28) = func_L01_004C85C8(obj, 0, 1.0f, 1.0f, 1.0f);
        func_003C7C38(obj);
    }
    return obj;
}
/* localdecomp:end func_L01_003E0058 */

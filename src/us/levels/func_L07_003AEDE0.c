#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of the PAL function at the same position (L07) */
/* localdecomp:start func_L07_003AEDE0 */
extern void func_003BDA38(void *, s32, void *);
extern f32 func_0037E2A8(void);
extern void func_003D3FA0(void *, s32, s32, s32, f32, f32, f32);

void func_L07_003AEDE0(u8 *obj) {
    vu0_v4 pos;
    f32 s1;
    f32 s2;

    s1 = (1.0f - (f32) * (s32 *)(*(u8 **)(obj + 0x68) + 0xA0) / 60.0f) * 3.0f;
    func_003BDA38(obj, 1, &pos);
    func_003D3FA0(&pos, 0x31, 0x60208040, 1, s1, 0.5f, func_0037E2A8());
    s2 = s1 * 0.4f;
    func_003D3FA0(&pos, 0x31, 0x7F208040, 1, s2, 0.5f, func_0037E2A8());
}
/* localdecomp:end func_L07_003AEDE0 */

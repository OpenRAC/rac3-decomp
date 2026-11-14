#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of the PAL function at the same position (L01 shared, @ps2as) */
/* localdecomp:start func_L01_002FB230 */
extern u8 D_L01_001EEB00[];
extern f32 func_003BEB48(f32, f32, f32);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern void func_L01_004445E0(void *, void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_003BD360(void *);

void func_L01_002FB230(u8 *obj) {
    vu0_v4 pos;
    f32 r;
    s32 v;

    *(u16 *)(obj + 0x34) |= 0x41;
    r = func_003BEB48(0.5f, 5.5f, (f32)obj[0xBC] / 15.0f);
    v = func_003CF790(obj + 0x10, 0x10, obj, 0, r);
    pos = *(vu0_v4 *)(obj + 0x10);
    func_L01_004445E0(obj, &pos, D_L01_001EEB00, v, 0, 0x01030001, 2, 1, -1, 1.0f, 1.0f, 1.0f);
    obj[0xBC]++;
    if (obj[0xBC] >= 0x10) {
        func_003BD360(obj);
    }
}
/* localdecomp:end func_L01_002FB230 */

#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of PAL func_L07_003B89E0. */
/* localdecomp:start func_L07_003B70F0 */
extern s32 func_L07_003A0BC0(s32, u8 *, s32, s32);
extern f32 func_L01_0040BF90(void *);
extern void func_L07_003B6DA0(u8 *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L07_003B71F0(void);

void func_L07_003B70F0(u8 *obj) {
    u8 *sub = *(u8 **)(obj + 0x68);
    vu0_v4 d;
    s32 r;

    if (*(s16 *)(sub + 0x29E) == 0) {
        func_L07_003A0BC0(8, obj, 0, 0x78);
        *(s16 *)(sub + 0x29E) = 0x4B0;
    }
    vec_sub_ba(&d, obj + 0x10, sub + 0x70);
    d.z = 0.0f;
    r = 8;
    if (sub[0x296] != 0) {
        r = 9;
    }
    if (func_L01_0040BF90(&d) < 144.0f) {
        func_L07_003B6DA0(obj, r);
        return;
    }
    func_00388830(&d, &d, 7.0f);
    vec_add_ab(sub + 0x270, sub + 0x70, &d);
    *(f32 *)(sub + 0x278) = *(f32 *)(*(u8 **)(sub + 0x190) + 0x18);
    sub[0x297] = r;
    sub[0x298] = 0;
    *(void **)(sub + 0x290) = func_L07_003B71F0;
    func_L07_003B6DA0(obj, 10);
}
/* localdecomp:end func_L07_003B70F0 */

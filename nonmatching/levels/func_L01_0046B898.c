/* NTSC-U draft (Claude wave B): C of func_L01_004681E8, the NTSC-U twin of func_L01_0046B898, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 75 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_004681E8", whose code is not the PAL one).
 * Worker's note: 75 diff (first draft, 1 compile): body read from the asm (sub = obj+0x20: f4 += f8; func_L01_00474030(obj->f20, &l30, &l34, obj+0x10, f4, fC, <16-byte copy of obj+0x10 passed on the stack at 0x10(sp)>); if func_003883C8(obj+0xA) { func_003C7CE0(obj); return; ...
 */
#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_004681E8 */
extern u8 D_L01_001EEB00[];
extern void func_L01_00474030(s32 a0, f32 *a1, f32 *a2, void *a3, f32 f12, f32 f13, u128_t pos);
extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);
extern s32 func_L01_00445B88(f32 a, f32 b, f32 c, f32 d);
extern s32 func_003CF790(void *a0, s32 a1, s32 a2, s32 a3, f32 f12);
extern void func_L01_004445E0(s32 a0, void *a1, void *a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, s32 stack0, f32 f12, f32 f13, f32 f14);

void func_L01_004681E8(u8 *obj) {
    u8 *sub = obj + 0x20;
    u8 *pos = obj + 0x10;
    f32 loc30;
    f32 loc34;
    s32 r;
    f32 h;
    *(f32 *)(sub + 4) = *(f32 *)(sub + 4) + *(f32 *)(sub + 8);
    func_L01_00474030(*(s32 *)(obj + 0x20), &loc30, &loc34, pos, *(f32 *)(sub + 4), *(f32 *)(sub + 0xC), *(u128_t *)pos);
    if (func_003883C8(obj + 0xA) != 0) {
        func_003C7CE0(obj);
        return;
    }
    h = (f32)*(s16 *)(obj + 0xA);
    if (h < 7.5f) {
        *(s32 *)(obj + 4) = func_L01_00445B88(0.7f, 0.7f, 0.7f, h * 0.08f / 7.5f);
    }
    r = func_003CF790(pos, 0x10, *(s32 *)(sub + 0x14), 0, 0.15f);
    func_L01_004445E0(*(s32 *)(sub + 0x14), (void *)&*(u128_t *)pos, D_L01_001EEB00, r, 0, 0x01010001, 2, 1, -1, 2.0f, 1.0f, 1.0f);
}
/* localdecomp:end func_L01_004681E8 */

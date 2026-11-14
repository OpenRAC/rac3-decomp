/* NTSC-U draft (2026-11-14, Claude worker): C of func_L40_003DA188, the NTSC-U twin of func_L40_003DA390, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L40_003DA2D0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"

/* NTSC-U counterpart of func_L40_003DA390 (src/levels/shared/...) */
/* localdecomp:start func_L40_003DA188 */
#include "vu0.h"

extern u8 *D_001DDF30_sda;
__asm__(".extern D_001DDF30_sda, 4");
extern s32 func_L40_003DA148(void *, f32);
extern void func_L40_003DA0C8(void);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L40_003D9C70(void *, void *);
extern s32 func_L39_005B2498(s32);
extern void func_L40_003D9B20(void *, void *);
extern s32 func_003883C8(void *);
extern void func_L40_003DAE40(void *);
extern void func_003C7CE0(void *);
extern f32 func_L01_00442098(f32, f32, f32, f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern u8 *func_L01_00469378(void *, s32, s32, s32);

void func_L40_003DA188(u8 *self) {
    vu0_v4 vB;
    vu0_v4 vA;
    vu0_v4 v20;
    vu0_v4 vC;
    vu0_v4 v40;
    u8 *m;
    u8 *t;
    u8 *c;
    u8 **slot;
    u8 *p;
    s32 i;
    f32 ratio;

    m = *(u8 **)(self + 0x68);
    t = *(u8 **)(m + 0x4C);
    if (t == 0) {
        return;
    }
    if (func_L40_003DA148(t + 0xA0, 48.0f) == 0) {
        return;
    }
    if (D_001DDF30_sda == self) {
        func_L40_003DA0C8();
    }
    if (m[0x42] != 0) {
        func_003886E8(self + 0x10, t + 0x250, -0.75f);
        vec_add_ab(self + 0x10, t + 0xA0, self + 0x10);
        *(f32 *)(self + 0xFC) = 0.5235988f;
        if (func_L40_003D9C70(self, t) != 0) {
            if (func_L39_005B2498(5) == 0) {
                func_L40_003D9B20(self, t);
            }
        }
    }
    if (func_003883C8(m + 0x40) != 0) {
        func_L40_003DAE40(self);
        return;
    }
    func_003886E8(&v20, t + 0x250, -0.75f);
    vec_add_ab(&v20, t + 0xA0, &v20);
    for (i = 3, slot = (u8 **)(m + 0x30); i >= 0; i--, slot++) {
        c = *slot;
        if (c == 0) {
            continue;
        }
        if (func_003883C8(c + 0x3E) != 0) {
            if (m[0x42] == 0 && D_001DDF30_sda != 0) {
                m[0x42] = 1;
            }
            func_003C7CE0(c);
            *slot = 0;
            continue;
        }
        vA.x = *(f32 *)(c + 0x30);
        vA.y = *(f32 *)(c + 0x34);
        vA.z = *(f32 *)(c + 0x38);
        vA.w = 0.0f;
        ratio = 1.0f - (f32) * (s16 *)(c + 0x3E) / (f32) * (s16 *)(c + 0x3C);
        vB.x = vA.x - *(f32 *)(c + 0x24);
        vB.y = vA.y - *(f32 *)(c + 0x28);
        vB.z = vA.z - *(f32 *)(c + 0x2C);
        vC.x = v20.x - *(f32 *)(c + 0x24);
        vC.y = v20.y - *(f32 *)(c + 0x28);
        vC.z = v20.z - *(f32 *)(c + 0x2C);
        *(f32 *)(c + 0x10) = func_L01_00442098(vB.x, vA.x, v20.x, vC.x, ratio);
        *(f32 *)(c + 0x14) = func_L01_00442098(vB.y, vA.y, v20.y, vC.y, ratio);
        *(f32 *)(c + 0x18) = func_L01_00442098(vB.z, vA.z, v20.z, vC.z, ratio);
        v40.x = func_L39_005B2568(0.0f, 0.01f) + *(f32 *)(c + 0x10);
        v40.y = func_L39_005B2568(0.0f, 0.01f) + *(f32 *)(c + 0x14);
        v40.z = func_L39_005B2568(0.0f, 0.01f) + *(f32 *)(c + 0x18);
        p = func_L01_00469378(&v40, 0x14, 0, 0);
        if (p != 0) {
            *(f32 *)(p + 0xC) = 10000.0f;
            *(s32 *)(p + 4) = 0x7F7F4040;
        }
    }
}
/* localdecomp:end func_L40_003DA188 */

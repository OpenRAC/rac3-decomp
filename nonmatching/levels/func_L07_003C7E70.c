/* PAL level-07 reconstruction from the owned retail ELF (Wave2 P04).
 * Near miss: stock tools/check.py reports 20 diff with the owning-file flags.
 * Initializer; float registers and tuning-store ordering still differ.
 * Checked with the owning file's normal prelude/earlier declarations; not linked.
 */
#include "common.h"
typedef int Q_003C7E70 __attribute__((mode(TI)));
extern void func_L01_00445F40(u8 *, s32);
extern s32 func_L07_003C1AF8(void);
extern f32 func_L07_003C1B40(s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L07_003C86D0(void *);
void func_L07_003C7E70(u8 *a0) {
    u8 *p;
    u8 *r;
    u8 *q;
    u8 *v;
    s32 k;
    f32 s;
    p = *(u8 **)(a0 + 0x68);
    func_L01_00445F40(a0, 0x19BD);
    r = p + 0x30;
    k = func_L07_003C1AF8();
    s = func_L07_003C1B40(k);
    *(s16 *)(r + 4) = (f32)*(s16 *)(p + 0x34) * s;
    *(f32 *)(p + 0x30) = (f32)*(s16 *)(r + 4);
    r[0x14] = (f32)p[0x44] * s;
    r[0x15] = (f32)p[0x45] * s;
    r[0x16] = (f32)p[0x46] * s;
    if (k == 1 || k == 3) {
        func_L01_00446058(a0, 0x1D8A, 0x19BD);
    }
    r[0x28] = 0x14; r[0x2A] = 0xE; *(f32 *)(r + 0x10) = 1.0f; r[0xF] = 0; r[9] = 0;
    q = p + 0x70;
    v = p + 0x150;
    q[0x48] = 0xFF; q[0x10] = 8; *(f32 *)(q + 0x3C) = 0.15f; *(f32 *)(q + 0x58) = 0.35f;
    *(f32 *)(q + 0x30) = 1.0f; *(f32 *)(q + 0x5C) = 0.5f; *(f32 *)(q + 0xB0) = 1.0f;
    *(f32 *)(q + 0x34) = 0.5f; q[0x77] = 1;
    *(f32 *)(p + 0x150) = 0.6f; *(f32 *)(v + 4) = 0.3f;
    *(f32 *)(v + 0x10) = 1.5707964f; *(f32 *)(v + 0x30) = 0.2443461f;
    *(f32 *)(v + 0x2C) = 0.196000025f; *(f32 *)(v + 0x34) = 0.2f;
    *(s32 *)(v + 0xEC) = 0; *(f32 *)(v + 8) = 0.5f; *(f32 *)(v + 0xC) = 0.5f;
    *(Q_003C7E70 *)(p + 0x440) = *(Q_003C7E70 *)(a0 + 0x10);
    *(Q_003C7E70 *)(p + 0x450) = *(Q_003C7E70 *)(a0 + 0xF0);
    func_L01_0045BD78(a0, 0.00240000011f, 0.120000005f, 0.00502654864f, 0.125663713f);
    func_L07_003C86D0(a0);
}

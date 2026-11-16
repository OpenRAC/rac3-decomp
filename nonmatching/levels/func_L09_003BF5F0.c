/* func_L09_003BF5F0: 151+ diff with the file's flags. Gets the D_1A4CB0 / h=-0xD0 base right, but uses 9 callee-saved regs (frame 0xB0 vs 0xA0): retail keeps p+0xD64, p+0xD68 in s-regs and builds p+0xD74/0xD78 at the call; mine hoists all four. Not resolved. */
#include "vu0.h"
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448728(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern u8 D_L09_001D9B60[];
extern s32 D_L09_001DE730;
__asm__(".extern D_L09_001DE730, 4");

void func_L09_003BF5F0(u8 *self) {
    u8 *p;
    u8 *e;
    u8 *h;
    vu0_v4 t;
    vu0_v4 v;
    vu0_v4 w;
    f32 f20, f21, f23, d;
    p = *(u8 **)(self + 0x68);
    e = D_L09_001E009C + (*(s32 *)(p + 0xCD0) << 8);
    f23 = 0.0f;
    *(u16 *)(e + 0x34) &= 0xFFF9;
    *(u128_t *)&t = *(u128_t *)(self + 0x10);
    func_L01_003EB350(0, &t);
    *(f32 *)(p + 0xD60) = f23;
    d = func_0038CF38(self + 0x10, (u8 *)&D_001A4BE0 + 0xD0);
    h = (u8 *)&D_001A4BE0;
    func_L01_00448728(p + 0xD64, p + 0xD74, 0, -func_0038D160(d, *(f32 *)(h + 0xD8) - *(f32 *)(self + 0x18)),
        0.0432000011f, 0.432000041f, 0.0418879054f);
    func_L01_00448728(p + 0xD68, p + 0xD78, 0,
        func_0038D160(*(f32 *)(h + 0xD0) - *(f32 *)(self + 0x10), *(f32 *)(h + 0xD4) - *(f32 *)(self + 0x14)),
        0.0432000011f, 0.432000041f, 0.0418879054f);
    *(f32 *)(p + 0xD6C) = f23;
    func_L01_003EB3C0(0, p + 0xD60);
    d = *(f32 *)(h + 0x88);
    *(u128_t *)&v = *(u128_t *)(self + 0x10);
    *(u128_t *)&w = *(u128_t *)&D_L09_001DE730;
    if (d < 332.0f) {
        f23 = 332.0f - d;
    }
    d = func_0038CF38(self + 0x10, (u8 *)&D_001A4BE0 + 0x80) - f23;
    f21 = 0.0f;
    if (d <= -5.0f) {
        f21 = -1.3f;
    } else if (d >= 15.0f) {
        f21 = 1.3f;
    } else {
        f20 = 1.3f;
        f21 = func_003C3BE8(f21, f20, (d - -5.0f) / 20.0f);
        f21 = f21 + f21 - f20;
    }
    w.x = w.x * f21;
    w.y = w.y * f21;
    func_0038D890(&w, &w, D_L09_001D9B60, *(f32 *)(p + 0xD68));
    vec_add_ab(&v, &v, &w);
    *(u128_t *)(e + 0x10) = *(u128_t *)&v;
    *(f32 *)(e + 0xF8) = *(f32 *)(p + 0xD68);
}

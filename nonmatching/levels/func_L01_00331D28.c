/* NEAR MISS: 2 instrs differ in check.py: retail loads v1=2 then v0=3 (sb 18 uses v0, sb 19 uses v1); mine loads v0=3 then v1=2. Statement order permutations tried. */
#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_331D28;
typedef struct { V4_331D28 v; void *f10; s32 f14; u8 f18, f19; u16 f1A; f32 f1C; s32 f20; } S_331D28;
typedef struct { u8 p0[0x64]; s32 f64; f32 f68; } E_331D28;
typedef struct { u8 p0[0x10]; u8 f10[0x58]; E_331D28 *f68; u8 p6C[0xAA - 0x6C]; u16 fAA; } O_331D28;
extern u8 D_L01_001D66B0;
extern void func_0040E620(void *, void *, f32);
extern void func_003D4D00(void *, s32, s32, void *, f32);
void func_L01_00331D28(O_331D28 *o, f32 f) {
    S_331D28 s;
    E_331D28 *e;
    e = o->f68;
    s.f10 = o;
    s.f14 = e->f64;
    s.f1C = f;
    s.f20 = 1;
    s.v = *(V4_331D28 *)&D_L01_001D66B0;
    func_0040E620(&s, &s, 1.0f);
    s.v.w = 5627.9248046875f;
    s.f18 = 3;
    s.f19 = 2;
    s.f1A = o->fAA;
    func_003D4D00(o->f10, 0, 0, &s, e->f68);
}

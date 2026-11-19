/* functional: high. Ambient-sound emitter driven by a visibility probe: samples 20 points (steps of pi/10) on a radius-4 circle around the listener (func_0038D890 rotates (4,0,0) about +Z), counts (x0.05) those for which func_L01_00451768 reports a value below D_001E2880[0x148], eases the level D_001DF730 up (0.2*dt) when the count exceeds it or down (0.75*dt) otherwise, clamps it to [0,1], scales the emitter voice volume by (f4+level)/(f4+1)*1024 and keeps the voice alive at the listener (starting sound 0x15 when it is gone) */
#include "vu0.h"
extern u8 D_001E2880[];
extern u8 D_001A3190[];
extern f32 D_001DF730;
extern f32 D_001D5324;
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_L01_00451768(void *);
extern s32 func_003A53E8(u32, s32);
extern s32 func_L01_004AAE90(s32, s32, void *, s32);
void func_L01_003EF2D0(u8 *self) {
    f32 p[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));
    f32 ax[4] __attribute__((aligned(16)));
    s32 *sub = *(s32 **)(self + 8);
    f32 ang = 0.0f, cnt = 0.0f, lvl, dt;
    u8 *slot;

    v[0] = 4.0f; v[1] = 0.0f; v[2] = 0.0f; v[3] = 1.0f;
    ax[0] = 0.0f; ax[1] = 0.0f; ax[2] = 1.0f;
    do {
        func_0038D890(p, v, ax, ang);
        vec_add_ba(p, D_L01_001E29C0, p);
        if (func_L01_00451768(p) < *(f32 *)(D_001E2880 + 0x148)) cnt = cnt + 0.05f;
        ang = ang + 0.31415927f;
    } while (ang < 6.2831855f);
    lvl = D_001DF730;
    dt = D_001D5324;
    if (lvl < cnt) lvl = lvl + dt * 0.2f;
    else lvl = lvl - dt * 0.75f;
    D_001DF730 = lvl;
    if (1.0f < D_001DF730) D_001DF730 = 1.0f;
    else if (D_001DF730 < 0.0f) D_001DF730 = 0.0f;
    slot = (u8 *)D_001A30B0 + (sub[2] << 7);
    if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) {
        f32 f4 = *(f32 *)(sub + 1);
        func_003A53E8(sub[2], (s32)((f4 + D_001DF730) / (f4 + 1.0f) * 1024.0f));
    }
    *(vu0_q *)(D_001A3190 + (sub[2] << 7)) = *(vu0_q *)D_L01_001E29C0;
    slot = (u8 *)D_001A30B0 + (sub[2] << 7);
    if (*(u8 **)(slot + 0x100) != self || slot[0xD0] == 0) {
        sub[2] = func_L01_004AAE90(sub[0], 0x15, self, 0x400);
    }
}

/* functional: high. Multi-variant positional sound emitter (sibling of func_L01_003EEA08): sub[0..5] hold a table of sound ids selected by sub[9]; sub[11] != -1 requests a switch (stops both voices, selects sub[11]); then, like 003EEA08, it clamps the listener offset to the emitter box, and inside the box it only (re)starts voice sub[8] (flags|0x110) with a random retrigger timer sub[6]; outside it fades by distance and drives voice sub[7] (flags|0x10) and sub[8] with func_003A53E8, stopping them when far. */
#include "vu0.h"
extern u8 *D_L01_001DFB6C;
extern u8 D_001A3190[];
extern void func_0038D000(void *, void *, void *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038CEA8(void *);
extern s32 func_00382468(s32);
extern s32 func_L01_004AAE90(s32, s32, void *, s32);
extern void func_003A4F28(s32);
extern s32 func_003A53E8(u32, s32);
void func_L01_003F02D8(u8 *self) {
    f32 a[4] __attribute__((aligned(16)));
    f32 r[4] __attribute__((aligned(16)));
    f32 dv[4] __attribute__((aligned(16)));
    s32 *sub = *(s32 **)(self + 8);
    u8 *row;
    u8 *slot;
    s32 flags, ok, vol, vol2, v, t3;
    f32 f20, dist, f3, f2, f4, f0;

    if (sub[11] != -1) {
        v = sub[7];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) func_003A4F28(v);
        }
        sub[7] = -1;
        v = sub[8];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) func_003A4F28(v);
        }
        t3 = sub[11];
        sub[11] = -1;
        sub[9] = t3;
        sub[8] = -1;
    }
    vec_sub_ba(a, D_L01_001E29C0, self + 0x40);
    a[3] = 0.0f;
    func_0038D000(r, a, self + 0x50);
    ok = 1;
    if (1.0f < r[0]) { r[0] = 1.0f; ok = 0; }
    if (r[0] < -1.0f) { r[0] = -1.0f; ok = 0; }
    if (1.0f < r[1]) { r[1] = 1.0f; ok = 0; }
    else if (r[1] < -1.0f) { r[1] = -1.0f; ok = 0; }
    if (1.0f < r[2]) { r[2] = 1.0f; ok = 0; }
    else if (r[2] < -1.0f) { r[2] = -1.0f; ok = 0; }
    row = D_L01_001DFB6C + sub[sub[9]] * 32;
    flags = 0;
    if (row[0x18] != 0) flags = 4;

    if (ok == 1) {
        v = sub[7];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) func_003A4F28(v);
        }
        sub[7] = -1;
        v = sub[8];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) return;
        }
        if (func_0038CAD0(sub + 6) == 0) return;
        sub[8] = func_L01_004AAE90(sub[sub[9]], flags | 0x110, self, 0x400);
        if (sub[5] <= 0) return;
        sub[6] = (s32)((f32)(sub[4] + func_00382468(sub[5] - sub[4])) * 50.0f);
        return;
    }

    func_0038D000(r, r, self + 0x10);
    vec_add_ba(r, r, self + 0x40);
    vec_sub_ba(dv, D_L01_001E29C0, r);
    dist = func_0038CEA8(dv);
    f2 = dist;
    f20 = 1.0f;
    if (*(f32 *)(row + 4) < dist) {
        v = sub[7];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) func_003A4F28(v);
        }
        sub[7] = -1;
        v = sub[8];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) func_003A4F28(v);
        }
        sub[8] = -1;
    } else {
        f0 = *(f32 *)(row + 4) - *(f32 *)(row + 0);
        f0 = 1.0f / f0;
        f20 = f2 * f0;
    }
    if (f20 < 0.2f) {
        f3 = 0.2f - f20;
        f3 = f3 * 5.0f;
        f2 = 1.0f - f3;
        f0 = f3 * f3 + f2 * f2;
        f4 = (f32)*(s32 *)(row + 0xC);
        f0 = sqrt_asm(f0);
        f4 = f4 / f0;
        f2 = f2 * f4;
        f3 = f3 * f4;
        vol = (s32)f2;
        vol2 = (s32)f3;
        v = sub[8];
        if (v == -1 || *(u8 **)((u8 *)D_001A30B0 + (v << 7) + 0x100) != self ||
            *((u8 *)D_001A30B0 + (v << 7) + 0xD0) == 0) {
            sub[8] = func_L01_004AAE90(sub[sub[9]], flags | 0x110, self, 0x400);
        }
        func_003A53E8(sub[8], vol2);
    } else {
        v = sub[8];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) {
                func_003A4F28(v);
                sub[8] = -1;
            }
        }
        f0 = 1.0f - f20;
        f4 = (f32)*(s32 *)(row + 0xC);
        vol = (s32)(f4 * f0);
    }
    v = sub[7];
    if (v == -1 || *(u8 **)((u8 *)D_001A30B0 + (v << 7) + 0x100) != self ||
        *((u8 *)D_001A30B0 + (v << 7) + 0xD0) == 0) {
        if (vol > 0) sub[7] = func_L01_004AAE90(sub[sub[9]], flags | 0x10, self, 0x400);
    }
    if (sub[7] != -1) *(vu0_q *)(D_001A3190 + (sub[7] << 7)) = *(vu0_q *)r;
    func_003A53E8(sub[7], vol);
}

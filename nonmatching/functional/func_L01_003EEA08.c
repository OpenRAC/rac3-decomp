/* functional: high. Positional sound emitter update (sibling of func_L01_003EE880/003EEF30): rotates the listener offset into the emitter's box, clamps it to [-1,1] per axis; inside the box it (re)starts the sound voice w14 at flags|0x110 and re-arms the random retrigger timer; outside it fades by distance (pan/volume pair from f20) driving the two voices w10 (flags|0x10) and w14 (flags|0x110) via func_003A53E8, stopping them with func_003A4F28 when out of range. Branch structure mirrors retail. */
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
void func_L01_003EEA08(u8 *self) {
    f32 a[4] __attribute__((aligned(16)));
    f32 r[4] __attribute__((aligned(16)));
    f32 dv[4] __attribute__((aligned(16)));
    s32 *sub = *(s32 **)(self + 8);
    u8 *row;
    u8 *slot;
    s32 flags, ok, vol, vol2, v;
    f32 f20, dist, f3, f2, f4, f0;

    if (sub[6] == 0) return;
    if (sub[0] == -1) return;
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
    row = D_L01_001DFB6C + sub[0] * 32;
    flags = 0;
    if (row[0x18] != 0) flags = 4;

    if (ok == 1) {
        v = sub[4];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) func_003A4F28(v);
        }
        sub[4] = -1;
        v = sub[5];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) {
                func_003A53E8(v, *(s32 *)(row + 0xC));
                return;
            }
        }
        if (func_0038CAD0(sub + 3) == 0) return;
        sub[5] = func_L01_004AAE90(sub[0], flags | 0x110, self, 0x400);
        if (sub[2] <= 0) return;
        sub[3] = (s32)((f32)(sub[1] + func_00382468(sub[2] - sub[1])) * 50.0f);
        return;
    }

    func_0038D000(r, r, self + 0x10);
    vec_add_ba(r, r, self + 0x40);
    vec_sub_ba(dv, D_L01_001E29C0, r);
    dist = func_0038CEA8(dv);
    f2 = dist;
    f20 = 1.0f;
    if (*(f32 *)(row + 4) < dist) {
        v = sub[4];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) func_003A4F28(v);
        }
        sub[4] = -1;
        v = sub[5];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) func_003A4F28(v);
        }
        sub[5] = -1;
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
        v = sub[5];
        if (v == -1 || *(u8 **)((u8 *)D_001A30B0 + (v << 7) + 0x100) != self ||
            *((u8 *)D_001A30B0 + (v << 7) + 0xD0) == 0) {
            sub[5] = func_L01_004AAE90(sub[0], flags | 0x110, self, 0x400);
        }
        func_003A53E8(sub[5], vol2);
    } else {
        v = sub[5];
        if (v != -1) {
            slot = (u8 *)D_001A30B0 + (v << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) {
                func_003A4F28(v);
                sub[5] = -1;
            }
        }
        f0 = 1.0f - f20;
        f4 = (f32)*(s32 *)(row + 0xC);
        vol = (s32)(f4 * f0);
    }
    v = sub[4];
    if (v == -1 || *(u8 **)((u8 *)D_001A30B0 + (v << 7) + 0x100) != self ||
        *((u8 *)D_001A30B0 + (v << 7) + 0xD0) == 0) {
        if (vol > 0) sub[4] = func_L01_004AAE90(sub[0], flags | 0x10, self, 0x400);
    }
    if (sub[4] != -1) *(vu0_q *)(D_001A3190 + (sub[4] << 7)) = *(vu0_q *)r;
    func_003A53E8(sub[4], vol);
}

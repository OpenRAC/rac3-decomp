/* functional: high. Positional sound emitter with a falloff table row (PAL; the NTSC-U draft is a different routine): compares the listener's distance in the emitter box (lv) with the box's own reach (lw); when inside it picks the sound id (row.wC if the listener is within the unit box, else func_003A3CF0(row, 0, lv, clamped-distance, lw)), (re)starts the voice with flags 0x10 (0x14 if the row's byte 0x18 is set) and a random retrigger timer, updates its volume and position; when outside it stops the voice */
#include "vu0.h"
extern u8 *D_L01_001DFB6C;
extern u8 D_001A3190[];
extern void func_0038D000(void *, void *, void *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038CEA8(void *);
extern s32 func_00382468(s32);
extern s32 func_003A3CF0(void *, s32, f32, f32, f32);
extern s32 func_L01_004AAE90(s32, s32, void *, s32);
extern void func_003A4F28(s32);
extern s32 func_003A53E8(u32, s32);
void func_L01_003EF708(u8 *self) {
    f32 d[4] __attribute__((aligned(16)));
    f32 s[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    s32 *sub;
    f32 lw, lv, r;
    s32 flags, id, idx;
    u8 *slot;

    vec_sub_ba(d, D_L01_001E29C0, self + 0x40);
    sub = *(s32 **)(self + 8);
    s[0] = *(f32 *)(self + 0xC);
    s[2] = s[0];
    s[1] = s[0];
    d[3] = 0.0f;
    func_0038D000(v, d, self + 0x50);
    func_0038D000(w, s, self + 0x50);
    lw = func_0038CEA8(w);
    lv = func_0038CEA8(v);
    if (lv < lw) {
        flags = 0x10;
        if (fabs_asm(v[0]) <= 1.0f && fabs_asm(v[1]) <= 1.0f && fabs_asm(v[2]) <= 1.0f) {
            id = *(s32 *)(D_L01_001DFB6C + sub[0] * 32 + 0xC);
        } else {
            if (1.0f < v[0]) v[0] = 1.0f;
            else if (v[0] < -1.0f) v[0] = -1.0f;
            if (1.0f < v[1]) v[1] = 1.0f;
            else if (v[1] < -1.0f) v[1] = -1.0f;
            if (1.0f < v[2]) v[2] = 1.0f;
            else if (v[2] < -1.0f) v[2] = -1.0f;
            r = func_0038CEA8(v);
            id = func_003A3CF0(D_L01_001DFB6C + sub[0] * 32, 0, lv, r, lw);
        }
        if (D_L01_001DFB6C[sub[0] * 32 + 0x18] != 0) flags = 0x14;
        slot = (u8 *)D_001A30B0 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) != self || slot[0xD0] == 0) {
            if (func_0038CAD0(sub + 3) != 0) {
                sub[4] = func_L01_004AAE90(sub[0], flags, self, id);
                if (sub[2] > 0) sub[3] = (s32)((f32)(sub[1] + func_00382468(sub[2] - sub[1])) * 50.0f);
            } else {
                sub[4] = -1;
            }
        }
        idx = sub[4];
        if (idx == -1) return;
        func_003A53E8(idx, id);
        func_0038D000(d, v, self + 0x10);
        vec_add_ba(d, d, self + 0x40);
        *(vu0_q *)(D_001A3190 + (sub[4] << 7)) = *(vu0_q *)d;
    } else {
        idx = sub[4];
        if (idx != -1) {
            slot = (u8 *)D_001A30B0 + (idx << 7);
            if (*(u8 **)(slot + 0x100) == self && slot[0xD0] != 0) func_003A4F28(idx);
        }
        sub[4] = -1;
    }
}

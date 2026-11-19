/* functional: high. 69 diff at level 01 (register allocation/scheduling only); same loop, comparisons, stores and calls. Needs #include "vu0.h" and -mvu0-use-vf0-vf2 in its file for vec_sub_ab (retail uses lqc2/vsub.xyz). */
#include "vu0.h"
extern s32 D_001E00B4;
extern u8 *D_001E00C0;
extern s32 D_001D6694;
extern u8 D_001DF9E4;
extern u8 D_001DF9E5;
extern u8 D_001DF9E6;
extern f32 D_001DF9E8;
extern f32 D_001DF9EC;
extern f32 D_001DF9F0;
extern f32 D_001DF9F4;
extern u8 D_1A30B0[];
extern f32 func_L01_0040E4C0(void *);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern void func_003A1930(s32, s32, s32);
extern void func_003864C0(s32);

void func_L01_0043B260(u8 *obj) {
    s32 i;
    s32 best = -1;
    f32 bestd = 1000000.0f;
    vu0_v4 v;
    vu0_v4 d;
    u8 *rec;
    s32 off;

    for (i = 0; i < D_001E00B4; i++) {
        rec = D_001E00C0 + i * 32;
        v.x = *(u16 *)(rec + 4) * 0.25f;
        v.y = *(u16 *)(rec + 6) * 0.25f;
        v.z = *(u16 *)(rec + 8) * 0.25f;
        vec_sub_ab(&d, obj + 0x10, &v);
        {
            f32 dist = func_L01_0040E4C0(&d);
            if (dist < bestd) {
                bestd = dist;
                best = i;
            }
        }
    }
    if (best == -1) {
        return;
    }
    if (400.0f < bestd) {
        return;
    }
    off = best * 32;
    rec = D_001E00C0 + off;
    func_003C6F90(obj, (rec[0x12] << 16) + (rec[0x11] << 8) + rec[0x10], 0, 0, 0);
    *(s32 *)(obj + 0x38) = *(s32 *)(D_001E00C0 + off);
    if (D_001D6694 != 2) {
        rec = D_001E00C0 + off;
        if (rec[0x16] != 0) {
            *(s32 *)(D_1A30B0 + 0xB4) = *(s16 *)(rec + 0xA);
            D_1A30B0[0x40] = rec[0x13];
            D_1A30B0[0x41] = rec[0x14];
            D_1A30B0[0x42] = rec[0x15];
            D_1A30B0[0x43] |= 7;
        }
        if (D_001D6694 != 2) {
            func_003A1930(*(s16 *)(D_001E00C0 + off + 0xC), 1, 0x400);
        }
    }
    rec = D_001E00C0 + off;
    if (*(s16 *)(rec + 0x1A) < *(s16 *)(rec + 0x1C)) {
        D_001DF9E4 = rec[0x17];
        D_001DF9E5 = rec[0x18];
        D_001DF9E6 = rec[0x19];
        D_001DF9E8 = *(s16 *)(rec + 0x1A) * 1024.0f;
        D_001DF9EC = *(s16 *)(rec + 0x1C) * 1024.0f;
        D_001DF9F0 = rec[0xE];
        D_001DF9F4 = rec[0xF];
        func_003864C0(0);
    }
}

/* NTSC-U draft (Claude wave K): C of func_L39_00555C28, the NTSC-U twin of func_L39_00556638, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 34 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00555C28", whose code is not the PAL one).
 * Worker's note: 34 real diffs (aligned; the raw count is 269 from shifted branch offsets) with -mvu0-use-vf0-vf2 + @ps2as (this PAL file's line has neither, so it would also be flags). Tail of the function is the matched sibling func_L39_00556E10 (alias ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_00556638 (src/levels/shared/L39_00554D98.c) */
/* localdecomp:start func_L39_00555C28 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00556638;
typedef struct { u8 v; } Ok_00556638;

extern u8 *D_L39_0024CF20[];
extern vu0_v4 D_L39_0025F870;
extern u8 D_L39_004998A0[];
extern f32 func_L01_00443D00(void *, void *, s32, void *, f32);
extern void func_L39_00625F88(void *);
extern u8 *func_0037E0B8(void *);
extern void func_L39_00635680(void *, void *, void *, s32, s32, s32, s32);
extern void func_L39_00625860(void *, s32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B25C8_00555C28(void);
extern f32 func_L39_005B2568(f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L39_005C6980(void *, void *, s32, s32, s32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00471248(void *, void *, s32);
extern void func_L01_003D46A8(void *, s32, s32, s32, s32, f32, f32);
extern void func_L39_0051AC58(void *, void *, void *);
extern void func_L39_00556268(int);
extern void func_003BD360(void *);
typedef struct { u8 pad[0x140]; f32 x; f32 y; } C_00556638;
extern C_00556638 D_L39_0024DDC0;

void func_L39_00555C28(u8 *self, s32 a1) {
    V_00556638 b;
    V_00556638 a;
    f32 s;
    f32 ang;
    s32 i;
    u8 *p;
    u8 *q;
    Ok_00556638 ok;
    u8 *e;
    u8 *d;
    u32 w0;
    u32 w1;
    s32 n;
    s32 k;
    s32 mm;
    s32 ci;

    p = D_L39_0024CF20[*(s32 *)(*(u8 **)(self + 0x68) + 0x9C)];
    if (p != 0) {
        *(s32 *)(p + 0x2458) = 0;
        if (p[0x1A14] != 0) {
            b = *(V_00556638 *)(self + 0x10);
            a = *(V_00556638 *)(self + 0x10);
            a.z += 2.0f;
            b.z -= 0.5f;
            if (func_L01_00443D00(&a, &b, 0x80, self, *(f32 *)(p + 0x1F4)) < 1.0f) {
                *(vu0_v4 *)(self + 0x10) = D_L39_0025F870;
            }
            *(vu0_v4 *)(p + 0xA0) = *(vu0_v4 *)(self + 0x10);
            *(vu0_v4 *)(p + 0xB0) = *(vu0_v4 *)(self + 0xF0);
        }
        if (a1 != 0) {
            func_L39_00625F88(p);
            q = func_0037E0B8(*(void **)(p + 0x2524));
            if (q != 0) {
                q[0xE] = 1;
            }
            if (p[0x1A14] != 0) {
                p[0x1A0A] = 1;
                func_L39_00635680(p, self + 0x10, self + 0xF0, 0, 1, 1, 0);
            }
        } else {
            ok.v = 0;
            if (*(u8 **)(p + 0x2530) != 0 && (*(u8 **)(p + 0x2530))[0x27B] != 0) {
                e = p + 0x19E4;
                if (*e == 0) {
                    w1 = 0;
                } else {
                    n = *e;
                    k = ((u32)e - n) & 7;
                    mm = n + 1;
                    d = (u8 *)&b;
                    for (ci = 0; ci < 40; ci += 5) {
                        *d++ = D_L39_004998A0[mm + ((k + ci) & 7) * 255];
                    }
                    w0 = *(u32 *)&b ^ (u32)e;
                    w1 = *((u32 *)&b + 1) ^ w0;
                    *(u32 *)&b = w0;
                    *((u32 *)&b + 1) = w1;
                }
                if ((w1 ^ 0x31) == 0) {
                    ok.v = 1;
                }
            }
            if (ok.v != 0) {
                func_L39_00625860(p, 0);
                (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(p + 0x14) + 0x34))(p, 0x76, 0, 1, 0);
                if (p[0x1A14] == 0) {
                    p[0x1A0A] = 2;
                }
            }
        }
    }
    for (i = 0; i < 15; i++) {
        func_0037E4B8(&a, func_L39_005B2510(0.0f, 0.37f), func_L39_005B25C8_00555C28(), func_L39_005B25C8_00555C28());
        a.z += func_L39_005B2510(0.35f, 0.6f);
        vec_add_ba(&a, &a, self + 0x10);
        func_0037E4B8(&b, func_L39_005B2510(0.0025000002f, 0.020000001f), func_L39_005B25C8_00555C28(), func_L39_005B25C8_00555C28());
        func_L39_005C6980(&a, &b, 0x4F7F7F7F, 0x202020, func_L39_005B24C8(0x1E, 0x39), 150000.0f);
    }
    for (i = 0; i < 20; i++) {
        f32 dir = func_00388A28(D_L39_0024DDC0.x - *(f32 *)(self + 0x10),
                            D_L39_0024DDC0.y - *(f32 *)(self + 0x14));
        func_L39_005B2568(1.0f, 2.0f);
        b.x = *(f32 *)(self + 0x10) + func_L39_005B2568(0.0f, 0.15f);
        b.y = *(f32 *)(self + 0x14) + func_L39_005B2568(0.0f, 0.15f);
        b.z = *(f32 *)(self + 0x18) + func_L39_005B2568(0.0f, 0.15f);
        s = func_L39_005B2510(3.0f, 7.0f);
        ang = func_00389380(dir, func_L39_005B2568(0.0f, 2.6179938f));
        s *= 0.0166666675f;
        a.x = func_00388960(ang) * s;
        a.y = func_00388978(ang) * s;
        a.z = 0.0f;
        a.z = func_L39_005B2510(5.0f, 10.0f) * 0.0166666675f;
        func_L01_00471248(&b, &a, 0xAA);
    }
    func_L01_003D46A8(self, 0x4E, 0x4F, 10, 1, 1.5f, 1.2f);
    for (i = 0; i < 10; i++) {
        func_0037E4B8(&a, func_L39_005B2510(0.0f, 0.35f), func_L39_005B25C8_00555C28(), func_L39_005B25C8_00555C28());
        a.z += 0.25f;
        vec_add_ba(&a, &a, self + 0x10);
        func_0037E4B8(&b, func_L39_005B2510(0.050000004f, 0.10000001f), func_L39_005B25C8_00555C28(), 1.2217305f);
        b.z = func_L39_005B2510(3.0f, 5.0f) * 0.0166666675f;
        func_L39_0051AC58(self, &a, &b);
    }
    func_L39_00556268((int)self);
    func_003BD360(self);
}
/* localdecomp:end func_L39_00555C28 */

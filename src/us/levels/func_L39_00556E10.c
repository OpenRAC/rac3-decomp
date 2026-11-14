#include "common.h"

/* NTSC-U counterpart of func_L39_00557890 (src/levels/shared/L39_00557890.c) */
/* localdecomp:start func_L39_00556E10 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00557890;

extern s32 func_L39_005F0CE0(s32, s32, void *);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B25C8_00556E10(void);
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
extern void func_L39_00557268(int);
extern void func_003BD360(void *);
typedef struct { u8 pad[0x140]; f32 x; f32 y; } C_00557890;
extern C_00557890 D_L39_0024DDC0;

void func_L39_00556E10(u8 *self) {
    V_00557890 b;
    V_00557890 a;
    f32 s;
    f32 ang;
    s32 i;

    func_L39_005F0CE0(1, 0, self);
    for (i = 0; i < 15; i++) {
        func_0037E4B8(&a, func_L39_005B2510(0.0f, 0.37f), func_L39_005B25C8_00556E10(), func_L39_005B25C8_00556E10());
        a.z += func_L39_005B2510(0.35f, 0.6f);
        vec_add_ba(&a, &a, self + 0x10);
        func_0037E4B8(&b, func_L39_005B2510(0.0025000002f, 0.020000001f), func_L39_005B25C8_00556E10(), func_L39_005B25C8_00556E10());
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
        func_0037E4B8(&a, func_L39_005B2510(0.0f, 0.35f), func_L39_005B25C8_00556E10(), func_L39_005B25C8_00556E10());
        a.z += 0.25f;
        vec_add_ba(&a, &a, self + 0x10);
        func_0037E4B8(&b, func_L39_005B2510(0.050000004f, 0.10000001f), func_L39_005B25C8_00556E10(), 1.2217305f);
        b.z = func_L39_005B2510(3.0f, 5.0f) * 0.0166666675f;
        func_L39_0051AC58(self, &a, &b);
    }
    func_L39_00557268((int)self);
    func_003BD360(self);
}
/* localdecomp:end func_L39_00556E10 */

#include "common.h"

/* localdecomp:start func_L39_00557890 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00557890;

extern s32 func_L39_005F33E0(s32, s32, void *);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4468(f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L39_005C8CA8(void *, void *, s32, s32, s32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004749C8(void *, void *, s32);
extern void func_L01_003D6158(void *, s32, s32, s32, s32, f32, f32);
extern void func_L39_0051AE58(void *, void *, void *);
extern void func_L39_00557CE8(int);
extern void func_003C2880(void *);
typedef struct { u8 pad[0x140]; f32 x; f32 y; } C_00557890;
extern C_00557890 D_L39_0024DCC0;

void func_L39_00557890(u8 *self) {
    V_00557890 b;
    V_00557890 a;
    f32 s;
    f32 ang;
    s32 i;

    func_L39_005F33E0(1, 0, self);
    for (i = 0; i < 15; i++) {
        func_00382760(&a, func_L39_005B4410(0.0f, 0.37f), func_L39_005B44C8(), func_L39_005B44C8());
        a.z += func_L39_005B4410(0.35f, 0.6f);
        vec_add_ba(&a, &a, self + 0x10);
        func_00382760(&b, func_L39_005B4410(0.0030000003f, 0.024000002f), func_L39_005B44C8(), func_L39_005B44C8());
        func_L39_005C8CA8(&a, &b, 0x4F7F7F7F, 0x202020, func_L39_005B43C8(0x19, 0x2F), 150000.0f);
    }
    for (i = 0; i < 20; i++) {
        f32 dir = func_0038D160(D_L39_0024DCC0.x - *(f32 *)(self + 0x10),
                            D_L39_0024DCC0.y - *(f32 *)(self + 0x14));
        func_L39_005B4468(1.0f, 2.0f);
        b.x = *(f32 *)(self + 0x10) + func_L39_005B4468(0.0f, 0.15f);
        b.y = *(f32 *)(self + 0x14) + func_L39_005B4468(0.0f, 0.15f);
        b.z = *(f32 *)(self + 0x18) + func_L39_005B4468(0.0f, 0.15f);
        s = func_L39_005B4410(3.0f, 7.0f);
        ang = func_0038DAB8(dir, func_L39_005B4468(0.0f, 2.6179938f));
        s *= 0.020000001f;
        a.x = func_0038D098(ang) * s;
        a.y = func_0038D0B0(ang) * s;
        a.z = 0.0f;
        a.z = func_L39_005B4410(5.0f, 10.0f) * 0.020000001f;
        func_L01_004749C8(&b, &a, 0x8E);
    }
    func_L01_003D6158(self, 0x4E, 0x4F, 10, 1, 1.5f, 1.2f);
    for (i = 0; i < 10; i++) {
        func_00382760(&a, func_L39_005B4410(0.0f, 0.35f), func_L39_005B44C8(), func_L39_005B44C8());
        a.z += 0.25f;
        vec_add_ba(&a, &a, self + 0x10);
        func_00382760(&b, func_L39_005B4410(0.060000002f, 0.120000005f), func_L39_005B44C8(), 1.2217305f);
        b.z = func_L39_005B4410(3.0f, 5.0f) * 0.020000001f;
        func_L39_0051AE58(self, &a, &b);
    }
    func_L39_00557CE8((int)self);
    func_003C2880(self);
}
/* localdecomp:end func_L39_00557890 */

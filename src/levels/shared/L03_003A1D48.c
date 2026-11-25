#include "common.h"

/* localdecomp:start func_L03_003A1D48 */
typedef int u128_003A1D48 __attribute__((mode(TI)));
extern u8 *D_L03_001DFA80;
__asm__(".extern D_L03_001DFA80, 16");
extern void func_003C2880(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L03_003A1EB0(void *);

void func_L03_003A1D48(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    f32 p[4];
    u8 *e;
    s32 n;
    s32 c;
    f32 r;
    switch (m[0x20]) {
    case 0:
        if (v[0] == -1) {
            func_003C2880(m);
        }
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (func_00382468(10) != 0) {
            break;
        }
        func_L01_004AAC98(0, 0, m, 0x19A0);
        r = func_003824E0(0.0f, 1.0f);
        e = D_L03_001DFA80 + (v[0] << 7);
        c = (s32)(r * r * (f32)v[1]);
        if (c > 0) {
            n = c;
            do {
                f32 x;
                f32 y;
                f32 z;
                *(u128_003A1D48 *)p = *(u128_003A1D48 *)(e + 0x30);
                x = *(f32 *)(e + 0x0);
                y = *(f32 *)(e + 0x14);
                z = *(f32 *)(e + 0x28);
                p[0] += func_003824E0(-x, x);
                p[1] += func_003824E0(-y, y);
                p[2] += func_003824E0(-z, z);
                func_L03_003A1EB0(p);
            } while (--n != 0);
        }
        break;
    }
}
/* localdecomp:end func_L03_003A1D48 */

/* localdecomp:start func_L03_003A1EB0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003A1EB0;

typedef struct {
    u8 pad0[0x164];
    u8 *sounds;
} Tab_003A1EB0;
extern Tab_003A1EB0 D_L03_0021F298;
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C4C18(void *, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L03_003A1EB0(void *arg) {
    V4_003A1EB0 *origin = arg;
    V4_003A1EB0 pos;
    V4_003A1EB0 vel;
    s32 n;
    s32 i;
    s32 spin;
    s32 life;
    u8 tint;
    f32 speed;
    f32 heading;
    f32 elevation;
    f32 size;
    u8 *p;

    n = func_00382498(1, 3);
    for (i = 0; i < n; i++) {
        pos = *origin;
        func_003C4C18(&pos, 0.3f);
        tint = 0;
        speed = func_003824E0(3.0f, 5.5f) * 0.020000001f;
        heading = func_00382538();
        elevation = func_003824E0(1.0471976f, 3.1415927f);
        func_00382760(&vel, speed, heading, elevation);
        spin = func_00382468(2) == 0 ? 3 : 0xFD;
        life = (func_00382498(20, 40) * 5 + 2) / 6;
        size = func_003824E0(0.25f, 0.75f) * 210000.0f;
        p = func_L01_0046FB40(&pos, &vel, life, 0x808020, spin, 0x7F, 0, size, size, 0.00392f, 0);
        if (p != 0) {
            p[2] = D_L03_0021F298.sounds[0];
            tint = p[8] + 0x20;
        }
        size *= 0.3f;
        p = func_L01_0046FB40(&pos, &vel, life, 0xFFFFFF, spin, 0x7F, 0x40, size, size, 0.00392f, 0);
        if (p != 0) {
            p[8] = tint;
            p[2] = D_L03_0021F298.sounds[0];
        }
    }
}
/* localdecomp:end func_L03_003A1EB0 */

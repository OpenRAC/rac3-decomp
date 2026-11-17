#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L08_0039ED70 */
#include "vu0.h"
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0046B288(f32, f32, void *, s32, s32, s32);

void func_L08_0039ED70(u8 *a0) {
    vu0_v4 v;
    f32 ang;
    f32 r;
    f32 c;
    f32 d;
    s32 n;
    f32 scale;

    if (a0[0x31] == 0) {
        return;
    }
    scale = 0.7f;
    if (func_00382468(14) == 0) {
        ang = func_00382538();
        r = func_003824E0(0.0f, 0.1f);
        c = func_003824E0(0.0f, 1.0f) * scale;
        d = func_003824E0(1.0f, 2.0f) * scale;
        n = func_003824E0(180.0f, 240.0f);
        v.x = func_0038D098(ang) * r;
        v.y = func_0038D0B0(ang) * r;
        v.z = 0.0f;
        vec_add_ba(&v, &v, a0 + 0x10);
        func_L01_0046B288(c, d, &v, 0x40005840, 0x5840, (n * 5 + 2) / 6);
    }
    if (func_00382468(4) == 0) {
        ang = func_00382538();
        r = func_003824E0(0.0f, 0.1f);
        c = func_003824E0(0.0f, 3.5f) * scale;
        d = func_003824E0(3.5f, 4.5f) * scale;
        n = func_003824E0(180.0f, 240.0f);
        v.x = func_0038D098(ang) * r;
        v.y = func_0038D0B0(ang) * r;
        v.z = 0.0f;
        vec_add_ba(&v, &v, a0 + 0x10);
        func_L01_0046B288(c, d, &v, 0x30005840, 0x7040, (n * 5 + 2) / 6);
    }
}
/* localdecomp:end func_L08_0039ED70 */

/* localdecomp:start func_L08_0039EFB0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0039EFB0;

extern s32 D_L08_001DE0B0;
__asm__(".extern D_L08_001DE0B0, 4");
extern s32 D_L08_001DE0B4;
__asm__(".extern D_L08_001DE0B4, 4");
extern s32 D_L08_001DE0B8;
__asm__(".extern D_L08_001DE0B8, 4");
extern f32 D_L08_001DE0BC;
__asm__(".extern D_L08_001DE0BC, 4");
extern f32 D_L08_001DE0C0;
__asm__(".extern D_L08_001DE0C0, 4");
extern f32 D_L08_001DE0C4;
__asm__(".extern D_L08_001DE0C4, 4");
extern f32 D_L08_001DE0C8;
__asm__(".extern D_L08_001DE0C8, 4");
extern f32 D_L08_001DE0CC;
__asm__(".extern D_L08_001DE0CC, 4");
extern s32 D_L08_001DE0D0;
__asm__(".extern D_L08_001DE0D0, 4");
extern f32 D_L08_001DE0D4;
__asm__(".extern D_L08_001DE0D4, 4");
extern f32 D_L08_001DE0D8;
__asm__(".extern D_L08_001DE0D8, 4");
extern f32 D_L08_001DE0DC;
__asm__(".extern D_L08_001DE0DC, 4");
extern f32 D_L08_001DE0E0;
__asm__(".extern D_L08_001DE0E0, 4");
extern f32 D_L08_001DE0E4;
__asm__(".extern D_L08_001DE0E4, 4");
extern s32 D_L08_001DE0E8;
__asm__(".extern D_L08_001DE0E8, 4");
extern s32 D_L08_001DE0EC;
__asm__(".extern D_L08_001DE0EC, 4");
extern s32 D_L08_001DE0F0;
__asm__(".extern D_L08_001DE0F0, 4");
extern s32 D_L08_001DE0F4;
__asm__(".extern D_L08_001DE0F4, 4");
extern s32 D_L08_001DE0F8;
__asm__(".extern D_L08_001DE0F8, 4");
extern s32 D_L08_001DE0FC;
__asm__(".extern D_L08_001DE0FC, 4");
extern f32 D_L08_001DE100;
__asm__(".extern D_L08_001DE100, 4");
extern s32 D_L08_001DE104;
__asm__(".extern D_L08_001DE104, 4");
extern s32 D_L08_001DE108;
__asm__(".extern D_L08_001DE108, 4");
extern f32 D_L08_001DE10C;
__asm__(".extern D_L08_001DE10C, 4");
extern f32 D_L08_001DE110;
__asm__(".extern D_L08_001DE110, 4");
extern f32 D_L08_001DE114;
__asm__(".extern D_L08_001DE114, 4");
extern f32 D_L08_001DE118;
__asm__(".extern D_L08_001DE118, 4");
extern f32 D_L08_001DE11C;
__asm__(".extern D_L08_001DE11C, 4");
extern f32 D_L08_001DE120;
__asm__(".extern D_L08_001DE120, 4");

extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_004739D8(void *, void *, s32, s32, s16, u8, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L08_0039EFB0(u8 *m) {
    V4_0039EFB0 rot;
    V4_0039EFB0 a;
    V4_0039EFB0 b;
    V4_0039EFB0 c;
    s32 i, j, k;
    f32 f, ang, r, z, t, g, s;
    s32 c1, c2;

    rot = *(V4_0039EFB0 *)(m + 0xE0);
    for (i = 0; i < D_L08_001DE0FC; i++) {
        func_0038CF68(&a, &rot, func_003824E0(D_L08_001DE10C, D_L08_001DE110) * 0.020000001f);
        func_003C4C18(&a, D_L08_001DE120 * 0.020000001f);
        func_0038CF68(&b, &rot, D_L08_001DE100);
        vec_add_ab(&b, &b, m + 0x10);
        func_003C4C18(&b, D_L08_001DE11C);
        f = func_003824E0(D_L08_001DE114, D_L08_001DE118) * 210000.0f;
        func_L01_004739D8(&b, &a, D_L08_001DE104, D_L08_001DE108, (func_00382498(0x78, 0xF0) * 5 + 2) / 6, 0, f);
    }
    for (j = 0; j < D_L08_001DE0B0; j++) {
        a = *(V4_0039EFB0 *)(m + 0x10);
        func_003C4C18(&a, D_L08_001DE0CC);
        a.z += 0.7f;
        ang = func_00382538();
        r = func_003824E0(D_L08_001DE0DC, D_L08_001DE0C0);
        z = func_003824E0(D_L08_001DE0C4, D_L08_001DE0C8);
        qzero(&b);
        b.x += func_0038D098(ang) * (r * 0.020000001f);
        b.y += func_0038D0B0(ang) * (r * 0.020000001f);
        b.z += z * 0.020000001f;
        c = b;
        t = func_003824E0(D_L08_001DE0BC * 0.7f, D_L08_001DE0BC * 1.3f);
        c.z -= t * 0.00040000002f * (f32)((D_L08_001DE0B4 * 5 + 2) / 6);
        for (k = 0; k < D_L08_001DE0D0; k++) {
            s = func_003824E0(0.5f, 1.5f);
            b.w = s * D_L08_001DE0E0;
            c.w = s * D_L08_001DE0E4;
            func_003C4C18(&a, D_L08_001DE0D4);
            func_003C4C18(&c, D_L08_001DE0D8 * 0.020000001f);
            c1 = func_0038DBD8(D_L08_001DE0E8, D_L08_001DE0F0, func_003824E0(0.0f, 1.0f));
            c2 = func_0038DBD8(D_L08_001DE0EC, D_L08_001DE0F4, func_003824E0(0.0f, 1.0f));
            g = (f32)D_L08_001DE0B8;
            g = func_003824E0(g * 0.5f, g * 2.5f);
            func_L01_00463378(&a, &b, &c, c1, c2, (D_L08_001DE0F8 * 5 + 2) / 6, (D_L08_001DE0B4 * 5 + 2) / 6,
                (s32)((g * 5.0f + 2.0f) / 6.0f), -1);
        }
    }
}
/* localdecomp:end func_L08_0039EFB0 */

/* localdecomp:start func_L08_0039F3C8 */
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0046B288(f32, f32, void *, s32, s32, s32);

void func_L08_0039F3C8(u8 *a0) {
    f32 v[4];
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 n;
    a = func_00382538();
    b = func_003824E0(0.0f, 0.7f);
    c = func_003824E0(0.0f, 1.5f);
    d = func_003824E0(1.5f, 5.7f);
    n = func_00382498(0x8C, 0xE6);
    v[0] = func_0038D098(a) * b;
    v[1] = func_0038D0B0(a) * b;
    v[2] = 0.0f;
    vec_add_ba(v, v, a0 + 0x10);
    v[2] = v[2] + 0.025f;
    func_L01_0046B288(c, d, v, 0x38007040, 0x4040, n);
}
/* localdecomp:end func_L08_0039F3C8 */

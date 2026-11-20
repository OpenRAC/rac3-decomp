#include "common.h"

/* localdecomp:start func_L08_0039C930 */
#include "vu0.h"
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0046B288(f32, f32, void *, s32, s32, s32);

void func_L08_0039C930(u8 *a0)
{
    vu0_v4 v;
    f32 mid = 1.0f;

    if (*(u8 *)(a0 + 0x31) != 0) {
        if (func_00382468(0xE) == 0) {
            f32 ang, r, a, b;
            s32 n;

            ang = func_00382538();
            r = func_003824E0(0.0f, 0.1f);
            a = func_003824E0(0.0f, mid);
            b = func_003824E0(mid, 2.0f);
            n = func_003824E0(180.0f, 240.0f);
            v.x = func_0038D098(ang) * r;
            v.y = func_0038D0B0(ang) * r;
            v.z = 0.0f;
            vec_add_ba(&v, &v, a0 + 0x10);
            func_L01_0046B288(a, b, &v, 0x40005840, 0x5840, (n * 5 + 2) / 6);
        }
        if (func_00382468(4) == 0) {
            f32 ang, r, a, b;
            s32 n;

            ang = func_00382538();
            r = func_003824E0(0.0f, 0.1f);
            a = func_003824E0(0.0f, 3.5f);
            b = func_003824E0(3.5f, 4.5f);
            n = func_003824E0(180.0f, 240.0f);
            v.x = func_0038D098(ang) * r;
            v.y = func_0038D0B0(ang) * r;
            v.z = 0.0f;
            vec_add_ba(&v, &v, a0 + 0x10);
            func_L01_0046B288(a, b, &v, 0x30005840, 0x7040, (n * 5 + 2) / 6);
        }
    }
}
/* localdecomp:end func_L08_0039C930 */

/* localdecomp:start func_L08_0039CB60 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0039CB60;

extern s32 D_L08_001DDFF0 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DDFF0, 4");
extern s32 D_L08_001DDFF4 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DDFF4, 4");
extern s32 D_L08_001DDFF8 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DDFF8, 4");
extern f32 D_L08_001DDFFC __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DDFFC, 4");
extern f32 D_L08_001DE000 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE000, 4");
extern f32 D_L08_001DE004 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE004, 4");
extern f32 D_L08_001DE008 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE008, 4");
extern f32 D_L08_001DE00C __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE00C, 4");
extern s32 D_L08_001DE010 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE010, 4");
extern f32 D_L08_001DE014 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE014, 4");
extern f32 D_L08_001DE018 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE018, 4");
extern f32 D_L08_001DE01C __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE01C, 4");
extern f32 D_L08_001DE020 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE020, 4");
extern f32 D_L08_001DE024 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE024, 4");
extern s32 D_L08_001DE028 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE028, 4");
extern s32 D_L08_001DE02C __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE02C, 4");
extern s32 D_L08_001DE030 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE030, 4");
extern s32 D_L08_001DE034 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE034, 4");
extern s32 D_L08_001DE038 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE038, 4");
extern s32 D_L08_001DE03C __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE03C, 4");
extern f32 D_L08_001DE040 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE040, 4");
extern s32 D_L08_001DE044 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE044, 4");
extern s32 D_L08_001DE048 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE048, 4");
extern f32 D_L08_001DE04C __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE04C, 4");
extern f32 D_L08_001DE050 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE050, 4");
extern f32 D_L08_001DE054 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE054, 4");
extern f32 D_L08_001DE058 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE058, 4");
extern f32 D_L08_001DE05C __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE05C, 4");
extern f32 D_L08_001DE060 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE060, 4");
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004739D8(void *, void *, s32, s32, s16, u8, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L08_0039CB60(u8 *m) {
    V_0039CB60 dir;
    V_0039CB60 a;
    V_0039CB60 b;
    V_0039CB60 c;
    s32 i;
    s32 j;
    s32 k;

    dir = *(V_0039CB60 *)(m + 0xE0);
    for (i = 0; i < D_L08_001DE03C; i++) {
        f32 s;
        func_0038CF68(&a, &dir, func_003824E0(D_L08_001DE04C, D_L08_001DE050) * 0.020000001f);
        func_003C4C18(&a, D_L08_001DE060 * 0.020000001f);
        func_0038CF68(&b, &dir, D_L08_001DE040);
        vec_add_ab(&b, &b, m + 0x10);
        func_003C4C18(&b, D_L08_001DE05C);
        s = func_003824E0(D_L08_001DE054, D_L08_001DE058) * 210000.0f;
        func_L01_004739D8(&b, &a, D_L08_001DE044, D_L08_001DE048, (func_00382498(0x78, 0xF0) * 5 + 2) / 6, 0, s);
    }
    for (j = 0; j < D_L08_001DDFF0; j++) {
        f32 ang;
        f32 r;
        f32 z;
        f32 n;
        a = *(V_0039CB60 *)(m + 0x10);
        func_003C4C18(&a, D_L08_001DE00C);
        a.z += 1.3f;
        ang = func_00382538();
        r = func_003824E0(D_L08_001DE01C, D_L08_001DE000);
        z = func_003824E0(D_L08_001DE004, D_L08_001DE008);
        qzero(&b);
        b.x += func_0038D098(ang) * (r * 0.020000001f);
        b.y += func_0038D0B0(ang) * (r * 0.020000001f);
        b.z += z * 0.020000001f;
        c = b;
        c.z -= func_003824E0(D_L08_001DDFFC * 0.7f, D_L08_001DDFFC * 1.3f) * 0.00040000002f * (f32)((D_L08_001DDFF4 * 5 + 2) / 6);
        for (k = 0; k < D_L08_001DE010; k++) {
            s32 c1;
            s32 c2;
            f32 f;
            f = func_003824E0(0.5f, 1.5f);
            b.w = f * D_L08_001DE020;
            c.w = f * D_L08_001DE024;
            func_003C4C18(&a, D_L08_001DE014);
            func_003C4C18(&c, D_L08_001DE018 * 0.020000001f);
            c1 = func_0038DBD8(D_L08_001DE028, D_L08_001DE030, func_003824E0(0.0f, 1.0f));
            c2 = func_0038DBD8(D_L08_001DE02C, D_L08_001DE034, func_003824E0(0.0f, 1.0f));
            n = (f32)D_L08_001DDFF8;
            func_L01_00463378(&a, &b, &c, c1, c2, (D_L08_001DE038 * 5 + 2) / 6, (D_L08_001DDFF4 * 5 + 2) / 6,
                (func_003824E0(n * 0.5f, n * 2.5f) * 5.0f + 2.0f) / 6.0f, -1);
        }
    }
}
/* localdecomp:end func_L08_0039CB60 */

/* localdecomp:start func_L08_0039CF78 */
#include "vu0.h"
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0046B288(f32, f32, void *, s32, s32, s32);

void func_L08_0039CF78(u8 *a0) {
    f32 v[4];
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 n;
    a = func_00382538();
    b = func_003824E0(0.0f, 1.0f);
    c = func_003824E0(0.0f, 1.5f);
    d = func_003824E0(1.5f, 7.0f);
    n = func_00382498(0x8C, 0xE6);
    v[0] = func_0038D098(a) * b;
    v[1] = func_0038D0B0(a) * b;
    v[2] = 0.0f;
    vec_add_ba(v, v, a0 + 0x10);
    v[2] = v[2] + 0.025f;
    func_L01_0046B288(c, d, v, 0x38007040, 0x4040, n);
}
/* localdecomp:end func_L08_0039CF78 */

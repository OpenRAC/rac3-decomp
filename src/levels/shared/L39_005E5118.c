#include "common.h"

/* localdecomp:start func_L39_005E5118 */
typedef struct {
    s32 f0;
    void *f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 a24[4];
    f32 a34[4];
    f32 a44[4];
} S_005E5118;

__asm__(".extern D_001D8374_sda, 4");
__asm__(".extern D_001D8388_sda, 4");
__asm__(".extern D_001D838C_sda, 4");
__asm__(".extern D_001D8390_sda, 4");
__asm__(".extern D_001D8394_sda, 4");
__asm__(".extern D_001D8398_sda, 4");
__asm__(".extern D_001D839C_sda, 4");
extern s32 *D_L39_00241120;
extern s32 D_001D8374_sda;
extern f32 D_001D8388_sda;
extern f32 D_001D838C_sda;
extern f32 D_001D8390_sda;
extern f32 D_001D8394_sda;
extern f32 D_001D8398_sda;
extern f32 D_001D839C_sda;

extern s32 func_L01_00517688(void);
extern void *func_L39_005E3A40(s32);
extern void *func_003B9BD0(s32);
extern s32 func_L39_005E7E30(void *, void *);
extern void func_003BABB0(void *, s32, f32, f32, f32, f32, f32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_003BA358(void *, s32, s32, s32);
extern void func_L39_005E5768(void);
extern s32 func_11D534(void *, s32, s32);
extern void func_0038E150(s32);
extern void func_L39_005E9138(s32, s32, f32, f32 *, f32 *);
extern void func_L39_005E8F98(void *, s32, s32, f32, f32);
extern void func_L01_00498F18(void *, s32, s32);

void func_L39_005E5118(void) {
    S_005E5118 s;
    f32 v[2];
    f32 t;
    f32 u;
    s32 idx = 0;
    s32 mode;
    s32 i;
    s32 j;
    f32 a = 0.5f;
    f32 b = 10.439128f;
    f32 c = a;
    f32 r = 0.817342f;
    f32 k1;
    f32 k2;
    f32 k3;
    f32 k4;

    mode = func_L01_00517688();
    switch (mode) {
    case 0:
        break;
    case 1:
        idx = 1;
        break;
    case 2:
        idx = 2;
        break;
    case 3:
        idx = 3;
        break;
    }
    if (*D_L39_00241120 >= 3) {
        c = 0.0f;
        b = 10.0f;
        switch (mode) {
        case 0:
        case 2:
            a = 0.5f;
            break;
        case 1:
        case 3:
            a = 1.5f;
            break;
        }
    } else if (*D_L39_00241120 >= 2) {
        c = 0.0f;
        b = 10.0f;
        switch (mode) {
        case 0:
            a = 0.5f;
            break;
        case 1:
            a = 1.0f;
            break;
        }
    }
    s.f0 = 0x200;
    D_001D8374_sda = 4;
    D_001D8390_sda = 0.139494f;
    D_001D8388_sda = 0.290759f;
    s.f4 = func_L39_005E3A40(mode);
    s.f1C = D_001D8388_sda;
    s.f20 = D_001D8390_sda;
    s.f8 = 0x14;
    s.fC = D_001D8374_sda;
    s.f10 = D_001D8374_sda > 8 ? 8 : D_001D8374_sda;
    s.f14 = 2;
    s.f18 = 1.0f;
    s.a24[0] = D_001D8394_sda;
    s.a24[1] = D_001D8398_sda;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = D_001D839C_sda;
    s.a34[1] = D_001D8398_sda - D_001D8394_sda - D_001D839C_sda;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_L39_005E7E30(func_003B9BD0(idx), &s);
    k1 = 0.0425f;
    k2 = 0.35f;
    k3 = 0.00666f;
    k4 = 0.03f;
    func_003BABB0(func_003B9BD0(idx), 0, a, r, 0.045f, k1, k2);
    func_003BABD0(func_003B9BD0(idx), a, c, r, b);
    func_003BA4E0(func_003B9BD0(idx), 1, D_001D838C_sda, k3, k4);
    func_003BA358(func_003B9BD0(idx), 0, 1, 3);
    func_003BA358(func_003B9BD0(idx), 1, 2, 3);
    func_L39_005E5768();
    if (*D_L39_00241120 >= 2) {
        t = 1.0f;
        func_11D534(v, 0, 8);
        func_0038E150(1);
        func_L39_005E9138(s.f10, s.f14, D_001D8398_sda - D_001D8394_sda, &t, v);
        if (t > 1.0f) {
            t = 1.0f;
        }
        u = t;
        s.a34[0] = v[0];
        s.a34[1] = v[1];
        s.f18 = u;
        func_L39_005E7E30(func_003B9BD0(idx), &s);
        func_003BABB0(func_003B9BD0(idx), 0, 0.5f, r, 0.09f, k1, k2);
        func_003BABD0(func_003B9BD0(idx), a, c, r, b);
        func_003BA4E0(func_003B9BD0(idx), 1, D_001D838C_sda, k3, k4);
        func_003BA358(func_003B9BD0(idx), 0, 1, 3);
        func_003BA358(func_003B9BD0(idx), 1, 2, 3);
        if (*D_L39_00241120 >= 2) {
            u = u + u;
        }
        for (i = 0; i < s.f10; i++) {
            for (j = 0; j < s.f14; j++) {
                func_L39_005E8F98(func_003B9BD0(idx), j, i + 1, t, u);
            }
        }
        func_L39_005E5768();
    }
    func_L01_00498F18(func_003B9BD0(idx), 0, 1);
    func_L01_00498F18(func_003B9BD0(idx), 1, 1);
}
/* localdecomp:end func_L39_005E5118 */

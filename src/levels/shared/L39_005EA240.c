#include "common.h"

/* declared by functions of L39_005E9FA0.c, which this file was cut from */
extern s32 func_L01_00517688(void);
extern s32 *func_003B9BD0(s32);

/* localdecomp:start func_L39_005EA240 */
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
} S_005EA240;

__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern s32 D_L39_002B6940[];
extern char D_L39_00243D48[];
extern char D_L39_00243D50[];
extern char D_L39_00243D58[];
__asm__(".extern D_001D858C_sda, 4");
__asm__(".extern D_001D8590_sda, 4");
__asm__(".extern D_001D8594_sda, 4");
__asm__(".extern D_001D8598_sda, 4");
__asm__(".extern D_001D859C_sda, 4");
extern f32 D_001D858C_sda;
extern f32 D_001D8590_sda;
extern f32 D_001D8594_sda;
extern f32 D_001D8598_sda;
extern f32 D_001D859C_sda;

extern s32 func_L01_00517688(void);
extern void *func_L39_005E3A40(s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_L39_005E7E30(void *, void *);
extern s32 func_L39_005E7FF8(void *, s32, s32);
extern void func_003BABB0(void *, f32, f32, f32, f32, f32, s32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA358(void *, s32, s32, s32);
extern void func_L01_00498F18(void *, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_00120048(s32, char *, ...);
extern void func_0011D534(void *, s32, s32);
extern void func_0038E150(s32);
extern s32 func_0038E548(s32, s32, f32);
extern void func_L39_005E9138(f32, s32, s32, f32 *, f32 *);
extern void func_L39_005E8F98(void *, s32, s32, f32, f32);

static __inline__ void setFrame_005EA240(void *p, f32 x, f32 y, f32 w, f32 h, f32 r) {
    func_003BABB0(p, x, y, w, h, r, 0);
}

void func_L39_005EA240(void) {
    S_005EA240 s;
    f32 vec[4];
    f32 scale;
    f32 w;
    s32 idx = 0;
    s32 v;
    s32 i;
    s32 best;
    f32 a;
    f32 b;
    f32 c;

    switch (func_L01_00517688()) {
    case 0: idx = 0; break;
    case 1: idx = 1; break;
    case 2: idx = 2; break;
    case 3: idx = 3; break;
    }
    v = func_L01_00517688();
    a = 0.5f;
    b = 0.72764f;
    c = 0.5f;
    if (*D_L39_00241120 >= 3) {
        a = 0.0f;
        b = 10.0f;
        switch (v) {
        case 0: case 2: c = 0.5f; break;
        case 1: case 3: c = 1.5f; break;
        }
    } else if (*D_L39_00241120 >= 2) {
        a = 0.0f;
        b = 10.0f;
        switch (v) {
        case 0: c = 0.5f; break;
        case 1: c = 1.0f; break;
        }
    }
    D_001D8590_sda = 0.139494f;
    D_001D858C_sda = 0.221012f;
    s.f0 = 0x200;
    s.f4 = func_L39_005E3A40(v);
    s.f8 = 20;
    s.fC = 5;
    s.f10 = 5;
    s.f14 = 2;
    s.f18 = 1.0f;
    s.f1C = D_001D858C_sda;
    s.f20 = D_001D8590_sda;
    s.a24[0] = D_001D8594_sda;
    s.a24[1] = D_001D8598_sda;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = D_001D859C_sda;
    s.a34[1] = D_001D8598_sda - D_001D8594_sda - D_001D859C_sda;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_L39_005E7E30(func_003B9BD0(idx), &s);
    setFrame_005EA240(func_003B9BD0(idx), c, 0.815506f, 0.045f, 0.0425f, 0.35f);
    func_003BA4E0(func_003B9BD0(idx), 1, 0.023f, 0.00666f, 0.03f);
    func_003BABD0(func_003B9BD0(idx), c, a, 0.815506f, b);
    func_003BA358(func_003B9BD0(idx), 0, 1, 3);
    func_003BA358(func_003B9BD0(idx), 1, 2, 3);
    func_L01_00498F18(func_003B9BD0(idx), 0, 1);
    func_L01_00498F18(func_003B9BD0(idx), 1, 1);
    func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 0, 0), D_L39_00243D48, func_00381FF0(0x15E3));
    func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 0, 1), D_L39_00243D50, func_00381FF0(0x191));
    func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 0, 2), D_L39_00243D50, func_00381FF0(0x190));
    func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 0, 3), D_L39_00243D50, func_00381FF0(0x23C));
    func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 0, 4), D_L39_00243D50, func_00381FF0(0x18F));
    func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 1, 0), D_L39_00243D48, func_00381FF0(0x1359));
    func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 1, 1), D_L39_00243D48, func_00381FF0(0x192));
    func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 1, 2), D_L39_00243D48, func_00381FF0(0x192));
    func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 1, 3), D_L39_00243D58);
    func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 1, 4), D_L39_00243D48, func_00381FF0(0x176));
    if (*D_L39_00241120 >= 2) {
                scale = 1.0f;
        func_0011D534(vec, 0, 8);
        best = 0;
        func_0038E150(1);
        for (i = 0; i < 3; i++) {
            s32 t = func_0038E548(D_L39_002B6940[i], -1, 1.0f);
            if (best < t) {
                best = t;
                func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 1, 0), D_L39_00243D48, D_L39_002B6940[i]);
            }
        }
        func_L39_005E9138(D_001D8598_sda - D_001D8594_sda, s.f10, s.f14, &scale, vec);
        D_001D859C_sda = 0.53f;
        if (scale > 1.0f) {
            scale = 1.0f;
        }
                w = scale;
        s.f18 = w;
        s.a34[0] = vec[0];
        s.a34[1] = vec[1];
        func_L39_005E7E30(func_003B9BD0(idx), &s);
        setFrame_005EA240(func_003B9BD0(idx), 0.5f, 0.815506f, 0.09f, 0.0425f, 0.35f);
        func_003BA4E0(func_003B9BD0(idx), 1, 0.023f, 0.00666f, 0.03f);
        func_003BABD0(func_003B9BD0(idx), c, a, 0.815506f, b);
        func_003BA358(func_003B9BD0(idx), 0, 1, 3);
        func_003BA358(func_003B9BD0(idx), 1, 2, 3);
        func_L01_00498F18(func_003B9BD0(idx), 0, 1);
        func_L01_00498F18(func_003B9BD0(idx), 1, 1);
        func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 0, 0), D_L39_00243D48, func_00381FF0(0x15E3));
        func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 0, 1), D_L39_00243D50, func_00381FF0(0x191));
        func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 0, 2), D_L39_00243D50, func_00381FF0(0x190));
        func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 0, 3), D_L39_00243D50, func_00381FF0(0x23C));
        func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 0, 4), D_L39_00243D50, func_00381FF0(0x18F));
        func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 1, 0), D_L39_00243D48, func_00381FF0(0x1359));
        func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 1, 1), D_L39_00243D48, func_00381FF0(0x192));
        func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 1, 2), D_L39_00243D48, func_00381FF0(0x192));
        func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 1, 3), D_L39_00243D58);
        func_00120048(func_L39_005E7FF8(func_003B9BD0(idx), 1, 4), D_L39_00243D48, func_00381FF0(0x176));
        if (*D_L39_00241120 >= 2) {
            w += w;
        }
        func_L39_005E8F98(func_003B9BD0(idx), 0, 1, scale, w);
        func_L39_005E8F98(func_003B9BD0(idx), 0, 2, scale, w);
        func_L39_005E8F98(func_003B9BD0(idx), 0, 3, scale, w);
        func_L39_005E8F98(func_003B9BD0(idx), 0, 4, scale, w);
        func_L39_005E8F98(func_003B9BD0(idx), 0, 5, scale, w);
        func_L39_005E8F98(func_003B9BD0(idx), 1, 1, scale, w);
        func_L39_005E8F98(func_003B9BD0(idx), 1, 2, scale, w);
        func_L39_005E8F98(func_003B9BD0(idx), 1, 3, scale, w);
        func_L39_005E8F98(func_003B9BD0(idx), 1, 4, scale, w);
        func_L39_005E8F98(func_003B9BD0(idx), 1, 5, scale, w);
    }
}
/* localdecomp:end func_L39_005EA240 */

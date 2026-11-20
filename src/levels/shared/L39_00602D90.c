#include "common.h"

/* localdecomp:start func_L39_00602D90 */
extern u8 func_L01_00437540(void);
extern void func_L01_00430110(u8);
extern s32 func_L01_003C55F8(void);
extern void func_L39_005872D8(void);
extern void func_003AA320(void *, f32, f32, s32, f32, f32, f32);
typedef struct { u8 pad[0xB0]; f32 fB0; } S_00602D90;
extern S_00602D90 D_L39_0025D6C0;
extern s32 D_L39_00242A50;
extern s32 D_L39_00242914;
extern s32 D_L39_00241118;

void func_L39_00602D90(u8 *obj, s32 a1, u32 a2, f32 p0, f32 p1, f32 p2, f32 p3) {
    u8 saved;
    f32 old, k, sc, ny, t, y1, x1, sz;
    u32 col;
    u8 *A;
    u8 *B;

    saved = func_L01_00437540();
    func_L01_00430110(0);
    if (D_L39_00242A50 != 0) {
        old = D_L39_0025D6C0.fB0;
        D_L39_0025D6C0.fB0 = 0.62f;
        func_L39_005872D8();
        k = 1.0f;
        t = (p1 - p0 - 26.0f) / 112.0f;
        t = t * 0.3110000193f + 0.0375000015f;
        if (D_L39_00242914 == 1) {
            k = 1.5f;
        } else if (D_L39_00242914 >= 2) {
            if (D_L39_00242914 < 4) k = 2.0f;
        }
        sc = func_L01_003C55F8() == 1 ? 0.9f : 1.0f;
        ny = -k;
        A = obj + 0x50D0;
        col = (a1 << 24) | a2;
        sz = 16.0f;
        func_003AA320(*(void **)(A + (D_L39_00241118 << 2)), p2, p0, col, ny, sc * k, t);
        B = obj + 0x50E0;
        func_003AA320(*(void **)(A + (D_L39_00241118 << 2)), p3, p0, col, k, sc * k, t);
        x1 = p2 + sz;
        y1 = p3 - sz;
        t = (p3 - p2 - 150.0f) / 306.0f;
        t = t * 0.4330000281f + 0.1019999981f;
        func_003AA320(*(void **)(B + (D_L39_00241118 << 2)), x1, p0, col, ny, k, t);
        func_003AA320(*(void **)(B + (D_L39_00241118 << 2)), y1, p0, col, k, k, t);
        func_003AA320(*(void **)(B + (D_L39_00241118 << 2)), x1, p1, col, ny, ny, t);
        func_003AA320(*(void **)(B + (D_L39_00241118 << 2)), y1, p1, col, k, ny, t);
        D_L39_0025D6C0.fB0 = old;
        func_L39_005872D8();
        func_L01_00430110(saved);
    }
}
/* localdecomp:end func_L39_00602D90 */

/* localdecomp:start func_L39_006030C8 */
extern s32 *D_L39_00241120;
extern f32 D_L39_00241140;
extern f32 D_L39_00241150;
extern s32 func_00381FF0(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L39_006025F0(void *, s32, f32, f32, s32);

void func_L39_006030C8(char *a0, s32 a1, s32 id, s32 val, s32 a4) {
    f32 x;
    f32 y;
    s32 flag;
    s32 n;
    flag = 1;
    x = 255.0f;
    y = 135.0f;
    if (a4 == -1) {
        a4 = 100;
    }
    n = a1 * 0x230;
    func_00120048((u8 *)(a0 + n + 0x4668), (u8 *)func_00381FF0(id), val);
    n = *D_L39_00241120;
    if (n >= 2) {
        s32 i = n - 1;
        x = (s32)(x / D_L39_00241140 * (&D_L39_00241140)[i]);
        y = (s32)(y / D_L39_00241150 * (&D_L39_00241150)[i]);
        flag = 0;
    }
    func_L39_006025F0(a0 + (a1 * 0x230 + 0x45E0), flag, x, y, a4);
}
/* localdecomp:end func_L39_006030C8 */

LINKER_REMNANT("asm/levels", func_L39_00603228);

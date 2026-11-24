#include "common.h"

/* localdecomp:start func_L01_004ACF48 */
#include "vu0.h"
typedef struct {
    vu0_v4 m[4];
    s32 c[4];
    struct { f32 x, y; } uv[4];
    long x70, x78, x80, x88;
} S_4ACF48;
__asm__(".extern D_L01_001D99A0, 8");
extern f32 D_L01_001D99A0[2];
__asm__(".extern D_L01_001D99C0, 4");
extern s32 D_L01_001D99C0;
__asm__(".extern D_L01_001D99D0, 8");
extern f32 D_L01_001D99D0[2];
extern f32 D_L01_001D99A4[2];
extern u8 D_L01_002EDE40[];
extern long func_00389598(s32);
extern void func_003C2EC0(void *, s32, void *);
extern s32 func_00382468(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

void func_L01_004ACF48(u8 *a) {
    S_4ACF48 s;
    vu0_v4 mat[4];
    s32 n;
    s32 j;
    s32 i;
    s32 q;
    s32 k;
    u8 *e;
    u8 *tbl;
    s32 col;
    f32 t;

    n = D_L01_001D99C0;
    tbl = D_L01_002EDE40;
    s.x78 = func_00389598(5);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.x70 = 0;
    for (q = 0; q < 4; q++) {
        s.uv[q].x = D_L01_001D99A0[q * 2];
        s.uv[q].y = D_L01_001D99A4[q * 2];
    }
    func_003C2EC0(a, 1, mat);
    for (j = 0; j < n; j++) {
        k = *(u8 *)(a + 0xBC);
        if (*(s16 *)(a + 0xB2) != 0) {
            k += func_00382468(*(s16 *)(a + 0xB2));
        }
        e = (u8 *)(j * 16 + (s32)tbl);
        col = (k << 24) | 0x2058B0;
        t = (f32)k * (*(f32 *)(e + 0xC) / 40.0f);
        for (i = 0; i < 4; i++) {
            s.c[i] = col;
            func_0038CE20(&s.m[i], D_L01_001D99D0 + i * 4, t);
            vec_add_ba(&s.m[i], &s.m[i], tbl + j * 16);
            func_0038D000(&s.m[i], &s.m[i], mat);
            vec_add_ab(&s.m[i], &s.m[i], &mat[3]);
        }
        func_003D2DA0(&s, 0, 0);
    }
}
/* localdecomp:end func_L01_004ACF48 */

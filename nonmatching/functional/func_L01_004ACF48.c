/* functional: medium. Read against the asm. Retail's stack block (corners, colours, uv pairs, packet header, matrix, count) is one struct passed to func_003D2DA0 by address, so it is one struct here (Quad_004ACF48); func_00382468 is called with the s16 left in $a0 (h) as retail leaves it (passthrough, probably rand(h)); vadd.xyz as float adds with w kept. Frame size differs from retail (bytes only). */
#include "vu0.h"
extern s32 D_L01_001D99C0;
extern f32 D_L01_001D99A0[];
extern f32 D_L01_001D99A4[];
extern u8 D_L01_001D99D0[];
extern u8 D_L01_002EDE40[];
__asm__(".extern D_L01_001D99C0, 4");
__asm__(".extern D_L01_001D99A0, 8");
__asm__(".extern D_L01_001D99D0, 16");
extern s64 func_00389598(s32);
extern void func_003C2EC0(void *, s32, void *);
extern s32 func_00382468(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

/* one block on retail's stack, passed to func_003D2DA0 by its address */
typedef struct {
    vu0_v4 corner[4];
    s32 color[4];
    f32 uv[8];
    s64 w70;
    s64 w78;
    s64 w80;
    s64 w88;
    vu0_v4 mat[4];
    s32 count;
    void *matp;
} Quad_004ACF48;

void func_L01_004ACF48(u8 *a0) {
    Quad_004ACF48 s;
    s32 i;
    s32 j;
    s32 h;
    s32 col;
    s32 word;
    f32 scale;
    u8 *e;
    u8 *t;

    s.count = D_L01_001D99C0;
    s.w78 = func_00389598(5);
    s.matp = s.mat;
    s.w80 = ((s64)0xFF90 << 32) | 0x260;
    s.w88 = ((s64)0x8000 << 24) | 0x48;
    s.w70 = 0;
    for (j = 0; j < 4; j++) {
        s.uv[j * 2] = D_L01_001D99A0[j * 2];
        s.uv[j * 2 + 1] = D_L01_001D99A4[j * 2];
    }
    func_003C2EC0(a0, 1, s.matp);
    for (i = 0; i < s.count; i++) {
        h = *(s16 *)(a0 + 0xB2);
        col = a0[0xBC];
        if (h != 0) {
            col = col + func_00382468(h);
        }
        e = D_L01_002EDE40 + i * 16;
        scale = (f32)col * (*(f32 *)(e + 0xC) / 40.0f);
        word = (col << 24) | 0x2058B0;
        t = D_L01_001D99D0;
        for (j = 0; j < 4; j++, t += 16) {
            s.color[j] = word;
            func_0038CE20(&s.corner[j], t, scale);
            s.corner[j].x = s.corner[j].x + *(f32 *)(e + 0);
            s.corner[j].y = s.corner[j].y + *(f32 *)(e + 4);
            s.corner[j].z = s.corner[j].z + *(f32 *)(e + 8);
            func_0038D000(&s.corner[j], &s.corner[j], s.matp);
            s.corner[j].x = s.corner[j].x + s.mat[3].x;
            s.corner[j].y = s.corner[j].y + s.mat[3].y;
            s.corner[j].z = s.corner[j].z + s.mat[3].z;
        }
        func_003D2DA0(&s, 0, 0);
    }
}

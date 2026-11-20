/* functional: medium. Scheduling and register use differ; control flow and calls follow retail, including the order of the rand()-based func_00382468 calls (slots 0..3 upwards); gp-relative data named by address. */
#include "vu0.h"
typedef struct { float x, y, z, w; } plain_v4;
static void plain_add(void *d, void *a, void *b) {
    plain_v4 *pd = d, *pa = a, *pb = b;
    pd->x = pa->x + pb->x; pd->y = pa->y + pb->y; pd->z = pa->z + pb->z; pd->w = pa->w;
}
static void plain_sub(void *d, void *a, void *b) {
    plain_v4 *pd = d, *pa = a, *pb = b;
    pd->x = pa->x - pb->x; pd->y = pa->y - pb->y; pd->z = pa->z - pb->z; pd->w = pa->w;
}
extern f32 D_L01_001DEC74_003C88E0;
__asm__(".extern D_L01_001DEC74_003C88E0, 4");
extern f32 D_L01_001DEDB0_003C88E0;
__asm__(".extern D_L01_001DEDB0_003C88E0, 4");
extern f32 D_L01_001DEDB4_003C88E0;
__asm__(".extern D_L01_001DEDB4_003C88E0, 4");
extern f32 D_L01_001DEF68_003C88E0;
__asm__(".extern D_L01_001DEF68_003C88E0, 4");
extern f32 D_L01_001DEF6C_003C88E0;
__asm__(".extern D_L01_001DEF6C_003C88E0, 4");
extern f32 D_L01_001DEF40_003C88E0;
__asm__(".extern D_L01_001DEF40_003C88E0, 4");
extern f32 D_L01_001DEF44_003C88E0;
__asm__(".extern D_L01_001DEF44_003C88E0, 4");
extern f32 D_L01_001DEF48_003C88E0;
__asm__(".extern D_L01_001DEF48_003C88E0, 4");
extern f32 D_L01_001DEF4C_003C88E0;
__asm__(".extern D_L01_001DEF4C_003C88E0, 4");
extern f32 D_L01_001DEF58_003C88E0;
__asm__(".extern D_L01_001DEF58_003C88E0, 4");
extern f32 D_L01_001DEF5C_003C88E0;
__asm__(".extern D_L01_001DEF5C_003C88E0, 4");
extern f32 D_L01_001DEF60_003C88E0;
__asm__(".extern D_L01_001DEF60_003C88E0, 4");
extern f32 D_L01_001DEF64_003C88E0;
__asm__(".extern D_L01_001DEF64_003C88E0, 4");
extern s32 D_L01_001DEF34_003C88E0;
__asm__(".extern D_L01_001DEF34_003C88E0, 4");
extern s32 D_L01_001DEF38_003C88E0;
__asm__(".extern D_L01_001DEF38_003C88E0, 4");
extern s32 D_L01_001DEF3C_003C88E0;
__asm__(".extern D_L01_001DEF3C_003C88E0, 4");
extern s32 D_L01_001DEF50_003C88E0;
__asm__(".extern D_L01_001DEF50_003C88E0, 4");
extern s32 D_L01_001DEF54_003C88E0;
__asm__(".extern D_L01_001DEF54_003C88E0, 4");
extern s32 D_L01_001DEF30_003C88E0;
__asm__(".extern D_L01_001DEF30_003C88E0, 4");
extern vu0_v4 D_L01_001DEDA0;
extern vu0_v4 D_L01_001DED60[];
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DBCA0;
extern void func_003A9440(s32, unsigned long);
extern u8 func_00382468(s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_0038DC20(void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);

void func_L01_003C88E0(u8 *obj, u8 *s) {
    vu0_v4 base, q10, q20, q30, p40, pk[4];
    s32 i, j, k;
    f32 fade, phase_base, ph, a, b, f21, f22;
    s32 color, al;
    for (k = 0; k < 4; k++) { /* retail walks the slots upwards (counter 3..0, pointer s+0x70/0x80 rising): rand() order matters */
        if (*(u8 **)(s + 0x70 + k * 4)) (*(u8 **)(s + 0x70 + k * 4))[8] = func_00382468(0xFF);
        if (*(u8 **)(s + 0x80 + k * 4)) (*(u8 **)(s + 0x80 + k * 4))[8] = func_00382468(0xFF);
    }
    fade = *(f32 *)(s + 0xC8) / (D_L01_001DEC74_003C88E0 * 0.0200000014f);
    func_0038D000(&base, &D_L01_001DEDA0, obj + 0xC0);
    plain_add(&base, &base, obj + 0x10);
    base.w = D_L01_001DEDB0_003C88E0;
    if (func_0038DC20(&base, D_L01_001DEDB4_003C88E0) == -1) return;
    fade = (fade - D_L01_001DEF68_003C88E0) / (D_L01_001DEF6C_003C88E0 - D_L01_001DEF68_003C88E0);
    D_L01_001DBCA0 |= 1;
    if (1.0f < fade) fade = 1.0f;
    else if (fade < 0.1f) fade = 0.1f;
    phase_base = (f32)(D_L01_001DFB40 % D_L01_001DEF34_003C88E0) / (f32)D_L01_001DEF34_003C88E0;
    func_003A9440(8, 0);
    func_003A9440(0x47, 0x513F1);
    for (i = 0; i < 4; i++) {
        if (*(u8 **)(s + 0x70 + i * 4)) (*(u8 **)(s + 0x70 + i * 4))[8] = func_00382468(0xFF);
        if (*(u8 **)(s + 0x80 + i * 4)) (*(u8 **)(s + 0x80 + i * 4))[8] = func_00382468(0xFF);
        *(vu0_q *)&q20 = *(vu0_q *)(obj + 0xE0);
        *(vu0_q *)&q10 = *(vu0_q *)(obj + 0xD0);
        *(vu0_q *)&q30 = *(vu0_q *)(obj + 0xC0);
        func_0038D000(&p40, &D_L01_001DED60[i], obj + 0xC0);
        plain_add(&p40, &p40, obj + 0x10);
        for (j = 0; j < D_L01_001DEF3C_003C88E0; j++) {
            ph = (f32)((D_L01_001DFB40 + D_L01_001DEF38_003C88E0 / D_L01_001DEF3C_003C88E0 * j) % D_L01_001DEF38_003C88E0) /
                 (f32)D_L01_001DEF38_003C88E0;
            if (i & 1) {
                ph += 0.5f;
                if (1.0f < ph) ph -= 1.0f;
            }
            ph = ph * ph;
            if (i < 2) {
                a = D_L01_001DEF40_003C88E0;
                b = D_L01_001DEF44_003C88E0 - a;
                f21 = D_L01_001DEF4C_003C88E0 - D_L01_001DEF48_003C88E0;
                f21 = f21 * ph + D_L01_001DEF48_003C88E0;
            } else {
                a = D_L01_001DEF58_003C88E0;
                b = D_L01_001DEF5C_003C88E0 - a;
                f21 = D_L01_001DEF64_003C88E0 - D_L01_001DEF60_003C88E0;
                f21 = f21 * ph + D_L01_001DEF60_003C88E0;
            }
            f22 = b * ph * fade + a;
            color = func_0038DBD8(D_L01_001DEF50_003C88E0, D_L01_001DEF54_003C88E0, ph);
            al = (u32)color >> 24;
            al = (s32)((f32)al * fade);
            color = (color & 0xFFFFFF) | (al << 24);
            func_0038CE20((f32 *)&pk[0], (f32 *)&q10, f21);
            func_0038CE20((f32 *)&pk[1], (f32 *)&q20, f21);
            func_0038CE20((f32 *)&pk[2], (f32 *)&q30, f22);
            plain_sub(&pk[3], &p40, &pk[2]);
            func_003D9740(pk, D_L01_001DEF30_003C88E0, color, 4, 1, phase_base + ph + (f32)(i & 1) * 0.5f);
        }
    }
}

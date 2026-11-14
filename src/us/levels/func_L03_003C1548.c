#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C1548;
typedef struct { u8 p0[0x24]; f32 f24; } K_3C1548;
typedef struct { u8 p0[0x10]; V4_3C1548 pos; u8 p20[4]; K_3C1548 *cls; u8 p28[4]; f32 f2C; } O_3C1548;

extern void func_003888C8(void *, void *, void *);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L01_00468C38(void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L03_003C1548 */
extern V4_3C1548 D_L03_001E24C0_003C1548;
extern u8 D_001DED90_sda[8];
__asm__(".extern D_001DED90_sda, 8");
extern f32 D_001DED54_sda;
__asm__(".extern D_001DED54_sda, 4");
extern f32 D_001DED58_sda_003C1548;
__asm__(".extern D_001DED58_sda_003C1548, 4");
extern f32 D_001DED5C_sda;
__asm__(".extern D_001DED5C_sda, 4");
extern f32 D_001DED60_sda;
__asm__(".extern D_001DED60_sda, 4");
extern s32 D_001DED64_sda;
__asm__(".extern D_001DED64_sda, 4");
extern s32 D_001DED68_sda;
__asm__(".extern D_001DED68_sda, 4");
extern s32 D_001DED6C_sda;
__asm__(".extern D_001DED6C_sda, 4");
extern f32 D_001DED70_sda;
__asm__(".extern D_001DED70_sda, 4");
extern f32 D_001DED74_sda;
__asm__(".extern D_001DED74_sda, 4");
extern s32 D_001DED78_sda;
__asm__(".extern D_001DED78_sda, 4");
extern s32 D_001DED7C_sda;
__asm__(".extern D_001DED7C_sda, 4");
extern f32 D_001DED80_sda;
__asm__(".extern D_001DED80_sda, 4");
extern f32 D_001DED84_sda;
__asm__(".extern D_001DED84_sda, 4");
extern s32 D_001DED88_sda;
__asm__(".extern D_001DED88_sda, 4");
extern s32 D_001DED8C_sda;
__asm__(".extern D_001DED8C_sda, 4");
extern s32 D_001DF540_sda;

void func_L03_003C1548(O_3C1548 *o) {
    V4_3C1548 a;
    V4_3C1548 b;
    V4_3C1548 c;
    V4_3C1548 d;
    V4_3C1548 e;
    s32 i;
    s32 j;

    func_003888C8(&a, &D_001DED90_sda, (u8 *)o + 0xC0);
    vec_add_ab(&a, &a, &o->pos);
    if (func_0037E1D8(4) == 0) {
        func_L01_00440A88(&b, D_001DED54_sda * 0.016666668f, D_001DED58_sda_003C1548 * 0.016666668f);
        func_L01_00468DC0(&a, &b, D_001DED68_sda, D_001DED70_sda, D_001DED64_sda, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        for (j = 2; j >= 0; j--) {
            func_L01_00440A88(&c, D_001DED5C_sda * 0.016666668f, D_001DED60_sda * 0.016666668f);
            vec_add_ab(&b, &b, &c);
            func_L01_00468DC0(&a, &b, D_001DED6C_sda, D_001DED74_sda, D_001DED64_sda, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
    vec_sub_ba(&d, &D_L03_001E24C0_003C1548, &a);
    func_00388830(&d, &d, -0.3f);
    func_00388830(&e, &d, 0.1f);
    vec_add_ab(&d, &d, &a);
    for (i = 0; i < 4; i++) {
        s32 col;
        s32 al;
        col = func_003894A0(D_001DED78_sda, D_001DED7C_sda, fabs_asm(0.5f - (f32)(255 - ((D_001DF540_sda + i * 20) & 0xFF)) / 255.0f));
        al = *(u8 *)&D_001DF540_sda;
        if (i & 2) {
            al = al << 1;
        }
        if (i & 1) {
            al = 255 - al;
        }
        func_L01_00468C38(&d, col, al & 0xFF, D_001DED8C_sda, D_001DED88_sda, 2, 0, 0, (D_001DED80_sda + (f32)i * D_001DED84_sda) * (o->f2C / o->cls->f24));
        vec_add_ab(&d, &d, &e);
    }
}
/* localdecomp:end func_L03_003C1548 */

#include "common.h"

/* NTSC-U counterpart of func_L19_003D2DD8 (src/levels/19_thran_asteroid_belt/L19_003D26C0.c) */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00467DA8(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern void func_00388830(void *, void *, f32);
extern void func_L19_003D0B20(void *, s32, s32, s32, void *);
extern f32 func_0037E2A8(void);

/* localdecomp:start func_L19_003D0B20 */
typedef int u128_t_3D2DD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D2DD8;
__asm__(".extern D_L19_001DEC78, 4");
__asm__(".extern D_L19_001DEC80_003D0B20, 4");
__asm__(".extern D_L19_001DEC84, 4");
__asm__(".extern D_L19_001DEC88, 4");
__asm__(".extern D_L19_001DEC8C, 4");
__asm__(".extern D_L19_001DEC90_003D0B20, 4");
__asm__(".extern D_L19_001DEC94, 4");
__asm__(".extern D_L19_001DEC98, 4");
extern s32 D_L19_001DEC78;
extern s32 D_L19_001DEC7C;
extern f32 D_L19_001DEC80_003D0B20;
extern f32 D_L19_001DEC84;
extern f32 D_L19_001DEC88;
extern f32 D_L19_001DEC8C;
extern f32 D_L19_001DEC90_003D0B20;
extern f32 D_L19_001DEC94;
extern f32 D_L19_001DEC98;
extern V4_3D2DD8 D_L19_001E2080_003D0B20;
extern V4_3D2DD8 D_001A4EC0;
extern u8 *D_L19_0021EED8_003D0B20[];
extern f32 func_L01_00440918(f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern void func_00389158(void *, f32, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00467DA8(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_004633E8(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern u8 *func_L01_0046D1D0(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);

void func_L19_003D0B20(void *p, s32 n2, s32 n1, s32 flag, void *obj) {
    V4_3D2DD8 *pos = p;
    V4_3D2DD8 axis;
    V4_3D2DD8 vel;
    V4_3D2DD8 dir;
    V4_3D2DD8 a;
    V4_3D2DD8 c;
    V4_3D2DD8 d;
    s32 spin;
    s32 k;
    s32 i, j;
    s32 one;
    s32 life;
    f32 sz;
    f32 ang;
    f32 el;
    u8 *r;
    u8 *t;
    u8 *q;

    *(u128_t_3D2DD8 *)&axis = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    vec_sub_ab(&dir, &D_L19_001E2080_003D0B20, pos);
    for (i = 0; i < n1; i++) {
        {
            a = *pos;
            a.x += func_L01_00440918(0.0f, 0.05f);
            a.y += func_L01_00440918(0.0f, 0.05f);
            a.z += func_L01_00440918(0.0f, 0.05f);
            spin = func_0037E1D8(2);
            if (spin == 0)
                spin--;
            func_00389158(&vel, func_0037E250(-1.0471976f, 1.0471976f), &dir, &axis);
            func_00388830(&vel, &vel, func_0037E250(D_L19_001DEC80_003D0B20, D_L19_001DEC84) * 0.0166666675f);
            vel.z = func_0037E250(D_L19_001DEC88, D_L19_001DEC8C) * 0.0166666675f;
            func_L01_00467DA8((u8 *)&a, 0x3C, func_0037E250(D_L19_001DEC94, D_L19_001DEC98), D_L19_001DEC98,
                              D_L19_001DEC78, 0, spin, &vel, D_L19_001DEC90_003D0B20, 0);
        }
    }
    for (j = 0; j < n2; j++) {
        {
            func_003886E8(&a, &D_001A4EC0, -(func_0037E250(0.1f, 1.5f) * 0.0166666675f));
            k = (s32)func_L01_00440918(1.0f, 2.0f);
            sz = func_0037E250(0.15f, 0.35f) * 210000.0f;
            c.x = pos->x + func_L01_00440918(0.0f, 0.1f);
            c.y = pos->y + func_L01_00440918(0.0f, 0.1f);
            c.z = pos->z + func_L01_00440918(0.0f, 0.1f);
            r = func_L01_004633E8(&c, 0.0f, 1.0f, 1.01f, sz, k, &a, 0x7F202020, 0);
            if (r != 0) {
                *(s16 *)(r + 0xA) = 0x5A;
                t = r + 0x20;
                r[0x3] = 0x44;
                r[0x9] = 0x44;
                *(f32 *)(t + 0x1C) = 5.0f;
                *(s32 *)(t + 0x4) = 3;
                t[0xA] = 0x30;
                t[0xB] = r[0xA];
            }
        }
    }
    one = 1;
    for (j = 0; j < 2; j++) {
        el = func_0037E250(-0.9599311f, -1.3962634f);
        ang = func_0037E2A8();
        func_0037E4B8(&a, func_0037E250(0.0f, 0.5f) * 0.0166666675f, ang, el);
        vec_sub_ab(&c, &D_L19_001E2080_003D0B20, pos);
        func_00388830(&c, &c, 0.3f);
        vec_add_ba(pos, pos, &c);
        sz = func_0037E250(20000.0f, 75000.0f);
        d.x = pos->x + func_L01_00440918(0.0f, 0.02f);
        d.y = pos->y + func_L01_00440918(0.0f, 0.02f);
        d.z = pos->z + func_L01_00440918(0.01f, 0.05f);
        if (flag)
            q = func_L01_0046D1D0(&d, &a, D_L19_001DEC78, D_L19_001DEC7C, sz, 0.1f, func_0037E208(10, 20), 1, 1, -1, one);
        else
            q = func_L01_0046D1D0(&d, &a, D_L19_001DEC78, D_L19_001DEC7C, sz, 0.1f, func_0037E208(25, 60), 1, 1, -1, one);
        if (q != 0)
            q[2] = D_L19_0021EED8_003D0B20[0x16C / 4][1];
    }
}
/* localdecomp:end func_L19_003D0B20 */

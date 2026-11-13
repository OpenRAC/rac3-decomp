#include "common.h"

/* localdecomp:start func_L19_003D2DD8 */
typedef int u128_t_3D2DD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D2DD8;
__asm__(".extern D_L19_001DEC38, 4");
__asm__(".extern D_L19_001DEC40, 4");
__asm__(".extern D_L19_001DEC44, 4");
__asm__(".extern D_L19_001DEC48, 4");
__asm__(".extern D_L19_001DEC4C, 4");
__asm__(".extern D_L19_001DEC50, 4");
__asm__(".extern D_L19_001DEC54, 4");
__asm__(".extern D_L19_001DEC58, 4");
extern s32 D_L19_001DEC38;
extern s32 D_L19_001DEC3C;
extern f32 D_L19_001DEC40;
extern f32 D_L19_001DEC44;
extern f32 D_L19_001DEC48;
extern f32 D_L19_001DEC4C;
extern f32 D_L19_001DEC50;
extern f32 D_L19_001DEC54;
extern f32 D_L19_001DEC58;
extern V4_3D2DD8 D_L19_001E2080;
extern V4_3D2DD8 D_001A4EC0;
extern u8 *D_L19_0021EED8[];
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D890(void *, f32, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern u8 *func_L01_004708C8(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);

void func_L19_003D2DD8(void *p, s32 n2, s32 n1, s32 flag, u8 *obj) {
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
    vec_sub_ab(&dir, &D_L19_001E2080, pos);
    for (i = 0; i < n1; i++) {
        {
            a = *pos;
            a.x += func_L01_00443A18(0.0f, 0.05f);
            a.y += func_L01_00443A18(0.0f, 0.05f);
            a.z += func_L01_00443A18(0.0f, 0.05f);
            spin = func_00382468(2);
            if (spin == 0)
                spin--;
            func_0038D890(&vel, func_003824E0(-1.0471976f, 1.0471976f), &dir, &axis);
            func_0038CF68(&vel, &vel, func_003824E0(D_L19_001DEC40, D_L19_001DEC44) * 0.020000001f);
            vel.z = func_003824E0(D_L19_001DEC48, D_L19_001DEC4C) * 0.020000001f;
            func_L01_0046B458((u8 *)&a, 0x32, func_003824E0(D_L19_001DEC54, D_L19_001DEC58), D_L19_001DEC58,
                              D_L19_001DEC38, 0, spin, &vel, D_L19_001DEC50 * 1.44f, 0);
        }
    }
    for (j = 0; j < n2; j++) {
        {
            func_0038CE20(&a, &D_001A4EC0, -(func_003824E0(0.1f, 1.5f) * 0.020000001f));
            k = (s32)func_L01_00443A18(1.0f, 2.0f);
            sz = func_003824E0(0.15f, 0.35f) * 210000.0f;
            c.x = pos->x + func_L01_00443A18(0.0f, 0.1f);
            c.y = pos->y + func_L01_00443A18(0.0f, 0.1f);
            c.z = pos->z + func_L01_00443A18(0.0f, 0.1f);
            r = func_L01_004669B0(&c, 0.0f, 1.0f, 1.01f, sz, k, &a, 0x7F202020, 0);
            if (r != 0) {
                *(s16 *)(r + 0xA) = 0x4B;
                t = r + 0x20;
                r[0x3] = 0x44;
                r[0x9] = 0x44;
                *(f32 *)(t + 0x1C) = 4.0f;
                *(s32 *)(t + 0x4) = 3;
                t[0xA] = 0x30;
                t[0xB] = r[0xA];
            }
        }
    }
    one = 1;
    for (j = 0; j < 2; j++) {
        el = func_003824E0(-0.9599311f, -1.3962634f);
        ang = func_00382538();
        func_00382760(&a, func_003824E0(0.0f, 0.5f) * 0.020000001f, ang, el);
        vec_sub_ab(&c, &D_L19_001E2080, pos);
        func_0038CF68(&c, &c, 0.3f);
        vec_add_ba(pos, pos, &c);
        sz = func_003824E0(20000.0f, 75000.0f);
        d.x = pos->x + func_L01_00443A18(0.0f, 0.02f);
        d.y = pos->y + func_L01_00443A18(0.0f, 0.02f);
        d.z = pos->z + func_L01_00443A18(0.01f, 0.05f);
        if (flag)
            q = func_L01_004708C8(&d, &a, D_L19_001DEC38, D_L19_001DEC3C, sz, 0.1f, func_00382498(8, 0x11), 1, 1, -1, one);
        else
            q = func_L01_004708C8(&d, &a, D_L19_001DEC38, D_L19_001DEC3C, sz, 0.1f, func_00382498(0x15, 0x32), 1, 1, -1, one);
        if (q != 0)
            q[2] = D_L19_0021EED8[0x16C / 4][1];
    }
}
/* localdecomp:end func_L19_003D2DD8 */

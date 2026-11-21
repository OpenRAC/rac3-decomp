/* functional: high. functional: high. 10-word register-allocation-only difference from retail; constants converted to PAL timing */
typedef int u128_3CDDD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CDDD8;
__asm__(".extern D_001DF1A0_sda, 4");
__asm__(".extern D_001DF1A8_sda, 4");
__asm__(".extern D_001DF1AC_sda, 4");
__asm__(".extern D_001DF1B0_sda, 4");
__asm__(".extern D_001DF1B4_sda, 4");
__asm__(".extern D_001DF1B8_sda, 4");
__asm__(".extern D_001DF1BC_sda, 4");
__asm__(".extern D_001DF1C0_sda, 4");
__asm__(".extern D_001DF1C4_sda, 4");
__asm__(".extern D_001DF1C8_sda, 4");
__asm__(".extern D_001DF1CC_sda, 4");
__asm__(".extern D_001DF1D0_sda, 4");
__asm__(".extern D_001DF1D4_sda, 4");
extern s32 D_001DF1A0_sda;
extern s32 D_L01_001DF1A4;
extern s32 D_001DF1A8_sda;
extern f32 D_001DF1AC_sda;
extern f32 D_001DF1B0_sda;
extern f32 D_001DF1B4_sda;
extern f32 D_001DF1B8_sda;
extern f32 D_001DF1BC_sda;
extern f32 D_001DF1C0_sda;
extern f32 D_001DF1C4_sda;
extern f32 D_001DF1C8_sda;
extern f32 D_001DF1CC_sda;
extern f32 D_001DF1D0_sda;
extern f32 D_001DF1D4_sda;
extern V4_3CDDD8 D_L01_001E29C0;
extern V4_3CDDD8 D_001A4EC0;
extern u8 *D_L01_00221098[];
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D890(void *, f32, void *, void *);
extern void func_0038CF68(f32 *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind, s32 spin,
                             void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern u8 *func_L01_004708C8(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);

void func_L01_003CDDD8(void *p0, int n2, int n1, int flag, M_3CC220 *unused, int enable) {
    V4_3CDDD8 *pos = p0;
    V4_3CDDD8 axis;
    V4_3CDDD8 vel;
    V4_3CDDD8 dir;
    V4_3CDDD8 a;
    V4_3CDDD8 c;
    V4_3CDDD8 d;
    s32 spin;
    s32 k;
    s32 i, j;
    s32 one;
    f32 sz;
    f32 ang;
    f32 el;
    u8 *r;
    u8 *t;
    u8 *q;

    *(u128_3CDDD8 *)&axis = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    vec_sub_ab(&dir, &D_L01_001E29C0, pos);
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
            func_0038CF68((f32 *)&vel, &vel, func_003824E0(D_001DF1AC_sda, D_001DF1B0_sda) * 0.020000001f);
            vel.z = func_003824E0(D_001DF1B4_sda, D_001DF1B8_sda) * 0.020000001f;
            func_L01_0046B458((u8 *)&a, 0x32, func_003824E0(D_001DF1C0_sda, D_001DF1C4_sda), D_001DF1C4_sda,
                              D_001DF1A8_sda, 0, spin, &vel, D_001DF1BC_sda * 1.44f, 0);
        }
    }
    for (j = 0; j < n2; j++) {
        {
            func_0038CE20(&a, &D_001A4EC0, -(func_003824E0(0.1f, 1.5f) * 0.020000001f));
            k = (s32)func_L01_00443A18(1.0f, 2.0f);
            sz = func_003824E0(D_001DF1D0_sda, D_001DF1D4_sda) * 210000.0f;
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
    if (enable != 0) {
        one = 1;
        for (j = 0; j < 2; j++) {
            el = func_003824E0(-0.9599311f, -1.3962634f);
            ang = func_00382538();
            func_00382760(&a, func_003824E0(0.0f, 0.5f) * 0.020000001f, ang, el);
            vec_sub_ab(&c, &D_L01_001E29C0, pos);
            func_0038CF68((f32 *)&c, &c, 0.3f);
            vec_add_ba(pos, pos, &c);
            sz = func_003824E0(D_001DF1C8_sda, D_001DF1CC_sda);
            d.x = pos->x + func_L01_00443A18(0.0f, 0.02f);
            d.y = pos->y + func_L01_00443A18(0.0f, 0.02f);
            d.z = pos->z + func_L01_00443A18(0.01f, 0.05f);
            if (flag)
                q = func_L01_004708C8(&d, &a, D_001DF1A0_sda, D_L01_001DF1A4, sz, 0.1f, func_00382498(8, 17), 1, 1, -1, one);
            else
                q = func_L01_004708C8(&d, &a, D_001DF1A0_sda, D_L01_001DF1A4, sz, 0.1f, func_00382498(21, 50), 1, 1, -1, one);
            if (q != 0)
                q[2] = D_L01_00221098[0x16C / 4][1];
        }
    }
}


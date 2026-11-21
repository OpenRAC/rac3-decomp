/* functional: high. functional: high. PAL port of the NTSC draft; every instruction matches retail as a multiset, only register allocation and VU0 scheduling order differ */
typedef int u128_t_3CD248 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CD248;
__asm__(".extern D_001DF078_sda, 4");
__asm__(".extern D_001DF080_sda, 4");
__asm__(".extern D_001DF084_sda, 4");
__asm__(".extern D_001DF088_sda, 4");
__asm__(".extern D_001DF08C_sda, 4");
__asm__(".extern D_001DF090_sda, 4");
__asm__(".extern D_001DF094_sda, 4");
__asm__(".extern D_001DF098_sda, 4");
extern s32 D_001DF078_sda;
extern s32 D_L01_001DF07C;
extern f32 D_001DF080_sda;
extern f32 D_001DF084_sda;
extern f32 D_001DF088_sda;
extern f32 D_001DF08C_sda;
extern f32 D_001DF090_sda;
extern f32 D_001DF094_sda;
extern f32 D_001DF098_sda;
extern V4_3CD248 D_L01_001E29C0;
extern V4_3CD248 D_001A4EC0;
extern u8 *D_L01_00221098[];
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

static __inline__ void w66_sub_ab(V4_3CD248 *d, V4_3CD248 *a, V4_3CD248 *b) {
 __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
static __inline__ void w66_sub_ba(V4_3CD248 *d, V4_3CD248 *a, V4_3CD248 *b) {
 __asm__("lqc2 $vf1,%2\n\tlqc2 $vf2,%1\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
static __inline__ void w66_add_ba(V4_3CD248 *d, V4_3CD248 *a, V4_3CD248 *b) {
 __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
void func_L01_003CD248(void *p, s32 n2, s32 n1, s32 flag, u8 *obj) {
    V4_3CD248 *pos = p;
    V4_3CD248 axis;
    V4_3CD248 vel;
    V4_3CD248 dir;
    V4_3CD248 a;
    V4_3CD248 c;
    V4_3CD248 d;
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

    *(u128_t_3CD248 *)&axis = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    w66_sub_ab(&dir, &D_L01_001E29C0, pos);
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
            func_0038CF68(&vel, &vel, func_003824E0(D_001DF080_sda, D_001DF084_sda) * 0.020000001f);
            vel.z = func_003824E0(D_001DF088_sda, D_001DF08C_sda) * 0.020000001f;
            func_L01_0046B458((u8 *)&a, 0x32, func_003824E0(D_001DF094_sda, D_001DF098_sda), D_001DF098_sda,
                              D_001DF078_sda, 0, spin, &vel, D_001DF090_sda * 1.44f, 0);
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
        w66_sub_ba(&c, &D_L01_001E29C0, pos);
        func_0038CF68(&c, &c, 0.3f);
        w66_add_ba(pos, pos, &c);
        sz = func_003824E0(20000.0f, 75000.0f);
        d.x = pos->x + func_L01_00443A18(0.0f, 0.02f);
        d.y = pos->y + func_L01_00443A18(0.0f, 0.02f);
        d.z = pos->z + func_L01_00443A18(0.01f, 0.05f);
        if (flag)
            q = func_L01_004708C8(&d, &a, D_001DF078_sda, D_L01_001DF07C, sz, 0.1f, func_00382498(8, 17), 1, 1, -1, one);
        else
            q = func_L01_004708C8(&d, &a, D_001DF078_sda, D_L01_001DF07C, sz, 0.1f, func_00382498(21, 50), 1, 1, -1, one);
        if (q != 0)
            q[2] = D_L01_00221098[0x16C / 4][1];
    }
}


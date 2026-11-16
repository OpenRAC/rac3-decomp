/* NTSC-U draft (Codex wave 3): C of func_L01_003CB998, the NTSC-U twin of func_L01_003CD248, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 250 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003CB998", whose code is not the PAL one).
 * Worker's note: 250 diff; allowed single-block VU0 draft reproduced; j-class template fails permitted flags: fixed or forbidden register 96 (vf17) spilled for VU_REGS (02.log); remaining interleaving/register allocation; best log func_L01_003CB998.01.log
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L01_003CB998 */
typedef int u128_t_3C41F0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C41F0;
__asm__(".extern D_001DF0B8_sda, 4");
__asm__(".extern D_001DF0C0_sda, 4");
__asm__(".extern D_001DF0C4_sda, 4");
__asm__(".extern D_001DF0C8_sda, 4");
__asm__(".extern D_001DF0CC_sda, 4");
__asm__(".extern D_001DF0D0_sda, 4");
__asm__(".extern D_001DF0D4_sda, 4");
__asm__(".extern D_001DF0D8_sda, 4");
extern s32 D_001DF0B8_sda;
extern s32 D_L01_001DF0BC;
extern f32 D_001DF0C0_sda;
extern f32 D_001DF0C4_sda;
extern f32 D_001DF0C8_sda;
extern f32 D_001DF0CC_sda;
extern f32 D_001DF0D0_sda;
extern f32 D_001DF0D4_sda;
extern f32 D_001DF0D8_sda;
extern V4_3C41F0 D_L01_001E2A40_003CB998;
extern V4_3C41F0 D_001A4EC0;
extern u8 *D_L01_00221118_003CB998[];
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

static __inline__ void w66_sub_ab(V4_3C41F0 *d, V4_3C41F0 *a, V4_3C41F0 *b) {
 __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
static __inline__ void w66_sub_ba(V4_3C41F0 *d, V4_3C41F0 *a, V4_3C41F0 *b) {
 __asm__("lqc2 $vf1,%2\n\tlqc2 $vf2,%1\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
static __inline__ void w66_add_ba(V4_3C41F0 *d, V4_3C41F0 *a, V4_3C41F0 *b) {
 __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
void func_L01_003CB998(void *p, s32 n2, s32 n1, s32 flag, u8 *obj) {
    V4_3C41F0 *pos = p;
    V4_3C41F0 axis;
    V4_3C41F0 vel;
    V4_3C41F0 dir;
    V4_3C41F0 a;
    V4_3C41F0 c;
    V4_3C41F0 d;
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

    *(u128_t_3C41F0 *)&axis = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    w66_sub_ab(&dir, &D_L01_001E2A40_003CB998, pos);
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
            func_00388830(&vel, &vel, func_0037E250(D_001DF0C0_sda, D_001DF0C4_sda) * 0.0166666675f);
            vel.z = func_0037E250(D_001DF0C8_sda, D_001DF0CC_sda) * 0.0166666675f;
            func_L01_00467DA8((u8 *)&a, 0x3C, func_0037E250(D_001DF0D4_sda, D_001DF0D8_sda), D_001DF0D8_sda,
                              D_001DF0B8_sda, 0, spin, &vel, D_001DF0D0_sda, 0);
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
        w66_sub_ba(&c, &D_L01_001E2A40_003CB998, pos);
        func_00388830(&c, &c, 0.3f);
        w66_add_ba(pos, pos, &c);
        sz = func_0037E250(20000.0f, 75000.0f);
        d.x = pos->x + func_L01_00440918(0.0f, 0.02f);
        d.y = pos->y + func_L01_00440918(0.0f, 0.02f);
        d.z = pos->z + func_L01_00440918(0.01f, 0.05f);
        if (flag)
            q = func_L01_0046D1D0(&d, &a, D_001DF0B8_sda, D_L01_001DF0BC, sz, 0.1f, func_0037E208(10, 20), 1, 1, -1, one);
        else
            q = func_L01_0046D1D0(&d, &a, D_001DF0B8_sda, D_L01_001DF0BC, sz, 0.1f, func_0037E208(25, 60), 1, 1, -1, one);
        if (q != 0)
            q[2] = D_L01_00221118_003CB998[0x16C / 4][1];
    }
}
/* localdecomp:end func_L01_003CB998 */

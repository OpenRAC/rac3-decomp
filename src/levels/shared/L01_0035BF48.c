#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

typedef struct {
    s32 a[12];
} S_0035E418;

/* localdecomp:start func_L01_0035BF48 */
typedef struct {
    s128 velocity;  /* 0x00: u a frame */
    f32 roll;       /* 0x10: a random start; n60_bullet_draw turns it */
    s32 bounces;    /* 0x14 */
    s32 gun;        /* 0x18: the attacker */
    f32 damage;     /* 0x1C */
    s32 life;       /* 0x20: frames */
    s32 tracer;     /* 0x24: draws the tracer */
    f32 flown;      /* 0x28: u */
    s32 shadow;     /* 0x2C */
} N60Bullet_0035BF48;

extern u8 *func_003C24B0(s32 class, s32 vars_size);
extern f32 func_00382538(void);
extern f32 func_0038CEA8(void *);
extern void func_L01_004CAC78(void *out, void *from, f32 speed, f32 range, f32 max_angle);
extern s32 func_L01_004C85C8(u8 *moby, s32 a1, f32 x, f32 y, f32 z);
extern void func_L01_004AA7E8(u8 *moby, s32 a1);
extern u8 D_001A4BE0[];

/* n60_bullet_spawn: an N60 Storm bullet (class 0x1851) at pos with velocity, the row's damage
   and the gun as attacker; in the aiming camera modes it bends toward the aim point. */
u8 *func_L01_0035BF48(s32 gun, s128 *pos, s128 *velocity, f32 damage, s32 life, s32 tracer, f32 size)
{
    u8 *bullet = func_003C24B0(0x1851, 0x80);
    N60Bullet_0035BF48 *vars;

    if (bullet != 0) {
        bullet[0x20] = 0;
        *(u16 *)(bullet + 0x32) = 0xFF;
        bullet[0x30] = 0xFF;
        vars = *(N60Bullet_0035BF48 **)(bullet + 0x68);
        *(s128 *)(bullet + 0x10) = *pos;
        vars->velocity = *velocity;
        vars->life = life;
        vars->gun = gun;
        vars->roll = func_00382538();
        vars->damage = damage;
        vars->tracer = tracer;
        vars->bounces = 0;
        vars->flown = 0.0f;
        /* the hero's camera mode: not the follow camera */
        if (*(s32 *)(D_001A4BE0 + 0x16B0) != 0) {
            /* within 35 u, turned at most 80 degrees */
            func_L01_004CAC78(vars, pos, func_0038CEA8(vars), 35.0f, 1.3962634f);
        }
        vars->shadow = func_L01_004C85C8(bullet, 0, size, 1.0f, 1.0f);
        *(s32 *)(bullet + 0x98) = 0;
        *(u16 *)(bullet + 0x34) = (*(u16 *)(bullet + 0x34) | 0x41) & ~0x1000;
        func_L01_004AA7E8(bullet, 1);
    }
    return bullet;
}
/* localdecomp:end func_L01_0035BF48 */

INCLUDE_ASM("asm/levels", func_L01_0035C098);

/* localdecomp:start func_L01_0035C6B0 */
extern void func_L01_004C8668(int);
extern void func_003C2880(void *);
void func_L01_0035C6B0(char *m)
{
    char *v = *(char **)(m + 104);
    if (v != 0) {
        func_L01_004C8668(*(int *)(v + 44));
    }
    func_003C2880(m);
}
/* localdecomp:end func_L01_0035C6B0 */

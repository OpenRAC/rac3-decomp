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

/* localdecomp:start func_L01_0035C098 */
#include "vu0.h"
typedef struct { u8 pad[0x2F]; u8 player; } Hero_0035C098;
typedef struct { u8 pad; u8 flag; u8 rest[0xEE]; } Row_0035C098;
typedef struct { u8 pad[0x18]; u8 *hit; S_38C110v position; S_38C110v normal; S_38C110v extra; } Contact_0035C098;
typedef struct { s128 data; s32 gun; u8 pad[4]; u8 kind, flag; u16 cls; u8 tail[0x14]; } Damage_0035C098;
extern Hero_0035C098 D_001425C0;
extern Row_0035C098 D_L01_002C5600[];
extern Contact_0035C098 D_L01_001EAA00;
void func_L01_0035C098(u8 *m) {
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_0035C6B0(char *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern s32 func_003C4B50(void *);
    extern void func_L01_0034C9F0(void *, s32, void *);
    extern void func_003D4D00(void *, s32, void *, void *, f32);
    extern void func_L01_0035CAD0(void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32,
        f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
        s32, s32, s32, s32, s32, s32, s32, s32);
    extern s32 func_0038DC20(void *, f32);
    extern void func_L01_00404A10_0035C098(void (*)(u8 *), void *);
    extern void func_L01_0035C8D0(u8 *);
    extern void func_L01_0035D358(void *, void *, void *);
    extern void func_L01_0035CFC8(void *, void *, void *);
    S_38C110v old, temp;
    union { Damage_0035C098 damage; S_38C110v current; } shared;
    N60Bullet_0035BF48 *v = *(N60Bullet_0035BF48 **)(m + 0x68);
    u8 *hit;
    if (func_L01_004CB2D8()) func_L01_004CAB30(m + 0x10, m + 0x10);
    switch (m[0x20]) {
    case 0:
        *(s128 *)&old = *(s128 *)(m + 0x10);
        func_L01_004C8688(v->shadow, v, 0);
        vec_add_ab(m + 0x10, v, m + 0x10);
        if (*(f32 *)(m+0x10) < 2.0f || *(f32 *)(m+0x10) > 1021.0f ||
            *(f32 *)(m+0x14) < 2.0f || *(f32 *)(m+0x14) > 1021.0f ||
            *(f32 *)(m+0x18) < 2.0f || *(f32 *)(m+0x18) > 1021.0f) func_L01_0035C6B0((char *)m);
        v->bounces++;
        if (func_003D3CB0(&old, m+0x10, 0, m, 0)) {
            if (((Row_0035C098 *)((s32)D_001425C0.player * 0xF0 + (s32)D_L01_002C5600))->flag == 0) {
                *(s128 *)(m+0x10) = *(s128 *)&D_L01_001EAA00.position;
                m[0x20] = 1;
                *(s128 *)&temp = v->velocity;
                func_0038CE20(&temp, &temp, 0.5f);
                temp.w = 5627.9248046875f;
                func_L01_00446760(&shared.damage, m, v->life, &temp, v->damage);
                shared.damage.gun = v->gun;
                shared.damage.flag = 1;
                shared.damage.cls = *(u16 *)(m+0xAA);
                shared.damage.kind = 0;
                hit = D_L01_001EAA00.hit;
                if (hit && (*(s16 *)(hit+0xAA) == 0x18BE || *(s16 *)(hit+0xAA) == 0 || hit == (u8 *)v->gun)) goto contact_done;
                if (hit) {
                    func_003D4D00(&D_L01_001EAA00.position, 0, m, &shared.damage, 1.0f);
                } else {
                    func_003D4D00(&D_L01_001EAA00.position, 0, m, &shared.damage, 0.6f);
                }
                goto collision_end;
            } else {
                m[0x20] = 1;
                *(s128 *)&temp = v->velocity;
                func_0038CE20(&temp, &temp, 0.5f);
                temp.w = 5627.9248046875f;
                func_L01_00446760(&shared.damage, m, v->life, &temp, v->damage);
                shared.damage.gun = v->gun;
                shared.damage.flag = 1;
                shared.damage.cls = *(u16 *)(m+0xAA);
                shared.damage.kind = 0;
                {
                u8 *hit2 = D_L01_001EAA00.hit;
                if (hit2 && (*(s16 *)(hit2+0xAA) == 0x18BE || *(s16 *)(hit2+0xAA) == 0 || hit2 == (u8 *)v->gun)) goto contact_done;
                if (hit2 && ((*(u8 **)(hit2+0x24) && (*(u8 **)(hit2+0x24))[0x46] == 5) || func_003C4B50(hit2) ||
                    (D_L01_001EAA00.hit && *(u8 **)(D_L01_001EAA00.hit+0x24) && (*(u8 **)(D_L01_001EAA00.hit+0x24))[0x46] == 0x16) ||
                    *(s16 *)(D_L01_001EAA00.hit+0xAA) == 0x61C)) {
                    func_L01_0034C9F0(D_L01_001EAA00.hit, 0x2F, m);
                    func_003D4D00(&D_L01_001EAA00.position, 0, m, &shared.damage, 1.0f);
                    goto collision_end;
                }
                goto bounce;
                }
            }
        bounce:
            *(s128 *)(m+0x10) = *(s128 *)&D_L01_001EAA00.position;
            func_L01_0035CAD0(m+0x10);
            func_L01_0040E790(v, v, &D_L01_001EAA00.extra);
        contact_done:
            vec_add_ab(m + 0x10, v, m + 0x10);
            m[0x20] = 0;
        }
    collision_end:
        if (((Row_0035C098 *)((s32)D_001425C0.player * 0xF0 + (s32)D_L01_002C5600))->flag == 0 && v->bounces >= 26) {
            func_L01_0035CAD0(m+0x10);
            func_L01_0035C6B0((char *)m);
        }
        if (((Row_0035C098 *)((s32)D_001425C0.player * 0xF0 + (s32)D_L01_002C5600))->flag != 0 && v->bounces >= 38) {
            func_L01_0035CAD0(m+0x10);
            func_L01_0035C6B0((char *)m);
        }
        break;
    case 1:
        func_0038CF68(v, v, -0.1f);
        vec_add_ba(&temp, m + 0x10, v);
        if (((Row_0035C098 *)((s32)D_001425C0.player * 0xF0 + (s32)D_L01_002C5600))->flag == 0) {
            func_L01_003303B8(&temp,0,5,2,2,2,0,0,0.14f,0.0f,0.0f,0.0f,
                0,1,0,0,1,0,0x01010000,0,0x00399EF7,0x93F7,0x00409FFF,0x90FF,
                0x9FFF,0x003094FF,0x7F205F7F,0x28005F7F,0x0030DFFF,1);
        }
        func_L01_0035C6B0((char *)m);
        break;
    }
    *(s128 *)&temp = *(s128 *)(m+0x10);
    temp.w = 0.5f;
    if (func_0038DC20(&temp, 96.0f) > 0) {
        func_L01_00404A10_0035C098(func_L01_0035C8D0, m);
        if (v->tracer) {
            *(s128 *)&shared.current = *(s128 *)(m+0x10);
            func_L01_0035D358(m, &shared.current, &old);
        } else {
            *(s128 *)&shared.current = *(s128 *)(m+0x10);
            func_L01_0035CFC8(m, &shared.current, &old);
        }
    }
}
/* localdecomp:end func_L01_0035C098 */

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

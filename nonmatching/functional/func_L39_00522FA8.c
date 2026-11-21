/* functional: medium. Written from the PAL assembly with the NTSC-U draft as structure; PAL differs in callees, cooldown (5), table names and the 0x21/0x3A1 weapon slots. Retail's first block calls func_0038CF68(&direction, &damage, 1.0f) with the not-yet-filled damage struct as source (a1 is the damage address, a0 the direction) and then func_0038CF68(&damage, &damage, 1.0f); that is reproduced literally (on the first hit damage holds stack leftovers, later hits the previous force), the gate should cover it. */
#include "vu0.h"

/* VU0 is not in the compiler's allocatable register set for this file's flags. */
static __inline__ void add_ab_522FA8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void add_ba_522FA8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void add2_522FA8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void sub_ba_522FA8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void sub2_522FA8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}

typedef struct {
    vu0_v4 force;
    u8 pad10[8];
    u8 type, active;
    u16 oclass;
    s32 reserved1C, mask;
    u8 pad24[0xC];
} Damage_522FA8;
typedef struct {
    vu0_v4 position, step, normal;
    u8 pad30[4];
    s32 hit, handle, fresh;
} Shot_522FA8;
typedef struct {
    u8 pad0[0x28];
    s32 cooldown;
    u8 *hero;
    u8 pad30[4];
    s32 count, index;
    u8 pad3C[0x20];
    Shot_522FA8 *shots;
} State_522FA8;
typedef struct {
    u8 pad0[0x18];
    u8 *object;
    u8 pad1C[4];
    vu0_v4 position;
    vu0_v4 normal;
} Collision_522FA8;

extern Collision_522FA8 D_L39_0025F740;
extern vu0_v4 D_L39_0025F760[];
extern u8 D_L39_0049C890[];
extern u8 D_L39_0049CC10[];
extern u8 *D_L39_002637C0[];
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern void func_L19_003B1A70(s32, void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004C8668(s32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_00648AE0(void *, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L39_005F33E0(s32, s32, void *);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_0019D510(void);
extern void func_L39_00524380(void *, void *, void *, void *);
extern void func_L39_005FF060(void *, void *, void *, f32);
extern void func_L39_00523860(void *, void *, void *);

void func_L39_00522FA8(u8 *self, s32 kind)
{
    vu0_v4 start, end, scaled, normal, angles;
    vu0_v4 matrix[4];
    vu0_v4 direction;
    Damage_522FA8 damage;
    s32 n = 0;
    State_522FA8 *p = *(State_522FA8 **)(self + 0x68);
    u8 *hero = p->hero;
    s32 index = p->index;
    s32 previous;
    s32 chance, chance1, chance2;

    func_L39_005FFDF8(*(s32 *)(hero + 0x2548));
    for (; n < p->count;) {
        Shot_522FA8 *shot = &p->shots[index];
        if (shot->handle >= 0) {
            func_L19_003B1A70(shot->handle, &shot->step, shot);
        }
        add_ab_522FA8(&end, &shot->position, &shot->step);
        if (!shot->hit) {
            if (shot->fresh) {
                func_0038CE20(&scaled, &shot->step, -0.5f);
                add_ab_522FA8(&start, &shot->position, &scaled);
                shot->fresh = 0;
            } else {
                start = shot->position;
            }
            if (func_003D3CB0(&start, &end, 0x10, self, 0)) {
                u8 *hit;
                shot->position = D_L39_0025F760[0];
                qzero(&shot->step);
                func_0038CF68(&scaled, &D_L39_0025F760[2], 0.1f);
                add_ba_522FA8(&shot->position, &shot->position, &scaled);
                shot->hit = 1;
                func_L01_004C8668(shot->handle);
                shot->handle = -1;
                shot->normal = scaled;
                func_0038CF68(&normal, &scaled, 0.01f);
                angles.x = func_L39_005B4410(-0.7853982f, 0.7853982f);
                angles.y = func_L39_005B4410(-0.7853982f, 0.7853982f);
                angles.z = func_L39_005B4410(-0.7853982f, 0.7853982f);
                func_0038D328(matrix, &angles);
                matrix[3].x = 0.0f;
                matrix[3].y = 0.0f;
                matrix[3].z = 0.0f;
                func_0038D028(&normal, &normal, matrix);
                chance = 1;
                switch (kind) {
                case 1: chance = 8; break;
                case 2: chance = 0x10; break;
                case 3: chance = 0x20; break;
                case 4: chance = 0x100; break;
                }
                if (!func_L39_005B4398(chance)) {
                    func_L01_00466F50((char *)shot, (char *)&normal, 0, -1.0f, 0.0f);
                }
                qzero(&angles);
                hit = D_L39_0025F740.object;
                if (hit && hit != *(u8 **)(hero + 0x2524) &&
                    ((*(u16 *)(hit + 0x34) & 0x1000) ||
                     *(u8 *)(*(u8 **)(hit + 0x24) + 0x46) == 5 ||
                     *(s16 *)(hit + 0xAA) == 0x1099)) {
                    u8 *weapon;
                    s32 count;
                    s32 i;
                    sub_ba_522FA8(&direction, hit + 0x10, self + 0x10);
                    func_0038CF68(&direction, &damage, 1.0f);
                    func_0038CF68(&damage, &damage, 1.0f);
                    if (func_L39_00648AE0(hero, 7)) {
                        weapon = D_L39_0049C890 + *(s8 *)(D_L39_0049C890 + 0x3A1) * 0x80;
                    } else {
                        weapon = D_L39_0049C890 + 0x380;
                    }
                    func_L01_00446760(&damage, self, 0x1110001, &direction, *(f32 *)(weapon + 0x30));
                    damage.force = direction;
                    damage.type = 9;
                    damage.mask = 1;
                    damage.force.w = 5627.925f;
                    damage.active = 1;
                    damage.oclass = *(u16 *)(D_L39_0025F740.object + 0xAA);
                    func_L01_00446978(D_L39_0025F740.object, &damage);
                    if (p->cooldown <= 0) {
                        func_L39_005F33E0(1, 0, self);
                        p->cooldown = 5;
                    }
                    count = func_003D4D00(D_L39_0025F740.object + 0x10, 0x10, self, 0, 1.5f);
                    n++;
                    previous = index - 1;
                    for (i = 0; i < count; i++) {
                        u8 *other = D_L39_002637C0[i];
                        if (other != *(u8 **)(hero + 0x2524)) {
                            sub2_522FA8(&direction, other + 0x10, self + 0x10);
                            func_0038CF68(&direction, &direction, 1.0f);
                            func_0038CF68(&damage, &damage, 1.0f);
                            if (func_L39_00648AE0(hero, 7)) {
                                weapon = D_L39_0049C890 + *(s8 *)(D_L39_0049CC10 + 0x21) * 0x80;
                            } else {
                                weapon = D_L39_0049C890 + 0x380;
                            }
                            func_L01_00446760(&damage, self, 0x1110001, &direction, *(f32 *)(weapon + 0x34));
                            damage.force = direction;
                            damage.mask = 1;
                            damage.force.w = 5627.925f;
                            damage.type = 9;
                            damage.active = 1;
                            damage.oclass = *(u16 *)(other + 0xAA);
                            func_L01_00446978(other, &damage);
                            if (p->cooldown <= 0) {
                                func_L39_005F33E0(1, 0, self);
                                p->cooldown = 5;
                            }
                        }
                    }
                } else {
                    n++;
                    previous = index - 1;
                    if (func_0019D510() % 11 == 0) {
                        func_L39_00524380(self, D_L39_0025F760, &scaled, &angles);
                    }
                }
            } else {
                n++;
                previous = index - 1;
                func_L39_005FF060(hero, shot, &shot->step, 0.006f);
            }
        } else {
            n++;
            previous = index - 1;
        }
        add2_522FA8(&shot->position, &shot->position, &shot->step);
        chance1 = 7;
        chance2 = 0x16;
        switch (kind) {
        case 1: chance1 = 0xA; chance2 = 0x1B; break;
        case 2: chance1 = 0xF; chance2 = 0x20; break;
        case 3: chance1 = 0x19; chance2 = 0x28; break;
        case 4: chance1 = 0x80; chance2 = 0x80; break;
        }
        index = 0x22;
        if (-1 < previous) index = previous;
        if (func_0019D510() % chance1 == 0) {
            func_0038CF68(&scaled, &shot->step, 0.05f);
            func_L39_00523860(self, shot, &shot->step);
        }
        if (func_0019D510() % chance2 == 0) {
            func_0038CF68(&scaled, &shot->step, 0.05f);
            func_L01_00466F50((char *)shot, (char *)&scaled, 0, -1.0f, 0.0f);
        }
    }
    func_L39_005FFE78();
}

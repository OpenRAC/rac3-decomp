/* NTSC-U draft (Codex wave 3): C of func_L39_00522B00, the NTSC-U twin of func_L39_00522FA8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 305 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00522B00", whose code is not the PAL one).
 * Worker's note: 305 diff; best log w69/func_L39_00522B00.check07.log; 7 checks incl j-form compile error; last three variants identical; explicit VU0 sequences compile; remaining VU scheduling, scalar register allocation/spills and reload/store order; retained .near.c
 */
/* Near: 305 diff; check07.log. Three source variants produced identical output.
 * VU0 j-form fails under assigned flags (check01.log); explicit VU0 sequences
 * compile, with remaining VU0 scheduling and scalar register-allocation differences. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_00522B00 */

/* VU0 is not in the compiler's allocatable register set for this file's flags. */
static __inline__ void add_ab_522B00(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void add_ba_522B00(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void add2_522B00(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void sub_ba_522B00(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void sub2_522B00(void *d, void *a, void *b) {
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
} Damage_522B00;
typedef struct {
    vu0_v4 position, step, normal;
    u8 pad30[4];
    s32 hit, handle, fresh;
} Shot_522B00;
typedef struct {
    u8 pad0[0x28];
    s32 cooldown;
    u8 *hero;
    u8 pad30[4];
    s32 count, index;
    u8 pad3C[0x20];
    Shot_522B00 *shots;
} State_522B00;
typedef struct { u8 pad0[0x18]; u8 *object; u8 pad1C[4]; vu0_v4 position; vu0_v4 normal; } Collision_522B00;
extern Collision_522B00 D_L39_0025F840[];
extern vu0_v4 D_L39_0025F860[];
extern u8 D_L39_0049C950[];
extern u8 D_L39_0049CCD0[];
extern u8 *D_L39_002638C0[];
extern void func_L39_005FD658(s32);
extern void func_L39_005FD6D8(void);
extern void func_L19_003AFE00(s32, void *, void *);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_004C4AB8(s32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_00388BF0(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern s32 func_L39_005B2498(s32);
extern void func_L01_00463938(void *, void *, s32, f32, f32);
extern s32 func_L39_00646268(void *, s32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_00443840(void *, void *);
extern void func_L39_005F0CE0(s32, s32, void *);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern s32 func_0019D650(void);
extern void func_L39_00523ED8(void *, void *, void *, void *);
extern void func_L39_005FC8C0(void *, void *, void *, f32);
extern void func_L39_005233B8(void *, void *, void *);

void func_L39_00522B00(u8 *self, s32 kind) {
    vu0_v4 start, end, scaled, normal, angles;
    vu0_v4 matrix[4];
    vu0_v4 direction;
    Damage_522B00 damage;
    s32 n = 0;
    State_522B00 *p = *(State_522B00 **)(self + 0x68);
    u8 *hero = p->hero;
    s32 index = p->index;
    func_L39_005FD658(*(s32 *)(hero + 0x2548));
    for (; n < p->count;) {
        Shot_522B00 *shot = &p->shots[index];
        s32 previous;
        s32 chance1, chance2;
        if (shot->handle >= 0) {
            func_L19_003AFE00(shot->handle, &shot->step, shot);
        }
        add_ab_522B00(&end, &shot->position, &shot->step);
        if (!shot->hit) {
            if (shot->fresh) {
                func_003886E8(&scaled, &shot->step, -0.5f);
                add_ab_522B00(&start, &shot->position, &scaled);
                shot->fresh = 0;
            } else {
                start = shot->position;
            }
            if (func_003CE740(&start, &end, 0x10, self, 0)) {
                s32 chance;
                u8 *hit;
                shot->position = D_L39_0025F860[0];
                qzero(&shot->step);
                func_00388830(&scaled, &D_L39_0025F860[2], 0.1f);
                add_ba_522B00(&shot->position, &shot->position, &scaled);
                shot->hit = 1;
                func_L01_004C4AB8(shot->handle);
                shot->handle = -1;
                shot->normal = scaled;
                func_00388830(&normal, &scaled, 0.01f);
                angles.x = func_L39_005B2510(-0.7853981852531433f, 0.7853981852531433f);
                angles.y = func_L39_005B2510(-0.7853981852531433f, 0.7853981852531433f);
                angles.z = func_L39_005B2510(-0.7853981852531433f, 0.7853981852531433f);
                func_00388BF0(matrix, &angles);
                matrix[3].x = 0.0f;
                matrix[3].y = 0.0f;
                matrix[3].z = 0.0f;
                func_003888F0(&normal, &normal, matrix);
                chance = 1;
                switch (kind) {
                    case 1: chance = 8; break;
                    case 2: chance = 0x10; break;
                    case 3: chance = 0x20; break;
                    case 4: chance = 0x100; break;
                }
                if (!func_L39_005B2498(chance)) {
                    func_L01_00463938(shot, &normal, 0, -1.0f, 0.0f);
                }
                qzero(&angles);
                hit = D_L39_0025F840->object;
                if (hit && hit != *(u8 **)(hero + 0x2524) &&
                    ((*(u16 *)(hit + 0x34) & 0x1000) ||
                     *(u8 *)(*(u8 **)(hit + 0x24) + 0x46) == 5 ||
                     *(s16 *)(hit + 0xAA) == 0x1099)) {
                    u8 *weapon;
                    s32 count;
                    s32 i;
                    sub_ba_522B00(&direction, (vu0_v4 *)(hit + 0x10), (vu0_v4 *)(self + 0x10));
                    func_00388830(&direction, &direction, 1.0f);
                    func_00388830(&damage, &damage, 1.0f);
                    if (func_L39_00646268(hero, 7)) {
                        weapon = D_L39_0049C950 + *(s8 *)(D_L39_0049C950 + 0x3A1) * 0x80;
                    } else {
                        weapon = D_L39_0049C950 + 0x380;
                    }
                    func_L01_00443628(&damage, self, 0x1110001, &direction, *(f32 *)(weapon + 0x30));
                    damage.force = direction;
                    damage.type = 9;
                    damage.mask = 1;
                    damage.force.w = 5627.9248046875f;
                    damage.active = 1;
                    damage.oclass = *(u16 *)(D_L39_0025F840->object + 0xAA);
                    func_L01_00443840(D_L39_0025F840->object, &damage);
                    if (p->cooldown <= 0) {
                        func_L39_005F0CE0(1, 0, self);
                        p->cooldown = 6;
                    }
                    count = func_003CF790(D_L39_0025F840->object + 0x10, 0x10, self, 0, 1.5f);
                    n++;
                    previous = index - 1;
                    for (i = 0; i < count; i++) {
                        u8 *other = D_L39_002638C0[i];
                        if (other != *(u8 **)(hero + 0x2524)) {
                            sub2_522B00(&direction, (vu0_v4 *)(other + 0x10), (vu0_v4 *)(self + 0x10));
                            func_00388830(&direction, &direction, 1.0f);
                            func_00388830(&damage, &damage, 1.0f);
                            if (func_L39_00646268(hero, 7)) {
                                weapon = D_L39_0049C950 + *(s8 *)(D_L39_0049CCD0 + 0x21) * 0x80;
                            } else {
                                weapon = D_L39_0049C950 + 0x380;
                            }
                            func_L01_00443628(&damage, self, 0x1110001, &direction, *(f32 *)(weapon + 0x34));
                            damage.force = direction;
                            damage.mask = 1;
                            damage.force.w = 5627.9248046875f;
                            damage.type = 9;
                            damage.active = 1;
                            damage.oclass = *(u16 *)(D_L39_002638C0[i] + 0xAA);
                            func_L01_00443840(D_L39_002638C0[i], &damage);
                            if (p->cooldown <= 0) {
                                func_L39_005F0CE0(1, 0, self);
                                p->cooldown = 6;
                            }
                        }
                    }
                } else {
                    n++;
                    previous = index - 1;
                    if (func_0019D650() % 11 == 0) {
                        func_L39_00523ED8(self, D_L39_0025F860, &scaled, &angles);
                    }
                }
            } else {
                n++;
                previous = index - 1;
                func_L39_005FC8C0(hero, shot, &shot->step, 0.006000000052154064f);
            }
        } else {
            n++;
            previous = index - 1;
        }
        add2_522B00(&shot->position, &shot->position, &shot->step);
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
        if (func_0019D650() % chance1 == 0) {
            func_00388830(&scaled, &shot->step, 0.05f);
            func_L39_005233B8(self, shot, &shot->step);
        }
        if (func_0019D650() % chance2 == 0) {
            func_00388830(&scaled, &shot->step, 0.05f);
            func_L01_00463938(shot, &scaled, 0, -1.0f, 0.0f);
        }
    }
    func_L39_005FD6D8();
}
/* localdecomp:end func_L39_00522B00 */

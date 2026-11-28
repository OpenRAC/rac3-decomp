/* Wave 13 (r21, 2026-11-28) replaces the earlier draft of this function (NTSC-U draft of `func_L39_00522B00` (Codex wave 3)). */
/* PAL near miss (wave 13 r21, 2026-11-28): 303 differences (build/codex/wave10/p10/check.py, level 39, the file's flags). First PAL draft: the NTSC-U draft of func_L39_00522B00 rewritten with PAL names and data (D_L39_0025F740/0025F760 collision record, D_L39_0049C890/0049CC10 weapon rows, D_L39_002637C0 list, the file's own prototypes of func_0038CF68, func_L39_005B4410, func_0019D510, func_L01_004C8668, func_L01_00466F50 and func_L39_00523860) and PAL's cooldown of 5. The control flow and call sequence follow retail. Left: (1) retail interleaves GPR instructions inside its lqc2/vadd/vsub/sqc2 sequences (0x0D0: addiu and sw between the lqc2s and the sqc2), which only per-instruction j-class asm gives (include/vu0.h's vec_* helpers, a -mvu0-use-vf0-vf2 line); this file's line lacks that flag, so each sequence is one asm block here; (2) register allocation: retail spills n (stack 0xE4, reloaded into s6), keeps kind in s7 and the D_L39_0025F760 high half in fp; ours keeps n in fp and kind in s6, so the spill slots after 0xE0 shift by one. */
#include "common.h"

/* localdecomp:start func_L39_00522FA8 */
#include "vu0.h"

/* One VU0 sequence per block (this file's line has no -mvu0-use-vf0-vf2 for the "j" helpers). */
static __inline__ void add_ab_00522FA8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void add_ba_00522FA8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void add2_00522FA8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void sub_ba_00522FA8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
static __inline__ void sub2_00522FA8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}

typedef struct {
    vu0_v4 force;
    u8 pad10[8];
    u8 type;
    u8 active;
    u16 oclass;
    s32 reserved1C;
    s32 mask;
    u8 pad24[0xC];
} Damage_00522FA8;

typedef struct {
    vu0_v4 position;
    vu0_v4 step;
    vu0_v4 normal;
    u8 pad30[4];
    s32 hit;
    s32 handle;
    s32 fresh;
} Shot_00522FA8;

typedef struct {
    u8 pad0[0x28];
    s32 cooldown;
    u8 *hero;
    u8 pad30[4];
    s32 count;
    s32 index;
    u8 pad3C[0x20];
    Shot_00522FA8 *shots;
} State_00522FA8;

typedef struct {
    u8 pad0[0x18];
    u8 *object;
    u8 pad1C[4];
    vu0_v4 position;
    vu0_v4 normal;
} Collision_00522FA8;

extern Collision_00522FA8 D_L39_0025F740[];
extern vu0_v4 D_L39_0025F760[];
extern u8 D_L39_0049C890[];
extern u8 D_L39_0049CC10[];
extern u8 *D_L39_002637C0[];

void func_L39_00522FA8(u8 *self, s32 kind) {
    extern void func_L39_005FFDF8(s32);
    extern void func_L39_005FFE78(void);
    extern void func_L19_003B1A70(s32, void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D328(void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern s32 func_L39_005B4398(s32);
    extern s32 func_L39_00648AE0(void *, s32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L39_005F33E0(s32, s32, void *);
    extern s32 func_003D4D00(void *, s32, void *, s32, f32);
    extern void func_L39_00524380(void *, void *, void *, void *);
    extern void func_L39_005FF060(void *, void *, void *, f32);
    vu0_v4 start, end, scaled, normal, angles;
    vu0_v4 matrix[4];
    vu0_v4 direction;
    Damage_00522FA8 damage;
    s32 n = 0;
    State_00522FA8 *p = *(State_00522FA8 **)(self + 0x68);
    u8 *hero = p->hero;
    s32 index = p->index;

    func_L39_005FFDF8(*(s32 *)(hero + 0x2548));
    for (; n < p->count;) {
        Shot_00522FA8 *shot = &p->shots[index];
        s32 previous;
        s32 chance1, chance2;

        if (shot->handle >= 0) {
            func_L19_003B1A70(shot->handle, &shot->step, shot);
        }
        add_ab_00522FA8(&end, &shot->position, &shot->step);
        if (!shot->hit) {
            if (shot->fresh) {
                func_0038CE20(&scaled, &shot->step, -0.5f);
                add_ab_00522FA8(&start, &shot->position, &scaled);
                shot->fresh = 0;
            } else {
                start = shot->position;
            }
            if (func_003D3CB0(&start, &end, 0x10, self, 0)) {
                s32 chance;
                u8 *hit;

                shot->position = D_L39_0025F760[0];
                qzero(&shot->step);
                func_0038CF68(&scaled, &D_L39_0025F760[2], 0.1f);
                add_ba_00522FA8(&shot->position, &shot->position, &scaled);
                shot->hit = 1;
                func_L01_004C8668(shot->handle);
                shot->handle = -1;
                shot->normal = scaled;
                func_0038CF68(&normal, &scaled, 0.01f);
                angles.x = func_L39_005B4410(-0.7853981852531433f, 0.7853981852531433f);
                angles.y = func_L39_005B4410(-0.7853981852531433f, 0.7853981852531433f);
                angles.z = func_L39_005B4410(-0.7853981852531433f, 0.7853981852531433f);
                func_0038D328(matrix, &angles);
                matrix[3].x = 0.0f;
                matrix[3].y = 0.0f;
                matrix[3].z = 0.0f;
                func_0038D028(&normal, &normal, matrix);
                chance = 1;
                switch (kind) {
                case 1:
                    chance = 8;
                    break;
                case 2:
                    chance = 0x10;
                    break;
                case 3:
                    chance = 0x20;
                    break;
                case 4:
                    chance = 0x100;
                    break;
                }
                if (!func_L39_005B4398(chance)) {
                    func_L01_00466F50((char *)shot, (char *)&normal, 0, -1.0f, 0.0f);
                }
                qzero(&angles);
                hit = D_L39_0025F740->object;
                if (hit && hit != *(u8 **)(hero + 0x2524) &&
                    ((*(u16 *)(hit + 0x34) & 0x1000) ||
                     *(u8 *)(*(u8 **)(hit + 0x24) + 0x46) == 5 ||
                     *(s16 *)(hit + 0xAA) == 0x1099)) {
                    u8 *weapon;
                    s32 count;
                    s32 i;

                    sub_ba_00522FA8(&direction, (vu0_v4 *)(hit + 0x10), (vu0_v4 *)(self + 0x10));
                    func_0038CF68(&direction, &direction, 1.0f);
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
                    damage.force.w = 5627.9248046875f;
                    damage.active = 1;
                    damage.oclass = *(u16 *)(D_L39_0025F740->object + 0xAA);
                    func_L01_00446978(D_L39_0025F740->object, &damage);
                    if (p->cooldown <= 0) {
                        func_L39_005F33E0(1, 0, self);
                        p->cooldown = 5;
                    }
                    count = func_003D4D00(D_L39_0025F740->object + 0x10, 0x10, self, 0, 1.5f);
                    n++;
                    previous = index - 1;
                    for (i = 0; i < count; i++) {
                        u8 *other = D_L39_002637C0[i];

                        if (other != *(u8 **)(hero + 0x2524)) {
                            sub2_00522FA8(&direction, (vu0_v4 *)(other + 0x10), (vu0_v4 *)(self + 0x10));
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
                            damage.force.w = 5627.9248046875f;
                            damage.type = 9;
                            damage.active = 1;
                            damage.oclass = *(u16 *)(D_L39_002637C0[i] + 0xAA);
                            func_L01_00446978(D_L39_002637C0[i], &damage);
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
                func_L39_005FF060(hero, shot, &shot->step, 0.006000000052154064f);
            }
        } else {
            n++;
            previous = index - 1;
        }
        add2_00522FA8(&shot->position, &shot->position, &shot->step);
        chance1 = 7;
        chance2 = 0x16;
        switch (kind) {
        case 1:
            chance1 = 0xA;
            chance2 = 0x1B;
            break;
        case 2:
            chance1 = 0xF;
            chance2 = 0x20;
            break;
        case 3:
            chance1 = 0x19;
            chance2 = 0x28;
            break;
        case 4:
            chance1 = 0x80;
            chance2 = 0x80;
            break;
        }
        index = 0x22;
        if (-1 < previous) {
            index = previous;
        }
        if (func_0019D510() % chance1 == 0) {
            func_0038CF68(&scaled, &shot->step, 0.05f);
            func_L39_00523860((char *)self, shot, (u128_t *)&shot->step);
        }
        if (func_0019D510() % chance2 == 0) {
            func_0038CF68(&scaled, &shot->step, 0.05f);
            func_L01_00466F50((char *)shot, (char *)&scaled, 0, -1.0f, 0.0f);
        }
    }
    func_L39_005FFE78();
}
/* localdecomp:end func_L39_00522FA8 */

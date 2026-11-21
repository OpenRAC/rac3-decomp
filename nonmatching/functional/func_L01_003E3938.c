/* functional: high. 338 diff vs retail; every branch, delay-slot store order (hero+0x98), constants, 16-iteration burst loop, and particle args verified vs asm; gp globals renamed D_L01_001DF648/64C/650 for consistency */
/* localdecomp:start func_L01_003E3938 */
#include "vu0.h"
typedef struct { vu0_v4 velocity, anchor; s32 timer; u8 pad24[8]; s32 x2C; u8 *owner; } Vars_003E3938;
typedef struct { u8 pad[0x18]; u8 *hit; u8 pad1C[4]; vu0_v4 position; vu0_v4 spare; vu0_v4 normal; } Collision_003E3938;
typedef struct { u8 pad[0xD4]; u8 *pD4; } Table_003E3938;
extern Collision_003E3938 D_L01_001EAA00[1];
extern Table_003E3938 D_L01_00221098[1];
extern G_3E8D18 D_001A4BE0;
extern f32 D_L01_001DF648;
extern u32 D_L01_001DF64C, D_L01_001DF650;
__asm__(".extern D_L01_001DF648, 4");
__asm__(".extern D_L01_001DF64C, 4");
__asm__(".extern D_L01_001DF650, 4");
void func_L01_003E3938(u8 *m) {
    extern s32 func_0038CAD0(void *);
    extern void func_003C3938(void *, s32, s32);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004C7D40(void *, void *, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern s32 func_003D5630(void);
    extern u8 *func_L01_003016B0(void *, s32, f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern void func_L01_00468A68(void *, void *, s32, s32);
    extern void func_L01_003506B8(void);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern void func_003C48A8(void *, void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_00404A10(void (*)(void *), void *);
    extern void func_L01_003E3F08(void *);
    vu0_v4 temp, vector, a, b, c, normal;
    Vars_003E3938 *v = *(Vars_003E3938 **)(m + 0x68);
    u8 *hero, *p;
    s32 state, i, life, angleStep, joint, next, size;
    f32 angle, speed;
    if (m[0x20] == 0) {
        if (func_0038CAD0(&v->timer)) goto destroy;
        func_003C3938(m, 0, 0);
        *(u128_t *)&temp = *(u128_t *)(m + 0x10);
        func_L01_004C8688(v->x2C, v, 0);
        func_L01_004C7D40(m + 0x10, v, 0.0044f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(m + 0x10)) : "m"(*(vu0_v4 *)(m + 0x10)), "m"(*(vu0_v4 *)(v)) : "vf1", "vf2");
        *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), D_L01_001DF648 * 0.017453292f);
        hero = *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0);
        *(s32 *)(hero + 0x98) = 0;
        if (func_L01_003FB640(m + 0x10, 0, m, 0.2f)) {
            hero = *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0);
            *(s32 *)(hero + 0x98) = *(s32 *)(*(u8 **)(hero + 0x24) + 0x10);
            state = func_003D5630();
            if (((u32)state < 2 || state == 11) && v->velocity.z < 0.0f) {
                qzero(&v->velocity);
                v->velocity.z = -0.030000001f;
                vector.x = *(f32 *)(m + 0x10);
                vector.y = *(f32 *)(m + 0x14);
                vector.z = D_L01_001EAA00[0].position.z;
                p = func_L01_003016B0(&vector, 3, 2.0f, 1.025f);
                if (p != 0) p[0x23] = 0x70;
                for (i = 15; i >= 0; i--) {
                    angle = func_00382538();
                    speed = func_003824E0(0.0f, 0.060000002f);
                    a.x = func_0038D098(angle) * speed;
                    a.y = func_0038D0B0(angle) * speed;
                    a.z = func_003824E0(0.060000002f, 0.13000001f);
                    life = func_00382498(90, 120);
                    func_L01_00468A68(&vector, &a, func_00382468(2), life);
                }
                goto destroy;
            }
            if (D_L01_001EAA00[0].hit != 0) {
                v->owner = D_L01_001EAA00[0].hit;
                *(u128_t *)&v->anchor = *(u128_t *)(v->owner + 0x10);
            }
            *(u128_t *)(m + 0x10) = *(u128_t *)&D_L01_001EAA00[0].position;
            func_0038CE20((f32 *)&normal, (f32 *)&D_L01_001EAA00[0].normal, 0.0009765625f);
            func_0038CF68((f32 *)&normal, (f32 *)&normal, 1.0f);
            func_0038CE90((f32 *)&c, (f32 *)(m + 0xC0), (f32 *)&normal);
            func_0038CF68((f32 *)&c, (f32 *)&c, 1.0f);
            func_0038CE90((f32 *)&b, (f32 *)&normal, (f32 *)&c);
            func_003C48A8(&b, m + 0xF0);
            m[0x20] = 1;
        }
        hero = *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0);
        *(s32 *)(hero + 0x98) = *(s32 *)(*(u8 **)(hero + 0x24) + 0x10);
    }
    for (i = 0; i >= 0; i--) {
        angleStep = func_L01_00443A18(2.0f, 5.0f);
        joint = func_00382498(1, 3);
        next = joint + 1;
        if (joint == 3) next = 1;
        func_003C2F58(m, joint, &a);
        func_003C2F58(m, next, &b);
        func_0038CDF8(&temp, &a, &b, func_003824E0(0.0f, 1.0f));
        *(u128_t *)&c = *(u128_t *)&temp;
        c.z += 1.0f;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&vector)) : "m"(*(vu0_v4 *)(&c)), "m"(*(vu0_v4 *)(&temp)) : "vf1", "vf2");
        func_0038CF68((f32 *)&vector, (f32 *)&vector, func_003824E0(1.5f, 2.0f) * 0.020000001415610313f);
        size = (func_00382498(10, 15) * 5 + 2) / 6;
        func_L01_004713C8(&temp, &vector, size, D_L01_001DF64C, angleStep, 0x7F, 0x7F, 1, 46200.0f, 4200.0f, -0.0012f);
        angleStep = -angleStep * 2;
        size = (func_00382498(10, 15) * 5 + 2) / 6;
        p = func_L01_004713C8(&temp, &vector, size, D_L01_001DF650, angleStep, 0x30, 0x30, 0, 184800.0f, 8400.0f, -0.0012f);
        if (p != 0) p[2] = D_L01_00221098[0].pD4[0];
    }
    if (m[0x20] == 1) {
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.6f;
        if (m[0x43] != 0) func_003C3A10(m, 0, 0, 8);
        if (m[0x60] & 2) *(s32 *)(m + 0x48) = 0;
        if (v->owner != 0) {
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&temp)) : "m"(*(vu0_v4 *)(v->owner + 0x10)), "m"(*(vu0_v4 *)(&v->anchor)) : "vf1", "vf2");
            *(u128_t *)&v->anchor = *(u128_t *)(v->owner + 0x10);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(m + 0x10)) : "m"(*(vu0_v4 *)(m + 0x10)), "m"(*(vu0_v4 *)(&temp)) : "vf1", "vf2");
        }
        func_L01_00404A10(func_L01_003E3F08, m);
    }
    return;
destroy:
    func_L01_003506B8();
}
/* localdecomp:end func_L01_003E3938 */

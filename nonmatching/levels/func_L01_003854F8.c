/* func_L01_003854F8 (Claude wave 14 r64, 2026-11-28). First draft kept here. */
/* func_L01_003854F8, first draft (fresh entry, wave 14 r64): the Suck-Cannon-style shot (class 0x1881) update.
 * Plain C under the file's own line, check.py first placement 361 words, the same length as retail (617
 * words): control flow, calls, constants, stack layout (the target block's vectors and the case 0 query share
 * 0xB0..0xDF) and the loop forms match (for (i = 0; i < n; i++) loops, which gcc reverses into retail's count
 * downs). The hit record, the camera point and the hero are reached through the globals themselves (aliases
 * _003854F8, the file declares them with other types), which gives retail's reuse of their %hi parts;
 * D_L01_001D66B0 is sized 8 with .extern 16 for retail's lui/addiu at each call.
 * What still differs is register allocation only: (1) retail computes m+0x10 into $s0 for the first two
 * calls and copies it to $s7 for the rest (here one pseudo); the same for &query ($s1, copied to $s5);
 * (2) $s0/$s1/$s2 swapped between the counter, &eye, the 6/255 divisors and spin; (3) $f20/$f21 swapped for
 * 210000.0f and 0.0f in the particle calls. Callees defined later in the file with types declared later are
 * declared without prototypes (func_L01_003868A0) or with struct Moby (func_L01_00385EE0).
 */
#include "common.h"

/* localdecomp:start func_L01_003854F8 */
#include "vu0.h"
#include "structs/weapon.h"
#include "structs/moby.h"
typedef struct {
    s32 index;
    u8 pad4[0xC];
    s32 unk10;
    s32 a14;
    s32 a18;
    u8 *target;
    vu0_v4 vel;
    s32 shadow;
    s32 ticks;
    f32 inv_ticks;
    s32 hits;
    f32 unk40;
} Vars_003854F8;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 position;
    u8 state;
    u8 pad21[3];
    u8 *pclass;
    u8 pad28[0x34 - 0x28];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    Vars_003854F8 *pvar;
    u8 pad6C[0xAA - 0x6C];
    s16 oclass;
    u8 padAC[0xB8 - 0xAC];
    void *owner;
} Moby_003854F8;
typedef struct {
    vu0_q dir;
    void *owner;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 oclass;
    f32 damage;
    s32 w20;
} Query_003854F8;
typedef struct {
    u8 pad0[0x18];
    Moby_003854F8 *moby;
    u8 pad1C[4];
    vu0_v4 position;
    vu0_v4 v30;
    vu0_v4 normal;
} Hit_003854F8;
typedef struct {
    u8 pad0[0x25C0];
    void *moby;
} Hero_003854F8;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern Hit_003854F8 D_L01_001EAA00_003854F8;
extern vu0_v4 D_L01_001E29C0_003854F8;
extern Hero_003854F8 D_001A4BE0_003854F8;
extern u8 D_L01_001D66B0_003854F8[8];
__asm__(".extern D_L01_001D66B0_003854F8, 16");
extern u8 *D_L01_0022116C[];
extern u8 *D_L01_00221098[];

void func_L01_003854F8(Moby_003854F8 *m) {
    extern s32 func_L01_00457458(s32, s32);
    extern void func_003C2880(void *);
    extern void func_L01_004C8668(s32);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_L01_00386AD8(s32);
    extern f32 *func_00382348(s32);
    extern void func_003C2F58(void *, s32, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(vu0_q *, vu0_q *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern void func_L01_00386410(void *, void *, s32, s32);
    extern void func_L01_0034C9F0(void *, s32, void *);
    extern s32 func_003D4D00(void *, f32, s32, void *, s32);
    extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32,
                                 s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern void func_L01_00470668(void *, void *, s32, f32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_003868A0();
    extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_00385EA0(char *);
    extern void func_L01_00385EE0(struct Moby *);
    vu0_v4 saved;
    vu0_v4 normal;
    Vars_003854F8 *vars = m->pvar;
    vu0_v4 *pos;
    f32 len;
    f32 speed;

    if (!func_L01_00457458(vars->a18, vars->a14)) {
        func_003C2880(m);
        func_L01_004C8668(vars->shadow);
        return;
    }
    func_L01_004CAB30(&m->position, &m->position);
    pos = &m->position;
    *(vu0_q *)&saved = *(vu0_q *)&m->position;
    func_003C5180(pos, &normal, 1);
    if (vars->target != 0) {
        if (vars->target[0x20] == 0xFE) {
            vars->target = 0;
        } else if (vars->target[0x20] == 0xFD) {
            vars->target = 0;
        } else if (func_L01_00386AD8((s32)vars->target)) {
            vars->target = 0;
        } else {
            vu0_v4 dir;
            vu0_v4 lead;
            vu0_v4 point;
            f32 *r;

            vec_sub_ba(&dir, vars->target + 0x10, &m->position);
            r = func_00382348((s32)vars->target);
            if (r != 0) {
                func_0038CE20((vu0_q *)&lead, (vu0_q *)(vars->target + 0xE0), r[4]);
                if (*(s16 *)(vars->target + 0xAA) == 0x1AB8) {
                    func_003C2F58(vars->target, 4, &point);
                    vec_sub_ab(&lead, &point, vars->target + 0x10);
                }
                vec_add_ab(&dir, &dir, &lead);
                len = func_0038CEA8(&dir);
            } else {
                len = func_0038CEA8(&dir);
            }
            if (len != 0.0f) {
                speed = *(f32 *)((u8 *)vars + 0x2C);
                func_0038CE20((vu0_q *)&vars->vel, (vu0_q *)&dir, speed / len);
                *(f32 *)((u8 *)vars + 0x2C) = speed;
            } else {
                vars->target = 0;
            }
        }
    }
    switch (m->state) {
    case 0: {
        Query_003854F8 query;
        vu0_v4 eye;
        vu0_v4 spark;
        vu0_v4 spawn;
        Hero_003854F8 *hero;
        u8 *p;
        s32 n;
        s32 i;
        s32 spin;
        f32 size;

        func_L01_004C8688(vars->shadow, &vars->vel, 0);
        vec_add_ba(&m->position, &m->position, &vars->vel);
        query.owner = m->owner;
        query.flags = 0x10000;
        query.w20 = 1;
        query.damage = (D_L01_002C5600 + D_001425C0[0x2F])->damage;
        query.dir = *(vu0_q *)&vars->vel;
        func_0038CF68(&query, &query, 1.0f);
        ((f32 *)&query.dir)[3] = 5627.9248046875f;
        query.oclass = m->oclass;
        query.b18 = 1;
        query.b19 = 1;
        hero = &D_001A4BE0_003854F8;
        if (func_003D3CB0(&saved, pos, 0, hero->moby, &query)) {
            if (D_L01_001EAA00_003854F8.moby == 0) {
                vars->hits++;
                func_L01_0040E790(&vars->vel, &vars->vel, &D_L01_001EAA00_003854F8.normal);
                func_L01_00386410(m, &D_L01_001EAA00_003854F8.position, 0xF, 0);
            } else if (D_L01_001EAA00_003854F8.moby->oclass == 0x1F6) {
                m->state = 1;
                vars->target = 0;
                m->h34 |= 0x41;
                vars->ticks = 5;
                func_L01_00386410(m, &D_L01_001EAA00_003854F8.position, 0xA, 1);
                func_L01_0034C9F0(D_L01_001EAA00_003854F8.moby, 0x30, m->owner);
                func_003D4D00(&D_L01_001EAA00_003854F8.position, 1.0f, 0, m, (s32)&query);
            } else if (D_L01_001EAA00_003854F8.moby->pclass != 0 && D_L01_001EAA00_003854F8.moby->pclass[0x46] == 5) {
                m->state = 1;
                vars->target = 0;
                m->h34 |= 0x41;
                vars->ticks = 5;
                func_L01_00386410(m, &D_L01_001EAA00_003854F8.position, 0xA, 1);
                func_L01_0034C9F0(D_L01_001EAA00_003854F8.moby, 0x30, m->owner);
                func_003D4D00(&D_L01_001EAA00_003854F8.position, 1.0f, 0, m, (s32)&query);
            } else {
                vars->hits++;
                func_L01_0040E790(&vars->vel, &vars->vel, &D_L01_001EAA00_003854F8.normal);
                func_L01_00386410(m, &D_L01_001EAA00_003854F8.position, 0xF, 0);
                func_003D4D00(&D_L01_001EAA00_003854F8.position, 1.0f, 0, m, (s32)&query);
            }
            if (vars->hits < 2) {
                func_L01_003303B8(&D_L01_001EAA00_003854F8.position, 0, 1, 1, 1, 1, 1, 0, 0.17f, 0.0f, 0.0f, 0.0f,
                                  0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x2040FF, 0x63FF, 0x307FFF, 0x20FF, 0x8FFF,
                                  0x2064FF, 0x7F3030FF, 0x280000FF, 0x1010FF, 0);
            }
            hero = &D_001A4BE0_003854F8;
            if (D_L01_001EAA00_003854F8.moby != hero->moby) {
                vec_sub_ba(&eye, &D_L01_001E29C0_003854F8, &D_L01_001EAA00_003854F8.position);
                func_0038CF68(&eye, &eye, func_003824E0(0.1f, 0.2f));
                n = (vars->hits <= 1) ? 10 : 2;
                for (i = 0; i < n; i++) {
                    eye.x += func_003824E0(-0.05f, 0.05f);
                    eye.y += func_003824E0(-0.05f, 0.05f);
                    eye.z += func_003824E0(-0.05f, 0.05f);
                    spin = func_00382498(0x19, 0x28);
                    func_L01_00470668(&D_L01_001EAA00_003854F8.position, &eye, (spin * 5 + 2) / 6, 0.00584f);
                }
            }
        } else if (func_0038CAD0(&vars->ticks)) {
            func_L01_003868A0(m, pos);
            m->state = 1;
            vars->target = 0;
            m->h34 |= 0x41;
            vars->ticks = 5;
        }
        spin = func_00382468(0xFF);
        p = func_L01_0046FB40(pos, D_L01_001D66B0_003854F8, 2, 0x1020FF, spin, 0x40, 0x10, 210000.0f, 210000.0f, 0.0f, 1);
        if (p != 0) {
            p[2] = *D_L01_0022116C[0];
        }
        spin = (spin + 0x80) % 255;
        p = func_L01_0046FB40(pos, D_L01_001D66B0_003854F8, 2, 0x1020FF, spin, 0x40, 0x10, 210000.0f, 210000.0f, 0.0f, 1);
        if (p != 0) {
            p[2] = *D_L01_0022116C[0];
        }
        spin = (spin + 0x40) % 255;
        p = func_L01_0046FB40(pos, D_L01_001D66B0_003854F8, 2, 0x4F4FFF, spin, 0x30, 0x10, 126000.0078125f, 126000.0078125f, 0.0f, 1);
        if (p != 0) {
            p[2] = *D_L01_0022116C[0];
        }
        vec_sub_ba(&eye, &m->position, &saved);
        func_0038CE20((vu0_q *)&eye, (vu0_q *)&eye, 0.4f);
        *(vu0_q *)&spark = *(vu0_q *)&saved;
        for (i = 0; i < 2; i++) {
            spin = func_00382468(0xFF);
            size = func_003824E0(0.2f, 0.6f);
            spawn.x = spark.x + func_L01_00443A18(0.0f, 0.05f);
            spawn.y = spark.y + func_L01_00443A18(0.0f, 0.05f);
            spawn.z = spark.z + func_L01_00443A18(0.0f, 0.05f);
            p = func_L01_0046FB40(&spawn, D_L01_001D66B0_003854F8, 0xC, 0x4080FF, spin, 0x20, 0, size * 210000.0f,
                                  size * 0.2f * 210000.0f, 0.0f, 1);
            vec_add_ab(&spark, &spark, &eye);
            if (p != 0) {
                p[2] = D_L01_00221098[91][0];
            }
        }
        func_L01_00404A10(func_L01_00385EE0, m);
        break;
    }
    case 1:
        if (func_0038CAD0(&vars->ticks)) {
            func_L01_00385EA0((char *)m);
        }
        func_L01_00404A10(func_L01_00385EE0, m);
        break;
    }
    if (m->position.x < 2.0f || m->position.x > 1021.0f || m->position.y < 2.0f || m->position.y > 1021.0f ||
        m->position.z < 2.0f || m->position.z > 1021.0f || vars->hits >= 8) {
        func_L01_00385EA0((char *)m);
    }
}
/* localdecomp:end func_L01_003854F8 */

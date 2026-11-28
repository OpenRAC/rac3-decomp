/* func_L01_0031D510 (Claude wave 14 r71, 2026-11-28). First draft kept here. */
/* PAL near miss (r71, wave 14, 2026-11-28), first draft: 142 differences (wave10/p10/check.py, level 01, the file's flags,
 * with the divs_nops row this function needs: NEEDS divs row 'func_L01_0031D510 2' (two nops before its one div.s)).
 * Written from the retail assembly with the functional C's types (nonmatching/functional/func_L01_0031D510.c). Thrown-ball
 * update: state 0 flies (VU0 pos += vel, a 3-spark trail, the collision request of func_L01_004C7E70, the damage probe of
 * func_003D4D00, bounces), state 1 spins, state 2 removes. Levers found: the frame (0x170) needs the vector temporaries as
 * function-scope f32[4] arrays reused as retail's slots show (0x10 old position / state-1 rotation, 0x20 trail point / the
 * 8-byte option block, 0x30 current position / spin axis): TImode locals get their slots late (when their address is taken);
 * the explode tail written out at each of its three sites (func_L01_0031DB70 + func_003C2880 + return; cross-jumping merges
 * them as retail): with a shared `goto explode` label cse followed the jump into the code after the collision test and
 * reused factor0's 1.0f in $f22 (250 -> 142). Still differs: the loop preheader's constant order (1.0f before 65000.0f),
 * register numbers in state 0's tail (res $s5 for $s6, vars + 0x10 $s1 for $s4, retail keeps obj + 0x10 in $s1 for the
 * func_003D4D00 call), the trail call's movz / D_L01_001D66B0 scheduling, the option-block copy's scheduling, and
 * func_0038CE20(along, ...) keeps &along in $s1 across func_0038CE68 (retail computes it after; splitting the call into
 * two statements renumbers every register: 270). */
#include "common.h"

/* localdecomp:start func_L01_0031D510 */
#include "vu0.h"
typedef int Q_0031D510 __attribute__((mode(TI)));
typedef struct { u8 b[8]; } Opt_0031D510;
typedef struct {
    Q_0031D510 start, end, velocity;
    u8 *hit;
    Opt_0031D510 *options;
    s32 mode;
    f32 radius, factor0, factor1;
    s32 flags, unknown;
    s32 out90, out94;
    s32 field98;
    s32 pad9C;
} Move_0031D510;
typedef struct {
    f32 dir[4];
    u8 *owner;
    u32 kind;
    u8 type, flag;
    u16 klass;
    f32 power;
    s32 enabled;
} Dmg_0031D510;
extern Opt_0031D510 D_L01_001DC898;
extern u8 D_001425C0[];
extern G_31DB28 D_L01_002C5600[];
extern Q_0031D510 D_L01_001EAA30[];
extern T_31DB28 *D_001A71A0[];
extern u8 D_L01_001D66B0[];
extern s32 D_L01_001D673C[];
extern s32 D_L01_001D6740[];
extern f32 D_L01_001DC870, D_L01_001DC878, D_L01_001DC880, D_L01_001DC884, D_L01_001DC88C, D_L01_001DC890;
extern s32 D_L01_001DC894;
__asm__(".extern D_L01_001DC870, 4");
__asm__(".extern D_L01_001DC878, 4");
__asm__(".extern D_L01_001DC880, 4");
__asm__(".extern D_L01_001DC884, 4");
__asm__(".extern D_L01_001DC88C, 4");
__asm__(".extern D_L01_001DC890, 4");
__asm__(".extern D_L01_001DC894, 4");
void func_L01_0031D510(u8 *obj) {
    extern void func_003C5180(u8 *, f32 *, s32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(u8 *, u8 *);
    extern void func_L01_004C8688(s32, u8 *, s32);
    extern void func_L01_004C7D40(u8 *, u8 *, f32);
    extern s32 func_0038CAD0(s32);
    extern void func_003C4098(void *, void *, void *, f32);
    extern s32 func_L01_004C7E70(Move_0031D510 *, s32);
    extern s32 func_L01_004CB018(s32);
    extern void func_0038D850(void *, void *, void *);
    extern void func_0038CF68(f32 *, s32, f32);
    extern s32 func_003D4D00(void *, s32, void *, void *, f32);
    extern void func_0038CE90(float *, float *, float *);
    extern f32 func_003824E0(f32, f32);
    extern void func_003C4840(f32 *, u8 *, f32);
    extern s32 func_003A52A0(s32, s32, u8 *);
    extern void func_L01_00451290(u8 *, f32 *, s32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_0031DB70(u8 *);
    extern void func_003C2880(Moby_0031BEF0 *);
    extern void func_L01_004471A8(u8 *, f32);
    f32 normal[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    Move_0031D510 move;
    Dmg_0031D510 dmg;
    f32 axis[4] __attribute__((aligned(16)));
    f32 along[4] __attribute__((aligned(16)));
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 scale;

    func_003C5180(obj + 0x10, normal, 1);
    if (func_L01_004CB2D8()) {
        func_L01_004CAB30(obj + 0x10, obj + 0x10);
    }
    switch (obj[0x20]) {
    case 0: {
        s32 res;
        f32 radius;
        f32 factor;
        *(Q_0031D510 *)a = *(Q_0031D510 *)(obj + 0x10);
        vec_add_ab(obj + 0x10, obj + 0x10, vars);
        func_L01_004C8688(*(s32 *)(vars + 0x30), vars, 0);
        func_L01_004C7D40(obj + 0x10, vars, 0.0058400002f);
        func_0038CAD0((s32)(vars + 0x28));
        if (*(s32 *)(vars + 0x28) != 0) {
            s32 i;
            for (i = 0; i < 3; i++) {
                s32 life;
                f32 size;
                s32 sign;
                u8 *p;
                *(Q_0031D510 *)c = *(Q_0031D510 *)(obj + 0x10);
                func_003C4098(b, a, c, (f32)i * 0.3333f);
                life = func_00382468(6);
                sign = func_00382468(2);
                size = (f32)*(s32 *)(vars + 0x28) / 42.0f * 65000.0f + 10000.0f;
                p = func_L01_004669B0(0.025f, 1.0f, 1.0f, size,
                    (u8 *)b, sign ? -life : life, (f32 *)D_L01_001D66B0, 0x80808080, 1);
                if (p != 0) {
                    u8 *q = p + 0x20;
                    *(s16 *)(p + 0xA) = 42;
                    *(s32 *)(q + 4) = 2;
                    q[0xA] = 0x7F;
                    q[0xB] = p[0xA];
                }
            }
        }
        {
            *(Opt_0031D510 *)b = D_L01_001DC898;
            factor = 1.5f;
            if ((f32)*(s32 *)(vars + 0x24) == 3.0f) {
                factor = 0.0f;
            }
            radius = D_L01_001DC880;
            if (*(s32 *)(vars + 0x2C) != 0) {
                radius = D_L01_001DC88C;
            }
            move.start = *(Q_0031D510 *)a;
            move.end = *(Q_0031D510 *)(obj + 0x10);
            move.velocity = *(Q_0031D510 *)vars;
            move.hit = obj;
            move.options = (Opt_0031D510 *)b;
            move.mode = 2;
            move.radius = radius;
            move.factor0 = (D_L01_001DC870 - 1.0f) * 1.2f + 1.0f;
            move.factor1 = factor;
            move.flags = 0;
            move.unknown = 0;
            move.field98 = 0;
            res = func_L01_004C7E70(&move, -1);
            {
                s32 r = func_L01_004CB018(move.out94);
                if (res > 0 && (r == 1 || r == 2)) {
                    func_L01_0031DB70(obj);
                    func_003C2880((Moby_0031BEF0 *)obj);
                    return;
                }
            }
            *(Q_0031D510 *)(obj + 0x10) = move.end;
            *(Q_0031D510 *)vars = move.velocity;
            func_0038D850(obj + 0xC0, obj + 0xC0, vars + 0x10);
            func_0038D850(obj + 0xD0, obj + 0xD0, vars + 0x10);
            func_0038D850(obj + 0xE0, obj + 0xE0, vars + 0x10);
            *(Q_0031D510 *)dmg.dir = *(Q_0031D510 *)vars;
            dmg.owner = obj;
            dmg.kind = 0x01030000;
            dmg.power = D_L01_002C5600[D_001425C0[0x13]].f6C;
            dmg.enabled = 1;
            func_0038CF68(dmg.dir, (s32)dmg.dir, 1.0f);
            dmg.dir[3] = 5627.9248046875f;
            dmg.type = 3;
            dmg.klass = *(u16 *)(obj + 0xAA);
            dmg.flag = 1;
            if (func_003D4D00(obj + 0x10, 1, D_001A71A0[0], &dmg, radius + 0.5f)) {
                func_L01_0031DB70(obj);
                func_003C2880((Moby_0031BEF0 *)obj);
                return;
            }
            if (res > 0) {
                *(Q_0031D510 *)c = *(Q_0031D510 *)vars;
                c[2] = 0.0f;
                func_0038CE90(c, c, normal);
                func_0038CF68(c, (s32)c, 1.0f);
                func_003C4840((f32 *)(vars + 0x10), (u8 *)c, func_003824E0(0.06283185631036758f, 0.12566371262073517f));
                func_003A52A0(1, 0, obj);
                *(s32 *)(vars + 0x24) += 1;
                if (*(s32 *)(vars + 0x24) >= 4) {
                    f32 speed;
                    *(Q_0031D510 *)(obj + 0x10) = D_L01_001EAA30[0];
                    obj[0x20] = 1;
                    *(s32 *)(vars + 0x20) = (D_L01_001DC894 * 5 + 2) / 6;
                    speed = D_L01_001DC878 * 0.06283185631036758f;
                    if (*(s32 *)(vars + 0x2C) != 0) {
                        speed *= D_L01_001DC884;
                    }
                    func_L01_00451290(obj, axis, 1);
                    func_0038CE20(along, axis, func_0038CE68(axis, vars));
                    vec_sub_ab(vars, vars, along);
                    func_0038CF68((f32 *)vars, (s32)vars, speed);
                    *(Q_0031D510 *)(vars + 0x10) = *(Q_0031D510 *)c;
                    *(f32 *)(vars + 0x1C) = 0.06283185631036758f;
                }
            }
        }
        break;
    }
    case 1: {
        f32 drag;
        vec_add_ba(obj + 0x10, obj + 0x10, vars);
        func_003C4840(a, vars + 0x10, *(f32 *)(vars + 0x1C));
        func_0038D850(obj + 0xC0, obj + 0xC0, a);
        func_0038D850(obj + 0xD0, obj + 0xD0, a);
        func_0038D850(obj + 0xE0, obj + 0xE0, a);
        drag = (D_L01_001DC890 - 1.0f) * 1.2f + 1.0f;
        *(f32 *)(vars + 0x1C) *= drag;
        func_0038CE20(vars, vars, drag);
        if (func_0038CAD0((s32)(vars + 0x20))) {
            func_L01_0031DB70(obj);
            func_003C2880((Moby_0031BEF0 *)obj);
            return;
        }
        break;
    }
    case 2:
        func_003C2880((Moby_0031BEF0 *)obj);
        return;
    }
    scale = D_L01_001DC878;
    if (*(s32 *)(vars + 0x2C) != 0) {
        scale *= D_L01_001DC884;
    }
    if (D_L01_001D673C[0] == 0 && D_L01_001D6740[0] == 0) {
        func_L01_004471A8(obj, scale);
    }
    return;
}
/* localdecomp:end func_L01_0031D510 */

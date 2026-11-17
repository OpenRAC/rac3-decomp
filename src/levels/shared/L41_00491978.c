#include "common.h"

/* localdecomp:start func_L41_00491978 */
/* signature: void * params as L41_0041B308.c declares them; the 10th is u8 (retail lbu), see .decl */
/* log: first draft 166 diff (sd saves, gp/lui of D_001D7C04_sda); .extern hint for the sda slot + --as ps2as;
   --flags=-fno-opt-stack gives sq $s saves but $ra stays sd in the lowest slot (sq_ra class);
   bit test written ((maskB >> i) ^ 1) & 1 for retail xori/andi/bnez (!(...&1), ~maskB, != 1 all fail).
   Best: 20 diff with --as ps2as --flags=-fno-opt-stack, all 20 in the save/restore layout only
   (same at level_42, level_45, level_51). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00491978;
typedef struct {
    u8 pad0[0x10];
    V_00491978 x10;
    u8 pad20[0x5C];
    s16 x7C;
    u8 pad7E[0x1A];
    s32 x98;
    u8 pad9C[0xE];
    s16 xAA;
    u8 padAC[0x14];
    V_00491978 xC0;
    u8 padD0[0x20];
    V_00491978 xF0;
} M_00491978;
typedef struct { u8 pad[0x64]; s32 x64; } S_00491978;

__asm__(".extern D_001D7C04_sda, 4");
extern s32 D_001D7C04_sda;
extern s32 D_L41_0024112C;
extern s32 D_L41_00248818;
extern void func_L01_00439880(void *, s32 *, s32 *);
extern void func_L39_005F33E0(s32, s32, void *);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern S_00491978 *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
void func_L41_00491978(void *mv, void *bv, void *cv, void *dv, s32 maskA, s32 id, s32 skip, s32 flags,
                       s32 maskB, u8 e, s32 f) {
    M_00491978 *m = mv;
    f32 *b = bv;
    f32 *c = cv;
    f32 *d = dv;
    s32 i;
    s32 n;
    s32 cnt;
    f32 r1;
    f32 r2;
    V_00491978 v;
    S_00491978 *s;

    if (D_001D7C04_sda != D_L41_0024112C) {
        D_001D7C04_sda = D_L41_0024112C;
        D_L41_00248818 = 0;
    }
    D_L41_00248818++;
    if (m == 0) {
        return;
    }
    m->x7C = 0;
    m->x98 = 0;
    func_L01_00439880(m, &n, &cnt);
    if (id != -1) {
        func_L39_005F33E0(id, 0, m);
    }
    for (i = 0; i < cnt; i++) {
        if (skip == i) {
            continue;
        }
        if (((maskB >> i) ^ 1) & 1) {
            continue;
        }
        r1 = func_L39_005B4410(d[0], d[1]);
        r2 = func_L39_005B4410(c[0], c[1]);
        if (flags & 2) {
            v.x = func_L39_005B4468(b[0], b[4]) * 0.020000001f;
        } else {
            v.x = func_L39_005B4410(b[0], b[4]) * 0.020000001f;
        }
        if (flags & 4) {
            v.y = func_L39_005B4468(b[1], b[5]) * 0.020000001f;
        } else {
            v.y = func_L39_005B4410(b[1], b[5]) * 0.020000001f;
        }
        v.z = func_L39_005B4410(b[2], b[6]) * 0.020000001f;
        if (!(flags & 8)) {
            func_0038D000(&v, &v, &m->xC0);
        }
        if ((maskA >> i) & 1) {
            s = func_L01_003F79D8(m, 2, m->xAA, i, &m->x10, &m->xF0, &v, e, r2, r1, 0xB4, 0, 0x80);
        } else {
            s = func_L01_003F79D8(m, 1, m->xAA, i, &m->x10, &m->xF0, &v, e, r2, r1, 0xB4, 0, 0x80);
        }
        if (s != 0 && f != 0) {
            s->x64 = f;
        }
    }
}
/* localdecomp:end func_L41_00491978 */

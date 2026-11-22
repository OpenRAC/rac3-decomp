/* func_L05_003629B8 (PAL): 4 differences, all one scheduling tie. The PAL port of the NTSC-U draft of
 * func_L05_00361680 (frontbin and level callees by their PAL names, gp slots D_L05_001DDA40..D_L05_001DDA60
 * (level names: level 10 has them at other $gp offsets, where the earlier D_001DDA40_sda names gave 13 more differences), 0.020000001f and
 * 0.080000006f for 1/50 and 4/50, the hand-written add helpers replaced by vec_add_ba / vec_add_ab). Needs on its file
 * (src/levels/shared/L05_003629B8.c): -mvu0-use-vf0-vf2 in config/levels/text_parts.txt and `#include "vu0.h"`.
 * func_L05_00363330 is called with a second argument (20) its one-parameter definition does not take: the K&R
 * declaration `extern void func_L05_00363330();` in this block allows that without changing func_L05_00363330's
 * block (measured 2026-11-21: this draft followed by that block, 4 diffs here and MATCH for func_L05_00363330).
 * Differs: the arguments of func_0038CF68(&retreat, &p->dir, D_L05_001DDA44 * 0.020000001f) and the likely branch before
 * them. Retail: addiu $a0,$sp,96; lui/ori/mtc1 $f12; move $a1,$s3 (and `beql` with the addiu in its slot); this C:
 * move $a1,$s3 first, addiu $a0 after the constant. sched1 dump: the ready list is `588 590 584 582`; insn 590
 * (`$5 = r296`, the last use of &p->dir) carries a REG_DEAD note, so its register weight is 0 against 1 for insn 588
 * (`$4 = $sp+96`), and the lower weight wins (rank_for_schedule key 2, sched1 only). Tried without effect: a float
 * local for the product (before the block, at the top, in its own block), a local pointer to p->dir (141 diffs), a
 * pointer to retreat, retreat declared in the inner block, 0.020000001f * D_L05_001DDA44, the float as the second
 * parameter of the prototype (all 4); &m->p->dir (101), p reloaded after the call (246). */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L05_003629B8 */
typedef int Q_3629B8 __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_3629B8;
typedef struct { V_3629B8 origin, pos, dir; u8 pad30[4]; float distance, age, damage; } P_3629B8;
typedef struct { u8 pad[0x68]; P_3629B8 *p; u8 pad6c[0xaa - 0x6c]; s16 kind; u8 padac[12]; void *owner; } M_3629B8;
typedef struct { u8 pad[0x18]; M_3629B8 *obj; u8 gap[4]; V_3629B8 pos; } HitGlobal_3629B8;
typedef struct { u8 pad[0x1a]; u16 kind; u8 rest[0x14]; } Hit_3629B8;
extern float D_L05_001DDA40, D_L05_001DDA44, D_L05_001DDA48, D_L05_001DDA4C, D_L05_001DDA50, D_L05_001DDA54, D_L05_001DDA58;
extern int D_L05_001DDA5C, D_L05_001DDA60;
__asm__(".extern D_L05_001DDA40,4");
__asm__(".extern D_L05_001DDA44,4");
__asm__(".extern D_L05_001DDA48,4");
__asm__(".extern D_L05_001DDA4C,4");
__asm__(".extern D_L05_001DDA50,4");
__asm__(".extern D_L05_001DDA54,4");
__asm__(".extern D_L05_001DDA58,4");
__asm__(".extern D_L05_001DDA5C,4");
__asm__(".extern D_L05_001DDA60,4");
extern M_3629B8 *D_L05_001EA6D8[];
extern HitGlobal_3629B8 D_L05_001EA6C0[];
extern void func_L05_00362EE0(u8 *);
extern void func_0038CF68(void *, void *, float);
extern float func_0038CF38(void *, void *);
extern void func_L01_00446760(void *, M_3629B8 *, int, float, void *);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern int func_003D3CB0(void *, void *, int, void *, void *);
extern int func_L01_00456250(void *);
extern void func_L05_00363330();
extern void func_L01_00456230(void *, int);
extern void func_003C2880(void *);
extern int func_00382468(int);
extern float func_003824E0(float, float);
extern u8 *func_L01_0046A938(void *, void *, int, float, float);
extern void func_L01_00404A10(void *, void *);

void func_L05_003629B8(M_3629B8 *m) {
    V_3629B8 start;
    V_3629B8 step;
    Hit_3629B8 hit;
    V_3629B8 mid;
    V_3629B8 retreat;
    P_3629B8 *p = m->p;
    int collided;
    HitGlobal_3629B8 *g;
    V_3629B8 *point;
    u8 *particle;
    float damage;
    p->age += 1.0f;
    if (p->age > 2.0f) start = p->pos;
    else start = p->origin;
    damage = p->damage;
    if (p->age < D_L05_001DDA48) {
        p->distance += D_L05_001DDA40 * 0.020000001f;
        func_0038CF68(&p->pos, &p->dir, p->distance);
        func_0038CF68(&step, &p->dir, 0.080000006f);
        func_L01_00446760(&hit, m, 0x10001, damage, &step);
        hit.kind = m->kind;
        vec_add_ba(&p->pos, &p->origin, &p->pos);
        func_0038CF68(&mid, &p->dir, -(D_L05_001DDA40 * 0.020000001f));
        vec_add_ab(&mid, &mid, &p->pos);
        func_L01_004CB320();
        collided = func_003D3CB0(&start, &p->pos, 0, m, &hit);
        if (collided && D_L05_001EA6D8[0] && D_L05_001EA6D8[0]->kind == 0x186d && ((u8 *)D_L05_001EA6D8[0])[0x20] != 2 && ((u8 *)D_L05_001EA6D8[0])[0x20] != 5) ((u8 *)D_L05_001EA6D8[0])[0x20] = 4;
        func_L01_004CB358();
        if (collided && (g = D_L05_001EA6C0, g->obj != m->owner) && (!g->obj || g->obj->kind != 0x1625)) goto impact;
    } else if (p->age >= D_L05_001DDA48 && p->age < D_L05_001DDA4C) {
        if (func_0038CF38(&p->origin, &p->pos) > D_L05_001DDA40 * 0.020000001f) {
            p->distance += D_L05_001DDA40 * 0.020000001f;
            func_0038CF68(&p->pos, &p->dir, p->distance);
            func_0038CF68(&step, &p->dir, 0.080000006f);
            func_L01_00446760(&hit, m, 0x10001, damage, &step);
            hit.kind = m->kind;
            vec_add_ba(&p->pos, &p->origin, &p->pos);
            func_0038CF68(&mid, &p->dir, -(D_L05_001DDA40 * 0.020000001f));
            vec_add_ab(&mid, &mid, &p->pos);
            func_L01_004CB320();
            collided = func_003D3CB0(&start, &p->pos, 0, m, &hit);
            if (collided && D_L05_001EA6D8[0] && D_L05_001EA6D8[0]->kind == 0x186d && ((u8 *)D_L05_001EA6D8[0])[0x20] != 2 && ((u8 *)D_L05_001EA6D8[0])[0x20] != 5) ((u8 *)D_L05_001EA6D8[0])[0x20] = 4;
            func_L01_004CB358();
            if (collided && (g = D_L05_001EA6C0, g->obj != m->owner) && (!g->obj || g->obj->kind != 0x1625)) {
impact:
                point = &g->pos;
                p->pos = *point;
                if (!func_L01_00456250(m)) {
                    func_L05_00363330(point, 20);
                    func_L01_00456230(m, 1);
                }
                func_003C2880(m);
                return;
            }
            func_0038CF68(&retreat, &p->dir, D_L05_001DDA44 * 0.020000001f);
            vec_add_ab(&p->origin, &p->origin, &retreat);
        } else return;
    } else {
        goto expired;
    }
    if (!func_00382468(D_L05_001DDA60)) {
        float f = func_003824E0(D_L05_001DDA50, D_L05_001DDA54);
        particle = func_L01_0046A938(&p->pos, 0, D_L05_001DDA5C, f, D_L05_001DDA58 * 210000.0f);
        if (particle) particle[1] = 0;
    }
    func_L01_00404A10(func_L05_00362EE0, m);
    return;
expired:
    func_L05_00363330(&p->pos, 20);
    func_003C2880(m);
}
/* localdecomp:end func_L05_003629B8 */

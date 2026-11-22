/* PAL port (2026-11-20) of the NTSC-U draft of func_L05_003BB658 (Codex worker, 2026-11-14), with PAL names, PAL data
 * and PAL's 50 Hz timer `(D_L05_001DEAE0 * 5 + 2) / 6`, and the VU0 sums written with include/vu0.h's helpers.
 * tools/check.py at level 05 with its file's line (L05_003BD448.c, which has -fno-sched-interblock): 347 differences
 * (task #2895, 2026-11-22). The positional count is higher than the earlier 312 although the code is closer: aligned
 * with diff(1), 48 instruction lines differ, against 78 for the earlier draft. The 312 included two `lui`/`lw` pairs
 * for D_L05_001DEAE0 that offset part of the one-word shift below; with the block's own declaration and `.extern`
 * hint retail's `lw 0x2230($gp)` comes out, which removes that accidental compensation.
 * The table D_L05_002A64C0 (`Row_3BD448`) is the file's own declaration, from func_L05_003BD448's block, so this
 * draft compiles in its file's context only (check.py without --no-context). Every other global and callee is
 * declared here (r3-37); func_L05_003BD078 was undeclared (implicit int) in the earlier draft.
 * Fixed in task #2895: D_L05_001DEAE0 declared with its `.extern` size ($gp load); the spawner func_L01_0046FB40
 * declared as the rest of src/ declares it, `(..., f32, f32, f32, s32)`, which puts `move $t3, $zero` in the
 * `jal` delay slots as retail has it; the damage record as a local struct written +0x18, +0x19, type, which gives
 * retail's registers ($v1 type, $v0 the 1).
 * What still differs:
 * - Retail keeps the particle colour 0x1010FF in $s0, set at the head of the loop (`lui` in the random call's delay
 *   slot), with the loop counter in $s4 and the table base in $s5. Ours puts the constant into $a3 at each call, so it
 *   saves one register fewer (frame 0xD0 against 0xE0). Task #2895's RTL dumps (-da) show why: CSE (in the same block)
 *   and GCSE's constant propagation (from a set before the loop, "CONST-PROP: Replacing reg ... with constant") put the
 *   constant into both argument moves, because this port prices every CONST_INT at 0. So retail's colour was not a
 *   constant CSE could see. Tried without effect: a `col` local inside or outside the loop (s32/u32, before or after
 *   the random call), set before the loop in an enclosing block, the loop counting up (`for`, `while`) or as a
 *   do-while: 346/347 each, all with the same 0x1010FF diff.
 * - The damage record's stores: retail `sb 1, +0x19; sh type, +0x1A; sb 1, +0x18`, its source order kept. In our
 *   sched1 dump the three stores are independent and are reordered; all 6 orders and 5 chained or copied forms put
 *   the `sh` first or last, never between. (The L01 twin func_L01_0035B710 gets that order, but its +0x18 store is 0.)
 * Fixed earlier: `scale = 1.0f` assigned after the two normalise calls gives retail's `mov.s $f21, $f20`, and a
 * sized `D_L05_001D66B0[8]` with its `.extern` gives the per-call `lui`/`addiu`.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003BD5E0 */
typedef struct {
    u8 pad[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0x47];
    u8 *vars;
    u8 pad6C[0x3E];
    s16 type;
    u8 padAC[0xC];
    void *parent;
} M_003BD5E0;

extern void func_003C2F58(void *, s32, void *);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_00382348(void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L05_003BDFA8(void *, s32, void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L05_003BDB68();

extern M_003BD5E0 *D_001A71A0[];
extern void func_L05_003BD078(u8 *);
extern s32 D_L05_001DEAE0;
__asm__(".extern D_L05_001DEAE0, 4");
extern f32 D_L05_001DEAE4;
__asm__(".extern D_L05_001DEAE4, 4");
extern vu0_v4 D_L05_001EA6E0[];
extern u8 D_L05_00220758[];
extern u8 D_L05_001D66B0[8];
__asm__(".extern D_L05_001D66B0, 16");

void func_L05_003BD5E0(M_003BD5E0 *m) {
    vu0_v4 p0, p10, p20, p30, hit, dir;
    struct { u8 pad[0x18]; u8 a18; u8 a19; u16 type; u8 pad1C[0x14]; } damage;
    u8 *v = m->vars;
    f32 angle;
    s32 i;
    u8 *part;
    u8 *tbl;

    func_003C2F58(m->parent, *(s32 *)(v + 0x1C), &p0);
    *(vu0_q *)&m->pos = *(vu0_q *)&p0;
    func_003C5180(&m->pos, &p10, 1);
    *(vu0_q *)&p20 = *(vu0_q *)&m->pos;
    vec_sub_ba(&p30, v + 0x30, &m->pos);
    func_0038CF68(&p30, &p30, 1.0f);
    angle = func_0038D160(*(f32 *)(v + 0x30) - (*D_001A71A0)->pos.x, *(f32 *)(v + 0x34) - (*D_001A71A0)->pos.y);
    if (angle < 1.57079637f) {
        angle = func_003824E0(0.0f, -0.785398185f);
    } else {
        angle = func_003824E0(0.0f, 0.785398185f);
    }
    *(vu0_q *)(v + 0x40) = *(vu0_q *)&m->pos;
    *(f32 *)(v + 0x48) -= D_L05_001DEAE4;
    vec_sub_ba(v + 0x40, v + 0x40, &m->pos);
    func_0038D890(v + 0x40, v + 0x40, &p30, angle);
    vec_add_ab(v + 0x40, &m->pos, v + 0x40);
    switch (m->state) {
    case 0:
        if (((M_003BD5E0 *)m->parent)->type != 0x1BF6) {
            if (func_003D3CB0(&m->pos, v + 0x30, 2, m->parent, 0)) {
                *(vu0_q *)(v + 0x30) = *(vu0_q *)D_L05_001EA6E0;
            }
            if (func_003D3CB0(&m->pos, v + 0x30, 0, m->parent, 0)) {
                f32 scale;
                u8 *other;
                *(vu0_q *)&hit = *(vu0_q *)D_L05_001EA6E0;
                vec_sub_ba(&dir, v + 0x30, &m->pos);
                func_0038CF68(&dir, &dir, 1.0f);
                func_0038CE20(&dir, &dir, 1.0f);
                dir.w = 5627.9248046875f;
                scale = 1.0f;
                other = func_00382348(m->parent);
                if (other) {
                    scale = (f32)other[0x14];
                }
                func_L01_00446760(&damage, m, 1, &dir, scale);
                damage.a18 = 1;
                damage.a19 = 1;
                damage.type = m->type;
                func_003D4D00(&hit, 0, m, &damage, 0.25f);
                other = *(u8 **)((u8 *)D_L05_001EA6E0 - 8);
                if (!other) {
                    func_L05_003BDFA8(&hit, 15, m);
                } else if (*(s32 *)(other + 0x98)) {
                    func_L05_003BDFA8(&hit, 10, m);
                }
                m->state = 1;
                *(s32 *)(v + 0x10) = (D_L05_001DEAE0 * 5 + 2) / 6;
                if (((M_003BD5E0 *)m->parent)->type == 0x1BF6) {
                    *(s32 *)(v + 0x10) <<= 3;
                }
            } else {
                m->state = 1;
                *(s32 *)(v + 0x10) = (D_L05_001DEAE0 * 5 + 2) / 6;
                if (((M_003BD5E0 *)m->parent)->type == 0x1BF6) {
                    *(s32 *)(v + 0x10) <<= 3;
                }
            }
        } else {
            m->state = 1;
            *(s32 *)(v + 0x10) = (D_L05_001DEAE0 * 5 + 2) / 6;
            if (((M_003BD5E0 *)m->parent)->type == 0x1BF6) {
                *(s32 *)(v + 0x10) <<= 3;
            }
        }
        break;
    case 1:
        if (func_0038CAD0(v + 0x10)) {
            *(s32 *)(v + 0xC) = 0;
            D_L05_002A64C0[*(s32 *)(v + 0x60)].h[0] = 0;
            func_003C2880(m);
            return;
        }
        tbl = D_L05_00220758;
        for (i = 9; i >= 0; i--) {
            f32 size = func_003824E0(0.15f, 0.25f) * 210000.0f;
            s32 col = 0x1010FF;
            part = func_L01_0046FB40(&m->pos, D_L05_001D66B0, 2, col, 2, 127, 16, size, size, 0.0f, 0);
            if (part) {
                part[2] = **(u8 **)(tbl + 0x64);
            }
            part = func_L01_0046FB40(&m->pos, D_L05_001D66B0, 2, col, -1, 127, 16, size, size, 0.0f, 0);
            if (part) {
                part[2] = **(u8 **)(tbl + 0x1A0);
            }
        }
        if (*(s32 *)(v + 0x10) >= 6) {
            func_L05_003BD078((u8 *)m);
        }
        func_L01_00404A10(func_L05_003BDB68, m);
        break;
    }
    if (m->pos.x < 2.0f || m->pos.x > 1021.0f || m->pos.y < 2.0f || m->pos.y > 1021.0f || m->pos.z < 2.0f || m->pos.z > 1021.0f) {
        D_L05_002A64C0[*(s32 *)(v + 0x60)].h[0] = 0;
        func_003C2880(m);
    }
}
/* localdecomp:end func_L05_003BD5E0 */

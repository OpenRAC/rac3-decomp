/* near miss: 4 raw diff of 553 words in the file's flags (check with `python tools/check.py <this file with the INCLUDE_ASM lines stripped> func_L01_0032B408
 * --no-context`; the block replaces the INCLUDE_ASM of func_L01_0032B408 at the top of src/levels/shared/L01_0032B408.c, its externs match the file's definitions).
 * 10-state `switch (m[0x20])` with a real 10-entry jump table: if it ever matches, run jtcheck at EVERY place (the table is read from the ELF).
 * Left, one row site (the store of vF0 into D_L01_002784E0[idx] at the end of the hit block): retail `addiu $a0,$zero,12; lui $v1,0x28; mult $v0,$v0,$a0;
 * addiu $v1,$v1,-0x7b20`, ours `addiu $v1,$zero,12; lui $a0,0x28; mult $v0,$v0,$v1; addiu $v1,$a0,-0x7b20` (same instructions, same order: the 12 and the
 * `lui` half swap $a0 / $v1). The other row site (post-switch read) matches.
 * Levers found (details in sonnet-b33-nm4b-findings.md): (1) a global read with a split `lui` + `lw %lo($other)` is an ARRAY (`D_001A71A4[0] == 0x74`): 20 -> 16;
 * (2) a SHARED table-base pointer assigned at each row site (`tab = D_L01_002784E0; d = tab + idx;`): a pseudo set at two places has no alias base value, so
 * the stores through `d` stay in front of the next frame load (retail's interleave) and the index / product / sum quantity outranks the hi / lo quantity in
 * local-alloc ($v0, $v1 as retail): 16 -> 4. A pointer used at one site only (or `d` alone) gives either the hoisted loads or the swapped $v0 / $v1.
 * Why 4 are left: the 12 and the `lui` half are equal-priority quantities (2 refs, 3 insns) and the tie goes to the lower qty number = born first in the post-sched1
 * stream; sched1 puts `li 12` (prio 8, it feeds the mult) before `lui` (prio 5). Tried without change: a local for the index before or after `tab`, `off = idx * 12`,
 * `d = tab; d += idx`, `&tab[idx]`, a u32 / u8 * `tab`, `tab = ... ` moved before the previous calls (13 / 21 diff), pointer locals in the earlier call arguments, per-site
 * `da` / `db` (4 too), a shared `k = 12` local (the `lui` matches but k and tab land in $a1 / $a2: 9).
 * h9 (round 20, ~7 compiles + 70 toy forms, sonnet-b33-h9-tools/toy_0032B408 reproduces the swap): in the post-sched1 stream of site A the order is [lw idx, li 12, lwc1, lui hi, mult, lo_sum]: hi and 12
 * overlap (the lo_sum comes after the mult), both have refs 2 / length 8 = equal local-alloc priority, and the quantity born first in the stream (the 12) takes the first free register. Retail needs hi
 * first (and hi / base tied: `addiu $v1,$v1,lo`). The matching site B has the stream [li, hi, lo_sum, mult]. A user local for the index gives the other swap (12 in $v0, hi/base in $v1, idx in $a0);
 * no `tab` variable gives hi/base first in $v0. None of the 70 toy forms (index local before/after tab, &tab[idx], cast multiply, vF0 loaded first, struct copy, z-first, second `tab =`) gives
 * {idx, product, sum} $v0 / {hi, base} $v1 / 12 $a0. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0032B408 */
typedef struct {
    vu0_v4 oldp; vu0_v4 pos; vu0_v4 vel; void *self; void *p34; s32 w38; f32 f3C; f32 f40; f32 f44;
    s32 w48; s32 w4C; s32 w50; s32 w54; s32 w58; f32 f5C;
} Desc_0032B408;
typedef struct { s32 w0; s32 w4; } W2_0032B408;
extern s32 D_L01_001DCE4C;
__asm__(".extern D_L01_001DCE4C, 4");
extern f32 D_L01_001DCE30;
__asm__(".extern D_L01_001DCE30, 4");
extern f32 D_L01_001DCE38;
__asm__(".extern D_L01_001DCE38, 4");
extern s32 D_L01_001E1090;
__asm__(".extern D_L01_001E1090, 4");
extern s32 D_L01_001E1098;
extern u8 *D_L01_001DAFEC;
extern s32 D_001A71A4[];
extern vu0_v4 D_001A4C60;
typedef struct { u8 pad[0x100]; s32 w100[0x40]; } W100_0032B408;
extern W100_0032B408 D_L01_00276E60_0032B408;
extern u8 *D_L01_00278350[];
typedef struct { f32 x, y, z; } V3_0032B408;
extern V3_0032B408 D_L01_002784E0[];
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_004C8688(s32, void *, s32);
extern void func_L01_004C7D40_0032B408(void *, f32, void *);
extern s32 func_L01_004C7E70(void *, s32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_L01_004CB018(s32);
extern void func_L01_004C67A0(void *, s32, u32, f32, f32, f32, f32);
extern void *func_L01_003016B0(void *, s32, f32, f32);
extern s32 func_L01_004CADE8(void *, void *);
extern void func_L01_0032CA80(void);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00444F38(void *, s32, s32, s32, s32);
extern void func_L01_004C8668(s32);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_L01_004395E0(void *);
extern void func_L01_0032BF70(u8 *);
extern void func_L01_0032C220(u8 *);
extern void func_L01_0032C390(u8 *);
extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
extern void func_L01_0032BCB0(u8 *);
extern void func_L01_0032BDD8(u8 *);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern void func_L01_004C81A8(s32);
extern s32 func_L01_004C80F8(void *, s32);
extern void func_L01_004CAE60(void *, s32);
extern void func_003C2880(void *);
extern void func_L01_0032C5D0(void *);
extern s32 func_L01_0040E050(void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_0032CB38(void *);
extern void func_L01_0032BE90(u8 *);
extern void func_L01_0032BEF0(u8 *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_0032E2B0(u8 *);
extern void func_L01_0032CF48();
extern void func_L01_00404A10(void *, void *);
extern void func_0038D000(void *, void *, void *);

void func_L01_0032B408(u8 *m) {
    vu0_v4 old;
    W2_0032B408 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60[3];
    Desc_0032B408 desc;
    vu0_v4 vF0;
    vu0_v4 v100[4];
    u8 *st;
    s32 r;
    s32 n;
    f32 f20;
    u8 *hit;
    s32 id;
    f32 half;
    s32 one;
    s32 two;
    u8 *pos;
    s32 r2;
    V3_0032B408 *d;
    V3_0032B408 *tab;

    st = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        m[0x20] = 1;
        n = D_L01_001DCE4C;
        *(s32 *)(st + 0x6C) = n;
        D_L01_001DCE4C = (n + 1) % 100;
        *(s32 *)(m + 0x98) = 0;
    case 1:
        pos = m + 0x10;
        func_L01_004C7D98(pos, &v20);
        half = 0.5f;
        func_0038CF68(&v30, m + 0xE0, 1.0f);
        one = 1;
        func_0038CE90(&v50, &v30, &v20);
        two = 2;
        f20 = func_0038CE68(&v30, &v20) * half;
        func_0038CE20(&v40, &v50, func_0038D0B0(f20));
        v40.w = func_0038D098(f20);
        func_0038D810(&v40, v60);
        func_0038D5F0(m + 0xC0, v60, m + 0xC0);
        old = *(vu0_v4 *)(m + 0x10);
        vec_add_ab(m + 0x10, m + 0x10, st);
        func_L01_004C8688(*(s8 *)(st + 0x4F), st, 0);
        func_L01_004C7D40_0032B408(pos, D_L01_001DCE30 * 0.00040000002f, st);
        v10.w0 = 0;
        v10.w4 = 0xC5A;
        desc.oldp = old;
        desc.pos = *(vu0_v4 *)(m + 0x10);
        desc.vel = *(vu0_v4 *)st;
        desc.self = m;
        desc.p34 = &v10;
        desc.w38 = two;
        desc.f3C = 0.1f;
        desc.f40 = D_L01_001DCE38;
        desc.f44 = 0.5555556f;
        desc.w48 = 0;
        desc.w4C = 0;
        desc.w58 = one;
        desc.w50 = one;
        desc.f5C = 0.074f;
        r = func_L01_004C7E70(&desc, -1);
        *(vu0_v4 *)(m + 0x10) = desc.pos;
        *(vu0_v4 *)st = desc.vel;
        if (func_L01_004CB2D8()) {
            func_L01_004CAB30(pos, pos);
        }
        if (r == two) {
            if (desc.self != 0) {
                id = *(s16 *)((u8 *)desc.self + 0xAA);
                if (id == 0xCB || id == 0x1366 || id == 0x1367) {
                    goto bounce;
                }
            }
            qzero(st);
            hit = (u8 *)desc.self;
            *(u8 **)(st + 0x70) = hit;
            if (hit != 0) {
                *(f32 *)(st + 0x74) = *(f32 *)(hit + 0x10);
                *(f32 *)(st + 0x78) = *(f32 *)(hit + 0x14);
                *(f32 *)(st + 0x7C) = *(f32 *)(hit + 0x18);
            }
            r2 = func_L01_004CB018(desc.w54);
            if (r2 == r) {
                *(f32 *)(st + 8) = -0.030000001f;
                m[0x20] = 7;
                if (desc.w54 == 0) {
                    u8 *q;
                    func_L01_004C67A0((void *)D_L01_001E1090, D_L01_001E1098, 1, *(f32 *)(m + 0x10), *(f32 *)(m + 0x14), half, -0.35f);
                    q = func_L01_003016B0(pos, 3, 2.0f, 1.025f);
                    if (q != 0) {
                        q[0x23] = 0x70;
                    }
                }
            } else if (r2 == one) {
                m[0x20] = 8;
            } else {
                st[0x4E] = func_L01_004CADE8(&D_L01_00276E60_0032B408, m);
                func_L01_0032CA80();
                if (D_L01_00276E60_0032B408.w100[(s8)st[0x4E]] != 0) {
                    m[0x20] = r;
                    func_003A52A0(1, 0, m);
                    func_L01_00444F38(m, 1, 0, 0, 0);
                } else {
                    m[0x20] = 6;
                }
            }
            func_L01_004C8668(*(s8 *)(st + 0x4F));
            D_L01_00278350[*(s32 *)(st + 0x6C)] = D_L01_001DAFEC;
            if (D_L01_001DAFEC != 0) {
                vec_sub_ab(&vF0, m + 0x10, D_L01_001DAFEC + 0x10);
                func_0038D5B0(v100, D_L01_00278350[*(s32 *)(st + 0x6C)] + 0xC0);
                func_0038D028(&vF0, &vF0, v100);
                tab = D_L01_002784E0;
                d = tab + *(s32 *)(st + 0x6C);
                d->x = vF0.x;
                d->y = vF0.y;
                d->z = vF0.z;
            }
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        }
        break;
    bounce:
        func_0038CE20(st, st, 1.1f);
        break;
    case 2:
        if (6.0f <= func_L01_004395E0(m)) {
            func_L01_00444F38(m, 2, 0, 0, 0);
            m[0x20] = 3;
        }
        break;
    case 3:
        func_L01_0032BF70(m);
        goto tail34;
    case 4:
        func_L01_0032C220(m);
        func_L01_0032C390(m);
    tail34:
        hit = *(u8 **)(st + 0x70);
        if (hit != 0) {
            if (hit[0x20] == 0xFE) {
                goto reset;
            }
            if (hit[0x20] == 0xFD) {
            reset:
                *(s32 *)(m + 0x98) = 0;
                st[0x4F] = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
                m[0x20] = 1;
                *(s32 *)(st + 0x70) = 0;
            }
        }
        break;
    case 5:
        if (func_L01_004395E0(m) <= 1.21f) {
            func_L01_00444F38(m, 0, 0, 0, 0);
            m[0x20] = 6;
            *(f32 *)(m + 0x48) = 1.0f;
        }
        break;
    case 6:
        if (D_L01_00276E60_0032B408.w100[(s8)st[0x4E]] != 0) {
            m[0x20] = 2;
            func_003A52A0(1, 0, m);
            func_L01_00444F38(m, 1, 0, 0, 0);
            *(s32 *)(st + 0x48) = func_L01_004C80F8(m, 0);
        }
        break;
    case 7:
        func_L01_0032BCB0(m);
        func_L01_0032BDD8(m);
        break;
    case 8:
        func_003A52A0(3, 0, m);
        func_L01_0044BB30(m, m + 0x10, -1, 0.5f, 13.0f);
        m[0x20] = 9;
        *(u16 *)(m + 0x34) |= 0x41;
        break;
    case 9:
        if (*(s16 *)(st + 0x66) == 0) {
            if (*(s32 *)(st + 0x48) != -1) {
                func_L01_004C81A8(*(s32 *)(st + 0x48));
            }
            if ((s8)st[0x4E] != -1) {
                func_L01_004CAE60(&D_L01_00276E60_0032B408, (s8)st[0x4E]);
            }
            func_003C2880(m);
            return;
        }
        break;
    }
    if (m[0x20] >= 2) {
        if (D_L01_00278350[*(s32 *)(st + 0x6C)] != 0) {
            tab = D_L01_002784E0;
            d = tab + *(s32 *)(st + 0x6C);
            v20.x = d->x;
            v20.y = d->y;
            v20.z = d->z;
            v20.w = 0.0f;
            func_0038D000(&v20, &v20, D_L01_00278350[*(s32 *)(st + 0x6C)] + 0xC0);
            vec_add_ab(m + 0x10, D_L01_00278350[*(s32 *)(st + 0x6C)] + 0x10, &v20);
        }
    }
    if ((u8)(m[0x20] - 3) < 2) {
        func_L01_0032C5D0(m);
    }
    func_L01_0040E050(st + 0x5C);
    if (func_0038CAD0(st + 0x40) != 0 || D_001A71A4[0] == 0x74) {
        if (m[0x20] != 9) {
            m[0x20] = 8;
        }
    }
    func_L01_0032CB38(m);
    if ((u8)(m[0x20] - 3) < 2) {
        func_L01_0032BE90(m);
        if (D_L01_00276E60_0032B408.w100[(s8)st[0x4E]] == 0) {
            func_L01_00444F38(m, 1, 9, 0, 0);
            *(f32 *)(m + 0x48) = -1.0f;
            m[0x20] = 5;
            func_L01_004C81A8(*(s32 *)(st + 0x48));
            *(s32 *)(st + 0x48) = -1;
            *(s16 *)(st + 0x4C) = 1;
            *(s32 *)(st + 0x50) = 0;
            *(s32 *)(st + 0x44) = 0;
            *(s32 *)(st + 0x68) = 0;
            *(vu0_v4 *)(st + 0x30) = *(vu0_v4 *)(st + 0x10);
            *(vu0_v4 *)(st + 0x20) = *(vu0_v4 *)(st + 0x10);
        }
    }
    if (m[0x20] < 8) {
        if (*(s32 *)(st + 0x70) != 0) {
            func_L01_0032BEF0(m);
        }
    }
    if (900.0f < func_L01_0040E548(m + 0x10, &D_001A4C60)) {
        func_L01_0032E2B0(m);
    }
    func_L01_00404A10(func_L01_0032CF48, m);
}
/* localdecomp:end func_L01_0032B408 */

/* func_L01_0037F948 (Claude wave 14 r54, 2026-11-28). First draft kept here. */
/* PAL near miss (r54, wave 14): first draft of a fresh entry (no earlier draft), under the file's own line
 * (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as) with the existing divs row
 * 'func_L01_0037F948 0 2 2 2 2'. The beam update called by func_L01_0037EFC8: the end point (locked target via
 * func_00382348 or a yaw/pitch ray), the 7-try func_003D3CB0 hit loop collecting 0x1BC3/0x189B mobys, the 12-point
 * bending chain in D_L01_0028F5A0 with its 20-point rings (D_L01_0028F7E0) and the two ribbon edges (0028F660/0028F720),
 * the func_L01_00404A10 render callback, the level-tinted sparks (func_L01_0046B458) and arc (func_L01_0046E5A8), the
 * spawn and update of the three travellers (D_L01_001E1E40..E1E80, E1DE0, E1E10). Same length as retail (978 vs 974
 * instructions), same frame (0x370) and stack layout: block-local b/mat in the point loop and cols/d/e in the arc block
 * reuse one area (the extra blocks around the loop bodies are what lets cc1 free those slots), a separate counter
 * per loop, 'i = next' (i not a biv, no strength reduction, like retail), pointer arithmetic for [i - 1]/[at + 1],
 * vars->pos read through a plain pointer (keeps it behind the E1DD0 store), E1DD0/E1DD4/DDC33 as gp-typed
 * symbols with .extern 16 (retail's $at/macro forms), D_L01_001D66B0[8] (rematerialised per call).
 * Still differs (240 of 974 rows after alignment, 63 by mnemonic): register choice and sched order in many small
 * places (reload registers for the spilled vars, the spawn body's statement order, the start of the point loop),
 * and the update loop's b sits at 0x2B0 (retail reuses 0x270 and its hoisted address pseudo). */
#include "common.h"

/* localdecomp:start func_L01_0037F948 */
#include "vu0.h"
#include "structs/weapon.h"
typedef int Q_0037F860 __attribute__((mode(TI)));
typedef struct {f32 x,y,z,w;} __attribute__((aligned(16))) V_0037F860;
typedef struct {
    Q_0037F860 pos;     /* 0x00 */
    u8 *target;         /* 0x10 */
    u8 pad_14[0x48 - 0x14];
    f32 yaw;            /* 0x48 */
    f32 pitch;          /* 0x4C */
} Vars_0037F948;
typedef struct {
    u8 pad_0[0x18];
    u8 *moby;           /* 0x18 */
    u8 pad_1C[4];
    Q_0037F860 pos;     /* 0x20 */
} Hit_0037F948;
typedef struct {
    u8 pad_0[0x25C0];
    u8 *moby;           /* 0x25C0 */
} Hero_0037F948;
extern f32 D_L01_001DDB84;
extern f32 D_L01_001E1DD0_0037F948;
__asm__(".extern D_L01_001E1DD0_0037F948, 16");
extern Q_0037F860 D_L01_0028F5A0[];
extern s32 D_L01_001E1E84;
extern u8 D_L01_001E1E80[3] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1E80, 16");
extern Q_0037F860 D_L01_001E1E10[3] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1E10, 48");
__asm__(".extern D_L01_001DDB84, 4");
__asm__(".extern D_L01_001E1E84, 16");
extern f32 D_L01_001E1E70[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1E70, 12");
extern f32 D_L01_001E1E50[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1E50, 12");
extern Q_0037F860 D_L01_001E1DE0[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1DE0, 48");
extern s32 D_L01_001E1E40[];
__asm__(".extern D_L01_001E1E40, 12");
extern f32 D_L01_001E1E60[];
__asm__(".extern D_L01_001E1E60, 12");
extern f32 D_L01_001E1DD4_0037F948;
__asm__(".extern D_L01_001E1DD4_0037F948, 16");
extern s8 D_L01_001DDC33;
__asm__(".extern D_L01_001DDC33, 16");
extern Q_0037F860 D_L01_0028F660[];
extern Q_0037F860 D_L01_0028F720[];
extern Q_0037F860 D_L01_0028F7E0[][20];
extern Hit_0037F948 D_L01_001EAA00_0037F948;
extern Hero_0037F948 D_001A4BE0_0037F948;
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_001A4EC0[];
extern u8 *D_L01_00221098[];
extern u8 D_L01_001D66B0[8];
extern f32 D_L01_001DDBC0, D_L01_001DDBC8, D_L01_001DDBCC, D_L01_001DDBD4, D_L01_001DDBD8, D_L01_001DDBDC;
extern f32 D_L01_001DDBFC, D_L01_001DDC00, D_L01_001DDC04, D_L01_001DDC0C, D_L01_001DDC10, D_L01_001DDC18;
extern f32 D_L01_001DDC28, D_L01_001DDC2C, D_L01_001DDC38;
extern s32 D_L01_001DDBC4, D_L01_001DDC14, D_L01_001DDC1C, D_L01_001DDC20;
__asm__(".extern D_L01_001DDBC0, 4");
__asm__(".extern D_L01_001DDBC4, 4");
__asm__(".extern D_L01_001DDBC8, 4");
__asm__(".extern D_L01_001DDBCC, 4");
__asm__(".extern D_L01_001DDBD4, 4");
__asm__(".extern D_L01_001DDBD8, 4");
__asm__(".extern D_L01_001DDBDC, 4");
__asm__(".extern D_L01_001DDBFC, 4");
__asm__(".extern D_L01_001DDC00, 4");
__asm__(".extern D_L01_001DDC04, 4");
__asm__(".extern D_L01_001DDC0C, 4");
__asm__(".extern D_L01_001DDC10, 4");
__asm__(".extern D_L01_001DDC14, 4");
__asm__(".extern D_L01_001DDC18, 4");
__asm__(".extern D_L01_001DDC1C, 4");
__asm__(".extern D_L01_001DDC20, 4");
__asm__(".extern D_L01_001DDC28, 4");
__asm__(".extern D_L01_001DDC2C, 4");
__asm__(".extern D_L01_001DDC38, 4");

void func_L01_0037F948(void *obj) {
    extern void func_L01_0037F860(u8 *);
    extern void func_L01_00380880(u8 *);
    extern f32 func_L01_0044AE78(f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 *func_00382348(s32);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_L01_00404A10(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_0046B458(void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);
    extern u8 *func_L01_0046E5A8(void *, s32, s32, s32, s32, void *, u8 *, f32, f32);
    extern s32 func_0038CAD0(void *);
    V_0037F860 bend;
    V_0037F860 seg;
    V_0037F860 up;
    V_0037F860 end;
    V_0037F860 tmp;
    u8 *hits[128];
    V_0037F860 dir;
    V_0037F860 a;
    u8 *self = obj;
    Vars_0037F948 *vars = *(Vars_0037F948 **)(self + 0x68);
    f32 *rec;
    f32 dist;
    f32 size;
    s32 n;
    s32 tries;
    s32 i;
    s32 j;
    s32 h;
    s32 k;
    s32 q;
    s32 sgn;
    s32 next;
    s32 c0;
    s32 c1;
    u8 *p;

    up.x = 0.0f;
    up.w = 1.0f;
    func_L01_0037F860(self);
    D_L01_001E1DD4_0037F948 = func_L01_0044AE78(D_L01_001E1DD4_0037F948 + D_L01_001DDBC8);
    func_0038CF68(&bend, self + 0xD0, -D_L01_001E1DD0_0037F948);
    if (vars->target != 0 && (rec = func_00382348((s32)vars->target)) != 0) {
        func_0038CE20(&tmp, vars->target + 0xE0, rec[4]);
        vec_add_ba(&end, vars->target + 0x10, &tmp);
    } else {
        func_00382760(&end, D_L01_001DDB84, vars->yaw, vars->pitch);
        vec_add_ab(&end, &end, vars);
    }
    n = 0;
    dist = D_L01_001DDB84;
    tries = 0;
    if (vars->target == 0) {
        *(Q_0037F860 *)&tmp = *(Q_0037F860 *)vars;
        while (func_003D3CB0(&tmp, &end, 20, D_001A4BE0_0037F948.moby, 0) != 0 && ++tries < 7) {
            u8 *m = D_L01_001EAA00_0037F948.moby;
            V_0037F860 b;
            f32 d;

            if (m != 0 && (*(s16 *)(m + 0xAA) == 0x1BC3 || *(s16 *)(m + 0xAA) == 0x189B)) {
                hits[n++] = m;
                *(s32 *)(m + 0x98) = 0;
                if (n < 128) {
                    *(Q_0037F860 *)&tmp = D_L01_001EAA00_0037F948.pos;
                    continue;
                }
            }
            vec_sub_ba(&dir, vars, &D_L01_001EAA00_0037F948.pos);
            d = func_0038CE68(D_001A4BE0_0037F948.moby + 0xE0, &dir);
            func_0038CE20(&a, D_001A4BE0_0037F948.moby + 0xE0, d);
            vec_sub_ab(&b, &dir, &a);
            dist = func_0038CEA8(&b);
            break;
        }
        {
        for (h = 0; h < n; h++) {
            *(s32 *)(hits[h] + 0x98) = *(s32 *)(*(u8 **)(hits[h] + 0x24) + 0x10);
        }
        }
    } else {
        f32 d;

        vec_sub_ba(&tmp, vars, vars->target + 0x10);
        d = func_0038CE68(D_001A4BE0_0037F948.moby + 0xE0, &tmp);
        func_0038CE20(&dir, D_001A4BE0_0037F948.moby + 0xE0, d);
        vec_sub_ab(&a, &tmp, &dir);
        dist = func_0038CEA8(&a);
    }
    D_L01_001E1DD0_0037F948 = dist * D_L01_001DDBC0;
    D_L01_0028F5A0[0] = *(Q_0037F860 *)vars;
    D_L01_0028F660[0] = *(Q_0037F860 *)vars;
    D_L01_0028F720[0] = *(Q_0037F860 *)vars;
    for (i = 1; i < 12; i = next) {
        {
        V_0037F860 b;
        V_0037F860 mat[4];
        f32 t;
        f32 s;
        f32 len;
        f32 r;
        f32 ang;

        func_L01_004CAB30(&D_L01_0028F5A0[i], &D_L01_0028F5A0[i]);
        t = (f32)i * D_L01_001DDBC0;
        s = 0.9f + (0.4f - 0.9f) * t;
        vec_sub_ab(&seg, &D_L01_0028F5A0[i], D_L01_0028F5A0 + i - 1);
        if (i > D_L01_001DDBC4 && vars->target != 0) {
            vec_sub_ab(&tmp, vars->target + 0x10, &D_L01_0028F5A0[i]);
            func_0038CF68(&tmp, &tmp, D_L01_001E1DD0_0037F948);
            func_0038CDF8(&bend, &bend, &tmp, 0.2f);
        }
        func_0038CDF8(&tmp, &seg, &bend, s);
        len = func_0038CEA8(&tmp);
        if (len == 0.0f) {
            D_L01_0028F5A0[i] = *(D_L01_0028F5A0 + i - 1);
        } else {
            func_0038CE20(&tmp, &tmp, D_L01_001E1DD0_0037F948 / len);
            vec_add_ba(&D_L01_0028F5A0[i], D_L01_0028F5A0 + i - 1, &tmp);
        }
        vec_sub_ab(&dir, &D_L01_0028F5A0[i], D_L01_0028F5A0 + i - 1);
        func_0038CE90(&a, &dir, D_001A4EC0);
        func_0038CF68(&a, &a, D_L01_001DDBD8 + (D_L01_001DDBDC - D_L01_001DDBD8) * t);
        next = i + 1;
        for (j = 0; j < 20; j++) {
            func_0038D890(&b, &a, &dir, (f32)j * D_L01_001DDBD4);
            vec_add_ab(&D_L01_0028F7E0[i][j], &b, &D_L01_0028F5A0[i]);
        }
        *(Q_0037F860 *)&mat[3] = D_L01_0028F5A0[i];
        func_0038CF68(&mat[0], &dir, 1.0f);
        func_0038CF68(&mat[1], &a, 1.0f);
        func_0038CE90(&mat[2], &mat[1], &mat[0]);
        r = D_L01_001DDBFC + (D_L01_001DDC00 - D_L01_001DDBFC) * t;
        ang = func_L01_0044AE78(D_L01_001E1DD4_0037F948 + D_L01_001DDBCC * (f32)i);
        up.y = r * func_0038D0B0(ang);
        up.z = r * func_0038D098(ang);
        func_0038D028(&D_L01_0028F660[i], &up, mat);
        up.z = -up.z;
        func_0038D028(&D_L01_0028F720[i], &up, mat);
        }
    }
    func_L01_00404A10(func_L01_00380880, self);
    size = func_003824E0(0.1f, 1.7f);
    c0 = 0x7F7F1010;
    c1 = 0x7FFF4F10;
    sgn = func_00382468(2);
    if (sgn == 0) {
        sgn--;
    }
    if (D_L01_002C5600[D_001425C0[0x8F]].level >= 4) {
        c0 = 0x7F10107F;
        c1 = 0x7F104FFF;
    }
    if (func_00382468(2) == 0) {
        *(Q_0037F860 *)&tmp = D_L01_0028F660[11];
        p = func_L01_0046B458(&tmp, 25, c0, 0, sgn, D_L01_001D66B0, 1, size * 0.1f, size, 0.003f);
        if (p != 0) {
            p[2] = D_L01_00221098[97][7];
        }
        sgn = -sgn;
        p = func_L01_0046B458(&tmp, 25, 0x7F7F7F7F, 1, sgn, D_L01_001D66B0, 1, size * 0.07f, size * 0.7f, 0.003f);
        if (p != 0) {
            p[2] = D_L01_00221098[97][7];
        }
    }
    if (func_00382468(2) == 0) {
        *(Q_0037F860 *)&tmp = D_L01_0028F720[11];
        p = func_L01_0046B458(&tmp, 25, c1, 0, sgn, D_L01_001D66B0, 1, size * 0.1f, size, 0.003f);
        if (p != 0) {
            p[2] = D_L01_00221098[97][7];
        }
        sgn = -sgn;
        p = func_L01_0046B458(&tmp, 25, 0x7F7F7F7F, 1, sgn, D_L01_001D66B0, 1, size * 0.07f, size * 0.7f, 0.003f);
        if (p != 0) {
            p[2] = D_L01_00221098[97][7];
        }
    }
    vec_sub_ab(&dir, &D_L01_0028F5A0[1], &D_L01_0028F5A0[0]);
    func_0038CF68(&dir, &dir, D_L01_001DDC04 * 1.2f);
    if (func_00382468(2) == 0) {
        s32 cols[5];
        V_0037F860 d;
        V_0037F860 e;
        s32 k0;
        s32 k1;
        s32 k2;
        s32 k3;
        s32 k4;
        s32 sel;
        s32 cnt;
        f32 r1;

        func_0038CF68(&a, self + 0xD0, D_L01_001DDC10);
        vec_add_ab(&tmp, &D_L01_0028F5A0[0], &a);
        k0 = 0x7FFF7F30;
        k1 = 0x7FFF6400;
        k2 = 0x7FFF2020;
        k3 = 0x7FFF7F00;
        k4 = 0x7FFF2020;
        if (D_L01_002C5600[D_001425C0[0x8F]].level >= 4) {
            k0 = 0x7F307FFF;
            k1 = 0x7F0064FF;
            k2 = 0x7F2020FF;
            k3 = 0x7F4080FF;
            k4 = 0x7F204080;
        }
        cols[0] = k0;
        cols[1] = k1;
        cols[2] = k2;
        cols[3] = k3;
        cols[4] = k4;
        sel = cols[func_00382468(5)];
        r1 = func_L01_00443A18(0.0f, D_L01_001DDC0C);
        func_0038D890(&d, &dir, D_001A4EC0, func_L01_00443A18(0.0f, D_L01_001DDC0C));
        func_0038CE90(&e, &dir, D_001A4EC0);
        func_0038D890(&d, &d, &e, r1);
        cnt = (s32)(dist * 1.2f / (D_L01_001DDC04 * 1.2f));
        if (vars->target != 0) {
            cnt *= 3;
        }
        p = func_L01_0046E5A8(&tmp, cnt, sel, 0, sgn, &d, vars->target, size * 0.1f, size);
        if (p != 0) {
            p[2] = D_L01_00221098[97][6];
        }
        p = func_L01_0046E5A8(&tmp, cnt, 0x7F7F7F7F, 1, -sgn, &d, vars->target, size * 0.07f, size * 0.7f);
        if (p != 0) {
            p[2] = D_L01_00221098[97][6];
        }
    }
    if (func_0038CAD0(&D_L01_001E1E84) != 0) {
        D_L01_001E1E84 = (D_L01_001DDC14 * 5 + 2) / 6;
        for (k = 0; k < 3; k++) {
            if (D_L01_001E1E80[k] == 0) {
                D_L01_001E1E70[k] = D_L01_001DDC2C;
                D_L01_001E1E80[k] = 1;
                D_L01_001E1E50[k] = (f32)D_L01_001DDC33;
                D_L01_001E1E60[k] = 0.0f;
                D_L01_001E1E40[k] = (D_L01_001DDC1C * 5 + 2) / 6;
                D_L01_001E1DE0[k] = *(Q_0037F860 *)vars;
                vec_sub_ba(&a, &D_L01_0028F5A0[1], &D_L01_0028F5A0[0]);
                func_0038CF68(&D_L01_001E1E10[k], &a, 1.0f);
                break;
            }
        }
    }
    for (q = 0; q < 3; q++) {
        if (D_L01_001E1E80[q] != 0) {
            if (func_0038CAD0(&D_L01_001E1E40[q]) != 0) {
                D_L01_001E1E80[q] = 0;
            } else {
                V_0037F860 b;
                f32 step;
                f32 frac;
                f32 rem;
                f32 len;
                s32 at;

                if (D_L01_001E1E40[q] < D_L01_001DDC20) {
                    D_L01_001E1E50[q] -= D_L01_001DDC38;
                }
                step = D_L01_001DDC18 * 0.020000001f;
                D_L01_001E1E60[q] += step;
                frac = D_L01_001E1E60[q] / D_L01_001DDB84;
                if (frac > 1.0f) {
                    frac = 1.0f;
                }
                D_L01_001E1E70[q] = D_L01_001DDC2C + (D_L01_001DDC28 - D_L01_001DDC2C) * frac;
                if (D_L01_001E1E60[q] >= D_L01_001DDB84) {
                    func_0038CE20(&a, &D_L01_001E1E10[q], step);
                    vec_add_ab(&D_L01_001E1DE0[q], &D_L01_001E1DE0[q], &a);
                } else {
                    at = (s32)(D_L01_001E1E60[q] / D_L01_001E1DD0_0037F948);
                    rem = D_L01_001E1E60[q] - (f32)at * D_L01_001E1DD0_0037F948;
                    D_L01_001E1DE0[q] = D_L01_0028F5A0[at];
                    if (at == 11) {
                        vec_sub_ba(&a, &D_L01_0028F5A0[11], &D_L01_0028F5A0[10]);
                    } else {
                        vec_sub_ba(&a, D_L01_0028F5A0 + at + 1, &D_L01_0028F5A0[at]);
                    }
                    len = func_0038CEA8(&a);
                    if (len != 0.0f) {
                        len = 1.0f / len;
                        func_0038CE20(&b, &a, rem * len);
                        vec_add_ba(&D_L01_001E1DE0[q], &D_L01_001E1DE0[q], &b);
                        func_0038CF68(&b, &a, len);
                        func_0038CDF8(&D_L01_001E1E10[q], &D_L01_001E1E10[q], &b, 0.1f);
                        func_0038CF68(&D_L01_001E1E10[q], &D_L01_001E1E10[q], 1.0f);
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L01_0037F948 */

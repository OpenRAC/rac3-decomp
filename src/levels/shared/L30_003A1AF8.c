#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;

INCLUDE_ASM("asm/levels", func_L30_003A1AF8);

INCLUDE_ASM("asm/levels", func_L30_003A1D08);

/* localdecomp:start func_L30_003A20D0 */
#include "vu0.h"
/* log (needs --flags=-mvu0-use-vf0-vf2 --as ps2as):
 * 1. first draft from retail: 108 diff (loop counter shared with the computed start)
 * 2. separate start, i = start in each loop: 12 diff (temps' registers)
 * 3. start = x4C; if (x180 > D) start++: MATCH
 */
typedef struct {
    u8 pad[0x20];
    Vec4 x20;
    Vec4 x30;
    u8 pad40[0x4C - 0x40];
    s32 x4C;
    u8 pad50[0x80 - 0x50];
    f32 x80[32];
    f32 x100[32];
    s32 x180;
} V_003A20D0;
typedef struct {
    u8 pad[0x68];
    V_003A20D0 *x68;
} O_003A20D0;
extern s32 D_L30_001DE9F4;
__asm__(".extern D_L30_001DE9F4, 4");
extern s32 D_L30_001DE8EC;
__asm__(".extern D_L30_001DE8EC, 4");
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
void func_L30_003A20D0(void *a0, s32 *idx, f32 *dist, s32 all, s32 mode) {
    V_003A20D0 *v = ((O_003A20D0 *)a0)->x68;
    s32 i;
    s32 start;
    s32 end;

    *idx = -1;
    *dist = 9999.0f;
    if (all) {
        start = 0;
        end = 32;
    } else {
        start = v->x4C;
        if (v->x180 > D_L30_001DE9F4) {
            start++;
        }
        end = start + D_L30_001DE8EC;
        if (start >= 32) {
            start = 31;
        }
        if (end >= 32) {
            end = 31;
        }
    }
    if (mode == 0) {
        for (i = start; i <= end; i++) {
            f32 dx = v->x30.f[0] - v->x80[i];
            f32 dz = v->x30.f[2] - v->x100[i];
            f32 d = dx * dx + dz * dz;
            if (d < *dist) {
                *idx = i;
                *dist = d;
            }
        }
    } else {
        for (i = start; i <= end; i++) {
            Vec4 p __attribute__((aligned(16)));
            Vec4 n;
            Vec4 c;
            qzero(&p);
            p.f[0] = v->x80[i];
            p.f[2] = v->x100[i];
            vec_sub_ab(&p, &p, &v->x30);
            func_L02_003BA9F8(&p, &v->x20, &n, &c);
            if (func_0038CE68(&v->x20, &n) < 0.0f) {
                if (func_0038CEA8(&c) < *dist) {
                    *dist = func_0038CEA8(&c);
                    *idx = i;
                }
            }
        }
    }
    if (v->x4C == *idx) {
        v->x180++;
    } else {
        v->x180 = 0;
    }
}
/* localdecomp:end func_L30_003A20D0 */

/* localdecomp:start func_L30_003A22F0 */
#include "vu0.h"
/* log (needs --flags=-mvu0-use-vf0-vf2 --as ps2as):
 * 1. first draft from retail: 76 diff
 * 2. ternary inside the call's arguments (not if/else): 12 (clamp registers)
 * 3. clamp through a second variable, i = 31; if (j <= 31) i = j: 2
 * 4. v->x50 > v->x68 (load order): MATCH
 */
typedef struct {
    Vec4 x00;
    Vec4 x10;
    Vec4 x20;
    Vec4 x30;
    f32 x40;
    f32 x44;
    s32 x48;
    s32 x4C;
    s32 x50;
    u8 pad54[0x60 - 0x54];
    f32 x60;
    u8 pad64[0x68 - 0x64];
    s32 x68;
    f32 x6C;
    u8 pad70[0x78 - 0x70];
    f32 x78;
    u8 pad7C[0x80 - 0x7C];
    f32 x80[32];
    f32 x100[32];
} V_003A22F0;
typedef struct {
    u8 pad[0x48];
    f32 x48;
    u8 pad4C[0x68 - 0x4C];
    V_003A22F0 *x68;
    u8 pad6C[0xAA - 0x6C];
    s16 xAA;
    u8 padAC[0xF4 - 0xAC];
    f32 xF4;
    f32 xF8;
} O_003A22F0;
extern u8 D_001A4BE0[];
extern u8 D_L30_001DE910;
__asm__(".extern D_L30_001DE910, 1");
extern s32 D_L30_001DE93C;
__asm__(".extern D_L30_001DE93C, 4");
extern s32 D_L30_001DE8EC;
__asm__(".extern D_L30_001DE8EC, 4");
extern s32 D_L30_001DE998;
__asm__(".extern D_L30_001DE998, 4");
extern f32 D_L30_001DE99C;
__asm__(".extern D_L30_001DE99C, 4");
extern f32 D_L30_001DE904;
__asm__(".extern D_L30_001DE904, 4");
extern f32 D_L30_001DE930;
__asm__(".extern D_L30_001DE930, 4");
extern f32 D_L30_001DE958;
__asm__(".extern D_L30_001DE958, 4");
extern f32 D_L30_001DE95C;
__asm__(".extern D_L30_001DE95C, 4");
extern f32 D_L30_001DE964;
__asm__(".extern D_L30_001DE964, 4");
extern f32 D_L30_001DE8A4;
__asm__(".extern D_L30_001DE8A4, 4");
extern f32 D_L30_001DE8A8;
__asm__(".extern D_L30_001DE8A8, 4");
extern f32 D_L30_001DE8D8;
__asm__(".extern D_L30_001DE8D8, 4");
extern f32 D_L30_001DE990;
__asm__(".extern D_L30_001DE990, 4");
extern s32 D_L30_001DF2C0;
extern u8 D_L30_001D66B0[] __attribute__((section(".sdata")));
extern Vec4 D_L30_001E9020;
extern void func_L30_003A2DE8(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L30_003A20D0(void *, s32 *, f32 *, s32, s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L30_003A2C68(void *, s32);
extern f32 func_0038CEA8(void *);
void func_L30_003A22F0(O_003A22F0 *a0) {
    V_003A22F0 *v = a0->x68;
    s32 flag = 0;
    s32 idx;
    f32 dist;
    s32 i;
    s32 n;
    s32 j;
    f32 f;
    Vec4 t __attribute__((aligned(16)));

    if (D_L30_001DE910) {
        func_L30_003A2DE8(a0);
    }
    if (func_L01_004561B8(a0)) {
        qzero(&v->x20);
        v->x50 = 0;
        flag = 1;
        v->x20.f[2] = -1.0f;
        v->x44 = 0;
    }
    if ((D_L30_001DF2C0 & D_L30_001DE93C) == (((s32)a0 >> 8) & D_L30_001DE93C) || flag) {
        func_L30_003A20D0(a0, &idx, &dist, flag, 0);
        if (idx != -1) {
            v->x4C = idx;
        }
        j = v->x4C + D_L30_001DE8EC;
        i = 31;
        if (j <= 31) {
            i = j;
        }
        v->x10.f[0] = v->x80[i];
        v->x10.f[1] = *(f32 *)(D_001A4BE0 + 0x84);
        v->x10.f[2] = v->x100[i];
    }
    n = v->x50 + 1;
    v->x50 = n;
    f = func_0038DB48((f32)(n % D_L30_001DE998) / (f32)D_L30_001DE998 * 3.1415927f);
    vec_sub_ba(&t, &v->x10, &v->x30);
    f = func_0038D0B0(f);
    func_0038CF68(&t, &t, v->x60 * (D_L30_001DE99C * f + 1.0f));
    vec_add_ba(&v->x00, &v->x00, &t);
    func_L30_0034D1E8(a0, &v->x30, v, D_L30_001D66B0, v->x6C, 0.0f, v->x78, v->x78, D_L30_001DE930, 0.0f, 1, 0, 0, 1);
    func_L01_00448890(&a0->xF4, 0.0f, &v->x40, D_L30_001DE958, D_L30_001DE95C, D_L30_001DE964, 0);
    func_L01_00448890(&a0->xF8, v->x00.f[0] > 0.0f ? D_L30_001DE8A8 : D_L30_001DE8A4, &v->x44, D_L30_001DE958, D_L30_001DE95C, D_L30_001DE964, 0);
    if (a0->xAA != 0x1C1A && v->x50 > v->x68
        && (D_L30_001DF2C0 & D_L30_001DE93C) == (((s32)a0 >> 8) & D_L30_001DE93C)
        && func_L01_003FB640(&v->x30, 2, 0, D_L30_001DE904)) {
        v->x10.q = D_L30_001E9020.q;
        vec_sub_ab(&v->x20, &v->x10, &v->x30);
        func_0038CF68(&v->x20, &v->x20, 1.0f);
        func_L30_003A2C68(a0, 3);
        return;
    }
    a0->x48 = D_L30_001DE8D8 * func_0038CEA8(v) / D_L30_001DE990;
}
/* localdecomp:end func_L30_003A22F0 */

/* localdecomp:start func_L30_003A2608 */
#include "vu0.h"
/* log (needs --flags=-mvu0-use-vf0-vf2 --as ps2as):
 * 1. j-form by hand: 119 diff (vf roles, $gp globals via lui)
 * 2. ps2as + .extern hints, .sdata on the vector global: 94 diff
 * 3. vu0.h helpers (vec_sub_ba/vec_add_ab/vec_sub_ab): 40 diff (s0 = &v->x30 CSE'd)
 * 4. if/else for the select, scalar u8 flag: 16; .sdata on D_L30_001D66B0: 10
 * 5. func_L30_0034D1E8 floats-before-ints prototype: 3 (flag in v0, retail v1)
 * 6. func_L30_0034D1E8 returns s32 (retail: lw $v0, 0xBC($sp) at its exit): MATCH
 */
typedef struct {
    Vec4 x00;
    Vec4 x10;
    Vec4 x20;
    Vec4 x30;
    f32 x40;
    f32 x44;
    u8 pad48[0x60 - 0x48];
    f32 x60;
    u8 pad64[0x6C - 0x64];
    f32 x6C;
    u8 pad70[0x78 - 0x70];
    f32 x78;
} V_003A2608;
typedef struct {
    u8 pad[0x48];
    f32 x48;
    u8 pad4C[0x68 - 0x4C];
    V_003A2608 *x68;
    u8 pad6C[0xF4 - 0x6C];
    f32 xF4;
    f32 xF8;
} O_003A2608;
extern u8 D_L30_001DE910;
__asm__(".extern D_L30_001DE910, 1");
extern f32 D_L30_001DE930;
__asm__(".extern D_L30_001DE930, 4");
extern f32 D_L30_001DE958;
__asm__(".extern D_L30_001DE958, 4");
extern f32 D_L30_001DE95C;
__asm__(".extern D_L30_001DE95C, 4");
extern f32 D_L30_001DE964;
__asm__(".extern D_L30_001DE964, 4");
extern f32 D_L30_001DE8A4;
__asm__(".extern D_L30_001DE8A4, 4");
extern f32 D_L30_001DE8A8;
__asm__(".extern D_L30_001DE8A8, 4");
extern f32 D_L30_001DE8D8;
__asm__(".extern D_L30_001DE8D8, 4");
extern f32 D_L30_001DE990;
__asm__(".extern D_L30_001DE990, 4");
extern u8 D_L30_001D66B0[] __attribute__((section(".sdata")));
extern u8 D_L30_001E1220;
extern Vec4 D_L30_001E11F0 __attribute__((section(".sdata")));
extern void func_L30_003A2DE8(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern f32 func_0038CEA8(void *);
extern f32 func_L30_0034C9F8(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L30_003A2C68(void *, s32);
void func_L30_003A2608(O_003A2608 *a0) {
    V_003A2608 *v = a0->x68;
    Vec4 t;
    Vec4 u;
    Vec4 w;

    if (D_L30_001DE910) {
        func_L30_003A2DE8(a0);
    }
    vec_sub_ba(&t, &v->x10, &v->x30);
    func_0038CF68(&t, &t, v->x60);
    vec_add_ab(&v->x00, &v->x00, &t);
    func_L30_0034D1E8(a0, &v->x30, v, D_L30_001D66B0, v->x6C, 0.0f, v->x78, v->x78, D_L30_001DE930, 0.0f, 1, 0, 0, 1);
    if (D_L30_001E1220 != 0) {
        vec_sub_ba(&v->x20, &D_L30_001E11F0, &v->x30);
        func_0038CF68(&u, &v->x20, -v->x6C);
        vec_add_ab(&v->x30, &D_L30_001E11F0, &u);
        func_0038CF68(&v->x20, &v->x20, 1.0f);
        func_L30_003A2C68(a0, 5);
    }
    if (func_0038CEA8(v) > 0.0f) {
        f32 f = func_L30_0034C9F8(&v->x20);
        f = func_0038DAB8(f, 1.5707964f);
        func_L01_00448890(&a0->xF4, f, &v->x40, D_L30_001DE958, D_L30_001DE95C, D_L30_001DE964, 0);
        vec_sub_ab(&w, &v->x10, &v->x30);
        func_0038CE90(&u, v, &w);
        if (u.f[1] < 0.0f) {
            f = D_L30_001DE8A8;
        } else {
            f = D_L30_001DE8A4;
        }
        func_L01_00448890(&a0->xF8, f, &v->x44,
                          D_L30_001DE958, D_L30_001DE95C, D_L30_001DE964, 0);
    }
    a0->x48 = D_L30_001DE8D8 * func_0038CEA8(v) / D_L30_001DE990;
}
/* localdecomp:end func_L30_003A2608 */

/* localdecomp:start func_L30_003A2808 */
#include "vu0.h"
/* log (needs --flags=-mvu0-use-vf0-vf2 --as ps2as):
 * 1. first draft (hero as D_001A4BE0 + off, goto to the shared 2AF8 call): 182 diff
 * 2. hero pointer local for the whole function: 90 (anchor kept in one saved reg)
 * 3. tails duplicated per branch instead of the goto (cross-jumped back): branch shape right
 * 4. hero pointer per block: 8; func_003A52A0 as s32 (v0 busy): 4 (vf1/vf2 swapped)
 * 5. one h assigned per block, block-local pointer in the last block: MATCH
 */
typedef struct M_003A2808 {
    u8 pad[0x10];
    Vec4 x10;
    u8 x20;
    u8 pad21[0x68 - 0x21];
    struct V_003A2808 *x68;
    u8 pad6C[0xA8 - 0x6C];
    u8 xA8;
    u8 padA9;
    s16 xAA;
} M_003A2808;
typedef struct V_003A2808 {
    Vec4 x00;
    u8 pad10[0x30 - 0x10];
    Vec4 x30;
    u8 pad40[0x54 - 0x40];
    s32 x54;
    s32 x58;
    u8 pad5C[0x7C - 0x5C];
    s32 x7C;
    u8 pad80[0xFC - 0x80];
    f32 xFC;
    u8 pad100[0x17C - 0x100];
    f32 x17C;
} V_003A2808;
typedef struct {
    u8 pad[0x10];
    Vec4 x10;
    M_003A2808 *x20;
    u8 pad24[0x2C - 0x24];
    f32 x2C;
} P_003A2808;
extern u8 D_001A4BE0[];
extern s32 D_L30_001DF2C0;
extern s32 D_L30_001E9018[];
extern s32 D_L30_001DE954;
__asm__(".extern D_L30_001DE954, 4");
extern f32 D_L30_001DE9F8;
__asm__(".extern D_L30_001DE9F8, 4");
extern f32 D_L30_001DE980;
__asm__(".extern D_L30_001DE980, 4");
extern f32 D_L30_001DE97C;
__asm__(".extern D_L30_001DE97C, 4");
extern s32 D_L30_001DE8C0;
__asm__(".extern D_L30_001DE8C0, 4");
extern f32 D_L30_001DE8AC;
__asm__(".extern D_L30_001DE8AC, 4");
extern f32 D_L30_001DE92C;
__asm__(".extern D_L30_001DE92C, 4");
extern s32 D_L30_001DE940;
__asm__(".extern D_L30_001DE940, 4");
extern f32 D_L30_001DE8D4;
__asm__(".extern D_L30_001DE8D4, 4");
extern P_003A2808 *func_L01_00447490(void *, u32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L30_003A2C68(void *, s32);
extern void func_L30_003A2AF8(void *);
extern void func_L30_0034CB68(void *, void *, s32, s32, s32, s32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038CF00(void *, void *);
void func_L30_003A2808(M_003A2808 *a0) {
    V_003A2808 *v = a0->x68;
    u8 *h;
    P_003A2808 *p;
    M_003A2808 *q;
    s16 c;
    Vec4 d __attribute__((aligned(16)));
    f32 t[3];
    Vec4 s __attribute__((aligned(16)));

    p = func_L01_00447490(a0, 0x10000, 0);
    if (p != 0) {
        a0->xA8 = 0xFF;
        if (a0->x20 != 4) {
            if (a0->xAA != 0x1C1A || v->x7C + D_L30_001DE954 < D_L30_001DF2C0) {
                if (p->x2C > 0.0f) {
                    q = p->x20;
                    if (q != 0) {
                        c = q->xAA;
                        if (c != 0x1946 && c != 0x1C1A) {
                            h = D_001A4BE0;
                            if (c == (*(M_003A2808 **)(h + 0x25C0))->xAA) {
                                s.q = p->x10.q;
                                func_0038CF68(&s, &s, 1.0f);
                                func_0038CF68(v, h + 0x110, D_L30_001DE9F8);
                                vec_add_ba(&v->x00, &v->x00, &s);
                                func_0038CF68(v, v, func_003824E0(D_L30_001DE980, D_L30_001DE97C));
                                func_L30_003A2C68(a0, 6);
                            } else if (c == 0x1678) {
                                vec_sub_ba(&v->x00, &v->x30, &q->x10);
                                func_0038CF68(v, v, func_003824E0(D_L30_001DE980, D_L30_001DE97C));
                                func_L30_003A2C68(a0, 6);
                            } else {
                                func_L30_003A2C68(a0, 0x42);
                            }
                            func_L30_003A2AF8(a0);
                        }
                    }
                }
            }
        }
    }
    if (a0->x20 == 6) {
        func_L30_003A2AF8(a0);
    }
    h = D_001A4BE0;
    a0->x10.f[1] = *(f32 *)(h + 0x84);
    if ((D_L30_001DF2C0 & D_L30_001DE8C0) == (((s32)a0 >> 8) & D_L30_001DE8C0)) {
        if (a0->x20 != 4) {
            vec_sub_ba(&d, h + 0x80, &a0->x10);
            func_0038CF68(&d, &d, 1.0f);
            func_L30_0034CB68(a0, &d, 1, -1, 0, 0, D_L30_001DE8AC, D_L30_001DE92C);
            if (D_L30_001E9018[0] != 0 && D_L30_001E9018[0] == *(s32 *)(h + 0x25C0) && v->x58 == 0) {
                func_003A52A0(0, 0, a0);
                v->x58 = D_L30_001DE940;
            }
        }
    }
    if ((v->x54 & 4) && func_0038CAD0(&v->x7C)) {
        func_L30_003A2AF8(a0);
        func_L30_003A2C68(a0, 0x42);
    }
    if (a0->x20 != 4) {
        u8 *hh = D_001A4BE0;
        t[0] = v->xFC;
        t[1] = *(f32 *)(hh + 0x84);
        t[2] = v->x17C;
        if (func_0038CF00(&v->x30, t) <= D_L30_001DE8D4 && a0->x20 != 0x42) {
            func_L30_003A2C68(a0, 0x42);
        }
    }
}
/* localdecomp:end func_L30_003A2808 */

/* localdecomp:start func_L30_003A2AF8 */
#include "vu0.h"

typedef struct {
    vu0_v4 vel;
    u8 pad10[0x54 - 0x10];
    s32 flags;
    u8 pad58[0x7C - 0x58];
    s32 w7C;
} V_003A2AF8;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x68 - 0x20];
    void *vars;
} M_003A2AF8;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x68 - 0x20];
    V_003A2AF8 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 xAA;
} O_003A2AF8;

__asm__(".extern D_L30_001DE8F8, 4");
__asm__(".extern D_L30_001DE8E8, 4");
__asm__(".extern D_L30_001DE9FC, 4");
extern f32 D_L30_001DE8F8;
extern s32 D_L30_001DE8E8;
extern f32 D_L30_001DE9FC;
extern O_003A2AF8 *D_L30_001ED080[];
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);

void func_L30_003A2AF8(void *arg0)
{
    M_003A2AF8 *m = arg0;
    void *w = m->vars;
    s32 n;
    s32 i;
    O_003A2AF8 *o;
    V_003A2AF8 *v;
    Vec4 d;

    n = func_003D4D00(&m->pos, 1, m, 0, D_L30_001DE8F8);
    for (i = 0; i < n; i++) {
        o = D_L30_001ED080[i];
        if (o == 0 || o->xAA != 0x1946) {
            continue;
        }
        v = o->vars;
        if (v == 0 || (v->flags & 4)) {
            continue;
        }
        v->flags |= 4;
        v->w7C = (s32)((f32)D_L30_001DE8E8 * 0.5f
                       * (func_0038CF00(&m->pos, &o->pos) / D_L30_001DE8F8 + 1.0f));
        vec_sub_ba(&d, &o->pos, &m->pos);
        func_0038CE20(&d, &d, func_0038CEA8(w) * D_L30_001DE9FC);
        vec_add_ab(&v->vel, &v->vel, &d);
    }
}
/* localdecomp:end func_L30_003A2AF8 */

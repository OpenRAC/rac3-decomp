/* PAL near miss (Sonnet round 20, b33 h3d, from H3c's 144-diff attempt): 14 differing words, ALL of them float register numbers of one run of loads in the last block (the camera-object marker).
 * Needs the divs_nops row `func_L01_003287D8 2` (the `nop; nop; div.s` of `1.0f / D_L01_001DCA44`). Check: splice this block in place of the INCLUDE_ASM of func_L01_003287D8 in
 * src/levels/shared/L01_00328598.c (the file line is unchanged: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as, the externs it needs are declared by the first function's block) and run
 *   python tools/check.py src/levels/shared/L01_00328598.c func_L01_003287D8 --no-context
 * The scene's marker pass: clear three tables (func_0038CB78), `vars = *(St **)(func_L01_003257E8() + 0x68)`, a rotation matrix from (0, 0, -pi/2), a view basis (cam = *(q *)(D_001A71A0[0] + 0xE0)),
 * a 0xE99A sprite via func_003972A0, then three passes over the 16 slot lists (vt[i]->fn10 = kind, fn8 = skip) calling func_L01_00328598 for the first kind and marking the others used, a pass over the
 * list at vars->w60, and the same marker maths as func_L01_00328598 for the object func_L01_003B3508 returns.
 * What mattered (diffs after, from 144): the block variables col/d/e/g share ONE set of function-scope slots (frame 0x260 instead of 0x280: 130); `long tex;` declared BEFORE `St *vars;` (spill slots are numbered in
 * pseudo order and retail's 8-byte slot is the lowest: 94); divs row, the colour words stored w3, w2, w1, w0 (sched1 emits the last-written first), `o = head[i]; vt = vt[i];` BEFORE `if (o != 0)` in the j loop (reorg moves the
 * vt load into the beqz slot: 37); the head copies `cam = P; v190 = D_L01_001E2DD0; v1A0 = cam;` in that order (12 words); the last block's `g.x = D_L01_001DCA34 + g.x * D_L01_001DCA4C - k` (the sum's operand
 * order puts the load order of retail, [gx, 4C, gy, 50, 34, 38]) 37 -> 26 -> 14.
 * Left (14 words): retail's registers f0 = D_001DCA4C (and the later k), f1 = g.x chain, f2 = g.y chain, f3 = D_001DCA50, f4 = D_001DCA34, f5 = D_001DCA38; ours (this form) f0 = 4C, f1 = 34 (its sum chain), f2 = 38, f3 = g.x, f4 = g.y,
 * f5 = 50. The other add form `g.x * D_4C + D_34 - k` has retail's `add.s prod, 34` operand order but sched1 order [gx, gy, 4C, 50] and the natural allocation f0 = g.x, f1 = g.y, f2 = 4C/k (25 words): the allocator
 * gives retail's 4C/k pair the first register, which no spelling of the expression (50 forms: operand orders, compound assignments, locals, cast pointers, struct-typed D_4C/D_50) moved. */
#include "common.h"
/* localdecomp:start func_L01_003287D8 */
typedef union {
    vu0_v4 v;
    s32 w[4];
} Col_003287D8;
typedef struct {
    u8 p0[8];
    s32 (*fn8)(void *);
    u8 pC[4];
    s32 (*fn10)(void *);
} Vt_003287D8;
typedef struct {
    u8 p0[0x30];
    unsigned long fl30;
    u8 p38[0x60];
    s32 w98;
} Mo_003287D8;
typedef struct {
    u8 p0[0x60];
    Mo_003287D8 *w60;
    u8 p64[0x160 - 0x64];
    Vt_003287D8 *vt[16];
    u8 p1A0[0x2A0 - 0x1A0];
    Mo_003287D8 *head[16];
} St_003287D8;
extern void func_0038CB78(void *, s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_0040EE50(void *, void *);
extern long func_00389598(s32);
extern s32 func_00396968(s32, s32);
extern void func_003972A0(s32, s32 *, f32, f32, f32, f32, f32);
extern s32 func_L01_00449050(void *);
extern s32 func_L01_003257E8(void);
extern void *func_L01_00326D98(void);
extern u8 *func_L01_003B3508(void);
extern u8 *D_001A71A0[];
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
__asm__(".extern D_001D4BC0, 16");
__asm__(".extern D_001D4BC4, 16");
extern vu0_q D_L01_001E2DD0;
__asm__(".extern D_L01_001E2DD0, 16");
extern f32 D_L01_001DCA6C;
extern f32 D_L01_001DCA70;
extern f32 D_L01_001DCA74;
extern f32 D_L01_001DCA78;
extern s32 D_L01_001DCA7C;
extern f32 D_L01_001DCA5C;
extern s32 D_L01_001DCA8C;
__asm__(".extern D_L01_001DCA8C, 16");
extern s32 D_L01_001DCA94;
__asm__(".extern D_L01_001DCA94, 16");
extern s32 D_L01_001DCA98[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DCA98, 8");
__asm__(".extern D_L01_001DCA6C, 4");
__asm__(".extern D_L01_001DCA70, 4");
__asm__(".extern D_L01_001DCA74, 4");
__asm__(".extern D_L01_001DCA78, 4");
__asm__(".extern D_L01_001DCA7C, 4");

void func_L01_003287D8(void) {
    s32 usedA[4];
    s32 usedB[16][4];
    s32 usedC[4];
    vu0_v4 cam;
    vu0_v4 ang;
    vu0_v4 mat[3];
    vu0_v4 v180;
    vu0_v4 v190;
    vu0_v4 v1A0;
    Col_003287D8 d;
    vu0_v4 e;
    vu0_v4 g;
    long tex;
    St_003287D8 *vars;
    s32 i;
    s32 j;
    s32 k;
    s32 kind;
    Mo_003287D8 *o;
    Mo_003287D8 *q;
    Vt_003287D8 *vt;
    u8 *node;
    u8 *p;

    func_0038CB78(usedA, 0, sizeof(usedA));
    func_0038CB78(usedB, 0, sizeof(usedB));
    func_0038CB78(usedC, 0, sizeof(usedC));
    vars = *(St_003287D8 **)(func_L01_003257E8() + 0x68);
    tex = func_00389598(D_L01_001DCA7C);
    qzero(&ang);
    ang.z = -1.5707964f;
    func_0038D308(mat, &ang);
    *(vu0_q *)&cam = *(vu0_q *)(D_001A71A0[0] + 0xE0);
    *(vu0_q *)&v190 = D_L01_001E2DD0;
    *(vu0_q *)&v1A0 = *(vu0_q *)&cam;
    func_0038CE90(&v180, &v190, &v1A0);
    func_0038CF68(&v180, &v180, 1.0f);
    func_0038D5F0(&v180, &v180, mat);
    func_L01_0040EE50(&v180, &v180);
    {
        f32 w;
        f32 h;
        w = (D_L01_001DCA6C + D_L01_001DCA6C) * (f32)D_001D4BC0;
        h = (D_L01_001DCA70 + D_L01_001DCA70) * (f32)D_001D4BC4;
        e.x = (D_L01_001DCA74 - D_L01_001DCA6C) * (f32)D_001D4BC0;
        e.y = (D_L01_001DCA78 - D_L01_001DCA70) * (f32)D_001D4BC4;
        d.w[3] = D_L01_001DCA8C;
        d.w[2] = D_L01_001DCA8C;
        d.w[1] = D_L01_001DCA8C;
        d.w[0] = D_L01_001DCA8C;
        func_003972A0(func_00396968(0xE99A, 3), d.w, e.x, e.y, w, h, 0.0f);
    }
    k = D_L01_001DCA98[0];
    for (i = 0; i < 16; i++) {
        q = vars->head[i];
        if (q != 0) {
            vt = vars->vt[i];
            if (vt->fn10 != 0) {
                o = q;
                do {
                    node = (u8 *)func_L01_00449050(o);
                    kind = vt->fn10(o);
                    if (kind != 0) {
                        if (vt->fn8(o) == 0) {
                            if ((o->fl30 & (0x8208UL << 29)) != (0x8200UL << 23) || o->w98 != 0) {
                                if (kind == k) {
                                    func_L01_00328598((u8 *)o, kind, &cam, &v180, tex);
                                } else {
                                    usedA[kind] = 1;
                                    usedB[i][kind] = 1;
                                }
                            }
                        }
                    }
                    o = *(Mo_003287D8 **)(node + 4);
                } while (o != 0);
            }
        }
    }
    if (vars->w60 != 0) {
        vt = func_L01_00326D98();
        o = vars->w60;
        if (o != 0) {
            do {
                node = (u8 *)func_L01_00449050(o);
                kind = vt->fn10(o);
                if (kind != 0) {
                    if (vt->fn8(o) == 0) {
                        if (kind == k) {
                            func_L01_00328598((u8 *)o, kind, &cam, &v180, tex);
                        } else {
                            usedC[kind] = 1;
                        }
                    }
                }
                o = *(Mo_003287D8 **)(node + 4);
            } while (o != 0);
        }
    }
    for (j = 1; j < 4; j++) {
        k = D_L01_001DCA98[j];
        if (usedA[k] != 0) {
            for (i = 0; i < 16; i++) {
                if (usedB[i][k] != 0) {
                    o = vars->head[i];
                    vt = vars->vt[i];
                    if (o != 0) {
                        do {
                            node = (u8 *)func_L01_00449050(o);
                            kind = vt->fn10(o);
                            if (kind == k) {
                                if (vt->fn8(o) == 0) {
                                    if ((o->fl30 & (0x8208UL << 29)) != (0x8200UL << 23) || o->w98 != 0) {
                                        func_L01_00328598((u8 *)o, kind, &cam, &v180, tex);
                                    }
                                }
                            }
                            o = *(Mo_003287D8 **)(node + 4);
                        } while (o != 0);
                    }
                }
            }
        }
    }
    if (vars->w60 != 0) {
        vt = func_L01_00326D98();
        for (j = 1; j < 4; j++) {
            k = D_L01_001DCA98[j];
            if (usedC[k] != 0) {
                o = vars->w60;
                if (o != 0) {
                    do {
                        node = (u8 *)func_L01_00449050(o);
                        kind = vt->fn10(o);
                        if (kind != 0) {
                            if (vt->fn8(o) == 0) {
                                if (kind == k) {
                                    func_L01_00328598((u8 *)o, kind, &cam, &v180, tex);
                                } else {
                                    usedC[kind] = 1;
                                }
                            }
                        }
                        o = *(Mo_003287D8 **)(node + 4);
                    } while (o != 0);
                }
            }
        }
    }
    p = func_L01_003B3508();
    if (p != 0) {
        f32 len;
        f32 s;
        f32 kk;
        vec_sub_ab(&d.v, p, D_001A4C60);
        s = func_0038CE68(&d.v, &cam);
        func_0038CE20(&e, &cam, s);
        vec_sub_ab(&d.v, &d.v, &e);
        len = func_0038CEA8(&d.v);
        if (len > D_L01_001DCA44) {
            len = D_L01_001DCA44;
        } else if (len < D_L01_001DCA48) {
            len = D_L01_001DCA48;
        }
        s = len * (1.0f / D_L01_001DCA44);
        func_0038D000(&d.v, &d.v, &v180);
        func_0038CF68(&g, &d.v, s * D_L01_001DCA54);
        g.x = D_L01_001DCA34 + g.x * D_L01_001DCA4C - D_L01_001DCA5C;
        g.y = D_L01_001DCA38 + g.y * D_L01_001DCA50 - D_L01_001DCA5C;
        kk = D_L01_001DCA5C;
        func_0038B4D0((s32)(g.x * D_L01_001DC0E8), (s32)(g.y * D_L01_001DC0EC), (s32)((kk + kk) * D_L01_001DC0E8),
                      (s32)((kk + kk) * D_L01_001DC0EC), 0, 0, D_L01_001DCA80, D_L01_001DCA80, D_L01_001DCA94, tex);
    }
}
/* localdecomp:end func_L01_003287D8 */

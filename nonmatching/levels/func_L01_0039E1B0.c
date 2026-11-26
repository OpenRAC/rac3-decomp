/* func_L01_0039E1B0 (3904 B, 34 places): PAL near miss, k6 agent 4 (2026-11-26). Ported from the matched
 * sibling func_L01_00302118 (same routine, an older variant: 3 strands, a strand count at rec+0xA, a float
 * bolt amount at rec+0x3C). check.py: 18 positional diffs at level 01 (same at all 34 places with the D_L01_
 * names), 976 = 976 words; needs the divs_nops row `func_L01_0039E1B0 2` (the one div.s in case 3).
 * Left: the 2 rows of the jump table placeholder, and case 0's basis block (16 rows): retail keeps the
 * lq temp of each perpendicular copy in $v0 and rebuilds the destination address with lui/addiu into $v1
 * right before the sq; here the address (high/lo_sum pseudos made at expand) wins local-alloc's first pick
 * ($v0) and the temp gets $v1, which also moves the first call's `move $a1,$s0` after `sb $zero,0xb`.
 * Tried: separate symbols (best), one array + index, a struct global, a perpendicular pointer (base kept in
 * $s0), three pointer locals (kept in $s0-$s2), block-scoped TI temps, struct/u8[]/vu0_q destinations,
 * every order of the three stores after func_0038D308, right/up/forward locals. */
#include "common.h"
/* localdecomp:start func_L01_0039E1B0 */
extern f32 D_L01_001DE128;
extern f32 D_L01_001DE170;
extern f32 D_L01_001DE124;
extern f32 D_L01_001DE120;
extern f32 D_L01_001DE168;
extern f32 D_L01_001DE164;
extern f32 D_L01_001DE108;
extern f32 D_L01_001DE10C;
extern s32 D_L01_001DE16C;
extern s32 D_L01_001DE150;
extern s32 D_L01_001DE154;
extern s32 D_L01_001DE158;
extern s32 D_L01_001DE15C;
extern s32 D_L01_001DE114;
extern s32 D_L01_001DE110;
extern u8 D_L01_001DE104;
extern f32 D_L01_001DE178[2];
extern f32 D_L01_001D67DC;
extern u8 *D_L01_001E20E0;
extern s32 D_L01_001DAFEC;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DE128, 4");
__asm__(".extern D_L01_001DE170, 4");
__asm__(".extern D_L01_001DE124, 4");
__asm__(".extern D_L01_001DE120, 4");
__asm__(".extern D_L01_001DE168, 4");
__asm__(".extern D_L01_001DE164, 4");
__asm__(".extern D_L01_001DE108, 4");
__asm__(".extern D_L01_001DE10C, 4");
__asm__(".extern D_L01_001DE16C, 4");
__asm__(".extern D_L01_001DE150, 4");
__asm__(".extern D_L01_001DE154, 4");
__asm__(".extern D_L01_001DE158, 4");
__asm__(".extern D_L01_001DE15C, 4");
__asm__(".extern D_L01_001DE114, 4");
__asm__(".extern D_L01_001DE110, 4");
__asm__(".extern D_L01_001DE104, 1");
__asm__(".extern D_L01_001DE178, 8");
__asm__(".extern D_L01_001E20E0, 16");
__asm__(".extern D_L01_001DAFEC, 16");
__asm__(".extern D_L01_001DFB40, 16");
__asm__(".extern D_001D5469, 16");

typedef struct {
    u8 *w4;
    f32 x4, y8, zC;
    f32 x10, y14, z18;
    s16 h1C;
    s16 h1E;
} Sub_39E1B0;

typedef struct {
    u8 p0[4];
    s32 w4;
    u8 b8;
    u8 p9[3];
    f32 fC;
    f32 x10, y14, z18;
    u8 p1C[4];
    Sub_39E1B0 s;
} Pt_39E1B0;

typedef struct {
    f32 f0;
    f32 f4;
    s16 h8;
    u8 b0A;
    u8 b0B;
    s32 wC;
    vu0_v4 v10;
    f32 v20[3];
    f32 f2C;
    Pt_39E1B0 *ptr[3];
    f32 f3C;
    s32 w40;
    s16 h44;
    u8 b46;
    u8 b47;
    u16 h48[4];
    f32 f50[4];
    u8 p60[0x10];
    s32 w70;
} Rec_39E1B0;

extern u8 D_001A4BE0[];
extern u8 D_001A4EC0[];
extern u8 D_001D5469[8];
extern u8 D_00142660[];
extern u8 D_L01_001E2A40[];
extern vu0_v4 D_L01_001E2080, D_L01_001E2090, D_L01_001E20A0;
extern vu0_v4 D_L01_001E20B0, D_L01_001E20C0, D_L01_001E20D0;

void func_L01_0039E1B0(u8 *self) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D308(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_003C5278(void *, void *, void *, f32);
    extern s32 func_L01_0033D178(void *);
    extern void func_L01_0039D938(u8 *);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038CF38(void *, void *);
    extern s32 func_L01_0039E158(u8 *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern s32 func_0038DC20(void *, f32);
    extern void func_L01_0039E0C8(u8 *);
    extern void func_L01_0039E018(u8 *, f32 *, s32);
    extern u8 *func_L01_0046CA28(void *, s32, s32, s32);
    extern void func_L01_0044C870(u8 *, u8 *, u8 *, void *);
    extern s32 func_0038CB00(void *);
    extern s32 func_0038CAD0(void *);
    extern void func_003CD250(void *);
    extern s32 func_L01_0039DCB8(u8 *);
    extern void func_L01_0039DB90(u8 *);
    extern void func_L01_004AAC98(s32, s32, void *, s32);
    extern void func_003E4D10(s32);
    extern void func_003C2880(u8 *);
    extern s32 func_L01_0044C108(void *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
    Rec_39E1B0 *rec;
    struct { vu0_v4 a, b, c, d, e, f, g; } L;
    u8 *w;
    u8 *o0;
    Sub_39E1B0 *sq;
    Pt_39E1B0 *p;
    u8 *q;
    s32 i0, i2b, i3, i4, i5, i6, i7, i8, i9;
    u8 *o1;
    u8 *hero2, *hero3b, *hero4;
    u8 *tbl2, *tbl3, *tbl4;
    s32 lim2, lim3, lim4;
    s32 v2, v3, v4;
    s32 kind;
    f32 *sp;
    s32 ca;
    s32 cb;
    f32 a;
    f32 b;
    f32 f;

    rec = *(Rec_39E1B0 **)(self + 0x68);
    switch (self[0x20]) {
    case 0:
        *(u16 *)(self + 0x34) |= 0x41;
        self[0x20] = 1;
        *(s32 *)(self + 0x98) = 0;
        self[0xBC] = 0;
        o0 = *(u8 **)(self + 0xB8);
        *(vu0_q *)(self + 0x10) = *(vu0_q *)(o0 + 0x10);
        *(vu0_q *)(self + 0xF0) = *(vu0_q *)(o0 + 0xF0);
        func_0038CF68(&rec->v10, self + 0xE0, 0.5f);
        vec_add_ab(&rec->v10, &rec->v10, self + 0x10);
        rec->f0 = 0.0f;
        rec->h8 = 0;
        rec->f4 = func_003824E0(rec->f0, 3.14159274f);
        rec->b46 = 0;
        rec->wC = 0;
        for (i0 = 0; i0 < 4; i0++) {
            rec->f50[i0] = func_00382468(255);
        }
        for (i0 = 0; i0 < 4; i0++) {
            rec->h48[i0] = (D_L01_001DE16C * 5 + 2) / 6;
        }
        for (i0 = 0; i0 < rec->b0A; i0++) {
            rec->ptr[i0] = 0;
        }
        if (D_L01_001E20E0 == 0) {
            void *right = self + 0xC0;
            func_0038D308(right, self + 0xF0);
            D_L01_001E20E0 = self;
            self[0x30] = 0xFF;
            rec->b0B = 0;
            func_0038CF68(&D_L01_001E2080, right, D_L01_001DE128);
            *(vu0_q *)&D_L01_001E20B0 = *(vu0_q *)(self + 0xE0);
            func_0038CF68(&D_L01_001E2090, self + 0xD0, D_L01_001DE128);
            *(vu0_q *)&D_L01_001E20C0 = *(vu0_q *)right;
            func_0038CF68(&D_L01_001E20A0, self + 0xE0, D_L01_001DE128);
            *(vu0_q *)&D_L01_001E20D0 = *(vu0_q *)(self + 0xD0);
        }
        a = func_003824E0(0.0f, 6.28318548f);
        b = func_003824E0(-1.57079637f, 1.57079637f);
        func_00382760(rec->v20, 1.0f, a, b);
        rec->f2C = func_L01_00443A18(0.785398006f, 1.57079637f);
        /* fall through */
    case 1:
        o1 = *(u8 **)(self + 0xB8);
        *(vu0_q *)(self + 0x10) = *(vu0_q *)(o1 + 0x10);
        *(vu0_q *)&rec->v10 = *(vu0_q *)(o1 + 0x10);
        func_003C5278(self + 0x10, &rec->v10, &rec->v10, -0.5f);
        w = *(u8 **)(self + 0xB8);
        if ((s8)w[0x20] < 0 || func_L01_0033D178(w) != 0 || w == self) {
            self[0x20] = 2;
            rec->w40 = 0;
        }
        /* fall through */
    case 2:
        if (self[0x20] == 2) {
            *(vu0_q *)&rec->v10 = *(vu0_q *)(self + 0x10);
            func_003C5278(self + 0x10, &rec->v10, &rec->v10, -0.5f);
            func_L01_0039D938(self);
            for (i3 = 0; i3 < rec->b0A; i3++) {
                sq = (Sub_39E1B0 *)rec->ptr[i3];
                if (sq != 0) {
                    sq = (Sub_39E1B0 *)((u8 *)sq + 0x20);
                    f = func_0038D0B0(sq->zC);
                    sq->y8 = D_L01_001DE170 * f + D_L01_001DE128;
                    sq->zC = func_0038DAB8(sq->zC, D_L01_001DE178[i3]);
                }
            }
        }
        tbl2 = D_00142660;
        hero2 = D_001A4BE0;
        lim2 = *(s32 *)(tbl2 + 8);
        if (hero2[0x25E4] == 1) lim2 = 4;
        if (self[0x20] != 1 && D_L01_001E20E0 != 0 && *(u8 **)(D_L01_001E20E0 + 0x68) != 0 &&
            *(s32 *)(hero2 + 0x2850) != 0 &&
            (*(s32 *)(hero2 + 0x2850) + (*(u8 **)(D_L01_001E20E0 + 0x68))[0xB] < lim2 ||
             (D_001D5469[1] != 0 && *(s16 *)(hero2 + 0x1DC) == 0)) &&
            (rec->ptr[0] != 0 || rec->ptr[1] != 0 || rec->ptr[2] != 0) &&
            func_0038CF00(self + 0x10, D_001A4BE0 + 0x80) < 10.0f && func_L01_0039E158(self) != 0) {
            self[0x20] = 3;
            (*(u8 **)(D_L01_001E20E0 + 0x68))[0xB] += 1;
            w = D_001A4BE0 + 0x80;
            if (D_001D5469[1] != 0) *(s16 *)(w + 0x15C) = 500;
            rec->h44 = (D_L01_001DE150 * 5 + 2) / 6;
            w += 0x260;
            func_0038CE20(&L.d, w, -D_L01_001DE168);
            vec_add_ba(&L.d, D_001A4BE0 + 0x80, &L.d);
            func_0038CE20(&L.a, w, -D_L01_001DE164);
            vec_sub_ab(&L.c, &L.d, self + 0x10);
            func_003C5278(self + 0x10, &L.c, &L.c, 0.5f);
            func_0038CE90(&L.e, &L.c, &L.a);
            func_0038CE90(&L.a, &L.e, &L.c);
            func_0038D890(&L.a, &L.a, &L.c, -1.57079637f);
            func_0038CF68(&L.a, &L.a, D_L01_001DE164);
            func_0038CE20(&L.f, &L.c, 0.5f);
            for (i4 = 0; i4 < rec->b0A; i4++) {
                p = rec->ptr[i4];
                if (p != 0) {
                    f32 *d3, *d4, *s3;
                    sq = &p->s;
                    func_0038D890(&L.b, &L.a, &L.c, (f32)i4 * 0.448549628f);
                    vec_add_ab(&L.g, &L.f, &L.b);
                    ca = D_L01_001DE158;
                    cb = D_L01_001DE15C;
                    d3 = &sq->x4;
                    d4 = &sq->x10;
                    d3[0] = L.g.x;
                    d3[1] = L.g.y;
                    d3[2] = L.g.z;
                    s3 = &rec->ptr[i4]->x10;
                    d4[0] = s3[0];
                    d4[1] = s3[1];
                    d4[2] = s3[2];
                    v2 = (func_00382498(ca, cb) * 5 + 2) / 6;
                    sq->h1C = v2;
                    sq->h1E = v2;
                }
            }
        }
        rec->f0 = D_L01_001DE124 * func_0038D0B0(rec->f4);
        rec->f4 = func_0038DAB8(rec->f4, D_L01_001DE120);
        if (D_L01_001E20E0 == self) func_L01_0039E0C8(self);
        *(vu0_q *)&L.a = *(vu0_q *)(self + 0x10);
        func_003C5278(self + 0x10, &L.a, &L.a, -0.5f);
        L.a.w = 1.0f;
        if (func_0038DC20(&L.a, 64.0f) >= 0) {
            kind = 0x21;
            if (10.0f < func_0038CF38(self + 0x10, D_L01_001E2A40)) kind = 4;
            for (i5 = 0; i5 < rec->b0A; i5++) {
                func_L01_0039E018(self, (f32 *)&L.b, i5);
                q = func_L01_0046CA28(&L.b, kind, 2, 0);
                if (q != 0) {
                    Pt_39E1B0 *pt = (Pt_39E1B0 *)q;
                    Sub_39E1B0 *pq = &pt->s;
                    *(vu0_q *)&L.c = *(vu0_q *)(self + 0x10);
                    qzero(&L.d);
                    if (self[0x20] == 1) {
                        func_L01_0044C870(self, *(u8 **)(self + 0xB8), self + 0x10, &L.d);
                    } else if (rec->wC != 0) {
                        func_L01_0044C870(self, (u8 *)rec->wC, self + 0x10, &L.d);
                        vec_sub_ab(&L.c, &L.c, &L.d);
                    }
                    vec_add_ab(&L.b, &L.b, &L.d);
                    pq->x10 = pt->x10 - L.c.x;
                    pq->y14 = pt->y14 - L.c.y;
                    pq->z18 = pt->z18 - L.c.z;
                    if (self[0x20] == 2) {
                        *(u8 **)&pq->x4 = self;
                    } else {
                        *(u8 **)&pq->x4 = *(u8 **)(self + 0xB8);
                    }
                    if (rec->b47) {
                        pt->w4 = D_L01_001DE114;
                    } else {
                        pt->w4 = D_L01_001DE110;
                    }
                    pt->fC = D_L01_001DE108;
                }
                if (rec->ptr[i5] == 0) {
                    rec->ptr[i5] = (Pt_39E1B0 *)func_L01_0046CA28(&L.b, 0, 1, 0);
                    if (rec->ptr[i5] != 0) {
                        Sub_39E1B0 *sqn = &rec->ptr[i5]->s;
                        sqn->zC = 0.0f;
                        sqn->y8 = D_L01_001DE128;
                        rec->ptr[i5]->fC = D_L01_001DE10C;
                        if (rec->b47) {
                            rec->ptr[i5]->w4 = D_L01_001DE114;
                        } else {
                            rec->ptr[i5]->w4 = D_L01_001DE110;
                        }
                    }
                } else {
                    *(vu0_q *)&rec->ptr[i5]->x10 = *(vu0_q *)&L.b;
                    rec->ptr[i5]->b8 += D_L01_001DE104;
                }
            }
        } else if (D_L01_001DAFEC != 0 || rec->wC != 0) {
            for (i6 = 0; i6 < rec->b0A; i6++) {
                if (rec->ptr[i6] != 0) *(vu0_q *)&rec->ptr[i6]->x10 = *(vu0_q *)(self + 0x10);
            }
        }
        if (func_0038CAD0(&rec->w70) != 0) {
            for (i2b = 0; i2b < rec->b0A; i2b++) {
                if (rec->ptr[i2b] != 0) {
                    func_003CD250(rec->ptr[i2b]);
                    rec->ptr[i2b] = 0;
                }
            }
            if (D_L01_001E20E0 == self) {
                self[0x20] = 4;
            } else {
                func_003C2880(self);
            }
        }
        break;
    case 3:
        if (D_L01_001E20E0 == self) func_L01_0039E0C8(self);
        if (rec->b46 != 0) {
            u8 *w3a = D_001A4EC0;
            func_0038CE20(self + 0x10, w3a, -D_L01_001DE168);
            vec_add_ab(self + 0x10, w3a - 0x260, self + 0x10);
            *(f32 *)(self + 0xFC) = 0.52359879f;
            if (func_L01_0039DCB8(self) != 0) {
                if (func_00382468(5) == 0) func_L01_0039DB90(self);
            }
        }
        hero3b = D_001A4BE0;
        tbl3 = D_00142660;
        lim3 = *(s32 *)(tbl3 + 8);
        if (hero3b[0x25E4] == 1) lim3 = 4;
        if (*(s32 *)(hero3b + 0x2850) == lim3 && *(s16 *)(hero3b + 0x1DC) != 0 && D_001D5469[1] != 0) {
            v3 = (D_L01_001DE154 * 5 + 2) / 6;
            if (rec->h44 < v3) {
                rec->h44 = v3;
                for (i7 = 0; i7 < 4; i7++) rec->h48[i7]++;
            }
        }
        if (func_0038CB00(&rec->h44) != 0) {
            for (i8 = 0; i8 < rec->b0A; i8++) {
                if (rec->ptr[i8] != 0) {
                    func_003CD250(rec->ptr[i8]);
                    rec->ptr[i8] = 0;
                }
            }
            if (D_L01_001E20E0 == self) {
                self[0x20] = 4;
            } else {
                func_003C2880(self);
            }
        } else {
            u8 *w3b = D_001A4EC0;
            func_0038CE20(&L.c, w3b, -D_L01_001DE168);
            vec_add_ab(&L.c, w3b - 0x260, &L.c);
            for (i9 = 0; i9 < rec->b0A; i9++) {
                p = rec->ptr[i9];
                if (p != 0) {
                    sq = &p->s;
                    if (func_0038CB00(&sq->h1E) != 0) {
                        if (rec->b46 == 0) {
                            s32 n;
                            hero4 = D_001A4BE0;
                            tbl4 = D_00142660;
                            lim4 = *(s32 *)(tbl4 + 8);
                            if (hero4[0x25E4] == 1) lim4 = 4;
                            v4 = *(s32 *)(hero4 + 0x2850);
                            if (v4 != 0) {
                                n = v4 + (s32)rec->f3C;
                                if (lim4 < n) n = lim4;
                                *(s32 *)(hero4 + 0x2850) = n;
                                D_L01_001D67DC += rec->f3C;
                                if (v4 != n) func_003E4D10(300);
                            }
                            {
                                u8 *ir = *(u8 **)(D_L01_001E20E0 + 0x68);
                                s32 d5 = ir[0xB] - 1;
                                ir[0xB] = d5;
                                if ((s32)(d5 << 24) < 0) ir[0xB] = 0;
                            }
                            if (rec->b47) {
                                func_L01_004AAC98(1, 0x20, self, 0x200);
                            } else {
                                func_L01_004AAC98(1, 0x20, self, 0x1F5);
                            }
                            rec->b46 = 1;
                        }
                        func_003CD250(p);
                        rec->ptr[i9] = 0;
                    } else {
                        Pt_39E1B0 *n2;
                        *(vu0_q *)&L.e = *(vu0_q *)&p->x10;
                        f = 1.0f - (f32)sq->h1E / (f32)sq->h1C;
                        sp = &p->s.x10;
                        L.b.x = sp[0];
                        L.b.y = sp[1];
                        L.b.z = sp[2];
                        L.b.w = 0.0f;
                        L.a.x = L.b.x - sq->x4;
                        L.a.y = L.b.y - sq->y8;
                        L.a.z = L.b.z - sq->zC;
                        L.d.x = L.c.x - sq->x4;
                        L.d.y = L.c.y - sq->y8;
                        L.d.z = L.c.z - sq->zC;
                        p->x10 = func_L01_004451D0(L.a.x, L.b.x, L.c.x, L.d.x, f);
                        p->y14 = func_L01_004451D0(L.a.y, L.b.y, L.c.y, L.d.y, f);
                        p->z18 = func_L01_004451D0(L.a.z, L.b.z, L.c.z, L.d.z, f);
                        L.f.x = func_L01_00443A18(0.0f, 0.00999999978f) + p->x10;
                        L.f.y = func_L01_00443A18(0.0f, 0.00999999978f) + p->y14;
                        L.f.z = func_L01_00443A18(0.0f, 0.00999999978f) + p->z18;
                        n2 = (Pt_39E1B0 *)func_L01_0046CA28(&L.f, 0x11, 0, 0);
                        if (n2 != 0) {
                            if (rec->b47) n2->w4 = D_L01_001DE114;
                            else n2->w4 = D_L01_001DE110;
                            n2->fC = D_L01_001DE108;
                        }
                        vec_add_ba(&L.e, &p->x10, &L.e);
                        func_0038CE20(&L.e, &L.e, 0.5f);
                        L.f.x = func_L01_00443A18(0.0f, 0.00999999978f) + L.e.x;
                        L.f.y = func_L01_00443A18(0.0f, 0.00999999978f) + L.e.y;
                        L.f.z = func_L01_00443A18(0.0f, 0.00999999978f) + L.e.z;
                        n2 = (Pt_39E1B0 *)func_L01_0046CA28(&L.f, 0x11, 0, 0);
                        if (n2 != 0) {
                            if (rec->b47) n2->w4 = D_L01_001DE114;
                            else n2->w4 = D_L01_001DE110;
                            n2->fC = D_L01_001DE108;
                        }
                    }
                }
            }
        }
        break;
    case 4:
        if (D_L01_001E20E0 == self) func_L01_0039E0C8(self);
        break;
    case 5:
        if ((D_L01_001DFB40 & 1) != 0 && func_L01_0044C108(self + 0x10) != 0) func_L01_004450F0(self, 2, -1);
        break;
    }
}
/* localdecomp:end func_L01_0039E1B0 */

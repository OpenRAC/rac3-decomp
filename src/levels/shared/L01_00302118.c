#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00302118 */

extern f32 D_L01_001DC488;
extern f32 D_L01_001DC4D0;
extern f32 D_L01_001DC484;
extern f32 D_L01_001DC480;
extern f32 D_L01_001DC4C8;
extern f32 D_L01_001DC4C4;
extern f32 D_L01_001DC468[1];
extern f32 D_L01_001DC46C;
extern s32 D_L01_001DC4CC;
extern s32 D_L01_001DC4B0;
extern s32 D_L01_001DC4B4;
extern s32 D_L01_001DC4B8;
extern s32 D_L01_001DC4BC;
extern s32 D_L01_001DC474;
extern s32 D_L01_001DC470;
extern u8 D_L01_001DC464;
extern f32 D_L01_001DC4D8[2];
extern u8 *D_L01_001DFC34;
extern s32 D_L01_001DAFEC;
extern s32 D_L01_001DFB40;
extern s32 D_001D545C;
__asm__(".extern D_L01_001DC488, 4");
__asm__(".extern D_L01_001DC4D0, 4");
__asm__(".extern D_L01_001DC484, 4");
__asm__(".extern D_L01_001DC480, 4");
__asm__(".extern D_L01_001DC4C8, 4");
__asm__(".extern D_L01_001DC4C4, 4");
__asm__(".extern D_L01_001DC468, 4");
__asm__(".extern D_L01_001DC46C, 4");
__asm__(".extern D_L01_001DC4CC, 4");
__asm__(".extern D_L01_001DC4B0, 4");
__asm__(".extern D_L01_001DC4B4, 4");
__asm__(".extern D_L01_001DC4B8, 4");
__asm__(".extern D_L01_001DC4BC, 4");
__asm__(".extern D_L01_001DC474, 4");
__asm__(".extern D_L01_001DC470, 4");
__asm__(".extern D_L01_001DC464, 1");
__asm__(".extern D_L01_001DC4D8, 8");
__asm__(".extern D_L01_001DFC34, 16");
__asm__(".extern D_L01_001DAFEC, 16");
__asm__(".extern D_L01_001DFB40, 16");
__asm__(".extern D_001D545C, 4");
__asm__(".extern D_001D5469, 16");

typedef struct {
    f32 x, y, z;
} V3_302118;

typedef struct {
    u8 *w4;
    f32 x4, y8, zC;
    f32 x10, y14, z18;
    s16 h1C;
    s16 h1E;
} Sub_302118;

typedef struct {
    u8 p0[4];
    s32 w4;
    u8 b8;
    u8 p9[3];
    f32 fC;
    f32 x10, y14, z18;
    u8 p1C[4];
    Sub_302118 s;
} Pt_302118;

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
    Pt_302118 *ptr[8];
    s32 w50;
    s16 h54;
    u8 b56;
    u8 b57;
    u16 h58[4];
    f32 f60[4];
    u8 p70[0x10];
    s32 w80;
    s32 w84;
    s32 w88;
    s32 w8C;
} Rec_302118;

extern u8 D_001A4BE0[];
extern u8 D_001A4EC0[];
extern u8 D_001D5469[8];
extern f32 D_L01_002A5970[];
extern s32 func_L01_00400430(s32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_0047B470_00302118(s32);
extern void func_L01_00303228(u8 *);
extern u8 D_00142660[];
extern u8 D_00142CC0[];
extern u8 D_001426E0[];
extern u8 D_L01_001E2A40[];
extern vu0_v4 D_L01_0026EC90[];
extern vu0_v4 D_L01_0026ED10[];

extern void func_0038CF68(void *, void *, f32);
extern void func_0038D308(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C5278(void *, void *, void *, f32);
extern s32 func_L01_0033D178(void *);
extern void func_L01_003018B8(u8 *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_003020C0(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_00302048(void);
extern void func_L01_00301F98(u8 *, void *, s32);
extern u8 *func_L01_0046CA28(void *, s32, s32, s32);
extern void func_L01_0044C870(u8 *, u8 *, u8 *, void *);
extern s32 func_0038CB00(void *);
extern void func_003CD250(void *);
extern s32 func_L01_00301C38(u8 *);
extern void func_L01_00301B10(u8 *);
extern void func_L01_004AAC98(s32, s32, void *, s32);
extern void func_003E4D10(s32);
extern void func_003C2880(u8 *);
extern s32 func_L01_0044C108(void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);

void func_L01_00302118(u8 *self) {
    Rec_302118 *rec;
    struct { vu0_v4 a, b, c, d, e, f, g;  } L;
    u8 *w;
    u8 *w3a;
    u8 *hero5;
    u8 *o0;
    Sub_302118 *sq;
    Sub_302118 *sqn;
    Pt_302118 **ppe;
    Pt_302118 **ppc;
    Pt_302118 **ppm;
    u8 *q;
    Pt_302118 *p;
    s32 i0;
    s32 i3;
    s32 i4;
    s32 i5;
    s32 i6;
    s32 i7;
    s32 i8;
    s32 i9;
    s32 kind;
    f32 *sp;
    s32 ca;
    s32 cb;
    u8 *hero3b;
    s16 *hp;
    s32 lim2;
    s32 lim3;
    s32 lim4;
    u8 * tbl2;
    u8 * tbl3;
    u8 * tbl4;
    u8 * tbl6;
    u8 * hero2;
    u8 * hero4;
    s32 v2;
    s32 v3;
    s32 v4;
    f32 a;
    f32 b;
    f32 f;

    rec = *(Rec_302118 **)(self + 0x68);
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
        rec->b56 = 0;
        rec->wC = 0;
        for (i0 = 0; i0 < 4; i0++) {
            rec->f60[i0] = func_00382468(255);
        }
        for (i0 = 0; i0 < 4; i0++) {
            rec->h58[i0] = (D_L01_001DC4CC * 5 + 2) / 6;
        }
        for (i0 = 7; i0 >= 0; i0--) {
            rec->ptr[i0] = 0;
        }
        if (D_L01_001DFC34 == 0) {
            vu0_v4 *basis;
            vu0_v4 *perpendicular;
            void *right = self + 0xC0;
            void *up = self + 0xD0;
            void *forward = self + 0xE0;

            func_0038D308(right, self + 0xF0);
            D_L01_001DFC34 = self;
            self[0x30] = 0xFF;
            rec->b0B = 0;

            basis = D_L01_0026EC90;
            func_0038CF68(&basis[0], right, D_L01_001DC488);
            perpendicular = D_L01_0026ED10;
            *(vu0_q *)&perpendicular[0] = *(vu0_q *)forward;
            func_0038CF68(&basis[1], up, D_L01_001DC488);
            *(vu0_q *)&perpendicular[1] = *(vu0_q *)right;
            func_0038CF68(&basis[2], forward, D_L01_001DC488);
            *(vu0_q *)&perpendicular[2] = *(vu0_q *)up;

            vec_add_ba(&basis[3], right, forward);
            func_0038CF68(&basis[3], &basis[3], D_L01_001DC488);
            func_0038CE90(&perpendicular[3], &basis[3], up);
            vec_add_ba(&basis[4], right, up);
            func_0038CF68(&basis[4], &basis[4], D_L01_001DC488);
            func_0038CE90(&perpendicular[4], &basis[4], forward);
            vec_sub_ab(&basis[5], up, forward);
            func_0038CF68(&basis[5], &basis[5], D_L01_001DC488);
            func_0038CE90(&perpendicular[5], &basis[5], right);
            {
                vec_sub_ab(&basis[6], right, forward);
                func_0038CF68(&basis[6], &basis[6], D_L01_001DC488);
                func_0038CE90(&perpendicular[6], &basis[6], up);
                vec_sub_ab(&basis[7], right, up);
                func_0038CF68(&basis[7], &basis[7], D_L01_001DC488);
                func_0038CE90(&perpendicular[7], &basis[7], forward);
            }
        }
        a = func_003824E0(0.0f, 6.28318548f);
        b = func_003824E0(-1.57079637f, 1.57079637f);
        func_00382760(rec->v20, 1.0f, a, b);
        rec->f2C = func_L01_00443A18(0.785398006f, 1.57079637f);
        /* fall through */
    case 1:
        w = *(u8 **)(self + 0xB8);
        if ((s8)w[0x20] < 0 || func_L01_0033D178(w) != 0 || w == self) {
            self[0x20] = 2;
            rec->w50 = 0;
        } else {
            *(vu0_q *)(self + 0x10) = *(vu0_q *)(w + 0x10);
            *(vu0_q *)&rec->v10 = *(vu0_q *)(w + 0x10);
            func_003C5278(self + 0x10, &rec->v10, &rec->v10, -0.5f);
        }
        /* fall through */
    case 2:
        if (self[0x20] == 2) {
            *(vu0_q *)&rec->v10 = *(vu0_q *)(self + 0x10);
            func_003C5278(self + 0x10, &rec->v10, &rec->v10, -0.5f);
            func_L01_003018B8(self);
            for (i3 = 0; i3 < 8; i3++) {
                sq = (Sub_302118 *)rec->ptr[i3];
                if (sq != 0) {
                    sq = (Sub_302118 *)((u8 *)sq + 0x20);
                    f = func_0038D0B0(sq->zC);
                    sq->y8 = D_L01_001DC4D0 * f + D_L01_001DC488;
                    sq->zC = func_0038DAB8(sq->zC, D_L01_001DC4D8[i3]);
                }
            }
        }
        hero2 = D_001A4BE0;
        tbl2 = D_00142660;
        lim2 = *(s32 *)(tbl2 + 8);
        if (hero2[0x25E4] == 1) lim2 = 4;
        if (self[0x20] != 1 && D_L01_001DFC34 != 0 && *(u8 **)(D_L01_001DFC34 + 0x68) != 0 &&
            *(s32 *)(hero2 + 0x2850) != 0 &&
            (*(s32 *)(hero2 + 0x2850) + (*(u8 **)(D_L01_001DFC34 + 0x68))[0xB] < lim2 ||
             (*(s32 *)(hero2 + 0x2850) == *(s32 *)(tbl2 + 8) && D_00142CC0[0] != 0 &&
              D_001426E0[0xD3] < D_001426E0[0xD4]) ||
             (D_001D5469[1] != 0 && (hero5 = D_001A4BE0, *(s16 *)(hero5 + 0x1DC) == 0))) &&
            (rec->ptr[0] != 0 || rec->ptr[1] != 0 || rec->ptr[2] != 0 ||
             rec->ptr[3] != 0 || rec->ptr[4] != 0 || rec->ptr[5] != 0 ||
             rec->ptr[6] != 0 || rec->ptr[7] != 0) &&
            func_0038CF00(self + 0x10, D_001A4BE0 + 0x80) < 10.0f && func_L01_003020C0(self) != 0) {
            self[0x20] = 3;
            (*(u8 **)(D_L01_001DFC34 + 0x68))[0xB] += 1;
            w = D_001A4BE0 + 0x80;
            if (D_001D5469[1] != 0) *(s16 *)(w + 0x15C) = 500;
            rec->h54 = (D_L01_001DC4B0 * 5 + 2) / 6;
            w += 0x260;
            func_0038CE20(&L.d, w, -D_L01_001DC4C8);
            vec_add_ba(&L.d, D_001A4BE0 + 0x80, &L.d);
            func_0038CE20(&L.a, w, -D_L01_001DC4C4);
            vec_sub_ab(&L.c, &L.d, self + 0x10);
            func_003C5278(self + 0x10, &L.c, &L.c, 0.5f);
            func_0038CE90(&L.e, &L.c, &L.a);
            func_0038CE90(&L.a, &L.e, &L.c);
            func_0038D890(&L.a, &L.a, &L.c, -1.57079637f);
            func_0038CF68(&L.a, &L.a, D_L01_001DC4C4);
            func_0038CE20(&L.f, &L.c, 0.5f);
            for (i4 = 0; i4 < 8; i4++) {
                p = rec->ptr[i4];
                if (p != 0) {
                    f32 *d3, *d4, *s3;
                    sq = &p->s;
                    func_0038D890(&L.b, &L.a, &L.c, (f32)i4 * 0.448549628f);
                    vec_add_ab(&L.g, &L.f, &L.b);
                    ca = D_L01_001DC4B8;
                    cb = D_L01_001DC4BC;
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
        rec->f0 = D_L01_001DC484 * func_0038D0B0(rec->f4);
        rec->f4 = func_0038DAB8(rec->f4, D_L01_001DC480);
        if (D_L01_001DFC34 == self) func_L01_00302048();
        *(vu0_q *)&L.a = *(vu0_q *)(self + 0x10);
        func_003C5278(self + 0x10, &L.a, &L.a, -0.5f);
        L.a.w = 1.0f;
        if (func_0038DC20(&L.a, 64.0f) >= 0) {
            func_L01_00404808(func_L01_00303228, self);
            kind = 0x21;
            if (10.0f < func_0038CF38(self + 0x10, D_L01_001E2A40)) kind = 4;
            for (i5 = 0; i5 < 8; i5++) {
                func_L01_00301F98(self, &L.b, i5);
                q = func_L01_0046CA28(&L.b, kind, 2, 0);
                if (q != 0) {
                    Pt_302118 *pt = (Pt_302118 *)q;
                    Sub_302118 *pq = &pt->s;
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
                    if (rec->b57) {
                        pt->w4 = D_L01_001DC474;
                    } else {
                        pt->w4 = D_L01_001DC470;
                    }
                    pt->fC = D_L01_001DC468[0];
                }
                if (rec->ptr[i5] == 0) {
                    rec->ptr[i5] = (Pt_302118 *)func_L01_0046CA28(&L.b, 0, 1, 0);
                    if (rec->ptr[i5] != 0) {
                        sqn = &rec->ptr[i5]->s;
                        sqn->zC = 0.0f;
                        sqn->y8 = D_L01_001DC488;
                        rec->ptr[i5]->fC = D_L01_001DC46C;
                        if (rec->b57) {
                            rec->ptr[i5]->w4 = D_L01_001DC474;
                        } else {
                            rec->ptr[i5]->w4 = D_L01_001DC470;
                        }
                    }
                } else {
                    *(vu0_q *)&rec->ptr[i5]->x10 = *(vu0_q *)&L.b;
                    rec->ptr[i5]->b8 += D_L01_001DC464;
                }
            }
        } else if (D_L01_001DAFEC != 0 || rec->wC != 0) {
            ppe = rec->ptr;
            for (i6 = 7; i6 >= 0; i6--, ppe++) {
                if (*ppe != 0) *(vu0_q *)&(*ppe)->x10 = *(vu0_q *)(self + 0x10);
            }
        }
        break;
    case 3:
        if (D_L01_001DFC34 == self) func_L01_00302048();
        if (rec->b56 != 0) {
            w3a = D_001A4BE0 + 0x2E0;
            func_0038CE20(self + 0x10, w3a, -D_L01_001DC4C8);
            vec_add_ab(self + 0x10, w3a - 0x260, self + 0x10);
            *(f32 *)(self + 0xFC) = 0.52359879f;
            if (func_L01_00301C38(self) != 0) {
                if (func_00382468(5) == 0) func_L01_00301B10(self);
            }
        }
        hero3b = D_001A4BE0;
        tbl3 = D_00142660;
        hp = &rec->h54;
        lim3 = *(s32 *)(tbl3 + 8);
        if (hero3b[0x25E4] == 1) lim3 = 4;
        if (*(s32 *)(hero3b + 0x2850) == lim3 && *(s16 *)(hero3b + 0x1DC) != 0 && D_001D5469[1] != 0) {
            v3 = (D_L01_001DC4B4 * 5 + 2) / 6;
            if (rec->h54 < v3) {
                rec->h54 = v3;
                for (i7 = 0; i7 < 4; i7++) rec->h58[i7]++;
            }
        }
        if (func_0038CB00(hp) != 0) {
            ppc = rec->ptr;
            for (i8 = 7; i8 >= 0; i8--, ppc++) {
                if (*ppc != 0) {
                    func_003CD250(*ppc);
                    *ppc = 0;
                }
            }
            if (D_L01_001DFC34 == self) {
                self[0x20] = 4;
            } else {
                func_003C2880(self);
            }
        } else {
            u8 *w3b = D_001A4EC0;
            func_0038CE20(&L.c, w3b, -D_L01_001DC4C8);
            vec_add_ba(&L.c, w3b - 0x260, &L.c);
            hero4 = w3b - 0x2E0;
            ppm = rec->ptr;
            for (i9 = 7; i9 >= 0; i9--, ppm++) {
                p = *ppm;
                if (p != 0) {
                    sq = &p->s;
                    if (func_0038CB00(&sq->h1E) != 0) {
                        if (rec->b56 == 0) {
                            f32 sc;
                            f32 amt;
                            tbl4 = D_00142660;
                            lim4 = *(s32 *)(tbl4 + 8);
                            if (hero4[0x25E4] == 1) lim4 = 4;
                            v4 = *(s32 *)(hero4 + 0x2850);
                            if (v4 != 0) {
                                s32 n;
                                s32 r;
                                s32 k;
                                if (tbl4[0x32] != 0) sc = D_L01_002A5970[D_001D545C];
                                else sc = 2.0f;
                                k = func_L01_00400430(hero4[0x25F7] & 0xF);
                                r = 0;
                                if (k == 3) r = rec->w88;
                                else if (k == 2) r = rec->w84;
                                else if (k == 1) r = rec->w80;
                                if (r <= 0) r = rec->b57 ? 4 : 1;
                                if (D_00142660[0x32] == 0 || rec->w8C == 0) sc = 1.0f;
                                amt = (f32)r;
                                if (D_00142CC0[0] != 0) {
                                    tbl6 = D_00142660;
                                    if (*(s32 *)(hero4 + 0x2850) == *(s32 *)(tbl6 + 8)) {
                                        u8 *ir = D_001426E0;
                                        if (ir[0xD3] < ir[0xD4]) {
                                            func_L01_0047B470_00302118(0);
                                            ir[0xD3] += (s32)(amt * sc);
                                            if (ir[0xD4] < ir[0xD3]) ir[0xD3] = ir[0xD4];
                                        }
                                    }
                                }
                                n = *(s32 *)(hero4 + 0x2850) + (s32)(amt * sc);
                                if (lim4 < n) n = lim4;
                                *(s32 *)(hero4 + 0x2850) = n;
                                if (v4 != n) func_003E4D10(300);
                            }
                            {
                                u8 *ir = *(u8 **)(D_L01_001DFC34 + 0x68);
                                s32 d5 = ir[0xB] - 1;
                                ir[0xB] = d5;
                                if ((s32)(d5 << 24) < 0) ir[0xB] = 0;
                            }
                            if (rec->b57) {
                                func_L01_004AAC98(1, 0x20, self, 0x200);
                            } else {
                                func_L01_004AAC98(1, 0x20, self, 0x1F5);
                            }
                            rec->b56 = 1;
                        }
                        func_003CD250(p);
                        *ppm = 0;
                    } else {
                        Pt_302118 *n2;
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
                        n2 = (Pt_302118 *)func_L01_0046CA28(&L.f, 0x11, 0, 0);
                        if (n2 != 0) {
                            n2->w4 = rec->b57 ? D_L01_001DC474 : D_L01_001DC470;
                            n2->fC = D_L01_001DC468[0];
                        }
                        vec_add_ba(&L.e, &p->x10, &L.e);
                        func_0038CE20(&L.e, &L.e, 0.5f);
                        L.f.x = func_L01_00443A18(0.0f, 0.00999999978f) + L.e.x;
                        L.f.y = func_L01_00443A18(0.0f, 0.00999999978f) + L.e.y;
                        L.f.z = func_L01_00443A18(0.0f, 0.00999999978f) + L.e.z;
                        n2 = (Pt_302118 *)func_L01_0046CA28(&L.f, 0x11, 0, 0);
                        if (n2 != 0) {
                            n2->w4 = rec->b57 ? D_L01_001DC474 : D_L01_001DC470;
                            n2->fC = D_L01_001DC468[0];
                        }
                    }
                }
            }
        }
        break;
    case 4:
        if (D_L01_001DFC34 == self) func_L01_00302048();
        break;
    case 5:
        if ((D_L01_001DFB40 & 1) != 0 && func_L01_0044C108(self + 0x10) != 0) func_L01_004450F0(self, 2, -1);
        break;
    }
}
/* localdecomp:end func_L01_00302118 */

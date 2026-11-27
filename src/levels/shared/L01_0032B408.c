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

static __inline__ void set_v3_0032B408(V3_0032B408 *dst, vu0_v4 *src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

static __inline__ void get_v3_0032B408(vu0_v4 *dst, V3_0032B408 *src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = 0.0f;
}

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
                set_v3_0032B408(&D_L01_002784E0[*(s32 *)(st + 0x6C)], &vF0);
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
            get_v3_0032B408(&v20, &D_L01_002784E0[*(s32 *)(st + 0x6C)]);
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

/* localdecomp:start func_L01_0032BCB0 */
typedef int s128 __attribute__((mode(TI)));

extern f32 D_L01_001DCE30;
__asm__(".extern D_L01_001DCE30, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
typedef struct {
    u8 pad0[0x100];
    s32 w100[0x40];
} T_0032BCB0;
extern T_0032BCB0 D_L01_00276E60;
extern void func_L01_004C7D40(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_004CADE8(void *, void *);
extern void func_L01_0032CA80(void);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00444F38(void *, s32, s32, s32, s32);

void func_L01_0032BCB0(u8 *self) {
    f32 old[4] __attribute__((aligned(16)));
    u8 *s;

    *(s128 *)old = *(s128 *)(self + 0x10);
    s = *(u8 **)(self + 0x68);
    vec_add_ab(self + 0x10, self + 0x10, s);
    func_L01_004C7D40(self + 0x10, s, D_L01_001DCE30 * 0.00040000002f * 0.1f);
    if (func_003D3CB0(old, self + 0x10, 0x10, self, 0) != 0) {
        self[0x20] = 8;
        if (D_001D545C == 0x1C) {
            s[0x4E] = func_L01_004CADE8(&D_L01_00276E60, self);
            func_L01_0032CA80();
            if (D_L01_00276E60.w100[(s8)s[0x4E]] != 0) {
                self[0x20] = 2;
                func_003A52A0(1, 0, self);
                func_L01_00444F38(self, 1, 0, 0, 0);
            } else {
                self[0x20] = 6;
            }
        }
    }
}
/* localdecomp:end func_L01_0032BCB0 */

/* localdecomp:start func_L01_0032BDD8 */
/* from the NTSC-U draft of func_L01_0032B970 (nonmatching/levels/func_L01_0032BDD8.c) */
/* log: draft with PAL catalogue names (func_00382468, func_003C3EC8, func_0038CE20, func_003824E0, func_L01_00468678) -> MATCH under the file's @ps2as line */
extern s32 func_00382468(s32);
extern f32 func_003C3EC8(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_00468678(void *, void *, f32, f32, s32);

void func_L01_0032BDD8(u8 *moby) {
    f32 velocity[4];
    f32 got;
    u8 *vars = *(u8 **)(moby + 0x68);

    if (func_00382468(4) != 0) {
        return;
    }
    got = func_003C3EC8(moby + 0x10, velocity);
    func_0038CE20(velocity, vars, 0.25f);
    func_L01_00468678(moby + 0x10, velocity, func_003824E0(0.05f, 0.1f) * 210000.0f, got, 0x88A0A0A0);
}
/* localdecomp:end func_L01_0032BDD8 */

/* localdecomp:start func_L01_0032BE90 */
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003FB640(f32 *, s32, u8 *, f32);
extern s32 D_L01_001EAA1C_0032BE90[];

void func_L01_0032BE90(u8 *a0) {
    f32 v[4];

    func_003C2F58(a0, 0, v);
    if (func_L01_003FB640(v, 2, a0, 0.2f) && D_L01_001EAA1C_0032BE90[0] > 0) {
        a0[32] = 8;
    }
}
/* localdecomp:end func_L01_0032BE90 */

/* localdecomp:start func_L01_0032BEF0 */
extern void func_L01_0044C638(void *, s32, void *, void *, void *, void *);
extern void func_003C3D30(void *, s32, s32, f32);
extern s32 D_001D545C;
extern s32 D_L01_001EAA18[];

void func_L01_0032BEF0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    func_L01_0044C638(a0, *(s32 *)(s + 0x70), a0 + 0x10, a0 + 0xF0, a0 + 0x10, a0 + 0xF0);
    if (D_001D545C == 7) {
        func_003C3D30(a0 + 0x10, 0, 0, 0.5f);
        if (D_L01_001EAA18[0] == 0) {
            *(s32 *)(s + 0x70) = 0;
        }
    }
}
/* localdecomp:end func_L01_0032BEF0 */

/* localdecomp:start func_L01_0032BF70 */
typedef struct { s32 w[9]; } Params_0032BF70;
typedef struct { f32 x, y, z, w; } Vec_0032BF70;
typedef struct {
    u8 p0[0x10];
    vu0_q q10;
    Vec_0032BF70 v20;
    vu0_q q30;
    u8 p40[0xC];
    s16 h4C;
    u8 p4E[6];
    s32 w54;
    u8 p58[4];
    s32 w5C;
    u8 *w60;
    u8 p64[4];
    u8 *w68;
} S_0032BF70;
extern Params_0032BF70 D_L01_001DCE50;
extern u8 D_L01_001DAFF0;
__asm__(".extern D_L01_001DAFF0, 16");
extern f32 D_L01_001DCE44;
__asm__(".extern D_L01_001DCE44, 4");
extern void func_L01_004C7D98(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L01_004501E8(void *, void *, f32, f32, f32, void *, s32, s32, s32, f32, f32, s32, void *, s32, s32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);

void func_L01_0032BF70(u8 *self) {
    S_0032BF70 *s = *(S_0032BF70 **)(self + 0x68);
    vu0_v4 v20;
    vu0_v4 pos;
    vu0_v4 quat;
    vu0_v4 axis;
    vu0_v4 tail;
    vu0_v4 m[4];
    Vec_0032BF70 at;
    f32 a;
    f32 r;

    func_L01_004C7D98(self + 0x10, &v20);
    func_003C2F58(self, 0, &pos);
    if (s->w68 == 0) {
        *(Params_0032BF70 *)&quat = D_L01_001DCE50;
        if (D_L01_001DAFF0 != 0) {
            s->w68 = func_L01_004501E8(&pos, self + 0xC0, 6.2831855f, 6.2831855f, 35.0f, &at, 0, 0, 0, 0.0f, 0.0f, 0, &quat, 1, -1, 0);
        } else {
            s->w68 = func_L01_004501E8(&pos, self + 0xC0, 6.2831855f, 6.2831855f, D_L01_001DCE44, &at, 0, 0, 0, 0.0f, 0.0f, 1, &quat, 1, -1, 1);
        }
        if (s->w68 != 0) {
            u8 *t = s->w68;

            if (*(u8 **)(t + 0x24) != 0 && (*(u8 **)(t + 0x24))[0x46] == 0x16) {
                s->w60 = t;
            }
            self[0x20] = 4;
            s->w5C = 0;
        }
    }
    if (s->h4C != 0 || s->w68 != 0) {
        if (s->w68 == 0) {
            *(vu0_q *)&axis = 0;
            axis.z = 1.0f;
            m[0] = *(vu0_v4 *)&s->q30;
            func_0038CE90(&m[1], &m[0], &axis);
            func_0038CF68(&m[1], &m[1], 1.0f);
            func_0038CE90(&m[2], &m[1], &m[0]);
            m[3].x = 0.0f;
            m[3].y = 0.0f;
            m[3].z = 0.0f;
            m[3].w = 1.0f;
            func_003C48A8(&m[0], &quat);
            r = func_L01_00443A18(0.7853982f, 1.5707964f);
            a = func_0038DAB8(quat.z, r);
            r = func_003824E0(-0.1f, 0.45f);
            func_00382760(&s->v20, 1.0f, a, r);
        }
        s->h4C = 0;
        s->w54 = 0;
        s->q10 = s->q30;
    }
}
/* localdecomp:end func_L01_0032BF70 */

/* localdecomp:start func_L01_0032C220 */
extern void *func_00382348(void *);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);

void func_L01_0032C220(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *t;
    u8 *m;
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40[3];
    vu0_q qa, qb, qr;
    f32 f;

    t = func_00382348(*(void **)(s + 0x68));
    func_L01_004C7D98(a0 + 0x10, &v10);
    *(vu0_q *)&v0 = *(vu0_q *)(*(u8 **)(s + 0x68) + 0x10);
    if (t != 0) {
        func_0038CE20(&v30, *(u8 **)(s + 0x68) + 0xE0, *(f32 *)(t + 0x10));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v0));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v30));
    } else {
        *(vu0_q *)&v0 = *(vu0_q *)(*(u8 **)(*(u8 **)(s + 0x68) + 0x24) + 0x30);
        f = *(f32 *)(*(u8 **)(s + 0x68) + 0x2C) * 0.0009765625f;
        func_0038CE20(&v0, &v0, f);
        v0.w = v0.w * f;
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v0));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(*(u8 **)(s + 0x68) + 0x10)));
    }
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(v0) : "j"(qr));
    m = *(u8 **)(s + 0x68);
    if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD || (*(u16 *)(m + 0x34) & 0x1000) == 0) {
        a0[0x20] = 3;
        *(s32 *)(s + 0x68) = 0;
    } else {
        s += 0x20;
        func_003C2F58(a0, 0, &v20);
        vec_sub_ab(&v30, &v0, &v20);
        func_0038CF68(s, &v30, 1.0f);
        func_L01_0040EE50(v40, a0 + 0xC0);
        func_0038D000(s, s, v40);
    }
}
/* localdecomp:end func_L01_0032C220 */

/* localdecomp:start func_L01_0032C390 */
typedef struct { u8 pad[0x15]; u8 index; } State_0032C390;
typedef struct { u8 pad[0x4C]; f32 speed, delay; u8 tail[0x9C]; } Row_0032C390;
extern State_0032C390 D_001425C0;
extern Row_0032C390 D_L01_002C5600[];
extern s32 D_L01_001DCE48;
__asm__(".extern D_L01_001DCE48, 4");
extern void func_L01_004CABD8(void *, void *, void *);
extern void func_L01_0032CAA0(void *, void *);
extern s32 func_003C4B50(void *);


void func_L01_0032C390(u8 *m) {
    vu0_v4 direction, target, delta, reference, forward;
    u8 *p = *(u8 **)(m + 0x68);
    u8 *desc;
    f32 scale;
    func_003C2F58(m, 1, &reference);
    func_L01_004C7D98(m + 0x10, &direction);
    if (*(f32 *)(p + 0x5C) == 0.0f && *(s32 *)(p + 0x50) && *(u8 **)(p + 0x68)) {
        desc = func_00382348(*(u8 **)(p + 0x68));
        target = *(vu0_v4 *)(*(u8 **)(p + 0x68) + 0x10);
        if (desc) {
            func_0038CE20(&forward, *(u8 **)(p + 0x68) + 0xE0, *(f32 *)(desc + 0x10));
            vec_add_ab(&target, &target, &forward);
        } else {
            target = *(vu0_v4 *)(*(u8 **)(*(u8 **)(p + 0x68) + 0x24) + 0x30);
            scale = *(f32 *)(*(u8 **)(p + 0x68) + 0x2C) * 0.0009765625f;
            func_0038CE20(&target, &target, scale);
            target.w *= scale;
            vec_add_ab(&target, *(u8 **)(p + 0x68) + 0x10, &target);
        }
        vec_sub_ab(&delta, &target, &reference);
        func_0038CF68(&delta, &delta, D_001425C0.index[D_L01_002C5600].speed * 0.020000001f);
        func_L01_004CABD8(&delta, &delta, &reference);
        func_L01_0032CAA0(m, &delta);
        func_003A52A0(0, 0, m);
        *(s32 *)(p + 0x40) = (D_L01_001DCE48 * 5 + 2) / 6;
        *(s32 *)(p + 0x44) = 5;
        if (!func_003C4B50(*(u8 **)(p + 0x68))) (*(u16 *)(p + 0x64))--;
        if (*(s16 *)(p + 0x64) <= 0) m[0x20] = 8;
        *(f32 *)(p + 0x5C) = 1.0f / D_L01_002C5600[D_001425C0.index].delay;
    }
}
/* localdecomp:end func_L01_0032C390 */

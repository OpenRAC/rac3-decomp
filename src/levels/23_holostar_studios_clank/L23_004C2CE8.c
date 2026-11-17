#include "common.h"
#include "vu0.h"
typedef struct { f32 v[4]; } __attribute__((aligned(16))) V4_4C2CE8;
typedef struct { V4_4C2CE8 m[4]; } Mtx_4C2CE8;
typedef struct { u8 p0[0x10]; u8 b10; } A_4C2CE8;
typedef struct { u8 p0[0x48]; A_4C2CE8 *a48[1]; } C_4C2CE8;
typedef struct {
    u8 p0[5];
    u8 b5;
    u8 p6[2];
    f32 f8;
    u8 pC[0x15];
    u8 b21;
    u8 p22[6];
    f32 f28;
} I_4C2CE8;
typedef struct {
    u8 p0[0x10];
    V4_4C2CE8 v10;
    u8 p20[4];
    C_4C2CE8 *p24;
    u8 p28[0xC];
    u16 h34;
    u8 p36[0xA];
    u8 b40, b41, b42, b43;
    f32 f44, f48, f4C;
    u8 p50[8];
    s32 w58;
    s32 w5C;
    u8 p60[0xF];
    u8 b6F;
    u8 p70[0x50];
    u8 aC0[0x30];
    u8 aF0[0x10];
} M_4C2CE8;
typedef struct {
    V4_4C2CE8 v0;
    u8 p10[0x80 - 0x10];
    V4_4C2CE8 v80;
    V4_4C2CE8 v90;
    u8 pA0[0x1E0 - 0xA0];
    s16 h1E0;
    s16 h1E2;
    u8 p1E4[0x238 - 0x1E4];
    s32 w238;
    u8 p23C[0x35C - 0x23C];
    s32 w35C;
    u8 p360[0x500 - 0x360];
    V4_4C2CE8 v500;
    u8 p510[0xBF8 - 0x510];
    M_4C2CE8 *wBF8;
    u8 pBFC[0x1420 - 0xBFC];
    V4_4C2CE8 v1420;
    u8 p1430[4];
    s16 h1434;
    u8 b1436;
    u8 p1437;
    f32 f1438;
    u8 p143C[0x16B0 - 0x143C];
    s32 w16B0;
    u8 p16B4[0x1A80 - 0x16B4];
    I_4C2CE8 *w1A80;
    u8 p1A84[0x1A8C - 0x1A84];
    s32 w1A8C;
    s32 w1A90;
    s32 w1A94;
    s32 w1A98;
    u8 p1A9C[0x22C0 - 0x1A9C];
    V4_4C2CE8 v22C0;
    u8 p22D0[0x25C0 - 0x22D0];
    M_4C2CE8 *w25C0;
    s32 w25C4;
    u8 p25C8[0x25E4 - 0x25C8];
    u8 b25E4;
    u8 p25E5[0x25F8 - 0x25E5];
    s32 w25F8;
    u8 p25FC[0x2838 - 0x25FC];
    f32 f2838;
    u8 p283C[0x286C - 0x283C];
    u8 *p286C;
    u8 p2870[0x2888 - 0x2870];
    s16 h2888;
    s16 h288A;
    s16 h288C;
    u8 p288E[0x28A8 - 0x288E];
    s16 h28A8;
    s16 h28AA;
} G_4C2CE8;
typedef struct {
    u8 p0[0x12F8];
    f32 f12F8;
    u8 p12FC[0x1334 - 0x12FC];
    f32 f1334;
    f32 f1338;
    u8 p133C[0x1458 - 0x133C];
    f32 f1458;
    u8 p145C[0x1494 - 0x145C];
    f32 f1494;
    f32 f1498;
} S_4C3330;

/* localdecomp:start func_L23_004C2CE8 */
extern G_4C2CE8 D_001A4BE0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_L23_00254D40[];
extern void func_003C2EC0(void *, s32, Mtx_4C2CE8 *);
extern void func_0038D590(void *, void *);
extern void func_003C48A8(void *, void *);
extern s32 func_L01_004DFCC8(M_4C2CE8 *, s32, s32, void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_003C7C38(void *);

void func_L23_004C2CE8(void)
{
    Mtx_4C2CE8 mtx;
    M_4C2CE8 *m;

    if (D_001D545C == 0x17) {
        return;
    }
    m = D_001A4BE0.wBF8;
    m->b6F = 0;
    if ((*(u8 *)&D_001A4BE0.w25C0->h34 ^ 1) & 1) {
        func_003C2EC0(D_001A4BE0.w25C0, 5, &mtx);
        m->v10 = mtx.m[3];
        func_0038D590(m->aC0, &mtx);
        func_003C48A8(m->aC0, m->aF0);
        m->h34 &= ~0x41;
        if (m->b43 != 0x65) {
            m->b42 = 0x65;
            m->b43 = 0x65;
            m->b40 = 1;
            m->w58 = func_L01_004DFCC8(m, 0x65, 1, D_L23_00254D40);
            m->w5C = func_L01_004DFCC8(m, m->b43, m->b41, D_L23_00254D40 + 0x600);
        } else if (m->b42 == m->b43) {
            m->f44 += m->f48 * m->f4C;
        } else {
            m->f44 += m->f4C;
        }
        if (m->f44 >= 1.0f) {
            m->b40 = m->b41;
            m->w58 = (s32)D_L23_00254D40;
            func_0038CC88(D_L23_00254D40, D_L23_00254D40 + 0x600, 0x600);
            m->b41++;
            if (m->b41 >= m->p24->a48[m->b43]->b10) {
                m->b41 = 0;
            }
            m->w5C = func_L01_004DFCC8(m, m->b43, m->b41, D_L23_00254D40 + 0x600);
            m->f44 = (m->f44 - 1.0f) / m->f4C;
            m->f4C = *(f32 *)m->w58;
            m->f44 *= m->f4C;
        }
        func_003C7C38(m);
    } else {
        m->h34 |= 0x41;
    }
}
/* localdecomp:end func_L23_004C2CE8 */

/* localdecomp:start func_L23_004C2EF0 */
extern u8 *D_001D52FC;
extern s32 D_L23_001DBD6C;
__asm__(".extern D_L23_001DBD6C, 4");
extern f32 D_L23_001DBCCC;
__asm__(".extern D_L23_001DBCCC, 4");
extern u8 *D_L23_001DE2D0;
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L23_003099A8(void *);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern void func_L23_00309888(void *, V4_4C2CE8, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_00439D70(void *, void *);
extern u8 *func_L01_00439CB8(void *, s32, s32, s32);
extern void func_L01_0043A1E8(void *, u8 *, s32, s32, s32, s32);
extern void func_L01_00439E10(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00450E48(void *, void *, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern u8 *func_L23_00432D60(void *, V4_4C2CE8 *, V4_4C2CE8 *, f32, f32, void *, void *, void *);
extern s32 func_L01_004F4E70(s32, s32);
extern u8 *func_L23_003373D0(void *src, V4_4C2CE8 *pos, s32 arg);

void func_L23_004C2EF0(void)
{
    V4_4C2CE8 buf;
    V4_4C2CE8 q;
    s32 a[3];
    s32 far;
    s32 i;
    f32 ang;

    if (D_001A4BE0.h1E0 != 0 || D_001A4BE0.w25C4 == 0x74) {
        return;
    }
    if (D_001A4BE0.w25C4 == 1 && D_001A4BE0.w1A98 == 0 && func_L01_004606E8(0x10, 6, 0, 0) != 0 && func_L23_003099A8(D_001A4BE0.w25C0) == 0) {
        D_001A4BE0.w1A98 = 0x96;
        func_L01_005110E8(&buf, 1, 2.0f, -2.1f, 8.7f);
        func_L23_00309888(D_001A4BE0.w25C0, buf, 1);
    }
    far = 1;
    if (D_001A4BE0.w25C4 == 0x61 || D_001A4BE0.w25C4 == 0x62) {
        far = 0;
    }
    if (D_001A4BE0.w1A8C != 0) {
        if (D_001A4BE0.w1A80 != 0) {
            if (D_001A4BE0.w1A80->b5 & 2) {
                D_001A4BE0.w1A90 = 1;
            }
            if (D_001A4BE0.w1A90 != 0) {
                if (D_001A4BE0.w1A80->f8 == 0.0f) {
                    func_L01_00439D70(D_001A4BE0.w25C0, &D_001A4BE0.w1A80);
                    D_001A4BE0.w1A8C = 0;
                    return;
                }
                func_003C4138(&D_001A4BE0.w1A80->f8, 0.0f, 0.084000006f);
            }
        } else {
            D_001A4BE0.w1A8C = 0;
        }
        if (D_001A4BE0.w1A8C != 0) {
            if (!(*(s32 *)(D_001D52FC + 0x1A0) & 0x20) || !far) {
                if (D_001A4BE0.w1A80 != 0) {
                    if (D_001A4BE0.w1A80->b5 & 2) {
                        D_001A4BE0.w1A90 = 1;
                    }
                    if (D_001A4BE0.w1A90 != 0) {
                        if (D_001A4BE0.w1A80->f8 == 0.0f) {
                            func_L01_00439D70(D_001A4BE0.w25C0, &D_001A4BE0.w1A80);
                            D_001A4BE0.w1A8C = 0;
                            return;
                        }
                        func_003C4138(&D_001A4BE0.w1A80->f8, 0.0f, 0.084000006f);
                    }
                } else {
                    D_001A4BE0.w1A8C = 0;
                }
            } else {
                D_001A4BE0.w1A90 = 0;
            }
            if (D_001A4BE0.w1A8C != 0) {
                goto active;
            }
        }
    }
    if (far && func_L01_004606E8(0x20, 7, 0, 0) != 0) {
        u8 *t = func_L01_00439CB8(D_001A4BE0.w25C0, 2, D_L23_001DBD6C, 0xFC0);
        D_001A4BE0.w1A90 = 0;
        D_001A4BE0.w1A80 = (I_4C2CE8 *)t;
        if (t != 0) {
            D_001A4BE0.w1A8C = 1;
            func_L01_0043A1E8(D_001A4BE0.w25C0, t, 0xD, 0, 7, 1);
        }
    }
    if (D_001A4BE0.w1A8C == 0) {
        return;
    }
active:
    if (D_001A4BE0.w1A80 == 0 || D_001A4BE0.w1A90 != 0) {
        return;
    }
    func_003C4138(&D_001A4BE0.w1A80->f8, 1.0f, 0.156f);
    D_001A4BE0.w1A80->f28 = 2.0f;
    func_L01_00439E10(D_001A4BE0.w25C0, D_001A4BE0.w1A80);
    func_0038CAD0(&D_001A4BE0.w1A94);
    if (D_001A4BE0.w1A80->b21 != 4 || D_001A4BE0.w1A94 != 0) {
        return;
    }
    D_001A4BE0.w1A94 = 4;
    for (i = 0; i < 2; i++) {
        u8 *t = 0;
        func_003C2F58(D_001A4BE0.w25C0, i + 3, &buf);
        func_L01_00450E48(D_001A4BE0.w25C0, &buf, D_L23_001DBCCC * 1.4f, 0.0f, 0.0f);
        if (D_L23_001DE2D0 != 0) {
            ang = func_0038D160(*(f32 *)(D_L23_001DE2D0 + 0x10) - D_001A4BE0.v80.v[0], *(f32 *)(D_L23_001DE2D0 + 0x14) - D_001A4BE0.v80.v[1]);
            if (func_0038DBA0(D_001A4BE0.v90.v[2], ang) < 0.9599311f && func_0038CF38(&D_001A4BE0.v80, D_L23_001DE2D0 + 0x10) < 50.0f) {
                t = D_L23_001DE2D0;
            }
        }
        if (t == 0) {
            q = D_001A4BE0.v0;
            t = func_L23_00432D60(D_001A4BE0.w25C0, &buf, &q, 0.34906584f, 10000.0f, &a[0], &a[1], &a[2]);
        }
        func_L01_004F4E70(5, 0);
        func_L23_003373D0(D_001A4BE0.w25C0, &buf, (s32)t);
    }
}
/* localdecomp:end func_L23_004C2EF0 */

/* localdecomp:start func_L23_004C3330 */
extern G_4C2CE8 D_001A4BE0;
extern S_4C3330 D_L23_002F5540;
extern f32 D_L23_002F671C[];
__asm__(".extern D_L23_002F671C, 16");
extern f32 D_L23_002F692C[];
__asm__(".extern D_L23_002F692C, 16");
extern s32 D_L23_001D673C;
extern u8 D_001D5470;
__asm__(".extern D_001D5470, 16");
extern f32 D_L23_001DBCCC;
__asm__(".extern D_L23_001DBCCC, 4");
extern f32 D_L23_001DBCFC;
__asm__(".extern D_L23_001DBCFC, 4");
extern void func_L01_0050FF00(void);
extern void func_L01_004EE4E0(void);
extern void func_L01_004E7CB8(void);
extern s32 func_L01_004E8318(s8 *, s8 *, s8 *);
extern void func_L01_004F3BE0(void);
extern s32 func_0038CAD0(void *);
extern void func_L01_00450E48(void *, void *, f32, f32, f32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern f32 func_L01_004F4E20(void *, int);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_004E0C18(void);
extern void func_L01_004E0CB0(void);
extern void func_L23_004EAE60(void);
extern void func_L01_004CC698(void);
extern void func_L01_004F5010(void);
extern void func_L01_004E04A0(void);
extern void func_L01_004E4770(void);
extern void func_L01_004E3148(void);
extern void func_L01_00512E68(void);
extern void func_L01_004E2ED0(void);
extern void func_L01_004E0920(void);
extern void func_L01_004E0CD8(void);
extern void func_L01_004E1020(void);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00430118(void *);
void func_L23_004C2EF0(void);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_004E3268(void);
extern void func_L01_004E48C8(void);
extern void func_L01_004436F4(void *);

void func_L23_004C3330(void)
{
    V4_4C2CE8 v;
    f32 f;

    func_L01_0050FF00();
    func_L01_004EE4E0();
    func_L01_004E7CB8();
    if (D_001A4BE0.b25E4 == 1) {
        func_L01_004E8318((s8 *)&D_001A4BE0.v80, (s8 *)&D_001A4BE0.v90, (s8 *)&D_001A4BE0.v500);
        func_L01_004F3BE0();
    }
    if (D_001A4BE0.b25E4 == 2) {
        func_0038CAD0(&D_001A4BE0.w1A98);
        if (D_001A4BE0.w35C != 0) {
            func_L01_00450E48(D_001A4BE0.w25C0, &v, 0.0f, 0.0f, D_L23_001DBCCC * 2.5f);
            vec_add_ab(&v, &v, &D_001A4BE0.v80);
            func_L01_00446780((u8 *)D_001A4BE0.w25C0, (u8 *)&v, 0x80000, 0, 1, 0, D_L23_001DBCCC * 4.0f, 100.0f, 1.0f);
        }
        if (D_001A4BE0.h1434 != 0 || (D_001A4BE0.w16B0 == 1 && func_L01_004606E8(0x28, 2, 0, 0) != 0)) {
            if (0.15f < D_001A4BE0.f2838 && D_001A4BE0.b1436 == 0) {
                D_L23_002F5540.f1498 = 0.38880002f;
                D_L23_002F5540.f1494 = 0.053280003f;
                D_L23_002F5540.f1334 = 0.036000002f;
                D_L23_002F5540.f1338 = 0.38880002f;
                if (D_L23_001D673C != 0) {
                    f = func_L01_004F4E20(&D_001A4BE0.v1420, 0);
                } else {
                    f = func_0038DB00(D_001A4BE0.f1438, D_001A4BE0.v90.v[2]);
                }
                D_L23_002F5540.f1458 = f;
                D_L23_002F5540.f12F8 = -f;
            }
        }
    }
    if (D_001A4BE0.b25E4 == 1) {
        func_L01_004E0C18();
        func_L01_004E0CB0();
    }
    D_001A4BE0.w238 = 3;
    func_L23_004EAE60();
    func_L01_004CC698();
    if (D_001A4BE0.b25E4 == 0) {
        return;
    }
    func_L01_004F5010();
    func_L01_004E04A0();
    if (D_001A4BE0.b25E4 == 0) {
        return;
    }
    func_L01_004E4770();
    func_L01_004E3148();
    func_L01_00512E68();
    func_L01_004E2ED0();
    if (D_001A4BE0.b25E4 == 1) {
        D_L23_002F671C[0] = D_L23_001DBCFC;
        func_L01_004E0920();
        func_L01_004E0CD8();
        func_L01_004E1020();
        if (D_001A4BE0.p286C != 0) {
            func_003A52A0((s32)(D_001A4BE0.p286C + 0x10), 0, D_001A4BE0.w25C0);
            D_001A4BE0.h28A8 = 0x2F;
            D_001A4BE0.h28AA = (s32)D_001A4BE0.p286C;
        }
        D_001A4BE0.p286C = 0;
    }
    func_L01_00430118(&D_001A4BE0.v80);
    if (D_001A4BE0.b25E4 == 2) {
        if (D_001D5470 != 0) {
            D_L23_002F692C[0] = D_L23_001DBCFC * 1.4f;
        }
        if (D_001A4BE0.h1E2 < 10000) {
            D_001A4BE0.h1E2++;
        }
        func_L01_004E0920();
        func_L23_004C2CE8();
        func_L23_004C2EF0();
        if ((*(u8 *)&D_001A4BE0.w25C0->h34 ^ 1) & 1) {
            func_003C2F58(D_001A4BE0.w25C0, 6, &v);
            D_001A4BE0.v22C0 = v;
            func_L01_004E3268();
        }
    }
    if (D_001A4BE0.b25E4 == 3) {
        if (D_001A4BE0.w25F8 != 0 && D_001A4BE0.w25F8 != 0x1E) {
            if (D_001A4BE0.h288C == 0) {
                D_001A4BE0.h2888 = 1;
                D_001A4BE0.h288C = 0x12;
                D_001A4BE0.h288A = 1;
            }
        } else {
            D_001A4BE0.w25F8 = 0;
        }
    }
    func_L01_004E48C8();
    func_L01_004436F4(D_001A4BE0.w25C0);
}
/* localdecomp:end func_L23_004C3330 */

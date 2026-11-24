#include "common.h"

/* The game's HUD rounding: a screen coordinate times the screen scale, rounded, with the dead
 * compare of the video mode that retail keeps (docs/wiki/Matching-Patterns.md, "Dead compare
 * loads before a rounding expression"). */
extern s32 D_L10_001E0420;
extern f32 D_L10_001E0424;

static __inline__ s32 scale_3B5690(f32 v) {
    f32 z0 = 0.0f, z1 = 0.0f;
    return (s32)((f32)(s32)v * D_L10_001E0424 + 0.5f + (D_L10_001E0420 == 1 ? z0 : z1));
}

/* localdecomp:start func_L10_003B4350 */
extern s32 D_L10_001DEC48;
extern u32 *D_L10_001E02E8;
extern u8 D_00141990[];
extern void func_003A92F0(s32);
extern s32 func_0012C908(s32);
extern void func_003A9108(void);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_003923D0(void);
extern void func_003A9440(s32, unsigned long);
extern void func_L01_004AADE8(s32, s32, void *, s32);
extern void func_003A4288(void);

void func_L10_003B4350(s32 n, s32 k) {
    s32 i;
    s32 c;
    s32 t;

    c = 0;
    func_003A92F0(1);
    i = n - 1;
    func_0012C908(0);
    D_L10_001DEC48 = D_L10_001DEC48 + 1;
    func_003A9108();
    while (i >= 0) {
        c++;
        func_003922B8();
        func_00392350(1);
        func_003923D0();
        func_003A9440(0x42, 0x8000000044UL);
        t = (i << 7) / (i + 1);
        func_003A9440(1, ((long)(0x80 - t) << 24) | 0xFFFFFF);
        D_L10_001E02E8[0] = 0x30000014;
        D_L10_001E02E8[1] = (u32)D_00141990;
        D_L10_001E02E8[2] = 0;
        D_L10_001E02E8[3] = 0x50000014;
        D_L10_001E02E8 = D_L10_001E02E8 + 4;
        func_003A92F0(1);
        func_0012C908(0);
        D_L10_001DEC48 = D_L10_001DEC48 + 1;
        func_003A91D0();
        func_003A9150();
        if (c == 2) {
            func_L01_004AADE8(0x17, 0x110, 0, 0);
        }
        func_003A4288();
        i--;
    }
    i = k - 1;
    while (i >= 0) {
        i--;
        func_003922B8();
        func_00392350(1);
        func_003923D0();
        func_003A9440(0x42, 0x8000000044UL);
        func_003A9440(1, 0x80FFFFFFUL);
        D_L10_001E02E8[0] = 0x30000014;
        D_L10_001E02E8[1] = (u32)D_00141990;
        D_L10_001E02E8[2] = 0;
        D_L10_001E02E8[3] = 0x50000014;
        D_L10_001E02E8 = D_L10_001E02E8 + 4;
        func_003A92F0(1);
        func_0012C908(0);
        D_L10_001DEC48 = D_L10_001DEC48 + 1;
        func_003A91D0();
        func_003A9150();
    }
    func_003A92F0(1);
    func_0012C908(0);
    D_L10_001DEC48 = D_L10_001DEC48 + 1;
    func_003A9108();
    func_003922B8();
    func_00392350(1);
}
/* localdecomp:end func_L10_003B4350 */

/* localdecomp:start func_L10_003B4600 */
extern void func_0038A238(s32);
extern void func_L01_0042B068(s32, s32);
extern void func_003864C0(s32);
extern f32 D_L10_001DEC50;
extern u8 D_L10_001DECE4;
extern u8 D_L10_001DECE5;
extern u8 D_L10_001DECE6;
extern f32 D_L10_001DECE8;
extern f32 D_L10_001DECEC;
extern f32 D_L10_001DECF0;
extern f32 D_L10_001DECF4;

void func_L10_003B4600(void) {
    func_0038A238(5);
    func_L01_0042B068(2, 0);
    D_L10_001DEC50 = 1.5f;
    D_L10_001DECE4 = 1;
    D_L10_001DECE5 = 1;
    D_L10_001DECE6 = 1;
    D_L10_001DECE8 = 262144.0f;
    D_L10_001DECEC = 524288.0f;
    D_L10_001DECF0 = 255.0f;
    D_L10_001DECF4 = 249.0f;
    func_003864C0(0);
}
/* localdecomp:end func_L10_003B4600 */

/* localdecomp:start func_L10_003B4698 */
typedef int Q_3B4698 __attribute__((mode(TI)));

typedef struct C_3B4698 {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x30];
    u16 h44;
} C_3B4698;

typedef struct M_3B4698 M_3B4698;
struct M_3B4698 {
    u8 pad0[0x10];
    Q_3B4698 pos;
    u8 state;
    u8 pad21[3];
    C_3B4698 *pclass;
    u8 pad28[8];
    u8 b30;
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x2E];
    void (*update)(M_3B4698 *);
    u8 *pvar;
    u8 pad6C[0x29];
    u8 b95;
    u8 pad96[2];
    s32 w98;
    u8 pad9C[0xE];
    s16 oclass;
    u8 padAC[0x44];
    Q_3B4698 rot;
};

typedef struct V_3B4698 {
    s32 w00;
    s32 w04;
    s32 w08;
    s32 w0C;
    s32 w10;
    s16 h14;
    s16 h16;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    s32 a30[7];
    s32 w4C;
    s32 a50[5];
    s32 w64;
    s32 w68;
    s32 w6C;
    s32 w70;
    s32 w74;
    s32 w78;
    s32 w7C;
    s32 w80;
    s32 w84;
} V_3B4698;

typedef struct P_3B4698 {
    u8 pad0[0x30];
    Q_3B4698 pos;
    u8 pad40[0x30];
    Q_3B4698 rot;
} P_3B4698;

typedef struct S_3B4698 {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[0x20];
    s16 h48;
    u8 pad4A[4];
    s16 h4E;
    u8 pad50[0x1C];
    s32 w6C;
    u8 pad70[6];
    s16 h76;
    u8 pad78[0x1C];
    s32 w94;
    s16 h98;
    u8 pad9A[4];
    s16 h9E;
} S_3B4698;

typedef struct H_3B4698 {
    u8 pad0[0x35C];
    M_3B4698 *f35C;
    u8 pad360[0x2260];
    s32 w25C0;
} H_3B4698;

typedef struct G_3B4698 {
    u8 pad0[0x98];
    s32 w98;
    s32 w9C;
} G_3B4698;

extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern u8 D_001426E0[];
extern s32 D_L10_001D6694;
extern s32 D_L10_001E5F30[];
extern s32 D_L10_001F2040[];
extern s32 D_L10_002CF830[];
extern s32 D_L10_001E1520;
extern M_3B4698 *D_L10_001DF29C;
extern M_3B4698 *D_L10_001DF2A0;
extern P_3B4698 *D_L10_001DF380;
extern S_3B4698 D_001CCFD0;
extern H_3B4698 D_001A4BE0;
extern G_3B4698 D_00142BA0;
extern u8 D_001A4C60[];
extern u8 *D_001D52FC;
extern u32 D_001A8588[];
extern u32 D_001A8594[];
extern s32 D_L10_001E0860[];
__asm__(".extern D_L10_001DE740, 4");
__asm__(".extern D_L10_001DE744, 4");
__asm__(".extern D_L10_001DE74C, 4");
extern s32 D_L10_001DE740;
extern s32 D_L10_001DE744;
extern s32 D_L10_001DE748;
extern s32 D_L10_001DE74C;
extern f32 D_L10_001DEC50;

extern void func_0039EF28(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_0042B068(s32, s32);
extern void func_003C2880(void *);
extern s32 func_L10_004F76E8(void);
extern void func_L01_00511A40(void *, s32, f32);
extern void func_L01_004B0EE0(void);
extern s32 func_L01_004BA800(void);
extern void func_L01_004A3610(void *, void *);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_003A1930(s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_003A2B68(s32, s32);
extern void func_003A1798(void);
extern s32 func_L10_004399A0(s32, s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00452658(s32, s32);
extern void func_0038A238(s32);
extern void func_L01_0043B510(s32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L05_00451150(void *, s32);
extern s32 func_L01_0044C108(void *);
extern void func_L05_0035A568(void *, s32);
extern void func_L10_003B8ED0(void *, s32);
extern void func_L06_0034FCC8(void *, s32);
extern void *func_003E6C08(void);
extern s32 func_L10_004F8E78(void *, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern s32 func_L01_004561B8(void *);
extern void func_003A1C28(void);
extern s32 func_0013C170(void);
extern void func_L01_004EDE10(void);
extern void func_L01_003B1DB8(void *);
extern void func_L10_003B5B48(void *);
extern void func_L10_003B4600(void);
extern void func_L10_003B4350(s32, s32);
extern void func_L10_003B57A8(void);

void func_L10_003B4698(M_3B4698 *m) {
    V_3B4698 *v = (V_3B4698 *)m->pvar;
    M_3B4698 *q;
    s32 snd;
    s32 n;
    s32 t;
    void *hud;

    if (D_001BBC40[v->w1C + D_001D545C * 16] & 0x80) {
        D_001426E0[2] = 1;
        func_0039EF28();
    }
    if (D_001BBC40[v->w20 + D_001D545C * 16] & 0x80) {
        D_001426E0[0x20] = 1;
        func_0039EF28();
        D_001426E0[0x7A] = 1;
        func_0039EF28();
    }
    switch (m->state) {
    case 0:
        if ((D_001BBC40[v->w1C + D_001D545C * 16] & 0x80) && !(D_001BBC40[v->w20 + D_001D545C * 16] & 0x80)) {
            func_L01_004F50C8(&D_L10_001DF380[v->w10].pos, &D_L10_001DF380[v->w10].rot, 0, 1);
            if (D_L10_001F2040[0] != 1) {
                func_L01_0042B068(1, 0);
            }
        }
        m->b95 = 0;
        if (D_001BBC40[v->w20 + D_001D545C * 16] & 0x80) {
            for (q = D_L10_001DF29C; q < D_L10_001DF2A0; q++) {
                if (q->oclass == 0x1C47) {
                    func_003C2880(q);
                }
            }
        }
        m->b30 = 0xFF;
        m->state = 1;
        break;
    case 1:
        if (D_L10_001F2040[0] == 1) {
            if (D_L10_001D6694 == 2) {
                D_L10_001DF29C[v->w28].h34 |= 2;
                if (D_L10_001E5F30[0] == 2) {
                    M_3B4698 *a = &D_L10_001DF29C[v->w28];
                    u8 *av;
                    a->b31 = 1;
                    a->h34 &= ~1;
                    av = a->pvar;
                    *(Q_3B4698 *)((u8 *)a + 0x10) = *(Q_3B4698 *)(av + 0x70);
                    *(Q_3B4698 *)((u8 *)a + 0xF0) = *(Q_3B4698 *)(av + 0x80);
                    func_L01_004F50C8(&D_L10_001DF380[v->w10].pos, &D_L10_001DF380[v->w10].rot, 0x74, 1);
                } else {
                    D_L10_001DF29C[v->w28].h34 |= 1;
                    D_L10_001DF29C[v->w28].b31 = 0;
                    D_L10_001DF29C[v->w28].h34 &= ~2;
                }
            } else {
                if (D_001A4BE0.f35C == &D_L10_001DF29C[v->w28]) {
                    if (func_L10_004F76E8() != 0x74 && !(D_001BBC40[v->w1C + D_001D545C * 16] & 0x80)) {
                        func_L01_00511A40(&D_L10_001DF29C[v->w28].pos, 0, 1.5707964f);
                    }
                }
                D_L10_001DF29C[v->w28].h34 &= ~1;
                D_L10_001DF29C[v->w28].b31 = 1;
            }
            if (D_L10_001D6694 == 6) {
                if ((D_001BBC40[v->w1C + D_001D545C * 16] & 0x80) && !(D_001BBC40[v->w20 + D_001D545C * 16] & 0x80)) {
                    func_L01_004B0EE0();
                }
            }
        }
        if (func_L01_004BA800() == 0 && D_L10_001D6694 != 6) {
            if (D_L10_001DEC50 <= 0.01f) {
                if (D_L10_001E1520 == 1) {
                    func_L01_004A3610(&D_L10_001DF380[v->w04].pos, &D_L10_001DF380[v->w04].rot);
                    func_L01_00451F60(0x25A, 0x4B, 0);
                } else if (D_L10_001E1520 == 2) {
                    func_L01_004A3610(&D_L10_001DF380[v->w84].pos, &D_L10_001DF380[v->w84].rot);
                    func_L01_00451F60(0x25A, 0x4B, 0);
                }
                D_L10_001E1520 = 0;
            }
            if (D_L10_001F2040[0] == 0) {
                if (D_001CCFD0.h48 != v->w74) {
                    D_001CCFD0.h4E = 5;
                    func_003A1930(v->w74, 1, 0x400);
                }
            } else if (D_L10_001F2040[0] == 1) {
                if (D_001BBC40[v->w1C + D_001D545C * 16] & 0x80) {
                    if (D_001CCFD0.h48 != v->w7C) {
                        D_001CCFD0.h4E = 5;
                        func_003A1930(v->w7C, 0, 0x400);
                    }
                } else {
                    if (D_001CCFD0.h48 != v->w78) {
                        D_001CCFD0.h4E = 5;
                        func_003A1930(v->w78, 1, 0x400);
                    }
                }
            }
            func_0038CAD0(&D_L10_001DE744);
            if (m->b95 == 0) {
                if (D_001CCFD0.w6C == 0 && D_001CCFD0.w24 == -1 && D_001CCFD0.w94 == 0) {
                    snd = -1;
                    if (!(D_001BBC40[v->w80 + D_001D545C * 16] & 0x80)) {
                        if (func_00382380(D_001A4C60, v->w6C, 0)) {
                            snd = v->w64;
                            v->w6C = -1;
                        } else if (func_00382380(D_001A4C60, v->w70, 0)) {
                            snd = v->w68;
                            v->w70 = -1;
                        }
                    }
                    if (snd == -1 && D_L10_001DE744 == 0 && D_L10_001F2040[0] == 0) {
                        if (D_L10_001DE74C < 8) {
                            if (D_L10_001DE74C == 0) {
                                snd = v->w4C;
                            } else {
                                snd = v->a30[D_L10_001DE74C - 1];
                            }
                        } else {
                            snd = v->a50[D_L10_001DE74C - 8];
                        }
                        if (++D_L10_001DE74C >= 13) {
                            D_L10_001DE74C = 0;
                        }
                        D_L10_001DE744 = D_L10_001DE740;
                    }
                    if (snd != -1) {
                        func_003A2B68((snd & 0x3FFF) + 2000, 0);
                        m->b95 = 1;
                    }
                }
            } else if (m->b95 == 1) {
                if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 7000) {
                    func_003A1798();
                    m->b95 = 0;
                }
            }
            if (!(D_001BBC40[v->w1C + D_001D545C * 16] & 0x80)) {
                if (func_L10_004399A0(D_001A4BE0.w25C0, v->w00)) {
                    if (D_00142BA0.w98 & 0x4000000) {
                        func_L01_00452560(0, 4, 0x855, 1, 0, 0, 0);
                        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                            if (D_L10_002CF830[0] == 4) {
                                if (D_00142BA0.w9C >= 0) {
                                    func_L10_003B4600();
                                    {
                                        M_3B4698 *o = &D_L10_001DF29C[v->w18];
                                        func_L01_00456230(o, 1);
                                        o->b30 = 0xFF;
                                        o->h34 &= ~2;
                                        o->update(o);
                                    }
                                } else {
                                    func_L01_004F50C8(&D_L10_001DF380[v->w04].pos, &D_L10_001DF380[v->w04].rot, 0, 1);
                                    func_L01_00452658(0, 4);
                                    if (D_L10_001F2040[0] != 1) {
                                        func_0038A238(8);
                                        D_L10_001DEC50 = 1.0f;
                                        func_L01_0042B068(1, 0);
                                        D_L10_001E1520 = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (func_L10_004399A0(D_001A4BE0.w25C0, v->w08)) {
                if (D_001BBC40[v->w1C + D_001D545C * 16] & 0x80) {
                    D_001426E0[0x20] = 1;
                    func_0039EF28();
                    D_001426E0[0x7A] = 1;
                    func_0039EF28();
                    func_L01_0043B510(v->w20);
                    func_L10_003B4600();
                    {
                        M_3B4698 *o = &D_L10_001DF29C[v->w2C];
                        func_L01_00456230(o, 1);
                        o->b30 = 0xFF;
                        o->h34 &= ~2;
                        o->update(o);
                    }
                } else {
                    func_L01_00452560(0, 4, 0x855, 1, 0, 0, 0);
                    if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                        if (D_L10_002CF830[0] == 4) {
                            func_L01_004F50C8(&D_L10_001DF380[v->w0C].pos, &D_L10_001DF380[v->w0C].rot, 0, 1);
                            func_L01_00452658(0, 4);
                            if (D_L10_001F2040[0] != 0) {
                                func_0038A238(8);
                                D_L10_001DEC50 = 1.0f;
                                func_L01_0042B068(0, 0);
                                D_L10_001E1520 = 2;
                            }
                        }
                    }
                }
            }
            if (!(D_001BBC40[v->w1C + D_001D545C * 16] & 0x80)) {
                break;
            }
            if (D_001BBC40[v->w20 + D_001D545C * 16] & 0x80) {
                break;
            }
            if (v->h16 == 0) {
                if (!(D_001A8588[0] & (1 << D_001D545C))) {
                    func_L01_0041A5B0(0xCF7, 0x9E);
                }
                v->h16 = (f32)v->h14 * 50.0f;
                func_L05_00451150(&D_L10_001DF29C[v->w24], 0x1647);
                {
                    M_3B4698 *r = &D_L10_001DF29C[v->w28];
                    u8 *rv;
                    v->w24 = -1;
                    rv = r->pvar;
                    rv[0x9F] = 1;
                    *(Q_3B4698 *)((u8 *)r + 0x10) = D_L10_001DF380[*(s32 *)(rv + 0x90)].pos;
                    *(Q_3B4698 *)((u8 *)r + 0xF0) = D_L10_001DF380[*(s32 *)(rv + 0x90)].rot;
                    r->state = 5;
                    *(s32 *)(rv + 8) = 0;
                }
                for (q = D_L10_001DF29C; q < D_L10_001DF2A0; q++) {
                    if (q->oclass == 0x1625 && func_L01_0044C108(&q->pos)) {
                        u8 *pa = q->pvar;
                        if (*(s32 *)(pa + 0x3C8)) {
                            *(s32 *)(pa + 0x3C8) = 0;
                            q->h34 &= ~2;
                            q->h34 &= ~4;
                            if (*(s32 *)(pa + 0x3A4) == -1) {
                                q->h34 &= ~0x41;
                                q->h34 |= q->pclass->h44 & 0x1000;
                                q->w98 = q->pclass->w10;
                                (*(M_3B4698 **)(pa + 0x3EC))->h34 &= ~0x41;
                                (*(M_3B4698 **)(pa + 0x3EC))->h34 |= (*(M_3B4698 **)(pa + 0x3EC))->pclass->h44 & 0x1000;
                                (*(M_3B4698 **)(pa + 0x3EC))->w98 = (*(M_3B4698 **)(pa + 0x3EC))->pclass->w10;
                                (*(M_3B4698 **)(pa + 0x3EC))->h34 &= ~2;
                                (*(M_3B4698 **)(pa + 0x3EC))->h34 &= ~4;
                            }
                        } else if (m && m->state != 0xFE && m->state != 0xFD) {
                            func_L05_0035A568(q, 1);
                            func_003C2880(q);
                        }
                    } else if (q->oclass == 0x1612 && func_L01_0044C108(&q->pos)) {
                        u8 *pb = q->pvar;
                        if (*(s32 *)(pb + 0x33C)) {
                            *(s32 *)(pb + 0x33C) = 0;
                            q->state = 1;
                            q->b95 = 0;
                            q->h34 &= ~0x41;
                            q->h34 |= q->pclass->h44 & 0x1000;
                            q->w98 = q->pclass->w10;
                            (*(M_3B4698 **)(pb + 0x2DC))->h34 &= ~0x41;
                            (*(M_3B4698 **)(pb + 0x2DC))->h34 |= (*(M_3B4698 **)(pb + 0x2DC))->pclass->h44 & 0x1000;
                            (*(M_3B4698 **)(pb + 0x2DC))->w98 = (*(M_3B4698 **)(pb + 0x2DC))->pclass->w10;
                        } else if (m && m->state != 0xFE && m->state != 0xFD) {
                            func_L10_003B8ED0(q, 1);
                            func_003C2880(q);
                        }
                    } else if (q->oclass == 0x1619 && func_L01_0044C108(&q->pos)) {
                        u8 *pc = q->pvar;
                        if (*(s32 *)(pc + 0x958)) {
                            *(s32 *)(pc + 0x958) = 0;
                            q->state = 1;
                            q->b95 = 0;
                            q->h34 &= ~0x41;
                            q->h34 |= q->pclass->h44 & 0x1000;
                            q->w98 = q->pclass->w10;
                        } else if (m && m->state != 0xFE && m->state != 0xFD) {
                            func_L06_0034FCC8(q, 1);
                            func_003C2880(q);
                        }
                    } else if (q->oclass == 0xB && func_L01_0044C108(&q->pos)) {
                        if (*(void **)(q->pvar + 0xC)) {
                            func_003C2880(*(void **)(q->pvar + 0xC));
                        }
                        func_003C2880(q);
                    }
                }
            }
            D_L10_001DE748 = v->h16;
            if (D_L10_001E0860[1] != 0) {
                hud = D_L10_001E0860;
            } else {
                hud = func_003E6C08();
            }
            func_L10_004F8E78(hud, (s32)func_L10_003B57A8);
            if (func_0038CB00(&v->h16)) {
                func_L01_004450F0(m, 2, -1);
                break;
            }
            t = v->h16;
            n = (t + 1) / 50;
            if (t / 50 != n) {
                switch (n) {
                case 10:
                    if (!(D_001A8594[0] & (1 << D_001D545C))) {
                        func_L01_0041A5B0(0xCF8, 0x9F);
                    }
                case 6:
                case 7:
                case 8:
                case 9:
                case 20:
                case 30:
                case 40:
                case 50:
                    func_L01_004AAC98(2, 0x110, m, 0x1C88);
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    func_L01_004AAC98(7 - n, 0x110, m, 0x1C88);
                    break;
                }
            }
        } else if (D_L10_001D6694 == 2) {
            switch (D_L10_001E5F30[0]) {
            case 5:
                func_L01_003B1DB8(m);
                break;
            case 6:
                func_L10_003B5B48(m);
                break;
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(m)) {
            for (q = D_L10_001DF29C; q < D_L10_001DF2A0; q++) {
                if (q->oclass == 0x1C88) {
                    func_L01_00456230(q, 1);
                }
            }
            func_003A1C28();
            func_0013C170();
            func_L10_003B4350(12, 100);
            func_L01_004EDE10();
        }
        break;
    }
}
/* localdecomp:end func_L10_003B4698 */

/* localdecomp:start func_L10_003B5690 */
extern s32 func_00396968(void *, s32);
extern void func_00396E50(s32, s32, s32, s32, s32, s32 *);

void func_L10_003B5690(u8 *a0, s32 color, f32 x0, f32 x1, f32 y0, f32 y1) {
    s32 c[4];
    f32 w = x1 - x0;
    f32 h = y1 - y0;

    c[0] = color;
    c[1] = color;
    c[2] = color;
    c[3] = color;
    func_00396E50(func_00396968(a0 + 0xED1C, 0), (s32)y0, scale_3B5690(x0), (s32)h,
                  scale_3B5690(w), c);
}
/* localdecomp:end func_L10_003B5690 */

/* localdecomp:start func_L10_003B57A8 */
__asm__(".extern D_L10_001DE748, 4");
extern s32 D_L10_001DE748;
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);
extern void func_L10_003B5690(u8 *, s32, f32, f32, f32, f32);

void func_L10_003B57A8(void) {
    s32 t = D_L10_001DE748;
    s32 m;
    s32 fr;
    f32 f;
    f32 x0;
    f32 x1;
    f32 y0;
    f32 y1;
    f32 w;
    f32 g;
    s32 d0;
    s32 d1;
    s32 d2;
    s32 d3;

    m = t / 50;
    fr = (t - m * 50) * 100;
    fr = fr / 50;
    if (m >= 100) {
        m = 99;
    }
    f = 0.0f;
    if (fr > 80) {
        f = (f32)(fr - 80) / 20.0f;
    }
    d0 = m % 10;
    d1 = m / 10 % 10;
    d2 = fr / 10 % 10;
    d3 = fr % 10;
    func_0038C3B0(scale_3B5690(71.0f), scale_3B5690(105.0f), 200, 307, 30, 0);
    func_L01_00436020(0x60, 0x462299DE, (f32)scale_3B5690(71.0f), (f32)scale_3B5690(105.0f), 200.0f, 307.0f);
    y0 = 251.0f;
    y1 = 255.0f;
    func_L10_003B5690((u8 *)0, 0x802020D0, 82.0f, 86.0f, y0, y1);
    func_L10_003B5690((u8 *)0, 0x802020D0, 92.0f, 96.0f, y0, y1);
    g = f + f;
    y1 = 250.0f - f;
    x0 = 75.0f - f * 3.0f;
    x1 = f * 3.0f + 103.0f;
    y0 = (y1 - 22.0f) - g;
    func_L10_003B5690((u8 *)d0, 0x802020D0, x0, x1, y0, y1);
    y1 = (y0 - 2.0f) - f;
    func_L10_003B5690((u8 *)d1, 0x802020D0, x0, x1, (y1 - 22.0f) - g, y1);
    y0 = f + 258.0f;
    y1 = (y0 + 22.0f) + g;
    func_L10_003B5690((u8 *)d2, 0x802020D0, x0, x1, y0, y1);
    y0 = (y1 + 2.0f) + f;
    func_L10_003B5690((u8 *)d3, 0x802020D0, x0, x1, y0, (y0 + 22.0f) + g);
}
/* localdecomp:end func_L10_003B57A8 */

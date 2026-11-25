#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_0034C9F0 */
typedef struct { vu0_v4 a; vu0_v4 b; } G_34C9F0;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3D30(void *, s32, f32, void *);
extern s32 func_003D5630(void);

s32 func_L02_0034C9F0(u8 *self) {
    u8 *d;
    vu0_v4 v, off;
    G_34C9F0 seg;
    f32 h;

    v = *(vu0_v4 *)(self + 0x10);
    d = *(u8 **)(self + 0x68);
    off.x = func_0038D098(*(f32 *)(self + 0xF8));
    off.y = func_0038D0B0(*(f32 *)(self + 0xF8));
    off.z = 0.0f;
    vec_add_ab(&v, &v, &off);
    h = func_003C3D30(&v, 0x20, 2.0f, 0);
    if (!(h < *(f32 *)(self + 0x18))) return 0;
    if (!(*(f32 *)(d + 0x7C) < __builtin_fabsf(h - *(f32 *)(self + 0x18)))) return 0;
    off.x = func_0038D098(*(f32 *)(self + 0xF8)) * 3.5f;
    off.y = func_0038D0B0(*(f32 *)(self + 0xF8)) * 3.5f;
    off.z = 0.0f;
    vec_add_ab(&v, self + 0x10, &off);
    h = func_003C3D30(&v, 0, 1.0f, 0);
    if (*(f32 *)(self + 0x18) - 5.0f < h) {
        seg.a = v;
        seg.b = v;
        seg.b.z = h - 2.0f;
        if (func_003D5630() != 0) goto hit;
    }
    return 2;
hit:
    *(f32 *)(d + 0xA18) = h;
    return 1;
}
/* localdecomp:end func_L02_0034C9F0 */

/* localdecomp:start func_L02_0034CB58 */
typedef struct Vec_34CB58 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_34CB58;

typedef struct Moby_34CB58 Moby_34CB58;

struct Moby_34CB58 {
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ Vec_34CB58 pos;
    /* 0x020 */ u8 b020;
    /* 0x021 */ u8 pad21[3];
    /* 0x024 */ u8 *p024;
    /* 0x028 */ u8 pad28[0x34 - 0x28];
    /* 0x034 */ u16 h034;
    /* 0x036 */ u8 pad36[0x42 - 0x36];
    /* 0x042 */ u8 b042;
    /* 0x043 */ u8 b043;
    /* 0x044 */ u8 pad44[4];
    /* 0x048 */ f32 f048;
    /* 0x04C */ u8 pad4C[0x60 - 0x4C];
    /* 0x060 */ u8 b060;
    /* 0x061 */ u8 pad61[0x68 - 0x61];
    /* 0x068 */ u8 *pv;
    /* 0x06C */ u8 pad6C[0x94 - 0x6C];
    /* 0x094 */ u8 b094;
    /* 0x095 */ u8 b095;
    /* 0x096 */ u16 h096;
    /* 0x098 */ s32 i098;
    /* 0x09C */ u8 pad9C[0xB0 - 0x9C];
    /* 0x0B0 */ u8 bB0;
    /* 0x0B1 */ u8 padB1;
    /* 0x0B2 */ u16 hB2;
    /* 0x0B4 */ u8 padB4[0xBC - 0xB4];
    /* 0x0BC */ u8 bBC;
    /* 0x0BD */ u8 padBD[3];
    /* 0x0C0 */ Vec_34CB58 vC0;
    /* 0x0D0 */ Vec_34CB58 vD0;
    /* 0x0E0 */ u8 padE0[0xF8 - 0xE0];
    /* 0x0F8 */ f32 fF8;
};

typedef struct Pv_34CB58 {
    u8 pad0[0x30];
    /* 0x030 */ f32 f030;
    /* 0x034 */ s16 h034;
    u8 pad36[0xE];
    /* 0x044 */ u8 b044;
    u8 pad45[0x5F];
    /* 0x0A4 */ f32 f0A4;
    u8 padA8[0x68];
    /* 0x110 */ Vec_34CB58 v110;
    /* 0x120 */ s32 i120;
    u8 pad124[0x3C];
    /* 0x160 */ u8 x160[0xC0];
    /* 0x220 */ Vec_34CB58 v220;
    /* 0x230 */ s32 i230;
    /* 0x234 */ s16 h234;
    u8 pad236[0x6E];
    /* 0x2A4 */ f32 f2A4;
    /* 0x2A8 */ f32 f2A8;
    u8 pad2AC[0x20];
    /* 0x2CC */ f32 f2CC;
    /* 0x2D0 */ s32 i2D0;
    u8 pad2D4[0x2];
    /* 0x2D6 */ s16 h2D6;
    /* 0x2D8 */ s32 i2D8;
    u8 pad2DC[0xC];
    /* 0x2E8 */ s32 i2E8;
    /* 0x2EC */ Moby_34CB58* p2EC;
    /* 0x2F0 */ Vec_34CB58 v2F0;
    /* 0x300 */ Vec_34CB58 v300;
    u8 pad310[0x60C];
    /* 0x91C */ s32 i91C;
    /* 0x920 */ s32 i920;
    u8 pad924[0x4];
    /* 0x928 */ s32 i928;
    /* 0x92C */ s32 i92C;
    u8 pad930[0x4];
    /* 0x934 */ s32 i934;
    u8 pad938[0x4];
    /* 0x93C */ s32 i93C;
    /* 0x940 */ u8 x940[0x68];
    /* 0x9A8 */ f32 f9A8;
    u8 pad9AC[0x14];
    /* 0x9C0 */ Vec_34CB58 v9C0;
    u8 pad9D0[0x4];
    /* 0x9D4 */ s32 i9D4;
    /* 0x9D8 */ s32 i9D8;
    u8 pad9DC[0x60];
    /* 0xA3C */ s32 iA3C;
} Pv_34CB58;

typedef struct Hero_34CB58 {
    /* 0x0000 */ u8 pad0[0x80];
    /* 0x0080 */ Vec_34CB58 v80;
    /* 0x0090 */ u8 pad90[0xE0 - 0x90];
    /* 0x00E0 */ f32 fE0;
    /* 0x00E4 */ f32 fE4;
    /* 0x00E8 */ u8 padE8[0x1B8 - 0xE8];
    /* 0x01B8 */ s32 i1B8;
    /* 0x01BC */ u8 pad1BC[0x1DC - 0x1BC];
    /* 0x01DC */ s16 h1DC;
    /* 0x01DE */ u8 pad1DE[0xBDC - 0x1DE];
    /* 0x0BDC */ s16 hBDC;
    /* 0x0BDE */ u8 padBDE[0xC18 - 0xBDE];
    /* 0x0C18 */ f32 fC18;
    /* 0x0C1C */ u8 padC1C[0x1228 - 0xC1C];
    /* 0x1228 */ s32 held;
    /* 0x122C */ u8 pad122C[0x25C0 - 0x122C];
    /* 0x25C0 */ Moby_34CB58 *moby;
    /* 0x25C4 */ s32 state;
    /* 0x25C8 */ u8 pad25C8[0x2808 - 0x25C8];
    /* 0x2808 */ Moby_34CB58 *m2808;
    /* 0x280C */ u8 pad280C[0x2824 - 0x280C];
    /* 0x2824 */ f32 pickup;
    /* 0x2828 */ u8 pad2828[0x2850 - 0x2828];
    /* 0x2850 */ s32 health;
} Hero_34CB58;

typedef struct Ent_34CB58 {
    u8 pad0[4];
    s32 i4;
    u8 pad8[0x2C - 8];
} Ent_34CB58;

typedef struct Rec80_34CB58 {
    u8 pad0[0x30];
    Vec_34CB58 v30;
    u8 pad40[0x30];
    Vec_34CB58 v70;
} Rec80_34CB58;

typedef struct Child_34CB58 {
    Vec_34CB58 v00;
    u8 pad10[4];
    f32 f14;
    u8 pad18[8];
    s32 i20;
    u8 pad24[0x30 - 0x24];
    Vec_34CB58 v30;
} Child_34CB58;

typedef struct Cell_34CB58 {
    u8 pad0[0x144];
    Moby_34CB58 *m144;
    Moby_34CB58 *m148;
} Cell_34CB58;

typedef struct Flags_34CB58 {
    u8 pad0[0x24];
    s32 i24;
    u8 pad28[0x6C - 0x28];
    s32 i6C;
    u8 pad70[6];
    s16 h76;
    u8 pad78[0x94 - 0x78];
    s32 i94;
    s16 h98;
    u8 pad9A[4];
    s16 h9E;
} Flags_34CB58;

extern Hero_34CB58 D_001A4BE0;
extern u8 D_001A4C60[];
extern Vec_34CB58 D_001A4CC0;
extern Ent_34CB58 D_002F3D10[];
extern u8 D_00142BA0[];
extern s32 D_00142668[];
extern u8 D_001426E5[];
extern u8 D_001426E6[];
extern u8 D_001426E7[];
extern u8 D_001BBE90[];
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_001D6690;
extern s32 D_001D6694;
extern s32 D_001D67A0;
extern s32 D_001D67A4;
extern Flags_34CB58 D_001CCFD0;
extern s32 D_L02_001DE4C0[];
extern s32 D_L02_001DE4C0_m;
__asm__(".extern D_L02_001DE4C0_m, 16");
extern s32 D_001DE4C0_sda;
__asm__(".extern D_001DE4C0_sda, 4");
extern s32 D_L02_001DE5C4;
__asm__(".extern D_L02_001DE5C4, 16");
extern s32 D_001DE5C4_sda;
__asm__(".extern D_001DE5C4_sda, 4");
extern s32 D_L02_001DCF78;
__asm__(".extern D_L02_001DCF78, 4");
extern f32 D_L02_001DE2D0;
extern f32 D_001DE2D0_sda;
__asm__(".extern D_001DE2D0_sda, 4");
extern Rec80_34CB58 *D_L02_001DEA80;
extern u8 D_L02_001DE364;
__asm__(".extern D_L02_001DE364, 16");
extern u8 D_L02_001DE365;
__asm__(".extern D_L02_001DE365, 16");
extern u8 D_L02_001DE366;
__asm__(".extern D_L02_001DE366, 16");
extern u8 D_001DE366_sda;
__asm__(".extern D_001DE366_sda, 1");
extern u8 D_L02_001E7E00[];
extern u8 D_L02_001E1300[];

extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_003C2EC0(void *, s32, void *);
extern s32 func_L01_00446780(void *, void *, f32, s32, f32, f32, s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern s32 func_0039EF28();
extern s32 func_0039EC28(s32, s32);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void func_003C2880(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_L01_0041A5B0(s32, s32);
extern void func_L01_0043B510(s32);
extern void func_L01_0044CCC8(s32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00451F60(s32, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_004561E0(void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004BA800(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern s32 func_L01_00513EF0(void);
extern void func_L02_003F4BE8(s32, s32);
extern s32 func_L02_0034F710(u8 *);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CED8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C3D30(void *, s32, f32, void *);
extern void func_L01_004443E8(s32, s32, s32);
extern f32 func_L01_004395E0(void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L02_0034FC40(void *);
extern void func_L02_0034FC88(u8 *);
extern void func_L02_00351838(void);
extern void func_L02_00351950(void *);
extern void func_L02_003519F0(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L02_00350030(void *, s32);
extern s32 func_L01_0045AA30(void *, void *);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_003C41A0(f32 *, f32, void *, f32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L01_00445AD0(s32, s32, s32);

void func_L02_0034CB58(Moby_34CB58 *s) {
    s32 dead;
    Pv_34CB58 *v;
    Vec_34CB58 a;
    Vec_34CB58 b;
    u8 *p;
    u8 *fl;
    u8 r, g, bl;
    Vec_34CB58 c;
    Vec_34CB58 d;
    Vec_34CB58 e;
    Vec_34CB58 f;

    v = (Pv_34CB58 *)s->pv;
    if (func_L02_0034F710((u8 *)s)) {
        func_003C2880(v->p2EC);
        v->p2EC = 0;
        func_003C2880(s);
        return;
    }
    if (v->f030 <= 0.0f) {
        D_001A4BE0.h1DC = 2;
    }
    fl = D_00142BA0;
    if ((*(s32 *)(fl + 0x6C) & 0x2000) && D_001DE4C0_sda < 5) {
        func_003C2880(v->p2EC);
        v->p2EC = 0;
        func_003C2880(s);
        return;
    }
    if (D_001A4BE0.held == 9) {
        D_L02_001DE5C4++;
    } else {
        D_001DE5C4_sda = 0;
    }
    if (s->b095 == 2 && D_L02_001DE5C4 >= 0x5DD) {
        func_L01_0041A5B0(0x13D7, 0x104);
        D_L02_001DE5C4 = 0;
    }
    switch (s->b095) {
    case 0:
        if (func_L01_004561E0(s)) {
            v->h2D6 = (func_00382498(0, 30) * 5 + 2) / 6;
        }
        if (v->f2CC == 0.0f) {
            s->i098 = 0;
            s->h034 = (s->h034 | 0x41) & 0xEFFF;
            func_L01_004AA7E8(s, 1);
            v->p2EC->h034 |= 0x41;
            v->p2EC->h034 &= 0xEFFF;
            v->p2EC->i098 = 0;
            func_L01_004AA7E8(v->p2EC, 1);
            if (!(func_0038CF38(&s->pos, &D_001A4BE0.moby->pos) < 10.0f) && !func_L01_00456500(&D_001A4BE0.v80, v->i93C)) {
            } else if (func_00392B20(D_L02_001E7E00, 0x6B)) {
                func_00392C78(D_L02_001E7E00);
                func_L01_004450F0(s, 3, 5);
                s->i098 = 0;
                s->h034 = (s->h034 | 0x41) & 0xEFFF;
                func_L01_004AA7E8(s, 1);
                v->p2EC->h034 |= 0x41;
                v->p2EC->h034 &= 0xEFFF;
                v->p2EC->i098 = 0;
                func_L01_004AA7E8(v->p2EC, 1);
            }
        }
        if (v->h234 == 1 && func_0038CB00(&v->h2D6)) {
            func_L01_004450F0(s, 0x11, 2);
            if (s->b043 != 0x10) {
                func_003C3A10(s, 0x10, 0, 8);
            }
            break;
        }
        if (v->i2D8 != 0) {
            if (func_0038CB00(&v->h2D6)) {
                func_L01_004450F0(s, 4, 1);
                v->i2D8 = 0;
                if (v->i2D0 < 250) {
                    v->i2D0 = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
                }
            }
        }
        break;
    case 4:
        s->i098 = 0;
        s->h034 = (s->h034 | 0x41) & 0xEFFF;
        func_L01_004AA7E8(s, 1);
        if (!func_L01_004BA800()) {
            a.z = 315.0f;
            a.x = 423.0f;
            a.y = 571.366f;
            b.z = 2.5307274f;
            b.x = 0.0f;
            b.y = 0.0f;
            func_L01_004F50C8(&a, &b, 0, 1);
            if (v->p2EC) {
                func_003C2880(v->p2EC);
                v->p2EC = 0;
            }
            D_001426E7[0] = 1;
            func_0039EF28();
            func_L01_0044CCC8(3);
            func_0039EF28();
            D_001A4BE0.pickup = 2.125f;
            if (s->hB2 & 1) {
                if (((D_001BBE90[((s16)s->hB2 >> 1) + (D_001D545C_sda << 10)] >> 4) & 7) != 7) {
                    D_001BBE90[((s16)s->hB2 >> 1) + (D_001D545C_sda << 10)] += 0x10;
                }
            } else {
                if ((D_001BBE90[((s16)s->hB2 >> 1) + (D_001D545C_sda << 10)] & 7) != 7) {
                    D_001BBE90[((s16)s->hB2 >> 1) + (D_001D545C_sda << 10)] += 1;
                }
            }
            func_L01_0043B510(s->bB0);
            D_001D6694 = 3;
            D_001D6690 = -2;
            func_003A0EC0(6, 2, 1, 3, 0);
            func_003C2880(s);
            return;
        }
        break;
    case 5:
        if (!func_L01_004BA800()) {
            Rec80_34CB58 *rec = (Rec80_34CB58 *)((u8 *)D_L02_001DEA80 + (v->i934 << 7));
            r = D_L02_001DE364;
            g = D_L02_001DE365;
            bl = D_L02_001DE366;
            func_L01_004F50C8(&rec->v30, &rec->v70, 0, 1);
            D_001426E5[0] = 1;
            D_L02_001DE364 = r;
            D_L02_001DE365 = g;
            D_001DE366_sda = bl;
            func_0039EF28();
            func_L01_00451F60(0xC7A, -1, 0);
            if (v->p2EC) {
                func_003C2880(v->p2EC);
                v->p2EC = 0;
            }
            if (s->hB2 & 1) {
                if (((D_001BBE90[((s16)s->hB2 >> 1) + (D_001D545C_sda << 10)] >> 4) & 7) != 7) {
                    D_001BBE90[((s16)s->hB2 >> 1) + (D_001D545C_sda << 10)] += 0x10;
                }
            } else {
                if ((D_001BBE90[((s16)s->hB2 >> 1) + (D_001D545C_sda << 10)] & 7) != 7) {
                    D_001BBE90[((s16)s->hB2 >> 1) + (D_001D545C_sda << 10)] += 1;
                }
            }
            func_L01_0043B510(s->bB0);
            func_003C2880(s);
            return;
        }
        break;
    case 1:
        if (v->h234 == 1) {
            func_L01_004450F0(s, 0xD, 2);
        } else if (v->i2D0 == 0) {
            func_L01_004450F0(s, 3, 0);
        }
        break;
    case 2:
        func_L01_0044E850(s, v->x940, 3, 0.0432f, 0.43200004f);
        func_003C4138(&D_L02_001DE2D0, 0.0f, 0.060000002f);
        if (D_L02_001DCF78 == D_001D67A0 && D_001A4BE0.health <= 0) {
            D_001D67A0 = D_L02_001DCF78 + 1;
        }
        if (v->iA3C != 0 && D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
            v->iA3C = 0;
        }
        if (((Cell_34CB58 *)D_L02_001E1300)->m144 == 0) {
            ((Cell_34CB58 *)D_L02_001E1300)->m144 = s;
            ((Cell_34CB58 *)D_L02_001E1300)->m148 = 0;
        }
        if (v->i920 == 0) {
            if (v->f030 < (f32)v->h034 * 0.6666f) {
                if (s->b020 != 15) {
                    if (s->b020 != 16 && s->b020 != 8 && s->b020 != 5 && s->b020 != 6 && s->b020 != 9 && s->b020 != 7) {
                        v->i920 = 1;
                        func_L01_004450F0(s, 5, -1);
                        if (s->b043 != 8) {
                            func_003C3A10(s, 8, 0, 8);
                        }
                    }
                }
            }
        }
        if (v->i920 == 1) {
            if (v->f030 < (f32)v->h034 * 0.3333f) {
                if (s->b020 != 15) {
                    if (s->b020 != 16 && s->b020 != 8 && s->b020 != 5 && s->b020 != 6 && s->b020 != 9 && s->b020 != 7) {
                        v->i920 = 2;
                        func_L01_004450F0(s, 5, -1);
                        if (s->b043 != 8) {
                            func_003C3A10(s, 8, 0, 8);
                        }
                    }
                }
            }
        }
        break;
    case 7:
        if (D_L02_001DE4C0_m >= 11) {
            D_L02_001DCF78 = D_001D67A0;
            if (D_001D67A0 == 1 && D_001D67A4 == 0) {
                if (!func_L01_00513EF0()) {
                    func_L02_003F4BE8(0xB76, 0xBB8);
                    D_001D67A4 = D_001D67A0;
                }
            } else if (D_001D67A0 - D_001D67A4 >= 2) {
                if (!func_L01_00513EF0()) {
                    func_L02_003F4BE8(0xB76, 0xBB8);
                    D_001D67A4 = D_001D67A0;
                }
            }
        }
        if (v->h234 == 1) {
            u8 *fl2 = D_00142BA0;
            if (!(*(s32 *)(fl2 + 0x6C) & 0x1000) && func_00392B20(D_L02_001E7E00, 0x6C)) {
                func_00392C78(D_L02_001E7E00);
                D_001A4BE0.health = D_00142668[0];
                func_L01_004450F0(s, 3, 8);
                func_0039EC28(0, -1);
            } else {
                func_L01_004450F0(s, 3, 6);
            }
        }
        break;
    case 8:
        if (!func_L01_004BA800()) {
            {
                Rec80_34CB58 *rec = (Rec80_34CB58 *)((u8 *)D_L02_001DEA80 + (v->i934 << 7));
                func_L01_004F50C8(&rec->v30, &rec->v70, 0, 1);
            }
            s->h034 &= 0xFFBE;
            s->h034 |= *(u16 *)(s->p024 + 0x44) & 0x1000;
            s->i098 = *(s32 *)(s->p024 + 0x10);
            D_001426E6[0] = 1;
            func_0039EF28();
            func_L01_004450F0(s, 0x11, 2);
            if (s->b043 != 0x10) {
                func_003C3A10(s, 0x10, 0, 8);
            }
        }
        break;
    case 6: {
        f32 one = 1.0f;
        func_003C4138(&D_L02_001DE2D0, one, 0.040000003f);
        if (D_L02_001DE2D0 == one) {
            D_L02_001DE2D0 = 1.5f;
        }
        if (one <= D_L02_001DE2D0) {
            {
                Rec80_34CB58 *rec = (Rec80_34CB58 *)((u8 *)D_L02_001DEA80 + (v->i934 << 7));
                func_L01_004F50C8(&rec->v30, &rec->v70, 0, 1);
            }
            s->h034 &= 0xFFBE;
            s->h034 |= *(u16 *)(s->p024 + 0x44) & 0x1000;
            s->i098 = *(s32 *)(s->p024 + 0x10);
            D_001426E6[0] = 1;
            func_0039EF28();
            func_L01_004450F0(s, 0x11, 2);
            if (s->b043 != 0x10) {
                func_003C3A10(s, 0x10, 0, 8);
            }
        }
        break;
    }
    case 3: {
        s32 flags;
        f32 h;
        if (v->f030 <= 0.0f) {
            func_L01_004561E0(s);
            if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
                dead = 1;
            } else {
                dead = 2;
            }
        }
        if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
            v->iA3C = 0;
        }
        flags = func_L01_00454370(s, v->x160);
        h = func_003C3D30(&s->pos, 2, 0.5f, 0);
        if (s->pos.z != h) {
            s->pos.z = s->pos.z - 0.19600002f;
            if (s->pos.z < h) {
                s->pos.z = h;
            }
        }
        if (v->f030 <= 0.0f) {
            D_001A4BE0.pickup = 50.0f;
        }
        if (v->f030 <= 0.0f && (s->b060 & 2) && D_001A4BE0.health > 0 && D_001A4BE0.state != 0x6A && D_001A4BE0.state != 0x7D && D_001A4BE0.state != 0x7E) {
            if (func_00392B20(D_L02_001E7E00, 0x6D)) {
                func_00392B20(D_L02_001E7E00, 0x6E);
                func_00392C78(D_L02_001E7E00);
                func_L01_004443E8((s32)s, 0, 3);
                func_L01_004450F0(s, 3, 4);
                s->f048 = 0.0f;
            }
            func_L02_0034FC40(s);
            return;
        }
        if (flags & 2) {
            if (0.0f < v->f030) {
                func_L01_004450F0(s, 0x11, 2);
                if (s->b043 != 0x10) {
                    func_003C3A10(s, 0x10, 0, 8);
                }
            }
        }
        break;
    }
    }
    switch (s->b020) {
    case 2:
        if (func_L01_004561B8(s)) {
            func_L01_0045BD78(s, 0.07000001f, 0.07000001f, 0.010053097f, 0.25132743f);
        }
        {
            f32 f = func_L01_004395E0(s);
            if (18.0f < f) {
                if (f < 28.0f) {
                    a = s->vC0;
                    func_0038CF68(&a, &a, 3.0f);
                    vec_add_ab(&a, &a, &s->pos);
                    func_L01_0045A748(s, &a);
                }
            }
        }
        if (s->b060 & 2) {
            s->pos = v->v300;
        }
        break;
    case 3: {
        f32 k1 = 0.02f;
        f32 k2 = 0.3f;
        f32 ang, pit;
        u8 *hp;
        s32 on = 0;
        if (s->b043 == 12) {
            on = 1;
            hp = D_001A4C60;
            if (func_0038CF38(&s->pos, hp) < 8.0f) {
                Hero_34CB58 *hr = (Hero_34CB58 *)(hp - 0x80);
                ang = func_0038DBA0(s->fF8, func_0038D160(hr->fE0 - s->pos.x, hr->fE4 - s->pos.y));
                if (ang < 1.5707964f) {
                    if (0.01f < func_0038CEA8(hp + 0x90)) {
                        v->i9D4 = 100;
                    } else {
                        func_0038CAD0(&v->i9D4);
                    }
                } else if (v->i9D4 != 0) {
                    v->i9D4 = 0;
                    v->v9C0 = D_001A4CC0;
                }
            } else if (v->i9D4 != 0) {
                v->i9D4 = 0;
                v->v9C0 = D_001A4CC0;
            }
            if (func_0038CAD0(&v->i9D8)) {
                v->i9D8 = (s32)((func_003824E0(90.0f, 120.0f) * 5.0f + 2.0f) / 6.0f);
                ang = func_0038DAB8(s->fF8, func_003824E0(-90.0f, 90.0f) * 0.017453292f);
                pit = func_003824E0(0.0f, 30.0f) * 0.017453292f;
                func_00382760(&v->v9C0, 6.0f, ang, pit);
                vec_add_ab(&v->v9C0, &v->v9C0, &s->pos);
            }
            if (v->i9D4 != 0) {
                k1 = 0.04f;
                k2 = 0.3f;
                a = D_001A4CC0;
            } else {
                a = v->v9C0;
            }
        }
        if (on) {
            b = s->pos;
            b.z += 2.0f;
            vec_sub_ab(&c, &a, &b);
            ang = func_0038DB00(func_0038D160(c.x, c.y), s->fF8);
            pit = -func_0038D160(func_0038CED8(&c), c.z);
            if (1.5707964f < ang) {
                ang = 1.5707964f;
            } else if (ang < -1.5707964f) {
                ang = -1.5707964f;
            }
            if (0.5235988f < pit) {
                pit = 0.5235988f;
            } else if (pit < -0.5235988f) {
                pit = -0.5235988f;
            }
            v->f2A4 = pit;
            v->f2A8 = ang * 0.6f;
            v->f9A8 = ang * 0.4f;
            func_L01_0044E850(s, v->x940, 3, k1 * 1.44f, k2 * 1.44f);
        }
        break;
    }
    case 5: {
        Rec80_34CB58 *rec;
        if (func_L01_004561B8(s)) {
            v->f0A4 = 0.1f;
            func_L01_0045BD78(s, 0.0064000003f, 0.12000000476837158f, 0.010053097f, 0.25132743f);
        }
        rec = (Rec80_34CB58 *)((u8 *)D_L02_001DEA80 + (v->i91C << 7));
        func_L01_0045A748(s, &rec->v30);
        if (func_0038CF38(&s->pos, &rec->v30) <= v->f0A4) {
            v->f0A4 = 0.5f;
            func_L02_00350030(s, v->i920);
            func_L01_004450F0(s, 6, -1);
            if (s->b043 != 2) {
                func_003C3A10(s, 2, 0, 8);
            }
            func_L01_0045BD78(s, 0.0064000003f, 0.12000000476837158f, 0.030997047f, 0.94945914f);
        }
        break;
    }
    case 6:
        if (func_L01_004561B8(s)) {
            v->v2F0 = s->pos;
        }
        if (s->b042 == 2) {
            f32 d = func_L01_004395E0(s);
            a = s->pos;
            if (6.0f < d && d < 15.0f) {
                func_003C41A0(&a.z, v->v2F0.z + 2.5f, &v->i2E8, 0.8333334f, 0.8333334f, 1.1111112f);
                vec_sub_ab(&b, &a, &s->pos);
                func_L01_0045AA30(s, &b);
                func_L01_0045BD10(s, ((Rec80_34CB58 *)((u8 *)D_L02_001DEA80 + (v->i91C << 7)))->v70.z);
            }
            if (func_L01_0044E1B8(s, 22.0f)) {
                v->i2E8 = 0;
                if (s->b043 != 4) {
                    func_003C3A10(s, 4, 5, 5);
                }
                func_L01_004450F0(s, 7, -1);
            }
        }
        break;
    case 7:
        if (s->b060 & 2) {
            func_L01_004450F0(s, 8, -1);
            if (s->b043 != 3) {
                func_003C3A10(s, 3, 0, 2);
            }
        }
        break;
    case 8:
        if (!func_L01_00445AD0(v->i92C, -1, 0) || s->h096 >= 0x12D) {
            func_L01_004450F0(s, 9, -1);
            if (s->b043 != 5) {
                func_003C3A10(s, 5, 0, 2);
            }
        }
        break;
    case 9:
        if (s->b042 == 5) {
            f32 d = func_L01_004395E0(s);
            f32 t;
            Vec_34CB58 *pp = &s->pos;
            a = *pp;
            if (0.0f < d && d < 5.0f) {
                f32 *pz = &a.z;
                t = func_003C3D30(pp, 0, 0.5f, 0);
                func_003C41A0(pz, t, &v->i2E8, 0.125f, 0.25f, 0.5f);
                vec_sub_ab(&b, &a, &s->pos);
                func_L01_0045AA30(s, &b);
            }
            if (s->b060 & 2) {
                func_L01_004450F0(s, 0xD, -1);
                if (s->b043 != 8) {
                    func_003C3A10(s, 8, 0, 8);
                }
            }
        }
        break;
    case 10:
        if (s->b042 == 10) {
            f32 dist = func_L01_004395E0(s);
            a = s->pos;
            if (5.0f < dist && dist < 14.0f) {
                b = D_001A4BE0.moby->vD0;
                func_0038CF68(&b, &b, 0.19444445f);
                vec_add_ba(&a, &a, &b);
                func_0038CF68(&c, &D_001A4BE0.moby->vC0, 0.13888889f);
                vec_add_ba(&a, &a, &c);
                vec_sub_ba(&d, &a, &s->pos);
                func_L01_0045AA30(s, &d);
            }
            if (func_L01_0044E1B8(s, 16.0f)) {
                if (s->b043 != 9) {
                    func_003C3A10(s, 9, 0, 8);
                }
                func_L01_004450F0(s, 0xE, -1);
            }
        }
        break;
    case 11:
        if (s->b042 == 11) {
            f32 dist = func_L01_004395E0(s);
            a = s->pos;
            if (5.0f < dist && dist < 14.0f) {
                b = D_001A4BE0.moby->vD0;
                func_0038CF68(&b, &b, -0.16666667f);
                vec_add_ba(&a, &a, &b);
                func_0038CF68(&c, &D_001A4BE0.moby->vC0, 0.13888889f);
                vec_add_ba(&a, &a, &c);
                vec_sub_ba(&d, &a, &s->pos);
                func_L01_0045AA30(s, &d);
            }
            if (func_L01_0044E1B8(s, 15.0f)) {
                if (s->b043 != 9) {
                    func_003C3A10(s, 9, 0, 8);
                }
                func_L01_004450F0(s, 0xE, -1);
            }
        }
        break;
    case 12:
        if (s->b042 == 11) {
            f32 dist = func_L01_004395E0(s);
            a = s->pos;
            if (5.0f < dist && dist < 14.0f) {
                b = D_001A4BE0.moby->vD0;
                func_0038CF68(&b, &b, -0.16666667f);
                vec_add_ba(&a, &a, &b);
                func_0038CF68(&c, &D_001A4BE0.moby->vC0, 0.13888889f);
                vec_add_ba(&a, &a, &c);
                vec_sub_ba(&d, &a, &s->pos);
                func_L01_0045AA30(s, &d);
                func_L01_0045BD10(s, func_0038D160(v->v220.x - s->pos.x, v->v220.y - s->pos.y));
            }
            if (func_L01_0044E1B8(s, 15.0f)) {
                if (s->b043 != 9) {
                    func_003C3A10(s, 9, 0, 8);
                }
                func_L01_004450F0(s, 0xE, -1);
            }
        }
        break;
    case 20:
        if (func_L01_004561B8(s)) {
            v->v2F0 = s->pos;
        }
        if (s->b042 == 2) {
            f32 d = func_L01_004395E0(s);
            a = s->pos;
            if (6.0f < d && d < 15.0f) {
                func_003C41A0(&a.z, v->v2F0.z + 2.5f, &v->i2E8, 0.8333334f, 0.8333334f, 1.1111112f);
                vec_sub_ab(&b, &a, &s->pos);
                func_L01_0045AA30(s, &b);
            }
            if (func_L01_0044E1B8(s, 15.0f)) {
                v->i2E8 = 0;
                if (s->b043 != 5) {
                    func_003C3A10(s, 5, 0, 0);
                }
                func_L01_004450F0(s, 9, -1);
            }
        }
        break;
    case 13:
        if (func_L01_004561B8(s)) {
            v->i120 = 0;
            qzero(&v->v110);
            func_L01_0045BD78(s, 0.0064000003f, 0.12000000476837158f, 0.010053097f, 0.25132743f);
        }
        func_L01_0045A748(s, &v->v220);
        if (func_0038CF38(&s->pos, &v->v220) < 4.0f) {
            if (func_0038DBA0(s->fF8, func_0038D160(v->v220.x - s->pos.x, v->v220.y - s->pos.y)) < 0.17453292f) {
                func_L01_004450F0(s, 0xF, -1);
                if (s->b043 != 0xE) {
                    func_003C3A10(s, 0xE, 3, 5);
                }
            }
        }
        if (fabs_asm((f32)v->i928 - v->f030) > 6.0f && v->i920 != 0) {
            if (func_0038DBA0(s->fF8, func_0038D160(v->v220.x - s->pos.x, v->v220.y - s->pos.y)) < 0.43633232f) {
                func_L01_004450F0(s, 0x11, -1);
                if (s->b043 != 0x10) {
                    func_003C3A10(s, 0x10, 0, 5);
                }
            }
        }
        if (v->i920 == 2) {
            if (func_0038CF38(&s->pos, &v->v220) < 13.0f) {
                if (func_0038DBA0(s->fF8, func_0038D160(v->v220.x - s->pos.x, v->v220.y - s->pos.y)) < 0.43633232f) {
                    func_L01_004450F0(s, 0x11, -1);
                    if (s->b043 != 0x10) {
                        func_003C3A10(s, 0x10, 0, 5);
                    }
                }
            }
        }
        break;
    case 14:
        if (func_L01_004561B8(s)) {
            qzero(&v->v110);
            v->i120 = 0;
            v->i928 = (s32)v->f030;
            func_L01_0045BD78(s, 0.0032000002f, 0.060000002f, 0.010053097f, 0.25132743f);
        }
        if (4.25f <= func_0038CF38(&s->pos, &v->v220)) {
            func_L01_0045A748(s, &v->v220);
        } else {
            func_L01_0045BD10(s, func_0038D160(v->v220.x - s->pos.x, v->v220.y - s->pos.y));
        }
        if (func_0038CF38(&s->pos, &v->v220) < 4.25f) {
            if (func_0038DBA0(s->fF8, func_0038D160(v->v220.x - s->pos.x, v->v220.y - s->pos.y)) < 0.17453292f) {
                func_L01_004450F0(s, 0xF, -1);
                if (s->b043 != 0xE) {
                    func_003C3A10(s, 0xE, 3, 5);
                }
            }
        }
        if (8.0f < func_0038CF38(&s->pos, &v->v220)) {
            func_L01_004450F0(s, 0xD, -1);
            if (s->b043 != 8) {
                func_003C3A10(s, 8, 0, 8);
            }
        }
        if (3.0f < fabs_asm((f32)v->i928 - v->f030)) {
            func_L01_004450F0(s, 0xD, -1);
            if (s->b043 != 8) {
                func_003C3A10(s, 8, 0, 5);
            }
        }
        if (s->b094 >= 0xA && s->b094 <= 0xC) {
            if (v->i920 == 2) {
                if (D_001A4BE0.state != 0x13 || 4.5f < func_0038CF38(&s->pos, &v->v220) ||
                    func_0038DBA0(D_001A4BE0.moby->fF8, func_0038D160(s->pos.x - D_001A4BE0.moby->pos.x, s->pos.y - D_001A4BE0.moby->pos.y)) < 0.43633232f) {
                    func_L01_004450F0(s, 0x11, -1);
                    if (s->b043 != 0x10) {
                        func_003C3A10(s, 0x10, 0, 5);
                    }
                }
            }
        }
        if (v->i920 != 0) {
            if (D_001A4BE0.state == 0x13) {
                if (func_0038CF38(&s->pos, &v->v220) < 4.5f) {
                    if (func_0038DBA0(D_001A4BE0.moby->fF8, func_0038D160(s->pos.x - D_001A4BE0.moby->pos.x, s->pos.y - D_001A4BE0.moby->pos.y)) < 0.43633232f) {
                        Ent_34CB58 *e = &D_002F3D10[D_001A4BE0.hBDC];
                        if (e->i4 == 0 && s->b094 != 0xB) {
                            if (s->b043 != 0xB) {
                                func_003C3A10(s, 0xB, 4, 2);
                            }
                            func_L01_004450F0(s, 0xB, -1);
                        } else if (e->i4 == 1 && D_001A4BE0.fC18 < 13.0f) {
                            if (s->b043 != 0xA) {
                                func_003C3A10(s, 0xA, 4, 2);
                            }
                            func_L01_004450F0(s, 0xA, -1);
                        } else if (e->i4 == 2 && D_001A4BE0.fC18 < 8.0f) {
                            if (s->b043 != 0xB) {
                                func_003C3A10(s, 0xB, 4, 2);
                            }
                            func_L01_004450F0(s, 0xC, -1);
                        }
                    }
                }
            }
            if ((D_001A4BE0.state == 0x14 && func_0038CF38(&s->pos, &v->v220) < 4.5f) || D_001A4BE0.state == 0x15) {
                if (func_0038DBA0(D_001A4BE0.moby->fF8, func_0038D160(s->pos.x - D_001A4BE0.moby->pos.x, s->pos.y - D_001A4BE0.moby->pos.y)) < 0.43633232f) {
                    if (D_001A4BE0.i1B8 >= 11) {
                        if (D_001A4BE0.i1B8 < 30) {
                            if (s->b043 != 0xB) {
                                func_003C3A10(s, 0xB, 4, 2);
                            }
                            func_L01_004450F0(s, 0xB, -1);
                        }
                    }
                }
            }
        }
        break;
    case 15: {
        f32 dist;
        if (func_L01_004561B8(s)) {
            func_L01_0045BD78(s, 0.060000002f, 0.060000002f, 0.010053097f, 0.25132743f);
        }
        dist = func_L01_004395E0(s);
        if (18.0f < dist && dist < 40.0f) {
            a = s->vC0;
            func_0038CF68(&a, &a, 3.0f);
            vec_add_ab(&a, &a, &s->pos);
            func_L01_0045A748(s, &a);
        }
        if ((21.0f < dist && dist < 28.0f) || (42.0f < dist && dist < 50.0f)) {
            func_003C2EC0(s, 0, &a);
            func_L01_00446780(s, &d, 0.5f, 1, (f32)v->b044, 2.5f, 0, 1, 0);
            f = a;
            vec_add_ab(&e, &f, &d);
            func_L01_00446780(s, &e, 0.5f, 1, (f32)v->b044, 2.5f, 0, 1, 0);
        }
        if (v->i920 != 0) {
            if (D_001A4BE0.state == 0x13 && (dist < 20.0f || s->b042 != 0xE) &&
                func_0038CF38(&s->pos, &D_001A4BE0.v80) < 4.5f &&
                func_0038DBA0(D_001A4BE0.moby->fF8, func_0038D160(s->pos.x - D_001A4BE0.moby->pos.x, s->pos.y - D_001A4BE0.moby->pos.y)) < 0.43633232f) {
                Ent_34CB58 *en = &D_002F3D10[D_001A4BE0.hBDC];
                if (en->i4 != 1 && en->i4 != 2) {
                    if (s->b043 != 0xB) {
                        func_003C3A10(s, 0xB, 5, 2);
                    }
                    func_L01_004450F0(s, 0xB, -1);
                }
            } else if ((dist < 20.0f || s->b042 != 0xE) &&
                       ((D_001A4BE0.state == 0x14 && func_0038CF38(&s->pos, &v->v220) < 4.5f) || D_001A4BE0.state == 0x15)) {
                if (func_0038DBA0(D_001A4BE0.moby->fF8, func_0038D160(s->pos.x - D_001A4BE0.moby->pos.x, s->pos.y - D_001A4BE0.moby->pos.y)) < 0.43633232f) {
                    if (D_001A4BE0.i1B8 >= 11) {
                        if (D_001A4BE0.i1B8 < 30) {
                            if (s->b043 != 0xB) {
                                func_003C3A10(s, 0xB, 4, 2);
                            }
                            func_L01_004450F0(s, 0xB, -1);
                        }
                    }
                }
            }
        }
        if (func_L01_0044E1B8(s, 50.0f)) {
            s32 r;
            if (s->b043 != 9) {
                func_003C3A10(s, 9, 0, 8);
            }
            func_L01_004450F0(s, 0xE, -1);
            if (D_001A4BE0.m2808 == s || func_00382468(3) == 0) {
                func_L01_004450F0(s, 0x15, -1);
                if (s->b043 != 0xD) {
                    func_003C3A10(s, 0xD, 0, 8);
                }
            }
            if (D_001A4BE0.m2808 == s) {
                r = func_00382468(6);
                if (D_001CCFD0.i6C == 0 && D_001CCFD0.i24 == -1 && D_001CCFD0.i94 == 0) {
                    if (r == 0) {
                        v->iA3C = 1;
                    } else {
                        v->iA3C = 1;
                    }
                }
            }
        }
        break;
    }
    case 16: {
        f32 dist;
        if (func_L01_004561B8(s)) {
            func_L01_0045BD78(s, 0.07000001f, 0.07000001f, 0.010053097f, 0.25132743f);
        }
        dist = func_L01_004395E0(s);
        if (18.0f < dist && dist < 28.0f) {
            a = s->vC0;
            func_0038CF68(&a, &a, 3.0f);
            vec_add_ab(&a, &a, &s->pos);
            func_L01_0045A748(s, &a);
        }
        if (21.0f < dist && dist < 28.0f) {
            func_003C2EC0(s, 0, &a);
            func_L01_00446780(s, &d, 0.5f, 1, (f32)v->b044, 2.0f, 0, 1, 0);
            f = a;
            vec_add_ab(&e, &f, &d);
            func_L01_00446780(s, &e, 0.5f, 1, (f32)v->b044, 2.0f, 0, 1, 0);
        }
        if (s->b060 & 2) {
            if (s->b043 != 9) {
                func_003C3A10(s, 9, 0, 8);
            }
            func_L01_004450F0(s, 0xE, -1);
            if (D_001A4BE0.m2808 == s || func_00382468(3) == 0) {
                func_L01_004450F0(s, 0x15, -1);
                if (s->b043 != 0xD) {
                    func_003C3A10(s, 0xD, 0, 8);
                }
            }
        }
        break;
    }
    case 21:
        if (s->b060 & 2) {
            func_L01_004450F0(s, 0xE, -1);
            if (s->b043 != 9) {
                func_003C3A10(s, 9, 0, 8);
            }
        }
        if (v->i920 != 0) {
            if (D_001A4BE0.state == 0x13) {
                if (func_0038CF38(&s->pos, &v->v220) < 4.5f) {
                    if (func_0038DBA0(D_001A4BE0.moby->fF8, func_0038D160(s->pos.x - D_001A4BE0.moby->pos.x, s->pos.y - D_001A4BE0.moby->pos.y)) < 0.43633232f) {
                        Ent_34CB58 *e = &D_002F3D10[D_001A4BE0.hBDC];
                        if (e->i4 == 0 && s->b094 != 0xB) {
                            if (s->b043 != 0xB) {
                                func_003C3A10(s, 0xB, 4, 2);
                            }
                            func_L01_004450F0(s, 0xB, -1);
                        } else if (e->i4 == 1 && D_001A4BE0.fC18 < 13.0f) {
                            if (s->b043 != 0xA) {
                                func_003C3A10(s, 0xA, 4, 2);
                            }
                            func_L01_004450F0(s, 0xA, -1);
                        } else if (e->i4 == 2 && D_001A4BE0.fC18 < 8.0f) {
                            if (s->b043 != 0xB) {
                                func_003C3A10(s, 0xB, 4, 2);
                            }
                            func_L01_004450F0(s, 0xC, -1);
                        }
                    }
                }
            }
            if ((D_001A4BE0.state == 0x14 && func_0038CF38(&s->pos, &v->v220) < 4.5f) || D_001A4BE0.state == 0x15) {
                if (func_0038DBA0(D_001A4BE0.moby->fF8, func_0038D160(s->pos.x - D_001A4BE0.moby->pos.x, s->pos.y - D_001A4BE0.moby->pos.y)) < 0.43633232f) {
                    if (D_001A4BE0.i1B8 >= 11) {
                        if (D_001A4BE0.i1B8 < 30) {
                            if (s->b043 != 0xB) {
                                func_003C3A10(s, 0xB, 4, 2);
                            }
                            func_L01_004450F0(s, 0xB, -1);
                        }
                    }
                }
            }
        }
        break;
    case 17:
        if (func_L01_0044E1B8(s, 16.0f)) {
            if (s->b042 == 0x10) {
                Child_34CB58 *ch = (Child_34CB58 *)v->p2EC->pv;
                s->bBC = 1;
                v->p2EC->b020 = 0;
                func_003C2EC0(s, 0, &a);
                ch->f14 = 0.06f;
                if (func_0038CF38(&s->pos, &v->v220) < 6.0f) {
                    ch->f14 = 0.32f;
                }
                ch->v00 = a;
                ch->v30 = v->v220;
                ch->i20 = v->i230;
                func_0038CF68(ch, ch, -1.0f);
                func_0038CF68(ch, ch, 0.70000005f);
                v->p2EC->h034 &= 0xFFFD;
                v->p2EC->h034 &= 0xFFFB;
            }
        }
        if (func_L01_0044E1B8(s, 23.0f)) {
            if (s->b043 != 0x11) {
                func_003C3A10(s, 0x11, 0, 8);
            }
            func_L01_004450F0(s, 0x12, -1);
        }
        if (func_L01_004561B8(s)) {
            if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
                dead = 1;
            } else {
                dead = 2;
            }
        }
        if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
            break;
        }
        break;
    case 18:
        if (s->bBC == 0) {
            func_L01_004450F0(s, 0x13, -1);
            if (s->b043 != 0x12) {
                func_003C3A10(s, 0x12, 0, 2);
            }
            v->p2EC->h034 |= 2;
        }
        break;
    case 19:
        func_L02_00351950(v->p2EC);
        func_L01_00404808(func_L02_00351838, v->p2EC);
        func_L01_0044FD88(s, (s32)v->p2EC, 0, 0);
        if (s->b060 & 2) {
            func_L01_004450F0(s, 0xE, -1);
            if (s->b043 != 9) {
                func_003C3A10(s, 9, 0, 7);
            }
            func_L02_003519F0(v->p2EC);
        }
        break;
    }
    func_L02_0034FC88((u8 *)s);
}
/* localdecomp:end func_L02_0034CB58 */

/* localdecomp:start func_L02_0034F710 */
typedef struct { u8 p0[0x24]; s32 f24; u8 p1[0x44]; s32 f6C; u8 p2[0x24]; s32 f94; } S_34F710;
extern s32 func_L02_0034F958(void *);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L02_0034FC40(void *);
extern s32 *func_L01_00447490(void *, s32, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_00382468(s32);
extern void func_L02_0034FD58(void *);
extern s32 func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L02_003FB148(s32, s32, f32);
extern S_34F710 D_001CCFD0_34F710;
__asm__(".extern D_001CCFD0_34F710, 16");

s32 func_L02_0034F710(u8 *a0)
{
    u8 *p;
    s32 *q;
    s32 v;

    p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        if (func_L02_0034F958(a0) != 0) return 1;
    }
    if (*(s32 *)(p + 0x938) != 0) func_L01_0044FD88(a0, *(s32 *)(p + 0x938), 2, 0);
    if (p[0x3E] == 2) {
        func_L02_0034FC40(a0);
        return 1;
    }
    if (*(s32 *)(p + 0x2EC) != 0 && a0[0xBC] == 0) func_L01_0044FD88(a0, *(s32 *)(p + 0x2EC), 0, 0);
    q = func_L01_00447490(a0, 0x10000, 0);
    if (q != 0 && *(u8 **)((u8 *)q + 0x20) != 0) {
        s32 h = *(s16 *)(*(u8 **)((u8 *)q + 0x20) + 0xAA);
        if (h == 0x18BE || h == 0x184F) {
            *(f32 *)((u8 *)q + 0x2C) *= 0.75f;
        }
    }
    if (*(f32 *)(p + 0x2CC) > 0.0f) {
        if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) {
            if (*(s32 *)(p + 0x21C) == 0) *(s32 *)(p + 0x21C) = 100;
            if (*(s32 *)(p + 0xA3C) == 0 && D_001CCFD0_34F710.f6C == 0 && D_001CCFD0_34F710.f24 == -1
                && D_001CCFD0_34F710.f94 == 0 && *(f32 *)(p + 0x30) > 0.0f) {
                func_00382468(4);
                *(s32 *)(p + 0xA3C) = 1;
            }
            func_L02_0034FD58(a0);
        }
    }
    func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
    if ((u8)(a0[0x95] - 2) < 2) {
        v = (s32)*(f32 *)(p + 0x30);
        if (v < 0) v = 0;
        func_L02_003FB148(10, 0, (f32)v / (f32)*(s16 *)(p + 0x34));
    }
    return 0;
}
/* localdecomp:end func_L02_0034F710 */

/* localdecomp:start func_L02_0034F958 */
extern void func_L01_00456160(s32, void *);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L02_0034FE10(void *);
extern s32 func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
typedef struct { u8 pad[0x464]; u8 spent[1]; } S_34F958;
extern S_34F958 D_L02_00234840;
__asm__(".extern D_L02_00234840, 16");
__asm__(".extern D_001BBE90, 16");
extern s32 D_001D545C;

s32 func_L02_0034F958(void *self)
{
    u8 *a0 = self;
    u8 *p;
    s32 v;
    s32 id;
    s32 one;

    p = *(u8 **)(a0 + 0x68);
    *(vu0_q *)(p + 0x300) = *(vu0_q *)(a0 + 0x10);
    *(s32 *)(p + 0x920) = 0;
    a0[0x30] = 0xFF;
    if (*(s32 *)(p + 0x938) != 0) {
        func_L01_00456160(*(s32 *)(p + 0x938), a0);
        *(u16 *)(*(u8 **)(p + 0x938) + 0x32) = *(u16 *)(a0 + 0x32);
    }
    p[0x1DB] = 0xFF;
    p[0x1A8] = 3;
    p[0x176] = 0;
    p[0x1D8] = 0;
    p[0x1D9] = 0;
    p[0x1DA] = 0;
    p[0x171] = 1;
    p[0x172] = 1;
    *(f32 *)(p + 0x19C) = 0.15f;
    p[0x1D7] = 1;
    one = 1;
    *(s32 *)(p + 0x218) = one;
    *(s32 *)(p + 0x74) = 0;
    *(f32 *)(p + 0x1B8) = 0.01f;
    *(s32 *)(p + 0x1DC) = *(s32 *)(p + 0x924);
    *(f32 *)(p + 0x70) = 1.5f;
    p[0x170] = 0x17;
    *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x194) = 0.5f;
    *(f32 *)(p + 0x78) = 0.5f;
    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x80) = 1.4835298f;
    *(f32 *)(p + 0xA0) = 0.34906584f;
    *(f32 *)(p + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, 0.0032000002f, 0.060000002f, 0.010053097f, 0.25132743f);
    *(s32 *)(p + 0xAC) = *(s32 *)(p + 0x924);
    func_L02_0034FE10(a0);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 100;
        *(f32 *)(p + 0x30) = 100.0f;
    }
    p[0x39] = one;
    p[0x3E] = 3;
    p[0x3F] = 0;
    *(f32 *)(p + 0x40) = 2.0f;
    *(s32 *)(p + 0x2EC) = func_003C24B0(0x1743, 0x80);
    func_L01_00456160(*(s32 *)(p + 0x2EC), a0);
    *(u8 **)(*(u8 **)(p + 0x2EC) + 0xB8) = a0;
    func_L01_0044FD88(a0, *(s32 *)(p + 0x2EC), 0, 0);
    func_L01_004450F0(a0, 3, 0);
    if (a0[0x43] != 0xC) func_003C3A10(a0, 0xC, 0, 0);
    if (*(s32 *)(p + 0x2C0) != -1) {
        func_L01_004450F0(a0, 0x16, 7);
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a0, 1);
    }
    id = *(u16 *)(a0 + 0xB2);
    if (D_L02_00234840.spent[(s16)id] == 0) {
        v = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
        if (id & 1) {
            if (((v >> 4) & 7) == 0) return 0;
        } else {
            if ((v & 7) == 0) goto fail;
        }
    }
    return 1;
fail:
    return 0;
}
/* localdecomp:end func_L02_0034F958 */

/* localdecomp:start func_L02_0034FC40 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00315900(s32, s32, s32);

void func_L02_0034FC40(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004443E8((s32) arg0, 0, 3);
    func_L01_00315900((*(s32 *)((u8 *)temp_s0 + 0x2EC)), 0, 0);
    *(s32 *)((u8 *)temp_s0 + 0x2EC) = 0;
}
/* localdecomp:end func_L02_0034FC40 */

/* localdecomp:start func_L02_0034FC88 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L02_00350200(void *, s32);
extern u8 D_L02_001E1300[];

void func_L02_0034FC88(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 value;

    func_0038CAD0(p + 0x2D0);
    func_0038CB00(p + 0x2D4);
    value = *(u16 *)(a0 + 0x96);
    if (value <= 0xFFFEu) {
        *(u16 *)(a0 + 0x96) = value + 1;
    }
    func_L01_00451DF8(a0, p + 0x240, 2, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L02_001E1300, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
    if (a0[0x20] != 3) {
        func_L02_00350200(a0, 1);
    }
}
/* localdecomp:end func_L02_0034FC88 */

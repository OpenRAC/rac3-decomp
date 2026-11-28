/* func_L01_00386B38 (Claude wave 14 r70, 2026-11-28). First draft kept here. */
/* func_L01_00386B38 (5988 B, 34 places): first PAL draft (wave 14 r70), written from the retail assembly
 * (no draft or functional C existed): the Shock Cannon style charge/fire handler. 1498 diff (wave10/p10
 * check, level 01, the file's flags): the control flow, calls, arguments and constants follow retail in
 * order (charge build-up particles, the full-charge burst, the release beam with its 20 ray points, the
 * timers, the hit sweep of 23 + 3 rays with the saved/restored moby words), but the frame is 0x260 where
 * retail has 0x210, so every stack offset and register after the prologue shifts.
 * Retail shares stack slots between the paths' locals: a hit record at 0x00 (the sweep's), another at
 * 0x20 (the release beam's), vectors at 0x10/0x30/0x40/0x50/0x60/0x70/0x140/0x150, the moby list at 0x80
 * and the saved words at 0xE0, spills from 0x160; block-scoped locals per path are the next lever.
 * The gp-relative forms retail has for D_001D52FC, D_L01_001E1EA4, D_L01_001E1EA0, D_L01_001E1F00,
 * D_001D545C and D_L01_001D7BE0 are all in delay slots: Ps2EeAs's expansion of the same unhinted
 * macro, so one plain extern each.
 * Declarations to settle before landing: func_L01_003882A0 is declared here as u8 *(void *, void *, void *,
 * void *, f32) (its definition later in the file returns Moby_003882A0 * with Vec_003882A0 * parameters,
 * types that are defined after this function); func_L01_00388EE0 and func_L01_00389798 are declared
 * without a prototype for the same reason. */
#include "common.h"

/* localdecomp:start func_L01_00386B38 */
#include "vu0.h"
typedef struct {
    f32 f0;           /* 0x00 */
    s16 t4;           /* 0x04 */
    s16 t6;           /* 0x06 */
    s16 t8;           /* 0x08 */
    s16 tA;           /* 0x0A */
    s32 charge;       /* 0x0C */
    vu0_v4 pos;       /* 0x10 */
    f32 inv8;         /* 0x20 */
    f32 invA;         /* 0x24 */
    f32 r28;          /* 0x28 */
    f32 r2C;          /* 0x2C */
    vu0_v4 aim;       /* 0x30 */
    s32 t40;          /* 0x40 */
    f32 inv40;        /* 0x44 */
    s32 big;          /* 0x48 */
    s32 effect;       /* 0x4C */
    u8 pad50[0x10];
    s32 full;         /* 0x60 */
    s32 sound;        /* 0x64 */
    f32 r68;          /* 0x68 */
} St_00386B38;
typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    u8 *ownerDC;
    u8 padE0[0x20];
} Snd_00386B38;
typedef struct {
    u8 pad0[0x24];
    s32 x24;
    u8 pad28[0x44];
    f32 damage;
    u8 pad70[0x80];
} Row_00386B38;
typedef struct {
    vu0_v4 dir;
    u8 *source;
    u32 flags;
    u8 kind, subtype;
    u16 class_id;
    f32 damage;
    s32 enabled;
} Hit_00386B38;
extern u8 D_00142A60[];
extern u8 D_001425E7[];
extern s32 D_0014288C;
extern u8 D_001A4BE0_00386B38[];
extern Snd_00386B38 D_001A30B0_00386B38[];
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern Row_00386B38 D_L01_002C5600_00386B38[];
extern u8 *D_L01_00221098[];
extern u8 *D_L01_00221208;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern s32 D_L01_001D7BE0;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E1EA0;
extern s32 D_L01_001E1EA4;
extern s32 D_L01_001E1EBC;
extern s32 D_L01_001E1F00;
extern s32 D_L01_001E1EF0;
extern s32 D_L01_001E1EF4;
extern u8 D_L01_001E1ED0[8];
extern vu0_v4 D_L01_001E1EE0;
extern s128 D_L01_001E29E0;
extern vu0_v4 D_L01_001E2A40;
extern u8 *D_L01_001EEA80[];
extern vu0_v4 D_L01_002906E0[];
extern u8 D_L01_002B3C10[];
extern u8 D_L01_002B3B90[];
extern u8 D_L01_001DDE20[];
__asm__(".extern D_L01_001DDE20, 4");
extern s32 D_L01_001DDDB0;
extern s32 D_L01_001DDDB4;
extern s32 D_L01_001DDDB8;
extern s32 D_L01_001DDDBC;
extern s32 D_L01_001DDDC0;
extern s32 D_L01_001DDDE4;
extern s32 D_L01_001DDDEC;
__asm__(".extern D_L01_001DDDB0, 4");
__asm__(".extern D_L01_001DDDB4, 4");
__asm__(".extern D_L01_001DDDB8, 4");
__asm__(".extern D_L01_001DDDBC, 4");
__asm__(".extern D_L01_001DDDC0, 4");
__asm__(".extern D_L01_001DDDE4, 4");
__asm__(".extern D_L01_001DDDEC, 4");
extern f32 D_L01_001DDE04;
extern f32 D_L01_001DDE08;
extern f32 D_L01_001DDE10;
extern f32 D_L01_001DDE14;
__asm__(".extern D_L01_001DDE04, 4");
__asm__(".extern D_L01_001DDE08, 4");
__asm__(".extern D_L01_001DDE10,4");
__asm__(".extern D_L01_001DDE14,4");
extern void func_L01_003884D8(u8 *obj);
extern void func_L01_003886E8(u8 *moby);
extern void func_L01_00388AC8(void *unused, s128 *position);
extern void func_L01_003897E8(void);
extern void func_L01_00388EE0();
extern void func_L01_00389798();

void func_L01_00386B38(u8 *obj)
{
    extern s32 func_0038CB00(void *);
    extern s32 func_0038CAD0(void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_003A4F28(s32);
    extern void func_003C2F58(void *, s32, void *);
    extern s32 func_003D4D00(void *, s32, u8 *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382580(void *, f32, f32);
    extern void func_L01_005003D0(s32, s32);
    extern void func_L01_0040E050(void *);
    extern s32 func_L01_004CB1F0(f32, f32);
    extern void func_L01_003F6F20(s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern s32 func_L01_005119E0(s32);
    extern s32 func_L01_004AA710(void *, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_004735F0(void *, void *, s32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_L01_005118D0(s32, s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern void func_L01_003F2278(s32, s32);
    extern void func_L01_00404A10(void (*)(void *), void *);
    extern void func_L01_00404AD8(void (*)(void *), void *);
    extern void func_L01_00457588(void *, void *, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_0034C9F0(void *, s32, void *);
    extern u8 *func_L01_003882A0(void *, void *, void *, void *, f32);
    St_00386B38 *st;
    u8 *h;
    u8 *p;
    u8 *m;
    Hit_00386B38 hit2;
    vu0_v4 a;
    Hit_00386B38 hit;
    vu0_v4 e[2];
    vu0_v4 u;
    vu0_v4 w60;
    vu0_v4 w70;
    u8 *found[23];
    s32 saved[23];
    vu0_v4 w140;
    vu0_v4 w150;
    vu0_v4 *q;
    s32 fire;
    s32 first;
    s32 i, k, n, r, cnt, left;
    f32 f;

    st = *(St_00386B38 **)(obj + 0x68);
    if (obj[0x20] == 0) {
        obj[0x20] = 1;
        st->sound = -1;
        st->t8 = 0;
        st->tA = 0;
        st->effect = -1;
        D_L01_001E1EA4 = 0;
        D_00142A60[0x27] |= 0x22;
    }
    if (obj[0x20] == 6) {
        if (func_0038CB00(&st->t4)) {
            func_003A52A0(2, 0, obj);
            obj[0x20] = 1;
        }
    }
    func_0038D000(&st->pos, D_L01_001DDE20, obj + 0xC0);
    vec_add_ab(&st->pos, &st->pos, obj + 0x10);
    h = D_001A4BE0_00386B38;
    if (*(s32 *)(h + 0x25C4) == 1) {
        func_L01_005003D0(0x1D, 1);
    }
    func_L01_0040E050(st);
    if (*(s32 *)(h + 0x25C4) == 0x1D || *(s32 *)(h + 0x16B0) != 0) {
        func_L01_003F6F20(0, obj, func_L01_004CB1F0(0.95f, 150.0f), 0, 0x5B, -1, 4, 1.0f, 1.5707964f, 90.0f,
                          0.5f, 0.5f, 30.0f, 55.0f);
    } else {
        *(s32 *)(h + 0x16D8) = 0;
        *(s32 *)(h + 0x16D4) = 0;
    }
    h = D_001A4BE0_00386B38;
    if (*(u8 **)(h + 0x1430) != 0) {
        *(u8 **)(h + 0xBD8) = *(u8 **)(h + 0x1430);
    }
    fire = 1;
    if (*(s32 *)(h + 0x25C4) == 0x1D) {
        if (func_0038CAD0(h + 0x28BC) == 0) {
            fire = 0;
        }
    } else {
        *(s32 *)(h + 0x28BC) = 0x21;
    }
    h = D_001A4BE0_00386B38;
    if ((*(s32 *)(D_001D52FC + 0x1A0) & *(s32 *)(h + 0x1210)) && func_L01_005119E0(-1) && h[0x25ED] == 0) {
        first = st->charge == 0;
        st->charge++;
        if (func_L01_004AA710(obj, st->sound) == 0) {
            st->sound = func_003A52A0(3, 4, obj);
        }
        if (st->charge >= 0x42) {
            st->full = 1;
            for (i = 1; i >= 0; i--) {
                n = (func_00382498(10, 20) * 5 + 2) / 6;
                r = func_00382498(-1, -3);
                p = func_L01_004713C8(&st->pos, D_L01_001D66B0, n, 0x965050, r, 0x40, 0, 0, 84000.0f, 220499.98f,
                                      -0.0004f);
                if (p != 0) {
                    p[2] = D_L01_00221098[0x68][func_00382498(0, 3)];
                }
            }
            a = st->pos;
            for (i = 1; i >= 0; i--) {
                a.x += func_003824E0(-0.2f, 0.2f);
                a.y += func_003824E0(-0.2f, 0.2f);
                a.z += func_003824E0(-0.2f, 0.2f);
                n = (func_00382498(10, 20) * 5 + 2) / 6;
                r = func_00382498(-1, -3);
                p = func_L01_004713C8(&a, D_L01_001D66B0, n, 0x505096, r, 0x40, 0, 0, 84000.0f, 220499.98f, -0.0004f);
                if (p != 0) {
                    p[2] = D_L01_00221098[0x61][func_00382498(5, 7)];
                }
            }
            func_00382580(&a, 0.025f, 0.15f);
            vec_add_ab(&a, &a, &st->pos);
            vec_sub_ba(&hit.dir, &st->pos, &a);
            func_0038CF68(&hit.dir, &hit.dir, 0.015f);
            func_L01_004735F0(&a, &hit.dir, 12, 1.0f);
            if (func_00382468(2)) {
                p = func_L01_0046A610(&st->pos, D_L01_001D66B0, 12, 6, 0x904020, (s32)func_L01_00443A18(1.0f, -1.0f),
                                      10.0f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[2] = D_L01_00221208[1];
                }
            }
        } else {
            for (i = 1; i >= 0; i--) {
                n = (func_00382498(10, 20) * 5 + 2) / 6;
                k = ((0xFF - st->charge) << 16) | ((st->charge + 0x80) << 8) | 0x20;
                r = func_00382498(-1, -3);
                p = func_L01_004713C8(&st->pos, D_L01_001D66B0, n, k, r, st->charge / 3, 0, 0, 21000.0f, 115500.0f,
                                      -0.0004f);
                if (p != 0) {
                    p[2] = D_L01_00221098[0x68][func_00382498(0, 3)];
                }
            }
        }
    } else {
        if ((*(s32 *)(D_001D52FC + 0x1A4) & *(s32 *)(h + 0x1210)) && func_L01_005119E0(-1) == 0) {
            func_003A52A0(1, 0, obj);
        }
        first = !(st->charge < 0x42);
        st->charge = 0;
        if (st->sound != -1) {
            if (D_001A30B0_00386B38[st->sound].ownerDC == obj && D_001A30B0_00386B38[st->sound].bD0 != 0) {
                func_003A4F28(st->sound);
            }
        }
        st->sound = -1;
    }
    if (first) {
        h = D_001A4BE0_00386B38;
        if (obj[0x20] == 1 && st->f0 == 0.0f && *(s32 *)(h + 0x1220) >= 0x13 && fire != 0) {
            if (func_L01_005119E0(-1)) {
                if ((*(u8 **)(h + 0x25C0))[0x43] == D_L01_002C5600_00386B38[D_001425E7[0]].x24 ||
                    *(s32 *)(h + 0x25CC) != 0 || *(s16 *)(h + 0x2874) != 0) {
                    st->big = 1;
                    st->tA = (D_L01_001DDDC0 * 5 + 2) / 6;
                    st->t6 = (D_L01_001DDDB0 * 5 + 2) / 6;
                    st->t8 = (D_L01_001DDDB8 * 5 + 2) / 6;
                } else {
                    st->t6 = 2;
                    st->t8 = (D_L01_001DDDB4 * 5 + 2) / 6;
                    st->big = 0;
                    st->tA = (D_L01_001DDDBC * 5 + 2) / 6;
                }
                if (st->full) {
                    for (i = 9; i >= 0; i--) {
                        func_L01_005118D0(-1, 1);
                    }
                } else {
                    func_L01_005118D0(-1, 1);
                }
                D_L01_001E1F00 = 1;
                if (st->full) {
                    *(f32 *)(D_L01_002B3C10 + 0x14) = 1.0f;
                    D_L01_001E1EF0 = 1;
                    D_L01_001E1EF4 = D_L01_001DFB40;
                    *(s32 *)(D_L01_002B3C10 + 0xC) = 0x7F804020;
                    *(s32 *)(D_L01_002B3C10 + 0x10) = 0x7FFF4020;
                    *(s32 *)(D_L01_002B3C10 + 0x0) = 10;
                    *(s32 *)(D_L01_002B3C10 + 0x4) = 10;
                }
                func_L01_004EA7D8(-1);
                st->effect = func_L01_003F2058(D_L01_002B3B90, 0);
                obj[0x20] = 2;
                st->r68 = func_00382538();
                if (st->full) {
                    D_L01_001E1EA4 = 0x19;
                    D_L01_001DDE08 = 1.0f;
                    D_L01_001E1EBC = 0;
                    D_L01_001DDE04 = 1.0f;
                    D_L01_001E1EA0 = (D_L01_001DDDEC * 5 + 2) / 6;
                } else {
                    D_L01_001E1EBC = 0x11;
                    D_L01_001DDE14 = 1.0f;
                    D_L01_001E1EA0 = 5;
                    D_L01_001DDE10 = 1.0f;
                    D_L01_001E1EA4 = 0;
                }
                st->inv8 = 1.0f / (f32)st->t8;
                st->invA = 1.0f / (f32)st->tA;
                st->r28 = func_00382538();
                st->r2C = func_00382538();
                st->t40 = (D_L01_001DDDE4 * 5 + 2) / 6;
                st->inv40 = 1.0f / (f32)st->t40;
            } else {
                if (st->full && D_0014288C < 10) {
                    st->full = 0;
                }
                if ((*(s32 *)(D_001D52FC + 0x1A4) & *(s32 *)(h + 0x1210)) || D_L01_001E1F00 == 1) {
                    func_003A52A0(3, 0, obj);
                    D_L01_001E1F00 = 0;
                }
            }
            h = D_001A4BE0_00386B38;
            if (!(((*(s32 *)(D_001D52FC + 0x1A0) & *(s32 *)(h + 0x1210)) ||
                   ((*(s32 *)(D_001D52FC + 0x1A0) & 8) && *(s32 *)(h + 0x25C4) == 0x1D)) &&
                  func_L01_005119E0(-1) && h[0x25E9] != 0)) {
                if (st->effect >= 0) {
                    func_L01_003F2278(st->effect, 0);
                    st->effect = -1;
                }
            }
        }
    }
    if (D_L01_001E1EA4 > 0) {
        func_00382580(&hit.dir, 0.3f, 0.40000004f);
        hit2.dir.w = 5627.925f;
        hit.source = obj;
        hit.flags = 0x210000;
        hit.kind = 3;
        hit.subtype = 2;
        hit.class_id = *(u16 *)(obj + 0xAA);
        hit.damage = D_L01_002C5600_00386B38[D_001425E7[0]].damage * 10.0f;
        hit.enabled = 1;
        func_0038CE20(&e[0], obj + 0xD0, -1.35f);
        vec_add_ab(&e[0], &e[0], obj + 0x10);
        func_0038CE20(&u, obj + 0xC0, 0.275f);
        vec_add_ab(&e[0], &e[0], &u);
        h = D_001A4BE0_00386B38;
        for (i = 0; i < 20; i++) {
            w60 = st->pos;
            func_0038CE20(&w70, h + 0x6F0, (f32)(i + 1) + (f32)(i + 1));
            vec_add_ab(&D_L01_002906E0[i], &w70, &w60);
            func_003D4D00(&D_L01_002906E0[i], 1, *(u8 **)(h + 0x25C0), &hit, 1.5f);
        }
    }
    if ((u32)(D_L01_001E1EA4 - 1) < 0x18) {
        func_L01_00404A10(func_L01_003897E8, obj);
    }
    if (D_L01_001E1EA4 == 8) {
        D_L01_001E1EF0 = 2;
        D_L01_001E1EF4 = D_L01_001DFB40;
    }
    if (D_L01_001E1EA4 != 0) {
        func_003C2F58(obj, 0, &e[0]);
        h = D_001A4BE0_00386B38;
        *(vu0_v4 *)D_L01_001E1ED0 = e[0];
        if (*(s16 *)(h + 0x2874) != 0) {
            func_0038CE20(&hit2.dir, obj + 0xD0, -10.0f);
        } else if (*(s32 *)(h + 0x16B0) == 1) {
            func_0038CE20(&hit2.dir, &D_L01_001E29E0, 40.0f);
        } else {
            func_0038CE20(&hit2.dir, h + 0x6F0, 40.0f);
        }
        vec_add_ab(&D_L01_001E1EE0, &e[0], &hit2.dir);
        for (i = 4; i >= 0; i--) {
            func_0038CDF8(&hit.dir, D_L01_001E1ED0, &D_L01_001E1EE0, func_003824E0(0.0f, 1.0f));
            n = (func_00382498(10, 18) * 5 + 2) / 6;
            r = func_00382498(-1, -3);
            p = func_L01_004713C8(&hit.dir, D_L01_001D66B0, n, 0x804020, r, 0x50, 0, 0, 168000.0f, 315000.0f,
                                  -0.0004f);
            if (p != 0) {
                p[2] = D_L01_00221098[0x68][func_00382498(0, 3)];
            }
        }
        for (i = 0; i >= 0; i--) {
            n = (func_00382498(10, 18) * 5 + 2) / 6;
            r = func_00382498(-1, -3);
            p = func_L01_004713C8(D_L01_001E1ED0, D_L01_001D66B0, n, 0x804020, r, 0x50, 0, 0, 63000.004f, 210000.0f,
                                  -0.0004f);
            if (p != 0) {
                p[2] = D_L01_00221098[0x68][func_00382498(0, 3)];
            }
        }
    }
    if (st->t6 == 0) {
        func_0038CB00(&st->tA);
        func_0038CB00(&st->t8);
        func_0038CAD0(&st->t40);
        if (*(u32 *)&st->t8 != 0) {
            func_L01_00404A10(func_L01_00388EE0, obj);
        }
    }
    if (func_0038CAD0(&D_L01_001E1EA0) == 0) {
        func_L01_00404AD8(func_L01_00389798, obj);
    }
    if (func_0038CAD0(&D_L01_001E1EA4) == 0) {
        if (D_L01_001E1EA4 >= 0xD) {
            D_L01_001DDE04 = D_L01_001DDE04 + 0.1f;
            D_L01_001DDE08 = D_L01_001DDE08 + 0.1f;
        } else {
            D_L01_001DDE04 = D_L01_001DDE04 - 0.125f;
            D_L01_001DDE08 = D_L01_001DDE08 - 0.075f;
        }
        if (D_L01_001E1EA4 < 0x1A) {
            func_L01_00404A10(func_L01_003897E8, obj);
        }
        func_L01_00404A10(func_L01_003886E8, obj);
    }
    if (func_0038CAD0(&D_L01_001E1EBC) == 0) {
        if (D_L01_001E1EBC >= 0xD) {
            D_L01_001DDE10 = D_L01_001DDE10 + 0.5f;
            D_L01_001DDE14 = D_L01_001DDE14 + 0.3f;
        } else {
            D_L01_001DDE10 = D_L01_001DDE10 - 0.3f;
            D_L01_001DDE14 = D_L01_001DDE14 - 0.2f;
        }
        func_L01_00404A10(func_L01_003884D8, obj);
    }
    if ((u32)(obj[0x20] - 2) < 2) {
        if (func_0038CB00(&st->t6)) {
            h = D_001A4BE0_00386B38;
            if (*(u8 **)(h + 0xBD8) != 0) {
                func_L01_00457588(*(u8 **)(h + 0xBD8), &st->pos, h + 0x6F0, 1.0f);
                *(s128 *)(h + 0x6C0) = *(s128 *)(h + 0x6F0);
            }
            if (obj[0x20] == 2) {
                obj[0x20] = 3;
                func_L01_00388AC8(obj, (s128 *)&st->pos);
                st->aim = *(vu0_v4 *)(h + 0x6F0);
                func_L01_00404A10(func_L01_00388EE0, obj);
                if (st->full) {
                    func_003A52A0(0, 0, obj);
                } else {
                    func_003A52A0(4, 0, obj);
                }
                f = 0.06f;
                if (st->big) {
                    f = 0.12f;
                }
                (&D_L01_001E2A40)[3].x = f;
                *(s32 *)&(&D_L01_001E2A40)[3].z = 0x19;
                *(s32 *)&(&D_L01_001E2A40)[2].w = 0;
                (&D_L01_001E2A40)[2].x = f;
                *(s32 *)&(&D_L01_001E2A40)[2].z = 0x19;
            } else {
                obj[0x20] = 6;
                st->t4 = 0x11;
                if (st->full == 0) {
                    hit2.flags = 0x410000;
                    hit2.enabled = 1;
                    hit2.kind = 3;
                    hit2.subtype = 2;
                    hit2.class_id = *(u16 *)(obj + 0xAA);
                    hit2.damage = D_L01_002C5600_00386B38[D_001425E7[0]].damage;
                    hit2.source = obj;
                    k = 0;
                    while (k < 4 && (!((u32)D_L01_001D7BE0 < 9 || D_001D545C == 0x1C || D_001D545C == 0x16) || k <= 0)) {
                        left = k + 1;
                        func_0038CE20(&e[0], obj + 0xD0, (f32)left * -1.35f);
                        vec_add_ab(&e[0], &e[0], obj + 0x10);
                        func_0038CE20(&e[1], obj + 0xC0, (f32)left * -0.175f);
                        vec_add_ab(&e[0], &e[0], &e[1]);
                        cnt = func_003D4D00(&e[0], 1, *(u8 **)(h + 0x25C0), 0, (f32)k * 0.25f + 1.5f);
                        if (cnt > 0) {
                            u8 **hitp = D_L01_001EEA80;
                            for (n = cnt; n != 0; n--, hitp++) {
                                if (*hitp != *(u8 **)(D_001A4BE0_00386B38 + 0x25C0)) {
                                    func_0038CE20(&hit2.dir, obj + 0xD0, -1.75f);
                                    hit2.dir.w = 5627.925f;
                                    func_L01_00446978(*hitp, &hit2);
                                    func_L01_0034C9F0(*hitp, 0x27, obj);
                                }
                            }
                        }
                        k = left;
                    }
                }
                if (st->full == 0) {
                    u = st->pos;
                    if (*(s16 *)(D_001A4BE0_00386B38 + 0x2874) == 1) {
                        func_0038CE20(&e[0], obj + 0xD0, -1.0f);
                        q = &e[1];
                        func_0038CE20(q, obj + 0xC0, -1.0f);
                    } else if (*(s32 *)(D_001A4BE0_00386B38 + 0x16B0) == 1) {
                        q = &e[1];
                        *(s128 *)&e[0] = (&D_L01_001E29E0)[0];
                        *(s128 *)&e[1] = (&D_L01_001E29E0)[1];
                    } else {
                        q = &e[1];
                        *(s128 *)&e[1] = *(s128 *)(D_001A4BE0_00386B38 + 0x6D0);
                        *(s128 *)&e[0] = *(s128 *)(D_001A4BE0_00386B38 + 0x6C0);
                    }
                    cnt = 0;
                    st->aim = e[0];
                    for (i = 22; i >= 0; i--) {
                        found[i] = 0;
                        saved[i] = 0;
                    }
                    for (i = 22; i >= 0; i--) {
                        func_0038CF68(&w70, q, 1.0f);
                        func_0038CF68(&w60, &st->aim, 1.0f);
                        f = func_003824E0(0.0f, -17.0f) * 0.017453292f;
                        func_0038D890(&w140, &w60, &w70, f);
                        func_0038D890(&w140, &w140, &w60, func_003824E0(-170.0f, 170.0f) * 0.017453292f);
                        func_0038CE20(&w140, &w140, 32.0f);
                        vec_add_ab(&w150, &u, &w140);
                        m = func_L01_003882A0(obj, &u, &w150, &hit2, f);
                        if (m != 0) {
                            saved[cnt] = *(s32 *)(m + 0x98);
                            found[cnt] = m;
                            cnt++;
                            *(s32 *)(m + 0x98) = 0;
                        }
                    }
                    for (k = 0; k < 3; k++) {
                        func_0038CF68(&w150, q, 1.0f);
                        func_0038CF68(&w140, &st->aim, 1.0f);
                        func_0038D890(&w60, &w140, &w150, -0.2617994f);
                        func_0038D890(&w60, &w60, &w140, (f32)k * 0.3490658f + -0.3490658f);
                        func_0038CE20(&w60, &w60, 32.0f);
                        vec_add_ab(&w70, &u, &w60);
                        m = func_L01_003882A0(obj, &u, &w70, &hit2, -0.2617994f);
                        if (m != 0) {
                            saved[cnt] = *(s32 *)(m + 0x98);
                            found[cnt] = m;
                            cnt++;
                            *(s32 *)(m + 0x98) = 0;
                        }
                    }
                    for (i = 0; i < cnt; i++) {
                        *(s32 *)(found[i] + 0x98) = saved[i];
                    }
                }
                st->f0 = 0.0f;
                st->full = 0;
                if (st->sound != -1) {
                    if (D_001A30B0_00386B38[st->sound].ownerDC == obj && D_001A30B0_00386B38[st->sound].bD0 != 0) {
                        func_003A4F28(st->sound);
                    }
                }
                st->sound = -1;
            }
        }
    }
}
/* localdecomp:end func_L01_00386B38 */

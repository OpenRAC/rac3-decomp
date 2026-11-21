/* functional: medium. Written from the PAL asm (no draft): the charge-shot glove weapon update (func_L01_0036B670; phases 1 idle / 2 fire / 3 post-fire / 6 cooldown). Control flow, constants, $gp globals (D_L01_001DD810..864, gp+0x5464/0x5468 = D_L01_001E1D14/18) and call arguments read block by block against the asm. Judgement calls: func_003A52A0 is declared to return s32 here (retail uses its result as a sound handle); the damage packet on the stack (sp+0x00..0x23) is modelled as Packet_0036B670; ray loop passes the first random angle (f20) as 36C828's damage argument and 2nd loop f22, exactly as retail; arr60/arrC0 are 23-word stack arrays (the clear loop runs 23 times). Medium because of size: the 3 ray loops' register-carried values were traced by hand. */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_0036B670;
typedef struct {
    Vec_0036B670 vec;
    u8 *owner;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 i20;
} Packet_0036B670;
typedef struct {
    u8 pad0[0x20];
    u8 phase;
    u8 pad21[0x7C - 0x21];
    s16 bangles;
} Moby_0036B670;
typedef struct {
    f32 f00;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    f32 f0C;
    Vec_0036B670 pos10;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    Vec_0036B670 v30;
    s32 i40;
    f32 f44;
    s32 i48;
    s32 i4C;
    s32 i50;
    s32 i54;
    s32 i58;
    s32 i5C;
} Vars_0036B670;
typedef struct {
    u8 pad0[0xBD8];
    u8 *fBD8;
    u8 pad0BDC[0x1210 - 0xBDC];
    s32 fire_button;
    u8 pad1214[0x1220 - 0x1214];
    s32 f1220;
    u8 pad1224[0x1430 - 0x1224];
    u8 *f1430;
    u8 pad1434[0x16B0 - 0x1434];
    s32 f16B0;
    u8 pad16B4[0x16D4 - 0x16B4];
    s32 f16D4;
    s32 f16D8;
    u8 pad16DC[0x25C0 - 0x16DC];
    u8 *camera;
    s32 state;
    s32 f25CC;
    u8 pad25D0[0x25E9 - 0x25D0];
    u8 b25E9;
    u8 pad25EA[0x25ED - 0x25EA];
    u8 no_firing;
    u8 pad25EE[0x2874 - 0x25EE];
    s16 h2874;
    u8 pad2876[0x28BC - 0x2876];
    s32 f28BC;
} Hero_0036B670;
typedef struct { u8 pad0[0x1A0]; s32 w1A0; s32 w1A4; } Pad_0036B670;
typedef struct { u8 p0; u8 kind; u8 p2[0x22]; s32 i24; u8 p28[0x50 - 0x28]; f32 f50; u8 p54[0x6C - 0x54]; f32 f6C; u8 p70[0xF0 - 0x70]; } Row_0036B670;
typedef struct { u8 pad[0x1A0]; u8 *p1A0; } T_221098_0036B670;
typedef struct { u8 pad[0xD0]; u8 bD0; u8 padD1[0xDC - 0xD1]; u8 *wDC; u8 padE0[0x80 - 0x60]; } Slot_0036B670;
extern Hero_0036B670 D_001A4BE0;
extern Pad_0036B670 *D_001D52FC;
extern Row_0036B670 D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_00142A60[];
extern s32 D_001D6694;
extern s32 D_001D545C;
extern u32 D_001D75E0;
extern u8 D_001D66B0[];
extern T_221098_0036B670 D_L01_00221098;
extern u8 D_001A30B0[];
extern u8 D_002B38C0[];
extern u8 *D_L01_001EEA80[];
extern Vec_0036B670 D_L01_001E29E0[];
extern u8 D_L01_001E2A40[];
extern s32 D_L01_001E1D14;
__asm__(".extern D_L01_001E1D14, 4");
extern s32 D_L01_001E1D18;
__asm__(".extern D_L01_001E1D18, 4");
extern s32 D_L01_001E1D1C;
extern s32 D_L01_001DD810;
__asm__(".extern D_L01_001DD810, 4");
extern s32 D_L01_001DD814;
__asm__(".extern D_L01_001DD814, 4");
extern s32 D_L01_001DD818;
__asm__(".extern D_L01_001DD818, 4");
extern s32 D_L01_001DD81C;
__asm__(".extern D_L01_001DD81C, 4");
extern s32 D_L01_001DD820;
__asm__(".extern D_L01_001DD820, 4");
extern s32 D_L01_001DD844;
__asm__(".extern D_L01_001DD844, 4");
extern s32 D_L01_001DD84C;
__asm__(".extern D_L01_001DD84C, 4");
extern s32 D_L01_001DD850;
__asm__(".extern D_L01_001DD850, 4");
extern f32 D_L01_001DD858;
__asm__(".extern D_L01_001DD858, 4");
extern f32 D_L01_001DD85C;
__asm__(".extern D_L01_001DD85C, 4");
extern f32 D_L01_001DD860;
__asm__(".extern D_L01_001DD860, 4");
extern f32 D_L01_001DD864;
__asm__(".extern D_L01_001DD864, 4");
static __inline__ void add_0036B670(Vec_0036B670 *d, Vec_0036B670 *a, Vec_0036B670 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L01_0036B670(Moby_0036B670 *moby) {
    extern s32 func_0038CB00(s16 *);
    extern s32 func_0038CAD0(s32 *);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L01_005003D0(s32, s32);
    extern void func_L01_0040E050(void *);
    extern s32 func_L01_004CB1F0(f32, f32);
    extern void func_L01_003F6F20(s32, void *, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern s32 func_L01_005119E0(s32);
    extern void func_003C2F58(s32, s32, void *);
    extern s32 func_L01_004AA710(void *, s32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_003A4F28(s32);
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern f32 func_00382538(void);
    extern void func_L01_003F2278(s32, s32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_0036D018(void *);
    extern void func_L01_0036DB20(void *);
    extern void func_L01_0036D8C8(void *);
    extern void func_L01_00457588(void *, void *, void *, f32);
    extern void func_L01_0036CB08(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_003D4D00(void *, s32, void *, s32, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_0034C9F0(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern u8 *func_L01_0036C828(void *, void *, void *, void *, f32);
    Vec_0036B670 V30, V40, V50, V120, V130, V140, V150;
    Packet_0036B670 P;
    u8 *arr60[23];
    s32 arrC0[23];
    Vars_0036B670 *vars = *(Vars_0036B670 **)((u8 *)moby + 0x68);
    s32 can, fire, kind, i, k, nhit, count, life, rnd, r;
    u8 *spark, *hit, *m;
    f32 f20, f22, f12, t;
    s32 col;

    if (moby->phase == 0) {
        moby->phase = 1;
        vars->i58 = -1;
        vars->h8 = 0;
        vars->hA = 0;
        vars->i4C = -1;
        vars->i50 = 0;
        D_L01_001E1D1C = 0;
    }
    if (D_L01_002C5600[D_001425C0[0x27]].kind >= 2)
        D_00142A60[0x27] |= 0x20;
    if (D_L01_002C5600[D_001425C0[0x27]].kind >= 3)
        D_00142A60[0x27] |= 2;
    kind = D_L01_002C5600[D_001425C0[0x27]].kind;
    if (kind >= 2)
        moby->bangles = 3;
    else if (kind == 1)
        moby->bangles = 2;
    if (D_001A4BE0.f1430)
        D_001A4BE0.fBD8 = D_001A4BE0.f1430;
    if (D_L01_001DD84C) {
        if (func_0038CB00(&vars->h4)) {
            D_L01_001DD84C = 0;
            func_003A52A0(2, 0, moby);
        }
    }
    if (moby->phase == 6) {
        if (func_0038CAD0(&vars->i5C))
            moby->phase = 1;
    }
    if (D_001A4BE0.state == 1)
        func_L01_005003D0(0x1D, 1);
    func_L01_0040E050(vars);
    if (D_001A4BE0.state == 0x1D || D_001A4BE0.f16B0) {
        r = func_L01_004CB1F0(0.949999988079071f, 150.0f);
        func_L01_003F6F20(0, moby, r, 0, 0x5B, -1, 4, 1.0f, 1.5707963705062866f, 90.0f, 0.5f, 0.5f,
                          D_L01_001DD860, D_L01_001DD864);
    } else {
        D_001A4BE0.f16D8 = 0;
        D_001A4BE0.f16D4 = 0;
    }
    can = 1;
    if (D_001A4BE0.state == 0x1D)
        can = func_0038CAD0(&D_001A4BE0.f28BC) != 0;
    else
        D_001A4BE0.f28BC = 0x21;
    if (D_001A4BE0.state == 0x74 || D_001D6694) {
        vars->i50 = 0;
        vars->i54 = 0;
    }

    if (D_L01_002C5600[D_001425C0[0x27]].kind != 0) {
        if ((D_001D52FC->w1A0 & D_001A4BE0.fire_button) && func_L01_005119E0(-1) && !D_001A4BE0.no_firing
            && !D_001D6694 && D_001A4BE0.state != 0x74) {
            r = vars->i50;
            fire = (r <= 0x13);
            vars->i50 = r + 1;
            func_003C2F58((s32)moby, 0, &vars->pos10);
            if (func_L01_004AA710(moby, vars->i58) == 0)
                vars->i58 = func_003A52A0(4, 4, moby);
            if (vars->i50 >= 0x42) {
                vars->i54 = 1;
                for (i = 1; i >= 0; i--) {
                    life = (func_00382498(10, 20) * 5 + 2) / 6;
                    rnd = func_00382498(-1, -3);
                    spark = func_L01_004713C8(&vars->pos10, D_001D66B0, life, 0x965050, rnd, 0x40, 0, 0,
                                              42000.0f, 178500.0f, -0.0004000000189989805f);
                    if (spark)
                        spark[2] = D_L01_00221098.p1A0[func_00382498(0, 3)];
                }
            } else {
                for (i = 1; i >= 0; i--) {
                    life = (func_00382498(10, 20) * 5 + 2) / 6;
                    r = vars->i50;
                    col = ((r + 0x20) << 16) | ((0xFF - r / 2) | 0x8000);
                    rnd = func_00382498(-1, -3);
                    spark = func_L01_004713C8(&vars->pos10, D_001D66B0, life, col, rnd, vars->i50 / 3, 0, 0,
                                              21000.0f, 115500.0f, -0.0004000000189989805f);
                    if (spark)
                        spark[2] = D_L01_00221098.p1A0[func_00382498(0, 3)];
                }
            }
        } else {
            if ((D_001D52FC->w1A4 & D_001A4BE0.fire_button) && !func_L01_005119E0(-1))
                func_003A52A0(3, 0, moby);
            fire = vars->i50 >= 0x42;
            vars->i50 = 0;
            if (vars->i58 != -1) {
                if (*(u8 **)(D_001A30B0 + (vars->i58 << 7) + 0xDC) == (u8 *)moby
                    && D_001A30B0[(vars->i58 << 7) + 0xD0] != 0)
                    func_003A4F28(vars->i58);
            }
            vars->i58 = -1;
        }
    } else {
        fire = (D_001D52FC->w1A0 & D_001A4BE0.fire_button)
            || ((D_001D52FC->w1A0 & 8) && D_001A4BE0.state == 0x1D);
    }

    if (fire && !D_001A4BE0.no_firing && moby->phase == 1 && vars->f00 == 0.0f && D_001A4BE0.f1220 >= 0x13
        && can && !D_001D6694 && D_001A4BE0.state != 0x74) {
        if (func_L01_005119E0(-1)) {
            if (*(u8 *)(D_001A4BE0.camera + 0x43) == D_L01_002C5600[D_001425C0[0x27]].i24
                || D_001A4BE0.f25CC != 0 || D_001A4BE0.h2874 != 0) {
                vars->hA = (D_L01_001DD820 * 5 + 2) / 6;
                vars->h6 = (D_L01_001DD810 * 5 + 2) / 6;
                vars->h8 = (D_L01_001DD818 * 5 + 2) / 6;
                vars->i48 = 1;
            } else {
                vars->h6 = 2;
                vars->h8 = (D_L01_001DD814 * 5 + 2) / 6;
                vars->hA = (D_L01_001DD81C * 5 + 2) / 6;
                vars->i48 = 0;
            }
            func_L01_005118D0(-1, 1);
            D_L01_001E1D14 = 1;
            func_L01_004EA7D8(-1);
            vars->i4C = func_L01_003F2058(D_002B38C0, 0);
            moby->phase = 2;
            vars->f0C = func_00382538();
            if (vars->i54) {
                D_L01_001E1D1C = 0x11;
                D_L01_001DD85C = 1.0f;
                D_L01_001DD858 = 1.0f;
                D_L01_001E1D18 = (D_L01_001DD850 * 5 + 2) / 6;
            } else {
                D_L01_001E1D1C = 0;
                D_L01_001E1D18 = 0;
            }
            vars->f20 = 1.0f / (f32)vars->h8;
            vars->f24 = 1.0f / (f32)vars->hA;
            vars->f28 = func_00382538();
            vars->f2C = func_00382538();
            vars->i40 = (D_L01_001DD844 * 5 + 2) / 6;
            vars->f44 = 1.0f / (f32)vars->i40;
        } else {
            if ((D_001D52FC->w1A4 & D_001A4BE0.fire_button) || D_L01_001E1D14 == 1) {
                func_003A52A0(3, 0, moby);
                D_L01_001E1D14 = 0;
            }
        }
        if (!((D_001D52FC->w1A0 & D_001A4BE0.fire_button) && func_L01_005119E0(-1) && D_001A4BE0.b25E9)) {
            if (vars->i4C >= 0) {
                func_L01_003F2278(vars->i4C, 0);
                vars->i4C = -1;
            }
        }
    }
    if (vars->h6 == 0) {
        func_0038CB00(&vars->hA);
        func_0038CB00(&vars->h8);
        func_0038CAD0(&vars->i40);
        if (*(u32 *)&vars->h8 != 0)
            func_L01_00404A10(func_L01_0036D018, moby);
    }
    if (func_0038CAD0(&D_L01_001E1D18) == 0)
        func_L01_00404A10(func_L01_0036DB20, moby);
    if (func_0038CAD0(&D_L01_001E1D1C) == 0) {
        if (D_L01_001E1D1C >= 0xD) {
            D_L01_001DD858 = D_L01_001DD858 + 0.5f;
            D_L01_001DD85C = D_L01_001DD85C + 0.30000001192092896f;
        } else {
            D_L01_001DD858 = D_L01_001DD858 - 0.30000001192092896f;
            D_L01_001DD85C = D_L01_001DD85C - 0.20000000298023224f;
        }
        func_L01_00404A10(func_L01_0036D8C8, moby);
    }
    if (moby->phase - 2 >= 2u)
        return;
    if (!func_0038CB00(&vars->h6))
        return;
    if (D_001A4BE0.fBD8) {
        func_L01_00457588(D_001A4BE0.fBD8, &vars->pos10, (u8 *)&D_001A4BE0 + 0x6F0, 1.0f);
        *(Vec_0036B670 *)((u8 *)&D_001A4BE0 + 0x6C0) = *(Vec_0036B670 *)((u8 *)&D_001A4BE0 + 0x6F0);
    }
    if (moby->phase == 2) {
        moby->phase = 3;
        func_003C2F58((s32)moby, 0, &vars->pos10);
        func_L01_0036CB08(moby, &vars->pos10);
        vars->v30 = *(Vec_0036B670 *)((u8 *)&D_001A4BE0 + 0x6F0);
        func_L01_00404A10(func_L01_0036D018, moby);
        func_003A52A0(0, 0, moby);
        t = 0.03999999910593033f;
        if (vars->i48)
            t = 0.09000000357627869f;
        *(f32 *)(D_L01_001E2A40 + 0x30) = t;
        *(s32 *)(D_L01_001E2A40 + 0x38) = 0x19;
        *(s32 *)(D_L01_001E2A40 + 0x2C) = 0;
        *(f32 *)(D_L01_001E2A40 + 0x20) = t;
        *(s32 *)(D_L01_001E2A40 + 0x28) = 0x19;
        return;
    }
    moby->phase = 6;
    D_L01_001DD84C = 1;
    vars->h4 = 0x2A;
    vars->i5C = 0x11;
    P.owner = (u8 *)moby;
    P.flags = 0x10000;
    P.b18 = 3;
    P.b19 = 2;
    P.h1A = *(u16 *)((u8 *)moby + 0xAA);
    P.i20 = 1;
    P.f1C = D_L01_002C5600[D_001425C0[0x27]].f6C;
    if (vars->i54)
        P.f1C = P.f1C * 3.0f;
    i = 0;
    while (i < 4 && (((D_001D75E0 >= 9) && D_001D545C != 8 && D_001D545C != 0x1C && D_001D545C != 0x16) || i <= 0)) {
        t = (f32)(i + 1);
        func_0038CE20(&V30, (u8 *)moby + 0xD0, t * -1.350000023841858f);
        add_0036B670(&V30, &V30, (Vec_0036B670 *)((u8 *)moby + 0x10));
        func_0038CE20(&V40, (u8 *)moby + 0xC0, t * -0.17499999701976776f);
        add_0036B670(&V30, &V30, &V40);
        count = func_003D4D00(&V30, 1, D_001A4BE0.camera, 0, (f32)i * 0.25f + 1.5f);
        if (count > 0) {
            for (k = 0; k < count; k++) {
                m = D_L01_001EEA80[k];
                if (m != D_001A4BE0.camera) {
                    func_0038CE20(&P, (u8 *)moby + 0xD0, -1.75f);
                    P.vec.w = 5627.9248046875f;
                    func_L01_00446978(m, &P);
                    if (D_L01_002C5600[D_001425C0[0x27]].kind != 0)
                        func_L01_0034C9F0(m, 0x27, moby);
                }
            }
        }
        i = i + 1;
    }
    func_003C2F58((s32)moby, 0, &V50);
    if (D_001A4BE0.h2874 == 1) {
        func_0038CE20(&V30, (u8 *)moby + 0xD0, -1.0f);
        func_0038CE20(&V40, (u8 *)moby + 0xC0, -1.0f);
    } else if (D_001A4BE0.f16B0 == 1) {
        V40 = D_L01_001E29E0[1];
        V30 = D_L01_001E29E0[0];
    } else {
        V40 = *(Vec_0036B670 *)((u8 *)&D_001A4BE0 + 0x6D0);
        V30 = *(Vec_0036B670 *)((u8 *)&D_001A4BE0 + 0x6C0);
    }
    vars->v30 = V30;
    nhit = 0;
    for (i = 22; i >= 0; i--) {
        arr60[22 - i] = 0;
        arrC0[22 - i] = 0;
    }
    for (i = 19; i >= 0; i--) {
        func_0038CF68(&V130, &V40, 1.0f);
        func_0038CF68(&V120, &vars->v30, 1.0f);
        f20 = func_003824E0(0.0f, -17.0f) * 0.01745329238474369f;
        func_0038D890(&V140, &V120, &V130, f20);
        f12 = func_003824E0(-170.0f, 170.0f) * 0.01745329238474369f;
        func_0038D890(&V140, &V140, &V120, f12);
        func_0038CE20(&V140, &V140, 32.0f);
        add_0036B670(&V150, &V50, &V140);
        hit = func_L01_0036C828(moby, &V50, &V150, &P, f20);
        if (hit) {
            arrC0[nhit] = *(s32 *)(hit + 0x98);
            arr60[nhit] = hit;
            nhit++;
            *(s32 *)(hit + 0x98) = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        func_0038CF68(&V130, &V40, 1.0f);
        func_0038CF68(&V120, &vars->v30, 1.0f);
        func_0038D890(&V140, &V120, &V130, -0.2617993950843811f);
        func_0038D890(&V140, &V140, &V120, (f32)i * 0.3490658402442932f + -0.3490658402442932f);
        func_0038CE20(&V140, &V140, 32.0f);
        add_0036B670(&V150, &V50, &V140);
        hit = func_L01_0036C828(moby, &V50, &V150, &P, -0.2617993950843811f);
        if (hit) {
            arrC0[nhit] = *(s32 *)(hit + 0x98);
            arr60[nhit] = hit;
            nhit++;
            *(s32 *)(hit + 0x98) = 0;
        }
    }
    for (i = 0; i < nhit; i++)
        *(s32 *)(arr60[i] + 0x98) = arrC0[i];
    if (D_L01_002C5600[D_001425C0[0x27]].kind != 0)
        vars->f00 = 0.0f;
    else
        vars->f00 = 1.0f / D_L01_002C5600[D_001425C0[0x27]].f50;
    vars->i54 = 0;
    if (vars->i58 != -1) {
        if (*(u8 **)(D_001A30B0 + (vars->i58 << 7) + 0xDC) == (u8 *)moby
            && D_001A30B0[(vars->i58 << 7) + 0xD0] != 0)
            func_003A4F28(vars->i58);
    }
    vars->i58 = -1;
}

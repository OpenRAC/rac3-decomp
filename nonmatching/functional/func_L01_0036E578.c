/* functional: high. Written from the PAL asm (no draft); the third glove-weapon update (lock-on candidate scan via func_003D4D00, target tracking timers, fire + ammo/no-ammo branches, charge-light effect slot in D_001F1B40). Every branch, offset, constant and call argument checked against the asm. Notes: the candidate scan accepts D_001EAA00.hit (offset 0x18), not the scanned object, exactly as retail; D_L01_001E1D24 is gp+0x5474; func_L01_00424D88 receives the handle through its leftover a0 (passed explicitly). */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_0036E578;
typedef struct {
    u8 pad0[0x20];
    u8 phase;
    u8 pad21[0x42 - 0x21];
    u8 b42;
    u8 b43;
    u8 pad44[0x48 - 0x44];
    f32 f48;
    u8 pad4C[0x60 - 0x4C];
    u8 flags60;
    u8 pad61[0x68 - 0x61];
    void *vars;
    u8 pad6C[0x7C - 0x6C];
    s16 bangles;
} Moby_0036E578;
typedef struct {
    f32 f00;
    u8 pad04[0x0C - 0x04];
    f32 f0C;
    u8 *i10;
    s32 i14;
    f32 f18;
    s16 h1C;
    s16 h1E;
    u8 *i20;
    s32 i24;
    s32 i28;
    s32 i2C;
} Vars_0036E578;
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
    u8 pad25C8[0x25E9 - 0x25C8];
    u8 b25E9;
    u8 pad25EA[0x25ED - 0x25EA];
    u8 no_firing;
    u8 pad25EE[0x2874 - 0x25EE];
    s16 h2874;
    u8 pad2876[0x28BC - 0x2876];
    s32 f28BC;
} Hero_0036E578;
typedef struct { u8 pad0[0x1A0]; s32 w1A0; s32 w1A4; } Pad_0036E578;
typedef struct { u8 p0; u8 kind; u8 p2[0x4E]; f32 f50; u8 p54[0xF0 - 0x54]; } Row_0036E578;
extern Hero_0036E578 D_001A4BE0;
extern Pad_0036E578 *D_001D52FC;
extern Row_0036E578 D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_00142A60[];
extern s32 D_001D6694;
extern s32 D_L01_001E1D24;
__asm__(".extern D_L01_001E1D24, 4");
extern u8 *D_L01_001EEA80[];
extern struct { u8 pad[0x18]; u8 *hit; } D_L01_001EAA00;
extern Vec_0036E578 D_L01_001E29C0;
extern u8 D_L01_002B3940[];
extern u8 D_L01_001F1B40[];
static __inline__ void add_0036E578(Vec_0036E578 *d, Vec_0036E578 *a, Vec_0036E578 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L01_0036E578(Moby_0036E578 *moby) {
    extern void func_L01_0036DEB0(void *);
    extern void func_L01_0040E050(void *);
    extern void func_L01_005003D0(s32, s32);
    extern void func_L01_00444F38(void *, s32, s32, s32, s32);
    extern s32 func_L01_004CB1F0(f32, f32);
    extern void func_L01_003F6F20(s32, void *, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern u8 *func_L01_00450BB0(void *, void *, s32, f32, f32, f32, f32, f32);
    extern f32 *func_00382348(void *);
    extern s32 func_0038CAD0(s32 *);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_004CB128(void *, void *, s32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern s32 func_L01_005118D0(s32, s32);
    extern s32 func_003D4D00(void *, s32, void *, s32, f32);
    extern s32 func_003C4B50(void *);
    extern void func_L01_0036E120(void *);
    extern void func_003A52A0(s32, s32, void *);
    extern void func_L01_0036F120(void *);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_003F2278(s32, s32);
    extern void func_003C2F58(s32, s32, void *);
    extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
    extern void func_0038CB00(s16 *);
    extern void func_L01_00424D88(s32);
    Vec_0036E578 V0, V10, V30, V40, V50;
    Vec_0036E578 V20;
    Vars_0036E578 *vars = moby->vars;
    u8 *newt, *cur, *m;
    f32 *r;
    f32 a, b, d, ang, f20, f21, f22;
    s32 can, i, count, h, mask, k, valid;
    u8 st;
    s32 ret;
    s16 sh;

    if (moby->phase == 0) {
        moby->phase = 1;
        vars->h1C = -1;
        vars->i24 = 4;
        vars->i2C = -1;
        vars->h1E = 0;
        vars->i10 = 0;
        vars->i20 = 0;
        vars->i28 = 0;
    }
    if (D_L01_002C5600[D_001425C0[0x3F]].kind >= 2)
        D_00142A60[0x3F] |= 2;
    if (D_L01_002C5600[D_001425C0[0x3F]].kind >= 3)
        D_00142A60[0x3F] |= 0x20;
    func_L01_0036DEB0(moby);
    func_L01_0040E050(vars);
    if (D_001A4BE0.state == 1)
        func_L01_005003D0(0x1D, 1);
    if (moby->b42 == moby->b43 && (moby->flags60 & 2))
        func_L01_00444F38(moby, 1, 0, 2, 0);
    if (D_001A4BE0.f1430)
        D_001A4BE0.fBD8 = D_001A4BE0.f1430;
    k = D_L01_002C5600[D_001425C0[0x3F]].kind;
    if (k == 2)
        moby->bangles = 3;
    else if (k == 1)
        moby->bangles = k;
    else if (k >= 3)
        moby->bangles = 7;

    if ((D_001A4BE0.state == 0x1D && (*(u16 *)(D_001A4BE0.camera + 0x34) & 1)) || D_001A4BE0.f16B0) {
        if (vars->i28 == 0) {
            vars->i10 = 0;
            vars->i24 = 4;
        }
        vars->i28 = 1;
        ret = func_L01_004CB1F0(0.9700000286102295f, 150.0f);
        func_L01_003F6F20(0, moby, ret, 0, 0x44, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        f20 = 0.06981316953897476f;
        f21 = f20;
    } else {
        D_001A4BE0.f16D4 = 0;
        D_001A4BE0.f16D8 = 0;
        vars->i28 = 0;
        f20 = 0.3141592741012573f;
        f21 = 0.296705961227417f;
    }
    if (D_001A4BE0.h2874 && D_001A4BE0.f16B0 != 2)
        func_0038CE20(&V0, (u8 *)moby + 0xD0, -1.0f);
    else
        V0 = *(Vec_0036E578 *)((u8 *)&D_001A4BE0 + 0x6F0);
    func_0038CE20(&V10, D_001A4BE0.camera + 0xE0, 0.75f);
    add_0036E578(&V10, (Vec_0036E578 *)((u8 *)&D_001A4BE0 + 0x80), &V10);
    newt = func_L01_00450BB0(&V10, &V0, 1, f20, f21, 30.0f, f20, f20);

    cur = vars->i10;
    if (cur) {
        r = func_00382348(cur);
        st = cur[0x20];
        valid = 0;
        if (st != 0xFE && st != 0xFD && *(u8 **)(cur + 0x24) != 0 && (*(u8 **)(cur + 0x24))[0x46] == 5) {
            if (r == 0 || *r > 0.0f) {
                if (cur[0x31] != 0 && D_001A4BE0.h2874 == 0)
                    valid = 1;
            }
        }
        if (!valid) {
            vars->i10 = 0;
            vars->i24 = 4;
        } else if (newt != cur) {
            if (func_0038CAD0(&vars->i14)) {
                vars->i10 = 0;
                vars->i24 = 4;
            }
        } else {
            vars->i14 = 4;
            if (D_001A4BE0.f16B0 == 0) {
                d = func_0038CF00(&D_L01_001E29C0, newt + 0x10) / 150.0f;
                func_L01_004CB128(&V20, newt, 0);
                ang = func_0038DAB8(vars->f0C, 0.03490658476948738f);
                d = d * 0.6499999761581421f;
                vars->f0C = ang;
                func_L01_003F6F20(0, moby, 0xFF0FFF0F, &V20, 0x26, -1, 4,
                                  fabs_asm(0.8999999761581421f - d), -ang, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            }
            D_001A4BE0.fBD8 = newt;
        }
    } else {
        if (newt == vars->i20) {
            if (func_0038CAD0(&vars->i24)) {
                vars->i10 = newt;
                vars->i14 = 4;
                r = func_00382348(newt);
                if (r)
                    vars->f18 = r[4];
                else
                    vars->f18 = 0.10000000149011612f;
            }
        } else {
            vars->i24 = 4;
        }
    }
    vars->i20 = newt;

    cur = vars->i10;
    can = 1;
    if (D_001A4BE0.state == 0x1D)
        can = func_0038CAD0(&D_001A4BE0.f28BC) != 0;
    else
        D_001A4BE0.f28BC = 0x21;

    if (D_001D6694 != 2) {
        if (vars->f00 == 0.0f && !D_001A4BE0.no_firing && moby->b42 < 2 && D_001A4BE0.f1220 >= 0x17
            && ((D_001D52FC->w1A0 & D_001A4BE0.fire_button)
                || ((D_001D52FC->w1A0 & 8) && D_001A4BE0.state == 0x1D))
            && can) {
            if (moby->b43 == 0)
                func_003C3A10(moby, 1, 0, 3);
            if (func_L01_005118D0(-1, 1)) {
                D_L01_001E1D24 = 1;
                if (cur == 0) {
                    func_0038CE20(&V30, (u8 *)moby + 0xD0, -1.0f);
                    add_0036E578(&V30, &V30, (Vec_0036E578 *)((u8 *)moby + 0x10));
                    func_0038CE20(&V40, (u8 *)moby + 0xC0, 0.2750000059604645f);
                    add_0036E578(&V30, &V30, &V40);
                    count = func_003D4D00(&V30, 1, D_001A4BE0.camera, 0, 1.0f);
                    if (count != 0 && count > 0) {
                        for (i = 0; i < count; i++) {
                            m = D_L01_001EEA80[i];
                            r = func_00382348(m);
                            if (m[0x31] == 0 || *(s16 *)(m + 0x32) <= 0 || m == 0)
                                continue;
                            st = m[0x20];
                            if (st == 0xFE || st == 0xFD)
                                continue;
                            sh = *(s16 *)(m + 0xAA);
                            if (sh == 0xC87 || sh == 0xECC || sh == 0x1D61 || sh == 0x1BAE)
                                continue;
                            if (r == 0)
                                continue;
                            if (!(0.0f < *r)) {
                                if (func_003C4B50(m) == 0)
                                    continue;
                            }
                            if (*(u8 **)(m + 0x24) != 0 && (*(u8 **)(m + 0x24))[0x46] == 5)
                                continue;
                            cur = D_L01_001EAA00.hit;
                            vars->i10 = cur;
                            break;
                        }
                    }
                }
                vars->h1E = 0xC;
                func_L01_0036E120(moby);
                func_003A52A0(0, 0, moby);
                func_L01_0036F120(moby);
                func_L01_004EA7D8(-1);
                func_003C3A10(moby, 2, 0, 0);
                if (D_L01_002C5600[D_001425C0[0x3F]].kind >= 4)
                    moby->f48 = 2.0f;
                vars->i2C = func_L01_003F2058(D_L01_002B3940, 0);
                vars->f00 = 1.0f / D_L01_002C5600[D_001425C0[0x3F]].f50;
            } else {
                if ((D_001D52FC->w1A4 & D_001A4BE0.fire_button) || D_L01_001E1D24 == 1) {
                    func_003A52A0(1, 0, moby);
                    D_L01_001E1D24 = 0;
                }
            }
            mask = D_001D52FC->w1A0 & D_001A4BE0.fire_button;
            if (!(mask && func_L01_005119E0(-1) && D_001A4BE0.b25E9)) {
                if (vars->i2C >= 0) {
                    func_L01_003F2278(vars->i2C, 0);
                    vars->i2C = -1;
                }
            }
        }
    }

    h = vars->h1E;
    if (moby->b42 != 2 && h > 0) {
        if (h >= 11) {
            f20 = (f32)(12 - h) * 0.5f;
            f21 = f20 * 0.5f;
            f22 = ((f32)(12 - h) * 0.800000011920929f) * 0.5f;
        } else {
            f20 = (f32)h * 0.10000000149011612f;
            f21 = ((f32)h * 0.5f) * 0.10000000149011612f;
            f22 = ((f32)h * 0.800000011920929f) * 0.10000000149011612f;
        }
        if (D_001A4BE0.h2874) {
            func_0038CE20(&V40, (u8 *)moby + 0xD0, -1.0f);
            func_003C2F58((s32)moby, 0, &V30);
        } else {
            V40 = *(Vec_0036E578 *)((u8 *)&D_001A4BE0 + 0x6F0);
            func_003C2F58((s32)moby, 0, &V30);
        }
        add_0036E578(&V30, &V30, &V40);
        func_0038CE20(&V50, D_001A4BE0.camera + 0xE0, 0.30000001192092896f);
        add_0036E578(&V30, &V30, &V50);
        if (vars->h1C == -1) {
            vars->h1C = func_L01_00424CB0(&V30, 8.0f, 0.0f, f20, f22, f21);
        } else {
            u8 *p = D_L01_001F1B40 + (vars->h1C << 5);
            *(Vec_0036E578 *)(p + 0x10) = V30;
            *(f32 *)(p + 0x08) = f21;
            *(f32 *)(p + 0x1C) = 8.0f;
            *(f32 *)(p + 0x00) = f20;
            *(f32 *)(p + 0x04) = f22;
        }
        func_0038CB00(&vars->h1E);
    } else {
        if (vars->h1C != -1) {
            func_L01_00424D88(vars->h1C);
            vars->h1C = -1;
            vars->h1E = 0;
        }
    }
    if (moby->b43 == 2) {
        if (vars->h1C != -1)
            func_L01_00424D88(vars->h1C);
        vars->h1C = -1;
        vars->h1E = 0;
    }
}

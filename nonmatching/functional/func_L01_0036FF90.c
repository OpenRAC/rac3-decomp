/* functional: high. Written from the PAL asm (no draft); the weapon-update twin of func_L01_0036F330 that fires func_L01_003706F0 projectiles. Every branch, constant, $gp address (D_L01_001DD940/950/960 are addresses, gp+0x1090/0x10A0 and D_001DD960; flag D_L01_001DD970 = gp+0x10C0) and call argument checked against the asm. Note k>=4 vs k<4 aim paths and the target-direction rule (L444) are retail's. */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_0036FF90;
typedef struct {
    u8 pad0[0x20];
    u8 phase;
    u8 pad21[0x42 - 0x21];
    u8 b42;
    u8 b43;
    u8 pad44[0x60 - 0x44];
    u8 flags60;
    u8 pad61[0x68 - 0x61];
    void *vars;
    u8 pad6C[0x7C - 0x6C];
    s16 bangles;
} Moby_0036FF90;
typedef struct { s32 timer; f32 angle; } Vars_0036FF90;
typedef struct {
    u8 pad0[0x1210];
    s32 fire_button;
    u8 pad1214[0x1220 - 0x1214];
    s32 f1220;
    u8 pad1224[0x15CC - 0x1224];
    u8 *f15CC;
    u8 pad15D0[0x15F0 - 0x15D0];
    f32 f15F0;
    u8 pad15F4[0x16B0 - 0x15F4];
    s32 f16B0;
    u8 pad16B4[0x16D4 - 0x16B4];
    s32 f16D4;
    s32 f16D8;
    u8 pad16DC[0x25C0 - 0x16DC];
    u8 *camera;
    s32 state;
    u8 pad25C8[0x25ED - 0x25C8];
    u8 no_firing;
    u8 pad25EE[0x2874 - 0x25EE];
    s16 f2874;
} Hero_0036FF90;
typedef struct { u8 pad0[0x1A0]; s32 w1A0; s32 w1A4; } Pad_0036FF90;
typedef struct { u8 p0; u8 kind; u8 p2[0x6A]; f32 damage; u8 p70[0xF0 - 0x70]; } Row_0036FF90;
extern Hero_0036FF90 D_001A4BE0;
extern Pad_0036FF90 *D_001D52FC;
extern Row_0036FF90 D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_001DAFF0;
extern s32 D_001D6694;
extern Vec_0036FF90 D_L01_001DD940;
extern Vec_0036FF90 D_L01_001DD950;
extern Vec_0036FF90 D_L01_001DD960;
extern s32 D_L01_001DD970;
__asm__(".extern D_L01_001DD970, 4");
extern Vec_0036FF90 D_L01_001E29C0;
extern Vec_0036FF90 D_L01_001E2DC0;
static __inline__ void add_0036FF90(Vec_0036FF90 *d, Vec_0036FF90 *a, Vec_0036FF90 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void sub_0036FF90(Vec_0036FF90 *d, Vec_0036FF90 *a, Vec_0036FF90 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L01_0036FF90(Moby_0036FF90 *moby) {
    extern void func_L01_005003D0(s32, s32);
    extern void func_0038D000(void *, void *, void *);
    extern s32 func_0038CAD0(s32 *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00444F38(void *, s32, s32, s32, s32);
    extern u8 *func_L01_00450BB0(void *, void *, s32, f32, f32, f32, f32, f32);
    extern void func_L01_004CB128(void *, void *, s32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_003F6F20(s32, void *, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern s32 func_L01_004CB1F0(f32, f32);
    extern s32 func_L01_005119E0(s32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_L01_004EA7D8(s32);
    extern f32 *func_00382348(void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_003A52A0(s32, s32, void *);
    extern void *func_L01_003706F0(void *, void *, void *, s32, void *, s32, s32, f32);
    Vec_0036FF90 A, B, C;
    Vars_0036FF90 *vars = moby->vars;
    u8 *target;
    u8 *camera;
    s32 k, lowk, mask;
    f32 reach, d, ang;
    f32 *r;
    u8 st;

    if (moby->phase == 0) {
        vars->timer = 0;
        moby->phase = 1;
    }
    if (D_001A4BE0.state == 1)
        func_L01_005003D0(0x1D, 1);
    k = D_L01_002C5600[D_001425C0[0x4F]].kind;
    if (k == 3)
        moby->bangles = 7;
    else if (k == 2)
        moby->bangles = 3;
    else if (k == 1)
        moby->bangles = k;
    func_0038D000(&A, &D_L01_001DD940, (u8 *)moby + 0xC0);
    add_0036FF90(&A, &A, (Vec_0036FF90 *)((u8 *)moby + 0x10));
    func_0038CAD0(&vars->timer);
    B = *(Vec_0036FF90 *)(D_001A4BE0.camera + 0xC0);
    func_0038CF68(&B, &B, 0.3499999940395355f);
    if (moby->b42 == moby->b43 && (moby->flags60 & 2))
        func_L01_00444F38(moby, 1, 0, 2, 0);
    reach = 20.0f;
    if (k >= 3)
        reach = 35.0f;
    if (D_001DAFF0)
        target = func_L01_00450BB0(&A, &B, 0, 0.3490658402442932f, 0.1745329201221466f, 50.0f, 0.7853981852531433f, 0.7853981852531433f);
    else
        target = func_L01_00450BB0(&A, &B, 0, 0.5323254466056824f, 0.5323254466056824f, reach, 0.7853981852531433f, 0.7853981852531433f);
    if (target) {
        func_L01_004CB128(&C, target, 0);
        if (D_001A4BE0.f16B0 == 0) {
            d = func_0038CF00(&D_L01_001E29C0, &C) / 150.0f;
            ang = func_0038DAB8(vars->angle, 0.03490658476948738f);
            d = d * 0.6499999761581421f;
            vars->angle = ang;
            func_L01_003F6F20(0, moby, 0xFF0FFF0F, &C, 0x26, -1, 4,
                              fabs_asm(0.8999999761581421f - d), -ang, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    }
    if (D_001A4BE0.state == 0x1D || D_001A4BE0.f16B0) {
        s32 ret;
        target = 0;
        ret = func_L01_004CB1F0(0.9800000190734863f, 150.0f);
        if (0.9800000190734863f < D_001A4BE0.f15F0)
            target = D_001A4BE0.f15CC;
        func_L01_003F6F20(0, moby, ret, 0, 0x5A, -1, 4,
                          0.800000011920929f, 3.1415927410125732f, 90.0f, 0.5f, 0.5f, 80.0f, 40.0f);
    } else {
        D_001A4BE0.f16D8 = 0;
        D_001A4BE0.f16D4 = 0;
    }
    if (D_001D6694)
        goto release;
    if (D_001A4BE0.no_firing)
        goto release;
    if (vars->timer != 0)
        goto release;
    if (moby->b42 >= 2)
        goto release;
    mask = D_001D52FC->w1A0;
    if (!(mask & D_001A4BE0.fire_button)) {
        if (!(mask & 8))
            goto release;
        if (D_001A4BE0.state != 0x1D)
            goto release;
    }
    if (D_001A4BE0.f1220 < 0x13)
        goto release;
    if (!func_L01_005119E0(-1))
        goto release;
    if (moby->b43 == 0)
        func_003C3A10(moby, 1, 0, 3);
    func_003C3A10(moby, 2, 0, 0);
    func_L01_005118D0(-1, 1);
    func_L01_004EA7D8(-1);
    lowk = k < 4;
    if (target) {
        r = func_00382348(target);
        st = target[0x20];
        if ((st == 0xFE || st == 0xFD) && !(r && *r >= 0.0f) && target[0x31] == 0 && D_001A4BE0.f2874 != 0) {
            /* keep B */
        } else {
            sub_0036FF90(&B, (Vec_0036FF90 *)(target + 0x10), &A);
        }
    }
    if (!lowk) {
        if (D_001A4BE0.state == 0x1D || D_001A4BE0.f16B0)
            B = D_L01_001E2DC0;
        func_0038CF68(&B, &B, 0.699999988079071f);
    } else {
        if (D_001A4BE0.state == 0x1D || D_001A4BE0.f16B0) {
            B = D_L01_001E2DC0;
        } else {
            camera = D_001A4BE0.camera;
            if (target)
                func_0038D890(&B, &B, camera + 0xD0, -1.0559241771697998f);
            else
                func_0038D890(&B, &B, camera + 0xD0, -0.39269909262657166f);
        }
        func_0038CF68(&B, &B, 0.3499999940395355f);
    }
    if (!lowk) {
        if (D_L01_001DD970) {
            func_0038D000(&C, &D_L01_001DD950, (u8 *)moby + 0xC0);
            add_0036FF90(&C, &C, (Vec_0036FF90 *)((u8 *)moby + 0x10));
            func_003A52A0(1, 0, moby);
            func_L01_003706F0(moby, &C, &B, 0x10000, target, 0, 0, D_L01_002C5600[D_001425C0[0x4F]].damage);
            D_L01_001DD970 = 0;
        } else {
            func_0038D000(&C, &D_L01_001DD960, (u8 *)moby + 0xC0);
            add_0036FF90(&C, &C, (Vec_0036FF90 *)((u8 *)moby + 0x10));
            func_003A52A0(1, 0, moby);
            func_L01_003706F0(moby, &C, &B, 0x10000, target, 0, 0, D_L01_002C5600[D_001425C0[0x4F]].damage);
            D_L01_001DD970 = 1;
        }
    } else {
        func_003A52A0(1, 0, moby);
        func_L01_003706F0(moby, &A, &B, 0x10000, target, 0, 0, D_L01_002C5600[D_001425C0[0x4F]].damage);
    }
    vars->timer = 0x19;
    return;
release:
    if ((D_001D52FC->w1A4 & D_001A4BE0.fire_button) && !func_L01_005119E0(-1))
        func_003A52A0(2, 0, moby);
}

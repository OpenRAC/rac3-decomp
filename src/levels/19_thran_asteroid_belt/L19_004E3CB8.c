#include "common.h"

/* localdecomp:start func_L19_004E3CB8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0xAA]; s16 oclass;
} Moby_004E3CB8;
typedef struct {
    u8 pad0[0x18]; Moby_004E3CB8 *moby; s32 count;
    vu0_v4 v20;
    u8 pad30[0x10];
    vu0_v4 v40;
} Surf_004E3CB8;
typedef union { f32 f; s32 i; } FloatBits_004E3CB8;
typedef union { f32 f[2]; s32 i[2]; } FloatPair_004E3CB8;
typedef union { s16 s; u16 u; } ShortBits_004E3CB8;
typedef union { f32 f[4]; s32 i[4]; } Vec4_004E3CB8;
typedef struct {
    u8 pad0[0x80];
    vu0_v4 pos;                         /* 0x80 */
    u8 pad90[0x20];
    vu0_v4 vB0;                         /* 0xB0: gravity point, w > 0 pulls towards it */
    u8 padC0[0x284 - 0xC0];
    f32 f284;                           /* 0x284: capsule radius */
    u8 pad288[0x2C0 - 0x288];
    Vec4_004E3CB8 v2C0;                 /* 0x2C0: ground normal */
    vu0_v4 v2D0;                        /* 0x2D0: water normal */
    vu0_v4 v2E0;                        /* 0x2E0: gravity direction */
    vu0_v4 v2F0;                        /* 0x2F0: ground point */
    vu0_v4 v300;                        /* 0x300: last ground point */
    vu0_v4 v310;                        /* 0x310: gravity override, used while w != 0 */
    FloatPair_004E3CB8 f320;            /* 0x320: side heights */
    FloatPair_004E3CB8 f328;            /* 0x328: side tilts y */
    FloatPair_004E3CB8 f330;            /* 0x330: side tilts x */
    FloatBits_004E3CB8 f338;            /* 0x338: ground z */
    f32 f33C;                           /* 0x33C: ground distance */
    FloatBits_004E3CB8 f340;            /* 0x340: ground slope */
    FloatBits_004E3CB8 f344;            /* 0x344: ground tilt y */
    FloatBits_004E3CB8 f348;            /* 0x348: ground tilt x */
    f32 f34C;                           /* 0x34C: downhill yaw */
    f32 f350;                           /* 0x350: water surface z */
    f32 f354;
    s32 w358;                           /* 0x358: frames in water */
    void *w35C;                         /* 0x35C: ground moby */
    s32 w360;                           /* 0x360: frames on the ground */
    u8 pad364[6];
    s16 h36A;                           /* 0x36A */
    ShortBits_004E3CB8 h36C;            /* 0x36C: frames off the ground */
    ShortBits_004E3CB8 h36E;            /* 0x36E: frames in the air */
    u8 pad370[0x46C - 0x370];
    u8 b46C;
    u8 pad46D[0xBF0 - 0x46D];
    void *wBF0;                         /* 0xBF0: last landed moby */
    u8 padBF4[0x1470 - 0xBF4];
    s16 h1470;                          /* 0x1470: ground type */
    u8 pad1472[0x147F - 0x1472];
    u8 b147F;                           /* 0x147F: ground sound class */
    u8 pad1480[0x1B70 - 0x1480];
    s32 w1B70;                          /* 0x1B70 */
    u8 pad1B74[0x25C0 - 0x1B74];
    void *moby;                         /* 0x25C0 */
    s32 w25C4;
    u8 pad25C8[4];
    s32 state_type;                     /* 0x25CC: control mode */
    u8 pad25D0[0x25F4 - 0x25D0];
    u8 mode;                            /* 0x25F4: gravity mode */
} Hero_004E3CB8;
extern Hero_004E3CB8 D_001A4BE0;
extern Surf_004E3CB8 D_L19_001E8E40;
extern s32 D_001D545C;
extern s32 D_L19_001D677C;
extern s32 func_L01_004E9308(void);
extern void func_L01_004EF6F0(vu0_v4 *, vu0_v4 *, s32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FE908(void);
extern s32 func_003D5630(void);
extern f32 func_003C3EC8(void *, void *);
extern s32 func_003C4B50(void *);
extern u8 *func_00382348(void *);
extern u8 *func_003C4D58(void *);
extern f32 func_L01_00451580(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0012FE98(void *, void *);
extern f32 func_L01_00511848(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_00500240(s32, s32);
extern void func_L01_004F40A8(vu0_v4 *, f32 *);
extern void func_L01_00511038(char *target, s32 add_position, f32 magnitude, f32 angle, f32 height);
/* the side probes call func_L01_00511038 with rac2's parameter order (func_L00_002D3638(void *,
 * float, float, float, int)): the same registers under the EABI, and only this order gives
 * retail's argument moves */
typedef void (*SideProbe_004E3CB8)(char *target, f32 magnitude, f32 angle, f32 height, s32 add_position);

/* from rac2-decomp's func_L01_002B5218 (the hero's ground probe) */
void func_L19_004E3CB8(void) {
    vu0_v4 rayEnd;
    vu0_v4 rayStart;
    vu0_v4 work;
    vu0_v4 sideStart;
    vu0_v4 sideEnd;
    vu0_v4 sideAngles;
    vu0_v4 sideNormal;
    s32 side;
    f32 angle;
    f32 sign;
    u8 *info;
    s32 alongGravity;
    f32 height;

    D_001A4BE0.h36E.u++;
    D_001A4BE0.h36C.u++;
    D_001A4BE0.v2C0.f[2] = 1.0f;
    D_001A4BE0.v2C0.i[0] = 0;
    D_001A4BE0.v2C0.i[1] = 0;
    D_001A4BE0.f340.i = 0;
    D_001A4BE0.f338.i = 0;
    qzero(&D_001A4BE0.v2F0);
    D_001A4BE0.h36A = 0;
    D_001A4BE0.f33C = 32.0f;
    D_001A4BE0.w35C = 0;
    if (D_001A4BE0.w358 != 0)
        D_001A4BE0.w358++;
    alongGravity = 1;
    height = D_001A4BE0.f284 * 2.2f;
    if (D_001A4BE0.state_type == 2)
        height = D_001A4BE0.f284 * 2.9f;
    if (func_L01_004E9308())
        height = 0.0f;
    func_L01_004EF6F0(&rayStart, &rayEnd, alongGravity, height, -48.0f);
    if (func_003D3CB0(&rayStart, &rayEnd, 2, D_001A4BE0.moby, 0) == 0)
        goto probed;
    D_001A4BE0.b147F = func_L01_003FE908();
    if (D_L19_001E8E40.moby != 0) {
        D_001A4BE0.b147F = 0;
        if (D_001D545C == 2) {
            if (D_L19_001E8E40.moby->oclass == 0x18C6) D_001A4BE0.b147F = 2;
            if (D_L19_001E8E40.moby->oclass == 0x18AF) D_001A4BE0.b147F = 2;
        }
        if (D_001D545C == 5) {
            if (D_L19_001E8E40.moby->oclass == 0x1607) D_001A4BE0.b147F = 2;
            if (D_L19_001E8E40.moby->oclass == 0x1681) D_001A4BE0.b147F = 2;
            if (D_L19_001E8E40.moby->oclass == 0x15F7) D_001A4BE0.b147F = 2;
            if (D_L19_001E8E40.moby->oclass == 0x16BB) D_001A4BE0.b147F = 3;
        }
        if (D_001D545C == 8) {
            if (D_L19_001E8E40.moby->oclass == 0x1A44) D_001A4BE0.b147F = 2;
        }
        if (D_001D545C == 10) {
            if (D_L19_001E8E40.moby->oclass == 0x1645) D_001A4BE0.b147F = 3;
            if (D_L19_001E8E40.moby->oclass == 0x162E) D_001A4BE0.b147F = 1;
        }
        if (D_001D545C == 0x15) {
            if (D_L19_001E8E40.moby->oclass == 0x1BA9) D_001A4BE0.b147F = 3;
        }
    }
    D_001A4BE0.h1470 = func_003D5630();
    if (D_001A4BE0.h1470 == 0) {
        D_001A4BE0.f350 = func_003C3EC8(&D_L19_001E8E40.v20, &D_001A4BE0.v2D0);
        if (D_001A4BE0.pos.z < D_001A4BE0.f350 && D_001A4BE0.w358 <= 0)
            D_001A4BE0.w358 = 1;
        if (func_003D3CB0(&rayStart, &rayEnd, 0x24, D_001A4BE0.moby, 0) == 0)
            goto probed;
        D_001A4BE0.b147F = func_L01_003FE908();
    }
    if (D_001A4BE0.h1470 == 13) {
        D_001A4BE0.f350 = D_L19_001E8E40.v20.z;
        rayStart.z = D_L19_001E8E40.v20.z - 0.01f;
        if (func_003D3CB0(&rayStart, &rayEnd, 4, D_001A4BE0.moby, 0) == 0)
            goto probed;
    }
    if (D_001A4BE0.h1470 == 11) {
        D_001A4BE0.f354 = D_L19_001E8E40.v20.z;
        goto probed;
    }
    if (D_001A4BE0.h1470 == 1) {
        if ((u32)(D_001A4BE0.w25C4 - 0x7E) < 2)
            goto probed;
    }
    if (D_L19_001E8E40.moby != 0) {
        if (func_003C4B50(D_L19_001E8E40.moby))
            D_001A4BE0.h36A = 1;
        info = func_00382348(D_L19_001E8E40.moby);
        if (info != 0 && (*(u16 *)(info + 0x1E) & 8))
            D_001A4BE0.h36A = 1;
        info = func_003C4D58(D_L19_001E8E40.moby);
        if (info != 0 && (*(s32 *)(info + 0x3C) & 8))
            D_001A4BE0.h36A = 1;
    }
    if (D_L19_001E8E40.count > 0) {
        *(vu0_q *)&D_001A4BE0.v2F0 = *(vu0_q *)&D_L19_001E8E40.v20;
        D_001A4BE0.f338.f = D_L19_001E8E40.v20.z;
        if (D_L19_001D677C)
            D_001A4BE0.f338.f = func_L01_00451580(&D_L19_001E8E40.v20);
        D_001A4BE0.f33C = func_0038CF00(&D_001A4BE0.pos, &D_001A4BE0.v2F0);
        D_001A4BE0.w35C = D_L19_001E8E40.moby;
        func_0012FE98(&D_001A4BE0.v2C0, &D_L19_001E8E40.v40);
        D_001A4BE0.f340.f = func_L01_00511848(&D_L19_001E8E40.v40);
        D_001A4BE0.f34C = func_0038D160(D_L19_001E8E40.v40.x, D_L19_001E8E40.v40.y);
        vec_sub_ba(&work, &D_001A4BE0.v2F0, &D_001A4BE0.pos);
        if (0.0f < func_0038CE68(&work, &D_001A4BE0.v2C0))
            D_001A4BE0.f33C = -D_001A4BE0.f33C;
        if (D_001A4BE0.f33C < 0.02f) {
            D_001A4BE0.h36C.s = 0;
            if (D_001A4BE0.f340.f <= 0.87266463f || D_001A4BE0.mode != 0) {
                D_001A4BE0.h36E.s = 0;
                D_001A4BE0.wBF0 = D_L19_001E8E40.moby;
            }
        }
    }
probed:
    if (D_001A4BE0.pos.z > D_001A4BE0.f350)
        D_001A4BE0.w358 = 0;
    if (D_001A4BE0.h36E.s != 0) {
        D_001A4BE0.w360 = 0;
    } else {
        D_001A4BE0.w360++;
        *(vu0_q *)&D_001A4BE0.v300 = *(vu0_q *)&D_001A4BE0.v2F0;
    }
    qzero(&D_001A4BE0.v2E0);
    switch (D_001A4BE0.mode) {
    case 0:
        D_001A4BE0.v2E0.z = -1.0f;
        break;
    case 1:
        if (D_001A4BE0.v310.w != 0.0f) {
            func_003C4138(&D_001A4BE0.v310.w, 0.0f, 1.0f);
            *(vu0_q *)&D_001A4BE0.v2E0 = *(vu0_q *)&D_001A4BE0.v310;
            func_0038CE20(&D_001A4BE0.v2C0, &D_001A4BE0.v2E0, -1.0f);
        } else {
            *(vu0_q *)&D_001A4BE0.v2E0 = *(vu0_q *)&D_001A4BE0.v2C0;
            func_0038CE20(&D_001A4BE0.v2E0, &D_001A4BE0.v2E0, -1.0f);
        }
        break;
    case 2:
        sign = -1.0f;
        if (D_001A4BE0.vB0.w > 0.0f)
            sign = 1.0f;
        vec_sub_ab(&D_001A4BE0.v2E0, &D_001A4BE0.vB0, &D_001A4BE0.pos);
        func_0038CF68(&D_001A4BE0.v2E0, &D_001A4BE0.v2E0, sign);
        break;
    }
    D_001A4BE0.f344.i = 0;
    D_001A4BE0.f348.i = 0;
    D_001A4BE0.f330.i[0] = 0;
    D_001A4BE0.f330.i[1] = 0;
    D_001A4BE0.f328.i[0] = 0;
    D_001A4BE0.f328.i[1] = 0;
    D_001A4BE0.f320.i[0] = 0;
    D_001A4BE0.f320.i[1] = 0;
    if (!(D_001A4BE0.f33C < 0.25f))
        return;
    if (!(D_001A4BE0.state_type == 0 || D_001A4BE0.state_type == 12 ||
          D_001A4BE0.state_type == 9 || D_001A4BE0.state_type == 7 ||
          (D_001A4BE0.state_type == 4 && D_001A4BE0.b46C) ||
          D_001A4BE0.state_type == 1))
        return;
    func_L01_004F40A8(&D_001A4BE0.v2C0, &work.x);
    if (-0.7853982f < work.y && work.y < 0.7853982f)
        D_001A4BE0.f344.f = work.y;
    if (-0.7853982f < work.x && work.x < 0.7853982f)
        D_001A4BE0.f348.f = work.x;
    for (side = 0; side < 2; side++) {
        angle = 1.5707964f;
        if (side == 1)
            angle = -angle;
        ((SideProbe_004E3CB8)func_L01_00511038)((char *)&sideStart, 0.2f, angle, 0.45f, 1);
        ((SideProbe_004E3CB8)func_L01_00511038)((char *)&sideEnd, 0.2f, angle, -0.45f, 1);
        if (func_003D3CB0(&sideStart, &sideEnd, 0x22, D_001A4BE0.moby, 0)) {
            if (D_L19_001D677C)
                D_001A4BE0.f320.f[side] = func_L01_00451580(&D_L19_001E8E40.v20) -
                                        func_L01_00451580(&D_001A4BE0.v2F0);
            else
                D_001A4BE0.f320.f[side] = D_L19_001E8E40.v20.z - D_001A4BE0.f338.f;
            if (0.4f < fabs_asm(D_001A4BE0.f320.f[side]))
                D_001A4BE0.f320.f[side] = 0.0f;
            func_0012FE98(&sideNormal, &D_L19_001E8E40.v40);
            func_L01_004F40A8(&sideNormal, &sideAngles.x);
            if (-0.7853982f < sideAngles.y && sideAngles.y < 0.7853982f)
                D_001A4BE0.f328.f[side] = sideAngles.y;
            if (-0.7853982f < sideAngles.x && sideAngles.x < 0.7853982f)
                D_001A4BE0.f330.f[side] = sideAngles.x;
        } else {
            D_001A4BE0.f320.i[side] = 0;
            D_001A4BE0.f328.f[side] = D_001A4BE0.f344.f;
            D_001A4BE0.f330.f[side] = D_001A4BE0.f348.f;
        }
    }
}
/* localdecomp:end func_L19_004E3CB8 */

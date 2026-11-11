#include "common.h"

typedef struct {
    u8 pad[104];
    s32 f68;
} Moby_0031BEF0;
typedef struct {
    u8 pad0[0x24];
    u8 *x24;
    u8 pad28[0xC];
    u16 h34;
} T_31DB28;
typedef struct {
    u8 pad0[0x18];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 pad1C[0x14];
} H_31DB28;
typedef struct {
    u8 pad0[0x6C];
    f32 f6C;
    u8 pad70[0x80];
} G_31DB28;
typedef struct {
    u8 pad0[0x18];
    T_31DB28 *x18;
} D_31DB28;
typedef struct { u8 b[320]; } E320_321CB8;
typedef struct { u8 b[160]; } E160_321CB8;
typedef struct { u8 x0; u8 x1; u8 pad[238]; } E240_321CB8;
typedef struct { u8 pad[80]; s32 idx; } Sub_00322E00;
typedef struct { u8 pad[104]; Sub_00322E00 *sub; } Moby_00322E00;

INCLUDE_ASM("asm/levels", func_L01_0031C1D0);

/* localdecomp:start func_L01_0031C348 */

extern s32 func_0038CAD0(s32);
extern void func_003C2880(Moby_0031BEF0 *);
extern void func_L01_00404A10_0031C348(void *, Moby_0031BEF0 *);
extern void func_L01_0031C398();

void func_L01_0031C348(Moby_0031BEF0 *m) {
    if (func_0038CAD0(m->f68)) {
        func_003C2880(m);
    } else {
        func_L01_00404A10_0031C348(func_L01_0031C398, m);
    }
}
/* localdecomp:end func_L01_0031C348 */

INCLUDE_ASM("asm/levels", func_L01_0031C398);

/* localdecomp:start func_L01_0031C770 */
void func_L01_0031C770(u8 *a0, u8 *a1, s8 *a2, s32 a3);

#define CHK(m) ((m) != 0 && *(u8 **)((m) + 36) != 0 && (*(u8 **)((m) + 36))[70] == 18)

void func_L01_0031C770(u8 *a0, u8 *a1, s8 *a2, s32 a3) {
    if (a1 == 0) {
        return;
    }
    if (*(s16 *)(a1 + 170) == 5669 && *(u8 **)(a1 + 104) != 0 && *(u8 **)(*(u8 **)(a1 + 104) + 1004) != 0) {
        func_L01_0031C770(a0, *(u8 **)(*(u8 **)(a1 + 104) + 1004), a2, a3);
    }
    if (a3 != 0) {
        if (a2[120] > 0) {
            *(u16 *)(a1 + 52) &= ~2;
        } else if (a2[120] < 0) {
            *(u16 *)(a1 + 52) |= 2;
        }
        if (a2[121] > 0 && !CHK(a1)) {
            a1[49] = 1;
            *(u16 *)(a1 + 52) &= ~1;
        } else if (a2[121] < 0 && !CHK(a1)) {
            a1[49] = 0;
            *(u16 *)(a1 + 52) |= 1;
        }
        if (a2[123] > 0 && *(u8 **)(a1 + 36) != 0) {
            *(s32 *)(a1 + 152) = *(s32 *)(*(u8 **)(a1 + 36) + 16);
        } else if (a2[123] < 0 && *(u8 **)(a1 + 36) != 0) {
            *(s32 *)(a1 + 152) = 0;
        }
        if (a2[124] != 0) {
            *(u16 *)(a0 + 52) |= 2;
        }
    } else {
        if (a2[120] > 0 && !CHK(a1)) {
            *(u16 *)(a1 + 52) |= 2;
        } else if (a2[120] < 0 && !CHK(a1)) {
            *(u16 *)(a1 + 52) &= ~2;
        }
        if (a2[121] > 0 && !CHK(a1)) {
            a1[49] = 0;
            *(u16 *)(a1 + 52) |= 1;
        } else if (a2[121] < 0 && !CHK(a1)) {
            a1[49] = 1;
            *(u16 *)(a1 + 52) &= ~1;
        }
        if (a2[123] > 0) {
            *(s32 *)(a1 + 152) = 0;
        } else if (a2[123] < 0) {
            *(s32 *)(a1 + 152) = *(s32 *)(*(u8 **)(a1 + 36) + 16);
        }
    }
}
/* localdecomp:end func_L01_0031C770 */

/* localdecomp:start func_L01_0031CA18 */
extern void func_L01_0031C770(u8 *a0, u8 *a1, s8 *a2, s32 a3);
extern short *D_L01_0021DE20[];
extern int D_L01_001E001C;

void func_L01_0031CA18(void *a0, void *a1, int a2, void *a3) {
    short *p = D_L01_0021DE20[a2];

    if (p != 0) {
        do {
            ((void (*)(void *, int, void *, void *))func_L01_0031C770)(a0, D_L01_001E001C + ((*p & 0x7FFF) << 8), a1, a3);
        } while (*p++ >= 0);
    }
}
/* localdecomp:end func_L01_0031CA18 */

INCLUDE_ASM("asm/levels", func_L01_0031CAA8);

/* localdecomp:start func_L01_0031CC48 */
extern void func_003C2880(Moby_0031BEF0 *);
extern s32 func_L01_003F7EE8(u8 *a0);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
void func_L01_0031CC48(u8 *a0) {
    switch (a0[32]) {
    case 0:
        if (func_L01_003F7EE8(a0)) {
            func_L01_004450F0(a0, 1, -1);
            *(u16 *)(a0 + 52) |= 0x2000;
        }
        break;
    case 1:
        func_L01_003F7EE8(a0);
        if (a0[35] < 2) {
            ((void (*)(u8 *a0))func_003C2880)(a0);
        } else {
            a0[35] -= 2;
        }
        break;
    }
}
/* localdecomp:end func_L01_0031CC48 */

LINKER_REMNANT("asm/levels", func_L01_0031CCE0);

INCLUDE_ASM("asm/levels", func_L01_0031CCE8);

INCLUDE_ASM("asm/levels", func_L01_0031D188);

/* localdecomp:start func_L01_0031D1D8 */
extern u8 *func_L01_0031D3D0(s32, s32, s32);

void func_L01_0031D1D8(u8 *a0, s32 a1, s32 a2) {
    u8 *r = func_L01_0031D3D0(a1, a2, *(s16 *)(a0 + 170) == 0xE9E);
    if (r != 0) {
        *(u8 **)(r + 184) = a0;
    }
}
/* localdecomp:end func_L01_0031D1D8 */

/* localdecomp:start func_L01_0031D218 */
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00443B88(f32 *, f32, f32);
extern u8 *func_L01_004669B0(f32, f32, f32, f32, u8 *, s32, f32 *, u32, s32);
extern void func_0038CF68(f32 *, s32, f32);
extern void func_L01_003006C0(u8 *, u8 *, s32, s32);
extern u8 D_L01_002AE8C0[];

void func_L01_0031D218(u8 *a0, u8 *a1, u8 *a2)
{
    f32 local[4];
    f32 f;
    s32 i;
    u32 v;
    u32 w;
    u32 x;
    u8 *r;

    for (i = 19; i >= 0; i--) {
        func_00382468(2);
        func_00382468(2);
        f = func_003824E0(70000.0f, 150000.0f);
        v = func_00382498(10, 127);
        w = (v << 8) | 0x7f000000U;
        x = (v << 16) | w;
        v = x | v;
        func_L01_00443B88(local, 2.0000004e-05f, 0.008f);
        r = func_L01_004669B0(0.3f, 1.0f, 1.01f, f, a1, 0, local, v, 1);
        if (r != 0) {
            u8 *q = r + 32;

            *(s16 *)(r + 10) = 100;
            *(s32 *)(q + 4) = 2;
            *(u8 *)(q + 10) = 127;
            *(u8 *)(q + 11) = *(u8 *)(r + 10);
        }
    }
    func_0038CF68((f32 *)D_L01_002AE8C0, (s32)a2, 1.5f);
    func_L01_003006C0(D_L01_002AE8C0, a1, 0, 0);
}
/* localdecomp:end func_L01_0031D218 */

/* localdecomp:start func_L01_0031D398 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_0031D398(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0031D398 */

INCLUDE_ASM("asm/levels", func_L01_0031D3D0);

INCLUDE_ASM("asm/levels", func_L01_0031D510);

/* localdecomp:start func_L01_0031DB60 */
void func_L01_0031DB60(u8 *a) {
    a[32] = 2;
}
/* localdecomp:end func_L01_0031DB60 */

/* localdecomp:start func_L01_0031DB70 */
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_003303B8(float, u8 *,
                              s32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32,
                              s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                              float, float, float);
extern void func_L01_004C7D98(u8 *, float *);
extern void func_0038CF68(f32 *, s32, f32);
extern void func_0038CE90(float *, float *, float *);
extern float func_00382538(void);
extern float func_003824E0(float, float);
extern void func_00382760(float *, float, float, float);
extern void func_0038D000(float *, float *, float *);
extern u8 *func_L01_0031E788(u8 *, float *, s32, s32, s32);
extern void func_L01_004C8668(s32);
extern s32 D_L01_001DAFEC;
__asm__(".extern D_L01_001DC874, 4");
extern s32 D_L01_001DC874;

void func_L01_0031DB70(u8 *object) {
    int i;
    float basis[3][4];
    float perpendicular[4];
    float direction[4];
    u8 *state = *(u8 **)(object + 0x68);
    u8 *fragment;
    float strength;
    float heading;
    float elevation;
    float speed;
    int j;

    func_003A52A0(0, 0, object);
    strength = 0.7f;
    for (j = 0; j < 2; j++) {
        func_L01_003303B8(strength, object + 0x10, 1, 14, 10, 15, 10, 20, 0,
                          1, 0, 1, 0, 0, 0, 0, D_L01_001DAFEC, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                          0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0, 0.0f, 0.0f, 0.0f);
        strength += 0.3f;
    }
    func_L01_004C7D98(object + 0x10,basis[2]);
    perpendicular[0] = basis[2][2];
    perpendicular[1] = basis[2][2];
    perpendicular[2] = -(basis[2][0] + basis[2][1]);
    func_0038CF68(basis[0], (s32)perpendicular, 1.0f);
    func_0038CE90(basis[1], basis[0], basis[2]);
    basis[0][3] = basis[1][3] = basis[2][3] = 0.0f;
    for (i = 0; i < D_L01_001DC874; i++) {
        heading = func_00382538();
        if (*(s32 *)(state + 0x2C) != 0) {
            elevation = func_003824E0(0.69813168f, 1.30899692f);
            speed = func_003824E0(4.0f, 12.0f) * 0.020000001f;
        } else {
            elevation = func_003824E0(0.87266463f, 1.57079637f);
            speed = func_003824E0(4.0f, 9.0f) * 0.020000001f;
        }
        func_00382760(direction, speed, heading, elevation);
        direction[3] = 0.0f;
        func_0038D000(direction, direction, basis[0]);
        fragment = func_L01_0031E788(object + 0x10,direction, i, *(s32 *)(state + 0x2C), 0);
        if (fragment != 0) *(s32 *)(fragment + 0xB8) = *(s32 *)(object + 0xB8);
    }
    func_L01_004C8668(*(s32 *)(state + 0x30));
}
/* localdecomp:end func_L01_0031DB70 */

INCLUDE_ASM("asm/levels", func_L01_0031DE80);

/* localdecomp:start func_L01_0031DFD8 */

extern D_31DB28 D_L01_001EAA00[];
extern T_31DB28 *D_001A71A0[];
extern u8 D_0014263F[];
extern G_31DB28 D_L01_002C5600[];
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern void func_0038CF68(f32 *, s32, f32);
extern void func_L01_00446760(H_31DB28 *, u8 *, s32, f32 *, f32);
extern void func_L01_00446978(T_31DB28 *, H_31DB28 *);
extern void func_L01_0031E3B8(u8 *, s32, s32, u8 *);

void func_L01_0031DFD8(u8 *obj, void *a1) {
    f32 v[4];
    H_31DB28 h;
    s32 m = *(s32 *)(obj + 104);
    T_31DB28 *t;

    if (func_003D3CB0(a1, obj + 16, 0, obj, 0) == 0) {
        return;
    }
    t = D_L01_001EAA00[0].x18;
    if (t != 0) {
        if (t != D_001A71A0[0] && (t->x24[70] == 5 || (t->h34 & 0x4000))) {
            func_0038CF68(v, m, 1.0f);
            func_L01_00446760(&h, obj, 0x410000, v, (D_L01_002C5600 + D_0014263F[0])->f6C * 0.1f);
            h.b18 = 5;
            h.b19 = 3;
            h.h1A = *(u16 *)(obj + 170);
            func_L01_00446978(D_L01_001EAA00[0].x18, &h);
            func_L01_0031E3B8(obj + 16, 10, 1, obj);
        }
        if (D_L01_001EAA00[0].x18 != 0) {
            obj[32] = 2;
            return;
        }
    }
    func_L01_0031E3B8(obj + 16, 15, 0, obj);
    obj[32] = 2;
}
/* localdecomp:end func_L01_0031DFD8 */

INCLUDE_ASM("asm/levels", func_L01_0031E148);

INCLUDE_ASM("asm/levels", func_L01_0031E3B8);

/* localdecomp:start func_L01_0031E788 */
typedef int s128_0031E788 __attribute__((mode(TI)));
typedef struct {
    f32 velocity[4];
    f32 spin[4];      /* 0x10 */
    s16 life;         /* 0x20: frames */
    s16 arm;          /* 0x22: frames until armed */
    s32 heavy;        /* 0x24 */
    s32 x28;
    s32 annihilator;  /* 0x2C: one of the Annihilator's mines */
} Bomblet_0031E788;

__asm__(".extern D_L01_001DC8A4, 4");
__asm__(".extern D_L01_001DC8A8, 4");
__asm__(".extern D_L01_001DC8B4, 4");
__asm__(".extern D_L01_001DC8B8, 4");
__asm__(".extern D_L01_001DC8C4, 4");
extern s32 D_L01_001DC8A4;
extern s32 D_L01_001DC8A8;
extern f32 D_L01_001DC8B4;
extern f32 D_L01_001DC8B8;
extern s32 D_L01_001DC8C4;
extern u8 *func_003C24B0(s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_0038D308(u8 *matrix, u8 *rotation);
extern f32 func_003824E0(f32, f32);
extern void func_003C4840(f32 *out, u8 *axis, f32 angle);
extern s32 func_L01_004C85C8(u8 *moby, s32 a1, f32 x, f32 y, f32 z);
extern void func_L01_00445F40(u8 *moby, s32 class_id);
extern void func_003C7C38(u8 *moby);

/* bouncer_bomblet_spawn: (position, velocity, index, heavy, annihilator): one of the
   Bouncer's bomblets (class 0xECE), or of the Annihilator's V2-V4 mines (model class 0x1897
   at 0.275 of its scale, 0.55 heavy): a life of 240-360 frames and armed after 70 plus its
   index (both x 5/6 for PAL's 50 Hz, rounded), at a random roll, spinning 3.6-7.2 degrees
   a frame. */
u8 *func_L01_0031E788(u8 *pos, f32 *velocity, s32 index, s32 heavy, s32 annihilator)
{
    u8 *bomblet = func_003C24B0(0xECE, 0x80);
    Bomblet_0031E788 *vars;
    f32 spin;

    if (bomblet != 0) {
        s32 opaque = 0xFF;

        bomblet[0x20] = 0;
        *(u16 *)(bomblet + 0x32) = opaque;
        bomblet[0x30] = opaque;
        vars = *(Bomblet_0031E788 **)(bomblet + 0x68);
        *(s128_0031E788 *)(bomblet + 0x10) = *(s128_0031E788 *)pos;
        *(s128_0031E788 *)vars->velocity = *(s128_0031E788 *)velocity;
        vars->life = (func_00382498(D_L01_001DC8A4, D_L01_001DC8A8) * 5 + 2) / 6;
        *(u16 *)(bomblet + 0x34) |= 0x100; /* its matrix (+0xC0) drawn as set */
        *(f32 *)(bomblet + 0xF0) = func_00382538();
        *(f32 *)(bomblet + 0xF4) = func_00382538();
        *(f32 *)(bomblet + 0xF8) = func_00382538();
        vars->annihilator = annihilator;
        func_0038D308(bomblet + 0xC0, bomblet + 0xF0);
        spin = func_003824E0(0.06283186f, 0.12566371f);
        func_003C4840(vars->spin, bomblet + 0xD0, spin);
        vars->heavy = heavy;
        vars->arm = index + (D_L01_001DC8C4 * 5 + 2) / 6;
        /* the moby's scale (+0x2C): x 1.5 heavy, else x 0.75 */
        if (heavy != 0) {
            *(f32 *)(bomblet + 0x2C) = *(f32 *)(bomblet + 0x2C) * D_L01_001DC8B8;
        } else {
            *(f32 *)(bomblet + 0x2C) = *(f32 *)(bomblet + 0x2C) * D_L01_001DC8B4;
        }
        vars->x28 = func_L01_004C85C8(bomblet, 0, 1.0f, 1.0f, 1.0f);
        if (annihilator != 0) {
            /* the mine's model, scaled from its class's scale (class + 0x24) */
            func_L01_00445F40(bomblet, 0x1897);
            if (heavy != 0) {
                *(f32 *)(bomblet + 0x2C) = *(f32 *)(*(u8 **)(bomblet + 0x24) + 0x24) * 0.55f;
            } else {
                *(f32 *)(bomblet + 0x2C) = *(f32 *)(*(u8 **)(bomblet + 0x24) + 0x24) * 0.275f;
            }
        }
        func_003C7C38(bomblet);
    }
    return bomblet;
}
/* localdecomp:end func_L01_0031E788 */

INCLUDE_ASM("asm/levels", func_L01_0031E968);

/* localdecomp:start func_L01_0031F258 */
void func_L01_0031F258(u8 *a) {
    a[32] = 2;
}
/* localdecomp:end func_L01_0031F258 */

INCLUDE_ASM("asm/levels", func_L01_0031F268);

INCLUDE_ASM("asm/levels", func_L01_0031F2E8);

INCLUDE_ASM("asm/levels", func_L01_0031F688);

/* localdecomp:start func_L01_0031FBC0 */
extern void func_L01_0031FD50(u8 *a0);
extern u8 *func_L01_0046CA28(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_L01_0031FC60(u8 *a0);
extern f32 func_0038DAB8(f32, f32);

void func_L01_0031FBC0(u8 *a0) {
    u8 *p;

    if (a0[32] == 0) {
        func_L01_0031FD50(a0);
        p = func_L01_0046CA28(a0 + 16, 12, 0, 0);
        if (p != 0) {
            *(f32 *)(p + 12) = 157500.0f;
        }
        *(f32 *)(a0 + 240) = func_0038DAB8(*(f32 *)(a0 + 240), 0.041887905f);
        *(f32 *)(a0 + 244) = func_0038DAB8(*(f32 *)(a0 + 244), 0.15707964f);
        func_L01_0031FC60(a0);
    }
}
/* localdecomp:end func_L01_0031FBC0 */

INCLUDE_ASM("asm/levels", func_L01_0031FC60);

INCLUDE_ASM("asm/levels", func_L01_0031FD50);

INCLUDE_ASM("asm/levels", func_L01_00320088);

/* localdecomp:start func_L01_00321608 */
typedef int s128_00321608 __attribute__((mode(TI)));
typedef union {
    s128_00321608 q;
    f32 f[4];
} End_00321608;

__asm__(".extern D_L01_001DC940, 4");
extern s32 D_L01_001DC940;
extern End_00321608 D_L01_00276A30[];
extern u8 *func_L01_00322100(u8 *gun);
extern void func_L01_004CB128(void *at, u8 *target, s32 flag);
extern f32 func_003824E0(f32, f32);

/* hydra_arc_ends_set: sets the ends of the Spitting Hydra's spit arcs (the level's number,
   D_L01_001DC940) at the point in the gun's vars, 32 u along the aim; where func_L01_00322100
   picks a target it gets the target mark, and an end with none is jittered up to 0.2 on
   each axis. */
void func_L01_00321608(u8 *gun)
{
    End_00321608 *vars = *(End_00321608 **)(gun + 0x68);
    u8 *target;
    s32 i;

    for (i = 0; i < D_L01_001DC940; i++) {
        target = func_L01_00322100(gun);
        if (target != 0) {
            func_L01_004CB128(vars, target, 0);
        }
        D_L01_00276A30[i].q = vars->q;
        if (target == 0) {
            D_L01_00276A30[i].f[0] += func_003824E0(-0.2f, 0.2f);
            D_L01_00276A30[i].f[1] += func_003824E0(-0.2f, 0.2f);
            D_L01_00276A30[i].f[2] += func_003824E0(-0.2f, 0.2f);
        }
    }
}
/* localdecomp:end func_L01_00321608 */

INCLUDE_ASM("asm/levels", func_L01_00321710);

INCLUDE_ASM("asm/levels", func_L01_003218A8);

INCLUDE_ASM("asm/levels", func_L01_00321A80);

INCLUDE_ASM("asm/levels", func_L01_00321F88);

INCLUDE_ASM("asm/levels", func_L01_003220A0);

INCLUDE_ASM("asm/levels", func_L01_003220D0);

INCLUDE_ASM("asm/levels", func_L01_00322100);

INCLUDE_ASM("asm/levels", func_L01_00322180);

/* localdecomp:start func_L01_003221B8 */
extern G_31DB28 D_L01_002C5600[];

extern s32 D_L01_001E17B0;
extern s32 D_L01_001DBCA0;
extern u8 D_00142607[];
extern E320_321CB8 D_L01_00276AA0[];
extern E160_321CB8 D_L01_00276D20[];
extern f32 func_003824E0(f32, f32);
extern void func_L01_003225F8(void *, s32, s32, u32, f32, f32, u32, s32, void *, s32, s32);

void func_L01_003221B8(u8 *a0) {
    s32 half;
    s32 i;
    f32 f;

    s32 t;
    half = D_L01_001E17B0 / 2;
    t = *(s32 *)(*(u8 **)(a0 + 104) + 68);
    D_L01_001DBCA0 |= 1;
    if (t != 0) {
        for (i = 0; i < 2; i++) {
            f = func_003824E0(0.025f, 0.03f);
            func_L01_003225F8(&D_L01_00276AA0[i], 20, half, 0x7F7F7F, f, func_003824E0(1.5f, 2.5f), 0xFF2020, 0, a0, 0, 1);
        }
        if (D_L01_001E17B0 >= 20 && (((E240_321CB8 *)&D_L01_002C5600) + D_00142607[0])->x1 >= 2) {
            for (i = 0; i < 2; i++) {
                f = func_003824E0(0.015f, 0.02f);
                func_L01_003225F8(&D_L01_00276D20[i], 10, half, 0xFF7F7F7F, f, func_003824E0(1.2f, 1.8f), 0xFFFF2020, 0, a0, 1, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_003221B8 */

INCLUDE_ASM("asm/levels", func_L01_00322398);

/* localdecomp:start func_L01_00322570 */
void func_L01_00322570(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_00322570 */

INCLUDE_ASM("asm/levels", func_L01_003225F8);

/* localdecomp:start func_L01_00322F80 */
__asm__(".extern D_L01_001DC93C, 4");
extern s32 D_L01_001DC93C;
extern u8 D_L01_001D66B0[8];
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_00424CB0(void *pos, f32 radius, f32 x, f32 r, f32 g, f32 b);
extern void func_L01_00323120(f32 *muzzle, u8 *zero, f32 charge);
extern void func_L01_00323080(f32 *muzzle);

/* hydra_charge_glow: the Spitting Hydra's muzzle look each frame at charge c: a light of
   radius 4c (made once; its slot is kept in D_L01_001DC93C, -1 for none), the glows sized
   by c, and from c 0.45 the glare. */
void func_L01_00322F80(u8 *gun, f32 *muzzle, f32 charge)
{
    u8 *vars = *(u8 **)(gun + 0x68);

    if (D_L01_001DC93C == -1) {
        /* blue-white: r 0.1-0.35, g 0.35, b 0.75-1 */
        D_L01_001DC93C = func_L01_00424CB0(vars + 0x10, charge * 4.0f, 0.0f,
                                           func_003824E0(0.1f, 0.35f), 0.35f,
                                           func_003824E0(0.75f, 1.0f));
    }
    /* D_L01_001D66B0, a zero vector, goes unused */
    func_L01_00323120(muzzle, D_L01_001D66B0, charge);
    if (0.45f <= charge) {
        func_L01_00323080(muzzle);
    }
}
/* localdecomp:end func_L01_00322F80 */

INCLUDE_ASM("asm/levels", func_L01_00323080);

LINKER_REMNANT("asm/levels", func_L01_00323118);

/* localdecomp:start func_L01_00323120 */
extern u8 D_L01_001D66B0[8];
extern u8 *D_L01_00221208[];
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046A610(f32 *pos, u8 *velocity, s32 life, s32 alpha, s32 rgb, s32 spin,
                             f32 size, f32 growth, f32 f14, f32 f15, f32 f16);

/* hydra_muzzle_glows: the Spitting Hydra's muzzle glows sized by its charge, each frame with
   even odds: a 0x2C of 6 x the charge in (0x20, 0x40, 0x90) at alpha 6 with particle type
   0x5C's texture 1, and one of 2.4 x the charge in (0x20, 0x40, 0x80) at 0x7F with its
   texture 0, jittered +-0.04, half added and half blended. */
void func_L01_00323120(f32 *muzzle, u8 *zero, f32 charge)
{
    f32 size = charge * 210000.0f;
    f32 at[4];
    u8 *glow;

    /* spun +-1, growing 500 (/ 210000) a frame */
    if (func_00382468(2) != 0) {
        glow = func_L01_0046A610(muzzle, D_L01_001D66B0, 12, 6, 0x904020,
                                 (s32)func_L01_00443A18(1.0f, -1.0f), size * 6.0f, 500.0f,
                                 1.0f, 0.0f, 2.0f);
        if (glow != 0) {
            glow[2] = D_L01_00221208[0][1];
        }
    }
    /* the second jittered up to 0.04 either way */
    at[0] = muzzle[0] + func_L01_00443A18(0.0f, 0.04f);
    at[1] = muzzle[1] + func_L01_00443A18(0.0f, 0.04f);
    at[2] = muzzle[2] + func_L01_00443A18(0.0f, 0.04f);
    if (func_00382468(2) != 0) {
        glow = func_L01_0046A610(at, D_L01_001D66B0, 12, 0x7F, 0x804020,
                                 (s32)func_L01_00443A18(1.0f, -1.0f), size * 2.4f, 500.0f,
                                 1.0f, 0.0f, 2.0f);
        if (glow != 0) {
            glow[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
            glow[2] = D_L01_00221208[0][0];
        }
    }
}
/* localdecomp:end func_L01_00323120 */

/* localdecomp:start func_L01_00323300 */
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
void func_L01_00323300(Moby_00322E00 *m) {
    Sub_00322E00 *s = m->sub;
    s32 i = s->idx;
    if (i != -1) {
        u8 *e = D_001A30B0 + i * 128;
        if (*(Moby_00322E00 **)(e + 220) == m && e[208] != 0) func_003A4F28(i);
    }
    s->idx = -1;
}
/* localdecomp:end func_L01_00323300 */

INCLUDE_ASM("asm/levels", func_L01_00323368);

INCLUDE_ASM("asm/levels", func_L01_00323A18);

INCLUDE_ASM("asm/levels", func_L01_00323C68);

INCLUDE_ASM("asm/levels", func_L01_00323F38);

LINKER_REMNANT("asm/levels", func_L01_00324160);

INCLUDE_ASM("asm/levels", func_L01_00324180);

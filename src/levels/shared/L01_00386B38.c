#include "common.h"

typedef struct {
    u8 pad0[104];
    u8 *inner;
} Obj3899C0;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q[5];
} S_2BEE10;

INCLUDE_ASM("asm/levels", func_L01_00386B38);

INCLUDE_ASM("asm/levels", func_L01_003882A0);

/* localdecomp:start func_L01_003884D8 */
#include "vu0.h"

extern void func_0038CE20(void *, void *, f32);
extern f32 D_L01_001DDE14;
extern f32 D_L01_001DDE10;
extern f32 D_L01_001DDE0C;
extern s32 D_L01_001DDE30;
extern s32 D_L01_001DDE34;
__asm__(".extern D_L01_001DDE14,4");
__asm__(".extern D_L01_001DDE10,4");
__asm__(".extern D_L01_001DDE0C,4");
__asm__(".extern D_L01_001DDE30,4");
__asm__(".extern D_L01_001DDE34,4");
extern f32 D_L01_001E1EC0;
extern s32 D_L01_001E1EBC;

void func_L01_003884D8(u8 *obj) {
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32,f32);
    extern void func_0038D328(s128 *,S_38C110v *);
    extern void func_003D9740(s128 *,s32,u32,s32,s32,f32);
    s128 mat[4];
    S_38C110v pos;
    S_38C110v dir;
    S_38C110v rot;
    S_38C110v offset;
    u8 *basis=obj+0xD0;
    pos=*(S_38C110v *)(*(u8 **)(obj+0x68)+0x10);
    func_0038CE20(&dir,basis,-1.0f);
    rot.x=0;
    rot.y=-func_0038D160(func_0038CED8(&dir),dir.z) + -1.5707964f;
    rot.z=func_0038D160(dir.x,dir.y);
    rot.w=1.0f;
    func_0038D328(mat,&rot);
    func_0038CE20(&offset,basis,-1.0f);
    func_0038CE20(&offset,&offset,5.0f);
    vec_add_ab(&pos,&pos,&offset);
    mat[3]=*(s128 *)&pos;
    func_0038CE20(&mat[0],&mat[0],D_L01_001DDE14);
    func_0038CE20(&mat[1],&mat[1],D_L01_001DDE10);
    func_0038CE20(&mat[2],&mat[2],D_L01_001DDE0C);
    D_L01_001E1EC0+=0.2f;
    if (D_L01_001E1EC0>=7.0f) D_L01_001E1EC0-=7.0f;
    func_003D9740(mat,D_L01_001DDE30,((D_L01_001E1EBC*5)<<24)|0xFF8080,4,1,D_L01_001E1EC0);
    func_0038CE20(&mat[0],&mat[0],D_L01_001DDE14*1.25f);
    func_0038CE20(&mat[1],&mat[1],D_L01_001DDE10*1.25f);
    func_003D9740(mat,D_L01_001DDE34,((D_L01_001E1EBC*3)<<24)|0xBF0530,2,1,D_L01_001E1EC0);
}
/* localdecomp:end func_L01_003884D8 */

INCLUDE_ASM("asm/levels", func_L01_003886E8);

INCLUDE_ASM("asm/levels", func_L01_00388AC8);

INCLUDE_ASM("asm/levels", func_L01_00388EE0);

/* localdecomp:start func_L01_00389798 */
typedef struct {
    u8 pad_0[0x10];
    u8 position[0x10];
} ShotVars_389798;
typedef struct {
    u8 pad_0[0x68];
    ShotVars_389798 *vars;
} Moby_389798;

/* The screen warp's timer: 6 frames for an uncharged shot, 27 charged (0x1E1F20 on NTSC-U) */
extern s32 D_L01_001E1EA0;
extern void func_L01_00389810(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d);

/* shock_cannon_warp: the Shock Cannon's screen warp each frame its timer runs: texture 66 at
   5 x the timer; the four floats (1, 0, 0, 0.9) aren't read */
void func_L01_00389798(Moby_389798 *shot) {
    func_L01_00389810(shot->vars->position, 0x42, D_L01_001E1EA0 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_00389798 */

/* localdecomp:start func_L01_003897E8 */
/* The charged lance's beam state (0x1E1F50 on NTSC-U); declared small so its address is one la,
   as retail builds it. */
extern u8 D_L01_001E1ED0[8];
/* The beam's numbers: fade times, half width, texture spacing (0x2B3C90 on NTSC-U) */
extern u8 D_L01_002B3C10[];
extern void func_L01_0040B858(void *beam, void *numbers);

/* shock_cannon_beam_draw: draws the Shock Cannon's charged lance beam with fx_beam_rings:
   texture 69 from the gun 40 u along the aim */
void func_L01_003897E8(void) {
    func_L01_0040B858(D_L01_001E1ED0, D_L01_002B3C10);
}
/* localdecomp:end func_L01_003897E8 */

/* localdecomp:start func_L01_00389810 */
extern s32 D_001D5520;
extern s16 D_001CFEC0[];
extern s32 D_L01_001DDE38;
__asm__(".extern D_L01_001DDE38, 4");
extern s32 D_L01_001DDE40;
__asm__(".extern D_L01_001DDE40, 4");
extern s32 D_L01_001DDE44;
__asm__(".extern D_L01_001DDE44, 4");
extern s32 D_L01_001DDE48;
__asm__(".extern D_L01_001DDE48, 4");
extern s32 D_L01_001DDE4C;
__asm__(".extern D_L01_001DDE4C, 4");
extern s32 D_L01_001DDE50;
__asm__(".extern D_L01_001DDE50, 4");
extern s32 D_L01_001DDE54;
__asm__(".extern D_L01_001DDE54, 4");
extern s32 D_L01_001DDE58;
__asm__(".extern D_L01_001DDE58, 4");
extern s32 D_L01_001DDE5C;
__asm__(".extern D_L01_001DDE5C, 4");
extern s32 D_L01_001DDE60;
__asm__(".extern D_L01_001DDE60, 4");
extern s32 D_L01_001DDE64;
__asm__(".extern D_L01_001DDE64, 4");
extern s32 D_L01_001DDE68;
__asm__(".extern D_L01_001DDE68, 4");
extern s32 D_L01_001DDE6C;
__asm__(".extern D_L01_001DDE6C, 4");
extern s32 D_L01_001DDE70;
__asm__(".extern D_L01_001DDE70, 4");
extern s32 D_L01_001DDE94;
__asm__(".extern D_L01_001DDE94, 4");
extern void func_L01_004C5E28(void);
/* the file's earlier blocks declare it with a 32-bit value; these calls pass the full 64-bit GS register */
extern void func_003A9440(s32, unsigned long);
extern unsigned long func_00389598(s32 a);
extern void func_0038B4D0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, long i, long j);

/* shock_cannon_warp_draw: the screen warp, texture 66 into the frame's alpha in four mirrored quarters, then the frame's copy mixed in */
void func_L01_00389810(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d) {
    long tex, col;

    func_L01_004C5E28();
    if (D_001D5520 != 0) {
        D_L01_001DDE94 = -1;
        D_L01_001DDE6C = 0xEC;
        D_L01_001DDE70 = 0xF0;
    }
    ((void (*)(s32, long))func_003A9440)(0x47, 0x513F1);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE44 | ((long)D_L01_001DDE48 << 2) | ((long)D_L01_001DDE4C << 4) | ((long)D_L01_001DDE50 << 6)) | (0x8000L << 24));
    tex = func_00389598(D_L01_001DDE38);
    col = (s32)((alpha << 24) | 0x7F7F7F);
    func_0038B4D0(0, 0, (s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], 0, -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(0, D_001CFEC0[0xA9], (s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], D_001CFEC0[0xA9], -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE44 | ((long)D_L01_001DDE48 << 2) | ((long)D_L01_001DDE4C << 4) | ((long)D_L01_001DDE50 << 6)) | (0x8000L << 24));
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE54 | ((long)D_L01_001DDE58 << 2) | ((long)D_L01_001DDE5C << 4) | ((long)D_L01_001DDE60 << 6)) | (0x8000L << 24));
    func_0038B4D0(0, 0, D_001CFEC0[0xA8], D_001CFEC0[0xA9], D_L01_001DDE64, D_L01_001DDE68, D_L01_001DDE6C, D_L01_001DDE70, D_L01_001DDE40, func_00389598(D_L01_001DDE94));
}
/* localdecomp:end func_L01_00389810 */

/* localdecomp:start func_L01_00389B00 */
#include "vu0.h"
typedef struct {
    s128 position;             /* 0x00 */
    u8 pad_10[0x10];
    vu0_v4 velocity;           /* 0x20 */
    u8 pad_30[4];
    s32 owner;                 /* 0x34 */
    s32 life;                  /* 0x38 */
    f32 fade;                  /* 0x3C */
    u8 pad_40[0x10];
    vu0_v4 back;               /* 0x50 */
    f32 value;                 /* 0x60 */
} Vars_00389B00;
typedef struct {
    u8 pad_0[0x10];
    s128 pos;                  /* 0x10 */
    u8 b20;                    /* 0x20 */
    u8 pad_21[0xF];
    u8 b30;                    /* 0x30 */
    u8 b31;                    /* 0x31 */
    u16 h32;                   /* 0x32 */
    u16 h34;                   /* 0x34 */
    u8 pad_36[0x68 - 0x36];
    Vars_00389B00 *vars;       /* 0x68 */
} Moby_00389B00;
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0038A4B8(void *);

Moby_00389B00 *func_L01_00389B00(s128 *position, void *direction, s128 *rotation, s32 owner, f32 value)
{
    Moby_00389B00 *moby = (Moby_00389B00 *)func_003C24B0(0x1883, 0x80);
    if (moby != 0) {
        Vars_00389B00 *vars = moby->vars;
        s128 *pos = &moby->pos;
        vu0_v4 back;
        moby->b30 = 0xFF;
        moby->b20 = 0;
        moby->h32 = 0xFF;
        moby->b31 = 1;
        moby->h34 |= 0x41;
        func_0038CF68(&vars->velocity, direction, 0.16000001f);
        vars->position = *position;
        moby->pos = *rotation;
        func_0038CF68(&back, &vars->velocity, -1.5f);
        vec_add_ab(&vars->back, position, &back);
        vars->value = value;
        vars->owner = owner;
        vars->fade = 0.05882353f;
        vars->life = 17;
        func_L01_0038A4B8(pos);
    }
    return moby;
}
/* localdecomp:end func_L01_00389B00 */

INCLUDE_ASM("asm/levels", func_L01_00389C28);

INCLUDE_ASM("asm/levels", func_L01_0038A0F8);

INCLUDE_ASM("asm/levels", func_L01_0038A4B8);

/* localdecomp:start func_L01_0038A708 */
typedef struct {
    u8 pad_0[0x1D8];
    s32 i1D8;                  /* 0x1D8 */
    u8 pad_1DC[0x6F0 - 0x1DC];
    S_38C110v aim;             /* 0x6F0 */
    u8 pad_700[0x1210 - 0x700];
    s32 fire_button;           /* 0x1210 */
    u8 pad_1214[0x1220 - 0x1214];
    s32 i1220;                 /* 0x1220 */
    u8 pad_1224[0x1430 - 0x1224];
    u8 *lockon_target;         /* 0x1430 */
    u8 pad_1434[0x25C0 - 0x1434];
    u8 *moby;                  /* 0x25C0 */
    s32 state;                 /* 0x25C4 */
    u8 pad_25C8[0x25E9 - 0x25C8];
    u8 b25E9;                  /* 0x25E9 */
    u8 pad_25EA[0x25ED - 0x25EA];
    u8 no_firing;              /* 0x25ED */
    u8 pad_25EE[0x28BC - 0x25EE];
    s32 aiming_fire_wait;      /* 0x28BC */
} Hero_0038A708;
typedef struct {
    u8 pad_0[0x10];
    u8 landing[0x10];          /* 0x10 */
    f32 timer;                 /* 0x20 */
    s32 w24;                   /* 0x24 */
    s32 w28;                   /* 0x28 */
    s32 rumble;                /* 0x2C */
} Vars_0038A708;
typedef struct {
    u8 pad_0[0x20];
    u8 phase;                  /* 0x20 */
    u8 pad_21[0x42 - 0x21];
    u8 b42;                    /* 0x42 */
    u8 b43;                    /* 0x43 */
    u8 pad_44[0x60 - 0x44];
    u8 b60;                    /* 0x60 */
    u8 pad_61[0x68 - 0x61];
    Vars_0038A708 *vars;       /* 0x68 */
} Moby_0038A708;
typedef struct { u8 pad_0[0x50]; f32 rate; u8 pad_54[0xF0 - 0x54]; } Row_0038A708;
typedef struct { s32 w[5]; } Skip_0038A708;
typedef struct { s32 w[6]; } Skip2_0038A708;
extern Hero_0038A708 D_001A4BE0_0038A708;
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern u8 D_00142637[];
extern u8 D_L01_001DAFF0_0038A708;
extern s32 D_L01_001D673C_0038A708;
extern s32 D_L01_001E1F10_0038A708;
extern f32 D_L01_001DDEA8_0038A708;
__asm__(".extern D_L01_001DDEA8_0038A708, 4");
extern f32 D_L01_001DDEAC_0038A708;
__asm__(".extern D_L01_001DDEAC_0038A708, 4");
extern f32 D_L01_001DDEB0_0038A708;
__asm__(".extern D_L01_001DDEB0_0038A708, 4");
extern f32 D_L01_001DDEB4_0038A708;
__asm__(".extern D_L01_001DDEB4_0038A708, 4");
extern Skip_0038A708 D_L01_001DDEB8_0038A708;
extern Skip2_0038A708 D_L01_001DDED0_0038A708;
extern u8 D_L01_002B3C60_0038A708[];
extern Row_0038A708 D_L01_002C5600_0038A708[];
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00444F38_0038A708(u8 *, s32, s32, s32, s32);
extern u8 *func_00382348(void *);
extern s32 func_0038CAD0(void *);
extern u8 *func_L01_004501E8_0038A708(void *, void *, f32, f32, f32, f32, void *, s32, s32, s32, f32, s32, void *, s32, s32, s32);
extern void func_L01_0038AD40_0038A708(void *, void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L01_004C7A18_0038A708(f32, void *, void *, void *, void *, void *, s32, s32);
extern void func_L01_004EAA80_0038A708(void);
extern s32 func_L01_005118D0_0038A708(s32, s32);
extern void func_L01_004EA7D8_0038A708(s32);
extern s32 func_L01_003F2058_0038A708(void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00362610_0038A708(void *, void *, void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_005119E0_0038A708(s32);
extern void func_L01_003F2278_0038A708(s32, void *);
extern s32 func_L01_0040E050_0038A708(void *);
extern void func_L01_00404A10_0038A708(void *, void *);
extern void func_L01_0038ACE8_0038A708(void *);

void func_L01_0038A708(Moby_0038A708 *m)
{
    Vars_0038A708 *vars = m->vars;
    u8 *target;
    S_38C110v pos;
    union { Skip_0038A708 skip; S_38C110v dir; } u;
    Skip2_0038A708 skip2;
    s32 at;
    s32 at2;
    s32 can_fire;

    func_003C2F58(m, 0, &pos);
    if (m->b42 == m->b43 && (m->b60 & 2))
        func_L01_00444F38_0038A708((u8 *)m, 1, 0, 2, 0);
    target = 0;
    if (D_001A4BE0_0038A708.lockon_target != 0 && D_001A4BE0_0038A708.lockon_target[0x20] != 0xFE &&
        D_001A4BE0_0038A708.lockon_target[0x20] != 0xFD) {
        f32 *health = (f32 *)func_00382348(D_001A4BE0_0038A708.lockon_target);
        if (health != 0 && 0.0f < *health)
            target = D_001A4BE0_0038A708.lockon_target;
    }
    can_fire = 1;
    if (D_001A4BE0_0038A708.state == 0x1D || D_001A4BE0_0038A708.state == 1) {
        if (func_0038CAD0(&D_001A4BE0_0038A708.aiming_fire_wait) == 0)
            can_fire = 0;
    } else {
        D_001A4BE0_0038A708.aiming_fire_wait = 0x21;
        if (target == 0) {
            u.skip = D_L01_001DDEB8_0038A708;
            target = func_L01_004501E8_0038A708(&pos, &D_001A4BE0_0038A708.aim, 0.39269909262657166f, 1.5707963705062866f,
                                       11.100000381469727f, 0.0f, &at, 0, 0, 0, 0.0f, 0, &u.skip, 1, -1, 0);
        }
    }
    if (D_L01_001DAFF0_0038A708 != 0 && D_001D545C == 5) {
        skip2 = D_L01_001DDED0_0038A708;
        target = func_L01_004501E8_0038A708(&pos, &D_001A4BE0_0038A708.aim, 0.8726646304130554f, 1.0471975803375244f,
                                   30.0f, 0.0f, &at2, 0, 0, 0, 0.0f, 0, &skip2, 1, -1, 0);
        if (target != 0 && *(s16 *)(target + 0xAA) == 0x1A13) {
            D_L01_001DDEA8_0038A708 = 10.0f;
            D_L01_001DDEB4_0038A708 = 50.0f;
        } else {
            D_L01_001DDEA8_0038A708 = 12.0f;
            D_L01_001DDEB4_0038A708 = 12.5f;
        }
    } else if (D_L01_001D673C_0038A708 != 0) {
        D_L01_001DDEA8_0038A708 = 6.0f;
        D_L01_001DDEB4_0038A708 = 12.5f;
    } else {
        D_L01_001DDEA8_0038A708 = 12.0f;
        D_L01_001DDEB4_0038A708 = 12.5f;
    }
    func_L01_0038AD40_0038A708(&u.dir, &pos, target, 0, D_L01_001DDEAC_0038A708, D_L01_001DDEA8_0038A708,
                      D_L01_001DDEB4_0038A708 * 0.020000001415610313f, D_L01_001DDEB0_0038A708 * 0.0004000000189989805f);
    vars->w24 = func_L01_004C7A18_0038A708(D_L01_001DDEB0_0038A708 * 0.0004000000189989805f, &pos, &u.dir, vars, vars->landing,
                                  m, 0, 0);
    switch (m->phase) {
    case 0:
        m->phase = 1;
        vars->rumble = -1;
        vars->timer = 0.0f;
        vars->w28 = 0;
    case 1:
        if (D_001A4BE0_0038A708.i1D8 >= 0x12)
            func_L01_004EAA80_0038A708();
        if (can_fire && vars->timer == 0.0f && D_001A4BE0_0038A708.no_firing == 0 &&
            (*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_0038A708.fire_button) &&
            D_001A4BE0_0038A708.i1220 >= 0x13) {
            if (func_L01_005118D0_0038A708(-1, 1)) {
                D_L01_001E1F10_0038A708 = 1;
                func_L01_004EA7D8_0038A708(-1);
                vars->rumble = func_L01_003F2058_0038A708(D_L01_002B3C60_0038A708, 0);
                func_L01_00444F38_0038A708((u8 *)m, 2, 0, 2, 0);
                if (target != 0)
                    func_0038D890(&u.dir, &u.dir, D_001A4BE0_0038A708.moby + 0xD0, -0.17453292012214661f);
                else
                    func_0038D890(&u.dir, &u.dir, D_001A4BE0_0038A708.moby + 0xD0, 0.08726646006107330f);
                if (func_0038CEA8(&u.dir) > 0.6000000238418579f)
                    func_0038CF68(&u.dir, &u.dir, 0.4400000274181366f);
                func_L01_00362610_0038A708(&pos, &u.dir, m, 1, 0);
                func_003A52A0(0, 0, m);
                vars->timer = 1.0f / (D_L01_002C5600_0038A708 + D_00142637[0])->rate;
            } else if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0_0038A708.fire_button) || D_L01_001E1F10_0038A708 == 1) {
                func_003A52A0(1, 0, m);
                D_L01_001E1F10_0038A708 = 0;
            }
            if (!((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_0038A708.fire_button) && func_L01_005119E0_0038A708(-1) &&
                  D_001A4BE0_0038A708.b25E9 != 0) && vars->rumble >= 0) {
                func_L01_003F2278_0038A708(vars->rumble, 0);
                vars->rumble = -1;
            }
        }
        break;
    }
    func_L01_0040E050_0038A708(&vars->timer);
    func_L01_00404A10_0038A708(func_L01_0038ACE8_0038A708, m);
}
/* localdecomp:end func_L01_0038A708 */

/* localdecomp:start func_L01_0038ACE8 */

extern s32 func_L01_005119E0(s32);
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);

void func_L01_0038ACE8(Obj3899C0 *obj) {
    u8 *p = obj->inner;
    if (*(s32 *)(p + 36) == 0) {
        return;
    }
    if (func_L01_005119E0(-1)) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0038ACE8 */

INCLUDE_ASM("asm/levels", func_L01_0038AD40);

/* localdecomp:start func_L01_0038B280 */
#include "vu0.h"

typedef struct {
    u8 pad_0[0x80];
    vu0_v4 pos;                /* 0x80 */
    u8 pad_90[0x1D8 - 0x90];
    s32 i1D8;                  /* 0x1D8 */
    u8 pad_1DC[0x6F0 - 0x1DC];
    vu0_v4 aim;                /* 0x6F0 */
    u8 pad_700[0x1210 - 0x700];
    s32 fire_button;           /* 0x1210 */
    u8 pad_1214[0x1220 - 0x1214];
    s32 i1220;                 /* 0x1220 */
    u8 pad_1224[0x1430 - 0x1224];
    u8 *lockon_target;         /* 0x1430 */
    u8 pad_1434[0x25C4 - 0x1434];
    s32 state;                 /* 0x25C4 */
    u8 pad_25C8[0x25E9 - 0x25C8];
    u8 b25E9;                  /* 0x25E9 */
    u8 pad_25EA[0x25ED - 0x25EA];
    u8 no_firing;              /* 0x25ED */
    u8 pad_25EE[0x2874 - 0x25EE];
    s16 h2874;                 /* 0x2874 */
    u8 pad_2876[0x28BC - 0x2876];
    s32 aiming_fire_wait;      /* 0x28BC */
} Hero_38B280_0038B280;
typedef struct {
    u8 pad_0[0x10];
    u8 landing[0x10];          /* 0x10 */
    f32 timer;                 /* 0x20 */
    s32 w24;                   /* 0x24 */
    u8 pad_28[4];
    s32 rumble;                /* 0x2C */
} InfVars_38B280_0038B280;
typedef struct {
    u8 pad_0[0x10];
    vu0_v4 pos;                /* 0x10 */
    u8 phase;                  /* 0x20 */
    u8 pad_21[0x42 - 0x21];
    u8 b42;                    /* 0x42 */
    u8 b43;                    /* 0x43 */
    u8 pad_44[0x60 - 0x44];
    u8 b60;                    /* 0x60 */
    u8 pad_61[0x68 - 0x61];
    InfVars_38B280_0038B280 *vars;      /* 0x68 */
    u8 pad_6C[0xC0 - 0x6C];
    u8 matrix[0x10];           /* 0xC0 */
    u8 forward[0x10];          /* 0xD0 */
} Inf_38B280_0038B280;
typedef struct { u8 pad_0[0x50]; f32 rate; u8 pad_54[0xF0 - 0x54]; } Row_38B280_0038B280;
typedef struct { s32 w[5]; } Skip_38B280_0038B280;

extern Hero_38B280_0038B280 D_001A4BE0;
extern u8 *D_001D52FC;
extern u8 D_001425F7[];
extern s32 D_L01_001D673C_0038B280;
extern s32 D_L01_001E1F14_0038B280;
extern f32 D_L01_001DDEF0_0038B280;
__asm__(".extern D_L01_001DDEF0_0038B280, 4");
extern f32 D_L01_001DDEF4_0038B280;
__asm__(".extern D_L01_001DDEF4_0038B280, 4");
extern f32 D_L01_001DDEF8_0038B280;
__asm__(".extern D_L01_001DDEF8_0038B280, 4");
extern f32 D_L01_001DDEFC_0038B280;
__asm__(".extern D_L01_001DDEFC_0038B280, 4");
extern f32 D_L01_001DDF00_0038B280[2];
__asm__(".extern D_L01_001DDF00_0038B280, 8");
extern Skip_38B280_0038B280 D_L01_001DDF10_0038B280;
extern u8 D_L01_002B3CE0_0038B280[];
extern Row_38B280_0038B280 D_L01_002C5600_0038B280[];
extern u8 D_L01_001D66B0_0038B280[8];
extern u8 *D_L01_0022123C_0038B280[];

extern void func_003C2F58(void *, s32, void *);
extern u8 *func_00382348(void *);
extern s32 func_0038CAD0(void *);
extern u8 *func_L01_004501E8_0038B280(void *, void *, f32, f32, f32, f32, void *, s32, s32, s32, f32, s32, void *, s32, s32, s32);
extern void func_L01_004C7438_0038B280(void *out, void *in, void *target, s32 b, f32 c, f32 d, f32 e, f32 f);
extern s32 func_L01_004C7A18_0038B280(f32 h, void *a, void *b, void *c, void *d, void *e, s32 f, s32 g);
extern void func_L01_00444F38_0038B280(u8 *, s32, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004EAA80_0038B280(void);
extern s32 func_L01_005118D0_0038B280(s32, s32);
extern void func_L01_004EA7D8_0038B280(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_003F2058_0038B280(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00390240_0038B280(void *, void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_005119E0_0038B280(s32);
extern void func_L01_003F2278_0038B280(s32, void *);
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8_0038B280(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_004C7D98_0038B280(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0013D3E0(void);
extern void func_L01_00466F50_0038B280(void *, void *, s32, f32, f32);
extern s32 func_L01_0040E050_0038B280(void *);
extern void func_L01_00404A10_0038B280(void *, void *);
extern void func_L01_0038B950_0038B280(u8 *);

/* infector_v5_update: the Infector's V5 update: entry 0 to fire, 1 for no ammo */
void func_L01_0038B280(Inf_38B280_0038B280 *inf)
{
    InfVars_38B280_0038B280 *vars = inf->vars;
    u8 *target = 0;
    vu0_v4 from;
    union { Skip_38B280_0038B280 skip; vu0_v4 pos; } u;
    vu0_v4 spot;
    vu0_v4 up;
    vu0_v4 at;
    s32 can_fire;
    s32 life;
    u8 *p;

    func_003C2F58(inf, 0, &from);
    if (D_001A4BE0.lockon_target != 0 && D_001A4BE0.lockon_target[0x20] != 0xFE &&
        D_001A4BE0.lockon_target[0x20] != 0xFD) {
        f32 *health = (f32 *)func_00382348(D_001A4BE0.lockon_target);
        if (health != 0 && 0.0f < *health)
            target = D_001A4BE0.lockon_target;
    }
    can_fire = 1;
    if (D_001A4BE0.state == 0x1D || D_001A4BE0.state == 1) {
        if (func_0038CAD0(&D_001A4BE0.aiming_fire_wait) == 0)
            can_fire = 0;
    } else {
        D_001A4BE0.aiming_fire_wait = 0x21;
        if (target == 0) {
            u.skip = D_L01_001DDF10_0038B280;
            target = func_L01_004501E8_0038B280(&from, &D_001A4BE0.aim, 0.39269909262657166f, 0.7853981852531433f,
                                       11.100000381469727f, 0.0f, &at, 0, 0, 0, 0.0f, 0, &u.skip, 1, -1, 0);
        }
    }
    if (D_L01_001D673C_0038B280 != 0) {
        D_L01_001DDEF0_0038B280 = 7.800000190734863f;
        D_L01_001DDEF4_0038B280 = 9.999999747378752e-06f;
        D_L01_001DDEF8_0038B280 = 12.0f;
        D_L01_001DDEFC_0038B280 = 10.0f;
    } else {
        D_L01_001DDEF0_0038B280 = 12.0f;
        D_L01_001DDEF4_0038B280 = 9.999999747378752e-06f;
        D_L01_001DDEF8_0038B280 = 12.0f;
        D_L01_001DDEFC_0038B280 = 15.0f;
    }
    func_L01_004C7438_0038B280(&u.pos, &from, target, 0, D_L01_001DDEF4_0038B280, D_L01_001DDEF0_0038B280,
                      D_L01_001DDEFC_0038B280 * 0.020000001415610313f, D_L01_001DDEF8_0038B280 * 0.0004000000189989805f);
    vars->w24 = func_L01_004C7A18_0038B280(D_L01_001DDEF8_0038B280 * 0.0004000000189989805f, &from, &u.pos, vars, vars->landing,
                                  inf, 0, 0);
    if (inf->b42 == inf->b43 && (inf->b60 & 2))
        func_L01_00444F38_0038B280((u8 *)inf, 1, 0, 2, 0);
    if (D_001A4BE0.h2874 != 0)
        func_0038CE20(&u.pos, inf->forward, -0.2900000214576721f);
    switch (inf->phase) {
    case 0:
        inf->phase = 1;
        vars->rumble = -1;
        vars->timer = 0.0f;
    case 1:
        if (D_001A4BE0.i1D8 >= 0x12)
            func_L01_004EAA80_0038B280();
        if (vars->timer == 0.0f && D_001A4BE0.no_firing == 0 &&
            (*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0.fire_button) && can_fire &&
            D_001A4BE0.i1220 >= 0x13) {
            if (func_L01_005118D0_0038B280(-1, 1)) {
                D_L01_001E1F14_0038B280 = 1;
                func_L01_004EA7D8_0038B280(-1);
                func_003C3A10(inf, 2, 0, 0);
                vars->rumble = func_L01_003F2058_0038B280(D_L01_002B3CE0_0038B280, 0);
                if (func_0038CEA8(&u.pos) > 0.6000000238418579f)
                    func_0038CF68(&u.pos, &u.pos, 0.4400000274181366f);
                func_L01_00390240_0038B280(inf, &from, &u.pos);
                func_003A52A0(0, 0, inf);
                vars->timer = 1.0f / (D_L01_002C5600_0038B280 + D_001425F7[0])->rate;
            } else if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0.fire_button) || D_L01_001E1F14_0038B280 == 1) {
                func_003A52A0(1, 0, inf);
                D_L01_001E1F14_0038B280 = 0;
            }
            if (!((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0.fire_button) && func_L01_005119E0_0038B280(-1) &&
                  D_001A4BE0.b25E9 != 0) && vars->rumble >= 0) {
                func_L01_003F2278_0038B280(vars->rumble, 0);
                vars->rumble = -1;
            }
            inf->phase = 1;
        }
        break;
    }
    if (D_001A4BE0.no_firing == 0) {
        func_0038D000(&spot, D_L01_001DDF00_0038B280, inf->matrix);
        vec_add_ab(&spot, &spot, &inf->pos);
        life = (func_00382498(10, 20) * 5 + 2) / 6;
        p = func_L01_004713C8_0038B280(&spot, D_L01_001D66B0_0038B280, life, 0x5A182, func_00382498(1, 4), 0x30, 0, 0,
                              52500.0f, 157500.0f, 0.00020000000949949026f);
        if (p != 0) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = D_L01_0022123C_0038B280[0][0];
        }
        func_L01_004C7D98_0038B280(&D_001A4BE0.pos, &up);
        func_0038CF68(&up, &up, func_003824E0(0.004999999888241291f, 0.014999999664723873f));
        spot.x += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        spot.y += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        spot.z += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        if (func_0013D3E0() % 12 == 0)
            func_L01_00466F50_0038B280(&spot, &up, 0x4005A182, -1.0f, 0.0f);
    }
    func_L01_0040E050_0038B280(&vars->timer);
    func_L01_00404A10_0038B280(func_L01_0038B950_0038B280, inf);
}
/* localdecomp:end func_L01_0038B280 */

/* localdecomp:start func_L01_0038B950 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_0038B950(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0038B950 */

/* localdecomp:start func_L01_0038B988 */
extern void func_L01_0036E578_0038B988();
 
void func_L01_0038B988(void) {
    func_L01_0036E578_0038B988();
}
/* localdecomp:end func_L01_0038B988 */

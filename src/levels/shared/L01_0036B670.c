#include "common.h"

typedef struct {
    u8 pad0[104];
    u8 *inner;
} Obj3899C0;
typedef struct {
    u8 b[8];
} Pair_371CB8;
typedef struct {
    u8 pad0[16];
    f32 pos[4];
    u8 pad32[4];
    s32 i36;
    s32 i40;
    u8 pad44[4];
    f32 f48;
} Obj_371CB8;

INCLUDE_ASM("asm/levels", func_L01_0036B670);

INCLUDE_ASM("asm/levels", func_L01_0036C828);

INCLUDE_ASM("asm/levels", func_L01_0036CB08);

INCLUDE_ASM("asm/levels", func_L01_0036D018);

INCLUDE_ASM("asm/levels", func_L01_0036D8C8);

/* localdecomp:start func_L01_0036DB20 */
extern s32 D_L01_001E1D18;
extern void func_003C2F58(s32, s32, void *);
extern void func_L01_0036DB78(void *, s32, s32, f32, f32, f32, f32);
void func_L01_0036DB20(s32 a0) {
    u8 buf[16];
    func_003C2F58(a0, 0, buf);
    func_L01_0036DB78(buf, 66, D_L01_001E1D18 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_0036DB20 */

/* localdecomp:start func_L01_0036DB78 */
typedef struct { u8 pad[0x150]; s16 width,height; } Screen_0036DB78;
extern Screen_0036DB78 D_001CFEC0;
typedef struct { s32 a,b,buffer; } Buffer_0036DB78;
extern Buffer_0036DB78 D_001A1ED0[1];
extern s32 D_001D5520;
extern s32 D_L01_001DD8CC;
__asm__(".extern D_L01_001DD8CC, 4");
extern s32 D_L01_001DD8A4;
__asm__(".extern D_L01_001DD8A4, 4");
extern s32 D_L01_001DD8A8;
__asm__(".extern D_L01_001DD8A8, 4");
extern s32 D_L01_001DD880;
__asm__(".extern D_L01_001DD880, 4");
extern s32 D_L01_001DD87C;
__asm__(".extern D_L01_001DD87C, 4");
extern s32 D_L01_001DD884;
__asm__(".extern D_L01_001DD884, 4");
extern s32 D_L01_001DD888;
__asm__(".extern D_L01_001DD888, 4");
extern s32 D_L01_001DD870;
__asm__(".extern D_L01_001DD870, 4");
extern s32 D_L01_001DD88C;
__asm__(".extern D_L01_001DD88C, 4");
extern s32 D_L01_001DD890;
__asm__(".extern D_L01_001DD890, 4");
extern s32 D_L01_001DD894;
__asm__(".extern D_L01_001DD894, 4");
extern s32 D_L01_001DD898;
__asm__(".extern D_L01_001DD898, 4");
extern s32 D_L01_001DD878;
__asm__(".extern D_L01_001DD878, 4");
extern s32 D_L01_001DD89C;
__asm__(".extern D_L01_001DD89C, 4");
extern s32 D_L01_001DD8A0;
__asm__(".extern D_L01_001DD8A0, 4");
void func_L01_0036DB78(void *pos, s32 tex, s32 alpha, f32 a, f32 b, f32 c, f32 d) {
    extern void func_L01_004C5E28(void *,s32,f32,f32,f32,f32);
    extern void func_003A9440(s32,unsigned long);
    extern void func_003D1030(void);
    extern unsigned long func_00389598(s32);
    extern void func_0038B4D0(s32,s32,s32,s32,s32,s32,s32,s32,long,unsigned long);
    unsigned long texture;
    long color;
    func_L01_004C5E28(pos,tex,a,b,c,d);
    if (D_001D5520 != 0) {
        D_L01_001DD8CC=-1;
        D_L01_001DD8A4=0xEC;
        D_L01_001DD8A8=0xF0;
    }
    func_003A9440(0x4E, (D_001A1ED0[0].buffer >> 13) | 0x01000000UL | 0x100000000UL);
    func_003A9440(0x42, (long)D_L01_001DD87C | ((long)D_L01_001DD880<<2) | ((long)D_L01_001DD884<<4) | ((long)D_L01_001DD888<<6) | 0x8000000000UL);
    func_003D1030();
    texture=func_00389598(D_L01_001DD870);
    color=(alpha<<24)|0x7F7F7F;
    func_0038B4D0(0,0,(s32)(D_001CFEC0.width*0.5f),(s32)(D_001CFEC0.height*0.5f),0,0,255,255,color,texture);
    func_0038B4D0(D_001CFEC0.width,0,-(s32)(D_001CFEC0.width*0.5f),(s32)(D_001CFEC0.height*0.5f),0,0,255,255,color,texture);
    func_0038B4D0(0,D_001CFEC0.height,(s32)(D_001CFEC0.width*0.5f),-(s32)(D_001CFEC0.height*0.5f),0,0,255,255,color,texture);
    func_0038B4D0(D_001CFEC0.width,D_001CFEC0.height,-(s32)(D_001CFEC0.width*0.5f),-(s32)(D_001CFEC0.height*0.5f),0,0,255,255,color,texture);
    func_003A9440(0x42, (long)D_L01_001DD87C | ((long)D_L01_001DD880<<2) | ((long)D_L01_001DD884<<4) | ((long)D_L01_001DD888<<6) | 0x8000000000UL);
    func_003A9440(0x42, (long)D_L01_001DD88C | ((long)D_L01_001DD890<<2) | ((long)D_L01_001DD894<<4) | ((long)D_L01_001DD898<<6) | 0x8000000000UL);
    func_0038B4D0(0,0,D_001CFEC0.width,D_001CFEC0.height,D_L01_001DD89C,D_L01_001DD8A0,D_L01_001DD8A4,D_L01_001DD8A8,D_L01_001DD878,func_00389598(D_L01_001DD8CC));
    func_003A9440(0x4E, 0x01000000UL | (D_001A1ED0[0].buffer >> 13));
}
/* localdecomp:end func_L01_0036DB78 */

INCLUDE_ASM("asm/levels", func_L01_0036DEB0);

INCLUDE_ASM("asm/levels", func_L01_0036E120);

INCLUDE_ASM("asm/levels", func_L01_0036E578);

LINKER_REMNANT("asm/levels", func_L01_0036F118);

INCLUDE_ASM("asm/levels", func_L01_0036F120);

INCLUDE_ASM("asm/levels", func_L01_0036F330);

/* localdecomp:start func_L01_0036F9F8 */

extern s32 func_L01_005119E0(s32);
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);

void func_L01_0036F9F8(Obj3899C0 *obj) {
    u8 *p = obj->inner;
    if (*(s32 *)(p + 36) == 0) {
        return;
    }
    if (func_L01_005119E0(-1)) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0036F9F8 */

INCLUDE_ASM("asm/levels", func_L01_0036FA50);

INCLUDE_ASM("asm/levels", func_L01_0036FF90);

INCLUDE_ASM("asm/levels", func_L01_003706F0);

INCLUDE_ASM("asm/levels", func_L01_00370A48);

/* localdecomp:start func_L01_00371C98 */
void func_L01_00371C98(u8 *a) {
    a[0x20] = 1;
}
/* localdecomp:end func_L01_00371C98 */

INCLUDE_ASM("asm/levels", func_L01_00371CA8);

LINKER_REMNANT("asm/levels", func_L01_00372120);

/* localdecomp:start func_L01_00372128 */
typedef int u128_372128 __attribute__((mode(TI)));
typedef struct {
    u8 pad_0[0x18C];
    s32 first_drawn;           /* 0x18C: set once rotation is kept */
    u128_372128 places[8];     /* 0x190: the ring of kept places */
    u128_372128 turns[8];      /* 0x210: each place's turn */
    u128_372128 rotation;      /* 0x290: the disc's rotation at its first draw */
    u8 trail[0x2C0 - 0x2A0];   /* 0x2A0: the trail's own state */
    s32 count;                 /* 0x2C0: places kept */
    s32 newest;                /* 0x2C4: the newest place's slot */
    f32 share;                 /* 0x2C8: share of the frames to the next kept place */
    u8 pad_2CC[0x2D4 - 0x2CC];
    s32 level;                 /* 0x2D4: the gun's level, 1 = V2 */
} DiscVars_372128;
typedef struct {
    u8 pad_0[0x10];
    u128_372128 position;
    u8 pad_20[0x68 - 0x20];
    DiscVars_372128 *vars;
    u8 pad_6C[0xF0 - 0x6C];
    u128_372128 rotation;
} Moby_372128;

extern void func_003C3FC0(u128_372128 *out, u128_372128 *angles);
extern void func_L01_00408C98(void *trail, s32 kind, u128_372128 *places, u128_372128 *turns,
                              s32 newest, s32 count, u32 head_colour, u32 tail_colour, f32 share,
                              s32 texture);

/* disc_blade_ribbon_draw: the Disc Blade's ribbon trail from V2: keeps the disc's place and turn
   in the ring and draws it with fx_trail, its colours by level */
void func_L01_00372128(Moby_372128 *disc) {
    DiscVars_372128 *vars = disc->vars;
    u32 head_colour;
    u32 tail_colour;
    s32 texture;

    if (vars->first_drawn != 0) {
        func_003C3FC0(&vars->turns[vars->newest], &vars->rotation);
    } else {
        func_003C3FC0(&vars->turns[vars->newest], &disc->rotation);
        vars->rotation = disc->rotation;
        vars->first_drawn = 1;
    }
    (&vars->places[0])[vars->newest] = disc->position;
    /* V2: (0xFF, 0x80, 0x40) at 0x6F to (0xFF, 0x20, 0) */
    head_colour = 0x6F4080FF;
    tail_colour = 0x20FF;
    texture = 8;
    if (vars->level == 2) {
        /* V3: (0x40, 0x80, 0xFF) at 0x6F to (0, 0x20, 0xFF), texture 29 */
        head_colour = 0x6FFF8040;
        tail_colour = 0xFF2000;
        texture = 0x1D;
    }
    if (vars->level == 3) {
        /* V4: (0x20, 0x10, 0xFF) at 0x4F to (0, 0, 0xFF), texture 60 */
        head_colour = 0x4FFF1020;
        tail_colour = 0xFF0000;
        texture = 0x3C;
    }
    if (vars->level >= 4) {
        /* V5: (0xFF, 0x10, 0x20) at 0x4F to (0xFF, 0, 0) */
        head_colour = 0x4F2010FF;
        tail_colour = 0xFF;
        texture = 0x3C;
    }
    func_L01_00408C98(vars->trail, 2, vars->places, vars->turns, vars->newest, vars->count,
                      head_colour, tail_colour, vars->share, texture);
}
/* localdecomp:end func_L01_00372128 */

/* localdecomp:start func_L01_00372240 */
typedef struct {
    u8 pad_0[0x180];
    f32 angle;
    u8 pad_184[0x2D4 - 0x184];
    s32 level;
} Vars_00372240;
extern f32 D_L01_001DD9BC;
extern s32 D_L01_001DD9A8;
extern f32 D_L01_001DD9C4;
extern f32 D_L01_001DD9C0;
__asm__(".extern D_L01_001DD9BC, 4");
__asm__(".extern D_L01_001DD9A8, 4");
__asm__(".extern D_L01_001DD9C4, 4");
__asm__(".extern D_L01_001DD9C0, 4");
void func_L01_00372240(u8 *moby) {
    extern f32 func_0038DAB8(f32 a, f32 b);
    extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
    extern f32 func_00382538(void);
    Vars_00372240 *vars = *(Vars_00372240 **)(moby + 0x68);
    u32 colour = 0x207F7F7F;
    u32 glow = 0x10007FFF;
    vars->angle = func_0038DAB8(vars->angle, D_L01_001DD9BC * 0.017453292f);
    if ((u32)(vars->level - 2) < 2) {
        colour = 0x20FF2020;
        glow = 0x10FF7F00;
    }
    if (vars->level < 4) {
        func_003D9508(moby + 0x10, D_L01_001DD9A8, colour, 1,
                      D_L01_001DD9C4, 0.08f, func_0038DAB8(-vars->angle * 1.5f, 0.0f));
        func_003D9508(moby + 0x10, D_L01_001DD9A8, colour, 1,
                      D_L01_001DD9C4, 0.08f, vars->angle * 0.5f);
        func_003D9508(moby + 0x10, D_L01_001DD9A8, colour, 1,
                      D_L01_001DD9C4, 0.08f, func_0038DAB8(vars->angle * 2.5f, 0.0f));
        func_003D9508(moby + 0x10, 49, glow, 1, 0.36f, 0.08f, vars->angle * 0.5f);
        func_003D9508(moby + 0x10, 49, glow, 1, 0.36f, 0.08f, vars->angle * -0.5f);
        func_003D9508(moby + 0x10, 47, 0x507F7F7F, 1, D_L01_001DD9C0, 0.08f, func_00382538());
    }
}
/* localdecomp:end func_L01_00372240 */

INCLUDE_ASM("asm/levels", func_L01_00372430);

/* localdecomp:start func_L01_003727B8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80]; f32 position[4]; u8 pad90[0x1210-0x90]; s32 mask;
    u8 pad1214[0x25C4-0x1214]; s32 weapon;
    u8 pad25C8[0x25ED-0x25C8]; u8 disabled;
    u8 pad25EE[0x28BC-0x25EE]; s32 timer;
} Game_003727B8;
typedef struct { u8 pad[0x1A4]; s32 buttons; } Pad_003727B8;
typedef struct { u8 first, kind; u8 pad[0xEE]; } Weapon_003727B8;
typedef struct { u8 pad[0x140]; f32 position[4]; } Aim_003727B8;
typedef struct { u8 pad[0x5C]; u8 *owner; } Owner_003727B8;
extern Game_003727B8 D_001A4BE0;
extern Pad_003727B8 *D_001D52FC;
extern u8 D_00142627 __attribute__((section(".data")));
extern Weapon_003727B8 D_L01_002C5600[];
extern Aim_003727B8 D_L01_001E2880;
extern Owner_003727B8 D_L01_00221098;
extern f32 D_L01_002F4D7C __attribute__((section(".data")));
void func_L01_003727B8(u8 *object) {
    extern void func_003C2F58(s32, s32, void *);
    extern void func_L01_004C7438(void *, void *, f32, f32, f32, f32, s32, s32);
    extern s32 func_0038CAD0(void *);
    extern s32 func_L01_0037C720_003727B8(void);
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_003A52A0(s32, s32, u8 *);
    extern void func_L01_004EA7D8(s32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00377A10(u8 *, void *, void *, f32);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_004C7A18(void *, void *, void *, void *, s32, s32, s32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_00372CE8(u8 *);
    extern void func_L01_00404A10_003727B8(void (*)(u8 *), u8 *);
    vu0_v4 start, direction, muzzle, position, velocity;
    u8 *state = *(u8 **)(object + 0x68);
    vu0_v4 *dir;
    f32 speed;
    s32 ready;
    s32 kind, sound, life, i;
    f32 angle;
    u8 *particle;
    func_003C2F58((s32)object, 0, &start);
    dir = &direction;
    speed = 5.0f;
    if (D_001A4BE0.weapon == 29) speed = 8.0f;
    func_L01_004C7438(dir, &start, 1.5f, speed, 0.3f, 0.0044f, 0, 0);
    if (object[0x31]) D_L01_002F4D7C = 0.1f;
    ready = 1;
    if (D_001A4BE0.weapon == 29) {
        if (!func_0038CAD0(&D_001A4BE0.timer)) ready = 0;
    } else D_001A4BE0.timer = 33;
    kind = ((Weapon_003727B8 *)(D_00142627 * sizeof(Weapon_003727B8) + (u32)D_L01_002C5600))->kind;
    if (kind == 3) *(s16 *)(object + 0x7C) = 7;
    if (kind == 2) *(s16 *)(object + 0x7C) = 3;
    else if (kind == 1) *(s16 *)(object + 0x7C) = kind;
    switch (object[0x20]) {
    case 0:
        object[0x20] = 1;
        *(s32 *)(state + 0x28) = 1;
        *(s32 *)(state + 0x24) = 0;
    case 1:
        if (((D_001D52FC->buttons & D_001A4BE0.mask) ||
            ((D_001D52FC->buttons & 8) && D_001A4BE0.weapon == 29)) &&
            !D_001A4BE0.disabled && ready) {
            if (func_L01_0037C720_003727B8() || !*(s32 *)(state + 0x28)) sound = 3;
            else if (func_L01_005118D0(-1, 1)) {
                func_003A52A0(2, 0, object);
                func_L01_004EA7D8(-1);
                object[0x20] = 2;
                *(s32 *)(state + 0x20) = 17;
                break;
            } else sound = 1;
            func_003A52A0(sound, 0, object);
        }
        break;
    case 2:
        if (func_0038CAD0(state + 0x20)) {
            if (func_0038CEA8(dir) > 0.40000003576278687f)
                func_0038CF68(dir, dir, 0.40000003576278687f);
            func_L01_00377A10(object, &start, dir, 1.0f);
            func_L01_004EAA80();
            object[0x20] = 3;
            *(s32 *)(state + 0x20) = 50;
        }
        break;
    case 3:
        if (func_0038CAD0(state + 0x20)) object[0x20] = 1;
        break;
    }
    if (object[0x20] != 3 && !func_L01_0037C720_003727B8()) {
        *(s32 *)(state + 0x24) = func_L01_004C7A18(&start, dir, state, state + 0x10, 0, 0, 0, 0.0044f);
        func_003C2F58((s32)object, 1, &muzzle);
        for (i = 3; i >= 0; i--) {
            angle = func_0038D160(D_001A4BE0.position[0] - D_L01_001E2880.position[0],
                D_001A4BE0.position[1] - D_L01_001E2880.position[1]);
            func_L01_00443A18(1.0f, 2.0f);
            position.x = muzzle.x + func_003824E0(-0.15f, 0.15f);
            position.y = muzzle.y + func_003824E0(-0.15f, 0.15f);
            position.z = muzzle.z + func_003824E0(-0.15f, 0.15f);
            angle = func_0038DAB8(angle, func_L01_00443A18(0.0f, -6.2831855f));
            velocity.x = func_0038D098(angle) * 0.015000000596046448f;
            velocity.y = func_0038D0B0(angle) * 0.015000000596046448f;
            velocity.z = 0.0f;
            life = (func_00382498(10, 30) * 5 + 2) / 6;
            particle = func_L01_004713C8(&position, &velocity, life, 0x804020,
                func_00382498(-2, -4), 127, 0, 0, 46200.0f, 16800.0f, 0.000800000037997961f);
            if (particle) particle[2] = D_L01_00221098.owner[0];
        }
        func_L01_00404A10_003727B8(func_L01_00372CE8, object);
    }
}
/* localdecomp:end func_L01_003727B8 */

/* localdecomp:start func_L01_00372CE8 */
extern void func_003C2F58(s32, s32, void *);
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);


extern Pair_371CB8 D_L01_001DD9D0[];
extern void func_L01_004C7D98(void *a, void *b);
extern f32 func_0038CE68(void *a, void *b);
extern f32 func_0038DAB8(f32 a, f32 b);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *a, void *b);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern f32 func_00382538(void);

void func_L01_00372CE8(u8 *moby) {
    u8 buf[16];
    Pair_371CB8 tmp;
    f32 vec[4];
    Obj_371CB8 *o = *(Obj_371CB8 **)(moby + 104);

    func_L01_004C7D98(o, buf);
    if (func_0038CE68(o->pos, buf) <= 0.9f) {
        o->i40 = 0;
    } else {
        o->i40 = 1;
    }
    tmp = D_L01_001DD9D0[0];
    if (o->i36) {
        if (o->i40) {
            ((void (*)(f32 s, void *a, void *b, void *c, s32 d))func_L01_004C70A8)(1.0f, o, o->pos, 0, 1);
        } else {
            ((void (*)(f32 s, void *a, void *b, void *c, s32 d))func_L01_004C70A8)(1.0f, o, o->pos, &tmp, 1);
        }
    }
    ((void (*)(void *a, s32 b, void *c))func_003C2F58)(moby, 1, vec);
    o->f48 = func_0038DAB8(o->f48, 0.017453292f);
    if (func_L01_004CB2D8()) {
        func_L01_004CAB30(vec, vec);
    }
    func_003D9508(vec, 57, 0x50505050, 1, 0.25f, 0.0f, func_0038DAB8(o->f48 * 2.5f, 0.0f));
    func_003D9508(vec, 42, 0x307F2040, 1, 0.25f, 0.0f, func_0038DAB8(-o->f48 * 1.5f, 0.0f));
    func_003D9508(vec, 44, 0x307F2040, 1, 0.25f, 0.0f, func_0038DAB8(o->f48, 0.0f));
    func_003D9508(vec, 49, 0x30FF7F00, 1, 0.18f, 0.0f, o->f48 * 0.5f);
    func_003D9508(vec, 49, 0x0030FF7F, 1, 0.18f, 0.0f, o->f48 * -0.5f);
    func_003D9508(vec, 47, 0x607F7F7F, 1, 0.06f, 0.0f, func_00382538());
}
/* localdecomp:end func_L01_00372CE8 */

INCLUDE_ASM("asm/levels", func_L01_00372F78);

/* localdecomp:start func_L01_00373368 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_373368;
typedef struct {
    Vec_373368 start;
    Vec_373368 pos_10;
    Vec_373368 target;
    u8 pad_30[0x34 - 0x30];
    f32 speed;
    f32 age;
    f32 damage;
} PulseVars_373368;
typedef struct Moby_373368 {
    u8 pad_0[0x10];
    Vec_373368 position;
    s8 state;
    u8 pad_21[0x30 - 0x21];
    u8 unk_30;
    u8 unk_31;
    u16 unk_32;
    u8 pad_34[0x38 - 0x34];
    long unk_38;
    u8 pad_40[0x68 - 0x40];
    PulseVars_373368 *vars;
    u8 pad_6C[0xB8 - 0x6C];
    struct Moby_373368 *owner;
} Moby_373368;

extern void *func_003C24B0(s32 class_id, s32 flags);

/* holo_pulse_spawn: spawns the Ultrashield's pulse (class 0x1869) from shield, for damage,
   leaving from start toward target */
Moby_373368 *func_L01_00373368(Moby_373368 *shield, Vec_373368 *from, Vec_373368 *to, f32 damage) {
    Vec_373368 start = *from;
    Vec_373368 target = *to;
    Moby_373368 *pulse = func_003C24B0(0x1869, 0x80);

    if (pulse != 0) {
        PulseVars_373368 *vars;

        pulse->unk_30 = 0xFF;
        pulse->unk_32 = 0xFF;
        pulse->unk_31 = 1;
        pulse->state = 0;
        pulse->owner = shield;
        vars = pulse->vars;
        pulse->unk_38 = shield->unk_38;
        pulse->position = vars->start;
        vars->start = start;
        vars->target = target;
        vars->damage = damage;
        vars->age = 0.0f;
        vars->speed = 0.0f;
    }
    return pulse;
}
/* localdecomp:end func_L01_00373368 */

/* localdecomp:start func_L01_00373410 */
void func_L01_00373410(Moby_373368 *pulse) {
    extern void func_L01_00373438_00373410(Moby_373368 *, Vec_373368 *);
    Vec_373368 start=pulse->vars->start;
    func_L01_00373438_00373410(pulse,&start);
}
/* localdecomp:end func_L01_00373410 */

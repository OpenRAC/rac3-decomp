#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

typedef struct {
    s32 a[12];
} S_0035E418;

extern void func_L01_004C8668(int);
extern void func_003C2880(void *);


/* localdecomp:start func_L01_0035E450 */
/* small for gcc (retail builds its address with one la, which Ps2EeAs expands in place) */
extern S_0035E418 D_L01_001E1A70 __attribute__((section(".sdata")));

/* Takes m out of the 12-slot list at D_L01_001E1A70 (func_L01_0035E418 tests whether it is
 * full): clears the first slot that holds it. */
void func_L01_0035E450(u8 *m)
{
    s32 i;

    for (i = 0; i < 12; i++) {
        if (D_L01_001E1A70.a[i] == (s32)m) {
            D_L01_001E1A70.a[i] = 0;
            return;
        }
    }
}
/* localdecomp:end func_L01_0035E450 */

/* localdecomp:start func_L01_0035E488 */
extern void func_003C2880(void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004C8668(s32);
extern void func_L01_0035E450(u8 *);

void func_L01_0035E488(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);

    if (*(s32 *)(pv + 0x24) == 0) {
        func_L01_003303B8(m + 16, 0, 0, 0, 0, 30, 0, 0, 0.75f, 0.0f, 0.0f, 2.0f,
                      0, 0, 0, 0, 0, 0, 0x10000, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0xFF8F00, 0xFF6430, 0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
    }
    func_L01_004C8668(*(s32 *)(pv + 0x2C));
    func_L01_0035E450(m);
    ((void (*)(u8 *))func_003C2880)(m);
}
/* localdecomp:end func_L01_0035E488 */

/* localdecomp:start func_L01_0035E598 */
extern S_0035E418 D_L01_001E1A70 __attribute__((section(".sdata")));
extern s32 func_L01_0035E418(void);
extern s32 func_00382468(s32);
extern void func_L01_0035E488(u8 *m);

/* Puts m in the 12-slot list at D_L01_001E1A70: in its first free slot, or, when it is full,
 * in a random one, ending what was there (func_L01_0035E488). */
void func_L01_0035E598(u8 *m)
{
    s32 i;
    s32 *slot;

    if (func_L01_0035E418() == 0) {
        for (i = 0; i < 12; i++) {
            if (D_L01_001E1A70.a[i] == 0) {
                D_L01_001E1A70.a[i] = (s32)m;
                return;
            }
        }
        return;
    }
    slot = &D_L01_001E1A70.a[func_00382468(12)];
    func_L01_0035E488((u8 *)*slot);
    *slot = (s32)m;
}
/* localdecomp:end func_L01_0035E598 */

LINKER_REMNANT("asm/levels", func_L01_0035E630);

/* localdecomp:start func_L01_0035E638 */
typedef struct {
    s128 velocity; /* u a frame */
    f32 phase;     /* a random start */
    s32 ticks;
    s32 x18;
    s32 owner;     /* who fired it */
    s32 x20;
    f32 damage;    /* a flat damage */
    s32 flags;     /* its damage flags */
} BulletVars_0035E638;

/* moby_spawn; an alias, because a later block of this file declares it with its own moby type */
extern u8 *func_003C24B0_0035E638(s32, s32);
extern f32 func_00382538(void);
extern void func_L01_004AA7E8(u8 *a0, s32 a1);

/* enemy_bullet_spawn: a small bullet (class 0x1855), the agents' and the Nitro Eruptor's,
   at pos flying at velocity, owned by owner, doing a flat damage with these flags. */
u8 *func_L01_0035E638(s32 owner, s128 *pos, s128 *velocity, f32 damage, s32 flags)
{
    u8 *bullet = func_003C24B0_0035E638(0x1855, 0x80);
    BulletVars_0035E638 *vars;

    if (bullet != 0) {
        s32 opaque = 0xFF;

        bullet[0x20] = 0;
        *(u16 *)(bullet + 0x32) = opaque;
        bullet[0x30] = opaque;
        vars = *(BulletVars_0035E638 **)(bullet + 0x68);
        *(s128 *)(bullet + 0x10) = *pos;
        vars->velocity = *velocity;
        vars->flags = flags;
        vars->owner = owner;
        vars->phase = func_00382538();
        vars->damage = damage;
        vars->ticks = 0;
        vars->x18 = 0;
        *(void **)(bullet + 0x98) = 0;
        *(u16 *)(bullet + 0x34) = (*(u16 *)(bullet + 0x34) | 0x41) & ~0x1000;
        func_L01_004AA7E8(bullet, 1);
    }
    return bullet;
}
/* localdecomp:end func_L01_0035E638 */

INCLUDE_ASM("asm/levels", func_L01_0035E710);

LINKER_REMNANT("asm/levels", func_L01_0035EB18);

/* localdecomp:start func_L01_0035EB20 */
#include "vu0.h"
extern S_38C110v D_L01_001E29C0;
/* agent_bullet_hit_embers: twenty embers thrown from where an agent's bullet hit. */
void func_L01_0035EB20(S_38C110v *origin) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    S_38C110v direction;
    S_38C110v velocity;
    S_38C110v position;
    f32 heading;
    f32 factor, elevation, yaw;
    s32 kind;
    s32 i;
    f32 lifetime_scale;
    vec_sub_ab(&direction, &D_L01_001E29C0, origin);
    heading = func_0038D160(direction.x, direction.y);
    for (i = 19; i >= 0; i--) {
        factor = func_003824E0(0.5f, 1.0f);
        kind = (s32)func_L01_00443A18(1.0f, 2.0f);
        func_003824E0(0.05f, 0.2f);
        lifetime_scale = 210000.0f;
        elevation = func_003824E0(0.0f, 1.3962634f);
        yaw = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
        func_00382760(&velocity, factor * 0.020000001f, yaw, elevation);
        position.x = origin->x + func_L01_00443A18(0.0f, 0.1f);
        position.y = origin->y + func_L01_00443A18(0.0f, 0.1f);
        position.z = origin->z + func_L01_00443A18(0.0f, 0.1f);
        func_L01_0046A610(&position, &velocity, 25, 127, 0x7F7F7F, kind,
                         func_003824E0(0.05f, 0.2f) * lifetime_scale, 500.0f, 1.0f, 0.0f, 1.0f);
    }
}
/* localdecomp:end func_L01_0035EB20 */

/* localdecomp:start func_L01_0035ED40 */
#include "vu0.h"
extern S_38C110v D_L01_001E29C0;
/* agent_bullet_tracer: the tracer quad behind an agent's bullet, along its velocity. */
void func_L01_0035ED40(u8 *moby) {
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, void *, s32);
    S_38C110v basis[4];
    u8 packet[0x90] __attribute__((aligned(16)));
    S_38C110v shifted;
    void *vars=*(void **)(moby+0x68);
    f32 width=func_003824E0(0.14f,0.22f);
    f32 length=func_003824E0(1.333f,1.5f);
    s32 i;
    func_0038CF68(&basis[0],vars,1.0f);
    vec_sub_ba(&basis[1], &D_L01_001E29C0, moby+0x10);
    func_0038CE90(&basis[2],&basis[1],&basis[0]);
    func_0038CF68(&basis[2],&basis[2],width);
    func_0038CF68(&basis[0],&basis[0],length);
    *(s32 *)&basis[0].w=0;
    *(s32 *)&basis[1].w=0;
    *(s32 *)&basis[2].w=0;
    func_003D93B0(packet,63,1,128);
    *(s32 *)(packet+0x50)=0; *(s32 *)(packet+0x54)=0;
    *(s32 *)(packet+0x58)=0; *(f32 *)(packet+0x5C)=1.0f;
    *(f32 *)(packet+0x60)=1.0f; *(s32 *)(packet+0x64)=0;
    *(f32 *)(packet+0x68)=1.0f; *(f32 *)(packet+0x6C)=1.0f;
    for (i=0;i<4;i++) {
        qzero((vu0_q *)packet+i);
        { S_38C110v *v=(S_38C110v *)packet+i;
        if (i<2) *(s32 *)&v->x=0; else v->x=1.0f;
        *(s32 *)&v->y=0;
        if (i&1) v->z=1.0f; else v->z=-1.0f;
        v->w=1.0f;
        ((u32 *)(packet+0x40))[i]=0x7FFFFFFF;
        }
    }
    func_0038CF68(&shifted,vars,-1.25f);
    vec_add_ba(&basis[3], &shifted, moby+0x10);
    basis[3].w=1.0f;
    func_003D2DA0(packet,basis,0);
}
/* localdecomp:end func_L01_0035ED40 */

/* localdecomp:start func_L01_0035EF20 */
typedef struct {
    f32 step[4];  /* 0x00: its move a frame */
    f32 spin;     /* 0x10: the glows' roll */
    u8 pad_14[4];
    f32 flown;    /* 0x18: how far it has gone */
} BulletVars_35EF20;

__asm__(".extern D_L01_001DD6EC, 4");
extern s32 D_L01_001DD6EC;
__asm__(".extern D_L01_001DD6F0, 4");
extern u32 D_L01_001DD6F0;
__asm__(".extern D_L01_001DD6F4, 4");
extern f32 D_L01_001DD6F4;
__asm__(".extern D_L01_001DD6F8, 4");
extern f32 D_L01_001DD6F8;
__asm__(".extern D_L01_001DD6FC, 4");
extern f32 D_L01_001DD6FC;
__asm__(".extern D_L01_001DD700, 4");
extern f32 D_L01_001DD700;
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038CEA8(void *);
extern void func_L01_0035ED40(u8 *);

/* agent_bullet_draw: the agents' small bullet (class 0x1855): two glows (texture 57) turning
 * opposite ways, one of 47 at a random roll, all added; its tracer once it has flown far enough. */
void func_L01_0035EF20(u8 *moby)
{
    BulletVars_35EF20 *vars = *(BulletVars_35EF20 **)(moby + 0x68);
    u8 *position = moby + 0x10;
    f32 height = 0.08f;

    /* D_L01_001DD6F4: degrees a frame */
    vars->spin = func_0038DAB8(vars->spin, D_L01_001DD6F4 * 0.017453292f);
    func_003D9508(position, D_L01_001DD6EC, D_L01_001DD6F0, 1, D_L01_001DD6FC, height,
                  func_0038DAB8(-vars->spin * 1.5f, 0.0f));
    func_003D9508(position, D_L01_001DD6EC, D_L01_001DD6F0, 1, D_L01_001DD6FC, height,
                  vars->spin * 0.5f);
    func_003D9508(position, 0x2F, 0x507F7F7F, 1, D_L01_001DD6F8, height, func_00382538());
    vars->flown += func_0038CEA8(vars);
    if (D_L01_001DD700 < vars->flown) {
        func_L01_0035ED40(moby);
    }
}
/* localdecomp:end func_L01_0035EF20 */

INCLUDE_ASM("asm/levels", func_L01_0035F048);

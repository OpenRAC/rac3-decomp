#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

INCLUDE_ASM("asm/levels", func_L01_0035F480);

/* localdecomp:start func_L01_0035FEB8 */
void func_L01_0035FEB8(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_0035FEB8 */

INCLUDE_ASM("asm/levels", func_L01_0035FEC8);

/* localdecomp:start func_L01_00360170 */
#include "vu0.h"
extern f32 D_L01_001DD710;
__asm__(".extern D_L01_001DD710, 4");
extern u8 D_001A4C60[];
void func_L01_00360170(u8 *obj) {
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_003C4C18(void *, f32);
    extern void func_L01_00360398(void *, s32, s32, s32, f32, f32, f32);
    S_38C110v hero_pos;
    S_38C110v angles;
    S_38C110v forward;
    S_38C110v points[20];
    S_38C110v base;
    S_38C110v offset;
    S_38C110v transformed;
    S_38C110v dir;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 i;
    f32 t, scale, spread, angle_step;
    D_L01_001DD710 -= 0.0275f;
    t = D_L01_001DD710;
    if (t < 0.0f) t = 0.0f;
    *(s128 *)&hero_pos = *(s128 *)D_001A4C60;
    func_003C5180(&hero_pos, &angles, 1);
    angle_step = 0.31415927f;
    func_0038CF68(&forward, *(u8 **)(D_001A4C60 + 0x2540) + 0xc0, 1.0f);
    scale = (1.0f - t) * 10.0f + 0.05f;
    spread = (1.0f - t) * 0.5f;
    if (func_L01_004CB2D8()) func_L01_004CAB30(vars, vars);
    *(s128 *)&base = *(s128 *)vars;
    func_L01_004C7D98(obj + 0x10, &offset);
    func_0038CF68(&offset, &offset, 0.75f);
    vec_add_ab(&base, &offset, &base);
    for (i = 0; i < 20; i++) {
        func_003C4840(&dir, &angles, i * angle_step);
        func_0038D850(&transformed, &forward, &dir);
        func_0038CE20((s128 *)&transformed, (s128 *)&transformed, scale);
        func_003C4C18(&transformed, spread);
        vec_add_ab(&points[i], &base, &transformed);
    }
    func_L01_00360398(points, *(s32 *)(vars + 0x1c) * 5, *(s32 *)(vars + 0x1c) * 5, 20, 0.4f, 0.9f, 0.2f);
}
/* localdecomp:end func_L01_00360170 */

INCLUDE_ASM("asm/levels", func_L01_00360398);

/* localdecomp:start func_L01_003609D0 */
extern void func_L01_00361D60_003609D0(void *);
extern void func_L01_003609D0(void *);

extern void func_L01_00361AC0_003609D0();
void func_L01_003609D0(void *p) {
    func_L01_00361AC0_003609D0(p);
    func_L01_00361D60_003609D0(p);
}
/* localdecomp:end func_L01_003609D0 */

/* localdecomp:start func_L01_00360A00 */
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s16 D_001CFEC0[];

void func_L01_00360A00(void) {
    func_003A9440(66, 72);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], (s32)0x80808080);
}
/* localdecomp:end func_L01_00360A00 */

INCLUDE_ASM("asm/levels", func_L01_00360A48);

/* localdecomp:start func_L01_003612E0 */
extern f32 D_L01_0028C6B0[][3];
extern s32 D_L01_0028C8A8[];
extern f32 D_L01_0028C950[];
extern void func_003A9440_003612E0(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D3A24(s32, void *, void *, void *, s32);

void func_L01_003612E0(s128 *matrix, f32 degrees, f32 r1, f32 r2, s32 texture, f32 unused, s32 colour, s32 blend)
{
    S_38C110v v;
    S_38C110v out;
    f32 step, angle, t, u, rad, denom;
    s32 i;

    func_003A9440_003612E0(8, 0);
    func_003A9440_003612E0(20, 0xFF9000000260UL);
    func_003A9440_003612E0(71, 0x513F1);
    func_003A9440_003612E0(6, func_00389598(texture));
    if (blend) {
        func_003A9440_003612E0(66, 0x8000000048UL);
    } else {
        func_003A9440_003612E0(66, 0x8000000041UL);
    }
    rad = 0.017453292f;
    func_0038C750();
    denom = 20.0f;
    step = degrees * rad / denom;
    for (i = 0; i < 42; i += 2) {
        t = i / 2;
        angle = func_0038DB48(t * step);
        func_0038D098(angle);
        u = t / denom;
        D_L01_0028C8A8[i] = colour;
        D_L01_0028C8A8[i + 1] = colour;
        D_L01_0028C950[i * 2] = u;
        D_L01_0028C950[i * 2 + 1] = 0.0f;
        D_L01_0028C950[i * 2 + 2] = u;
        D_L01_0028C950[i * 2 + 3] = 1.0f;
        func_00382760(&v, 1.0f, angle, r1 * rad);
        v.w = 1.0f;
        func_0038D028(&out, &v, matrix);
        D_L01_0028C6B0[i][0] = out.x;
        D_L01_0028C6B0[i][1] = out.y;
        D_L01_0028C6B0[i][2] = out.z;
        func_00382760(&v, 1.0f, angle, r2 * rad);
        v.w = 1.0f;
        func_0038D028(&out, &v, matrix);
        D_L01_0028C6B0[i + 1][0] = out.x;
        D_L01_0028C6B0[i + 1][1] = out.y;
        D_L01_0028C6B0[i + 1][2] = out.z;
    }
    func_003D3A24(42, D_L01_0028C6B0, D_L01_0028C8A8, D_L01_0028C950, 1);
}
/* localdecomp:end func_L01_003612E0 */

/* localdecomp:start func_L01_00361568 */


extern void func_0038D328(s128 *, S_38C110v *);
extern void func_0038D640(s128 *, void *, s128 *);
extern void func_0038CE20(s128 *, s128 *, f32);
extern void func_L01_003612E0(s128 *, f32, f32, f32, s32, f32, s32, s32);

void func_L01_00361568(S_38C110v *a0, void *a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16, f32 f17) {
    S_38C110v v;
    s128 m1[4];
    s128 m2[4];

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = f12;
    v.w = 1.0f;
    func_0038D328(m1, &v);
    func_0038D640(m2, a1, m1);
    func_0038CE20(&m2[0], &m2[0], f13);
    func_0038CE20(&m2[1], &m2[1], f13);
    func_0038CE20(&m2[2], &m2[2], f13);
    *(S_38C110v *)&m2[3] = *a0;
    func_L01_003612E0(m2, f17, f14, f15, a2, f16, a3, 1);
}
/* localdecomp:end func_L01_00361568 */

INCLUDE_ASM("asm/levels", func_L01_00361690);

/* localdecomp:start func_L01_00361AC0 */
#include "vu0.h"
__asm__(".extern D_L01_001DD730, 4");
__asm__(".extern D_L01_001DD734, 4");
__asm__(".extern D_L01_001DD738, 4");
__asm__(".extern D_L01_001DD73C, 4");
__asm__(".extern D_L01_001DD740, 4");
__asm__(".extern D_L01_001DD744, 4");
__asm__(".extern D_L01_001DD748, 4");
__asm__(".extern D_L01_001DD704, 4");
typedef struct {
    S_38C110v p[4];
    s32 c40,c44,c48,c4C;
    f32 uv[4][2];
    unsigned long tag0, texture, tag1, tag2;
} Strip_00361AC0;
extern s32 D_L01_001DD730, D_L01_001DD734, D_L01_001DD738, D_L01_001DD73C, D_L01_001DD740, D_L01_001DD744;
extern s32 D_L01_001DD748;
extern f32 D_L01_001DD704;
extern u8 D_00142637[];
typedef struct { u8 p0; u8 kind; u8 pad[0xEE]; } Gun_00361AC0;
extern Gun_00361AC0 D_L01_002C5600[];
extern s16 D_L01_002B3080[][8];
extern S_38C110v D_L01_002B2B80[];
extern f32 D_L01_002B3480[][2];
extern f32 D_L01_002B3484[][2];
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_00361AC0;
extern Hero_00361AC0 D_001A4BE0_00361AC0;
void func_L01_00361AC0(u8 *moby) {
    extern long func_00389598(s32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_003D2DA0(void *, void *, s32);
    Strip_00361AC0 strip;
    S_38C110v basis[3];
    S_38C110v offset;
    s32 i,j;
    f32 *u0,*v0;
    u8 *vars=*(u8 **)(moby+0x68);
    strip.texture=func_00389598(D_L01_001DD744);
    strip.tag1=0xFF9000000260UL;
    strip.tag2=(long)D_L01_001DD730 | ((long)D_L01_001DD734<<2) | ((long)D_L01_001DD738<<4) | ((long)D_L01_001DD73C<<6) | ((long)D_L01_001DD740<<32);
    qzero(&basis[0]); qzero(&basis[1]); qzero(&basis[2]);
    strip.tag0=0;
    basis[0].x=*(f32 *)(vars+0x24)+*(f32 *)(vars+0x24);
    basis[1].y=*(f32 *)(vars+0x24)+*(f32 *)(vars+0x24);
    basis[2].z=*(f32 *)(vars+0x24)*0.25f;
    {
        s32 kind=((Gun_00361AC0 *)(D_00142637[0]*sizeof(Gun_00361AC0)+(s32)D_L01_002C5600))->kind;
        if(kind==1) D_L01_001DD748=0x300505;
        else if(kind==2) D_L01_001DD748=0x204080;
        else if(kind==3) D_L01_001DD748=0x204080;
    }
    strip.c40=strip.c44=strip.c48=strip.c4C=D_L01_001DD748+(*(s32 *)(vars+0x20)<<24);
    func_003C5180(vars,&offset,1);
    func_0038CE20((s128 *)&offset,(s128 *)&offset,0.25f);
    u0=&strip.uv[0][0];
    v0=&strip.uv[0][1];
    for(i=0;i<64;) {
        s32 next=i+1;
        s16 *row=&D_L01_002B3080[i][0];
        S_38C110v *dst=strip.p;
        f32 *v=v0;
        f32 *u=u0;
        for(j=3;j>=0;j--) {
            s32 uv=row[1];
            func_0038CE20((s128 *)dst,(s128 *)&D_L01_002B2B80[row[0]],D_L01_001DD704);
            *u=D_L01_002B3480[uv][0];
            *v=D_L01_002B3484[uv][0];
            func_0038D000(dst,dst,basis);
            func_0038D000(dst,dst,D_001A4BE0_00361AC0.moby+0xC0);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\tlqc2 $vf2, %0\n\tlqc2 $vf1, %3\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(*dst) : "m"(*dst),"m"(*(S_38C110v *)vars),"m"(offset) : "vf1", "vf2");
            row+=2; v+=2; u+=2; dst++;
        }
        func_003D2DA0(&strip,0,0);
        i=next;
    }
}
/* localdecomp:end func_L01_00361AC0 */

INCLUDE_ASM("asm/levels", func_L01_00361D60);

INCLUDE_ASM("asm/levels", func_L01_00361FA8);

/* localdecomp:start func_L01_00362600 */
void func_L01_00362600(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_00362600 */

/* localdecomp:start func_L01_00362610 */
typedef struct {
    s128 velocity;        /* 0x00 */
    u8 pad_10[0x40 - 0x10];
    s32 ticks;            /* 0x40 */
    u8 pad_44[4];
    s32 timer;            /* 0x48 */
    u8 pad_4C[4];
    s32 eruptor;          /* 0x50: the Nitro Eruptor's charge (1) */
    void *target;         /* 0x54 */
    s32 flag_58;          /* 0x58 */
} NitroVars_362610;

typedef struct {
    u8 pad_0[0x10];
    s128 position;        /* 0x10 */
    u8 state;             /* 0x20 */
    u8 pad_21[0x24 - 0x21];
    u8 *pclass;           /* 0x24 */
    u8 pad_28[0x2C - 0x28];
    f32 scale;            /* 0x2C */
    u8 update_dist;       /* 0x30: names for 0x30-0x32 from Horizon Private Server's libuya */
    u8 drawn;             /* 0x31 */
    s16 draw_dist;        /* 0x32 */
    u8 pad_34[0x68 - 0x34];
    NitroVars_362610 *vars; /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    f32 rotation[4];      /* 0xF0 */
} NitroMoby_362610;

extern NitroMoby_362610 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C7C38(u8 *);
extern NitroMoby_362610 *D_L01_001E10F8;

/* nitro_charge_spawn: spawns a Nitro charge (class 0x185A) at position with its velocity,
 * turned at random, with its timer. */
NitroMoby_362610 *func_L01_00362610(s128 *position, s128 *velocity, void *target,
                                    s32 eruptor, s32 flag_58)
{
    NitroMoby_362610 *moby;
    NitroVars_362610 *vars;

    moby = func_003C24B0(0x185A, 0x80);
    if (moby != 0) {
        moby->update_dist = 0xFF;
        moby->draw_dist = 0x1FF;
        moby->drawn = 1;
        moby->state = 0;
        vars = moby->vars;
        moby->position = *position;
        vars->velocity = *velocity;
        vars->ticks = 0;
        moby->rotation[0] = func_003824E0(-3.1415927f, 3.1415927f);
        moby->rotation[1] = func_003824E0(-3.1415927f, 3.1415927f);
        moby->rotation[2] = func_003824E0(-3.1415927f, 3.1415927f);
        moby->rotation[3] = 0.0f;
        moby->scale = *(f32 *)(moby->pclass + 0x24) * 1.25f;
        vars->flag_58 = flag_58;
        func_003C7C38((u8 *)moby);
        D_L01_001E10F8 = moby;
        vars->timer = 42; /* NTSC-U's 50 frames at 60 Hz */
        vars->eruptor = eruptor;
        vars->target = target;
    }
    return moby;
}
/* localdecomp:end func_L01_00362610 */

INCLUDE_ASM("asm/levels", func_L01_00362758);

/* localdecomp:start func_L01_00363138 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F160[];
s32 func_L01_00363138(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F160[i] != 0) n++;
    }
    return n;
}
/* localdecomp:end func_L01_00363138 */

/* localdecomp:start func_L01_00363170 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];
extern s32 D_L01_0028F160[];
s32 func_L01_00363170(s32 *out) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        s32 v = D_L01_0028F160[i];
        if (v != 0) {
            D_L01_0028F160[i] = 0;
            *out = D_L01_0028F0C0[i];
            D_L01_0028F0C0[i] = 0;
            return v;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_00363170 */

/* localdecomp:start func_L01_003631C8 */
typedef struct {
    u8 pad_0[0x18];
    u8 b18;            /* 0x18 */
    u8 b19;            /* 0x19 */
    s16 source_class;  /* 0x1A: the class of what hit */
    u8 pad_1C[0x30 - 0x1C];
} DamageInfo_3631C8;

typedef struct {
    u8 pad_0[0x4];
    s16 health;        /* 0x04 */
    u8 pad_6[0xF - 0x6];
    u8 takes_hits;     /* 0x0F */
} DamageRecord_3631C8;

typedef struct Moby_3631C8 {
    u8 pad_0[0x24];
    u8 *pclass;        /* 0x24 */
    u8 pad_28[0x68 - 0x28];
    u8 *vars;          /* 0x68 */
    u8 pad_6C[0x98 - 0x6C];
    void *coll_record; /* 0x98 */
    u8 pad_9C[0xAA - 0x9C];
    s16 class_id;      /* 0xAA */
} Moby_3631C8;

typedef struct {
    u8 pad_0[0x18];
    Moby_3631C8 *moby; /* 0x18: the moby the last test met */
} CollHit_3631C8;

typedef struct {
    u8 pos[0x20];      /* every other point of the vortex */
} SuckPoint_3631C8;

extern u8 D_001A4BE0[];
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];
extern s32 D_L01_0028F160[];
extern SuckPoint_3631C8 D_L01_0028E3C0[];
extern CollHit_3631C8 D_L01_001EAA00;
extern u8 D_L01_001D66B0[8];
extern s32 func_L01_003FB640(void *position, s32 mask, u8 *skip, f32 radius);
extern s32 func_003C4B50(Moby_3631C8 *moby);
extern DamageRecord_3631C8 *func_00382348(Moby_3631C8 *moby);
extern void func_L01_00446760(DamageInfo_3631C8 *info, u8 *attacker, s32 flags, void *push, f32 damage);
extern void func_L01_00446978(Moby_3631C8 *moby, DamageInfo_3631C8 *info);
extern s32 func_L01_00363E10(s32 value);

/* suck_crate_grab: as the Suck Cannon sucks, balls of 1.2, 1.4, 1.7 and 1.9 u at every other
 * point of its vortex look for a crate or a damageable moby to take in, into a free slot of
 * the held list (D_L01_0028F160: classes, D_L01_0028F0C0: mobys). */
void func_L01_003631C8(u8 *moby)
{
    DamageInfo_3631C8 info;
    Moby_3631C8 *hit;
    DamageRecord_3631C8 *record;
    u8 *hero = D_001A4BE0;
    s32 class_id;
    s32 i;

    /* not in states 0x35 and 0x36 */
    if ((u32)(*(s32 *)(hero + 0x25C4) - 0x35) < 2) {
        return;
    }
    for (i = 0; i < D_L01_001DD790; i++) {
        u8 *player = D_001A4BE0; /* the hero again: a second pointer, as retail */

        if (D_L01_0028F160[i] != 0) {
            continue;
        }
        /* the hero's moby out of the tests; its class's record is put back after */
        (*(Moby_3631C8 **)(player + 0x25C0))->coll_record = 0;
        if (func_L01_003FB640(&D_L01_0028E3C0[0], 1, moby, 1.2f) ||
            func_L01_003FB640(&D_L01_0028E3C0[1], 1, moby, 1.4f) ||
            func_L01_003FB640(&D_L01_0028E3C0[2], 1, moby, 1.7f) ||
            func_L01_003FB640(&D_L01_0028E3C0[3], 1, moby, 1.9f)) {
            /* what the ball met: an enemy (class category 5) or a crate (func_003C4B50) */
            if (D_L01_001EAA00.moby != 0 && D_L01_001EAA00.moby->class_id != 0 &&
                ((D_L01_001EAA00.moby->pclass != 0 && D_L01_001EAA00.moby->pclass[0x46] == 5) ||
                 func_003C4B50(D_L01_001EAA00.moby))) {
                class_id = D_L01_001EAA00.moby->class_id;
                /* never classes 0x1F8 and 0x1F7 */
                if (class_id != 0x1F8) {
                    if (class_id != 0x1F7) {
                        record = func_00382348(D_L01_001EAA00.moby);
                        /* a 1-damage hit with flag 0x8000000 */
                        func_L01_00446760(&info, moby, 0x8000000, D_L01_001D66B0, 1.0f);
                        info.b19 = 1;
                        info.source_class = *(s16 *)(moby + 0xAA);
                        info.b18 = 0;
                        if (func_003C4B50(D_L01_001EAA00.moby)) {
                            hit = D_L01_001EAA00.moby;
                            if (!func_L01_00363E10((s32)hit)) { /* not held yet */
                                *(s32 *)(hit->vars + 0xDC) |= 0x14;
                                D_L01_0028F0C0[i] = (s32)hit;
                                D_L01_0028F160[i] = hit->class_id;
                            }
                        } else if (record != 0 && record->takes_hits != 0) {
                            if (record->health >= 2) { /* only if it outlives it */
                                func_L01_00446978(D_L01_001EAA00.moby, &info);
                            }
                            if (!func_L01_00363E10((s32)D_L01_001EAA00.moby)) {
                                D_L01_0028F0C0[i] = (s32)D_L01_001EAA00.moby;
                                D_L01_0028F160[i] = D_L01_001EAA00.moby->class_id;
                            }
                        }
                    }
                }
            }
        }
        (*(Moby_3631C8 **)(player + 0x25C0))->coll_record =
            *(void **)((*(Moby_3631C8 **)(player + 0x25C0))->pclass + 0x10);
    }
}
/* localdecomp:end func_L01_003631C8 */

/* localdecomp:start func_L01_00363468 */
extern u8 D_L01_001D66B0[8];
extern u8 *func_L01_0046B458(u8 *position, s32 life, s32 colour, s32 roll_kind, s32 spin, void *velocity,
                             s32 delay, f32 size, f32 start_size, f32 unk);
extern u8 *func_L01_00470C78(u8 *position, s32 life, s32 colour, s32 a3, s32 spin, void *velocity, s32 t2,
                             s32 t3, s16 arg8, s32 arg9, f32 size, f32 start_size);

/* suck_take_in_sparkles: the Suck Cannon taking something in: at the muzzle four orange 0x35
 * sparkles (the Flux's muzzle sparkles) and three 0x5C bursts; D_L01_001D66B0 is a zero vector. */
void func_L01_00363468(u8 *moby)
{
    u8 *muzzle = *(u8 **)(moby + 0x68) + 0x10;

    func_L01_0046B458(muzzle, 14, 0xBF204080, 2, 4, D_L01_001D66B0, 1, 5.25f, 0.1f, 0.0f);
    func_L01_0046B458(muzzle, 14, 0xBF2040A0, 2, -4, D_L01_001D66B0, 1, 3.75f, 0.1f, 0.0f);
    func_L01_0046B458(muzzle, 14, 0xC0FFFFFF, 2, 4, D_L01_001D66B0, 1, 2.625f, 0.1f, 0.0f);
    func_L01_0046B458(muzzle, 14, 0xB0FFFFFF, 2, -4, D_L01_001D66B0, 1, 1.875f, 0.1f, 0.0f);
    func_L01_00470C78(muzzle, 17, 0x46787878, 2, 4, D_L01_001D66B0, 0, 2, 6, 1, 1.08f, 0.84000003f);
    func_L01_00470C78(muzzle, 17, 0x46787878, 2, -2, D_L01_001D66B0, 1, 2, 6, 1, 2.0400002f, 0.84000003f);
    func_L01_00470C78(muzzle, 17, 0x2D787878, 2, 2, D_L01_001D66B0, 1, 2, 6, 1, 2.4f, 1.8000001f);
}
/* localdecomp:end func_L01_00363468 */

INCLUDE_ASM("asm/levels", func_L01_00363690);

/* localdecomp:start func_L01_00363BF0 */
extern u8 *D_L01_001E0028_00363BF0;
extern u8 D_L01_0028E430_00363BF0[];
extern f32 func_0038CF00(void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_002F8D40_00363BF0(u8 *, u8 *, s32, f32, f32);

void func_L01_00363BF0(u8 *moby)
{
    u8 *p;
    for (p = D_L01_001E0028_00363BF0; p != 0; p = *(u8 **)(p + 0x28)) {
        if (func_0038CF00(p + 0x10, D_L01_0028E430_00363BF0) < 2.5f ||
            func_0038CF00(p + 0x10, D_L01_0028E430_00363BF0 - 0x30) < 1.7f ||
            func_0038CF00(p + 0x10, D_L01_0028E430_00363BF0 - 0x50) < 1.4f ||
            func_0038CF00(p + 0x10, D_L01_0028E430_00363BF0 - 0x70) < 1.2f) {
            if (p != 0 && *(u8 **)(p + 0x24) != 0 &&
                (*(u8 **)(p + 0x24))[0x46] == 0x13 && p[0x20] - 3 == 0) {
                f32 x = func_003824E0(-5.0f, 5.0f) * 0.017453292f;
                f32 y = func_003824E0(0.0f, 5.0f) * 0.017453292f;
                func_L01_002F8D40_00363BF0(p, moby, 1, x, y);
            }
        }
    }
}
/* localdecomp:end func_L01_00363BF0 */

/* localdecomp:start func_L01_00363D90 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F160[];

s32 func_L01_00363D90(void) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F160[i] != 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00363D90 */

/* localdecomp:start func_L01_00363DD0 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];

s32 func_L01_00363DD0(void) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F0C0[i] != 0) return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00363DD0 */

/* localdecomp:start func_L01_00363E10 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];

s32 func_L01_00363E10(s32 value) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F0C0[i] == value) return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00363E10 */

LINKER_REMNANT("asm/levels", func_L01_00363E50);

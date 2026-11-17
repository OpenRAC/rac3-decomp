#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_002F7800 */
void func_L01_002F7800(void) {
}
/* localdecomp:end func_L01_002F7800 */

/* localdecomp:start func_L01_002F7808 */
typedef struct {
    float a[4];
    float b[4];
} Pair_002F7888;
typedef struct {
    u8 pad[16];
    float f;
    u8 pad2[8];
} Src_002F7888;
__asm__(".extern D_L01_001DC2C0, 4");
extern s32 D_L01_001DC2C0;
extern Pair_002F7888 D_L01_0026E050[];
extern Src_002F7888 D_L01_002BE708[];
extern void func_0038D750(float *, s32, float);
void func_L01_002F7808(void) {
    s32 i;
    if (D_L01_001DC2C0 == 0) {
        for (i = 0; i < 10; i++) {
            func_0038D750(D_L01_0026E050[i].a, 0, D_L01_002BE708[i].f);
            func_0038D750(D_L01_0026E050[i - 1].b, 0, -D_L01_002BE708[i].f);
        }
        D_L01_001DC2C0 = 1;
    }
}
/* localdecomp:end func_L01_002F7808 */

INCLUDE_ASM("asm/levels", func_L01_002F78B0);

INCLUDE_ASM("asm/levels", func_L01_002F88E0);

INCLUDE_ASM("asm/levels", func_L01_002F8AA8);

/* localdecomp:start func_L01_002F8D40 */
#include "vu0.h"
s32 func_L01_002F8D40(u8 *m, u8 *target, s32 directed, f32 angle, f32 speed) {
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003C4840(void *, void *, f32);
    extern void func_L01_004450F0(void *, s32, s32);
    vu0_v4 delta, toward;
    u8 *data = *(u8 **)(m + 0x68);
    if (m[0x20] == 4) return 0;
    if (angle == 0.0f) angle = func_003824E0(-0.5235987901687622f, 0.5235987901687622f);
    if (speed == 0.0f) speed = func_003824E0(0.0f, 0.5235987901687622f);
    if (directed) data[0x6D] |= 8;
    if ((u32)(m[0x20] - 2) < 2) {
        if (directed) {
            vec_sub_ab(&delta, target + 0x10, m + 0x10);
            func_0038CF68(data + 0x30, &delta, 0.40000003576278687f);
        } else {
            func_0038CF68(data + 0x30, data + 0x40, 0.1600000113248825f);
        }
    }
    *(f32 *)(data + 0x74) = angle;
    *(f32 *)(data + 0x70) = speed;
    *(s32 *)(data + 0x60) = 0;
    *(u8 **)(data + 0x68) = target;
    vec_sub_ba(&toward, target + 0x10, m + 0x10);
    func_0038CE90(&delta, data + 0x30, &toward);
    func_0038CF68(data + 0x20, &delta, 1.0f);
    func_003C4840(data + 0x20, data + 0x20, 0.25132742524147034f);
    func_L01_004450F0(m, 4, -1);
    return 1;
}
/* localdecomp:end func_L01_002F8D40 */

/* localdecomp:start func_L01_002F8F10 */
void func_L01_002F8F10(void) {

}
/* localdecomp:end func_L01_002F8F10 */

LINKER_REMNANT("asm/levels", func_L01_002F8F18);

INCLUDE_ASM("asm/levels", func_L01_002F8F20);

INCLUDE_ASM("asm/levels", func_L01_002F9310);

/* localdecomp:start func_L01_002F94F8 */
typedef struct {
    u8 pad[0xAA];
    u16 f_AA;
} S_002F94F8;

s32 func_L01_002F94F8(S_002F94F8 *p) {
    u16 v = p->f_AA;
    if ((u32)(v - 13) < 7) {
        return (s16)v - 13;
    }
    switch ((s16)v) {
    case 7516:
        return 7;
    case 7517:
        return 8;
    case 7077:
        return 9;
    default:
        return 0;
    }
}
/* localdecomp:end func_L01_002F94F8 */

/* localdecomp:start func_L01_002F9578 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_2F9578;

typedef struct {
    Vec_2F9578 origin; /* 0x00: the spawner's second point (explosion_spawn: the blast raised) */
    void *owner;       /* 0x10: the moby it is for, or 0 */
    s32 life;          /* 0x14: ticks it lives */
    f32 scale;         /* 0x18: its full scale */
    s16 timer;         /* 0x1C: ticks left */
    s16 opacity;       /* 0x1E: its opacity while it holds */
} DomeVars_2F9578;

typedef struct {
    u8 pad_0[0x10];
    Vec_2F9578 position; /* 0x10 */
    u8 state;            /* 0x20 */
    u8 pad_21[0x23 - 0x21];
    u8 opacity;          /* 0x23 */
    u8 pad_24[0x2C - 0x24];
    f32 scale;           /* 0x2C */
    u8 update_dist;      /* 0x30: names for 0x30-0x32 from Horizon Private Server's libuya */
    u8 drawn;            /* 0x31 */
    s16 draw_dist;       /* 0x32 */
    u8 pad_34[0x68 - 0x34];
    DomeVars_2F9578 *vars; /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    Vec_2F9578 rotation; /* 0xF0: angles x, y, z */
} DomeMoby_2F9578;

extern DomeMoby_2F9578 *func_003C24B0_002F9578(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_003C7C38(u8 *);

/* explosion_dome_spawn: spawns the explosions' dome (class 0x70) at place, at its class's scale
 * times factor, turned at random on all three axes, tinted (r, g, b), for life ticks. */
DomeMoby_2F9578 *func_L01_002F9578(f32 factor, void *owner, Vec_2F9578 *place, Vec_2F9578 *origin,
                                   s32 life, u8 r, u8 g, u8 b, u8 opacity)
{
    DomeMoby_2F9578 *moby;
    DomeVars_2F9578 *vars;
    Vec_2F9578 rotation;

    moby = func_003C24B0_002F9578(0x70, 0x80);
    if (moby != 0) {
        vars = moby->vars;
        {
            Vec_2F9578 turn = { 0 }; /* -pi to pi on each axis */
            turn.x = func_003824E0(-3.1415927f, 3.1415927f);
            turn.y = func_003824E0(-3.1415927f, 3.1415927f);
            turn.z = func_003824E0(-3.1415927f, 3.1415927f);
            rotation = turn;
        }
        moby->state = 0;
        moby->opacity = opacity;
        moby->update_dist = 0xFF;
        moby->draw_dist = 0x1FF;
        moby->drawn = 1;
        func_L01_0043B9E8((u8 *)moby, r, g, b);
        vars->scale = moby->scale * factor;
        moby->scale = 0.0f;
        vars->owner = owner;
        moby->position = *place;
        vars->origin = *origin;
        moby->rotation = rotation;
        vars->life = life;
        vars->timer = vars->life - 3; /* it starts with 3 ticks gone */
        moby->scale = (f32)(life - vars->timer) * vars->scale / (f32)life;
        vars->opacity = opacity;
        func_003C7C38((u8 *)moby);
    }
    return moby;
}
/* localdecomp:end func_L01_002F9578 */

/* localdecomp:start func_L01_002F9738 */
typedef struct {
    u8 pad_0[0x14];
    s32 life;    /* 0x14: ticks it lives */
    f32 scale;   /* 0x18: its full scale */
    s16 timer;   /* 0x1C: ticks left */
    s16 opacity; /* 0x1E: its opacity while it holds */
} DomeVars_2F9738;

typedef struct {
    u8 pad_0[0x23];
    u8 opacity;  /* 0x23 */
    u8 pad_24[0x2C - 0x24];
    f32 scale;   /* 0x2C */
    u8 pad_30[0x68 - 0x30];
    DomeVars_2F9738 *vars; /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    f32 rotation[3]; /* 0xF0: angles x, y, z */
} DomeMoby_2F9738;

extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CB00(void *p);
extern void func_003C2880(void *);

/* explosion_dome_update: the explosions' dome (class 0x70) grows to its scale over its life,
 * turns on all three axes and fades over the last half of its life. */
void func_L01_002F9738(DomeMoby_2F9738 *moby)
{
    DomeVars_2F9738 *vars = moby->vars;
    f32 turn = 0.06283186f; /* 2 pi / 100 rad (3.6 degrees) a frame: NTSC-U turns 3 degrees at 60 Hz */
    s32 half;

    moby->scale = (f32)(vars->life - vars->timer) * vars->scale / (f32)vars->life;
    moby->rotation[0] = func_0038DAB8(moby->rotation[0], turn);
    moby->rotation[1] = func_0038DAB8(moby->rotation[1], turn);
    moby->rotation[2] = func_0038DAB8(moby->rotation[2], turn);
    if (func_0038CB00(&vars->timer)) {
        func_003C2880(moby);
        return;
    }
    half = vars->life / 2;
    if (vars->timer < half) {
        moby->opacity = vars->timer * vars->opacity / half;
    }
}
/* localdecomp:end func_L01_002F9738 */

/* localdecomp:start func_L01_002F9830 */
void func_L01_002F9830(u8 *moby) {
    extern void func_L01_002F9F20(u8 *);
    extern void func_L01_002F9B08(u8 *);
    extern void func_L01_002F9A18(u8 *);
    extern void func_L01_004CAB30(u8 *, u8 *);
    extern void func_L01_004CAC40(u8 *, u8 *);
    extern void func_L01_002FB208(u8 *);
    extern f32 func_0038DAB8(f32, f32);
    u8 *vars = *(u8 **)(moby + 0x68);
    switch (moby[0x20]) {
    case 0:
        if (*(s32 *)(vars + 0x14)) func_L01_002F9F20(moby);
        else func_L01_002F9B08(moby);
        *(f32 *)(moby + 0xF0) = func_0038DAB8(*(f32 *)(moby + 0xF0), 0.041887905448675156f);
        *(f32 *)(moby + 0xF4) = func_0038DAB8(*(f32 *)(moby + 0xF4), 0.15707963705062866f);
        func_L01_002F9A18(moby);
        break;
    case 1:
        func_L01_004CAB30(moby + 0x10, moby + 0x10);
        func_L01_004CAC40(vars, vars);
        func_L01_002FB208(moby);
        break;
    }
}
/* localdecomp:end func_L01_002F9830 */

/* localdecomp:start func_L01_002F98F8 */
typedef int Q_002F98F8 __attribute__((mode(TI)));
u8 *func_L01_002F98F8(Q_002F98F8 *position, Q_002F98F8 *origin) {
    extern s32 func_L01_004C85C8(u8 *, s32, f32, f32, f32);
    u8 *moby = (u8 *)func_003C24B0(0x79, 0x80);
    u8 *vars;
    if (moby) {
        moby[0x30] = 0xFF;
        *(s16 *)(moby + 0x32) = 0x1FF;
        moby[0x31] = 1;
        moby[0x20] = 0;
        vars = *(u8 **)(moby + 0x68);
        *(Q_002F98F8 *)(moby + 0x10) = *position;
        *(Q_002F98F8 *)vars = *origin;
        *(s32 *)(vars + 0x14) = 0;
        *(s32 *)(vars + 0x10) = 25;
        *(s32 *)(vars + 0x18) = 250;
        *(f32 *)(moby + 0xF0) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(moby + 0xF4) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(moby + 0xF8) = func_003824E0(-3.1415927f, 3.1415927f);
        *(s32 *)(moby + 0xFC) = 0;
        func_003C7C38(moby);
        *(s32 *)(vars + 0x1C) = func_L01_004C85C8(moby, 0, 1.0f, 1.0f, 1.0f);
    }
    return moby;
}
/* localdecomp:end func_L01_002F98F8 */

/* localdecomp:start func_L01_002F9A18 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Color_002F9A18;
void func_L01_002F9A18(u8 *moby) {
    extern s32 func_0038CAD0(s32 *);
    Color_002F9A18 color = {0};
    u8 *vars = *(u8 **)(moby + 0x68);
    f32 t;
    s32 r, g, b;
    color.z = color.y = color.x = 128.0f;
    color.w = 255.0f;
    func_0038CAD0((s32 *)(vars + 0x10));
    t = (f32)*(s32 *)(vars + 0x10) / 25.0f;
    b = (s32)((color.z - 64.0f) * t + 64.0f);
    g = (s32)((color.y - 64.0f) * t + 64.0f);
    r = (s32)((color.x - 255.0f) * t + 255.0f);
    *(u32 *)(moby + 0x78) = (b << 16) | 0xFF000000 | (g << 8) | r;
}
/* localdecomp:end func_L01_002F9A18 */

/* localdecomp:start func_L01_002F9B08 */
#include "vu0.h"
typedef struct { vu0_v4 vector; u8 *object; u32 flags; u8 mode,active; u16 oclass; f32 scale; s32 enabled; } Packet_002F9B08;
typedef struct { u8 pad[0x18]; u8 *object; s32 count; vu0_v4 position; u8 pad30[0x10]; vu0_v4 normal; } Hit_002F9B08;
extern s32 D_L01_001E1090;
__asm__(".extern D_L01_001E1090, 4");
extern s32 D_L01_001E1098;
extern f32 D_L01_001EAA28[];
extern u8 D_L01_001EAA00[];
extern u8 *D_001A71A0[];
extern s32 D_L01_001D9E60;
void func_L01_002F9B08(u8 *m) {
    extern void func_L01_004C8688(s32,void *,s32);
    extern void func_L01_004CAB30(void *,void *);
    extern void func_L01_004CAC40(void *,void *);
    extern void func_L01_004C7D40(void *,void *,f32);
    extern void func_L01_002FB2F0(u8 *);
    extern void func_0038CFB8(void *,void *,f32);
    extern s32 func_003D3CB0(void *,void *,s32,void *,void *);
    extern s32 func_003D5630(void);
    extern void func_L01_004C67A0(s32,s32,s32,f32,f32,f32,f32);
    extern u8 *func_L01_003016B0(void *,s32,f32,f32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32,s32);
    extern s32 func_00382468(s32);
    extern void func_L01_00468A68(void *,void *,s32,s32);
    extern void func_L01_0040E790(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_004C8668(s32);
    extern void func_L01_002FA1F8(u8 *,void *,void *);
    vu0_v4 old,shock,normal;
    Packet_002F9B08 packet;
    vu0_v4 position,velocity;
    u8 *d=*(u8 **)(m+0x68);
    *(vu0_q *)&shock=0;
    *(vu0_q *)&normal=0;
    shock.z=0.04000000283122063f;
    *(vu0_q *)&old=*(vu0_q *)(m+0x10);
    normal.z=1.0f;
    vec_add_ba(m+0x10,d,m+0x10);
    func_L01_004C8688(*(s32 *)(d+0x1C),d,0);
    func_L01_004CAB30(m+0x10,m+0x10);
    func_L01_004CAC40(d,d);
    func_L01_004C7D40(m+0x10,d,0.004399999976158142f);
    func_L01_002FB2F0(m);
    packet.object=m;
    packet.flags=0x1030000;
    if (*(s32 *)(d+0x18)<242) packet.flags=0x1030001;
    packet.scale=1.0f;
    packet.enabled=1;
    *(vu0_q *)&packet.vector=*(vu0_q *)d;
    func_0038CFB8(&packet.vector,&packet.vector,1.0f);
    packet.vector.z=1.0f;
    packet.vector.w=5627.9248046875f;
    packet.mode=2;
    packet.oclass=*(u16 *)(m+0xAA);
    packet.active=1;
    if (func_003D3CB0(&old,m+0x10,0x10,m,&packet)) {
        if (func_003D5630()==0 && *(f32 *)(d+8)<0.0f) {
            u8 *r;
            s32 i;
            func_L01_004C67A0(D_L01_001E1090,D_L01_001E1098,1,*(f32 *)(m+0x10),*(f32 *)(m+0x14),0.5f,-0.35f);
            qzero(d);
            *(s32 *)(d+0x14)=1;
            *(f32 *)(d+8)=-0.030000001192092896f;
            position.x=*(f32 *)(m+0x10);
            position.y=*(f32 *)(m+0x14);
            position.z=D_L01_001EAA28[0];
            r=func_L01_003016B0(&position,3,2.0f,1.025f);
            if (r) r[0x23]=0x70;
            { vu0_v4 *pv=&velocity;
            i=15;
            do {
                f32 angle=func_00382538();
                f32 speed=func_003824E0(0.0f,0.06000000238418579f);
                s32 life;
                velocity.x=func_0038D098(angle)*speed;
                velocity.y=func_0038D0B0(angle)*speed;
                velocity.z=func_003824E0(0.06000000238418579f,0.1300000101327896f);
                life=func_00382498(90,120);
                func_L01_00468A68(&position,pv,func_00382468(2),life);
            } while (--i>=0);
            }
        } else {
            if (((Hit_002F9B08 *)D_L01_001EAA00)->object) {
                if (((Hit_002F9B08 *)D_L01_001EAA00)->object==D_001A71A0[0] || *(s16 *)(((Hit_002F9B08 *)D_L01_001EAA00)->object+0xAA)==0xC0) {
                    if (*(s32 *)(d+0x18)>=242) goto done;
                }
                if (*(u8 **)(((Hit_002F9B08 *)D_L01_001EAA00)->object+0x64)==(u8 *)D_L01_001D9E60 && *(s16 *)(((Hit_002F9B08 *)D_L01_001EAA00)->object+0xAA)!=0x336) goto done;
                m[0xBC]=1;
                *(vu0_q *)(m+0x10)=*(vu0_q *)&((Hit_002F9B08 *)D_L01_001EAA00)->position;
                func_L01_0040E790(&shock,d,&((Hit_002F9B08 *)D_L01_001EAA00)->normal);
                func_0038CF68(&shock,&shock,0.04000000283122063f);
                func_0038CF68(&normal,&((Hit_002F9B08 *)D_L01_001EAA00)->normal,1.0f);
            } else if (((Hit_002F9B08 *)D_L01_001EAA00)->count>0) {
                m[0xBC]=1;
                *(vu0_q *)(m+0x10)=*(vu0_q *)&((Hit_002F9B08 *)D_L01_001EAA00)->position;
                func_L01_0040E790(&shock,d,&((Hit_002F9B08 *)D_L01_001EAA00)->normal);
                func_0038CF68(&shock,&shock,0.04000000283122063f);
                func_0038CF68(&normal,&((Hit_002F9B08 *)D_L01_001EAA00)->normal,1.0f);
            }
        }
    } else if (func_0038CAD0((s32 *)(d+0x18))) {
        m[0xBC]=1;
        vec_add_ab(&shock,&shock,d);
    }
done:
    if (m[0xBC]) {
        func_L01_004C8668(*(s32 *)(d+0x1C));
        func_L01_002FA1F8(m,&shock,&normal);
    }
}
/* localdecomp:end func_L01_002F9B08 */

/* localdecomp:start func_L01_002F9F20 */
#include "vu0.h"
typedef struct {
    vu0_v4 vector;
    u8 *owner;
    u32 flags;
    u8 type, enabled;
    u16 kind;
    f32 scale;
    s32 active;
} Hit_002F9F20;
typedef struct {
    u8 pad[0x18];
    u8 *object;
    s32 count;
    vu0_v4 position;
    u8 pad30[0x10];
    vu0_v4 normal;
} Collision_002F9F20;
extern u8 D_L01_001EAA00[];
extern u8 *D_001A71A0[];
extern s32 D_L01_001D9E60;
void func_L01_002F9F20(u8 *obj) {
    extern void func_003C5180(void *,void *,s32);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern void func_L01_002FB5A8(u8 *);
    extern void func_0038CFB8(void *,void *,f32);
    extern s32 func_003D3CB0(void *,void *,s32,void *,void *);
    extern void func_L01_0040E790(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_004C8668(s32);
    extern void func_L01_002FA1F8(u8 *,void *,void *);
    extern void func_L01_002FAAA0(u8 *,void *,void *);
    vu0_v4 reflected = {0,0,0,0};
    vu0_v4 normal = {0,0,0,0};
    vu0_v4 previous;
    vu0_v4 ground;
    Hit_002F9F20 hit;
    u8 *vars = *(u8 **)(obj+0x68);
    previous=*(vu0_v4 *)(obj+0x10);
    reflected.z=0.04000000283122063f;
    normal.z=1.0f;
    vec_add_ab(obj+0x10,obj+0x10,vars);
    func_003C5180(obj+0x10,&ground,0);
    func_0038CE20((f32 *)&ground,(f32 *)&ground,0.0004400000034365803f);
    func_L01_002FB5A8(obj);
    hit.owner=obj;
    hit.flags=0x1030000;
    if (*(s32 *)(vars+0x18)<242) hit.flags=0x1030001;
    hit.scale=1;
    hit.active=1;
    hit.vector=*(vu0_v4 *)vars;
    func_0038CFB8(&hit.vector,&hit.vector,1.0f);
    hit.type=2;
    hit.vector.w=5627.9248046875f;
    hit.kind=*(u16 *)(obj+0xAA);
    hit.vector.z=1;
    hit.enabled=1;
    (*(s32 *)(vars+0x14))++;
    if (func_003D3CB0(&previous,obj+0x10,16,obj,&hit)) {
        if(((Collision_002F9F20 *)D_L01_001EAA00)->object) {
            if ((((Collision_002F9F20 *)D_L01_001EAA00)->object==D_001A71A0[0] || *(s16 *)(((Collision_002F9F20 *)D_L01_001EAA00)->object+0xAA)==0xC0) && *(s32 *)(vars+0x18)>=242) goto done;
            if (*(s32 *)(((Collision_002F9F20 *)D_L01_001EAA00)->object+0x64)==D_L01_001D9E60 && *(s16 *)(((Collision_002F9F20 *)D_L01_001EAA00)->object+0xAA)!=0x336) goto done;
            obj[0xBC]=1;
            *(vu0_v4 *)(obj+0x10)=((Collision_002F9F20 *)D_L01_001EAA00)->position;
            func_L01_0040E790(&reflected,vars,&((Collision_002F9F20 *)D_L01_001EAA00)->normal);
            func_0038CF68(&reflected,&reflected,0.04000000283122063f);
            func_0038CF68(&normal,&((Collision_002F9F20 *)D_L01_001EAA00)->normal,1.0f);
        } else if (((Collision_002F9F20 *)D_L01_001EAA00)->count>0) {
            obj[0xBC]=1;
            *(vu0_v4 *)(obj+0x10)=((Collision_002F9F20 *)D_L01_001EAA00)->position;
            func_L01_0040E790(&reflected,vars,&((Collision_002F9F20 *)D_L01_001EAA00)->normal);
            func_0038CF68(&reflected,&reflected,0.04000000283122063f);
            func_0038CF68(&normal,&((Collision_002F9F20 *)D_L01_001EAA00)->normal,1.0f);
        }
    } else if(func_0038CAD0((s32 *)(vars+0x18))) {
        obj[0xBC]=1;
        vec_add_ab(&reflected,&reflected,vars);
    }
done:
    if (obj[0xBC]) {
        func_L01_004C8668(*(s32 *)(vars+0x1C));
        if (*(s32 *)(vars+0x14)<17) func_L01_002FA1F8(obj,&reflected,&normal);
        else func_L01_002FAAA0(obj,&reflected,&normal);
    }
}
/* localdecomp:end func_L01_002F9F20 */

INCLUDE_ASM("asm/levels", func_L01_002FA1F8);

INCLUDE_ASM("asm/levels", func_L01_002FAAA0);

/* localdecomp:start func_L01_002FB208 */
typedef int Q_002FB208 __attribute__((mode(TI)));
extern u8 D_L01_001EEA80[];
void func_L01_002FB208(u8 *moby) {
    extern f32 func_003C4088(f32, f32, f32);
    extern s32 func_003D4D00(u8 *, s32, u8 *, s32, f32);
    extern void func_L01_00447718(u8 *, Q_002FB208 *, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    Q_002FB208 position;
    s32 hit;
    f32 radius;
    *(u16 *)(moby + 0x34) |= 0x41;
    radius = func_003C4088(0.5f, 5.5f, (f32)moby[0xBC] / 12.0f);
    hit = func_003D4D00(moby + 0x10, 16, moby, 0, radius);
    position = *(Q_002FB208 *)(moby + 0x10);
    func_L01_00447718(moby, &position, D_L01_001EEA80, hit, 0, 0x01030001, 2, 1, 1.0f, 1.0f, 1.0f, -1);
    if (++moby[0xBC] > 12) func_003C2880(moby);
}
/* localdecomp:end func_L01_002FB208 */

/* localdecomp:start func_L01_002FB2F0 */
extern s32 D_L01_001DFB40;
void func_L01_002FB2F0(u8 *moby) {
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_L01_00443B88(f32 *, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_003C5278(u8 *, f32 *, f32 *, f32);
    extern void func_L01_00463378(u8 *, f32 *, f32 *, u32, u32, s32, s32, s32, s32);
    f32 velocity[4] __attribute__((aligned(16)));
    f32 sphere[4] __attribute__((aligned(16)));
    f32 jitter[4] __attribute__((aligned(16)));
    f32 *vars = *(f32 **)(moby + 0x68);
    s32 i;
    u32 start, end;
    s32 a, b, c;
    if ((D_L01_001DFB40 & 7) != 0) return;
    {
    f32 *jitter_p = jitter;
    f32 *velocity_p = velocity;
    f32 *sphere_p = sphere;
    for (i = 0; i >= 0; i--) {
        func_0038CE20(velocity, vars, 0.5f);
        func_L01_00443B88(jitter_p, 0.0f, 0.020000001f);
        vec_add_ab(velocity, jitter, velocity);
        qzero(sphere);
        velocity[3] = func_003824E0(0.25f, 0.15f);
        sphere[3] = func_003824E0(0.15f, 0.05f);
        start = func_0038DBD8(0x804080FF, 0x8040FFFF, func_003824E0(0.0f, 1.0f));
        end = func_0038DBD8(0x80104040, 0x80002080, func_003824E0(0.0f, 1.0f));
        a = (s32)(((func_003824E0(0.0f, 1.0f) + 1.0f) * 5.0f + 2.0f) / 6.0f);
        b = (s32)(((func_003824E0(-0.5f, 0.5f) + 1.0f) * 30.0f * 5.0f + 2.0f) / 6.0f);
        c = (s32)(((func_003824E0(-0.5f, 0.5f) + 1.0f) * 10.0f * 5.0f + 2.0f) / 6.0f);
        func_003C5278(moby + 0x10, sphere_p, sphere_p, (f32)b * 0.0016000001f);
        func_L01_00463378(moby + 0x10, velocity_p, sphere_p, start, end, a, b, c, 0x10019);
    }
    }
}
/* localdecomp:end func_L01_002FB2F0 */

/* localdecomp:start func_L01_002FB5A8 */
extern s32 func_00382468(s32);
extern f32 func_003C3EC8(u8 *position, f32 *out);
extern void func_0038CE20(f32 *, f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00468678(u8 *position, f32 *velocity, s32 colour, f32 size, f32 f13);

/* One frame in four on average, a bubble (particle_spawn_bubble, type 0x22) at the moby, moving
 * at a quarter of the vector its vars start with; func_003C3EC8's result (it also writes the
 * buffer, which the scale then overwrites) goes to the bubble as its f13. */
void func_L01_002FB5A8(u8 *moby)
{
    f32 velocity[4];
    f32 got;
    u8 *vars = *(u8 **)(moby + 0x68);

    if (func_00382468(4) != 0) {
        return;
    }
    got = func_003C3EC8(moby + 0x10, velocity);
    func_0038CE20(velocity, (f32 *)vars, 0.25f);
    func_L01_00468678(moby + 0x10, velocity, 0x88A0A0A0, func_003824E0(0.05f, 0.1f) * 210000.0f, got);
}
/* localdecomp:end func_L01_002FB5A8 */

/* localdecomp:start func_L01_002FB660 */
typedef int Q_002FB660 __attribute__((mode(TI)));
u8 *func_L01_002FB660(Q_002FB660 *position, Q_002FB660 *origin, s32 life, s32 mode, s32 flag, s32 value) {
    u8 *moby = (u8 *)func_003C24B0_002F9578(0x7A, 0x80);
    u8 *vars;
    if (moby) {
        vars = *(u8 **)(moby + 0x68);
        moby[0x30] = 0xFF;
        *(s16 *)(moby + 0x32) = 0xFF;
        moby[0x31] = 1;
        moby[0x23] = 0x80;
        *(s32 *)(vars + 0x24) = value;
        func_L01_0043B9E8(moby, 0x7F, 0x7F, 0x7F);
        *(Q_002FB660 *)(moby + 0x10) = *position;
        *(Q_002FB660 *)vars = *origin;
        *(f32 *)(vars + 0x10) = func_003824E0(0.12566371262073517f, 0.25132742524147034f);
        *(f32 *)(vars + 0x14) = func_003824E0(0.12566371262073517f, 0.25132742524147034f);
        *(s16 *)(vars + 0x18) = life;
        *(s16 *)(vars + 0x1A) = life;
        if (mode == 2) {
            mode = 1;
            *(s32 *)(vars + 0x20) = mode;
        }
        if (mode == 0) *(f32 *)(moby + 0x2C) *= func_003824E0(0.5f, 0.75f);
        *(f32 *)(vars + 0x1C) = *(f32 *)(moby + 0x2C);
        moby[0xBC] = mode | (flag << 1);
        func_003C7C38(moby);
    }
    return moby;
}
/* localdecomp:end func_L01_002FB660 */

/* localdecomp:start func_L01_002FB7D8 */
#include "vu0.h"
typedef struct { s32 a[4]; } Colors_002FB7D8;
extern Colors_002FB7D8 D_L01_001DC348;
extern vu0_v4 D_L01_001EAA40;
void func_L01_002FB7D8(u8 *self)
{
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L01_00448D88(s32,s32);
    extern void func_L01_004637C8(void *,void *,s32,s32,s32,s32,s32,s32);
    extern f32 func_0038DAB8(f32,f32);
    extern s32 func_003D3CB0(void *,void *,s32,void *,s32);
    extern void func_L01_0040E790(void *,void *,void *);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_00451388_002FB7D8(void *,void *,void *,f32);
    extern void func_003C2880(void *);
    extern s32 func_0038CB00(void *);
    u8 *vars=*(u8 **)(self+0x68);
    s32 spawn=1;
    s32 quarter;
    union { Colors_002FB7D8 colors; vu0_v4 old; } temporary;
    if(*(s32 *)(vars+0x20)!=0) {
        if(func_00382468(2)) spawn=0;
    }
    if((self[0xbc]&1) && spawn) {
        vu0_v4 direction;
        temporary.colors=D_L01_001DC348;
        {
            vu0_v4 random={0};
            random.x=func_003824E0(-1.0f,1.0f);
            random.y=func_003824E0(-1.0f,1.0f);
            random.z=func_003824E0(-1.0f,1.0f);
            direction=random;
        }
        func_0038CF68(&direction,&direction,0.020000001f);
        if(self[0xbc]&0xfe) {
            s32 color=func_L01_00448D88(temporary.colors.a[func_00382468(4)],self[0xbc]>>1);
            s32 other=func_L01_00448D88(0x4fff,self[0xbc]>>1);
            func_L01_004637C8(self+0x10,&direction,color,other,37,50,120,1);
        } else {
            func_L01_004637C8(self+0x10,&direction,temporary.colors.a[func_00382468(4)],0x4fff,37,50,120,1);
        }
    }
    *(f32 *)(self+0xf0)=func_0038DAB8(*(f32 *)(self+0xf0),*(f32 *)(vars+0x10));
    *(f32 *)(self+0xf4)=func_0038DAB8(*(f32 *)(self+0xf4),*(f32 *)(vars+0x14));
    if(*(s32 *)(vars+0x24)) {
        temporary.old=*(vu0_v4 *)(self+0x10);
        vec_add_ab(self+0x10,self+0x10,vars);
        if(func_003D3CB0(&temporary.old,self+0x10,16,self,0)) {
            func_L01_0040E790(vars,vars,&D_L01_001EAA40);
            func_0038CF68(vars,vars,func_0038CEA8(vars)*0.76f);
        }
    } else {
        vec_add_ab(self+0x10,self+0x10,vars);
    }
    func_L01_00451388_002FB7D8(self,vars,vars,0.0058400002f);
    if(*(f32 *)(self+0x10)<0.0f || *(f32 *)(self+0x14)<0.0f || *(f32 *)(self+0x18)<0.0f) {
        func_003C2880(self);
        return;
    }
    quarter=*(s16 *)(vars+0x1a)/4;
    if(*(s16 *)(vars+0x18)<quarter) {
        *(f32 *)(self+0x2c)=*(f32 *)(vars+0x1c)*(f32)*(s16 *)(vars+0x18)/(f32)quarter;
    }
    if(func_0038CB00(vars+0x18)) func_003C2880(self);
}
/* localdecomp:end func_L01_002FB7D8 */

INCLUDE_ASM("asm/levels", func_L01_002FBB10);

INCLUDE_ASM("asm/levels", func_L01_002FBCD0);

/* localdecomp:start func_L01_002FC3E8 */
#include "vu0.h"
#include "structs/hero.h"
extern vu0_v4 D_001A4D30;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 16");
void func_L01_002FC3E8(u8 *obj) {
    extern f32 func_00382538(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038D000(void *,void *,void *);
    extern u8 *func_L01_00466588(void *,void *,s32,s32,s32,s32,f32);
    extern f32 func_0038CF00(void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_004669B0(void *,f32,f32,f32,f32,s32,void *,s32,s32);
    vu0_v4 velocity, pos, delta, step;
    u8 *vars=*(u8 **)(obj+0x68);
    struct Hero *hero;
    f32 distance, growth;
    s32 i,count,color;
    u8 *particle;
    velocity.x=func_0038D098(func_00382538())*0.05f;
    velocity.y=func_0038D0B0(func_00382538())*0.05f;
    velocity.z=0.0f;
    velocity.z=-func_003824E0(0.01f,0.03f);
    func_0038D000(&velocity,&velocity,obj+0xC0);
    vec_add_ba(&velocity,&velocity,&D_001A4D30);
    *(vu0_q *)&pos=*(vu0_q *)(obj+0x10);
    if(*(s32 *)((u8 *)&D_001A4D30+0x2474)==128) {
        if(D_L01_001DFB40%3==0)func_L01_00466588(&pos,&velocity,0x4F007FFF,0x1FFFFFFF,8,1,10000.0f);
    } else {
        func_L01_00466588(&pos,&velocity,0x4F007FFF,0x1FFFFFFF,8,1,10000.0f);
    }
    if(*(s32 *)(vars+0xC)) {
        distance=func_0038CF00(vars+0x10,&pos)*0.5f;
        vec_sub_ab(&delta,vars+0x10,&pos);
        for(i=1;i<2;i++) {
            func_0038CF68(&step,&delta,distance*(f32)i);
            vec_add_ab(&step,&pos,&step);
            func_L01_00466588(&step,&velocity,0x4F007FFF,0x1FFFFFFF,8,1,10000.0f);
        }
    }
    *(s32 *)vars=func_00382468(8);
    velocity.x=0.0f;
    velocity.y=0.0f;
    velocity.z=-0.3f;
    velocity.w=1.0f;
    func_0038D000(&velocity,&velocity,obj+0xC0);
    vec_add_ab(&pos,obj+0x10,&velocity);
    velocity.z=-0.075f;
    velocity.w=1.0f;
    velocity.x=0.0f;
    velocity.y=0.0f;
    func_0038D000(&velocity,&velocity,obj+0xC0);
    velocity.z=0.025f;
    vec_add_ab(&velocity,&velocity,&D_001A4D30);
    hero=(struct Hero *)((u8 *)&D_001A4D30-0x150);
    color=0x808080;
    growth=1.075f;
    if(hero->state==8) {
        velocity.z-=0.10000000894069672f;
        color=0xA0A0A0;
        growth=1.0165f;
    }
    if(hero->state==128) {
        velocity.z-=0.06000000238418579f;
        color=0xA0A0A0;
        growth=1.037f;
    }
    {
        particle=func_L01_004669B0(&pos,0.05f,1.01f,growth,30000.0f,6,&velocity,color,0);
        if(particle)particle[3]=68;
    }
    if(*(s32 *)(vars+0xC)) {
        distance=func_0038CF00(vars+0x10,&pos)*0.16667f;
        count=4;
        if(hero->state==8)count=2;
        if(hero->state==128)count=1;
        vec_sub_ab(&delta,vars+0x10,&pos);
        for(i=1;i<count;i++) {
            func_0038CF68(&step,&delta,distance*(f32)i);
            vec_add_ab(&step,&pos,&step);
            particle=func_L01_004669B0(&step,0.05f,1.01f,growth,30000.0f,6,&velocity,color,0);
            if(particle)particle[3]=68;
        }
    }
    *(vu0_q *)(vars+0x10)=*(vu0_q *)&pos;
    *(s32 *)(vars+0xC)=1;
}
/* localdecomp:end func_L01_002FC3E8 */

/* localdecomp:start func_L01_002FC8A8 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
} S_2FC880b;

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x30 - 0x21];
    u8 b30;
    u8 b31;
    s16 h32;
    u8 pad34[0x68 - 0x34];
    S_2FC880b *p68;
} S_2FC880;

extern S_2FC880 *func_003C24B0(s32 a0, s32 a1);

S_2FC880 *func_L01_002FC8A8(s32 a0) {
    S_2FC880 *p = func_003C24B0(167, 128);
    if (p != 0) {
        S_2FC880b *q = p->p68;
        q->w4 = a0;
        q->w0 = 0;
        q->w8 = 0;
        q->wC = 0;
        p->b30 = 255;
        p->h32 = 126;
        p->b31 = 0;
        p->b20 = 0;
    }
    return p;
}
/* localdecomp:end func_L01_002FC8A8 */

/* localdecomp:start func_L01_002FC910 */
typedef struct {
    u8 pad0[0x1B8]; s32 frame;
    u8 pad1BC[0x36E - 0x1BC]; s16 h36E;
    u8 pad370[0x46E - 0x370]; u8 disabled;
    u8 pad46F[0xC18 - 0x46F]; f32 anim;
    u8 padC1C[0x12F0 - 0xC1C]; void *backpack,*clank;
    u8 pad12F8[0x1318 - 0x12F8]; s32 item;
    u8 pad131C[0x25C0 - 0x131C]; u8 *moby;
    s32 state;
    u8 pad25C8[0x2884 - 0x25C8]; s16 suppressed;
} Hero_002FC910;
typedef struct {
    s32 timer,kind; void *owner; s32 active;
    u8 pad10[0x20 - 0x10];
    f32 a,b,c,d,da,db,dc,dd;
} Vars_002FC910;
extern Hero_002FC910 D_001A4BE0_002FC910;
extern u8 *D_001D52FC;
extern u16 D_001A8EA4[];
void func_L01_002FC910(u8 *self)
{
    extern s32 func_L01_004E9238(s32);
    extern s32 func_003A3BB8(s32,s32);
    extern void func_003C2880(void *);
    extern void func_L01_0041A5B0(s32,s32);
    extern void func_L01_002FBCD0(u8 *);
    extern void (func_L01_00404A10_002FC910)(void (*)(u8 *),u8 *);
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_002FC3E8(u8 *);
    s32 active=0;
    Vars_002FC910 *v=*(Vars_002FC910 **)(self+0x68);
    if((D_001A4BE0_002FC910.item==3 || func_L01_004E9238(3)==8) && (self[0x20]==1 || self[0x20]==3)) {
        Hero_002FC910 *h=&D_001A4BE0_002FC910;
        if((u32)(h->state-11)<4 || (h->state==27 && h->moby[0x42]==h->moby[0x43] && h->anim>=6.0f && h->anim<=16.0f)) {if(!h->disabled)active=1;}
        if(D_001A4BE0_002FC910.state==135 && (*(s32 *)(D_001D52FC+0x1A0)&func_003A3BB8(64,0))) active=1;
        if(D_001A4BE0_002FC910.state==16 && D_001A4BE0_002FC910.frame<=36)active=1;
        if(D_001A4BE0_002FC910.state==33 && (D_001A4BE0_002FC910.frame<12 || (D_001A4BE0_002FC910.frame>=28 && D_001A4BE0_002FC910.h36E)))active=1;
        if(D_001A4BE0_002FC910.state==8)active=1;
        if(D_001A4BE0_002FC910.state==135)active=1;
        if(D_001A4BE0_002FC910.suppressed)active=0;
    }
    switch(self[0x20]) {
    case 0:
        self[0x20]=1;
        *(u16 *)(self+0x34)|=1;
        self[0x30]=255;
        *(f32 *)(self+0x18)+=0.5f;
        break;
    case 1:
        if((func_L01_004E9238(3)!=3 && func_L01_004E9238(3)!=8) || !D_001A4BE0_002FC910.clank) {
            func_003C2880(self);
            return;
        }
        if(!D_001A8EA4[0] && D_001A4BE0_002FC910.item==3)func_L01_0041A5B0(0x18CD,0x161);
        if(active) {
            self[0x20]=2;
            v->timer=2;
            v->da=0.00625f;
            v->db=0.1f;
            v->dc=0.025f;
            v->dd=0.0125f;
            v->a=0;
            v->b=0;
            v->c=0;
            v->d=0;
        }
        break;
    case 2:
        v->a+=v->da;
        v->b+=v->db;
        v->c+=v->dc;
        v->d+=v->dd;
        v->owner=D_001A4BE0_002FC910.backpack;
        (func_L01_00404A10_002FC910)(func_L01_002FBCD0,self);
        if(func_0038CAD0(&v->timer)) {
            f32 c, b, a;
            self[0x20]=3;
            a=0.0125f;
            b=0.2f;
            c=0.05f;
            v->d=0.025f;
            v->a=a;
            v->b=b;
            v->c=c;
            v->active=0;
        }
        break;
    case 3:
        v->owner=D_001A4BE0_002FC910.backpack;
        (func_L01_00404A10_002FC910)(func_L01_002FBCD0,self);
        if(!active) {
            self[0x20]=4;
            v->timer=7;
            v->da=0.0017857142956927419f;
            v->db=0.02857142873108387f;
            v->dc=0.0071428571827709675f;
            v->dd=0.0035714285913854837f;
        } else {
            v->a=0.0125f;
            func_L01_002FC3E8(self);
        }
        break;
    case 4:
        if(func_0038CAD0(&v->timer))self[0x20]=1;
        else {
            v->a-=v->da;
            v->b-=v->db;
            v->c-=v->dc;
            v->d-=v->dd;
            v->owner=D_001A4BE0_002FC910.backpack;
            (func_L01_00404A10_002FC910)(func_L01_002FBCD0,self);
        }
        break;
    }
}
/* localdecomp:end func_L01_002FC910 */

INCLUDE_ASM("asm/levels", func_L01_002FCDC0);

/* localdecomp:start func_L01_002FD090 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_002FD090(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_002FD090 */

/* localdecomp:start func_L01_002FD0C8 */
#include "vu0.h"
__asm__(".extern D_L01_001DC434, 4");
extern f32 D_L01_001DC434;
extern vu0_q D_L01_001E16C0[1] __attribute__((section(".sdata")));
void func_L01_002FD0C8(u8 *p) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_L01_002FD818(u8 *);
    extern void func_003D9508(vu0_q *, s32, u32, s32, f32, f32, f32);
    f32 t, a, b, c;
    u32 x, y, z;
    D_L01_001DC434 = func_0038DAB8(D_L01_001DC434, 0.15f);
    t = (func_0038D098(D_L01_001DC434) + 1.0f) * 0.5f;
    a = t * 0.0625f + 0.0625f;
    b = t * 0.19999998807907104f + 0.15f;
    c = t * 0.125f + 0.125f;
    x = func_0038DBD8(0x2F007F00, 0x3F007F00, t);
    y = func_0038DBD8(0x2F7F7F7F, 0x5F7F7F7F, t);
    z = func_0038DBD8(0x10208040, 0x10208040, t);
    func_L01_002FD818(p);
    func_003D9508(D_L01_001E16C0, 0x31, x, 1, c, 0.125f, 0.0f);
    func_003D9508(D_L01_001E16C0, 0x31, y, 1, a, 0.124f, 0.0f);
    func_003D9508(D_L01_001E16C0, 0xB, z, 1, b, 0.123f, 0.0f);
}
/* localdecomp:end func_L01_002FD0C8 */

/* localdecomp:start func_L01_002FD288 */
typedef struct {
    f32 pos[4], second[4], origin[4], attached[4];
    f32 angle[3], velocity[3], scale[3];
    f32 angle2[3], velocity2[3], scale2[3];
    s32 timer, kind;
    u8 *owner;
    s32 remaining, duration, finished;
} Effect_002FD288;
extern Effect_002FD288 D_L01_0026EAB0_002FD288[];
extern vu0_q D_L01_001E16C0[1] __attribute__((section(".sdata")));
void func_L01_002FD288(s32 kind, u8 *owner, s32 duration) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_00382348(u8 *);
    extern void func_L01_00451290(u8 *, f32 *, s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    f32 offset[4] __attribute__((aligned(16)));
    Effect_002FD288 *base = D_L01_0026EAB0_002FD288;
    s32 i = 0;
    vu0_q *origin = D_L01_001E16C0;
    Effect_002FD288 *p;
    u8 *attachment;
    for (; i < 3; i++) {
        p = &base[i];
        if (p->kind != 0) continue;
        p->kind = kind;
        *(vu0_q *)p->origin = *origin;
        p->angle[0] = func_003824E0(-3.1415927f, 3.1415927f);
        p->angle[1] = func_003824E0(-3.1415927f, 3.1415927f);
        p->angle[2] = func_003824E0(-3.1415927f, 3.1415927f);
        p->angle2[0] = func_003824E0(-3.1415927f, 3.1415927f);
        p->angle2[1] = func_003824E0(-3.1415927f, 3.1415927f);
        p->angle2[2] = func_003824E0(-3.1415927f, 3.1415927f);
        p->velocity[0] = func_L01_00443A18(0.001f, 0.005f);
        p->velocity[1] = func_L01_00443A18(0.001f, 0.005f);
        p->velocity[2] = func_L01_00443A18(0.001f, 0.005f);
        p->velocity2[0] = func_L01_00443A18(0.001f, 0.005f);
        p->velocity2[1] = func_L01_00443A18(0.001f, 0.005f);
        p->velocity2[2] = func_L01_00443A18(0.001f, 0.005f);
        p->scale[0] = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->scale[1] = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->scale[2] = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->scale2[0] = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->scale2[1] = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->scale2[2] = func_003824E0(3.25f, 4.75f) * 0.5f;
        qzero(p->pos);
        qzero(p->second);
        p->remaining = duration;
        p->duration = duration;
        p->timer = 12;
        p->owner = owner;
        p->finished = 0;
        attachment = func_00382348(owner);
        if (attachment != 0) {
            func_L01_00451290(owner, offset, 1);
            func_0038CE20(offset, offset, *(f32 *)(attachment + 0x10));
            vec_add_ba(p->attached, offset, owner + 0x10);
        } else {
            *(vu0_q *)p->attached = *(vu0_q *)(owner + 0x10);
        }
        break;
    }
}
/* localdecomp:end func_L01_002FD288 */

/* localdecomp:start func_L01_002FD530 */
typedef struct {
    f32 pos[4], second[4], origin[4], attached[4];
    f32 angle[3], velocity[3], scale[3];
    f32 angle2[3], velocity2[3], scale2[3];
    s32 timer, kind;
    u8 *owner;
    s32 remaining, duration, finished;
} Effect_002FD530;
extern Effect_002FD530 D_L01_0026EAB0[];
extern vu0_q D_L01_001E16C0[1] __attribute__((section(".sdata")));
void func_L01_002FD530(s32 kind) {
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern u8 *func_00382348(u8 *);
    extern void func_L01_00451290(u8 *, f32 *, s32);
    extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
    extern s32 func_0038CAD0(s32 *);
    f32 offset[4] __attribute__((aligned(16)));
    vu0_q *origin = D_L01_001E16C0;
    Effect_002FD530 *base = D_L01_0026EAB0;
    s32 i;
    Effect_002FD530 *p;
    u8 *attachment;
    for (i = 0; i < 3; i++) {
        p = &base[i];
        if (p->kind != kind) continue;
        *(vu0_q *)p->origin = *origin;
        if (p->remaining) {
            p->angle[0] = func_0038DAB8(p->angle[0], p->velocity[0] * 100.0f);
            p->angle[1] = func_0038DAB8(p->angle[1], p->velocity[1] * 100.0f);
            p->angle[2] = func_0038DAB8(p->angle[2], p->velocity[2] * 100.0f);
            p->angle2[0] = func_0038DAB8(p->angle2[0], p->velocity2[0] * 100.0f);
            p->angle2[1] = func_0038DAB8(p->angle2[1], p->velocity2[1] * 100.0f);
            p->angle2[2] = func_0038DAB8(p->angle2[2], p->velocity2[2] * 100.0f);
        } else {
            p->angle[0] = func_0038DAB8(p->angle[0], p->velocity[0] * 50.0f);
            p->angle[1] = func_0038DAB8(p->angle[1], p->velocity[1] * 50.0f);
            p->angle[2] = func_0038DAB8(p->angle[2], p->velocity[2] * 50.0f);
            p->angle2[0] = func_0038DAB8(p->angle2[0], p->velocity2[0] * 50.0f);
            p->angle2[1] = func_0038DAB8(p->angle2[1], p->velocity2[1] * 50.0f);
            p->angle2[2] = func_0038DAB8(p->angle2[2], p->velocity2[2] * 50.0f);
        }
        p->pos[0] = func_0038D098(p->angle[0]) * p->scale[0];
        p->pos[1] = func_0038D0B0(p->angle[1]) * p->scale[1];
        p->pos[2] = -func_0038D0B0(p->angle[2]) * p->scale[2];
        p->second[0] = func_0038D098(p->angle2[0]) * p->scale2[0];
        p->second[1] = func_0038D0B0(p->angle2[1]) * p->scale2[1];
        p->second[2] = -func_0038D0B0(p->angle2[2]) * p->scale2[2];
        if (p->owner) {
            attachment = func_00382348(p->owner);
            if (attachment) {
                func_L01_00451290(p->owner, offset, 1);
                func_0038CE20(offset, offset, *(f32 *)(attachment + 0x10));
                vec_add_ab(p->attached, offset, p->owner + 0x10);
            } else {
                *(vu0_q *)p->attached = *(vu0_q *)(p->owner + 0x10);
            }
            func_0038CDF8(p->attached, p->origin, p->attached, 1.0f - (f32)p->remaining / (f32)p->duration);
        }
        if (func_0038CAD0(&p->remaining)) {
            if (!p->finished) p->finished = 1;
            if (func_0038CAD0(&p->timer)) p->kind = 0;
        }
    }
}
/* localdecomp:end func_L01_002FD530 */

INCLUDE_ASM("asm/levels", func_L01_002FD818);

/* localdecomp:start func_L01_002FD988 */
void func_L01_002FD988(f32 *p) {
    *(long *)(p + 32) = 0x0000FF9000000260L;
    *(long *)(p + 28) = 0;
    p[20] = 0.0f;
    p[21] = 0.0f;
    p[22] = 1.0f;
    p[23] = 0.0f;
    p[24] = 0.0f;
    p[25] = 1.0f;
    p[26] = 1.0f;
    p[27] = 1.0f;
    p[2] = -1.0f;
    p[6] = 1.0f;
    p[10] = -1.0f;
    p[14] = 1.0f;
    p[1] = -1.0f;
    p[5] = -1.0f;
    p[9] = 1.0f;
    p[13] = 1.0f;
    p[0] = 0.0f;
    p[4] = 0.0f;
    p[8] = 0.0f;
    p[12] = 0.0f;
    p[3] = 1.0f;
    p[7] = 1.0f;
    p[11] = 1.0f;
    p[15] = 1.0f;
}
/* localdecomp:end func_L01_002FD988 */

INCLUDE_ASM("asm/levels", func_L01_002FDA10);

/* localdecomp:start func_L01_002FDBD8 */
void func_L01_002FDBD8(f32 (*pts)[4], s32 n) {
    f32 d[4];

    vec_sub_ab(d, pts[n - 2], pts[n - 3]);
    vec_add_ab(pts[n - 1], pts[n - 2], d);
}
/* localdecomp:end func_L01_002FDBD8 */

INCLUDE_ASM("asm/levels", func_L01_002FDC18);

/* localdecomp:start func_L01_002FE0A0 */
extern f32 D_L01_001D66B0;
extern u8 *D_L01_00221208[];
void func_L01_002FE0A0(f32 *pos, f32 size) {
    extern s32 func_00382468(s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_0046A610(f32 *, f32 *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    f32 point[4];
    u8 *p;
    size *= 210000.0f;
    if (func_00382468(2)) {
        s32 rotation = (s32)func_L01_00443A18(1.0f, -1.0f);
        p = func_L01_0046A610(pos, &D_L01_001D66B0, 2, 6, 0x20FF40, rotation, size * 6.0f, 500.0f, 1.0f, 0.0f, 2.0f);
        if (p) p[2] = D_L01_00221208[0][1];
    }
    point[0] = pos[0] + func_L01_00443A18(0.0f, 0.04f);
    point[1] = pos[1] + func_L01_00443A18(0.0f, 0.04f);
    point[2] = pos[2] + func_L01_00443A18(0.0f, 0.04f);
    if (func_00382468(2)) {
        s32 rotation = (s32)func_L01_00443A18(1.0f, -1.0f);
        p = func_L01_0046A610(point, &D_L01_001D66B0, 2, 127, 0x20FF40, rotation, size * 2.4f, 500.0f, 1.0f, 0.0f, 2.0f);
        if (p) {
            p[3] = func_00382468(2) ? 72 : 68;
            p[2] = D_L01_00221208[0][0];
        }
    }
}
/* localdecomp:end func_L01_002FE0A0 */

INCLUDE_ASM("asm/levels", func_L01_002FE280);

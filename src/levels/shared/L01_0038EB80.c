#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} G391938A;
typedef struct {
    u8 pad0[336];
    s16 unk150;
    s16 unk152;
} G391938B;
typedef struct {
    u8 pad0[36];
    s32 unk24;
} V391938;
typedef struct {
    u8 pad0[104];
    V391938 *pVars;
} M391938;
typedef int s128 __attribute__((mode(TI)));
typedef union {
    s128 q;
    f32 f[4];
} V_003919E0;
typedef struct { u8 pad0[48]; s32 id; u8 pad1[28]; } Ent_00312A80;
typedef struct {
    u8 pad0[52];
    f32 f34;
    u8 pad38[72 - 56];
    f32 f48;
    u8 pad4C[96 - 76];
    s32 w60;
    u8 pad64[104 - 100];
    s32 w68;
    u8 pad6C[112 - 108];
    s32 w70;
    u8 pad74[124 - 116];
    s32 w7C;
} S_393258;

INCLUDE_ASM("asm/levels", func_L01_0038EB80);

/* localdecomp:start func_L01_0038F3F8 */
#include "vu0.h"
extern vu0_q D_L01_00291750[][4][137];
extern f32 D_L01_0029C290[][4][137];
extern vu0_v4 D_L01_0029EE60[][4];
extern s32 D_L01_0029EE00[][4];
extern s32 D_L01_0029ED60[][4];
extern s32 D_L01_0029EDB0[][4];
extern f32 D_L01_001E1F50[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1F68[] __attribute__((section(".sdata")));
extern f32 D_L01_001E1F80[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1FE0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1F98[] __attribute__((section(".sdata")));
extern f32 D_L01_001E1FB0[] __attribute__((section(".sdata")));
extern f32 D_L01_001E1FC8[] __attribute__((section(".sdata")));
void func_L01_0038F3F8(u8 *obj) {
    extern f32 func_003824E0(f32, f32);
    extern s32 func_0013D3E0(void);
    s32 *index = *(s32 **)(obj+0x68);
    s32 i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<137;j++) {
            f32 r=func_003824E0(0.5f,4.0f);
            qzero(&D_L01_00291750[*index][i][j]);
            D_L01_0029C290[*index][i][j]=r;
        }
        *(vu0_q *)((u8 *)D_L01_0029EE60 + *index * 64 + i * 16)=*(vu0_q *)(obj+0x10);
        D_L01_0029EE00[*index][i]=5;
        D_L01_0029ED60[*index][i]=func_0013D3E0()%128+128;
        D_L01_0029EDB0[*index][i]=func_0013D3E0()%2+6;
        D_L01_0029EE60[*index][i].x += func_003824E0(0.0f,0.5f)+ -0.25f;
        D_L01_0029EE60[*index][i].y += func_003824E0(0.0f,0.5f)+ -0.25f;
        D_L01_0029EE60[*index][i].z += func_003824E0(0.0f,0.5f)+ -0.25f;
    }
    D_L01_001E1F50[*index]=0.01f;
    D_L01_001E1F68[*index]=128;
    D_L01_001E1F80[*index]=0.1f;
    D_L01_001E1FE0[*index]=5;
    D_L01_001E1F98[*index]=128;
    D_L01_001E1FB0[*index]=0.0f;
    D_L01_001E1FC8[*index]=0.0f;
}
/* localdecomp:end func_L01_0038F3F8 */

INCLUDE_ASM("asm/levels", func_L01_0038F728);

/* localdecomp:start func_L01_0038FCA8 */
void func_L01_0038FCA8(u8 *a) {
    a[32] = 2;
}
/* localdecomp:end func_L01_0038FCA8 */

INCLUDE_ASM("asm/levels", func_L01_0038FCB8);

/* localdecomp:start func_L01_003900F8 */
#include "vu0.h"
void func_L01_003900F8(vu0_v4 *origin) {
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32 low, f32 high);
    extern s32 func_00382498(s32, s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32 angle);
    extern u8 *func_L01_0046B288(void *, u32, u32, s32, f32, f32);
    extern s32 func_00382468(s32);
    vu0_v4 position;
    f32 angle, radius, a, b;
    s32 life;
    s32 i = 0;
    u8 *particle;
    do {
        i--;
        angle = func_00382538();
        radius = func_003824E0(0.0f, 0.6f);
        a = func_003824E0(0.0f, 1.5f);
        b = func_003824E0(1.0f, 5.0f);
        life = func_00382498(100, 160);
        position.x = func_0038D098(angle) * radius;
        position.y = func_0038D0B0(angle) * radius;
        position.z = 0.0f;
        vec_add_ba(&position, &position, origin);
        particle = func_L01_0046B288(&position, 0x5005C162, 0x0005C162, life, a, b);
        if (particle != 0) {
            particle[3] = func_00382468(3) ? 0x48 : 0x44;
        }
    } while (i >= 0);
}
/* localdecomp:end func_L01_003900F8 */

/* localdecomp:start func_L01_00390240 */
typedef int u128_390240 __attribute__((mode(TI)));
typedef struct {
    u128_390240 velocity;
    f32 spin_x;                /* 0x10: radians a frame */
    f32 spin_y;                /* 0x14 */
    s32 unk_18;
    u8 pad_1C[0x30 - 0x1C];
    void *owner;               /* 0x30 */
    s32 unk_34;                /* 0x34: from func_L01_004C85C8 */
} BombVars_390240;
typedef struct {
    u8 pad_0[0x10];
    u128_390240 position;
    s8 state;
    u8 pad_21[0x23 - 0x21];
    u8 opacity;
    u8 pad_24[0x2C - 0x24];
    f32 scale;
    u8 unk_30;
    u8 pad_31;
    u16 unk_32;
    u8 pad_34[0x68 - 0x34];
    BombVars_390240 *vars;
} Moby_390240;

extern void *func_003C24B0(s32 class_id, s32 flags);
extern f32 func_003824E0(f32 low, f32 high);
extern s32 func_L01_004C85C8(void *moby, void *a1, f32 a2, f32 a3, f32 a4);
extern void func_003C7C38(void *moby);

/* infecto_bomb_spawn: spawns the Infecto-Bomb's blob (class 0x188A) at position with velocity:
   scale 0.0165 where its class's is 0.0588, opacity 0x28, a random spin */
Moby_390240 *func_L01_00390240(void *owner, u128_390240 *position, u128_390240 *velocity) {
    Moby_390240 *bomb = func_003C24B0(0x188A, 0x80);

    if (bomb != 0) {
        BombVars_390240 *vars;

        bomb->state = 0;
        bomb->unk_32 = 0xFF;
        bomb->unk_30 = 0xFF;
        vars = bomb->vars;
        bomb->position = *position;
        vars->velocity = *velocity;
        bomb->opacity = 0x28;
        bomb->scale = 0.0165f;
        /* 2 pi / 100 to 2 pi / 50 */
        vars->spin_x = func_003824E0(0.062831856f, 0.12566371f);
        vars->spin_y = func_003824E0(0.062831856f, 0.12566371f);
        vars->owner = owner;
        vars->unk_18 = 0;
        vars->unk_34 = func_L01_004C85C8(bomb, 0, 1.0f, 1.0f, 1.0f);
        func_003C7C38(bomb);
    }
    return bomb;
}
/* localdecomp:end func_L01_00390240 */

INCLUDE_ASM("asm/levels", func_L01_00390358);

/* localdecomp:start func_L01_00390A40 */
typedef int u128_390A40 __attribute__((mode(TI)));
typedef struct {
    u128_390A40 rotation;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} BurstVars_390A40;
typedef struct {
    u8 pad_0[0x10];
    u128_390A40 position;
    s8 state;
    u8 pad_21[0x30 - 0x21];
    u8 unk_30;
    u8 pad_31[0x68 - 0x31];
    BurstVars_390A40 *vars;
} Moby_390A40;

extern void *func_003C24B0(s32 class_id, s32 flags);

/* infecto_burst_spawn: spawns the Infecto-Bomb's burst (class 0x188B) where the bomb lands,
   turned by rotation (the bomb passes the zero rotation) */
Moby_390A40 *func_L01_00390A40(u128_390A40 *position, u128_390A40 *rotation) {
    Moby_390A40 *burst = func_003C24B0(0x188B, 0x80);

    if (burst != 0) {
        BurstVars_390A40 *vars;

        burst->state = 0;
        burst->unk_30 = 0xFF;
        vars = burst->vars;
        burst->position = *position;
        vars->rotation = *rotation;
        vars->unk_10 = 0x19;
        vars->unk_14 = 0;
        vars->unk_18 = 0x3A;
    }
    return burst;
}
/* localdecomp:end func_L01_00390A40 */

INCLUDE_ASM("asm/levels", func_L01_00390AB8);

LINKER_REMNANT("asm/levels", func_L01_003912D0);

/* localdecomp:start func_L01_003912E0 */
typedef struct {
    u8 pad0[0x1200]; u8 *moby;
    u8 pad1204[0x1228 - 0x1204]; s32 index;
    u8 pad122C[0x28C9 - 0x122C]; u8 active;
} Hero_003912E0;
typedef struct { u8 pad0[0x1A0]; u8 *table; } Table_003912E0;
extern u8 D_001A4BE0[];
extern s32 D_L01_001DDFE8;
__asm__(".extern D_L01_001DDFE8, 4");
extern u8 D_001425C0[];
typedef struct { u8 pad0; u8 kind; u8 pad2[0xEE]; } Row_003912E0;
extern u8 D_L01_002C5600[];
extern u8 *D_L01_00221098[];
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
void func_L01_003912E0(u8 *moby) {
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(u8 *);
    extern f32 func_0038D098(f32);
    extern void func_003C2F58(u8 *, s32, void *);
    extern void func_L01_00391938(u8 *);
    extern void func_L01_003916E8(u8 *);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_00424D88(s32);
    extern void func_L01_00391A80(u8 *);
    extern void func_L01_00391D88(u8 *);
    extern void func_L01_00391F98(u8 *);
    extern void func_L01_00404A10_003912E0(void (*)(u8 *), u8 *);
    f32 position[4] __attribute__((aligned(16)));
    f32 point[4] __attribute__((aligned(16)));
    Hero_003912E0 *hero = (Hero_003912E0 *)D_001A4BE0;
    u8 *vars = *(u8 **)(moby + 0x68);
    *(u8 **)(vars + 0x18) = hero->moby;
    hero->active = 1;
    if (!*(u8 **)(vars + 0x18)) { hero->active = 0; return; }
    func_003C2F58(*(u8 **)(vars + 0x18), 0, moby + 0x10);
    switch (moby[0x20]) {
    case 0:
        moby[0x20] = 3;
        *(s32 *)(vars + 4) = 100;
        *(s32 *)(vars + 0x14) = 0;
        break;
    case 3: {
        s32 colour, i;
        s32 kind;
        s32 sixth;
        u8 *particle;
        if ((*(s32 *)(vars + 4) & 7) == 0) func_L01_00391938(moby);
        func_0038CAD0(vars + 4);
        func_L01_003916E8(moby);
        *(s128 *)position = *(s128 *)(hero->moby + 0x10);
        func_003C2F58(hero->moby, 0, point);
        kind = ((Row_003912E0 *)(D_001425C0[hero->index] * 0xF0 + (s32)D_L01_002C5600))->kind;
        if (kind == 1) colour = 0x0080FF20;
        else if (kind == 2) colour = 0x00FF1010;
        else if (kind == 3) colour = 0x00FF8020;
        else colour = 0x00601010;
        sixth = 6;
        i = 1;
        do {
            s32 life = (func_00382498(10, 20) * 5 + 2) / sixth;
            particle = func_L01_004713C8(point, D_L01_001D66B0, life, colour, func_00382498(-1, -3), 0x30, 0, 0, 31500.001953125f, 157500.0f, -0.0004000000189989805f);
            if (particle) {
                s32 index = func_00382498(0, 3);
                particle[2] = ((Table_003912E0 *)D_L01_00221098)->table[index];
            }
            i--;
        } while (i >= 0);
        if (*(s32 *)(vars + 4) < 34) moby[0x20] = 4;
        break;
    }
    case 4:
        if (func_0038CAD0(vars + 4) && *(s32 *)vars == 0) {
            if (*(u8 **)(vars + 8)) func_003C2880(*(u8 **)(vars + 8));
            if (*(u8 **)(vars + 12)) func_003C2880(*(u8 **)(vars + 12));
            if (*(s32 *)(vars + 16) != -1) func_L01_00424D88(*(s32 *)(vars + 16));
            hero->active = 0;
            D_L01_001DDFE8 = 0;
            func_003C2880(moby);
            return;
        }
        break;
    }
    func_0038D098((1.0f - (f32)*(s32 *)(vars + 4) / 100.0f) * 6.2831854820251465f - 3.1415927410125732f);
    func_L01_00391A80(moby);
    func_L01_00391D88(moby);
    func_L01_00404A10_003912E0(func_L01_00391F98, moby);
}
/* localdecomp:end func_L01_003912E0 */

/* localdecomp:start func_L01_00391610 */
typedef struct { u8 pad[0x1C]; s32 owner; u8 tail[0x10]; } Entry_00391610;
typedef struct { u8 pad[0x44]; s32 owner; u8 tail[8]; } EntryB_00391610;
extern s32 D_L01_001DDFE8;
__asm__(".extern D_L01_001DDFE8, 4");
extern Entry_00391610 D_L01_0029EFA0_00391610[];
extern EntryB_00391610 D_L01_0029F1E0_00391610[];
void func_L01_00391610(void) {
    extern s32 func_L01_00424CB0(void *,f32,f32,f32,f32,f32);
    Moby_390240 *obj;
    u8 *p;
    void *pos;
    s32 i;
    if(D_L01_001DDFE8==0) {
        obj=func_003C24B0(0x188D,0x80);
        if(obj) {
            obj->unk_30=0xFF;
            obj->unk_32=0xFF;
            p=(u8 *)obj->vars;
            obj->state=0;
            pos=&obj->position;
            for(i=11;i>=0;i--)D_L01_0029EFA0_00391610[i].owner=0;
            for(i=127;i>=0;i--)D_L01_0029F1E0_00391610[i].owner=0;
            *(s32 *)(p+0x10)=func_L01_00424CB0(pos,0.0f,0.0f,0.0f,0.0f,0.0f);
            D_L01_001DDFE8=(s32)obj;
        }
    }
}
/* localdecomp:end func_L01_00391610 */

/* localdecomp:start func_L01_003916E0 */
extern s32 D_L01_001DDFE8;

void func_L01_003916E0(void) { D_L01_001DDFE8 = 0; }
/* localdecomp:end func_L01_003916E0 */

INCLUDE_ASM("asm/levels", func_L01_003916E8);

/* localdecomp:start func_L01_00391938 */
#include "vu0.h"
typedef struct { vu0_q direction; f32 angle, speed; s32 life; void *owner; f32 scale; u8 pad[12]; } Particle_00391938;
extern Particle_00391938 D_L01_0029EFA0[];
void func_L01_00391938(u8 *m) {
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    vu0_v4 forward, position, end;
    vu0_v4 *pos = &position;
    u8 *v = *(u8 **)(m+0x68);
    Particle_00391938 *p;
    p=D_L01_0029EFA0;
    do {
        if(p->owner == 0) {
            p->owner=m;
            p->angle=func_00382538();
            p->speed=func_L01_00443A18(1200.0f,1400.0f)*0.017453292f*0.020000001f;
            p->life=31;
            p->scale=func_003824E0(0.3f,0.4f);
            func_0038CF68(&forward,*(u8 **)(v+0x18)+0xD0,1.0f);
            *(vu0_q *)&position=*(vu0_q *)(m+0x10);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(end) : "m"(position), "m"(forward) : "vf1", "vf2");
            func_0038CE90((f32 *)pos,(f32 *)pos,(f32 *)&end);
            func_0038CF68(p,pos,p->scale);
            break;
        }
        p++;
    } while ((s32)p < (s32)(D_L01_0029EFA0+12));
}
/* localdecomp:end func_L01_00391938 */

/* localdecomp:start func_L01_00391A80 */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(f32 *, f32 *, f32 *, f32);
extern void func_L01_00391BD0_00391A80(u8 *, vu0_v4 *, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);

void func_L01_00391A80(u8 *m) {
    vu0_v4 forward, pos;
    u8 *v = *(u8 **)(m + 0x68);
    Particle_00391938 *p;
    f32 t;
    s32 i;

    for (i = 0; i < 12; i++) {
        p = &D_L01_0029EFA0[i];
        if (p->owner == m) {
            func_0038CF68(&forward, *(u8 **)(v + 0x18) + 0xD0, 1.0f);
            t = p->life / 37.0f;
            func_0038D890((f32 *)&pos, (f32 *)p, (f32 *)&forward, p->angle);
            func_L01_00391BD0_00391A80(m, &pos, t * 128.0f);
            p->angle = func_0038DAB8(p->angle, p->speed);
            func_0038CF68(&forward, &forward, 0.04f);
            vec_add_ab(p, p, &forward);
            if (func_0038CAD0(&D_L01_0029EFA0[i].life)) {
                p->owner = 0;
            }
        }
    }
}
/* localdecomp:end func_L01_00391A80 */

/* localdecomp:start func_L01_00391BD0 */
#include "vu0.h"
typedef int Q_00391BD0 __attribute__((mode(TI)));
typedef struct {
    Q_00391BD0 pos, vel;
    f32 f20, f24, f28, f2C;
    s32 f30, f34, color, life, start;
    u8 *owner;
    s32 f48, f4C;
} Effect_00391BD0;
extern Effect_00391BD0 D_L01_0029F1E0[];
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
void func_L01_00391BD0(u8 *obj, Q_00391BD0 *pos, s32 kind)
{
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    s32 *vars = *(s32 **)(obj + 0x68);
    u8 *base = (u8 *)D_L01_0029F1E0;
    u8 *hero = D_001A4BE0;
    u8 *map = D_001425C0;
    u8 *weapons = D_L01_002C5600;
    s32 i;
    Effect_00391BD0 *p;
    for (i = 0; i < 128; ++i) {
        p = (Effect_00391BD0 *)(i * 80 + base);
        if (p->owner == 0) {
            p->owner = obj;
            p->f30 = kind;
            p->pos = *pos;
            qzero(&p->vel);
            {
                u8 type = weapons[*(u8 *)(*(s32 *)(hero + 0x1228) + (s32)map) * 240 + 1];
                if (type == 1) p->color = 0x601010;
                else if (type == 2) p->color = 0x204060;
                else if (type == 3) p->color = 0x101060;
                else p->color = 0x601010;
            }
            p->f20 = func_003824E0(0.1f, 0.2f);
            p->f24 = func_003824E0(0.3f, 0.4f);
            p->life = (func_00382498(25, 40) * 5 + 2) / 6;
            p->start = p->life;
            p->f2C = func_00382538();
            p->f28 = func_L01_00443A18(180.0f, 360.0f) * 0.017453292f * 0.020000001f;
            ++*vars;
            break;
        }
    }
}
/* localdecomp:end func_L01_00391BD0 */

/* localdecomp:start func_L01_00391D88 */
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CF68(void *out, void *in, f32 length);
extern void func_0038CE20(f32 *, f32 *, f32);
extern s32 func_0038CAD0(void *);
void func_L01_00391D88(u8 *obj) {
    Effect_00391BD0 *r;
    u8 *vars = *(u8 **)(obj + 0x68);
    vu0_v4 change;
    s32 i;
    for (i = 0; i < 128; i++) {
        r = &D_L01_0029F1E0[i];
        if (r->owner == obj) {
            r->f34 = (s32)((f32)r->f30 * ((f32)r->life / (f32)r->start));
            r->f2C = func_0038DAB8(r->f2C, r->f28);
            vec_add_ab(&r->pos, &r->pos, &r->vel);
            func_0038CF68(&change, *(u8 **)(vars + 0x18) + 0xD0, 1.0f);
            func_0038CE20((f32 *)&change, (f32 *)&change, -0.0009f);
            vec_add_ab(&r->vel, &r->vel, &change);
            if (func_0038CAD0(&r->life)) {
                if (r->f34 > 0) r->f34--;
                else {
                    r->owner = 0;
                    (*(s32 *)vars)--;
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00391D88 */

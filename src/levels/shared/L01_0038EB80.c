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

INCLUDE_ASM("asm/levels", func_L01_003900F8);

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

INCLUDE_ASM("asm/levels", func_L01_00391A80);

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

INCLUDE_ASM("asm/levels", func_L01_00391D88);

INCLUDE_ASM("asm/levels", func_L01_00391EC8);

/* localdecomp:start func_L01_00391F98 */
extern G391938B D_001CFEC0;
extern void func_0038AF30(s32, s32, s32, s32, s32);
extern f32 func_L01_004451A8(f32);
extern void func_L01_00391EC8(void *);
void func_L01_00391F98(u8 *a0) {
    s32 n = *(s32 *)(*(u8 **)(a0 + 0x68) + 4);

    if (n >= 0x58) {
        f32 t = func_L01_004451A8((f32)(n - 0x57) / 12.0f);
        s32 c = t * 128.0f;

        c = (c << 24) | 0xFFFFFF;
        ((void (*)(s32, s32, s32, s32, unsigned long))func_0038AF30)(0, D_001CFEC0.unk152, 0, D_001CFEC0.unk150, c);
    }
    func_L01_00391EC8(a0);
}
/* localdecomp:end func_L01_00391F98 */

/* localdecomp:start func_L01_00392040 */
void func_L01_00392040(u8 *p)
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
/* localdecomp:end func_L01_00392040 */

/* localdecomp:start func_L01_003920C8 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_003920C8(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_003920C8 */

INCLUDE_ASM("asm/levels", func_L01_00392130);

/* localdecomp:start func_L01_003922E0 */
s32 func_L01_003922E0(s32 n) {
    s32 a = 16;
    if (n % a != 0) {
        n = ((s32)((f32)n / (f32)a) + 1) * a;
    }
    return n;
}
/* localdecomp:end func_L01_003922E0 */

INCLUDE_ASM("asm/levels", func_L01_00392328);

/* localdecomp:start func_L01_00392908 */
typedef int u128_392908 __attribute__((mode(TI)));
typedef struct {
    u128_392908 origin;        /* 0x00 */
} DreadVars_392908;
typedef struct {
    u8 pad_0[0x10];
    u128_392908 position;      /* 0x10 */
    s8 state;                  /* 0x20 */
    u8 pad_21[0x30 - 0x21];
    u8 update_dist;            /* 0x30-0x32: names from Horizon Private Server's libuya */
    u8 drawn;
    u16 draw_dist;
    u16 mode_flags;            /* 0x34: 0x100 draw the matrix at +0xC0 as set */
    u8 pad_36[0x68 - 0x36];
    DreadVars_392908 *vars;    /* 0x68 */
    u8 pad_6C[0xC0 - 0x6C];
    u128_392908 matrix[3];     /* 0xC0 */
    u128_392908 rotation;      /* 0xF0 */
} Moby_392908;

/* The Dread blast now out; a new one removes it */
__asm__(".extern D_L01_001DE000, 4");
extern s32 D_L01_001DE000;
extern u8 *D_001A71A0[];
extern void *func_003C24B0(s32 class_id, s32 flags);
extern void func_0038D308(u8 *, u8 *);
extern void func_003C5180(void *position, void *normal, s32 flags);
extern void func_0038CF68(void *out, void *in, f32 length);
extern void func_0038CE90(f32 *, f32 *, f32 *);
extern f32 func_0038CE68(f32 *, f32 *);
extern f32 func_0038D0B0(f32 angle);
extern void func_0038CE20(f32 *, f32 *, f32);
extern f32 func_0038D098(f32);
extern void func_0038D810(void *quat, void *matrix);
extern void func_0038D5F0(void *a0, void *a1, void *a2);
extern void func_003C2880(u8 *);

/* dread_blast_spawn: spawns the Dread blast (class 0x188F), the Agents of Dread's end at V5,
   turned so its up lies along the ground's normal under it */
Moby_392908 *func_L01_00392908(u128_392908 *position, u128_392908 *origin) {
    f32 turn[4];
    f32 axis[4];
    f32 normal[4];
    u128_392908 rot[3];
    f32 half;
    Moby_392908 *blast = func_003C24B0(0x188F, 0x80);
    DreadVars_392908 *vars = blast->vars;

    if (blast != 0) {
        u128_392908 *centre = &blast->position;

        blast->mode_flags |= 0x100;
        blast->state = 0;
        blast->draw_dist = 0xFF;
        blast->update_dist = 0xFF;
        blast->position = *position;
        vars->origin = *origin;
        func_0038D308((u8 *)blast->matrix, D_001A71A0[0] + 0xF0);
        func_003C5180(centre, normal, 1);
        func_0038CF68(normal, normal, 1.0f);
        /* turn its z row toward the ground's normal: a quaternion about their cross product,
           from half their dot product through the two VU0 trig helpers */
        func_0038CE90(axis, (f32 *)&blast->matrix[2], normal);
        half = func_0038CE68((f32 *)&blast->matrix[2], normal) * 0.5f;
        func_0038CE20(turn, axis, func_0038D0B0(half));
        turn[3] = func_0038D098(half);
        func_0038D810(turn, rot);
        func_0038D5F0(blast->matrix, rot, blast->matrix);
        if (D_L01_001DE000 != 0) {
            func_003C2880((u8 *)D_L01_001DE000);
        }
        D_L01_001DE000 = (s32)blast;
    }
    return blast;
}
/* localdecomp:end func_L01_00392908 */

/* localdecomp:start func_L01_00392A78 */
extern s32 D_L01_001DE000;

void func_L01_00392A78(void) { D_L01_001DE000 = 0; }
/* localdecomp:end func_L01_00392A78 */

/* localdecomp:start func_L01_00392A80 */
extern u8 *D_L01_001E2018;

void func_L01_00392A80(void) {
    D_L01_001E2018 = 0;
    D_L01_001DE000 = 0;
}
/* localdecomp:end func_L01_00392A80 */

INCLUDE_ASM("asm/levels", func_L01_00392A90);

/* localdecomp:start func_L01_00392D80 */




extern G391938A D_001A1ED0;
extern G391938B D_001CFEC0;
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, s32);

void func_L01_00392D80(M391938 *m) {
    V391938 *v = m->pVars;

    if (v->unk24 != 0) {
        func_003A9440(78, (long)((D_001A1ED0.unk8 >> 13) | 0x1000000) | 0x100000000);
        func_0038AF30(0, D_001CFEC0.unk152, 0, D_001CFEC0.unk150, (v->unk24 << 24) | 0xFFFFFF);
        func_003A9440(78, 0x1000000 | (D_001A1ED0.unk8 >> 13));
    }
}
/* localdecomp:end func_L01_00392D80 */

/* localdecomp:start func_L01_00392E28 */
extern void func_L01_00393E90(s32 id);
extern void func_L01_00392D80(M391938 *m);


extern s32 func_L01_00457458(s32, s32);
extern void func_L01_00392A80(void);
extern void func_003C2880(u8 *);
extern s32 func_L01_00459590(V_003919E0 *, s32, f32);
extern void func_L01_00392F08(u8 *);
extern void func_L01_00393150(u8 *);
extern void func_L01_00393390(u8 *);
extern void func_L01_003937E8(u8 *);

void func_L01_00392E28(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    V_003919E0 t;
    if (a0 == 0) {
        return;
    }
    if (a0[32] == 254) {
        return;
    }
    if (a0[32] == 253) {
        return;
    }
    if (v == 0) {
        return;
    }
    if (func_L01_00457458(*(s16 *)(a0 + 170), *(s32 *)(v + 40)) == 0) {
        func_L01_00392A80();
        func_003C2880(a0);
        return;
    }
    t.q = *(s128 *)(a0 + 16);
    t.f[3] = 2.0f;
    if (func_L01_00459590(&t, 0, 100.0f) == -1) {
        return;
    }
    if (a0[32] != 6) {
        func_L01_00392F08(a0);
        func_L01_00393150(a0);
        ((void (*)(u8 *))func_L01_00392D80)(a0);
    }
    func_L01_00393390(a0);
    func_L01_003937E8(a0);
    ((void (*)(u8 *))func_L01_00393E90)(a0);
}
/* localdecomp:end func_L01_00392E28 */

INCLUDE_ASM("asm/levels", func_L01_00392F08);

INCLUDE_ASM("asm/levels", func_L01_00393150);

INCLUDE_ASM("asm/levels", func_L01_00393390);

INCLUDE_ASM("asm/levels", func_L01_003937E8);

INCLUDE_ASM("asm/levels", func_L01_00393C80);

/* localdecomp:start func_L01_00393DA8 */
extern u8 *D_L01_001E2018;
extern s32 func_0038CAD0(void *);
extern s32 func_0013D3E0(void);
extern void func_L01_00393EF8(void *, s32, f32, f32, s32);
extern void func_L01_00394390(void *);

void func_L01_00393DA8(s32 a0) {
    s32 i;
    for (i = 0; i < 1; i++) {
        u8 *e = (u8 *)(i * 80 + (s32)D_L01_001E2018);
        if (*(s32 *)(e + 48) == a0) {
            if (func_0038CAD0(e + 52) != 0) {
                if (*(s32 *)(e + 56) == 0) {
                    *(s32 *)(e + 48) = 0;
                }
            } else if (!(func_0013D3E0() & 1)) {
                func_L01_00393EF8(e, 0, 0.0f, 0.0f, 0);
                func_L01_00393EF8(e, 0, 0.0f, 0.0f, 0);
            }
            func_L01_00394390(e);
        }
    }
}
/* localdecomp:end func_L01_00393DA8 */

/* localdecomp:start func_L01_00393E90 */
extern void func_L01_003946B8(s32 id);
extern u8 *D_L01_001E2018;
void func_L01_00393E90(s32 id) {
    s32 i;
    for (i = 0; i < 1; i++) {
        if ((*(Ent_00312A80 * *)&D_L01_001E2018)[i].id == id) ((void (*)(Ent_00312A80 *))func_L01_003946B8)(&(*(Ent_00312A80 * *)&D_L01_001E2018)[i]);
    }
}
/* localdecomp:end func_L01_00393E90 */

INCLUDE_ASM("asm/levels", func_L01_00393EF8);

/* localdecomp:start func_L01_00394390 */
#include "vu0.h"
typedef struct {
    vu0_v4 pos, velocity;
    f32 f20,scale,spin_start,spin,spin_end,angle,length_start,length,length_end,size_start,size,size_end;
    s32 f50,timer,duration,count_start,count,color_start,color,color_end,f70,state,mode;
    u8 *owner;
} Particle_00394390;
extern S_393258 *D_L01_001E201C;
void func_L01_00394390(void *owner) {
    extern f32 func_L01_004451A0(f32);
    extern f32 func_L01_004451A8(f32);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern void func_003C5180(void *,void *,s32);
    extern f32 func_0038DAB8(f32,f32);
    extern s32 func_00382498(s32,s32);
    extern s32 func_0038CAD0(void *);
    vu0_v4 offset,normal,step;
    s32 i;

    qzero(&offset);
    for(i=0;i<300;i++) {
        Particle_00394390 *p=(Particle_00394390 *)((i<<7)+(s32)D_L01_001E201C);
        u8 *obj,*state;
        f32 t;
        s32 active;
        s32 one=1;
        if(p->owner!=owner) continue;
        t=1.0f-(f32)p->timer/(f32)p->duration;
        if(p->state==0) goto interpolate;
        else if(p->state==one) {
            p->count=(s32)((f32)p->count_start-(f32)p->count_start*func_L01_004451A0(t));
            if(p->mode==2) goto plain_scale;
interpolate:
            p->color=func_0038DBD8(p->color_start,p->color_end,t);
            p->spin=p->spin_start+(p->spin_end-p->spin_start)*t;
            p->length=p->length_start+(p->length_end-p->length_start)*t;
            p->size=p->size_start+(p->size_end-p->size_start)*t;
            { void *velocity=&p->velocity; f32 factor=func_L01_004451A8(t); func_0038CF68(&offset,velocity,p->scale*factor); }
            goto update;
plain_scale:
            func_0038CF68(&offset,&p->velocity,p->scale);
        }
update:
        func_003C5180(*(u8 **)((u8 *)owner+0x30)+0x10,&normal,1);
        active=1;
        func_0038CF68(&step,&normal,p->length);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(p->pos) : "m"(p->pos),"m"(step) : "vf1","vf2");
        if(p->mode!=1) {
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(p->pos) : "m"(offset),"m"(p->pos) : "vf1","vf2");
        }
        obj=*(u8 **)(p->owner+0x30);
        state=*(u8 **)(obj+0x68);
        p->angle=func_0038DAB8(p->angle,p->spin);
        if(obj[0x20]==2 && *(s32 *)(state+0x14)<32 && p->mode!=2) {
            s32 n;
            p->state=active;
            n=(func_00382498(30,45)*5+2)/6;
            p->size_start=p->size;
            p->color_start=p->color;
            p->length_start=p->length;
            p->count_start=p->count;
            p->spin_start=p->spin;
            p->timer=n; p->duration=n;
        }
        if(func_0038CAD0(&p->timer)) {
            if(p->state==0) {
                s32 n;
                p->state=one;
                if(p->mode==one) { p->duration=25;p->timer=25; }
                else { p->duration=46;p->timer=46; }
            } else if(p->count>0) {
                p->state=2;p->count--;
            } else {
                (*(s32 *)(p->owner+0x38))--;
                if(p->mode==0) goto dec0;
                if(p->mode==one) goto dec1;
                goto clear;
dec0:
                (*(s32 *)(p->owner+0x40))--;
                goto clear;
dec1:
                (*(s32 *)(p->owner+0x44))--;
clear:
                p->owner=0;
            }
        }
    }
}
/* localdecomp:end func_L01_00394390 */

/* localdecomp:start func_L01_003946B8 */

extern S_393258 *D_L01_001E201C;
extern void func_L01_00394828(S_393258 *a0, f32 f12, s32 a1, s32 a2, f32 f13, s32 a3, s32 t0, f32 f14);

void func_L01_003946B8(s32 id) {
    s32 i;
    S_393258 *p;
    for (i = 0; i < 300; i++) {
        if (D_L01_001E201C[i].w7C == id) {
            p = &D_L01_001E201C[i];
            func_L01_00394828(p, p->f48, p->w68, p->w60, p->f34, 46, p->w70, 0.25f);
        }
    }
}
/* localdecomp:end func_L01_003946B8 */

/* localdecomp:start func_L01_00394738 */
void func_L01_00394738(u8 *p)
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
/* localdecomp:end func_L01_00394738 */

/* localdecomp:start func_L01_003947C0 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_003947C0(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_003947C0 */

INCLUDE_ASM("asm/levels", func_L01_00394828);

/* localdecomp:start func_L01_003949E8 */
typedef struct { s128 direction; s128 origin; u8 pad20[0x10]; f32 random; s32 timer; s32 owner; f32 value; s32 kind; s32 zero44; s32 zero48; s32 effect; } Vars_003949E8;
typedef struct { u8 pad0[0x10]; s128 position; u8 state; u8 pad21[0xf]; u8 update; u8 pad31; u16 distance; u16 flags; u8 pad36[0x32]; Vars_003949E8 *vars; u8 pad6c[0x2c]; s32 zero98; } Moby_003949E8;
extern void *func_003C24B0(s32 class_id, s32 flags);
extern f32 func_00382538(void);
extern s32 func_L01_004C85C8(void *moby, void *a1, f32 a2, f32 a3, f32 a4);
extern void func_L01_004AA7E8(void *, s32);
Moby_003949E8 *func_L01_003949E8(s32 owner, s128 *position, s128 *direction, f32 value, s32 kind, s32 unused) {
    Moby_003949E8 *m = func_003C24B0(0x1890, 0x80);

    if (m) {
        Vars_003949E8 *v;

        m->state = 0;
        m->distance = 255;
        m->update = 255;
        v = m->vars;
        m->position = *position;
        v->direction = *direction;
        v->kind = kind;
        v->owner = owner;
        v->random = func_00382538();
        v->value = value;
        v->timer = 0;
        v->zero44 = 0;
        v->zero48 = 0;
        v->origin = *position;
        v->effect = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
        m->zero98 = 0;
        m->flags |= 0x41;
        m->flags &= 0xefff;
        func_L01_004AA7E8(m, 1);
    }
    return m;
}
/* localdecomp:end func_L01_003949E8 */

INCLUDE_ASM("asm/levels", func_L01_00394AF0);

/* localdecomp:start func_L01_00395020 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_395020;
typedef struct { u8 pad0[0xD4]; u8 *puff_tex; u8 pad1[0x184 - 0xD8]; u8 *rock_tex; } S_221098_395020;
extern f32 D_L01_001DE088;
__asm__(".extern D_L01_001DE088, 4");
extern f32 D_L01_001DE08C;
__asm__(".extern D_L01_001DE08C, 4");
extern S_221098_395020 D_L01_00221098_00395020;
extern s32 D_001D545C;
extern void func_L01_00443B88(V4_395020 *v, f32 a, f32 b);
extern f32 func_003824E0(f32 a, f32 b);
extern f32 func_L01_00443A18(f32 a, f32 b);
extern s32 func_00382468(s32 a);
extern u8 *func_L01_004713C8(void *pos, V4_395020 *vel, s32 life, s32 col, s32 d, s32 e, s32 f, f32 a, f32 b, s32 g, f32 c);

/* whip_wave_dark_puffs: four casts of black then violet puffs from the V5 shock wave */
void func_L01_00395020(void *pos) {
    V4_395020 vel;
    f32 up, size, scale;
    s32 i, d;
    u8 *p;

    for (i = 3; i >= 0; i--) {
        func_L01_00443B88(&vel, 0.0300000012f, 0.0800000057f);
        up = vel.z;
        up = fabs_asm(up);
        up += func_003824E0(1.0f, 3.0f) * 0.0200000014156f;
        vel.z = up;
        size = func_003824E0(D_L01_001DE088, D_L01_001DE08C);
        func_00382468(3);
        switch (D_001D545C) {
        case 0x29: func_00382468(3); break;
        case 0x2A: func_00382468(3); break;
        }
        scale = 1.25f;
        d = (s32)func_L01_00443A18(2.0f, 3.0f);
        p = func_L01_004713C8(pos, &vel, 0x32, 0, d, 0x7F, 0x7F,
                              func_003824E0(0.800000011921f, scale) * 210000.0f * size, size * 2100.0f, 6, 0.00624000048f);
        if (p != 0) {
            p[3] = 0x44;
            p[2] = D_L01_00221098_00395020.puff_tex[0];
        }
        d = (s32)func_L01_00443A18(2.0f, 3.0f);
        p = func_L01_004713C8(pos, &vel, 0x32, 0x7C0030, d, 0x30, 0x30,
                              func_003824E0(0.800000011921f, scale) * 210000.0f * scale * size, size * 4200.0f, 0, 0.00624000048f);
        if (p != 0) {
            p[3] = 0x44;
            p[2] = D_L01_00221098_00395020.puff_tex[0];
        }
    }
}
/* localdecomp:end func_L01_00395020 */

/* localdecomp:start func_L01_00395288 */
extern S_221098_395020 D_L01_00221098_00395288;
extern s32 D_L01_001DE090;
__asm__(".extern D_L01_001DE090, 4");
extern f32 D_L01_001DE094;
__asm__(".extern D_L01_001DE094, 4");
extern f32 D_L01_001DE098;
__asm__(".extern D_L01_001DE098, 4");
extern f32 D_L01_001DE09C;
__asm__(".extern D_L01_001DE09C, 4");
extern s32 func_00382498(s32 a, s32 b);

/* whip_wave_rocks: two 0x61 rocks thrown up where the whip's V4 shock wave casts onto some ground materials */
void func_L01_00395288(void *pos, s32 high) {
    V4_395020 vel;
    f32 size;
    s32 i, col_a, col_b, pick;
    u8 *p;

    for (i = 0; i < D_L01_001DE090; i++) {
        if (high == 0) {
            func_L01_00443B88(&vel, 0.0200000014156f, D_L01_001DE094 * 0.0200000014156f);
            vel.z = fabs_asm(vel.z) + func_003824E0(D_L01_001DE098, D_L01_001DE09C) * 0.0200000014156f;
        } else {
            func_L01_00443B88(&vel, 0.0200000014156f, 0.0500000044703f);
            vel.z = fabs_asm(vel.z) + func_003824E0(7.0f, 10.5f) * 0.0200000014156f;
        }
        size = func_003824E0(0.0599999986589f, 0.219999998808f);
        func_00382468(3);
        if (D_001D545C == 0x29) {
            pick = func_00382468(3);
            col_a = 0x5A523E; col_b = 0x605129;
        } else {
            pick = func_00382468(3);
            col_a = 0x273538; col_b = 0x263438;
        }
        if (pick != 0) col_a = col_b;
        p = func_L01_004713C8(pos, &vel, (func_00382498(90, 150) * 5 + 2) / 6, col_a, -2, 0x7F, 0x7F, size * 210000.0f, size * 210000.0f, 0, 0.00624000048f);
        if (p != 0) {
            u8 tex = D_L01_00221098_00395288.rock_tex[func_00382468(3) + 10];
            p[3] = 0x44;
            p[2] = tex;
        }
    }
}
/* localdecomp:end func_L01_00395288 */

LINKER_REMNANT("asm/levels", func_L01_00395480);

/* localdecomp:start func_L01_00395498 */
s32 func_L01_00395498(s32 n) {
    s32 a = 16;
    if (n % a != 0) {
        n = ((s32)((f32)n / (f32)a) + 1) * a;
    }
    return n;
}
/* localdecomp:end func_L01_00395498 */

INCLUDE_ASM("asm/levels", func_L01_003954E0);

/* localdecomp:start func_L01_003968E8 */
void func_L01_003968E8(u8 *a) {
    a[0x20] = 5;
}
/* localdecomp:end func_L01_003968E8 */

/* localdecomp:start func_L01_003968F8 */
typedef int u128_t_396 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3968F8;
typedef struct {
    u8 pad0[0x10];
    u128_t_396 pos;                /* 0x10 */
    s8 state;                      /* 0x20 */
    u8 pad21[2];
    u8 opacity;                    /* 0x23 */
    u8 pad24[8];
    f32 scale;                     /* 0x2C */
    u8 x30;
    u8 pad31;
    s16 draw_dist;                 /* 0x32 */
    u16 flags;                     /* 0x34 */
    u8 pad36[0x68 - 0x36];
    u8 *pvar;                      /* 0x68 */
    u8 pad6c[0x78 - 0x6c];
    u32 colour;                    /* 0x78 */
} M_3968F8;
typedef struct { u8 pad0[0xBD8]; void *lock_target; } H_3968F8;
extern s32 D_L01_001DE0B0;
__asm__(".extern D_L01_001DE0B0, 4");
extern f32 D_L01_001DE0B4;
__asm__(".extern D_L01_001DE0B4, 4");
extern f32 D_L01_001DE0B8;
__asm__(".extern D_L01_001DE0B8, 4");
extern s32 D_L01_001E2030;
__asm__(".extern D_L01_001E2030, 4");
extern s32 D_L01_001E2034;
__asm__(".extern D_L01_001E2034, 4");
extern s32 D_L01_001E2038;
__asm__(".extern D_L01_001E2038, 4");
extern H_3968F8 D_001A4BE0_003968F8;
extern void *func_003C24B0(s32 class_id, s32 flags);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32 a, f32 b);
extern f32 func_0038CEA8(V4_3968F8 *v);
extern void func_L01_00457588(void *target, void *from, f32 s, V4_3968F8 *v);
extern void func_0038CF68(void *dst, void *src, f32 s);
extern s32 func_L01_00395498(s32 n);
extern s32 func_L01_004C85C8(void *moby, void *a1, f32 a2, f32 a3, f32 a4);

/* from rac2-decomp's func_L00_003DBF50 */
/* agent_comet_spawn: the agents' comet (class 0x1893), scale 0.025 */
M_3968F8 *func_L01_003968F8(M_3968F8 *owner, s32 a1, u128_t_396 *pos, V4_3968F8 *dir, s32 a4, s32 a5) {
    M_3968F8 *m;
    u8 *pv;
    V4_3968F8 v;
    f32 len;
    s32 s, a, b;

    m = (M_3968F8 *)func_003C24B0(0x1893, 0x80);
    if (m != 0) {
        m->state = 0;
        pv = m->pvar;
        m->x30 = 0xFF;
        m->draw_dist = 0xFF;
        *(f32 *)(pv + 0x54) = func_00382538();
        *(f32 *)(pv + 0x58) = func_003824E0(0.446804314852f, 0.753982305527f);
        *(s32 *)(pv + 0x64) = *(s16 *)((u8 *)owner + 0xAA);
        *(s32 *)(pv + 0x6C) = 0;
        *(s32 *)(pv + 0x74) = a5;
        *(u128_t_396 *)((u8 *)m + 0x10) = *pos;
        m->opacity = 0x50;
        m->flags |= 0x100;
        m->scale = 0.0250000003725f;
        m->colour = 0x7F4080FF;
        *(s32 *)(pv + 0x70) = a4;
        *(s32 *)(pv + 0x60) = a1;
        {
            u8 *ps = owner->pvar;

            if (D_L01_001DE0B0 == 0) {
                s = *(s32 *)(ps + 8);
                D_L01_001E2030 = s;
                a = func_L01_00395498(s + 0x100);
                D_L01_001E2034 = a;
                b = func_L01_00395498(a + 0x4B00);
                D_L01_001E2038 = b;
                func_L01_00395498(b + 0xA0);
                D_L01_001DE0B0 = 1;
            }
        }
        if (D_001A4BE0_003968F8.lock_target != 0) {
            len = func_0038CEA8(dir);
            if (len == 0.0f) len = 1.0f;
            func_L01_00457588(D_001A4BE0_003968F8.lock_target, pos, len, dir);
            *(u128_t_396 *)pv = *(u128_t_396 *)dir;
        } else {
            *(u128_t_396 *)pv = *(u128_t_396 *)dir;
        }
        v = *dir;
        v.x += func_003824E0(-0.150000005960f, 0.150000005960f);
        v.y += func_003824E0(-0.150000005960f, 0.150000005960f);
        func_0038CF68(&v, &v, func_003824E0(D_L01_001DE0B8 * 0.0200000014156f, D_L01_001DE0B4 * 0.0200000014156f) * 0.5f);
        *(s32 *)(pv + 0x5C) = 0x60;
        *(s32 *)(pv + 0x50) = 0x237;
        *(s32 *)(pv + 0x68) = ((s32 (*)(void *, f32, f32, f32, s32))func_L01_004C85C8)(m, 1.0f, 1.0f, 1.0f, 0);
    }
    return m;
}
/* localdecomp:end func_L01_003968F8 */

LINKER_REMNANT("asm/levels", func_L01_00396B68);

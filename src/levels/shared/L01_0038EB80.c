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

/* localdecomp:start func_L01_0038F728 */
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


typedef struct {
    vu0_q start, end, velocity;
    u8 *hit;
    s32 *options;
    s32 mode;
    f32 radius, factor0, factor1;
    s32 flags, unknown;
    u8 pad50[8];
    s32 field58;
    u8 pad5C[4];
} Move_0038F728;
extern s32 D_L01_001D673C;
__asm__(".extern D_L01_001D673C, 16");
extern u8 *D_001A71A0[];
extern vu0_q D_L01_001EAA20[];
extern u8 D_L01_001D66B0[8];
__asm__(".extern D_L01_001DDFE0_sda, 4");
__asm__(".extern D_L01_001DDFE4_sda, 4");
extern f32 D_L01_001DDFE0_sda __attribute__((section(".sdata")));
extern f32 D_L01_001DDFE4_sda __attribute__((section(".sdata")));
void func_L01_0038F728(u8 *obj) {
    extern void func_L01_004471A8(void *, f32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_0038FCB8(u8 *);
    extern s32 func_00382468(s32);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_L01_003900F8(vu0_v4 *);
    extern void func_003C5180(void *, void *, s32);
    extern void func_L01_004CAC40(void *, void *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004C7D40(void *, void *, f32);
    extern s32 func_L01_004C7E70(Move_0038F728 *, s32);
    extern u8 *func_00382348(void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern u8 *func_L01_0046B288(void *, u32, u32, f32, f32, s32);
    extern Moby_390A40 *func_L01_00390A40(u128_390A40 *, u128_390A40 *);
    extern void func_L01_004C8668(s32);
    extern void func_003C2880(u8 *);
    extern f32 func_0038DAB8(f32, f32);
    vu0_v4 old;
    s32 options[2];
    vu0_v4 direction;
    Move_0038F728 move;
    vu0_v4 point, normal, offset;
    u8 *vars = *(u8 **)(obj + 0x68);
    func_L01_004471A8(obj, 1.0f);
    if (func_L01_004CB2D8()) func_L01_004CAB30(obj + 0x10, obj + 0x10);
    switch (obj[0x20]) {
    case 0:
        obj[0x20] = 1;
    case 1:
        func_L01_0038FCB8(obj);
        if (!D_L01_001D673C && !func_L01_004CB2D8() && func_00382468(2)) {
            func_L01_004C7D98(obj + 0x10, &direction);
            func_0038CF68(&direction, &direction, -5.0f);
            vec_add_ba(&direction, (obj + 0x10), &direction);
            if (func_003D3CB0(obj + 0x10, &direction, 0, D_001A71A0[0], 0)) func_L01_003900F8((vu0_v4 *)D_L01_001EAA20);
        }
        old = *(vu0_v4 *)(obj + 0x10);
        func_003C5180(&old, &direction, 1);
        vec_add_ab((obj + 0x10), (obj + 0x10), vars);
        func_L01_004CAB30(obj + 0x10, obj + 0x10);
        func_L01_004CAC40(vars, vars);
        func_L01_004C8688(*(s32 *)(vars + 0x34), vars, 0);
        func_L01_004C7D40(obj + 0x10, vars, 0.0048f);
        options[0] = 0;
        options[1] = 0xCE3;
        move.start = *(vu0_q *)&old;
        move.end = *(vu0_q *)(obj + 0x10);
        move.velocity = *(vu0_q *)vars;
        move.hit = obj;
        move.options = options;
        move.mode = 2;
        move.radius = 0.25f;
        move.factor0 = D_L01_001DDFE0_sda;
        move.factor1 = D_L01_001DDFE4_sda;
        move.flags = 0;
        move.unknown = 0;
        move.field58 = 0;
        if (func_L01_004C7E70(&move, -1) == 2) obj[0x20] = 2;
        *(vu0_q *)(obj + 0x10) = move.end;
        *(vu0_q *)vars = move.velocity;
        *(vu0_q *)(vars + 0x20) = move.start;
        if (move.hit && ((*(u8 **)(move.hit + 0x24))[0x46] == 5 ||
            (*(u8 **)(move.hit + 0x24))[0x46] == 9 || (*(u16 *)(move.hit + 0x34) & 0x4000))) {
            u8 *info = func_00382348(move.hit);
            func_L01_004C7D98(move.hit + 0x10, &normal);
            *(vu0_q *)&point = *(vu0_q *)(obj + 0x10);
            if (info) {
                func_0038CE20((f32 *)&offset, (f32 *)&normal, *(f32 *)(info + 0x10));
                vec_add_ab(&point, &point, &offset);
            }
            func_0038CE20((f32 *)&normal, (f32 *)&normal, -3.0f);
            obj[0x20] = 2;
            vec_add_ab(&normal, &normal, &point);
            *(vu0_q *)(obj + 0x10) = D_L01_001EAA20[0];
            *(vu0_q *)(vars + 0x20) = D_L01_001EAA20[2];
            func_0038CF68(vars + 0x20, vars + 0x20, 1.0f);
            if (func_003D3CB0(&point, &normal, 6, move.hit, 0)) {
                *(vu0_q *)(obj + 0x10) = D_L01_001EAA20[0];
                *(vu0_q *)(vars + 0x20) = D_L01_001EAA20[2];
                func_0038CF68(vars + 0x20, vars + 0x20, 1.0f);
            }
        }
        break;
    case 2:
        func_003A52A0(0, 0, obj);
        if (!D_L01_001D673C && !func_L01_004CB2D8()) {
            s32 i;
            for (i = 0; i < 1; i++) {
                f32 angle = func_00382538();
                f32 radius = func_003824E0(0, 0.6f);
                f32 size = func_003824E0(0, 1.5f);
                f32 lifetime = func_003824E0(1.5f, 5.5f);
                s32 alpha = func_00382498(100, 160);
                direction.x = func_0038D098(angle) * radius;
                direction.y = func_0038D0B0(angle) * radius;
                direction.z = 0;
                vec_add_ba(&direction, &direction, (obj + 0x10));
                func_L01_0046B288(&direction, 0x30305020, 0x182810, size, lifetime, alpha);
                }
        }
        {
            Moby_390A40 *burst = func_L01_00390A40((u128_390A40 *)(obj + 0x10), (u128_390A40 *)D_L01_001D66B0);
            *(s32 *)((u8 *)burst + 0xB8) = *(s32 *)(vars + 0x30);
        }
        func_L01_004C8668(*(s32 *)(vars + 0x34));
        func_003C2880(obj);
        return;
    }
    *(f32 *)(obj + 0xF0) = func_0038DAB8(*(f32 *)(obj + 0xF0), *(f32 *)(vars + 0x10));
    *(f32 *)(obj + 0xF4) = func_0038DAB8(*(f32 *)(obj + 0xF4), *(f32 *)(vars + 0x14));
    func_L01_004471A8(obj, 0.2f);
    if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f ||
        *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f ||
        *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) {
        func_L01_004C8668(*(s32 *)(vars + 0x34));
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_0038F728 */

/* localdecomp:start func_L01_0038FCA8 */
void func_L01_0038FCA8(u8 *a) {
    a[32] = 2;
}
/* localdecomp:end func_L01_0038FCA8 */

/* localdecomp:start func_L01_0038FCB8 */
extern u8 *D_L01_00221098[];
void func_L01_0038FCB8(u8 *obj) {
    extern void func_00382580(void *, f32, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00466F50(void *, void *, u32, f32, f32);
    vu0_v4 position, velocity, offset, normal;
    s32 i, j, k;
    u8 *particle;
    for (i = 0; i < 1; i++) {
        func_00382580(&velocity, 0.035f, 0.05f);
        func_0038CE20(&offset.x, &velocity.x, 10.0f);
        vec_add_ab(&position, &offset, obj + 0x10);
        particle = func_L01_004713C8(&position, &velocity, (func_00382498(10, 30) * 5 + 2) / 6, 0x5A182,
                     func_00382498(-1, -3), 0x20, 0, 0, 94500.0f, 199500.0f, 0.0096f);
        if (particle) {
            particle[3] = func_00382468(2) ? 0x48 : 0x44;
            particle[2] = *D_L01_00221098[0x5C / 4];
        }
    }
    for (j = 0; j < 1; j++) {
        func_00382580(&velocity, 0.01f, 0.04f);
        func_0038CE20(&offset.x, &velocity.x, 10.0f);
        vec_add_ab(&position, &offset, obj + 0x10);
        particle = func_L01_004713C8(&position, &velocity, (func_00382498(10, 30) * 5 + 2) / 6, 0x5A182,
                     func_00382498(-1, -3), 0x20, 0, 0, 73500.0f, 52500.0f, 0.0096f);
        if (particle) {
            particle[3] = func_00382468(2) ? 0x48 : 0x44;
            particle[2] = *D_L01_00221098[0x1A4 / 4];
        }
    }
    for (k = 0; k < 1; k++) {
        func_00382580(&velocity, 0.01f, 0.03f);
        func_0038CE20(&offset.x, &velocity.x, 10.0f);
        vec_add_ab(&position, &offset, obj + 0x10);
        particle = func_L01_004713C8(&position, &velocity, (func_00382498(10, 30) * 5 + 2) / 6, 0x5A182,
                     func_00382498(-1, -3), 0x20, 0, 0, 73500.0f, 31500.001953125f, 0.0096f);
        if (particle) {
            particle[3] = func_00382468(2) ? 0x48 : 0x44;
            particle[2] = *D_L01_00221098[0x88 / 4];
        }
    }
    if (func_00382468(3) == 0) {
        func_00382580(&velocity, 0.01f, 0.03f);
        func_0038CE20(&offset.x, &velocity.x, 20.0f);
        vec_add_ab(&position, &offset, obj + 0x10);
        func_L01_004C7D98(obj + 0x10, &normal);
        func_0038CF68(&normal, &normal, -func_003824E0(0.01f, 0.05f));
        func_L01_00466F50(&position, &normal, 0x4005A182, -1.0f, -0.004f);
    }
}
/* localdecomp:end func_L01_0038FCB8 */

/* localdecomp:start func_L01_003900F8 */
#include "vu0.h"
void func_L01_003900F8(vu0_v4 *origin) {
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32 low, f32 high);
    extern s32 func_00382498(s32, s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32 angle);
    extern u8 *func_L01_0046B288(void *, u32, u32, f32, f32, s32);
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
        particle = func_L01_0046B288(&position, 0x5005C162, 0x0005C162, a, b, life);
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

/* localdecomp:start func_L01_00390AB8 */
typedef struct { f32 f[4]; } __attribute__((aligned(16))) Vec_00390AB8;
typedef struct { f32 pos[4]; u8 pad10[0x10]; f32 strength; s32 pad24; s32 time; s32 mode; } Effect_00390AB8;
extern Effect_00390AB8 D_L01_001E2A40;
extern u8 *D_L01_00221098[];
extern s32 D_L01_001D673C;
__asm__(".extern D_L01_001D673C, 16");
void func_L01_00390AB8(u8 *obj, f32 *dir1, f32 *dir2) {
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038CEA8(void *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern s32 func_00382468(s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void *func_L01_0040E6B8(void *, void *, f32);
    extern void *func_L01_003E0058(void *, void *, s32);
    extern u8 *func_L01_0039D818(void *, void *, void *);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern u8 *func_L01_0046B288(void *, u32, u32, f32, f32, s32);
    extern s32 func_L01_004CB2D8(void);
    Vec_00390AB8 d, e, c, b, ppos, pvel;
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 two = 2.0f;
    f32 dist, yaw;
    s32 m, i, j, k;
    func_0038CE20(dir1, dir1, two);
    vec_sub_ab(&d, &D_L01_001E2A40, obj + 0x10);
    dist = func_0038CEA8(&d);
    obj[0x20] = 0;
    /* five random shots, each flattened against dir2 (remove its component, add a random
     * multiple of it) and sent out from the object */
    for (k = 0; k < 5; k++) {
        f32 dot, k, sc;
        *(vu0_q *)&b = 0;
        b.f[0] = func_003824E0(-1.0f, 1.0f);
        b.f[1] = func_003824E0(-1.0f, 1.0f);
        c = b;
        dot = func_0038CE68(&c, dir2);
        func_0038CF68(&e, dir2, dot);
        vec_sub_ab(&c, &c, &e);
        k = func_003824E0(1.0f, 2.0f);
        func_0038CF68(&e, dir2, k);
        vec_add_ab(&c, &c, &e);
        sc = two * func_003824E0(3.5f, 5.0f);
        func_0038CF68(&c, &c, sc * 0.020000001f);
        vec_add_ab(&c, &c, dir1);
        b = *(Vec_00390AB8 *)(obj + 0x10);
        b.f[2] = b.f[2] + 0.5f;
        func_L01_003E0058(&b, &c, 0);
    }
    /* one big shot toward D_L01_001E2A40 */
    *(vu0_q *)&b = 0;
    b.f[0] = func_003824E0(-1.0f, 1.0f);
    b.f[1] = func_003824E0(-1.0f, 1.0f);
    b.f[2] = func_003824E0(-1.0f, 1.0f);
    d.f[2] = d.f[2] + dist * 0.5f;
    c = b;
    func_0038CF68(&c, &c, (dist / 5.0f) * 0.020000001f);
    func_0038CF68(&d, &d, (dist + dist) * 0.020000001f);
    vec_add_ab(&c, &c, &d);
    func_L01_0040E6B8(&c, &c, 0.20000001788139343f);
    b = *(Vec_00390AB8 *)(obj + 0x10);
    b.f[2] = b.f[2] + 0.5f;
    func_L01_0039D818(obj, &b, &c);
    *(s32 *)vars = 0;
    obj[0xBC] = 0;
    D_L01_001E2A40.strength = dist < 20.0f ? 0.4f - dist * 0.017500000074505806f : 0.050000011920928955f;
    D_L01_001E2A40.mode = 0;
    D_L01_001E2A40.time = 21;
    yaw = func_0038D160(D_L01_001E2A40.pos[0] - *(f32 *)(obj + 0x10), D_L01_001E2A40.pos[1] - *(f32 *)(obj + 0x14));
    /* two sprays of 20 particles around the yaw (second with the third asset byte) */
    for (m = 0; m < 20; m++) {
        u8 *p;
        s32 kind = (s32)func_L01_00443A18(2.0f, 5.0f);
        f32 size, speed, ang, h, vz;
        ppos.f[0] = *(f32 *)(obj + 0x10) + func_L01_00443A18(0.0f, 0.1f);
        ppos.f[1] = *(f32 *)(obj + 0x14) + func_L01_00443A18(0.0f, 0.1f);
        ppos.f[2] = *(f32 *)(obj + 0x18) + func_L01_00443A18(0.0f, 0.1f);
        size = func_003824E0(0.7f, 1.4f);
        speed = func_003824E0(7.0f, 10.0f);
        ang = func_0038DAB8(yaw, func_L01_00443A18(0.0f, 1.3962634f));
        speed = speed * 0.020000001f;
        pvel.f[0] = func_0038D098(ang) * speed;
        pvel.f[1] = func_0038D0B0(ang) * speed;
        pvel.f[2] = 0.0f;
        h = func_003824E0(0.0f, 12.0f);
        vz = h * 0.020000001f;
        pvel.f[2] = vz;
        p = func_L01_004713C8(&ppos, &pvel, (func_00382498(30, 50) * 5 + 2) / 6, 0x6C182, kind, 0x30, 0x30, 0,
                size * 210000.0f, (size * 0.1f) * 210000.0f, 0.006400000303983688f);
        if (p != 0) p[2] = *D_L01_00221098[0x1A4 / 4];
    }
    for (j = 0; j < 20; j++) {
        u8 *p;
        s32 kind = (s32)func_L01_00443A18(2.0f, 5.0f);
        f32 size, speed, ang, h, vz;
        ppos.f[0] = *(f32 *)(obj + 0x10) + func_L01_00443A18(0.0f, 0.1f);
        ppos.f[1] = *(f32 *)(obj + 0x14) + func_L01_00443A18(0.0f, 0.1f);
        ppos.f[2] = *(f32 *)(obj + 0x18) + func_L01_00443A18(0.0f, 0.1f);
        size = func_003824E0(0.7f, 1.4f);
        speed = func_003824E0(7.0f, 10.0f);
        ang = func_0038DAB8(yaw, func_L01_00443A18(0.0f, 1.3962634f));
        speed = speed * 0.020000001f;
        pvel.f[0] = func_0038D098(ang) * speed;
        pvel.f[1] = func_0038D0B0(ang) * speed;
        pvel.f[2] = 0.0f;
        h = func_003824E0(0.0f, 12.0f);
        vz = h * 0.020000001f;
        pvel.f[2] = vz;
        p = func_L01_004713C8(&ppos, &pvel, (func_00382498(30, 50) * 5 + 2) / 6, 0x6C182, kind, 0x30, 0x30, 0,
                size * 210000.0f, (size * 0.05f) * 210000.0f, 0.006400000303983688f);
        if (p != 0) p[2] = *D_L01_00221098[0x88 / 4];
    }
    if (D_L01_001D673C == 0 && func_L01_004CB2D8() == 0) {
        for (i = 0; i < 5; i++) {
            u8 *p;
            f32 angle = func_00382538();
            f32 radius = func_003824E0(0.5f, 2.75f);
            f32 size = func_003824E0(0.0f, 1.5f);
            f32 life = func_003824E0(3.0f, 5.0f);
            s32 alpha = func_00382498(100, 160);
            ppos.f[0] = func_0038D098(angle) * radius;
            ppos.f[1] = func_0038D0B0(angle) * radius;
            ppos.f[2] = 0.0f;
            vec_add_ab(&ppos, &ppos, obj + 0x10);
            p = func_L01_0046B288(&ppos, 0x5005D152, 0x5D152, size, life, alpha);
            if (p != 0) p[3] = func_00382468(3) ? 0x48 : 0x44;
        }
    }
}
/* localdecomp:end func_L01_00390AB8 */

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

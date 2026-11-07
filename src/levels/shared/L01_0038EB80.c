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

INCLUDE_ASM("asm/levels", func_L01_0038F3F8);

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

INCLUDE_ASM("asm/levels", func_L01_003912E0);

INCLUDE_ASM("asm/levels", func_L01_00391610);

/* localdecomp:start func_L01_003916E0 */
extern s32 D_L01_001DDFE8;

void func_L01_003916E0(void) { D_L01_001DDFE8 = 0; }
/* localdecomp:end func_L01_003916E0 */

INCLUDE_ASM("asm/levels", func_L01_003916E8);

INCLUDE_ASM("asm/levels", func_L01_00391938);

INCLUDE_ASM("asm/levels", func_L01_00391A80);

INCLUDE_ASM("asm/levels", func_L01_00391BD0);

INCLUDE_ASM("asm/levels", func_L01_00391D88);

INCLUDE_ASM("asm/levels", func_L01_00391EC8);

INCLUDE_ASM("asm/levels", func_L01_00391F98);

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

INCLUDE_ASM("asm/levels", func_L01_00392908);

/* localdecomp:start func_L01_00392A78 */
extern s32 D_L01_001DE000;

void func_L01_00392A78(void) { D_L01_001DE000 = 0; }
/* localdecomp:end func_L01_00392A78 */

INCLUDE_ASM("asm/levels", func_L01_00392A80);

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

INCLUDE_ASM("asm/levels", func_L01_00394390);

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

INCLUDE_ASM("asm/levels", func_L01_003949E8);

INCLUDE_ASM("asm/levels", func_L01_00394AF0);

INCLUDE_ASM("asm/levels", func_L01_00395020);

INCLUDE_ASM("asm/levels", func_L01_00395288);

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

INCLUDE_ASM("asm/levels", func_L01_003968F8);

LINKER_REMNANT("asm/levels", func_L01_00396B68);

/* Draft (206 differing words; open-rac-engine: holo_drain_update). Both loops' logic, the calls
 * and their arguments follow retail. Two things differ:
 * - retail splits the hero's address (its `lui` hoisted into $s5, `addiu %lo` at each use), which
 *   src/levels/shared/L01_0037ADE0.c's -mno-split-addresses forbids. The flag can go: with it
 *   removed and D_L01_001E10D0 declared `__attribute__((section(".sdata")))` in the two blocks
 *   that use it, all four C blocks of the file still match (verify_all at L01 and L19);
 * - in the first loop retail keeps `vars + i*0xB0` as the induction pointer (owner/target at
 *   +0x130/+0x134, ended by `< vars + 0x840`) next to `&links[i]`; gcc reverses the loop and adds
 *   an i*0xB0 offset to vars at each use. A `link` local instead keeps a `mult` in the loop.
 * D_L01_001D6694 is read once through $gp (a delay slot, so Ps2EeAs cannot expand it) and once
 * through `lui`: a small scalar with no size hint gives both. */
typedef struct {
    u8 pad0[0x20];
    u8 pos[0x80];        /* 0x20 */
    u8 *owner;           /* 0xA0: the shield */
    u8 *target;          /* 0xA4: the moby linked */
    u8 padA8[0xB0 - 0xA8];
} Link_0037CEC8;
typedef struct {
    u8 pad0[0x20];
    s32 heal_timer;      /* 0x20: 45 frames between points of health */
    u8 pad24[0x26 - 0x24];
    s16 hits;            /* 0x26: hits left */
    u8 pad28[0x54 - 0x28];
    s32 heal;            /* 0x54: health a point gives */
    u8 pad58[0x64 - 0x58];
    s32 drain_timer;     /* 0x64: 180 frames between drains */
    u8 pad68[0x90 - 0x68];
    Link_0037CEC8 links[12]; /* 0x90 */
} HoloVars_0037CEC8;
typedef struct {
    u8 pad0[0x20];
    u8 state;            /* 0x20 */
    u8 pad21[0x24 - 0x21];
    u8 *pclass;          /* 0x24 */
    u8 pad28[0x34 - 0x28];
    u16 flags;           /* 0x34 */
    u8 pad36[0x68 - 0x36];
    HoloVars_0037CEC8 *vars; /* 0x68 */
    u8 pad6C[0xAA - 0x6C];
    s16 oclass;          /* 0xAA */
} Moby_0037CEC8;
typedef struct {
    u8 pad0[0x80];
    u8 pos[0x60];        /* 0x80 */
    u8 pickup_point[0x10]; /* 0xE0 */
    u8 padF0[0x25C0 - 0xF0];
    Moby_0037CEC8 *moby; /* 0x25C0 */
    u8 pad25C4[0x2850 - 0x25C4];
    s32 health;          /* 0x2850 */
} Hero_0037CEC8;
typedef struct {
    u8 pad0[0x18];
    u8 x18;
    u8 x19;
    s16 oclass;          /* 0x1A */
    u8 pad1C[0x40 - 0x1C];
} Damage_0037CEC8;

typedef struct { s32 w[0x2900 / 4]; } HeroW_0037CEC8;
extern HeroW_0037CEC8 D_001A4BE0;
extern s32 D_L01_001D6694;
extern s32 D_00142660[];
extern f32 *func_00382348(Moby_0037CEC8 *);
extern s32 func_0038CAD0(s32 *);
extern void func_L01_00446748(Damage_0037CEC8 *, Moby_0037CEC8 *, s32, f32);
extern void func_L01_00446978(Moby_0037CEC8 *, Damage_0037CEC8 *);
extern void func_L01_0037D210(Moby_0037CEC8 *, Link_0037CEC8 *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_00382468(s32);
extern void func_00382580(void *, f32, f32);
extern void func_L01_0046C470(void *, void *, u32, s32, u8, s32, s32, s32, f32);
extern void func_003E4D10(s32);

/* holo_drain_update: the Holo Shield's drain: 1 damage to a linked enemy when a 180-frame timer
   runs out, and a point of health to the hero within 5 u every 45 frames */
void func_L01_0037CEC8(Moby_0037CEC8 *shield)
{
    Damage_0037CEC8 damage;
    HoloVars_0037CEC8 *vars = shield->vars;
    Link_0037CEC8 *link;
    Moby_0037CEC8 *target;
    f32 *health;
    s32 enemy = 0;
    s32 i;
    s32 max;
    s32 hp;
    s32 n;

    for (i = 0; i < 12; i++) {
        if (vars->links[i].owner != (u8 *)shield) {
            continue;
        }
        target = (Moby_0037CEC8 *)vars->links[i].target;
        if (target == 0) {
            continue;
        }
        health = func_00382348(target);
        if (health == 0 || target == (Moby_0037CEC8 *)D_001A4BE0.w[0x25C0 / 4] || target == 0 || target->pclass == 0
            || target->pclass[0x46] != 5 || target->state == 0xFE || target->state == 0xFD
            || !(*health > 0.0f) || (target->flags & 2) || target->oclass == 0x1AE6
            || target->oclass == 0x1A17 || target->oclass == 0x1B27) {
            continue;
        }
        enemy = 1;
        if (D_L01_001D6694 == 0 && func_0038CAD0(&vars->drain_timer)) {
            func_L01_00446748(&damage, shield, 0x10000, 1.0f);
            damage.x18 = 0;
            damage.oclass = shield->oclass;
            damage.x19 = enemy;
            func_L01_00446978(target, &damage);
            vars->drain_timer = 150;
        }
        func_L01_0037D210(shield, &vars->links[i]);
    }
    for (i = 0; i < 12; i++) {
        link = &vars->links[i];
        if ((Moby_0037CEC8 *)link->target != (Moby_0037CEC8 *)D_001A4BE0.w[0x25C0 / 4] || !enemy) {
            continue;
        }
        if (!(func_L01_0040E548(&D_001A4BE0.w[0x80 / 4], link->pos) < 25.0f)) {
            continue;
        }
        if (func_00382468(2) == 0) {
            func_00382580(&damage, 0.02f, 0.04f);
            func_L01_0046C470(&D_001A4BE0.w[0xE0 / 4], &damage, 0x50804040, 0x3C, func_00382468(0xFF), 1, 0x40, 0, 0.4f);
            func_L01_0046C470(&D_001A4BE0.w[0xE0 / 4], &damage, 0x407F7F7F, 0x3C, func_00382468(0xFF), 1, 0x40, 0, 0.2f);
        }
        max = D_00142660[2];
        if (D_L01_001D6694 == 0 && func_0038CAD0(&vars->heal_timer) && (hp = D_001A4BE0.w[0x2850 / 4]) != 0) {
            n = hp + vars->heal;
            if (max < n) {
                n = max;
            }
            D_001A4BE0.w[0x2850 / 4] = n;
            if (hp != n) {
                vars->heal_timer = 37;
                vars->hits -= vars->heal;
                if (vars->hits < 0) {
                    vars->hits = 0;
                }
                func_003E4D10(300);
            }
        }
        func_L01_0037D210(shield, link);
        break;
    }
}

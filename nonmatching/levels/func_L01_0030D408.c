/* Near miss for func_L01_0030D408 (open-rac-engine names it coil_ball_spawn), file
   src/levels/shared/L01_003068B8.c; uses that file's context (s128_00309B80, S_0030CD20 and
   the earlier blocks' externs): tools/check.py nonmatching/levels/func_L01_0030D408.c
   func_L01_0030D408. 5 words differ, all at the once-only init test: retail keeps the
   gun-class store (sw $v0, 0x40($s1)) before bnez and fills its delay slot with the
   fall-through's load of the gun's vars (lw $v0, 0x68($s6)); here reorg moves the store
   into the delay slot and the load follows into $v1. Loading the gun's vars before the
   test gives the delay slot but $a0 and another store order (best of 12 placements: 5);
   an int-typed load and reading the flag first: no change. What did match: the temp start
   in an f32[4] (a stack slot, no sq save), a pointer to the ball's position (its $s4), the
   arc slots as a 0xA0-byte struct (its pointer loop), no argument to func_L01_0030D678
   (the gun's 3 refs give velocity $s5), and func_L01_004CAC78 called pointers first. */
typedef struct {
    f32 velocity[4];
    s32 life;       /* 0x10: frames */
    s32 slot;       /* 0x14: its place among the 5 */
    f32 radius;     /* 0x18 */
    s32 x1C;
    u8 pad20[0x10];
    s32 sound;      /* 0x30 */
    s32 x34;
    s32 x38;
    s32 level;      /* 0x3C */
    s32 gun_class;  /* 0x40 */
    s32 shadow;     /* 0x44 */
} CoilBall_0030D408;

typedef struct {
    u8 pad0[0x8C];
    s32 used;       /* 0x8C */
    u8 pad90[0x10];
} CoilArc_0030D408;

__asm__(".extern D_L01_001DC650, 4");
__asm__(".extern D_L01_001DC654, 4");
extern s32 D_L01_001DC650;
extern s32 D_L01_001DC654;
extern s32 D_L01_00271AF0[];
extern s32 func_L01_0030D678(void);
extern u8 *func_L01_00457410(u8 *);

/* coil_ball_spawn: the Plasma Coil's ball (class 0xA9B) from pos at velocity x 1.2 (PAL's
   frame), in the first free of 5 slots; none while 4 are out. In the aiming camera modes it
   bends toward the aim point. The first one also clears the sparks' and arcs' slots; each
   ball gets 20 sparks. */
u8 *func_L01_0030D408(u8 *gun, s32 level, s128_00309B80 *pos, f32 *velocity)
{
    u8 *ball;
    CoilBall_0030D408 *vars;
    f32 at[4];
    s128_00309B80 *place;
    s32 i;

    if (func_L01_0030D678() != 0) {
        return 0;
    }
    for (i = 0; i < 5; i++) {
        if (D_L01_00271AF0[i * 4] == 0) {
            break;
        }
    }
    ball = func_003C24B0(0xA9B, 0x80);
    if (ball != 0) {
        ball[0x20] = 0;
        *(u16 *)(ball + 0x32) = 0xFF;
        ball[0x30] = 0xFF;
        vars = *(CoilBall_0030D408 **)(ball + 0x68);
        place = (s128_00309B80 *)(ball + 0x10);
        *place = *pos;
        *(s128_00309B80 *)at = *place;
        /* its shadow made at the hero, then put where it starts */
        *place = *(s128_00309B80 *)D_001A4C60;
        vars->shadow = func_L01_004C85C8(ball, 0, 1.0f, 1.0f, 1.0f);
        *place = *(s128_00309B80 *)at;
        func_0038CF68((S_0030CD20 *)vars, (S_0030CD20 *)velocity, 1.2f);
        /* the hero's camera mode: not the follow camera */
        if (*(s32 *)(D_001A4C60 + 0x1630) != 0) {
            /* within 35 u, turned at most 80 degrees */
            ((void (*)(void *, void *, f32, f32, f32))func_L01_004CAC78)(vars, place, func_0038CEA8(vars), 35.0f, 1.3962634f);
        }
        /* 133 frames: the US's 160 */
        vars->life = 133;
        vars->sound = 17;
        vars->slot = i;
        D_L01_00271AF0[i * 4] = (s32)ball;
        D_L01_001DC650++;
        vars->radius = 2.5f;
        vars->level = level;
        vars->x1C = 0;
        vars->x34 = 0;
        vars->x38 = 0;
        vars->gun_class = *(s16 *)(gun + 0xAA);
        if (D_L01_001DC654 == 0) {
            D_L01_001E1720 = *(S_0030CD20 **)(*(u8 **)(gun + 0x68) + 8);
            D_L01_001E1724 = func_L01_00457410((u8 *)D_L01_001E1720 + 0xC00);
            func_L01_00457410(D_L01_001E1724 + 0x780);
            D_L01_001DC654 = 1;
            for (i = 63; i >= 0; i--) {
                D_L01_001E1720[i].w16 = 0;
            }
            for (i = 0; i < 12; i++) {
                ((CoilArc_0030D408 *)D_L01_001E1724)[i].used = 0;
            }
        }
        for (i = 0; i < 20; i++) {
            func_L01_0030CFC0((s32)ball);
        }
    }
    return ball;
}

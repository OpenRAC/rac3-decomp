/* func_L39_00537B28: Opus handoff (prep by Sonnet worker w6, 2026-11-08)
   Size: 5952 bytes, places: 15 levels (39..53), file: src/levels/shared/L39_00537998.c (@ps2as), flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as
   Step 0: one function, no jump table (no switch); heavy on vec_set_length (func_0038CF68), collision (func_003D5630,
     func_003D3CB0) and the 'protected value' helper func_L39_00648AE0; 44 COP2 instrs, 48 lq/sq.
   rac2 twin: func_L00_003AE900 (rac2-decomp src/levels/shared/L00_003AE900-g8.c, 840 lines, matched, 8440 B): the per-frame
     update of the hero-steered bot (moby class 0x81E). Opcode similarity 0.57: a family relative, not a port.
     rac3 sibling func_L39_00539398: 0.50-0.52 to this one (align.py): same prologue and helper set, parts identical.
   Mapping: the draft below is the rac2 C with func_/D_ names renamed through aligned jal/lui/$gp pairs (rac2 gp 0x1AEFF0,
     rac3 L39 gp 0x247FC0): func_00282F20->func_0038CF68 (vec_set_length, solid), func_00282978->func_0038CAD0 (timer_tick),
     func_L00_003AE550->func_L39_00648AE0 (weak). Weakly supported pairs are named UNMAPPED_<rac2 name>. Moby layout is shared with
     rac2 (pos +0x10, state +0x20, class +0x24, flags +0x34).
   Identical / changed: only ~50% of the opcodes line up, in short runs; rac2 has big blocks with no partner here
     (003AEA78-003AEAEC, 003AEB04-003AEB5C, 003AEC34-003AED34) and this function has replaced ones (A 00537C14-00537C4C ...).
   Draft: compiles at level 39 (2104 diff): it is rac2's logic, NOT a body for this function; kept for its type context and
     the rename table. The usable starting point for the logic is m2c (m2c2 output ~700 lines), see Tool note.
   VU0 note: 44 COP2 instructions; with the 2026-11-06 rule (no VU0 inline asm) this stays a near miss unless a TI-mode
     form generates them.
   Left for Opus: (1) work from m2c, not from the rac2 body; (2) decide with the sibling which blocks are shared and match
     the smaller one (func_L39_00537B28) first; (3) COP2 blocks.
   Tool note: tools in out/tools-w6/ (m2c2.py restores `.word`-hidden instructions and the jump tables so m2c runs;
     port.py renames rac2 C onto an aligned rac3 function).
*/
/* Per-frame update of the hero-steered bot (class 0x81E): flight, collision, attachment,
   idle effects and self-destruct burst. Own unit: it reaches the level's globals through $gp. */

typedef int TI128_AE900 __attribute__((mode(TI)));
typedef union { TI128_AE900 q; float f[4]; int i[4]; } VecAE900;

/* One frame at 60 Hz, and degrees to radians, as the retail constants fold. */
#define FRAME_AE900 0.016666668f
#define DEG_AE900 0.017453294f
#define PI_AE900 3.1415927f

struct VarsAE900;

typedef struct MobyAE900 {
    char pad00[0x10];
    VecAE900 pos;                 /* 0x10 */
    unsigned char state;          /* 0x20 */
    char pad21[3];
    char *pClass;                 /* 0x24 */
    char pad28[0xC];
    unsigned short flags;         /* 0x34 */
    char pad36[0xC];
    unsigned char b42;            /* 0x42 */
    unsigned char b43;            /* 0x43 */
    char pad44[0x1C];
    unsigned char b60;            /* 0x60 */
    char pad61[7];
    struct VarsAE900 *vars;       /* 0x68 */
    char pad6C[0x2C];
    int collData;                 /* 0x98 */
    char pad9C[0xC];
    unsigned char bA8;            /* 0xA8 */
    char padA9;
    short oClass;                 /* 0xAA */
    char padAC[0x10];
    unsigned char bBC;            /* 0xBC */
    char padBD[3];
    char matrix[0x30];            /* 0xC0 */
    float rot[4];                 /* 0xF0 */
} MobyAE900;

typedef struct VarsAE900 {
    VecAE900 vel;                 /* 0x00: vel.f[2] is the vertical speed */
    char pad10[0x20];
    MobyAE900 *owner;             /* 0x30 */
    short timer34;                /* 0x34 */
    short s36;                    /* 0x36 */
    char pad38[8];
    float pull;                   /* 0x40 */
    char pad44[4];
    short timer48;                /* 0x48 */
    char pad4A[2];
    MobyAE900 *ground;            /* 0x4C */
    short inWater;                /* 0x50 */
    short bob;                    /* 0x52 */
    MobyAE900 *target;            /* 0x54 */
    int timer58;                  /* 0x58 */
    int i5C;                      /* 0x5C */
    float f60;                    /* 0x60 */
    float f64;                    /* 0x64 */
    int sound;                    /* 0x68 */
    float amp;                    /* 0x6C */
    float phase;                  /* 0x70 */
    int frame;                    /* 0x74 */
    int i78;                      /* 0x78 */
} VarsAE900;

typedef struct {
    char pad00[0x88];
    float z;                      /* 0x88 */
    char pad8C[0x33C - 0x8C];
    MobyAE900 *standing;          /* 0x33C */
    char pad340[0x1220 - 0x340];
    MobyAE900 *held;              /* 0x1220 */
    char pad1224[0x2290 - 0x1224];
    MobyAE900 *moby;              /* 0x2290 */
    char pad2294[0x22B4 - 0x2294];
    unsigned char b22B4;
    unsigned char b22B5;
    char pad22B6[9];
    unsigned char b22BF;
} HeroAE900;

typedef struct {
    char pad00[0x18];
    MobyAE900 *hit;               /* 0x18 */
    int count;                    /* 0x1C */
    VecAE900 point;               /* 0x20 */
    VecAE900 p30;                 /* 0x30 */
    VecAE900 normal;              /* 0x40 */
} CollAE900;

/* The record handed to the collision test (its fifth argument). */
typedef struct {
    VecAE900 dir;                 /* 0x00 */
    MobyAE900 *owner;             /* 0x10 */
    int flags;                    /* 0x14 */
    unsigned char b18;
    unsigned char b19;
    unsigned short oClass;        /* 0x1A */
    float damage;                 /* 0x1C */
    int i20;                      /* 0x20 */
} HitAE900;

/* 0xE0-byte weapon record: +4 upgraded flag, +0x70 a rate. */
typedef struct { char pad00[4]; unsigned char upgraded; char pad05[0x6B]; float rate; char pad74[0x6C]; } WeaponAE900 __attribute__((aligned(16)));

/* Sound state has a 0x70-byte header followed by 52 0x70-byte voices. */
typedef struct {
    unsigned int handle;
    unsigned char active;
    char unknown05[0x13];
    MobyAE900 *owner;
    char unknown1C[0x54];
} SlotAE900 __attribute__((aligned(16)));
typedef struct { char header[0x70]; SlotAE900 slots[52]; } SoundAE900;
#define SLOT_AE900(i) (D_L39_001FE020.slots[(i)])

/* 0x50-byte effect template copied to the stack for func_L01_0044BEC8. */
typedef struct { VecAE900 v; char rest[0x40]; } TemplateAE900;

/* Four per-kind rates, 4-byte aligned: copied with unaligned doubleword moves. */
typedef struct { float v[4]; } RatesAE900;

/* Camera shake record: +0x160 amount, +0x168 frames, +0x16C counter. */
typedef struct { char pad000[0x160]; float amount; char pad164[4]; int frames; int counter; } ShakeAE900;


extern HeroAE900 D_L39_0024CE20;
extern unsigned char D_00139568[];
extern WeaponAE900 D_L39_0025DE80[];
extern SoundAE900 D_L39_001FE020;
extern CollAE900 D_L39_0025F740;
extern TemplateAE900 D_L00_002A2870;
extern TemplateAE900 D_L00_002A28C0;
extern RatesAE900 D_L00_001AF7E0;
extern int D_L39_0024112C ;
extern float D_L00_001AF7B4 ;
extern int D_L00_001AF7B0 ;
extern int D_L00_001B2630 ;
extern int D_L39_0024CAF0 ;
extern VecAE900 D_L00_001B8DC0;
extern ShakeAE900 D_L39_0024DE80;
extern char D_L00_001C3280[];
extern MobyAE900 *D_L00_001FACE0[];
extern char D_L00_001FDEF8[];
extern char D_L39_00296818[];

extern void func_L00_003ADEA0(void);
extern int func_L39_00648AE0(VarsAE900 *, MobyAE900 *, int);
extern float func_L39_00537908(float, float, float);
extern void *func_L39_005CE670(void *, void *, unsigned int, float, float, int, float, int, int);
extern int func_L01_00480A78(int, int, float);
extern float func_0038CEA8(void *);
extern char *func_003C4D58(void *);
extern void func_00283410(void *, void *);
extern void func_00283658(void *, void *);
extern void func_00283788(void *, void *, void *);
extern void func_00283678(void *, void *);
extern void func_0038CFB8(void *, void *, void *);
extern void UNMAPPED_func_00282CF0(void *, void *, void *);
extern int func_L39_005B4398(int);
extern float func_002A90F8(void *, void *);
extern void func_0038CE20(void *, void *, float);
extern float func_L39_005B4410(float, float);
extern void * func_002BF728(void *, void *, float, float);
extern void func_00282F70(void *, void *, float);
extern float func_00283CE0(int);
extern float func_0038D0B0(float);
extern float func_0038D098(float);
extern int func_L39_00539268(void *, void *, int, void *, void *);
extern int func_003D5630(void);
extern void func_L01_004C67A0(int, int, int, float, float, float, float);
extern void func_00282C88(void *);
extern char *func_L01_003016B0(void *, float);
extern float func_L39_005B44C8(void);
extern int func_L39_005B43C8(int, int);
extern void * func_L01_00468A68(void *, void *, int, int);
extern int func_002ABB78(void *);
extern float func_003C3D30(void *, int, float);
extern void func_L01_0040E790(void *, void *, void *);
extern void func_0038CF68(void *, void *, float);
extern float func_0038CE68(void *, void *);
extern float func_00282C48(float);
extern float func_00282C10(float);
extern float func_0038D160(float, float);
extern int func_L01_0044C638(void *, void *, void *, void *, void *, void *);
extern void func_L39_005F3088(int);
extern void func_L39_005F2FA0(void *, int, int, int);
extern int func_002E59B0(void *, int);
extern int func_L39_005F33E0(int, int, void *);
extern int func_0038CAD0(void *);
extern void func_002A8C00(void *, void *, int, void *, float);
extern int UNMAPPED_func_00277F48(void *, int, void *, void *, float);
extern int func_L01_003FB640(void *, int, void *, float);
extern int UNMAPPED_func_00282948(void *);
extern void func_002AEF28(void *, void *, void *, float, float, float);
extern char *func_002A9640(void *, unsigned int, int);
extern float func_00282E80(void *, void *);
extern float func_003D4D00(void *, void *);
extern int func_L01_0044EBA0(void *, void *, void *, float, float, float, float, int);
extern void func_002AC728(void *, void *, int, float, float);
extern void func_002ACAD0(void *, void *);
extern void func_L01_00447718(void *);
extern float func_00283B98(float, float);
extern void func_002A9850(void *, void *, void *, int, int, int, int, int, float, float, float);
extern float func_002A8A20(void *);
extern int func_L01_00448D88(unsigned int, int);
extern char *func_L39_005C7B40(void *, void *, int, int, float, int, int, int, int, int);
extern void func_L32_003B8498(void *, void *, void *, float, float, int, int, int, float, float, float, float, int, float, int, int, int, int, int);
extern int func_00283CF0(float);
extern char *func_002BCF18(void *, void *, int, int, float, int, int);
extern void func_002AF000(void *, float, float, float);
extern void * func_L01_0044BEC8(void *, void *, int, int);
extern void func_L01_004471A8(void *, float);

/* Leaves the current state: stops the owned sound and resets the fall. */
#define DETACH_AE900() \
    { \
        int sound; \
        moby->state = 0; \
        sound = vars->sound; \
        if (sound != -1) { \
            if (SLOT_AE900(sound).owner == moby && SLOT_AE900(sound).active) \
                func_L39_005F3088(sound); \
        } \
        vars->sound = -1; \
        vars->timer34 = 0x78; \
        vars->vel.f[2] = 0.0f; \
    }

/* Rotation matrix for half a turn about X. */
static __inline__ void HalfTurnAE900(VecAE900 *m)
{
    VecAE900 turn;

    turn.q = 0;
    turn.f[0] = PI_AE900;
    func_00283410(m, &turn);
}

/* Copies the owner's matrix into dst. */
static __inline__ void OwnerMatrixAE900(VecAE900 *dst, MobyAE900 *owner)
{
    func_00283658(dst, owner->matrix);
}

/* While held (state 1): the bot's matrix is its owner's, turned half a turn about X. */
static __inline__ void AlignToOwnerAE900(MobyAE900 *moby, VarsAE900 *vars)
{
    VecAE900 m1[4];
    VecAE900 m2[4];
    VecAE900 *rot = m1;
    VecAE900 *own;

    HalfTurnAE900(rot);
    own = m2;
    OwnerMatrixAE900(own, vars->owner);
    func_00283788(rot, own, rot);
    func_00283678(moby->matrix, rot);
}

void func_L39_00537B28(MobyAE900 *moby)
{
    TemplateAE900 small;
    TemplateAE900 big;
    VecAE900 impulse;
    VecAE900 prev;
    VecAE900 up;
    VarsAE900 *vars;
    char *landed;
    MobyAE900 *owner;

    small = D_L00_002A2870;
    big = D_L00_002A28C0;
    landed = 0;
    impulse.q = 0;
    impulse.f[2] = 2.0f * FRAME_AE900;
    up.q = 0;
    up.f[2] = 1.0f;
    vars = moby->vars;
    func_L00_003ADEA0();

    if ((D_L39_0024CE20.b22B5 != 0 || D_L39_0024CE20.b22BF != 0) && moby->state == 1)
        moby->flags |= 0x41;
    else
        moby->flags &= ~0x41;

    if (D_L39_0024CE20.held == 0 || D_L39_0024CE20.held->oClass != 0x81E) {
        if (moby->state == 1) {
            func_L01_00447718(moby);
            return;
        }
    }
    if (D_L39_0024CE20.b22B4 != 0) {
        if (moby->state == 1) {
            func_L01_00447718(moby);
            return;
        }
    }

    owner = vars->owner;
    if (owner != 0)
        if (owner->state != 0xFE)
            if (owner->state != 0xFD)
                if (owner->oClass == 0x81E && vars->s36 == 0 && func_0038CEA8(vars) > 0.0f) {
                    if (D_L39_0024CE20.standing == 0 || func_003C4D58(D_L39_0024CE20.standing) == 0) {
                        func_L39_00648AE0(vars, moby, 1);
                    } else {
                        if (func_L39_00648AE0(vars, moby, 0) == 0)
                            func_L39_00648AE0(vars, moby, 2);
                    }
                }

    if (moby->state == 1) {
        if (D_L39_0024CE20.held == 0 || D_L39_0024CE20.held->oClass != 0x81E) {
            func_L01_00447718(moby);
            return;
        }
        AlignToOwnerAE900(moby, vars);
        moby->collData = 0;
        moby->flags |= 0x100;
        return;
    } else {
        HitAE900 hit;
        VecAE900 t120;
        VecAE900 t130;
        VecAE900 t140;
        VecAE900 t150;
        VecAE900 t160;
        VecAE900 t170;
        VecAE900 t180;
        float t;
        float dist;
        float water;
        MobyAE900 *target;

        moby->flags &= ~0x100;
        qcopy_nc(&prev, &moby->pos);
        if (!(moby->state & 4)) {
            func_0038CFB8(&moby->pos, &moby->pos, &vars->vel);
            if (vars->inWater == 0) {
                vars->vel.f[2] -= 9.8f / 60.0f / 60.0f;
            } else {
                vars->vel.f[2] -= 0.98f / 60.0f / 60.0f;
                if (func_L39_005B4398(5) == 0) {
                    float height = func_002A90F8(&moby->pos, &hit.dir);
                    func_0038CE20(&hit.dir, &vars->vel, 0.25f);
                    func_002BF728(&moby->pos, &hit.dir, func_L39_005B4410(0.05f, 0.1f) * 210000.0f, height);
                }
            }
        }
        hit.owner = moby;
        hit.flags = 0x830000;
        hit.i20 = 1;
        hit.damage = (*(D_L39_0025DE80 + D_00139568[0x22])).rate;
        qcopy(&hit.dir, &vars->vel);
        func_00282F70(&hit.dir, &hit.dir, 1.0f);
        hit.b18 = 2;
        hit.dir.f[3] = 5627.925f;
        hit.b19 = 1;
        hit.oClass = moby->oClass;
        hit.dir.f[2] = 1.0f;
        moby->pos.f[2] -= 0.4f;
        t = func_00283CE0(D_L39_0024112C - vars->frame) / D_L00_001AF7B4;
        if (t > 1.0f)
            t = 1.0f;
        else if (t < 0.0f)
            t = 0.0f;
        moby->pos.f[2] -= vars->amp * func_0038D0B0(vars->phase) * t;

        if (!(moby->state & 4) && func_L39_00539268(&prev, &moby->pos, 0x10, moby, &hit)) {
            if (vars->inWater == 0 && func_003D5630() == 0 && vars->vel.f[2] < 0.0f) {
                char *splash;
                int i;

                func_L01_004C67A0(D_L00_001B2630, D_L39_0024CAF0, 1, moby->pos.f[0], moby->pos.f[1], 0.5f, -0.35f);
                vars->inWater = 1;
                func_00282C88(vars);
                vars->vel.f[2] = -1.5f * FRAME_AE900;
                t120.f[0] = moby->pos.f[0];
                t120.f[1] = moby->pos.f[1];
                t120.f[2] = D_L39_0025F740.point.f[2];
                splash = func_L01_003016B0(&t120, 2.0f);
                if (splash)
                    splash[0x23] = 0x70;
                for (i = 0; i < 16; i++) {
                    float a = func_L39_005B44C8();
                    float r = func_L39_005B4410(0.0f, 3.0f * FRAME_AE900);
                    int life;

                    t130.f[0] = func_0038D098(a) * r;
                    t130.f[1] = func_0038D0B0(a) * r;
                    t130.f[2] = func_L39_005B4410(3.0f * FRAME_AE900, 6.5f * FRAME_AE900);
                    life = func_L39_005B43C8(90, 120);
                    func_L01_00468A68(&t120, &t130, func_L39_005B4398(2), life);
                }
            } else if (vars->inWater != 0 || func_003D5630() != 0) {
                if (D_L39_0025F740.hit) {
                    if (func_002ABB78(D_L39_0025F740.hit) || (D_L39_0025F740.hit->flags & 0x1000)) {
                        if (D_L39_0025F740.hit->oClass != moby->oClass && D_L39_0025F740.hit != D_L39_0024CE20.moby
                            && D_L39_0025F740.hit != vars->owner) {
                            moby->bBC = 1;
                            if (moby->state != 1) {
                                qcopy(&moby->pos, &D_L39_0025F740.point);
                                moby->pos.f[2] = func_003C3D30(&moby->pos, 0, 0.5f);
                            }
                            goto settled;
                        }
                    }
                }
                if (D_L39_0025F740.hit && D_L39_0025F740.hit->oClass == moby->oClass) {
                    UNMAPPED_func_00282CF0(&D_L39_0025F740.normal, &moby->pos, &D_L39_0025F740.hit->pos);
                    if (vars->vel.f[2] < -9.8f * FRAME_AE900) {
                        moby->bBC = 1;
                        qcopy(&moby->pos, &D_L39_0025F740.point);
                        func_L01_0040E790(&impulse, &vars->vel, &D_L39_0025F740.normal);
                        func_0038CF68(&impulse, &impulse, 2.0f * FRAME_AE900);
                        func_0038CF68(&up, &D_L39_0025F740.normal, 1.0f);
                    } else {
                        qcopy(&moby->pos, &D_L39_0025F740.point);
                        func_0038CF68(&t120, &D_L39_0025F740.normal, 9.7f / 3600.0f);
                        func_0038CFB8(&moby->pos, &moby->pos, &t120);
                        func_L01_0040E790(&vars->vel, &vars->vel, &D_L39_0025F740.normal);
                        func_0038CE20(&vars->vel, &vars->vel, 0.4f);
                        func_0038CF68(&t120, &D_L39_0025F740.normal, 1.0f);
                        func_0038CE68(&t120, &up);
                        qcopy(&t130, &D_L39_0025F740.normal);
                        goto align;
                    }
                } else if ((D_L39_0025F740.hit && D_L39_0025F740.hit != D_L39_0024CE20.moby && D_L39_0025F740.hit != vars->owner) || D_L39_0025F740.count > 0) {
                    if (vars->inWater != 0 || func_003D5630() == 0 || vars->vel.f[2] < -9.8f * FRAME_AE900) {
                        moby->bBC = 1;
                        qcopy(&moby->pos, &D_L39_0025F740.point);
                        func_L01_0040E790(&impulse, &vars->vel, &D_L39_0025F740.normal);
                        func_0038CF68(&impulse, &impulse, 2.0f * FRAME_AE900);
                        func_0038CF68(&up, &D_L39_0025F740.normal, 1.0f);
                    } else {
                        MobyAE900 *under = D_L39_0025F740.hit;

                        if (under)
                            landed = func_003C4D58(under);
                        qcopy(&moby->pos, &D_L39_0025F740.point);
                        func_0038CF68(&t120, &D_L39_0025F740.normal, 9.7f / 3600.0f);
                        func_0038CFB8(&moby->pos, &moby->pos, &t120);
                        t150.q = vars->vel.q;
                        func_L01_0040E790(&vars->vel, &vars->vel, &D_L39_0025F740.normal);
                        func_0038CE20(&vars->vel, &vars->vel, 0.6f);
                        vars->vel.f[2] *= 0.5f;
                        if (vars->amp == 0.0f) {
                            float ph;

                            vars->amp = func_00282C48(t150.f[2]) * 2.0f;
                            ph = -2.3561947f;
                            if (0.0f < t150.f[2]) {
                                ph = 0.78539824f;
                            }
                            vars->frame = D_L39_0024112C;
                            vars->phase = ph;
                        }
                        func_0038CF68(&t120, &D_L39_0025F740.normal, 1.0f);
                        if (func_0038CE68(&t120, &up) > 0.707f) {
                            if (t150.f[2] < 0.0f) {
                                float floor = func_003C3D30(&moby->pos, 0, 0.5f);

                                if (moby->pos.f[2] < floor)
                                    moby->pos.f[2] = floor;
                                vars->vel.f[2] = -vars->vel.f[2];
                                if (func_0038CEA8(vars) < 0.5f * FRAME_AE900 || landed) {
                                    func_00282C88(vars);
                                    moby->state |= 4;
                                    moby->collData = *(int *)(moby->pClass + 0x10);
                                    if (D_L39_0025F740.hit && landed)
                                        vars->ground = D_L39_0025F740.hit;
                                }
                            }
                        }
                        qcopy(&t130, &D_L39_0025F740.normal);
                    align:
                        t140.f[0] = t130.f[0] * func_0038D098(moby->rot[2]) + t130.f[1] * func_0038D0B0(moby->rot[2]);
                        t140.f[1] = t130.f[1] * func_0038D098(moby->rot[2]) - t130.f[0] * func_0038D0B0(moby->rot[2]);
                        t140.f[2] = t130.f[2];
                        moby->rot[0] = func_L39_00537908(moby->rot[0],
                            -func_0038D160(func_00282C10(t140.f[0] * t140.f[0] + t140.f[2] * t140.f[2]), t140.f[1]),
                            PI_AE900 * FRAME_AE900);
                        moby->rot[1] = func_L39_00537908(moby->rot[1], func_0038D160(t140.f[2], t140.f[0]), PI_AE900 * FRAME_AE900);
                    }
                }
            }
        } else if (moby->state & 4) {
            float floor = func_003C3D30(&moby->pos, 0, 0.5f);

            if (vars->ground) {
                if (vars->ground->state != 0xFE)
                    if (vars->ground->state != 0xFD)
                        goto alive;
                moby->bBC = 1;
                vars->ground = 0;
                goto check;
            alive:
                if (D_L39_0025F740.hit) {
                    landed = func_003C4D58(D_L39_0025F740.hit);
                    if (landed)
                        func_L01_0044C638(moby, vars->ground, &moby->pos, moby->rot, &moby->pos, moby->rot);
                }
            check:
                if (!landed) {
                    DETACH_AE900();
                    vars->ground = 0;
                }
            } else if (!(moby->state & 8)) {
                if (moby->pos.f[2] - floor < 1.0f / 90.0f) {
                    moby->pos.f[2] = floor;
                    vars->timer34 = 0;
                    if (D_L39_0025F740.hit && func_003C4D58(D_L39_0025F740.hit))
                        vars->ground = D_L39_0025F740.hit;
                } else {
                    DETACH_AE900();
                }
            }
            target = vars->target;
            if (target == 0)
                goto lost;
            if (target->state == 0xFE)
                goto lost;
            if (target->state == 0xFD)
                goto lost;
            if (target->flags & 0x1000)
                goto kept;
        lost:
            if (moby->state & 8) {
                DETACH_AE900();
                vars->target = 0;
                if (moby->b43)
                    func_L39_005F2FA0(moby, 0, 0, 10);
            }
        kept:
            if (vars->target != 0 && (moby->state & 8)) {
                t130.q = moby->pos.q;
                if (moby->b60 & 2) {
                    if (moby->b42 == 1 && moby->b43 != 2)
                        func_L39_005F2FA0(moby, 2, 0, 10);
                }
                if (!func_002E59B0(moby, vars->sound))
                    vars->sound = func_L39_005F33E0(1, 4, moby);
                vars->pull += 0.25f * FRAME_AE900;
                if (vars->pull > 16.0f * FRAME_AE900)
                    vars->pull = 16.0f * FRAME_AE900;
                if (vars->bob == 1) {
                    moby->pos.f[2] += 0.05f;
                    if (func_0038CAD0(&vars->timer48)) {
                        vars->timer48 = 7;
                        vars->bob = 2;
                    }
                } else if (vars->bob == 2) {
                    moby->pos.f[2] -= 0.05f;
                    if (func_0038CAD0(&vars->timer48))
                        vars->bob = 0;
                }
                UNMAPPED_func_00282CF0(&t120, &vars->target->pos, &moby->pos);
                func_0038CF68(&t120, &t120, vars->pull);
                func_0038CFB8(&moby->pos, &moby->pos, &t120);
                func_002A8C00(&t140, moby, 0x10000, &t120, (*(D_L39_0025DE80 + D_00139568[0x22])).rate);
                qcopy(&t170, &moby->pos);
                t170.f[2] += 0.35f;
                if (UNMAPPED_func_00277F48(&t170, 0x10, moby, &t140, 0.35f)) {
                    MobyAE900 *blocker = D_L39_0025F740.hit;

                    if (blocker && blocker->oClass != 0x363 && blocker->oClass != 0x81F && blocker->oClass != 0x458
                        && blocker->oClass != 0x365 && blocker->oClass != 0x367)
                        moby->bBC = 1;
                }
                qcopy(&t170, &moby->pos);
                t170.f[2] += 0.25f;
                if (func_L01_003FB640(&t170, 0, moby, 0.25f)) {
                    UNMAPPED_func_00282CF0(&t180, &D_L39_0025F740.p30, &t170);
                    func_0038CFB8(&moby->pos, &moby->pos, &t180);
                }
                if (UNMAPPED_func_00282948(&vars->timer58))
                    moby->bBC = 1;
            }
            func_002AEF28(moby, &vars->f60, &vars->f64, 30.0f * DEG_AE900, 30.0f * DEG_AE900 * FRAME_AE900,
                          17.0f * DEG_AE900 * FRAME_AE900);
            if (moby->state & 4) {
                UNMAPPED_func_00282CF0(&t120, &moby->pos, &prev);
                vars->vel.q = t120.q;
            }
        }
    settled:
        if (!(moby->state & 2)) {
            if (func_0038CAD0(&vars->timer34)) {
                moby->state |= 2;
                vars->target = 0;
            }
        }
        {
            char *link = func_002A9640(moby, 0x830000, 0);

            if (link && *(MobyAE900 **)(link + 0x20) && (*(MobyAE900 **)(link + 0x20))->oClass != moby->oClass)
                moby->bBC = 1;
        }
        moby->bA8 = 0xFF;
        if (moby->state & 2) {
            if (!(moby->state & 4)
                || (func_00282E80(&D_L39_0024CE20.moby->pos, &moby->pos) < 0.75f
                    && func_00282C48(moby->pos.f[2] - D_L39_0024CE20.z) < 0.25f && (moby->state & 8))) {
                moby->bBC = 1;
            } else if (func_003D4D00(&D_L39_0024CE20.moby->pos, &moby->pos) < 0.75f) {
                UNMAPPED_func_00282CF0(&t140, &moby->pos, &D_L39_0024CE20.moby->pos);
                t120.q = t140.q;
                func_0038CF68(&t120, &t120, 0.75f);
                func_0038CFB8(&t140, &D_L39_0024CE20.moby->pos, &t120);
                t130.q = t140.q;
                func_L01_0044EBA0(moby, &moby->pos, &t130, 0.4f, 0.25f, 0.25f, 30.0f * DEG_AE900, 0);
            } else {
                int i = 0;
                MobyAE900 *other = D_L00_001FACE0[0];

                while (other) {
                    if (!(func_003D4D00(&moby->pos, &other->pos) > 30.0f)) {
                        if (func_003D4D00(&moby->pos, &other->pos) < 0.75f) {
                            moby->bBC = 1;
                            break;
                        }
                    }
                    i++;
                    other = D_L00_001FACE0[i];
                }
            }
        }
        vars->i78 = 0;
        if (vars->i5C < 0 || D_L00_001AF7B0 != 0) {
            func_002AC728(moby, &moby->pos, -1, 0.33f, 13.0f);
            func_002ACAD0(moby, D_L00_001FDEF8);
            func_L01_00447718(moby);
        }
        if (vars->amp > 0.05f) {
            vars->amp *= 0.988f;
            if (vars->amp < 0.05f)
                vars->amp = 0.05f;
        }
        t = func_00283CE0(D_L39_0024112C - vars->frame) / D_L00_001AF7B4;
        if (t > 1.0f)
            t = 1.0f;
        else if (t < 0.0f)
            t = 0.0f;
        vars->phase = func_00283B98(vars->phase, 360.0f * DEG_AE900 * FRAME_AE900);
        moby->pos.f[2] = moby->pos.f[2] + vars->amp * func_0038D0B0(vars->phase) * t + 0.4f;
        if (moby->bBC) {
            dist = func_00282E80(&moby->pos, &D_L00_001B8DC0);
            if (vars->inWater == 0) {
                float radius = 2.0f;
                int count;

                if ((*(D_L39_0025DE80 + D_00139568[0x22])).upgraded)
                    radius = 3.0f;
                count = UNMAPPED_func_00277F48(&moby->pos, 0x10, moby, 0, radius);
                t120.q = moby->pos.q;
                func_002A9850(moby, &t120, D_L00_001C3280, count, 0, 0x810000, 4, 1, (*(D_L39_0025DE80 + D_00139568[0x22])).rate, 0.25f, 1.5f);
            }
            water = func_002A8A20(&moby->pos);
            if (vars->inWater != 0) {
                float surface;
                int i;
                int j;
                int l;
                int cb;
                int cg;
                int cr;
                int c;

                t120.q = moby->pos.q;
                t120.f[2] += 3.5f;
                surface = func_003C3D30(&t120, 0, 0.5f);
                for (i = 0; i < 150; i++) {
                    t140.q = 0;
                    t140.f[0] = func_L39_005B4410(-1.0f, 1.0f);
                    t140.f[1] = func_L39_005B4410(-1.0f, 1.0f);
                    t140.f[2] = func_L39_005B4410(-0.5f, -2.0f);
                    t130.q = t140.q;
                    func_0038CF68(&t130, &t130, func_L39_005B4410(4.0f * FRAME_AE900, 8.0f * FRAME_AE900));
                    func_002BF728(&moby->pos, &t130, func_L39_005B4410(0.05f, 0.1f) * 210000.0f, surface);
                }
                cr = 0x60;
                cg = 0x60;
                cb = 0x7F;
                for (j = 0; j < 150; j++) {
                    float rr;
                    float ang;
                    float half;
                    int c1;
                    int c2;

                    t140.q = 0;
                    t140.f[0] = func_L39_005B4410(-0.75f * FRAME_AE900, 0.75f * FRAME_AE900);
                    t140.f[1] = func_L39_005B4410(-0.75f * FRAME_AE900, 0.75f * FRAME_AE900);
                    t140.f[2] = func_L39_005B4410(4.0f * FRAME_AE900, 16.0f * FRAME_AE900);
                    t130.q = t140.q;
                    rr = func_L39_005B4410(0.0f, 0.35f);
                    half = 0.5f;
                    ang = func_L39_005B44C8();
                    t140.f[0] = func_0038D098(ang) * rr;
                    t140.f[1] = func_0038D0B0(ang) * rr;
                    t140.f[2] = 0.0f;
                    func_0038CFB8(&t140, &t140, &moby->pos);
                    t140.f[2] = surface + half;
                    t130.f[2] -= rr * (8.0f * FRAME_AE900);
                    c1 = (0x16 << 24) | (cb << 16) | (cg << 8);
                    c2 = (cb << 16) | (cg << 8);
                    func_L39_005CE670(&t140, &t130, 0, func_L39_005B4410(0.35f, 1.25f), surface,
                                      c1 | cr, 1.0f / 180.0f, c2 | cr, 1);
                }
                c = (0x7F << 24) | (cb << 16) | (cg << 8);
                for (l = 0; l < 20; l++) {
                    int c1 = func_L01_00480A78(0x7F000000, c | cr, func_L39_005B4410(0.25f, 1.0f));
                    int c2 = func_L01_00480A78(0, ((cb / 2) << 16) | ((cg / 2) << 8) | (cr / 2),
                                               func_L39_005B4410(0.5f, 1.0f));
                    float sz;
                    int life;
                    char **defs;
                    int tex;

                    t140.f[0] = func_L39_005B4410(-3.0f, 3.0f);
                    t140.f[1] = func_L39_005B4410(-3.0f, 3.0f);
                    t140.f[2] = func_L39_005B4410(4.0f * FRAME_AE900, 14.0f * FRAME_AE900);
                    func_0038CF68(&t140, &t140, func_L39_005B4410(1.5f, 3.0f) * FRAME_AE900);
                    t140.f[2] = func_L39_005B4410(3.0f, 6.0f) * FRAME_AE900;
                    t130.q = moby->pos.q;
                    t130.f[2] = surface;
                    c1 = func_L01_00448D88(c1, (*(D_L39_0025DE80 + D_00139568[0x22])).upgraded != 0);
                    c2 = func_L01_00448D88(c2, (*(D_L39_0025DE80 + D_00139568[0x22])).upgraded != 0);
                    sz = func_L39_005B4410(0.15f * 210000.0f, 0.25f * 210000.0f);
                    life = func_L39_005B43C8(90, 150);
                    defs = (char **)D_L39_00296818;
                    tex = *(unsigned char *)defs[11];
                    func_L39_005C7B40(&t130, &t140, c1, c2, sz, life, 1, tex, -1, 0);
                }
            } else if (water + 2.0f < moby->pos.f[2]) {
                func_00282C88(&t120);
                func_L32_003B8498(moby, &t120, 0, 0.0f, 0.0f, 3, 3, 5, 2.0f, 1.0f, 4.0f, 1.0f, 2, 7.0f, 0, 1, -1,
                              (*(D_L39_0025DE80 + D_00139568[0x22])).upgraded != 0, 0x810001);
            } else {
                float scale = 1.0f;
                int count;
                int i;

                if ((*(D_L39_0025DE80 + D_00139568[0x22])).upgraded)
                    scale = 1.5f;
                count = func_00283CF0(dist * 15.0f);
                for (i = 0; i < count; i++) {
                    int kind = func_L39_005B4398(4);
                    RatesAE900 *rates = (RatesAE900 *)&t120;
                    float r;
                    float a;

                    *rates = D_L00_001AF7E0;
                    t140.q = 0;
                    t140.f[0] = func_L39_005B4410(-0.5f * FRAME_AE900, 0.5f * FRAME_AE900) * scale;
                    t140.f[1] = func_L39_005B4410(-0.5f * FRAME_AE900, 0.5f * FRAME_AE900) * scale;
                    t140.f[2] = func_L39_005B4410(4.0f * FRAME_AE900, rates->v[kind]) * scale;
                    t130.q = t140.q;
                    r = func_L39_005B4410(0.0f, kind == 1 ? 0.5f : 0.25f) * scale;
                    a = func_L39_005B44C8();
                    t140.f[0] = func_0038D098(a) * r;
                    t140.f[1] = func_0038D0B0(a) * r;
                    t140.i[2] = 0;
                    func_0038CFB8(&t140, &t140, &moby->pos);
                    t140.f[2] -= r * func_0038D098(0.785398f);
                    t130.f[2] -= r * (8.0f * FRAME_AE900);
                    switch (kind) {
                    case 0: {
                        int c = func_L01_00448D88(0x1F101820, (*(D_L39_0025DE80 + D_00139568[0x22])).upgraded != 0);
                        float f = func_L39_005B4410(200000.0f, 300000.0f) * scale;
                        func_002BCF18(&t140, &t130, c, 0x101010, f, func_L39_005B43C8(180, 240), 0);
                        break;
                    }
                    case 1: {
                        int c1 = func_L01_00448D88(0x3F081020, (*(D_L39_0025DE80 + D_00139568[0x22])).upgraded != 0);
                        int c2 = func_L01_00448D88(0x0F081020, (*(D_L39_0025DE80 + D_00139568[0x22])).upgraded != 0);
                        func_002BCF18(&t140, &t130, c1, c2, func_L39_005B4410(50000.0f, 100000.0f) * scale, 180, 1);
                        break;
                    }
                    case 2: {
                        int color;
                        int c1;
                        int c2;
                        float f;
                        int roll = func_L39_005B4398(100);

                        color = 0x2F486078;
                        if (roll <= 39)
                            color = 0x5FF8F8F8;
                        c1 = func_L01_00448D88(color, (*(D_L39_0025DE80 + D_00139568[0x22])).upgraded != 0);
                        c2 = func_L01_00448D88(0x0F000020, (*(D_L39_0025DE80 + D_00139568[0x22])).upgraded != 0);
                        f = scale * 150000.0f;
                        func_002BCF18(&t140, &t130, c1, c2, f, func_L39_005B43C8(30, 45), 2);
                        break;
                    }
                    case 3: {
                        int c1 = func_L01_00480A78(0x7F000000, 0x7F182030, func_L39_005B4410(0.25f, 1.0f));
                        int c2 = func_L01_00480A78(0, 0x5F5F5F, func_L39_005B4410(0.5f, 1.0f));
                        float f;

                        c1 = func_L01_00448D88(c1, (*(D_L39_0025DE80 + D_00139568[0x22])).upgraded != 0);
                        c2 = func_L01_00448D88(c2, (*(D_L39_0025DE80 + D_00139568[0x22])).upgraded != 0);
                        func_002AF000(&t130, func_L39_005B4410(0.0f, 1.0f) * FRAME_AE900, a, func_L39_005B44C8());
                        f = func_L39_005B4410(200000.0f, 300000.0f) * scale;
                        func_002BCF18(&t140, &t130, c1, c2, f, func_L39_005B43C8(240, 300), 3);
                        break;
                    }
                    }
                }
            }
            moby->bBC = 0;
            if ((*(D_L39_0025DE80 + D_00139568[0x22])).upgraded)
                func_L39_005F33E0(3, 0, moby);
            else
                func_L39_005F33E0(2, 0, moby);
            {
                ShakeAE900 *shake = &D_L39_0024DE80;

                if (dist < 20.0f)
                    shake->amount = 0.4f - dist * 0.0175f;
                else
                    shake->amount = 0.4f - 20.0f * 0.0175f;
            }
            D_L39_0024DE80.counter = 0;
            D_L39_0024DE80.frames = 25;
            if ((*(D_L39_0025DE80 + D_00139568[0x22])).upgraded)
                func_L01_0044BEC8(&big, &moby->pos, 0, 0);
            else
                func_L01_0044BEC8(&small, &moby->pos, 0, 0);
            func_002ACAD0(moby, D_L00_001FDEF8);
            func_L01_00447718(moby);
        } else {
            func_L01_004471A8(moby, 0.25f);
        }
    }
}

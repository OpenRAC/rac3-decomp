#include "common.h"
#include "vu0.h"

typedef int s128_00341C10 __attribute__((mode(TI)));
typedef union {
    s128_00341C10 q;
    f32 f[4];
} V_00341C10;
typedef struct {
    u8 a;
    u8 b;
    u8 pad[238];
} S_00341C10;
typedef struct {
    u8 pad0[16];
    u8 pos[20];
    s32 active;
    s32 visible;
    s32 target;
} Vars3462F0;
typedef struct {
    char pad0[0x20];
    unsigned char b32;
} Obj;
extern void func_003C2880(Obj *);
typedef struct { u8 pad[0x1A]; s16 x1A; } V_347888;
typedef struct { u8 pad[0x68]; V_347888 *x68; } O_347888;

typedef struct {
    u8 pad0[0x170];
    f32 f170;
    u8 pad1[0x109C];
    s32 f1210;
    u8 pad2[0x13B0];
    s32 f25C4;
    u8 pad3[0x25];
    u8 b25ED;
    u8 pad4[0x2CE];
    s32 f28BC;
} G_00346998;

INCLUDE_ASM("asm/levels", func_L01_00340670);

/* localdecomp:start func_L01_00340C48 */
extern u8 D_L01_001DD180[8];
__asm__(".extern D_L01_001DD180, 8");
u8 *func_L01_00340C48(void *a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 4;
        return D_L01_001DD180;
    }
    return 0;
}
/* localdecomp:end func_L01_00340C48 */

/* localdecomp:start func_L01_00340C68 */
extern f32 D_L01_001DD178;
extern f32 D_L01_001DD17C;
extern void func_L01_004450F0(char *, s32, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_00340FB0(char *);
extern void func_L01_00340DC0(char *);
extern void func_L01_003411A8(char *);
extern void func_L01_00404808(void (*)(void), char *);
extern void func_L01_0044E820(char *, s32);

void func_L01_00340C68(char *obj)
{
    char *sub = *(char **)(obj + 0x68);
    char **list;
    int count;
    float one;
    switch (*(unsigned char *)(obj + 0x20)) {
    case 0:
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        one = 1.0f;
        if (*(float *)(sub + 8) < one) {
            func_003C4138((float *)(sub + 8), one, D_L01_001DD178 * 0.020000001f);
        } else {
            list = (char **)(sub + 0x10);
            if (!(*(float *)(sub + 12) < one))
                goto cleanup;
            if (*(int *)(sub + 4) == 0) {
                *(int *)(sub + 4) = 1;
                func_L01_00340FB0(obj);
            }
            func_L01_00340DC0(obj);
            func_003C4138((float *)(sub + 12), one, D_L01_001DD17C * 0.020000001f);
        }
        goto update;
    cleanup:
        count = 3;
        sub += 0x30;
        do {
            if (*list) {
                *(unsigned short *)(*list + 0x34) = *(unsigned short *)(sub - 0x10);
                func_L01_0044E820(*list, *(int *)sub);
            }
            sub += 4;
            count--;
            list++;
        } while (count >= 0);
        func_003C2880((Obj *)obj);
        break;
    update:
        func_L01_00404808(func_L01_003411A8, obj);
        break;
    }
}
/* localdecomp:end func_L01_00340C68 */

INCLUDE_ASM("asm/levels", func_L01_00340DC0);

/* localdecomp:start func_L01_00340FB0 */
#include "vu0.h"
typedef struct { f32 lo, hi; } PairF_00340FB0;
typedef struct { s32 lo, hi; } PairI_00340FB0;
__asm__(".extern D_L01_001DD188, 8");
__asm__(".extern D_L01_001DD190, 8");
__asm__(".extern D_L01_001DD198, 8");
__asm__(".extern D_L01_001DD1A0, 8");
extern PairF_00340FB0 D_L01_001DD188;
extern PairI_00340FB0 D_L01_001DD190;
extern PairI_00340FB0 D_L01_001DD198;
extern PairF_00340FB0 D_L01_001DD1A0;
extern PairF_00340FB0 D_L01_001DD1A8[];
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_0046C470(void *, void *, s32, s32, u8, s32, s32, s32, f32);
extern void func_0038CE20(void *, void *, f32);
void func_L01_00340FB0(char *obj) {
    vu0_v4 pos;
    s32 i;
    s32 lifetime, color;
    f32 angle = 0.0f;
    f32 r;
    pos = *(vu0_v4 *)(obj + 0x10);
    pos.z += 0.5f;
    {
    PairF_00340FB0 radius = { D_L01_001DD188.lo * 0.020000001f, D_L01_001DD188.hi * 0.020000001f };
    PairF_00340FB0 angleRange = D_L01_001DD1A8[0];
    vu0_v4 vel;
    i = 31;
    do {
        i--;
        lifetime = (func_00382498(D_L01_001DD190.lo, D_L01_001DD190.hi) * 5 + 2) / 6;
        color = func_0038DBD8(D_L01_001DD198.lo, D_L01_001DD198.hi, func_003824E0(0.0f, 1.0f));
        r = func_003824E0(radius.lo, radius.hi);
        vel.x = func_0038D098(angle) * r;
        vel.y = func_0038D0B0(angle) * r;
        vel.z = 0.0f;
        angle = func_0038DAB8(angle, func_003824E0(angleRange.lo, angleRange.hi));
        func_L01_0046C470(&pos, &vel, color, lifetime, func_00382468(255), 0, 64, 0, D_L01_001DD1A0.lo);
        func_0038CE20(&vel, &vel, 0.8f);
        func_L01_0046C470(&pos, &vel, color, lifetime, func_00382468(255), 0, 64, 0, D_L01_001DD1A0.hi);
    } while (i >= 0);
    }
}
/* localdecomp:end func_L01_00340FB0 */

INCLUDE_ASM("asm/levels", func_L01_003411A8);

/* localdecomp:start func_L01_003413D0 */
#include "vu0.h"
typedef struct { u8 pad[0x10]; u8 *objects[4]; s32 flags[4]; s32 states[4]; } Vars_003413D0;
s32 func_L01_003413D0(u8 *self, vu0_q *pos, vu0_q *rot, u8 **list, s32 count) {
    extern u8 *func_003C24B0(s32, s32);
    extern s32 func_L01_0044E7D8(void *);
    extern void func_0038D5B0(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_003C4E80(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_003C48A8(void *, void *);
    extern void func_0038D308(void *, void *);
    vu0_q matrix[4];
    vu0_q delta[1];
    vu0_q transform[3];
    vu0_q angles;
    u8 *object = func_003C24B0(0x9BB, 0x80);
    Vars_003413D0 *vars;
    s32 i;
    if (object) {
    *(u8 **)(object + 0xB8) = self;
    object[0x30] = 0xFF;
    vars = *(Vars_003413D0 **)(object + 0x68);
    *(vu0_q *)(object + 0x10) = *pos;
    vars->objects[0] = self;
    vars->flags[0] = *(u16 *)(self + 0x34);
    vars->states[0] = func_L01_0044E7D8(self);
    func_0038D5B0(matrix, self + 0xC0);
    for (i = 0; i < count && i < 3; i++) {
        if (list[i]) {
            vars->objects[i + 1] = list[i];
            vars->flags[i + 1] = *(u16 *)(list[i] + 0x34);
            vars->states[i + 1] = func_L01_0044E7D8(list[i]);
            vec_sub_ba(&delta, list[i] + 0x10, self + 0x10);
            func_0038D000(&delta, &delta, matrix);
            func_003C4E80(&delta, (u8 *)vars + 0x40 + (i << 2));
            func_0038D5F0(transform, matrix, list[i] + 0xC0);
            func_003C48A8(transform, &angles);
            func_003C4E80(&angles, (u8 *)vars + 0x4C + (i << 2));
            *(u16 *)(list[i] + 0x34) |= 0x102;
            *(u16 *)(list[i] + 0x34) |= 1;
            list[i][0x31] = 0;
            *(s32 *)(list[i] + 0x98) = 0;
        }
    }
    *(vu0_q *)(self + 0x10) = *pos;
    *(vu0_q *)(self + 0xF0) = *rot;
    func_0038D308(self + 0xC0, self + 0xF0);
    *(s32 *)(self + 0x98) = 0;
    self[0x31] = 0;
    *(u16 *)(self + 0x34) |= 0x103;
    return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003413D0 */

INCLUDE_ASM("asm/levels", func_L01_003415F8);

INCLUDE_ASM("asm/levels", func_L01_00341910);

/* localdecomp:start func_L01_003424B0 */



extern s32 D_L01_001D6694;
extern s32 D_L01_001DD25C;
extern u8 D_001A4BE0[];
extern u8 D_001425D6[];
extern S_00341C10 D_L01_002C5600[];
extern f32 func_L01_004C93D8_003424B0(void);
extern s32 func_L01_00343850(f32 t);
extern void func_003C2F58(s32 a, s32 b, void *c);
extern void func_L01_00342640(u8 *self);
extern void func_L01_00342938(u8 *self);
extern void func_L01_00342D18(u8 *self);
extern void func_0038CE20(void *out, void *in, f32 s);
extern void func_0038CE90(void *out, void *a, void *b);
extern void func_0038CF68(void *out, void *in, f32 s);
extern void func_003D9740(void *v, s32 a, s32 b, s32 c, s32 d, f32 e);

void func_L01_003424B0(u8 *self) {
    V_00341C10 arr[4];
    V_00341C10 tmp;
    u8 *v;
    u8 *base;
    f32 t;

    if (D_L01_001D6694 != 0) {
        return;
    }
    v = *(u8 **)(self + 104);
    if (func_L01_00343850(func_L01_004C93D8_003424B0()) == 0) {
        return;
    }
    if (D_L01_001DD25C == 40) {
        return;
    }
    base = D_001A4BE0;
    func_003C2F58(*(s32 *)(base + 9664), 10, v + 48);
    func_L01_00342640(self);
    func_L01_00342938(self);
    func_L01_00342D18(self);
    if ((D_001425D6[0] + D_L01_002C5600)->b < 2) {
        return;
    }
    t = *(f32 *)(v + 64) + 0.1f;
    *(f32 *)(v + 64) = t;
    if (7.0f <= t) {
        *(f32 *)(v + 64) = t - 7.0f;
    }
    arr[3].q = *(s128_00341C10 *)(v + 48);
    arr[3].f[3] = 1.0f;
    arr[0].q = *(s128_00341C10 *)(*(u8 **)(base + 9664) + 192);
    func_0038CE20(&tmp, base + 736, -1.0f);
    func_0038CE90(&arr[1], &arr[0], &tmp);
    func_0038CF68(&arr[1], &arr[1], 1.0f);
    func_0038CE90(&arr[2], &arr[1], &arr[0]);
    func_003D9740(arr, 23, *(s32 *)(v + 8) | 0x1F000000, 10, 1, *(f32 *)(v + 64));
}
/* localdecomp:end func_L01_003424B0 */

INCLUDE_ASM("asm/levels", func_L01_00342640);

INCLUDE_ASM("asm/levels", func_L01_00342938);

/* localdecomp:start func_L01_00342D18 */
#include "vu0.h"
typedef struct { u8 b0, b1, b2, b3; u32 color; u32 pad8; f32 size; } Particle_00342D18;
typedef struct { u8 pad[0xF8]; u8 *data; } Table_00342D18;
extern u8 D_001425D6[];
extern S_00341C10 D_L01_002C5600[];
extern s32 D_L01_001E1940[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_00278F80[][20];
extern vu0_v4 D_L01_001E1900[] __attribute__((section(".sdata")));
extern Table_00342D18 D_L01_00221098;
__asm__(".extern D_L01_001DD260, 4");
__asm__(".extern D_L01_001DD264, 4");
__asm__(".extern D_L01_001DD268, 4");
__asm__(".extern D_L01_001DD26C, 4");
__asm__(".extern D_L01_001DD270, 4");
__asm__(".extern D_L01_001DD274, 4");
extern f32 D_L01_001DD260;
extern u32 D_L01_001DD264;
extern u32 D_L01_001DD268;
extern u32 D_L01_001DD26C;
extern f32 D_L01_001DD270;
extern f32 D_L01_001DD274;
void func_L01_00342D18(u8 *self) {
    extern void func_003C4840(f32, void *, void *);
    extern void func_0038D850(void *, void *, void *);
    extern void func_003C4C18(void *, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern Particle_00342D18 *func_L01_0046CA28(void *, s32, s32, s32);
    extern void func_L01_003430E8(void *, s32, s32, s32, u32, u32, u32, u32, s32, s32, s32, f32, f32, f32);
    vu0_v4 points[20];
    vu0_v4 position;
    vu0_v4 rotation;
    u8 *vars = *(u8 **)(self + 0x68);
    s32 type = 44;
    f32 angle = 6.0f;
    s32 level = (D_001425D6[0] + D_L01_002C5600)->b;
    s32 i, j, n, next;
    f32 length;
    vu0_v4 *last;
    Particle_00342D18 *particle;
    *(vu0_q *)&position = *(vu0_q *)(vars + 0x30);
    if (level >= 4) angle = 10.0f;
    if (level == 2 || level == 3) type = 15;
    else if (level >= 4) type = 48;
    for (i = 0; i < 4; i++) {
        D_L01_001E1940[i]++;
        if (D_L01_001E1940[i] >= 20) D_L01_001E1940[i] = 20;
        n = D_L01_001E1940[i] - 1;
        for (j = n; j > 0; j--) {
            *(vu0_q *)&D_L01_00278F80[i][j] = *(vu0_q *)&D_L01_00278F80[i][j - 1];
            vec_add_ab(&points[n - j], &position, &D_L01_00278F80[i][j]);
            points[n - j].w = 0.05f;
        }
        func_003C4840(angle * 0.017453292f, &rotation, (void *)((i << 4) + (s32)D_L01_001E1900));
        func_0038D850(&D_L01_00278F80[i][0], &D_L01_00278F80[i][0], &rotation);
        func_003C4C18(&D_L01_00278F80[i][0], 0.025f);
        length = func_0038CEA8(&D_L01_00278F80[i][0]);
        if (length > D_L01_001DD260 * 1.1f) {
            func_0038CE20(&D_L01_00278F80[i][0], &D_L01_00278F80[i][0], D_L01_001DD260 * 1.1f / length);
        } else if (length < D_L01_001DD260 * 0.9f) {
            func_0038CE20(&D_L01_00278F80[i][0], &D_L01_00278F80[i][0], D_L01_001DD260 * 0.9f / length);
        }
        vec_add_ab(&points[n], &position, &D_L01_00278F80[i][0]);
        points[n].w = 0.05f;
        {
        s32 tail = *(s32 *)((i << 2) + (s32)D_L01_001E1940) - 1;
        last = points + tail;
        }
        particle = func_L01_0046CA28(last, 2, 0, 1);
        {
        if (particle) {
            particle->color = D_L01_001DD264 | *(u32 *)(vars + 8);
            particle->size = D_L01_001DD270 * 210000.0f;
            particle->b2 = D_L01_00221098.data[1];
        }
        }
        particle = func_L01_0046CA28(last, 2, 0, 1);
        {
        if (particle) {
            particle->color = 0x407F7F7F;
            particle->size = D_L01_001DD270 * 0.15f * 210000.0f;
        }
        }
        func_L01_003430E8(points, 20, type, type, D_L01_001DD268, D_L01_001DD268 & 0xFFFFFF, D_L01_001DD26C | *(u32 *)(vars + 8), D_L01_001DD26C, 0, *(s32 *)((i << 2) + (s32)D_L01_001E1940) - 1, *(s32 *)((i << 2) + (s32)D_L01_001E1940), 0.02f, 0.07f, D_L01_001DD274);
    }
}
/* localdecomp:end func_L01_00342D18 */

INCLUDE_ASM("asm/levels", func_L01_003430E8);

/* localdecomp:start func_L01_00343650 */
extern s32 D_L01_001DD298;

void func_L01_00343650(void) { D_L01_001DD298 = 0; }
/* localdecomp:end func_L01_00343650 */

/* localdecomp:start func_L01_00343658 */
typedef int s128_00343658 __attribute__((mode(TI)));

extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern void func_00382760(f32 *out, f32 length, f32 a, f32 b);
extern f32 func_L01_00443A18(f32, f32);
/* The floats are declared among the ints (the registers are the same under EABI: ints and floats
   count separately) because gcc emits the argument moves in prototype order, and retail sets $f13
   before $a2 and $f14 before $t2. */
extern u8 *func_L01_0046B458(f32 *pos, s32 life, f32 size_end, f32 size, s32 colour, s32 roll,
                             s32 spin, f32 *velocity, f32 z, s32 n);

/* shield_zap_sparkles: the Shield Charger's zap at the point on the shell toward the enemy:
   eight pairs of 0x35 sparkles, each pair from one f = rand(1, 6): half f shrinking to 0.1 f
   in the shield's colour, and 0.4 f to 0.04 f in grey 0x7F, spinning opposite ways; both
   jittered +-0.1, 0.5-6 u/s any way, life 17 (20 at 60 Hz), render byte +9 0x74. */
void func_L01_00343658(s128_00343658 *at, s32 colour)
{
    f32 velocity[4];
    f32 pos[4];
    s32 i;
    s32 spin;
    f32 f;
    f32 speed;
    f32 a;
    u8 *sparkle;

    for (i = 0; i < 8; i++) {
        f = func_003824E0(1.0f, 6.0f);
        spin = func_00382468(2);
        /* 1 or -1 */
        if (spin == 0) {
            spin--;
        }
        speed = func_003824E0(0.5f, 6.0f) * 0.020000001f;
        a = func_00382538();
        func_00382760(velocity, speed, a, func_00382538());
        *(s128_00343658 *)pos = *at;
        pos[0] += func_L01_00443A18(0.0f, 0.1f);
        pos[1] += func_L01_00443A18(0.0f, 0.1f);
        pos[2] += func_L01_00443A18(0.0f, 0.1f);
        sparkle = func_L01_0046B458(pos, 17, f * 0.1f, f, colour | 0x7F000000, 0, spin, velocity, 0.0f, 1);
        if (sparkle != 0) {
            sparkle[9] = 0x74;
        }
        sparkle = func_L01_0046B458(pos, 17, f * 0.04f, f * 0.4f, 0x7F7F7F7F, 1, -spin, velocity, 0.0f, 1);
        if (sparkle != 0) {
            sparkle[9] = 0x74;
        }
    }
}
/* localdecomp:end func_L01_00343658 */

/* localdecomp:start func_L01_00343850 */
extern u8 D_001A4BE0[];

/* shield_holds: whether the shield stays up: it has points left, and the hero's moby is of
   class 0, he isn't in critter mode, in the vehicle state or of state type 0x14, and has
   health. */
s32 func_L01_00343850(f32 points)
{
    u8 *hero;

    if (points <= 0.0f
        /* his moby's class (hero + 0x25C0, moby + 0xAA) */
        || (hero = D_001A4BE0, *(s16 *)(*(u8 **)(hero + 0x25C0) + 0xAA) != 0)
        || hero[0x25E4] != 0                     /* critter mode */
        || *(s32 *)(hero + 0x25C4) == 0x31       /* state 49: the vehicle */
        || *(s32 *)(hero + 0x25CC) == 0x14       /* state type 0x14 */
        || *(s32 *)(hero + 0x2850) <= 0) {       /* no health */
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00343850 */

/* localdecomp:start func_L01_003438C0 */
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
void func_L01_003438C0(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    s32 i = *(s32 *)(s0 + 12);
    if (i != -1) {
        u8 *e = D_001A30B0 + (i << 7);
        if (*(u8 **)(e + 220) == a0 && e[208] != 0) {
            func_003A4F28(i);
        }
    }
    *(s32 *)(s0 + 12) = -1;
}
/* localdecomp:end func_L01_003438C0 */

/* localdecomp:start func_L01_00343928 */
extern u8 *D_001D52FC;
extern s32 D_L01_00278BB0[];
extern void func_L01_004C7438(void *out, void *in, s32 a, s32 b, f32 c, f32 d, f32 e, f32 f);
extern s32 func_L01_004C7A18(f32 h, void *a, void *b, void *c, void *d, void *e, s32 f, s32 g);
extern s32 func_0038CAD0(void *);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L01_005118D0(s32, s32);
extern s32 func_L01_005119E0(s32);
extern void func_L01_004EA7D8(s32);
extern void func_L01_004EAA80(void);
extern void func_L01_0032F8E8(void *, void *, void *);
extern void func_L01_00343BA0(u8 *);
extern void func_L01_00404A10_00343928(void (*)(u8 *), u8 *);

void func_L01_00343928(u8 *owner) {
    f32 origin[4];
    f32 target[4];
    u8 *context = *(u8 **)(owner + 0x68);
    s32 allowed;
    u8 *base;
    u8 *base2;

    func_003C2F58((s32)owner, 0, origin);
    func_L01_004C7438(target,origin, 0, 0, 1.5f, 11.0f, 0.3f, 0.0044f);
    allowed = 1;
    *(s32 *)(context + 0x24) = func_L01_004C7A18(0.0044f, origin, target, context, context + 0x10, owner, 0, 0);

    base = D_001A4BE0;
    if (*(s32 *)(base +0x25C4) == 29) {
        if (!func_0038CAD0(base +0x28BC))
            allowed = 0;
    } else {
        *(s32 *)(base +0x28BC) = 33;
    }

    switch (owner[0x20]) {
    case 0:
        owner[0x20] = 1;
        *(s32 *)(context + 0x24) = 0;
        /* Fall through. */
    case 1:
        base2 = D_001A4BE0;
        if ((*(s32 *)(D_001D52FC + 0x1A4) & *(s32 *)(base2 + 0x1210)) && !base2[0x25ED] && allowed && D_L01_00278BB0[0] < 6) {
            if (func_L01_005118D0(-1, 1)) {
                func_L01_004EA7D8(-1);
                owner[0x20] = 2;
                *(s32 *)(context + 0x20) = 17;
            } else {
                func_003A52A0(2, 0, owner);
            }
        } else if (!(func_L01_005119E0(-1) && D_L01_00278BB0[0] < 7)) {
            u8 *base3 = D_001A4BE0;
            if (*(s32 *)(D_001D52FC + 0x1A4) & *(s32 *)(base3 + 0x1210)) {
                func_003A52A0(2, 0, owner);
            }
        }
        break;
    case 2:
        if (func_0038CAD0(context + 0x20)) {
            func_003A52A0(0, 0, owner);
            func_L01_0032F8E8(owner, origin, target);
            func_L01_004EAA80();
            owner[0x20] = 3;
            *(s32 *)(context + 0x20) = 8;
        }
        break;
    case 3:
        if (func_0038CAD0(context + 0x20))
            owner[0x20] = 1;
        break;
    }
    func_L01_00404A10_00343928(func_L01_00343BA0, owner);
}
/* localdecomp:end func_L01_00343928 */

/* localdecomp:start func_L01_00343BA0 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_00343BA0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_00343BA0 */

INCLUDE_ASM("asm/levels", func_L01_00343BD8);

/* localdecomp:start func_L01_00344A40 */
void func_L01_00344A40(u8 *a) {
    a[32] = 2;
}
/* localdecomp:end func_L01_00344A40 */

LINKER_REMNANT("asm/levels", func_L01_00344A50);

/* localdecomp:start func_L01_00344A58 */
typedef struct {
    u8 pad0[0x48];
    s32 w48;
    s32 pad4C;
} E_00344A58;

extern E_00344A58 D_L01_002797C0[];

void func_L01_00344A58(void) {
    s32 i;
    for (i = 299; i >= 0; i--) {
        D_L01_002797C0[i].w48 = 0;
    }
}
/* localdecomp:end func_L01_00344A58 */

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
extern void func_L01_003411A8(void);
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

INCLUDE_ASM("asm/levels", func_L01_00340FB0);

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

INCLUDE_ASM("asm/levels", func_L01_00343658);

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

INCLUDE_ASM("asm/levels", func_L01_00344A88);

LINKER_REMNANT("asm/levels", func_L01_00344C70);

/* localdecomp:start func_L01_00344C78 */
extern void func_L01_00344CA8(char *);

/* from rac2-decomp's func_L00_003CA650, renamed */
void func_L01_00344C78(char *object)
{
    if (*(unsigned char *)(object + 0x20) == 1)
        func_L01_00344CA8(object);
}
/* localdecomp:end func_L01_00344C78 */

/* localdecomp:start func_L01_00344CA8 */
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00409B08(u8 *a0, s32 a1, s32 a2);
extern void func_L01_00409E70(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);

void func_L01_00344CA8(char *obj) {
    vu0_v4 v;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 color;

    *(vu0_q *)&v = 0;
    v.x = -0.3f;
    v.w = 1.0f;
    func_0038D000(&v, &v, obj + 0xC0);
    vec_add_ba(&v, &v, obj + 0x10);
    color = vars[0x81] != 0 ? 0x803010 : 0x103080;
    func_L01_00409B08((u8 *)&v, color, 0);
    func_L01_00409E70((u8 *)&v, vars + 0x10, color, 4, *(f32 *)(vars + 0x64), 0.25f);
}
/* localdecomp:end func_L01_00344CA8 */

INCLUDE_ASM("asm/levels", func_L01_00344D68);

INCLUDE_ASM("asm/levels", func_L01_00345C08);

/* localdecomp:start func_L01_00346620 */
extern void func_003C2F58(s32 a, s32 b, void *c);
extern void func_L01_00346668(f32 *, f32, f32, f32, f32);

void func_L01_00346620(s32 a) {
    f32 v[4];
    ((void (*)(s32, s32, f32 *))func_003C2F58)(a, 1, v);
    func_L01_00346668(v, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_00346620 */

/* localdecomp:start func_L01_00346668 */
__asm__(".extern D_L01_001DD2C0, 4");
__asm__(".extern D_L01_001DD2C4, 4");
__asm__(".extern D_L01_001DD2C8, 4");
__asm__(".extern D_L01_001DD2CC, 4");
__asm__(".extern D_L01_001DD2D0, 4");
__asm__(".extern D_L01_001DD2D4, 4");
__asm__(".extern D_L01_001DD2D8, 4");
__asm__(".extern D_L01_001DD2DC, 4");
__asm__(".extern D_L01_001DD2E0, 4");
__asm__(".extern D_L01_001DD2E4, 4");
__asm__(".extern D_L01_001DD2E8, 4");
__asm__(".extern D_L01_001DD2EC, 4");
__asm__(".extern D_L01_001DD2F0, 4");
__asm__(".extern D_L01_001DD2F4, 4");
__asm__(".extern D_L01_001DD2F8, 4");
__asm__(".extern D_L01_001DD2FC, 4");
__asm__(".extern D_L01_001DD300, 4");
__asm__(".extern D_L01_001DD304, 4");
extern s32 D_L01_001DD2C0;
extern s32 D_L01_001DD2C4;
extern s32 D_L01_001DD2C8;
extern s32 D_L01_001DD2CC;
extern s32 D_L01_001DD2D0;
extern s32 D_L01_001DD2D4;
extern s32 D_L01_001DD2D8;
extern s32 D_L01_001DD2DC;
extern s32 D_L01_001DD2E0;
extern s32 D_L01_001DD2E4;
extern s32 D_L01_001DD2E8;
extern s32 D_L01_001DD2EC;
extern s32 D_L01_001DD2F0;
extern s32 D_L01_001DD2F4;
extern s32 D_L01_001DD2F8;
extern s32 D_L01_001DD2FC;
extern s32 D_L01_001DD300;
extern s32 D_L01_001DD304;
extern s32 D_L39_00240300;
extern s32 D_L39_00240304;
extern s32 D_L39_002413A0;
extern void func_L01_004C5E28(void);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038B4D0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, long c, long d);

/* flux_scope_draw: the Flux Rifle's scope over the screen: texture 0x46 as four mirrored
   quarter-screen quads into the frame's alpha, the shading quarter in its texture, then the
   frame drawn over the whole screen where that alpha allows (the lens). */
void func_L01_00346668(f32 *v, f32 x, f32 y, f32 z, f32 w)
{
    s32 width;
    s32 height;
    long tex;

    func_L01_004C5E28();
    height = D_L39_00240304;
    width = D_L39_00240300;
    /* drawn into a frame of its own: its size */
    if (D_L39_002413A0 != 0) {
        D_L01_001DD304 = -1;
        D_L01_001DD2F4 = 0xEC;
        D_L01_001DD2F8 = 0xF0;
        width = D_L01_001DD2FC;
        height = D_L01_001DD300;
    }
    func_003A9440(0x47, 0x513F1);
    /* the scope's top-left quarter, mirrored into each quarter */
    func_0038B4D0(0, 0, (s32)(width * 0.5f), (s32)(height * 0.5f), 0, 0, 0x7F, 0x7F, 0x50101010,
                  func_00389598(0x46));
    func_0038B4D0(width, 0, -(s32)(width * 0.5f), (s32)(height * 0.5f), 0, 0, 0x7F, 0x7F, 0x50101010,
                  func_00389598(0x46));
    func_0038B4D0(0, height, (s32)(width * 0.5f), -(s32)(height * 0.5f), 0, 0, 0x7F, 0x7F, 0x50101010,
                  func_00389598(0x46));
    func_0038B4D0(width, height, -(s32)(width * 0.5f), -(s32)(height * 0.5f), 0, 0, 0x7F, 0x7F,
                  0x50101010, func_00389598(0x46));
    /* the shading quarter, the same way */
    func_003A9440(0x42, (long)D_L01_001DD2CC | ((long)D_L01_001DD2D0 << 2) | ((long)D_L01_001DD2D4 << 4)
                  | ((long)D_L01_001DD2D8 << 6) | (0x80L << 32));
    tex = func_00389598(D_L01_001DD2C0);
    func_0038B4D0(0, 0, (s32)(width * 0.5f), (s32)(height * 0.5f), 0, 0, 0xFF, 0xFF, D_L01_001DD2C4,
                  tex);
    func_0038B4D0(width, 0, -(s32)(width * 0.5f), (s32)(height * 0.5f), 0, 0, 0xFF, 0xFF,
                  D_L01_001DD2C4, tex);
    func_0038B4D0(0, height, (s32)(width * 0.5f), -(s32)(height * 0.5f), 0, 0, 0xFF, 0xFF,
                  D_L01_001DD2C4, tex);
    func_0038B4D0(width, height, -(s32)(width * 0.5f), -(s32)(height * 0.5f), 0, 0, 0xFF, 0xFF,
                  D_L01_001DD2C4, tex);
    /* the frame over the whole screen where the alpha allows: the lens */
    func_003A9440(0x42, (long)D_L01_001DD2DC | ((long)D_L01_001DD2E0 << 2) | ((long)D_L01_001DD2E4 << 4)
                  | ((long)D_L01_001DD2E8 << 6) | (0x80L << 32));
    func_0038B4D0(0, 0, width, height, D_L01_001DD2EC, D_L01_001DD2F0, D_L01_001DD2F4, D_L01_001DD2F8,
                  D_L01_001DD2C8, func_00389598(D_L01_001DD304));
}
/* localdecomp:end func_L01_00346668 */

/* localdecomp:start func_L01_00346998 */
extern u8 D_001A4BE0[];
extern u8 *D_001D52FC;
extern void func_L01_004C7438(void *a, void *b, s32 i, s32 j, f32 f0, f32 f1, f32 f2, f32 f3);
extern s32 func_0038CAD0(void *p);
extern s32 func_L01_005118D0(s32 i, s32 n);
extern s32 func_L01_005119E0(s32 i);
extern void func_L01_004EA7D8(s32 i);
extern void func_L01_004EAA80(void);
extern void func_003A52A0(s32, s32, void *);
extern u8 *func_L01_0032C7A0(void *a, void *b);
extern void func_L01_00346C18(u8 *self);
extern void func_L01_00404A10_00346998(void *, u8 *);

void func_L01_00346998(u8 *self) {
    u8 a[16];
    u8 b[16];
    u8 *st = *(u8 **)(self + 0x68);
    s32 ready;
    u8 *shot;

    func_003C2F58((s32)self, 0, a);
    func_L01_004C7438(b, a, 0, 0, 1.5f, 11.0f, 0.3f, 0.0044f);
    *(s32 *)(st + 0x24) = func_L01_004C7A18(0.0044f, a, b, st, st + 0x10, self, 0, (s32)(st + 0x2C));
    ready = 1;
    if ((*(G_00346998 *)&D_001A4BE0).f25C4 == 29) {
        if (!func_0038CAD0(&(*(G_00346998 *)&D_001A4BE0).f28BC)) ready = 0;
    } else {
        (*(G_00346998 *)&D_001A4BE0).f28BC = 33;
    }
    switch (self[0x20]) {
    case 0:
        self[0x20] = 1;
        *(s32 *)(st + 0x28) = 1;
        *(s32 *)(st + 0x24) = 0;
    case 1:
        if ((*(s32 *)(D_001D52FC + 0x1A4) & (*(G_00346998 *)&D_001A4BE0).f1210) &&
            !(*(G_00346998 *)&D_001A4BE0).b25ED && ready && *(s32 *)(st + 0x28) != 0) {
            if (func_L01_005118D0(-1, 1)) {
                func_L01_004EA7D8(-1);
                self[0x20] = 2;
                *(s32 *)(st + 0x20) = 17;
            } else {
                func_003A52A0(2, 0, self);
            }
        } else if (!func_L01_005119E0(-1) &&
                   (*(s32 *)(D_001D52FC + 0x1A4) & (*(G_00346998 *)&D_001A4BE0).f1210)) {
            func_003A52A0(2, 0, self);
        }
        break;
    case 2:
        if (func_0038CAD0(st + 0x20) || (*(G_00346998 *)&D_001A4BE0).f170 > 0.0f) {
            func_003A52A0(0, 0, self);
            shot = func_L01_0032C7A0(a, b);
            *(u8 **)(shot + 0xB8) = self;
            func_L01_004EAA80();
            self[0x20] = 3;
            *(s32 *)(st + 0x20) = 8;
        }
        break;
    case 3:
        if (func_0038CAD0(st + 0x20)) self[0x20] = 1;
        break;
    }
    func_L01_00404A10_00346998(func_L01_00346C18, self);
}
/* localdecomp:end func_L01_00346998 */

/* localdecomp:start func_L01_00346C18 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);

extern s32 func_L01_004CB018(s32);
extern s32 func_L01_004CB2D8(void);
extern s32 D_L01_00277080[];

void func_L01_00346C18(u8 *self) {
    Vars3462F0 *v = *(Vars3462F0 **)(self + 104);

    if (v->target != 0) {
        if ((u32)(func_L01_004CB018(v->target) - 1) < 2) {
            v->visible = 0;
        } else if (v->active == 0 || (D_L01_00277080[0] >= 9 && func_L01_004CB2D8() == 0)) {
            v->visible = 0;
        } else {
            v->visible = 1;
        }
    }
    if (v->active != 0 && v->visible != 0) {
        ((void (*)(void *, void *, s32, s32, f32))func_L01_004C70A8)(v, v->pos, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_00346C18 */

INCLUDE_ASM("asm/levels", func_L01_00346CC8);

/* localdecomp:start func_L01_00347348 */
#include "vu0.h"
extern u8 D_0014262F[];
void func_L01_00347348(u8 *self) {
    extern s32 func_L01_00457458(s32, s32);
    extern void func_L01_00348168(Obj *obj);
    extern void func_L01_00348258(u8 *shot, s128_00341C10 *pos);
    extern void func_L01_003493C8(u8 *, void *);
    extern s32 func_L01_003476D8(u8 *, void *);
    extern void func_0038CDF8(void *, void *, void *, f32);
    vu0_v4 previous;
    vu0_v4 point;
    u8 *vars = *(u8 **)(self + 0x68);
    s32 level = (D_0014262F[0] + D_L01_002C5600)->b;
    s32 i;
    f32 upper;
    if (!func_L01_00457458(0xC04, *(s16 *)(vars + 0x1A))) {
        func_003C2880((Obj *)self);
        return;
    }
    if (self[0x20] == 2) {
        func_L01_004CAB30(self + 0x10, self + 0x10);
        func_L01_00348168((Obj *)self);
        return;
    }
    if (*(s32 *)(vars + 0x28) == 1) {
        *(vu0_q *)&previous = *(vu0_q *)(vars + 0x40);
    } else {
        *(vu0_q *)&previous = *(vu0_q *)(self + 0x10);
    }
    vec_add_ab(self + 0x10, self + 0x10, vars);
    if (*(s32 *)(vars + 0x28) == 1) vec_add_ab(vars + 0x40, vars + 0x40, vars + 0x30);
    if (self[0x20] == 0) self[0x20] = 1;
    for (i = 0; i < 4; i++) {
        func_0038CDF8(&point, &previous, self + 0x10, i * 0.25f);
        func_L01_00348258(self, (s128_00341C10 *)&point);
    }
    if (level >= 2) {
        func_L01_003493C8(self, self + 0x10);
        func_0038CDF8(&point, &previous, self + 0x10, 0.5f);
        func_L01_003493C8(self, &point);
    }
    if (*(f32 *)(self + 0x10) < 2.0f || *(f32 *)(self + 0x10) > 1021.0f ||
        *(f32 *)(self + 0x14) < 2.0f || *(f32 *)(self + 0x14) > 1021.0f ||
        *(f32 *)(self + 0x18) < 2.0f || *(f32 *)(self + 0x18) > 1021.0f) {
        if (*(f32 *)(self + 0x10) < 5.0f) *(f32 *)(self + 0x10) = 5.0f;
        if (*(f32 *)(self + 0x14) < 5.0f) *(f32 *)(self + 0x14) = 5.0f;
        if (*(f32 *)(self + 0x18) < 5.0f) *(f32 *)(self + 0x18) = 5.0f;
        upper = 1016.0f;
        if (upper < *(f32 *)(self + 0x10)) *(f32 *)(self + 0x10) = upper;
        if (upper < *(f32 *)(self + 0x14)) *(f32 *)(self + 0x14) = upper;
        if (upper < *(f32 *)(self + 0x18)) *(f32 *)(self + 0x18) = upper;
        self[0x20] = 2;
    } else if (func_L01_003476D8(self, &previous) || func_0038CAD0(vars + 0x10)) {
        self[0x20] = 2;
    } else {
        func_L01_00348168((Obj *)self);
    }
}
/* localdecomp:end func_L01_00347348 */

/* localdecomp:start func_L01_00347640 */
extern void func_0038CF68(void *out, void *in, f32 s);
extern void func_0038CE90(void *dst, void *a, void *b);
void func_L01_00347640(u8 *a0, void *a1) {
    f32 one = 1.0f;
    ((void (*)(f32 s, void *dst, void *src))func_0038CF68)(one, a0 + 192, *(void **)(a0 + 104));
    func_0038CE90(a0 + 208, a0 + 192, a1);
    ((void (*)(f32 s, void *dst, void *src))func_0038CF68)(one, a0 + 208, a0 + 208);
    func_0038CE90(a0 + 224, a0 + 208, a0 + 192);
}
/* localdecomp:end func_L01_00347640 */

/* localdecomp:start func_L01_003476D8 */
typedef struct {
    vu0_v4 dir;
    void *owner;
    s32 flags;
    u8 b18, b19;
    u16 classid;
    f32 radius;
    s32 mode;
} Ray_003476D8;
typedef struct { u8 pad[0x6C]; f32 radius; u8 rest[0x80]; } Row_003476D8;
extern u8 D_0014262F[];
extern vu0_v4 D_L01_001EAA20[];
extern s32 D_001A71A0[];
s32 func_L01_003476D8(u8 *m, vu0_v4 *dest) {
    extern void func_0038CF68(void *out, void *in, f32 s);
    extern s32 func_003D3CB0(void *, void *, s32, s32, void *);
    extern void func_L01_00347838(u8 *, void *);
    extern s32 func_L01_00446720(void *);
    Ray_003476D8 ray;
    vu0_v4 pos, delta;
    vu0_v4 *hit;
    u8 *vars = *(u8 **)(m + 0x68);
    ray.owner = m;
    ray.flags = 0x10000;
    ray.radius = ((Row_003476D8 *)D_L01_002C5600)[D_0014262F[0]].radius;
    ray.mode = 1;
    *(vu0_q *)&ray.dir = *(vu0_q *)vars;
    func_0038CF68(&ray, &ray, 1.0f);
    ray.dir.w = 5627.925f;
    ray.classid = *(u16 *)(m + 0xAA);
    ray.b18 = 1;
    ray.b19 = 1;
    if (*(s32 *)(vars + 0x28) == 1) *(vu0_q *)&pos = *(vu0_q *)(vars + 0x40);
    else *(vu0_q *)&pos = *(vu0_q *)(m + 0x10);
    if (!func_003D3CB0(dest, &pos, 0, D_001A71A0[0], &ray)) return 0;
    vec_sub_ba(&delta, dest, &pos);
    func_0038CF68(&delta, &delta, 0.25f);
    hit = D_L01_001EAA20;
    vec_add_ab(&delta, &delta, hit);
    func_L01_00347838(m, &delta);
    if (*(void **)((u8 *)hit - 8) == 0 || func_L01_00446720(*(void **)((u8 *)hit - 8))) return 1;
    return 0;
}
/* localdecomp:end func_L01_003476D8 */

INCLUDE_ASM("asm/levels", func_L01_00347838);

/* localdecomp:start func_L01_00348160 */
void func_L01_00348160(void) {

}
/* localdecomp:end func_L01_00348160 */

/* localdecomp:start func_L01_00348168 */
extern void func_L01_003481F8(O_347888 *o);

extern int func_L01_00348500(Obj *);
extern int func_L01_00348C88(Obj *);
extern int func_L01_00349538(Obj *);
extern void func_L01_00404A10_00348168(void (*)(void), Obj *);

void func_L01_00348168(Obj *obj) {
    int a = func_L01_00348500(obj);
    int b = func_L01_00348C88(obj);
    int c = func_L01_00349538(obj);

    if (a == 0 && b == 0 && c == 0) {
        if (obj->b32 == 2) {
            func_003C2880(obj);
        }
    } else {
        func_L01_00404A10_00348168(((void (*)(void))func_L01_003481F8), obj);
    }
}
/* localdecomp:end func_L01_00348168 */

/* localdecomp:start func_L01_003481F8 */
extern s32 func_L01_00457458(s32, s32);
extern void func_L01_00348620(O_347888 *);
extern void func_L01_00348E30(O_347888 *);
extern void func_L01_003495F0(O_347888 *);
void func_L01_003481F8(O_347888 *o) {
    if (func_L01_00457458(3076, o->x68->x1A) == 0) {
        ((void (*)(O_347888 *))func_003C2880)(o);
    } else {
        func_L01_00348620(o);
        func_L01_00348E30(o);
        func_L01_003495F0(o);
    }
}
/* localdecomp:end func_L01_003481F8 */

/* localdecomp:start func_L01_00348258 */
typedef int s128_00348258 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    f32 angle;  /* 0x20 */
    f32 width;  /* 0x24 */
    f32 spin;   /* 0x28 */
    f32 drift;  /* 0x2C */
} TrailPoint_00348258;
typedef struct {
    u8 pad0[0x18];
    s16 trail;  /* 0x18: its slot in the trail list */
    s16 id;     /* 0x1A */
    u8 pad1C[4];
    s16 points; /* 0x20: points laid so far */
} FluxVars_00348258;

__asm__(".extern D_L01_001DD314, 4");
__asm__(".extern D_L01_001DD318, 4");
__asm__(".extern D_L01_001DD31C, 4");
__asm__(".extern D_L01_001DD320, 4");
__asm__(".extern D_L01_001DD324, 4");
__asm__(".extern D_L01_001DD328, 4");
extern f32 D_L01_001DD314;
extern f32 D_L01_001DD318;
extern f32 D_L01_001DD31C;
extern f32 D_L01_001DD320;
extern f32 D_L01_001DD324;
extern f32 D_L01_001DD328;
extern char *func_L01_00457480(s32, s32);
extern f32 func_L01_0044AE78(f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00348380(TrailPoint_00348258 *points, s32 count);

/* flux_shot_trail: a per-step call of the Flux Rifle shot that lays its trail: the next
   point of its list at pos, its angle from n x 40 degrees (D_L01_001DD31C), a spin of 1 to
   1 degree (D_L01_001DD314, D_L01_001DD318), width 0.3 (D_L01_001DD320) and a drift of
   0.01-0.5 either way (D_L01_001DD324, D_L01_001DD328) x 0.02. */
void func_L01_00348258(u8 *shot, s128_00348258 *pos)
{
    FluxVars_00348258 *vars = *(FluxVars_00348258 **)(shot + 0x68);
    u32 lists;
    TrailPoint_00348258 **list;
    s32 n;

    if (vars == 0) {
        return;
    }
    lists = (u32)func_L01_00457480(0xC04, vars->id);
    if (lists == 0) {
        return;
    }
    n = vars->points;
    /* the shot's own list among them */
    list = (TrailPoint_00348258 **)(vars->trail * 4 + lists);
    *(s128_00348258 *)(*list)[n].pos = *pos;
    (*list)[n].angle = func_L01_0044AE78(n * (D_L01_001DD31C * 0.017453292f));
    (*list)[n].spin = func_003824E0(D_L01_001DD314, D_L01_001DD318) * 0.017453292f;
    (*list)[n].width = D_L01_001DD320;
    (*list)[n].drift = func_L01_00443A18(D_L01_001DD324, D_L01_001DD328) * 0.020000001f;
    func_L01_00348380(*list, n);
    vars->points++;
}
/* localdecomp:end func_L01_00348258 */

/* localdecomp:start func_L01_00348380 */
#include "vu0.h"
extern s32 D_L01_001D673C;
extern f32 D_L01_001DD310;
__asm__(".extern D_L01_001DD310, 4");
void func_L01_00348380(TrailPoint_00348258 *points, s32 count) {
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    vu0_v4 axis;
    vu0_v4 result;
    vu0_v4 delta;
    vu0_v4 rotation;
    f32 one = 1.0f;
    *(vu0_q *)&axis = 0;
    axis.z = one;
    if (D_L01_001D673C) func_003C5180(&axis, points[count].pos, 1);
    if ((f32)count == 0.0f || fabs_asm(points[count].angle) < 0.00001f) {
        func_0038CE20(&result, &axis, points[count].width);
    } else {
        vec_sub_ba(&delta, points[count].pos, points[count - 1].pos);
        func_0038CF68(&rotation, &delta, one);
        func_003C4840(&rotation, &rotation, points[count].angle);
        func_0038D850(&result, &axis, &rotation);
        func_0038CE20(&result, &result, points[count].width);
    }
    vec_add_ba(points[count].pad0, points[count].pos, &result);
    *(f32 *)(points[count].pad0 + 12) = D_L01_001DD310;
}
/* localdecomp:end func_L01_00348380 */

/* localdecomp:start func_L01_00348500 */
__asm__(".extern D_L01_001DD340, 4");
extern float D_L01_001DD340;
__asm__(".extern D_L01_001DD344, 4");
extern float D_L01_001DD344;

int func_L01_00348500(Obj *arg0)
{
    extern char *func_L01_00457480(int, int);
    extern float func_0038DAB8(float, float);
    extern void func_L01_00348380(TrailPoint_00348258 *, s32);
    extern int func_0038CB00(char *);
    char *moby = (char *)arg0;
    char *state;
    char *table;
    char *base;
    char *rec;
    int index;
    int count;
    int i = 0;
    float value;

    state = *(char **)(moby + 0x68);
    table = func_L01_00457480(0xC04, *(short *)(state + 0x1A));
    index = *(short *)(state + 0x18);
    base = *(char **)(table + index * 4);
    count = *(short *)(state + 0x20);
    if (count > 0) {
        rec = base;
        do {
            *(float *)(rec + 0x20) = func_0038DAB8(*(float *)(rec + 0x20), *(float *)(rec + 0x28));
            func_L01_00348380((TrailPoint_00348258 *)base, i);
            rec += 0x30;
            i++;
        } while (i < count);
    }
    value = D_L01_001DD340;
    if (value > 7.0f) {
        D_L01_001DD340 = 0.0f;
    } else if (value < -7.0f) {
        D_L01_001DD340 = 0.0f;
    }
    D_L01_001DD340 = D_L01_001DD340 - D_L01_001DD344;
    if (D_L01_001DD340 <= -4.0f) {
        D_L01_001DD340 = D_L01_001DD340 + 4.0f;
    }
    return func_0038CB00(state + 0x22) == 0;
}
/* localdecomp:end func_L01_00348500 */

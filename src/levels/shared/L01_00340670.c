#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L01_00340C48);

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

INCLUDE_ASM("asm/levels", func_L01_003413D0);

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

INCLUDE_ASM("asm/levels", func_L01_00342D18);

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

INCLUDE_ASM("asm/levels", func_L01_00344A58);

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

INCLUDE_ASM("asm/levels", func_L01_00344CA8);

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

INCLUDE_ASM("asm/levels", func_L01_00346668);

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

INCLUDE_ASM("asm/levels", func_L01_00347348);

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

INCLUDE_ASM("asm/levels", func_L01_003476D8);

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

INCLUDE_ASM("asm/levels", func_L01_00348380);

INCLUDE_ASM("asm/levels", func_L01_00348500);

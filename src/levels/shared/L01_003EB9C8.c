#include "common.h"

typedef struct { u8 pad[28]; u8 *p; } E_3EAB98;
typedef struct {
    u8 pad0[56];
    u8 f38;
    u8 f39;
    u8 pad3A[8];
    s8 f42;
    s8 f43;
} Info_003EBD50;
typedef struct {
    u8 pad0[28];
    Info_003EBD50 *info;
} Ent_003EBD50;
typedef struct {
    u8 pad0[124];
    u8 f7C;
    u8 pad7D;
    s16 f7E;
    u8 pad80[4];
    s16 f84;
    s16 f86;
} Obj_003EBD50;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[512];
    u8 b200[48];
    u128_t v230;
    u8 pad240[675 - 576];
    u8 b2A3;
    u8 pad2A4[696 - 676];
    f32 f2B8;
    u8 pad2BC[712 - 700];
    f32 f2C8;
    u8 pad2CC[1120 - 716];
} Ent003EC730;
typedef int u128_3EC828 __attribute__((mode(TI)));
typedef struct { u8 p0[0x200]; u8 b200[0x30]; u128_3EC828 q230; u8 pad[0x460 - 0x240]; } E_3EC828;
typedef struct { u8 p0[0x30]; u128_3EC828 q30; u8 p40[0x54]; s32 w94; } M_3EC828;
typedef int s128_003ED620 __attribute__((mode(TI)));
typedef struct {
    u8 pad[128];
} E_003ED620;
typedef struct {
    s32 f0;
    s32 f4;
} H_003ED620;
typedef struct {
    u8 pad[8];
    H_003ED620 *h;
} Obj_003ED620;
extern s128_003ED620 D_L01_001E29C0[];
extern E_003ED620 D_001A30B0[];
typedef struct { s32 x0; u8 pad4[0xC64 - 4]; s32 xC64; } G_3EF740;

typedef struct {
    u8 pad0[0x7D];
    u8 f7D;
    s16 f7E;
    u8 pad80[0x86 - 0x80];
    s16 f86;
    u8 pad88[0x94 - 0x88];
    s32 w94;
} Obj_003EC990;
typedef struct {
    u8 pad0[0xFC];
    s32 xFC;
    s32 x100;
} Sub_003EC990;

typedef struct {
    u8 b0, b1, b2, b3;
    s16 s4, s6, s8, s10, s12;
    u8 e, f;
} Rec_003F2058;
typedef struct {
    u8 pad[0x54C];
    u8 b54C;
    u8 pad54D[0x557 - 0x54D];
    u8 b557;
} Ctx_003F2058;
typedef struct {
    Rec_003F2058 r[8];
} Tab_003F2058;

INCLUDE_ASM("asm/levels", func_L01_003EB9C8);

INCLUDE_ASM("asm/levels", func_L01_003EBA68);

/* localdecomp:start func_L01_003EBED0 */
s32 func_L01_003EBED0(void) {
    return 0;
}
/* localdecomp:end func_L01_003EBED0 */

/* localdecomp:start func_L01_003EBED8 */
extern s32 D_001A4E18[];
extern void func_L01_003EBA68(u8 *a0);
extern void func_L01_003F6048(void *a0, u8 *a1, f32 f12);
void func_L01_003EBED8(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 112) + 224;
    D_001A4E18[0] = 2;
    func_L01_003EBA68(a0);
    if (*(s32 *)(s0 + 64) != 0) {
        a0[137] = 0;
        func_L01_003F6048(*(void **)(a0 + 148), a0 + 48, 0.5f);
    }
}
/* localdecomp:end func_L01_003EBED8 */

/* localdecomp:start func_L01_003EBF38 */
void func_L01_003EBF38(void) {

}
/* localdecomp:end func_L01_003EBF38 */

INCLUDE_ASM("asm/levels", func_L01_003EBF40);

INCLUDE_ASM("asm/levels", func_L01_003EC1A0);

INCLUDE_ASM("asm/levels", func_L01_003EC650);

/* localdecomp:start func_L01_003EC848 */
extern void func_L01_003EC650_003EC848(void *);
extern void func_L01_003EC848(void *);

extern void func_L01_003EC1A0_003EC848();
void func_L01_003EC848(void *p) {
    func_L01_003EC1A0_003EC848(p);
    func_L01_003EC650_003EC848(p);
}
/* localdecomp:end func_L01_003EC848 */

LINKER_REMNANT("asm/levels", func_L01_003EC878);

/* localdecomp:start func_L01_003EC898 */
s32 func_L01_003EC898(void) {
    return 0;
}
/* localdecomp:end func_L01_003EC898 */

INCLUDE_ASM("asm/levels", func_L01_003EC8A0);

/* localdecomp:start func_L01_003EC990 */
extern Ent003EC730 D_L01_001E2A40[];

void func_L01_003EC990(Obj_003EC990 *obj) {
    u8 *e = (u8 *)D_L01_001E2A40 + obj->w94 * 0x460;
    Sub_003EC990 *s = (Sub_003EC990 *)(e + 0x150);
    if (s->xFC != obj->f86 && s->x100 != 6) {
        obj->f7D = 0;
        obj->f7E = 3;
    }
}
/* localdecomp:end func_L01_003EC990 */

/* localdecomp:start func_L01_003EC9E0 */
extern char * D_L01_001DF804 __attribute__((section(".sdata")));
extern char *D_L01_001DF804 __attribute__((section(".sdata")));

/* from rac2-decomp's func_L00_00429020, renamed */
void func_L01_003EC9E0(int i) {
    unsigned char *q;
    q = *(unsigned char **)(D_L01_001DF804 + i * 0x20 + 0x1C);
    q[0x38] = 1;
    q[0x39] = 0;
}
/* localdecomp:end func_L01_003EC9E0 */

/* localdecomp:start func_L01_003ECA10 */
extern char *D_L01_001DF804;
int func_L01_003ECA10(int i) {
    unsigned char *p = *(unsigned char **)(D_L01_001DF804 + i * 32 + 28);
    int r = 0;
    if (p[68]) {
        r = p[57] != 0;
    }
    return r;
}
/* localdecomp:end func_L01_003ECA10 */

LINKER_REMNANT("asm/levels", func_L01_003ECA40);

/* localdecomp:start func_L01_003ECA48 */
extern char *D_L01_001DF804;
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_001A4C60[];
extern u8 *D_L01_0021F6C0[];
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_0044BFC8(void *, s32);
extern s32 func_L01_0044C078(void *, s32);
extern s32 func_L01_004463F8(void *, u8 *, s32);

s32 func_L01_003ECA48(u8 *m) {
    u8 *d = (*(E_3EAB98 * *)&D_L01_001DF804)[*(s16 *)(m + 0x84)].p;
    u8 *p;

    if (*(s32 *)(d + 160) != -1) {
        if (D_001BBC40[D_001D545C][*(s32 *)(d + 160)] & 0x80) {
            return 0;
        }
    }
    if (*(s32 *)(d + 12) >= 0) {
        if (func_00382380(D_001A4C60, *(s32 *)(d + 12), 0)) {
            return 1;
        }
    } else if (*(s32 *)(d + 16) >= 0) {
        if (func_L01_0044BFC8(D_001A4C60, *(s32 *)(d + 16))) {
            return 1;
        }
    } else if (*(s32 *)(d + 8) >= 0) {
        if (func_L01_0044C078(D_001A4C60, *(s32 *)(d + 8))) {
            return 1;
        }
    } else if (*(s32 *)(d + 20) >= 0) {
        p = D_L01_0021F6C0[*(s32 *)(d + 20)];
        if (func_L01_004463F8(D_001A4C60, p + 16, *(s32 *)p)) {
            return 1;
        }
    } else {
        if (d[56] != 0 && d[57] == 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003ECA48 */

INCLUDE_ASM("asm/levels", func_L01_003ECB58);

INCLUDE_ASM("asm/levels", func_L01_003ECDD0);

INCLUDE_ASM("asm/levels", func_L01_003ED1F8);

/* localdecomp:start func_L01_003EDC90 */
extern s32 func_L01_003ECA48(u8 *m);
extern char *D_L01_001DF804;
extern s32 D_001A71AC[];
extern s32 D_001A71A4[];
s32 func_L01_003EDC90(Obj_003EBD50 *a, Obj_003EBD50 *b) {
    Info_003EBD50 *info;
    info = (*(Ent_003EBD50 * *)&D_L01_001DF804)[a->f84].info;
    if (info->f39 != 0) {
        return -1;
    }
    if (info->f38 != 0 && b->f86 != 19) {
        return 1;
    }
    if (b != 0 && b->f7E == 0) {
        if (b->f7C >= a->f7C || b->f86 == 32) {
            if (b->f86 != 32) {
                return 0;
            }
        }
    }
    if (((s32 (*)(Obj_003EBD50 *))func_L01_003ECA48)(a) == 0) {
        return 0;
    }
    if (info->f43 >= 0 && D_001A71AC[0] != info->f43) {
        return 0;
    }
    if (info->f42 >= 0 && D_001A71A4[0] != info->f42) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_003EDC90 */

/* localdecomp:start func_L01_003EDD80 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003EDD80(void) {
}
/* localdecomp:end func_L01_003EDD80 */

/* localdecomp:start func_L01_003EDD88 */
extern Ent003EC730 D_L01_001E2A40[];
extern char *D_L01_001E0100;
extern f32 func_0038CF38(void *, void *);

s32 func_L01_003EDD88(u8 *a) {
    u8 *owner = (u8 *)&D_L01_001E2A40[*(s32 *)(a + 0x94)];
    u8 *st = owner + 0x150;
    u8 *own = *(u8 **)(owner + 0x50);
    u8 *sub = *(u8 **)(own + 0x70);
    u8 *move = sub + 0x180;
    u8 *rot = sub + 0x1E0;
    u8 *p;
    u32 mode;
    s32 r;

    p = *(u8 **)(D_L01_001DF804 + *(s16 *)(a + 0x84) * 32 + 28);
    if (*(s16 *)(own + 0x86) != 0) {
        goto out;
    }
    mode = st[0x12B] == 1 || st[0x12B] == 2;
    if (*(s16 *)(p + 0x4A) && !mode) goto out;
    if (*(s16 *)(p + 0x48) && mode) goto out;
    if (*(s32 *)(p + 0x34)) {
        if (__builtin_fabsf(*(f32 *)(move + 0x34)) > 0.01f) goto out;
        if (__builtin_fabsf(*(f32 *)(rot + 8)) > 0.01f) goto out;
    }
    if ((u32)(*(s32 *)(st + 0x100) - 0x66) >= 2 && *(f32 *)(st + 0x110) > 0.020000001f) {
    out:
        return 0;
    }
    {
        if (*(s32 *)(p + 0xC) >= 0) {
            if (*(s32 *)(st + 0x100) == 0x66 && func_0038CF38(st + 0x40,D_L01_001E0100 + *(s32 *)(p + 0xC) * 128 + 0x30) < 3.0f) return 1;
            if (func_00382380(st + 0x40,*(s32 *)(p + 0xC), 0)) return 1;
        }
        if (*(s32 *)(p + 0x10) >= 0) {
            if (*(s32 *)(st + 0x100) == 0x66 && func_0038CF38(st + 0x40,D_L01_001E0100 + *(s32 *)(p + 0x10) * 128 + 0x30) < 3.0f) return 1;
            if (func_L01_0044BFC8(st + 0x40,*(s32 *)(p + 0x10))) return 1;
        }
        if (*(s32 *)(p + 8) >= 0) {
            if (*(s32 *)(st + 0x100) == 0x66 && func_0038CF38(st + 0x40,D_L01_001E0100 + *(s32 *)(p + 8) * 128 + 0x30) < 3.0f) return 1;
            if (func_L01_0044C078(st + 0x40,*(s32 *)(p + 8))) return 1;
        }
        r = 0;
        *(s16 *)(p + 0x26) = 1;
        return r;
    }
}
/* localdecomp:end func_L01_003EDD88 */

INCLUDE_ASM("asm/levels", func_L01_003EDFF0);

INCLUDE_ASM("asm/levels", func_L01_003EE568);

/* localdecomp:start func_L01_003EE638 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003EE638(void) {
}
/* localdecomp:end func_L01_003EE638 */

/* localdecomp:start func_L01_003EE640 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003EE640(void) {
}
/* localdecomp:end func_L01_003EE640 */

/* localdecomp:start func_L01_003EE648 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003EE648(void) {
}
/* localdecomp:end func_L01_003EE648 */

/* localdecomp:start func_L01_003EE650 */
extern char *D_L01_001DF804 __attribute__((section(".sdata")));

/* from rac2-decomp's func_L00_0042A500, renamed */
void func_L01_003EE650(int i)
{
    char *q = *(char **)(D_L01_001DF804 + i * 0x20 + 0x1C);
    *(short *)(q + 0x26) = 0;
    *(int *)(q + 0x20) = 0;
}
/* localdecomp:end func_L01_003EE650 */

/* localdecomp:start func_L01_003EE670 */


extern Ent003EC730 D_L01_001E2A40[];
extern void func_0038CC88(u8 *, void *, s32);

void func_L01_003EE670(u8 *obj)
{
    Ent003EC730 *ent = &D_L01_001E2A40[*(s32 *)(obj + 148)];

    *(u128_t *)(obj + 48) = ent->v230;
    func_0038CC88(obj, ent->b200, 48);
    *(u16 *)(obj + 126) = 0;
    ent->b2A3 = 0;
    D_L01_001E2A40[*(s32 *)(obj + 148)].f2C8 = 0.075f;
    D_L01_001E2A40[*(s32 *)(obj + 148)].f2B8 = 0.075f;
}
/* localdecomp:end func_L01_003EE670 */

INCLUDE_ASM("asm/levels", func_L01_003EE708);

/* localdecomp:start func_L01_003EE768 */
extern void func_0038CC88(u8 *, void *, s32);
extern Ent003EC730 D_L01_001E2A40[];

void func_L01_003EE768(M_3EC828 *m) {
    E_3EC828 *e = &((E_3EC828 *)&D_L01_001E2A40)[m->w94];
    m->q30 = e->q230;
    ((void (*)(M_3EC828 *, u8 *, s32))func_0038CC88)(m, e->b200, 48);
}
/* localdecomp:end func_L01_003EE768 */

INCLUDE_ASM("asm/levels", func_L01_003EE7B0);

/* localdecomp:start func_L01_003EE880 */
extern u8 *D_L01_001DFB6C;
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_00382468(s32);
extern s32 func_L01_004AAE90(s32, s32, void *, s32);
extern void func_003A4F28(s32);

void func_L01_003EE880(char *self) {
    int *sub = *(int **)(self + 8);
    unsigned int flags;
    float distance;
    if (sub[5] == 0) return;
    if (sub[0] < 0) return;
    distance = func_0038CF00(D_L01_001E29C0, self + 0x40);
    if (distance < *(float *)(self + 0xc)) {
        char *slot;
        flags = 0;
        if (*(u8 *)(D_L01_001DFB6C + sub[0] * 32 + 0x18)) flags |= 4;
        slot = (char *)D_001A30B0 + sub[4] * 0x80;
        if (*(char **)(slot + 0x100) == self && *(u8 *)(slot + 0xD0)) return;
        if (func_0038CAD0(sub + 3)) {
            sub[4] = func_L01_004AAE90(sub[0], flags, self, 0x400);
            if (sub[2] > 0) sub[3] = (int)((sub[1] + func_00382468(sub[2] - sub[1])) * 50.0f);
        }
    } else if (*(float *)(self + 0xc) + 1.0f < distance) {
        char *slot;
        int index = sub[4];
        if (index != -1) {
            slot = (char *)D_001A30B0 + index * 0x80;
            if (*(char **)(slot + 0x100) == self && *(u8 *)(slot + 0xD0)) func_003A4F28(index);
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L01_003EE880 */

LINKER_REMNANT("asm/levels", func_L01_003EEA00);

INCLUDE_ASM("asm/levels", func_L01_003EEA08);

INCLUDE_ASM("asm/levels", func_L01_003EEF30);

INCLUDE_ASM("asm/levels", func_L01_003EF140);

INCLUDE_ASM("asm/levels", func_L01_003EF2D0);

/* localdecomp:start func_L01_003EF560 */




extern u8 D_001A3190[];
extern s32 D_L01_001E2E90[];
extern s32 func_L01_004AAE90(s32, s32, void *, s32);
extern void func_003A4F28(s32);

void func_L01_003EF560(Obj_003ED620 *obj) {
    H_003ED620 *h = obj->h;
    u8 *e;
    s32 on;

    if (h->f4 != -1) {
        *(s128_003ED620 *)(D_001A3190 + (h->f4 << 7)) = D_L01_001E29C0[0];
    }
    e = (u8 *)&D_001A30B0[h->f4];
    on = 0;
    if (*(void **)(e + 256) == obj) {
        on = e[208] != 0;
    }
    if (D_L01_001E2E90[0] != 0) {
        if (!on) {
            h->f4 = func_L01_004AAE90(h->f0, 21, obj, 1024);
        }
    } else if (on) {
        func_003A4F28(h->f4);
        h->f4 = -1;
    }
}
/* localdecomp:end func_L01_003EF560 */

INCLUDE_ASM("asm/levels", func_L01_003EF628);

INCLUDE_ASM("asm/levels", func_L01_003EF708);

/* localdecomp:start func_L01_003EFA80 */
f32 func_L01_003EFA80(f32 a, f32 b, f32 t) {
    return a * (1.0f - t) + b * t;
}
/* localdecomp:end func_L01_003EFA80 */

INCLUDE_ASM("asm/levels", func_L01_003EFAA0);

INCLUDE_ASM("asm/levels", func_L01_003EFB38);

INCLUDE_ASM("asm/levels", func_L01_003F0140);

INCLUDE_ASM("asm/levels", func_L01_003F02D8);

/* localdecomp:start func_L01_003F08C0 */
extern s32 D_L01_001D56C0;
s32 func_L01_003F08C0(void) {
    return D_L01_001D56C0;
}
/* localdecomp:end func_L01_003F08C0 */

INCLUDE_ASM("asm/levels", func_L01_003F08C8);

/* localdecomp:start func_L01_003F1188 */
extern u8 D_L01_002A43C0[];
extern u8 D_L01_001DF780[];
extern void func_0038CBA0(void *, s32);
void func_L01_003F1188(void) {
    s32 size = D_L01_002A43C0 - D_L01_001DF780;
    if ((size & 0xF) == 0 && ((u32)D_L01_001DF780 & 0xF) == 0) {
        func_0038CBA0(D_L01_001DF780, size);
    } else {
        s32 i;
        for (i = 0; i < D_L01_002A43C0 - D_L01_001DF780; i++) {
            D_L01_001DF780[i] = 0;
        }
    }
}
/* localdecomp:end func_L01_003F1188 */

INCLUDE_ASM("asm/levels", func_L01_003F1218);

INCLUDE_ASM("asm/levels", func_L01_003F1478);

/* localdecomp:start func_L01_003F1600 */
extern s32 D_00143950[];
extern s8 D_L01_001E6DE1[];
extern s32 D_L01_001DF948;
extern void func_L01_00461818(void);
extern void func_L01_004BA278(void);
extern void func_L01_003F26E0(void);
extern s32 func_0012C908(s32);

s32 func_L01_003F1600(void) {
    s32 limit = 9600;
    s32 r;

    if (D_00143950[0] != 0) {
        limit = 11520;
    }
    if (limit < *(volatile s32 *)0x10000800 && D_L01_001E6DE1[0] == 0) {
        func_L01_00461818();
        func_L01_004BA278();
    }
    func_L01_003F26E0();
    r = func_0012C908(0);
    D_L01_001DF948++;
    return r;
}
/* localdecomp:end func_L01_003F1600 */

/* localdecomp:start func_L01_003F1680 */
extern void func_L01_003F1E68(void *a, s32 b, void *c);
extern G_3EF740 D_L01_00237800;
extern s16 D_001CD018[];
extern u8 D_L01_001D667B;
extern void func_003A9108(void);
extern void func_0013CA28(void);
extern void func_0013B620(void);
extern void func_003A5430(void);
extern void func_003A1C28(void);
extern void func_L01_0041A6E0(void);
extern void func_L01_0042B4F8(s32, s32);
extern void func_L01_00430110(s32);
extern void func_L01_0045A720(s32);
extern void func_003A1930(s32, s32, s32);
extern void func_L01_0041BFE8(void);
extern void func_L01_00478608(void);
void func_L01_003F1680(s32 a0) {
    s32 n;
    func_003A9108();
    func_0013CA28();
    func_0013B620();
    func_003A5430();
    func_003A1C28();
    n = D_001CD018[0];
    if (D_L01_00237800.x0 != 0) {
        n = D_L01_00237800.xC64;
    }
    func_L01_0041A6E0();
    func_L01_0042B4F8(0, a0);
    func_L01_00430110(0);
    func_L01_0045A720(0);
    func_003A1930(n, 1, 1024);
    func_L01_0041BFE8();
    func_L01_00478608();
    ((void (*)(void))func_L01_003F1E68)();
    D_L01_001D667B = 0;
}
/* localdecomp:end func_L01_003F1680 */

/* localdecomp:start func_L01_003F1740 */
extern void func_L01_003F5748(s32);

void func_L01_003F1740(void) {
    func_L01_003F5748(0);
}
/* localdecomp:end func_L01_003F1740 */

INCLUDE_ASM("asm/levels", func_L01_003F1760);

/* localdecomp:start func_L01_003F1780 */
extern void func_00384CC8();
void func_L01_003F1780(void) {
    ((s32 * (*)(s32))func_00384CC8)(2);
}
/* localdecomp:end func_L01_003F1780 */

/* localdecomp:start func_L01_003F17A0 */
extern void func_00384CC8();
void func_L01_003F17A0(void) {
    func_00384CC8(3);
}
/* localdecomp:end func_L01_003F17A0 */

/* localdecomp:start func_L01_003F17C0 */
extern f32 D_L01_001DF788[2];

void func_L01_003F17C0(void *a0, s32 *out) {
    s32 i;
    f32 big = 1000000.0f;
    for (i = 0; i < 4; i++) {
        f32 best = big;
        s32 bi = -1;
        s32 j;
        for (j = 0; j < 4; j++) {
            if (D_L01_001DF788[j] < best) {
                best = D_L01_001DF788[j];
                bi = j;
            }
        }
        out[i] = bi;
        D_L01_001DF788[bi] = big;
    }
}
/* localdecomp:end func_L01_003F17C0 */

INCLUDE_ASM("asm/levels", func_L01_003F1850);

/* localdecomp:start func_L01_003F19B0 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003F19B0(void) {
}
/* localdecomp:end func_L01_003F19B0 */

INCLUDE_ASM("asm/levels", func_L01_003F19B8);

/* localdecomp:start func_L01_003F1E68 */
extern void func_L01_0045E4B0();
extern s32 D_L01_001DFB40;

void func_L01_003F1E68(void *a, s32 b, void *c) {
    func_L01_0045E4B0(a, b, c);
    D_L01_001DFB40 += 1;
}
/* localdecomp:end func_L01_003F1E68 */

INCLUDE_ASM("asm/levels", func_L01_003F1E98);

/* localdecomp:start func_L01_003F1F08 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003F1F08(void) {
}
/* localdecomp:end func_L01_003F1F08 */

/* localdecomp:start func_L01_003F1F10 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003F1F10(void) {
}
/* localdecomp:end func_L01_003F1F10 */

LINKER_REMNANT("asm/levels", func_L01_003F1F18);

/* localdecomp:start func_L01_003F1F20 */
struct Rac2Native_5f824a0e369ccf7b_src_record {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned short s4;
    unsigned short s6;
    unsigned short s8;
    unsigned short s10;
    unsigned short s12;
    unsigned char e;
    unsigned char f;
};
extern struct Rac2Native_5f824a0e369ccf7b_src_record *D_L01_002BF4A0[];
int func_L01_003F2058();

/* from rac2-decomp's func_L00_002D6900, renamed */
int func_L01_003F1F20(unsigned int index)
{
    if (index < 0x62)
        return func_L01_003F2058(D_L01_002BF4A0[index]);
    return -1;
}
/* localdecomp:end func_L01_003F1F20 */

INCLUDE_ASM("asm/levels", func_L01_003F1F60);

/* localdecomp:start func_L01_003F1FC0 */
extern u8 D_L01_001E2480_003F1FC0[];

s32 func_L01_003F1FC0(s32 a0, u8 *a1) {
    s32 idx;
    u8 *p;

    idx = 0;
    if (a1 != 0) {
        idx = a1[0x54c] * 4 + a1[0x557];
    }
    p = D_L01_001E2480_003F1FC0 + (a0 * 16 + idx * 128);
    return *p != 0;
}
/* localdecomp:end func_L01_003F1FC0 */

/* localdecomp:start func_L01_003F2000 */
extern u8 D_L01_001E2480_003F2000[];

void func_L01_003F2000(void) {
    s32 i;
    s32 j;
    u8 *p;
    for (i = 0; i < 8; i++) {
        p = D_L01_001E2480_003F2000 + i * 128;
        for (j = 7; j >= 0; j--) {
            p[0] = 0;
            p[1] = 0;
            *(s16 *)(p + 0xa) = 0;
            *(s16 *)(p + 0xc) = 0;
            p[0xe] = 0;
            p += 16;
        }
    }
}
/* localdecomp:end func_L01_003F2000 */

/* localdecomp:start func_L01_003F2058 */
extern Tab_003F2058 D_L01_001E2480[];

int func_L01_003F2058(Rec_003F2058 *src, Ctx_003F2058 *ctx)
{
    int base = 0;
    int n = 0;
    int i;
    int j;

    if (ctx) {
        if (ctx->b557 == 255)
            return 0;
        base = ctx->b54C * 4 + ctx->b557;
    }

    for (n = 0; n < 8 && src[n].b0 != 255; n++)
        ;

    j = 0;
    for (i = 0; i < 8 && j < n; i++) {
        if (D_L01_001E2480[base].r[i].b0 == 0)
            j++;
    }

    if (j != n)
        return -1;

    for (j = 0; j < n; j++) {
        for (i = 0; i < 8 && D_L01_001E2480[base].r[i].b0 != 0; i++)
            ;
        if (i < 8) {
            D_L01_001E2480[base].r[i].b0 = src[j].b0;
            D_L01_001E2480[base].r[i].b1 = src[j].b1;
            D_L01_001E2480[base].r[i].b2 = src[j].b2;
            D_L01_001E2480[base].r[i].b3 = src[j].b3;
            D_L01_001E2480[base].r[i].s4 = src[j].s4;
            D_L01_001E2480[base].r[i].s6 = src[j].s6;
            D_L01_001E2480[base].r[i].s8 = src[j].s8;
            D_L01_001E2480[base].r[i].s10 = src[j].s10;
            D_L01_001E2480[base].r[i].s12 = src[j].s12;
            D_L01_001E2480[base].r[i].e = src[j].e - src[j].f;
            D_L01_001E2480[base].r[i].f = src[j].f;
            if (D_L01_001E2480[base].r[i].s10 + D_L01_001E2480[base].r[i].s12 == 0)
                D_L01_001E2480[base].r[i].s10++;
        }
    }
    return i;
}
/* localdecomp:end func_L01_003F2058 */

INCLUDE_ASM("asm/levels", func_L01_003F2278);

INCLUDE_ASM("asm/levels", func_L01_003F22D8);

INCLUDE_ASM("asm/levels", func_L01_003F26E0);

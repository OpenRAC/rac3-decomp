#include "common.h"

typedef struct {
    u8 pad[80];
} Ent_4C4520;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    s32 w8;
    s32 w12;
    s32 w16;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w32;
    s32 w36;
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w52;
    s32 w56;
    s32 w60;
    s32 owner;
    char pad44[0x50 - 0x44];
} Slot;
typedef struct {
    u8 pad[64];
    s32 handle;
    u8 pad2[12];
} Ent_004C45F8;
typedef struct {
    s32 w0;
    s32 w4;
    s32 pad8[2];
} E_4C46A8;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Unk24FA60;
typedef int u128_4C4A18 __attribute__((mode(TI)));
typedef struct {
    u128_4C4A18 pos;
    f32 x10;
    f32 x14;
    f32 x18;
    u8 *x1C;
} E_4C4A18;
typedef struct {
    u8 pad0[872];
    s16 x368;
    u8 pad36A[8790];
    u8 *x25C0;
} S_4C4A18;
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_004C4AD8;
typedef struct {
    u8 p0[0x10];
    Vec4_004C4AD8 x10;
} O_004C4AD8;
typedef struct {
    u8 p0[0xE0];
    Vec4_004C4AD8 xE0;
} P_004C4AD8;
typedef struct {
    Vec4_004C4AD8 x0;
    f32 x10;
    f32 x14;
    f32 x18;
    O_004C4AD8 *x1C;
} T_004C4AD8;
typedef struct {
    u8 p0[0x368];
    s16 x368;
    u8 p36A[0x25C0 - 0x36A];
    P_004C4AD8 *x25C0;
} S_004C4AD8;
typedef struct { u8 a; u8 b; u8 pad[238]; } Ent_004C4F88;
typedef struct {
    u8 pad0[4608];
    s32 f4608;
    u8 pad4612[36];
    s32 f4648;
} Game_004C5038;
typedef struct {
    u8 pad0[28];
    s32 f28;
} Ent_004C5038;
typedef struct {
    u8 pad0[16];
    f32 x;
    f32 y;
    f32 z;
    u8 pad1C[20];
    u8 b30;
    u8 pad31[3];
    u16 h34;
    u8 pad36[98];
    s32 f98;
} Obj_4C5DE0;
typedef struct {
    u8 pad0[336];
    s16 unk150;
    s16 unk152;
} G4C67B8;
typedef struct { u8 pad[336]; s16 a; s16 b; } Ent_004C6A70;
typedef struct {
    int a[64];
    int b[64];
    int c[8];
    int n220;
    int n224;
    int n228;
} S_4C7228;

LINKER_REMNANT("asm/levels", func_L01_004C6618);

INCLUDE_ASM("asm/levels", func_L01_004C6620);

LINKER_REMNANT("asm/levels", func_L01_004C6788);

INCLUDE_ASM("asm/levels", func_L01_004C67A0);

INCLUDE_ASM("asm/levels", func_L01_004C6D40);

LINKER_REMNANT("asm/levels", func_L01_004C7028);

INCLUDE_ASM("asm/levels", func_L01_004C70A8);

INCLUDE_ASM("asm/levels", func_L01_004C7438);

INCLUDE_ASM("asm/levels", func_L01_004C7A18);

INCLUDE_ASM("asm/levels", func_L01_004C7D40);

INCLUDE_ASM("asm/levels", func_L01_004C7D98);

INCLUDE_ASM("asm/levels", func_L01_004C7E70);

/* localdecomp:start func_L01_004C80D0 */

extern Ent_4C4520 D_L01_0024E5E0[];

Ent_4C4520 *func_L01_004C80D0(u32 a0) {
    Ent_4C4520 *r = 0;
    if (a0 < 64) {
        r = &D_L01_0024E5E0[a0];
    }
    return r;
}
/* localdecomp:end func_L01_004C80D0 */

/* localdecomp:start func_L01_004C80F8 */
extern Ent_4C4520 D_L01_0024E5E0[];

extern void func_L01_0043A430(s32, s32, Slot *);

s32 func_L01_004C80F8(s32 owner, s32 arg1) {
    Slot *e;
    s32 i;

    for (i = 0; i < 64; i++) {
        e = &((Slot *)&D_L01_0024E5E0)[i];
        if (e->owner == 0) {
            e->w4 = -1;
            e->owner = owner;
            e->b3 = 0;
            e->b0 = 0;
            e->w12 = 0;
            e->w8 = 0;
            e->w16 = 0;
            e->w20 = 0;
            e->w24 = 0;
            e->w28 = 0;
            e->w48 = 0;
            e->w52 = 0;
            e->w56 = 0;
            e->w60 = 0;
            e->b2 = 0;
            e->w32 = 0;
            e->w36 = 0;
            e->w40 = 0;
            e->w44 = 0;
            e->b1 = 0;
            func_L01_0043A430(owner, arg1, e);
            goto out;
        }
    }
out:
    return i;
}
/* localdecomp:end func_L01_004C80F8 */

/* localdecomp:start func_L01_004C81A8 */
extern Ent_4C4520 D_L01_0024E5E0[];

extern void func_003C2C98(s32, Ent_004C45F8 *);

void func_L01_004C81A8(u32 i) {
    Ent_004C45F8 *e;

    if (i < 64) {
        e = &((Ent_004C45F8 *)&D_L01_0024E5E0)[i];
        func_003C2C98(e->handle, e);
        e->handle = 0;
    }
}
/* localdecomp:end func_L01_004C81A8 */

INCLUDE_ASM("asm/levels", func_L01_004C81F0);

/* localdecomp:start func_L01_004C8258 */

extern E_4C46A8 D_L01_0024F9E0[];

s32 func_L01_004C8258(s32 a0, s32 a1) {
    s32 i;
    s32 r = 1;
    for (i = 0; i < 32; i++) {
        if (D_L01_0024F9E0[i].w4 == a0 && D_L01_0024F9E0[i].w0 == a1) {
            r = 0;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L01_004C8258 */

/* localdecomp:start func_L01_004C82C0 */
extern E_4C46A8 D_L01_0024F9E0[];
s32 func_L01_004C82C0(s32 b, s32 a) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (((Unk24FA60 *)&D_L01_0024F9E0)[i].b == b && ((Unk24FA60 *)&D_L01_0024F9E0)[i].a == a) {
            return ((Unk24FA60 *)&D_L01_0024F9E0)[i].c;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_004C82C0 */

/* localdecomp:start func_L01_004C8308 */
extern s32 func_L01_004C82C0(s32 b, s32 a);

s32 func_L01_004C8308(void *ctx, s32 *list, s32 n, s32 type) {
    s32 best = 0;
    s32 bestd = 9999;
    s32 d;
    s32 i;

    for (i = 0; i < n; i++) {
        if (type <= 0 || *(u8 *)(*(s32 *)(list[i] + 36) + 70) == type) {
            d = ((s32 (*)(void *, s32))func_L01_004C82C0)(ctx, list[i]);
            if (d < bestd && d != -1) {
                best = list[i];
                bestd = d;
            }
        }
    }
    return best;
}
/* localdecomp:end func_L01_004C8308 */

/* localdecomp:start func_L01_004C83D0 */
extern s32 func_L01_004C8308(void *ctx, s32 *list, s32 n, s32 type);
extern s32 func_L01_004C8258(s32 a0, s32 a1);

u8 *func_L01_004C83D0(void *a, u8 **list, s32 n, s32 *out, s32 type) {
    s32 i;
    u8 *r;

    *out = 1;
    for (i = 0; i < n; i++) {
        if (type > 0 && (*(u8 **)(list[i] + 36))[70] != type) {
            continue;
        }
        if (((s32 (*)(void *, u8 *))func_L01_004C8258)(a, list[i]) == 1) {
            return list[i];
        }
    }
    if (n < 2) {
        return 0;
    }
    r = ((u8 * (*)(void *, u8 **, s32, s32))func_L01_004C8308)(a, list, n, type);
    if (r != 0) {
        *out = 0;
    }
    return r;
}
/* localdecomp:end func_L01_004C83D0 */

INCLUDE_ASM("asm/levels", func_L01_004C84D8);

INCLUDE_ASM("asm/levels", func_L01_004C8598);

/* localdecomp:start func_L01_004C85C8 */



extern void func_003C5180(u128_4C4A18 *, E_4C4A18 *, s32);
extern E_4C4A18 D_L01_00250100[];
extern S_4C4A18 D_001A4BE0;

s32 func_L01_004C85C8(u8 *a0, u128_4C4A18 *a1, f32 f12, f32 f13, f32 f14) {
    u128_4C4A18 v;
    E_4C4A18 *e = D_L01_00250100;
    s32 i;
    for (i = 0; i < 128; i++, e++) {
        if (e->x1C == 0) {
            if (a1 != 0) {
                v = *a1;
            } else {
                v = *(u128_4C4A18 *)(a0 + 16);
            }
            e->x1C = a0;
            e->x10 = f12;
            e->x14 = f13;
            e->x18 = f14;
            if (D_001A4BE0.x368 != 0) {
                e->pos = *(u128_4C4A18 *)(D_001A4BE0.x25C0 + 224);
            } else {
                func_003C5180(&v, e, 1);
            }
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_004C85C8 */

INCLUDE_ASM("asm/levels", func_L01_004C8668);

/* localdecomp:start func_L01_004C8688 */
extern S_4C4A18 D_001A4BE0;
extern E_4C4A18 D_L01_00250100[];
extern void func_003C5180(u128_4C4A18 *, E_4C4A18 *, s32);





extern f32 func_0038CEA8(Vec4_004C4AD8 *);
extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
extern void func_0038CE90(Vec4_004C4AD8 *, Vec4_004C4AD8 *, T_004C4AD8 *);
extern f32 func_0038CE68(Vec4_004C4AD8 *, T_004C4AD8 *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
extern void func_0038D688(Vec4_004C4AD8 *, Vec4_004C4AD8 *, Vec4_004C4AD8 *);
extern s32 D_L01_001D673C;
extern s32 D_L01_001D6740;
extern s16 D_001A4F48[];
extern s32 D_001A6290[];

void func_L01_004C8688(s32 idx, Vec4_004C4AD8 *r, Vec4_004C4AD8 *target) {
    Vec4_004C4AD8 q;
    Vec4_004C4AD8 d;
    Vec4_004C4AD8 a;
    Vec4_004C4AD8 b;
    Vec4_004C4AD8 c;
    Vec4_004C4AD8 tgt;
    T_004C4AD8 *t;
    f32 k;
    f32 len;
    f32 w;
    f32 h;
    f32 s;

    if (idx < 0) {
        return;
    }
    if (D_L01_001D673C == 0) {
        if (D_L01_001D6740 == 0 && D_001A4F48[0] == 0) {
            return;
        }
    } else if (D_001A6290[0] > 0) {
        return;
    }
    t = &((T_004C4AD8 *)&D_L01_00250100)[idx];
    k = 1.0f;
    if (target != 0) {
        tgt = *target;
    } else {
        if (t->x1C == 0) {
            return;
        }
        tgt = t->x1C->x10;
    }
    if ((*(S_004C4AD8 *)&D_001A4BE0).x368 != 0) {
        if (D_L01_001D6740 != 0) {
            k = t->x14;
        } else {
            k = t->x18;
        }
    } else if (D_L01_001D6740 != 0) {
        k = t->x14;
    }
    if (D_L01_001D673C != 0) {
        k = t->x10;
    }
    q = t->x0;
    w = r->w;
    r->w = 0.0f;
    len = func_0038CEA8(r);
    if ((*(S_004C4AD8 *)&D_001A4BE0).x368 != 0 && D_L01_001D6740 == 0) {
        t->x0 = (*(S_004C4AD8 *)&D_001A4BE0).x25C0->xE0;
    } else {
        ((void (*)(Vec4_004C4AD8 *, T_004C4AD8 *, s32))func_003C5180)(&tgt, t, 1);
    }
    func_0038CF68(r, r, 1.0f);
    func_0038CE90(&d, &q, t);
    h = -func_0038CE68(&q, t) * 0.5f * k;
    func_0038CE20(&a, &d, func_0038D0B0(h));
    s = func_0038D098(h);
    a.w = s;
    b.x = -a.x;
    b.y = -a.y;
    b.z = -a.z;
    b.w = s;
    func_0038D688(&c, &a, r);
    func_0038D688(r, &c, &b);
    func_0038CF68(r, r, len);
    r->w = w;
}
/* localdecomp:end func_L01_004C8688 */

INCLUDE_ASM("asm/levels", func_L01_004C88C8);

/* localdecomp:start func_L01_004C8B38 */
extern Ent_004C4F88 D_L01_002C5600[];
extern u8 D_0014261F[];
extern void func_L01_0032CA80(void);
extern void func_L01_0032FB80(void);
extern void func_L01_004C9030(void);
extern void func_L01_004C8BA0(void);
extern void func_L01_004C8DD0(void);
void func_L01_004C8B38(void) {
    func_L01_0032CA80();
    func_L01_0032FB80();
    if ((D_0014261F[0] + D_L01_002C5600)->b) func_L01_004C9030();
    func_L01_004C8BA0();
    func_L01_004C8DD0();
}
/* localdecomp:end func_L01_004C8B38 */

/* localdecomp:start func_L01_004C8BA0 */
extern S_4C4A18 D_001A4BE0;
extern void func_L01_004C8D28(void);
void func_L01_004C8BA0(void) {
    u8 *p = ((u8 *)&D_001A4BE0);
    if (*(s32 *)(p + 4648) != 127 || *(u8 *)(p + 9700) == 3) {
        func_L01_004C8D28();
    }
}
/* localdecomp:end func_L01_004C8BA0 */

/* localdecomp:start func_L01_004C8BE8 */
extern S_4C4A18 D_001A4BE0;


extern s32 D_L01_001D6694;
extern s32 D_L01_001DD298;
extern Ent_004C5038 D_L01_0028CAA0[];
extern void func_L01_00323300(s32);
extern f32 func_L01_004C93D8_004C8BE8(void);
extern void func_L01_003438C0(s32);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_004B14C8(s32);

void func_L01_004C8BE8(void) {
    s32 i;

    if ((*(Game_004C5038 *)&D_001A4BE0).f4648 == 71 && D_L01_001D6694 == 6) {
        func_L01_00323300((*(Game_004C5038 *)&D_001A4BE0).f4608);
    }
    if (func_L01_004C93D8_004C8BE8() != 0.0f && D_L01_001D6694 != 0 && D_L01_001DD298 != 0) {
        func_L01_003438C0(D_L01_001DD298);
    }
    if ((*(Game_004C5038 *)&D_001A4BE0).f4648 == 135 && D_L01_001D6694 != 0) {
        for (i = 199; i >= 0; i--) {
            D_L01_0028CAA0[i].f28 = 0;
        }
    }
    if ((*(Game_004C5038 *)&D_001A4BE0).f4648 == 111 && D_L01_001D6694 == 8) {
        func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_L01_004B14C8(1);
    }
}
/* localdecomp:end func_L01_004C8BE8 */

INCLUDE_ASM("asm/levels", func_L01_004C8D28);

INCLUDE_ASM("asm/levels", func_L01_004C8DD0);

INCLUDE_ASM("asm/levels", func_L01_004C9030);

INCLUDE_ASM("asm/levels", func_L01_004C9360);

INCLUDE_ASM("asm/levels", func_L01_004C93B0);

/* localdecomp:start func_L01_004C93D8 */
extern float D_L01_001E1140;
float func_L01_004C93D8(void) {
    return D_L01_001E1140;
}
/* localdecomp:end func_L01_004C93D8 */

INCLUDE_ASM("asm/levels", func_L01_004C93E0);

INCLUDE_ASM("asm/levels", func_L01_004C94B0);

INCLUDE_ASM("asm/levels", func_L01_004C94C0);

INCLUDE_ASM("asm/levels", func_L01_004C9500);

INCLUDE_ASM("asm/levels", func_L01_004C97C8);

/* localdecomp:start func_L01_004C9848 */
extern void func_003C25D8(void *);
extern void func_0038CB78(void *, s32, s32);
extern void func_003C7C38(void *);

void func_L01_004C9848(u8 *a0) {
    void *p = *(void **)(a0 + 104);
    func_003C25D8(a0);
    *(void **)(a0 + 104) = p;
    func_0038CB78(p, 0, 128);
    if (!(*(u16 *)(a0 + 52) & 4)) {
        func_003C7C38(a0);
    }
}
/* localdecomp:end func_L01_004C9848 */

INCLUDE_ASM("asm/levels", func_L01_004C98A8);

/* localdecomp:start func_L01_004C99A0 */
extern void func_L01_004C9848(u8 *a0);
extern Obj_4C5DE0 *D_L01_001E1138;
void func_L01_004C99A0(void) {
    Obj_4C5DE0 *o;
    ((void (*)(Obj_4C5DE0 *, s32))func_L01_004C9848)(D_L01_001E1138, 1007);
    o = D_L01_001E1138;
    o->b30 = 255;
    o->h34 |= 0x43;
    o->f98 = 0;
    o->z = 5.0f;
    o->y = 5.0f;
    o->x = 5.0f;
}
/* localdecomp:end func_L01_004C99A0 */

INCLUDE_ASM("asm/levels", func_L01_004C99F8);

INCLUDE_ASM("asm/levels", func_L01_004CA088);

INCLUDE_ASM("asm/levels", func_L01_004CA270);

/* localdecomp:start func_L01_004CA3F0 */

extern G4C67B8 D_001CFEC0;
extern s16 D_L01_001E1102;
extern f32 D_L01_001E1104;
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, long);

void func_L01_004CA3F0(void)
{
    s32 c;

    func_003A9440(66, 68);
    c = (s32)((1.0f - (f32)D_L01_001E1102 * D_L01_001E1104) * 255.0f);
    func_0038AF30(0, D_001CFEC0.unk152, 0, D_001CFEC0.unk150, c << 24);
}
/* localdecomp:end func_L01_004CA3F0 */

INCLUDE_ASM("asm/levels", func_L01_004CA478);

/* localdecomp:start func_L01_004CA6A8 */
extern void func_0038AF30(s32, s32, s32, s32, long);
extern void func_003A9440(s32, s32);
extern G4C67B8 D_001CFEC0;
extern s16 D_L01_001E1136;
void func_L01_004CA6A8(void) {
    ((void (*)(s32, long))func_003A9440)(66, ((long)D_L01_001E1136 << 32) | 68);
    {
        s32 c = D_L01_001E1136 << 24;
        ((void (*)(s32, s32, s32, s32, s32))func_0038AF30)(0, ((Ent_004C6A70 *)&D_001CFEC0)[0].b, 0, ((Ent_004C6A70 *)&D_001CFEC0)[0].a, c | 0xFFFFFF);
    }
}
/* localdecomp:end func_L01_004CA6A8 */

INCLUDE_ASM("asm/levels", func_L01_004CA710);

INCLUDE_ASM("asm/levels", func_L01_004CA8C8);

INCLUDE_ASM("asm/levels", func_L01_004CA928);

INCLUDE_ASM("asm/levels", func_L01_004CAB30);

INCLUDE_ASM("asm/levels", func_L01_004CAB80);

INCLUDE_ASM("asm/levels", func_L01_004CABD8);

INCLUDE_ASM("asm/levels", func_L01_004CAC40);

INCLUDE_ASM("asm/levels", func_L01_004CAC78);

/* localdecomp:start func_L01_004CADE8 */
s32 func_L01_004CADE8(s32 *a0, s32 a1) {
    s32 ret = -1;
    s32 i;
    for (i = 0; i < 64; i++) {
        if (a0[i] == 0) {
            a0[i] = a1;
            ret = i;
            a0[137] = 1;
            a0[136]++;
            a0[i + 64] = 0;
            break;
        }
    }
    return ret;
}
/* localdecomp:end func_L01_004CADE8 */

INCLUDE_ASM("asm/levels", func_L01_004CAE60);

/* localdecomp:start func_L01_004CAE90 */

extern u8 D_001A4C60[];
extern f32 func_L01_0040E548(void *, void *);

void func_L01_004CAE90(S_4C7228 *s) {
    f32 d[64];
    int cnt;
    int i;

    if (s->n224 == 0) {
        return;
    }
    cnt = 0;
    for (i = 0; i < 64; i++) {
        if (s->a[i] != 0) {
            s->b[i] = 0;
            cnt++;
            d[i] = func_L01_0040E548(D_001A4C60, (u8 *)s->a[i] + 16);
        }
        if (cnt == s->n220) {
            break;
        }
    }
    for (i = 0; i < s->n228 && i < s->n220; i++) {
        f32 best = 9999.0f;
        int bi = -1;
        int j;

        for (j = 0; j < 64; j++) {
            if (d[j] < best && s->b[j] == 0 && s->a[j] != 0) {
                best = d[j];
                bi = j;
            }
        }
        s->c[i] = s->a[bi];
        s->b[bi] = 1;
    }
}
/* localdecomp:end func_L01_004CAE90 */

LINKER_REMNANT("asm/levels", func_L01_004CB008);

/* localdecomp:start func_L01_004CB018 */
int func_L01_004CB018(int a0)
{
    int r = 0;
    if (a0 == 0 || a0 == 14 || a0 == 13) {
        r = 2;
    } else if (a0 == 1 || a0 == 3 || a0 == 11 || a0 == 12) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_004CB018 */

INCLUDE_ASM("asm/levels", func_L01_004CB068);

LINKER_REMNANT("asm/levels", func_L01_004CB120);

INCLUDE_ASM("asm/levels", func_L01_004CB128);

INCLUDE_ASM("asm/levels", func_L01_004CB1F0);

INCLUDE_ASM("asm/levels", func_L01_004CB2D8);

LINKER_REMNANT("asm/levels", func_L01_004CB318);

INCLUDE_ASM("asm/levels", func_L01_004CB320);

INCLUDE_ASM("asm/levels", func_L01_004CB358);

INCLUDE_ASM("asm/levels", func_L01_004CB388);

/* localdecomp:start func_L01_004CB540 */
extern u8 D_L01_001DB084_004CB540;
void func_L01_004CB540(u8 a) { D_L01_001DB084_004CB540 = a; }
/* localdecomp:end func_L01_004CB540 */

/* localdecomp:start func_L01_004CB548 */
extern u8 D_L01_001DB084_004CB548;

u8 func_L01_004CB548(void) {
    return D_L01_001DB084_004CB548;
}
/* localdecomp:end func_L01_004CB548 */

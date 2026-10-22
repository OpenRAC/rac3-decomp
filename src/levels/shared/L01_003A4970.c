#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
    u8 pad8[8];
    void (*f10)(u8 *);
} Tbl_003A5118;
typedef struct {
    u8 pad0[576];
    s32 f240;
    u8 pad244[284];
    s32 ids[10];
    u8 pad388[32];
    s32 f3A8;
} Vars_003A5118;
typedef struct {
    u8 pad0[104];
    Vars_003A5118 *vars;
} Obj_003A5118;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    u8 p10[0x30];
    s32 x40;
    s32 x44;
    s32 x48;
    s32 x4C;
    u8 p50[0x18];
    s32 x68;
    s32 x6C;
    u8 p70[0x64];
    s32 xD4;
} S_3A68C0;
typedef struct {
    u8 p0[0xB2];
    u16 xB2;
} O_3A68C0;
typedef struct {
    u8 p0[0x464];
    u8 x464[1];
} T_3A68C0;
typedef struct {
    u8 pad0[150];
    u16 timer;
} Obj003A7510;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128_3A7C18 __attribute__((mode(TI)));
typedef struct {
    s128_3A7C18 q0;
    u8 *parent;
    f32 f14;
    int f18;
    f32 f1C;
    f32 f20;
} V_3A7C18;
typedef int u128_003A9A80 __attribute__((mode(TI)));
typedef struct {
    u8 pad[0x64];
    u8 *w64;
} Moby_003A9A80;
typedef struct {
    u8 pad[0x30];
    u8 b30;
    u8 pad2[3];
    u16 h34;
    u8 pad3[0x98 - 0x36];
    int x98;
} S_3A9AC0m;
typedef struct {
    int x0;
    int x4;
    u8 pad[0x10];
} S_3A9AC0a;
typedef struct {
    int x0;
    int x4;
    u8 pad[0x28];
} S_3A9AC0b;
typedef struct {
    u8 pad[0x24];
    int n;
    S_3A9AC0b *p;
    u8 pad2[4];
} S_3A9AC0c;
typedef struct {
    u8 pad[8];
    int n8;
    S_3A9AC0a *pC;
    u8 pad2[0x34 - 0x10];
    int n34;
    S_3A9AC0c *p38;
} S_3A9AC0d;
typedef struct {
    u8 pad[0xD0];
    u8 bD0;
    u8 pad2[0xDC - 0xD1];
    S_3A9AC0m *mDC;
} S_3A9AC0e;
typedef struct {
    u8 pad[0x64];
    S_3A9AC0m *m;
    S_3A9AC0d *d;
    u8 pad2[0xBA0 - 0x6C];
    u8 xBA0[0xC48 - 0xBA0];
    int xC48;
    u8 pad3[0xD1C - 0xC4C];
    int xD1C;
} S_3A9AC0o;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_003AB448;

INCLUDE_ASM("asm/levels", func_L01_003A4970);

/* localdecomp:start func_L01_003A62F8 */
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define H(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define L(p, o) (*(unsigned long *)((u8 *)(p) + (o)))

extern s32 func_L01_003A65F0(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_003A6BB0(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_003A6990(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);
extern u8 D_L01_001E2A40[];
extern s32 D_001D545C;
extern s32 D_L01_001DFB40;

s32 func_L01_003A62F8(u8 *m) {
    u8 *v = *(u8 **)(m + 104);

    if (B(m, 32) == 0) {
        if (func_L01_003A65F0(m) != 0) {
            return 1;
        }
    }
    if (B(m, 49) != 0) {
        if (func_L01_0040E548(D_L01_001E2A40, m + 16) < 576.0f) {
            func_L01_004472C0(m);
            B(m, 111) = 22;
        }
    }
    if (B(v, 62) != 2) {
        if (func_L01_00452FB0(m, v + 352, 0, 0, 0) != 0) {
            func_003A52A0(3, 0, m);
            func_L01_003A6BB0(m);
        }
        func_L01_00452860(m, v + 48, 0);
        if (B(v, 94) == 0) {
            goto rest;
        }
        func_003A52A0(3, 0, m);
    }
    func_L01_003A6990(m);
    return 1;
rest:
    if ((L(m, 48) & 0x104100000000L) != 0x4100000000L || W(m, 152) != 0) {
        if (0.0f < F(v, 48)) {
            if (B(v, 95) != 0) {
                func_L01_00456BD0(m, 5);
            } else if (D_001D545C != 9 || (u8)(B(m, 149) - 3) < 2) {
                func_L01_00456BD0(m, 3);
            }
        }
    }
    if ((H(m, 178) + 8) % 8 != D_L01_001DFB40 % 8) {
        return 0;
    }
    if (B(v, 95) != 0) {
        if (B(m, 149) == 0) {
            func_L01_00456C98(m, W(v, 720), 0, 0, 0, 0, 3, 0, F(v, 724), 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(m, W(v, 728), 0, 0, 0, 0, 3, 0, F(v, 732), 10.0f, 1.0f, 0, 0);
        }
    } else {
        if (B(m, 149) == 0) {
            func_L01_00456C98(m, W(v, 720), 0, 0, 0, 0, 1, W(v, 960) != 0, F(v, 724), 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(m, W(v, 728), 0, 0, 0, 0, 1, W(v, 960) != 0, F(v, 732), 10.0f, 1.0f, 0, 0);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003A62F8 */

INCLUDE_ASM("asm/levels", func_L01_003A65F0);

/* localdecomp:start func_L01_003A6898 */
extern u8 *D_L01_001E001C;
extern Tbl_003A5118 *func_L01_0043B548(s32, s32);
extern void func_L01_003A6F80(Obj_003A5118 *);
extern void func_003C2880(Obj_003A5118 *);
void func_L01_003A6898(Obj_003A5118 *o, s32 flag) {
    Vars_003A5118 *v;
    Tbl_003A5118 *t;
    s32 i;
    v = o->vars;
    if (v->f240 != 0) {
        t = func_L01_0043B548(6625, 108);
        for (i = 0; i < 10; i++) {
            if (v->ids[i] != -1) {
                t->f10(D_L01_001E001C + v->ids[i] * 256);
                v->ids[i] = -1;
            }
        }
        t->f0(o);
        if (flag != 0) {
            t->f4(o);
        }
    } else if (v->f3A8 != 0) {
        func_L01_003A6F80(o);
    } else {
        func_003C2880(o);
    }
}
/* localdecomp:end func_L01_003A6898 */

LINKER_REMNANT("asm/levels", func_L01_003A6988);

INCLUDE_ASM("asm/levels", func_L01_003A6990);

INCLUDE_ASM("asm/levels", func_L01_003A6AC0);

INCLUDE_ASM("asm/levels", func_L01_003A6BB0);

INCLUDE_ASM("asm/levels", func_L01_003A6C68);

/* localdecomp:start func_L01_003A6D78 */
f32 func_L01_003A6D78(void) {
    return 2.0f;
}
/* localdecomp:end func_L01_003A6D78 */

/* localdecomp:start func_L01_003A6D88 */
extern void func_L01_003A6898_003A6D88(Obj_003A5118 *o, s32 flag);
extern void func_L01_003A6D88(void *p);
extern void func_L01_003A6D88(void *);

 
void func_L01_003A6D88(void *p) {
    ((void (*)(void *, s32))func_L01_003A6898_003A6D88)(p, 0);
}
/* localdecomp:end func_L01_003A6D88 */

INCLUDE_ASM("asm/levels", func_L01_003A6DA8);

INCLUDE_ASM("asm/levels", func_L01_003A6EB0);

INCLUDE_ASM("asm/levels", func_L01_003A6F80);

INCLUDE_ASM("asm/levels", func_L01_003A7080);

INCLUDE_ASM("asm/levels", func_L01_003A70A8);

INCLUDE_ASM("asm/levels", func_L01_003A78E8);

INCLUDE_ASM("asm/levels", func_L01_003A7B38);

LINKER_REMNANT("asm/levels", func_L01_003A7D50);

INCLUDE_ASM("asm/levels", func_L01_003A7D70);

INCLUDE_ASM("asm/levels", func_L01_003A7DC0);

/* localdecomp:start func_L01_003A8048 */
extern s32 func_L01_00456250(void *);
extern s32 func_0038CAD0(s32 *);
extern void func_L01_004AADE8(s32, s32, void *, s32);
extern u8 *D_L01_001E001C;
extern s32 D_001D545C;
extern s32 D_L01_001DE370;
extern T_3A68C0 D_L01_00237800;
extern u8 D_001BBE90[];

s32 func_L01_003A8048(O_3A68C0 *o, S_3A68C0 *p) {
    s32 ok = 1;
    if (p->x0 != -1) {
        if (!func_L01_00456250(D_L01_001E001C + (p->x0 << 8))) ok = 0;
    }
    if (p->x4 != -1) {
        if (!func_L01_00456250(D_L01_001E001C + (p->x4 << 8))) ok = 0;
    }
    if (p->xD4) {
        u16 h = o->xB2;
        s32 b;
        if (D_L01_00237800.x464[(s16)h] || (b = D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)], (h & 1) ? (b >> 4) & 7 : b & 7)) ok = 1;
    }
    if (p->x68 != ok) {
        if (p->x6C == 0) p->x6C = D_L01_001DE370;
        if (func_0038CAD0(&p->x6C)) {
            s32 a, f;
            p->x68 = ok;
            if (p->xC && ok) {
                p->x0 = -1;
                p->x4 = -1;
            }
            if (ok) {
                a = p->x40;
                if (a < 0) goto done;
                f = p->x48;
            } else {
                a = p->x44;
                if (a < 0) goto done;
                f = p->x4C;
            }
            if (f == 0) func_L01_004AADE8(a, 0, D_L01_001E001C + (p->x8 << 8), 0);
        }
    } else {
        p->x6C = 0;
    }
done:
    if (p->xD4 && ok) {
        u16 h = o->xB2;
        if (h & 1) {
            u8 *q = &D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)];
            if (((*q >> 4) & 7) != 7) *q += 16;
        } else {
            u8 *q = &D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)];
            if ((*q & 7) != 7) *q += 1;
        }
    }
    return p->x68;
}
/* localdecomp:end func_L01_003A8048 */

INCLUDE_ASM("asm/levels", func_L01_003A8288);

INCLUDE_ASM("asm/levels", func_L01_003A8850);

/* localdecomp:start func_L01_003A8C98 */
extern void func_003C2880(Obj_003A5118 *);

extern void func_L01_003A8850(Obj003A7510 *);
extern void func_L01_00404808(void (*)(Obj003A7510 *), Obj003A7510 *);

void func_L01_003A8C98(Obj003A7510 *obj) {
    obj->timer++;
    func_L01_00404808(func_L01_003A8850, obj);
    if (obj->timer >= 7) {
        ((void (*)(Obj003A7510 *))func_003C2880)(obj);
    }
}
/* localdecomp:end func_L01_003A8C98 */

/* localdecomp:start func_L01_003A8CF0 */

extern u8 D_001A4EC0[];
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(u8 *, Vec4 *, f32);
extern void func_0038CE90(u8 *, u8 *, u8 *);

u8 *func_L01_003A8CF0(u8 *parent, Vec4 *a1, Vec4 *a2, f32 scale)
{
    Vec4 pos;
    Vec4 rot;
    u8 *m;
    Vec4 *rp = &rot;

    pos = *a1;
    rot = *a2;
    m = func_003C24B0(6387, 128);
    if (m != 0) {
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        m[32] = 0;
        *(u8 **)(m + 184) = parent;
        *(u128_t *)(m + 16) = pos.q;
        *(u16 *)(m + 52) |= 0x100;
        *(f32 *)(*(u8 **)(m + 104) + 16) = scale;
        *(f32 *)(m + 28) = scale;
        if (rp->f[0] != 0.0f || rp->f[1] != 0.0f || rp->f[2] != 0.0f) {
            func_0038CF68(m + 192, rp, 1.0f);
            func_0038CE90(m + 208, m + 192, D_001A4EC0);
            func_0038CF68(m + 208, (Vec4 *)(m + 208), 1.0f);
            func_0038CE90(m + 224, m + 208, m + 192);
        } else {
            *(u128_t *)(m + 192) = *(u128_t *)(parent + 192);
            *(u128_t *)(m + 208) = *(u128_t *)(parent + 208);
            *(u128_t *)(m + 224) = *(u128_t *)(parent + 224);
        }
    }
    return m;
}
/* localdecomp:end func_L01_003A8CF0 */

INCLUDE_ASM("asm/levels", func_L01_003A8E50);

/* localdecomp:start func_L01_003A93A0 */


extern u8 *func_003C24B0(int, int);
extern f32 func_00382538(void);
extern void func_0038D308(void *, void *);

u8 *func_L01_003A93A0(u8 *parent, s128_3A7C18 *a, s128_3A7C18 *pos, int n, f32 f) {
    u8 *m = func_003C24B0(6390, 128);
    V_3A7C18 *pv;

    if (m != 0) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        m[0x20] = 0;
        pv = *(V_3A7C18 **)(m + 0x68);
        *(long *)(m + 0x38) = *(long *)(parent + 0x38);
        *(s128_3A7C18 *)(m + 0x10) = *pos;
        pv->q0 = *a;
        pv->f14 = f;
        pv->parent = parent;
        pv->f20 = func_00382538();
        *(u16 *)(m + 0x34) |= 0x208;
        *(f32 *)((u8 *)pv + 0xC) = (f32)n;
        *(s128_3A7C18 *)(m + 0xF0) = *(s128_3A7C18 *)(parent + 0xF0);
        func_0038D308(m + 0xC0, m + 0xF0);
        m[0x23] = 0x80;
        *(u16 *)(m + 0x34) |= 0x100;
        pv->f18 = 0;
    }
    return m;
}
/* localdecomp:end func_L01_003A93A0 */

INCLUDE_ASM("asm/levels", func_L01_003A94A8);

/* localdecomp:start func_L01_003A9928 */
void func_L01_003A9928(u8 *obj) {
    *(u16 *)(obj + 52) |= 2;
}
/* localdecomp:end func_L01_003A9928 */

/* localdecomp:start func_L01_003A9938 */
void func_L01_003A9938(void *arg0) {
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 2);
}
/* localdecomp:end func_L01_003A9938 */

/* localdecomp:start func_L01_003A9948 */
void func_L01_003A9948(void *arg0) {
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 2);
}
/* localdecomp:end func_L01_003A9948 */

/* localdecomp:start func_L01_003A9958 */
void func_L01_003A9958(void *arg0) {
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 2);
}
/* localdecomp:end func_L01_003A9958 */

/* localdecomp:start func_L01_003A9968 */
void func_L01_003A9968(void *arg0) {
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 2);
}
/* localdecomp:end func_L01_003A9968 */

INCLUDE_ASM("asm/levels", func_L01_003A9978);

INCLUDE_ASM("asm/levels", func_L01_003AA018);

INCLUDE_ASM("asm/levels", func_L01_003AA120);

INCLUDE_ASM("asm/levels", func_L01_003AA618);

INCLUDE_ASM("asm/levels", func_L01_003AA658);

INCLUDE_ASM("asm/levels", func_L01_003AABB0);

INCLUDE_ASM("asm/levels", func_L01_003AADB8);

INCLUDE_ASM("asm/levels", func_L01_003AAE80);

/* localdecomp:start func_L01_003AB208 */


extern void func_0038D308(void *, void *);

void func_L01_003AB208(u8 *src, Moby_003A9A80 *m) {
    *(u128_003A9A80 *)(m->w64 + 16) = *(u128_003A9A80 *)(src + 16);
    *(u128_003A9A80 *)(m->w64 + 240) = *(u128_003A9A80 *)(src + 240);
    func_0038D308(m->w64 + 192, src + 240);
}
/* localdecomp:end func_L01_003AB208 */

/* localdecomp:start func_L01_003AB248 */

extern u8 D_001A30B0[];
extern void func_003A4F28(int);
extern void func_L01_0044EA78(S_3A9AC0m *, void *);
extern void func_L01_004AA7E8(S_3A9AC0m *, int);
extern void func_L01_004450F0(S_3A9AC0m *, int, int);

void func_L01_003AB248(int unused, S_3A9AC0o *o, int flag) {
    S_3A9AC0d *d = o->d;
    S_3A9AC0a *a;
    S_3A9AC0b *b;
    S_3A9AC0c *c;
    int i, j;
    int k = o->xD1C;

    if (k != -1) {
        S_3A9AC0e *e = (S_3A9AC0e *)(D_001A30B0 + k * 128);
        if (e->mDC == o->m && e->bD0 != 0) {
            func_003A4F28(k);
        }
    }
    o->xD1C = -1;
    func_L01_0044EA78(o->m, o->xBA0);
    if (d->n8 != 0) {
        a = d->pC;
        for (i = 0; i < d->n8; i++) {
            func_L01_0044EA78(o->m, (u8 *)o + (a->x4 * 128 + 160));
            a++;
        }
    }
    if (d->n34 != 0) {
        c = d->p38;
        for (j = 0; j < d->n34; j++) {
            if (c->n != 0) {
                b = c->p;
                for (i = 0; i < c->n; i++) {
                    func_L01_0044EA78(o->m, (u8 *)o + (b->x4 * 128 + 160));
                    b++;
                }
            }
            c++;
        }
    }
    o->m->h34 |= 0x41;
    o->m->h34 &= 0xEFFF;
    o->m->x98 = 0;
    func_L01_004AA7E8(o->m, 1);
    if (flag) {
        func_L01_004450F0(o->m, 1, -1);
        o->m->h34 |= 2;
    } else {
        o->m->b30 = 255;
        func_L01_004450F0(o->m, 3, -1);
    }
    o->d = 0;
    o->m = 0;
    o->xC48 = 0;
}
/* localdecomp:end func_L01_003AB248 */

/* localdecomp:start func_L01_003AB448 */

void func_L01_003AB448(u8 *obj, Vec4_003AB448 a, Vec4_003AB448 b) {
    *(Vec4_003AB448 *)(obj + 128) = a;
    *(Vec4_003AB448 *)(obj + 144) = b;
}
/* localdecomp:end func_L01_003AB448 */

/* localdecomp:start func_L01_003AB470 */
extern u8 D_001A4C60[];
extern u8 *D_L01_001E001C;
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern f32 *func_00382348(u8 *);

s32 func_L01_003AB470(s32 a0, u8 *p) {
    u8 *o;
    f32 *v;

    if (*(s32 *)(p + 0xC20) != -1 && func_00382380(D_001A4C60, *(s32 *)(p + 0xC20), 0) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0xC24) != -1 && func_L01_00456500(D_001A4C60, *(s32 *)(p + 0xC24)) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0xD28) != -1 && func_L01_00445AD0(*(s32 *)(p + 0xD28), -1, 0) <= *(s16 *)(p + 0xD2C)) {
        return 1;
    }
    if (*(s32 *)(p + 0xD24) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0xC28) != -1) {
        o = D_L01_001E001C + (*(s32 *)(p + 0xC28) << 8);
        if (o == 0 || o[0x20] == 254) {
            return 1;
        }
        if (o[0x20] == 253) {
            return 1;
        }
        v = func_00382348(o);
        if (v != 0 && *v <= 0.0f) {
            return 1;
        }
    }
    if (*(s32 *)(p + 0xC2C) != -1 && func_L01_00445AD0(*(s32 *)(p + 0xC2C), -1, 1) == 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003AB470 */

INCLUDE_ASM("asm/levels", func_L01_003AB598);

INCLUDE_ASM("asm/levels", func_L01_003AB5D0);

INCLUDE_ASM("asm/levels", func_L01_003AB790);

INCLUDE_ASM("asm/levels", func_L01_003ABD10);

INCLUDE_ASM("asm/levels", func_L01_003ABD60);

INCLUDE_ASM("asm/levels", func_L01_003ABE88);

INCLUDE_ASM("asm/levels", func_L01_003ABF48);

INCLUDE_ASM("asm/levels", func_L01_003AC000);

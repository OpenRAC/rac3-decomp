#include "common.h"

typedef struct {
    u8 pad0[6];
    s16 h6;
} S_4DBFE8_Ent;
typedef struct {
    u8 pad0[0x10];
    u8 b10;
    u8 pad11[2];
    u8 b13;
    u8 pad14[8];
    S_4DBFE8_Ent *entries[1];
} S_4DBFE8_Hdr;
typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[0x3F];
    S_4DBFE8_Hdr *hdrs[1];
} S_4DBFE8_Tbl;
typedef struct {
    u8 pad0[0x24];
    S_4DBFE8_Tbl *tbl;
} S_4DBFE8_Obj;
typedef struct { u8 pad[0xB0]; } S_4DC790;
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[8944];
    u128_t q[8];
    s32 i[8];
    f32 a[8];
    f32 b[8];
    s16 count;
} S_4DF808;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[128];
    s128 v128;
    s128 v144;
    u8 pad160[336];
    s16 h496;
    u8 pad498[126];
    f32 f624;
    f32 f628;
    u8 pad632[12];
    f32 f644;
    u8 pad648[9016];
    u8 *obj;
    u8 pad9668[8];
    s32 w9676;
} S_001A4BE0;
typedef struct {
    u8 p0[0x10];
    u128_t q10;
    u8 p20[0x98 - 0x20];
    s32 f98;
    u8 p9C[0xA8 - 0x9C];
    u8 bA8;
    u8 pA9[0xC0 - 0xA9];
    u8 fC0[0x30];
    u128_t qF0;
} Obj_4E09A8;
typedef struct {
    u8 p0[0x80];
    u128_t q80;
    u128_t q90;
    u8 pA0[0x1F0 - 0xA0];
    s16 h1F0;
    u8 p1F2[0x270 - 0x1F2];
    f32 f270;
    f32 f274;
    u8 p278[0x284 - 0x278];
    f32 f284;
    u8 p288[0x25C0 - 0x288];
    Obj_4E09A8 *f25C0;
    s32 f25C4;
    u8 p25C8[0x25E5 - 0x25C8];
    u8 b25E5;
} S_4E09A8;
typedef struct {
    u8 pad0[8800];
    f32 x2260;
    f32 x2264;
} S_004E1168;
typedef unsigned long u64l;
typedef struct {
    u64l a;
    u64l b;
    u64l c;
    u64l d;
} E_4E1758;
typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    u64l x10;
    u64l data[1];
} H_4E1758;
typedef struct { u8 pad[164]; f32 a; f32 b; } S_004E25C8;
typedef struct { u8 pad[340]; f32 a; f32 b; } S_004E25E0;
typedef struct { u8 pad[516]; f32 a; f32 b; } S_004E25F8;
typedef struct { u8 pad[692]; f32 a; f32 b; } S_004E2610;

INCLUDE_ASM("asm/levels", func_L01_004DF428);

INCLUDE_ASM("asm/levels", func_L01_004DF840);

/* localdecomp:start func_L01_004DFCC8 */




extern void func_L01_0043C8F8(S_4DBFE8_Ent **, S_4DBFE8_Ent *, s32, s32);
extern void func_0038CD28(s32, S_4DBFE8_Ent *, s32);
extern void func_0011F0A0(s32);

s32 func_L01_004DFCC8(S_4DBFE8_Obj *obj, s32 a, s32 b, s32 out) {
    S_4DBFE8_Tbl *tbl = obj->tbl;
    S_4DBFE8_Hdr *hdr = tbl->hdrs[a];
    S_4DBFE8_Ent *ent = hdr->entries[b];
    if ((u32)ent & 0xF0000000) {
        func_L01_0043C8F8(&hdr->entries[hdr->b10] + hdr->b13, ent, out, tbl->b8);
    } else {
        func_0038CD28(out, ent, (ent->h6 + 1) << 4);
    }
    func_0011F0A0(0);
    return out;
}
/* localdecomp:end func_L01_004DFCC8 */

INCLUDE_ASM("asm/levels", func_L01_004DFD60);

INCLUDE_ASM("asm/levels", func_L01_004DFDB0);

INCLUDE_ASM("asm/levels", func_L01_004DFE80);

INCLUDE_ASM("asm/levels", func_L01_004DFE88);

INCLUDE_ASM("asm/levels", func_L01_004DFEA0);

/* localdecomp:start func_L01_004E0100 */
extern s32 D_001A71A0[];
extern s32 D_001A5ED4[];
extern s32 D_001A5DE0[];

s32 func_L01_004E0100(s32 a0) {
    if (a0 == 0 || a0 == 2 || a0 == 3 || a0 == 4 || a0 == 6) {
        return D_001A71A0[0];
    }
    if (a0 == 1) {
        return D_001A5ED4[0];
    }
    if (a0 == 7) {
        return D_001A5DE0[0];
    }
    return 0;
}
/* localdecomp:end func_L01_004E0100 */

INCLUDE_ASM("asm/levels", func_L01_004E0160);

/* localdecomp:start func_L01_004E04A0 */
extern S_4DC790 D_L01_002F4540[];
void func_L01_004E0160(S_4DC790 *);
void func_L01_004E04A0(void) {
    s32 i;
    for (i = 0; i < 43; i++) func_L01_004E0160(&D_L01_002F4540[i]);
}
/* localdecomp:end func_L01_004E04A0 */

INCLUDE_ASM("asm/levels", func_L01_004E04E8);

INCLUDE_ASM("asm/levels", func_L01_004E0580);

INCLUDE_ASM("asm/levels", func_L01_004E0618);

INCLUDE_ASM("asm/levels", func_L01_004E0920);

INCLUDE_ASM("asm/levels", func_L01_004E0C18);

/* localdecomp:start func_L01_004E0CB0 */
extern s32 D_001A6634[];
extern void func_L01_004E3268(void);

void func_L01_004E0CB0(void) {
    if (D_001A6634[0]) {
        func_L01_004E3268();
    }
}
/* localdecomp:end func_L01_004E0CB0 */

INCLUDE_ASM("asm/levels", func_L01_004E0CD8);

INCLUDE_ASM("asm/levels", func_L01_004E1020);

INCLUDE_ASM("asm/levels", func_L01_004E1180);

/* localdecomp:start func_L01_004E11C0 */
extern G_4DD4B0 D_001A4BE0;
extern void func_L01_004AAF20(s32, s32, s32, s32, s32, s32);
void func_L01_004E11C0(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 buf[32];
    if (a2 != 0) {
        s32 f = 0;
        if (D_001A4BE0.f1250 != 0) {
            f = D_001A4BE0.f1278 == 13;
        }
        a3 = (a3 << 10) / 30;
        func_L01_004AAF20(a0, a1, f, 0, D_001A4BE0.f25C0, a3);
    }
}
/* localdecomp:end func_L01_004E11C0 */

INCLUDE_ASM("asm/levels", func_L01_004E1218);

INCLUDE_ASM("asm/levels", func_L01_004E13A0);

INCLUDE_ASM("asm/levels", func_L01_004E1560);

INCLUDE_ASM("asm/levels", func_L01_004E1638);

INCLUDE_ASM("asm/levels", func_L01_004E1F00);

INCLUDE_ASM("asm/levels", func_L01_004E20E8);

/* localdecomp:start func_L01_004E26A0 */
extern s32 D_001D545C;
extern s32 func_L01_005143C0(s32);

s32 func_L01_004E26A0(void) {
    s32 r = 0;

    switch (D_001D545C) {
    case 9:
        r = func_L01_005143C0(4) != 0;
        break;
    case 19:
        if (func_L01_005143C0(1) || func_L01_005143C0(2)) {
            r = 1;
        }
        break;
    }
    return r;
}
/* localdecomp:end func_L01_004E26A0 */

INCLUDE_ASM("asm/levels", func_L01_004E2720);

INCLUDE_ASM("asm/levels", func_L01_004E27A0);

INCLUDE_ASM("asm/levels", func_L01_004E27A8);

INCLUDE_ASM("asm/levels", func_L01_004E2988);

INCLUDE_ASM("asm/levels", func_L01_004E2C48);

INCLUDE_ASM("asm/levels", func_L01_004E2DC8);

INCLUDE_ASM("asm/levels", func_L01_004E2E30);

INCLUDE_ASM("asm/levels", func_L01_004E2ED0);

INCLUDE_ASM("asm/levels", func_L01_004E3148);

/* localdecomp:start func_L01_004E3268 */
extern G_4DD4B0 D_001A4BE0;
extern char func_L01_004E32A8[];
extern void func_L01_00404808(char *, s32);
void func_L01_004E3268(void) {
    u8 *b = ((u8 *)&D_001A4BE0);
    if (*(s16 *)(b + 9170) == 0) {
        *(s16 *)(b + 9170) = 1;
        func_L01_00404808(func_L01_004E32A8, *(s32 *)(b + 9664));
    }
}
/* localdecomp:end func_L01_004E3268 */

INCLUDE_ASM("asm/levels", func_L01_004E32A8);

/* localdecomp:start func_L01_004E35D0 */
extern G_4DD4B0 D_001A4BE0;


extern void func_L01_004E3268(void);

void func_L01_004E35D0(u128_t *v, s32 n, f32 x, f32 y) {
    S_4DF808 *s = &(*(S_4DF808 *)&D_001A4BE0);

    if (s->count < 8) {
        s->q[s->count] = *v;
        s->i[s->count] = n;
        s->a[s->count] = x;
        s->b[s->count] = y;
        func_L01_004E3268();
        s->count++;
    }
}
/* localdecomp:end func_L01_004E35D0 */

INCLUDE_ASM("asm/levels", func_L01_004E3650);

/* localdecomp:start func_L01_004E45C8 */
extern G_4DD4B0 D_001A4BE0;


extern void func_L01_004E2DC8(void);
extern void func_L01_004E2E30(void);
extern void func_0038CC88(void *, void *, s32);
extern void func_003C7C38(void *);
extern void func_L01_00511158(s128 *, s128 *, f32);
extern void func_L01_00439790(void *, s32, s128 *, f32, f32);
extern s32 func_L01_004E9308(void);

void func_L01_004E45C8(void) {
    s128 v;
    u8 *o;
    f32 d;
    f32 f;

    (*(S_001A4BE0 *)&D_001A4BE0).obj[168] = 255;
    *(s128 *)((*(S_001A4BE0 *)&D_001A4BE0).obj + 16) = (*(S_001A4BE0 *)&D_001A4BE0).v128;
    func_L01_004E2DC8();
    *(s128 *)((*(S_001A4BE0 *)&D_001A4BE0).obj + 240) = (*(S_001A4BE0 *)&D_001A4BE0).v144;
    func_L01_004E2E30();
    func_0038CC88((*(S_001A4BE0 *)&D_001A4BE0).obj + 192, &(*(S_001A4BE0 *)&D_001A4BE0), 48);
    func_003C7C38((*(S_001A4BE0 *)&D_001A4BE0).obj);
    o = (*(S_001A4BE0 *)&D_001A4BE0).obj;
    if (*(u8 **)(o + 36) != 0 && (*(u8 **)(o + 36))[6] != 0) {
        o[99] = 16;
    } else {
        (*(S_001A4BE0 *)&D_001A4BE0).obj[99] = 16;
    }
    if ((*(S_001A4BE0 *)&D_001A4BE0).h496 != 0) {
        return;
    }
    if (*(s32 *)((*(S_001A4BE0 *)&D_001A4BE0).obj + 152) == 0) {
        return;
    }
    v = (*(S_001A4BE0 *)&D_001A4BE0).v128;
    func_L01_00511158(&v, &v, (*(S_001A4BE0 *)&D_001A4BE0).f628);
    d = (*(S_001A4BE0 *)&D_001A4BE0).f624 - (*(S_001A4BE0 *)&D_001A4BE0).f628;
    if (d < 0.05f) {
        d = 0.05f;
    }
    func_L01_00439790((*(S_001A4BE0 *)&D_001A4BE0).obj, 0, &v, (*(S_001A4BE0 *)&D_001A4BE0).f644, d);
    f = (*(S_001A4BE0 *)&D_001A4BE0).f644 + 0.05f;
    if ((*(S_001A4BE0 *)&D_001A4BE0).w9676 == 4) {
        f += 0.15f;
    }
    if (func_L01_004E9308() != 0) {
        f = (*(S_001A4BE0 *)&D_001A4BE0).f628;
    }
    v = (*(S_001A4BE0 *)&D_001A4BE0).v128;
    func_L01_00511158(&v, &v, f);
    d = (*(S_001A4BE0 *)&D_001A4BE0).f624 - f;
    if (d < 0.05f) {
        d = 0.05f;
    }
    func_L01_00439790((*(S_001A4BE0 *)&D_001A4BE0).obj, 1, &v, (*(S_001A4BE0 *)&D_001A4BE0).f644, d);
}
/* localdecomp:end func_L01_004E45C8 */

/* localdecomp:start func_L01_004E4770 */
extern void func_L01_00439790(void *, s32, s128 *, f32, f32);
extern void func_003C7C38(void *);
extern G_4DD4B0 D_001A4BE0;
extern void func_L01_00510C28(void);
extern void func_L01_00510C60(void);
extern void func_0038CC88(void *, void *, s32);
extern void func_L01_00511158(u128_t *, u128_t *, f32);
void func_L01_004E4770(void) {
    S_4E09A8 *p;
    u128_t v;
    f32 r;

    if ((*(S_4E09A8 *)&D_001A4BE0).b25E5 != 0) {
        func_L01_00510C28();
    } else {
        func_L01_00510C60();
    }
    p = &(*(S_4E09A8 *)&D_001A4BE0);
    p->f25C0->bA8 = 255;
    p->f25C0->q10 = p->q80;
    p->f25C0->qF0 = p->q90;
    func_0038CC88(p->f25C0->fC0, p, 48);
    ((void (*)(Obj_4E09A8 *))func_003C7C38)(p->f25C0);
    if (p->h1F0 != 0) {
        return;
    }
    if (p->f25C0->f98 == 0) {
        return;
    }
    v = p->q80;
    func_L01_00511158(&v, &v, p->f274);
    ((void (*)(Obj_4E09A8 *, s32, u128_t *, f32, f32))func_L01_00439790)(p->f25C0, 0, &v, p->f284, p->f270 - p->f274);
    r = p->f284 + 0.05f;
    v = p->q80;
    func_L01_00511158(&v, &v, r);
    ((void (*)(Obj_4E09A8 *, s32, u128_t *, f32, f32))func_L01_00439790)(p->f25C0, 1, &v, p->f284, p->f270 - r);
    if (p->f25C4 == 163) {
        ((void (*)(Obj_4E09A8 *, s32, u128_t *, f32, f32))func_L01_00439790)(p->f25C0, 0, &v, p->f284, p->f270 - r);
    }
}
/* localdecomp:end func_L01_004E4770 */

INCLUDE_ASM("asm/levels", func_L01_004E48C8);

/* localdecomp:start func_L01_004E4F30 */
extern G_4DD4B0 D_001A4BE0;


extern f32 func_003C4138(f32 *, f32, f32);

void func_L01_004E4F30(f32 *out, f32 *st, f32 k) {
    f32 buf[2];

    buf[0] = -(*(S_004E1168 *)&D_001A4BE0).x2260;
    buf[1] = -(*(S_004E1168 *)&D_001A4BE0).x2264;
    func_003C4138(&st[2], buf[0], k);
    if (st[2] > 1.0f) {
        st[2] = 1.0f;
    }
    if (st[2] < -1.0f) {
        st[2] = -1.0f;
    }
    out[0] = st[2];
    func_003C4138(&st[1], buf[1], k);
    if (st[1] > 1.0f) {
        st[1] = 1.0f;
    }
    if (st[1] < -1.0f) {
        st[1] = -1.0f;
    }
    out[1] = st[1];
}
/* localdecomp:end func_L01_004E4F30 */

INCLUDE_ASM("asm/levels", func_L01_004E5030);

INCLUDE_ASM("asm/levels", func_L01_004E5130);

INCLUDE_ASM("asm/levels", func_L01_004E51A0);

INCLUDE_ASM("asm/levels", func_L01_004E5290);

INCLUDE_ASM("asm/levels", func_L01_004E52E0);

/* localdecomp:start func_L01_004E5520 */



extern E_4E1758 D_L01_00251A80[];
extern E_4E1758 D_L01_00251A88[];
extern E_4E1758 D_L01_00251A90[];
extern u64l func_L01_0040E8B0(u8 *, f32);

void func_L01_004E5520(s32 *list, H_4E1758 *out, u8 *src, s32 pad) {
    u64l *p;
    u64l *q;
    s32 n, nb, nc, j, k, sz, i, tot;
    u64l v;

    out->x10 = 0x7FFF000000000000;
    p = out->data;
    for (n = 1; list[n] >= 0; n++) {
        *p++ = D_L01_00251A80[list[n]].a;
    }
    for (i = 0; i < pad; i++, n++) {
        *p++ = 0x7FFF000000000000;
    }
    nb = 0;
    k = 1;
    sz = n * 8;
    for (; list[k] >= 0; k++) {
        u64l w = D_L01_00251A88[list[k]].a;
        if (w != 0x100010001000) {
            *p = w;
            nb++;
            ((u16 *)p)[3] = k | 0x8000;
            p++;
        }
    }
    tot = n + nb;
    nc = 0;
    for (j = 1; list[j] >= 0; j++) {
        v = D_L01_00251A90[list[j]].a;
        if (v != (func_L01_0040E8B0(*(u8 **)(src + 24) + j * 16, 1.0f) & 0xFFFFFFFFFFFF)) {
            *p = v;
            nc++;
            ((u16 *)p)[3] = j;
            p++;
        }
    }
    if ((s32)p & 0xF) {
        *p++ = 0;
    }
    out->h0 = 0;
    out->h2 = 0;
    out->h4 = 0;
    q = p - 2;
    out->h6 = ((s32)q - (s32)out) >> 4;
    out->h8 = sz;
    out->hA = nb;
    out->hC = tot * 8;
    out->hE = nc;
}
/* localdecomp:end func_L01_004E5520 */

INCLUDE_ASM("asm/levels", func_L01_004E5748);

INCLUDE_ASM("asm/levels", func_L01_004E5840);

INCLUDE_ASM("asm/levels", func_L01_004E5A20);

INCLUDE_ASM("asm/levels", func_L01_004E5C08);

INCLUDE_ASM("asm/levels", func_L01_004E5EB8);

INCLUDE_ASM("asm/levels", func_L01_004E60E8);

/* localdecomp:start func_L01_004E6390 */
extern S_4DC790 D_L01_002F4540[];
void func_L01_004E6390(f32 a, f32 b) {
    (*(S_004E25C8 *)&D_L01_002F4540).a = a;
    (*(S_004E25C8 *)&D_L01_002F4540).b = b;
}
/* localdecomp:end func_L01_004E6390 */

/* localdecomp:start func_L01_004E63A8 */
extern S_4DC790 D_L01_002F4540[];
void func_L01_004E63A8(f32 a, f32 b) {
    (*(S_004E25E0 *)&D_L01_002F4540).a = a;
    (*(S_004E25E0 *)&D_L01_002F4540).b = b;
}
/* localdecomp:end func_L01_004E63A8 */

/* localdecomp:start func_L01_004E63C0 */
extern S_4DC790 D_L01_002F4540[];
void func_L01_004E63C0(f32 a, f32 b) {
    (*(S_004E25F8 *)&D_L01_002F4540).a = a;
    (*(S_004E25F8 *)&D_L01_002F4540).b = b;
}
/* localdecomp:end func_L01_004E63C0 */

/* localdecomp:start func_L01_004E63D8 */
extern S_4DC790 D_L01_002F4540[];
void func_L01_004E63D8(f32 a, f32 b) {
    (*(S_004E2610 *)&D_L01_002F4540).a = a;
    (*(S_004E2610 *)&D_L01_002F4540).b = b;
}
/* localdecomp:end func_L01_004E63D8 */

INCLUDE_ASM("asm/levels", func_L01_004E63F0);

INCLUDE_ASM("asm/levels", func_L01_004E64C0);

INCLUDE_ASM("asm/levels", func_L01_004E67C0);

INCLUDE_ASM("asm/levels", func_L01_004E67F8);

INCLUDE_ASM("asm/levels", func_L01_004E6D10);

INCLUDE_ASM("asm/levels", func_L01_004E6D18);

#include "common.h"

typedef void (*FnVt_006C7F08)(void *, s32, s32);

/* localdecomp:start func_L39_006C69C0 */
typedef struct { s32 a, b, c, type; } S_006C69C0;
extern S_006C69C0 D_L39_004B1768_006C69C0[][25];
extern char D_002497D0[];
extern f32 D_001DDFFC_sda;
extern f32 D_001DE000_sda;
extern f32 D_001DDF60_sda;
extern f32 D_001DDF58_sda;
extern f32 D_001DDF10_sda;
extern s32 func_00381FF0();
__asm__(".extern D_001DDFFC_sda, 4");
__asm__(".extern D_001DE000_sda, 4");
__asm__(".extern D_001DDF60_sda, 4");
__asm__(".extern D_001DDF58_sda, 4");
__asm__(".extern D_001DDF10_sda, 4");

void func_L39_0068A4A8(void *, s32, s32, u32, f32, f32, f32, f32);
typedef struct O_006C69C0 O_006C69C0;
typedef struct {
    u8 pad[0x6C];
    void (*f6C)(O_006C69C0 *, s32, char **);
    u8 pad2[0x94 - 0x70];
    void (*f94)(O_006C69C0 *, f32);
} Vt_006C69C0;
struct O_006C69C0 { u8 pad[0x60]; Vt_006C69C0 *vt; };

void func_L39_006C69C0(u8 *arg0, s32 idx) {
    char *names[25];
    s32 count;
    s32 i;
    s32 n;

    if (idx == -1) {
        idx = *(s32 *)(arg0 + 0xD4C);
    }
    count = 0;
    for (i = 0; i < 25 && D_L39_004B1768_006C69C0[idx][i].a != 0; i++) {
        if (D_L39_004B1768_006C69C0[idx][i].b != 0) {
            names[i] = (char *)func_00381FF0(D_L39_004B1768_006C69C0[idx][i].b);
        } else {
            names[i] = D_002497D0;
        }
        count++;
    }
    (*(O_006C69C0 **)(arg0 + 0x12C))->vt->f6C(*(O_006C69C0 **)(arg0 + 0x12C), count, names);
    if (idx == 6) {
        (*(O_006C69C0 **)(arg0 + 0x12C))->vt->f94(*(O_006C69C0 **)(arg0 + 0x12C), D_001DDFFC_sda);
    } else {
        (*(O_006C69C0 **)(arg0 + 0x12C))->vt->f94(*(O_006C69C0 **)(arg0 + 0x12C), D_001DE000_sda);
    }
    n = count - 1;
    if (n >= 13) {
        n = 12;
    }
    func_L39_0068A4A8(arg0, 0, n, 0x332299DE, D_001DDF58_sda, 0.265f, D_001DDF10_sda, D_001DDF60_sda - 0.035f);
}
/* localdecomp:end func_L39_006C69C0 */

/* localdecomp:start func_L39_006C6B30 */
/* best: 72 diff, all register allocation. Control flow, calls, args, float/$gp loads all line up.
 * Left: self in $s2 and i in $s1 (retail swaps them); in both item loops the vt/fn loads use
 * $v0/$v1 swapped vs retail. Tried: items pointer walk, items[i] index, it/vt/fn temps, i
 * scoped per branch, void *arg0 + local struct, `count >= i`. ee29: no match.
 * $gp floats need `.extern X, 4` hints; D_001DE008_sda array uses a size-8 hint (real size unknown). */
typedef struct W_006C6B30 W_006C6B30;
typedef struct {
    u8 pad0[0x1C];
    s32 (*setState)(W_006C6B30 *, s32, s32);
    u8 pad20[0x88 - 0x20];
    void (*select)(W_006C6B30 *, s32);
    u8 pad8C[0xB8 - 0x8C];
    void (*setText)(W_006C6B30 *, u8 *);
} VT_006C6B30;
struct W_006C6B30 {
    u8 pad0[0x60];
    VT_006C6B30 *vt;
};

__asm__(".extern D_001DDF3C_sda, 4");
extern f32 D_001DDF3C_sda;
__asm__(".extern D_001DDF44_sda, 4");
extern f32 D_001DDF44_sda;
__asm__(".extern D_001DDF4C_sda, 4");
extern f32 D_001DDF4C_sda;
__asm__(".extern D_001DDF54_sda, 4");
extern f32 D_001DDF54_sda;
__asm__(".extern D_001DDF58_sda, 4");
extern f32 D_001DDF58_sda;
__asm__(".extern D_001DDF5C_sda, 4");
extern f32 D_001DDF5C_sda;
__asm__(".extern D_001DDF60_sda, 4");
extern f32 D_001DDF60_sda;
__asm__(".extern D_001DDF64_sda, 4");
extern f32 D_001DDF64_sda;
__asm__(".extern D_001DDF68_sda, 4");
extern f32 D_001DDF68_sda;
__asm__(".extern D_001DDF6C_sda, 4");
extern f32 D_001DDF6C_sda;
__asm__(".extern D_001DDF70_sda, 4");
extern f32 D_001DDF70_sda;
__asm__(".extern D_001DDF74_sda, 4");
extern f32 D_001DDF74_sda;
__asm__(".extern D_001DDFBC_sda, 4");
extern f32 D_001DDFBC_sda;
__asm__(".extern D_001DDFC0_sda, 4");
extern f32 D_001DDFC0_sda;
__asm__(".extern D_001DDFC8_sda, 4");
extern f32 D_001DDFC8_sda;
__asm__(".extern D_001DDFD0_sda, 4");
extern f32 D_001DDFD0_sda;
__asm__(".extern D_001DDFD4_sda, 4");
extern f32 D_001DDFD4_sda;
__asm__(".extern D_001DDFE0_sda, 4");
extern f32 D_001DDFE0_sda;
__asm__(".extern D_001DDFE4_sda, 4");
extern f32 D_001DDFE4_sda;
__asm__(".extern D_001DDFF0_sda, 4");
extern f32 D_001DDFF0_sda;
__asm__(".extern D_001DDFF4_sda, 4");
extern f32 D_001DDFF4_sda;
__asm__(".extern D_001DE008_sda, 8");
extern s32 D_001DE008_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DE054_sda, 4");
extern f32 D_001DE054_sda;
__asm__(".extern D_001DE058_sda, 4");
extern f32 D_001DE058_sda;
__asm__(".extern D_001DE05C_sda, 4");
extern f32 D_001DE05C_sda;
__asm__(".extern D_001DE060_sda, 4");
extern f32 D_001DE060_sda;

extern void func_L39_006C7E98(void *);
extern void func_L39_006C7F08(void *);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A7B8(void *, s32, u32, f32, f32, f32, f32);

typedef struct {
    u8 pad0[0x110];
    W_006C6B30 *items[7]; /* 0x110 */
    W_006C6B30 *w12C, *w130, *w134, *w138, *w13C, *w140, *w144, *w148;
    u8 pad14C[0x19C - 0x14C];
    W_006C6B30 *w19C, *w1A0;
    u8 pad1A4[0xB64 - 0x1A4];
    s32 sel; /* 0xB64 */
    u8 padB68[0xD4C - 0xB68];
    s32 mode; /* 0xD4C */
    s32 count; /* 0xD50 */
} S_006C6B30;


void func_L39_006C6B30(S_006C6B30 *self, s32 mode, s32 arg2) {
    s32 i;

    if (mode == 0) {
        for (i = 0; i <= self->count; i++) {
            self->items[i]->vt->setState(self->items[i], 3, 0);
        }
        self->w138->vt->setState(self->w138, 1, 0);
        self->w19C->vt->setState(self->w19C, 1, 0);
        self->w1A0->vt->setState(self->w1A0, 1, 0);
        self->w12C->vt->setState(self->w12C, 0, 0);
        func_L39_006C7E98(self);
        self->w130->vt->setState(self->w130, 0, 0);
        self->w140->vt->setState(self->w140, 0, 0);
        self->w148->vt->setState(self->w148, 0, 0);
        self->w144->vt->setState(self->w144, 0, 0);
        self->w13C->vt->setState(self->w13C, 0, 0);
        func_L39_0068A6D0(self, 0, D_001DDF58_sda, D_001DDF3C_sda, D_001DDF60_sda, D_001DDF44_sda, 0x332299DE);
        func_L39_0068A4A8(self, 0, 5, 0x332299DE, D_001DDF58_sda, D_001DDFBC_sda, D_001DDFC0_sda, D_001DDF60_sda - 0.035f);
        func_L39_0068A6D0(self, 1, D_001DDF58_sda, D_001DDF4C_sda, D_001DDF60_sda, D_001DDF54_sda, 0x332299DE);
        func_L39_0068A6D0(self, 2, D_001DDF68_sda, D_001DDF6C_sda, D_001DDF70_sda, D_001DDF74_sda, 0x332299DE);
        func_L39_0068A4A8(self, 3, 0, 0x332299DE, D_001DE054_sda, D_001DE058_sda, D_001DE05C_sda, D_001DE060_sda);
        func_L39_0068A7B8(self, 0, 0x331465B7, D_001DDF58_sda, D_001DDFF0_sda, D_001DDFF4_sda, D_001DDF60_sda - 0.02f);
        func_L39_0068A7B8(self, 1, 0, 0.0f, 0.0f, 0.0f, 0.0f);
    } else if (mode == 1) {
        VT_006C6B30 *vt;

        for (i = 0; i <= self->count; i++) {
            self->items[i]->vt->setState(self->items[i], 0, 0);
        }
        self->w138->vt->setState(self->w138, 0, 0);
        self->w19C->vt->setState(self->w19C, 0, 0);
        self->w12C->vt->setState(self->w12C, 3, 0);
        if (arg2) {
            func_L39_006C7F08(self);
            self->w1A0->vt->setState(self->w1A0, 0, 0);
            self->w130->vt->setState(self->w130, 1, 0);
            self->w140->vt->setState(self->w140, 1, 0);
            self->w148->vt->setState(self->w148, 1, 0);
            self->w144->vt->setState(self->w144, 1, 0);
        } else {
            func_L39_006C7E98(self);
            self->w1A0->vt->setState(self->w1A0, 1, 0);
            self->w130->vt->setState(self->w130, 0, 0);
            self->w140->vt->setState(self->w140, 0, 0);
            self->w148->vt->setState(self->w148, 0, 0);
            self->w144->vt->setState(self->w144, 0, 0);
        }
        self->w13C->vt->setState(self->w13C, 1, 0);
        vt = self->w13C->vt;
        vt->setText(self->w13C, (u8 *)func_00381FF0(D_001DE008_sda[self->mode]));
        func_L39_0068A6D0(self, 0, D_001DDF58_sda, D_001DDF5C_sda, D_001DDF60_sda, D_001DDF64_sda, 0x332299DE);
        func_L39_0068A6D0(self, 1, D_001DDF58_sda, D_001DDF5C_sda, D_001DDF60_sda, D_001DDF64_sda, 0x332299DE);
        func_L39_0068A6D0(self, 2, D_001DDF68_sda, D_001DDF6C_sda, D_001DDF70_sda, D_001DDF74_sda, 0x332299DE);
        if (arg2) {
            func_L39_0068A7B8(self, 0, 0x331465B7, D_001DDF68_sda, D_001DDFD0_sda, D_001DDFD4_sda, D_001DDF70_sda - 0.02f);
            func_L39_0068A4A8(self, 3, 9, 0x332299DE, D_001DDF68_sda, D_001DE058_sda, D_001DDFC8_sda, D_001DDF70_sda - 0.035f);
        } else {
            func_L39_0068A7B8(self, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f);
            func_L39_0068A4A8(self, 3, 0, 0x332299DE, D_001DE054_sda, D_001DE058_sda, D_001DE05C_sda, D_001DE060_sda);
        }
        func_L39_0068A7B8(self, 1, 0x331465B7, D_001DDF58_sda, D_001DDFE0_sda, D_001DDFE4_sda, D_001DDF60_sda - 0.02f);
        func_L39_006C69C0((u8 *)self, -1);
        self->w12C->vt->select(self->w12C, self->sel);
    }
}
/* localdecomp:end func_L39_006C6B30 */

/* localdecomp:start func_L39_006C7128 */
typedef void (*FnP_006C7128)(void *, void *);
typedef void (*FnI_006C7128)(void *, s32);
typedef struct { s32 w[0x23]; } Blk_006C7128;
typedef struct { char *s; s32 n; } Str_006C7128;
typedef struct O_006C7128 O_006C7128;
typedef struct { u8 pad[0x50]; void (*f50)(O_006C7128 *, s32); } Vt_006C7128;
struct O_006C7128 { u8 pad[0x60]; Vt_006C7128 *vt; };
typedef struct { u8 pad[0x110]; O_006C7128 *objs[0x296]; } P_006C7128;
extern void *D_0024D760[] __attribute__((section(".sdata")));
extern u8 D_001A5CD0[];
extern char D_003847C8[];
extern char D_0024D400[0x28] __attribute__((section(".sdata")));
extern char D_0024D428[0x28] __attribute__((section(".sdata")));
extern char D_0024D3E0[0x100] __attribute__((section(".sdata")));
extern char D_002497D8[];
extern char D_002497E0[];
extern char D_00249780[];
extern char D_00249788[];
extern s32 D_001DDF0C_sda;
extern Str_006C7128 D_001E1C50_sda;
__asm__(".extern D_001E1C50_sda, 8");
s32 func_00381FF0(s32);
s32 func_00120884(s32);
s32 func_00120048(char *, const char *, ...);
s32 func_L39_006D6750(u8 *, s32, s32, s32);
u8 *func_L39_006D6CF8(u8 *, s32, s32, s32);
s32 func_L39_006D6E50(u8 *, s32, s32, void *);
void func_L39_005958A0(Str_006C7128 *, s32, s32);
void func_L39_006C7D28(u8 *, s32, s32, void *);
void func_L39_006C7E10(u8 *, s32);
void func_L39_006C7FA0(u8 *, s32);
s32 func_L39_006C7CE8(u8 *);
void func_L39_006C7C40(u8 *, s32);
void func_L39_006C7B40(u8 *, char *, s32, s32);

void func_L39_006C7128(u8 *p) {
    char buf[0x20];
    char *names[12];
    char *blank[12];
    char *one;
    u8 *g = *(u8 **)((u8 *)D_0024D760[0] + 0x44);
    u8 *entry;
    u8 *list;
    u8 *r;
    s32 sel;
    s32 i;
    s32 n;
    s32 *vals;
    u8 *gs0;

    if (p[0x2AC] == 1) {
        if (g[8]) {
            return;
        }
        if (!p[0x2B4]) {
            p[0x2B4] = 1;
            func_L39_006D6750(g, *(s32 *)(p + 0xBA4), 1, *(s32 *)(p + 0xBA8));
            gs0 = D_001A5CD0;
            *(s32 *)(p + 0x2B0) = *(s32 *)(g + 0x10);
            r = func_L39_006D6CF8(g, *(s32 *)(gs0 + 0x34), *(s32 *)(p + 0xBA4), 1);
            if (r) {
                *(s32 *)(p + 0xBAC) = *(s32 *)(r + 0x20);
                *(s32 *)(p + 0xD48) = *(s32 *)(r + 0x1C);
            }
            p[0x2AC] = 0;
        }
    }
    if (g[8] || !p[0x2B4] || *(s32 *)(g + 0x10) == *(s32 *)(p + 0x2B0)) {
        return;
    }
    entry = 0;
    if (g[0] && *(s32 *)(g + 4) >= 0) {
        entry = g + (*(s32 *)(g + 4) * 12 + 0x68);
    }
    p[0x2B4] = 0;
    vals = (s32 *)(p + 0xBB8);
    if (*(s32 *)(p + 0xBB4) == 0) {
        if (func_L39_006D6E50(g, *(s32 *)(D_001A5CD0 + 0x34), 0, vals)) {
            *(s32 *)(p + 0xBB4) = 1;
        }
    }
    if (*(s32 *)(p + 0xBB4)) {
        func_L39_006C7B40(p, buf, *(s32 *)((u8 *)vals + (*(s32 *)(p + 0xBA4) << 2)), *(s32 *)(p + 0xD48));
        func_00120048(D_0024D400, D_002497D8, func_00381FF0(0x1940), buf);
        func_00120048(D_0024D428, D_002497E0, func_00381FF0(0x1941), *(s32 *)(p + 0xD48));
        ((FnP_006C7128)((void **)(*(O_006C7128 **)(p + 0x144))->vt)[0xB8 / 4])(*(void **)(p + 0x144), D_0024D400);
        ((FnP_006C7128)((void **)(*(O_006C7128 **)(p + 0x148))->vt)[0xB8 / 4])(*(void **)(p + 0x148), D_0024D428);
    }
    if (!entry || *(s32 *)(g + 0x10) == *(s32 *)(p + 0x2B0)) {
        return;
    }
    *(s32 *)(p + 0x2B0) = *(s32 *)(g + 0x10);
    if ((*(s32 *)(p + 0x2B8) = *(s32 *)(entry + 4)) == 0 && *(s32 *)(p + 0xBA8) == 1) {
        s32 a;
        p[0xB60] = 0;
        one = (char *)func_00381FF0(0x1328);
        a = func_00381FF0(0x1328);
        func_L39_005958A0(&D_001E1C50_sda, a, func_00120884(func_00381FF0(0x1328)));
        one = (char *)&D_001E1C50_sda;
        func_L39_006C7D28(p, 0, 1, &one);
        func_L39_006C7E10(p, 1);
        func_L39_006C7FA0(p, 2);
        return;
    }
    p[0xB60] = 1;
    if (*(s32 *)(p + 0x2B8) > 10) {
        *(s32 *)(p + 0x2B8) = 10;
    }
    sel = func_L39_006C7CE8(p);
    list = *(u8 **)((u8 *)D_0024D760[0] + 0x34);
    if (*(s32 *)(p + 0x2B8) - 1 < sel) {
        sel = 0;
    }
    for (i = 0; i < *(s32 *)(p + 0x2B8); i++) {
        u8 *e = ((u8 **)*(u8 **)(entry + 8))[i];
        s32 id;
        s32 found;
        s32 res;
        u8 *gs;
        names[i] = (char *)(e + 0x28);
        *(s32 *)((p + (i << 2)) + 0x2BC) = *(s32 *)(e + 0x24);
        *(Blk_006C7128 *)(p + i * 0x8C + 0x2F8) = *(Blk_006C7128 *)(e + 0x148);
        func_L39_006C7B40(p, D_003847C8 + i * 30, *(s32 *)(e + 0x20), *(s32 *)(p + 0xBA8) + i);
        ((P_006C7128 *)p)->objs[i + 15]->vt->f50(((P_006C7128 *)p)->objs[i + 15], 0x8066CCFF);
        ((P_006C7128 *)p)->objs[i + 25]->vt->f50(((P_006C7128 *)p)->objs[i + 25], 0x8066CCFF);
        gs = D_001A5CD0;
        id = *(s32 *)(e + 0x24);
        res = id == *(s32 *)(gs + 0x34);
        if (!res) {
            u8 *t;
            found = 0;
            t = 0;
            if (list[0] && *(s32 *)(list + 4) >= 0) {
                t = list + (*(s32 *)(list + 4) * 12 + 0x28);
            }
            if (t) {
                s32 j;
                for (j = 0; j < *(s32 *)(t + 4); j++) {
                    if (*(s32 *)(((u8 **)*(u8 **)(t + 8))[j] + 0x1C) == id) {
                        found = 1;
                        break;
                    }
                }
            }
            res = found;
            if (!res || p[0xBB0]) {
                continue;
            }
        }
        ((P_006C7128 *)p)->objs[i + 15]->vt->f50(((P_006C7128 *)p)->objs[i + 15], D_001DDF0C_sda);
        ((P_006C7128 *)p)->objs[i + 25]->vt->f50(((P_006C7128 *)p)->objs[i + 25], D_001DDF0C_sda);
    }
    func_L39_006C7D28(p, 0, *(s32 *)(p + 0x2B8), names);
    func_L39_006C7C40(p, sel);
    if (*(s32 *)(p + 0x2B8) < 10) {
        *(s32 *)(p + 0xBAC) = *(s32 *)(p + 0xBA8) + *(s32 *)(p + 0x2B8);
    }
    for (n = 0; n < *(s32 *)(p + 0x2B8); n++) {
        blank[n] = D_003847C8 + n * 30;
    }
    func_L39_006C7D28(p, 1, *(s32 *)(p + 0x2B8), blank);
    func_L39_006C7C40(p, sel);
    if (!p[0xB61]) {
        func_L39_006C7E10(p, 1);
    }
    if (*(s32 *)(p + 0xBA8) == 1) {
        func_00120048(D_0024D3E0, D_00249780, func_00381FF0(0x190A));
    } else {
        func_00120048(D_0024D3E0, D_00249788, func_00381FF0(0x190B), *(s32 *)(p + 0xBA8), *(s32 *)(p + 0xBA8) + *(s32 *)(p + 0x2B8) - 1);
    }
    ((FnP_006C7128)((void **)(*(O_006C7128 **)(p + 0x140))->vt)[0xB8 / 4])(*(void **)(p + 0x140), D_0024D3E0);
}
/* localdecomp:end func_L39_006C7128 */

INCLUDE_ASM("asm/levels", func_L39_006C7800);

/* localdecomp:start func_L39_006C7B40 */
typedef struct { s32 a, b, c, type; } S_006C7B40;
extern S_006C7B40 D_L39_004B1768[][25];
extern f32 D_001A6A24 __attribute__((section(".data")));
extern char D_002497E8[];
extern char D_002497F0[];
extern char D_002497F8[];
s32 func_001321C8(f32);
s32 func_00120048(char *, const char *, ...);

void func_L39_006C7B40(u8 *arg0, char *buf, s32 value, s32 arg3) {
    s32 type = D_L39_004B1768[*(s32 *)(arg0 + 0xD4C)][*(s32 *)(arg0 + 0xB64)].type;

    if (type == 1) {
        func_00120048(buf, D_002497F0, func_001321C8(value / D_001A6A24));
    } else if (type == 2) {
        func_00120048(buf, D_002497E8, arg3);
    } else if (value > 99999) {
        value = (value + 500) / 1000;
        func_00120048(buf, D_002497F8, value);
    } else {
        func_00120048(buf, D_002497E8, value);
    }
}
/* localdecomp:end func_L39_006C7B40 */

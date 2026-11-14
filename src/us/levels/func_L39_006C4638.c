#include "common.h"

/* NTSC-U counterpart of func_L39_006C7128 (src/levels/39_multiplayer_menu/L39_006C69C0.c) */
extern s32 func_0037DF98();

/* localdecomp:start func_L39_006C4638 */
typedef void (*FnP_006C7128)(void *, void *);
typedef void (*FnI_006C7128)(void *, s32);
typedef struct { s32 w[0x23]; } Blk_006C7128;
typedef struct { char *s; s32 n; } Str_006C7128;
typedef struct O_006C7128 O_006C7128;
typedef struct { u8 pad[0x50]; void (*f50)(O_006C7128 *, s32); } Vt_006C7128;
struct O_006C7128 { u8 pad[0x60]; Vt_006C7128 *vt; };
typedef struct { u8 pad[0x110]; O_006C7128 *objs[0x296]; } P_006C7128;
extern void *D_L39_0024D860[] __attribute__((section(".sdata")));
extern u8 D_001A5E50[];
extern char D_L39_003848C8[];
extern char D_L39_0024D500[0x28] __attribute__((section(".sdata")));
extern char D_L39_0024D528[0x28] __attribute__((section(".sdata")));
extern char D_L39_0024D4E0_006C4638[0x100] __attribute__((section(".sdata")));
extern char D_L39_00249920[];
extern char D_L39_00249928[];
extern char D_L39_002498D0_006C4638[];
extern char D_L39_002498D8[];
extern s32 D_001DDEDC_sda;
extern Str_006C7128 D_001E1BD0_sda;
__asm__(".extern D_001E1BD0_sda, 8");
s32 func_0037DF98(s32);
s32 func_00120884(s32);
s32 func_00120048(char *, const char *, ...);
s32 func_L39_006D3FC0(u8 *, s32, s32, s32);
u8 *func_L39_006D4568(u8 *, s32, s32, s32);
s32 func_L39_006D46C0(u8 *, s32, s32, void *);
void func_L39_005945F0(Str_006C7128 *, s32, s32);
void func_L39_006C5238(u8 *, s32, s32, void *);
void func_L39_006C5320(u8 *, s32);
void func_L39_006C54B0(u8 *, s32);
s32 func_L39_006C51F8(u8 *);
void func_L39_006C5150(u8 *, s32);
void func_L39_006C5050(u8 *, char *, s32, s32);

void func_L39_006C4638(u8 *p) {
    char buf[0x20];
    char *names[12];
    char *blank[12];
    char *one;
    u8 *g = *(u8 **)((u8 *)D_L39_0024D860[0] + 0x44);
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
            func_L39_006D3FC0(g, *(s32 *)(p + 0xBA4), 1, *(s32 *)(p + 0xBA8));
            gs0 = D_001A5E50;
            *(s32 *)(p + 0x2B0) = *(s32 *)(g + 0x10);
            r = func_L39_006D4568(g, *(s32 *)(gs0 + 0x34), *(s32 *)(p + 0xBA4), 1);
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
        if (func_L39_006D46C0(g, *(s32 *)(D_001A5E50 + 0x34), 0, vals)) {
            *(s32 *)(p + 0xBB4) = 1;
        }
    }
    if (*(s32 *)(p + 0xBB4)) {
        func_L39_006C5050(p, buf, *(s32 *)((u8 *)vals + (*(s32 *)(p + 0xBA4) << 2)), *(s32 *)(p + 0xD48));
        func_00120048(D_L39_0024D500, D_L39_00249920, func_0037DF98(0x1940), buf);
        func_00120048(D_L39_0024D528, D_L39_00249928, func_0037DF98(0x1941), *(s32 *)(p + 0xD48));
        ((FnP_006C7128)((void **)(*(O_006C7128 **)(p + 0x144))->vt)[0xB8 / 4])(*(void **)(p + 0x144), D_L39_0024D500);
        ((FnP_006C7128)((void **)(*(O_006C7128 **)(p + 0x148))->vt)[0xB8 / 4])(*(void **)(p + 0x148), D_L39_0024D528);
    }
    if (!entry || *(s32 *)(g + 0x10) == *(s32 *)(p + 0x2B0)) {
        return;
    }
    *(s32 *)(p + 0x2B0) = *(s32 *)(g + 0x10);
    if ((*(s32 *)(p + 0x2B8) = *(s32 *)(entry + 4)) == 0 && *(s32 *)(p + 0xBA8) == 1) {
        s32 a;
        p[0xB60] = 0;
        one = (char *)func_0037DF98(0x1328);
        a = func_0037DF98(0x1328);
        func_L39_005945F0(&D_001E1BD0_sda, a, func_00120884(func_0037DF98(0x1328)));
        one = (char *)&D_001E1BD0_sda;
        func_L39_006C5238(p, 0, 1, &one);
        func_L39_006C5320(p, 1);
        func_L39_006C54B0(p, 2);
        return;
    }
    p[0xB60] = 1;
    if (*(s32 *)(p + 0x2B8) > 10) {
        *(s32 *)(p + 0x2B8) = 10;
    }
    sel = func_L39_006C51F8(p);
    list = *(u8 **)((u8 *)D_L39_0024D860[0] + 0x34);
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
        func_L39_006C5050(p, D_L39_003848C8 + i * 30, *(s32 *)(e + 0x20), *(s32 *)(p + 0xBA8) + i);
        ((P_006C7128 *)p)->objs[i + 15]->vt->f50(((P_006C7128 *)p)->objs[i + 15], 0x8066CCFF);
        ((P_006C7128 *)p)->objs[i + 25]->vt->f50(((P_006C7128 *)p)->objs[i + 25], 0x8066CCFF);
        gs = D_001A5E50;
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
        ((P_006C7128 *)p)->objs[i + 15]->vt->f50(((P_006C7128 *)p)->objs[i + 15], D_001DDEDC_sda);
        ((P_006C7128 *)p)->objs[i + 25]->vt->f50(((P_006C7128 *)p)->objs[i + 25], D_001DDEDC_sda);
    }
    func_L39_006C5238(p, 0, *(s32 *)(p + 0x2B8), names);
    func_L39_006C5150(p, sel);
    if (*(s32 *)(p + 0x2B8) < 10) {
        *(s32 *)(p + 0xBAC) = *(s32 *)(p + 0xBA8) + *(s32 *)(p + 0x2B8);
    }
    for (n = 0; n < *(s32 *)(p + 0x2B8); n++) {
        blank[n] = D_L39_003848C8 + n * 30;
    }
    func_L39_006C5238(p, 1, *(s32 *)(p + 0x2B8), blank);
    func_L39_006C5150(p, sel);
    if (!p[0xB61]) {
        func_L39_006C5320(p, 1);
    }
    if (*(s32 *)(p + 0xBA8) == 1) {
        func_00120048(D_L39_0024D4E0_006C4638, D_L39_002498D0_006C4638, func_0037DF98(0x190A));
    } else {
        func_00120048(D_L39_0024D4E0_006C4638, D_L39_002498D8, func_0037DF98(0x190B), *(s32 *)(p + 0xBA8), *(s32 *)(p + 0xBA8) + *(s32 *)(p + 0x2B8) - 1);
    }
    ((FnP_006C7128)((void **)(*(O_006C7128 **)(p + 0x140))->vt)[0xB8 / 4])(*(void **)(p + 0x140), D_L39_0024D4E0_006C4638);
}
/* localdecomp:end func_L39_006C4638 */

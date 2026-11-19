/* functional: medium. Callee prototypes for func_L39_00569868/00569EB0/00578EA0/0038CDF8 inferred from register use only; vadd/vsub.xyz w lanes follow the destination register; 372 byte diffs are codegen/stack layout. */
#include "common.h"
extern s32 D_0024B858[];
extern f32 D_0024DE80[];
extern u8 D_0025F760[];
void func_L01_003E4028(void *);
void func_L39_00569868(void *);
void func_L39_00569EB0(void *, void *);
f32 func_0038CE68(void *, void *);
void func_0038CE20(void *, void *, f32);
f32 func_0038CF00(void *, void *);
f32 func_L39_00578EA0(void *, f32, f32, f32, f32, f32);
void func_0038CDF8(void *, void *, void *, f32);
void func_L01_003E5700(void *, void *);
s32 func_L01_0040E020(void *);
s32 func_003D3CB0(void *, void *, s32, s32, s32);
f32 func_0038CEA8(void *);
void func_L01_003E8C28(s32, f32, f32);

static void bf148_vop(f32 *d, f32 *a, f32 *b, s32 sub) {
    f32 w = a[3];
    if (sub) {
        d[0] = a[0] - b[0]; d[1] = a[1] - b[1]; d[2] = a[2] - b[2];
    } else {
        d[0] = a[0] + b[0]; d[1] = a[1] + b[1]; d[2] = a[2] + b[2];
    }
    d[3] = w;
}
static void bf148_q(void *d, void *s) {
    s32 *dd = d, *ss = s;
    s32 a = ss[0], b = ss[1], c = ss[2], e = ss[3];
    dd[0] = a; dd[1] = b; dd[2] = c; dd[3] = e;
}

void func_L39_0056A7B8(u8 *obj) {
    u8 *G = (u8 *)(D_0024DE80 + *(s32 *)(obj + 0x94) * 0x118);
    u8 *st = *(u8 **)(obj + 0x70);
    u8 *base = st + 0x60;
    u8 *G80, *G90;
    f32 out[8];
    f32 v30[4], v40[4], v50[4], v60[4], v70[4], v80[4], v90[4], vA0[4], vB0[4];
    f32 f20, f21, d, t, lim, cnt;
    s32 idx, c, r;
    u8 *p;

    f20 = 0.0f;
    func_L01_003E4028(obj);
    func_L39_00569868(obj);
    func_L39_00569EB0(obj, out);
    bf148_q(st + 0x70, out);
    bf148_q(v30, st + 0x60);
    d = func_0038CE68(G + 0x90, st + 0xC0);
    func_0038CE20(v40, G + 0x90, d);
    bf148_vop(v50, (f32 *)(st + 0xC0), v40, 1);
    *(f32 *)(base + 0x110) = func_0038CF00(v40, st + 0x70);
    v40[0] = func_L39_00578EA0(st + 0x100, v40[0], *(f32 *)(base + 0x10), *(f32 *)(base + 0x104), *(f32 *)(base + 0x108), f20);
    v40[1] = func_L39_00578EA0(st + 0x104, v40[1], *(f32 *)(base + 0x14), *(f32 *)(base + 0x104), *(f32 *)(base + 0x108), f20);
    v40[2] = func_L39_00578EA0(st + 0x108, v40[2], *(f32 *)(base + 0x18), *(f32 *)(base + 0x104), *(f32 *)(base + 0x108), f20);
    v50[0] = func_L39_00578EA0(st + 0xF0, v50[0], *(f32 *)(st + 0x60), *(f32 *)(base + 0xFC), *(f32 *)(base + 0x100), f20);
    v50[1] = func_L39_00578EA0(st + 0xF4, v50[1], *(f32 *)(base + 0x4), *(f32 *)(base + 0xFC), *(f32 *)(base + 0x100), f20);
    v50[2] = func_L39_00578EA0(st + 0xF8, v50[2], *(f32 *)(base + 0x8), *(f32 *)(base + 0xFC), *(f32 *)(base + 0x100), f20);
    bf148_vop((f32 *)(st + 0x60), (f32 *)(st + 0x60), (f32 *)(st + 0x70), 0);
    bf148_vop((f32 *)(st + 0xC0), v50, v40, 0);
    func_0038CE20(v60, G + 0x80, *(f32 *)(base + 0xD0));
    if (*(u8 *)(base + 0xF9) != 0) {
        c = *(u8 *)(base + 0xF8) + 1;
        *(u8 *)(base + 0xF8) = c;
        if (*(s16 *)(base + 0x10C) < (c & 0xFF)) *(u8 *)(base + 0xF8) = *(u8 *)(base + 0x10C);
    } else {
        func_L01_0040E020(st + 0x158);
    }
    cnt = (f32)*(u8 *)(base + 0xF8);
    lim = (f32)*(s16 *)(base + 0x10C);
    func_0038CDF8(v70, st + 0x60, st + 0xC0, cnt / lim);
    bf148_vop((f32 *)(st + 0xA0), v60, v70, 0);
    func_L01_003E5700(obj, v60);

    G80 = G + 0x80;
    if (G[0x27C] != 0 && G[0x283] != 0) {
        func_0038CE20(v60, G80, 2.0f);
    } else if (*(s32 *)(G + 0x254) == 0x11) {
        *(s32 *)(v60 + 0) = 0; *(s32 *)(v60 + 1) = 0; *(s32 *)(v60 + 2) = 0; *(s32 *)(v60 + 3) = 0;
    } else {
        func_0038CE20(v60, G80, 0.5f);
    }
    bf148_vop(v70, out + 4, v60, 0);
    func_0038CE20(v60, G80, *(f32 *)(st + 0x1B0));
    bf148_vop((f32 *)(st + 0xB0), v60, (f32 *)(st + 0x60), 0);
    G = (u8 *)(D_0024DE80 + *(s32 *)(obj + 0x94) * 0x118);
    func_0038CE20(v80, G80, 20.0f);
    p = *(u8 **)(*(u8 **)(G + 0x50) + 0x70);
    f20 = *(f32 *)(p + 0x254) * *(f32 *)(p + 0x24C) * (*(f32 *)(p + 0x250) - 1.0f) + 0.35f;
    bf148_vop(v80, v70, v80, 0);
    idx = *(s32 *)(obj + 0x94);
    r = func_003D3CB0(v70, v80, D_0024B858[idx], *(s32 *)(G + 0x240), 0);
    if (r != 0) bf148_q(v90, D_0025F760); else bf148_q(v90, v80);
    func_0038CE20(v80, G80, 20.0f);
    bf148_vop(v80, v70, v80, 1);
    idx = *(s32 *)(obj + 0x94);
    r = func_003D3CB0(v70, v80, D_0024B858[idx], *(s32 *)(G + 0x240), 0);
    if (r != 0) bf148_q(v80, D_0025F760);
    bf148_vop(vA0, v80, v90, 1);
    d = func_0038CEA8(vA0);
    if (d < f20 + f20) {
        bf148_vop(vB0, v90, v80, 0);
        func_0038CE20(vB0, vB0, 0.5f);
        goto tail;
    }
    bf148_vop(vA0, v90, (f32 *)(st + 0x60), 1);
    d = func_0038CEA8(vA0);
    f21 = *(f32 *)(st + 0x1B0);
    if (d <= f21 + f20) {
        func_0038CE20(vB0, G80, f20);
        bf148_vop(vB0, v90, vB0, 1);
tail:
        bf148_q(st + 0xB0, vB0);
        bf148_vop(vA0, vB0, (f32 *)(st + 0x60), 1);
        d = func_0038CE68(vA0, G80);
        func_L01_003E8C28(*(s32 *)(obj + 0x94), d, 0.006f);
        return;
    }
    G90 = G + 0x90;
    f20 = func_0038CE68(st + 0x60, G90);
    d = func_0038CE68(v80, G90);
    if (d < f20) bf148_q(v80, st + 0x60);
    func_0038CE20(v60, G80, f21);
    bf148_vop((f32 *)(st + 0xB0), v60, v80, 0);
}

#include "common.h"

/* localdecomp:start func_L39_0062B838 */
#include "vu0.h"
typedef int q128_0062B838 __attribute__((mode(TI)));
typedef struct { u8 pad0[0xA]; s8 b0A; u8 pad0B[0x21 - 0xB]; s8 b21; u8 pad22[0x80 - 0x22]; } E_0062B838;
typedef struct { u8 pad[4]; u8 *joints[1]; } JL_0062B838;
typedef struct { u8 pad0[8]; u8 jointCount; u8 pad9[0x1C - 9]; JL_0062B838 *jl; } Cls_0062B838;
typedef struct {
    u8 pad0[0x10];
    q128_0062B838 pos;
    u8 pad20[4];
    Cls_0062B838 *cls;
    u8 pad28[4];
    f32 scale;
    u8 pad30[0xC0 - 0x30];
    u8 rot[1];
} Sub_0062B838;
typedef struct {
    u8 pad0[0x474];
    s32 w474;
    s32 w478;
    u8 pad47C[0x4C4 - 0x47C];
    s32 w4C4;
    u8 pad4C8[0x640 - 0x4C8];
    u8 m640[0xA40 - 0x640];
    q128_0062B838 qA40;
    u8 padA50[0xAF0 - 0xA50];
    q128_0062B838 qAF0;
    u8 padB00[0xF10 - 0xB00];
    q128_0062B838 qF10;
    u8 padF20[0x18F0 - 0xF20];
    q128_0062B838 q18F0;
    u8 pad1900[0x1A1F - 0x1900];
    u8 b1A1F;
    u8 pad1A20[0x2524 - 0x1A20];
    Sub_0062B838 *sub;
} Obj_0062B838;
extern E_0062B838 D_L39_0049C890[];
__asm__(".extern D_001DA928_sda, 4");
extern s32 D_001DA928_sda[3] __attribute__((section(".sdata")));
extern s32 D_L39_00246040[] __attribute__((section(".sdata")));
extern s32 D_L39_0024CF08;
extern u8 D_L39_00480760[];
extern u8 D_L39_002FA500[];
extern s32 func_L39_00648AE0(void *, s32);
extern void func_L01_0040E388(void *);
extern void func_L01_00440AD8(void *);
extern void func_L01_00441740(void *, void *, s32);
extern void func_0038D570(void *, void *);
extern void func_L01_00441558(s32, void *, f32);
extern void func_0038CD28(void *, void *, s32);

static __inline__ s32 hash_0062B838(u8 *p) {
    u32 buf[2];
    s32 r;
    long t = *p;
    if (t == 0) {
        r = 0;
    } else {
        u8 *bp = (u8 *)buf;
        s32 n = *p;
        s32 m = n + 1;
        s32 k = ((s32)p - n) & 7;
        u32 x;
        s32 h;
        for (h = 0; h < 24; h += 3) {
            *bp++ = D_L39_00480760[m + ((k + h) & 7) * 193];
        }
        buf[0] ^= (u32)p;
        x = buf[1] ^ buf[0];
        buf[1] = (x >> 16) / (((x ^ (x >> 16)) << 16) + 1);
        r = buf[1];
    }
    return r;
}

static __inline__ s32 teamId_0062B838(Obj_0062B838 *o) {
    s32 id = -1;
    if (o->w474 == 2) id = o->w478;
    return id;
}

static __inline__ s32 playerId_0062B838(Obj_0062B838 *o) {
    s32 id = hash_0062B838(&o->b1A1F);
    if (id == -1) id = teamId_0062B838(o);
    return id;
}

static __inline__ s32 isSpecial_0062B838(s32 id) {
    s32 r;
    if (id == 6 || id == 12) r = 1; else r = 0;
    return r;
}

void func_L39_0062B838(Obj_0062B838 *o, Sub_0062B838 *s) {
    s32 idx;
    q128_0062B838 saved[3];
    if (s == 0) {
        s = o->sub;
    }
    idx = o->w478;
    if (idx != 0) {
        E_0062B838 *e;
        s32 v;
        if (func_L39_00648AE0(o, idx)) {
            E_0062B838 *q = &D_L39_0049C890[idx];
            e = &D_L39_0049C890[q->b21];
        } else {
            e = &D_L39_0049C890[idx];
        }
        v = e->b0A;
        if (v != D_001DA928_sda[0]) {
            D_001DA928_sda[0] = v;
            D_L39_0024CF08 = 0;
        }
    }
    if (D_L39_00246040[1] == -1) {
        s32 n = 0x1D;
        u8 *j = s->cls->jl->joints[n];
        (&D_L39_0024CF08)[3] = j[j[0] + 4];
        D_L39_00246040[1] = n;
    }
    if (D_L39_0024CF08 == 0) {
        u8 **joints = s->cls->jl->joints;
        s32 n;
        for (n = 0; n < 3; n++) {
            u8 *j = joints[D_001DA928_sda[n]];
            (&D_L39_0024CF08)[n] = j[j[0] + 4];
        }
    }
    saved[0] = o->qA40;
    saved[1] = o->qAF0;
    saved[2] = o->qF10;
    func_L01_0040E388(&o->qA40);
    func_L01_0040E388(&o->qAF0);
    func_L01_0040E388(&o->qF10);
    func_L01_00440AD8(s);
    if (o->w4C4 != 0 || (o->w474 == 0 && isSpecial_0062B838(playerId_0062B838(o))) ||
        isSpecial_0062B838(teamId_0062B838(o))) {
        func_L01_00441740(D_L39_002FA500, (void *)0x70000000, 0x50);
    }
    o->qA40 = saved[0];
    o->qAF0 = saved[1];
    o->qF10 = saved[2];
    {
    u8 world[0x40] __attribute__((aligned(16)));
    s32 i;
    func_0038D570(world, s->rot);
    *(q128_0062B838 *)(world + 0x30) = s->pos;
    func_L01_00441558(s->cls->jointCount, world, s->scale * 0.0009765625f);
    for (i = 0; i < 3; i++) {
        if ((&D_L39_0024CF08)[i] == 0) {
            o->q18F0 = *(q128_0062B838 *)(o->m640 + 0x30 + 0x40 * i);
        }
        func_0038CD28(o->m640 + 0x40 * i, (u8 *)0x70000000 + ((&D_L39_0024CF08)[i] << 6), 0x40);
    }
    }
    {
        if (isSpecial_0062B838(teamId_0062B838(o))) {
            o->q18F0 = *(q128_0062B838 *)((u8 *)o + 0x730);
            func_0038CD28((u8 *)o + 0x700, (u8 *)0x70000000 + ((&D_L39_0024CF08)[3] << 6), 0x40);
        } else {
            qzero(&o->q18F0);
        }
    }
}
/* localdecomp:end func_L39_0062B838 */

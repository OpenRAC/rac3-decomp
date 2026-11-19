#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 pos[2]; s32 color0; s32 x24; s32 color1; s32 x2C; } Sparks;
typedef struct { s32 id; u8 pad4[0xC]; u128_t pos; u8 path[0x10]; } Vars_3B5068;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 pad20[0xC];
    f32 scale;
    u8 pad30[4];
    u16 x34;
    u8 pad36[0x32];
    Vars_3B5068 *vars;
} Moby_3B5068;
typedef struct { u8 pad0[0x12]; s16 count; u8 pad14[0xC]; s32 *ids; u8 pad24[0xC]; } Path_3B4108;
typedef struct { s32 count; u8 pad4[0x1C]; Path_3B4108 paths[1]; } Paths_3B4108;
typedef struct { u8 pad0[0x30]; V4 pos; u8 pad40[0x40]; } Node_3B4108;
typedef struct { u8 pad0[0x18]; s32 x18; u8 pad1C[4]; V4 pos; } Tgt_3B4108;
typedef struct {
    f32 pos[4][4];
    u32 rgba[4];
    f32 uv[4][2];
    unsigned long count;
    unsigned long tex;
    unsigned long tex0;
    unsigned long alpha;
} Quad_3B5628;
typedef struct {
    u8 pad0[0xA8];
    s32 xA8;
    u8 padAC[0x2C8 - 0xAC];
    s32 x2C8;
    u8 pad2CC[0x310 - 0x2CC];
    u128_t x310;
    V4 x320;
} Vars_3B67B0;
typedef struct {
    u8 pad0[0x30]; f32 x30; s16 x34; u8 pad36[0x388 - 0x36];
    s32 x388; u8 pad38C[4]; u32 x390; u8 pad394[4]; s32 x398; u8 pad39C[4]; s32 x3A0[12];
} Vars_3B44F8;
typedef struct { u8 pad0[0x2B0]; s32 x2B0; } EVars_3B44F8;
typedef struct {
    u8 pad0[0x30]; f32 x30; s16 h34; u8 pad36[0x3]; u8 x39; u8 pad3A[0x6]; f32 x40; u8 pad44[0x14];
    u8 x58; u8 pad59[0x1]; u8 x5A; u8 pad5B[0x15]; f32 x70; f32 x74; f32 x78; f32 x7C; f32 x80; u8 pad84[0x18];
    f32 x9C; f32 xA0; f32 xA4; u8 padA8[0xC8]; u8 x170; u8 x171; u8 pad172[0xA];
    f32 x17C; f32 x180; f32 x184; f32 x188; f32 x18C; f32 x190; f32 x194; u8 pad198[0x4]; f32 x19C; f32 x1A0;
    u8 pad1A4[0x5]; u8 x1A9; u8 pad1AA[0xE]; f32 x1B8; f32 x1BC; u8 pad1C0[0xC]; u8 x1CC; u8 x1CD; u8 pad1CE[0x9];
    u8 x1D7; u8 x1D8; u8 pad1D9[0x2]; u8 x1DB; u8 pad1DC[0x220 - 0x1DC];
    V4 v220; s32 w230; s16 h234; u8 pad236[0x240 - 0x236]; u8 a240[0x80];
    s32 x2C0; s32 x2C4; s32 x2C8; s32 x2CC;
    s32 w2D0; f32 f2D4; s32 w2D8; f32 f2DC; u8 pad2E0[0x8]; s32 x2E8; u8 pad2EC[0x4]; s32 x2F0; s32 x2F4;
    u8 pad2F8[0x10]; s32 x308; s32 w30C; u8 pad310[0x10]; V4 x320; V4 x330;
} V_3B6390;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[0x10]; u8 b31; u8 pad32[0x68 - 0x32];
    V_3B6390 *vars; u8 pad6C[3]; u8 b6F; u8 pad70[0x25]; u8 b95;
} M_3B6390;
typedef struct { u8 pad0[0x24]; f32 x24; } Cls_3B4AD0;
typedef struct { s32 id; u8 pad4[0xC]; V4 home; u8 path[0x10]; } Vars_3B4AD0;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[3]; Cls_3B4AD0 *cls; u8 pad28[4]; f32 scale; u8 pad30[4]; u16 x34;
    u8 pad36[0x32]; Vars_3B4AD0 *vars; u8 pad6C[0x2A]; u16 h96; s32 x98; u8 pad9C[0xC]; u8 bA8; u8 padA9[0x47]; f32 rot[3];
} Moby_3B4AD0;
typedef struct { u8 pad0[0x44]; u16 x44; u8 pad46[2]; u8 *x48; u8 pad4C[8]; u8 *x54; u8 *x58; } Cls_3B57B8;
typedef struct { s32 count; u8 pad4[0xC]; V4 pts[1]; } Pts_3B57B8;
typedef struct {
    u8 pad0[0x30]; f32 x30; u8 pad34[0x160 - 0x34]; u8 a160[0xC0];
    V4 v220; s32 w230; s16 h234; u8 pad236[0x2C0 - 0x236];
    s32 x2C0; s32 x2C4; u8 pad2C8[4]; s32 x2CC; u8 pad2D0[0x2E0 - 0x2D0];
    s32 x2E0; s32 x2E4; s32 x2E8; f32 x2EC; u8 pad2F0[0x300 - 0x2F0];
    s32 x300; s32 x304; u8 pad308[0x320 - 0x308];
    V4 x320; V4 x330;
} Vars_3B57B8;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[3]; Cls_3B57B8 *cls; u8 pad28[0xC]; u16 flags;
    u8 pad36[0xC]; u8 b42; u8 b43; u8 pad44[4]; s32 x48; u8 pad4C[0x14]; u8 b60; u8 pad61[7];
    Vars_3B57B8 *vars; u8 pad6C[0x29]; u8 b95; u8 pad96[2]; s32 x98; u8 pad9C[0x20]; u8 bBC;
    u8 padBD[0x3B]; f32 fF8;
} Moby_3B57B8;
typedef struct {
    u8 pad0[0x78]; f32 f78; f32 f7C; f32 f80; u8 pad84[0x9C - 0x84]; f32 f9C;
    u8 padA0[4]; f32 fA4; s32 wA8; u8 padAC[0x110 - 0xAC]; f32 a110[2]; f32 f118;
    u8 pad11C[0x300 - 0x11C]; s32 w300; u8 pad304[0x310 - 0x304]; s32 w310; u8 a314[0x10];
    f32 f324; f32 f328; u8 pad32C[0x334 - 0x32C]; s32 w334; u8 pad338[8]; s32 w340; f32 f344;
    u8 pad348[8]; u8 a350[0x28]; f32 f378; u8 pad37C[0x39C - 0x37C]; f32 f39C;
} V_3B3BB8;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 pad20[0x48]; V_3B3BB8 *vars; u8 pad6C[0xF4 - 0x6C]; s32 wF4;
} M_3B3BB8;

/* localdecomp:start func_L23_003B3BB8 */
extern f32 D_L23_001DE2E8[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE2E8, 4");
extern f32 D_L23_001DE2F8[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE2F8, 4");
extern f32 D_L23_001DE308[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE308, 4");
extern f32 D_L23_001DE318[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE318, 4");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern f32 func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern s32 func_L23_003B3EA8(u8 *, s32, f32 *, void *, void *, s32);
extern void func_L01_0045A898(void *, void *, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_L01_0040E570(void *a, void *b);
extern void func_L01_0045AA10(void *, f32);
extern void func_L01_0045A748(void *, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_0038CEA8(f32 *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);

void func_L23_003B3BB8(M_3B3BB8 *m, V4 *target, s32 mode, f32 speed)
{
    V_3B3BB8 *v = m->vars;
    V4 t;
    f32 d;

    v->w300 = mode;
    func_L01_0045BD78(m, D_L23_001DE2F8[mode], D_L23_001DE2E8[mode], D_L23_001DE318[mode], D_L23_001DE308[mode]);
    if (v->w300 == 3) {
        v->wA8 |= 0x514;
        v->f78 = 20.0f;
        v->f9C = 0.0f;
        v->f7C = 20.0f;
        v->f80 = 1.5707964f;
        v->f324 -= 0.00392f;
        func_003C41A0(&v->f328, &v->f324, v->f39C, 0.008f, 0.008f, 0.40000004f);
        target->z = v->f378 + v->f328;
    } else {
        v->wA8 &= ~0x514;
        v->f9C = 0.00392f;
        v->f78 = 1.5f;
        v->f7C = 1.5f;
        v->f80 = 1.3962634f;
    }
    t = *target;
    if (v->w300 == 3) {
        func_L23_003B3EA8(m, v->w310, &t, v->a350, v->a314, 0);
        func_L01_0045A898(m, &t, speed);
        func_L01_0045BD10(m, speed);
    } else {
        if (mode == 0 || func_L01_0040E570(&m->pos, target) < v->fA4 * v->fA4) {
            func_L01_0045AA10(m, speed);
        } else {
            func_L01_0045A748(m, &t);
        }
        if (0.0f < v->f118) {
            v->f118 = 0.0f;
        }
        m->pos.z = func_003C3D30(&m->pos, 0, 0, 0.5f);
        d = func_0038CEA8(v->a110);
        if (D_L23_001DE2E8[v->w300] < d) {
            func_0038CE20(v->a110, v->a110, D_L23_001DE2E8[v->w300] / d);
        }
    }
    if (mode == 3) {
        if (v->w334 != 0) {
            func_L01_00448890((u8 *)&m->wF4, (u8 *)&v->w340, v->f344, 0.0050265486f, 0.0050265486f, 0.25132743f, 0);
        } else {
            func_L01_00448890((u8 *)&m->wF4, (u8 *)&v->w340, 0.0f, 0.0050265486f, 0.0050265486f, 0.25132743f, 0);
        }
    } else {
        v->w340 = 0;
        m->wF4 = 0;
    }
}
/* localdecomp:end func_L23_003B3BB8 */

/* localdecomp:start func_L23_003B3EA8 */
#include "common.h"
#include "vu0.h"
extern Paths_3B4108 *D_L23_001DED4C;
__asm__(".extern D_L23_001DED4C, 16");
extern Node_3B4108 *D_L23_001DF240;
__asm__(".extern D_L23_001DF240, 16");
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern int func_00382380(void *, int, int);

s32 func_L23_003B3EA8(u8 *m, s32 idx, f32 *out, void *a3, void *a4, s32 flag)
{
    V4 *home = a3;
    s32 *cur = a4;
    Path_3B4108 *path;
    V4 pos;
    V4 tgt;
    V4 dir;
    f32 d;
    f32 nd;
    f32 lim;
    s32 best;
    s32 i;
    s32 id;
    Node_3B4108 *e;

    if (idx >= 0 && idx < D_L23_001DED4C->count) {
    path = &D_L23_001DED4C->paths[idx];
    pos = *(V4 *)(m + 0x10);
    tgt = *(V4 *)out;
    d = func_L01_0040E570(&pos, &tgt);
    vec_sub_ab(&dir, &tgt, &pos);
    func_0038CE20(&dir, &dir, sqrt_asm(d));
    if (flag == 0 && func_003D3CB0(&pos, &tgt, 2, m, 0) == 0) {
        *cur = -1;
        *home = *(V4 *)out;
        return 1;
    }
    lim = d * 10.0f;
    best = -1;
    for (i = 0; i < path->count; i++) {
        id = path->ids[i];
        e = &D_L23_001DF240[id];
        if (id == *cur)
            continue;
        if (func_00382380(&pos, id, 0) != 0) {
            *cur = path->ids[i];
            continue;
        }
        nd = func_L01_0040E570(&tgt, &e->pos);
        if (lim < nd)
            continue;
        if (func_003D3CB0(&pos, &e->pos, 0, m, 0) != 0)
            continue;
        lim = nd;
        best = i;
    }
    if (best < 0) {
        if (func_L01_0040E570(out, home) > 1.0f)
            *(V4 *)out = *home;
        else
            return 0;
    } else {
        *(V4 *)out = D_L23_001DF240[path->ids[best]].pos;
    }
    }
    return 1;
}
/* localdecomp:end func_L23_003B3EA8 */

/* localdecomp:start func_L23_003B4108 */
extern Paths_3B4108 *D_L23_001DED4C;
__asm__(".extern D_L23_001DED4C, 16");
extern Node_3B4108 *D_L23_001DF240;
extern Tgt_3B4108 D_L23_001E8780;
__asm__(".extern D_L23_001E8780, 16");
#include "structs/hero.h"
extern struct Hero D_001A4BE0_3B4108;
__asm__(".extern D_001A4BE0_3B4108, 16");
extern V4 D_001A4C60;
__asm__(".extern D_001A4C60, 16");
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

void func_L23_003B4108(V4 *out, u8 *self, s32 idx, V4 from, f32 r1, f32 r2)
{
    u8 *v = *(u8 **)(self + 0x68);
    Path_3B4108 *path = &D_L23_001DED4C->paths[idx];
    Node_3B4108 *e;
    V4 a;
    V4 b;
    f32 r1sq = r1 * r1;
    f32 r2sq = r2 * r2;
    f32 lim = r2sq * 4.0f;
    f32 d;
    f32 dh;
    s32 best = -1;
    s32 i;

    for (i = 0; i < path->count; i++) {
        e = &D_L23_001DF240[path->ids[i]];
        d = func_L01_0040E570(&from, &e->pos);
        dh = func_L01_0040E570(&D_001A4C60, &e->pos);
        if (d < r2sq && r1sq < dh && d < lim) {
            a = D_001A4C60;
            a.z = *(f32 *)(v + 0x378) + 2.0f;
            b = e->pos;
            b.z = *(f32 *)(v + 0x378) + 2.0f;
            if (func_003D3CB0(&a, &b, 0, D_001A4BE0_3B4108.hero_moby, 0) == 0) {
                lim = d;
                best = path->ids[i];
            }
        }
    }
    if (best >= 0) {
        *out = D_L23_001DF240[best].pos;
        return;
    }
    a = *(V4 *)(self + 0x10);
    a.z = 0.0f;
    if (func_003D3CB0(self + 0x10, &a, 0, self, 0) != 0 && fabsf(D_L23_001E8780.pos.z - *(f32 *)(v + 0x378)) < 0.5f) {
        *out = D_L23_001E8780.pos;
        return;
    }
    a.x += 10.0f;
    if (func_003D3CB0(self + 0x10, &a, 0, self, 0) != 0 && fabsf(D_L23_001E8780.pos.z - *(f32 *)(v + 0x378)) < 0.5f) {
        *out = D_L23_001E8780.pos;
        return;
    }
    a.x -= 20.0f;
    if (func_003D3CB0(self + 0x10, &a, 0, self, 0) != 0 && fabsf(D_L23_001E8780.pos.z - *(f32 *)(v + 0x378)) < 0.5f) {
        *out = D_L23_001E8780.pos;
        return;
    }
    a.x += 10.0f;
    a.y += 10.0f;
    if (func_003D3CB0(self + 0x10, &a, 0, self, 0) != 0 && fabsf(D_L23_001E8780.pos.z - *(f32 *)(v + 0x378)) < 0.5f) {
        *out = D_L23_001E8780.pos;
        return;
    }
    a.y -= 20.0f;
    if (func_003D3CB0(self + 0x10, &a, 0, self, 0) != 0 && fabsf(D_L23_001E8780.pos.z - *(f32 *)(v + 0x378)) < 0.5f)
        *out = D_L23_001E8780.pos;
}
/* localdecomp:end func_L23_003B4108 */

/* localdecomp:start func_L23_003B44E8 */
void func_L23_003B44E8(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x390) = 0;
}
/* localdecomp:end func_L23_003B44E8 */

/* localdecomp:start func_L23_003B44F8 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
__asm__(".extern D_L23_001DF198, 16");
extern s32 D_L23_001DE2DC;
__asm__(".extern D_L23_001DE2DC, 4");
extern s32 D_L23_001DE2E0;
__asm__(".extern D_L23_001DE2E0, 4");
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L23_003A4448(s32, s32, f32);
extern void func_L23_003B0010(s32);

void func_L23_003B44F8(u8 *self)
{
    Vars_3B44F8 *v = *(Vars_3B44F8 **)(self + 0x68);
    u8 r = 0;
    u16 *p;
    u8 *e;
    f32 ratio;
    s32 stage;

    if (v->x390 < 12) {
        v->x388 = 0;
        if (v->x3A0[v->x390] >= 0) {
            p = D_L23_0021C0E0[v->x3A0[v->x390]];
            while ((v->x3A0[v->x390] & 0xFF) != 0xFF && v->x3A0[v->x390] <= D_L23_001DF198 && p != 0 &&
                   ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[v->x3A0[v->x390]])) {
                e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
                if (e == 0) {
                    break;
                }
                if (e[0x20] != 0xFE) {
                    if (e[0x20] != 0xFD) {
                        v->x388 += 1 + (*(EVars_3B44F8 **)(e + 0x68))->x2B0;
                    }
                }
                p++;
            }
        }
        ratio = v->x30 / (f32)v->x34;
        switch (v->x390) {
        case 0:
            r = 1;
            break;
        case 1:
            r = ratio < 0.85f;
            break;
        case 2:
            r = ratio < 0.65f;
            break;
        case 3:
        case 4:
            r = v->x388 < 1;
            break;
        case 5:
            r = ratio < 0.6f;
            break;
        case 6:
            r = ratio < 0.35f;
            break;
        case 7:
            r = ratio <= 0.0f;
            break;
        }
    }
    if (D_L23_001DE2E0 != 0) {
        D_L23_001DE2E0 = 0;
        D_L23_001DE2DC = v->x390 + 1;
    }
    if (D_L23_001DE2DC > 0) {
        v->x390 = D_L23_001DE2DC - 1;
        r = 1;
        D_L23_001DE2DC = -1;
    }
    if (r != 0) {
        stage = v->x390;
        v->x390 = stage + 1;
        switch (stage) {
        case 0:
            func_L01_004450F0(self, 7, 3);
            func_L23_003A4448(0, 0, 1.0f);
            func_L23_003B0010(v->x3A0[v->x390]);
            break;
        case 1:
            func_L01_004450F0(self, 7, 3);
            func_L23_003A4448(-1, 6, 1.0f);
            func_L23_003B0010(v->x3A0[v->x390]);
            break;
        case 2:
            func_L01_004450F0(self, 2, 2);
            func_L23_003A4448(-1, 6, 1.0f);
            func_L23_003B0010(v->x3A0[v->x390]);
            break;
        case 3:
            func_L01_004450F0(self, 2, 2);
            func_L23_003A4448(-1, 6, 1.5f);
            func_L23_003B0010(v->x3A0[v->x390]);
            break;
        case 4:
            func_L01_004450F0(self, 7, 3);
            func_L23_003A4448(0, 0, 1.0f);
            func_L23_003B0010(v->x3A0[v->x390]);
            v->x398 = 1;
            break;
        case 5:
            func_L01_004450F0(self, 7, 3);
            func_L23_003A4448(0, 0, 1.0f);
            func_L23_003B0010(v->x3A0[v->x390]);
            v->x398 = 1;
            break;
        case 6:
            func_L01_004450F0(self, 7, 3);
            func_L23_003A4448(-1, 8, 1.5f);
            func_L23_003B0010(v->x3A0[v->x390]);
            v->x398 = 1;
            break;
        case 7:
            break;
        }
    }
}
/* localdecomp:end func_L23_003B44F8 */

/* localdecomp:start func_L23_003B48D0 */
#include "vu0.h"
extern f32 D_L23_001DE32C;
__asm__(".extern D_L23_001DE32C, 4");
extern u8 D_001A4CC0[];
extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L23_003B48D0(u8 *m)
{
    u8 *v = *(u8 **)(m + 0x68);
    V4 a;
    V4 b;
    u32 c;
    u32 k;

    *(u128_t *)&a = *(u128_t *)(m + 0x10);
    *(u128_t *)&b = *(u128_t *)D_001A4CC0;
    a.z += D_L23_001DE32C;
    k = 0x60008000;
    c = (*(s16 *)(v + 0x184) == 1) ? k : 0x60000080;
    func_L01_0040A8C0(&a, &b, 0x16, 1, k, k,
                      c, c, 0.1f, 1.0f, 0.0f);
    *(u128_t *)&a = *(u128_t *)(m + 0x10);
    *(u128_t *)&b = *(u128_t *)(v + 0x360);
    func_L01_0040A8C0(&a, &b, 0x16, 1, 0x60006060, 0x60006060, 0x60006060, 0x60006060, 0.1f, 1.0f, 0.0f);
    *(u128_t *)&a = *(u128_t *)(m + 0x10);
    *(u128_t *)&b = *(u128_t *)(v + 0x170);
    func_L01_0040A8C0(&a, &b, 0x16, 1, 0x60800000, 0x60800000, 0x60800000, 0x60800000, 0.1f, 1.0f, 0.0f);
    *(u128_t *)&a = *(u128_t *)(m + 0x10);
    a.z += 1.0f;
    b.x = func_0038D098(*(f32 *)(v + 0x384)) * *(f32 *)(v + 0x380);
    b.y = func_0038D0B0(*(f32 *)(v + 0x384)) * *(f32 *)(v + 0x380);
    b.z = 0.0f;
    vec_add_ab(&b, &b, &a);
    func_L01_0040A8C0(&a, &b, 0x16, 1, 0x60000080, 0x60000080, 0x60000080, 0x60000080, 0.1f, 1.0f, 0.0f);
}
/* localdecomp:end func_L23_003B48D0 */

/* localdecomp:start func_L23_003B4AD0 */
/* 353 diff (needs -mvu0-use-vf0-vf2 on L23_003B3BB8.c and divs row "func_L23_003B4AD0 2 2 0") */
#include "vu0.h"
extern Moby_3B5068 *D_L23_001DE410;
__asm__(".extern D_L23_001DE410, 4");
extern s32 D_L23_001DE130;
extern s32 D_L23_001DE400;
__asm__(".extern D_L23_001DE400, 4");
extern s32 D_L23_001DE3F0;
__asm__(".extern D_L23_001DE3F0, 4");
extern u16 **D_L23_001D6764;
extern u8 *D_L23_001E0014;
void func_L23_003B5318(void);
void func_L23_003B5068(Moby_3B5068 *o);
void func_L23_003B5628(u8 *obj);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0044F450(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00463378(void *, void *, void *, u32, u32, s32, s32, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00404808(void *, void *);

void func_L23_003B4AD0(Moby_3B4AD0 *self)
{
    Vars_3B4AD0 *v = self->vars;
    V4 d;
    V4 a;
    V4 b;
    V4 c;
    u8 *h;
    f32 f;
    f32 ang;
    f32 t;
    s32 i;
    u16 *p;
    u8 *e;

    if (v->id < 0)
        return;
    if (D_L23_001DE410 == (Moby_3B5068 *)self)
        func_L23_003B5318();
    switch (self->b20) {
    case 0:
        func_L23_003B5068((Moby_3B5068 *)self);
        break;
    case 1:
        h = (u8 *)func_L01_00447490(self, -1, 0);
        if (h != 0) {
            f = *(f32 *)(h + 0x2C);
            if (3.0f < f) {
                if (40.0f < f)
                    func_L01_004450F0(self, 3, -1);
                else
                    func_L01_004450F0(self, 2, -1);
            }
            self->bA8 = 0xFF;
        }
        break;
    case 2:
        ang = func_003824E0(-3.1415927f, 3.1415927f);
        t = (f32)self->h96 / (f32)D_L23_001DE130;
        d.x = (v->home.x - self->pos.x) + t * 0.120000005f * func_0038D098(ang);
        d.y = (v->home.y - self->pos.y) + t * 0.120000005f * func_0038D0B0(ang);
        d.z = 0.0f;
        d.w = 1.0f;
        vec_add_ab(&self->pos, &self->pos, &d);
        func_L01_0044F450(self, v->path);
        for (i = 4; i >= 0; i--) {
            f32 th;
            func_0038CE20(&a, &D_L23_001DE3F0, self->scale / self->cls->x24);
            vec_add_ab(&a, &a, &self->pos);
            th = func_003824E0(-3.1415927f, 3.1415927f);
            b.x = func_0038D098(th) * 0.32000002f;
            b.y = func_0038D0B0(th) * 0.32000002f;
            b.z = 0.040000003f;
            vec_add_ab(&b, &b, &d);
            b.w = 1.0f;
            func_0038CE20(&c, &b, 0.25f);
            c.w = 2.0f;
            func_L01_00463378(&a, &b, &c, 0x60807070, 0x40706060, 0xC, 8, 8, -1);
        }
        if (self->h96 >= 0x33)
            func_L01_004450F0(self, 3, -1);
        break;
    case 3:
        if (func_L01_004561B8((u8 *)self) != 0) {
            self->x34 |= 0x41;
            self->x98 = 0;
            self->rot[2] = func_003824E0(-3.1415927f, 3.1415927f);
            self->pos.z = func_003C3D30(&self->pos, 0, 0, 0.5f);
            func_003A52A0(0, 0, self);
            p = D_L23_001D6764[v->id];
            while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
                e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
                if (e == 0)
                    break;
                e[0x1E] |= 4;
                p++;
            }
            func_0038CE20(&d, &D_L23_001DE400, self->scale * 0.5f / self->cls->x24);
            vec_add_ab(&d, &d, &self->pos);
            func_L01_003303B8((u8 *)&d, 1, 0xE, 0x14, 0xC, 0xA, 0x14, 8, 7.0f, 10.0f, 1.5f, 5.0f,
                              1, 1, 1, 1, 1, 1, 0x1130007, 0, 0x688EF7, 0x6363F7, 0x7000FFFF, 0x7000FFFF, 0x8FAF, 0x70303280, 0x7F004020, 0x2800FFFF, 0x3064FF, 0);
        }
        func_L01_00404808(func_L23_003B5628, self);
        break;
    }
    self->h96++;
}
/* localdecomp:end func_L23_003B4AD0 */

/* localdecomp:start func_L23_003B5068 */
extern u16 **D_L23_001D6764;
extern u8 *D_L23_001E001C;
__asm__(".extern D_L23_001E001C, 16");
extern u8 *D_L23_001E0014_3B5068;
__asm__(".extern D_L23_001E0014_3B5068, 4");
extern s16 D_L23_0023A3C0[];
extern Moby_3B5068 *D_L23_001DE410;
__asm__(".extern D_L23_001DE410, 4");
extern s32 D_L23_001DE134;
__asm__(".extern D_L23_001DE134, 4");
extern f32 func_0038CEA8(f32 *);
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003B5068(Moby_3B5068 *o)
{
    Vars_3B5068 *v = o->vars;
    u16 *p;
    u8 *e;
    u8 *found = 0;

    p = D_L23_001D6764[v->id];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
        e = D_L23_001E001C + ((*p & 0x7FFF) << 6);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[(D_L23_001E0014_3B5068 + ((*p & 0x7FFF) << 5))[0x1D]] == 0x1D21) {
            found = e;
            break;
        }
        p++;
    }
    o->pos = *(u128_t *)(found + 0x30);
    o->scale *= func_0038CEA8((f32 *)(found + 0x20));
    o->x34 |= 0x41;
    if (D_L23_001DE410 == 0)
        D_L23_001DE410 = o;
    v->pos = o->pos;
    D_L23_001DE134 = 0;
    func_L01_0044ED88(o, v->path, 0x10, -1, v->id, -1, 7, 0);
    o->x34 |= 0x41;
    func_L01_004450F0(o, 1, -1);
}
/* localdecomp:end func_L23_003B5068 */

/* localdecomp:start func_L23_003B51C0 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
extern f32 func_L01_0040E570(void *a, void *b);
extern s32 func_00382498(s32 a, s32 b);

u8 *func_L23_003B51C0(u8 *object, u8 *skip, f32 radius) {
    u8 *list[64];
    s32 n = 0;
    u16 *p;
    u8 *e;
    if (object == 0)
        return 0;
    {
        p = D_L23_0021C0E0[object[0x21]];
        while (object[0x21] != 0xFF && object[0x21] <= D_L23_001DF198 && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[object[0x21]])) {
            e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (n < 0x40 && e != skip && e[0x20] < 3 && func_L01_0040E570(object + 0x10, e + 0x10) < radius) {
                list[n++] = e;
            }
            p++;
        }
    }
    if (n > 0)
        return list[func_00382498(0, n - 1)];
    return 0;
}
/* localdecomp:end func_L23_003B51C0 */

/* localdecomp:start func_L23_003B5318 */
__asm__(".extern D_L23_001DE3B0, 4");
__asm__(".extern D_L23_001DE400, 4");
__asm__(".extern D_L23_001DE414, 4");
__asm__(".extern D_L23_001DE418, 8");
extern s32 D_L23_001DE3B0;
extern s32 D_L23_001DE400;
extern s32 D_L23_001DE414;
extern u8 *D_L23_001DE418[2];
extern Sparks D_L23_002A3A80;
extern s32 func_0038CAD0(void *);
extern s32 func_00382468(s32);
extern void func_L01_0040C7A0(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00404808(void *, void *);
void func_L23_003B5538(void);

void func_L23_003B5318(void)
{
    func_0038CAD0(&D_L23_001DE414);
    if (D_L23_001DE414 <= 0) {
        D_L23_001DE418[0] = D_L23_001DE418[1];
        if (D_L23_001DE418[1] == 0 || func_00382468(10) == 0)
            D_L23_001DE418[0] = func_L23_003B51C0((u8 *)D_L23_001DE410, 0, 1000000.0f);
        D_L23_001DE418[1] = func_L23_003B51C0(D_L23_001DE418[0], D_L23_001DE418[0], 16.0f);
        if (D_L23_001DE418[0] != 0 && D_L23_001DE418[1] != 0) {
            func_L01_0040C7A0(&D_L23_002A3A80, &D_L23_001DE3B0);
            D_L23_002A3A80.color0 = 0x606060;
            D_L23_002A3A80.x24 = 0x7070;
            D_L23_002A3A80.color1 = 0x6060;
            D_L23_002A3A80.x2C = 0x204040;
            func_0038CE20(&D_L23_002A3A80.pos[0], &D_L23_001DE400,
                          *(f32 *)(D_L23_001DE418[0] + 0x2C) / *(f32 *)(*(u8 **)(D_L23_001DE418[0] + 0x24) + 0x24));
            vec_add_ab(&D_L23_002A3A80.pos[0], &D_L23_002A3A80.pos[0], D_L23_001DE418[0] + 0x10);
            func_0038CE20(&D_L23_002A3A80.pos[1], &D_L23_001DE400,
                          *(f32 *)(D_L23_001DE418[1] + 0x2C) / *(f32 *)(*(u8 **)(D_L23_001DE418[1] + 0x24) + 0x24));
            vec_add_ab(&D_L23_002A3A80.pos[1], &D_L23_002A3A80.pos[1], D_L23_001DE418[1] + 0x10);
        }
        D_L23_001DE414 = 8;
    }
    if (D_L23_001DE418[0] != 0 && D_L23_001DE418[1] != 0)
        func_L01_00404808(func_L23_003B5538, D_L23_001DE410);
}
/* localdecomp:end func_L23_003B5318 */

/* localdecomp:start func_L23_003B54A0 */
extern u16 **D_L23_001D6764;
extern u8 *D_L23_001E0014;
extern s16 D_L23_0023A3C0[];

s32 func_L23_003B54A0(s32 arg0) {
    u16 *p;
    u8 *e;

    p = D_L23_001D6764[arg0];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[arg0])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0) {
            break;
        }
        if (D_L23_0023A3C0[e[0x1D]] == 0x1D21) {
            return 1;
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003B54A0 */

/* localdecomp:start func_L23_003B5538 */
__asm__(".extern D_L23_001DE3B0, 4");
__asm__(".extern D_L23_001DE420, 4");
__asm__(".extern D_L23_001DE424, 4");
__asm__(".extern D_L23_001DE428, 4");
extern s32 D_L23_001DE3B0;
extern s32 D_L23_001DE420;
extern f32 D_L23_001DE424;
extern f32 D_L23_001DE428;
extern Sparks D_L23_002A3A80;
extern void func_L01_0040C948(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L23_003B5538(void)
{
    s32 i;
    u32 color;
    f32 size;

    func_L01_0040C948(&D_L23_002A3A80, &D_L23_001DE3B0);
    for (i = 0; i < 2; i++) {
        color = func_0038DBD8(D_L23_002A3A80.color0, D_L23_002A3A80.color1, func_003824E0(0.0f, 1.0f)) | 0x60000000;
        size = D_L23_001DE428 * func_003824E0(0.75f, 1.25f);
        func_003D9508(&D_L23_002A3A80.pos[i], D_L23_001DE420, color, 1, size, D_L23_001DE424, func_003824E0(-3.1415927f, 3.1415927f));
    }
}
/* localdecomp:end func_L23_003B5538 */

/* localdecomp:start func_L23_003B5628 */
/* 4 diff */
#include "vu0.h"


extern s32 D_L23_001DE430[2];
__asm__(".extern D_L23_001DE430, 8");
extern f32 D_L23_001DE42C;
__asm__(".extern D_L23_001DE42C, 4");
extern void func_0038D570(void *, void *);
extern long func_00389598(s32);
extern void func_003D2DA0(Quad_3B5628 *, f32 *, s32);

void func_L23_003B5628(u8 *obj)
{
    f32 m[4][4] __attribute__((aligned(16)));
    Quad_3B5628 q __attribute__((aligned(16)));
    f32 s;

    func_0038D570(m, obj + 0xC0);
    *(u128_t *)m[3] = *(u128_t *)(obj + 0x10);
    m[3][3] = 1.0f;
    m[3][2] += 0.02f;
    q.tex = func_00389598(D_L23_001DE430[((s32)obj >> 8) % 2]);
    s = D_L23_001DE42C;
    qzero(q.pos[0]);
    qzero(q.pos[1]);
    qzero(q.pos[2]);
    qzero(q.pos[3]);
    q.uv[1][1] = 1.0f;
    q.tex0 = 0xFF9000000379;
    q.uv[0][0] = 0.0f;
    q.uv[2][0] = 1.0f;
    q.uv[0][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.count = 5;
    q.uv[3][1] = 1.0f;
    q.alpha = 0x8000000044;
    q.uv[1][0] = 0.0f;
    q.uv[2][1] = 0.0f;
    q.rgba[3] = 0x50000000;
    q.rgba[2] = 0x50000000;
    q.pos[0][3] = 1.0f;
    q.pos[1][3] = 1.0f;
    q.rgba[1] = 0x50000000;
    q.rgba[0] = 0x50000000;
    q.pos[2][3] = 1.0f;
    q.pos[0][0] = -s;
    q.pos[2][1] = -s;
    q.pos[1][1] = s;
    q.pos[3][3] = 1.0f;
    q.pos[3][0] = s;
    func_003D2DA0(&q, m[0], 0);
}
/* localdecomp:end func_L23_003B5628 */

/* localdecomp:start func_L23_003B5760 */
extern void func_L23_003B67B0(void *owner, void *p, int z, float f, float g);

void func_L23_003B5760(unsigned char *owner)
{
    func_L23_003B67B0(owner, owner + 0x10, 0, *(float *)(owner + 0xF8), 0.0f);
}
/* localdecomp:end func_L23_003B5760 */

/* localdecomp:start func_L23_003B5788 */
extern void func_L23_003B67B0(void *, void *, int, float, float);

void func_L23_003B5788(char *obj, float x) {
    func_L23_003B67B0(obj, *(char **)(obj + 0x68) + 0x320, 3, *(float *)(obj + 0xF8), x);
}
/* localdecomp:end func_L23_003B5788 */

/* localdecomp:start func_L23_003B57B8 */
#include "vu0.h"

extern s32 D_L23_001D6694;
extern f32 D_L23_001DE478;
__asm__(".extern D_L23_001DE478, 4");
extern f32 D_L23_001DE4B0;
__asm__(".extern D_L23_001DE4B0, 4");
extern s32 D_L23_001DE4A4;
__asm__(".extern D_L23_001DE4A4, 4");
extern f32 D_L23_001DE4A8;
__asm__(".extern D_L23_001DE4A8, 4");
extern Pts_3B57B8 *D_L23_0021D380[];
extern s32 func_L01_0044C108(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L23_003B6390(M_3B6390 *);
extern s32 func_L01_004561E0(void *);
extern f32 func_L01_004395E0(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L23_003B5760(unsigned char *);
extern void func_L23_003B5788(char *, float);
extern void func_L23_003B6990(u8 *);
extern void func_L23_003B6A80(void *);
extern void func_L23_003B6AD0(u8 *);
extern void func_L23_003B6C90(u8 *);
extern s32 func_L01_00454370(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_00382538(void);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L23_003B67B0(void *, void *, int, float, float);

void func_L23_003B57B8(Moby_3B57B8 *m)
{
    Vars_3B57B8 *v;
    f32 a;
    f32 d;

    if (func_L01_0044C108(&m->pos) == 0)
        return;
    v = m->vars;
    if (D_L23_001D6694 == 2) {
        m->x98 = 0;
        m->flags = (m->flags | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    } else {
        m->flags &= 0xFFBE;
        m->flags |= m->cls->x44 & 0x1000;
        m->x98 = *(s32 *)((u8 *)m->cls + 0x10);
    }
    func_L23_003B6390(m);
    switch (m->b95) {
    case 2:
        if (v->h234 == 1) {
            func_L01_004450F0(m, 7, 4);
            func_L23_003B6C90(m);
        }
        break;
    case 3:
        if (func_L01_004561E0(m) != 0)
            v->x2C4 = 500;
        if (v->h234 == 1) {
            func_L01_004450F0(m, 7, 4);
            func_L23_003B6C90(m);
        }
        if (v->x2C4 <= 0)
            func_L01_004450F0(m, 4, 2);
        break;
    case 4:
        if (v->h234 == 0)
            func_L01_004450F0(m, 6, 3);
        break;
    case 5:
        if (func_L01_004561E0(m) != 0)
            func_L23_003B6C90(m);
        break;
    }
    switch (m->b20) {
    case 1:
        if (func_L01_004561B8(m) != 0) {
            m->x98 = 0;
            m->flags = (m->flags | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0 || (m->b43 == 1 && (m->b60 & 2) && m->b42 == m->b43)) {
            if (m->b43 != 0)
                func_003C3A10(m, 0, func_00382468(m->cls->x48[0x10]), 8);
            v->x2C0 = (func_00382498(0xB4, 0x168) * 5 + 2) / 6;
        }
        if (v->x2C0 == 0) {
            v->x2C0 = -1;
            if (m->b43 != 1)
                func_003C3A10(m, 1, 0, 8);
        }
        if (v->x2E4 != 0)
            func_L01_004450F0(m, 5, 2);
        func_L23_003B5760(m);
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 3)
                func_003C3A10(m, 3, func_00382468(m->cls->x54[0x10]), 8);
            v->x2C0 = (func_00382498(0x168, 0x1E0) * 5 + 2) / 6;
            v->x320 = m->pos;
        }
        if (v->x2C0 == 0) {
            v->x2C0 = -1;
            if (m->b43 != 1)
                func_003C3A10(m, 1, 0, 8);
        }
        if (m->b43 == 1) {
            if ((m->b60 & 2) && m->b42 == m->b43) {
                if (m->b42 != 3)
                    func_003C3A10(m, 3, func_00382468(m->cls->x54[0x10]), 8);
                v->x2C0 = (func_00382498(0x168, 0x1E0) * 5 + 2) / 6;
            }
            func_L23_003B5760(m);
        } else {
            a = func_0038D160(v->x320.x - m->pos.x, v->x320.y - m->pos.y);
            func_L23_003B67B0(m, &v->x320, 1, a, 0.0f);
            d = func_L01_0040E570(&m->pos, &v->x320);
            if (d < D_L23_001DE478 * D_L23_001DE478) {
                if (v->x2E0 >= 0) {
                    Pts_3B57B8 *t = D_L23_0021D380[v->x2E0];
                    v->x320 = *(t->pts + v->x2E8);
                    v->x2E8++;
                    if (v->x2E8 >= t->count)
                        v->x2E8 = 0;
                } else {
                    a = func_00382538();
                    v->x320.x = func_0038D098(a) * v->x2EC;
                    v->x320.y = func_0038D0B0(a) * v->x2EC;
                    v->x320.z = 0.0f;
                    vec_add_ab(&v->x320, &v->x320, &v->x330);
                }
            }
        }
        break;
    case 6:
        if (func_L01_004561B8(m) != 0 || v->x2C0 <= 0) {
            if (m->b43 != 1)
                func_003C3A10(m, 1, 0, 5);
        }
        if (m->b43 == 1) {
            if ((m->b60 & 2) && m->b42 == m->b43) {
                if (m->b42 != 0)
                    func_003C3A10(m, 0, func_00382468(m->cls->x48[0x10]), 5);
                v->x2C0 = (func_00382498(0x3C, 0xB4) * 5 + 2) / 6;
            }
        }
        func_L23_003B5760(m);
        break;
    case 7:
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 4)
                func_003C3A10(m, 4, func_00382468(m->cls->x58[0x10]), 5);
        }
        a = func_0038D160(m->pos.x - v->v220.x, m->pos.y - v->v220.y);
        v->x320.x = func_0038D098(a) * D_L23_001DE4B0;
        v->x320.y = func_0038D0B0(a) * D_L23_001DE4B0;
        v->x320.z = 0.0f;
        vec_add_ba(&v->x320, &v->x320, &v->v220);
        func_L23_003B67B0(m, &v->x320, 2, 0.0f, 0.0f);
        d = func_L01_0040E570(&m->pos, &v->x320);
        if (d < D_L23_001DE478 * D_L23_001DE478)
            func_L01_004450F0(m, 8, -1);
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            v->x2CC = 3;
            v->x300 = D_L23_001DE4A4;
            v->x304 = 0;
            if (m->b43 != 0)
                func_003C3A10(m, 0, func_00382468(m->cls->x48[0x10]), v->x300 >> 1);
        }
        if (v->x300 <= 0 && v->x2CC == 3) {
            v->x2CC = 1;
            if (m->b43 != 5)
                func_003C3A10(m, 5, 0, 5);
        }
        if (m->b43 == 5 && m->b42 == m->b43) {
            f32 f = func_L01_004395E0(m);
            if (func_L01_0044E1B8(m, 2.0f) != 0) {
                a = func_0038D160(m->pos.x - v->v220.x, m->pos.y - v->v220.y);
                v->x320.x = func_0038D098(a) * D_L23_001DE4A8;
                v->x320.y = func_0038D0B0(a) * D_L23_001DE4A8;
                v->x320.z = 0.0f;
                vec_add_ab(&v->x320, &v->x320, &v->v220);
                v->x320.z = func_003C3D30(&v->x320, 0, 0, 0.5f);
                if (fabs_asm(v->x320.z - m->pos.z) > 1.0f)
                    v->x320 = m->pos;
            }
            if (2.0f <= f && f <= 9.0f)
                func_L23_003B5788(m, (f - 2.0f) / 7.0f);
            else
                func_L23_003B5760(m);
        } else {
            func_L23_003B5760(m);
        }
        if (m->b43 == 5 && func_L01_0044E1B8(m, 28.0f) != 0)
            func_L01_004450F0(m, 9, -1);
        func_L23_003B6990(m);
        break;
    case 9:
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 6)
                func_003C3A10(m, 6, 0, 5);
            v->x320 = m->pos;
            m->bBC = 0;
        }
        if (func_L01_0044E1B8(m, 35.0f) != 0) {
            a = func_0038DAB8(m->fF8, 3.1415927f);
            v->x320.x = func_0038D098(a) * 2.0f;
            v->x320.y = func_0038D0B0(a) * 2.0f;
            v->x320.z = 0.0f;
            vec_add_ab(&v->x320, &v->x320, &m->pos);
            v->x320.z = func_003C3D30(&v->x320, 0, 0, 0.5f);
            if (fabs_asm(v->x320.z - m->pos.z) > 1.0f)
                v->x320 = m->pos;
        }
        d = func_L01_004395E0(m);
        if (35.0f <= d && d <= 49.0f)
            func_L23_003B5788(m, (d - 35.0f) / 14.0f);
        else
            func_L23_003B5760(m);
        if (func_L01_0044E1B8(m, 56.0f) != 0) {
            if (v->x304 != 0)
                func_L01_004450F0(m, 10, -1);
            else
                func_L01_004450F0(m, 7, -1);
        }
        break;
    case 10:
        if (func_L01_004561B8(m) != 0 && m->b43 != 2)
            func_003C3A10(m, 2, 0, 5);
        if (m->b42 == m->b43 && (m->b60 & 2))
            func_L01_004450F0(m, 7, -1);
        func_L23_003B67B0(m, &m->pos, 0, func_0038D160(v->v220.x - m->pos.x, v->v220.y - m->pos.y), 0.0f);
        break;
    case 11: {
        s32 r = func_L01_00454370(m, v->a160);
        if (v->x30 <= 0.0f || (r & 1) != 0) {
            func_L01_004450F0(m, 12, 5);
        } else if ((r & 2) != 0) {
            if (m->b95 == 4)
                func_L01_004450F0(m, 8, -1);
            else
                func_L01_004450F0(m, 6, 3);
        }
        break;
    }
    case 12:
        if (func_L01_004561B8(m) != 0)
            func_L23_003B6AD0(m);
        break;
    }
    func_L23_003B6A80(m);
}
/* localdecomp:end func_L23_003B57B8 */

/* localdecomp:start func_L23_003B6390 */
#include "vu0.h"
extern Tgt_3B4108 D_L23_001E8780;
__asm__(".extern D_L23_001E8780, 16");
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
/* 28 diff */
extern u8 D_L23_001E1A40[];
extern u8 D_L23_001D66B0;
extern void func_L23_003B65F0(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00452F78(void *, s32, s32, s32);
void func_L23_003B6C90(u8 *a0);
extern void func_L01_00404A10(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_00382348(s32);

void func_L23_003B6390(M_3B6390 *s)
{
    V_3B6390 *v = s->vars;
    V4 a;
    V4 b;
    s32 was;
    u8 *r;

    if (s->b20 == 0) {
        func_L23_003B65F0(s);
    }
    if (v->w30C != -1 && func_00382380(&s->pos, v->w30C, 0) == 0) {
        func_L01_00446A70(s, s, 0x10000, &s->pos, &D_L23_001D66B0, (f32)(v->h34 * 2));
    }
    func_L01_00451DF8(s, v->a240, 0, 1, 2.5f);
    if (s->b31 != 0 && func_L01_0040E548(D_L23_001E1A40, &s->pos) < 1024.0f) {
        func_L01_004472C0(s);
        s->b6F = 0x1E;
    }
    if (func_L01_00452F78(s, 0, 0, 0) != 0) {
        func_L23_003B6C90((u8 *)s);
    }
    func_L01_00404A10(s, 3);
    was = v->h234 == 1;
    if (s->b95 == 2) {
        func_L01_00456C98(s, v->w2D0, 0, 0, 0, 0, 1, 0, 0, 0, v->f2D4, 10.0f, 1.0f);
    } else {
        func_L01_00456C98(s, v->w2D8, 0, 0, 0, 0, 1, 0, 0, 0, v->f2DC, 10.0f, 1.0f);
    }
    if (!was && v->h234 == 1) {
        a = s->pos;
        a.z += 0.5f;
        b = v->v220;
        b.z += 0.5f;
        if (func_003D3CB0(&a, &b, 0, s, 0) != 0 && D_L23_001E8780.x18 != v->w230) {
            v->h234 = 0;
        }
    }
    if (v->w230 != 0) {
        r = func_00382348(v->w230);
        if (r != 0) {
            r[0x31] = 0xFF;
        }
    }
}
/* localdecomp:end func_L23_003B6390 */

/* localdecomp:start func_L23_003B65F0 */
/* MATCH */
extern f32 D_L23_001DE474;
__asm__(".extern D_L23_001DE474, 4");
extern f32 D_L23_001DE478;
__asm__(".extern D_L23_001DE478, 4");

void func_L23_003B65F0(void *obj)
{
    M_3B6390 *m = obj;
    V_3B6390 *v = m->vars;
    f32 g;
    f32 h;

    v->x58 = 10;
    v->x5A = 2;
    v->x40 = 0.3f;
    v->x39 = 1;
    if (v->h34 == 0) {
        v->h34 = 2;
        v->x30 = 2.0f;
    }
    g = D_L23_001DE474;
    h = D_L23_001DE478;
    v->x70 = g;
    v->x78 = 0.5f;
    v->xA4 = h;
    v->x80 = 1.553343f;
    v->xA0 = 0.17453292f;
    v->x9C = 0.00392f;
    v->x74 = g;
    v->x170 = 11;
    v->x7C = 1.0f;
    v->x190 = g;
    v->x194 = g;
    v->x19C = 0.15f;
    v->x1D7 = 1;
    v->x171 = 7;
    v->x1CC = 7;
    v->x1D8 = 0;
    v->x1B8 = 0.1f;
    v->x1BC = 1.0f;
    v->x1CD = 14;
    v->x1DB = 20;
    v->x184 = 0.010000001f;
    v->x17C = 0.3f;
    v->x180 = 0.030000001f;
    v->x1A9 = 0;
    v->x188 = 0.010000001f;
    v->x18C = 0.00080000004f;
    v->x1A0 = m->pos.z - 10.0f;
    v->x2C0 = 0;
    v->x2C4 = 0;
    v->x2C8 = 0;
    v->x2CC = 0;
    v->x2F0 = 0;
    v->x2F4 = 0;
    v->x2E8 = 0;
    v->x320 = m->pos;
    v->x330 = m->pos;
    if (v->x308 != 0)
        func_L01_004450F0(m, 4, 1);
    else
        func_L01_004450F0(m, 4, 2);
}
/* localdecomp:end func_L23_003B65F0 */

/* localdecomp:start func_L23_003B67B0 */
/* MATCH: needs -mvu0-use-vf0-vf2 on L23_003B3BB8.c (vec_* helpers) */
#include "vu0.h"

extern f32 D_L23_001DE47C;
__asm__(".extern D_L23_001DE47C, 4");
extern s32 D_L23_001DE440;
__asm__(".extern D_L23_001DE440, 4");
extern f32 D_L23_001DE460[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE460, 4");
extern f32 D_L23_001DE448[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE448, 4");
extern f32 D_L23_001DE498;
__asm__(".extern D_L23_001DE498, 4");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_0045AA10(void *, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern s32 func_L01_0045AA30(u8 *, u128_t *);
extern void func_0038CE20(void *, void *, f32);

void func_L23_003B67B0(void *owner, void *p, int z, float f, float g)
{
    u8 *m = owner;
    Vars_3B67B0 *v = *(Vars_3B67B0 **)(m + 0x68);
    V4 d;
    u128_t e;
    f32 t;

    if (z != v->x2C8) {
        if (z == 2) {
            *(f32 *)(m + 0x48) = D_L23_001DE47C;
        }
        if (D_L23_001DE440 != 0) {
            *(f32 *)(m + 0x48) = 0.1f;
        }
        func_L01_0045BD78(m, D_L23_001DE460[z] * *(f32 *)(m + 0x48), D_L23_001DE448[z] * *(f32 *)(m + 0x48),
                          *(f32 *)(m + 0x48) * 0.0050265486f, *(f32 *)(m + 0x48) * 0.12566371f);
        if (z == 3) {
            v->x310 = *(u128_t *)(m + 0x10);
            v->xA8 = 0x514;
        } else {
            v->xA8 = 0;
        }
    }
    v->x2C8 = z;
    switch (z) {
    case 0:
        func_L01_0045AA10(m, f);
        func_L01_0045BD10(m, f);
        break;
    case 1:
    case 2:
        func_L01_0045A748(m, p);
        break;
    case 3:
        t = g + g - 1.0f;
        t = (1.0f - t * t) * D_L23_001DE498;
        vec_sub_ba(&d, &v->x320, &v->x310);
        func_0038CE20(&d, &d, g);
        vec_add_ba(&d, &d, &v->x310);
        d.z += t;
        vec_sub_ba(&e, &d, m + 0x10);
        func_L01_0045AA30(m, &e);
        break;
    }
}
/* localdecomp:end func_L23_003B67B0 */

/* localdecomp:start func_L23_003B6990 */
extern u8 D_001A4BE0[];
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L01_004395E0(void *);
extern void func_L03_00433C70(void *, Vec4 *, Vec4 *, s32, f32, f32, s32, s32, s32);

void func_L23_003B6990(u8 *obj) {
    u8 *vars = *(u8 **)(obj + 0x68);
    Vec4 a;
    Vec4 b;
    u8 inRange = 0;
    f32 d;

    if (*(s32 *)(vars + 0x2CC) == 1) {
        func_003C2F58(obj, 1, &a);
        func_003C2F58(obj, 2, &b);
        d = func_L01_004395E0(obj);
        inRange = (10.0f <= d && d <= 16.0f);
    }
    if (*(s32 *)(vars + 0x304) == 0 && *(u8 **)(D_001A4BE0 + 0x2808) == obj) {
        *(s32 *)(vars + 0x304) = 1;
    }
    if (inRange) {
        func_L03_00433C70(obj, &a, &b, 1, 1.0f, 1.0f, 0, 1, 0);
    }
}
/* localdecomp:end func_L23_003B6990 */

/* localdecomp:start func_L23_003B6A80 */
extern s32 func_0038CAD0(void *);

void func_L23_003B6A80(void *arg0) {
    u8 *temp_s0;
    u16 temp_v1;

    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    temp_s0 = *(u8 **)((u8 *)arg0 + 0x68);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
    func_0038CAD0(temp_s0 + 0x2C0);
    func_0038CAD0(temp_s0 + 0x2C4);
    func_0038CAD0(temp_s0 + 0x300);
}
/* localdecomp:end func_L23_003B6A80 */

/* localdecomp:start func_L23_003B6AD0 */
/* 29 diff */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L03_0043FC00(s32, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern void func_L01_004443E8(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L23_003B6AD0(u8 *m)
{
    u8 *v = *(u8 **)(m + 0x68);
    Vec4 d;
    Vec4 p;

    d.v[0] = func_0038D098(*(f32 *)(v + 0x2F8)) * (*(f32 *)(v + 0x2FC) * 0.020000001f);
    d.v[1] = func_0038D0B0(*(f32 *)(v + 0x2F8)) * (*(f32 *)(v + 0x2FC) * 0.020000001f);
    d.v[2] = 0.0f;
    func_L03_0043FC00((s32)m, 0x3FF, (u8 *)&d, 3, 3, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0.05f);
    func_L01_004443E8(m, 0, 3);
    func_003A52A0(3, 0, m);
    p = *(Vec4 *)(m + 0x10);
    p.v[2] += 0.2f;
    func_L01_003303B8((u8 *)&p, 1, 10, 20, 0, 4, 20, 2, 0.2f, 0.0f, 0.0f, 0.0f,
        1, 1, 1, 0, 1, 1, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_003C2880(m);
}
/* localdecomp:end func_L23_003B6AD0 */

/* localdecomp:start func_L23_003B6C90 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
extern void func_L01_004450F0(void *a0, s32 a1, s32 a2);

void func_L23_003B6C90(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L23_0021C0E0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L23_001DF198 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[a0[0x21]])) {
        e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (*(s16 *)(e + 0xAA) == 0x1BE3 && a0[0x95] == 2) {
            func_L01_004450F0(e, 6, 3);
        }
        p++;
    }
}
/* localdecomp:end func_L23_003B6C90 */

/* localdecomp:start func_L23_003B6D78 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
__asm__(".extern D_L23_001DF198, 16");
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003B6D78(s32 a0) {
    u16 *p;
    u8 *e;

    p = D_L23_0021C0E0[a0];
    if ((a0 & 0xFF) == 0xFF || a0 > D_L23_001DF198 || p == 0) {
        return;
    }
    for (;;) {
        e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            return;
        }
        if (*(s16 *)(e + 0xAA) == 0x1BE3 && e[0x95] == 1) {
            func_L01_004450F0(e, 4, 2);
        }
        p++;
        if ((a0 & 0xFF) == 0xFF) {
            return;
        }
        if (a0 > D_L23_001DF198) {
            return;
        }
        if (p == 0) {
            return;
        }
        if ((s16)p[-1] >= 0) {
            continue;
        }
        if (p == D_L23_0021C0E0[a0]) {
            continue;
        }
        return;
    }
}
/* localdecomp:end func_L23_003B6D78 */

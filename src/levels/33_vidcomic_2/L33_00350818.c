#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_00350818 */
typedef struct {
    u8 pad0[0x14];
    u8 f14;
    u8 pad15[0x3B];
    vu0_v4 v50;
    vu0_v4 v60;
    u8 pad70[8];
    s32 f78;
    u8 pad7C[4];
    vu0_v4 v80;
    f32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    s32 fA0;
    u8 padA4[8];
    s32 fAC;
    s32 fB0;
    f32 fB4;
    f32 fB8;
    f32 fBC;
    f32 fC0;
} Vars_00350818;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x30];
    u16 f44;
} Ref_00350818;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[2];
    u8 f23;
    Ref_00350818 *f24;
    u8 pad28[0xC];
    u16 f34;
    u8 pad36[0xC];
    u8 f42;
    u8 f43;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x14];
    u8 flags;
    u8 pad61[7];
    Vars_00350818 *vars;
    u8 pad6C[0x2A];
    u16 f96;
    s32 f98;
    u8 pad9C[0xE];
    s16 oclass;
    u8 padAC[0x4C];
    f32 fF8;
} Moby_00350818;

typedef struct {
    u8 pad0[0x80];
    vu0_v4 pos;
    u8 pad90[0x25C0 - 0x90];
    Moby_00350818 *p25C0;
} Hero_00350818;

typedef struct {
    vu0_v4 pos;
    u8 pad10[0x2540 - 0x10];
    Moby_00350818 *p2540;
} HeroPos_00350818;

extern Hero_00350818 D_001A4BE0;
extern HeroPos_00350818 D_001A4C60;
extern u8 *D_001DFC00;
extern u8 *D_001DFB1C;
extern u8 *D_L33_001DFC00;
__asm__(".extern D_L33_001DFC00, 4");
extern u8 *D_L33_001DFB1C;
__asm__(".extern D_L33_001DFB1C, 4");
extern u8 D_L33_001E1858[] __attribute__((section(".sdata")));
extern u8 D_L33_001E1898[] __attribute__((section(".sdata")));
extern u8 D_L33_001E18B8[] __attribute__((section(".sdata")));
extern vu0_v4 D_L33_001E9620;

extern f32 D_L33_001DD888[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD888, 4");
extern f32 D_L33_001DD8A8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD8A8, 4");
extern f32 D_L33_001DD8B8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD8B8, 4");
extern f32 D_L33_001DD8C8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD8C8, 4");
extern f32 D_L33_001DD8D8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD8D8, 4");
extern f32 D_L33_001DD900[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD900, 4");
extern f32 D_L33_001DD938[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD938, 4");
extern f32 D_L33_001DD948[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD948, 4");
extern f32 D_L33_001DD998[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD998, 4");
extern f32 D_L33_001DD9E0[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD9E0, 4");
extern f32 D_L33_001DDA10[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDA10, 4");
extern f32 D_L33_001DDA50[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDA50, 4");
extern f32 D_L33_001DDAC0[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDAC0, 4");
extern s32 D_L33_001DDAD0[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDAD0, 4");
extern f32 D_L33_001DDAF8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDAF8, 4");

extern u8 D_L33_001DCFDC;
__asm__(".extern D_L33_001DCFDC, 1");
extern s32 D_L33_001DD85C;
__asm__(".extern D_L33_001DD85C, 4");
extern f32 D_L33_001DD8E4;
__asm__(".extern D_L33_001DD8E4, 4");
extern f32 D_L33_001DD968;
__asm__(".extern D_L33_001DD968, 4");
extern f32 D_L33_001DD970;
__asm__(".extern D_L33_001DD970, 4");
extern f32 D_L33_001DD974;
__asm__(".extern D_L33_001DD974, 4");
extern f32 D_L33_001DD978;
__asm__(".extern D_L33_001DD978, 4");
extern f32 D_L33_001DD97C;
__asm__(".extern D_L33_001DD97C, 4");
extern f32 D_L33_001DD980;
__asm__(".extern D_L33_001DD980, 4");
extern f32 D_L33_001DD9A4;
__asm__(".extern D_L33_001DD9A4, 4");
extern s32 D_L33_001DD9A8;
__asm__(".extern D_L33_001DD9A8, 4");
extern f32 D_L33_001DDA3C;
__asm__(".extern D_L33_001DDA3C, 4");
extern f32 D_L33_001DDA74;
__asm__(".extern D_L33_001DDA74, 4");
extern f32 D_L33_001DDA78;
__asm__(".extern D_L33_001DDA78, 4");
extern f32 D_L33_001DDA7C;
__asm__(".extern D_L33_001DDA7C, 4");
extern f32 D_L33_001DDA80;
__asm__(".extern D_L33_001DDA80, 4");
extern f32 D_L33_001DDA88;
__asm__(".extern D_L33_001DDA88, 4");
extern f32 D_L33_001DDAAC;
__asm__(".extern D_L33_001DDAAC, 4");
extern f32 D_L33_001DDAEC;
__asm__(".extern D_L33_001DDAEC, 4");
extern f32 D_L33_001DDAF0;
__asm__(".extern D_L33_001DDAF0, 4");
extern f32 D_L33_001DDB38;
__asm__(".extern D_L33_001DDB38, 4");
extern f32 D_L33_001DDB40;
__asm__(".extern D_L33_001DDB40, 4");
extern s32 D_L33_001DDB48;
__asm__(".extern D_L33_001DDB48, 4");
extern f32 D_L33_001DDB70;
__asm__(".extern D_L33_001DDB70, 4");
extern f32 D_L33_001DDB74;
__asm__(".extern D_L33_001DDB74, 4");
extern s32 D_L33_001DDC90;
__asm__(".extern D_L33_001DDC90, 4");

extern s32 func_L31_00346798(void *, f32, f32, f32);
extern void func_L31_00346B10(void *, void *, f32, f32, f32, f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L30_0034CB68(void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L30_0034CDC0(f32, f32 *, f32 *, f32 *, f32 *);
extern s32 func_L30_0034D8D8(void *, f32);
extern s32 func_L32_00349630(void *, void *, f32, f32, f32, f32, f32, f32, f32);
extern void func_L03_0034B248(void *, void *);
extern s32 func_L33_00352760(s32, s32, s32);
extern f32 func_L33_003527C0(void *);
extern void func_L33_00352908(void *);
extern void func_L33_00352A08(void *);
extern s32 func_L33_00352E08(void *, s32, s32, s32);
extern void func_L33_00352ED0(void *, s32);
extern void func_L33_003532D8(void *);
s32 func_L33_003534E0(u8 *);
extern void func_L33_00353800(void *, void *, s32, s32, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern f32 func_L01_004395E0(void *);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_0038CAD0(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003C2880(void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);

void func_L33_00350818(Moby_00350818 *p) {
    vu0_v4 grav;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    f32 top;
    Vars_00350818 *s = p->vars;
    s32 idx = 0x1761 - p->oclass;
    s32 facing = func_L31_00346798(p, D_L33_001DD97C, D_L33_001DD980, D_L33_001DD978) != 0;
    s32 inZ;
    s32 inX;
    s32 seen;
    s32 left;
    s32 snd;
    s32 ret;
    s32 n;
    f32 frame;
    f32 a;
    f32 sp;
    f32 m;
    f32 d;
    f32 r;
    f32 q;
    f32 k;
    f32 c;
    f32 z;
    f32 w;
    f32 x;
    f32 y;
    Moby_00350818 *h;

    inZ = 0;
    if (D_001A4BE0.pos.z < D_L33_001DD8E4 + p->pos.z) {
        if (p->pos.z - D_L33_001DD8E4 < D_001A4BE0.pos.z) {
            inZ = 1;
        }
    }
    inX = fabs_asm(D_001A4BE0.pos.x - p->pos.x) < D_L33_001DD8D8[idx];
    seen = 0;
    if (s->fA0 == -1 || func_00382380(&D_001A4BE0.pos, s->fA0, 0) != 0) {
        seen = s->fB0 == 0;
    }
    a = fabs_asm(func_0038DB00(D_L33_001DD97C, p->fF8));
    left = 1;
    if (!(a < fabs_asm(func_0038DB00(D_L33_001DD980, p->fF8)))) {
        left = 0;
    }
    frame = func_L01_004395E0(p);
    qzero(&grav);
    grav.z = D_L33_001DD998[idx];
    snd = p->oclass == 0x175F;

    if (p->state == 0) {
        func_L33_003532D8(p);
        if (s->f9C != -1) {
            func_L33_00352ED0(p, 15);
        } else {
            func_L33_00352ED0(p, 5);
        }
    }
    func_L33_00352A08(p);

    switch (p->state) {
    case 1:
        if (func_L01_004561B8(p)) {
            s->v80 = D_001A4C60.pos;
            s->v60.x = 0.0f;
            p->f96 = 0;
        }
        ret = func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f,
                                0.0f, 0.0f, D_L33_001DD968, 1, 1, 1, 0);
        if (D_L33_001DD8A8[idx] <= frame && frame <= D_L33_001DD8B8[idx]) {
            func_L30_0034CB68(p, &s->v60, 1, 1, 0, 0, s->f14, D_L33_001DD8C8[idx]);
        }
        if (++p->f96 <= 20) {
            break;
        }
        if (!(p->flags & 2) && !(D_L33_001DD888[idx] <= frame)) {
            break;
        }
        if (!ret) {
            func_L33_00352ED0(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352ED0(p, 1);
        } else if (!func_00382498(0, 1)) {
            func_L33_00352ED0(p, 13);
        } else if (seen && inZ) {
            if (facing) {
                func_L33_00352ED0(p, 12);
            } else {
                s->v80 = D_001A4C60.pos;
                func_L33_00352ED0(p, 14);
            }
        } else {
            func_L33_00352ED0(p, 5);
        }
        break;
    case 0x42:
        if (func_L01_004561B8(p)) {
            s->f78 = D_L33_001DDAD0[idx];
            D_L33_001DD85C += 3 - idx;
        }
        if (!func_0038CAD0(&s->f78)) {
            func_L30_0034C8A8(D_L33_001E1858, p);
            func_L30_0034C8A8(D_L33_001E1898, p);
            p->f23 = (f32)s->f78 * 128.0f / (f32)D_L33_001DDAD0[idx];
            func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, 0.0f,
                              0.0f, D_L33_001DD900[idx], 1, 1, 1, 0);
            break;
        }
        v10.z = D_L33_001DDB38;
        v10.x = D_L33_001DD998[idx] * 5.0f / (2.0f * D_L33_001DDB38);
        n = p->oclass == 0x1761 ? 1 : 2;
        if (D_001A4BE0.pos.x < p->pos.x) {
            v10.x = -v10.x;
        }
        if (p->oclass != 0x175F) {
            if (p->oclass == 0x1760) {
                func_003A52A0(6, 0, p);
            } else {
                func_003A52A0(7, 0, p);
            }
            v10.x *= func_003824E0(0.8f, 1.2f);
            func_L33_00353800(&p->pos, &v10, n, -1, -1, -1, 1);
            v10.x *= func_003824E0(0.4f, 0.6f);
            func_L33_00353800(&p->pos, &v10, n, -1, -1, -1, 1);
        }
        qzero(&s->v60);
        func_L33_00352760(0, p->oclass, 0);
        func_003C2880(p);
        break;
    case 2:
        if (func_L01_004561B8(p)) {
            s->f78 = D_L33_001DDAD0[idx];
            func_003A52A0(snd + 5, 0, p);
            func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, 0.0f,
                              0.0f, D_L33_001DD900[idx], 1, 1, 1, 1);
        }
        if (p->f42 == p->f43) {
            func_L32_00349630(p, &p->pos, D_L33_001DDAF8[idx], s->v60.z, D_L33_001DD998[idx], D_L33_001DD948[idx],
                              D_L33_001DD938[idx], 0.0f, -1.0f);
        } else {
            p->f48 = 1.0f;
        }
        if (!func_0038CAD0(&s->f78)) {
            func_L30_0034C8A8(D_L33_001E1858, p);
            func_L30_0034C8A8(D_L33_001E1898, p);
        }
        ret = func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, 0.0f,
                                0.0f, D_L33_001DD900[idx], 1, 1, 1, 1);
        if ((p->flags & 2) || (idx == 2 && s->v60.z <= 0.0f && D_L33_001DD948[idx] <= frame) ||
            (idx < 2 && s->v60.z <= 0.0f && D_L33_001DD948[idx] <= frame && ret)) {
            func_L33_00352ED0(p, 0x42);
        }
        break;
    case 3:
        if (func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, 100.0f,
                              0.0f, D_L33_001DD968, 1, 1, 1, 0)) {
            func_L33_00352ED0(p, 11);
        }
        break;
    case 4:
        if (func_L01_004561B8(p)) {
            s->f78 = D_L33_001DDAD0[idx];
            func_003A52A0(snd + 3, 0, p);
            func_003A52A0(snd | 4, 0, p);
            func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, 0.0f,
                              0.0f, D_L33_001DD9E0[idx], 1, 1, 1, 0);
        }
        if (!func_0038CAD0(&s->f78)) {
            func_L30_0034C8A8(D_L33_001E1858, p);
        }
        ret = func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, 0.0f,
                                0.0f, D_L33_001DD9E0[idx], 1, 1, 1, 0);
        if (!(p->flags & 2) && !(D_L33_001DDA10[idx] < frame && p->f42 == p->f43)) {
            break;
        }
        if (!ret) {
            func_L33_00352ED0(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352ED0(p, 1);
        } else if (!seen) {
            func_L33_00352ED0(p, 5);
        } else if (!inZ) {
            func_L33_00352ED0(p, 6);
        } else if (facing) {
            func_L33_00352ED0(p, 12);
        } else {
            s->v80 = D_001A4C60.pos;
            func_L33_00352ED0(p, 14);
        }
        break;
    case 5:
        if (!func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, 0.0f,
                               D_L33_001DDB40, s->fB4, 1, 1, 1, 0)) {
            func_L33_00352ED0(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352ED0(p, 1);
        } else if (seen && inZ) {
            if (facing) {
                func_L33_00352ED0(p, 12);
            } else {
                s->v80 = D_001A4C60.pos;
                func_L33_00352ED0(p, 14);
            }
        } else if (p->flags & 2) {
            s->v80 = p->pos;
            s->v80.x += func_L33_003534E0((u8 *)p) ? 4.0f : -4.0f;
            func_L33_00352ED0(p, 14);
        }
        break;
    case 6:
        if (func_L01_004561B8(p)) {
            func_L33_00352908(p);
            s->f78 = 0;
        }
        v10 = s->v80;
        v10.x = func_L33_003527C0(p);
        func_L31_00346B10(p, &s->v60, v10.x, D_L33_001DD970, s->fB8, s->fB4, s->fB4);
        ret = func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, s->fB8,
                                D_L33_001DDB40, 0.0f, 1, 1, 1, 0);
        {
            f32 spd = D_L33_001DDA3C * func_0038CEA8(&s->v60) / D_L33_001DDAC0[idx];
            p->f48 = spd;
            if (spd > 5.0f) {
                p->f48 = 5.0f;
            } else if (spd < 0.5f) {
                p->f48 = 0.5f;
            }
        }
        if (func_0038CAD0(&s->f78)) {
            if (!D_L33_001DCFDC) {
                func_L03_0034B248(D_L33_001E18B8, p);
            }
            s->f78 = D_L33_001DDC90;
        }
        if (!ret) {
            func_L33_00352ED0(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352ED0(p, 1);
        } else if (seen && inZ) {
            if (facing) {
                func_L33_00352ED0(p, 12);
            } else {
                s->v80 = D_001A4C60.pos;
                func_L33_00352ED0(p, 14);
            }
        } else if (func_0038CF00(&s->v80, &p->pos) < D_L33_001DD970 || func_L33_00352E08(p, left, facing, 0)) {
            func_L33_00352ED0(p, 5);
        }
        break;
    case 7:
        if (func_L01_004561B8(p)) {
            qzero(&s->v60);
        }
        if (D_L33_001DDAF0 < frame && frame < D_L33_001DDAEC) {
            v10 = s->v50;
            v20 = *(vu0_v4 *)(D_L33_001DFC00 + s->f9C * 128 + 0x30);
            func_003C4098(&p->pos, &v10, &v20, (frame - D_L33_001DDAF0) / (D_L33_001DDAEC - D_L33_001DDAF0));
            if (D_L33_001DDAF0 + D_L33_001DDAEC < 2.0f * frame && s->f98 != -1) {
                func_L01_00456230(D_L33_001DFB1C + s->f98 * 256, 1);
            }
        } else if (D_L33_001DDAEC < frame) {
            func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, 0.0f,
                              D_L33_001DDB40, 0.0f, 1, 1, 1, 0);
        }
        if (p->flags & 2) {
            s->v80 = D_001A4C60.pos;
            func_L33_00352ED0(p, 14);
        }
        break;
    case 8:
        if (func_L01_004561B8(p)) {
            func_L30_0034CDC0(1.0f, 0, 0, 0, &top);
            v20 = p->pos;
            v30 = p->pos;
            y = D_001A4BE0.pos.y;
            x = *(f32 *)(D_001DFC00 + s->f9C * 128 + 0x30);
            v30.x = x;
            v30.y = y;
            v20.y = y;
            v20.x = x;
            v20.z = top;
            if (!func_003D3CB0(&v20, &v30, 2, 0, 0)) {
                func_L33_00352ED0(p, 0x42);
                break;
            }
            top = D_L33_001E9620.z + D_L33_001DDA88;
            qzero(&s->v60);
            s->v60.z = sqrt_asm(fabs_asm(2.0f * D_L33_001DD9A4 * (top - p->pos.z)));
            p->f96 = sqrt_asm(fabs_asm((top - p->pos.z) * 2.0f / D_L33_001DD9A4));
            s->f78 = p->f96;
            s->v60.x = (*(f32 *)(D_001DFC00 + s->f9C * 128 + 0x30) - s->v50.x) / p->f96;
            s->f94 = 0;
            p->fF8 = func_0038DB48(p->pos.x < D_001A4BE0.p25C0->pos.x ? D_L33_001DD980 : D_L33_001DD97C);
        }
        {
            s32 cnt = p->f96 - 1;
            if (cnt < 0) {
                cnt = 0;
            }
            p->f96 = cnt;
        }
        p->pos.y = func_003C4088(s->v50.y, D_001A4BE0.pos.y, 1.0f - (f32)p->f96 / (f32)s->f78);
        if (s->v60.z < 0.0f) {
            p->f98 = p->f24->f10;
        }
        func_L32_00349630(p, &p->pos, D_L33_001DDAF8[idx], s->v60.z, D_L33_001DD9A4, D_L33_001DDA78, D_L33_001DDA7C,
                          0.0f, -1.0f);
        qzero(&v10);
        v10.z = D_L33_001DD9A4;
        if (D_L33_001DDA7C <= frame) {
            s->f90 = p->pos.x < D_001A4BE0.pos.x ? D_L33_001DD980 : D_L33_001DD97C;
            if (D_L33_001DD978 < fabs_asm(func_0038DB00(s->f90, p->fF8))) {
                {
                    f32 q2 = s->fBC * D_L33_001DDB70;
                    f32 r2 = s->fC0 * D_L33_001DDB70;
                    func_L01_00448890(&p->fF8, &s->f94, s->f90 == 0.0f ? -1 : 1, s->f90, q2, q2, r2);
                }
            }
            m = 0.0f;
        } else {
            m = 100.0f;
        }
        func_L30_0034D1E8(p, &p->pos, &s->v60, &v10, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, m,
                          D_L33_001DDB40, 0.0f, 1, 1, 1, 0);
        if (D_L33_001DDA80 <= frame || (p->flags & 2)) {
            s->v80 = D_001A4C60.pos;
            func_L33_00352ED0(p, 14);
        }
        break;
    case 9:
        func_L01_004561B8(p);
        if (func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, s->fB8,
                              D_L33_001DDB40, 0.0f, 1, 1, 1, 0)) {
            func_L33_00352ED0(p, 10);
        }
        break;
    case 10:
    case 11:
        if (func_L01_004561B8(p)) {
            s->f94 = 0;
        }
        ret = func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, 0.0f,
                                D_L33_001DDB40, 0.0f, 1, 1, 1, 0);
        {
            f32 tgt;
            if (p->pos.x < D_001A4BE0.pos.x) {
                tgt = D_L33_001DD980;
            } else {
                tgt = D_L33_001DD97C;
            }
            s->f90 = tgt;
        }
        if (D_L33_001DD978 < fabs_asm(func_0038DB00(s->f90, p->fF8))) {
            {
                f32 q2 = s->fBC * D_L33_001DDB70;
                f32 r2 = s->fC0 * D_L33_001DDB70;
                func_L01_00448890(&p->fF8, &s->f94, s->f90 == 0.0f ? -1 : 1, s->f90, q2, q2, r2);
            }
        }
        if (!ret) {
            func_L33_00352ED0(p, 3);
        }
        if ((p->flags & 2) || (p->state == 11 && D_L33_001DDA50[idx] <= frame) ||
            (p->state == 10 && D_L33_001DDA74 <= frame)) {
            if (facing && inX && inZ) {
                func_L33_00352ED0(p, 1);
            } else if (seen && inZ) {
                if (facing) {
                    func_L33_00352ED0(p, 12);
                } else {
                    s->v80 = D_001A4C60.pos;
                    func_L33_00352ED0(p, 14);
                }
            } else {
                func_L33_00352ED0(p, 5);
            }
        }
        break;
    case 12:
        if (func_L01_004561B8(p)) {
            s->f78 = 0;
        }
        s->v80 = D_001A4C60.pos;
        v10 = s->v80;
        v10.x = func_L33_003527C0(p);
        h = D_001A4C60.p2540;
        z = s->fB8;
        w = s->fB4;
        if ((h->fF8 < 1.5707964f && p->pos.x < h->pos.x) || (1.5707964f <= h->fF8 && h->pos.x < p->pos.x)) {
            z *= D_L33_001DDAAC;
            w *= D_L33_001DDAAC;
        }
        func_L31_00346B10(p, &s->v60, v10.x, D_L33_001DD970, z, w, w);
        ret = func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, z,
                                D_L33_001DDB40, 0.0f, 1, 1, 1, 0);
        if (func_0038CEA8(&s->v60) < D_L33_001DD974 && fabs_asm(v10.x - p->pos.x) < D_L33_001DDAF8[idx]) {
            if (!(p->f43 == 1 || p->f43 == 2 || p->f43 == 9) || (p->flags & 2)) {
                if (!func_00382498(0, 2)) {
                    if (p->f43 != 1) {
                        func_003C3A10(p, 1, func_003824E0(0.0f, 4.0f), D_L33_001DDB48);
                    }
                } else if (!func_00382498(0, 1)) {
                    if (p->f43 != 2) {
                        func_003C3A10(p, 2, func_003824E0(0.0f, 4.0f), D_L33_001DDB48);
                    }
                } else {
                    if (p->f43 != 9) {
                        func_003C3A10(p, 9, func_003824E0(0.0f, 4.0f), D_L33_001DDB48);
                    }
                }
                p->f48 = 1.0f;
            }
        } else {
            f32 spd;
            if (p->f43 != 3) {
                func_003C3A10(p, 3, 0, (D_L33_001DDB48 * 5 + 2) / 6);
            }
            spd = D_L33_001DDA3C * func_0038CEA8(&s->v60) / D_L33_001DDAC0[idx];
            p->f48 = spd;
            if (spd > 5.0f) {
                p->f48 = 5.0f;
            } else if (spd < 0.5f) {
                p->f48 = 0.5f;
            }
        }
        if (func_0038CAD0(&s->f78)) {
            if (!D_L33_001DCFDC) {
                func_L03_0034B248(D_L33_001E18B8, p);
            }
            s->f78 = D_L33_001DDC90;
        }
        if (func_L33_00352E08(p, left, facing, 1)) {
            s->fB0 = D_L33_001DD9A8;
        }
        if (!ret) {
            func_L33_00352ED0(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352ED0(p, 1);
        } else if (!seen || (inX && !inZ)) {
            func_L33_00352ED0(p, 5);
        } else if (!facing) {
            func_L33_00352ED0(p, 14);
        }
        break;
    case 13:
        if (!func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, 0.0f,
                               D_L33_001DDB40, 0.0f, 1, 1, 1, 0)) {
            func_L33_00352ED0(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352ED0(p, 1);
        } else if (p->flags & 2) {
            if (seen && inZ) {
                if (facing) {
                    func_L33_00352ED0(p, 12);
                } else {
                    s->v80 = D_001A4C60.pos;
                    func_L33_00352ED0(p, 14);
                }
            } else {
                func_L33_00352ED0(p, 5);
            }
        }
        break;
    case 14:
        if (func_L01_004561B8(p)) {
            s->f90 = p->pos.x < s->v80.x ? D_L33_001DD980 : D_L33_001DD97C;
            s->v60.x = 0.0f;
            s->f94 = 0;
        }
        d = func_0038DB00(s->f90, p->fF8);
        r = s->fC0;
        if (inX) {
            r *= D_L33_001DDB70;
        }
        q = s->fBC;
        if (inX) {
            q *= D_L33_001DDB70;
        }
        if (D_L33_001DD978 < fabs_asm(d)) {
            func_L01_00448890(&p->fF8, &s->f94, s->f90 == 0.0f ? -1 : 1, s->f90, q, q, r);
            if (d > 2.0943952f) {
                d = 2.0943952f;
            } else if (d < -2.0943952f) {
                d = -2.0943952f;
            }
            k = func_0038CEA8(&s->v60) / D_L33_001DDAC0[idx];
            c = func_0038D098(func_0038DB48(d));
            if (c < 0.0f) {
                c = 0.0f;
            }
            p->f48 = func_003C4088(k, D_L33_001DDB70, fabs_asm(d) / 2.0943952f);
            sp = s->fB8 * fabs_asm(c);
            if (func_L33_00352E08(p, left, facing, 0)) {
                sp = 0.0f;
            }
            v10 = s->v80;
            v10.x = func_L33_003527C0(p);
            func_L31_00346B10(p, &s->v60, v10.x, D_L33_001DD8D8[idx], s->fB8, s->fB4, s->fB4);
            if (sp < s->v60.x) {
                s->v60.x = sp;
            } else if (s->v60.x < -sp) {
                s->v60.x = -sp;
            }
            if (!func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, sp,
                                   D_L33_001DDB40, s->fB4, 1, 1, 1, 0)) {
                func_L33_00352ED0(p, 3);
            }
        } else if (facing && inX && inZ) {
            func_L33_00352ED0(p, 1);
        } else if (func_003824E0(0.0f, 1.0f) < D_L33_001DDB74) {
            func_L33_00352ED0(p, 13);
        } else if (seen && inZ) {
            if (facing) {
                func_L33_00352ED0(p, 12);
            } else {
                s->v80 = D_001A4C60.pos;
                func_L33_00352ED0(p, 14);
            }
        } else if (!seen) {
            func_L33_00352ED0(p, 5);
        } else {
            func_L33_00352ED0(p, 6);
        }
        break;
    case 15:
        if (!func_L30_0034D1E8(p, &p->pos, &s->v60, &grav, D_L33_001DDAF8[idx], D_L33_001DDAF8[idx], 100.0f, s->fB8,
                               D_L33_001DDB40, 0.0f, 0, 0, 0, 0)) {
            p->f98 = 0;
            p->f34 = (p->f34 | 0x41) & ~0x1000;
            func_L01_004AA7E8(p, 1);
        }
        if (func_L01_00456250(p) || (s->fAC != -1 && func_00382380(&D_001A4C60, s->fAC, 0)) ||
            (s->fAC == -1 && s->fA0 != -1 && func_00382380(&D_001A4C60, s->fA0, 0)) ||
            (s->fAC == -1 && s->fA0 == -1 && func_L30_0034D8D8(&D_001A4C60, 1.5f))) {
            Ref_00350818 *ref;
            p->f34 &= 0xFFBE;
            ref = p->f24;
            p->f34 |= ref->f44 & 0x1000;
            p->f98 = ref->f10;
            if (p->oclass == 0x1761) {
                if (s->f98 != -1) {
                    func_L33_00352ED0(p, 7);
                } else {
                    func_L33_00352ED0(p, 3);
                }
            } else if (p->oclass == 0x1760) {
                func_L33_00352ED0(p, 8);
            } else {
                if (p->pos.x < D_001A4BE0.p25C0->pos.x) {
                    p->fF8 = func_0038DB48(D_L33_001DD980);
                } else {
                    p->fF8 = func_0038DB48(D_L33_001DD97C);
                }
                func_L01_00456230(D_001DFB1C + s->f98 * 256, 1);
                func_L33_00352ED0(p, 9);
            }
        }
        break;
    }
}
/* localdecomp:end func_L33_00350818 */

INCLUDE_ASM("asm/levels", func_L33_003523C0);

/* localdecomp:start func_L33_00352760 */
extern s32 D_001DDD64;
extern s32 D_001DDD60;

s32 func_L33_00352760(s32 add, s32 amount, s32 force) {
    amount -= 0x175E;
    if (add) {
        if (D_001DDD60 < D_001DDD64 + amount && !force) {
            return 0;
        }
        D_001DDD64 += amount;
    } else {
        if (D_001DDD64 - amount < 0) {
            return 0;
        }
        D_001DDD64 -= amount;
    }
    return 1;
}
/* localdecomp:end func_L33_00352760 */

/* localdecomp:start func_L33_003527C0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003527C0;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 D_L33_001DDB18[3] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDB18, 8");
extern f32 D_L33_001DDB00 __attribute__((section(".sdata")));
extern u8 D_L33_001E9600[];

f32 func_L33_003527C0(void *arg) {
    u8 *a0 = arg;
    u8 *s1 = *(u8 **)(a0 + 0x68);
    V_003527C0 p;
    V_003527C0 q;
    f32 w;
    f32 d;
    f32 x;
    f32 e;
    u8 *g;
    u8 *m;
    s16 t;

    p = *(V_003527C0 *)(a0 + 0x10);
    w = D_L33_001DDB18[0x1761 - *(s16 *)(a0 + 0xAA)];
    x = p.x;
    if (*(f32 *)(s1 + 0x80) < *(f32 *)(a0 + 0x10)) {
        d = -w;
        x += d;
    } else {
        x += w;
    }
    p.x = x;
    p.z += D_L33_001DDB00;
    q = p;
    q.x = *(f32 *)(s1 + 0x80);
    if (func_003D3CB0(&p, &q, 1, a0, 0)) {
        g = D_L33_001E9600;
        m = *(u8 **)(g + 0x18);
        if (m != 0) {
            if ((u32)(*(u16 *)(m + 0xAA) - 0x175F) < 3) {
                t = *(s16 *)(m + 0xAA);
                e = D_L33_001DDB18[0x1761 - t];
                if (*(f32 *)(g + 0x20) < *(f32 *)(a0 + 0x10)) {
                    return *(f32 *)(m + 0x10) + e + w;
                } else {
                    return *(f32 *)(m + 0x10) - e - w;
                }
            }
        }
    }
    return *(f32 *)(s1 + 0x80);
}
/* localdecomp:end func_L33_003527C0 */

/* localdecomp:start func_L33_00352908 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00352908;
extern s32 func_L33_003534E0(u8 *p);
extern void func_L30_0034CCD0(u8 *, f32 *, f32 *, f32 *, f32 *);
extern f32 func_003824E0(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 D_L33_001DDB3C;
__asm__(".extern D_L33_001DDB3C, 4");

void func_L33_00352908(void *arg) {
    u8 *a0 = arg;
    u8 *s1 = *(u8 **)(a0 + 0x68);
    f32 b[4];
    f32 v;
    f32 r;
    f32 x;
    f32 y;
    f32 t;

    *(V_00352908 *)(s1 + 0x80) = *(V_00352908 *)(a0 + 0x10);
    if (*(s32 *)(s1 + 0xA4) == -1) {
        v = *(f32 *)(s1 + 0x80);
        if (func_L33_003534E0(a0)) {
            r = v - D_L33_001DDB3C;
        } else {
            r = v + D_L33_001DDB3C;
        }
    } else {
        func_L30_0034CCD0(*(s32 *)(s1 + 0xA4) * 0x80 + D_L33_001DFC00, &b[0], &b[1], &b[2], &b[3]);
        if (func_L33_003534E0(a0)) {
            v = b[0];
            t = func_003824E0(0.2f, 0.4f);
            y = *(f32 *)(a0 + 0x10);
            x = v;
        } else {
            v = b[1];
            t = func_003824E0(0.6f, 0.8f);
            x = *(f32 *)(a0 + 0x10);
            y = v;
        }
        r = func_003C4088(x, y, t);
    }
    *(f32 *)(s1 + 0x80) = r;
}
/* localdecomp:end func_L33_00352908 */

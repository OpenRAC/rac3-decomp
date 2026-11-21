#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003E40D0 */
typedef struct {
    f32 x, y, z, w;
    f32 f10;
    f32 f14;
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[4];
    u8 pad20[16];
} __attribute__((aligned(16))) Ev_003E22E0;

typedef struct {
    f32 f00;
    f32 f04;
    f32 f08;
    u8 pad0C[8];
    s32 w14;
    s32 w18;
    s32 w1C;
    u8 pad20[4];
    f32 f24;
    s32 w28;
    s32 w2C;
    s32 w30;
    f32 f34;
    s32 w38;
    u8 pad3C[4];
    vu0_v4 hist[4];
} Priv_003E22E0;

typedef struct {
    f32 f00;
    f32 f04;
    f32 f08;
    s32 w0C;
    vu0_v4 v10;
} Rec_003E22E0;

typedef struct {
    u8 pad00[0x18];
    u8 *p18;
    u8 pad1C[4];
    vu0_v4 v20;
} Glob_003E22E0;

typedef struct {
    u8 pad00[0x5C];
    u8 *p5C;
} Tab_003E22E0;

extern u8 D_L07_001D66B0[8];
__asm__(".extern D_L07_001D66B0, 16");
extern Glob_003E22E0 D_L07_001E8C00;
extern Rec_003E22E0 D_L07_001EFD40[];
extern Tab_003E22E0 D_L07_0021EC98;
extern void func_L07_003E4048(u8 *);
extern void func_L01_00424D88(s32);
extern void func_003C2880(void *);
extern void func_L01_004CB320(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004CB358(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D4D00(void *, s32, s32, void *, f32);
extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
extern void func_L07_003E3DA8(void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00404A10_003E40D0(void *, void *);

void func_L07_003E40D0(u8 *obj) {
    vu0_v4 v0;
    vu0_v4 v10;
    Ev_003E22E0 ev;
    Priv_003E22E0 *p;
    u8 *o;
    u8 *e;
    Rec_003E22E0 *rec;
    s32 hit;
    vu0_v4 *hp;
    s32 r;
    s32 i;
    f32 f;
    f32 g;

    p = *(Priv_003E22E0 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0:
        *(vu0_q *)&v0 = *(vu0_q *)(obj + 0x10);
        p->f08 = p->f08 + p->f34;
        vec_add_ab(obj + 0x10, p, obj + 0x10);
        if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f || *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f || *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) {
            if (p->w18 != -1) {
                func_L01_00424D88(p->w18);
            }
            p->w18 = -1;
            func_003C2880(obj);
            return;
        }
        p->w14 = p->w14 + 1;
        r = p->w38;
        func_L01_004CB320();
        hit = func_003D3CB0(&v0, obj + 0x10, r, obj, 0);
        if (hit != 0) {
            e = D_L07_001E8C00.p18;
            if (e != 0 && *(s16 *)(e + 0xAA) == 0x186D && e[0x20] != 2 && e[0x20] != 5) {
                e[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit != 0) {
            if (!(D_L07_001E8C00.p18 != 0 && ((s32)D_L07_001E8C00.p18 == p->w1C || *(s16 *)(D_L07_001E8C00.p18 + 0xAA) == 0x199B || *(s16 *)(D_L07_001E8C00.p18 + 0xAA) == 0x199C || *(s16 *)(D_L07_001E8C00.p18 + 0xAA) == 0x199A) && D_L07_001E8C00.p18 != 0)) {
                *(vu0_q *)(obj + 0x10) = *(vu0_q *)&D_L07_001E8C00.v20;
                obj[0x20] = 1;
                *(vu0_q *)&v10 = *(vu0_q *)p;
                func_0038CE20(&v10, &v10, 2.0f);
                v10.w = 5627.925f;
                func_L01_00446760(&ev, obj, p->w28, &v10, p->f24);
                ev.b18 = 0;
                ev.b19 = 1;
                ev.h1A = *(u16 *)(obj + 0xAA);
                if (D_L07_001E8C00.p18 != 0) {
                    if ((s32)D_L07_001E8C00.p18 != p->w1C) {
                        func_003D4D00(&D_L07_001E8C00.v20, 0, p->w1C, &ev, *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 1.25f);
                    }
                } else {
                    func_003D4D00(&D_L07_001E8C00.v20, 0, p->w1C, &ev, *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 1.25f);
                }
            }
        }
        if (p->w18 == -1) {
            p->w18 = func_L01_00424CB0(obj + 0x10, 5.0f, 0.0f, 0.45f, 0.2f, 1.0f);
        } else {
            rec = &D_L07_001EFD40[p->w18];
            rec->v10 = *(vu0_v4 *)(obj + 0x10);
            rec->v10.z = rec->v10.z + 1.0f;
            rec->v10.w = 5.0f;
            rec->f00 = 0.45f;
            rec->f04 = 0.2f;
            rec->f08 = 1.0f;
            rec->w0C = 0;
        }
        if (p->w14 > p->w2C) {
            func_L07_003E3DA8(obj, p);
        }
        break;
    case 1:
        func_L07_003E3DA8(obj, p);
        break;
    }
    *(f32 *)(obj + 0xF4) = -func_0038D160(func_0038CED8(p), p->f08);
    *(f32 *)(obj + 0xF8) = func_0038D160(p->f00, p->f04);
    *(f32 *)(obj + 0xF0) = func_0038DAB8(*(f32 *)(obj + 0xF0), 0.13962635f);
    func_003C2F58(obj, 0, &v10);
    r = func_00382468(0x28);
    f = *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.6f * 210000.0f;
    g = func_003824E0(500.0f, 1500.0f);
    o = func_L01_0046A610(&v10, D_L07_001D66B0, 0x11, 0x60, 0x101010, r, f, g, 1.0f, 0.0f, 0.0f);
    if (o != 0) {
        o[2] = *D_L07_0021EC98.p5C;
        o[3] = 0x44;
    }
    *(vu0_q *)&ev = *(vu0_q *)&v10;
    i = 3;
    hp = &p->hist[2];
    for (; i > 0; i--) {
        hp[1] = hp[0];
        hp--;
    }
    p->hist[0] = *(vu0_v4 *)&ev;
    p->w30 = p->w30 + 1;
    if (p->w30 >= 4) {
        func_L01_00404A10_003E40D0(func_L07_003E4048, obj);
    }
}
/* localdecomp:end func_L07_003E40D0 */

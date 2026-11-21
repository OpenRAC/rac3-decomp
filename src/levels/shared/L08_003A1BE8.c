#include "common.h"
#include "vu0.h"

typedef struct {
    u8 p0[0x30];
    u8 v30[0x0E];
    u8 b3E;
    u8 p3F[0x5E - 0x3F];
    u8 b5E;
    u8 b5F;
    u8 p60[0x160 - 0x60];
    u8 v160[0x304 - 0x160];
    s32 i304;
    f32 f308;
} S_Vars3A1638;
typedef struct {
    u8 p0[0x20]; u8 state;
    u8 p21[0x68 - 0x21]; S_Vars3A1638 *vars;
} S_Moby3A1638;
typedef struct {
    u8 pad0[16];
    u8 pos[33];
    u8 b49;
    u8 pad32[61];
    u8 b111;
    u8 pad70[38];
    u16 h150;
} Moby_3A1DD8;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A1FA0;
typedef struct { s32 n; s32 pad[3]; V4_003A1FA0 pt[1]; } Path_003A1FA0;

/* localdecomp:start func_L08_003A1BE8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A1BE8;
extern V4_003A1BE8 D_001A4C60;
extern u8 D_L08_001D66B0[8];
extern f32 D_L08_001DE240;
__asm__(".extern D_L08_001DE240, 4");
extern s32 D_L08_001DE260;
__asm__(".extern D_L08_001DE260, 4");
extern s32 D_L08_001DE264;
__asm__(".extern D_L08_001DE264, 4");
extern s32 D_L08_001DE268;
__asm__(".extern D_L08_001DE268, 4");
extern s32 D_L08_001DE26C;
__asm__(".extern D_L08_001DE26C, 4");
extern s32 D_L08_001DE270;
__asm__(".extern D_L08_001DE270, 4");
extern s32 D_L08_001DE274;
__asm__(".extern D_L08_001DE274, 4");
extern s32 D_L08_001DE278;
__asm__(".extern D_L08_001DE278, 4");
extern s32 D_L08_001DE27C;
__asm__(".extern D_L08_001DE27C, 4");
extern s32 D_L08_001DE280;
__asm__(".extern D_L08_001DE280, 4");
extern f32 D_L08_001DE284;
__asm__(".extern D_L08_001DE284, 4");
extern f32 D_L08_001DE288;
__asm__(".extern D_L08_001DE288, 4");
extern f32 D_L08_001DE28C;
__asm__(".extern D_L08_001DE28C, 4");
extern f32 D_L08_001DE290;
__asm__(".extern D_L08_001DE290, 4");

extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004739D8(void *, void *, s32, s32, s16, u8, f32);
extern void *func_L08_003AA088(void *, void *, void *, f32, f32);
extern void func_L08_003A17C0(void *, void *, void *);

void func_L08_003A1BE8(u8 *m, u8 *t) {
    V4_003A1BE8 d;
    V4_003A1BE8 x;
    V4_003A1BE8 rot;
    V4_003A1BE8 unused; /* never used: retail's frame has a dead 16-byte slot at 0x40 */
    V4_003A1BE8 pos;
    V4_003A1BE8 tmp;
    s32 i;
    s32 c1, c2;
    f32 g, f;

    vec_sub_ab(&d, &D_001A4C60, m + 0x10);
    func_0038CF68(&d, &d, 1.0f);
    rot = *(V4_003A1BE8 *)(m + 0xE0);
    func_0038CE90(&x, &rot, &d);
    for (i = 0; i < 10; i++) {
        func_0038CE20(&tmp, &rot, func_L01_00443A18(0.0f, 0.5f));
        vec_add_ab(&pos, &tmp, &d);
        func_0038CE20(&tmp, &x, func_L01_00443A18(0.0f, 0.5f));
        vec_add_ab(&pos, &tmp, &pos);
        func_0038CE20(&pos, &pos, func_003824E0(D_L08_001DE290 * 0.4f, D_L08_001DE290) * 0.020000001f);
        c1 = func_0038DBD8(D_L08_001DE260, D_L08_001DE268, func_003824E0(0.0f, 1.0f));
        c2 = func_0038DBD8(D_L08_001DE264, D_L08_001DE26C, func_003824E0(0.0f, 1.0f));
        g = func_003824E0((f32)D_L08_001DE278 * 0.5f, (f32)D_L08_001DE278 * 2.5f);
        func_L01_00463378(t, &pos, D_L08_001D66B0, c1, c2, (D_L08_001DE270 * 5 + 2) / 6, (D_L08_001DE274 * 5 + 2) / 6,
            (s32)((g * 5.0f + 2.0f) / 6.0f), -1);
        func_0038CE20(&pos, &pos, func_003824E0(1.5f, 2.5f));
        f = func_003824E0(D_L08_001DE284, D_L08_001DE288) * 210000.0f;
        func_L01_004739D8(t, &pos, D_L08_001DE27C, D_L08_001DE280, (func_00382498(0x78, 0xF0) * 5 + 2) / 6, 0, f);
    }
    func_0038CE20(&tmp, &rot, func_L01_00443A18(0.0f, 0.75f));
    vec_add_ab(&pos, &tmp, &d);
    func_0038CE20(&tmp, &x, func_L01_00443A18(0.0f, 0.5f));
    vec_add_ab(&pos, &tmp, &pos);
    func_0038CE20(&pos, &pos, func_003824E0(D_L08_001DE28C * 0.7f, D_L08_001DE28C) * 0.020000001f);
    func_L08_003AA088(t, &pos, m, 0.0f, D_L08_001DE240);
    func_L08_003A17C0(m, t, &d);
}
/* localdecomp:end func_L08_003A1BE8 */

/* localdecomp:start func_L08_003A1FA0 */
#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)
#define P8(p, o) (((struct { u8 _p[o]; u8 *v; } *)(p))->v)


extern u8 *D_L08_001DF21C;
extern Path_003A1FA0 *D_L08_0021D140[];
extern s32 D_001D545C;
extern s32 D_L08_001DE230;
__asm__(".extern D_L08_001DE230, 4");
extern f32 D_L08_001DE234;
__asm__(".extern D_L08_001DE234, 4");
extern f32 D_L08_001DE238;
__asm__(".extern D_L08_001DE238, 4");
extern f32 D_L08_001DE23C;
__asm__(".extern D_L08_001DE23C, 4");
extern f32 D_L08_001DE244;
__asm__(".extern D_L08_001DE244, 4");
extern s32 D_L08_001DE248;
__asm__(".extern D_L08_001DE248, 4");
extern s32 D_L08_001DE24C;
__asm__(".extern D_L08_001DE24C, 4");
extern s32 D_L08_001DE250;
__asm__(".extern D_L08_001DE250, 4");
extern s32 D_L08_001DE254;
__asm__(".extern D_L08_001DE254, 4");
__asm__(".extern D_L08_001DE240, 4");
extern f32 D_L08_001DE258;
__asm__(".extern D_L08_001DE258, 4");

extern s32 func_L08_003A3380(void *);
extern void func_L08_003A3B20(void *);
extern s32 func_L08_003A3C90(u8 *, s32);
extern s32 func_L08_003A3E20(u8 *, s32);
extern void func_L08_003A37A0(void *);
extern void func_L02_003F4BE8(s32, u32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern void func_003C2880(void *);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_00451FE0(u8 *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_004468C8(u8 *, s32, f32, s32, f32, f32, s32, s32, s32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_L01_004395E0(void *);
extern s32 func_L01_0045BDE8(void *, s32);
extern s32 func_L01_00459590(void *, s32, f32);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_L01_00447878(void *, void *, s32, f32, f32);
extern void func_L01_00315900(void *, s32, s32);
extern void func_003C4C18(void *, f32);
extern void func_003C2F58(void *, s32, void *);

#define kill_3A1FA0(obj) { \
    u8 *o_ = (obj); \
    f32 a_ = 3.0f; \
    f32 b_ = 6.0f; \
    f32 c_ = -1.0f; \
    f32 d_ = 1.0f; \
    func_L01_00451FE0(o_, 0x4FFF, D_L08_001D66B0, a_, b_, a_, b_, 0xFF, c_, c_, 0xB4, 0, 0, 0x23, d_, d_, 0, 3); \
    func_L01_00451FE0(o_, 0x4FFF, D_L08_001D66B0, a_, b_, a_, b_, 0xFF, c_, c_, 0xB4, 0, 0, 0x23, d_, d_, 0, 3); \
    func_L01_004443E8(o_, 0, 3); \
    func_003C2880(o_); \
}

#define kill_cur_3A1FA0(st) { \
    s32 idx_ = S32(st, 0x318) ? S32(st, 0x2F8) : S32(st, 0x2E0); \
    if (idx_ != -1) { \
        kill_3A1FA0(D_L08_001DF21C + (idx_ << 8)) \
        if (S32(st, 0x318) == 0) { \
            S32(st, 0x2E0) = -1; \
        } else { \
            S32(st, 0x2F8) = -1; \
        } \
    } \
}

void func_L08_003A1FA0(u8 *m) {
    u8 *st = P8(m, 0x68);
    V4_003A1FA0 v10;
    V4_003A1FA0 v20;
    V4_003A1FA0 v30;
    s32 i;
    s32 t;
    s32 fl;
    s32 k;
    s32 r;
    Path_003A1FA0 *p;
    f32 d0;
    f32 dz;
    f32 f;

    if (func_L08_003A3380(m) != 0) {
        func_003C2880(m);
        return;
    }
    switch (U8(m, 0x95)) {
    case 3:
        fl = 0;
        if (func_L08_003A3C90(m, 0)) {
            fl = 1;
            S32(st, 0x318) = 0;
        } else if (func_L08_003A3C90(m, 1)) {
            S32(st, 0x318) = 1;
            fl = 1;
        }
        if (S32(st, 0x320) != 0) {
            if (func_L01_00456500(st + 0x220, S32(st, 0x2D8))) {
                func_L01_004450F0(m, 1, 0);
            }
        }
        if (S32(st, 0x324) != 0) {
            if (func_L01_00456500(st + 0x220, S32(st, 0x2F0))) {
                func_L01_004450F0(m, 1, 0);
            }
        }
        if (fl) {
            s32 cur;
            ((struct { u8 _p[0x320]; s32 v[2]; } *)st)->v[S32(st, 0x318)] = 1;
            U16(m, 0x34) &= 0xFFBE;
            U16(m, 0x34) |= U16(P8(m, 0x24), 0x44) & 0x1000;
            S32(m, 0x98) = S32(P8(m, 0x24), 0x10);
            func_L01_004450F0(m, 4, 1);
            if (U8(m, 0x43) != 2) {
                func_003C3A10(m, 2, 0, 8);
            }
            cur = S32(st, 0x318) ? S32(st, 0x2F8) : S32(st, 0x2E0);
            if (cur != -1) {
                func_L01_004450F0(m, 2, 1);
            }
        }
        break;
    case 0:
        if (S16(st, 0x234) == 1) {
            if (func_L08_003A3E20(m, 0)) {
                S32(st, 0x318) = 0;
                if (S32(st, 0x320) == 0) {
                    func_L01_004450F0(m, 0xB, 3);
                } else {
                    func_L01_004450F0(m, 4, 1);
                    if (U8(m, 0x43) != 2) {
                        func_003C3A10(m, 2, 0, 8);
                    }
                }
            } else if (func_L08_003A3E20(m, 1)) {
                S32(st, 0x318) = 1;
                if (S32(st, 0x324) == 0) {
                    func_L01_004450F0(m, 0xB, 3);
                } else {
                    func_L01_004450F0(m, 4, 1);
                    if (U8(m, 0x43) != 2) {
                        func_003C3A10(m, 2, 0, 8);
                    }
                }
            }
        }
        break;
    case 1:
        if (S16(st, 0x234) != 1 && func_L01_004561E0(m) == 0) {
            func_L01_004450F0(m, 6, 0);
            if (U8(m, 0x43) != 3) {
                func_003C3A10(m, 3, 0, 8);
            }
            S32(st, 0x30C) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        func_L01_00446780(m, m + 0x10, 0x10000, 0, 1, 0, D_L08_001DE258, 8.0f, 1.0f);
        break;
    case 2:
        t = func_L01_00454370(m, st + 0x160);
        if (func_L01_004561B8(m) && U8(m, 0x94) == 2) {
            kill_cur_3A1FA0(st)
        }
        if (t & 1) {
            func_L08_003A37A0(m);
            func_L01_00315900(m, 7, 0);
            { V4_003A1FA0 *p20 = &v20;
            V4_003A1FA0 *p10 = &v10;
            for (i = 4; i < 8; i++) {
                func_003C2F58(m, i, p20);
                v10 = v20;
                v10.w = 5.0f;
                if (func_L01_00459590(p10, 0, 255.0f) >= 0) {
                    func_L08_003A1BE8(m, (u8 *)p20);
                }
            } }
            if (S32(st, 0x2E0) != -1) {
                kill_3A1FA0(D_L08_001DF21C + (S32(st, 0x2E0) << 8))
            }
            if (S32(st, 0x2F8) != -1) {
                kill_3A1FA0(D_L08_001DF21C + (S32(st, 0x2F8) << 8))
            }
            return;
        }
        if (t & 2) {
            if (S16(st, 0x234) == 1) {
                func_L01_004450F0(m, 4, 1);
                if (U8(m, 0x43) != 2) {
                    func_003C3A10(m, 2, 0, 8);
                }
            } else {
                func_L01_004450F0(m, 1, 0);
                S32(st, 0x30C) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }

    switch (U8(m, 0x20)) {
    case 1:
        if (func_L01_004561B8(m) && U8(m, 0x43) != 1) {
            func_003C3A10(m, 1, 0, 8);
        }
        break;
    case 2:
        if (S32(st, 0x318) != 0 && S32(st, 0x2E8) == -1) {
            S32(st, 0x318) = 0;
        }
        { s32 n2 = S32(st, 0x318) ? S32(st, 0x2E8) : S32(st, 0x2D0);
        p = D_L08_0021D140[n2]; }
        if (func_L01_004561B8(m)) {
            if (D_001D545C == 8) {
                func_L02_003F4BE8(0xB76, 0x3A98);
            }
            if (U8(m, 0x43) != 0) {
                func_003C3A10(m, 0, 0, 8);
            }
            d0 = func_L01_0040E570(&p->pt[0], st + 0x2C0);
            if (func_L01_0040E570((u8 *)p + (p->n << 4), st + 0x2C0) < d0) {
                F32(m, 0x10) = p->pt[p->n - 1].x;
                F32(m, 0x14) = p->pt[p->n - 1].y;
            } else {
                F32(m, 0x10) = p->pt[0].x;
                F32(m, 0x14) = p->pt[0].y;
            }
            F32(m, 0xF8) = func_0038D160(F32(st, 0x220) - F32(m, 0x10), F32(st, 0x224) - F32(m, 0x14));
        }
        if (func_L01_0044E1B8(m, 20.0f) && U8(m, 0x42) == 0) {
            u8 *o;
            if (S32(st, 0x318) != 0) {
                o = D_L08_001DF21C + (S32(st, 0x2F8) << 8);
            } else {
                o = D_L08_001DF21C + (S32(st, 0x2E0) << 8);
            }
            if (S32(st, 0x2E0) == -1 && S32(st, 0x318) == 0 && S32(st, 0x2F8) != -1) {
                o = D_L08_001DF21C + (S32(st, 0x2F8) << 8);
            }
            kill_3A1FA0(o)
            if (S32(st, 0x318) == 0) {
                S32(st, 0x2E0) = -1;
            } else {
                S32(st, 0x2F8) = -1;
            }
        }
        if (U8(m, 0x60) & 2) {
            func_L01_004450F0(m, 4, -1);
            if (U8(m, 0x43) != 2) {
                func_003C3A10(m, 2, 0, 8);
            }
        }
        break;
    case 4:
        if (S32(st, 0x318) != 0 && S32(st, 0x2E8) == -1) {
            S32(st, 0x318) = 0;
        }
        if (S32(st, 0x318) == 0 && S32(st, 0x2E0) != -1) {
            kill_3A1FA0(D_L08_001DF21C + (S32(st, 0x2E0) << 8))
            if (S32(st, 0x318) == 0) {
                S32(st, 0x2E0) = -1;
            }
        } else if (S32(st, 0x318) != 0 && S32(st, 0x2F8) != -1) {
            kill_3A1FA0(D_L08_001DF21C + (S32(st, 0x2F8) << 8))
            if (S32(st, 0x318) != 0) {
                S32(st, 0x2F8) = -1;
            }
        }
        k = S32(st, 0x318) ? S32(st, 0x2E8) : S32(st, 0x2D0);
        if (func_L01_004561B8(m)) {
            S32(st, 0xA8) &= ~4;
            S32(st, 0xA8) &= ~0x10;
            F32(st, 0x78) = 0.7f;
            F32(st, 0x7C) = 0.7f;
            U16(m, 0x34) &= 0xFEFF;
            F32(st, 0x80) = 12.566371f;
            S32(st, 0xA8) |= 3;
            if (k != -1) {
                p = D_L08_0021D140[k];
                d0 = func_L01_0040E570(&p->pt[0], st + 0x2C0);
                if (func_L01_0040E570((u8 *)p + (p->n << 4), st + 0x2C0) < d0) {
                    func_L01_0045C150(m, p, 0, 0);
                } else {
                    func_L01_0045C150(m, p, p->n - 1, p->n - 1);
                }
            }
            if (U8(m, 0x43) != 2) {
                func_003C3A10(m, 2, 0, 8);
            }
        }
        if (k == -1) {
            func_L01_0045A748(m, st + 0x220);
            if (func_0038CF38(m + 0x10, st + 0x220) < D_L08_001DE244) {
                func_L01_004450F0(m, 9, -1);
                if (U8(m, 0x43) != 6) {
                    func_003C3A10(m, 6, 0, 8);
                }
            }
        } else {
            dz = fabs_asm(F32(m, 0x18) - F32(st, 0x228));
            r = func_L01_0045BDE8(m, k);
            if (func_0038CF38(m + 0x10, st + 0x220) < D_L08_001DE244) {
                func_L01_004450F0(m, 9, -1);
                if (U8(m, 0x43) != 6) {
                    func_003C3A10(m, 6, 0, 8);
                }
            } else if (r != 0 || U16(m, 0x96) >= 0x33 || dz > 3.0f) {
                func_L01_004450F0(m, 7, -1);
                if (U8(m, 0x43) != 4) {
                    func_003C3A10(m, 4, 0, 8);
                }
            }
            if (func_0038CF38(m + 0x10, st + 0x220) < 6.0f) {
                func_L01_004450F0(m, 7, -1);
                if (U8(m, 0x43) != 4) {
                    func_003C3A10(m, 4, 0, 8);
                }
            }
        }
        if (!func_L01_00456500(st + 0x220, S32(st, 0x318) ? S32(st, 0x2F0) : S32(st, 0x2D8))) {
            func_L01_004450F0(m, 6, -1);
            if (U8(m, 0x43) != 3) {
                func_003C3A10(m, 3, 0, 8);
            }
        }
        func_L01_00446780(m, m + 0x10, 0x10000, 0, 1, 0, D_L08_001DE258, 8.0f, 1.0f);
        break;
    case 6:
        if (func_L01_004561B8(m) && U8(m, 0x43) != 3) {
            func_003C3A10(m, 3, 0, 8);
        }
        func_L01_0045A748(m, st + 0x2C0);
        if (func_0038CF38(m + 0x10, st + 0x2C0) < F32(st, 0xA4)) {
            func_L01_004450F0(m, 1, 0);
            if (U8(m, 0x43) != 1) {
                func_003C3A10(m, 1, 0, 8);
            }
        }
        break;
    case 7:
        func_L01_0045BD10(m, func_0038D160(F32(st, 0x220) - F32(m, 0x10), F32(st, 0x224) - F32(m, 0x14)));
        if (func_L01_004561B8(m) && U8(m, 0x43) != 4) {
            func_003C3A10(m, 4, 0, 8);
        }
        if (U8(m, 0x60) & 2) {
            func_L01_004450F0(m, 8, -1);
            if (U8(m, 0x43) != 5) {
                func_003C3A10(m, 5, 0, 2);
            }
        }
        break;
    case 8:
        func_L01_0045BD10(m, func_0038D160(F32(st, 0x220) - F32(m, 0x10), F32(st, 0x224) - F32(m, 0x14)));
        if (func_L01_004561B8(m)) {
            S32(st, 0x328) = 0;
        }
        if (U8(m, 0x60) & 2) {
            func_L01_004450F0(m, 4, -1);
            if (U8(m, 0x43) != 2) {
                func_003C3A10(m, 2, 0, 8);
            }
        }
        if (D_L08_001DE238 < func_L01_004395E0(m) && S32(st, 0x328) < D_L08_001DE230) {
            f32 dist = func_0038CF38(m + 0x10, st + 0x220);
            f32 sp;
            V4_003A1FA0 *pv = &v10;
            v10 = *(V4_003A1FA0 *)(st + 0x220);
            if (S32(st, 0x328) != 0) {
                func_003C4C18(pv, D_L08_001DE234 * dist);
            }
            sp = D_L08_001DE23C * dist;
            func_003C2F58(m, 2, &v20);
            sp = sp * 0.020000001f;
            vec_sub_ab(&v30, &v10, &v20);
            func_0038CF68(&v30, &v30, sp);
            v30.z = func_L01_00447878(&v20, pv, 0, sp, -(D_L08_001DE240 * 0.00040000002f));
            func_L08_003AA088(&v20, &v30, m, (f32)U8(st, 0x44), D_L08_001DE240);
            S32(st, 0x328)++;
        }
        break;
    case 9:
        if (func_L01_004561B8(m) && U8(m, 0x43) != 6) {
            func_003C3A10(m, 6, 0, 8);
        }
        func_L01_0045BD10(m, func_0038D160(F32(st, 0x220) - F32(m, 0x10), F32(st, 0x224) - F32(m, 0x14)));
        f = func_L01_004395E0(m);
        if (f < (f32)D_L08_001DE254 && (f32)D_L08_001DE250 < f) {
            func_L01_004468C8(m, 0, 1.0f, 1, 5.0f, 1.5f, 0, 1, 0);
        }
        if (f < (f32)D_L08_001DE24C && (f32)D_L08_001DE248 < f) {
            func_L01_004468C8(m, 1, 1.0f, 1, 5.0f, 1.5f, 0, 1, 0);
        }
        if (U8(m, 0x60) & 2) {
            func_L01_004450F0(m, 4, -1);
            if (U8(m, 0x43) != 2) {
                func_003C3A10(m, 2, 0, 8);
            }
        }
        break;
    }
    func_L08_003A3B20(m);
}
/* localdecomp:end func_L08_003A1FA0 */

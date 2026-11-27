/* func_L01_002F78B0: matches alone, but as C its jump table joins func_L01_002FC910's in the file's read-only data while retail keeps the tables of the assembly functions between them (func_L01_002FA1F8, func_L01_002FAAA0) in between, so no level links (level_symbols: two places for the file's .rodata) (reverted from src/levels/shared/L01_002F7800.c, 2026-11-27). */
#include "common.h"
/* localdecomp:start func_L01_002F78B0 */
typedef struct {
    vu0_v4 home;                /* 0x00 */
    vu0_v4 rot;                 /* 0x10 */
    vu0_v4 spin;                /* 0x20 */
    vu0_v4 vel;                 /* 0x30 */
    vu0_v4 up;                  /* 0x40 */
    vu0_v4 tilt;                /* 0x50 */
    f32 radius;                 /* 0x60 */
    u8 *hit;                    /* 0x64 */
    u8 *target;                 /* 0x68 */
    u8 landed;                  /* 0x6C */
    u8 flags;                   /* 0x6D */
    u8 hop_len;                 /* 0x6E */
    u8 hop;                     /* 0x6F */
    f32 f70;                    /* 0x70 */
    f32 f74;                    /* 0x74 */
    f32 floor;                  /* 0x78 */
} St_2F78B0;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;                 /* 0x10 */
    u8 state;                   /* 0x20 */
    u8 pad21[3];
    u8 *cls;                    /* 0x24 */
    u8 pad28[4];
    f32 scale;                  /* 0x2C */
    u8 f30;                     /* 0x30 */
    u8 f31;                     /* 0x31 */
    u16 f32;                    /* 0x32 */
    u16 flags;                  /* 0x34 */
    u8 pad36[0x63 - 0x36];
    u8 f63;                     /* 0x63 */
    u8 pad64[4];
    St_2F78B0 *vars;            /* 0x68 */
    u8 pad6C[0xB0 - 0x6C];
    u8 fB0;                     /* 0xB0 */
    u8 padB1;
    s16 fB2;                    /* 0xB2 */
    u8 padB4[0xC0 - 0xB4];
    vu0_v4 m0;                  /* 0xC0 */
    vu0_v4 m1;                  /* 0xD0 */
    vu0_v4 m2;                  /* 0xE0 */
} M_2F78B0;
typedef struct {
    u8 pad0[0x18];
    u8 *obj;                    /* 0x18 */
    u8 pad1C[4];
    vu0_v4 pos;                 /* 0x20 */
    u8 pad30[0x10];
    vu0_v4 normal;              /* 0x40 */
} Hit_2F78B0;
typedef struct {
    u8 pad0[0x20];
    vu0_v4 v20;                 /* 0x20 */
    vu0_v4 v30;
    vu0_v4 v40;                 /* 0x40 */
    u8 pad50[0x30];
    vu0_v4 pos;                 /* 0x80 */
    u8 pad90[0x50];
    vu0_v4 vE0;                 /* 0xE0 */
    u8 padF0[0x60];
    vu0_v4 v150;                /* 0x150 */
    u8 pad160[0x2F0 - 0x160];
    vu0_v4 v2F0;                /* 0x2F0 */
    u8 pad300[0x25C0 - 0x300];
    u8 *hero;                   /* 0x25C0 */
    u8 pad25C4[0x2824 - 0x25C4];
    f32 near_r;                 /* 0x2824 */
    f32 near_h;                 /* 0x2828 */
    u8 pad282C[0x2850 - 0x282C];
    s32 f2850;                  /* 0x2850 */
} G_2F78B0;
typedef struct { f32 scale; u8 pad4[8]; f32 pitch; f32 f10; f32 speed; s32 bolts; } Kind_2F78B0;
typedef struct { u8 pad0[0x3C]; s32 bolts; } P_2F78B0;
typedef struct { u8 pad[0x464]; u8 arr[1]; } Drop_2F78B0;
extern G_2F78B0 D_001A4BE0_002F78B0;
extern vu0_v4 D_001A4CC0;
extern u8 D_L01_001EAA00[];
extern Kind_2F78B0 D_L01_002BE708_002F78B0[];
extern P_2F78B0 D_00142660_002F78B0;
extern M_2F78B0 *D_L01_001E0020;
__asm__(".extern D_L01_001E0020, 4");
extern M_2F78B0 *D_L01_001E0020_002F78B0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 4");
extern u8 D_001BBC40[];
extern u8 D_L01_001DFE80[] __attribute__((section(".sdata")));
extern Drop_2F78B0 D_L01_00236B90;
extern Drop_2F78B0 D_L01_00237800;

#define HIT_2F78B0 ((Hit_2F78B0 *)D_L01_001EAA00)

/* The bolt's update: spawn, hop, rest, hop in place, pulled to the hero. The f31 check that ends
 * cases 1-3 is written out where each branch returns; gcc cross-jumps the copies into one. */
void func_L01_002F78B0(M_2F78B0 *self) {
    extern void func_L01_002F88E0(void *);
    extern void func_L01_002F8AA8(u8 *, vu0_q *, vu0_q *);
    extern s32 func_L01_002F8D40(u8 *, u8 *, s32, f32, f32);
    extern void func_L01_002F9310(void *, s32);
    extern s32 func_L01_002F94F8();
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern s32 func_003D5630(void);
    extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
    extern f32 func_0038CEA8(void *);
    extern f32 func_0038CED8(void *);
    extern f32 func_L01_0040E4C0(u8 *);
    extern f32 func_L01_0040E548(void *, void *);
    extern f32 func_L01_0040E570(void *, void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D308(void *, void *);
    extern void func_0038D688(void *, void *, void *);
    extern void func_0038D6C8(void *, void *, void *, f32);
    extern void func_0038D810(void *, void *);
    extern void func_L01_0040F128(void *, void *, void *, void *, void *, void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003C2880(void *);
    extern void func_003C6F90(void *, s32, s32, s32, s32);
    extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
    extern void func_003C6FB0(void *, s32 *, s32 *, s32 *);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern void func_003C3FC0(void *, void *);
    extern f32 func_003C4138(f32 *, f32, f32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_003C48A8(void *, void *);
    extern void func_003C4BB0(float *, float);
    extern u8 *func_003C4D58(void *);
    extern void func_L01_0044CB18(void *, void *, void *, void *, void *, void *);
    extern void func_L01_0044E820(u8 *, s32);
    extern s32 func_003A52A0(s32, s32, u8 *);
    St_2F78B0 *st = self->vars;
    vu0_v4 a;           /* 0x00 */
    vu0_v4 b;           /* 0x10 */
    vu0_v4 c;           /* 0x20 */
    vu0_v4 q1;          /* 0x30 */
    vu0_v4 q2;          /* 0x40 */
    s32 rx, ry, rz;      /* 0x50 */

    f32 d, t, ang;
    s32 n, hit;
    u8 f;

    switch (self->state) {
    case 0:
        func_L01_002F7808();
        func_L01_004450F0((u8 *)self, 3, -1);
        self->f63 = 10;
        self->flags |= 0x100;
        self->f30 = 0x20;
        self->f32 = 0x20;
        st->flags = 0;
        if (func_00382468(2) == 0) {
            st->flags |= 1;
        }
        func_0038CF68(&a, &self->m2, 0.200000003f);
        vec_add_ab(&a, &a, &self->pos);
        func_0038CF68(&b, &self->m2, -3.0f);
        vec_add_ab(&b, &b, &self->pos);
        hit = func_003D3CB0(&a, &b, 0x22, 0, 0);
        if (st->landed == 0 && hit != 0) {
            qzero(&c);
            c.y = func_0038D160(HIT_2F78B0->normal.z, func_0038CED8(&HIT_2F78B0->normal));
            c.y = func_0038DAB8(c.y, D_L01_002BE708_002F78B0[func_L01_002F94F8(self)].pitch);
            c.z = func_0038D160(HIT_2F78B0->normal.x, HIT_2F78B0->normal.y);
            func_0038D750((f32 *)&q1, 1, c.y);
            func_0038D750((f32 *)&q2, 2, c.z);
            func_0038D688(&st->rot, &q1, &q2);
            func_0038D750((f32 *)&st->tilt, 0, 0.0f);
            func_0038CF68(&st->up, &HIT_2F78B0->normal, 1.0f);
            if (st->flags & 1) {
                func_003C4840(&st->vel, &st->up, -D_L01_002BE708_002F78B0[func_L01_002F94F8(self)].speed);
            } else {
                func_003C4840(&st->vel, &st->up, D_L01_002BE708_002F78B0[func_L01_002F94F8(self)].speed);
            }
            *(vu0_q *)&st->home = *(vu0_q *)&HIT_2F78B0->pos;
            if (HIT_2F78B0->obj != 0 && func_003C4D58(HIT_2F78B0->obj) != 0) {
                st->hit = HIT_2F78B0->obj;
                func_L01_0044CB18(self, st->hit, st, &c, st, &c);
            }
        } else {
            *(vu0_q *)&st->home = *(vu0_q *)&self->pos;
            func_0038D750((f32 *)&st->rot, 2, 0.0f);
            func_0038D750((f32 *)&st->tilt, 0, 0.0f);
            if (st->flags & 1) {
                func_0038D750((f32 *)&st->vel, 2, -D_L01_002BE708_002F78B0[func_L01_002F94F8(self)].speed);
            } else {
                func_0038D750((f32 *)&st->vel, 2, D_L01_002BE708_002F78B0[func_L01_002F94F8(self)].speed);
            }
        }
        st->floor = self->pos.z;
        func_L01_0044E820((u8 *)self, 0x80181010);
        func_003C6FB0(self, &rx, &ry, &rz);
        func_003C6F90(self, 0, 13, 0, 0);
        func_L01_0043B9E8((u8 *)self, rx, ry, rz);
        self->scale = *(f32 *)(self->cls + 0x24) * D_L01_002BE708_002F78B0[func_L01_002F94F8(self)].scale;
        return;
    case 1:
        {
        f32 dd = func_L01_0040E570(&self->pos, &D_001A4BE0_002F78B0.pos);
        f = st->flags;
        if (!(f & 4) && dd < D_001A4BE0_002F78B0.near_r * D_001A4BE0_002F78B0.near_r && fabs_asm(self->pos.z - D_001A4BE0_002F78B0.pos.z) < D_001A4BE0_002F78B0.near_h) {
            st->flags = f | 4;
        }
        }
        st->vel.z -= 0.0043200003f;
        vec_add_ab(&self->pos, &self->pos, &st->vel);
        func_L01_0040F128(&self->m0, &self->m1, &self->m2, &self->m0, &self->m1, &self->m2, &st->spin);
        if (self->pos.z < st->floor - 2.0f && self->pos.z < D_001A4BE0_002F78B0.pos.z - 2.0f) {
            func_L01_002F8D40((u8 *)self, D_001A4BE0_002F78B0.hero, 0, func_003824E0(-0.261799395f, 0.261799395f), 0.0f);
        } else if (func_L01_003FB640(&self->pos, 0x22, self, 0.25f) != 0) {
            vec_sub_ab(&a, &self->pos, &HIT_2F78B0->pos);
            func_L01_0040E790(&st->vel, &st->vel, &a);
            func_0038CF68(&st->up, &HIT_2F78B0->normal, 1.0f);
            if (D_001A4BE0_002F78B0.f2850 != 0 && ((st->flags & 4)
                    || (func_L01_0040E570(&self->pos, &D_001A4BE0_002F78B0.pos) < D_001A4BE0_002F78B0.near_r * D_001A4BE0_002F78B0.near_r && fabs_asm(self->pos.z - D_001A4BE0_002F78B0.pos.z) < D_001A4BE0_002F78B0.near_h)
                    || func_003D5630() != -1)) {
                func_0038CF68(&st->vel, &st->vel, 0.160000011f);
                func_L01_002F8D40((u8 *)self, D_001A4BE0_002F78B0.hero, 0, 0.0f, 0.0f);
            } else if (func_0038D160(a.z, func_0038CED8(&a)) < 0.785398185f
                       && func_0038D160(HIT_2F78B0->normal.z, func_0038CED8(&HIT_2F78B0->normal)) < 0.785398185f) {
                qzero(&b);
                b.y = func_0038D160(HIT_2F78B0->normal.z, func_0038CED8(&HIT_2F78B0->normal));
                b.y = func_0038DAB8(b.y, D_L01_002BE708_002F78B0[func_L01_002F94F8(self)].pitch);
                b.z = func_0038D160(HIT_2F78B0->normal.x, HIT_2F78B0->normal.y);
                func_0038D750((f32 *)&c, 1, b.y);
                func_0038D750((f32 *)&q1, 2, b.z);
                func_0038D688(&st->rot, &c, &q1);
                func_0038D750((f32 *)&st->tilt, 0, 0.0f);
                if (st->flags & 1) {
                    func_003C4840(&st->vel, &st->up, -D_L01_002BE708_002F78B0[func_L01_002F94F8(self)].speed);
                } else {
                    func_003C4840(&st->vel, &st->up, D_L01_002BE708_002F78B0[func_L01_002F94F8(self)].speed);
                }
                *(vu0_q *)&st->home = *(vu0_q *)&HIT_2F78B0->pos;
                func_L01_004450F0((u8 *)self, 2, -1);
                st->hop = st->hop_len = (func_003824E0(30.0f, 40.0f) * 5.0f + 2.0f) / 6.0f;
                if (HIT_2F78B0->obj != 0 && func_003C4D58(HIT_2F78B0->obj) != 0) {
                    st->hit = HIT_2F78B0->obj;
                    func_L01_0044CB18(self, st->hit, st, &b, st, &b);
                }
                func_003C48A8(&self->m0, &q2);
                func_003C3FC0(&st->spin, &q2);
                if (self->f31 != 0) {
                    func_L01_002F9310(self, 1);
                }
                return;
            }
        }
        if (self->f31 != 0) {
            func_L01_002F9310(self, 1);
        }
        return;
    case 2:
        {
        f32 dd = func_L01_0040E570(&self->pos, &D_001A4BE0_002F78B0.pos);
        f = st->flags;
        if (!(f & 4) && dd < D_001A4BE0_002F78B0.near_r * D_001A4BE0_002F78B0.near_r && fabs_asm(self->pos.z - D_001A4BE0_002F78B0.pos.z) < D_001A4BE0_002F78B0.near_h) {
            st->flags = f | 4;
        }
        }
        func_L01_002F8AA8((u8 *)self, (vu0_q *)&a, (vu0_q *)&b);
        a.z += 0.25f;
        {
            f32 k = st->hop;
            f32 inv = 1.0f / k;
            k = k / st->hop_len;
            func_0038D6C8(&st->spin, &st->spin, &b, inv);
            func_0038CDF8((f32 *)&self->pos, (f32 *)&self->pos, (f32 *)&a, k);
            k -= 0.5f;
            self->pos.z += -(k * k - 0.25f) * (st->hop_len * 0.0250000004f);
        }
        func_0038D810(&st->spin, &self->m0);
        if (--st->hop == 0) {
            func_L01_004450F0((u8 *)self, 3, -1);
            st->hop = st->hop_len = (func_003824E0(10.0f, 20.0f) * 5.0f + 2.0f) / 6.0f;
        }
        if (self->f31 != 0) {
            func_L01_002F9310(self, 1);
        }
        return;
    case 3:
        d = func_L01_0040E570(&self->pos, &D_001A4BE0_002F78B0.pos);
        if ((st->flags & 4) || (d < D_001A4BE0_002F78B0.near_r * D_001A4BE0_002F78B0.near_r && fabs_asm(self->pos.z - D_001A4BE0_002F78B0.pos.z) < D_001A4BE0_002F78B0.near_h)) {
            func_L01_002F8D40((u8 *)self, D_001A4BE0_002F78B0.hero, 0, 0.0f, 0.0f);
        } else if (self > D_L01_001E0020 && d > 1024.0f && self->f31 == 0) {
            D_00142660_002F78B0.bolts += D_L01_002BE708_002F78B0[func_L01_002F94F8(self)].bolts;
            func_003C2880(self);
            return;
        } else if (self->f31 != 0 || st->hit != 0) {
            func_L01_002F8AA8((u8 *)self, 0, 0);
            if (st->hop != 0) {
                f32 k = (f32)st->hop / st->hop_len - 0.5f;
                self->pos.z += -(k * k - 0.25f) * (st->hop_len * 0.0125000002f);
                st->hop--;
            }
            if (self->f31 != 0) {
                func_L01_002F9310(self, 1);
            }
            return;
        } else if (st->hop != 0) {
            st->hop--;
        }
        if (self->f31 != 0) {
            func_L01_002F9310(self, 1);
        }
        return;
    case 4:
        n = 0;
        if (*(s16 *)(st->target + 0xAA) == 0) {
            vec_sub_ab(&a, &self->pos, &D_001A4BE0_002F78B0.v2F0);
            func_0038D028(&a, &a, &D_001A4BE0_002F78B0.v40);
            if (a.z < 0.0f) {
                n = 1;
            }
        }
        if (n != 0) {
            func_0038CF68(&a, &D_001A4BE0_002F78B0.v20, 0.160000011f);
            vec_sub_ba(&b, &a, &st->vel);
            func_003C4BB0((f32 *)&b, 0.0200000014f);
            vec_add_ab(&st->vel, &st->vel, &b);
        } else {
            t = 0.00960000046f;
            if (st->flags & 8) {
                func_003C4138(&st->radius, 1.60000014f, 0.0256000012f);
            } else {
                if (func_0038CEA8(&st->vel) > t) {
                    func_0038CF68(&a, &st->vel, t);
                    vec_sub_ab(&st->vel, &st->vel, &a);
                }
                func_003C4138(&st->radius, 0.640000045f, t);
            }
        }
        {
            f32 len = func_0038CEA8(&D_001A4BE0_002F78B0.v150);
            if (len > 0.0800000057f) {
                func_0038CF68(&a, &D_001A4BE0_002F78B0.v150, len - 0.0800000057f);
            vec_add_ab(&self->pos, &self->pos, &a);
            }
        }
        func_L01_0040F128(&self->m0, &self->m1, &self->m2, &self->m0, &self->m1, &self->m2, &st->spin);
        vec_add_ab(&self->pos, &self->pos, &st->vel);
        if (!(st->flags & 8) || !(func_L01_0040E548(st->target + 0x10, &self->pos) < 0.25f)) {
            if (*(s16 *)(st->target + 0xAA) == 0) {
                vec_sub_ab(&a, &D_001A4CC0, &self->pos);
            } else {
                vec_sub_ab(&a, st->target + 0x10, &self->pos);
            }
            if (func_L01_0040E4C0((u8 *)&a) > st->radius * st->radius) {
                if (st->f74 != 0.0f || st->f70 != 0.0f) {
                    func_0038D000(&a, &a, &D_001A4BE0_002F78B0.v40);
                    ang = func_0038D160(a.x, a.y);
                    qzero(&q2);
                    {
                        f32 y = st->f70;
                        q2.y = y;
                        if (ang < 1.57079637f && ang > -1.57079637f) {
                            q2.y = -y;
                        }
                    }
                    q2.z = st->f74;
                    func_0038D308(&b, &q2);
                    func_0038D000(&a, &a, &b);
                    func_0038D000(&a, &a, &D_001A4BE0_002F78B0);
                }
                func_0038CF68(&a, &a, st->radius);
                vec_add_ab(&self->pos, &self->pos, &a);
                break;
            }
        }
        func_L01_002F88E0(self);
        func_003A52A0(0, 0x20, (u8 *)self);
        if (self < D_L01_001E0020_002F78B0) {
            (&D_L01_00236B90)->arr[self->fB2] = self->fB0 + 2;
            if (self->fB0 == 0xFF
                || (!(D_L01_001DFE80[self->fB0] & 0x80) && (D_001BBC40[self->fB0 + (D_001D545C << 4)] & 0x80))) {
                D_L01_00237800.arr[self->fB2] = self->fB0 + 2;
            }
        }
        func_003C2880(self);
        return;
    default:
        return;
    }
    if (self->f31 != 0) {
        func_L01_002F9310(self, 0);
    }
}
/* localdecomp:end func_L01_002F78B0 */

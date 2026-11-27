#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_002F7800 */
void func_L01_002F7800(void) {
}
/* localdecomp:end func_L01_002F7800 */

/* localdecomp:start func_L01_002F7808 */
typedef struct {
    float a[4];
    float b[4];
} Pair_002F7888;
typedef struct {
    u8 pad[16];
    float f;
    u8 pad2[8];
} Src_002F7888;
__asm__(".extern D_L01_001DC2C0, 4");
extern s32 D_L01_001DC2C0;
extern Pair_002F7888 D_L01_0026E050[];
extern Src_002F7888 D_L01_002BE708[];
extern void func_0038D750(float *, s32, float);
void func_L01_002F7808(void) {
    s32 i;
    if (D_L01_001DC2C0 == 0) {
        for (i = 0; i < 10; i++) {
            func_0038D750(D_L01_0026E050[i].a, 0, D_L01_002BE708[i].f);
            func_0038D750(D_L01_0026E050[i - 1].b, 0, -D_L01_002BE708[i].f);
        }
        D_L01_001DC2C0 = 1;
    }
}
/* localdecomp:end func_L01_002F7808 */

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

/* localdecomp:start func_L01_002F88E0 */
extern s32 D_00142660[];
extern s32 D_L01_001D6714;
extern u8 *D_001E0020_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_001D545C_sda;
extern s32 D_001A9280[];
typedef struct { u8 pad[24]; s32 val; } Row_88E0;
typedef struct { Row_88E0 arr[10]; } Tbl_88E0;
typedef struct {
    u8 pad[0xAA];
    u16 f_AA;
} S_002F94F8;
void func_L01_002F88E0(u8 *m) {
    extern s32 func_L01_002F94F8(S_002F94F8 *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern void func_003E54E0(s32);
    extern void func_L01_00443B88(f32 *, f32, f32);
    extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, s32, f32, f32, f32);
    f32 direction[4] __attribute__((aligned(16)));
    f32 position[4] __attribute__((aligned(16)));
    Tbl_88E0 *t = (Tbl_88E0 *)D_L01_002BE708;
    u8 *vars = *(u8 **)(m + 0x68);
    s32 n;
    s32 increment;
    f32 scale;
    increment = t->arr[func_L01_002F94F8((void *)m)].val;
    D_00142660[0] += increment;
    if ((vars[0x6D] & 2) || (D_L01_001D6714 && m < D_001E0020_sda)) {
        D_001A9280[D_001D545C_sda] += increment;
    }
    func_003E54E0(150);
    func_L01_00443B88(direction, 0.014f, 0.020000001f);
    func_0038CE20(position, direction, 10.0f);
    vec_add_ba(position, position, m + 0x10);
    n = func_00382468(2);
    if (n == 0) n--;
    scale = func_003824E0(0.4f, 0.5f);
    func_L01_0046B458(position, 21, 0x7F207F7F, 0, n, direction, 0, scale * 0.2f, scale, 0.0f);
    func_L01_0046B458(position, 21, 0x7F7F7F7F, 1, -n, direction, 0, scale * 0.14f, scale * 0.7f, 0.0f);
}
/* localdecomp:end func_L01_002F88E0 */

/* localdecomp:start func_L01_002F8AA8 */
#include "vu0.h"
typedef struct {
    u8 pad[0xAA];
    u16 f_AA;
} S_002F94F8_8AA8;
extern vu0_v4 D_L01_0026E040[][2];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001DFB40_002F8AA8;
__asm__(".extern D_L01_001DFB40_002F8AA8, 16");
void func_L01_002F8AA8(u8 *obj, vu0_q *out_pos, vu0_q *out_rot) {
    extern s32 func_L01_002F94F8_002F8AA8(S_002F94F8_8AA8 *);
    extern void func_0038D688(void *, void *, void *);
    extern void func_L01_0044C998(void *, void *, void *, void *, void *, void *);
    extern void func_003C3FC0(void *, void *);
    extern void func_0038D850(void *, void *, void *);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern u8 *func_003C4D58(void *);
    extern void func_0038D810(void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    vu0_v4 offset, position, rotation, direction, angles, parent_matrix;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 kind = func_L01_002F94F8_002F8AA8((S_002F94F8_8AA8 *)obj);
    Src_002F7888 *settings;
    func_0038D688(vars + 0x50, &D_L01_0026E040[kind][vars[0x6D] & 1], vars + 0x50);
    func_0038D688(vars + 0x10, vars + 0x10, vars + 0x30);
    func_0038D688(&rotation, vars + 0x50, vars + 0x10);
    if (*(u8 **)(vars + 0x64)) {
        s32 detach;
        u8 *parent;
        qzero(&angles);
        func_L01_0044C998(obj, *(u8 **)(vars + 0x64), vars, &angles, &position, &angles);
        func_003C3FC0(&parent_matrix, &angles);
        func_0038D688(&rotation, &rotation, &parent_matrix);
        func_0038D850(&direction, vars + 0x40, &parent_matrix);
        if (obj[0x20] == 3) {
            detach = 0;
            parent = *(u8 **)(vars + 0x64);
            if (parent == 0 || parent[0x20] == 0xFE || parent[0x20] == 0xFD) {
                detach = 1;
            } else if (((D_L01_001DFB40_002F8AA8 + ((obj - D_L01_001E001C) >> 8)) & 7) == 0) {
                detach = !func_L01_003FB640(obj + 0x10, 0x22, obj, 0.25f);
            }
            if (detach) {
                u8 *p;
                func_L01_004450F0(obj, 1, -1);
                qzero(vars + 0x20);
                *(f32 *)(vars + 0x2C) = 1.0f;
                p = func_003C4D58(*(u8 **)(vars + 0x64));
                if (p) *(vu0_q *)(vars + 0x30) = *(vu0_q *)(p + 0x10);
                else qzero(vars + 0x30);
                *(s32 *)(vars + 0x64) = 0;
            }
        }
    } else {
        *(vu0_q *)&position = *(vu0_q *)vars;
        *(vu0_q *)&direction = *(vu0_q *)(vars + 0x40);
    }
    func_0038D810(&rotation, obj + 0xC0);
    kind = func_L01_002F94F8_002F8AA8((S_002F94F8_8AA8 *)obj);
    settings = &D_L01_002BE708[kind];
    func_0038CE20((f32 *)(obj + 0x10), (f32 *)&direction, *(f32 *)((u8 *)settings + 4));
    func_0038CE20((f32 *)&offset, (f32 *)(obj + 0xC0), *(f32 *)((u8 *)settings + 8));
    vec_add_ba(obj + 0x10, obj + 0x10, &offset);
    vec_add_ab(obj + 0x10, obj + 0x10, &position);
    if (out_pos) *out_pos = *(vu0_q *)&position;
    if (out_rot) *out_rot = *(vu0_q *)&rotation;
}
/* localdecomp:end func_L01_002F8AA8 */

/* localdecomp:start func_L01_002F8D40 */
#include "vu0.h"
s32 func_L01_002F8D40(u8 *m, u8 *target, s32 directed, f32 angle, f32 speed) {
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003C4840(void *, void *, f32);
    extern void func_L01_004450F0(void *, s32, s32);
    vu0_v4 delta, toward;
    u8 *data = *(u8 **)(m + 0x68);
    if (m[0x20] == 4) return 0;
    if (angle == 0.0f) angle = func_003824E0(-0.5235987901687622f, 0.5235987901687622f);
    if (speed == 0.0f) speed = func_003824E0(0.0f, 0.5235987901687622f);
    if (directed) data[0x6D] |= 8;
    if ((u32)(m[0x20] - 2) < 2) {
        if (directed) {
            vec_sub_ab(&delta, target + 0x10, m + 0x10);
            func_0038CF68(data + 0x30, &delta, 0.40000003576278687f);
        } else {
            func_0038CF68(data + 0x30, data + 0x40, 0.1600000113248825f);
        }
    }
    *(f32 *)(data + 0x74) = angle;
    *(f32 *)(data + 0x70) = speed;
    *(s32 *)(data + 0x60) = 0;
    *(u8 **)(data + 0x68) = target;
    vec_sub_ba(&toward, target + 0x10, m + 0x10);
    func_0038CE90(&delta, data + 0x30, &toward);
    func_0038CF68(data + 0x20, &delta, 1.0f);
    func_003C4840(data + 0x20, data + 0x20, 0.25132742524147034f);
    func_L01_004450F0(m, 4, -1);
    return 1;
}
/* localdecomp:end func_L01_002F8D40 */

/* localdecomp:start func_L01_002F8F10 */
void func_L01_002F8F10(void) {

}
/* localdecomp:end func_L01_002F8F10 */

LINKER_REMNANT("asm/levels", func_L01_002F8F18);

/* localdecomp:start func_L01_002F8F20 */
#include "vu0.h"
typedef struct {
    u8 pad[0x3C];
    s32 bolts;              /* 0x3C: the bolt count */
} Stats_002F8F20;
extern vu0_v4 D_L01_001E29C0;   /* the camera position */
extern Stats_002F8F20 D_00142660_002F8F20;
extern u8 *D_001A71A0[];
/* the moby at the root of a chain of parents (0xB8) */
static __inline__ u8 *root_002F8F20(u8 *moby) {
    while (*(u8 **)(moby + 0xB8)) moby = *(u8 **)(moby + 0xB8);
    return moby;
}
/* bolt_coin_spawn: spawns a coin moby worth value bolts (its class by value) at position, moving
   with velocity, spun toward its parent; 64 u or more from the camera it banks the bolts instead */
u8 *func_L01_002F8F20(u8 *parent, vu0_q *position, vu0_q *velocity, s32 flags, s32 value, s32 counts) {
    extern f32 func_L01_0040E548(void *, void *);
    extern u8 *func_003C24B0_002F8F20(s32, s32);
    extern void func_L01_002F7808(void);
    extern void func_L01_004450F0(void *, s32, s32);
    extern s32 func_L01_002F94F8();
    extern void func_0038D308(void *, void *);
    extern void func_L01_0044E820(u8 *, u32);
    extern void func_003C6FB0(u8 *, s32 *, s32 *, s32 *);
    extern void func_003C6F90(u8 *, s32, s32, s32, s32);
    extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003C4840(void *, void *, f32);
    extern s32 func_L01_002F8D40(u8 *, u8 *, s32, f32, f32);
    extern void func_003C7C38(u8 *);
    vu0_v4 axis, toward;
    s32 r, g, b;
    s32 type;
    u8 *coin, *vars, *root;
    f32 spin, angle;
    if (func_L01_0040E548(position, &D_L01_001E29C0) >= 4096.0f) {
        D_00142660_002F8F20.bolts += value;
        return 0;
    }
    if (value >= 30000) type = 0x1BA5;
    else if (value >= 10000) type = 0x1D5D;
    else if (value >= 3000) type = 0x1D5C;
    else if (value >= 1000) type = 0x13;
    else if (value >= 500) type = 0x12;
    else if (value >= 100) type = 0x11;
    else if (value >= 50) type = 0x10;
    else if (value >= 20) type = 0xF;
    else if (value >= 50) type = 0xE; /* never true: retail tests 50 again here (slti 0x32; movz) */
    else type = 0xD;
    coin = func_003C24B0_002F8F20(type, 0x80);
    if (coin == 0) return 0;
    func_L01_002F7808();
    vars = *(u8 **)(coin + 0x68);
    vars[0x6D] = 0;
    if (counts) vars[0x6D] = 2;
    if (!parent) root = 0;
    else root = root_002F8F20(parent);
    *(u8 **)(coin + 0xB8) = root;
    coin[0x63] = 10;
    coin[0x30] = 64;
    *(s16 *)(coin + 0x32) = 64;
    coin[0x31] = 1;
    func_L01_004450F0(coin, 1, -1);
    *(u16 *)(coin + 0x34) |= 0x100;
    *(f32 *)(coin + 0x2C) = *(f32 *)(*(u8 **)(coin + 0x24) + 0x24) *
        *(f32 *)&D_L01_002BE708[func_L01_002F94F8(coin)];
    func_0038D308(coin + 0xC0, coin + 0xF0);
    func_L01_0044E820(coin, 0x80181010);
    func_003C6FB0(coin, &r, &g, &b);
    func_003C6F90(coin, 0, 13, 0, 0);
    func_L01_0043B9E8(coin, r, g, b);
    *(vu0_q *)(coin + 0x10) = *position;
    *(vu0_q *)(vars + 0x30) = *velocity;
    if (func_00382468(2)) vars[0x6D] |= 1;
    *(f32 *)(vars + 0x78) = *(f32 *)(coin + 0x18);
    spin = func_003824E0(0.0f, 0.25132742524147034f);
    vec_sub_ba(&toward, parent + 0x10, coin + 0x10);
    func_0038CE90(&axis, vars + 0x30, &toward);
    func_0038CF68(vars + 0x20, &axis, 1.0f);
    func_003C4840(vars + 0x20, vars + 0x20, spin);
    if (flags & 2) {
        angle = 0.0f;
        if (flags & 0x10) angle = func_003824E0(-0.5235987901687622f, 0.5235987901687622f);
        func_L01_002F8D40(coin, D_001A71A0[0], 0, angle, 0.0f);
    }
    func_003C7C38(coin);
    return coin;
}
/* localdecomp:end func_L01_002F8F20 */

INCLUDE_ASM("asm/levels", func_L01_002F9310);

/* localdecomp:start func_L01_002F94F8 */
s32 func_L01_002F94F8(S_002F94F8 *p) {
    u16 v = p->f_AA;
    if ((u32)(v - 13) < 7) {
        return (s16)v - 13;
    }
    switch ((s16)v) {
    case 7516:
        return 7;
    case 7517:
        return 8;
    case 7077:
        return 9;
    default:
        return 0;
    }
}
/* localdecomp:end func_L01_002F94F8 */

/* localdecomp:start func_L01_002F9578 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_2F9578;

typedef struct {
    Vec_2F9578 origin; /* 0x00: the spawner's second point (explosion_spawn: the blast raised) */
    void *owner;       /* 0x10: the moby it is for, or 0 */
    s32 life;          /* 0x14: ticks it lives */
    f32 scale;         /* 0x18: its full scale */
    s16 timer;         /* 0x1C: ticks left */
    s16 opacity;       /* 0x1E: its opacity while it holds */
} DomeVars_2F9578;

typedef struct {
    u8 pad_0[0x10];
    Vec_2F9578 position; /* 0x10 */
    u8 state;            /* 0x20 */
    u8 pad_21[0x23 - 0x21];
    u8 opacity;          /* 0x23 */
    u8 pad_24[0x2C - 0x24];
    f32 scale;           /* 0x2C */
    u8 update_dist;      /* 0x30: names for 0x30-0x32 from Horizon Private Server's libuya */
    u8 drawn;            /* 0x31 */
    s16 draw_dist;       /* 0x32 */
    u8 pad_34[0x68 - 0x34];
    DomeVars_2F9578 *vars; /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    Vec_2F9578 rotation; /* 0xF0: angles x, y, z */
} DomeMoby_2F9578;

extern DomeMoby_2F9578 *func_003C24B0_002F9578(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_003C7C38(u8 *);

/* explosion_dome_spawn: spawns the explosions' dome (class 0x70) at place, at its class's scale
 * times factor, turned at random on all three axes, tinted (r, g, b), for life ticks. */
DomeMoby_2F9578 *func_L01_002F9578(f32 factor, void *owner, Vec_2F9578 *place, Vec_2F9578 *origin,
                                   s32 life, u8 r, u8 g, u8 b, u8 opacity)
{
    DomeMoby_2F9578 *moby;
    DomeVars_2F9578 *vars;
    Vec_2F9578 rotation;

    moby = func_003C24B0_002F9578(0x70, 0x80);
    if (moby != 0) {
        vars = moby->vars;
        {
            Vec_2F9578 turn = { 0 }; /* -pi to pi on each axis */
            turn.x = func_003824E0(-3.1415927f, 3.1415927f);
            turn.y = func_003824E0(-3.1415927f, 3.1415927f);
            turn.z = func_003824E0(-3.1415927f, 3.1415927f);
            rotation = turn;
        }
        moby->state = 0;
        moby->opacity = opacity;
        moby->update_dist = 0xFF;
        moby->draw_dist = 0x1FF;
        moby->drawn = 1;
        func_L01_0043B9E8((u8 *)moby, r, g, b);
        vars->scale = moby->scale * factor;
        moby->scale = 0.0f;
        vars->owner = owner;
        moby->position = *place;
        vars->origin = *origin;
        moby->rotation = rotation;
        vars->life = life;
        vars->timer = vars->life - 3; /* it starts with 3 ticks gone */
        moby->scale = (f32)(life - vars->timer) * vars->scale / (f32)life;
        vars->opacity = opacity;
        func_003C7C38((u8 *)moby);
    }
    return moby;
}
/* localdecomp:end func_L01_002F9578 */

/* localdecomp:start func_L01_002F9738 */
typedef struct {
    u8 pad_0[0x14];
    s32 life;    /* 0x14: ticks it lives */
    f32 scale;   /* 0x18: its full scale */
    s16 timer;   /* 0x1C: ticks left */
    s16 opacity; /* 0x1E: its opacity while it holds */
} DomeVars_2F9738;

typedef struct {
    u8 pad_0[0x23];
    u8 opacity;  /* 0x23 */
    u8 pad_24[0x2C - 0x24];
    f32 scale;   /* 0x2C */
    u8 pad_30[0x68 - 0x30];
    DomeVars_2F9738 *vars; /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    f32 rotation[3]; /* 0xF0: angles x, y, z */
} DomeMoby_2F9738;

extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CB00(void *p);
extern void func_003C2880(void *);

/* explosion_dome_update: the explosions' dome (class 0x70) grows to its scale over its life,
 * turns on all three axes and fades over the last half of its life. */
void func_L01_002F9738(DomeMoby_2F9738 *moby)
{
    DomeVars_2F9738 *vars = moby->vars;
    f32 turn = 0.06283186f; /* 2 pi / 100 rad (3.6 degrees) a frame: NTSC-U turns 3 degrees at 60 Hz */
    s32 half;

    moby->scale = (f32)(vars->life - vars->timer) * vars->scale / (f32)vars->life;
    moby->rotation[0] = func_0038DAB8(moby->rotation[0], turn);
    moby->rotation[1] = func_0038DAB8(moby->rotation[1], turn);
    moby->rotation[2] = func_0038DAB8(moby->rotation[2], turn);
    if (func_0038CB00(&vars->timer)) {
        func_003C2880(moby);
        return;
    }
    half = vars->life / 2;
    if (vars->timer < half) {
        moby->opacity = vars->timer * vars->opacity / half;
    }
}
/* localdecomp:end func_L01_002F9738 */

/* localdecomp:start func_L01_002F9830 */
void func_L01_002F9830(u8 *moby) {
    extern void func_L01_002F9F20(u8 *);
    extern void func_L01_002F9B08(u8 *);
    extern void func_L01_002F9A18(u8 *);
    extern void func_L01_004CAB30(u8 *, u8 *);
    extern void func_L01_004CAC40(u8 *, u8 *);
    extern void func_L01_002FB208(u8 *);
    extern f32 func_0038DAB8(f32, f32);
    u8 *vars = *(u8 **)(moby + 0x68);
    switch (moby[0x20]) {
    case 0:
        if (*(s32 *)(vars + 0x14)) func_L01_002F9F20(moby);
        else func_L01_002F9B08(moby);
        *(f32 *)(moby + 0xF0) = func_0038DAB8(*(f32 *)(moby + 0xF0), 0.041887905448675156f);
        *(f32 *)(moby + 0xF4) = func_0038DAB8(*(f32 *)(moby + 0xF4), 0.15707963705062866f);
        func_L01_002F9A18(moby);
        break;
    case 1:
        func_L01_004CAB30(moby + 0x10, moby + 0x10);
        func_L01_004CAC40(vars, vars);
        func_L01_002FB208(moby);
        break;
    }
}
/* localdecomp:end func_L01_002F9830 */

/* localdecomp:start func_L01_002F98F8 */
typedef int Q_002F98F8 __attribute__((mode(TI)));
u8 *func_L01_002F98F8(Q_002F98F8 *position, Q_002F98F8 *origin) {
    extern s32 func_L01_004C85C8(u8 *, s32, f32, f32, f32);
    u8 *moby = (u8 *)func_003C24B0(0x79, 0x80);
    u8 *vars;
    if (moby) {
        moby[0x30] = 0xFF;
        *(s16 *)(moby + 0x32) = 0x1FF;
        moby[0x31] = 1;
        moby[0x20] = 0;
        vars = *(u8 **)(moby + 0x68);
        *(Q_002F98F8 *)(moby + 0x10) = *position;
        *(Q_002F98F8 *)vars = *origin;
        *(s32 *)(vars + 0x14) = 0;
        *(s32 *)(vars + 0x10) = 25;
        *(s32 *)(vars + 0x18) = 250;
        *(f32 *)(moby + 0xF0) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(moby + 0xF4) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(moby + 0xF8) = func_003824E0(-3.1415927f, 3.1415927f);
        *(s32 *)(moby + 0xFC) = 0;
        func_003C7C38(moby);
        *(s32 *)(vars + 0x1C) = func_L01_004C85C8(moby, 0, 1.0f, 1.0f, 1.0f);
    }
    return moby;
}
/* localdecomp:end func_L01_002F98F8 */

/* localdecomp:start func_L01_002F9A18 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Color_002F9A18;
void func_L01_002F9A18(u8 *moby) {
    extern s32 func_0038CAD0(s32 *);
    Color_002F9A18 color = {0};
    u8 *vars = *(u8 **)(moby + 0x68);
    f32 t;
    s32 r, g, b;
    color.z = color.y = color.x = 128.0f;
    color.w = 255.0f;
    func_0038CAD0((s32 *)(vars + 0x10));
    t = (f32)*(s32 *)(vars + 0x10) / 25.0f;
    b = (s32)((color.z - 64.0f) * t + 64.0f);
    g = (s32)((color.y - 64.0f) * t + 64.0f);
    r = (s32)((color.x - 255.0f) * t + 255.0f);
    *(u32 *)(moby + 0x78) = (b << 16) | 0xFF000000 | (g << 8) | r;
}
/* localdecomp:end func_L01_002F9A18 */

/* localdecomp:start func_L01_002F9B08 */
#include "vu0.h"
typedef struct { vu0_v4 vector; u8 *object; u32 flags; u8 mode,active; u16 oclass; f32 scale; s32 enabled; } Packet_002F9B08;
typedef struct { u8 pad[0x18]; u8 *object; s32 count; vu0_v4 position; u8 pad30[0x10]; vu0_v4 normal; } Hit_002F9B08;
extern s32 D_L01_001E1090;
__asm__(".extern D_L01_001E1090, 4");
extern s32 D_L01_001E1098;
extern f32 D_L01_001EAA28[];
extern u8 D_L01_001EAA00[];
extern u8 *D_001A71A0[];
extern s32 D_L01_001D9E60;
void func_L01_002F9B08(u8 *m) {
    extern void func_L01_004C8688(s32,void *,s32);
    extern void func_L01_004CAB30(void *,void *);
    extern void func_L01_004CAC40(void *,void *);
    extern void func_L01_004C7D40(void *,void *,f32);
    extern void func_L01_002FB2F0(u8 *);
    extern void func_0038CFB8(void *,void *,f32);
    extern s32 func_003D3CB0(void *,void *,s32,void *,void *);
    extern s32 func_003D5630(void);
    extern void func_L01_004C67A0(s32,s32,s32,f32,f32,f32,f32);
    extern u8 *func_L01_003016B0(void *,s32,f32,f32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32,s32);
    extern s32 func_00382468(s32);
    extern void func_L01_00468A68(void *,void *,s32,s32);
    extern void func_L01_0040E790(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_004C8668(s32);
    extern void func_L01_002FA1F8(u8 *,void *,void *);
    vu0_v4 old,shock,normal;
    Packet_002F9B08 packet;
    vu0_v4 position,velocity;
    u8 *d=*(u8 **)(m+0x68);
    *(vu0_q *)&shock=0;
    *(vu0_q *)&normal=0;
    shock.z=0.04000000283122063f;
    *(vu0_q *)&old=*(vu0_q *)(m+0x10);
    normal.z=1.0f;
    vec_add_ba(m+0x10,d,m+0x10);
    func_L01_004C8688(*(s32 *)(d+0x1C),d,0);
    func_L01_004CAB30(m+0x10,m+0x10);
    func_L01_004CAC40(d,d);
    func_L01_004C7D40(m+0x10,d,0.004399999976158142f);
    func_L01_002FB2F0(m);
    packet.object=m;
    packet.flags=0x1030000;
    if (*(s32 *)(d+0x18)<242) packet.flags=0x1030001;
    packet.scale=1.0f;
    packet.enabled=1;
    *(vu0_q *)&packet.vector=*(vu0_q *)d;
    func_0038CFB8(&packet.vector,&packet.vector,1.0f);
    packet.vector.z=1.0f;
    packet.vector.w=5627.9248046875f;
    packet.mode=2;
    packet.oclass=*(u16 *)(m+0xAA);
    packet.active=1;
    if (func_003D3CB0(&old,m+0x10,0x10,m,&packet)) {
        if (func_003D5630()==0 && *(f32 *)(d+8)<0.0f) {
            u8 *r;
            s32 i;
            func_L01_004C67A0(D_L01_001E1090,D_L01_001E1098,1,*(f32 *)(m+0x10),*(f32 *)(m+0x14),0.5f,-0.35f);
            qzero(d);
            *(s32 *)(d+0x14)=1;
            *(f32 *)(d+8)=-0.030000001192092896f;
            position.x=*(f32 *)(m+0x10);
            position.y=*(f32 *)(m+0x14);
            position.z=D_L01_001EAA28[0];
            r=func_L01_003016B0(&position,3,2.0f,1.025f);
            if (r) r[0x23]=0x70;
            { vu0_v4 *pv=&velocity;
            i=15;
            do {
                f32 angle=func_00382538();
                f32 speed=func_003824E0(0.0f,0.06000000238418579f);
                s32 life;
                velocity.x=func_0038D098(angle)*speed;
                velocity.y=func_0038D0B0(angle)*speed;
                velocity.z=func_003824E0(0.06000000238418579f,0.1300000101327896f);
                life=func_00382498(90,120);
                func_L01_00468A68(&position,pv,func_00382468(2),life);
            } while (--i>=0);
            }
        } else {
            if (((Hit_002F9B08 *)D_L01_001EAA00)->object) {
                if (((Hit_002F9B08 *)D_L01_001EAA00)->object==D_001A71A0[0] || *(s16 *)(((Hit_002F9B08 *)D_L01_001EAA00)->object+0xAA)==0xC0) {
                    if (*(s32 *)(d+0x18)>=242) goto done;
                }
                if (*(u8 **)(((Hit_002F9B08 *)D_L01_001EAA00)->object+0x64)==(u8 *)D_L01_001D9E60 && *(s16 *)(((Hit_002F9B08 *)D_L01_001EAA00)->object+0xAA)!=0x336) goto done;
                m[0xBC]=1;
                *(vu0_q *)(m+0x10)=*(vu0_q *)&((Hit_002F9B08 *)D_L01_001EAA00)->position;
                func_L01_0040E790(&shock,d,&((Hit_002F9B08 *)D_L01_001EAA00)->normal);
                func_0038CF68(&shock,&shock,0.04000000283122063f);
                func_0038CF68(&normal,&((Hit_002F9B08 *)D_L01_001EAA00)->normal,1.0f);
            } else if (((Hit_002F9B08 *)D_L01_001EAA00)->count>0) {
                m[0xBC]=1;
                *(vu0_q *)(m+0x10)=*(vu0_q *)&((Hit_002F9B08 *)D_L01_001EAA00)->position;
                func_L01_0040E790(&shock,d,&((Hit_002F9B08 *)D_L01_001EAA00)->normal);
                func_0038CF68(&shock,&shock,0.04000000283122063f);
                func_0038CF68(&normal,&((Hit_002F9B08 *)D_L01_001EAA00)->normal,1.0f);
            }
        }
    } else if (func_0038CAD0((s32 *)(d+0x18))) {
        m[0xBC]=1;
        vec_add_ab(&shock,&shock,d);
    }
done:
    if (m[0xBC]) {
        func_L01_004C8668(*(s32 *)(d+0x1C));
        func_L01_002FA1F8(m,&shock,&normal);
    }
}
/* localdecomp:end func_L01_002F9B08 */

/* localdecomp:start func_L01_002F9F20 */
#include "vu0.h"
typedef struct {
    vu0_v4 vector;
    u8 *owner;
    u32 flags;
    u8 type, enabled;
    u16 kind;
    f32 scale;
    s32 active;
} Hit_002F9F20;
typedef struct {
    u8 pad[0x18];
    u8 *object;
    s32 count;
    vu0_v4 position;
    u8 pad30[0x10];
    vu0_v4 normal;
} Collision_002F9F20;
extern u8 D_L01_001EAA00[];
extern u8 *D_001A71A0[];
extern s32 D_L01_001D9E60;
void func_L01_002F9F20(u8 *obj) {
    extern void func_003C5180(void *,void *,s32);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern void func_L01_002FB5A8(u8 *);
    extern void func_0038CFB8(void *,void *,f32);
    extern s32 func_003D3CB0(void *,void *,s32,void *,void *);
    extern void func_L01_0040E790(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_004C8668(s32);
    extern void func_L01_002FA1F8(u8 *,void *,void *);
    extern void func_L01_002FAAA0(u8 *,void *,void *);
    vu0_v4 reflected = {0,0,0,0};
    vu0_v4 normal = {0,0,0,0};
    vu0_v4 previous;
    vu0_v4 ground;
    Hit_002F9F20 hit;
    u8 *vars = *(u8 **)(obj+0x68);
    previous=*(vu0_v4 *)(obj+0x10);
    reflected.z=0.04000000283122063f;
    normal.z=1.0f;
    vec_add_ab(obj+0x10,obj+0x10,vars);
    func_003C5180(obj+0x10,&ground,0);
    func_0038CE20((f32 *)&ground,(f32 *)&ground,0.0004400000034365803f);
    func_L01_002FB5A8(obj);
    hit.owner=obj;
    hit.flags=0x1030000;
    if (*(s32 *)(vars+0x18)<242) hit.flags=0x1030001;
    hit.scale=1;
    hit.active=1;
    hit.vector=*(vu0_v4 *)vars;
    func_0038CFB8(&hit.vector,&hit.vector,1.0f);
    hit.type=2;
    hit.vector.w=5627.9248046875f;
    hit.kind=*(u16 *)(obj+0xAA);
    hit.vector.z=1;
    hit.enabled=1;
    (*(s32 *)(vars+0x14))++;
    if (func_003D3CB0(&previous,obj+0x10,16,obj,&hit)) {
        if(((Collision_002F9F20 *)D_L01_001EAA00)->object) {
            if ((((Collision_002F9F20 *)D_L01_001EAA00)->object==D_001A71A0[0] || *(s16 *)(((Collision_002F9F20 *)D_L01_001EAA00)->object+0xAA)==0xC0) && *(s32 *)(vars+0x18)>=242) goto done;
            if (*(s32 *)(((Collision_002F9F20 *)D_L01_001EAA00)->object+0x64)==D_L01_001D9E60 && *(s16 *)(((Collision_002F9F20 *)D_L01_001EAA00)->object+0xAA)!=0x336) goto done;
            obj[0xBC]=1;
            *(vu0_v4 *)(obj+0x10)=((Collision_002F9F20 *)D_L01_001EAA00)->position;
            func_L01_0040E790(&reflected,vars,&((Collision_002F9F20 *)D_L01_001EAA00)->normal);
            func_0038CF68(&reflected,&reflected,0.04000000283122063f);
            func_0038CF68(&normal,&((Collision_002F9F20 *)D_L01_001EAA00)->normal,1.0f);
        } else if (((Collision_002F9F20 *)D_L01_001EAA00)->count>0) {
            obj[0xBC]=1;
            *(vu0_v4 *)(obj+0x10)=((Collision_002F9F20 *)D_L01_001EAA00)->position;
            func_L01_0040E790(&reflected,vars,&((Collision_002F9F20 *)D_L01_001EAA00)->normal);
            func_0038CF68(&reflected,&reflected,0.04000000283122063f);
            func_0038CF68(&normal,&((Collision_002F9F20 *)D_L01_001EAA00)->normal,1.0f);
        }
    } else if(func_0038CAD0((s32 *)(vars+0x18))) {
        obj[0xBC]=1;
        vec_add_ab(&reflected,&reflected,vars);
    }
done:
    if (obj[0xBC]) {
        func_L01_004C8668(*(s32 *)(vars+0x1C));
        if (*(s32 *)(vars+0x14)<17) func_L01_002FA1F8(obj,&reflected,&normal);
        else func_L01_002FAAA0(obj,&reflected,&normal);
    }
}
/* localdecomp:end func_L01_002F9F20 */

INCLUDE_ASM("asm/levels", func_L01_002FA1F8);

INCLUDE_ASM("asm/levels", func_L01_002FAAA0);

/* localdecomp:start func_L01_002FB208 */
typedef int Q_002FB208 __attribute__((mode(TI)));
extern u8 D_L01_001EEA80[];
void func_L01_002FB208(u8 *moby) {
    extern f32 func_003C4088(f32, f32, f32);
    extern s32 func_003D4D00(u8 *, s32, u8 *, s32, f32);
    extern void func_L01_00447718(u8 *, Q_002FB208 *, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    Q_002FB208 position;
    s32 hit;
    f32 radius;
    *(u16 *)(moby + 0x34) |= 0x41;
    radius = func_003C4088(0.5f, 5.5f, (f32)moby[0xBC] / 12.0f);
    hit = func_003D4D00(moby + 0x10, 16, moby, 0, radius);
    position = *(Q_002FB208 *)(moby + 0x10);
    func_L01_00447718(moby, &position, D_L01_001EEA80, hit, 0, 0x01030001, 2, 1, 1.0f, 1.0f, 1.0f, -1);
    if (++moby[0xBC] > 12) func_003C2880(moby);
}
/* localdecomp:end func_L01_002FB208 */

/* localdecomp:start func_L01_002FB2F0 */
extern s32 D_L01_001DFB40;
void func_L01_002FB2F0(u8 *moby) {
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_L01_00443B88(f32 *, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_003C5278(u8 *, f32 *, f32 *, f32);
    extern void func_L01_00463378(u8 *, f32 *, f32 *, u32, u32, s32, s32, s32, s32);
    f32 velocity[4] __attribute__((aligned(16)));
    f32 sphere[4] __attribute__((aligned(16)));
    f32 jitter[4] __attribute__((aligned(16)));
    f32 *vars = *(f32 **)(moby + 0x68);
    s32 i;
    u32 start, end;
    s32 a, b, c;
    if ((D_L01_001DFB40 & 7) != 0) return;
    {
    f32 *jitter_p = jitter;
    f32 *velocity_p = velocity;
    f32 *sphere_p = sphere;
    for (i = 0; i >= 0; i--) {
        func_0038CE20(velocity, vars, 0.5f);
        func_L01_00443B88(jitter_p, 0.0f, 0.020000001f);
        vec_add_ab(velocity, jitter, velocity);
        qzero(sphere);
        velocity[3] = func_003824E0(0.25f, 0.15f);
        sphere[3] = func_003824E0(0.15f, 0.05f);
        start = func_0038DBD8(0x804080FF, 0x8040FFFF, func_003824E0(0.0f, 1.0f));
        end = func_0038DBD8(0x80104040, 0x80002080, func_003824E0(0.0f, 1.0f));
        a = (s32)(((func_003824E0(0.0f, 1.0f) + 1.0f) * 5.0f + 2.0f) / 6.0f);
        b = (s32)(((func_003824E0(-0.5f, 0.5f) + 1.0f) * 30.0f * 5.0f + 2.0f) / 6.0f);
        c = (s32)(((func_003824E0(-0.5f, 0.5f) + 1.0f) * 10.0f * 5.0f + 2.0f) / 6.0f);
        func_003C5278(moby + 0x10, sphere_p, sphere_p, (f32)b * 0.0016000001f);
        func_L01_00463378(moby + 0x10, velocity_p, sphere_p, start, end, a, b, c, 0x10019);
    }
    }
}
/* localdecomp:end func_L01_002FB2F0 */

/* localdecomp:start func_L01_002FB5A8 */
extern s32 func_00382468(s32);
extern f32 func_003C3EC8(u8 *position, f32 *out);
extern void func_0038CE20(f32 *, f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00468678(u8 *position, f32 *velocity, s32 colour, f32 size, f32 f13);

/* One frame in four on average, a bubble (particle_spawn_bubble, type 0x22) at the moby, moving
 * at a quarter of the vector its vars start with; func_003C3EC8's result (it also writes the
 * buffer, which the scale then overwrites) goes to the bubble as its f13. */
void func_L01_002FB5A8(u8 *moby)
{
    f32 velocity[4];
    f32 got;
    u8 *vars = *(u8 **)(moby + 0x68);

    if (func_00382468(4) != 0) {
        return;
    }
    got = func_003C3EC8(moby + 0x10, velocity);
    func_0038CE20(velocity, (f32 *)vars, 0.25f);
    func_L01_00468678(moby + 0x10, velocity, 0x88A0A0A0, func_003824E0(0.05f, 0.1f) * 210000.0f, got);
}
/* localdecomp:end func_L01_002FB5A8 */

/* localdecomp:start func_L01_002FB660 */
typedef int Q_002FB660 __attribute__((mode(TI)));
u8 *func_L01_002FB660(Q_002FB660 *position, Q_002FB660 *origin, s32 life, s32 mode, s32 flag, s32 value) {
    u8 *moby = (u8 *)func_003C24B0_002F9578(0x7A, 0x80);
    u8 *vars;
    if (moby) {
        vars = *(u8 **)(moby + 0x68);
        moby[0x30] = 0xFF;
        *(s16 *)(moby + 0x32) = 0xFF;
        moby[0x31] = 1;
        moby[0x23] = 0x80;
        *(s32 *)(vars + 0x24) = value;
        func_L01_0043B9E8(moby, 0x7F, 0x7F, 0x7F);
        *(Q_002FB660 *)(moby + 0x10) = *position;
        *(Q_002FB660 *)vars = *origin;
        *(f32 *)(vars + 0x10) = func_003824E0(0.12566371262073517f, 0.25132742524147034f);
        *(f32 *)(vars + 0x14) = func_003824E0(0.12566371262073517f, 0.25132742524147034f);
        *(s16 *)(vars + 0x18) = life;
        *(s16 *)(vars + 0x1A) = life;
        if (mode == 2) {
            mode = 1;
            *(s32 *)(vars + 0x20) = mode;
        }
        if (mode == 0) *(f32 *)(moby + 0x2C) *= func_003824E0(0.5f, 0.75f);
        *(f32 *)(vars + 0x1C) = *(f32 *)(moby + 0x2C);
        moby[0xBC] = mode | (flag << 1);
        func_003C7C38(moby);
    }
    return moby;
}
/* localdecomp:end func_L01_002FB660 */

/* localdecomp:start func_L01_002FB7D8 */
#include "vu0.h"
typedef struct { s32 a[4]; } Colors_002FB7D8;
extern Colors_002FB7D8 D_L01_001DC348;
extern vu0_v4 D_L01_001EAA40;
void func_L01_002FB7D8(u8 *self)
{
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L01_00448D88(s32,s32);
    extern void func_L01_004637C8(void *,void *,s32,s32,s32,s32,s32,s32);
    extern f32 func_0038DAB8(f32,f32);
    extern s32 func_003D3CB0(void *,void *,s32,void *,s32);
    extern void func_L01_0040E790(void *,void *,void *);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_00451388_002FB7D8(void *,void *,void *,f32);
    extern void func_003C2880(void *);
    extern s32 func_0038CB00(void *);
    u8 *vars=*(u8 **)(self+0x68);
    s32 spawn=1;
    s32 quarter;
    union { Colors_002FB7D8 colors; vu0_v4 old; } temporary;
    if(*(s32 *)(vars+0x20)!=0) {
        if(func_00382468(2)) spawn=0;
    }
    if((self[0xbc]&1) && spawn) {
        vu0_v4 direction;
        temporary.colors=D_L01_001DC348;
        {
            vu0_v4 random={0};
            random.x=func_003824E0(-1.0f,1.0f);
            random.y=func_003824E0(-1.0f,1.0f);
            random.z=func_003824E0(-1.0f,1.0f);
            direction=random;
        }
        func_0038CF68(&direction,&direction,0.020000001f);
        if(self[0xbc]&0xfe) {
            s32 color=func_L01_00448D88(temporary.colors.a[func_00382468(4)],self[0xbc]>>1);
            s32 other=func_L01_00448D88(0x4fff,self[0xbc]>>1);
            func_L01_004637C8(self+0x10,&direction,color,other,37,50,120,1);
        } else {
            func_L01_004637C8(self+0x10,&direction,temporary.colors.a[func_00382468(4)],0x4fff,37,50,120,1);
        }
    }
    *(f32 *)(self+0xf0)=func_0038DAB8(*(f32 *)(self+0xf0),*(f32 *)(vars+0x10));
    *(f32 *)(self+0xf4)=func_0038DAB8(*(f32 *)(self+0xf4),*(f32 *)(vars+0x14));
    if(*(s32 *)(vars+0x24)) {
        temporary.old=*(vu0_v4 *)(self+0x10);
        vec_add_ab(self+0x10,self+0x10,vars);
        if(func_003D3CB0(&temporary.old,self+0x10,16,self,0)) {
            func_L01_0040E790(vars,vars,&D_L01_001EAA40);
            func_0038CF68(vars,vars,func_0038CEA8(vars)*0.76f);
        }
    } else {
        vec_add_ab(self+0x10,self+0x10,vars);
    }
    func_L01_00451388_002FB7D8(self,vars,vars,0.0058400002f);
    if(*(f32 *)(self+0x10)<0.0f || *(f32 *)(self+0x14)<0.0f || *(f32 *)(self+0x18)<0.0f) {
        func_003C2880(self);
        return;
    }
    quarter=*(s16 *)(vars+0x1a)/4;
    if(*(s16 *)(vars+0x18)<quarter) {
        *(f32 *)(self+0x2c)=*(f32 *)(vars+0x1c)*(f32)*(s16 *)(vars+0x18)/(f32)quarter;
    }
    if(func_0038CB00(vars+0x18)) func_003C2880(self);
}
/* localdecomp:end func_L01_002FB7D8 */

/* localdecomp:start func_L01_002FBB10 */
typedef struct Obj_002FBB10 Obj_002FBB10;
typedef struct {
    s32 unused;
    s32 timer;
    s32 remaining;
    s32 cooldown;
    s32 indices[4];
    Obj_002FBB10 *objects[4];
} Vars_002FBB10;
struct Obj_002FBB10 {
    u8 pad[0x10];
    vu0_q position;
    u8 state;
    u8 pad21[0x68 - 0x21];
    Vars_002FBB10 *vars;
    u8 pad6C[0xA8 - 0x6C];
    u8 active;
};
extern u8 *D_L01_001E001C;
__asm__(".extern D_L01_001DC358, 4");
__asm__(".extern D_L01_001DC35C, 4");
extern s32 D_L01_001DC358;
extern s32 D_L01_001DC35C;
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_0038CAD0(s32 *);
extern void func_003C2880(void *);
void func_L01_002FBB10(Obj_002FBB10 *obj) {
    Vars_002FBB10 *vars = obj->vars;
    s32 hit;
    s32 i;
    switch (obj->state) {
    case 0:
        obj->state = 1;
        vars->timer = D_L01_001DC358;
        vars->remaining = 3;
        vars->objects[0] = (Obj_002FBB10 *)(D_L01_001E001C + (vars->indices[0] << 8));
        vars->objects[1] = (Obj_002FBB10 *)(D_L01_001E001C + (vars->indices[1] << 8));
        vars->objects[2] = (Obj_002FBB10 *)(D_L01_001E001C + (vars->indices[2] << 8));
        vars->objects[3] = (Obj_002FBB10 *)(D_L01_001E001C + (vars->indices[3] << 8));
        break;
    case 1:
        hit = func_L01_00447490(obj, 0x10000, 0);
        func_0038CAD0(&vars->cooldown);
        if (hit && vars->cooldown == 0) {
            obj->active = 255;
            vars->cooldown = D_L01_001DC35C;
            if (--vars->remaining <= 0) {
                func_003C2880(obj);
                return;
            }
        }
        if (vars->objects[0]->state == 80 || vars->objects[1]->state == 80 || vars->objects[2]->state == 80 || vars->objects[3]->state == 80) {
            if (func_0038CAD0(&vars->timer)) {
                vars->timer = D_L01_001DC358;
                for (i = 0; i < 4; i++) {
                    if (vars->objects[i]->state == 80) {
                        vars->objects[i]->state = 81;
                        vars->objects[i]->position = obj->position;
                        vars->objects[i]->active = 255;
                        break;
                    }
                }
            }
        }
        break;
    }
}
/* localdecomp:end func_L01_002FBB10 */

/* localdecomp:start func_L01_002FBCD0 */
typedef struct {
    vu0_v4 vertices[4];
    u32 colors[4];
    f32 uv[4][2];
    unsigned long tag[4];
} Quad_002FBCD0;
typedef struct { s32 a, b; } Pair_002FBCD0;
typedef struct { f32 x, y, z; } Pos_002FBCD0;
extern u8 D_001A4BE0[];
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_L01_001DC360[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001DC3A0[] __attribute__((section(".sdata")));
extern f32 D_L01_001DC3E0[][2] __attribute__((section(".sdata")));
extern f32 D_L01_001DC400;
extern f32 D_L01_001DC404;
extern f32 D_L01_001DC408;
extern f32 D_L01_001DC40C;
__asm__(".extern D_L01_001DC400, 4");
__asm__(".extern D_L01_001DC360, 8");
__asm__(".extern D_L01_001DC3A0, 8");
__asm__(".extern D_L01_001DC3E0, 8");
__asm__(".extern D_L01_001DC404, 4");
__asm__(".extern D_L01_001DC408, 4");
__asm__(".extern D_L01_001DC40C, 4");
extern Pair_002FBCD0 D_L01_001DC410[];
extern Pair_002FBCD0 D_L01_001DC418[];
extern Pos_002FBCD0 D_L01_0026E180[];
extern vu0_v4 D_L01_002A4400[];
extern f32 D_L01_002A5040[][2];
extern u32 D_L01_002A5660[];
void func_L01_002FBCD0(u8 *self) {
    extern s32 func_L01_00513EF0(void);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_0043A860(void *, s32, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_0038D2A0(void *);
    extern void func_0038D640(void *, void *, void *);
    extern unsigned long func_00389598(s32);
    extern void func_003D2DA0(void *, void *, s32);
    extern void func_003A9440(s32, unsigned long);
    extern void func_0038C750(void);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    extern f32 func_003824E0(f32, f32);
    Quad_002FBCD0 quad;
    vu0_v4 matrix[4];
    vu0_v4 from;
    vu0_v4 to;
    vu0_v4 up;
    vu0_v4 offset;
    vu0_v4 view[4];
    vu0_v4 local[4];
    vu0_v4 glow[4];
    unsigned long color;
    u8 *vars;
    u8 *game;
    u8 *target;
    f32 angle;
    s32 i;
    s32 j;

    game = D_001A4BE0;
    target = *(u8 **)(game + 0x12F0);
    vars = *(u8 **)(self + 0x68);
    if (target == 0) {
        return;
    }
    if (*(s16 *)(target + 0xAA) != 0x260 && *(s16 *)(target + 0xAA) != 0x96C) {
        return;
    }
    quad.tag[2] = 0xFF9000000260UL;
    quad.tag[3] = 0x8000000048UL;
    quad.tag[0] = 0;
    if (func_L01_00513EF0() == 2) {
        angle = func_0038DAB8(*(f32 *)(game + 0x1580), *(s32 *)(vars + 4) ? 1.5707964f : -1.5707964f);
        offset.x = func_0038D098(angle) * D_L01_001DC408;
        offset.y = func_0038D0B0(angle) * D_L01_001DC408;
        offset.z = 0;
        angle = func_0038DAB8(*(f32 *)(game + 0x1580), 3.1415927f);
        up.x = func_0038D098(angle) * D_L01_001DC400;
        up.y = func_0038D0B0(angle) * D_L01_001DC400;
        up.z = 0;
        vec_add_ab(&up, &up, game + 0x80);
        vec_add_ab(&up, &up, &offset);
        up.z += D_L01_001DC404;
        to = up;
        from = up;
        to.z += D_L01_001DC40C;
    } else if (*(s32 *)(vars + 4) != 0) {
        *(Pair_002FBCD0 *)&up = D_L01_001DC410[0];
        func_L01_0043A860(target, 2, &up, &from);
    } else {
        *(Pair_002FBCD0 *)&up = D_L01_001DC418[0];
        func_L01_0043A860(target, 2, &up, &from);
    }
    *(vu0_q *)&up = 0;
    up.y = 1.0f;
    vec_sub_ab(&matrix[2], &from, &to);
    func_0038CF68(&matrix[2], &matrix[2], 1.0f);
    matrix[2].w = 0;
    func_0038CE90(&matrix[0], &up, &matrix[2]);
    func_0038CF68(&matrix[0], &matrix[0], 1.0f);
    matrix[0].w = 0;
    func_0038CE90(&matrix[1], &matrix[2], &matrix[0]);
    matrix[3] = to;
    matrix[1].w = 0;
    matrix[3].w = 1.0f;
    *(vu0_v4 *)(self + 0xC0) = matrix[0];
    *(vu0_v4 *)(self + 0xD0) = matrix[1];
    *(vu0_v4 *)(self + 0xE0) = matrix[2];
    *(vu0_v4 *)(self + 0x10) = matrix[3];
    color = 0x80800000;
    color |= 0x8080;
    func_0038D2A0(local);
    local[3].x = 0;
    local[3].y = 0;
    local[3].z = -0.075f;
    local[3].w = 1.0f;
    func_0038D640(view, matrix, local);
    quad.tag[1] = func_00389598(12);
    for (i = 0; i < 4; i++) {
        quad.colors[i] = color;
        if (i == 0 || i == 2) {
            func_0038CE20((f32 *)&quad.vertices[i], (f32 *)&D_L01_001DC360[i], *(f32 *)(vars + 0x2C));
        } else {
            func_0038CE20((f32 *)&quad.vertices[i], (f32 *)&D_L01_001DC360[i], *(f32 *)(vars + 0x2C));
            quad.vertices[i].z -= func_003824E0(0.0f, 0.1f);
        }
        quad.uv[i][0] = D_L01_001DC3E0[i][0];
        quad.uv[i][1] = D_L01_001DC3E0[i][1];
    }
    func_003D2DA0(&quad, view, 0);
    for (i = 0; i < 4; i++) {
        if (i == 0 || i == 2) {
            func_0038CE20((f32 *)&quad.vertices[i], (f32 *)&D_L01_001DC3A0[i], *(f32 *)(vars + 0x2C));
        } else {
            func_0038CE20((f32 *)&quad.vertices[i], (f32 *)&D_L01_001DC3A0[i], *(f32 *)(vars + 0x2C));
            quad.vertices[i].z -= func_003824E0(0.0f, 0.1f);
        }
    }
    func_003D2DA0(&quad, view, 0);
    quad.tag[1] = func_00389598(11);
    func_0038CE20((f32 *)&glow[3], (f32 *)&matrix[2], -0.13f);
    vec_add_ab(&glow[3], &glow[3], &matrix[3]);
    vec_sub_ab(&glow[0], &D_L01_001E29C0, &glow[3]);
    func_0038CF68(&glow[0], &glow[0], 1.0f);
    func_0038CE90(&glow[1], &glow[0], D_001A4BE0 + 0x2E0);
    func_0038CF68(&glow[1], &glow[1], -1.0f);
    func_0038CE90(&glow[2], &glow[1], &glow[0]);
    quad.colors[0] = quad.colors[1] = quad.colors[2] = quad.colors[3] = 0x7F2020FF;
    for (j = 0; j < 4; j++) {
        func_0038CE20((f32 *)&quad.vertices[j], (f32 *)&D_L01_001DC360[j], 0.1f);
        func_0038D028(&quad.vertices[j], &quad.vertices[j], glow);
    }
    func_003D2DA0(&quad, 0, 0);
    func_003A9440(6, func_00389598(10));
    func_003A9440(0x42, quad.tag[3]);
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x4A, 0);
    func_0038C750();
    for (i = 0; i < 196; i++) {
        f32 v;
        func_0038CE20((f32 *)&offset, (f32 *)&D_L01_002A4400[i], *(f32 *)(vars + 0x20));
        func_0038D028(&offset, &offset, matrix);
        D_L01_0026E180[i].x = offset.x;
        D_L01_0026E180[i].y = offset.y;
        D_L01_0026E180[i].z = offset.z;
        v = D_L01_002A5040[i][1] - 0.025f;
        D_L01_002A5040[i][1] = v;
        if (v < -7.0f) {
            D_L01_002A5040[i][1] = v + 7.0f;
        }
    }
    func_003D3A24(0x94, D_L01_0026E180, D_L01_002A5660, D_L01_002A5040, 1);
    func_003D3A24(0x32, (u8 *)D_L01_0026E180 + 0x6D8, (u8 *)D_L01_002A5660 + 0x248, (u8 *)D_L01_002A5040 + 0x490, 1);
}
/* localdecomp:end func_L01_002FBCD0 */

/* localdecomp:start func_L01_002FC3E8 */
#include "vu0.h"
#include "structs/hero.h"
extern vu0_v4 D_001A4D30;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 16");
void func_L01_002FC3E8(u8 *obj) {
    extern f32 func_00382538(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038D000(void *,void *,void *);
    extern u8 *func_L01_00466588(void *,void *,s32,s32,s32,s32,f32);
    extern f32 func_0038CF00(void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_004669B0(void *,f32,f32,f32,f32,s32,void *,s32,s32);
    vu0_v4 velocity, pos, delta, step;
    u8 *vars=*(u8 **)(obj+0x68);
    struct Hero *hero;
    f32 distance, growth;
    s32 i,count,color;
    u8 *particle;
    velocity.x=func_0038D098(func_00382538())*0.05f;
    velocity.y=func_0038D0B0(func_00382538())*0.05f;
    velocity.z=0.0f;
    velocity.z=-func_003824E0(0.01f,0.03f);
    func_0038D000(&velocity,&velocity,obj+0xC0);
    vec_add_ba(&velocity,&velocity,&D_001A4D30);
    *(vu0_q *)&pos=*(vu0_q *)(obj+0x10);
    if(*(s32 *)((u8 *)&D_001A4D30+0x2474)==128) {
        if(D_L01_001DFB40%3==0)func_L01_00466588(&pos,&velocity,0x4F007FFF,0x1FFFFFFF,8,1,10000.0f);
    } else {
        func_L01_00466588(&pos,&velocity,0x4F007FFF,0x1FFFFFFF,8,1,10000.0f);
    }
    if(*(s32 *)(vars+0xC)) {
        distance=func_0038CF00(vars+0x10,&pos)*0.5f;
        vec_sub_ab(&delta,vars+0x10,&pos);
        for(i=1;i<2;i++) {
            func_0038CF68(&step,&delta,distance*(f32)i);
            vec_add_ab(&step,&pos,&step);
            func_L01_00466588(&step,&velocity,0x4F007FFF,0x1FFFFFFF,8,1,10000.0f);
        }
    }
    *(s32 *)vars=func_00382468(8);
    velocity.x=0.0f;
    velocity.y=0.0f;
    velocity.z=-0.3f;
    velocity.w=1.0f;
    func_0038D000(&velocity,&velocity,obj+0xC0);
    vec_add_ab(&pos,obj+0x10,&velocity);
    velocity.z=-0.075f;
    velocity.w=1.0f;
    velocity.x=0.0f;
    velocity.y=0.0f;
    func_0038D000(&velocity,&velocity,obj+0xC0);
    velocity.z=0.025f;
    vec_add_ab(&velocity,&velocity,&D_001A4D30);
    hero=(struct Hero *)((u8 *)&D_001A4D30-0x150);
    color=0x808080;
    growth=1.075f;
    if(hero->state==8) {
        velocity.z-=0.10000000894069672f;
        color=0xA0A0A0;
        growth=1.0165f;
    }
    if(hero->state==128) {
        velocity.z-=0.06000000238418579f;
        color=0xA0A0A0;
        growth=1.037f;
    }
    {
        particle=func_L01_004669B0(&pos,0.05f,1.01f,growth,30000.0f,6,&velocity,color,0);
        if(particle)particle[3]=68;
    }
    if(*(s32 *)(vars+0xC)) {
        distance=func_0038CF00(vars+0x10,&pos)*0.16667f;
        count=4;
        if(hero->state==8)count=2;
        if(hero->state==128)count=1;
        vec_sub_ab(&delta,vars+0x10,&pos);
        for(i=1;i<count;i++) {
            func_0038CF68(&step,&delta,distance*(f32)i);
            vec_add_ab(&step,&pos,&step);
            particle=func_L01_004669B0(&step,0.05f,1.01f,growth,30000.0f,6,&velocity,color,0);
            if(particle)particle[3]=68;
        }
    }
    *(vu0_q *)(vars+0x10)=*(vu0_q *)&pos;
    *(s32 *)(vars+0xC)=1;
}
/* localdecomp:end func_L01_002FC3E8 */

/* localdecomp:start func_L01_002FC8A8 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
} S_2FC880b;

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x30 - 0x21];
    u8 b30;
    u8 b31;
    s16 h32;
    u8 pad34[0x68 - 0x34];
    S_2FC880b *p68;
} S_2FC880;

extern S_2FC880 *func_003C24B0(s32 a0, s32 a1);

S_2FC880 *func_L01_002FC8A8(s32 a0) {
    S_2FC880 *p = func_003C24B0(167, 128);
    if (p != 0) {
        S_2FC880b *q = p->p68;
        q->w4 = a0;
        q->w0 = 0;
        q->w8 = 0;
        q->wC = 0;
        p->b30 = 255;
        p->h32 = 126;
        p->b31 = 0;
        p->b20 = 0;
    }
    return p;
}
/* localdecomp:end func_L01_002FC8A8 */

/* localdecomp:start func_L01_002FC910 */
typedef struct {
    u8 pad0[0x1B8]; s32 frame;
    u8 pad1BC[0x36E - 0x1BC]; s16 h36E;
    u8 pad370[0x46E - 0x370]; u8 disabled;
    u8 pad46F[0xC18 - 0x46F]; f32 anim;
    u8 padC1C[0x12F0 - 0xC1C]; void *backpack,*clank;
    u8 pad12F8[0x1318 - 0x12F8]; s32 item;
    u8 pad131C[0x25C0 - 0x131C]; u8 *moby;
    s32 state;
    u8 pad25C8[0x2884 - 0x25C8]; s16 suppressed;
} Hero_002FC910;
typedef struct {
    s32 timer,kind; void *owner; s32 active;
    u8 pad10[0x20 - 0x10];
    f32 a,b,c,d,da,db,dc,dd;
} Vars_002FC910;
extern Hero_002FC910 D_001A4BE0_002FC910;
extern u8 *D_001D52FC;
extern u16 D_001A8EA4[];
void func_L01_002FC910(u8 *self)
{
    extern s32 func_L01_004E9238(s32);
    extern s32 func_003A3BB8(s32,s32);
    extern void func_003C2880(void *);
    extern void func_L01_0041A5B0(s32,s32);
    extern void func_L01_002FBCD0(u8 *);
    extern void (func_L01_00404A10_002FC910)(void (*)(u8 *),u8 *);
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_002FC3E8(u8 *);
    s32 active=0;
    Vars_002FC910 *v=*(Vars_002FC910 **)(self+0x68);
    if((D_001A4BE0_002FC910.item==3 || func_L01_004E9238(3)==8) && (self[0x20]==1 || self[0x20]==3)) {
        Hero_002FC910 *h=&D_001A4BE0_002FC910;
        if((u32)(h->state-11)<4 || (h->state==27 && h->moby[0x42]==h->moby[0x43] && h->anim>=6.0f && h->anim<=16.0f)) {if(!h->disabled)active=1;}
        if(D_001A4BE0_002FC910.state==135 && (*(s32 *)(D_001D52FC+0x1A0)&func_003A3BB8(64,0))) active=1;
        if(D_001A4BE0_002FC910.state==16 && D_001A4BE0_002FC910.frame<=36)active=1;
        if(D_001A4BE0_002FC910.state==33 && (D_001A4BE0_002FC910.frame<12 || (D_001A4BE0_002FC910.frame>=28 && D_001A4BE0_002FC910.h36E)))active=1;
        if(D_001A4BE0_002FC910.state==8)active=1;
        if(D_001A4BE0_002FC910.state==135)active=1;
        if(D_001A4BE0_002FC910.suppressed)active=0;
    }
    switch(self[0x20]) {
    case 0:
        self[0x20]=1;
        *(u16 *)(self+0x34)|=1;
        self[0x30]=255;
        *(f32 *)(self+0x18)+=0.5f;
        break;
    case 1:
        if((func_L01_004E9238(3)!=3 && func_L01_004E9238(3)!=8) || !D_001A4BE0_002FC910.clank) {
            func_003C2880(self);
            return;
        }
        if(!D_001A8EA4[0] && D_001A4BE0_002FC910.item==3)func_L01_0041A5B0(0x18CD,0x161);
        if(active) {
            self[0x20]=2;
            v->timer=2;
            v->da=0.00625f;
            v->db=0.1f;
            v->dc=0.025f;
            v->dd=0.0125f;
            v->a=0;
            v->b=0;
            v->c=0;
            v->d=0;
        }
        break;
    case 2:
        v->a+=v->da;
        v->b+=v->db;
        v->c+=v->dc;
        v->d+=v->dd;
        v->owner=D_001A4BE0_002FC910.backpack;
        (func_L01_00404A10_002FC910)(func_L01_002FBCD0,self);
        if(func_0038CAD0(&v->timer)) {
            f32 c, b, a;
            self[0x20]=3;
            a=0.0125f;
            b=0.2f;
            c=0.05f;
            v->d=0.025f;
            v->a=a;
            v->b=b;
            v->c=c;
            v->active=0;
        }
        break;
    case 3:
        v->owner=D_001A4BE0_002FC910.backpack;
        (func_L01_00404A10_002FC910)(func_L01_002FBCD0,self);
        if(!active) {
            self[0x20]=4;
            v->timer=7;
            v->da=0.0017857142956927419f;
            v->db=0.02857142873108387f;
            v->dc=0.0071428571827709675f;
            v->dd=0.0035714285913854837f;
        } else {
            v->a=0.0125f;
            func_L01_002FC3E8(self);
        }
        break;
    case 4:
        if(func_0038CAD0(&v->timer))self[0x20]=1;
        else {
            v->a-=v->da;
            v->b-=v->db;
            v->c-=v->dc;
            v->d-=v->dd;
            v->owner=D_001A4BE0_002FC910.backpack;
            (func_L01_00404A10_002FC910)(func_L01_002FBCD0,self);
        }
        break;
    }
}
/* localdecomp:end func_L01_002FC910 */

/* localdecomp:start func_L01_002FCDC0 */
typedef struct { s32 a, b, c; } Params_002FCDC0;
typedef struct {
    u8 pad0[0x1210];
    s32 buttons;        /* 0x1210 */
    u8 pad1214[0xC];
    s32 health;         /* 0x1220 */
    u8 pad1224[0x25C4 - 0x1224];
    s32 state;          /* 0x25C4 */
    u8 pad25C8[0x25ED - 0x25C8];
    u8 busy;            /* 0x25ED */
    u8 pad25EE[0x28BC - 0x25EE];
    s32 timer;          /* 0x28BC */
} Hero_002FCDC0;
extern Params_002FCDC0 D_L01_001DC420;
extern Hero_002FCDC0 D_001A4BE0_002FCDC0;
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L01_004501E8(void *, void *, f32, f32, f32, void *, s32, s32, s32, f32, f32, s32, void *, s32, s32, s32);
extern void func_L01_004C7438(void *, void *, void *, f32, f32, f32, f32, s32);
extern s32 func_L01_004C7A18(f32, void *, void *, void *, void *, void *, s32, s32);
extern s32 func_L01_005118D0(s32, s32);
extern void func_L01_004EA7D8(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004EAA80(void);
extern void func_L01_00404A10_002FCDC0(void (*)(u8 *), u8 *);
extern void func_L01_002FD090(u8 *);
extern u8 *func_L01_002F98F8(Q_002F98F8 *, Q_002F98F8 *);
extern s32 func_0038CAD0(s32 *);
void func_L01_002FCDC0(u8 *self) {
    Q_002F98F8 position[1];
    Params_002FCDC0 params;
    Q_002F98F8 origin[1];
    Q_002F98F8 *origin_ptr;
    Q_002F98F8 hit[1];
    u8 *vars = *(u8 **)(self + 0x68);
    u8 *ref;
    Hero_002FCDC0 *hero;
    u8 *target;
    f32 distance;
    s32 allowed;

    func_003C2F58(self, 0, position);
    ref = (u8 *)&D_001A4BE0_002FCDC0 + 0x6F0;
    params = D_L01_001DC420;
    target = func_L01_004501E8(self + 0x10, ref, 0.39269909262657166f, 0.7853981852531433f, 11.100000381469727f,
                               hit, 0, 0, 0, 0.0f, 0.0f, 0, &params, 1, -1, 0);
    hero = &D_001A4BE0_002FCDC0;
    origin_ptr = origin;
    distance = 10.0f;
    if (hero->state == 29) distance = 11.0f;
    allowed = 1;
    func_L01_004C7438(origin_ptr, position, target, 1.5f, distance, 0.20000001788139343f, 0.004399999976158142f, 0);
    *(s32 *)(vars + 0x24) = func_L01_004C7A18(0.004399999976158142f, position, origin_ptr, vars, vars + 0x10, self, 0, 0);
    if (hero->state == 29) {
        if (func_0038CAD0(&hero->timer) == 0) allowed = 0;
    } else {
        hero->timer = 33;
    }
    switch (self[0x20]) {
    case 0:
        self[0x20] = 1;
        *(s32 *)(vars + 0x24) = 0;
    case 1:
        if ((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_002FCDC0.buttons) && D_001A4BE0_002FCDC0.busy == 0
            && D_001A4BE0_002FCDC0.health >= 19 && allowed) {
            if (func_L01_005118D0(-1, 1)) {
                func_L01_004EA7D8(-1);
                self[0x20] = 2;
                *(s32 *)(vars + 0x20) = 17;
            } else if (*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0_002FCDC0.buttons) {
                func_003A52A0(2, 0, self);
            }
        }
        break;
    case 2:
        if (func_0038CAD0((s32 *)(vars + 0x20))) {
            u8 *m = func_L01_002F98F8(position, origin_ptr);
            *(u8 **)(m + 0xB8) = self;
            func_L01_004EAA80();
            self[0x20] = 3;
            *(s32 *)(vars + 0x20) = 8;
        }
        break;
    case 3:
        if (func_0038CAD0((s32 *)(vars + 0x20)) != 0) self[0x20] = 1;
        break;
    }
    func_L01_00404A10_002FCDC0(func_L01_002FD090, self);
}
/* localdecomp:end func_L01_002FCDC0 */

/* localdecomp:start func_L01_002FD090 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_002FD090(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_002FD090 */

/* localdecomp:start func_L01_002FD0C8 */
#include "vu0.h"
__asm__(".extern D_L01_001DC434, 4");
extern f32 D_L01_001DC434;
extern vu0_q D_L01_001E16C0[1] __attribute__((section(".sdata")));
void func_L01_002FD0C8(u8 *p) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_L01_002FD818(u8 *);
    extern void func_003D9508(vu0_q *, s32, u32, s32, f32, f32, f32);
    f32 t, a, b, c;
    u32 x, y, z;
    D_L01_001DC434 = func_0038DAB8(D_L01_001DC434, 0.15f);
    t = (func_0038D098(D_L01_001DC434) + 1.0f) * 0.5f;
    a = t * 0.0625f + 0.0625f;
    b = t * 0.19999998807907104f + 0.15f;
    c = t * 0.125f + 0.125f;
    x = func_0038DBD8(0x2F007F00, 0x3F007F00, t);
    y = func_0038DBD8(0x2F7F7F7F, 0x5F7F7F7F, t);
    z = func_0038DBD8(0x10208040, 0x10208040, t);
    func_L01_002FD818(p);
    func_003D9508(D_L01_001E16C0, 0x31, x, 1, c, 0.125f, 0.0f);
    func_003D9508(D_L01_001E16C0, 0x31, y, 1, a, 0.124f, 0.0f);
    func_003D9508(D_L01_001E16C0, 0xB, z, 1, b, 0.123f, 0.0f);
}
/* localdecomp:end func_L01_002FD0C8 */

/* localdecomp:start func_L01_002FD288 */
typedef struct {
    f32 pos[4], second[4], origin[4], attached[4];
    f32 angle[3], velocity[3], scale[3];
    f32 angle2[3], velocity2[3], scale2[3];
    s32 timer, kind;
    u8 *owner;
    s32 remaining, duration, finished;
} Effect_002FD288;
extern Effect_002FD288 D_L01_0026EAB0_002FD288[];
extern vu0_q D_L01_001E16C0[1] __attribute__((section(".sdata")));
void func_L01_002FD288(s32 kind, u8 *owner, s32 duration) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_00382348(u8 *);
    extern void func_L01_00451290(u8 *, f32 *, s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    f32 offset[4] __attribute__((aligned(16)));
    Effect_002FD288 *base = D_L01_0026EAB0_002FD288;
    s32 i = 0;
    vu0_q *origin = D_L01_001E16C0;
    Effect_002FD288 *p;
    u8 *attachment;
    for (; i < 3; i++) {
        p = &base[i];
        if (p->kind != 0) continue;
        p->kind = kind;
        *(vu0_q *)p->origin = *origin;
        p->angle[0] = func_003824E0(-3.1415927f, 3.1415927f);
        p->angle[1] = func_003824E0(-3.1415927f, 3.1415927f);
        p->angle[2] = func_003824E0(-3.1415927f, 3.1415927f);
        p->angle2[0] = func_003824E0(-3.1415927f, 3.1415927f);
        p->angle2[1] = func_003824E0(-3.1415927f, 3.1415927f);
        p->angle2[2] = func_003824E0(-3.1415927f, 3.1415927f);
        p->velocity[0] = func_L01_00443A18(0.001f, 0.005f);
        p->velocity[1] = func_L01_00443A18(0.001f, 0.005f);
        p->velocity[2] = func_L01_00443A18(0.001f, 0.005f);
        p->velocity2[0] = func_L01_00443A18(0.001f, 0.005f);
        p->velocity2[1] = func_L01_00443A18(0.001f, 0.005f);
        p->velocity2[2] = func_L01_00443A18(0.001f, 0.005f);
        p->scale[0] = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->scale[1] = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->scale[2] = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->scale2[0] = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->scale2[1] = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->scale2[2] = func_003824E0(3.25f, 4.75f) * 0.5f;
        qzero(p->pos);
        qzero(p->second);
        p->remaining = duration;
        p->duration = duration;
        p->timer = 12;
        p->owner = owner;
        p->finished = 0;
        attachment = func_00382348(owner);
        if (attachment != 0) {
            func_L01_00451290(owner, offset, 1);
            func_0038CE20(offset, offset, *(f32 *)(attachment + 0x10));
            vec_add_ba(p->attached, offset, owner + 0x10);
        } else {
            *(vu0_q *)p->attached = *(vu0_q *)(owner + 0x10);
        }
        break;
    }
}
/* localdecomp:end func_L01_002FD288 */

/* localdecomp:start func_L01_002FD530 */
typedef struct {
    f32 pos[4], second[4], origin[4], attached[4];
    f32 angle[3], velocity[3], scale[3];
    f32 angle2[3], velocity2[3], scale2[3];
    s32 timer, kind;
    u8 *owner;
    s32 remaining, duration, finished;
} Effect_002FD530;
extern Effect_002FD530 D_L01_0026EAB0[];
extern vu0_q D_L01_001E16C0[1] __attribute__((section(".sdata")));
void func_L01_002FD530(s32 kind) {
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern u8 *func_00382348(u8 *);
    extern void func_L01_00451290(u8 *, f32 *, s32);
    extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
    extern s32 func_0038CAD0(s32 *);
    f32 offset[4] __attribute__((aligned(16)));
    vu0_q *origin = D_L01_001E16C0;
    Effect_002FD530 *base = D_L01_0026EAB0;
    s32 i;
    Effect_002FD530 *p;
    u8 *attachment;
    for (i = 0; i < 3; i++) {
        p = &base[i];
        if (p->kind != kind) continue;
        *(vu0_q *)p->origin = *origin;
        if (p->remaining) {
            p->angle[0] = func_0038DAB8(p->angle[0], p->velocity[0] * 100.0f);
            p->angle[1] = func_0038DAB8(p->angle[1], p->velocity[1] * 100.0f);
            p->angle[2] = func_0038DAB8(p->angle[2], p->velocity[2] * 100.0f);
            p->angle2[0] = func_0038DAB8(p->angle2[0], p->velocity2[0] * 100.0f);
            p->angle2[1] = func_0038DAB8(p->angle2[1], p->velocity2[1] * 100.0f);
            p->angle2[2] = func_0038DAB8(p->angle2[2], p->velocity2[2] * 100.0f);
        } else {
            p->angle[0] = func_0038DAB8(p->angle[0], p->velocity[0] * 50.0f);
            p->angle[1] = func_0038DAB8(p->angle[1], p->velocity[1] * 50.0f);
            p->angle[2] = func_0038DAB8(p->angle[2], p->velocity[2] * 50.0f);
            p->angle2[0] = func_0038DAB8(p->angle2[0], p->velocity2[0] * 50.0f);
            p->angle2[1] = func_0038DAB8(p->angle2[1], p->velocity2[1] * 50.0f);
            p->angle2[2] = func_0038DAB8(p->angle2[2], p->velocity2[2] * 50.0f);
        }
        p->pos[0] = func_0038D098(p->angle[0]) * p->scale[0];
        p->pos[1] = func_0038D0B0(p->angle[1]) * p->scale[1];
        p->pos[2] = -func_0038D0B0(p->angle[2]) * p->scale[2];
        p->second[0] = func_0038D098(p->angle2[0]) * p->scale2[0];
        p->second[1] = func_0038D0B0(p->angle2[1]) * p->scale2[1];
        p->second[2] = -func_0038D0B0(p->angle2[2]) * p->scale2[2];
        if (p->owner) {
            attachment = func_00382348(p->owner);
            if (attachment) {
                func_L01_00451290(p->owner, offset, 1);
                func_0038CE20(offset, offset, *(f32 *)(attachment + 0x10));
                vec_add_ab(p->attached, offset, p->owner + 0x10);
            } else {
                *(vu0_q *)p->attached = *(vu0_q *)(p->owner + 0x10);
            }
            func_0038CDF8(p->attached, p->origin, p->attached, 1.0f - (f32)p->remaining / (f32)p->duration);
        }
        if (func_0038CAD0(&p->remaining)) {
            if (!p->finished) p->finished = 1;
            if (func_0038CAD0(&p->timer)) p->kind = 0;
        }
    }
}
/* localdecomp:end func_L01_002FD530 */

/* localdecomp:start func_L01_002FD818 */
extern void func_L01_002FDA10(u8 *, void *);
extern void func_003D9508(vu0_q *, s32, u32, s32, f32, f32, f32);
void func_L01_002FD818(u8 *owner) {
    s32 i;
    Effect_002FD530 *p;

    for (i = 0; i < 3; i++) {
        Effect_002FD530 *base = D_L01_0026EAB0;
        p = &base[i];
        if (p->kind == (s32)owner) {
            func_L01_002FDA10(owner, p);
            if (p->remaining == 0) {
                func_003D9508((vu0_q *)p->attached, 0x31, 0x3F007F00, 1, func_003824E0(0.125f, 0.25f) * 5.0f, 1.25f, 0.0f);
                func_003D9508((vu0_q *)p->attached, 0x31, 0x5F7F7F7F, 1, func_003824E0(0.0625f, 0.125f) * 5.0f, 1.24f, 0.0f);
                func_003D9508((vu0_q *)p->attached, 0xB, 0x10003F00, 1, func_003824E0(0.15f, 0.35f) * 5.0f, 1.23f, 0.0f);
            }
        }
    }
}
/* localdecomp:end func_L01_002FD818 */

/* localdecomp:start func_L01_002FD988 */
void func_L01_002FD988(f32 *p) {
    *(long *)(p + 32) = 0x0000FF9000000260L;
    *(long *)(p + 28) = 0;
    p[20] = 0.0f;
    p[21] = 0.0f;
    p[22] = 1.0f;
    p[23] = 0.0f;
    p[24] = 0.0f;
    p[25] = 1.0f;
    p[26] = 1.0f;
    p[27] = 1.0f;
    p[2] = -1.0f;
    p[6] = 1.0f;
    p[10] = -1.0f;
    p[14] = 1.0f;
    p[1] = -1.0f;
    p[5] = -1.0f;
    p[9] = 1.0f;
    p[13] = 1.0f;
    p[0] = 0.0f;
    p[4] = 0.0f;
    p[8] = 0.0f;
    p[12] = 0.0f;
    p[3] = 1.0f;
    p[7] = 1.0f;
    p[11] = 1.0f;
    p[15] = 1.0f;
}
/* localdecomp:end func_L01_002FD988 */

/* localdecomp:start func_L01_002FDA10 */
#include "vu0.h"
void func_L01_002FDA10(u8 *owner, void *in) {
    extern void func_L01_00445208_002FDA10(void *, void *, void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_002FDC18_002FDA10(void *, s32, void *, s32);
    Effect_002FD530 *input = (Effect_002FD530 *)in;
    vu0_q points[25];
    vu0_v4 a, b, random;
    vu0_q *out = points;
    s32 i;
    for (i = 0; i < 24; i++, out++) {
        /* both ends go into VU0 registers first; the "j" class has only vf1 and vf2, so the second
           is spilled to the stack around the first sum (retail's sqc2/lqc2 at sp+0x1C0) */
        vu0_q qo, qe, qa, qb;
        __asm__("lqc2 %0, %1" : "=j"(qo) : "m"(*(vu0_v4 *)input->origin));
        __asm__("lqc2 %0, %1" : "=j"(qe) : "m"(*(vu0_v4 *)input->attached));
        *(vu0_q *)&a = *(vu0_q *)input->pos;
        *(vu0_q *)&b = *(vu0_q *)input->second;
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)&a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qo));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&a) : "j"(qa));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)&b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qe));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&b) : "j"(qb));
        func_L01_00445208_002FDA10(out, input->origin, input->attached, &a, &b, (f32)i / 23.0f);
        random.w = 0.0f;
        random.x = func_003824E0(-1.0f, 1.0f);
        random.y = func_003824E0(-1.0f, 1.0f);
        random.z = func_003824E0(-1.0f, 1.0f);
        func_0038CF68(&random, &random, 0.075f);
        vec_add_ab(out, out, &random);
    }
    if (input->timer >= 6) func_L01_002FDC18_002FDA10(owner, func_00382498(64, 128), points, 25);
    else func_L01_002FDC18_002FDA10(owner, func_00382498(0, 64), points, 25);
}
/* localdecomp:end func_L01_002FDA10 */

/* localdecomp:start func_L01_002FDBD8 */
void func_L01_002FDBD8(f32 (*pts)[4], s32 n) {
    f32 d[4];

    vec_sub_ab(d, pts[n - 2], pts[n - 3]);
    vec_add_ab(pts[n - 1], pts[n - 2], d);
}
/* localdecomp:end func_L01_002FDBD8 */

/* localdecomp:start func_L01_002FDC18 */
#include "vu0.h"
void func_L01_002FDC18(s32 unused, s32 colour, f32 (*pts)[4], s32 count) {
    extern unsigned long func_00389598(s32);
    extern void func_L01_002FDBD8(f32 (*)[4], s32);
    extern void func_L01_002FD988(f32 *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern void func_0038D028(f32 *, f32 *, f32 *);
    extern void func_003D2DA0(f32 *, s32, s32);
    f32 a[36] __attribute__((aligned(16)));
    f32 b[36] __attribute__((aligned(16)));
    f32 axis[4] __attribute__((aligned(16)));
    f32 eye[4] __attribute__((aligned(16)));
    f32 side[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 inner[4] __attribute__((aligned(16)));
    f32 outer[4] __attribute__((aligned(16)));
    s32 i;
    s32 edgeColour = 0x8000FF00;
    unsigned long texture;
    f32 u, v;
    f32 k;
    texture = func_00389598(43);
    *(unsigned long *)(a + 28) = 0;
    *(unsigned long *)(a + 32) = 0x0000FF9000000260UL;
    *(unsigned long *)(a + 34) = ((unsigned long)(u32)colour << 32) | 104;
    *(s32 *)(a + 17) = 0x7FFFFFFF;
    *(s32 *)(a + 16) = 0x7FFFFFFF;
    *(unsigned long *)(a + 30) = texture;
    texture = func_00389598(43);
    *(unsigned long *)(b + 28) = 0;
    *(unsigned long *)(b + 32) = 0x0000FF9000000260UL;
    *(unsigned long *)(b + 34) = ((unsigned long)(u32)(colour / 3) << 32) | 104;
    *(unsigned long *)(b + 30) = texture;
    *(vu0_q *)inner = 0;
    *(vu0_q *)outer = 0;
    inner[2] = 0.05f;
    outer[2] = 0.2f;
    *(s32 *)(a + 17) = edgeColour;
    *(s32 *)(b + 16) = edgeColour;
    inner[3] = 1.0f; outer[3] = 1.0f;
    func_L01_002FDBD8(pts, count);
    func_L01_002FD988(a);
    func_L01_002FD988(b);
    a[20]=0.0f; a[21]=0.0f; a[22]=0.0f; a[23]=1.0f;
    a[24]=1.0f; a[25]=0.0f; a[26]=1.0f; a[27]=1.0f;
    b[20]=0.0f; b[21]=0.0f; b[22]=0.0f; b[23]=1.0f;
    b[24]=0.33f; b[25]=0.0f; b[26]=0.33f; b[27]=1.0f;
    vec_sub_ba(axis, pts[1], pts[0]);
    func_0038CF68(axis, axis, 1.0f);
    vec_sub_ab(eye, (f32 *)&D_L01_001E29C0, pts[0]);
    func_0038CE90(side, eye, axis);
    func_0038CF68(side, side, 1.0f);
    func_0038CE90(eye, axis, side);
    *(vu0_q *)pos = *(vu0_q *)pts[0];
    *(vu0_q *)a = *(vu0_q *)inner;
    func_0038CE20(a + 4, a, -1.0f);
    func_0038D028(a, a, axis);
    func_0038D028(a + 4, a + 4, axis);
    *(vu0_q *)b = *(vu0_q *)outer;
    func_0038CE20(b + 4, b, -1.0f);
    func_0038D028(b, b, axis);
    func_0038D028(b + 4, b + 4, axis);
    for (i = 1; i < count - 1; i++) {
        *(vu0_q *)(a + 8) = *(vu0_q *)inner;
        func_0038CE20(a + 12, a + 8, -1.0f);
        *(vu0_q *)(b + 8) = *(vu0_q *)outer;
        func_0038CE20(b + 12, b + 8, -1.0f);
        vec_sub_ab(axis, pts[i + 1], pts[i]);
        func_0038CF68(axis, axis, 1.0f);
        vec_sub_ab(eye, (f32 *)&D_L01_001E29C0, pts[i]);
        func_0038CE90(side, eye, axis);
        func_0038CF68(side, side, 1.0f);
        func_0038CE90(eye, axis, side);
        *(vu0_q *)pos = *(vu0_q *)pts[i];
        func_0038D028(a + 8, a + 8, axis);
        func_0038D028(a + 12, a + 12, axis);
        func_0038D028(b + 8, b + 8, axis);
        k = 0.33f;
        func_0038D028(b + 12, b + 12, axis);
        *(s32 *)(a + 19) = 0x7F7F7F7F;
        *(s32 *)(a + 18) = 0x7F7F7F7F;
        *(s32 *)(b + 19) = edgeColour;
        *(s32 *)(b + 18) = edgeColour;
        func_003D2DA0(a, 0, 0);
        func_003D2DA0(b, 0, 0);
        u = i * k;
        v = u + k;
        if (u >= 1.0f) { u -= 1.0f; v -= 1.0f; }
        b[20] = u; b[24] = v; b[22] = u; b[26] = v;
        *(vu0_q *)a = *(vu0_q *)(a + 8);
        *(vu0_q *)(a + 4) = *(vu0_q *)(a + 12);
        *(vu0_q *)b = *(vu0_q *)(b + 8);
        *(vu0_q *)(b + 4) = *(vu0_q *)(b + 12);
    }
}
/* localdecomp:end func_L01_002FDC18 */

/* localdecomp:start func_L01_002FE0A0 */
extern f32 D_L01_001D66B0;
extern u8 *D_L01_00221208[];
void func_L01_002FE0A0(f32 *pos, f32 *unused, f32 size) {
    extern s32 func_00382468(s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_0046A610(f32 *, f32 *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    f32 point[4];
    u8 *p;
    size *= 210000.0f;
    if (func_00382468(2)) {
        s32 rotation = (s32)func_L01_00443A18(1.0f, -1.0f);
        p = func_L01_0046A610(pos, &D_L01_001D66B0, 2, 6, 0x20FF40, rotation, size * 6.0f, 500.0f, 1.0f, 0.0f, 2.0f);
        if (p) p[2] = D_L01_00221208[0][1];
    }
    point[0] = pos[0] + func_L01_00443A18(0.0f, 0.04f);
    point[1] = pos[1] + func_L01_00443A18(0.0f, 0.04f);
    point[2] = pos[2] + func_L01_00443A18(0.0f, 0.04f);
    if (func_00382468(2)) {
        s32 rotation = (s32)func_L01_00443A18(1.0f, -1.0f);
        p = func_L01_0046A610(point, &D_L01_001D66B0, 2, 127, 0x20FF40, rotation, size * 2.4f, 500.0f, 1.0f, 0.0f, 2.0f);
        if (p) {
            p[3] = func_00382468(2) ? 72 : 68;
            p[2] = D_L01_00221208[0][0];
        }
    }
}
/* localdecomp:end func_L01_002FE0A0 */

/* localdecomp:start func_L01_002FE280 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_002FE280;
typedef struct {
    V4_002FE280 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long tag[4];
} Q_002FE280;
typedef struct {
    u8 pad0[0x14];
    u8 *f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} P_002FE280;
__asm__(".extern D_L01_001DC438, 4");
extern s32 D_L01_001DC438;
__asm__(".extern D_L01_001DC43C, 4");
extern s32 D_L01_001DC43C;
__asm__(".extern D_L01_001DC440, 4");
extern s32 D_L01_001DC440;
__asm__(".extern D_L01_001DC444, 4");
extern s32 D_L01_001DC444;
__asm__(".extern D_L01_001DC448, 4");
extern u32 D_L01_001DC448;
__asm__(".extern D_L01_001DC44C, 4");
extern s32 D_L01_001DC44C;
__asm__(".extern D_L01_001DC450, 4");
extern s32 D_L01_001DC450;
extern f32 D_L01_001E2880[];
extern u8 *D_L01_0022116C[];
extern unsigned long func_00389598(int);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_003D9508(vu0_q *, s32, u32, s32, f32, f32, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038DB48(f32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_L01_002FE0A0(f32 *, f32 *, f32);

void func_L01_002FE280(u8 *a0) {
    Q_002FE280 q;
    V4_002FE280 start;
    V4_002FE280 cur;
    V4_002FE280 end;
    V4_002FE280 dir;
    V4_002FE280 side;
    V4_002FE280 up;
    V4_002FE280 tmp;
    V4_002FE280 to;
    V4_002FE280 off;
    V4_002FE280 joint;
    V4_002FE280 pos;
    V4_002FE280 vel;
    P_002FE280 *pv;
    s32 i;
    s32 n;
    f32 ang;
    f32 dang;
    f32 width;
    f32 len;
    f32 t;
    f32 step;
    f32 wave;
    f32 s;
    f32 sn;
    f32 a;
    f32 amp;
    f32 sc;
    u8 *r;
    s32 k;
    unsigned long tex;
    unsigned long t2 = 0xFF9000000260;

    pv = *(P_002FE280 **)(a0 + 0x68);
    if (pv == 0) {
        return;
    }
    pv->f24 += 0.2f;
    if (pv->f24 >= 3.0f) {
        pv->f24 = 0.0f;
    }
    func_003C2F58(a0, 1, &joint);
    func_L01_002FE0A0((f32 *)&joint, &D_L01_001D66B0, 0.25f);
    for (i = 0; i < 2; i++) {
        if (i == 1) {
            D_L01_001DC44C = D_L01_001DC450;
            D_L01_001DC448 = 0x3020FF20;
            width = 0.11f;
        } else {
            D_L01_001DC44C = 0x45;
            D_L01_001DC448 = 0x80208040;
            width = 0.05f;
        }
        tex = func_00389598(D_L01_001DC44C);
        q.col[3] = D_L01_001DC448;
        q.col[2] = D_L01_001DC448;
        q.col[1] = D_L01_001DC448;
        q.col[0] = D_L01_001DC448;
        q.tag[1] = tex;
        q.tag[3] = (long)D_L01_001DC438 | ((long)D_L01_001DC43C << 2) | ((long)D_L01_001DC440 << 4)
                 | ((long)D_L01_001DC444 << 6) | 0xFF00000000;
        q.tag[2] = t2;
        q.tag[0] = 0;
        q.uv[0][0] = pv->f24 + 0.0f;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = pv->f24 + 1.0f;
        q.uv[1][1] = 0.0f;
        q.uv[2][0] = pv->f24 + 0.0f;
        q.uv[2][1] = 1.0f;
        q.uv[3][0] = pv->f24 + 1.0f;
        q.uv[3][1] = 1.0f;
        func_003C2F58(a0, 1, &end);
        start = *(V4_002FE280 *)(pv->f14 + 0x10);
        cur = start;
        dang = func_0038D160(D_L01_001E2880[0x140 / 4] - *(f32 *)(a0 + 0x10),
                            D_L01_001E2880[0x144 / 4] - *(f32 *)(a0 + 0x14));
        n = func_L01_00443A18(2.0f, 5.0f);
        pos.x = *(f32 *)(a0 + 0x10) + func_003824E0(-0.01f, 0.01f);
        pos.y = *(f32 *)(a0 + 0x14) + func_003824E0(-0.01f, 0.01f);
        pos.z = *(f32 *)(a0 + 0x18) + func_003824E0(-0.01f, 0.01f);
        s = func_003824E0(0.4f, 0.6f);
        sc = func_003824E0(4.5f, 6.0f);
        ang = func_0038DAB8(dang, func_L01_00443A18(0.0f, 1.3962634f));
        sc *= 0.020000001f;
        vel.x = func_0038D098(ang) * sc;
        vel.y = func_0038D0B0(ang) * sc;
        vel.z = 0.0f;
        vel.z = func_003824E0(0.0f, 0.5f);
        vel.z *= 0.020000001f;
        func_L01_004713C8(&start, &vel, (func_00382498(15, 25) * 5 + 2) / 6, 0x40FF7F, n, 0x7F, 0x7F,
                          s * 210000.0f, 2100.0f, 0.0064000003f, 6);
        n = -(n * 2);
        k = func_00382498(15, 25);
        s *= 3.0f;
        r = func_L01_004713C8(&start, &vel, (k * 5 + 2) / 6, 0xFF20, n, 0x30, 0x30,
                              s * 210000.0f, 4200.0f, 0.0064000003f, 0);
        if (r != 0) {
            r[2] = D_L01_0022116C[0][0];
        }
        func_003D9508((vu0_q *)&start, 0x31, 0x2F208040, 1, 0.25f, 0.125f, 0.0f);
        func_003D9508((vu0_q *)&start, 0x31, 0x2F208040, 1, 0.4f, 0.124f, 0.0f);
        func_003D9508((vu0_q *)&start, 0xB, 0x2F007F00, 1, 0.55f, 0.123f, 0.0f);
        vec_sub_ab(&dir, &end, &start);
        len = func_0038CEA8(&dir);
        tmp = dir;
        tmp.z -= 0.1f;
        func_0038CE90(&side, &dir, &tmp);
        func_0038CE90(&up, &dir, &side);
        q.v[0] = start;
        q.v[2] = start;
        q.v[2].z += width;
        q.v[0].z -= width;
        amp = func_0038D098(func_0038DB48(pv->f18));
        t = 0.0f;
        while (t < len) {
            step = 0.4f;
            if (len - t < step) {
                step = len - t;
            }
            t += step;
            a = t * 3.1415927f;
            sn = func_0038D0B0(a / len);
            wave = func_0038D0B0(func_0038DB48(a / pv->f1C)) * sn;
            wave *= amp;
            wave *= pv->f20;
            func_0038CF68(&dir, &dir, step);
            vec_add_ab(&cur, &cur, &dir);
            q.v[1] = cur;
            q.v[3] = cur;
            vec_sub_ba(&to, &D_L01_001E29C0, &cur);
            func_0038CE90(&off, &to, &dir);
            func_0038CF68(&off, &off, width);
            vec_add_ab(&q.v[1], &q.v[1], &off);
            vec_sub_ab(&q.v[3], &q.v[3], &off);
            func_0038CF68(&tmp, &side, wave);
            vec_add_ab(&q.v[1], &q.v[1], &tmp);
            vec_add_ab(&q.v[3], &q.v[3], &tmp);
            func_003D2DA0(&q, 0, 1);
            start = cur;
            q.v[0] = q.v[1];
            q.v[2] = q.v[3];
        }
    }
}
/* localdecomp:end func_L01_002FE280 */

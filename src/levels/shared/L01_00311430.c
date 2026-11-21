#include "common.h"
#include "vu0.h"

typedef struct {
    u8 p0[0x10];
    f32 f10;
    s32 f14;
    f32 f18;
    s32 f1C;
    u8 p20[4];
    s32 f24;
    s32 f28;
} St_311430;

typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 p21[0x34 - 0x21];
    u16 h34;
    u8 p36[0x68 - 0x36];
    St_311430 *s;
    u8 p6C[0xAA - 0x6C];
    s16 hAA;
} Mb_311430;

typedef struct {
    u8 p0[0x30];
    s32 f30;
    u8 p34[4];
    s32 f38;
} G_311430;

typedef struct {
    u8 p0[0x7C];
    s32 f7C;
} Pt_311430;

typedef struct {
    vu0_v4 v;
    u8 p10[8];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 p1C[4];
    s32 f20;
} Info_311430;

typedef struct {
    u8 p0[0x25C0];
    Mb_311430 *f25C0;
} H_311430;

typedef struct {
    u8 p0[0x20];
    f32 f20;
    u8 p24[4];
    s32 f28;
    s32 f2C;
} T_311430;

extern s32 func_L01_00457458(s32, s32);
extern void func_L01_003119E0(void);
extern void func_003C2880(void *);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_L01_004572B0(void *, s32, void *);
extern char *func_L01_00457480(s32, s32);
extern s32 func_L01_003113E8(s32);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_0044BB30(void *, void *, f32, f32, s32);
extern void func_L01_00312B60(void *, s32, void *, void *, f32);
extern void func_L01_003119F0(void *, void *);
extern s32 func_0038DC20(void *, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern void *func_00382348(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, f32, void *);
extern void func_L01_00446978(void *, void *);
extern void func_L01_00312C88(void *);
extern void func_L01_00404A10_00311430(void *, void *);
extern void func_L01_00311D08(void *);

extern G_311430 *D_L01_001E1730;
extern G_311430 *D_L01_001E1730_00311430;
extern Pt_311430 *D_L01_001E1734_00311430;
extern s32 *D_L01_001E1738;
__asm__(".extern D_L01_001E1730, 4");
__asm__(".extern D_L01_001E1730_00311430, 16");
__asm__(".extern D_L01_001E1734_00311430, 16");
__asm__(".extern D_L01_001E1738, 16");
extern T_311430 D_L01_001E2A40_00311430;
extern Mb_311430 *D_L01_001EEA80_00311430[];
extern u8 D_001A4BE0[];
extern f32 D_L01_001DC6A4;
extern f32 D_L01_001DC6A0;
__asm__(".extern D_L01_001DC6A4, 4");
__asm__(".extern D_L01_001DC6A0, 4");

/* localdecomp:start func_L01_00311430 */
void func_L01_00311430(Mb_311430 *self) {
    St_311430 *s;
    u8 *v;
    u8 *q;
    u8 *ip;
    vu0_v4 vec;
    vu0_v4 d10;
    vu0_v4 vec2;
    vu0_v4 d30;
    Info_311430 info;
    s32 out;
    s32 *p;
    s32 n;
    s32 cnt;
    u16 t;
    s32 i;
    char *r;
    Mb_311430 **tbl;
    Pt_311430 *pp;

    s = self->s;
    if (self->b20 != 0) {
        if (func_L01_00457458(self->hAA, s->f28) == 0) {
            func_L01_003119E0();
            func_003C2880(self);
            return;
        }
    }
    v = (u8 *)self + 0x10;
    func_L01_004CAB30(v, v);
    q = v;
    switch (self->b20) {
    case 0:
        self->b20 = 1;
        s->f10 = 0.0f;
        s->f14 = 0x11;
        s->f18 = 0.8000001f;
        s->f1C = 0x7F;
        s->f24 = 0x6F;
        s->f28 = func_L01_004572B0(self, 0, &out);
        r = func_L01_00457480(self->hAA, s->f28);
        D_L01_001E1730 = (G_311430 *)r;
        D_L01_001E1734_00311430 = (Pt_311430 *)func_L01_003113E8((s32)(r + 0x50));
        D_L01_001E1738 = (s32 *)func_L01_003113E8((s32)D_L01_001E1734_00311430 + 0xA000);
        v = (u8 *)&vec2;
        for (i = 0; i < 0x90; i++) {
            D_L01_001E1738[i] = 0;
        }
        pp = D_L01_001E1734_00311430;
        for (i = 0x13F; i >= 0; i--) {
            pp[i].f7C = 0;
        }
        D_L01_001E1730_00311430->f30 = 0;
        vec = self->pos;
        func_003C5180(q, &d10, 1);
        vec_add_ba(&vec, &self->pos, &d10);
        func_L01_0044BB30(self, &vec, 2.0f, 20.0f, -1);
        func_L01_00312B60(self, 0x11, q, s, 0.20000002f);
        func_L01_003119F0(self, q);
        vec2 = vec;
        vec2.w = 2.0f;
        if (func_0038DC20(v, 100.0f) != -1) {
            D_L01_001E2A40_00311430.f20 = 0.45f;
            D_L01_001E2A40_00311430.f28 = 0x21;
            D_L01_001E2A40_00311430.f2C = 0;
        }
        /* fall through */
    case 1:
        s->f24 -= 5;
        if (s->f24 < 0) {
            s->f24 = 0;
        }
        p = &s->f14;
        s->f10 = s->f10 + s->f18;
        n = func_003D4D00(q, 0, self, 0, (1.0f - (f32)s->f14 / 17.0f) * 8.0f + 0.001f);
        if (n > 0) {
            tbl = D_L01_001EEA80_00311430;
            cnt = n;
            do {
                if ((func_00382348(*tbl) != 0 || ((*tbl)->h34 & 0x4000) != 0)
                    && *tbl != ((H_311430 *)D_001A4BE0)->f25C0
                    && (*tbl)->hAA != 0xA5A) {
                    vec_sub_ab(&d30, &(*tbl)->pos, &self->pos);
                    func_0038CF68(&d30, &d30, 1.0f);
                    ip = (u8 *)&info;
                    func_0038CF68(ip, ip, 1.0f);
                    func_L01_00446760(ip, self, 0x01030000, 1.0f, &d30);
                    info.v = d30;
                    t = 3;
                    info.b19 = t;
                    info.f20 = 1;
                    info.v.w = 5627.925f;
                    info.b18 = 5;
                    t = (*tbl)->hAA;
                    info.h1A = t;
                    func_L01_00446978(*tbl, ip);
                }
                tbl++;
                cnt--;
            } while (cnt != 0);
        }
        if (func_0038CAD0(p) != 0) {
            self->b20 = 2;
            s->f14 = 0x21;
        }
        break;
    case 2:
        s->f10 = s->f10 + s->f18;
        {
            s32 cur = s->f14;
            f32 ratio = (f32)cur / 40.0f;
            if (cur == 0x14) {
                func_L01_003119F0(self, v);
            }
            if (func_0038CAD0(&s->f14) != 0) {
                if (s->f1C != 0) {
                    s->f1C = s->f1C - 1;
                } else {
                    s->f1C = 0;
                    self->b20 = 6;
                }
            } else {
                s->f1C = (s32)(ratio * 127.0f);
            }
        }
        break;
    case 6:
        s->f18 = s->f18 - 0.020000001f;
        if (s->f18 < 0.10000001f) {
            s->f18 = 0.10000001f;
        }
        s->f10 = s->f10 + s->f18;
        if (D_L01_001E1730_00311430->f38 == 0) {
            func_L01_003119E0();
            func_003C2880(self);
            return;
        }
        break;
    }
    D_L01_001DC6A4 = D_L01_001DC6A4 - 0.04f;
    if (D_L01_001DC6A0 < -8.0f) {
        D_L01_001DC6A0 = D_L01_001DC6A0 + 8.0f;
    }
    if (D_L01_001DC6A4 < -8.0f) {
        D_L01_001DC6A4 = D_L01_001DC6A4 + 8.0f;
    }
    func_L01_00312C88(self);
    func_L01_00404A10_00311430((void *)func_L01_00311D08, self);
}
/* localdecomp:end func_L01_00311430 */

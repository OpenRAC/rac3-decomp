#include "common.h"

/* NTSC-U counterpart of func_L01_00311430 (src/levels/shared/L01_00311430.c) */
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
extern s32 func_L01_00454168(s32, s32);
extern void func_L01_003116F0(void);
extern void func_003BD360(void *);
extern void func_L01_004C6EC8(void *, void *);
extern s32 func_L01_00453FC0(void *, s32, void *);
extern char *func_L01_00454190(s32, s32);
extern s32 func_L01_003110F8(s32);
extern void func_003BFC18(void *, void *, s32);
extern void func_L01_004488B8(void *, void *, f32, f32, s32);
extern void func_L01_00312870(void *, s32, void *, void *, f32);
extern void func_L01_00311700(void *, void *);
extern s32 func_003894E8(void *, f32);
extern s32 func_003CF790(void *, s32, void *, void *, f32);
extern s32 func_00388398(void *);
extern void *func_0037E0B8(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, f32, void *);
extern void func_L01_00443840(void *, void *);
extern void func_L01_00312998(void *);
extern void func_L01_004026A0_00311140(void *, void *);
extern void func_L01_00311A18(void *);
extern G_311430 *D_L01_001E17B0_00311140_b;
extern G_311430 *D_L01_001E17B0_00311140;
extern Pt_311430 *D_L01_001E17B4_00311140;
extern s32 *D_L01_001E17B8_00311140;
__asm__(".extern D_L01_001E17B0_00311140_b, 4");
__asm__(".extern D_L01_001E17B0_00311140, 16");
__asm__(".extern D_L01_001E17B4_00311140, 16");
__asm__(".extern D_L01_001E17B8_00311140, 16");
extern T_311430 D_L01_001E2AC0_00311140;
extern Mb_311430 *D_L01_001EEB00_00311140[];
extern u8 D_001A4BE0[];
extern f32 D_L01_001DC6E4;
extern f32 D_L01_001DC6E0;
__asm__(".extern D_L01_001DC6E4, 4");
__asm__(".extern D_L01_001DC6E0, 4");

/* localdecomp:start func_L01_00311140 */
void func_L01_00311140(Mb_311430 *self) {
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
        if (func_L01_00454168(self->hAA, s->f28) == 0) {
            func_L01_003116F0();
            func_003BD360(self);
            return;
        }
    }
    v = (u8 *)self + 0x10;
    func_L01_004C6EC8(v, v);
    q = v;
    switch (self->b20) {
    case 0:
        self->b20 = 1;
        s->f10 = 0.0f;
        s->f14 = 0x14;
        s->f18 = 0.6666667f;
        s->f1C = 0x7F;
        s->f24 = 0x6F;
        s->f28 = func_L01_00453FC0(self, 0, &out);
        r = func_L01_00454190(self->hAA, s->f28);
        D_L01_001E17B0_00311140_b = (G_311430 *)r;
        D_L01_001E17B4_00311140 = (Pt_311430 *)func_L01_003110F8((s32)(r + 0x50));
        D_L01_001E17B8_00311140 = (s32 *)func_L01_003110F8((s32)D_L01_001E17B4_00311140 + 0xA000);
        v = (u8 *)&vec2;
        for (i = 0; i < 0x90; i++) {
            D_L01_001E17B8_00311140[i] = 0;
        }
        pp = D_L01_001E17B4_00311140;
        for (i = 0x13F; i >= 0; i--) {
            pp[i].f7C = 0;
        }
        D_L01_001E17B0_00311140->f30 = 0;
        vec = self->pos;
        func_003BFC18(q, &d10, 1);
        vec_add_ba(&vec, &self->pos, &d10);
        func_L01_004488B8(self, &vec, 2.0f, 20.0f, -1);
        func_L01_00312870(self, 0x14, q, s, 0.16666667f);
        func_L01_00311700(self, q);
        vec2 = vec;
        vec2.w = 2.0f;
        if (func_003894E8(v, 100.0f) != -1) {
            D_L01_001E2AC0_00311140.f20 = 0.45f;
            D_L01_001E2AC0_00311140.f28 = 0x28;
            D_L01_001E2AC0_00311140.f2C = 0;
        }
        /* fall through */
    case 1:
        s->f24 -= 5;
        if (s->f24 < 0) {
            s->f24 = 0;
        }
        p = &s->f14;
        s->f10 = s->f10 + s->f18;
        n = func_003CF790(q, 0, self, 0, (1.0f - (f32)s->f14 / 20.0f) * 8.0f + 0.001f);
        if (n > 0) {
            tbl = D_L01_001EEB00_00311140;
            cnt = n;
            do {
                if ((func_0037E0B8(*tbl) != 0 || ((*tbl)->h34 & 0x4000) != 0)
                    && *tbl != ((H_311430 *)D_001A4BE0)->f25C0
                    && (*tbl)->hAA != 0xA5A) {
                    vec_sub_ab(&d30, &(*tbl)->pos, &self->pos);
                    func_00388830(&d30, &d30, 1.0f);
                    ip = (u8 *)&info;
                    func_00388830(ip, ip, 1.0f);
                    func_L01_00443628(ip, self, 0x01030000, 1.0f, &d30);
                    info.v = d30;
                    t = 3;
                    info.b19 = t;
                    info.f20 = 1;
                    info.v.w = 5627.925f;
                    info.b18 = 5;
                    t = (*tbl)->hAA;
                    info.h1A = t;
                    func_L01_00443840(*tbl, ip);
                }
                tbl++;
                cnt--;
            } while (cnt != 0);
        }
        if (func_00388398(p) != 0) {
            self->b20 = 2;
            s->f14 = 0x28;
        }
        break;
    case 2:
        s->f10 = s->f10 + s->f18;
        {
            s32 cur = s->f14;
            f32 ratio = (f32)cur / 40.0f;
            if (cur == 0x14) {
                func_L01_00311700(self, v);
            }
            if (func_00388398(&s->f14) != 0) {
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
        s->f18 = s->f18 - 0.016666668f;
        if (s->f18 < 0.083333336f) {
            s->f18 = 0.083333336f;
        }
        s->f10 = s->f10 + s->f18;
        if (D_L01_001E17B0_00311140->f38 == 0) {
            func_L01_003116F0();
            func_003BD360(self);
            return;
        }
        break;
    }
    D_L01_001DC6E4 = D_L01_001DC6E4 - 0.04f;
    if (D_L01_001DC6E0 < -8.0f) {
        D_L01_001DC6E0 = D_L01_001DC6E0 + 8.0f;
    }
    if (D_L01_001DC6E4 < -8.0f) {
        D_L01_001DC6E4 = D_L01_001DC6E4 + 8.0f;
    }
    func_L01_00312998(self);
    func_L01_004026A0_00311140((void *)func_L01_00311A18, self);
}
/* localdecomp:end func_L01_00311140 */

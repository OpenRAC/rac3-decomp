#include "common.h"

/* NTSC-U counterpart of func_L03_003993A0 (src/levels/03_starship_phoenix/L03_00399278.c) */
extern void func_L01_00441FB8(u8 *, s32, s32);

/* localdecomp:start func_L03_00397D10 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x40];
    f32 f40;
    f32 f44;
    u8 f48[0x5C - 0x48];
    s32 i5C;
    s32 i60;
    u8 pad64[0x70 - 0x64];
    f32 f70;
    f32 f74;
    s16 h78;
    s16 h7A;
    u8 pad7C[4];
    u8 b80;
    u8 b81;
} S_003993A0;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 b20; u8 pad21[0x47]; S_003993A0 *p68; u8 pad6C[0x95 - 0x6C]; u8 b95; } A_003993A0;
extern void func_L03_00398188(u8 *);
extern void func_003BEC60(f32 *, void *, f32, f32, f32, f32);
extern void func_0039FB08(s32);
extern s32 func_L01_004A72A8(s32, s32, u8 *, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L03_00398650(void *);
extern void func_L03_00398A38(void *);
extern s32 func_003883C8(void *);
extern void func_L03_00398208(void *);
extern s32 func_0037E208(s32, s32);
extern void func_L03_00398858(void *);
extern void func_L01_00402560(void *, u8 *);
extern void func_L03_00398B18(void *);
extern f32 func_00389380(f32, f32);
extern s32 func_L03_003984F8(u8 *, s32);
extern f32 func_00389410(f32);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern f32 func_0037E250(f32, f32);
extern void func_L03_003990A0(void *);

void func_L03_00397D10(u8 *self) {
    A_003993A0 *a = (A_003993A0 *)self;
    S_003993A0 *s;
    func_L03_00398188(self);
    s = a->p68;
    switch (a->b95) {
    case 1:
        break;
    case 2:
        func_003BEC60((f32 *)(self + 0x18), s->f48, s->f44, 0.002222222276031971f, 0.002222222276031971f, 0.13333334028720856f);
        if (*(f32 *)(self + 0x18) <= s->f44) {
            func_0039FB08(s->i5C);
            s->b80 = 0;
            s->h78 = 120;
            s->i60 = func_L01_004A72A8(1, 4, self, 0x18EC);
            func_L01_00441FB8(self, 1, 3);
        }
        break;
    case 3:
        func_L03_00398650(self);
        if (s->h78 < 0 && (s->h78 % 4) == 0) func_L03_00398A38(self);
        if (func_003883C8(&s->h78)) {
            func_L03_00398208(self);
            s->b81 = 0;
            s->h78 = 120;
            s->h7A = (func_0037E208(-3, 3) + 20);
            s->i5C = func_L01_004A72A8(0, 4, self, 0x18EC);
            func_L01_00441FB8(self, 2, 4);
        }
        break;
    case 4: {
        int done = 1;
        func_003883C8(&s->h78);
        if (s->h78 > 0) {
            func_L03_00398858(self);
            done = 0;
        }
        if (*(f32 *)(self + 0x18) < s->f40) {
            func_003BEC60((f32 *)(self + 0x18), s->f48, s->f40, 0.00027777778450399637f, 0.00027777778450399637f, 0.06666667014360428f);
            done = 0;
        }
        if (done) {
            func_0039FB08(s->i60);
            s->i60 = -1;
            func_0039FB08(s->i5C);
            func_L01_00441FB8(self, 0, 1);
        }
        break;
    }
    }
    switch (a->b20) {
    case 0:
        break;
    case 1:
        func_L01_00402560(func_L03_00398B18, self);
        break;
    case 2:
        s->f74 = func_00389380(s->f74, 0.05235988274216652f);
        func_L01_00402560(func_L03_00398B18, self);
        if (func_003883C8(&s->h7A)) {
            func_L03_003984F8(&s->b80, 4);
            if (s->b80 == 15) {
                s->h7A = (func_0037E208(-3, 3) + 20);
                func_L01_00441FB8(self, 3, -1);
            } else {
                s->h7A = (func_0037E208(-3, 3) + 20);
            }
        }
        break;
    case 3:
        s->f74 = func_00389380(s->f74, 0.05235988274216652f);
        func_L01_00402560(func_L03_00398B18, self);
        if (func_003883C8(&s->h7A)) {
            s32 r = func_L03_003984F8(&s->b81, 4);
            if (r != -1) {
                vu0_v4 p;
                vu0_v4 v;
                vu0_v4 w;
                f32 ang = func_00389410(s->f74 + (f32)r * 1.5707964f);
                p = a->pos;
                *(vu0_q *)&w = 0;
                p.z += 1.7f;
                w.x = s->f70 * func_00388978(ang);
                w.y = s->f70 * func_00388960(ang);
                v = w;
                vec_add_ab(&v, &p, &v);
                v.z = func_0037E250(s->f44, p.z);
                func_L03_003990A0(&v);
            }
            if (s->b81 == 15) {
                s->h7A = (func_0037E208(-3, 3) + 30);
                func_L01_00441FB8(self, 4, -1);
            } else {
                s->h7A = (func_0037E208(-3, 3) + 20);
            }
        }
        break;
    case 4:
        func_L01_00402560(func_L03_00398B18, self);
        if (func_003883C8(&s->h7A)) {
            vu0_v4 p;
            p = a->pos;
            p.z += 1.7f;
            func_L03_003990A0(&p);
            func_0039FB08(s->i60);
            s->i60 = -1;
            func_L01_00441FB8(self, 0, -1);
        }
        break;
    }
}
/* localdecomp:end func_L03_00397D10 */

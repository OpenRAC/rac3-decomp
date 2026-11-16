#include "common.h"

/* NTSC-U counterpart of func_L03_003A05D0 (src/levels/03_starship_phoenix/L03_0039FEF0.c) */
#include "vu0.h"
typedef struct {
    u8 pad0[0x44]; u8 b44;
    u8 pad45[0x70 - 0x45]; u8 a70[0xC0];
    f32 f130; f32 f134;
    u8 pad138[0x144 - 0x138]; s16 s144;
    u8 pad146[0x188 - 0x146]; s32 i188;
    u8 pad18C[0x250 - 0x18C]; void *p250;
    u8 pad254[0x268 - 0x254]; s16 s268; s16 s26A; u8 pad26C[4]; u8 a270[0x80];
    u8 a2F0[0x10]; u8 *p300;
    u8 pad304[0x30C - 0x304]; f32 f30C; u8 a310[0x10];
} P_003A05D0;
typedef struct {
    u8 pad0[0x10]; f32 x; f32 y; u8 pad18[0x8]; u8 st;
    u8 pad21[2]; u8 b23;
    u8 pad24[0x60 - 0x24]; u8 b60;
    u8 pad61[0x68 - 0x61]; P_003A05D0 *p;
    u8 pad6C[0xBC - 0x6C]; u8 bBC;
} S_003A05D0;
#include "vu0.h"
extern void func_L03_0032D348_0039EDE8(void *);
f32 func_00388A28(f32, f32);
#include "vu0.h"
extern s32 func_L03_0032D500(void *);
extern s32 func_L03_0032D510(void *, s32);

/* localdecomp:start func_L03_0039EDE8 */
extern void func_L03_0039F410(void *);
extern void func_L03_0039F5B8();
extern void func_L03_0039F970(void *, s32);
extern void func_L03_0039FC00(void *, f32);
extern void func_L03_0039FCE8(void *, void *, void *, s32);
extern void func_L03_0039FE18(void *);
extern void func_L03_0039C408(void *, void *, f32, f32, void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004576E8(void *);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L01_00457708(void *, f32);
extern s32 func_L03_0032CED8(void *, void *);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_L01_00436500(void *);
extern s32 func_L03_0032D498(void *);
extern s16 func_L03_0032D200(void *);
extern void func_L03_0032D348_0039EDE8(void *);
extern s32 func_L03_0032D500(void *);
extern s32 func_L03_0032D510(void *, s32);
extern void func_L01_00402498(void *, void *);
extern void func_L01_0044EB78(void *, void *, s32, s32, f32);
extern s32 func_003883C8(void *);
extern f32 func_00388A28(f32, f32);

void func_L03_0039EDE8(S_003A05D0 *s) {
    P_003A05D0 *p;
    char buf[16];
    f32 f20;
    f32 d;
    u8 *v;
    s32 r;
    s32 t;

    func_L03_0039F410(s);
    func_L03_0039F5B8(s);
    p = s->p;
    switch (s->st) {
    case 2:
        if (func_L01_00452EC8(s)) {
            p->f30C = 1.0f / (f32)p->s268;
        }
        s->b23 = (s32)((1.0f - p->f30C * (f32)p->s268) * 128.0f);
        if (func_003883C8(&p->s268)) {
            s->b23 = 0x80;
            func_L03_0039F970(s, 3);
        }
        if (p->p300 != 0) {
            p->p300[0x23] = s->b23;
        }
        break;
    case 3:
        func_L01_004576E8(s);
        func_L03_0039F970(s, 5);
    case 4:
        if (func_L01_00451078(s, p->a70) & 2) {
            func_L03_0039F970(s, 5);
        }
        break;
    case 5:
        func_L01_004576E8(s);
        if (func_L03_0032CED8(p->p250, s)) {
            if (func_L01_0040C040(&s->x, &p->f130) < 64.0f) {
                func_L03_0039F970(s, 9);
            } else {
                func_L03_0039F970(s, 6);
            }
        } else {
            func_L03_0039F970(s, 0xE);
        }
        break;
    case 6:
        p->i188 &= ~0x10;
        d = func_00388A28(p->f130 - s->x, p->f134 - s->y);
        func_L01_00457708(s, d);
        if (s->b60 & 2) {
            func_L03_0039F970(s, 7);
        }
        break;
    case 7:
        func_L03_0039FC00(s, 3.0f);
        if (p->s144 != 1 || !func_L03_0032CED8(p->p250, s) || func_L01_0040C040(&s->x, &p->f130) < 16.0f) {
            func_L03_0039F970(s, 8);
        }
        break;
    case 8:
        if (s->b60 & 2) {
            if (p->s144 != 1) {
                func_L03_0039F970(s, 5);
            } else if (func_L03_0032CED8(p->p250, s)) {
                if (func_L01_0040C040(&s->x, &p->f130) < 64.0f) {
                    func_L03_0039F970(s, 9);
                } else {
                    func_L03_0039F970(s, 6);
                }
            } else {
                func_L03_0039F970(s, 0xE);
            }
        }
        break;
    case 9:
        func_L03_0039FC00(s, 5.0f);
        if (p->s144 != 1) {
            p->i188 &= ~0x10;
            func_L03_0032D348_0039EDE8(s);
            func_L03_0039F970(s, 5);
        } else if (!func_L03_0032CED8(p->p250, s)) {
            func_L03_0032D348_0039EDE8(s);
            func_L03_0039F970(s, 0xE);
        } else if (func_L01_0040C040(&s->x, &p->f130) < 64.0f) {
            if (p->s26A == -1) {
                p->s26A = func_L03_0032D200(s);
            }
            if (func_L03_0032D498(s)) {
                func_L03_0039F970(s, 0xA);
            }
        } else {
            p->i188 &= ~0x10;
            func_L03_0032D348_0039EDE8(s);
            func_L03_0039F970(s, 5);
        }
        break;
    case 10: {
        u8 *v8 = p->a2F0;
        func_L03_0039FC00(s, 5.0f);
        r = func_L01_00452EC8(s);
        func_L03_0039FCE8(s, v8, 0, r & 0xFF);
        func_L01_00402498(func_L03_0039FE18, s);
        if (func_003883C8(p->a310)) {
            func_L03_0039F970(s, 0xB);
        }
        break;
    }
    case 11:
        func_L03_0039FC00(s, 5.0f);
        if (func_L01_0044AF40(s, 15.0f) && p->p300 != 0) {
            u8 *v9 = p->a2F0;
            s32 t9;
            func_L03_0039FCE8(s, v9, buf, 0);
            f20 = p->b44;
            t9 = func_L03_0032D500(s);
            r = func_L03_0032D510(s, 2);
            func_L03_0039C408(buf, v9, 0.10000000894069672f, f20, s, t9, r);
        } else {
            if (func_L01_00436500(s) < 15.0f) {
                func_L03_0039FCE8(s, p->a2F0, 0, 0);
                func_L01_00402498(func_L03_0039FE18, s);
            }
        }
        if (s->b60 & 2) {
            func_L03_0032D348_0039EDE8(s);
            func_L03_0039F970(s, 0xC);
        }
        break;
    case 12:
        func_L03_0039FC00(s, 5.0f);
        switch (s->bBC) {
        case 0:
            break;
        case 1:
            func_L03_0039F970(s, 0xD);
            break;
        case 2:
        case -1:
            func_L03_0039F970(s, 5);
            break;
        }
        break;
    case 13:
        if (s->b60 & 2) {
            func_L03_0039F970(s, 5);
        }
        break;
    case 14:
        func_L03_0039FC00(s, 8.0f);
        if (p->s144 != 1) {
            p->i188 &= ~0x10;
            func_L03_0039F970(s, 5);
        } else if (func_L03_0032CED8(p->p250, s)) {
            p->i188 &= ~0x10;
            func_L03_0039F970(s, 6);
        }
        break;
    case 1:
        break;
    }
    func_L01_0044EB78(s, p->a270, 1, 1, 1.5f);
}
/* localdecomp:end func_L03_0039EDE8 */

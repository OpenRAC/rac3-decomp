#include "common.h"

/* localdecomp:start func_L03_0039DBE8 */
typedef struct S_0039F3C0 S_0039F3C0;
typedef struct P_0039F3C0 P_0039F3C0;
struct P_0039F3C0 {
    u8 pad0[0x70]; u8 a70[0xC0]; f32 f130; f32 f134;
    u8 pad138[0x144 - 0x138]; s16 s144;
    u8 pad146[0x188 - 0x146]; s32 i188;
    u8 pad18C[0x250 - 0x18C]; void *p250;
    u8 pad254[0x260 - 0x254]; f32 f260;
    u8 pad264[0x268 - 0x264]; s16 s268; s16 s26A;
    u8 pad26C[0x270 - 0x26C]; u8 a270[0x80];
    u8 a2F0[0x150]; u8 a440[0x10];
    S_0039F3C0 *p450; u8 pad454[0x458 - 0x454]; s16 s458; u8 b45A; u8 pad45B; f32 f45C;
};
struct S_0039F3C0 {
    u8 pad0[0x10]; f32 x; f32 y;
    u8 pad18[0x20 - 0x18]; u8 st; u8 pad21[2]; u8 b23;
    u8 pad24[0x60 - 0x24]; u8 b60;
    u8 pad61[0x68 - 0x61]; P_0039F3C0 *p;
};
extern void func_L03_0039E188(void *);
extern void func_L03_0039E330(void *);
void func_L03_0039E708(void *, s32);
void func_L03_0039EAC8(void *, f32);
s32 func_L03_0039EBB0(void *);
s32 func_L01_00452EC8(void *);
s32 func_003883C8(void *);
void func_L01_004576E8(void *);
s32 func_L01_00451078(void *, void *);
s32 func_L03_0032CED8(void *, void *);
f32 func_L01_0040C040(void *, void *);
f32 func_00388A28(f32, f32);
s32 func_L01_00457708(void *, f32);
void func_L03_0032D348_0039DBE8(void *);
s32 func_L03_0032D200(void *);
s32 func_L03_0032D498(void *);
s32 func_L01_0044AF40(void *, f32);
void func_L01_0044B1E0(void *, s32);
s32 func_L01_00457440(void *, void *);
void func_L01_0044B4B8(void *);
s32 func_0037E1D8(s32);
void func_L01_0044EB78(void *, void *, s32, s32, f32);
extern void func_L01_004A72A8(s32,s32,void *,s32);

void func_L03_0039DBE8(S_0039F3C0 *s) {
    P_0039F3C0 *p;
    s32 v;
    s32 w;
    s32 n;
    s32 m;
    func_L03_0039E188(s);
    func_L03_0039E330(s);
    p = s->p;
    switch (s->st) {
    case 1:
        break;
    case 2:
        if (func_L01_00452EC8(s)) {
            p->f45C = 1.0f / p->s268;
        }
        s->b23 = (1.0f - p->f45C * p->s268) * 128.0f;
        if (func_003883C8(&p->s268)) {
            s->b23 = 0x80;
            func_L03_0039E708(s, 3);
        }
        if (p->p450 != 0) {
            p->p450->b23 = s->b23;
        }
        break;
    case 3:
        func_L01_004576E8(s);
        func_L03_0039E708(s, 5);
    case 4:
        if ((func_L01_00451078(s, p->a70) & 2) == 0) {
            break;
        }
        goto L884;
    case 5:
        func_L01_004576E8(s);
        if (p->s144 == 1) {
            if (func_L03_0032CED8(p->p250, s)) {
                if (func_L01_0040C040(&s->x, &p->f130) < 36.0f) {
                    goto L650;
                }
                goto L660;
            }
            goto L6C8;
        }
        break;
    case 6:
        func_L01_00457708(s, func_00388A28(p->f130 - s->x, p->f134 - s->y));
        if (s->b60 & 2) {
            func_L03_0039E708(s, 7);
        }
        break;
    case 7:
        func_L03_0039EAC8(s, 2.0f);
        if (p->s144 == 1) {
            if (func_L03_0032CED8(p->p250, s)) {
                if (!(func_L01_0040C040(&s->x, &p->f130) < 6.25f)) {
                    break;
                }
            }
        }
        func_L03_0039E708(s, 8);
        break;
    case 8:
        if (!(s->b60 & 2)) {
            break;
        }
        if (p->s144 != 1) {
            goto L884;
        }
        if (func_L03_0032CED8(p->p250, s)) {
            if (!(func_L01_0040C040(&s->x, &p->f130) < 36.0f)) {
                goto L660;
            }
            p->s458 = 0;
L650:
            func_L03_0039E708(s, 9);
            break;
L660:
            func_L03_0039E708(s, 6);
            break;
        }
        goto L6C8;
    case 9:
        func_L03_0039EAC8(s, 3.5f);
        if (p->s144 != 1) {
            p->i188 &= ~0x10;
            func_L03_0032D348_0039DBE8(s);
            goto L884;
        }
        if (func_L03_0032CED8(p->p250, s) == 0) {
            func_L03_0032D348_0039DBE8(s);
L6C8:
            func_L03_0039E708(s, 14);
            break;
        }
        if (func_003883C8(&p->s458)) {
            if (p->s26A == -1) {
                p->s26A = func_L03_0032D200(s);
            }
            if (func_L03_0032D498(s)) {
                p->i188 &= ~0x10;
                func_L03_0039E708(s, 10);
            }
        }
        break;
    case 10:
        func_L01_00457708(s, func_00388A28(p->f130 - s->x, p->f134 - s->y));
        if (func_L01_0044AF40(s, 17.0f)) {
            func_L01_004A72A8(6, 0, s, 0x197B);
        }
        if (s->b60 & 2) {
            func_L03_0039E708(s, 11);
        }
        break;
    case 11:
        func_L01_0044B1E0(p->a2F0, 0);
        v = func_L01_00457440(s, p->a440);
        p->f260 = func_00388A28(s->x - p->f130, s->y - p->f134);
        if (!(v & 0x80)) {
            if (func_L03_0039EBB0(s) == 0) {
                break;
            }
        }
        p->i188 &= ~0x10;
        func_L01_0044B4B8(p->a2F0);
        func_L03_0039E708(s, 12);
        break;
    case 12:
        func_L01_004576E8(s);
        p->f260 = func_00388A28(s->x - p->f130, s->y - p->f134);
        if (s->b60 & 2) {
            p->s458 = func_0037E1D8(30) + 60;
            func_L03_0032D348_0039DBE8(s);
            if (p->b45A) {
                func_L03_0039E708(s, 13);
                break;
            }
L884:
            func_L03_0039E708(s, 5);
        }
        break;
    case 13:
        func_L03_0039EAC8(s, 3.5f);
        if (s->b60 & 2) {
            p->i188 &= ~0x10;
            func_L03_0039E708(s, 5);
        }
        break;
    case 14:
        func_L03_0039EAC8(s, 5.0f);
        if (p->s144 != 1) {
            p->i188 &= ~0x10;
            func_L03_0039E708(s, 5);
            break;
        }
        if (func_L03_0032CED8(p->p250, s)) {
            p->i188 &= ~0x10;
            func_L03_0039E708(s, 6);
        }
        break;
    }
    func_L01_0044EB78(s, p->a270, 1, 1, 1.5f);
}
/* localdecomp:end func_L03_0039DBE8 */

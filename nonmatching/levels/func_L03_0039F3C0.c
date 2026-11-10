/* near miss (level 3, Starship Phoenix): check.py says MATCH with the file's @ps2as and its context, but the full build rejects it: the jump table's entry +0x2C is 0x0039F4C0 where the level has 0x0039F4CC (one case block lands three instructions early, the case 3 into case 4 fall-through block); check.py does not compare the table, and the file's C jump tables must also be adjacent (func_L03_003A1158 and func_L03_003A17D8 are still assembly between them); the shared tails written out per case with four gotos left (FEF0(s,5/9/6/14)) */
#include "common.h"

/* localdecomp:start func_L03_0039F3C0 */
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
void func_L03_0039F960();
void func_L03_0039FB18();
void func_L03_0039FEF0(void *, s32);
void func_L03_003A02B0(void *, f32);
s32 func_L03_003A0398(void *);
s32 func_L01_004561B8(void *);
s32 func_0038CB00(void *);
void func_L01_0045A9F0(void *);
s32 func_L01_00454370(void *, void *);
s32 func_L03_0032D598(void *, void *);
f32 func_L01_0040E570(void *, void *);
f32 func_0038D160(f32, f32);
s32 func_L01_0045AA10(void *, f32);
void func_L03_0032DA08(void *);
s32 func_L03_0032D8C0(void *);
s32 func_L03_0032DB58(void *);
s32 func_L01_0044E1B8(void *, f32);
void func_L01_0044E468(void *, s32);
s32 func_L01_0045A748(void *, void *);
void func_L01_0044E740(void *);
s32 func_00382468(s32);
void func_L01_00451DF8(void *, void *, s32, s32, f32);

void func_L03_0039F3C0(S_0039F3C0 *s) {
    P_0039F3C0 *p;
    s32 v;
    s32 w;
    s32 n;
    s32 m;
    func_L03_0039F960(s);
    func_L03_0039FB18(s);
    p = s->p;
    switch (s->st) {
    case 1:
        break;
    case 2:
        if (func_L01_004561B8(s)) {
            p->f45C = 1.0f / p->s268;
        }
        s->b23 = (1.0f - p->f45C * p->s268) * 128.0f;
        if (func_0038CB00(&p->s268)) {
            s->b23 = 0x80;
            func_L03_0039FEF0(s, 3);
        }
        if (p->p450 != 0) {
            p->p450->b23 = s->b23;
        }
        break;
    case 3:
        func_L01_0045A9F0(s);
    case 4:
        func_L03_0039FEF0(s, 5);
        if ((func_L01_00454370(s, p->a70) & 2) == 0) {
            break;
        }
        goto L884;
    case 5:
        func_L01_0045A9F0(s);
        if (p->s144 == 1) {
            if (func_L03_0032D598(p->p250, s)) {
                if (func_L01_0040E570(&s->x, &p->f130) < 36.0f) {
                    goto L650;
                }
                goto L660;
            }
            goto L6C8;
        }
        break;
    case 6:
        func_L01_0045AA10(s, func_0038D160(p->f130 - s->x, p->f134 - s->y));
        if (s->b60 & 2) {
            func_L03_0039FEF0(s, 7);
        }
        break;
    case 7:
        func_L03_003A02B0(s, 2.0f);
        if (p->s144 == 1) {
            if (func_L03_0032D598(p->p250, s)) {
                if (!(func_L01_0040E570(&s->x, &p->f130) < 6.25f)) {
                    break;
                }
            }
        }
        func_L03_0039FEF0(s, 8);
        break;
    case 8:
        if (!(s->b60 & 2)) {
            break;
        }
        if (p->s144 != 1) {
            goto L884;
        }
        if (func_L03_0032D598(p->p250, s)) {
            if (!(func_L01_0040E570(&s->x, &p->f130) < 36.0f)) {
                goto L660;
            }
            p->s458 = 0;
L650:
            func_L03_0039FEF0(s, 9);
            break;
L660:
            func_L03_0039FEF0(s, 6);
            break;
        }
        goto L6C8;
    case 9:
        func_L03_003A02B0(s, 3.5f);
        if (p->s144 != 1) {
            p->i188 &= ~0x10;
            func_L03_0032DA08(s);
            goto L884;
        }
        if (func_L03_0032D598(p->p250, s) == 0) {
            func_L03_0032DA08(s);
L6C8:
            func_L03_0039FEF0(s, 14);
            break;
        }
        if (func_0038CB00(&p->s458)) {
            if (p->s26A == -1) {
                p->s26A = func_L03_0032D8C0(s);
            }
            if (func_L03_0032DB58(s)) {
                p->i188 &= ~0x10;
                func_L03_0039FEF0(s, 10);
            }
        }
        break;
    case 10:
        func_L01_0045AA10(s, func_0038D160(p->f130 - s->x, p->f134 - s->y));
        if (func_L01_0044E1B8(s, 17.0f)) {
            func_L01_004AAC98(6, 0, (s32)s, 0x197B);
        }
        if (s->b60 & 2) {
            func_L03_0039FEF0(s, 11);
        }
        break;
    case 11:
        func_L01_0044E468(p->a2F0, 0);
        v = func_L01_0045A748(s, p->a440);
        p->f260 = func_0038D160(s->x - p->f130, s->y - p->f134);
        if (!(v & 0x80)) {
            if (func_L03_003A0398(s) == 0) {
                break;
            }
        }
        p->i188 &= ~0x10;
        func_L01_0044E740(p->a2F0);
        func_L03_0039FEF0(s, 12);
        break;
    case 12:
        func_L01_0045A9F0(s);
        p->f260 = func_0038D160(s->x - p->f130, s->y - p->f134);
        if (s->b60 & 2) {
            p->s458 = func_00382468(25) + 50;
            func_L03_0032DA08(s);
            if (p->b45A) {
                func_L03_0039FEF0(s, 13);
                break;
            }
L884:
            func_L03_0039FEF0(s, 5);
        }
        break;
    case 13:
        func_L03_003A02B0(s, 3.5f);
        if (s->b60 & 2) {
            p->i188 &= ~0x10;
            func_L03_0039FEF0(s, 5);
        }
        break;
    case 14:
        func_L03_003A02B0(s, 5.0f);
        if (p->s144 != 1) {
            p->i188 &= ~0x10;
            func_L03_0039FEF0(s, 5);
            break;
        }
        if (func_L03_0032D598(p->p250, s)) {
            p->i188 &= ~0x10;
            func_L03_0039FEF0(s, 6);
        }
        break;
    }
    func_L01_00451DF8(s, p->a270, 1, 1, 1.5f);
}
/* localdecomp:end func_L03_0039F3C0 */

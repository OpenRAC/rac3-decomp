/* near miss (level 3, Starship Phoenix): 192 differences, mostly shifted branch targets (needs no flag: the file has @ps2as): the prologue, saved registers and cases 2-8, 10-14 match in instruction order (case 1 empty for the table range, case 3 falling into case 4, a goto for the shared andi 2 test, switch(bBC) in case 12); the blocker is case 9: retail keeps two copies of `i188 &= ~0x10; func_L03_0032DA08(s); b` (one on the h144 != 1 fall-through, one after a bc1f) and gcc cross-jumps them into one, so the C is 8 instructions short and every later target shifts by 0x20; explicit if/else, goto reorder, temps and an inline call tried; in cases 6 and 8 retail uses $v1 for the lbu 0x60 where the C uses $v0 */
#include "common.h"

/* localdecomp:start func_L03_003A05D0 */
typedef struct {
    u8 pad0[0x30]; f32 f30;
    u8 pad34[0x44 - 0x34]; u8 b44;
    u8 pad45[0x70 - 0x45];
    u8 pad70[0xC0];
    f32 f130; f32 f134;
    u8 pad138[0x144 - 0x138]; s16 h144;
    u8 pad146[0x188 - 0x146]; s32 i188;
    u8 pad18C[0x250 - 0x18C]; s32 i250;
    u8 pad254[0x268 - 0x254]; s16 h268; s16 h26A;
    u8 pad26C[0x270 - 0x26C]; u8 a270[0x80];
    u8 pad2F0[0x300 - 0x2F0]; u8 *p300;
    u8 pad304[0x30C - 0x304]; f32 f30C;
    u8 a310[4];
} P_003A05D0;
typedef struct {
    u8 pad0[0x10]; f32 x; f32 y; u8 pad18[0x8]; u8 st; u8 pad21[2]; u8 b23;
    u8 pad24[0x60 - 0x24]; u8 b60; u8 pad61[0x68 - 0x61]; P_003A05D0 *p;
    u8 pad6C[0xBC - 0x6C]; u8 bBC;
} S_003A05D0;
void func_L03_003A0BF8(void *);
void func_L03_003A0DA0(void *);
s32 func_L01_004561B8(void *);
s32 func_0038CB00(void *);
void func_L03_003A1158(void *, s32);
void func_L01_0045A9F0(void *);
s32 func_L01_00454370(void *, void *);
s32 func_L03_0032D598(s32, void *);
f32 func_L01_0040E570(void *, void *);
f32 func_0038D160(f32, f32);
void func_L01_0045AA10(void *, f32);
void func_L03_003A13E8(void *, f32);
void func_L03_0032DA08(void *);
s32 func_L03_0032D8C0(void *);
s32 func_L03_0032DB58(void *);
void func_L03_003A14D0(void *, void *, void *, s32);
void func_L01_00404808(void *, void *);
void func_L03_003A1600(void *);
s32 func_L01_0044E1B8(void *, f32);
s32 func_L03_0032DBC0_003A05D0();
s32 func_L03_0032DBD0_003A05D0();
void func_L03_0039DB68(void *, void *, void *, s32, s32, f32, f32);
f32 func_L01_004395E0(void *);
void func_L01_00451DF8(void *, f32, void *, s32, s32);

void func_L03_003A05D0(S_003A05D0 *s) {
    P_003A05D0 *p;
    char buf[0x10];
    f32 f;
    f32 d;
    s32 r;
    s32 m;

    func_L03_003A0BF8(s);
    func_L03_003A0DA0(s);
    p = s->p;
    switch (s->st) {
    case 1:
        break;
    case 2:
        if (func_L01_004561B8(s)) {
            p->f30C = 1.0f / p->h268;
        }
        s->b23 = (1.0f - p->f30C * p->h268) * 128.0f;
        if (func_0038CB00(&p->h268)) {
            s->b23 = 0x80;
            func_L03_003A1158(s, 3);
        }
        if (p->p300 != 0) {
            p->p300[0x23] = s->b23;
        }
        break;
    case 3:
        func_L01_0045A9F0(s);
        func_L03_003A1158(s, 5);
    case 4:
        m = func_L01_00454370(s, p->pad70) & 2;
        goto L0B38;
    case 5:
        func_L01_0045A9F0(s);
        if (func_L03_0032D598(p->i250, s) == 0) goto L08CC;
        if (func_L01_0040E570(&s->x, &p->f130) < 64.0f) goto L0854;
        goto L0864;
    case 6:
        p->i188 &= ~0x10;
        f = func_0038D160(p->f130 - s->x, p->f134 - s->y);
        func_L01_0045AA10(s, f);
        if ((s->b60 & 2) != 0) {
            func_L03_003A1158(s, 7);
        }
        break;
    case 7:
        func_L03_003A13E8(s, 3.0f);
        if (p->h144 != 1 || func_L03_0032D598(p->i250, s) == 0 || func_L01_0040E570(&s->x, &p->f130) < 16.0f) {
            func_L03_003A1158(s, 8);
        }
        break;
    case 8:
        if ((s->b60 & 2) != 0) {
            if (p->h144 != 1) goto L0B40;
            if (func_L03_0032D598(p->i250, s) == 0) goto L08CC;
            if (func_L01_0040E570(&s->x, &p->f130) < 64.0f) {
L0854:
                func_L03_003A1158(s, 9);
            } else {
L0864:
                func_L03_003A1158(s, 6);
            }
        }
        break;
    case 9:
        func_L03_003A13E8(s, 5.0f);
        if (p->h144 == 1) goto L08B0;
        p->i188 &= ~0x10;
        func_L03_0032DA08(s);
        func_L03_003A1158(s, 5);
        break;
L08B0:
        if (func_L03_0032D598(p->i250, s) == 0) {
            func_L03_0032DA08(s);
L08CC:
            func_L03_003A1158(s, 14);
            break;
        }
        if (func_L01_0040E570(&s->x, &p->f130) < 64.0f) {
            if (p->h26A == -1) {
                p->h26A = func_L03_0032D8C0(s);
            }
            if (func_L03_0032DB58(s) != 0) {
                func_L03_003A1158(s, 10);
            }
            break;
        }
        p->i188 &= ~0x10;
        func_L03_0032DA08(s);
        func_L03_003A1158(s, 5);
        break;
    case 10: {
        u8 *q;
        func_L03_003A13E8(s, 5.0f);
        q = (u8 *)p + 0x2F0;
        r = func_L01_004561B8(s);
        func_L03_003A14D0(s, q, 0, r & 0xFF);
        func_L01_00404808(func_L03_003A1600, s);
        if (func_0038CB00(p->a310) != 0) {
            func_L03_003A1158(s, 11);
        }
        break;
    }
    case 11: {
        u8 *q;
        func_L03_003A13E8(s, 5.0f);
        if (func_L01_0044E1B8(s, 15.0f) != 0 && p->p300 != 0) {
            q = (u8 *)p + 0x2F0;
            func_L03_003A14D0(s, q, buf, 0);
            f = p->b44;
            r = func_L03_0032DBC0_003A05D0(s);
            func_L03_0039DB68(buf, q, s, r, func_L03_0032DBD0_003A05D0(s, 2), 0.12f, f);
        } else {
            if (func_L01_004395E0(s) < 15.0f) {
                func_L03_003A14D0(s, (u8 *)p + 0x2F0, 0, 0);
                func_L01_00404808(func_L03_003A1600, s);
            }
        }
        if ((s->b60 & 2) != 0) {
            func_L03_0032DA08(s);
            func_L03_003A1158(s, 12);
        }
        break;
    }
    case 12:
        func_L03_003A13E8(s, 5.0f);
        switch (s->bBC) {
        case 0:
            break;
        case 1:
            func_L03_003A1158(s, 13);
            break;
        case 2:
        case -1:
            goto L0B40;
        }
        break;
    case 13:
        m = s->b60 & 2;
L0B38:
        if (m != 0) {
L0B40:
            func_L03_003A1158(s, 5);
        }
        break;
    case 14:
        func_L03_003A13E8(s, 8.0f);
        if (p->h144 != 1) {
            p->i188 &= ~0x10;
            func_L03_003A1158(s, 5);
        } else if (func_L03_0032D598(p->i250, s) != 0) {
            p->i188 &= ~0x10;
            func_L03_003A1158(s, 6);
        }
        break;
    }
    func_L01_00451DF8(s, 1.5f, p->a270, 1, 1);
}
/* localdecomp:end func_L03_003A05D0 */

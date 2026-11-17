#include "common.h"

/* localdecomp:start func_L39_00622450 */
typedef struct {
    u8 pad0[0x10];
    u8 b10;
    u8 pad11;
    u8 b12;
    u8 pad13[0x1C - 0x13];
    f32 *f1C[1];
} Anim_00622450;

typedef struct {
    u8 pad0[0x48];
    Anim_00622450 *anim[1];
} Set_00622450;

typedef struct {
    u8 pad0[0x24];
    Set_00622450 *p24;
    u8 pad28[0x40 - 0x28];
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    f32 f44;
    u8 pad48[0x58 - 0x48];
    f32 *p58;
    f32 *p5C;
    u8 pad60[0x6C - 0x60];
    u8 b6C;
    u8 b6D;
    u8 b6E;
    u8 pad6F[0xAA - 0x6F];
    s16 hAA;
} Act_00622450;

typedef struct {
    u8 pad0[0x610];
    f32 f610;
    f32 f614;
    s32 w618;
    s32 w61C;
    s32 w620;
    s32 w624;
    f32 f628;
    f32 f62C;
    s32 w630;
    s32 w634;
    s32 w638;
    u8 pad63C[0x2524 - 0x63C];
    Act_00622450 *a2524;
} St_00622450;

extern f32 D_L39_0047A718[][25];
extern const f32 D_00246034 __attribute__((section(".data")));
extern u8 D_001FE020[];
extern f32 func_L01_004395E0(void *);
extern void func_L39_0062B718(void *);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005F3088(s32);

/* from rac1-decomp's advance_hero_animation */
void func_L39_00622450(St_00622450 *s) {
    Act_00622450 *a = s->a2524;
    u8 oldIdx;
    f32 old;
    s32 same;
    f32 delta;
    s32 i;
    s32 pOld, pNew;
    s32 ev;
    f32 prev;

    s->w618 &= ~3;
    oldIdx = a->b40;
    old = a->f44;
    same = (a->b42 == a->b43);
    if (a->b42 == a->b43) {
        a->f44 = old + s->f610 * (s->f614 * 1.2f);
    } else if (s->w620 >= 0) {
        a->f44 = D_L39_0047A718[s->w620][s->w624++];
    } else {
        a->f44 = old + s->f614 * 1.2f;
    }
    if (a->f44 > 0.99f && a->f44 < 1.01f) {
        a->f44 = 1.0f;
    }
    if (a->f44 > -0.01f && a->f44 < 0.01f) {
        a->f44 = 0.0f;
    }
    delta = a->f44 - old;
    while (a->f44 >= 1.0f) {
        if (a->b42 != a->b43) {
            a->b42 = a->b43;
            a->b6E = a->p24->anim[a->b42]->b12;
        }
        s->w620 = -1;
        s->w618 |= 1;
        a->b40 = a->b41;
        a->p58 = a->p5C;
        a->b41++;
        if (s->w638 != 0) {
            s->w638 = 0;
            s->f614 = D_00246034;
            a->f44 = s->w638;
            a->b41 = s->w634;
            a->p5C = a->p24->anim[a->b43]->f1C[a->b41];
            func_L39_0062B718(s);
        } else {
            if (s->w630 != -1 && s->w634 < a->b41) {
                s->f614 = 0.33333334f;
                a->f44 = 0.0f;
                a->b41 = s->w630;
                a->p5C = a->p24->anim[a->b43]->f1C[a->b41];
            } else {
                if (a->b41 >= a->p24->anim[a->b43]->b10) {
                    a->b41 = 0;
                    s->w618 |= 2;
                }
                a->p5C = a->p24->anim[a->b43]->f1C[a->b41];
                a->f44 -= 1.0f;
                a->f44 /= s->f614;
                s->f614 = *a->p58;
                a->f44 *= s->f614;
            }
        }
    }
    if (same && a->b6E != 0) {
        Anim_00622450 *q = a->p24->anim[a->b42];
        s32 *ep = (s32 *)&q->f1C[q->b10];
        pNew = (a->b40 << 4) + (s32)(a->f44 * 16.0f);
        pOld = (oldIdx << 4) + (s32)(old * 16.0f);
        for (i = 0; i < q->b12; i++, ep++) {
            ev = *ep;
            if (pOld < (ev >> 16) && !(pNew < (ev >> 16))) {
                if (a->b42 != a->b43 || a->b42 != 0x28) {
                    u16 id = ev;
                    if (id - 0x25 < 3U && a->hAA != 0x171C) id = 0;
                    func_L39_005F33E0(id, 0, a);
                }
                break;
            }
        }
    }
    if (a->b6D != 0xFF) {
        u8 *slot = D_001FE020 + (a->b6D << 7);
        if (*(void **)(slot + 0xDC) != a) {
            a->b6D = 0xFF;
        } else if (*(s16 *)(slot + 0xCA) != a->b6C) {
            func_L39_005F3088(a->b6D);
            a->b6D = 0xFF;
        }
    } else if (a->b6C != 0xFF) {
        a->b6D = func_L39_005F33E0(a->b6C, 4, a);
    }
    prev = s->f628;
    {
        f32 d = func_L01_004395E0(a);
        s->f628 = d;
        if (prev <= d) {
            s->f62C = d - prev;
        } else {
            s->f62C = delta;
        }
    }
    s->w61C = (a->b42 != a->b43);
}
/* localdecomp:end func_L39_00622450 */

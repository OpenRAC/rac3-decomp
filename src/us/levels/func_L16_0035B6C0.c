#include "common.h"

/* NTSC-U counterpart of func_L16_0035C1C0 (src/levels/16_kerwan/L16_0035C1C0.c) */
/* localdecomp:start func_L16_0035B6C0 */
typedef int TI_0035C1C0 __attribute__((mode(TI)));

typedef struct V_0035C1C0 {
    s32 hour;
    s32 sec;
    s32 min;
    s32 timer;
    struct M_0035C1C0 *minHand;
    struct M_0035C1C0 *hourHand;
    s32 sound;
    s32 pad1C;
    s32 chimes;
    s32 i24;
    s32 i28;
} V_0035C1C0;

typedef struct C_0035C1C0 {
    u8 pad0[0x10];
    s32 i10;
    u8 pad14[0x30];
    u16 h44;
} C_0035C1C0;

typedef struct Q_0035C1C0 {
    u8 pad0[0x38];
    s32 i38;
} Q_0035C1C0;

typedef struct M_0035C1C0 {
    u8 pad0[0x10];
    TI_0035C1C0 q10;
    u8 b20;
    u8 pad21[3];
    C_0035C1C0 *p24;
    u8 pad28[8];
    u8 b30;
    u8 b31;
    u16 h32;
    u16 h34;
    u8 pad36[2];
    long d38;
    u8 pad40[0x28];
    void *p68;
    u8 pad6C[0x2A];
    u16 h96;
    s32 i98;
    u8 pad9C[0x24];
    TI_0035C1C0 qC0;
    u8 padD0[0x20];
    union {
        TI_0035C1C0 q;
        f32 f[4];
    } rF0;
} M_0035C1C0;

extern u8 *D_L16_001E015C_0035B6C0;
extern void func_0012BE28(void *);
extern void func_0013AD58(void *);
extern M_0035C1C0 *func_003BCFB0(s32, s32);
extern void func_00388BD0(void *, void *);
extern f32 func_L01_0040CFE8(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_003C26C8(void *);
extern s32 func_00388398(void *);
extern s32 func_L01_004A6D20(void *, s32);
extern s32 func_L01_004A73F8(s32, s32, void *, s32);
extern void func_L01_004A6DF8(void *, s32);

void func_L16_0035B6C0(M_0035C1C0 *m) {
    V_0035C1C0 *p = m->p68;
    u8 clock[8];
    M_0035C1C0 *o;
    f32 hf;
    s32 h;
    s32 sec;
    s32 min;
    s32 hr;
    s32 k;
    f32 hh;

    if (m->b20 == 0) {
        m->h96 = 0;
        m->b20 = 1;
        m->b30 = 0xFF;
        m->h32 = 0x320;
        p->timer = 0;
        p->chimes = 0;
        func_0012BE28(clock);
        func_0013AD58(clock);
        p->minHand = func_003BCFB0(0xE9F, 0x80);
        if (p->minHand != 0) {
            p->minHand->b30 = 0xFF;
            p->minHand->h32 = 0x320;
            p->minHand->b31 = 1;
            p->minHand->b20 = 0;
            p->minHand->d38 = m->d38;
            p->minHand->q10 = m->q10;
            p->minHand->rF0.q = m->rF0.q;
            func_00388BD0(&p->minHand->qC0, &p->minHand->rF0);
        }
        p->hourHand = func_003BCFB0(0xEA0, 0x80);
        if (p->hourHand != 0) {
            p->hourHand->b30 = 0xFF;
            p->hourHand->h32 = 0x320;
            p->hourHand->b31 = 1;
            p->hourHand->b20 = 0;
            p->hourHand->d38 = m->d38;
            p->hourHand->q10 = m->q10;
            p->hourHand->rF0.q = m->rF0.q;
            func_00388BD0(&p->hourHand->qC0, &p->hourHand->rF0);
        }
        o = func_003BCFB0(0xEA1, 0x80);
        if (o != 0) {
            o->b30 = 0xFF;
            o->h32 = 0x320;
            o->b31 = 1;
            o->b20 = 0;
            o->d38 = m->d38;
            o->q10 = m->q10;
            o->rF0.q = m->rF0.q;
            func_00388BD0(&o->qC0, &p->hourHand->rF0);
        }
        p->hour = clock[3];
        p->min = clock[2];
        p->sec = clock[1];
        sec = p->sec / 16 * 10 + (s32)func_L01_0040CFE8((f32)p->sec, 16.0f);
        min = p->min / 16 * 10 + (s32)func_L01_0040CFE8((f32)p->min, 16.0f);
        hr = p->hour / 16 * 10 + (s32)func_L01_0040CFE8((f32)p->hour, 16.0f);
        p->min = min;
        p->sec = sec;
        p->hour = hr;
    }

    if (m->b20 == 1 && m->h96 == 60) {
        p->sec++;
        if (p->sec >= 60) {
            p->sec = 0;
            p->min++;
        }
        if (p->min >= 60) {
            p->min = 0;
            p->hour++;
        }
        if (p->hour >= 24) {
            p->hour = 0;
        }
        hf = (f32)p->hour;
        h = (s32)hf;
        if (hf > 12.0f) {
            hf -= 12.0f;
        }
        k = (s32)hf;
        if (k == 0 || k == 2 || k == 4 || k == 6 || k == 8 || k == 10 || k == 12) {
            if (p->i28 != -1) {
                u8 *b = D_L16_001E015C_0035B6C0 + (p->i28 << 8);
                M_0035C1C0 *e = (M_0035C1C0 *)b;
                e->h34 &= 0xFFBE;
                e->h34 |= e->p24->h44 & 0x1000;
                e->i98 = e->p24->i10;
                e->h34 &= ~2;
            }
        } else {
            if (p->i28 != -1) {
                M_0035C1C0 *e = (M_0035C1C0 *)(D_L16_001E015C_0035B6C0 + (p->i28 << 8));
                e->i98 = 0;
                e->h34 = (e->h34 | 0x41) & 0xEFFF;
                func_L01_004A6DF8(e, 1);
                e->h34 |= 2;
            }
        }
        if (h == 3) {
            if (p->i24 != -1) {
                Q_0035C1C0 *q = ((M_0035C1C0 *)(D_L16_001E015C_0035B6C0 + (p->i24 << 8)))->p68;
                if (q->i38 == 0) {
                    q->i38 = 1;
                }
            }
        } else {
            if (p->i24 != -1) {
                Q_0035C1C0 *q = ((M_0035C1C0 *)(D_L16_001E015C_0035B6C0 + (p->i24 << 8)))->p68;
                if (q->i38 != 0) {
                    q->i38 = 0;
                }
            }
        }
        if (p->sec == 0 && p->min == 0) {
            p->sound = func_L01_004A73F8(0x10, 0x21, m, 0);
            p->chimes = (s32)hf;
            p->timer = 10;
        }
        m->h96 = 0;
    }

    m->rF0.f[0] = func_00389380(0.0f, (f32)(p->sec * 6) * 0.017453292f);
    func_00388BD0(&m->qC0, &m->rF0);
    p->minHand->rF0.f[0] = func_00389380(0.0f, ((f32)p->min * 6.0f + (f32)p->sec * 0.1f) * 0.017453292f);
    func_00388BD0(&p->minHand->qC0, &p->minHand->rF0);
    func_003C26C8(p->minHand);
    hh = (f32)p->hour;
    if (hh > 12.0f) {
        hh -= 12.0f;
    }
    hh *= 30.0f;
    hh += (f32)p->min * 0.5f;
    p->hourHand->rF0.f[0] = func_00389380(0.0f, hh * 0.017453292f);
    func_00388BD0(&p->hourHand->qC0, &p->hourHand->rF0);
    func_003C26C8(p->hourHand);
    if (m->h96 < 0xFFFF) {
        m->h96++;
    }
    if (func_00388398(&p->timer) && p->chimes != 0 && !func_L01_004A6D20(m, p->sound)) {
        p->sound = -1;
        func_L01_004A73F8(0x11, 0x21, m, 0);
        p->timer = 120;
        p->chimes--;
    }
}
/* localdecomp:end func_L16_0035B6C0 */

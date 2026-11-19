#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_00397E90);

INCLUDE_ASM("asm/levels", func_L03_00398500);

INCLUDE_ASM("asm/levels", func_L03_00398760);

/* localdecomp:start func_L03_00398900 */
typedef struct {
    u8 pad0[0x3C];
    u16 flags3C;
} E_A_00398900;

typedef struct {
    u8 pad0[0x24];
    u8 *p24;
    u8 pad28[0xC];
    u16 flags34;
    u8 pad36[0x62];
    s32 w98;
} E_B_00398900;

extern s16 **D_L03_001D6764_00398900;
extern u8 *D_L03_001E0854_00398900;
extern E_A_00398900 *D_L03_0023A700_00398900[];
extern s16 *D_L03_0021C620_00398900[];
extern u8 *D_L03_001DF99C_00398900;
extern s32 D_L03_001DF9D8_00398900;

void func_L03_00398900(u8 *a0) {
    u8 *b = *(u8 **)(a0 + 0x68);
    s16 *p;
    u8 *e;
    E_B_00398900 *t;
    s16 *r;
    s32 n;
    p = D_L03_001D6764_00398900[*(s32 *)(b + 0x4C0)];
    while (p != 0) {
        if (p[-1] < 0 && p != D_L03_001D6764_00398900[*(s32 *)(b + 0x4C0)]) break;
        e = D_L03_001E0854_00398900 + ((u16)p[0] & 0x7FFF) * 32;
        if (e == 0) break;
        p += 1;
        D_L03_0023A700_00398900[e[0x1D]]->flags3C &= 0xFFFE;
    }
    r = D_L03_0021C620_00398900[*(s32 *)(b + 0x4C4)];
    while (((n = *(s32 *)(b + 0x4C4)) & 0xFF) != 0xFF && n <= D_L03_001DF9D8_00398900 && r != 0) {
        if (r[-1] < 0 && r != D_L03_0021C620_00398900[n]) break;
        t = (E_B_00398900 *)(D_L03_001DF99C_00398900 + (((u16)r[0] & 0x7FFF) << 8));
        if (t == 0) break;
        t->flags34 &= 0xFFBE;
        t->flags34 |= *(u16 *)(t->p24 + 0x44) & 0x1000;
        t->w98 = *(s32 *)(t->p24 + 0x10);
        r += 1;
    }
}
/* localdecomp:end func_L03_00398900 */

INCLUDE_ASM("asm/levels", func_L03_00398A78);

/* localdecomp:start func_L03_00398BF0 */
typedef struct {
    u8 pad0[0x3C];
    u16 flags3C;
} E_A_00398BF0;

typedef struct {
    u8 pad0[0x24];
    u8 *p24;
    u8 pad28[0xC];
    u16 flags34;
    u8 pad36[0x62];
    s32 w98;
} E_B_00398BF0;

extern s16 **D_L03_001D6764_00398BF0;
__asm__(".extern D_L03_001D6764_00398BF0, 4");
extern u8 *D_L03_001E0854_00398BF0;
extern E_A_00398900 *D_L03_0023A700_00398BF0[];
extern s16 *D_L03_0021C620_00398BF0[];
extern u8 *D_L03_001DF99C_00398BF0;
extern s32 D_L03_001DF9D8_00398BF0;
__asm__(".extern D_L03_001DF9D8_00398BF0, 4");

void func_L03_00398BF0(u8 *a0) {
    u8 *b = *(u8 **)(a0 + 0x68);
    s16 *p;
    u8 *e;
    E_B_00398BF0 *t;
    u8 *q;
    s32 m;
    s32 n;
    if (*(s32 *)(b + 0x4C8) != -1) {
        s16 **list = D_L03_001D6764_00398BF0;
        p = list[*(s32 *)(b + 0x4C8)];
        m = -2;
        while (p != 0) {
            if (p[-1] < 0 && p != D_L03_001D6764_00398BF0[*(s32 *)(b + 0x4C8)]) break;
            e = D_L03_001E0854_00398BF0 + ((u16)p[0] & 0x7FFF) * 32;
            if (e == 0) break;
            p += 1;
            D_L03_0023A700_00398BF0[e[0x1D]]->flags3C &= m;
        }
    }
    if (*(s32 *)(b + 0x4CC) != -1) {
        s16 *r = D_L03_0021C620_00398BF0[*(s32 *)(b + 0x4CC)];
        while (((n = *(s32 *)(b + 0x4CC)) & 0xFF) != 0xFF && n <= D_L03_001DF9D8_00398BF0 && r != 0) {
            if (r[-1] < 0 && r != D_L03_0021C620_00398BF0[n]) break;
            t = (E_B_00398BF0 *)(D_L03_001DF99C_00398BF0 + (((u16)r[0] & 0x7FFF) << 8));
            r += 1;
            if (t == 0) break;
            t->flags34 &= 0xFFBE;
            t->flags34 |= *(u16 *)(t->p24 + 0x44) & 0x1000;
            t->w98 = *(s32 *)(t->p24 + 0x10);
        }
    }
}
/* localdecomp:end func_L03_00398BF0 */

/* localdecomp:start func_L03_00398D50 */
extern void func_L03_00398DA0(u8 *, s32, s32);

void func_L03_00398D50(u8 *obj) {
    func_L03_00398DA0(obj, 0, -1);
    func_L03_00398DA0(obj, 1, 1);
    *(f32 *)(obj + 20) = 325.0f;
}
/* localdecomp:end func_L03_00398D50 */

/* localdecomp:start func_L03_00398DA0 */
void func_L03_00398DA0(u8 *a0, s32 i, s32 mode) {
    s32 k;
    u8 *b = *(u8 **)(a0 + 0x68);
    f32 *p;
    b += 0x3C0;
    p = (f32 *)((i << 7) + (s32)b);
    for (k = 0; k < 4; k++) {
        if (mode == 1) {
            *p = (f32)k * 0.0047996556f + 0.39269909f;
        } else {
            *p = (f32)k * -0.39269909f;
        }
        p += 8;
    }
}
/* localdecomp:end func_L03_00398DA0 */

INCLUDE_ASM("asm/levels", func_L03_00398E30);

/* localdecomp:start func_L03_00399010 */
typedef struct {
    u8 pad[0x4D0];
    f32 target;
    f32 speed;
    u8 pad4D8[0x10];
    s32 effect;
    s16 state;
} Vars_399010;
extern f32 func_L03_00399218(s32, s32);
extern f32 func_L01_00448890(void *, void *, f32, f32, f32, f32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern s32 D_001A74A4[];
__asm__(".extern D_001A74A4, 16");
extern u8 D_001A30B0[];
extern void func_L01_005003D0(s32, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_00399010(u8 *m, s32 index, s32 state) {
    Vars_399010 *v = *(Vars_399010 **)(m + 0x68);
    f32 *angle;
    f32 step, target;
    s32 i;
    s32 effect;
    u8 *e;
    if (v->state == -1) {
        v->state = 0;
        v->speed = 0.0f;
        v->target = func_L03_00399218(0, -1);
    }
    angle = (f32 *)((u8 *)v + 0x3C0 + (index << 7) + v->state * 0x20);
    target = func_L03_00399218(3, -1);
    step = func_L01_00448890(angle, &v->speed, target, 0.00069813174f, 0.00069813174f, 54.000004f, 0);
    for (i = 3; i > v->state; i--) {
        f32 *p = (f32 *)((index << 7) + (u32)v + (i << 5));
        *(f32 *)((u8 *)p + 0x3C0) = func_0038DAB8(*(f32 *)((u8 *)p + 0x3C0), step);
    }
    if (func_0038DB00(*(f32 *)((u8 *)v + ((v->state << 5) + (index << 7)) + 0x3C0), v->target) <= 0.0f) {
        if (v->state < 3) {
            v->state++;
            v->target = func_L03_00399218(v->state, -1);
        } else {
            v->speed = 0.0f;
            v->state = -1;
            D_001A74A4[0] = 0;
            func_L01_005003D0(0, 1);
            effect = v->effect;
            if (effect != -1) {
                e = D_001A30B0 + (effect << 7);
                if (*(u8 **)(e + 0xDC) == m && e[0xD0]) {
                    func_003A4F28(effect);
                }
            }
            v->effect = -1;
            v->effect = func_003A52A0(0, 4, m);
            func_L01_004450F0(m, state, -1);
        }
    }
}
/* localdecomp:end func_L03_00399010 */

/* localdecomp:start func_L03_00399218 */
f32 func_L03_00399218(s32 a0, s32 a1) {
    if (a1 == 1) {
        return (f32)(a0 - 1) * -0.39269909262657166f + 0.0047996556386351585f;
    }
    return (f32)a0 * -0.39269909262657166f;
}
/* localdecomp:end func_L03_00399218 */

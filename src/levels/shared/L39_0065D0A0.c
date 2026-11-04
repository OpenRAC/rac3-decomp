#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 b0C;
    u8 b0D;
    u8 b0E;
} S_006618D8;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x170 - 8];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} S_1A5CD0_006618D8;

INCLUDE_ASM("asm/levels", func_L39_0065D0A0);

INCLUDE_ASM("asm/levels", func_L39_0065F1A8);

/* localdecomp:start func_L39_0065F468 */
extern void func_0038CB78(void *, s32, s32);
extern void *func_L39_00662510(u8 *p);
extern u8 D_L39_0047B2E0[];

void func_L39_0065F468(u8 *p) {
    func_0038CB78(p, 0, 0x4500);
    func_L39_00662510(p);
    *(u8 **)(p + 0x14) = D_L39_0047B2E0;
    *(u8 *)(p + 0x1A14) = 1;
    *(u8 *)(p + 0x44EF) = 5;
}
/* localdecomp:end func_L39_0065F468 */

INCLUDE_ASM("asm/levels", func_L39_0065F4B8);

INCLUDE_ASM("asm/levels", func_L39_006606E0);

/* localdecomp:start func_L39_00661268 */
s32 func_L39_00661268(u8 *p) {
    u8 *q = *(u8 **)(p + 9512);
    if (q != 0) {
        return *(s32 *)(q + 720);
    }
    return 0;
}
/* localdecomp:end func_L39_00661268 */

/* localdecomp:start func_L39_00661288 */
typedef struct {
    u8 pad0[0x108];
    f32 x;
    f32 y;
    u8 pad110[0x1A0 - 0x110];
    s32 mask;
    u8 pad1A4[0x1B0 - 0x1A4];
    s32 buttons;
    u8 pad1B4[0x1D4 - 0x1B4];
    s32 flag;
} S_65E9B0_Pad;

typedef struct {
    u8 pad0[0x110];
    f32 x;
    f32 y;
    u8 pad118[0x300 - 0x118];
    s32 c300;
    s32 c304;
    u8 pad308[0x338 - 0x308];
    s16 h338;
    u8 pad33A[0x2468 - 0x33A];
    f32 f2468;
    f32 f246C;
    u8 pad2470[0x248C - 0x2470];
    f32 f248C;
    u8 pad2490[0x2534 - 0x2490];
    S_65E9B0_Pad *pad;
    u8 pad2538[0x2544 - 0x2538];
    s32 port;
} S_65E9B0;

extern void func_L39_0063BF40(S_65E9B0 *);
extern s32 func_L39_005C42E8(s32, s32);
extern f32 func_L39_00647588(S_65E9B0 *, f32 *);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);

void func_L39_00661288(S_65E9B0 *p) {
    S_65E9B0_Pad *q;
    s32 b;
    s32 t;
    s32 v;

    func_L39_0063BF40(p);
    if ((p->pad->mask & func_L39_005C42E8(4, p->port)) == 0) {
        p->h338 = 0;
    }
    if (p->pad->flag != 0) {
        p->c300 = 0;
        p->c304++;
    } else {
        p->c304 = 0;
        p->c300++;
    }
    p->x = p->pad->x;
    p->y = -p->pad->y;
    p->f248C = func_L39_00647588(p, &p->x);
    if (func_0038CED8(&p->x) < 0.25f) {
        q = p->pad;
        t = ((q->buttons >> 13) & 1) - ((q->buttons >> 15) & 1);
        p->x = (f32)t;
        b = q->buttons;
        t = (b >> 14) & 1;
        if (b & 0x1000) {
            v = 1 - t;
        } else {
            v = -t;
        }
        p->y = (f32)v;
    }
    p->f2468 = func_L39_00647588(p, &p->x);
    p->f246C = func_0038D160(p->x, p->y);
}
/* localdecomp:end func_L39_00661288 */

/* localdecomp:start func_L39_006613D0 */
typedef struct {
    u8 pad0[9048];
    s32 hist0[8];
    s32 hist1[8];
    s32 index;
    s32 count;
    u8 pad1[9520 - 9120];
    u8 *target;
} Self_65EAF8;

extern void func_003C48A8(void *a, f32 *out);
extern void func_L39_005BA3A0(f32 *v, s32 *out);
extern void func_L39_005BA488(u8 *target, s32 *out);

void func_L39_006613D0(Self_65EAF8 *self) {
    f32 v[4];
    if (*(s16 *)(*(u8 **)(self->target + 80) + 134) == 33) {
        return;
    }
    func_003C48A8(self->target + 896, v);
    func_L39_005BA3A0(v, &self->hist1[self->index]);
    func_L39_005BA488(self->target, &self->hist0[self->index]);
    self->index = (self->index + 1) % 8;
    self->count++;
    if (self->count > 8) {
        self->count = 8;
    }
}
/* localdecomp:end func_L39_006613D0 */

INCLUDE_ASM("asm/levels", func_L39_00661488);

INCLUDE_ASM("asm/levels", func_L39_006617C8);

/* localdecomp:start func_L39_006618D8 */
extern void func_14AD08(s32, s32, s32, s32, s32, void *);


extern S_1A5CD0_006618D8 D_1A5CD0;

void func_L39_006618D8(u8 *p, f32 *v, s32 a2, s8 a3, s32 a4) {
    S_006618D8 s;
    u8 b;

    s.b0D = p[0x2544];
    s.b0C = p[0x44ED];
    b = p[0x44EE];
    s.b0E = b;
    if (a2 != 0) {
        s.b0E = b | 0x40;
    }
    if (a4 != 0) {
        s.b0E |= 0x20;
    }
    s.b0D |= (a3 + 1) << 4;
    s.f0 = v[0];
    s.f4 = v[1];
    s.f8 = v[2];
    if (D_1A5CD0.w170 == 0) {
        func_14AD08(D_1A5CD0.b7D4 | 0x80, D_1A5CD0.w4, -1,
                    *(s32 *)0x2405E4, 0x10, &s);
    }
}
/* localdecomp:end func_L39_006618D8 */

INCLUDE_ASM("asm/levels", func_L39_00661988);

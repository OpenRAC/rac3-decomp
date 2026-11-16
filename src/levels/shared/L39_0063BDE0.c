#include "common.h"

/* declared by functions of L39_00639350.c, which this file was cut from */
extern s32 func_0038CB00(s16 *timer);
extern u8 D_L39_004997E0[];

/* localdecomp:start func_L39_0063BDE0 */
typedef struct { u8 pad[0xAA]; s16 t; } S639;
s32 func_L39_0063BDE0(s32 unused, S639 *p) {
    if (p == 0) return 0;
    return p->t == 0x18AB;
}
/* localdecomp:end func_L39_0063BDE0 */

/* localdecomp:start func_L39_0063BE00 */
#include "vu0.h"
typedef union Buf_0063BE00 {
    u8 b[8];
    u32 w[2];
} Buf_0063BE00;

extern u8 D_L39_004997E0[];
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(void *);
extern f32 func_L39_00633C78(void *, void *, s32);
extern f32 func_0038DBA0(f32, f32);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_0063BE00(u8 *q) {
    Buf_0063BE00 buf;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 i;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((s32)q - n) & 7;
    b = buf.b;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

s32 func_L39_0063BE00(u8 *o, f32 lim) {
    f32 d;

    if (*(s16 *)(o + 0x3E4) != 0 ||
        (*(s32 *)(o + 0x1310) == 1 && func_L01_004606E8(0x28, 2, 0, *(s32 *)(o + 0x2534)) != 0 &&
        func_L39_006212E8(o) != 0xA)) {
        if ((get_state_0063BE00(o + 0x19E4) ^ 0x10) != 0) {
            if (o[0x1A06] != 0) {
                d = fabs_asm(func_L39_00633C78(o, o + 0x23C0, 0));
            } else {
                d = func_0038DBA0(*(f32 *)(o + 0xB8), *(f32 *)(o + 0x23B8));
            }
            if (d < lim) {
                return 0;
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0063BE00 */

/* localdecomp:start func_L39_0063BF40 */
extern s32 func_0038CB00(s16 *timer);
typedef struct {
    char pad0[452];
    int a;
    int b;
} Pad006396F8;

typedef struct {
    char pad0[996];
    unsigned short count;
    char pad3E6[9524 - 998];
    Pad006396F8 *pad;
} Obj006396F8;

extern int func_L39_00639D90(Obj006396F8 *);

void func_L39_0063BF40(Obj006396F8 *o)
{
    if (func_L39_00639D90(o)) {
        ((void (*)(unsigned short *))func_0038CB00)(&o->count);
        return;
    }
    if (o->pad->a & 3) {
        if (o->pad->a & 2)
            o->count++;
        if (o->pad->a & 1)
            o->count++;
    }
    if (o->pad->b & 3) {
        if (o->pad->b & 2)
            ((void (*)(unsigned short *))func_0038CB00)(&o->count);
        if (o->pad->b & 1)
            ((void (*)(unsigned short *))func_0038CB00)(&o->count);
    }
}
/* localdecomp:end func_L39_0063BF40 */

INCLUDE_ASM("asm/levels", func_L39_0063C000);

/* localdecomp:start func_L39_0063C468 */
typedef union Buf_0063C468 {
    u8 b[8];
    u32 w[2];
} Buf_0063C468;

extern u8 D_L39_004997E0[];
extern void func_L39_00621D30(u8 *);
extern void func_L39_00634E48(u8 *, f32, f32);
extern void func_L39_00634E28(u8 *, f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern s32 func_0038CAD0(void *);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_003C4088(f32, f32, f32);

static __inline__ u32 Dec_0063C468(u8 *q) {
    Buf_0063C468 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

void func_L39_0063C468(u8 *self) {
    s32 flag;
    s32 t;
    u8 *p;
    u8 c;
    f32 r;

    if (*(s32 *)(self + 0x324) < 0x11) {
        return;
    }
    if (self[0x1A07] != 0 || *(s32 *)(self + 0x1078) != 0) {
        func_L39_00621D30(self);
        func_L39_00634E48(self, 0.0432f, 0.2880000174045563f);
        func_L39_00634E28(self, 0.0432f, 0.2880000174045563f);
        *(s32 *)(self + 0x10A0) = func_L39_005B43C8(0x4B, 0x64);
        *(s16 *)(self + 0x334) = func_L39_005B43C8(0x4B, 0x64);
        return;
    }
    flag = 1;
    t = -1;
    if (*(s32 *)(self + 0x474) == 2) {
        t = *(s32 *)(self + 0x478);
    }
    if (t == 1) {
        flag = 0;
    }
    if (Dec_0063C468(self + 0x19E4) != 0) {
        return;
    }
    p = *(u8 **)(self + 0x2524);
    c = p[0x43];
    if (c >= 3) {
        return;
    }
    if (*(s32 *)(self + 0x2454) != 0) {
        return;
    }
    if ((u32)(c - 1) < 2) {
        *(s32 *)(self + 0x10A0) = func_L39_005B43C8(0x21, 0x3A);
    }
    if (func_0038CAD0(self + 0x10A0)) {
        *(f32 *)(self + 0x1094) = -func_L39_005B4410(-0.15707964f, 0.43633232f);
        if (*(f32 *)(self + 0x208) < 1.5f) {
            *(f32 *)(self + 0x1098) = func_L39_005B4468(0.87266463f, 1.2217305f);
        } else {
            *(f32 *)(self + 0x1098) = func_L39_005B4468(0.34906584f, 0.99483764f);
        }
        r = func_L39_005B4410(0.0f, 1.0f);
        *(f32 *)(self + 0x10A4) = func_003C4088(0.015f, 0.007f, r);
        *(f32 *)(self + 0x10A8) = func_003C4088(0.29f, 0.3f, r);
        *(s32 *)(self + 0x10A0) = func_L39_005B43C8(0x4B, 0xA7) + (s32)(r * 67.0f);
    }
    if ((u32)((*(u8 **)(self + 0x2524))[0x43] - 1) < 2) {
        if (0.34906584f < *(f32 *)(self + 0x1098)) {
            *(f32 *)(self + 0x1098) = 0.34906584f;
        } else if (*(f32 *)(self + 0x1098) < -0.34906584f) {
            *(f32 *)(self + 0x1098) = -0.34906584f;
        }
        if (0.2617994f < *(f32 *)(self + 0x1094)) {
            *(f32 *)(self + 0x1094) = 0.2617994f;
        }
        if (*(f32 *)(self + 0x1094) < 0.0f) {
            *(f32 *)(self + 0x1094) = 0.0f;
        }
    }
    func_L39_00634E48(self, *(f32 *)(self + 0x10A4), *(f32 *)(self + 0x10A8));
    *(f32 *)(self + 0x9D8) = *(f32 *)(self + 0x1098);
    *(f32 *)(self + 0x9D4) = *(f32 *)(self + 0x1094);
    if (flag) {
        func_L39_00634E28(self, 0.011520001105964184f, 0.4320000410079956f);
        *(f32 *)(self + 0x878) = *(f32 *)(self + 0x9D8) * 0.52f;
        *(f32 *)(self + 0x874) = *(f32 *)(self + 0x9D4) * 0.55f;
    }
}
/* localdecomp:end func_L39_0063C468 */

INCLUDE_ASM("asm/levels", func_L39_0063C840);

/* localdecomp:start func_L39_0063D0F0 */
s32 func_L39_0063D0F0(s32 arg0, s32 arg1) {
    return arg1;
}
/* localdecomp:end func_L39_0063D0F0 */

/* localdecomp:start func_L39_0063D0F8 */
typedef union Buf_0063D0F8 {
    u8 b[8];
    u32 w[2];
} Buf_0063D0F8;

typedef struct E_0063D0F8 {
    s32 w0;
    u8 pad4[0x18];
} E_0063D0F8;

extern u8 D_L39_004997E0[];
extern E_0063D0F8 D_L39_004840A0[];
extern s32 func_0038CB00(s16 *timer);
extern s32 func_L39_005C2FD0(void *);
extern s32 func_L39_005C3078(void *);
void func_L39_006770F8(u8);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_0063D0F8(u8 *q) {
    Buf_0063D0F8 buf;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 i;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((s32)q - n) & 7;
    b = buf.b;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

void func_L39_0063D0F8(u8 *o) {
    func_0038CB00((s16 *)(o + 0x24A6));
    func_0038CB00((s16 *)(o + 0x24A8));
    if ((get_state_0063D0F8(o + 0x19E4) ^ 0x37) == 0) {
        return;
    }
    if (*(s32 *)(o + 0x251C) != 0 || o[0x1A0C] != 0 || D_L39_004840A0[*(s32 *)(o + 0x2544)].w0 != 0) {
        return;
    }
    if (func_L39_005C2FD0(*(void **)(o + 0x2534)) & 0x10) {
        *(s16 *)(o + 0x24A6) = 0x11;
    }
    if (*(s16 *)(o + 0x24A6) != 0) {
        if (func_L39_005C3078(*(void **)(o + 0x2534)) & 0x10) {
            o[0x24AA] = 1;
            func_L39_006770F8(o[0x24C9]);
            if (*(s16 *)(o + 0x24A8) == 0) {
                *(s16 *)(o + 0x24A8) = 0x11;
            }
        }
    }
}
/* localdecomp:end func_L39_0063D0F8 */

/* localdecomp:start func_L39_0063D240 */
void func_L39_006770F8(u8);

void func_L39_0063D240(void *arg0, s32 arg1) {
    if ((((*(u8 *)((u8 *)arg0 + 0x1A14)) != 0) || (arg1 != 0)) && ((*(s32 *)((u8 *)arg0 + 0x251C)) != 0)) {
        *(s32 *)((u8 *)arg0 + 0x251C) = 0;
        *(s8 *)((u8 *)arg0 + 0x24AA) = 1;
        func_L39_006770F8((*(u8 *)((u8 *)arg0 + 0x24C9)));
        if ((*(s16 *)((u8 *)arg0 + 0x24A8)) == 0) {
            *(s16 *)((u8 *)arg0 + 0x24A8) = 0x11;
        }
    }
}
/* localdecomp:end func_L39_0063D240 */

INCLUDE_ASM("asm/levels", func_L39_0063D2A8);

INCLUDE_ASM("asm/levels", func_L39_0063E3D0);

#include "common.h"

/* NTSC-U counterpart of func_L39_00621D60 (src/levels/shared/L39_00621D30.c) */
extern u8 D_L39_004998A0[];

/* localdecomp:start func_L39_0061F5C0 */
typedef struct {
    u8 pad0[0xB];
    s8 bB;
    s16 h0C;
    s16 h0E;
    s16 h10;
    u8 pad12[0x20 - 0x12];
    u8 b20;
    s8 b21;
    u8 pad22[0x80 - 0x22];
} E_00621D60;

typedef struct {
    u8 pad0[8];
    f32 f8;
} N_00621D60;

typedef struct {
    u8 pad0[0x474];
    s32 f474;
    s32 f478;
    u8 pad47C[0x748 - 0x47C];
    N_00621D60 *f748[2];
    s32 f750;
    s32 f754;
    u8 pad758[0x10A0 - 0x758];
    s32 f10A0;
    u8 pad10A4[0x19E6 - 0x10A4];
    u8 b19E6;
    u8 pad19E7[0x1A05 - 0x19E7];
    u8 b1A05;
    u8 pad1A06;
    u8 b1A07;
    u8 b1A08;
    u8 pad1A09[0x1A17 - 0x1A09];
    u8 b1A17;
    u8 pad1A18[0x2448 - 0x1A18];
    s32 f2448;
    s32 f244C;
    u8 pad2450[0x24FD - 0x2450];
    u8 b24FD;
    u8 pad24FE[0x2524 - 0x24FE];
    s32 f2524;
    u8 pad2528[0x2580 - 0x2528];
    u8 b2580[1];
} O_00621D60;

typedef union {
    u32 w[2];
    u8 b[8];
} B_00621D60;

extern E_00621D60 D_L39_0049C950_0061F5C0[];
extern u8 D_L39_004998A0[];
extern s32 D_L39_00246268[] __attribute__((section(".sdata")));

extern s32 func_L39_00646268(u8 *, s32);
extern void func_L39_0061F590(void *);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L39_00628CD0(void *, s32, s32, s32, f32);
extern void func_L01_00436C90(s32, void *);
extern N_00621D60 *func_L39_005A8E28(s32, s32, void *, s32);
extern void func_L01_00437108(s32, void *, s32, s32, s32, s32);

/* the weapon table entry of idx (its upgraded row when func_L39_00646268 says so) */
static __inline__ E_00621D60 *ent_00621D60(O_00621D60 *o, s32 idx) {
    if (func_L39_00646268((u8 *)o, idx)) {
        return &D_L39_0049C950_0061F5C0[((E_00621D60 *)((u8 *)D_L39_0049C950_0061F5C0 + (idx << 7)))->b21];
    }
    return (E_00621D60 *)((u8 *)D_L39_0049C950_0061F5C0 + (idx << 7));
}

static __inline__ u32 Dec_00621D60(u8 *p) {
    B_00621D60 buf;
    u8 *d;
    s32 x;
    long t;
    s32 i;

    t = *p;
    if (t == 0) {
        x = 0;
    } else {
        s32 m;
        s32 kk;
        s32 n = *p;
        m = n + 1;
        kk = ((s32)p - n) & 7;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004998A0[m + ((kk + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)p;
        buf.w[1] ^= buf.w[0];
        x = buf.w[1];
    }
    return x;
}

static __inline__ u32 DecB_00621D60(u8 *p) {
    B_00621D60 buf;
    u32 z;

    if (*p == 0) {
        z = 0;
    } else {
        s32 n = *p;
        s32 m = n + 1;
        s32 kk = ((s32)p - n) & 7;
        u8 *d = buf.b;
        s32 i;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004998A0[m + ((kk + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)p;
        buf.w[1] ^= buf.w[0];
        z = buf.w[1];
    }
    return z;
}

static __inline__ u32 DecC_00621D60(u8 *p2) {
    B_00621D60 buf;
    u32 r;

    if (*p2 == 0) {
        r = 0;
    } else {
        u32 aa;
        u32 bb;
        s32 n = *p2;
        s32 m = n + 1;
        s32 kk = ((u32)p2 - n) & 7;
        u8 *d = buf.b;
        s32 i;
        for (i = 0; i < 24; i += 3) {
            *d++ = D_L39_004998A0[m + ((kk + i) & 7) * 255];
        }
        aa = buf.w[0] ^ (u32)p2;
        bb = buf.w[1] ^ aa;
        buf.w[0] = aa;
        buf.w[1] = (bb >> 16) / (((bb ^ (bb >> 16)) << 16) + 1);
        r = buf.b[4];
    }
    return r;
}

void func_L39_0061F5C0(void *self, s32 idx) {
    O_00621D60 *o = self;
    s32 stk;
    s32 x;
    s32 z;
    s32 a;
    s32 b;
    s32 h12;
    s32 h14;
    s32 k;

    if (idx == -1) {
        s32 r;
        if (o->f474 == 2) {
            r = o->f478;
        } else {
            r = -1;
        }
        idx = r;
    }
    if (idx == -1 || idx == 0) {
        return;
    }
    o->f244C = idx;
    h12 = ent_00621D60(o, idx)->h0C;
    h14 = ent_00621D60(o, idx)->h0E;
    x = Dec_00621D60((u8 *)o + 0x19E6);
    if ((x ^ 0xC) == 0 || o->b24FD != 0) {
        h14 = ent_00621D60(o, idx)->h10;
    }
    o->b1A05 = ent_00621D60(o, idx)->b20;
    o->b1A07 = 1;
    stk = 0;
    a = -1;
    if (ent_00621D60(o, idx)->bB == 0) {
        a = 9;
        stk = 7;
    } else if (h12 == 0x2E || idx == 2) {
        a = 2;
    } else if (idx == 1) {
        a = 5;
    }
    b = a;
    if (a < 0) {
        b = 11;
    }
    func_L39_0061F590(o);
    o->f10A0 = func_L39_005B24C8(0x5A, 0x78);
    z = DecB_00621D60((u8 *)o + 0x19E6);
    if (z == 0 && o->b1A08 == 0 && o->b24FD == 0) {
        o->f2448 = h12;
        func_L39_00628CD0(o, h12, stk, 0, (f32)a);
        o->f754 = 1;
        return;
    }
    if (h14 == -1) {
        for (k = 0; k < 2; k++) {
            if (o->f748[k] != 0) {
                func_L01_00436C90(o->f2524, &o->f748[k]);
            }
        }
        return;
    }
    for (k = 0; k < 2; k++) {
        N_00621D60 *q;
        if (k == 1) {
            if ((DecC_00621D60(&o->b1A17) ^ 2) != 0) {
                return;
            }
        }
        if (o->f748[k] != 0) {
            func_L01_00436C90(o->f2524, &o->f748[k]);
        }
        q = func_L39_005A8E28(o->f2524, D_L39_00246268[k], &o->b2580[k * 0x3C0], 0x3C0);
        o->f748[k] = q;
        if (q != 0) {
            o->f2448 = h14;
            o->f754 = 0;
            q->f8 = 1.0f;
            func_L01_00437108(o->f2524, q, o->f2448, 0, b, 1);
        }
    }
}
/* localdecomp:end func_L39_0061F5C0 */

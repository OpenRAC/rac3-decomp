#include "common.h"

/* declared by functions of L39_00675830.c, which this file was cut from */
typedef struct S_00675830 {
    u8 pad0[0x48];
    s16 h48;
    s16 h4A;
    u8 pad4C[0xC];
    s32 w58;
    s32 w5C;
    u8 pad60[0x10];
    s32 w70;
    s32 w74;
    s32 w78;
    u8 pad7C[0x14];
} S_00675830;
extern S_00675830 D_L39_00498B10[];
extern u8 D_L39_00246510[8];
extern u8 *func_L39_0061BF38(s32);
extern s32 func_L39_005C42E8(s32, s32);
extern void func_L39_00674F50(u8 *);

/* localdecomp:start func_L39_00675908 */
#include "vu0.h"

typedef struct S_Q_00675908 {
    u8 pad0[0x148];
    f32 f148;
    f32 f14C;
    u8 pad150[0x70];
    u32 w1C0;
    u32 w1C4;
    u8 pad1C8[4];
    s32 w1CC;
    u8 pad1D0[8];
    s32 w1D8;
} S_Q_00675908;

typedef struct S_S_00675908 {
    u8 pad0[0x19E6];
    u8 b19E6;
    u8 pad19E7[0x2A];
    u8 b1A11;
    u8 pad1A12[0xA92];
    u8 b24A4;
    u8 pad24A5[0x8F];
    S_Q_00675908 *q2534;
    u8 pad2538[0xC];
    s32 w2544;
} S_S_00675908;

typedef struct S_P_00675908 {
    u8 pad0[0x64];
    s32 w64;
    u8 pad68[4];
    s32 w6C;
    u8 b70;
    u8 b71;
    u8 pad72[2];
    s32 w74;
    union {
        s32 w;
        s8 b[4];
    } u78;
    s32 w7C;
    u8 pad80[0x10];
} S_P_00675908;

typedef struct S_E_00675908 {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
} S_E_00675908;

extern S_E_00675908 D_L39_004840A0[];
extern u8 D_L39_004997E0[];
extern s32 D_L39_0024BD40;
extern S_E_00675908 **D_L39_0024BD48[] __attribute__((section(".sdata")));
extern S_E_00675908 D_L39_002464E0 __attribute__((section(".sdata")));
extern s32 D_L39_002410F8[] __attribute__((section(".sdata")));
extern s32 D_L39_0024CFD8[] __attribute__((section(".sdata")));
extern s32 D_L39_0024CFC8[] __attribute__((section(".sdata")));
extern s32 D_L39_0024CFB8[] __attribute__((section(".sdata")));
extern u32 D_L39_0024B9C8;
extern u8 D_L39_00246510[8];
extern s32 D_L39_00246500[2];
extern f32 D_L39_00246528;
typedef struct Rooms_00675908 {
    u8 pad0[0x18A0];
    u8 arr[4][0xB50];
} Rooms_00675908;
typedef struct World_00675908 {
    u8 pad0[0x1FCA8];
    Rooms_00675908 rooms;
} World_00675908;
extern World_00675908 *D_L39_00242A50;
__asm__(".extern D_L39_00246510, 8");
__asm__(".extern D_L39_00246500, 8");
__asm__(".extern D_L39_00246528, 4");
__asm__(".extern D_L39_00242A50, 4");

extern s32 func_L39_005C42E8(s32, s32);
extern void func_L39_00677148(s32);
extern s32 func_L39_00677170(s32);
extern void func_L39_00677130(s32);
extern void func_L39_00677120(s32);
extern s32 func_L01_0040E020(void *);
extern void func_L39_00605AA8(u8 *, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_L39_005F3548(s32, s32, s32);
extern s32 func_003934B8(s32);
extern void func_L39_0063E3D0(void *, s32);

/* reads a byte value stored scrambled through the D_L39_004997E0 tables */
static __inline__ u32 decode_00675908(u8 *kp) {
    u8 buf[8];
    u8 b;
    s32 b1;
    s32 k;
    u8 *d;
    u32 base;

    if (*kp == 0) {
        return 0;
    }
    b = *kp;
    b1 = b + 1;
    d = buf;
    base = ((u32)kp - b) & 7;
    for (k = 0; k < 40; k += 5) {
        *d++ = D_L39_004997E0[b1 + ((base + k) & 7) * 255];
    }
    ((u32 *)buf)[0] ^= (u32)kp;
    ((u32 *)buf)[1] ^= ((u32 *)buf)[0];
    return ((u32 *)buf)[1];
}

void func_L39_00675908(S_P_00675908 *p) {
    s32 i = (S_00675830 *)p - D_L39_00498B10 - 8;
    S_S_00675908 *s = (S_S_00675908 *)func_L39_0061BF38(i);
    S_Q_00675908 *q;
    s32 flag = 0;
    s32 g;
    s32 h;
    s32 cur;
    f32 ang;
    f32 len;
    f32 x;
    f32 y;
    u8 *t;

    if (D_L39_004840A0[s->w2544].w0 != 0 || (decode_00675908(&s->b19E6) ^ 0x14) == 0) {
        flag = 1;
    }
    t = &p->b70;
    g = 1;
    func_L39_00677148(i);
    if (func_L39_00677170(i) == 0 || flag) g = 0;
    if (!flag && (s->q2534->w1C0 & (func_L39_005C42E8(8, s->w2544) | 2))) {
        if (D_L39_00246510[i] == 0) {
            D_L39_00246510[i] = 4;
            func_L39_00674F50((u8 *)s);
        }
    } else if (!flag && (s->q2534->w1C0 & 0x10)) {
        if (func_L01_0040E020(&D_L39_00246510[i])) {
            func_L39_00674F50((u8 *)s);
        }
    }
    if (g && D_L39_00242A50 != 0) {
        Rooms_00675908 *rooms = &D_L39_00242A50->rooms;
        func_L39_00605AA8(rooms->arr[i], 2);
    }
    p->w7C = 0x96;
    p->w6C = 0x18;
    if (!flag && func_0038CB00(&s->b24A4) != 0 && g) {
        s->q2534->w1CC = 2;
    }
    q = s->q2534;
    x = q->f148;
    y = q->f14C;
    len = sqrt_asm(x * x + y * y);
    if (len != 0.0f) {
        x /= len;
        y /= len;
    }
    ang = func_0038D160(x, y);
    if ((p->u78.w >> 24) == 0) {
        if ((s->q2534->w1C4 & 0xF000) || len < 0.5f || --p->u78.w == -1) {
            p->w74 = -1;
            p->u78.w = 0x10000FF;
        }
    }
    h = 0;
    cur = p->w74;
    if (p->u78.b[3] == 1 && (s->q2534->w1C0 & 0x10) && g) {
        q = s->q2534;
        if (len > 0.9f) {
            f32 pi = 3.1415927f;
            f32 n = (f32)D_L39_0024BD40;
            f32 a22 = ang + pi + pi + 1.5707964f + pi / n;
            f32 a20 = (f32)cur * 6.2831855f / n - pi;
            f32 a21 = a22 * (n / 6.2831855f);
            if (cur == -1 || func_0038DBA0(a20, func_0038DB00(ang, 1.5707964f)) > 0.5890486f) {
                s32 n2 = (s32)a21;
                s32 r = n2 % D_L39_0024BD40;
                if ((r ^ 1) & 1) {
                    f32 fr = a21 - (f32)n2;
                    if (fr > 0.8f) r++;
                    else if (fr < 0.2f) r--;
                    r = (r + D_L39_0024BD40) % D_L39_0024BD40;
                }
                h = -1;
                p->w74 = r;
                D_L39_00246528 = func_0038DB48(a22 - ((f32)r * 0.7853982f + 0.3926991f));
                if (D_L39_00246528 > 0.0f) h = 1;
            }
        } else {
            if (q->w1D8 == 0 && (q->w1C4 & 0xF000)) {
                s32 c2 = cur;
                if (q->w1C4 & 0x1000) {
                    c2 = (c2 == -1) ? D_L39_002464E0.w10 : D_L39_0024BD48[i][D_L39_00246500[i]][c2].w10;
                }
                if (s->q2534->w1C4 & 0x4000) {
                    c2 = (c2 == -1) ? D_L39_002464E0.w14 : D_L39_0024BD48[i][D_L39_00246500[i]][c2].w14;
                }
                if (s->q2534->w1C4 & 0x8000) {
                    c2 = (c2 == -1) ? D_L39_002464E0.w8 : D_L39_0024BD48[i][D_L39_00246500[i]][c2].w8;
                }
                if (s->q2534->w1C4 & 0x2000) {
                    c2 = (c2 == -1) ? D_L39_002464E0.wC : D_L39_0024BD48[i][D_L39_00246500[i]][c2].wC;
                }
                p->w74 = c2;
            }
        }
        if (D_L39_0024BD48[i][D_L39_00246500[i]][p->w74].w0 == 0) {
            if (h != 0) {
                s32 nx = (p->w74 + h) % D_L39_0024BD40;
                if (D_L39_0024BD48[i][D_L39_00246500[i]][nx].w0 != 0) p->w74 = nx;
            }
        }
    }
    if (p->w74 != cur) {
        t[1] = 0;
        func_L39_005F3548(3, 0, 0);
    } else {
        if (t[1] < 8) t[1]++;
    }
    if ((s->q2534->w1C0 & 0x10) == 0 && !flag) {
        if (t[0] == 0 || --t[0] == 0) {
            if (p->w74 >= 0) {
                s32 e = D_L39_0024BD48[i][D_L39_00246500[i]][p->w74].w18;
                if (e != 0) {
                    switch (e) {
                    case -1:
                        s->b1A11 = 2;
                        break;
                    case -2:
                        D_L39_002410F8[s->w2544] = 2;
                        break;
                    case -3:
                        D_L39_002410F8[s->w2544] = 1;
                        break;
                    case -4:
                        D_L39_002410F8[s->w2544] = 0;
                        break;
                    default:
                        func_L39_0063E3D0(s, e);
                        break;
                    }
                }
            }
        }
        func_L39_00677130(i);
        func_L39_00677120(i);
    } else {
        if (t[0] < 8) t[0]++;
    }
    if (t[0] == 0 || flag) {
        D_L39_0024CFD8[i] = p->w74;
        D_L39_0024CFC8[i] = p->u78.w;
        func_003934B8(p->w64);
        p->w6C = -6;
        D_L39_0024CFB8[i] = D_L39_0024B9C8;
    }
}
/* localdecomp:end func_L39_00675908 */

INCLUDE_ASM("asm/levels", func_L39_006761D0);
